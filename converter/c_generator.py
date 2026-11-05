"""
C code generator for SMT-LIB / SyGuS invariant synthesis benchmarks.
Translates SyGuSProblem AST into minimal sufficient C99 code with ACSL annotations
compatible with Frama-C static analysis (both WP and Eva).
"""

import re
from typing import List, Tuple, Dict, Optional, Set
from ast_nodes import (
    ASTNode, Var, IntLiteral, FloatLiteral, BoolLiteral, App, Let, Forall, Exists,
    DefineFun, SynthInv, InvConstraint, SyGuSProblem
)
from utils import sanitize_identifier


def unpack_store(store_node: App) -> Tuple[ASTNode, List[Tuple[ASTNode, ASTNode]]]:
    """Unpack nested (store (store ... idx1 val1) idx2 val2)."""
    updates = []
    curr = store_node
    while isinstance(curr, App) and curr.op == 'store':
        base = curr.args[0]
        idx = curr.args[1]
        val = curr.args[2]
        updates.append((idx, val))
        curr = base
    return curr, updates


def flatten_conjuncts(node: ASTNode) -> List[ASTNode]:
    """Flatten nested 'and' expressions into a list of conjuncts."""
    res = []
    if isinstance(node, App) and node.op == 'and':
        for a in node.args:
            res.extend(flatten_conjuncts(a))
    else:
        res.append(node)
    return res


def flatten_disjuncts(node: ASTNode) -> List[ASTNode]:
    """Flatten nested 'or' expressions into a list of disjuncts."""
    res = []
    if isinstance(node, App) and node.op == 'or':
        for a in node.args:
            res.extend(flatten_disjuncts(a))
    else:
        res.append(node)
    return res


def get_used_vars(node: ASTNode) -> Set[str]:
    """Extract all variable names referenced in an AST node."""
    vars_set = set()
    if isinstance(node, Var):
        vars_set.add(node.name)
    elif isinstance(node, Let):
        for _, b in node.bindings:
            vars_set.update(get_used_vars(b))
        vars_set.update(get_used_vars(node.body))
    elif isinstance(node, (Forall, Exists)):
        vars_set.update(get_used_vars(node.body))
    elif isinstance(node, App):
        for a in node.args:
            vars_set.update(get_used_vars(a))
    return vars_set


def apply_subst(node: ASTNode, subst: Dict[str, ASTNode], visited: Optional[Set[str]] = None) -> ASTNode:
    """Recursively apply variable substitutions, preventing cycles."""
    if visited is None:
        visited = set()
    if isinstance(node, Var):
        if node.name in subst and node.name not in visited:
            val = subst[node.name]
            if isinstance(val, Var) and val.name == node.name:
                return node
            new_visited = set(visited)
            new_visited.add(node.name)
            return apply_subst(val, subst, new_visited)
        return node
    elif isinstance(node, App):
        return App(node.op, [apply_subst(a, subst, visited) for a in node.args])
    elif isinstance(node, Let):
        new_s = dict(subst)
        for name, val in node.bindings:
            new_s[name] = val
        return apply_subst(node.body, new_s, visited)
    return node


def expr_to_c(node: ASTNode, let_env: Optional[Dict[str, ASTNode]] = None, is_acsl: bool = True) -> str:
    """Convert an AST expression to a C or ACSL string representation."""
    if let_env is None:
        let_env = {}

    if isinstance(node, Var):
        if node.name in let_env:
            return expr_to_c(let_env[node.name], let_env, is_acsl)
        return sanitize_identifier(node.name)

    if isinstance(node, (IntLiteral, FloatLiteral)):
        return str(node.value)

    if isinstance(node, BoolLiteral):
        if is_acsl:
            return "\\true" if node.value else "\\false"
        else:
            return "true" if node.value else "false"

    if isinstance(node, Let):
        new_env = dict(let_env)
        for name, val in node.bindings:
            new_env[name] = val
        return expr_to_c(node.body, new_env, is_acsl)

    if isinstance(node, Forall):
        decls = ', '.join(f"integer {sanitize_identifier(v)}" for v, _ in node.vars)
        body_str = expr_to_c(node.body, let_env, is_acsl=True)
        return f"(\\forall {decls}; {body_str})"

    if isinstance(node, Exists):
        decls = ', '.join(f"integer {sanitize_identifier(v)}" for v, _ in node.vars)
        body_str = expr_to_c(node.body, let_env, is_acsl=True)
        return f"(\\exists {decls}; {body_str})"

    if isinstance(node, App):
        op = node.op

        # Boolean connectives
        if op == 'and':
            if not node.args:
                return "\\true" if is_acsl else "true"
            return '(' + ' && '.join(expr_to_c(a, let_env, is_acsl) for a in node.args) + ')'

        if op == 'or':
            if not node.args:
                return "\\false" if is_acsl else "false"
            return '(' + ' || '.join(expr_to_c(a, let_env, is_acsl) for a in node.args) + ')'

        if op == 'not':
            return f"!({expr_to_c(node.args[0], let_env, is_acsl)})"

        if op == '=>':
            if len(node.args) == 2:
                if is_acsl:
                    return f"({expr_to_c(node.args[0], let_env, is_acsl)} ==> {expr_to_c(node.args[1], let_env, is_acsl)})"
                else:
                    return f"(!({expr_to_c(node.args[0], let_env, is_acsl)}) || {expr_to_c(node.args[1], let_env, is_acsl)})"
            else:
                res = expr_to_c(node.args[-1], let_env, is_acsl)
                for a in reversed(node.args[:-1]):
                    if is_acsl:
                        res = f"({expr_to_c(a, let_env, is_acsl)} ==> {res})"
                    else:
                        res = f"(!({expr_to_c(a, let_env, is_acsl)}) || {res})"
                return res

        # Equality & Store updates
        if op == '=':
            if len(node.args) == 2:
                a0, a1 = node.args
                if isinstance(a1, App) and a1.op == 'store':
                    base, updates = unpack_store(a1)
                    eqs = [f"({expr_to_c(a0, let_env, is_acsl)}[{expr_to_c(idx, let_env, is_acsl)}] == {expr_to_c(val, let_env, is_acsl)})" for idx, val in updates]
                    not_eqs = ' || '.join(f"(_k == {expr_to_c(idx, let_env, is_acsl)})" for idx, _ in updates)
                    if is_acsl:
                        eqs.append(f"(\\forall integer _k; !({not_eqs}) ==> ({expr_to_c(a0, let_env, is_acsl)}[_k] == {expr_to_c(base, let_env, is_acsl)}[_k]))")
                    return '(' + ' && '.join(eqs) + ')'
                elif isinstance(a0, App) and a0.op == 'store':
                    base, updates = unpack_store(a0)
                    eqs = [f"({expr_to_c(a1, let_env, is_acsl)}[{expr_to_c(idx, let_env, is_acsl)}] == {expr_to_c(val, let_env, is_acsl)})" for idx, val in updates]
                    not_eqs = ' || '.join(f"(_k == {expr_to_c(idx, let_env, is_acsl)})" for idx, _ in updates)
                    if is_acsl:
                        eqs.append(f"(\\forall integer _k; !({not_eqs}) ==> ({expr_to_c(a1, let_env, is_acsl)}[_k] == {expr_to_c(base, let_env, is_acsl)}[_k]))")
                    return '(' + ' && '.join(eqs) + ')'
                else:
                    return f"({expr_to_c(a0, let_env, is_acsl)} == {expr_to_c(a1, let_env, is_acsl)})"
            else:
                return '(' + ' && '.join(f"({expr_to_c(node.args[i], let_env, is_acsl)} == {expr_to_c(node.args[i+1], let_env, is_acsl)})" for i in range(len(node.args)-1)) + ')'

        # Comparisons
        if op in ('<=', '<', '>=', '>'):
            if len(node.args) == 2:
                return f"({expr_to_c(node.args[0], let_env, is_acsl)} {op} {expr_to_c(node.args[1], let_env, is_acsl)})"
            else:
                return '(' + ' && '.join(f"({expr_to_c(node.args[i], let_env, is_acsl)} {op} {expr_to_c(node.args[i+1], let_env, is_acsl)})" for i in range(len(node.args)-1)) + ')'

        # Arithmetic
        if op == '+':
            if len(node.args) == 1:
                return expr_to_c(node.args[0], let_env, is_acsl)
            return '(' + ' + '.join(expr_to_c(a, let_env, is_acsl) for a in node.args) + ')'

        if op == '-':
            if len(node.args) == 1:
                return f"(-({expr_to_c(node.args[0], let_env, is_acsl)}))"
            return '(' + ' - '.join(expr_to_c(a, let_env, is_acsl) for a in node.args) + ')'

        if op == '*':
            return '(' + ' * '.join(expr_to_c(a, let_env, is_acsl) for a in node.args) + ')'

        if op in ('/', 'div'):
            return f"({expr_to_c(node.args[0], let_env, is_acsl)} / {expr_to_c(node.args[1], let_env, is_acsl)})"

        if op == 'mod':
            return f"({expr_to_c(node.args[0], let_env, is_acsl)} % {expr_to_c(node.args[1], let_env, is_acsl)})"

        # Conditional
        if op == 'ite':
            return f"(({expr_to_c(node.args[0], let_env, is_acsl)}) ? ({expr_to_c(node.args[1], let_env, is_acsl)}) : ({expr_to_c(node.args[2], let_env, is_acsl)}))"

        # Array indexing
        if op == 'select':
            return f"{expr_to_c(node.args[0], let_env, is_acsl)}[{expr_to_c(node.args[1], let_env, is_acsl)}]"

        # User-defined function call
        prefix = "c_" if not is_acsl else ""
        fn_name = prefix + sanitize_identifier(op)
        args_str = ', '.join(expr_to_c(a, let_env, is_acsl) for a in node.args)
        return f"{fn_name}({args_str})"

    return "0"


def has_quantifier(node: ASTNode) -> bool:
    """Check if an AST node contains a quantifier (Forall or Exists)."""
    if isinstance(node, (Forall, Exists)):
        return True
    if isinstance(node, Let):
        return any(has_quantifier(b[1]) for b in node.bindings) or has_quantifier(node.body)
    if isinstance(node, App):
        return any(has_quantifier(a) for a in node.args)
    return False


def get_c_type(var_type: str) -> Tuple[str, bool]:
    """Get C type and is_array flag using 64-bit 'long long' to prevent overflow."""
    if "Array" in var_type:
        elem_type = "_Bool" if "Bool" in var_type else "long long"
        return elem_type, True
    elif var_type == "Bool":
        return "_Bool", False
    else:
        return "long long", False


def get_acsl_type(var_type: str) -> Tuple[str, bool]:
    """Get ACSL logic type using mathematical 'integer' to prevent logic overflow."""
    if "Array" in var_type:
        elem_type = "boolean" if "Bool" in var_type else "integer"
        return elem_type, True
    elif var_type == "Bool":
        return "boolean", False
    else:
        return "integer", False


def extract_safety_property(post_node: ASTNode, base_vars: List[str]) -> ASTNode:
    """Extract simplified safety property from postcondition."""
    subst = {v: Var(v) for v in base_vars}
    all_vars = get_used_vars(post_node)
    for v in all_vars:
        base = re.sub(r'_\d+$', '', v)
        if base in base_vars:
            subst[v] = Var(base)

    s_post = apply_subst(post_node, subst)

    # In Code2Inv benchmarks: post is (or (not (and (= x x) ...)) (not (and (not guard) (not safety))))
    if isinstance(s_post, App) and s_post.op == 'or':
        for a in s_post.args:
            if isinstance(a, App) and a.op == 'not':
                inner = a.args[0]
                if isinstance(inner, App) and inner.op == 'and' and len(inner.args) == 2:
                    c0, c1 = inner.args
                    if isinstance(c1, App) and c1.op == 'not':
                        return c1.args[0]
                    if isinstance(c0, App) and c0.op == 'not':
                        return c0.args[0]
    return s_post


def try_extract_natural_loop(problem: SyGuSProblem):
    """
    Attempt to extract a natural imperative loop:
    (base_vars, inits, input_guards, guards, updates, safety_prop)
    """
    tbody = problem.trans_fun.body if problem.trans_fun else None
    if not tbody:
        return None

    step_conjs = None
    if isinstance(tbody, App) and tbody.op == 'or':
        branches = flatten_disjuncts(tbody)
        if len(branches) == 2:
            b0_conjs = flatten_conjuncts(branches[0])
            b1_conjs = flatten_conjuncts(branches[1])
            b0_has_ineq = any(isinstance(c, App) and c.op in ('<', '<=', '>', '>=') for c in b0_conjs)
            b1_has_ineq = any(isinstance(c, App) and c.op in ('<', '<=', '>', '>=') for c in b1_conjs)
            if b1_has_ineq and not b0_has_ineq:
                step_conjs = b1_conjs
            elif b0_has_ineq and not b1_has_ineq:
                step_conjs = b0_conjs
            else:
                b0_has_arith = any(isinstance(c, App) and any(isinstance(a, App) and a.op in ('+', '-', '*') for a in c.args) for c in b0_conjs if isinstance(c, App))
                b1_has_arith = any(isinstance(c, App) and any(isinstance(a, App) and a.op in ('+', '-', '*') for a in c.args) for c in b1_conjs if isinstance(c, App))
                if b1_has_arith and not b0_has_arith:
                    step_conjs = b1_conjs
                elif b0_has_arith and not b1_has_arith:
                    step_conjs = b0_conjs
    elif isinstance(tbody, App) and tbody.op == 'and':
        step_conjs = flatten_conjuncts(tbody)

    if not step_conjs:
        return None

    all_params = [p[0] for p in problem.inv_fun.params] if problem.inv_fun else []

    base_vars = []
    for v in all_params:
        if not re.search(r'_\d+$', v) or v.startswith('conf_'):
            base_vars.append(v)
    if not base_vars:
        base_vars = all_params

    # Build SSA to base mapping
    base_subst = {}
    for name in all_params:
        base = re.sub(r'_\d+$', '', name)
        if base in base_vars:
            base_subst[name] = Var(base)

    # Pass 1: Collect SSA definitions in loop step (ignoring primed vars)
    subst = {}
    for c in step_conjs:
        if isinstance(c, App) and c.op == '=' and len(c.args) == 2:
            a0, a1 = c.args
            if (isinstance(a0, Var) and a0.name.endswith('!')) or (isinstance(a1, Var) and a1.name.endswith('!')):
                continue
            if isinstance(a0, Var) and not isinstance(a1, Var):
                subst[a0.name] = a1
            elif isinstance(a1, Var) and not isinstance(a0, Var):
                subst[a1.name] = a0
            elif isinstance(a0, Var) and isinstance(a1, Var):
                if '_' in a0.name and '_' not in a1.name:
                    subst[a0.name] = a1
                elif '_' in a1.name and '_' not in a0.name:
                    subst[a1.name] = a0
                else:
                    subst[a0.name] = a1

    # Pass 2: Extract updates for primed base variables
    updates = {}
    for c in step_conjs:
        if isinstance(c, App) and c.op == '=' and len(c.args) == 2:
            a0, a1 = c.args
            if isinstance(a0, Var) and a0.name.endswith('!'):
                v = a0.name[:-1]
                if v in base_vars:
                    target_expr = apply_subst(a1, subst)
                    target_expr = apply_subst(target_expr, base_subst)
                    if not (isinstance(target_expr, Var) and target_expr.name == v):
                        updates[v] = target_expr
            elif isinstance(a1, Var) and a1.name.endswith('!'):
                v = a1.name[:-1]
                if v in base_vars:
                    target_expr = apply_subst(a0, subst)
                    target_expr = apply_subst(target_expr, base_subst)
                    if not (isinstance(target_expr, Var) and target_expr.name == v):
                        updates[v] = target_expr

    # Pass 3: Extract guards
    guards = []
    for c in step_conjs:
        if isinstance(c, App) and c.op == '=' and len(c.args) == 2:
            a0, a1 = c.args
            if (isinstance(a0, Var) and a0.name.endswith('!')) or (isinstance(a1, Var) and a1.name.endswith('!')):
                continue
            if isinstance(a0, Var) and a0.name in subst:
                continue
            if isinstance(a1, Var) and a1.name in subst:
                continue
            g = apply_subst(c, subst)
            g = apply_subst(g, base_subst)
            guards.append(g)
        else:
            g = apply_subst(c, subst)
            g = apply_subst(g, base_subst)
            guards.append(g)

    # Pre-condition inits & input constraints
    pre_conjs = flatten_conjuncts(problem.pre_fun.body) if problem.pre_fun else []
    pre_subst = {}
    input_guards = []

    for c in pre_conjs:
        if isinstance(c, App) and c.op == '=' and len(c.args) == 2:
            a0, a1 = c.args
            if isinstance(a0, Var) and not isinstance(a1, Var):
                pre_subst[a0.name] = a1
            elif isinstance(a1, Var) and not isinstance(a0, Var):
                pre_subst[a1.name] = a0
            elif isinstance(a0, Var) and isinstance(a1, Var):
                if '_' in a1.name and '_' not in a0.name:
                    pre_subst[a0.name] = a1
                elif '_' in a0.name and '_' not in a1.name:
                    pre_subst[a1.name] = a0
                else:
                    pre_subst[a0.name] = a1
        else:
            input_guards.append(c)

    inits = {}
    for v in base_vars:
        if v in pre_subst:
            resolved_init = apply_subst(pre_subst[v], pre_subst)
            resolved_init = apply_subst(resolved_init, base_subst)
            if not (isinstance(resolved_init, Var) and resolved_init.name == v):
                inits[v] = resolved_init

    # Substitute input guards
    resolved_input_guards = []
    for g in input_guards:
        rg = apply_subst(g, pre_subst)
        rg = apply_subst(rg, base_subst)
        resolved_input_guards.append(rg)

    if not updates and not guards:
        return None

    # Safety property extraction
    safety_prop = None
    if problem.post_fun:
        safety_prop = extract_safety_property(problem.post_fun.body, base_vars)
        if safety_prop:
            safety_prop = apply_subst(safety_prop, base_subst)

    return base_vars, inits, resolved_input_guards, guards, updates, safety_prop


def _contains_store(node: ASTNode) -> bool:
    """Check if an AST node contains a 'store' operation."""
    if isinstance(node, App):
        if node.op == 'store':
            return True
        return any(_contains_store(a) for a in node.args)
    if isinstance(node, Let):
        return any(_contains_store(b[1]) for b in node.bindings) or _contains_store(node.body)
    if isinstance(node, (Forall, Exists)):
        return _contains_store(node.body)
    return False


def _contains_primed(node: ASTNode) -> bool:
    """Check if an AST node contains primed variables (ending with '!' or '_next')."""
    if isinstance(node, Var):
        return node.name.endswith('!') or node.name.endswith('_next')
    if isinstance(node, App):
        return any(_contains_primed(a) for a in node.args)
    if isinstance(node, Let):
        return any(_contains_primed(b[1]) for b in node.bindings) or _contains_primed(node.body)
    if isinstance(node, (Forall, Exists)):
        return _contains_primed(node.body)
    return False


def is_valid_natural_loop(problem: SyGuSProblem, res) -> bool:
    """
    Validate that the extracted natural loop result is safe to emit as a
    clean imperative while-loop. Rejects cases that must use the relational
    fallback harness:
      1. Reactive / Lustre benchmarks with helper functions (other_funs).
      2. Array-typed state variables (need store/select, not scalar assignment).
      3. Guards, updates, inits, or input_guards that still reference primed
         variables (_next / !) or contain 'store' operations.
      4. Any variable referenced that is not in the base variable set.
    """
    if res is None:
        return False

    base_vars, inits, input_guards, guards, updates, safety_prop = res

    # 1. Reject reactive benchmarks with helper node functions
    if problem.other_funs:
        return False

    # 2. Reject if any state parameter is an array type
    state_params = problem.inv_fun.params if problem.inv_fun else (
        problem.pre_fun.params if problem.pre_fun else [])
    for _, p_type in state_params:
        _, is_arr = get_c_type(p_type)
        if is_arr:
            return False

    base_set = set(base_vars)

    # 3. Check guards: no primed vars, no store, all vars in base_set
    for g in guards:
        if _contains_primed(g) or _contains_store(g):
            return False
        if not get_used_vars(g).issubset(base_set):
            return False

    # 4. Check updates: targets must be base vars, expressions clean
    for v, up_expr in updates.items():
        if v not in base_set:
            return False
        if _contains_primed(up_expr) or _contains_store(up_expr):
            return False
        if not get_used_vars(up_expr).issubset(base_set):
            return False

    # 5. Check inits: targets must be base vars, expressions clean
    for v, init_expr in inits.items():
        if v not in base_set:
            return False
        if _contains_primed(init_expr) or _contains_store(init_expr):
            return False
        if not get_used_vars(init_expr).issubset(base_set):
            return False

    # 6. Check input_guards
    for ig in input_guards:
        if _contains_primed(ig) or _contains_store(ig):
            return False
        if not get_used_vars(ig).issubset(base_set):
            return False

    return True


def generate_c_code(problem: SyGuSProblem, source_filename: str = "") -> str:
    """
    Generate minimal sufficient C code suitable for Frama-C (WP and Eva).
    Avoids 32-bit integer overflow by using 'long long' and ACSL 'integer'.
    Eliminates all '/*@ assume ... */' annotations to comply with ACSL.
    """
    lines = []

    # File Header
    lines.append("/*")
    lines.append(f" * Generated C verification file from: {source_filename}")
    lines.append(f" * SMT-LIB Logic: {problem.logic}")
    lines.append(" * Suitable for static analysis via Frama-C (WP and Eva).")
    lines.append(" */")
    lines.append("")
    lines.append("#include <assert.h>")
    lines.append("#include <stdbool.h>")
    lines.append("")
    lines.append("/*@ assigns \\nothing; */")
    lines.append("long long nondet_long(void);")
    lines.append("")
    lines.append("/*@ assigns \\nothing; */")
    lines.append("_Bool nondet_bool(void);")
    lines.append("")

    # Attempt natural loop extraction and validate
    natural_res = try_extract_natural_loop(problem)

    all_state_params = problem.inv_fun.params if problem.inv_fun else (problem.pre_fun.params if problem.pre_fun else [])
    param_types = {name: ty for name, ty in all_state_params}

    if is_valid_natural_loop(problem, natural_res):
        base_vars, inits, input_guards, guards, updates, safety_prop = natural_res

        # Build substitution map from SSA variables to base variables
        inv_subst = {v: Var(v) for v in base_vars}
        for v in get_used_vars(problem.inv_fun.body):
            base = re.sub(r'_\d+$', '', v)
            if base in base_vars:
                inv_subst[v] = Var(base)

        inv_body_clean = apply_subst(problem.inv_fun.body, inv_subst) if problem.inv_fun else BoolLiteral(True)

        # ACSL Invariant Predicate over base_vars
        inv_name = sanitize_identifier(problem.inv_fun.name) if problem.inv_fun else "inv_f"
        params_str_list = []
        for v in base_vars:
            ty = param_types.get(v, "Int")
            acsl_type, is_arr = get_acsl_type(ty)
            v_ident = sanitize_identifier(v)
            if is_arr:
                params_str_list.append(f"{acsl_type} {v_ident}[]")
            else:
                params_str_list.append(f"{acsl_type} {v_ident}")
        params_str = ", ".join(params_str_list)

        lines.append("/*@")
        lines.append("  // ACSL Logic Invariant Predicate (using mathematical integers)")
        lines.append(f"  predicate {inv_name}({params_str}) =")
        lines.append(f"    {expr_to_c(inv_body_clean, is_acsl=True)};")
        lines.append("  @*/")
        lines.append("")

        # Pure C Invariant Function (using 64-bit long long)
        if not has_quantifier(inv_body_clean):
            c_params_str_list = []
            for v in base_vars:
                ty = param_types.get(v, "Int")
                c_type, is_arr = get_c_type(ty)
                v_ident = sanitize_identifier(v)
                if is_arr:
                    c_params_str_list.append(f"const {c_type} {v_ident}[]")
                else:
                    c_params_str_list.append(f"{c_type} {v_ident}")
            c_params_str = ", ".join(c_params_str_list)

            lines.append(f"static inline _Bool c_{inv_name}({c_params_str}) {{")
            lines.append(f"    return {expr_to_c(inv_body_clean, is_acsl=False)};")
            lines.append("}")
            lines.append("")

        # main() function
        lines.append("int main(void) {")
        lines.append("    // 1. Variable declarations")
        for v in base_vars:
            ty = param_types.get(v, "Int")
            c_type, is_arr = get_c_type(ty)
            v_ident = sanitize_identifier(v)
            if is_arr:
                lines.append(f"    {c_type} {v_ident}[100];")
                lines.append(f"    for (int _i = 0; _i < 100; ++_i) {{ {v_ident}[_i] = nondet_long(); }}")
            else:
                lines.append(f"    {c_type} {v_ident};")
        lines.append("")

        lines.append("    // 2. Pre-condition initialization")
        for v in base_vars:
            v_ident = sanitize_identifier(v)
            if v in inits:
                lines.append(f"    {v_ident} = {expr_to_c(inits[v], is_acsl=False)};")
            else:
                ty = param_types.get(v, "Int")
                c_type, is_arr = get_c_type(ty)
                if not is_arr:
                    nondet_call = "nondet_bool()" if c_type == "_Bool" else "nondet_long()"
                    lines.append(f"    {v_ident} = {nondet_call};")

        # Input constraints on inputs (safe C guard instead of /*@ assume */)
        for g in input_guards:
            lines.append(f"    if (!({expr_to_c(g, is_acsl=False)})) return 0;")
        lines.append("")

        # Loop body with ACSL loop invariant
        inv_args = [sanitize_identifier(v) for v in base_vars]
        assigns_str = ", ".join(sanitize_identifier(v) for v in updates.keys())
        if not assigns_str:
            assigns_str = ", ".join(sanitize_identifier(v) for v in base_vars)

        guard_expr = " && ".join(expr_to_c(g, is_acsl=False) for g in guards) if guards else "1"

        lines.append("    // 3. Loop body with ACSL loop invariant")
        lines.append("    /*@")
        lines.append(f"      @ loop invariant {inv_name}({', '.join(inv_args)});")
        lines.append(f"      @ loop assigns {assigns_str};")
        lines.append("      @*/")
        lines.append(f"    while ({guard_expr}) {{")

        needs_tmp = set()
        for v, expr_node in updates.items():
            used = set()
            def find_vars(n):
                if isinstance(n, Var): used.add(n.name)
                elif isinstance(n, App):
                    for a in n.args: find_vars(a)
            find_vars(expr_node)
            for other_v in updates.keys():
                if other_v != v and other_v in used:
                    needs_tmp.add(other_v)

        for v in sorted(needs_tmp):
            v_ident = sanitize_identifier(v)
            lines.append(f"        long long _old_{v_ident} = {v_ident};")

        for v, expr_node in updates.items():
            v_ident = sanitize_identifier(v)
            val_str = expr_to_c(expr_node, is_acsl=False)
            for old_v in needs_tmp:
                val_str = re.sub(rf'\b{sanitize_identifier(old_v)}\b', f"_old_{sanitize_identifier(old_v)}", val_str)
            lines.append(f"        {v_ident} = {val_str};")

        lines.append("    }")
        lines.append("")

        lines.append("    // 4. Post-condition assertion")
        if safety_prop:
            c_safety_str = expr_to_c(safety_prop, is_acsl=False)
            acsl_safety_str = expr_to_c(safety_prop, is_acsl=True)
            lines.append(f"    assert({c_safety_str});")
            lines.append(f"    /*@ assert {acsl_safety_str}; */")

    else:
        # Fallback: Relational / Multi-branch Loop Harness (using safe plain C guards, NO assume!)
        all_funs = []
        if problem.other_funs:
            all_funs.extend(problem.other_funs)
        for fn in [problem.pre_fun, problem.trans_fun, problem.post_fun, problem.inv_fun]:
            if fn and fn not in all_funs:
                all_funs.append(fn)

        lines.append("/*@")
        lines.append("  // ACSL Logic Predicates")
        for fn in all_funs:
            pred_name = sanitize_identifier(fn.name)
            params_str_list = []
            for p_name, p_type in fn.params:
                acsl_type, is_arr = get_acsl_type(p_type)
                p_ident = sanitize_identifier(p_name)
                if is_arr:
                    params_str_list.append(f"{acsl_type} {p_ident}[]")
                else:
                    params_str_list.append(f"{acsl_type} {p_ident}")
            params_str = ", ".join(params_str_list)
            body_acsl = expr_to_c(fn.body, is_acsl=True)
            lines.append(f"  predicate {pred_name}({params_str}) =")
            lines.append(f"    {body_acsl};")
            lines.append("")
        lines.append("  @*/")
        lines.append("")

        lines.append("// Pure C helper functions (using 64-bit long long)")
        for fn in all_funs:
            fn_c_name = "c_" + sanitize_identifier(fn.name)
            if has_quantifier(fn.body):
                lines.append(f"// {fn_c_name} omitted (contains logic quantifier \\forall/\\exists; verified via ACSL predicate)")
                continue

            params_str_list = []
            for p_name, p_type in fn.params:
                c_type, is_arr = get_c_type(p_type)
                p_ident = sanitize_identifier(p_name)
                if is_arr:
                    params_str_list.append(f"const {c_type} {p_ident}[]")
                else:
                    params_str_list.append(f"{c_type} {p_ident}")
            params_str = ", ".join(params_str_list)
            body_c = expr_to_c(fn.body, is_acsl=False)
            lines.append(f"static inline _Bool {fn_c_name}({params_str}) {{")
            lines.append(f"    return {body_c};")
            lines.append("}")
            lines.append("")

        state_params = problem.inv_fun.params if problem.inv_fun else (problem.pre_fun.params if problem.pre_fun else [])
        trans_params = problem.trans_fun.params if problem.trans_fun else []
        k = len(state_params)
        next_params = trans_params[k:] if len(trans_params) >= 2 * k else []

        lines.append("int main(void) {")
        lines.append("    // 1. Variable declarations & nondeterministic initialization")
        state_idents = []
        assigns_list = []
        for p_name, p_type in state_params:
            c_type, is_arr = get_c_type(p_type)
            ident = sanitize_identifier(p_name)
            state_idents.append(ident)
            if is_arr:
                lines.append(f"    {c_type} {ident}[100];")
                lines.append(f"    for (int _i = 0; _i < 100; ++_i) {{ {ident}[_i] = nondet_long(); }}")
                assigns_list.append(f"{ident}[0..99]")
            else:
                nondet_fn = "nondet_bool()" if c_type == "_Bool" else "nondet_long()"
                lines.append(f"    {c_type} {ident} = {nondet_fn};")
                assigns_list.append(ident)
        lines.append("")

        pre_name = "c_" + sanitize_identifier(problem.pre_fun.name) if problem.pre_fun else None
        if pre_name:
            lines.append("    // 2. Precondition check (safe C guard instead of /*@ assume */)")
            lines.append(f"    if (!{pre_name}({', '.join(state_idents)})) return 0;")
            lines.append("")

        inv_name = sanitize_identifier(problem.inv_fun.name) if problem.inv_fun else "inv_f"
        assigns_str = ", ".join(assigns_list)
        lines.append("    // 3. Loop body with ACSL loop invariant")
        lines.append("    /*@")
        lines.append(f"      @ loop invariant {inv_name}({', '.join(state_idents)});")
        if assigns_str:
            lines.append(f"      @ loop assigns {assigns_str};")
        lines.append("      @*/")
        lines.append("    while (1) {")

        next_idents = []
        for idx, (p_name, p_type) in enumerate(next_params):
            c_type, is_arr = get_c_type(p_type)
            raw_ident = sanitize_identifier(p_name)
            ident = raw_ident if ("_next" in raw_ident) else f"{state_idents[idx]}_next"
            next_idents.append(ident)
            if is_arr:
                lines.append(f"        {c_type} {ident}[100];")
                lines.append(f"        for (int _i = 0; _i < 100; ++_i) {{ {ident}[_i] = nondet_long(); }}")
            else:
                nondet_fn = "nondet_bool()" if c_type == "_Bool" else "nondet_long()"
                lines.append(f"        {c_type} {ident} = {nondet_fn};")

        trans_name = "c_" + sanitize_identifier(problem.trans_fun.name) if problem.trans_fun else None
        trans_args = state_idents + next_idents
        lines.append("")
        if trans_name:
            lines.append(f"        if (!{trans_name}({', '.join(trans_args)})) break;")
        else:
            lines.append("        if (!nondet_bool()) break;")
        lines.append("")

        lines.append("        // State updates")
        for idx, (p_name, p_type) in enumerate(state_params):
            curr_id = state_idents[idx]
            nxt_id = next_idents[idx] if idx < len(next_idents) else f"{curr_id}_next"
            _, is_arr = get_c_type(p_type)
            if is_arr:
                lines.append(f"        for (int _i = 0; _i < 100; ++_i) {{ {curr_id}[_i] = {nxt_id}[_i]; }}")
            else:
                lines.append(f"        {curr_id} = {nxt_id};")

        lines.append("    }")
        lines.append("")

        acsl_post_name = sanitize_identifier(problem.post_fun.name) if problem.post_fun else None
        post_has_quant = has_quantifier(problem.post_fun.body) if problem.post_fun else False
        post_name = ("c_" + sanitize_identifier(problem.post_fun.name)) if (problem.post_fun and not post_has_quant) else None
        lines.append("    // 4. Post-condition assertion")
        if post_name:
            lines.append(f"    assert({post_name}({', '.join(state_idents)}));")
        if acsl_post_name:
            lines.append(f"    /*@ assert {acsl_post_name}({', '.join(state_idents)}); */")

    lines.append("")
    lines.append("    return 0;")
    lines.append("}")
    lines.append("")

    return "\n".join(lines)
