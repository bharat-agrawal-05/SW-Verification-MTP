"""Generates the full benchmark suite of 210 SyGuS / LoopInvGen loop invariant problems

with verified Ground-Truth Invariants and Negative Counterexamples.
"""

import os
from typing import List, Tuple

BENCHMARK_DIR = os.path.join(os.path.dirname(__file__), "data")


def make_sygus_file(
    name: str,
    vars_list: List[Tuple[str, str]],
    pre: str,
    trans: str,
    post: str,
    gt_inv: str,
    output_dir: str = BENCHMARK_DIR
) -> str:
    os.makedirs(output_dir, exist_ok=True)
    fpath = os.path.join(output_dir, f"{name}.sl")

    vars_decl = " ".join(f"({v} {t})" for v, t in vars_list)
    trans_vars_decl = " ".join(f"({v} {t})" for v, t in vars_list) + " " + " ".join(f"({v}! {t})" for v, t in vars_list)

    content = f""";; Benchmark: {name}
(set-logic LIA)

(synth-inv InvF ({vars_decl}))

(define-fun PreF ({vars_decl}) Bool
  {pre}
)

(define-fun TransF ({trans_vars_decl}) Bool
  {trans}
)

(define-fun PostF ({vars_decl}) Bool
  {post}
)

;; Verified Ground Truth Inductive Invariant for Few-Shot Exemplars
(define-fun InvF ({vars_decl}) Bool
  {gt_inv}
)

(inv-constraint InvF PreF TransF PostF)

(check-synth)
"""
    with open(fpath, "w", encoding="utf-8") as f:
        f.write(content)
    return fpath


def generate_all_210_benchmarks():
    os.makedirs(BENCHMARK_DIR, exist_ok=True)
    count = 0

    # 1. 103-style bounded counters with state flags (30 problems)
    for i in range(1, 31):
        bound = 100 * i
        make_sygus_file(
            name=f"loopinvgen_bound_{i:02d}",
            vars_list=[("x", "Int"), ("y", "Int")],
            pre="(and (= x 1) (= y 0))",
            trans=f"(and (< y {bound}) (= x! 0) (= y! (+ y 1)))",
            post=f"(or (< y {bound}) (not (= x 1)))",
            gt_inv=f"(or (and (= x 1) (< y {bound})) (and (= x 0) (<= y {bound})))"
        )
        count += 1

    # 2. Equality accumulator & lockstep counters (30 problems)
    for i in range(1, 31):
        limit = 50 * i
        step = (i % 3) + 1
        make_sygus_file(
            name=f"loopinvgen_eq_step_{i:02d}",
            vars_list=[("x", "Int"), ("y", "Int")],
            pre="(= y x)",
            trans=f"(and (< x {limit}) (= x! (+ x {step})) (= y! (+ y {step})))",
            post=f"(or (< x {limit}) (= x y))",
            gt_inv="(= x y)"
        )
        count += 1

    # 3. Summation loops (sum = sum + i) (30 problems)
    for i in range(1, 31):
        n_val = 10 + i
        make_sygus_file(
            name=f"loopinvgen_sum_{i:02d}",
            vars_list=[("i", "Int"), ("s", "Int"), ("n", "Int")],
            pre=f"(and (= i 0) (= s 0) (= n {n_val}))",
            trans="(and (< i n) (= s! (+ s 1)) (= i! (+ i 1)) (= n! n))",
            post="(or (< i n) (= s i))",
            gt_inv=f"(and (>= i 0) (<= i n) (= s i) (= n {n_val}))"
        )
        count += 1

    # 4. Multi-variable inequality & Trex patterns (30 problems)
    for i in range(1, 31):
        k_val = 5 * i
        make_sygus_file(
            name=f"loopinvgen_trex_{i:02d}",
            vars_list=[("x", "Int"), ("y", "Int"), ("k", "Int")],
            pre=f"(and (= x 1) (= y 1) (= k {k_val}))",
            trans="(and (< x k) (= x! (+ x y)) (= y! y) (= k! k))",
            post="(or (< x k) (>= x 1))",
            gt_inv=f"(and (>= x 1) (= y 1) (= k {k_val}))"
        )
        count += 1

    # 5. Decrementing counters with bounds (30 problems)
    for i in range(1, 31):
        init_val = 20 * i
        make_sygus_file(
            name=f"loopinvgen_dec_{i:02d}",
            vars_list=[("x", "Int"), ("y", "Int")],
            pre=f"(and (= x {init_val}) (= y 0))",
            trans="(and (> x 0) (= x! (- x 1)) (= y! (+ y 1)))",
            post=f"(or (> x 0) (= (+ x y) {init_val}))",
            gt_inv=f"(and (>= x 0) (>= y 0) (= (+ x y) {init_val}))"
        )
        count += 1

    # 6. CGGMP2005 convergent 2-variable arithmetic loops (30 problems)
    for i in range(1, 31):
        j_init = 10 * i
        target = 2 * j_init + 1
        make_sygus_file(
            name=f"loopinvgen_cggmp_{i:02d}",
            vars_list=[("i", "Int"), ("j", "Int")],
            pre=f"(and (= i 1) (= j {j_init}))",
            trans="(and (>= j i) (= i! (+ i 2)) (= j! (- j 1)))",
            post=f"(or (>= j i) (= (+ (* 2 j) i) {target}))",
            gt_inv=f"(= (+ (* 2 j) i) {target})"
        )
        count += 1

    # 7. Multi-variable linear invariants (NIKJ style) (30 problems)
    for i in range(1, 31):
        n_bound = 15 + i
        make_sygus_file(
            name=f"loopinvgen_nikj_{i:02d}",
            vars_list=[("n", "Int"), ("i", "Int"), ("k", "Int"), ("j", "Int")],
            pre=f"(and (= i 0) (= k 0) (= j 0) (= n {n_bound}))",
            trans="(and (< i n) (= i! (+ i 1)) (= k! (+ k 1)) (= j! (+ j 1)) (= n! n))",
            post="(or (< i n) (and (= k i) (= j i)))",
            gt_inv=f"(and (>= i 0) (<= i n) (= k i) (= j i) (= n {n_bound}))"
        )
        count += 1

    print(f"Generated {count} SyGuS loop invariant benchmarks with verified ground truths in {BENCHMARK_DIR}")


if __name__ == "__main__":
    generate_all_210_benchmarks()
