"""RQ1.5 Experiment: Combining Domain Instructions with Few-Shot Examples (Table VIII)."""

from typing import List, Dict, Any
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq1_5(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    example_finder: ExampleFinder,
    k_samples: int = 50,
    n_few_shot: int = 2,
    temperature: float = 0.7,
    token_limit: int = 8192
) -> Dict[str, Any]:
    """Compares Instruction-only, Few-shot only, and Integrated (Instructions + Few-Shot) prompts."""
    results = {
        "instruction_only": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems), "token_limit_exceeded": 0},
        "few_shot_only": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems), "token_limit_exceeded": 0},
        "integrated": {"k10": 0, "k30": 0, "k50": 0, "total": len(problems), "token_limit_exceeded": 0},
    }

    modes = [
        ("instruction_only", lambda p: PromptBuilder.build_rq1_1_prompt(p, with_instructions=True)),
        ("few_shot_only", lambda p: PromptBuilder.build_few_shot_prompt(p, example_finder, n=n_few_shot, metric="syntactic", example_type="EX_P")),
        ("integrated", lambda p: PromptBuilder.build_rq1_5_integrated_prompt(p, example_finder, n=n_few_shot, metric="syntactic", example_type="EX_P")),
    ]

    for mode, prompt_fn in modes:
        print(f"\n[RQ1.5] Running evaluation for setup: {mode} (k={k_samples})...")

        for prob in tqdm(problems, desc=f"RQ1.5 ({mode})"):
            prompt = prompt_fn(prob)
            
            # Check prompt token length
            token_count = llm.count_tokens(prompt)
            if token_count > token_limit:
                results[mode]["token_limit_exceeded"] += 1
                continue

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
                results[mode]["k10"] += 1
            if solved_at_k30:
                results[mode]["k30"] += 1
            if solved_at_k50:
                results[mode]["k50"] += 1

    return results
