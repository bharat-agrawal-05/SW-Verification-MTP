"""Unit tests for SMT2 / SyGuS and AST Parser."""

import pytest
from core.parser import SyGusParser, parse_all_sexprs, sexpr_to_ast, ASTNode
from core.problem import Problem, Variable


def test_parse_sexpr():
    text = "(define-fun PreF ((x Int) (y Int)) Bool (and (= x 1) (= y 0)))"
    exprs = parse_all_sexprs(text)
    assert len(exprs) == 1
    assert exprs[0][0] == "define-fun"
    assert exprs[0][1] == "PreF"


def test_sygus_parser():
    sygus_str = """
    (set-logic LIA)
    (synth-inv InvF ((x Int) (y Int)))
    (define-fun PreF ((x Int) (y Int)) Bool (and (= x 1) (= y 0)))
    (define-fun TransF ((x Int) (y Int) (x! Int) (y! Int)) Bool (and (< y 1024) (= x! 0) (= y! (+ y 1))))
    (define-fun PostF ((x Int) (y Int)) Bool (or (< y 1024) (not (= x 1))))
    (inv-constraint InvF PreF TransF PostF)
    (check-synth)
    """
    prob = SyGusParser.parse(sygus_str, problem_name="test_103")
    assert prob.name == "test_103"
    assert prob.logic == "LIA"
    assert len(prob.variables) == 2
    assert prob.var_names == ["x", "y"]
    assert "(= x 1)" in prob.pre_f
    assert "(< y 1024)" in prob.trans_f
    assert "(not (= x 1))" in prob.post_f


def test_ast_bracket_conversion():
    expr = ["and", ["=", "x", "1"], ["=", "y", "0"]]
    ast = sexpr_to_ast(expr)
    bracket = ast.to_bracket_str()
    assert bracket.startswith("{and")
    assert "{={x}{1}}" in bracket
    assert "{={y}{0}}" in bracket
