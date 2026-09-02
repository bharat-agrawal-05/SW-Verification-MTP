"""Base LLM Client interface."""

from abc import ABC, abstractmethod
from typing import List, Dict, Any, Optional


class BaseLLMClient(ABC):
    """Abstract interface for querying Large Language Models."""

    def __init__(self, model_name: str = "bharat-ai", **kwargs):
        self.model_name = model_name
        self.kwargs = kwargs

    @abstractmethod
    def generate(
        self,
        prompt: str,
        n_samples: int = 1,
        temperature: float = 0.7,
        max_tokens: int = 2048,
        stop: Optional[List[str]] = None
    ) -> List[str]:
        """Generates n candidate responses for a given prompt."""
        pass

    def count_tokens(self, text: str) -> int:
        """Heuristic or tokenizer-based token counter."""
        # Simple whitespace heuristic fallback (~1.3 tokens per word)
        return int(len(text.split()) * 1.3)
