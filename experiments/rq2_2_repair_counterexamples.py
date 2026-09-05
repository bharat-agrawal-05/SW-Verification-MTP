"""RQ2.2 Experiment: Invariant Repair Using Concrete Counterexample Values & Multi-turn Trajectory Tracking (Table X, Fig 12)."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq2_2(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    n_incorrect_per_problem: int = 2,
    max_repair_turns: int = 3,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Evaluates LLM invariant repair guided by concrete Z3 counterexample values across single and multi-turn loops."""
    total_attempted = 0
    single_turn_repaired = 0
    multi_turn_repaired = 0
    trajectories = []

    print(f"\n[RQ2.2] Running Invariant Repair using Counterexample Models on {len(problems)} problems...")

    for prob in tqdm(problems, desc="RQ2.2 (Counterexample Repair)"):
        # Collect initial incorrect invariants
        prompt_gen = PromptBuilder.build_rq1_1_prompt(prob, with_instructions=True)
        initial_responses = llm.generate(prompt_gen, n_samples=max(5, n_incorrect_per_problem * 2), temperature=temperature)

        incorrect_invariants = []

        for resp in initial_responses:
            cand = InvariantExtractor.extract_and_normalize(resp, prob)
            v_res = verifier.verify(prob, cand)
            if not v_res.is_valid:
                incorrect_invariants.append((cand, v_res))
                if len(incorrect_invariants) >= n_incorrect_per_problem:
                    break

        # Fallback if needed
        if len(incorrect_invariants) < n_incorrect_per_problem:
            fallback_inv = f"{prob.get_inv_signature()} false)"
            v_res = verifier.verify(prob, fallback_inv)
            while len(incorrect_invariants) < n_incorrect_per_problem:
                incorrect_invariants.append((fallback_inv, v_res))

        # Repair loop for each incorrect invariant
        for failed_inv, init_v_res in incorrect_invariants:
            total_attempted += 1
            current_inv = failed_inv
            current_v_res = init_v_res
            turn_history = []
            visited_invariants = set()

            success = False
            for turn in range(1, max_repair_turns + 1):
                ce_vals = current_v_res.counterexample_str or "N/A"
                details = current_v_res.error_details or "Failed to satisfy condition"

                repair_prompt = PromptBuilder.build_rq2_2_repair_prompt(
                    problem=prob,
                    failed_inv=current_inv,
                    error_details=details,
                    counterexample_values=ce_vals
                )

                repair_resp = llm.generate(repair_prompt, n_samples=1, temperature=temperature)[0]
                repaired_inv = InvariantExtractor.extract_and_normalize(repair_resp, prob)
                v_res = verifier.verify(prob, repaired_inv)

                is_cycle = repaired_inv in visited_invariants
                visited_invariants.add(repaired_inv)

                turn_history.append({
                    "turn": turn,
                    "previous_inv": current_inv,
                    "repaired_inv": repaired_inv,
                    "counterexample_given": ce_vals,
                    "is_valid": v_res.is_valid,
                    "is_cycle": is_cycle,
                    "failed_rule": v_res.failed_rule
                })

                if v_res.is_valid:
                    success = True
                    if turn == 1:
                        single_turn_repaired += 1
                    multi_turn_repaired += 1
                    break

                current_inv = repaired_inv
                current_v_res = v_res

            trajectories.append({
                "problem": prob.name,
                "initial_inv": failed_inv,
                "success": success,
                "turns_taken": len(turn_history),
                "history": turn_history
            })

    single_turn_rate = (single_turn_repaired / total_attempted * 100.0) if total_attempted > 0 else 0.0
    multi_turn_rate = (multi_turn_repaired / total_attempted * 100.0) if total_attempted > 0 else 0.0

    return {
        "num_problems": len(problems),
        "attempted_invariants": total_attempted,
        "single_turn_successful_repairs": single_turn_repaired,
        "single_turn_success_rate_percent": single_turn_rate,
        "multi_turn_successful_repairs": multi_turn_repaired,
        "multi_turn_success_rate_percent": multi_turn_rate,
        "trajectories": trajectories
    }
