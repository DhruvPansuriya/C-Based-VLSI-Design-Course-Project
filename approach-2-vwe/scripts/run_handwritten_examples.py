#!/usr/bin/env python3
"""Run the hand-written golden harnesses for Examples 1, 2 and 4 of the research draft with
real CBMC, assemble obligation outcomes, apply vwe.verdict.decide, and compare with
tests/golden/expected.json. Every check runs on two backends (SAT and Z3); a disagreement
makes the obligation INCONCLUSIVE, exactly as the confirmation stage requires.

Usage: python3 scripts/run_handwritten_examples.py [--out evaluation/results/golden]
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from vwe.tools import cbmc  # noqa: E402
from vwe.obligations import classify  # noqa: E402
from vwe.verdict import Evidence, Obligation, Outcome, decide  # noqa: E402

EX = ROOT / "evaluation" / "tool_spikes" / "examples"
BACKENDS = ("sat", "z3")


def both(files, **kw):
    runs = {b: cbmc.run([str(f) for f in files], backend=b, **kw) for b in BACKENDS}
    return runs



def is_p1_safety(p):       # E0: a standard check failing inside the candidate
    return p.property_id.startswith("p1_") and ".assertion." not in p.property_id


def is_assert(p):
    return p.property_id.startswith("main.assertion")


def ex1(v):
    d = EX / "ex1_saturate"
    common = dict(defines=[f"VARIANT={v}"], watch=("a", "b"))
    core = both([d / "p0.c", d / "p1_variants.c", d / "harness_core.c"], **common)
    e0, _ = classify(core, is_p1_safety, "E0", allow_empty=True, ignore_unselected_assertions=True, independent_safety_refutation=True)
    e1, _ = classify(core, is_assert, "E1")
    it = both([d / "p0.c", d / "p1_variants.c", d / "harness_interp.c"], **common)
    i1, _ = classify(it, is_assert, "I1")
    vac = cbmc.run([str(d / "p1_variants.c"), str(d / "harness_vacuity.c")], defines=[f"VARIANT={v}"])
    probes_ok = vac.ok and len(vac.failed(is_assert)) == 2
    if not probes_ok:
        i1 = Obligation(Outcome.INCONCLUSIVE, note="vacuity probe did not fire")
    return Evidence(e0, e1, True, {"I1": i1})


def ex2(v):
    d = EX / "ex2_argmax"
    common = dict(defines=[f"VARIANT={v}"], unwind=6, watch=("n",))
    core = both([d / "p0.c", d / "p1_variants.c", d / "harness_core.c"], **common)
    e0, _ = classify(core, is_p1_safety, "E0", allow_empty=True, ignore_unselected_assertions=True, independent_safety_refutation=True)
    e1, _ = classify(core, is_assert, "E1")
    it = both([d / "p0.c", d / "p1_variants.c", d / "harness_interp.c"], **common)
    i1, _ = classify(it, lambda p: is_assert(p), "I1")
    return Evidence(e0, e1, True, {"I1": i1})


def ex4(v):
    d = EX / "ex4_sum"
    common = dict(defines=[f"VARIANT={v}"], unwind=6, watch=("n",))
    it = both([d / "p1_variants.c", d / "harness_interp.c"], **common)
    e0, _ = classify(it, is_p1_safety, "E0", allow_empty=True, ignore_unselected_assertions=True, independent_safety_refutation=True)
    i1, _ = classify(it, is_assert, "I")
    keep = Obligation(Outcome.PROVED, note="no keep region: total interpretation (type T4)")
    return Evidence(e0, keep, True, {"I": i1})


def side_checks():
    """Facts the draft relies on, checked directly."""
    out = {}
    d = EX / "ex2_argmax"
    r_all = cbmc.run([str(d / "p0.c"), str(d / "harness_b_ub.c")], unwind=6, watch=("n",))
    r_pos = cbmc.run([str(d / "p0.c"), str(d / "harness_b_ub.c")], defines=["NMIN=1"], unwind=6)
    ns = sorted({p.witness.get("n") for p in r_all.failed(lambda p: p.property_id.startswith("p0_"))})
    out["ex2_B_ub_is_n_eq_0"] = {"P0 UB witnesses n": ns, "P0 safe for n>=1": r_pos.status == "success"}
    d = EX / "ex4_sum"
    r = cbmc.run([str(d / "p1_variants.c"), str(d / "harness_interp.c")],
                 defines=["VARIANT=1", "SHAPE_ELEMS(n)=((n)-1)"], unwind=6)
    in_contract = [p.property_id for p in r.failed() if p.property_id.startswith("main.") and "assertion" not in p.property_id]
    out["ex4_shape_n_minus_1_discarded_by_V_G"] = {"contract UB under (n-1) shape": bool(in_contract),
                                                     "properties": in_contract[:3]}
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(ROOT / "runs" / "handwritten"))
    args = ap.parse_args()
    if not cbmc.cbmc_available():
        print("cbmc not found on PATH; see tools/install_tools.sh", file=sys.stderr)
        return 2
    expected = json.loads((ROOT / "tests" / "golden" / "expected.json").read_text())
    runners = {"ex1_saturate": ex1, "ex2_argmax": ex2, "ex4_sum": ex4}
    rows, mismatches = [], 0
    for ex, variants in expected.items():
        if ex not in runners:
            continue
        for v, (dec, cls) in variants.items():
            verdict = decide(runners[ex](v))
            ok = (verdict.decision, verdict.evidence_class) == (dec, cls)
            mismatches += not ok
            rows.append({"example": ex, "variant": v, "expected": [dec, cls],
                         "got": [verdict.decision, verdict.evidence_class],
                         "reason": verdict.reason, "witness": verdict.witness, "match": ok})
            print(f"{ex:14s} v{v}: expected {dec:9s} {cls}  got {verdict.decision:9s} {verdict.evidence_class}  "
                  f"{'OK' if ok else 'MISMATCH'}  {verdict.reason}  {verdict.witness or ''}")
    facts = side_checks()
    for k, val in facts.items():
        print(k, val)
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    (out / "golden_results.json").write_text(json.dumps(
        {"cbmc_version": cbmc.version(), "rows": rows, "side_checks": facts}, indent=2))
    return 1 if mismatches else 0


if __name__ == "__main__":
    sys.exit(main())
