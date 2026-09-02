"""LLM Client interfaces and factory function."""

from typing import Dict, Any
from llm.base import BaseLLMClient
from llm.ollama_client import OllamaClient
from llm.openai_client import OpenAICompatibleClient
from llm.hf_client import HuggingFaceClient
from llm.mock_client import MockLLMClient


def get_llm_client(config: Dict[str, Any]) -> BaseLLMClient:
    """Factory creating LLM client according to config dictionary."""
    llm_cfg = config.get("llm", {})
    provider = llm_cfg.get("provider", "openai").lower()
    model_name = llm_cfg.get("model", "bharat-ai")

    if provider in ("openai", "vllm", "lmdeploy", "litellm", "endpoint"):
        openai_cfg = llm_cfg.get("openai", {})
        return OpenAICompatibleClient(
            model_name=model_name,
            base_url=openai_cfg.get("base_url", "http://localhost:3000/v1"),
            api_key=openai_cfg.get("api_key", "EMPTY"),
            timeout=openai_cfg.get("timeout", 120)
        )
    elif provider == "ollama":
        ollama_cfg = llm_cfg.get("ollama", {})
        return OllamaClient(
            model_name=model_name,
            host=ollama_cfg.get("host", "http://localhost:11434"),
            timeout=ollama_cfg.get("timeout", 120)
        )
    elif provider in ("huggingface", "hf", "gpu"):
        hf_cfg = llm_cfg.get("huggingface", {})
        return HuggingFaceClient(
            model_name=hf_cfg.get("model_id", "Qwen/Qwen2.5-32B-Instruct"),
            load_in_4bit=hf_cfg.get("load_in_4bit", True),
            load_in_8bit=hf_cfg.get("load_in_8bit", False),
            torch_dtype=hf_cfg.get("torch_dtype", "bfloat16"),
            device_map=hf_cfg.get("device_map", "auto")
        )
    elif provider in ("mock", "test", "dummy"):
        return MockLLMClient(model_name=model_name)
    else:
        raise ValueError(f"Unknown LLM provider: {provider}")


__all__ = [
    "BaseLLMClient",
    "OllamaClient",
    "OpenAICompatibleClient",
    "HuggingFaceClient",
    "MockLLMClient",
    "get_llm_client",
]
