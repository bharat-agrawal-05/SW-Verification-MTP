"""Create a CEGIS-vs-ground-truth CSV from an experiment result JSON file."""

import argparse
import csv
import json
import re
import sys
from collections import Counter
from pathlib import Path
from typing import Any, Dict, Optional

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from core.parser import SyGusParser, parse_all_sexprs, sexpr_to_str


NO_CORRECT_RESPONSE = "NO_CORRECT_RESPONSE"
NONE = "NONE"
GROUND_TRUTH_UNAVAILABLE = "GROUND_TRUTH_UNAVAILABLE"
DEFAULT_OUTPUT_DIR = Path(__file__).resolve().parents[1] / "cegis_quality_comparison"


def infer_benchmark_dir(json_path: Path, benchmark_dir: Optional[str]) -> Path:
    if benchmark_dir:
        return Path(benchmark_dir)

    match = re.search(r"experiment_results_[^_]+_(.+?)_\d{2}-\d{2}-\d{4}_", json_path.name)
    if not match:
        raise ValueError(
            "Could not infer the benchmark directory from the JSON filename; "
            "pass --benchmark-dir explicitly."
        )
    return Path(match.group(1))


def ground_truth_for(problem_name: str, benchmark_dir: Path) -> str:
    benchmark_path = benchmark_dir / f"{problem_name}.sl"
    if not benchmark_path.is_file():
        alternatives = list(benchmark_dir.rglob(f"{problem_name}.sl"))
        if not alternatives:
            return "GROUND_TRUTH_NOT_FOUND"
        benchmark_path = alternatives[0]

    try:
        problem = SyGusParser.parse(
            benchmark_path.read_text(encoding="utf-8"), problem_name=problem_name
        )
    except Exception as error:
        return f"GROUND_TRUTH_PARSE_ERROR: {error}"

    return problem.ground_truth_inv or "GROUND_TRUTH_NOT_GIVEN"


def generated_result(trajectory: Dict[str, Any]) -> str:
    if not trajectory.get("solved"):
        return NO_CORRECT_RESPONSE

    solved_turn = trajectory.get("solved_at_turn")
    history = trajectory.get("history", [])
    for entry in history:
        if entry.get("is_valid") and (
            solved_turn is None or entry.get("turn") == solved_turn
        ):
            return entry.get("candidate_inv", NO_CORRECT_RESPONSE)
    return NO_CORRECT_RESPONSE


def _canonicalize(expr: Any) -> Any:
    if not isinstance(expr, list):
        return expr
    if not expr:
        return expr

    operator = str(expr[0])
    arguments = [_canonicalize(argument) for argument in expr[1:]]
    if operator == "or" and len(arguments) == 2:
        inclusive_bound = _inclusive_bound(arguments)
        if inclusive_bound is not None:
            return inclusive_bound
    if operator in {"=", "and", "or"}:
        arguments.sort(key=sexpr_to_str)
    if operator in {">=", ">"} and len(arguments) == 2:
        operator = "<=" if operator == ">=" else "<"
        arguments.reverse()
    return [operator, *arguments]


def _inclusive_bound(arguments: list[Any]) -> Optional[list[Any]]:
    inequality = next(
        (
            argument
            for argument in arguments
            if isinstance(argument, list)
            and len(argument) == 3
            and argument[0] in {"<", ">"}
        ),
        None,
    )
    equality = next(
        (
            argument
            for argument in arguments
            if isinstance(argument, list)
            and len(argument) == 3
            and argument[0] == "="
        ),
        None,
    )
    if inequality is None or equality is None:
        return None
    if set(map(sexpr_to_str, inequality[1:])) != set(
        map(sexpr_to_str, equality[1:])
    ):
        return None
    return ["<=", inequality[1], inequality[2]] if inequality[0] == "<" else [
        ">=",
        inequality[1],
        inequality[2],
    ]


def _invariant_body(invariant: str) -> Any:
    expressions = parse_all_sexprs(invariant)
    if not expressions:
        return []
    expression = expressions[0]
    if isinstance(expression, list) and expression and expression[0] == "define-fun":
        return expression[-1]
    return expression


def _clauses(invariant: str) -> Counter[str]:
    body = _invariant_body(invariant)
    if isinstance(body, list) and body and body[0] == "and":
        clauses = body[1:]
    else:
        clauses = [body]
    return Counter(sexpr_to_str(_canonicalize(clause)) for clause in clauses)


def compare_invariants(generated: str, ground_truth: str) -> tuple[str, str]:
    """Return extra generated clauses and missing generated clauses."""
    if generated == NO_CORRECT_RESPONSE:
        return NO_CORRECT_RESPONSE, NO_CORRECT_RESPONSE
    if ground_truth.startswith("GROUND_TRUTH_"):
        return GROUND_TRUTH_UNAVAILABLE, GROUND_TRUTH_UNAVAILABLE

    generated_clauses = _clauses(generated)
    ground_truth_clauses = _clauses(ground_truth)
    generated_only = list((generated_clauses - ground_truth_clauses).elements())
    ground_truth_only = list((ground_truth_clauses - generated_clauses).elements())

    if not generated_only and not ground_truth_only:
        return NONE, NONE

    return (
        "; ".join(generated_only) if generated_only else NONE,
        "; ".join(ground_truth_only) if ground_truth_only else NONE,
    )


def generate_csv(
    json_file: str,
    benchmark_dir: Optional[str] = None,
    output_dir: Optional[str] = None,
) -> Path:
    json_path = Path(json_file)
    result = json.loads(json_path.read_text(encoding="utf-8"))
    experiment = result.get("enhanced_cegis", result)
    benchmark_path = infer_benchmark_dir(json_path, benchmark_dir)
    destination = Path(output_dir) if output_dir else DEFAULT_OUTPUT_DIR
    destination.mkdir(parents=True, exist_ok=True)
    output_path = destination / json_path.with_suffix(".csv").name

    with output_path.open("w", encoding="utf-8", newline="") as csv_file:
        writer = csv.writer(csv_file)
        writer.writerow(
            [
                "Problem Name",
                "Extra Clauses in Generated Result",
                "Missing Clauses in Generated Result",
                "Generated Result",
                "Ground Truth",
            ]
        )
        for trajectory in experiment.get("trajectories", []):
            problem_name = trajectory["problem"]
            generated = generated_result(trajectory)
            ground_truth = ground_truth_for(problem_name, benchmark_path)
            extra_clauses, missing_clauses = compare_invariants(generated, ground_truth)
            writer.writerow(
                [
                    problem_name,
                    extra_clauses,
                    missing_clauses,
                    generated,
                    ground_truth,
                ]
            )

    return output_path


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("json_file", help="CEGIS experiment result JSON file")
    parser.add_argument(
        "--benchmark-dir",
        help="Benchmark directory; inferred from the JSON filename when omitted",
    )
    parser.add_argument(
        "--output-dir",
        help="Output directory; defaults to cegis_quality_comparison at the repository root",
    )
    args = parser.parse_args()
    print(generate_csv(args.json_file, args.benchmark_dir, args.output_dir))


if __name__ == "__main__":
    main()