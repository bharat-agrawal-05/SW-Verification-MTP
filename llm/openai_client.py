"""OpenAI-compatible Client for vLLM, LMDeploy, LiteLLM, or OpenAI/Mistral endpoints."""

import requests
from typing import List, Optional
from llm.base import BaseLLMClient


class OpenAICompatibleClient(BaseLLMClient):
    """Client for any OpenAI-compatible API endpoint (such as http://localhost:3000/v1 with model 'bharat-ai')."""

    def __init__(
        self,
        model_name: str = "bharat-ai",
        base_url: str = "http://localhost:3000/v1",
        api_key: str = "EMPTY",
        timeout: int = 120,
        **kwargs
    ):
        super().__init__(model_name=model_name, **kwargs)
        self.base_url = base_url.rstrip("/")
        self.api_key = api_key
        self.timeout = timeout

    def generate(
        self,
        prompt: str,
        n_samples: int = 1,
        temperature: float = 0.7,
        max_tokens: int = 2048,
        stop: Optional[List[str]] = None
    ) -> List[str]:
        """Generates n candidate responses using completions or chat completions."""
        url = f"{self.base_url}/chat/completions"
        headers = {
            "Content-Type": "application/json",
            "Authorization": f"Bearer {self.api_key}"
        }
        
        payload = {
            "model": self.model_name,
            "messages": [{"role": "user", "content": prompt}],
            "temperature": temperature,
            "max_tokens": max_tokens,
            "n": n_samples
        }
        if stop:
            payload["stop"] = stop

        try:
            resp = requests.post(url, headers=headers, json=payload, timeout=self.timeout)
            resp.raise_for_status()
            data = resp.json()
            choices = data.get("choices", [])
            return [c.get("message", {}).get("content", "") for c in choices]
        except Exception:
            # Fallback to sequential calls if batch n is not supported by endpoint
            results = []
            for _ in range(n_samples):
                payload["n"] = 1
                try:
                    resp = requests.post(url, headers=headers, json=payload, timeout=self.timeout)
                    resp.raise_for_status()
                    data = resp.json()
                    choices = data.get("choices", [])
                    results.append(choices[0].get("message", {}).get("content", "") if choices else "")
                except Exception as err:
                    results.append(f"; Error querying endpoint {url}: {err}")
            return results
