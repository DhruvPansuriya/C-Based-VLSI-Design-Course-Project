"""Combine the project checker with a mature external SMT verifier."""

import json
from pathlib import Path

from .checker import check_equivalence
from .esbmc_backend import run_esbmc


def check_with_fallback(original, candidate, *, function=None, output_dir,
                        scalar_ranges=None, timeout_ms=10000, max_unroll=256, max_paths=256):
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    if scalar_ranges:
        first = {"status": "unsupported", "reason": "Range preconditions require the ESBMC backend"}
    else:
        first = check_equivalence(original, candidate, function, timeout_ms=timeout_ms,
                                   max_unroll=max_unroll, max_paths=max_paths,
                                   smt_path=output_dir / "symbolic.smt2")
    (output_dir / "symbolic_result.json").write_text(json.dumps(first, indent=2) + "\n", encoding="utf-8")
    if first["status"] in ("unsupported", "unknown", "error"):
        final = run_esbmc(original, candidate, output_dir=output_dir / "esbmc",
                          function=function, scalar_ranges=scalar_ranges, unwind=max_unroll,
                          timeout_seconds=max(1, (timeout_ms + 999) // 1000))
        final["fallback_used"] = True
    else:
        final = {**first, "backend": "hlscheck/Z3", "fallback_used": False}
    final["initial_stage"] = first
    (output_dir / "pipeline_result.json").write_text(json.dumps(final, indent=2) + "\n", encoding="utf-8")
    return final
