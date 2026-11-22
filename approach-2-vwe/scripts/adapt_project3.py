#!/usr/bin/env python3
"""EVAL-P3: adapt the Project 3 team handoff (equivalence of optimised HLS kernels) to VWE tasks.

Their problem is a T5 request: "rewrite for hardware without changing behaviour".
Each task has P0 = their original kernel, one fixed request, a computed T5
preservation reading (no LLM), and their candidates. Their labels and their
checker's outcome go to eval/project3.json only (never read by the pipeline).

Sources (read-only, from an extracted copy of the handoff):
  * main cohort pairs: benchmarks/{demo,expanded,feedback,machsuite_u32,submission}/
    <name>_original.c with <name>_optimized.c (their result: proved equivalent) and
    <name>_buggy.c (their seeded one-bit fault: rejected);
  * subtle-fault controls: experiments/subtle_faults/<id>/{original,candidate}.c with the
    expected label and their checker status from results/subtle_faults/summary.json.

Adaptation (recorded per task): `#include <stdint.h>` is replaced by explicit
fixed-width typedefs (their stated ILP32 integer scope; the macOS SDK header is not
parseable by the VWE frontend). Anything else outside the supported subset is
skipped with a reason. Generated tasks are git-ignored (another team's code).
"""
from __future__ import annotations

import argparse
from collections import Counter
from hashlib import sha256
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
from pycparser import c_ast as C, c_parser  # noqa: E402

from vwe.c_frontend import UnsupportedC, analyze, without_comments  # noqa: E402

PAIR_DIRS = ("demo", "expanded", "feedback", "machsuite_u32", "submission")
TYPEDEFS = ("typedef signed char int8_t;\ntypedef unsigned char uint8_t;\ntypedef short int16_t;\n"
            "typedef unsigned short uint16_t;\ntypedef int int32_t;\ntypedef unsigned int uint32_t;\n"
            "typedef long long int64_t;\ntypedef unsigned long long uint64_t;\n")
REQUEST = ("Rewrite this kernel to improve its synthesized hardware (area or latency) without "
           "changing its observable behaviour: every output must stay identical for every valid input.\n")
FUNCTION = "kernel"


class Skip(Exception):
    pass


def adapt(text: str) -> tuple[str, list[str]]:
    notes = []
    includes = re.findall(r"^\s*#\s*include\s*[<\"]([^>\"]+)[>\"]", text, re.M)
    if any(i != "stdint.h" for i in includes):
        raise Skip(f"unsupported include {sorted(set(includes) - {'stdint.h'})}")
    if includes:
        text = re.sub(r"^\s*#\s*include\s*<stdint\.h>\s*$", TYPEDEFS.rstrip(), text, count=1, flags=re.M)
        notes.append("replaced #include <stdint.h> with explicit ILP32/LP64 fixed-width typedefs")
    return text, notes


def signature_info(text: str) -> tuple[dict, list[str]]:
    """Caller profile (exact fixed buffer sizes) and the observable outputs of kernel()."""
    pre = subprocess.run(["cc", "-E", "-P", "-x", "c", "-"], input=text, capture_output=True, text=True,
                         timeout=30)
    if pre.returncode != 0:
        raise Skip("preprocessing failed")
    try:
        analysis = analyze(pre.stdout, FUNCTION)
    except UnsupportedC as exc:
        raise Skip(f"frontend: {str(exc)[:70]}")
    if analysis.unsupported or analysis.forbidden:
        raise Skip("frontend reports unsupported/forbidden constructs")
    if any(role == "input_output" for _, role in analysis.globals):
        raise Skip("mutable globals are outputs the preservation relation would not constrain")
    fdef = next(n for n in c_parser.CParser().parse(pre.stdout).ext
                if isinstance(n, C.FuncDef) and n.decl.name == FUNCTION)
    buffers, outputs = {}, []
    ret = fdef.decl.type.type
    if not (isinstance(ret, C.TypeDecl) and getattr(ret.type, "names", None) == ["void"]):
        outputs.append("out_ret == old_ret")
    for p in (fdef.decl.type.args.params if fdef.decl.type.args else []):
        t = p.type
        if isinstance(t, C.TypeDecl) and getattr(t.type, "names", None) == ["void"]:
            continue
        if isinstance(t, C.PtrDecl):
            raise Skip(f"pointer parameter {p.name} has no declared size")
        if isinstance(t, C.ArrayDecl):
            if isinstance(t.type, C.ArrayDecl) or not isinstance(t.dim, C.Constant):
                raise Skip("multi-dimensional or non-constant array parameter")
            size = int(t.dim.value.rstrip("uUlL"), 0)
            buffers[p.name] = str(size)
            if "const" not in (t.type.quals or []):
                outputs.append(f"forall(i, 0, {size}, out_{p.name}[i] == old_{p.name}[i])")
    if not outputs:
        raise Skip("no observable output")
    return {"buffers": buffers, "alias": "disjoint", "bounds": {}}, outputs


def preservation_reading(task_id: str, shape: dict, outputs: list[str]) -> dict:
    equal = " && ".join(outputs)
    return {"id": f"{task_id}.preserve", "provenance": {"source": "computed", "computed_kind": "T5_identity"},
            "request_type": "T5", "shape": shape, "clauses": [], "ext": equal, "reach": "false",
            "nl_rendering": "No functional change: every output equals the original's on every input."}


def write_task(out: Path, task_id: str, p0: str, candidates: dict[str, str], evaluation: dict,
               origin: str, notes: list[str]) -> None:
    root = out / task_id
    if root.exists():
        shutil.rmtree(root)
    for sub in ("candidates", "eval", "interpretations"):
        (root / sub).mkdir(parents=True)
    p0_text, p0_notes = adapt(p0)
    shape, outputs = signature_info(p0_text)
    adapted = {}
    for name, text in candidates.items():
        cand, _ = adapt(text)
        if signature_info(cand)[0] != shape:
            raise Skip(f"candidate {name} changes the interface")
        adapted[name] = cand
    (root / "p0.c").write_text(p0_text)
    (root / "request.txt").write_text(REQUEST)
    (root / "eval/p_ref.c").write_text(p0_text)  # T5: the original is its own reference
    (root / "eval/phi_ref.c").write_text("/* T5 reference: outputs identical to the original kernel */\n")
    (root / "eval/project3.json").write_text(json.dumps(evaluation, indent=2) + "\n")
    (root / "interpretations/preserve.json").write_text(
        json.dumps(preservation_reading(task_id, shape, outputs), indent=2) + "\n")
    for name, text in adapted.items():
        (root / f"candidates/{name}.c").write_text(text)
    manifest = {
        "task_id": task_id,
        "source": {"suite": "Project3-handoff", "origin": origin,
                   "license": "course team handoff supplied by the user; not redistributed",
                   "adaptations": [*sorted(set(p0_notes)), *notes,
                                   "request text is one fixed T5 template (agent_template)",
                                   "single computed T5 preservation reading (no LLM)"]},
        "function": FUNCTION, "p0": "p0.c",
        "requests": [{"id": "original", "file": "request.txt", "origin": "agent_template"}],
        "candidates": {n: f"candidates/{n}.c" for n in adapted},
        "interpretations": ["interpretations/preserve.json"],
        "caller_domain": shape,
        "eval_only": {"p_ref": "eval/p_ref.c", "phi_ref": "eval/phi_ref.c", "true_shape": shape},
    }
    (root / "task.json").write_text(json.dumps(manifest, indent=2) + "\n")


def digest(path: Path) -> str:
    return sha256(path.read_bytes()).hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--handoff", type=Path, required=True, help="extracted Project3_Team_Handoff folder")
    ap.add_argument("--out", type=Path, default=ROOT / "evaluation/benchmarks/project3/tasks")
    ap.add_argument("--log", type=Path, default=ROOT / "evaluation/benchmarks/project3/adaptation_log.json")
    args = ap.parse_args()
    h = args.handoff
    args.out.mkdir(parents=True, exist_ok=True)
    log = {"handoff_sha256": {}, "selected": [], "skipped": Counter()}
    for d in PAIR_DIRS:
        for orig in sorted((h / "benchmarks" / d).glob("*_original.c")):
            name = orig.name[: -len("_original.c")]
            cands = {role: (h / "benchmarks" / d / f"{name}_{role}.c") for role in ("optimized", "buggy")}
            cands = {r: p for r, p in cands.items() if p.is_file()}
            tid = re.sub(r"[^a-z0-9_]+", "_", f"p3_{d}_{name}".lower())
            evaluation = {"cohort": "main", "labels": {"optimized": "equivalent", "buggy": "not_equivalent"},
                          "their_outcome": {"optimized": "equivalent", "buggy": "not_equivalent"},
                          "basis": "RESULTS.md section 1: all 50 candidates proved equivalent, all 50 seeded "
                                   "faults rejected; *_buggy.c flips one output bit"}
            evaluation = {**evaluation, "labels": {r: evaluation["labels"][r] for r in cands},
                          "their_outcome": {r: evaluation["their_outcome"][r] for r in cands}}
            try:
                write_task(args.out, tid, orig.read_text(), {r: p.read_text() for r, p in cands.items()},
                           evaluation, f"Project3 handoff benchmarks/{d}/{name}", [])
            except Skip as exc:
                log["skipped"][str(exc)] += 1
                shutil.rmtree(args.out / tid, ignore_errors=True)
                continue
            for p in (orig, *cands.values()):
                log["handoff_sha256"][str(p.relative_to(h))] = digest(p)
            log["selected"].append({"task_id": tid, "cohort": "main", "candidates": sorted(cands)})
    summary = json.loads((h / "results/subtle_faults/summary.json").read_text())
    for case in summary["cases"]:
        folder = h / case["directory"]
        tid = re.sub(r"[^a-z0-9_]+", "_", f"p3_sf_{case['id']}".lower())
        evaluation = {"cohort": "subtle_faults", "labels": {"candidate": case["expected"]},
                      "their_outcome": {"candidate": case["status"]}, "rationale": case.get("rationale", "")}
        try:
            if digest(folder / "original.c") != case["original_sha256"] or \
                    digest(folder / "candidate.c") != case["candidate_sha256"]:
                raise Skip("handoff file hash differs from their recorded hash")
            write_task(args.out, tid, (folder / "original.c").read_text(),
                       {"candidate": (folder / "candidate.c").read_text()}, evaluation,
                       f"Project3 handoff {case['directory']}", [])
        except Skip as exc:
            log["skipped"][str(exc)] += 1
            shutil.rmtree(args.out / tid, ignore_errors=True)
            continue
        log["selected"].append({"task_id": tid, "cohort": "subtle_faults", "candidates": ["candidate"]})
    log["skipped"] = dict(log["skipped"])
    args.log.parent.mkdir(parents=True, exist_ok=True)
    args.log.write_text(json.dumps(log, indent=2) + "\n")
    cohorts = Counter(s["cohort"] for s in log["selected"])
    print(f"{len(log['selected'])} tasks {dict(cohorts)}; "
          f"{sum(len(s['candidates']) for s in log['selected'])} candidates; skipped {log['skipped']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
