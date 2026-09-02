"""Unit tests for AST Syntactic (APTED) and Semantic similarity computation."""

import pytest
from core.problem import Problem, Variable
from similarity.syntactic import SyntacticSimilarity, formula_to_ast, compute_tree_similarity
from similarity.semantic import SemanticSimilarity
from similarity.example_finder import ExampleFinder
from benchmarks.benchmark_loader import get_default_benchmark_problems


def test_tree_similarity():
    ast1 = formula_to_ast("(= x 1)")
    ast2 = formula_to_ast("(= x 1)")
    sim_identical = compute_tree_similarity(ast1, ast2)
    assert sim_identical == 1.0

    ast3 = formula_to_ast("(and (> x 10) (< y 20))")
    sim_diff = compute_tree_similarity(ast1, ast3)
    assert 0.0 <= sim_diff < 1.0


def test_syntactic_similarity_problems():
    problems = get_default_benchmark_problems()
    p1 = problems[0]
    p2 = problems[1]
    
    # Self similarity is 1.0
    sim_self = SyntacticSimilarity.compute(p1, p1)
    assert sim_self == 1.0

    sim_p1_p2 = SyntacticSimilarity.compute(p1, p2)
    assert 0.0 <= sim_p1_p2 <= 1.0


def test_example_finder():
    problems = get_default_benchmark_problems()
    finder = ExampleFinder(problem_pool=problems)
    
    similar = finder.find_similar(problems[0], n=2, metric="syntactic")
    assert len(similar) == 2
    assert similar[0][0].name != problems[0].name

    # Check formatting
    ex_p = finder.format_example(problems[0], example_type="EX_P")
    assert "A successful invariant:" in ex_p

    ex_n = finder.format_example(problems[0], example_type="EX_N")
    assert "An Unsuccessful invariant:" in ex_n

    ex_mix = finder.format_example(problems[0], example_type="EX_Mix")
    assert "A successful invariant:" in ex_mix
    assert "An Unsuccessful invariant:" in ex_mix
