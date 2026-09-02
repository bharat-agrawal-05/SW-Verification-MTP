"""Benchmark Loader for SyGuS/SMT2 Loop Invariant datasets."""

import os
import glob
import random
from typing import List, Optional
from core.problem import Problem, Variable, NegativeExample
from core.parser import SyGusParser


def get_default_benchmark_problems() -> List[Problem]:
    """Provides a curated set of representative Loop Invariant problems from the LoopInvGen / SyGuS benchmark."""
    problems = []

    # Problem 1: Figure 1 example (103.c)
    p1 = Problem(
        name="fig1_103",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int")],
        pre_f="(and (= x 1) (= y 0))",
        trans_f="(and (< y 1024) (= x! 0) (= y! (+ y 1)))",
        post_f="(or (< y 1024) (not (= x 1)))",
        ground_truth_inv="(define-fun InvF ((x Int) (y Int)) Bool (or (and (= x 1) (< y 1024)) (and (= x 0) (<= y 1024))))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((x Int) (y Int)) Bool (> x y))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (PreF x y) (InvF x y))"
            )
        ]
    )
    problems.append(p1)

    # Problem 2: Figure 4 / 12 example (sygus_loop_nikj)
    p2 = Problem(
        name="fig4_nikj",
        logic="LIA",
        variables=[Variable("n", "Int"), Variable("i", "Int"), Variable("k", "Int"), Variable("j", "Int")],
        pre_f="(and (= i 0) (= k 0) (= j 0))",
        trans_f="(and (< i n) (= i! (+ i 1)) (= k! (+ k 1)) (= j! (+ j 1)) (= n! n))",
        post_f="(or (< i n) (and (>= i 0) (<= i n) (>= j 0) (<= j n) (= (+ k j) (* 2 i))))",
        ground_truth_inv="(define-fun InvF ((n Int) (i Int) (k Int) (j Int)) Bool (and (>= i 0) (<= i n) (= k i) (= j i)))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((n Int) (i Int) (k Int) (j Int)) Bool (and (>= i 0) (<= i n) (>= j 0) (<= j n) (= (+ k j) i)))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (PreF n i k j) (InvF n i k j)))",
                counterexample_model={"k": "0", "n": "-1", "i": "0", "j": "0", "n!": "0", "j!": "0", "i!": "0", "k!": "0"}
            )
        ]
    )
    problems.append(p2)

    # Problem 3: Table VI / VII example (ex_xy_equality)
    p3 = Problem(
        name="table6_xy_eq",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int")],
        pre_f="(= y x)",
        trans_f="(and (< x 1024) (= x! (+ x 1)) (= y! (+ y 1)))",
        post_f="(or (< x 1024) (= x y))",
        ground_truth_inv="(define-fun InvF ((x Int) (y Int)) Bool (= x y))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((x Int) (y Int)) Bool (> x y))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (PreF x y) (InvF x y))"
            )
        ]
    )
    problems.append(p3)

    # Problem 4: Section IV-D example (bounded_counter)
    p4 = Problem(
        name="bounded_counter",
        logic="LIA",
        variables=[Variable("x", "Int")],
        pre_f="(= x 1)",
        trans_f="(and (< x 100) (= x! (+ x 1)))",
        post_f="(or (< x 100) (and (>= x 1) (<= x 101)))",
        ground_truth_inv="(define-fun InvF ((x Int)) Bool (and (>= x 1) (<= x 101)))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((x Int)) Bool (<= x 11))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (and (InvF x) (TransF x x!)) (InvF x!))"
            )
        ]
    )
    problems.append(p4)

    # Problem 5: Listing 3 example (mult_loop)
    p5 = Problem(
        name="mult_loop",
        logic="LIA",
        variables=[Variable("i", "Int"), Variable("j", "Int"), Variable("k", "Int")],
        pre_f="(and (= i 0) (>= j 0) (>= k 0))",
        trans_f="(and (< i (* j k)) (= i! (+ i 1)) (= j! j) (= k! k))",
        post_f="(or (< i (* j k)) (and (<= 0 i) (<= i (* j k))))",
        ground_truth_inv="(define-fun InvF ((i Int) (j Int) (k Int)) Bool (and (<= 0 i) (<= i (* j k))))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((i Int) (j Int) (k Int)) Bool (and (<= 0 i) (<= i (* j k)) (> j 0) (> k 0)))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (PreF i j k) (InvF i j k))"
            )
        ]
    )
    problems.append(p5)

    # Problem 6: Listing 4 example (bounded_c)
    p6 = Problem(
        name="bounded_c",
        logic="LIA",
        variables=[Variable("c", "Int")],
        pre_f="(= c 0)",
        trans_f="(and (< c 4) (= c! (+ c 1)))",
        post_f="(or (< c 4) (and (>= c 0) (<= c 4)))",
        ground_truth_inv="(define-fun InvF ((c Int)) Bool (and (>= c 0) (<= c 4)))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((c Int)) Bool (and (= c 0) (>= c 0) (<= c 4)))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (and (InvF c) (TransF c c!)) (InvF c!))"
            )
        ]
    )
    problems.append(p6)

    # Problem 7: trex01 loop
    p7 = Problem(
        name="trex01",
        logic="LIA",
        variables=[Variable("x", "Int"), Variable("y", "Int"), Variable("k", "Int")],
        pre_f="(and (= x 1) (= y 1) (> k 0))",
        trans_f="(and (< x k) (= x! (+ x y)) (= y! y) (= k! k))",
        post_f="(or (< x k) (>= x 1))",
        ground_truth_inv="(define-fun InvF ((x Int) (y Int) (k Int)) Bool (and (>= x 1) (= y 1) (> k 0)))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((x Int) (y Int) (k Int)) Bool (> x k))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (PreF x y k) (InvF x y k))"
            )
        ]
    )
    problems.append(p7)

    # Problem 8: cggmp2005 loop
    p8 = Problem(
        name="cggmp2005",
        logic="LIA",
        variables=[Variable("i", "Int"), Variable("j", "Int")],
        pre_f="(and (= i 1) (= j 10))",
        trans_f="(and (>= j i) (= i! (+ i 2)) (= j! (- j 1)))",
        post_f="(or (>= j i) (= (+ (* 2 j) i) 21))",
        ground_truth_inv="(define-fun InvF ((i Int) (j Int)) Bool (= (+ (* 2 j) i) 21))",
        negative_examples=[
            NegativeExample(
                candidate_inv="(define-fun InvF ((i Int) (j Int)) Bool (and (>= i 1) (<= j 10)))",
                failure_cause='FAIL : {("LoopInvGen.Exceptions.Internal_Exn(\\"Unsatisfied\\")")}',
                failure_details="Failed to satisfy the condition (=> (InvF i j) (PostF i j))"
            )
        ]
    )
    problems.append(p8)

    return problems


class BenchmarkLoader:
    """Loads SyGuS/SMT2 benchmarks from disk or default curated collection."""

    def __init__(self, benchmark_dir: str = "benchmarks"):
        self.benchmark_dir = benchmark_dir

    def load_problems(self, sample_size: Optional[int] = None, seed: int = 42) -> List[Problem]:
        """Loads all .sl/.smt2 files from benchmark_dir or falls back to curated benchmark suite."""
        problems = []
        if os.path.isdir(self.benchmark_dir):
            files = glob.glob(os.path.join(self.benchmark_dir, "**", "*.sl"), recursive=True) + \
                    glob.glob(os.path.join(self.benchmark_dir, "**", "*.smt2"), recursive=True)
            for fpath in files:
                try:
                    with open(fpath, "r", encoding="utf-8") as f:
                        content = f.read()
                    name = os.path.splitext(os.path.basename(fpath))[0]
                    prob = SyGusParser.parse(content, problem_name=name)
                    if prob.pre_f and prob.trans_f and prob.post_f:
                        problems.append(prob)
                except Exception:
                    continue

        if not problems:
            # Load default curated suite
            problems = get_default_benchmark_problems()

        if sample_size and sample_size < len(problems):
            random.seed(seed)
            problems = random.sample(problems, sample_size)

        return problems
