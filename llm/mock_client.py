"""Mock LLM Client for self-contained testing, dry-runs, and offline CI."""

import re
from typing import List, Optional
from llm.base import BaseLLMClient


class MockLLMClient(BaseLLMClient):
    """Deterministic Mock LLM client for testing and verifying pipeline workflows without GPU."""

    def __init__(self, model_name: str = "mock-qwen3.8:27b", **kwargs):
        super().__init__(model_name=model_name, **kwargs)

    def generate(
        self,
        prompt: str,
        n_samples: int = 1,
        temperature: float = 0.7,
        max_tokens: int = 2048,
        stop: Optional[List[str]] = None
    ) -> List[str]:
        """Generates mock responses based on prompt structure."""
        results = []

        # Detect prompt type
        if "Repair the invariant" in prompt or "Now repair the invariant" in prompt:
            # Repair prompt
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024)))) </code>"
        elif "pre-f implies inv-f" in prompt and "combine the correct invariants" in prompt:
            # Combiner prompt
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (and (>= x 0) (<= y 1024))) </code>"
        elif "satisfy the condition ``` PreF implies InvF" in prompt:
            # Partial Pre
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (= x 1)) </code>"
        elif "satisfy the condition ``` inv-f implies post-f" in prompt:
            # Partial Post
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (or (< y 1024) (not (= x 1)))) </code>"
        elif "satisfy the condition" in prompt and "trans" in prompt:
            # Partial Trans
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (<= y 1024)) </code>"
        elif "A loop invariant synthesis problem is given below" in prompt:
            # Few-shot prompt
            response = "<code> (define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024)))) </code>"
        else:
            # General instruction prompt
            response = "```lisp\n(define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024))))\n```"

        for _ in range(n_samples):
            results.append(response)

        return results
