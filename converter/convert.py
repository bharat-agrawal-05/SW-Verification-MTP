#!/usr/bin/env python3
"""
CLI entry point for converting SMT-LIB / SyGuS .sl benchmark files
to minimal sufficient C code suitable for static analysis (e.g. Frama-C).

Usage:
  python3 convert.py [--sl-dir PATH] [--out-dir PATH] [--file PATH] [--verbose]

Examples (run from converter folder):
  python3 convert.py --sl-dir ../benchmarks3
  python3 convert.py --file ../benchmarks3/1.c.sl
"""

import os
import sys
import glob
import time
import argparse
from typing import List, Tuple

from sl_parser import parse_sl_file
from c_generator import generate_c_code
from utils import sl_to_c_filename, resolve_paths


def convert_single_file(sl_path: str, out_path: str) -> bool:
    """
    Parse a single .sl file and generate corresponding .c file.
    Returns True on success, False on failure.
    """
    try:
        problem = parse_sl_file(sl_path)
        c_code = generate_c_code(problem, os.path.basename(sl_path))
        os.makedirs(os.path.dirname(os.path.abspath(out_path)), exist_ok=True)
        with open(out_path, 'w', encoding='utf-8') as f:
            f.write(c_code)
        return True
    except Exception as e:
        print(f"[ERROR] Failed converting {sl_path}: {e}", file=sys.stderr)
        return False


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))

    parser = argparse.ArgumentParser(
        description="Convert SyGuS/SMT .sl files to minimal sufficient C code for Frama-C static analysis."
    )
    parser.add_argument(
        "--sl-dir",
        type=str,
        default="../benchmarks3",
        help="Path to directory containing .sl files (relative to script or absolute). Default: ../benchmarks3"
    )
    parser.add_argument(
        "--out-dir",
        type=str,
        default=None,
        help="Path to output directory for .c files. Default: c_{sl_dir_name} alongside the source folder."
    )
    parser.add_argument(
        "--file",
        type=str,
        default=None,
        help="Convert a single .sl file instead of an entire directory."
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Enable verbose output during conversion."
    )

    args = parser.parse_args()

    # Single-file conversion mode
    if args.file:
        file_path = args.file
        if not os.path.isabs(file_path):
            cand1 = os.path.abspath(os.path.join(script_dir, file_path))
            cand2 = os.path.abspath(file_path)
            file_path = cand1 if os.path.isfile(cand1) else cand2

        if not os.path.isfile(file_path):
            print(f"[ERROR] Input file not found: {args.file}", file=sys.stderr)
            sys.exit(1)

        c_filename = sl_to_c_filename(file_path)
        if args.out_dir:
            out_dir = os.path.abspath(args.out_dir) if os.path.isabs(args.out_dir) else os.path.abspath(os.path.join(script_dir, args.out_dir))
        else:
            out_dir = os.path.dirname(file_path)

        out_path = os.path.join(out_dir, c_filename)
        print(f"Converting single file: {file_path} -> {out_path}")
        success = convert_single_file(file_path, out_path)
        if success:
            print("[SUCCESS] Conversion complete.")
            sys.exit(0)
        else:
            sys.exit(1)

    # Batch directory conversion mode
    resolved_sl_dir, resolved_out_dir, src_folder_name = resolve_paths(
        args.sl_dir, args.out_dir, script_dir
    )

    if not os.path.isdir(resolved_sl_dir):
        print(f"[ERROR] Input directory not found: {resolved_sl_dir}", file=sys.stderr)
        sys.exit(1)

    print(f"==================================================")
    print(f" SyGuS to C Converter")
    print(f" Source Directory: {resolved_sl_dir}")
    print(f" Output Directory: {resolved_out_dir}")
    print(f"==================================================")

    sl_files = sorted(glob.glob(os.path.join(resolved_sl_dir, "*.sl")))
    if not sl_files:
        print(f"[WARNING] No .sl files found in {resolved_sl_dir}")
        sys.exit(0)

    print(f"Found {len(sl_files)} .sl files to convert.")
    os.makedirs(resolved_out_dir, exist_ok=True)

    start_time = time.time()
    success_count = 0
    failure_count = 0
    failures: List[Tuple[str, str]] = []

    for idx, sl_file in enumerate(sl_files, start=1):
        c_filename = sl_to_c_filename(sl_file)
        out_path = os.path.join(resolved_out_dir, c_filename)

        if args.verbose:
            print(f"[{idx}/{len(sl_files)}] Converting {os.path.basename(sl_file)} -> {c_filename}")

        ok = convert_single_file(sl_file, out_path)
        if ok:
            success_count += 1
        else:
            failure_count += 1
            failures.append((sl_file, "Conversion failed"))

    elapsed = time.time() - start_time

    print("\n--------------------------------------------------")
    print(f"Conversion Summary:")
    print(f"  Total files : {len(sl_files)}")
    print(f"  Succeeded   : {success_count}")
    print(f"  Failed      : {failure_count}")
    print(f"  Time taken  : {elapsed:.2f} seconds")
    print(f"  Output path : {resolved_out_dir}")
    print("--------------------------------------------------")

    if failures:
        print("\nFailed files:")
        for f, err in failures[:10]:
            print(f"  {f}: {err}")
        sys.exit(1)
    else:
        print("[SUCCESS] All files converted successfully!")
        sys.exit(0)


if __name__ == "__main__":
    main()

