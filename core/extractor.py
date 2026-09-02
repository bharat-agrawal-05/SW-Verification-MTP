"""LLM Response Parser and Invariant Extractor with Parentheses Repair Heuristics."""

import re
from typing import Optional, List, Tuple
from core.problem import Problem


class InvariantExtractor:
    """Extracts candidate loop invariants from raw LLM text responses and repairs common syntax issues."""

    @staticmethod
    def balance_parentheses(s: str) -> str:
        """Repairs unbalanced parentheses using heuristic balancing."""
        s = s.strip()
        open_count = s.count("(")
        close_count = s.count(")")

        if open_count > close_count:
            # Append missing closing parentheses
            s = s + (")" * (open_count - close_count))
        elif close_count > open_count:
            # Strip trailing unmatched closing parentheses
            excess = close_count - open_count
            while excess > 0 and s.endswith(")"):
                s = s[:-1]
                excess -= 1
        return s

    @staticmethod
    def strip_stray_keywords(s: str) -> str:
        """Strips stray prefix keywords observed in LLM outputs (Listing 1-4 in paper: 'code', 'scheme', 'lisp')."""
        s = s.strip()
        prefixes = [
            r"^code\s+",
            r"^scheme\s+",
            r"^lisp\s+",
            r"^smt2?\s+",
            r"^clojure\s+",
            r"^racket\s+",
        ]
        for p in prefixes:
            s = re.sub(p, "", s, flags=re.IGNORECASE).strip()
        return s

    @classmethod
    def extract_raw_block(cls, response: str) -> str:
        """Extract candidate invariant block from code tags or markdown blocks."""
        if not response:
            return ""

        # 1. Try <code> ... </code> tags (as instructed in Figures 4, 5, 8)
        code_tag_matches = re.findall(r"<code>(.*?)</code>", response, re.DOTALL | re.IGNORECASE)
        if code_tag_matches:
            # Pick the longest or last matching code tag content
            return code_tag_matches[-1].strip()

        # 2. Try markdown triple backtick blocks: ```...```
        code_block_matches = re.findall(r"```(?:[a-zA-Z0-9_-]+)?\s*\n?(.*?)```", response, re.DOTALL)
        if code_block_matches:
            return code_block_matches[-1].strip()

        # 3. Try finding (define-fun ...) or top-level s-expression
        df_match = re.search(r"\(define-fun\s+[^\s]+.*", response, re.DOTALL)
        if df_match:
            return df_match.group(0).strip()

        # 4. Fallback to raw response
        return response.strip()

    @classmethod
    def extract_and_normalize(cls, response: str, problem: Problem) -> str:
        """Extracts candidate invariant and normalizes it to a full `(define-fun InvF (...) Bool ...)` definition."""
        raw = cls.extract_raw_block(response)
        cleaned = cls.strip_stray_keywords(raw)
        balanced = cls.balance_parentheses(cleaned)

        # Standard signature
        std_sig = problem.get_inv_signature()  # "(define-fun InvF ((x Int) (y Int)) Bool"

        # Check if already a full define-fun
        if balanced.startswith("(define-fun"):
            # Check if name is inv_fun, inv-f, InvF etc.
            # Normalize the function name and args if needed
            match = re.match(r"\(define-fun\s+([^\s]+)\s+\((.*?)\)\s+Bool\s+(.*)\)", balanced, re.DOTALL)
            if match:
                body = match.group(3).strip()
                # Wrap with standardized signature
                return f"{std_sig} {body})"
            return balanced

        # Check if it starts with "inv_fun (" or "(inv_fun" or "inv-f"
        # As in Figure 8: "inv_fun (vars) Bool (..."
        inv_fun_match = re.match(r"^inv_fun\s*\(.*?\)\s*Bool\s*(.*)", balanced, re.DOTALL | re.IGNORECASE)
        if inv_fun_match:
            body = inv_fun_match.group(1).strip()
            body_balanced = cls.balance_parentheses(body)
            return f"{std_sig} {body_balanced})"

        # If it is a bare logical expression like `(and (= x 1) (<= y 1024))` or `(= x y)`
        if balanced.startswith("("):
            return f"{std_sig} {balanced})"

        # If bare boolean literal `true` or `false`
        if balanced.lower() in ("true", "false"):
            return f"{std_sig} {balanced.lower()})"

        # Fallback
        return f"{std_sig} {balanced})"

    @classmethod
    def is_syntactically_valid(cls, inv_str: str) -> bool:
        """Checks if the invariant expression has balanced parentheses and parses without syntax errors."""
        try:
            from core.parser import parse_all_sexprs
            exprs = parse_all_sexprs(inv_str)
            return len(exprs) > 0
        except Exception:
            return False
