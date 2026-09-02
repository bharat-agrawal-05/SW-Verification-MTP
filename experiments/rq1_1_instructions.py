"""RQ1.1 Experiment: Invariant Generation with Guiding Instructions vs Baseline (Tables II & III)."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq1_1(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    k_samples: int = 50,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Evaluates Loop Invariant Generation with vs without domain knowledge instructions."""
    results = {
        "with_instructions": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems), "followed_template": 0, "syntactically_correct": 0, "total_generated": 0},
        "without_instructions": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems), "followed_template": 0, "syntactically_correct": 0, "total_generated": 0},
    }

    for mode, with_inst in [("without_instructions", False), ("with_instructions", True)]:
        print(f"\n[RQ1.1] Running evaluation: {mode} (k={k_samples})...")

        for prob in tqdm(problems, desc=f"RQ1.1 ({mode})"):
            prompt = PromptBuilder.build_rq1_1_prompt(prob, with_instructions=with_inst)
            responses = llm.generate(prompt, n_samples=k_samples, temperature=temperature)

            solved_at_k10 = False
            solved_at_k30 = False
            solved_at_k50 = False

            for idx, resp in enumerate(responses):
                results[mode]["total_generated"] += 1
                
                # Check template following
                if "```" in resp or "<code>" in resp or "(define-fun" in resp:
                    results[mode]["followed_template"] += 1

                candidate_inv = InvariantExtractor.extract_and_normalize(resp, prob)
                
                # Check syntax correctness
                if InvariantExtractor.is_syntactically_valid(candidate_inv):
                    results[mode]["syntactically_correct"] += 1

                # Verify correctness with Z3
                v_res = verifier.verify(prob, candidate_inv)
                if v_res.is_valid:
                    if idx < 10:
                        solved_at_k10 = True
                    if idx < 30:
                        solved_at_k30 = True
                    if idx < 50:
                        solved_at_k50 = True

            if solved_at_k10:
                results[mode]["k10"] += 1
            if solved_at_k30:
                results[mode]["k30"] += 1
            if solved_at_k50:
                results[mode]["k50"] += 1

    return results
