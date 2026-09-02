"""RQ1.4 Experiment: Impact of Example Types (EX_P, EX_N, EX_Mix) in Few-Shot Prompting (Tables VI & VII)."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq1_4(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    example_finder: ExampleFinder,
    k_samples: int = 50,
    n_few_shot: int = 2,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Compares positive (EX_P), negative (EX_N), and mixed (EX_Mix) example types for few-shot invariant generation."""
    results = {
        "EX_P": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems)},
        "EX_N": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems)},
        "EX_Mix": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems)},
    }

    for ex_type in ["EX_P", "EX_N", "EX_Mix"]:
        print(f"\n[RQ1.4] Running evaluation for Example Type: {ex_type} (k={k_samples})...")

        for prob in tqdm(problems, desc=f"RQ1.4 ({ex_type})"):
            prompt = PromptBuilder.build_few_shot_prompt(
                problem=prob,
                example_finder=example_finder,
                n=n_few_shot,
                metric="syntactic",
                example_type=ex_type
            )

            responses = llm.generate(prompt, n_samples=k_samples, temperature=temperature)

            solved_at_k10 = False
            solved_at_k30 = False
            solved_at_k50 = False

            for idx, resp in enumerate(responses):
                candidate_inv = InvariantExtractor.extract_and_normalize(resp, prob)
                v_res = verifier.verify(prob, candidate_inv)
                if v_res.is_valid:
                    if idx < 10:
                        solved_at_k10 = True
                    if idx < 30:
                        solved_at_k30 = True
                    if idx < 50:
                        solved_at_k50 = True

            if solved_at_k10:
                results[ex_type]["k10"] += 1
            if solved_at_k30:
                results[ex_type]["k30"] += 1
            if solved_at_k50:
                results[ex_type]["k50"] += 1

    return results
