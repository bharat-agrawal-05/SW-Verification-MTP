"""Prompt Builder assembling prompts for all RQs."""

from typing import List, Tuple, Dict, Any
from core.problem import Problem
from similarity.example_finder import ExampleFinder
from prompts.templates import (
    PROMPT_RQ1_1_WITH_INSTRUCTIONS,
    PROMPT_RQ1_1_WITHOUT_INSTRUCTIONS,
    PROMPT_RQ1_2_PARTIAL,
    PROMPT_RQ1_2_COMBINER,
    PROMPT_FEW_SHOT,
    PROMPT_RQ1_5_INTEGRATED,
    PROMPT_RQ2_1_REPAIR_ERROR,
    PROMPT_RQ2_2_REPAIR_COUNTEREXAMPLE,
    PROMPT_ENHANCED_CEGIS_FEEDBACK,
)


class PromptBuilder:
    """Constructs prompts for all experimental conditions in RQ1 and RQ2."""

    @staticmethod
    def build_rq1_1_prompt(problem: Problem, with_instructions: bool = True) -> str:
        """Constructs prompt for RQ1.1 (Figure 3 or Baseline)."""
        smt_str = problem.to_smt_functions_str()
        if with_instructions:
            return PROMPT_RQ1_1_WITH_INSTRUCTIONS.format(problem_smt=smt_str)
        else:
            return PROMPT_RQ1_1_WITHOUT_INSTRUCTIONS.format(problem_smt=smt_str)

    @staticmethod
    def build_rq1_2_partial_prompt(problem: Problem, condition: str) -> str:
        """Constructs partial invariant synthesis prompt P_pre, P_trans, or P_post (Figure 4)."""
        partial_sygus = problem.to_partial_sygus_str(condition)
        vars_sig = problem.get_var_signature_smt()

        if condition == "pre":
            condition_clause = "PreF implies InvF"
        elif condition == "trans":
            condition_clause = "( trans-f and inv-f ) implies inv-f!"
        elif condition == "post":
            condition_clause = "inv-f implies post-f"
        else:
            raise ValueError(f"Unknown condition: {condition}")

        return PROMPT_RQ1_2_PARTIAL.format(
            partial_sygus=partial_sygus,
            condition_clause=condition_clause,
            vars_sig=vars_sig
        )

    @staticmethod
    def build_rq1_2_combiner_prompt(
        problem: Problem,
        pre_invariants: List[Tuple[str, bool]],
        trans_invariants: List[Tuple[str, bool]],
        post_invariants: List[Tuple[str, bool]]
    ) -> str:
        """Constructs combiner prompt P_full (Figure 5) showing correct/wrong candidate invariants."""
        def format_candidates(inv_list: List[Tuple[str, bool]]) -> str:
            if not inv_list:
                return "* <code> (define-fun InvF () Bool true) </code> which was correct"
            lines = []
            for inv_str, is_correct in inv_list:
                status = "which was correct" if is_correct else "which was wrong"
                lines.append(f"* <code> {inv_str} </code> {status}")
            return "\n".join(lines)

        sygus_str = problem.to_sygus_str()
        pre_block = format_candidates(pre_invariants)
        trans_block = format_candidates(trans_invariants)
        post_block = format_candidates(post_invariants)

        return PROMPT_RQ1_2_COMBINER.format(
            sygus_problem=sygus_str,
            pre_invariants_block=pre_block,
            trans_invariants_block=trans_block,
            post_invariants_block=post_block
        )

    @staticmethod
    def build_few_shot_prompt(
        problem: Problem,
        example_finder: ExampleFinder,
        n: int = 2,
        metric: str = "syntactic",
        example_type: str = "EX_P"
    ) -> str:
        """Constructs few-shot prompt for RQ1.3 & RQ1.4 (Figure 8)."""
        smt_str = problem.to_smt_functions_str()
        var_names = " ".join(problem.var_names)
        few_shots = example_finder.build_few_shot_block(
            query=problem,
            n=n,
            metric=metric,
            example_type=example_type
        )
        return PROMPT_FEW_SHOT.format(
            problem_smt=smt_str,
            var_names=var_names,
            few_shot_examples=few_shots
        )

    @staticmethod
    def build_rq1_5_integrated_prompt(
        problem: Problem,
        example_finder: ExampleFinder,
        n: int = 2,
        metric: str = "syntactic",
        example_type: str = "EX_P"
    ) -> str:
        """Constructs integrated instructions + few-shots prompt for RQ1.5 (Figure 9)."""
        smt_str = problem.to_smt_functions_str()
        few_shots = example_finder.build_few_shot_block(
            query=problem,
            n=n,
            metric=metric,
            example_type=example_type
        )
        return PROMPT_RQ1_5_INTEGRATED.format(
            problem_smt=smt_str,
            few_shot_examples=few_shots
        )

    @staticmethod
    def build_rq2_1_repair_prompt(
        problem: Problem,
        failed_inv: str,
        error_cause: str,
        error_details: str
    ) -> str:
        """Constructs error-cause based repair prompt for RQ2.1 (Figure 10)."""
        return PROMPT_RQ2_1_REPAIR_ERROR.format(
            problem_name=problem.name,
            inv=failed_inv,
            error_cause=error_cause,
            error_details=error_details
        )

    @staticmethod
    def build_rq2_2_repair_prompt(
        problem: Problem,
        failed_inv: str,
        error_details: str,
        counterexample_values: str
    ) -> str:
        """Constructs counterexample-based repair prompt for RQ2.2 (Figure 11)."""
        return PROMPT_RQ2_2_REPAIR_COUNTEREXAMPLE.format(
            problem_name=problem.name,
            inv=failed_inv,
            error_details=error_details,
            counterexample_values=counterexample_values
        )

    @staticmethod
    def build_cegis_feedback_prompt(
        problem: Problem,
        example_finder: ExampleFinder,
        history: List[Dict[str, Any]],
        turn: int
    ) -> str:
        """Constructs cumulative CEGIS feedback prompt with generalization directives."""
        smt_str = problem.to_smt_functions_str()
        vars_sig = problem.get_var_signature_smt()
        
        # Get top-1 positive syntactic reference example
        similar = example_finder.find_similar(problem, n=1, metric="syntactic")
        ref_example = ""
        if similar:
            ref_example = example_finder.format_example(similar[0][0], example_type="EX_P")
        else:
            ref_example = f"Problem:\n*** {smt_str} ***\nA successful invariant: {problem.get_inv_signature()} true)"

        history_lines = []
        for item in history:
            t = item["turn"]
            inv = item["candidate_inv"]
            rule = item.get("failed_rule", "Unknown")
            details = item.get("error_details", "")
            ce = item.get("counterexample_str", "N/A")
            history_lines.append(
                f"- Attempt {t}:\n"
                f"  Proposed: <code> {inv} </code>\n"
                f"  Failed Rule: {rule} ({details})\n"
                f"  Counterexample State: `{ce}`"
            )

        attempt_history_str = "\n".join(history_lines)

        return PROMPT_ENHANCED_CEGIS_FEEDBACK.format(
            problem_smt=smt_str,
            reference_example=ref_example,
            turn=turn,
            attempt_history=attempt_history_str,
            vars_sig=vars_sig
        )
