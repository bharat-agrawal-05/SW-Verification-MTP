#!/usr/bin/env python3
"""Main Entrypoint and CLI for LLM Loop Invariant Generation and Fixing Framework.

Based on the paper:
'LLM For Loop Invariant Generation and Fixing: How Far Are We?'
(Akhond, Chakraborty, Uddin, 2025)
"""

import argparse
import sys
import yaml
import os

from experiments.runner import ExperimentRunner
from core.problem import Problem, Variable
from core.verifier import InvariantVerifier
from core.extractor import InvariantExtractor


def load_config(config_path: str) -> dict:
    if not os.path.exists(config_path):
        print(f"Warning: Config file {config_path} not found. Using default internal settings.")
        return {}
    with open(config_path, "r", encoding="utf-8") as f:
        return yaml.safe_load(f) or {}


def main():
    parser = argparse.ArgumentParser(
        description="LLM Loop Invariant Generation and Fixing (Qwen 3.8:27B / GPU Benchmark Suite)"
    )
    parser.add_argument(
        "--config",
        type=str,
        default="config/default_config.yaml",
        help="Path to YAML configuration file"
    )
    parser.add_argument(
        "--rq",
        type=str,
        default="all",
        choices=["rq1_1", "rq1_2", "rq1_3", "rq1_4", "rq1_5", "rq2_1", "rq2_2", "cegis", "rq3_cegis", "all"],
        help="Specific Research Question experiment to execute"
    )
    parser.add_argument(
        "--provider",
        type=str,
        default=None,
        choices=["ollama", "openai", "huggingface", "mock"],
        help="Override LLM provider (ollama, openai / vllm, huggingface, or mock)"
    )
    parser.add_argument(
        "--model",
        type=str,
        default=None,
        help="Override model identifier (e.g. qwen3.8:27b, Qwen/Qwen2.5-32B-Instruct)"
    )
    parser.add_argument(
        "--ollama-host",
        type=str,
        default=None,
        help="Ollama host endpoint URL (e.g. http://localhost:11434)"
    )
    parser.add_argument(
        "--openai-url",
        type=str,
        default=None,
        help="OpenAI/vLLM base URL (e.g. http://localhost:8000/v1)"
    )
    parser.add_argument(
        "--k",
        type=int,
        default=None,
        help="Number of samples to generate per problem (k=10, 30, 50)"
    )
    parser.add_argument(
        "--subset-size",
        type=int,
        default=None,
        help="Number of problems to evaluate from benchmark"
    )
    parser.add_argument(
        "--verify-invariant",
        type=str,
        default=None,
        help="Directly verify a specific candidate invariant string with Z3"
    )

    args = parser.parse_args()
    config = load_config(args.config)

    # CLI overrides
    if args.provider:
        if "llm" not in config:
            config["llm"] = {}
        config["llm"]["provider"] = args.provider

    if args.model:
        if "llm" not in config:
            config["llm"] = {}
        config["llm"]["model"] = args.model

    if args.ollama_host:
        config.setdefault("llm", {}).setdefault("ollama", {})["host"] = args.ollama_host

    if args.openai_url:
        config.setdefault("llm", {}).setdefault("openai", {})["base_url"] = args.openai_url

    if args.subset_size:
        config.setdefault("benchmarks", {})["subset_size"] = args.subset_size

    k_samples = args.k or config.get("llm", {}).get("generation", {}).get("default_k", 50)

    # Direct invariant verification mode
    if args.verify_invariant:
        print("\n--- Direct Invariant Verification Mode ---")
        prob = Problem(
            name="interactive_test",
            logic="LIA",
            variables=[Variable("x", "Int"), Variable("y", "Int")],
            pre_f="(and (= x 1) (= y 0))",
            trans_f="(and (< y 1024) (= x! 0) (= y! (+ y 1)))",
            post_f="(or (< y 1024) (not (= x 1)))"
        )
        verifier = InvariantVerifier()
        normalized = InvariantExtractor.extract_and_normalize(args.verify_invariant, prob)
        print(f"Testing Invariant: {normalized}")
        res = verifier.verify(prob, normalized)
        print(f"Valid: {res.is_valid}")
        print(f"R1 (Pre => Inv): {res.r1_holds}")
        print(f"R2 (Inv /\\ Trans => Inv'): {res.r2_holds}")
        print(f"R3 (Inv => Post): {res.r3_holds}")
        if not res.is_valid:
            print(f"Failed Rule: {res.failed_rule}")
            print(f"Error Details: {res.error_details}")
            print(f"Counterexample: {res.counterexample_str}")
        return

    # Run experiment runner
    print("=" * 80)
    print("LLM For Loop Invariant Generation and Fixing: Empirical Evaluation")
    print(f"Target Model: {config.get('llm', {}).get('model', 'bharat-ai')} | Provider: {config.get('llm', {}).get('provider', 'openai')} | Endpoint: {config.get('llm', {}).get('openai', {}).get('base_url', 'http://localhost:3000/v1')}")
    print("=" * 80)

    runner = ExperimentRunner(config)
    runner.run(target_rq=args.rq, k_samples=k_samples)


if __name__ == "__main__":
    main()
