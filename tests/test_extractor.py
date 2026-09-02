"""Unit tests for invariant extractor and heuristic syntax repair."""

from core.extractor import InvariantExtractor
from core.problem import Problem, Variable


def test_parentheses_balancing():
    # Missing closing
    unbalanced_1 = "(and (= x 1) (<= y 1024)"
    balanced_1 = InvariantExtractor.balance_parentheses(unbalanced_1)
    assert balanced_1 == "(and (= x 1) (<= y 1024))"

    # Excess closing
    unbalanced_2 = "(and (= x 1) (<= y 1024)))"
    balanced_2 = InvariantExtractor.balance_parentheses(unbalanced_2)
    assert balanced_2 == "(and (= x 1) (<= y 1024))"


def test_strip_stray_keywords():
    s1 = "code ((...) Bool (and (= x 1)))"
    assert InvariantExtractor.strip_stray_keywords(s1) == "((...) Bool (and (= x 1)))"

    s2 = "scheme (and (= x 1))"
    assert InvariantExtractor.strip_stray_keywords(s2) == "(and (= x 1))"


def test_extract_and_normalize():
    prob = Problem(
        name="test",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int")],
        pre_f="(= x 1)",
        trans_f="(= x! x)",
        post_f="(= x 1)"
    )

    # From code block
    llm_resp = "Here is the invariant:\n```lisp\n(or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024)))\n```"
    extracted = InvariantExtractor.extract_and_normalize(llm_resp, prob)
    assert extracted.startswith("(define-fun InvF ((x Int) (y Int)) Bool")
    assert "(or (and (= x 1) (< y 1024))" in extracted
    assert InvariantExtractor.is_syntactically_valid(extracted) is True

    # From <code> tag
    llm_resp2 = "<code> (define-fun InvF ((x Int) (y Int)) Bool (<= y 1024)) </code>"
    extracted2 = InvariantExtractor.extract_and_normalize(llm_resp2, prob)
    assert extracted2 == "(define-fun InvF ((x Int) (y Int)) Bool (<= y 1024))"
    assert InvariantExtractor.is_syntactically_valid(extracted2) is True
