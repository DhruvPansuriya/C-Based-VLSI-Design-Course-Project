#!/usr/bin/env python3
"""Build each benchmark task's candidate pool: ref, unchanged P0, mutants of P_ref, any LLM fixes.

Deduplicated by normalised token stream. Writes candidates/ and updates the task's
candidate list (benchmark tasks are generated, git-ignored files).
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.eval.mutants import deduplicate, mutants  # noqa: E402


def build_pool(task: Path, limit: int) -> dict:
    manifest = json.loads((task / "task.json").read_text())
    p_ref = (task / "eval/p_ref.c").read_text()
    named = {"ref": p_ref, "unchanged": (task / "p0.c").read_text()}
    provenance = {"ref": "copy of P_ref", "unchanged": "P0 submitted unchanged"}
    for m in mutants(p_ref, limit=limit):
        name = f"mut_{m.operator.replace('+', 'p').replace('-', '_')}_{m.site}"
        named[name], provenance[name] = m.text, f"mutant of P_ref: {m.operator} at {m.description}"
    for path in sorted((task / "candidates").glob("llm_*.c")):
        named[path.stem] = path.read_text()
        provenance[path.stem] = "LLM fix (see candidates/llm_provenance.json)"
    kept, dropped = deduplicate(named)
    for old in (task / "candidates").glob("mut_*.c"):
        old.unlink()
    for name, text in kept.items():
        (task / "candidates" / f"{name}.c").write_text(text)
    manifest["candidates"] = {name: f"candidates/{name}.c" for name in kept}
    (task / "task.json").write_text(json.dumps(manifest, indent=2) + "\n")
    record = {"kept": {n: provenance[n] for n in kept}, "duplicates": dropped}
    (task / "eval/pool.json").write_text(json.dumps(record, indent=2) + "\n")
    return record


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--task", action="append", default=[])
    ap.add_argument("--tasks", type=Path, default=Path("benchmarks/tasks"))
    ap.add_argument("--limit", type=int, default=6)
    args = ap.parse_args()
    roots = sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file()) if args.all \
        else [args.tasks / t for t in args.task]
    for root in roots:
        rec = build_pool(root, args.limit)
        print(f"{root.name}: {len(rec['kept'])} candidates, {len(rec['duplicates'])} duplicates")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
