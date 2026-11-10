#!/usr/bin/env python3
"""T15 check: run the pipeline on each task's P_ref copy (candidate "ref").

P_ref must never be REJECTed: a REJECT means a bad adapted task or a tool bug and
must be investigated. With no interpretations yet, ACCEPT is impossible; the
check still exercises admission, P0-only regions and candidate E0 safety.
Writes JSON evidence keyed by the hashes of each task's files.
"""
from __future__ import annotations

import argparse
from hashlib import sha256
import json
from pathlib import Path
import sys
from time import monotonic

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.config import load_config  # noqa: E402
from vwe.pipeline import verify  # noqa: E402


ADAPTER_FILES = ("p0.c", "request.txt", "eval/p_ref.c", "eval/phi_ref.c", "candidates/ref.c")


def task_hash(root: Path) -> str:
    """Hash of the adapter-produced task (later candidate pools/labels do not change it)."""
    h = sha256()
    manifest = json.loads((root / "task.json").read_text())
    manifest.pop("candidates", None)
    h.update(json.dumps(manifest, sort_keys=True).encode())
    for name in ADAPTER_FILES:
        h.update(b"\0" + name.encode() + b"\0" + (root / name).read_bytes())
    return h.hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tasks", type=Path, default=Path("benchmarks/tasks"))
    ap.add_argument("--config", type=Path, default=Path("config/benchmark.toml"))
    ap.add_argument("--out", type=Path, default=Path("benchmarks/ref_check.json"))
    ap.add_argument("--runs-root", type=Path, default=Path("runs/bench-ref"))
    args = ap.parse_args()
    cfg = load_config(args.config)
    rows = []
    for root in sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file()):
        start = monotonic()
        data = verify(root, "ref", cfg, "handwritten", runs_root=args.runs_root).data
        rows.append({"task_id": root.name, "task_sha256": task_hash(root), "decision": data["decision"],
                     "evidence_class": data["evidence_class"], "claim_target": data["claim_target"],
                     "reason": data["reason"], "seconds": round(monotonic() - start, 1)})
        print(json.dumps(rows[-1]), flush=True)
    args.out.write_text(json.dumps({"config": str(args.config), "rows": rows}, indent=2) + "\n")
    rejected = [r["task_id"] for r in rows if r["decision"] == "REJECT"]
    print(f"{len(rows)} tasks; REJECT: {rejected or 'none'}")
    return 1 if rejected else 0


if __name__ == "__main__":
    raise SystemExit(main())
