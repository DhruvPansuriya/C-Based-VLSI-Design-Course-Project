"""Audit and evaluate original EqBench C pairs without changing their semantics.

Examples:
  python scripts/run_eqbench.py --audit-only
  python scripts/run_eqbench.py --limit 12 --timeout-ms 5000

Every original pair is indexed, including unsupported cases. No signed-to-
unsigned conversion, header removal, or implicit preconditions are applied.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import argparse
from collections import Counter
import hashlib
import json

from hlscheck.esbmc_backend import make_harness
from hlscheck.pipeline import check_with_fallback


ROOT = Path(__file__).resolve().parents[1]
DATA = ROOT / "datasets/EqBench"
OUT = ROOT / "results/eqbench"
SNAPSHOT = "3724fce5b287cc63165028444daf904f25b0158b"


def index_pairs():
    pairs = []
    for original in sorted((DATA / "benchmarks").rglob("oldV.c")):
        candidate = original.with_name("newV.c")
        label = original.parent.name
        if label not in ("Eq", "Neq"):
            continue
        relative = original.parent.relative_to(DATA / "benchmarks").as_posix()
        row = {"id": relative, "label": "equivalent" if label == "Eq" else "not_equivalent",
               "original": str(original.relative_to(ROOT)), "candidate": str(candidate.relative_to(ROOT)),
               "source_sha256": hashlib.sha256(original.read_bytes()).hexdigest(),
               "candidate_sha256": hashlib.sha256(candidate.read_bytes()).hexdigest() if candidate.exists() else None,
               "eligible": False}
        try:
            meta = json.loads(original.with_name("C-Desc.json").read_text(encoding="utf-8-sig"))
            row["metadata"] = meta
            function = meta.get("function name")
            if not isinstance(function, str) or not function.strip():
                function = None
            row["function"] = function
            make_harness(original.read_text(encoding="utf-8-sig"), candidate.read_text(encoding="utf-8-sig"), function)
            row["eligible"] = True
        except Exception as error:
            # Keep every parse/interface/metadata error in the dataset audit.
            row["exclusion_reason"] = f"{type(error).__name__}: {error}"
        pairs.append(row)
    return pairs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--audit-only", action="store_true")
    parser.add_argument("--limit", type=int, default=12)
    parser.add_argument("--timeout-ms", type=int, default=5000)
    parser.add_argument("--max-unroll", type=int, default=32)
    args = parser.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)
    pairs = index_pairs()
    eligible = [p for p in pairs if p["eligible"]]
    audit = {"dataset": "EqBench C", "repository": "https://github.com/shrBadihi/EqBench",
             "snapshot": SNAPSHOT, "total_pairs": len(pairs),
             "labels": dict(Counter(p["label"] for p in pairs)),
             "eligible_for_current_adapter": len(eligible),
             "eligible_labels": dict(Counter(p["label"] for p in eligible)),
             "exclusions": dict(Counter(p.get("exclusion_reason") for p in pairs if not p["eligible"])),
             "label_caveat": "Published labels are preserved. Open issue #15 disputes some labels; safety outcomes and semantic disagreements require separate review.",
             "pairs": pairs}
    (OUT / "audit.json").write_text(json.dumps(audit, indent=2) + "\n", encoding="utf-8")
    print(f"Dataset pairs: {len(pairs)}; current adapter eligible: {len(eligible)}", flush=True)
    print("Labels:", audit["labels"], "Eligible:", audit["eligible_labels"], flush=True)
    if args.audit_only:
        return 0
    if args.limit < 1 or args.timeout_ms < 1:
        parser.error("limit and timeout must be positive")
    # Deterministic, approximately label-balanced first sample. Never select by
    # solver outcome; all excluded/unsampled cases remain in the audit.
    groups = {label: [p for p in eligible if p["label"] == label] for label in ("equivalent", "not_equivalent")}
    selected = []
    for i in range(max((len(g) for g in groups.values()), default=0)):
        for label in groups:
            if i < len(groups[label]): selected.append(groups[label][i])
    selected = selected[:args.limit]
    rows = []
    for pair in selected:
        directory = OUT / "cases" / pair["id"]
        result = check_with_fallback((ROOT / pair["original"]).read_text(encoding="utf-8-sig"),
                                     (ROOT / pair["candidate"]).read_text(encoding="utf-8-sig"),
                                     function=pair["function"], output_dir=directory,
                                     timeout_ms=args.timeout_ms, max_unroll=args.max_unroll)
        row = {"pair": pair["id"], "published_label": pair["label"], "result": result,
               "agrees_with_published_label": result["status"] == pair["label"] if result["status"] in ("equivalent", "not_equivalent") else None}
        rows.append(row)
        print(f"{pair['id']:48} {result['status']:20} label={pair['label']}", flush=True)
        conclusive = [r for r in rows if r["agrees_with_published_label"] is not None]
        summary = {"dataset": "EqBench", "snapshot": SNAPSHOT, "indexed": len(pairs), "eligible": len(eligible),
                   "evaluated": len(rows), "sample_limit": args.limit, "timeout_ms": args.timeout_ms,
                   "max_unroll": args.max_unroll, "preconditions": "None added; complete scalar type domains",
                   "statuses": dict(Counter(r["result"]["status"] for r in rows)),
                   "conclusive": len(conclusive),
                   "agreements": sum(r["agrees_with_published_label"] for r in conclusive),
                   "rows": rows}
        (OUT / "summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
