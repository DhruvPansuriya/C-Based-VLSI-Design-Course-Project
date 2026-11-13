"""Verify every recorded submission candidate and seeded negative control."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import hashlib
import argparse
import json

from hlscheck import check_equivalence


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--cases',nargs='*')
    parser.add_argument('--timeout-ms',type=int,default=30000)
    parser.add_argument('--force',action='store_true')
    args=parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    catalog = json.loads((root / "experiments/catalog.json").read_text())
    output = root / "results/submission_verification"
    output.mkdir(parents=True, exist_ok=True)
    results = []
    engine_hash=hashlib.sha256((root/'hlscheck/checker.py').read_bytes()).hexdigest()
    for case in catalog["cases"]:
        if args.cases and case['name'] not in args.cases:
            continue
        directory = root / case["directory"]
        original_path = directory / f"{case['name']}_original.c"
        for variant, expected in (("optimized", "equivalent"), ("buggy", "not_equivalent")):
            candidate_path = directory / f"{case['name']}_{variant}.c"
            identifier = case["name"] + "_" + variant
            cached=output/(identifier+'.json')
            if cached.exists() and not args.force:
                old=json.loads(cached.read_text())
                if (old.get('checker_sha256')==engine_hash and old['original_sha256']==hashlib.sha256(original_path.read_bytes()).hexdigest()
                    and old['candidate_sha256']==hashlib.sha256(candidate_path.read_bytes()).hexdigest()
                    and old['verification']['status']==expected):
                    print(identifier,expected,'cached',flush=True)
                    continue
            result = check_equivalence(original_path.read_text(), candidate_path.read_text(), "kernel",
                                       smt_path=output / (identifier + ".smt2"), timeout_ms=args.timeout_ms)
            row = {"case": case["name"], "variant": variant, "expected": expected,
                   "origin": case["origin"], "transformation": case["transformation"],
                   "original": str(original_path.relative_to(root)), "candidate": str(candidate_path.relative_to(root)),
                   "original_sha256": hashlib.sha256(original_path.read_bytes()).hexdigest(),
                   "candidate_sha256": hashlib.sha256(candidate_path.read_bytes()).hexdigest(), "verification": result,
                   'checker_sha256':engine_hash,'timeout_ms':args.timeout_ms}
            results.append(row)
            (output / (identifier + ".json")).write_text(json.dumps(row, indent=2) + "\n")
            print(identifier, result["status"], result["elapsed_seconds"], flush=True)
    results=[]
    pending=[]
    stale=[]
    for case in catalog['cases']:
        for variant in ('optimized','buggy'):
            path=output/(case['name']+'_'+variant+'.json')
            if path.exists():
                row=json.loads(path.read_text())
                results.append(row)
                folder=root/case['directory']
                if (row.get('checker_sha256')!=engine_hash or
                    row['original_sha256']!=hashlib.sha256((folder/(case['name']+'_original.c')).read_bytes()).hexdigest() or
                    row['candidate_sha256']!=hashlib.sha256((folder/(case['name']+'_'+variant+'.c')).read_bytes()).hexdigest()):
                    stale.append(case['name']+'_'+variant)
            else:
                pending.append(case['name']+'_'+variant)
    summary = {"passed": not pending and not stale and all(r["verification"]["status"] == r["expected"] for r in results),
               'pending':pending,'stale':stale,'checker_sha256':engine_hash,"cases": results}
    (output / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    return 0 if summary["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
