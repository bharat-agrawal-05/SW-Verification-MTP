"""Z3 Formal Verification Engine for SyGuS/SMT2 Loop Invariants."""

from dataclasses import dataclass, field
from typing import Dict, Any, Optional, Tuple, List
import z3
from core.problem import Problem


@dataclass
class VerificationResult:
    is_valid: bool
    r1_holds: bool = False
    r2_holds: bool = False
    r3_holds: bool = False
    failed_rule: Optional[str] = None  # "R1", "R2", "R3", or "SYNTAX_ERROR"
    error_cause: Optional[str] = None
    error_details: Optional[str] = None
    counterexample_model: Dict[str, Any] = field(default_factory=dict)
    counterexample_str: Optional[str] = None
    raw_error: Optional[str] = None


class InvariantVerifier:
    """Formally verifies loop invariants using Z3 theorem prover against Hoare logic rules R1, R2, R3."""

    def __init__(self, timeout_ms: int = 10000):
        self.timeout_ms = timeout_ms

    def _build_declarations_smt(self, problem: Problem) -> str:
        """Build SMT2 declarations for unprimed and primed variables."""
        decls = []
        for v in problem.variables:
            decls.append(f"(declare-fun {v.name} () {v.type_name})")
            decls.append(f"(declare-fun {v.name}! () {v.type_name})")
        return "\n".join(decls)

    def _build_call_args(self, problem: Problem, primed: bool = False) -> str:
        suffix = "!" if primed else ""
        return " ".join(f"{v.name}{suffix}" for v in problem.variables)

    def _build_trans_call_args(self, problem: Problem) -> str:
        unprimed = " ".join(f"{v.name}" for v in problem.variables)
        primed = " ".join(f"{v.name}!" for v in problem.variables)
        return f"{unprimed} {primed}"

    def _format_counterexample(self, problem: Problem, model: z3.ModelRef, include_primed: bool = False) -> Tuple[Dict[str, Any], str]:
        """Extracts variable assignments from Z3 model and formats string as in paper Figure 11."""
        model_dict = {}
        parts = []

        for v in problem.variables:
            val_sym = z3.Int(v.name) if v.type_name == "Int" else z3.Bool(v.name)
            val = model.eval(val_sym, model_completion=True)
            model_dict[v.name] = str(val)
            parts.append(f"{v.name} = {val}")

        if include_primed:
            for v in problem.variables:
                p_name = f"{v.name}!"
                val_sym = z3.Int(p_name) if v.type_name == "Int" else z3.Bool(p_name)
                val = model.eval(val_sym, model_completion=True)
                model_dict[p_name] = str(val)
                parts.append(f"{p_name} = {val}")

        ce_str = ", ".join(parts)
        return model_dict, ce_str

    def verify_rule_1(self, problem: Problem, inv_def: str) -> Tuple[bool, Optional[Dict[str, Any]], Optional[str]]:
        """Check R1: PreF(v) => InvF(v) [Satisfied iff PreF(v) and not InvF(v) is UNSAT]"""
        args = self._build_call_args(problem, primed=False)
        smt_script = f"""
(set-logic {problem.logic})
{self._build_declarations_smt(problem)}
(define-fun PreF ({problem.get_var_signature_smt()}) Bool {problem.pre_f})
{inv_def}
(assert (and (PreF {args}) (not (InvF {args}))))
"""
        solver = z3.Solver()
        solver.set("timeout", self.timeout_ms)
        try:
            exprs = z3.parse_smt2_string(smt_script)
            solver.add(exprs)
            check = solver.check()
            if check == z3.unsat:
                return True, None, None
            elif check == z3.sat:
                model = solver.model()
                m_dict, m_str = self._format_counterexample(problem, model, include_primed=False)
                return False, m_dict, m_str
            else:
                return False, {}, "Solver unknown / timeout"
        except Exception as e:
            return False, {}, f"SMT error in R1: {e}"

    def verify_rule_2(self, problem: Problem, inv_def: str) -> Tuple[bool, Optional[Dict[str, Any]], Optional[str]]:
        """Check R2: InvF(v) and TransF(v, v!) => InvF(v!) [Satisfied iff InvF(v) and TransF(v, v!) and not InvF(v!) is UNSAT]"""
        args_unprimed = self._build_call_args(problem, primed=False)
        args_primed = self._build_call_args(problem, primed=True)
        args_trans = self._build_trans_call_args(problem)

        smt_script = f"""
(set-logic {problem.logic})
{self._build_declarations_smt(problem)}
(define-fun TransF ({problem.get_trans_var_signature_smt()}) Bool {problem.trans_f})
{inv_def}
(assert (and (InvF {args_unprimed}) (TransF {args_trans}) (not (InvF {args_primed}))))
"""
        solver = z3.Solver()
        solver.set("timeout", self.timeout_ms)
        try:
            exprs = z3.parse_smt2_string(smt_script)
            solver.add(exprs)
            check = solver.check()
            if check == z3.unsat:
                return True, None, None
            elif check == z3.sat:
                model = solver.model()
                m_dict, m_str = self._format_counterexample(problem, model, include_primed=True)
                return False, m_dict, m_str
            else:
                return False, {}, "Solver unknown / timeout"
        except Exception as e:
            return False, {}, f"SMT error in R2: {e}"

    def verify_rule_3(self, problem: Problem, inv_def: str) -> Tuple[bool, Optional[Dict[str, Any]], Optional[str]]:
        """Check R3: InvF(v) => PostF(v) [Satisfied iff InvF(v) and not PostF(v) is UNSAT]"""
        args = self._build_call_args(problem, primed=False)
        smt_script = f"""
(set-logic {problem.logic})
{self._build_declarations_smt(problem)}
(define-fun PostF ({problem.get_var_signature_smt()}) Bool {problem.post_f})
{inv_def}
(assert (and (InvF {args}) (not (PostF {args}))))
"""
        solver = z3.Solver()
        solver.set("timeout", self.timeout_ms)
        try:
            exprs = z3.parse_smt2_string(smt_script)
            solver.add(exprs)
            check = solver.check()
            if check == z3.unsat:
                return True, None, None
            elif check == z3.sat:
                model = solver.model()
                m_dict, m_str = self._format_counterexample(problem, model, include_primed=False)
                return False, m_dict, m_str
            else:
                return False, {}, "Solver unknown / timeout"
        except Exception as e:
            return False, {}, f"SMT error in R3: {e}"

    def verify(self, problem: Problem, inv_def: str) -> VerificationResult:
        """Full inductive loop invariant verification (R1, R2, and R3)."""
        args = " ".join(v.name for v in problem.variables)

        # 1. Check R1 (PreF => InvF)
        r1_ok, r1_model, r1_ce_str = self.verify_rule_1(problem, inv_def)
        if not r1_ok:
            cond_str = f"(=> (PreF {args}) (InvF {args}))"
            return VerificationResult(
                is_valid=False,
                r1_holds=False,
                r2_holds=False,
                r3_holds=False,
                failed_rule="R1",
                error_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                error_details=f"Failed to satisfy the condition {cond_str}",
                counterexample_model=r1_model or {},
                counterexample_str=r1_ce_str or "",
                raw_error=r1_ce_str
            )

        # 2. Check R2 (InvF and TransF => InvF!)
        r2_ok, r2_model, r2_ce_str = self.verify_rule_2(problem, inv_def)
        if not r2_ok:
            args_primed = " ".join(f"{v.name}!" for v in problem.variables)
            cond_str = f"(=> (and (InvF {args}) (TransF {self._build_trans_call_args(problem)})) (InvF {args_primed}))"
            return VerificationResult(
                is_valid=False,
                r1_holds=True,
                r2_holds=False,
                r3_holds=False,
                failed_rule="R2",
                error_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                error_details=f"Failed to satisfy the condition {cond_str}",
                counterexample_model=r2_model or {},
                counterexample_str=r2_ce_str or "",
                raw_error=r2_ce_str
            )

        # 3. Check R3 (InvF => PostF)
        r3_ok, r3_model, r3_ce_str = self.verify_rule_3(problem, inv_def)
        if not r3_ok:
            cond_str = f"(=> (InvF {args}) (PostF {args}))"
            return VerificationResult(
                is_valid=False,
                r1_holds=True,
                r2_holds=True,
                r3_holds=False,
                failed_rule="R3",
                error_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                error_details=f"Failed to satisfy the condition {cond_str}",
                counterexample_model=r3_model or {},
                counterexample_str=r3_ce_str or "",
                raw_error=r3_ce_str
            )

        # All 3 rules hold!
        return VerificationResult(
            is_valid=True,
            r1_holds=True,
            r2_holds=True,
            r3_holds=True
        )

    def verify_partial(self, problem: Problem, inv_def: str, condition: str) -> bool:
        """Verifies a single condition ('pre' for R1, 'trans' for R2, 'post' for R3) for RQ1.2."""
        if condition == "pre":
            ok, _, _ = self.verify_rule_1(problem, inv_def)
            return ok
        elif condition == "trans":
            ok, _, _ = self.verify_rule_2(problem, inv_def)
            return ok
        elif condition == "post":
            ok, _, _ = self.verify_rule_3(problem, inv_def)
            return ok
        else:
            raise ValueError(f"Unknown condition: {condition}. Must be 'pre', 'trans', or 'post'.")
