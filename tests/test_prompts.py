"""Unit tests for prompt builders matching paper templates."""

from core.problem import Problem, Variable
from similarity.example_finder import ExampleFinder
from prompts.builder import PromptBuilder
from benchmarks.benchmark_loader import get_default_benchmark_problems


def test_rq1_1_prompt_formatting():
    prob = Problem(
        name="test_103",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int")],
        pre_f="(= x 1)",
        trans_f="(= x! 0)",
        post_f="(= x 0)"
    )
    prompt_inst = PromptBuilder.build_rq1_1_prompt(prob, with_instructions=True)
    assert "You have to follow the instructions" in prompt_inst
    assert "3.1 Before the loop execution (pre-f)" in prompt_inst
    assert "Do not use non-deterministic function calls" in prompt_inst
    assert "(define-fun PreF" in prompt_inst

    prompt_base = PromptBuilder.build_rq1_1_prompt(prob, with_instructions=False)
    assert "Synthesize an inductive loop invariant" in prompt_base
    assert "3.1 Before the loop execution" not in prompt_base


def test_rq1_2_partial_and_combiner_prompts():
    prob = Problem(
        name="test_partial",
        logic="LIA",
        variables=[Variable("n", "Int"), Variable("i", "Int")],
        pre_f="(= i 0)",
        trans_f="(= i! (+ i 1))",
        post_f="(>= i n)"
    )
    p_pre = PromptBuilder.build_rq1_2_partial_prompt(prob, "pre")
    assert "PreF implies InvF" in p_pre
    assert "<code> and </code>" in p_pre

    p_trans = PromptBuilder.build_rq1_2_partial_prompt(prob, "trans")
    assert "( trans-f and inv-f ) implies inv-f!" in p_trans

    p_comb = PromptBuilder.build_rq1_2_combiner_prompt(
        prob,
        pre_invariants=[("(define-fun InvF ...)", True)],
        trans_invariants=[("(define-fun InvF ...)", False)],
        post_invariants=[("(define-fun InvF ...)", True)]
    )
    assert "which was correct" in p_comb
    assert "which was wrong" in p_comb
    assert "combine the correct invariants" in p_comb


def test_rq2_repair_prompts():
    prob = Problem(
        name="fig1_103",
        variables=[Variable("x", "Int"), Variable("y", "Int")]
    )
    p_err = PromptBuilder.build_rq2_1_repair_prompt(
        prob,
        failed_inv="(define-fun InvF ((x Int)) Bool false)",
        error_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
        error_details="Failed to satisfy the condition (=> (PreF x y) (InvF x y))"
    )
    assert "Cause of error :" in p_err
    assert "Error details:" in p_err

    p_ce = PromptBuilder.build_rq2_2_repair_prompt(
        prob,
        failed_inv="(define-fun InvF ((x Int)) Bool false)",
        error_details="Failed to satisfy condition",
        counterexample_values="x = 1, y = 0, x! = 0, y! = 1"
    )
    assert "For the values x = 1, y = 0" in p_ce
