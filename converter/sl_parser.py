"""
Parser for SMT-LIB / SyGuS .sl files.
Tokenizes and parses S-expressions into structured AST nodes.
"""

import re
from typing import List, Tuple, Any, Optional
from ast_nodes import (
    ASTNode, Var, IntLiteral, FloatLiteral, BoolLiteral, App, Let, Forall, Exists,
    DefineFun, SynthInv, InvConstraint, SyGuSProblem
)


class SExprTokenizer:
    """Tokenizes SMT-LIB / SyGuS text, stripping comments."""

    def __init__(self, text: str):
        self.text = text
        self.pos = 0
        self.length = len(text)

    def next_token(self) -> Optional[str]:
        while self.pos < self.length:
            c = self.text[self.pos]

            # Whitespace
            if c.isspace():
                self.pos += 1
                continue

            # Comment: ';' to end of line
            if c == ';':
                while self.pos < self.length and self.text[self.pos] != '\n':
                    self.pos += 1
                continue

            # Parentheses
            if c in '()':
                self.pos += 1
                return c

            # String literal
            if c == '"':
                start = self.pos
                self.pos += 1
                while self.pos < self.length and self.text[self.pos] != '"':
                    if self.text[self.pos] == '\\' and self.pos + 1 < self.length:
                        self.pos += 2
                    else:
                        self.pos += 1
                if self.pos < self.length:
                    self.pos += 1  # include closing quote
                return self.text[start:self.pos]

            # Atom: identifier, number, symbol
            start = self.pos
            while self.pos < self.length:
                ch = self.text[self.pos]
                if ch.isspace() or ch in '();"':
                    break
                self.pos += 1
            return self.text[start:self.pos]

        return None


def parse_sexpr(tokenizer: SExprTokenizer) -> Any:
    """Parse a single S-expression from tokens."""
    token = tokenizer.next_token()
    if token is None:
        return None

    if token == '(':
        lst = []
        while True:
            # Peek or get next token
            # We call parse_sexpr recursively
            start_pos = tokenizer.pos
            next_t = tokenizer.next_token()
            if next_t is None:
                raise ValueError("Unexpected EOF while parsing S-expression (missing ')')")
            if next_t == ')':
                return lst
            # Rewind token
            tokenizer.pos = start_pos
            elem = parse_sexpr(tokenizer)
            lst.append(elem)
    elif token == ')':
        raise ValueError("Unexpected ')' in input")
    else:
        return token


def parse_all_sexprs(text: str) -> List[Any]:
    """Parse all top-level S-expressions from text."""
    tokenizer = SExprTokenizer(text)
    sexprs = []
    while True:
        s = parse_sexpr(tokenizer)
        if s is None:
            break
        sexprs.append(s)
    return sexprs


def parse_param_list(raw_params: Any) -> List[Tuple[str, str]]:
    """
    Parse parameter list like:
      (('x' 'Int') ('y' 'Int'))
      or (('a' ('Array' 'Int' 'Int')) ('n' 'Int'))
    """
    params = []
    if not isinstance(raw_params, list):
        return params

    for item in raw_params:
        if isinstance(item, list) and len(item) >= 2:
            var_name = item[0]
            var_type_raw = item[1]
            if isinstance(var_type_raw, list):
                # E.g. ('Array' 'Int' 'Int')
                var_type = " ".join(str(x) for x in var_type_raw)
            else:
                var_type = str(var_type_raw)
            params.append((str(var_name), var_type))
    return params


def sexpr_to_ast(sexpr: Any) -> ASTNode:
    """Convert an S-expression structure into an ASTNode."""
    if isinstance(sexpr, str):
        # Check integer literal (including negative like -10)
        if re.fullmatch(r'-?\d+', sexpr):
            return IntLiteral(int(sexpr))
        # Check float literal (e.g. 0.5)
        if re.fullmatch(r'-?\d+\.\d+', sexpr):
            return FloatLiteral(float(sexpr))
        # Check boolean literal
        if sexpr == 'true':
            return BoolLiteral(True)
        if sexpr == 'false':
            return BoolLiteral(False)
        # Variable / symbol
        return Var(sexpr)

    if isinstance(sexpr, int):
        return IntLiteral(sexpr)

    if isinstance(sexpr, bool):
        return BoolLiteral(sexpr)

    if not isinstance(sexpr, list) or len(sexpr) == 0:
        raise ValueError(f"Cannot parse empty or invalid S-expression: {sexpr}")

    head = sexpr[0]

    # Let binding: (let ((x1 e1) (x2 e2) ...) body)
    if head == 'let':
        if len(sexpr) < 3:
            raise ValueError(f"Malformed let expression: {sexpr}")
        raw_bindings = sexpr[1]
        bindings = []
        if isinstance(raw_bindings, list):
            for b in raw_bindings:
                if isinstance(b, list) and len(b) == 2:
                    bindings.append((str(b[0]), sexpr_to_ast(b[1])))
        body = sexpr_to_ast(sexpr[2])
        return Let(bindings, body)

    # Forall: (forall ((j Int) ...) body)
    if head == 'forall':
        if len(sexpr) < 3:
            raise ValueError(f"Malformed forall expression: {sexpr}")
        vars_list = parse_param_list(sexpr[1])
        body = sexpr_to_ast(sexpr[2])
        return Forall(vars_list, body)

    # Exists: (exists ((j Int) ...) body)
    if head == 'exists':
        if len(sexpr) < 3:
            raise ValueError(f"Malformed exists expression: {sexpr}")
        vars_list = parse_param_list(sexpr[1])
        body = sexpr_to_ast(sexpr[2])
        return Exists(vars_list, body)

    # Unary negative number encoded as (- 1)
    if head == '-' and len(sexpr) == 2 and isinstance(sexpr[1], str) and re.fullmatch(r'\d+', sexpr[1]):
        return IntLiteral(-int(sexpr[1]))

    # General function/operator application: (op arg1 arg2 ...)
    op = str(head)
    args = [sexpr_to_ast(arg) for arg in sexpr[1:]]
    return App(op, args)


def parse_sl_file(file_path: str) -> SyGuSProblem:
    """Parse an .sl file into a SyGuSProblem AST structure."""
    with open(file_path, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    sexprs = parse_all_sexprs(content)

    logic = "LIA"
    synth_inv: Optional[SynthInv] = None
    inv_constraint: Optional[InvConstraint] = None
    functions: List[DefineFun] = []

    for sx in sexprs:
        if not isinstance(sx, list) or len(sx) == 0:
            continue

        cmd = sx[0]

        if cmd == 'set-logic' and len(sx) > 1:
            logic = str(sx[1])

        elif cmd == 'synth-inv' and len(sx) >= 3:
            name = str(sx[1])
            params = parse_param_list(sx[2])
            synth_inv = SynthInv(name, params)

        elif cmd == 'inv-constraint' and len(sx) >= 5:
            inv_constraint = InvConstraint(
                inv_name=str(sx[1]),
                pre_name=str(sx[2]),
                trans_name=str(sx[3]),
                post_name=str(sx[4])
            )

        elif cmd == 'define-fun' and len(sx) >= 5:
            name = str(sx[1])
            params = parse_param_list(sx[2])
            ret_type = str(sx[3]) if not isinstance(sx[3], list) else " ".join(str(x) for x in sx[3])
            body_ast = sexpr_to_ast(sx[4])
            functions.append(DefineFun(name=name, params=params, ret_type=ret_type, body=body_ast))

    # Match inv_fun, pre_fun, trans_fun, post_fun
    # Look at inv_constraint first
    inv_name = inv_constraint.inv_name if inv_constraint else (synth_inv.name if synth_inv else "inv_fun")
    pre_name = inv_constraint.pre_name if inv_constraint else "pre_fun"
    trans_name = inv_constraint.trans_name if inv_constraint else "trans_fun"
    post_name = inv_constraint.post_name if inv_constraint else "post_fun"

    f_map = {fn.name: fn for fn in functions}

    # Find the specific functions
    # Note: in some files, define-fun inv-f might appear twice or after a comment
    # We want the verified ground truth definition if present
    inv_fun = f_map.get(inv_name)
    pre_fun = f_map.get(pre_name)
    trans_fun = f_map.get(trans_name)
    post_fun = f_map.get(post_name)

    # Other helper functions (e.g. __node_init_..., __node_trans_...)
    key_names = {inv_name, pre_name, trans_name, post_name}
    other_funs = [fn for fn in functions if fn.name not in key_names]

    return SyGuSProblem(
        logic=logic,
        synth_inv=synth_inv,
        inv_constraint=inv_constraint,
        functions=functions,
        inv_fun=inv_fun,
        pre_fun=pre_fun,
        trans_fun=trans_fun,
        post_fun=post_fun,
        other_funs=other_funs
    )
