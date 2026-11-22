"""Native differential testing of a candidate against P_ref (T16 labelling).

Both programs are namespaced into one binary built with ASan/UBSan and
-fno-sanitize-recover. Inputs are generated deterministically from (seed, index):
boundary values and random values cast to each parameter type, arrays at their
exact caller-profile size. Progress markers on stderr locate a crash or hang:
an abort/hang before the reference returned excludes that input (P_ref undefined
or nonterminating there); one after it is a candidate failure on a defined input.
Limitations: uninitialised reads are not detected (no MSan on this platform), so
a difference is replayed to check that P_ref is deterministic on that input, and
a labeller must not rely on differential results alone.
"""
from __future__ import annotations

from dataclasses import dataclass, field
import os
from pathlib import Path
import re
import subprocess
import tempfile
from typing import Mapping

from pycparser import c_ast as C, c_parser

from ..c_frontend import UnsupportedC, analyze, renamed, without_comments

PRELUDE = ("typedef signed char int8_t; typedef unsigned char uint8_t; typedef short int16_t; "
           "typedef unsigned short uint16_t; typedef int int32_t; typedef unsigned int uint32_t; "
           "typedef long long int64_t; typedef unsigned long long uint64_t;\n")
_SCALARS = {"char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int",
            "unsigned", "long", "unsigned long", "long long", "unsigned long long", "int8_t", "uint8_t",
            "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t", "signed", "long int",
            "short int", "unsigned short int", "long long int", "unsigned long int"}


class DifferentialUnsupported(ValueError):
    pass


@dataclass(frozen=True)
class Param:
    name: str
    ctype: str
    length: int | None  # None for scalars


@dataclass
class DiffResult:
    status: str  # agree | disagree | unsupported | incomplete | reference_undefined
    inputs_run: int = 0
    inputs_excluded: int = 0
    counterexamples: list[dict] = field(default_factory=list)
    detail: str = ""


def _preprocess(text: str) -> str:
    body = "\n".join("" if re.match(r"\s*#\s*include", l) else l for l in text.splitlines())
    done = subprocess.run(["cc", "-E", "-P", "-x", "c", "-"], input=PRELUDE + body,
                          capture_output=True, text=True, timeout=30)
    if done.returncode != 0:
        raise DifferentialUnsupported("preprocessing failed")
    return done.stdout


def _params(pre: str, fn: str, shape: Mapping) -> tuple[str, list[Param]]:
    ast = c_parser.CParser().parse(pre)
    fdef = next((n for n in ast.ext if isinstance(n, C.FuncDef) and n.decl.name == fn), None)
    if fdef is None:
        raise DifferentialUnsupported("function not found")
    ret = fdef.decl.type.type
    ret_type = " ".join(ret.type.names) if isinstance(ret, C.TypeDecl) and isinstance(ret.type, C.IdentifierType) else None
    if ret_type is None or (ret_type != "void" and ret_type not in _SCALARS):
        raise DifferentialUnsupported("unsupported return type")
    out = []
    for p in (fdef.decl.type.args.params if fdef.decl.type.args else []):
        t = p.type
        if isinstance(t, C.TypeDecl) and getattr(t.type, "names", None) == ["void"]:
            continue
        length = None
        if isinstance(t, C.ArrayDecl):
            length = int(shape["buffers"][p.name])
            t = t.type
        if not (isinstance(t, C.TypeDecl) and isinstance(t.type, C.IdentifierType)):
            raise DifferentialUnsupported(f"unsupported parameter {p.name}")
        ctype = " ".join(n for n in t.type.names)
        if ctype not in _SCALARS:
            raise DifferentialUnsupported(f"unsupported parameter type {ctype}")
        out.append(Param(p.name, ctype, length))
    return ret_type, out


def harness(p_ref: str, candidate: str, fn: str, shape: Mapping) -> str:
    units = []
    for prefix, text in (("ref", p_ref), ("cand", candidate)):
        pre = _preprocess(text)
        try:
            unit, _ = renamed(analyze(pre, fn), prefix)
        except UnsupportedC as exc:
            raise DifferentialUnsupported(str(exc)) from exc
        units.append(unit)
    ret, params = _params(_preprocess(p_ref), fn, shape)
    decls, setup, args_r, args_c, compare = [], [], [], [], []
    bounds = shape.get("value_bounds", {})

    def pick(p: Param) -> str:
        if p.name in bounds:  # the caller value profile defines the tested domain
            lo, hi = (int(v) for v in bounds[p.name])
            return f"({p.ctype})pick_in(&s, {lo}LL, {hi}LL)"
        return f"({p.ctype})pick(&s)"

    for p in params:
        if p.length is None:
            decls.append(f"{p.ctype} {p.name}_r, {p.name}_c;")
            setup.append(f"{p.name}_r = {pick(p)}; {p.name}_c = {p.name}_r;")
            args_r.append(f"{p.name}_r"); args_c.append(f"{p.name}_c")
        else:
            decls.append(f"{p.ctype} {p.name}_r[{p.length}], {p.name}_c[{p.length}];")
            setup.append(f"for (int k = 0; k < {p.length}; k++) {{ {p.name}_r[k] = {pick(p)}; "
                         f"{p.name}_c[k] = {p.name}_r[k]; }}")
            args_r.append(f"{p.name}_r"); args_c.append(f"{p.name}_c")
            compare.append(f"for (int k = 0; k < {p.length}; k++) if ({p.name}_r[k] != {p.name}_c[k]) "
                           f"{{ printf(\"DIFF %ld {p.name}[%d] %lld %lld\\n\", i, k, (long long){p.name}_r[k], "
                           f"(long long){p.name}_c[k]); diff = 1; }}")
    call_r = f"{fn}({', '.join(args_r)})".replace(fn, f"ref_{fn}", 1)
    call_c = f"{fn}({', '.join(args_c)})".replace(fn, f"cand_{fn}", 1)
    if ret == "void":
        calls = f"{call_r}; fprintf(stderr, \"R %ld\\n\", i); {call_c};"
    else:
        calls = (f"{ret} out_r = {call_r}; fprintf(stderr, \"R %ld\\n\", i); {ret} out_c = {call_c};"
                 f" if (out_r != out_c) {{ printf(\"DIFF %ld ret %lld %lld\\n\", i, (long long)out_r, "
                 f"(long long)out_c); diff = 1; }}")
    return "\n".join([
        "#include <stdio.h>\n#include <stdlib.h>", *units,
        "static unsigned long long mix(unsigned long long z) { z += 0x9e3779b97f4a7c15ULL;"
        " z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL; z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;"
        " return z ^ (z >> 31); }",
        "static long long pick(unsigned long long *s) { static const long long edge[] = {0, 1, -1, 2, -2,"
        " 127, -128, 255, 32767, -32768, 65535, 2147483647LL, -2147483647LL - 1, 4294967295LL};"
        " *s = mix(*s); unsigned long long r = *s; if ((r & 3) == 0) return edge[(r >> 2) % 14];"
        " if ((r & 3) == 1) return (long long)((r >> 8) % 2001) - 1000; return (long long)(r >> 1); }",
        "static long long pick_in(unsigned long long *s, long long lo, long long hi) {"
        " *s = mix(*s); unsigned long long r = *s; long long edge[] = {lo, hi, 0, 1, -1, lo + 1, hi - 1};"
        " if ((r & 3) == 0) { long long v = edge[(r >> 2) % 7]; if (v >= lo && v <= hi) return v; }"
        " return lo + (long long)((r >> 8) % (unsigned long long)(hi - lo + 1)); }",
        "int main(int argc, char **argv) {",
        "  long start = atol(argv[1]), count = atol(argv[2]); unsigned long long seed = strtoull(argv[3], 0, 10);",
        "  for (long i = start; i < start + count; i++) {",
        "    unsigned long long s = mix(seed ^ mix((unsigned long long)i)); int diff = 0;",
        "    " + " ".join(decls), "    " + " ".join(setup),
        "    fprintf(stderr, \"I %ld\\n\", i);", "    " + calls, "    " + " ".join(compare),
        "    fprintf(stderr, \"C %ld\\n\", i); (void)diff;", "  }", "  return 0;", "}", ""])


def _build(source: str, folder: Path) -> Path:
    (folder / "diff.c").write_text(source)
    exe = folder / "diff"
    done = subprocess.run(["cc", "-std=c11", "-O1", "-g", "-fsanitize=address,undefined",
                           "-fno-sanitize-recover=all", "-fno-omit-frame-pointer", "-w",
                           str(folder / "diff.c"), "-o", str(exe)], capture_output=True, text=True, timeout=120)
    if done.returncode != 0:
        raise DifferentialUnsupported("harness failed to compile: " + done.stderr[-300:])
    return exe


def _run(exe: Path, start: int, count: int, seed: int, timeout_s: float):
    env = dict(os.environ, ASAN_OPTIONS="symbolize=0:detect_leaks=0", UBSAN_OPTIONS="symbolize=0")
    try:
        done = subprocess.run([str(exe), str(start), str(count), str(seed)], capture_output=True,
                              text=True, timeout=timeout_s, env=env)
        return done.returncode, done.stdout, done.stderr, False
    except subprocess.TimeoutExpired as exc:
        out = exc.stdout.decode() if isinstance(exc.stdout, bytes) else (exc.stdout or "")
        err = exc.stderr.decode() if isinstance(exc.stderr, bytes) else (exc.stderr or "")
        return None, out, err, True


def _last_marker(stderr: str) -> tuple[str, int] | None:
    marks = re.findall(r"^([IRC]) (\d+)$", stderr, re.M)
    return (marks[-1][0], int(marks[-1][1])) if marks else None


def differential(p_ref: str, candidate: str, fn: str, shape: Mapping, *, samples: int = 10000,
                 seed: int = 0, chunk: int = 1000, chunk_timeout_s: float = 20.0,
                 max_restarts: int = 200, max_counterexamples: int = 5) -> DiffResult:
    try:
        source = harness(p_ref, candidate, fn, shape)
    except (DifferentialUnsupported, UnsupportedC, KeyError, ValueError) as exc:
        return DiffResult("unsupported", detail=str(exc)[:200])
    with tempfile.TemporaryDirectory(prefix="vwe-diff-") as tmp:
        try:
            exe = _build(source, Path(tmp))
        except DifferentialUnsupported as exc:
            return DiffResult("unsupported", detail=str(exc)[:300])
        result, i, restarts = DiffResult("agree"), 0, 0
        while i < samples:
            count = min(chunk, samples - i)
            code, out, err, hung = _run(exe, i, count, seed, chunk_timeout_s)
            for line in out.splitlines():
                m = re.match(r"DIFF (\d+) (.*)", line)
                if m and len(result.counterexamples) < max_counterexamples:
                    idx = int(m.group(1))
                    if not any(c["index"] == idx for c in result.counterexamples):
                        result.counterexamples.append({"index": idx, "kind": "output", "detail": m.group(2)})
            if code == 0 and not hung:
                result.inputs_run += count
                i += count
                continue
            mark = _last_marker(err)
            if mark is None:
                return DiffResult("incomplete", result.inputs_run, result.inputs_excluded,
                                  result.counterexamples, "harness failed before the first input")
            phase, idx = mark
            result.inputs_run += idx - i
            if phase == "I":  # P_ref aborted or hung on this input: outside its defined domain
                result.inputs_excluded += 1
            elif phase == "R":  # candidate aborted or hung where P_ref returned
                kind = "nontermination" if hung else "sanitizer abort"
                if len(result.counterexamples) < max_counterexamples:
                    result.counterexamples.append({"index": idx, "kind": kind, "detail": err[-200:].strip()})
            else:  # crashed between inputs: harness fault
                return DiffResult("incomplete", result.inputs_run, result.inputs_excluded,
                                  result.counterexamples, "abort outside a call")
            i = idx + 1
            restarts += 1
            if result.inputs_run == 0 and result.inputs_excluded >= 50:
                result.status, result.detail = "reference_undefined", "P_ref undefined on every tried input"
                return result
            if restarts > max_restarts:
                result.status, result.detail = "incomplete", "restart budget exhausted"
                break
        confirmed = []
        for cex in result.counterexamples:  # replay: P_ref must be deterministic on that input
            runs = [_run(exe, cex["index"], 1, seed, chunk_timeout_s) for _ in range(2)]
            if cex["kind"] != "output" or runs[0][1] == runs[1][1]:
                confirmed.append(cex)
        result.counterexamples = confirmed
        if confirmed:
            result.status = "disagree"
        return result
