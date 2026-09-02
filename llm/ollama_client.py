"""Ollama Client for local/remote Ollama instances (e.g. qwen3.8:27b, qwen2.5:32b)."""

import requests
from typing import List, Optional
from llm.base import BaseLLMClient


class OllamaClient(BaseLLMClient):
    """Client for Ollama REST API supporting Qwen models."""

    def __init__(self, model_name: str = "qwen3.8:27b", host: str = "http://localhost:11434", timeout: int = 120, **kwargs):
        super().__init__(model_name=model_name, **kwargs)
        self.host = host.rstrip("/")
        self.timeout = timeout

    def generate(
        self,
        prompt: str,
        n_samples: int = 1,
        temperature: float = 0.7,
        max_tokens: int = 2048,
        stop: Optional[List[str]] = None
    ) -> List[str]:
        """Generates n candidate responses from Ollama."""
        url = f"{self.host}/api/generate"
        results = []

        for _ in range(n_samples):
            payload = {
                "model": self.model_name,
                "prompt": prompt,
                "stream": False,
                "options": {
                    "temperature": temperature,
                    "num_predict": max_tokens,
                }
            }
            if stop:
                payload["options"]["stop"] = stop

            try:
                resp = requests.post(url, json=payload, timeout=self.timeout)
                resp.raise_for_status()
                data = resp.json()
                results.append(data.get("response", ""))
            except Exception as e:
                # Fallback on network or endpoint error
                results.append(f"; Error querying Ollama at {url}: {e}")

        return results
