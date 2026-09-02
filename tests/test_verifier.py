"""Unit tests for Z3 formal verification engine and counterexample generation."""

import pytest
from core.problem import Problem, Variable
from core.verifier import InvariantVerifier


@pytest.fixture
def sample_problem():
    return Problem(
        name="fig1_103",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int")],
        pre_f="(and (= x 1) (= y 0))",
        trans_f="(and (< y 1024) (= x! 0) (= y! (+ y 1)))",
        post_f="(or (< y 1024) (not (= x 1)))"
    )


def test_valid_inductive_invariant(sample_problem):
    verifier = InvariantVerifier()
    valid_inv = "(define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024))))"
    res = verifier.verify(sample_problem, valid_inv)
    assert res.is_valid is True
    assert res.r1_holds is True
    assert res.r2_holds is True
    assert res.r3_holds is True


def test_invalid_invariant_counterexample(sample_problem):
    verifier = InvariantVerifier()
    # Invariant that fails postcondition or transition
    invalid_inv = "(define-fun InvF ((x Int) (y Int)) Bool (= x 1))"
    res = verifier.verify(sample_problem, invalid_inv)
    assert res.is_valid is False
    assert res.failed_rule is not None
    assert res.error_details is not None
    assert res.counterexample_str is not None
    assert len(res.counterexample_model) > 0


def test_partial_verification(sample_problem):
    verifier = InvariantVerifier()
    # (= x 1) satisfies pre-condition PreF => InvF
    inv_pre = "(define-fun InvF ((x Int) (y Int)) Bool (= x 1))"
    assert verifier.verify_partial(sample_problem, inv_pre, condition="pre") is True

    # (<= y 1024) satisfies transition condition
    inv_trans = "(define-fun InvF ((x Int) (y Int)) Bool (<= y 1024))"
    assert verifier.verify_partial(sample_problem, inv_trans, condition="trans") is True

    # (not (= x 1)) satisfies postcondition InvF => PostF
    inv_post = "(define-fun InvF ((x Int) (y Int)) Bool (not (= x 1)))"
    assert verifier.verify_partial(sample_problem, inv_post, condition="post") is True
