"""S-expression and SyGuS / SMT2 Parser and AST generator."""

import re
from typing import List, Any, Optional, Tuple, Dict
from core.problem import Problem, Variable


def tokenize_sexpr(text: str) -> List[str]:
    """Tokenize S-expression string into parentheses and symbol/literal tokens."""
    # Strip comments starting with ';'
    lines = []
    for line in text.splitlines():
        if ";" in line:
            line = line.split(";", 1)[0]
        lines.append(line)
    cleaned = " ".join(lines)

    # Tokenize parentheses and strings/identifiers
    token_pattern = re.compile(r'\(|\)|"[^"]*"|[^\s()]+')
    return token_pattern.findall(cleaned)


def parse_sexpr_tokens(tokens: List[str]) -> Tuple[Any, List[str]]:
    """Recursively parse tokens into nested Python lists."""
    if not tokens:
        raise ValueError("Unexpected end of tokens while parsing S-expression")

    token = tokens.pop(0)
    if token == "(":
        sub_list = []
        while tokens and tokens[0] != ")":
            sub_list.append(parse_sexpr_tokens(tokens)[0])
        if not tokens:
            raise ValueError("Mismatched opening parenthesis in S-expression")
        tokens.pop(0)  # Remove ')'
        return sub_list, tokens
    elif token == ")":
        raise ValueError("Unexpected closing parenthesis")
    else:
        return token, tokens


def parse_all_sexprs(text: str) -> List[Any]:
    """Parse multiple top-level S-expressions from text."""
    tokens = tokenize_sexpr(text)
    exprs = []
    while tokens:
        expr, tokens = parse_sexpr_tokens(tokens)
        exprs.append(expr)
    return exprs


def sexpr_to_str(expr: Any) -> str:
    """Format Python nested list S-expression back to S-expression string."""
    if isinstance(expr, list):
        return "(" + " ".join(sexpr_to_str(x) for x in expr) + ")"
    return str(expr)


class ASTNode:
    """AST Node for Tree Edit Distance (APTED) computation."""
    def __init__(self, name: str, children: Optional[List["ASTNode"]] = None):
        self.name = name
        self.children: List["ASTNode"] = children or []

    def to_bracket_str(self) -> str:
        """Converts AST to bracket notation required by APTED: {name{child1}{child2}}"""
        # Clean name from special chars for APTED bracket format
        clean_name = self.name.replace("{", "_").replace("}", "_").replace(" ", "")
        if not clean_name:
            clean_name = "node"
        if not self.children:
            return f"{{{clean_name}}}"
        children_str = "".join(child.to_bracket_str() for child in self.children)
        return f"{{{clean_name}{children_str}}}"

    def __repr__(self):
        return self.to_bracket_str()


def sexpr_to_ast(expr: Any) -> ASTNode:
    """Convert an S-expression (nested list or atom) to an ASTNode."""
    if isinstance(expr, list):
        if not expr:
            return ASTNode("nil")
        # First element is usually the operator/function name
        op = str(expr[0])
        children = [sexpr_to_ast(arg) for arg in expr[1:]]
        return ASTNode(op, children)
    else:
        return ASTNode(str(expr))


def normalize_fn_name(name: str) -> str:
    """Normalize function names like pre_fun, pre-f, PreF to standard form."""
    low = name.lower().replace("-", "_")
    if "pre" in low:
        return "PreF"
    elif "trans" in low:
        return "TransF"
    elif "post" in low:
        return "PostF"
    elif "inv" in low:
        return "InvF"
    return name


class SyGusParser:
    """Parser for SyGuS Loop Invariant problems (.sl / .smt2 format)."""

    @staticmethod
    def parse(sygus_content: str, problem_name: str = "problem") -> Problem:
        """Parses a full SyGuS problem string into a Problem object."""
        exprs = parse_all_sexprs(sygus_content)
        
        logic = "LIA"
        variables: List[Variable] = []
        pre_f_body = ""
        trans_f_body = ""
        post_f_body = ""
        gt_inv = None

        for expr in exprs:
            if not isinstance(expr, list) or len(expr) == 0:
                continue

            head = str(expr[0])

            if head == "set-logic" and len(expr) > 1:
                logic = str(expr[1])

            elif head == "synth-inv" and len(expr) >= 3:
                # (synth-inv InvF ((x Int) (y Int)))
                var_decls = expr[2]
                if isinstance(var_decls, list):
                    for v in var_decls:
                        if isinstance(v, list) and len(v) >= 2:
                            variables.append(Variable(name=str(v[0]), type_name=str(v[1])))

            elif head == "define-fun" and len(expr) >= 5:
                fn_name = str(expr[1])
                fn_norm = normalize_fn_name(fn_name)
                args = expr[2]
                ret_type = str(expr[3])
                body = expr[4]

                # If variables weren't extracted from synth-inv, extract from define-fun PreF / PostF
                if not variables and fn_norm in ("PreF", "PostF", "InvF") and isinstance(args, list):
                    for v in args:
                        if isinstance(v, list) and len(v) >= 2:
                            v_name = str(v[0])
                            if not v_name.endswith("!"):
                                variables.append(Variable(name=v_name, type_name=str(v[1])))

                body_str = sexpr_to_str(body)
                if fn_norm == "PreF":
                    pre_f_body = body_str
                elif fn_norm == "TransF":
                    trans_f_body = body_str
                elif fn_norm == "PostF":
                    post_f_body = body_str
                elif fn_norm == "InvF":
                    gt_inv = sexpr_to_str(expr)

        return Problem(
            name=problem_name,
            logic=logic,
            variables=variables,
            pre_f=pre_f_body,
            trans_f=trans_f_body,
            post_f=post_f_body,
            ground_truth_inv=gt_inv,
            raw_sygus=sygus_content
        )
