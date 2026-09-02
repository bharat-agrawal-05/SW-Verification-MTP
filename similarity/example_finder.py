"""Example Finder for retrieving similar problems using S_syntactic or S_semantic and formatting few-shot examples."""

from typing import List, Tuple, Optional
from core.problem import Problem
from similarity.syntactic import SyntacticSimilarity
from similarity.semantic import SemanticSimilarity


class ExampleFinder:
    """Finds top-n similar problems from a benchmark dataset and formats them for few-shot prompts."""

    def __init__(self, problem_pool: List[Problem], semantic_model_name: str = "all-MiniLM-L6-v2"):
        self.problem_pool = problem_pool
        self.semantic_sim = SemanticSimilarity(model_name=semantic_model_name)

    def find_similar(
        self,
        query: Problem,
        n: int = 2,
        metric: str = "syntactic"  # "syntactic" or "semantic"
    ) -> List[Tuple[Problem, float]]:
        """Finds top-n most similar problems from the pool (excluding query problem)."""
        scored_candidates = []

        for candidate in self.problem_pool:
            if candidate.name == query.name:
                continue

            if metric == "syntactic":
                score = SyntacticSimilarity.compute(query, candidate)
            elif metric == "semantic":
                score = self.semantic_sim.compute(query, candidate)
            else:
                raise ValueError(f"Unknown similarity metric: {metric}")

            scored_candidates.append((candidate, score))

        # Sort descending by similarity score
        scored_candidates.sort(key=lambda x: x[1], reverse=True)
        return scored_candidates[:n]

    @staticmethod
    def format_example(problem: Problem, example_type: str = "EX_P") -> str:
        """Formats a single problem and its invariant(s) according to Table VI in the paper."""
        funcs = problem.to_smt_functions_str()
        gt_inv = problem.ground_truth_inv or f"{problem.get_inv_signature()} true)"

        if example_type == "EX_P":
            return (
                f"Problem :\n"
                f"*** {funcs} ***\n"
                f"A successful invariant: {gt_inv}"
            )

        elif example_type == "EX_N":
            if problem.negative_examples:
                neg = problem.negative_examples[0]
                neg_inv = neg.candidate_inv
                reason = f"{neg.failure_cause} - {neg.failure_details}"
            else:
                # Default negative invariant fallback
                neg_inv = f"{problem.get_inv_signature()} false)"
                reason = "Verifier found counterexample violating pre-condition"

            return (
                f"Problem :\n"
                f"*** {funcs} ***\n"
                f"An Unsuccessful invariant: {neg_inv} Because: {reason}"
            )

        elif example_type == "EX_Mix":
            if problem.negative_examples:
                neg = problem.negative_examples[0]
                neg_inv = neg.candidate_inv
                reason = f"{neg.failure_cause} - {neg.failure_details}"
            else:
                neg_inv = f"{problem.get_inv_signature()} false)"
                reason = "Verifier found counterexample violating pre-condition"

            return (
                f"Problem :\n"
                f"*** {funcs} ***\n"
                f"A successful invariant: {gt_inv}\n"
                f"An Unsuccessful invariant: {neg_inv} Because: {reason}"
            )

        else:
            raise ValueError(f"Unknown example type: {example_type}. Must be EX_P, EX_N, or EX_Mix.")

    def build_few_shot_block(
        self,
        query: Problem,
        n: int = 2,
        metric: str = "syntactic",
        example_type: str = "EX_P"
    ) -> str:
        """Retrieves top-n examples and formats the full few-shot block."""
        top_matches = self.find_similar(query, n=n, metric=metric)
        example_blocks = []
        for prob, _ in top_matches:
            formatted = self.format_example(prob, example_type=example_type)
            example_blocks.append(formatted)

        return "\n\n".join(example_blocks)
