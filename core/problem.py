"""Problem representation for SyGuS / SMT2 Loop Invariant Synthesis."""

from dataclasses import dataclass, field
from typing import List, Tuple, Optional, Dict, Any


@dataclass
class Variable:
    name: str
    type_name: str = "Int"

    def primed(self) -> "Variable":
        return Variable(name=f"{self.name}!", type_name=self.type_name)

    def to_smt_decl(self) -> str:
        return f"({self.name} {self.type_name})"


@dataclass
class NegativeExample:
    candidate_inv: str
    failure_cause: str
    failure_details: str
    counterexample_model: Optional[Dict[str, Any]] = None


@dataclass
class Problem:
    name: str
    logic: str = "LIA"
    variables: List[Variable] = field(default_factory=list)
    pre_f: str = ""      # S-expression body or full define-fun
    trans_f: str = ""    # S-expression body or full define-fun (with primed variables)
    post_f: str = ""     # S-expression body or full define-fun
    ground_truth_inv: Optional[str] = None
    negative_examples: List[NegativeExample] = field(default_factory=list)
    raw_sygus: Optional[str] = None

    @property
    def var_names(self) -> List[str]:
        return [v.name for v in self.variables]

    @property
    def primed_variables(self) -> List[Variable]:
        return [v.primed() for v in self.variables]

    def get_var_signature_smt(self) -> str:
        return " ".join(v.to_smt_decl() for v in self.variables)

    def get_trans_var_signature_smt(self) -> str:
        unprimed = " ".join(v.to_smt_decl() for v in self.variables)
        primed = " ".join(v.to_smt_decl() for v in self.primed_variables)
        return f"{unprimed} {primed}"

    def get_inv_signature(self) -> str:
        return f"(define-fun InvF ({self.get_var_signature_smt()}) Bool"

    def to_sygus_str(self) -> str:
        """Returns the problem representation in SyGuS / SMT format as seen in Figure 1 & Figure 4."""
        if self.raw_sygus:
            return self.raw_sygus.strip()

        lines = [
            f"(set-logic {self.logic})",
            f"(synth-inv InvF ({self.get_var_signature_smt()}))",
            f"(define-fun PreF ({self.get_var_signature_smt()}) Bool {self.pre_f.strip()})",
            f"(define-fun TransF ({self.get_trans_var_signature_smt()}) Bool {self.trans_f.strip()})",
            f"(define-fun PostF ({self.get_var_signature_smt()}) Bool {self.post_f.strip()})",
            "(inv-constraint InvF PreF TransF PostF)",
            "(check-synth)"
        ]
        return "\n".join(lines)

    def to_partial_sygus_str(self, condition: str) -> str:
        """Generates relaxed partial problem representation for RQ1.2 (P_pre, P_trans, P_post)."""
        lines = [
            f"(set-logic {self.logic})",
            f"(synth-inv InvF ({self.get_var_signature_smt()}))"
        ]
        if condition == "pre":
            lines.append(f"(define-fun PreF ({self.get_var_signature_smt()}) Bool {self.pre_f.strip()})")
        elif condition == "trans":
            lines.append(f"(define-fun TransF ({self.get_trans_var_signature_smt()}) Bool {self.trans_f.strip()})")
        elif condition == "post":
            lines.append(f"(define-fun PostF ({self.get_var_signature_smt()}) Bool {self.post_f.strip()})")
        return "\n".join(lines)

    def to_smt_functions_str(self) -> str:
        """Outputs the three define-fun blocks commonly displayed in prompts."""
        lines = [
            f"(define-fun PreF ({self.get_var_signature_smt()}) Bool {self.pre_f.strip()})",
            f"(define-fun TransF ({self.get_trans_var_signature_smt()}) Bool {self.trans_f.strip()})",
            f"(define-fun PostF ({self.get_var_signature_smt()}) Bool {self.post_f.strip()})"
        ]
        return "\n".join(lines)
