"""RQ1.2 Experiment: Problem Partitioning & Divide-and-Conquer Invariant Synthesis (Figures 4-7)."""

from typing import List, Dict, Any, Tuple
from tqdm import tqdm
from core.problem import Problem
from core.extractor import InvariantExtractor
from core.verifier import InvariantVerifier
from prompts.builder import PromptBuilder
from llm.base import BaseLLMClient


def run_rq1_2(
    problems: List[Problem],
    llm: BaseLLMClient,
    verifier: InvariantVerifier,
    k_partial: int = 10,
    k_full: int = 50,
    temperature: float = 0.7
) -> Dict[str, Any]:
    """Evaluates divide-and-conquer problem partitioning (P_pre, P_trans, P_post, and P_full)."""
    results = {
        "pre_solved": 0,
        "trans_solved": 0,
        "post_solved": 0,
        "all_partial_solved": 0,
        "full_combiner_solved": 0,
        "total_problems": len(problems),
        "details": []
    }

    print(f"\n[RQ1.2] Running problem partitioning evaluation on {len(problems)} problems...")

    for prob in tqdm(problems, desc="RQ1.2 (Partitioning)"):
        # Solve P_pre (R1)
        prompt_pre = PromptBuilder.build_rq1_2_partial_prompt(prob, condition="pre")
        resp_pre = llm.generate(prompt_pre, n_samples=k_partial, temperature=temperature)
        pre_cands: List[Tuple[str, bool]] = []
        pre_ok = False
        for r in resp_pre:
            inv = InvariantExtractor.extract_and_normalize(r, prob)
            ok = verifier.verify_partial(prob, inv, condition="pre")
            pre_cands.append((inv, ok))
            if ok:
                pre_ok = True

        # Solve P_trans (R2)
        prompt_trans = PromptBuilder.build_rq1_2_partial_prompt(prob, condition="trans")
        resp_trans = llm.generate(prompt_trans, n_samples=k_partial, temperature=temperature)
        trans_cands: List[Tuple[str, bool]] = []
        trans_ok = False
        for r in resp_trans:
            inv = InvariantExtractor.extract_and_normalize(r, prob)
            ok = verifier.verify_partial(prob, inv, condition="trans")
            trans_cands.append((inv, ok))
            if ok:
                trans_ok = True

        # Solve P_post (R3)
        prompt_post = PromptBuilder.build_rq1_2_partial_prompt(prob, condition="post")
        resp_post = llm.generate(prompt_post, n_samples=k_partial, temperature=temperature)
        post_cands: List[Tuple[str, bool]] = []
        post_ok = False
        for r in resp_post:
            inv = InvariantExtractor.extract_and_normalize(r, prob)
            ok = verifier.verify_partial(prob, inv, condition="post")
            post_cands.append((inv, ok))
            if ok:
                post_ok = True

        if pre_ok:
            results["pre_solved"] += 1
        if trans_ok:
            results["trans_solved"] += 1
        if post_ok:
            results["post_solved"] += 1
        if pre_ok and trans_ok and post_ok:
            results["all_partial_solved"] += 1

        # Solve P_full Combiner
        prompt_full = PromptBuilder.build_rq1_2_combiner_prompt(
            prob, pre_cands, trans_cands, post_cands
        )
        resp_full = llm.generate(prompt_full, n_samples=k_full, temperature=temperature)
        full_ok = False
        for r in resp_full:
            inv = InvariantExtractor.extract_and_normalize(r, prob)
            v_res = verifier.verify(prob, inv)
            if v_res.is_valid:
                full_ok = True
                break

        if full_ok:
            results["full_combiner_solved"] += 1

        results["details"].append({
            "problem": prob.name,
            "pre_ok": pre_ok,
            "trans_ok": trans_ok,
            "post_ok": post_ok,
            "full_ok": full_ok
        })

    return results
