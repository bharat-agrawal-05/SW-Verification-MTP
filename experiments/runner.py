"""Master Experiment Coordinator and Results Formatter."""

import os
import json
import time
from datetime import datetime
from typing import Dict, Any
from tabulate import tabulate

from core.verifier import InvariantVerifier
from similarity.example_finder import ExampleFinder
from benchmarks.benchmark_loader import BenchmarkLoader
from llm import get_llm_client
from experiments.rq1_1_instructions import run_rq1_1
from experiments.rq1_2_partitioning import run_rq1_2
from experiments.rq1_3_similarity import run_rq1_3
from experiments.rq1_4_example_types import run_rq1_4
from experiments.rq1_5_integrated import run_rq1_5
from experiments.rq2_1_repair_errors import run_rq2_1
from experiments.rq2_2_repair_counterexamples import run_rq2_2
from experiments.rq3_enhanced_cegis import run_enhanced_cegis


class ExperimentRunner:
    """Coordinates benchmark loading, LLM querying, Z3 verification, and table generation."""

    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.llm = get_llm_client(config)
        
        v_cfg = config.get("verifier", {})
        self.verifier = InvariantVerifier(timeout_ms=v_cfg.get("timeout_ms", 10000))

        b_cfg = config.get("benchmarks", {})
        self.loader = BenchmarkLoader(benchmark_dir=b_cfg.get("directory", "benchmarks"))

        self.benchmark_name = os.path.basename(b_cfg.get("directory", "benchmarks"))

        subset_size = b_cfg.get("subset_size", None)
        seed = b_cfg.get("random_seed", 42)
        self.problems = self.loader.load_problems(sample_size=subset_size, seed=seed)

        s_cfg = config.get("similarity", {})
        self.example_finder = ExampleFinder(
            problem_pool=self.problems,
            semantic_model_name=s_cfg.get("semantic_model", "all-MiniLM-L6-v2")
        )

        out_cfg = config.get("output", {})
        self.results_dir = out_cfg.get("results_dir", "results")
        os.makedirs(self.results_dir, exist_ok=True)

    def print_table_2(self, r1_res: Dict[str, Any]):
        """Prints formatted Table II (Followed Template & Syntactically Correct)."""
        tot_with = r1_res["with_instructions"]["total_generated"] or 1
        f_with = r1_res["with_instructions"]["followed_template"] / tot_with * 100
        s_with = r1_res["with_instructions"]["syntactically_correct"] / tot_with * 100

        tot_wo = r1_res["without_instructions"]["total_generated"] or 1
        f_wo = r1_res["without_instructions"]["followed_template"] / tot_wo * 100
        s_wo = r1_res["without_instructions"]["syntactically_correct"] / tot_wo * 100

        table = [
            [f"{self.llm.model_name} (With Instructions)", f"{f_with:.1f}%", f"{s_with:.1f}%"],
            [f"{self.llm.model_name} (Without Instructions)", f"{f_wo:.1f}%", f"{s_wo:.1f}%"]
        ]
        headers = ["Model Setup", "% Followed template", "% Syntactically correct"]
        print("\n" + "="*60)
        print("TABLE II: Study on LLMs' Invariant Generation Capability")
        print("="*60)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_3(self, r1_res: Dict[str, Any]):
        """Prints formatted Table III (% Solved with vs without instructions across k)."""
        tot_w = r1_res["with_instructions"]["total"] or 1
        tot_wo = r1_res["without_instructions"]["total"] or 1

        w10 = r1_res["with_instructions"]["k10"] / tot_w * 100
        w30 = r1_res["with_instructions"]["k30"] / tot_w * 100
        w50 = r1_res["with_instructions"]["k50"] / tot_w * 100

        wo10 = r1_res["without_instructions"]["k10"] / tot_wo * 100
        wo30 = r1_res["without_instructions"]["k30"] / tot_wo * 100
        wo50 = r1_res["without_instructions"]["k50"] / tot_wo * 100

        table = [
            [self.llm.model_name, f"{wo10:.1f}%", f"{wo30:.1f}%", f"{wo50:.1f}%", f"{w10:.1f}%", f"{w30:.1f}%", f"{w50:.1f}%"]
        ]
        headers = ["LLM", "Without (k=10)", "Without (k=30)", "Without (k=50)", "With (k=10)", "With (k=30)", "With (k=50)"]
        print("\n" + "="*75)
        print("TABLE III: Performance comparison on generating invariants following instructions")
        print("="*75)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_5(self, r3_res: Dict[str, Any]):
        """Prints formatted Table V (S_semantic vs S_syntactic)."""
        tot_sem = r3_res["S_semantic"]["total"] or 1
        tot_syn = r3_res["S_syntactic"]["total"] or 1

        sem10 = r3_res["S_semantic"]["k10"] / tot_sem * 100
        sem30 = r3_res["S_semantic"]["k30"] / tot_sem * 100
        sem50 = r3_res["S_semantic"]["k50"] / tot_sem * 100

        syn10 = r3_res["S_syntactic"]["k10"] / tot_syn * 100
        syn30 = r3_res["S_syntactic"]["k30"] / tot_syn * 100
        syn50 = r3_res["S_syntactic"]["k50"] / tot_syn * 100

        table = [
            [self.llm.model_name, f"{sem10:.1f}%", f"{sem30:.1f}%", f"{sem50:.1f}%", f"{syn10:.1f}%", f"{syn30:.1f}%", f"{syn50:.1f}%"]
        ]
        headers = ["LLM", "S_semantic (k=10)", "S_semantic (k=30)", "S_semantic (k=50)", "S_syntactic (k=10)", "S_syntactic (k=30)", "S_syntactic (k=50)"]
        print("\n" + "="*80)
        print("TABLE V: Few-shot with S_semantic vs Few-shot with S_syntactic")
        print("="*80)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_7(self, r4_res: Dict[str, Any]):
        """Prints formatted Table VII (EX_P, EX_N, EX_Mix)."""
        tot = r4_res["EX_P"]["total"] or 1
        p50 = r4_res["EX_P"]["k50"] / tot * 100
        n50 = r4_res["EX_N"]["k50"] / tot * 100
        m50 = r4_res["EX_Mix"]["k50"] / tot * 100

        table = [
            [self.llm.model_name, f"{p50:.1f}%", f"{n50:.1f}%", f"{m50:.1f}%"]
        ]
        headers = ["LLM", "EX_P (Positive)", "EX_N (Negative)", "EX_Mix (Mixed)"]
        print("\n" + "="*60)
        print("TABLE VII: Study on LLM's Successful Invariant Generation with few-shot prompts")
        print("="*60)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_8(self, r5_res: Dict[str, Any]):
        """Prints formatted Table VIII (Integrated instructions + few-shots)."""
        tot = r5_res["integrated"]["total"] or 1
        inst50 = r5_res["instruction_only"]["k50"] / tot * 100
        fs50 = r5_res["few_shot_only"]["k50"] / tot * 100
        int50 = r5_res["integrated"]["k50"] / tot * 100

        table = [
            ["Instruction only", f"{r5_res['instruction_only']['k10']/tot*100:.1f}%", f"{r5_res['instruction_only']['k30']/tot*100:.1f}%", f"{inst50:.1f}%"],
            ["Few-shot only", f"{r5_res['few_shot_only']['k10']/tot*100:.1f}%", f"{r5_res['few_shot_only']['k30']/tot*100:.1f}%", f"{fs50:.1f}%"],
            ["Integrated Few-Shot with Instruction", f"{r5_res['integrated']['k10']/tot*100:.1f}%", f"{r5_res['integrated']['k30']/tot*100:.1f}%", f"{int50:.1f}%"],
        ]
        headers = ["Prompt Setup", "k = 10", "k = 30", "k = 50"]
        print("\n" + "="*65)
        print("TABLE VIII: Performance comparison of LLMs with Combined Few-shot and Instructions")
        print("="*65)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_9(self, r2_1_res: Dict[str, Any]):
        """Prints formatted Table IX (Repair using Error Causes and Details)."""
        table = [
            [self.llm.model_name, r2_1_res["num_problems"], r2_1_res["attempted_invariants"], f"{r2_1_res['success_rate_percent']:.1f}%"]
        ]
        headers = ["LLM Model", "# Problems", "# Attempted invariants", "% Successful repair"]
        print("\n" + "="*65)
        print("TABLE IX: LLMs Performance in Invariant Repair Using Errors")
        print("="*65)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_10(self, r2_2_res: Dict[str, Any]):
        """Prints formatted Table X (Repair using Concrete Counterexample Error Values)."""
        table = [
            [self.llm.model_name, r2_2_res["num_problems"], r2_2_res["attempted_invariants"], f"{r2_2_res['single_turn_success_rate_percent']:.1f}%", f"{r2_2_res['multi_turn_success_rate_percent']:.1f}%"]
        ]
        headers = ["LLM Model", "# Problems", "# Attempted invariants", "% Single-turn Repair", "% Multi-turn Repair"]
        print("\n" + "="*75)
        print("TABLE X: LLMs Performance in Invariant Repair Using Counterexample Error Values")
        print("="*75)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def print_table_cegis(self, cegis_res: Dict[str, Any]):
        """Prints formatted Table XI (Enhanced Multi-Turn CEGIS)."""
        c_rates = cegis_res["cumulative_success_rates"]
        table = [
            [
                self.llm.model_name,
                cegis_res["num_problems"],
                f"{c_rates.get(1, 0.0):.1f}%",
                f"{c_rates.get(2, 0.0):.1f}%",
                f"{c_rates.get(3, 0.0):.1f}%",
                f"{cegis_res['total_success_rate_percent']:.1f}%",
                cegis_res["cycles_prevented"]
            ]
        ]
        headers = ["Model", "# Problems", "Turn 1 (Init)", "Turn 2 (+CE1)", "Turn 3 (+CE2)", "Total Solved", "Cycles Prevented"]
        print("\n" + "="*85)
        print("TABLE XI (BEYOND PAPER): Enhanced Multi-Turn CEGIS with Cumulative Counterexample Memory")
        print("="*85)
        print(tabulate(table, headers=headers, tablefmt="github"))

    def run(self, target_rq: str = "all", k_samples: int = 50):
        """Runs specified RQ or all RQs and writes output report."""
        # timestamp = int(time.time())
        all_results = {}

        print(f"Loaded {len(self.problems)} benchmark problems.")
        print(f"Target LLM: {self.llm.model_name} (Provider: {self.config.get('llm', {}).get('provider')})")

        if target_rq in ("rq1_1", "all"):
            r1_1 = run_rq1_1(self.problems, self.llm, self.verifier, k_samples=k_samples)
            all_results["rq1_1"] = r1_1
            self.print_table_2(r1_1)
            self.print_table_3(r1_1)

        if target_rq in ("rq1_2", "all"):
            r1_2 = run_rq1_2(self.problems, self.llm, self.verifier, k_partial=10, k_full=k_samples)
            all_results["rq1_2"] = r1_2
            print("\n[RQ1.2 Results Summary]")
            print(f"Precondition (P_pre) Solved: {r1_2['pre_solved']}/{r1_2['total_problems']}")
            print(f"Transition (P_trans) Solved: {r1_2['trans_solved']}/{r1_2['total_problems']}")
            print(f"Postcondition (P_post) Solved: {r1_2['post_solved']}/{r1_2['total_problems']}")
            print(f"All Partials Solved: {r1_2['all_partial_solved']}/{r1_2['total_problems']}")
            print(f"Combiner (P_full) Solved: {r1_2['full_combiner_solved']}/{r1_2['total_problems']}")

        if target_rq in ("rq1_3", "all"):
            r1_3 = run_rq1_3(self.problems, self.llm, self.verifier, self.example_finder, k_samples=k_samples)
            all_results["rq1_3"] = r1_3
            self.print_table_5(r1_3)

        if target_rq in ("rq1_4", "all"):
            r1_4 = run_rq1_4(self.problems, self.llm, self.verifier, self.example_finder, k_samples=k_samples)
            all_results["rq1_4"] = r1_4
            self.print_table_7(r1_4)

        if target_rq in ("rq1_5", "all"):
            r1_5 = run_rq1_5(self.problems, self.llm, self.verifier, self.example_finder, k_samples=k_samples)
            all_results["rq1_5"] = r1_5
            self.print_table_8(r1_5)

        if target_rq in ("rq2_1", "all"):
            r2_1 = run_rq2_1(self.problems, self.llm, self.verifier)
            all_results["rq2_1"] = r2_1
            self.print_table_9(r2_1)

        if target_rq in ("rq2_2", "all"):
            r2_2 = run_rq2_2(self.problems, self.llm, self.verifier)
            all_results["rq2_2"] = r2_2
            self.print_table_10(r2_2)

        if target_rq in ("cegis", "rq3_cegis", "all"):
            cegis_res = run_enhanced_cegis(self.problems, self.llm, self.verifier, self.example_finder, max_turns=3)
            all_results["enhanced_cegis"] = cegis_res
            self.print_table_cegis(cegis_res)

        # Save JSON output
        dt_str = datetime.now().strftime("%d-%m-%Y_%H-%M-%S")
        out_file = os.path.join(self.results_dir, f"experiment_results_{target_rq}_{self.benchmark_name}_{dt_str}.json")
        with open(out_file, "w", encoding="utf-8") as f:
            json.dump(all_results, f, indent=2)
        print(f"\nSaved complete results to: {out_file}")
