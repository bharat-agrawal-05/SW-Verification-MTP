"""
Abstract Syntax Tree (AST) node definitions for SMT-LIB / SyGuS problems.
"""

from dataclasses import dataclass
from typing import List, Tuple, Optional, Any, Union


class ASTNode:
    """Base class for all AST nodes."""
    pass


@dataclass
class Var(ASTNode):
    name: str

    def __repr__(self):
        return f"Var({self.name})"


@dataclass
class IntLiteral(ASTNode):
    value: int

    def __repr__(self):
        return f"IntLiteral({self.value})"


@dataclass
class FloatLiteral(ASTNode):
    value: float

    def __repr__(self):
        return f"FloatLiteral({self.value})"


@dataclass
class BoolLiteral(ASTNode):
    value: bool

    def __repr__(self):
        return f"BoolLiteral({self.value})"


@dataclass
class App(ASTNode):
    op: str
    args: List[ASTNode]

    def __repr__(self):
        return f"App({self.op}, {self.args})"


@dataclass
class Let(ASTNode):
    bindings: List[Tuple[str, ASTNode]]  # [(var_name, expr), ...]
    body: ASTNode

    def __repr__(self):
        return f"Let({self.bindings}, {self.body})"


@dataclass
class Forall(ASTNode):
    vars: List[Tuple[str, str]]  # [(var_name, var_type), ...]
    body: ASTNode

    def __repr__(self):
        return f"Forall({self.vars}, {self.body})"


@dataclass
class Exists(ASTNode):
    vars: List[Tuple[str, str]]  # [(var_name, var_type), ...]
    body: ASTNode

    def __repr__(self):
        return f"Exists({self.vars}, {self.body})"


@dataclass
class DefineFun:
    name: str
    params: List[Tuple[str, str]]  # [(param_name, param_type), ...]
    ret_type: str
    body: ASTNode


@dataclass
class SynthInv:
    name: str
    params: List[Tuple[str, str]]


@dataclass
class InvConstraint:
    inv_name: str
    pre_name: str
    trans_name: str
    post_name: str


@dataclass
class SyGuSProblem:
    logic: str
    synth_inv: Optional[SynthInv]
    inv_constraint: Optional[InvConstraint]
    functions: List[DefineFun]  # all define-fun declarations in the order they appear
    inv_fun: Optional[DefineFun] = None
    pre_fun: Optional[DefineFun] = None
    trans_fun: Optional[DefineFun] = None
    post_fun: Optional[DefineFun] = None
    other_funs: List[DefineFun] = None

    def __post_init__(self):
        if self.other_funs is None:
            self.other_funs = []
