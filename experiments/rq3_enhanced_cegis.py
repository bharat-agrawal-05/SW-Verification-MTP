"""Enhanced CEGIS Experiment (Beyond the Paper): Integrated Prompting + Multi-Turn Cumulative Counterexample Feedback."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_enhanced_cegis(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    example_finder: ExampleFinder,
    max_turns: int = 3,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Evaluates the Enhanced CEGIS Framework: Combining Integrated Few-Shot Prompting with

    Cumulative Counterexample History, Anti-Overfitting Generalization Directives, and Cycle
    Prevention.
    """
    total_problems = len(problems)
    turn_solved_counts = {t: 0 for t in range(0, max_turns + 1)}
    cumulative_solved_counts = {t: 0 for t in range(0, max_turns + 1)}
    total_solved = 0
    total_cycles_prevented = 0
    trajectories = []

    print(f"\n[Enhanced CEGIS] Running Multi-Turn Cumulative Counterexample Synthesis on {total_problems} problems (Turn 0 [Init] + {max_turns} repair turns)...")

    for prob in tqdm(problems, desc="Enhanced CEGIS Loop"):
        history = []
        visited_invariants = set()
        solved = False
        solved_turn = None

        # Turn 0: Initial Synthesis via Integrated Prompt (Domain Instructions + Syntactic Few-Shot Exemplar)
        initial_prompt = PromptBuilder.build_rq1_5_integrated_prompt(
            prob, example_finder, n=2, metric="syntactic", example_type="EX_P"
        )
        resp0 = llm.generate(initial_prompt, n_samples=1, temperature=temperature)[0]
        cand0 = InvariantExtractor.extract_and_normalize(resp0, prob)
        v_res0 = verifier.verify(prob, cand0)
        visited_invariants.add(cand0)

        history.append({
            "turn": 0,
            "candidate_inv": cand0,
            "is_valid": v_res0.is_valid,
            "failed_rule": v_res0.failed_rule,
            "error_details": v_res0.error_details,
            "counterexample_str": v_res0.counterexample_str or "N/A"
        })

        if v_res0.is_valid:
            solved = True
            solved_turn = 0
            turn_solved_counts[0] += 1
            total_solved += 1
        else:
            # Multi-turn CEGIS repair loop: Turns 1 to max_turns
            for turn in range(1, max_turns + 1):
                feedback_prompt = PromptBuilder.build_cegis_feedback_prompt(
                    problem=prob,
                    example_finder=example_finder,
                    history=history,
                    turn=turn
                )

                resp = llm.generate(feedback_prompt, n_samples=1, temperature=temperature)[0]
                cand = InvariantExtractor.extract_and_normalize(resp, prob)

                is_cycle = cand in visited_invariants
                if is_cycle:
                    # Active Cycle Prevention: re-prompt with explicit tabu warning and higher temperature to break cycle
                    max_cycle_retries = 2
                    for retry in range(1, max_cycle_retries + 1):
                        retry_temp = min(1.0, temperature + 0.15 * retry)
                        retry_prompt = (
                            f"{feedback_prompt}\n\n"
                            f"CRITICAL REMINDER: The invariant `{cand}` was ALREADY attempted and failed. "
                            f"Do NOT re-submit `{cand}`. You MUST synthesize a strictly different, novel invariant."
                        )
                        retry_resp = llm.generate(retry_prompt, n_samples=1, temperature=retry_temp)[0]
                        new_cand = InvariantExtractor.extract_and_normalize(retry_resp, prob)
                        if new_cand not in visited_invariants:
                            cand = new_cand
                            is_cycle = False
                            total_cycles_prevented += 1
                            break
                visited_invariants.add(cand)

                v_res = verifier.verify(prob, cand)

                history.append({
                    "turn": turn,
                    "candidate_inv": cand,
                    "is_valid": v_res.is_valid,
                    "is_cycle": is_cycle,
                    "failed_rule": v_res.failed_rule,
                    "error_details": v_res.error_details,
                    "counterexample_str": v_res.counterexample_str or "N/A"
                })

                if v_res.is_valid:
                    solved = True
                    solved_turn = turn
                    turn_solved_counts[turn] += 1
                    total_solved += 1
                    break

        # Calculate cumulative solved up to each turn
        if solved and solved_turn is not None:
            for t in range(solved_turn, max_turns + 1):
                cumulative_solved_counts[t] += 1

        trajectories.append({
            "problem": prob.name,
            "solved": solved,
            "solved_at_turn": solved_turn,
            "total_turns": len(history),
            "history": history
        })

    return {
        "num_problems": total_problems,
        "total_solved": total_solved,
        "total_success_rate_percent": (total_solved / total_problems * 100.0) if total_problems > 0 else 0.0,
        "turn_solved_counts": turn_solved_counts,
        "cumulative_solved_counts": cumulative_solved_counts,
        "cumulative_success_rates": {
            t: (cumulative_solved_counts[t] / total_problems * 100.0) if total_problems > 0 else 0.0
            for t in range(0, max_turns + 1)
        },
        "cycles_prevented": total_cycles_prevented,
        "trajectories": trajectories
    }
