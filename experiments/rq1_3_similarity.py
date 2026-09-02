"""RQ1.3 Experiment: Few-shot Prompting with Syntactic (S_syntactic) vs Semantic (S_semantic) similarity (Table V)."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq1_3(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    example_finder: ExampleFinder,
    k_samples: int = 50,
    n_few_shot: int = 2,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Compares few-shot prompting performance between S_syntactic and S_semantic retrieval."""
    results = {
        "S_semantic": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems)},
        "S_syntactic": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems)},
    }

    for metric in ["S_semantic", "S_syntactic"]:
        metric_key = "semantic" if metric == "S_semantic" else "syntactic"
        print(f"\n[RQ1.3] Running few-shot evaluation with {metric} (n={n_few_shot}, k={k_samples})...")

        for prob in tqdm(problems, desc=f"RQ1.3 ({metric})"):
            prompt = PromptBuilder.build_few_shot_prompt(
                problem=prob,
                example_finder=example_finder,
                n=n_few_shot,
                metric=metric_key,
                example_type="EX_P"
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
                results[metric]["k10"] += 1
            if solved_at_k30:
                results[metric]["k30"] += 1
            if solved_at_k50:
                results[metric]["k50"] += 1

    return results
