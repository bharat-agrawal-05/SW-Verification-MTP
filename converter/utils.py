"""
Utility functions for identifier sanitization, C filename generation, and path resolution.
"""

import os
import re
from typing import Set

# C99/C11 reserved keywords
C_RESERVED_KEYWORDS: Set[str] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict", "return", "short",
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof",
    "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn",
    "_Static_assert", "_Thread_local", "bool", "true", "false"
}


def sanitize_identifier(ident: str) -> str:
    """
    Sanitize an SMT-LIB identifier into a valid C identifier.
    Examples:
      'x!' -> 'x_next'
      'x_0!' -> 'x_0_next'
      'Age.usr.p_a_0' -> 'Age_usr_p_a_0'
      'pre-f' -> 'pre_f'
      'inv-f' -> 'inv_f'
      'return' -> '_return'
    """
    if not ident:
        return "_empty"

    # Replace prime / next state exclamation mark
    s = ident
    if s.endswith("!"):
        s = s[:-1] + "_next"
    else:
        s = s.replace("!", "_next_")

    # Replace dots, dashes, and other non-alphanumeric characters with underscores
    s = re.sub(r'[\.\-\:\$@]', '_', s)

    # Ensure it only contains valid C identifier characters [a-zA-Z0-9_]
    s = re.sub(r'[^a-zA-Z0-9_]', '_', s)

    # If it starts with a digit, prefix with 'v_'
    if s and s[0].isdigit():
        s = "v_" + s

    # If it collides with a C reserved keyword, prefix with '_'
    if s in C_RESERVED_KEYWORDS:
        s = "_" + s

    return s


def sl_to_c_filename(sl_filename: str) -> str:
    """
    Convert a .sl filename to a valid .c filename according to specifications:
    - If filename ends with '.c.sl', strip '.sl' -> '*.c'
    - If filename ends with '.sl', replace with '.c' -> '*.c'
    - Sanitize any problematic characters.
    """
    base = os.path.basename(sl_filename)
    if base.endswith(".c.sl"):
        c_name = base[:-3]  # strip '.sl' -> ends in '.c'
    elif base.endswith(".sl"):
        c_name = base[:-3] + ".c"
    else:
        c_name = base + ".c"

    # Ensure safe filename
    c_name = re.sub(r'[\s:;]', '_', c_name)
    return c_name


def resolve_paths(sl_dir_arg: str, out_dir_arg: str = None, script_dir: str = None):
    """
    Resolve input and output directory paths modularly.
    If paths are relative, they can be relative to the script directory or current working directory.
    Output directory defaults to 'c_{folder_name}' alongside the input directory or in parent directory.
    """
    if script_dir is None:
        script_dir = os.path.dirname(os.path.abspath(__file__))

    # Check relative to script_dir first, then cwd
    if os.path.isabs(sl_dir_arg):
        resolved_sl_dir = os.path.abspath(sl_dir_arg)
    else:
        cand1 = os.path.abspath(os.path.join(script_dir, sl_dir_arg))
        cand2 = os.path.abspath(sl_dir_arg)
        if os.path.isdir(cand1):
            resolved_sl_dir = cand1
        elif os.path.isdir(cand2):
            resolved_sl_dir = cand2
        else:
            resolved_sl_dir = cand1  # default to cand1 even if not yet existing

    # Determine source folder name
    src_folder_name = os.path.basename(os.path.normpath(resolved_sl_dir))

    # Output directory
    if out_dir_arg:
        if os.path.isabs(out_dir_arg):
            resolved_out_dir = os.path.abspath(out_dir_arg)
        else:
            # If specified relative, check relative to script_dir or cwd
            cand1 = os.path.abspath(os.path.join(script_dir, out_dir_arg))
            resolved_out_dir = cand1
    else:
        # Default: placed in the parent of resolved_sl_dir as c_{src_folder_name}
        parent_dir = os.path.dirname(os.path.normpath(resolved_sl_dir))
        resolved_out_dir = os.path.join(parent_dir, f"c_{src_folder_name}")

    return resolved_sl_dir, resolved_out_dir, src_folder_name

