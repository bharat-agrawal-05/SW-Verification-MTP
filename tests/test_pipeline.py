"""Integration tests for all experiment pipelines (RQ1.1 - RQ2.2) using Mock client."""

import pytest
from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from benchmarks.benchmark_loader import get_default_benchmark_problems
from llm.mock_client import MockLLMClient
from experiments.rq1_1_instructions import run_rq1_1
from experiments.rq1_2_partitioning import run_rq1_2
from experiments.rq1_3_similarity import run_rq1_3
from experiments.rq1_4_example_types import run_rq1_4
from experiments.rq1_5_integrated import run_rq1_5
from experiments.rq2_1_repair_errors import run_rq2_1
from experiments.rq2_2_repair_counterexamples import run_rq2_2
from experiments.rq3_enhanced_cegis import run_enhanced_cegis
from experiments.runner import ExperimentRunner


@pytest.fixture
def test_setup():
    problems = get_default_benchmark_problems()[:2]
    llm = MockLLMClient()
    verifier = InvariantVerifier(timeout_ms=5000)
    finder = ExampleFinder(problem_pool=problems)
    return problems, llm, verifier, finder


def test_rq1_1_pipeline(test_setup):
    problems, llm, verifier, _ = test_setup
    res = run_rq1_1(problems, llm, verifier, k_samples=5)
    assert "with_instructions" in res
    assert "without_instructions" in res
    assert res["with_instructions"]["total"] == len(problems)


def test_rq1_2_pipeline(test_setup):
    problems, llm, verifier, _ = test_setup
    res = run_rq1_2(problems, llm, verifier, k_partial=3, k_full=5)
    assert "pre_solved" in res
    assert "full_combiner_solved" in res


def test_rq1_3_pipeline(test_setup):
    problems, llm, verifier, finder = test_setup
    res = run_rq1_3(problems, llm, verifier, finder, k_samples=5, n_few_shot=1)
    assert "S_semantic" in res
    assert "S_syntactic" in res


def test_rq1_4_pipeline(test_setup):
    problems, llm, verifier, finder = test_setup
    res = run_rq1_4(problems, llm, verifier, finder, k_samples=5, n_few_shot=1)
    assert "EX_P" in res
    assert "EX_N" in res
    assert "EX_Mix" in res


def test_rq1_5_pipeline(test_setup):
    problems, llm, verifier, finder = test_setup
    res = run_rq1_5(problems, llm, verifier, finder, k_samples=5, n_few_shot=1)
    assert "integrated" in res


def test_rq2_1_pipeline(test_setup):
    problems, llm, verifier, _ = test_setup
    res = run_rq2_1(problems, llm, verifier, n_incorrect_per_problem=1)
    assert "attempted_invariants" in res
    assert "successful_repairs" in res


def test_rq2_2_pipeline(test_setup):
    problems, llm, verifier, _ = test_setup
    res = run_rq2_2(problems, llm, verifier, n_incorrect_per_problem=1, max_repair_turns=2)
    assert "single_turn_successful_repairs" in res
    assert "multi_turn_successful_repairs" in res
    assert len(res["trajectories"]) > 0


def test_enhanced_cegis_pipeline(test_setup):
    problems, llm, verifier, finder = test_setup
    res = run_enhanced_cegis(problems, llm, verifier, finder, max_turns=2)
    assert "num_problems" in res
    assert "total_solved" in res
    assert "cumulative_success_rates" in res
    assert len(res["trajectories"]) > 0


def test_experiment_runner_all():
    config = {
        "llm": {"provider": "mock", "model": "mock-qwen3.8:27b"},
        "verifier": {"timeout_ms": 5000},
        "benchmarks": {"subset_size": 2},
        "similarity": {"semantic_model": "all-MiniLM-L6-v2"},
        "output": {"results_dir": "results_test"}
    }
    runner = ExperimentRunner(config)
    runner.run(target_rq="rq1_1", k_samples=2)
