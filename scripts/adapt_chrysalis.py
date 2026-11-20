#!/usr/bin/env python3
"""Deterministically adapt single-bug Chrysalis-HLS instances into VWE tasks (T15).

P_ref = upstream source; P0 = upstream source with the documented faulty edit
applied (exact single-occurrence replacement). Every textual change is recorded
in task.json source.adaptations. Requests are generated from a fixed template per
documented bug type (origin "agent_template"); they are NOT human-authored, there
are no independent paraphrases, and phi_ref is "outputs equal P_ref's" — not an
independently written specification. See docs/T15_BENCHMARKS.md.
"""
from __future__ import annotations

import argparse
from collections import defaultdict
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from pycparser import c_ast as C, c_parser  # noqa: E402
from vwe.c_frontend import UnsupportedC, analyze, without_comments  # noqa: E402
from vwe.eval.differential import differential  # noqa: E402

DATASET = Path("third_party/Chrysalis-HLS/HLS_Bug_Dataset")
TYPES = ("OOB", "INIT", "SHFT", "INF", "USE", "ZERO", "BUF", "MLU")
SUITE_ORDER = ("MachSuite", "CHStone", "polybench")
SCALE = 4  # equals the default K
KNOWN_CAPS = {"INT_MAX", "INT_MIN", "UINT_MAX", "CHAR_BIT", "NULL"}
REJECT = re.compile(r"\b(float|double|template|class|ap_u?int|ap_fixed|hls|std|namespace|bool|"
                    r"true|false|new|delete|printf|malloc|free|static_cast|struct|union|goto)\b|::|&\s*\w+\s*[,)]")
PRELUDE = ("typedef signed char int8_t; typedef unsigned char uint8_t; typedef short int16_t; "
           "typedef unsigned short uint16_t; typedef int int32_t; typedef unsigned int uint32_t; "
           "typedef long long int64_t; typedef unsigned long long uint64_t;\n")
REQUESTS = {
    "OOB": "{fn} can access an array element outside the array's bounds. Fix the indexing so every "
           "access stays in bounds and the function computes its intended result; keep all other "
           "behaviour unchanged.",
    "INIT": "{fn} reads a variable before it has been initialised. Give it the intended initial value "
            "so the result is well defined; keep all other behaviour unchanged.",
    "SHFT": "{fn} performs a bit shift by an amount that is out of range for the operand type. Fix the "
            "shift so it is well defined and computes the intended value; keep all other behaviour unchanged.",
    "INF": "A loop in {fn} has an incorrect termination condition and can run forever. Fix the loop "
           "bound so it terminates after the intended iterations; keep all other behaviour unchanged.",
    "USE": "{fn} produces wrong values because a value is unintentionally sign-extended. Fix the "
           "conversion so the intended (unsigned) value is used; keep all other behaviour unchanged.",
    "ZERO": "In {fn} a variable is initialised to zero instead of its intended nonzero initial value. "
            "Restore the intended initialiser; keep all other behaviour unchanged.",
    "BUF": "{fn} copies from the wrong half of a split buffer. Copy from the intended half; keep all "
           "other behaviour unchanged.",
    "MLU": "A manually unrolled loop in {fn} does not match the original loop (an element or index is "
           "wrong in one of the unrolled copies). Fix the unrolled code so it computes what the rolled "
           "loop would; keep all other behaviour unchanged.",
}


class Skip(Exception):
    pass


def adapt_text(source: str) -> tuple[str, list[str]]:
    notes: list[str] = []
    lines = []
    for line in source.splitlines():
        if re.match(r"\s*#\s*include", line):
            notes.append(f"removed include line: {line.strip()}")
            continue
        m = re.match(r"(\s*#\s*define\s+([A-Z][A-Z0-9_]*)\s+)(\d+)\s*$", line)
        if m and int(m.group(3)) > SCALE:
            notes.append(f"scaled #define {m.group(2)} {m.group(3)} -> {SCALE}")
            line = f"{m.group(1)}{SCALE}"
        lines.append(line)
    text = "\n".join(lines) + "\n"
    defined = set(re.findall(r"#\s*define\s+([A-Za-z_]\w*)", text))
    # Identifier scan ignores preprocessor lines (#pragma HLS ..., #define) by design.
    code = "\n".join(l for l in without_comments(text).splitlines() if not l.lstrip().startswith("#"))
    missing = sorted(set(re.findall(r"\b[A-Z][A-Z0-9_]{1,}\b", code)) - defined - KNOWN_CAPS)
    for name in missing:
        value_use = re.search(rf"[\[<>=+\-*/%(,]\s*{name}\b|\b{name}\s*[\]<>+\-*/%;),]", code)
        type_use = re.search(rf"\b{name}\s+\**\s*[A-Za-z_]", code) or re.search(rf"typedef[^;]*\b{name}\s*;", code)
        if type_use or not value_use:
            raise Skip(f"undefined identifier {name} needs a missing header")
    head = []
    if re.search(r"\b u?int(8|16|32|64)_t\b".replace(" ", ""), code):
        head.append("#include <stdint.h>")
        notes.append("added #include <stdint.h> for fixed-width integer types")
    for name in missing:
        head.append(f"#define {name} {SCALE}")
        notes.append(f"defined missing macro {name} as {SCALE} (sizes scaled to K={SCALE})")
    return "\n".join(head + [text]), notes


def parse_for_analysis(text: str) -> str:
    body = "\n".join(l for l in text.splitlines() if not re.match(r"\s*#\s*include", l))
    done = subprocess.run(["cc", "-E", "-P", "-x", "c", "-"], input=PRELUDE + body,
                          capture_output=True, text=True, timeout=30)
    if done.returncode != 0:
        raise Skip("preprocessing failed")
    return done.stdout


def edited_function(text: str, needle: str) -> str:
    """Name of the function definition whose source lines contain the edit (pycparser coords)."""
    if text.count(needle) != 1:
        raise Skip("edit text not unique after adaptation")
    edit_line = text[: text.index(needle)].count("\n") + 1
    body = "\n".join("" if re.match(r"\s*#\s*include", l) else l for l in text.splitlines())
    done = subprocess.run(["cc", "-E", "-x", "c", "-"], input=PRELUDE + body,
                          capture_output=True, text=True, timeout=30)
    if done.returncode != 0:
        raise Skip("preprocessing failed")
    try:
        ast = c_parser.CParser().parse(done.stdout, filename="<stdin>")
    except Exception as exc:  # pycparser raises its own ParseError
        raise Skip(f"frontend: {str(exc)[:60]}")
    prelude_lines = PRELUDE.count("\n")
    starts = sorted((n.coord.line - prelude_lines, n.decl.name) for n in ast.ext
                    if isinstance(n, C.FuncDef) and n.coord and n.coord.file == "<stdin>")
    before = [name for line, name in starts if line <= edit_line]
    if not before:
        raise Skip("edit is not inside a function")
    return before[-1]


def shape_of(pre: str, fn: str) -> dict:
    ast = c_parser.CParser().parse(pre)
    defs = [n for n in ast.ext if isinstance(n, C.FuncDef) and n.decl.name == fn]
    if len(defs) != 1:
        raise Skip("function definition not found once")
    buffers, values = {}, {}
    params = defs[0].decl.type.args.params if defs[0].decl.type.args else []
    for p in params:
        if isinstance(p, C.EllipsisParam) or (isinstance(p.type, C.TypeDecl) and
                                              getattr(p.type.type, "names", None) == ["void"]):
            continue
        t = p.type
        if isinstance(t, C.PtrDecl):
            raise Skip(f"pointer parameter {p.name} has no declared size")
        if isinstance(t, C.ArrayDecl):
            if isinstance(t.type, C.ArrayDecl):
                raise Skip("multi-dimensional array parameter")
            if not isinstance(t.dim, C.Constant):
                raise Skip("array parameter without constant size")
            buffers[p.name] = str(int(t.dim.value, 0))
            t = t.type
        names = getattr(getattr(t, "type", None), "names", None) or []
        values[p.name] = _value_range(" ".join(names))
    return {"buffers": buffers, "alias": "disjoint", "bounds": {}, "value_bounds": values}


VALUE_LIMIT = 1000  # explicit caller value profile, as in draft Example 4


def _value_range(ctype: str) -> list[int]:
    """Caller value profile per input: [-1000, 1000] clipped to the C type's range."""
    unsigned = "unsigned" in ctype or ctype.startswith("uint")
    if "char" in ctype or ctype in {"int8_t", "uint8_t"}:
        lo, hi = (0, 255) if unsigned else (-128, 127)
    else:
        lo, hi = (0, VALUE_LIMIT) if unsigned else (-VALUE_LIMIT, VALUE_LIMIT)
    return [max(lo, -VALUE_LIMIT), min(hi, VALUE_LIMIT)]


def candidates(dataset: Path):
    for bug in sorted(dataset.glob("*/*/Bugs/bug_*.txt")):
        try:
            doc = json.loads(bug.read_text())
        except ValueError:
            continue
        if doc.get("Error Size") != 1:
            continue
        spec = doc["Error Specification"][0]
        if spec["Error Type"] not in TYPES:
            continue
        sources = sorted((bug.parent.parent / "Source_Code").glob("*"))
        if len(sources) == 1:
            yield bug, spec, sources[0]


def build(bug: Path, spec: dict, src: Path, commit: str) -> dict:
    suite, design = bug.parts[-4], bug.parts[-3]
    upstream = src.read_text(encoding="utf-8")
    if REJECT.search(without_comments(upstream)):
        raise Skip("outside the supported C subset (float, C++, struct, I/O or references)")
    original, faulty = spec["Original Code"], spec["Faulty Code"]
    if upstream.count(original) != 1 or original == faulty:
        raise Skip("faulty edit does not apply exactly once")
    ref_text, notes = adapt_text(upstream)
    fn = edited_function(ref_text, original)
    p0_text, _ = adapt_text(upstream.replace(original, faulty, 1))
    signatures = []
    for text in (ref_text, p0_text):
        syntax = subprocess.run(["cc", "-fsyntax-only", "-std=c11", "-Werror=implicit-function-declaration",
                                 "-x", "c", "-"], input=text, capture_output=True, text=True, timeout=30)
        if syntax.returncode != 0:
            raise Skip("does not compile as standalone C11 (missing declarations from other files)")
        pre = parse_for_analysis(text)
        try:
            analysis = analyze(pre, fn)
        except UnsupportedC as exc:
            raise Skip(f"frontend: {str(exc)[:80]}")
        if analysis.unsupported or analysis.forbidden:
            raise Skip("frontend reports unsupported/forbidden constructs")
        signatures.append(analysis.signature)
    if signatures[0] != signatures[1]:
        raise Skip("faulty edit changes the function interface")
    shape = shape_of(parse_for_analysis(ref_text), fn)
    if any(int(n) > SCALE for n in shape["buffers"].values()):
        raise Skip(f"array parameter larger than K={SCALE} with a literal size (not scaled)")
    probe = differential(ref_text, ref_text, fn, shape, samples=200, chunk=200)
    if probe.status == "reference_undefined":
        raise Skip("P_ref undefined on every sampled input after size scaling (sanitizer probe)")
    return {"suite": suite, "design": design, "type": spec["Error Type"], "function": fn,
            "ref": ref_text, "p0": p0_text, "notes": notes, "shape": shape,
            "origin": f"https://github.com/UIUC-ChenLab/Chrysalis-HLS@{commit}:"
                      f"{bug.relative_to(DATASET.parent.parent).as_posix()} + {src.name}",
            "edit": {"original": original, "faulty": faulty}}


def write_task(item: dict, out: Path) -> str:
    tid = re.sub(r"[^a-z0-9_]+", "_", f"chrysalis_{item['suite']}_{item['design']}_{item['type']}".lower())
    root = out / tid
    if root.exists():
        shutil.rmtree(root)
    (root / "candidates").mkdir(parents=True)
    (root / "eval").mkdir()
    (root / "p0.c").write_text(item["p0"])
    (root / "eval/p_ref.c").write_text(item["ref"])
    (root / "candidates/ref.c").write_text(item["ref"])
    (root / "eval/phi_ref.c").write_text(
        "/* phi_ref for this adapted task: a candidate is correct iff, on the caller domain,\n"
        "   every observable output equals that of eval/p_ref.c (upstream source).\n"
        "   This is a behavioural-equivalence reference, not an independently authored\n"
        "   specification. Labels are computed by T16 differential checking. */\n")
    (root / "request.txt").write_text(REQUESTS[item["type"]].format(fn=f"`{item['function']}`") + "\n")
    manifest = {
        "task_id": tid,
        "source": {"suite": "Chrysalis-HLS", "origin": item["origin"],
                   "license": "Apache-2.0 (Chrysalis-HLS LICENSE.txt); upstream benchmark notices apply",
                   "adaptations": [f"caller value profile: every input value in {item['shape']['value_bounds']} "
                                   "(explicit assumption; unconstrained ints make P0 undefined almost everywhere)",
                                   f"applied documented {item['type']} faulty edit to obtain P0: "
                                   f"{item['edit']['original']!r} -> {item['edit']['faulty']!r}",
                                   *item["notes"],
                                   f"request text from the fixed {item['type']} template (agent_template); "
                                   "not human-authored",
                                   "candidate 'ref' is a copy of P_ref for the P_ref-not-rejected check"]},
        "function": item["function"], "p0": "p0.c",
        "requests": [{"id": "original", "file": "request.txt", "origin": "agent_template"}],
        "candidates": {"ref": "candidates/ref.c"},
        "interpretations": [],
        "caller_domain": item["shape"],
        "eval_only": {"p_ref": "eval/p_ref.c", "phi_ref": "eval/phi_ref.c", "true_shape": item["shape"]},
    }
    (root / "task.json").write_text(json.dumps(manifest, indent=2) + "\n")
    return tid


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dataset", type=Path, default=DATASET)
    ap.add_argument("--out", type=Path, default=Path("benchmarks/tasks"))
    ap.add_argument("--limit", type=int, default=30)
    ap.add_argument("--per-design", type=int, default=2)
    ap.add_argument("--log", type=Path, default=Path("benchmarks/adaptation_log.json"))
    args = ap.parse_args()
    manifest = json.loads(Path("third_party/MANIFEST.json").read_text())
    commit = manifest["sources"]["Chrysalis-HLS"]["commit"]
    pools: dict[str, list] = defaultdict(list)
    log = {"commit": commit, "selected": [], "skipped": defaultdict(int)}
    for bug, spec, src in candidates(args.dataset):
        try:
            item = build(bug, spec, src, commit)
        except Skip as exc:
            log["skipped"][str(exc)] += 1
            continue
        pools[item["type"]].append(item)
    for items in pools.values():  # deterministic preference: preferred suite, then short source
        items.sort(key=lambda i: (SUITE_ORDER.index(i["suite"]) if i["suite"] in SUITE_ORDER else len(SUITE_ORDER),
                                  len(i["ref"]), i["suite"], i["design"]))
    chosen, per_design = [], defaultdict(int)
    while len(chosen) < args.limit and any(pools.values()):
        for t in TYPES:  # round-robin over bug types for balance
            while pools[t]:
                item = pools[t].pop(0)
                if per_design[(item["suite"], item["design"])] < args.per_design:
                    per_design[(item["suite"], item["design"])] += 1
                    chosen.append(item)
                    break
            if len(chosen) >= args.limit:
                break
    args.out.mkdir(parents=True, exist_ok=True)
    for item in chosen:
        tid = write_task(item, args.out)
        log["selected"].append({"task_id": tid, "suite": item["suite"], "design": item["design"],
                                "type": item["type"], "function": item["function"]})
        print(tid)
    log["skipped"] = dict(sorted(log["skipped"].items()))
    args.log.write_text(json.dumps(log, indent=2) + "\n")
    print(f"{len(chosen)} tasks; skip reasons: {log['skipped']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
