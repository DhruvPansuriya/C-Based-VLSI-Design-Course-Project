"""Run with: python -m hlscheck original.c candidate.c --function kernel."""

import argparse
import json
from pathlib import Path

from .checker import check_equivalence


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("candidate", type=Path)
    parser.add_argument("--function")
    parser.add_argument("--backend", choices=("hybrid", "symbolic", "esbmc", "auto"), default="hybrid",
                        help="Default: one relational-summary/refinement algorithm. Other values reproduce legacy engine experiments.")
    parser.add_argument("--ranges", type=Path, help="ESBMC scalar ranges as a JSON object: {parameter: [min, max]}")
    parser.add_argument("--output-dir", type=Path, default=Path("results/check"), help="Contract, proof obligations, residual C and verification logs")
    parser.add_argument("--timeout-ms", type=int, default=60000,
                        help="Per SMT solver check / C-verifier invocation; default 60000 ms. Frontend and expression construction add wall time.")
    parser.add_argument("--max-unroll", type=int, default=256)
    parser.add_argument("--max-paths", type=int, default=256)
    parser.add_argument("--json", type=Path)
    parser.add_argument("--smt", type=Path)
    args = parser.parse_args()
    if min(args.timeout_ms, args.max_unroll, args.max_paths) <= 0:
        parser.error("Resource limits must be positive")
    original = args.original.read_text(encoding="utf-8")
    candidate = args.candidate.read_text(encoding="utf-8")
    if args.backend == "hybrid":
        from .hybrid import verify_equivalence
        if args.smt:
            parser.error("The integrated checker writes multiple dependent proof obligations under --output-dir; use --backend symbolic for a standalone --smt query")
        ranges = json.loads(args.ranges.read_text()) if args.ranges else None
        result = verify_equivalence(original, candidate, args.function, output_dir=args.output_dir,
                                    scalar_ranges=ranges, timeout_ms=args.timeout_ms,
                                    max_unroll=args.max_unroll, max_paths=args.max_paths)
    elif args.backend in ("esbmc", "auto"):
        from .esbmc_backend import run_esbmc
        if args.smt:
            parser.error("--smt export is currently available only for the symbolic backend")
        ranges = json.loads(args.ranges.read_text()) if args.ranges else None
        if args.backend == "auto":
            from .pipeline import check_with_fallback
            result = check_with_fallback(original, candidate, function=args.function,
                                          output_dir=args.output_dir, scalar_ranges=ranges,
                                          timeout_ms=args.timeout_ms, max_unroll=args.max_unroll,
                                          max_paths=args.max_paths)
        else:
            result = run_esbmc(original, candidate, function=args.function, output_dir=args.output_dir,
                              scalar_ranges=ranges, unwind=args.max_unroll,
                              timeout_seconds=max(1, (args.timeout_ms + 999) // 1000))
    else:
        if args.ranges:
            parser.error("--ranges is currently available only for the ESBMC backend")
        result = check_equivalence(original, candidate, args.function,
                                  timeout_ms=args.timeout_ms, max_unroll=args.max_unroll,
                                  max_paths=args.max_paths, smt_path=args.smt)
    output = json.dumps(result, indent=2)
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(output + "\n", encoding="utf-8")
    print(output)
    return {"equivalent": 0, "not_equivalent": 1}.get(result["status"], 2)


if __name__ == "__main__":
    raise SystemExit(main())
