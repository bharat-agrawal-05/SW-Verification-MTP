"""Syntactic AST Similarity (S_syntactic) computation using APTED Tree Edit Distance."""

from typing import Tuple
from apted import APTED, Config
from core.problem import Problem
from core.parser import parse_all_sexprs, sexpr_to_ast, ASTNode


def count_ast_nodes(node: ASTNode) -> int:
    """Recursively count nodes in an AST."""
    return 1 + sum(count_ast_nodes(child) for child in node.children)


def formula_to_ast(formula_str: str) -> ASTNode:
    """Parse formula string into ASTNode."""
    exprs = parse_all_sexprs(formula_str)
    if not exprs:
        return ASTNode("true")
    return sexpr_to_ast(exprs[0])


def tree_edit_distance(ast1: ASTNode, ast2: ASTNode) -> Tuple[float, int, int]:
    """Compute APTED tree edit distance and tree node counts."""
    bracket1 = ast1.to_bracket_str()
    bracket2 = ast2.to_bracket_str()
    
    n1 = count_ast_nodes(ast1)
    n2 = count_ast_nodes(ast2)

    try:
        from apted.helpers import Tree
        t1 = Tree.from_text(bracket1)
        t2 = Tree.from_text(bracket2)
        apted_solver = APTED(t1, t2)
        dist = apted_solver.compute_edit_distance()
        return float(dist), n1, n2
    except Exception:
        # Fallback if APTED fails on ill-formed bracket string
        return float(max(n1, n2)), n1, n2


def compute_tree_similarity(ast1: ASTNode, ast2: ASTNode) -> float:
    """Computes normalized similarity in [0, 1] between two ASTs."""
    dist, n1, n2 = tree_edit_distance(ast1, ast2)
    max_dist = max(1, n1 + n2)
    sim = max(0.0, 1.0 - (dist / max_dist))
    return min(1.0, sim)


class SyntacticSimilarity:
    """Computes S_syntactic between two Loop Invariant problems P and Q as described in Section IV-C2(b)."""

    @classmethod
    def compute(cls, p: Problem, q: Problem) -> float:
        """Calculates mathematical average of APTED similarities across PreF, TransF, and PostF."""
        ast_pre_p = formula_to_ast(p.pre_f)
        ast_pre_q = formula_to_ast(q.pre_f)
        sim_pre = compute_tree_similarity(ast_pre_p, ast_pre_q)

        ast_trans_p = formula_to_ast(p.trans_f)
        ast_trans_q = formula_to_ast(q.trans_f)
        sim_trans = compute_tree_similarity(ast_trans_p, ast_trans_q)

        ast_post_p = formula_to_ast(p.post_f)
        ast_post_q = formula_to_ast(q.post_f)
        sim_post = compute_tree_similarity(ast_post_p, ast_post_q)

        return (sim_pre + sim_trans + sim_post) / 3.0
