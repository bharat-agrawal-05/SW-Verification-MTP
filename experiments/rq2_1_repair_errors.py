"""RQ2.1 Experiment: Invariant Repair Using Verifier Error Causes and Details (Table IX)."""

from typing import List, Dict, Any, Tuple
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq2_1(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    n_incorrect_per_problem: int = 2,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Evaluates LLM capability to repair incorrect invariants given verifier error causes and details."""
    total_attempted = 0
    total_repaired = 0
    repair_details = []

    print(f"\n[RQ2.1] Running Invariant Repair using Verifier Error Feedback on {len(problems)} problems...")

    for prob in tqdm(problems, desc="RQ2.1 (Error Repair)"):
        # Collect initial candidates to find incorrect ones
        prompt_gen = PromptBuilder.build_rq1_1_prompt(prob, with_instructions=True)
        initial_responses = llm.generate(prompt_gen, n_samples=max(5, n_incorrect_per_problem * 2), temperature=temperature)

        incorrect_invariants: List[Tuple[str, str, str]] = []

        for resp in initial_responses:
            cand = InvariantExtractor.extract_and_normalize(resp, prob)
            v_res = verifier.verify(prob, cand)
            if not v_res.is_valid:
                cause = v_res.error_cause or 'FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}'
                details = v_res.error_details or "Failed to satisfy verification condition"
                incorrect_invariants.append((cand, cause, details))
                if len(incorrect_invariants) >= n_incorrect_per_problem:
                    break

        # Fallback if LLM didn't generate enough invalid candidates
        if len(incorrect_invariants) < n_incorrect_per_problem:
            fallback_inv = f"{prob.get_inv_signature()} false)"
            v_res = verifier.verify(prob, fallback_inv)
            cause = v_res.error_cause or 'FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}'
            details = v_res.error_details or "Failed to satisfy precondition"
            while len(incorrect_invariants) < n_incorrect_per_problem:
                incorrect_invariants.append((fallback_inv, cause, details))

        # Attempt repair for each incorrect invariant
        for failed_inv, cause, details in incorrect_invariants:
            total_attempted += 1
            repair_prompt = PromptBuilder.build_rq2_1_repair_prompt(
                problem=prob,
                failed_inv=failed_inv,
                error_cause=cause,
                error_details=details
            )

            repair_resp = llm.generate(repair_prompt, n_samples=1, temperature=temperature)[0]
            repaired_inv = InvariantExtractor.extract_and_normalize(repair_resp, prob)
            v_res = verifier.verify(prob, repaired_inv)

            is_success = v_res.is_valid
            if is_success:
                total_repaired += 1

            repair_details.append({
                "problem": prob.name,
                "failed_inv": failed_inv,
                "repaired_inv": repaired_inv,
                "success": is_success,
                "error_cause": cause,
                "error_details": details
            })

    success_rate = (total_repaired / total_attempted * 100.0) if total_attempted > 0 else 0.0

    return {
        "num_problems": len(problems),
        "attempted_invariants": total_attempted,
        "successful_repairs": total_repaired,
        "success_rate_percent": success_rate,
        "details": repair_details
    }
