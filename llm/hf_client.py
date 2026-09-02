"""Direct HuggingFace Transformers pipeline for NVIDIA RTX A5000 GPU (24GB VRAM)."""

from typing import List, Optional
from llm.base import BaseLLMClient


class HuggingFaceClient(BaseLLMClient):
    """Direct HuggingFace Transformers GPU Client with 4-bit/8-bit quantization support for RTX A5000."""

    def __init__(
        self,
        model_name: str = "Qwen/Qwen2.5-32B-Instruct",
        load_in_4bit: bool = True,
        load_in_8bit: bool = False,
        torch_dtype: str = "bfloat16",
        device_map: str = "auto",
        **kwargs
    ):
        super().__init__(model_name=model_name, **kwargs)
        self.load_in_4bit = load_in_4bit
        self.load_in_8bit = load_in_8bit
        self.torch_dtype_str = torch_dtype
        self.device_map = device_map
        self._model = None
        self._tokenizer = None

    def _init_pipeline(self):
        if self._model is not None:
            return

        import torch
        from transformers import AutoModelForCausalLM, AutoTokenizer, BitsAndBytesConfig

        dtype = torch.bfloat16 if self.torch_dtype_str == "bfloat16" else torch.float16

        bnb_config = None
        if self.load_in_4bit:
            bnb_config = BitsAndBytesConfig(
                load_in_4bit=True,
                bnb_4bit_use_double_quant=True,
                bnb_4bit_quant_type="nf4",
                bnb_4bit_compute_dtype=dtype,
            )
        elif self.load_in_8bit:
            bnb_config = BitsAndBytesConfig(load_in_8bit=True)

        self._tokenizer = AutoTokenizer.from_pretrained(
            self.model_name,
            trust_remote_code=True,
            padding_side="left"
        )
        if self._tokenizer.pad_token is None:
            self._tokenizer.pad_token = self._tokenizer.eos_token

        self._model = AutoModelForCausalLM.from_pretrained(
            self.model_name,
            quantization_config=bnb_config,
            torch_dtype=dtype,
            device_map=self.device_map,
            trust_remote_code=True,
        )

    def generate(
        self,
        prompt: str,
        n_samples: int = 1,
        temperature: float = 0.7,
        max_tokens: int = 2048,
        stop: Optional[List[str]] = None
    ) -> List[str]:
        """Generates n candidate invariants using GPU model."""
        self._init_pipeline()
        import torch

        # Format with chat template if available
        messages = [{"role": "user", "content": prompt}]
        if hasattr(self._tokenizer, "apply_chat_template"):
            input_text = self._tokenizer.apply_chat_template(
                messages, tokenize=False, add_generation_prompt=True
            )
        else:
            input_text = prompt

        inputs = self._tokenizer(input_text, return_tensors="pt").to(self._model.device)
        input_len = inputs.input_ids.shape[1]

        results = []
        # Generate samples (in batches if needed)
        with torch.no_grad():
            outputs = self._model.generate(
                **inputs,
                max_new_tokens=max_tokens,
                temperature=temperature if temperature > 0 else 1.0,
                do_sample=(temperature > 0),
                num_return_sequences=n_samples,
                pad_token_id=self._tokenizer.pad_token_id,
                eos_token_id=self._tokenizer.eos_token_id,
            )

            for i in range(n_samples):
                gen_tokens = outputs[i][input_len:]
                decoded = self._tokenizer.decode(gen_tokens, skip_special_tokens=True)
                results.append(decoded)

        return results
