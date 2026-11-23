"""Reuse ESBMC's C frontend and Z3 with an automatically generated C miter.

This is a verification harness adapter, not a reimplementation of ESBMC.
Default safety and unwinding assertions are retained. An incomplete unwind
never becomes an equivalence claim.
"""

from __future__ import annotations

import json
import os
import re
import shutil
import subprocess
import time
from pathlib import Path

from pycparser import c_ast, c_generator, c_parser

from .checker import Unsupported, parse


def kind_of(node):
    if not isinstance(node, c_ast.TypeDecl) or not isinstance(node.type, c_ast.IdentifierType):
        raise Unsupported("Harness parameters require explicit scalar or array types")
    names = node.type.names
    if "volatile" in node.quals or "_Atomic" in node.quals:
        raise Unsupported("volatile/atomic interfaces are unsupported")
    if names in (["uint32_t"], ["unsigned"], ["unsigned", "int"]): return "unsigned int"
    if names in (["int"], ["signed"], ["signed", "int"]): return "int"
    if names == ["void"]: return "void"
    raise Unsupported("Harness currently supports int/unsigned int/uint32_t interfaces")


def parameter_specs(fn):
    params = fn.decl.type.args.params if fn.decl.type.args else []
    if len(params) == 1 and isinstance(params[0], c_ast.Typename) and kind_of(params[0].type) == "void":
        return []
    specs = []
    for parameter in params:
        if not isinstance(parameter, c_ast.Decl):
            raise Unsupported("Unsupported parameter declaration")
        node = parameter.type
        length = None
        if isinstance(node, c_ast.ArrayDecl):
            if not isinstance(node.dim, c_ast.Constant) or not node.dim.value.isdecimal():
                raise Unsupported("Harness array dimensions must be decimal integer literals")
            length = int(node.dim.value)
            if not 1 <= length <= 4096:
                raise Unsupported("Harness array length must be in 1..4096")
            node = node.type
        kind = kind_of(node)
        if kind == "void": raise Unsupported("Invalid parameter type")
        specs.append({"name": parameter.name, "kind": kind, "length": length})
    return specs


def make_harness(original, candidate, function=None, scalar_ranges=None):
    left, right = parse(original, function), parse(candidate, function)
    left_specs, right_specs = parameter_specs(left), parameter_specs(right)
    lshape = [(s["kind"], s["length"]) for s in left_specs]
    rshape = [(s["kind"], s["length"]) for s in right_specs]
    return_type = kind_of(left.decl.type.type)
    if lshape != rshape or return_type != kind_of(right.decl.type.type):
        raise Unsupported("Function signatures differ")
    reserved = {"__hls_original", "__hls_candidate", "main", "__hls_nondet_uint", "__hls_nondet_int"}
    class RejectReserved(c_ast.NodeVisitor):
        def visit_ID(self, node):
            if node.name in reserved:
                raise Unsupported("Input uses a harness-reserved identifier")
        def visit_FuncCall(self, node):
            raise Unsupported("Source calls/recursion require an explicit model and are unsupported by this adapter")
        def visit_Decl(self, node):
            if node.storage:
                raise Unsupported("Static/extern/thread-local declarations require a persistent-state model")
            self.generic_visit(node)
    RejectReserved().visit(left)
    RejectReserved().visit(right)
    left.decl.name = left.decl.type.type.declname = "__hls_original"
    right.decl.name = right.decl.type.type.declname = "__hls_candidate"
    generator = c_generator.CGenerator()
    text = ["#include <stdint.h>",
            'extern void __ESBMC_assert(_Bool, const char *);',
            'extern void __ESBMC_assume(_Bool);',
            'extern unsigned int __hls_nondet_uint(void);',
            'extern int __hls_nondet_int(void);',
            '_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");',
            generator.visit(left), generator.visit(right), "int main(void) {"]
    left_args, right_args, assertions = [], [], []
    scalar_ranges = scalar_ranges or {}
    known = {s["name"] for s in left_specs if s["length"] is None}
    if not set(scalar_ranges).issubset(known):
        raise Unsupported("Range constraints must name scalar parameters in the original")
    for position, spec in enumerate(left_specs):
        name, kind, n = spec["name"], spec["kind"], spec["length"]
        nondet = "__hls_nondet_uint" if kind == "unsigned int" else "__hls_nondet_int"
        if n is None:
            arg = f"input_{position}"
            text.append(f"{kind} {arg} = {nondet}();")
            if name in scalar_ranges:
                limits = scalar_ranges[name]
                if len(limits) != 2 or not all(type(x) is int for x in limits):
                    raise Unsupported("Each scalar range must be [integer_min, integer_max]")
                low, high = limits
                domain = (0, 2**32 - 1) if kind == "unsigned int" else (-2**31, 2**31 - 1)
                if not domain[0] <= low <= high <= domain[1]:
                    raise Unsupported("Empty or out-of-domain scalar range")
                suffix = "u" if kind == "unsigned int" else ""
                text.append(f"__ESBMC_assume({arg} >= {low}{suffix} && {arg} <= {high}{suffix});")
            left_args.append(arg)
            right_args.append(arg)
        else:
            a, b = f"original_arg_{position}", f"candidate_arg_{position}"
            text += [f"{kind} {a}[{n}];", f"{kind} {b}[{n}];",
                     f"for (int seed_{position}=0; seed_{position}<{n}; seed_{position}++) {{",
                     f"{kind} value = {nondet}();", f"{a}[seed_{position}] = value;",
                     f"{b}[seed_{position}] = value;", "}"]
            left_args.append(a)
            right_args.append(b)
            assertions += [f"for(int compare_{position}=0; compare_{position}<{n}; compare_{position}++) {{",
                           f'__ESBMC_assert({a}[compare_{position}]=={b}[compare_{position}], "EQUIV:array:{position}");', "}"]
    a_call, b_call = f"__hls_original({','.join(left_args)})", f"__hls_candidate({','.join(right_args)})"
    if return_type == "void":
        text += [a_call + ";", b_call + ";"]
    else:
        text += [f"{return_type} original_return={a_call};", f"{return_type} candidate_return={b_call};",
                 '__ESBMC_assert(original_return==candidate_return, "EQUIV:return");']
    text += assertions + ["return 0;", "}"]
    return "\n".join(text) + "\n", {"parameters": left_specs, "scalar_ranges": scalar_ranges,
        "assumptions": ["32-bit int/unsigned int", "Array parameters valid and pairwise nonoverlapping",
                        "All scalar/array inputs symbolic over their full type domain except stated ranges",
                        "Default ESBMC bounds, pointer and unwinding checks retained; signed overflow and shift UB checks enabled"]}


def classify_log(output, returncode):
    # Never infer equivalence from exit status alone, or from a safety failure.
    if returncode == 0 and "VERIFICATION SUCCESSFUL" in output:
        return "equivalent"
    if "VERIFICATION FAILED" in output:
        failed_lines = [line for line in output.splitlines() if re.search(r"\bFAILED\s+\[", line)]
        if any("unwind" in line.lower() for line in failed_lines):
            return "incomplete_unwind"
        if any("EQUIV:" not in line for line in failed_lines):
            return "safety_violation"
        violated = re.search(r"Violated property:(.*?)(?:VERIFICATION FAILED|$)", output, re.S)
        detail = violated.group(1) if violated else ""
        if "unwinding assertion" in detail.lower(): return "incomplete_unwind"
        if "EQUIV:" in detail: return "not_equivalent"
        return "safety_violation"
    return "error" if returncode else "unknown"


def run_esbmc(original, candidate, *, output_dir, executable=None, function=None,
              scalar_ranges=None, unwind=256, timeout_seconds=30):
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    bundled = Path(__file__).resolve().parents[1] / "tools/esbmc-v8.7/release/bin/esbmc.exe"
    executable = Path(executable or os.environ.get("ESBMC_PATH") or
                      (str(bundled) if bundled.exists() else shutil.which("esbmc") or str(bundled)))
    result = {"backend": "ESBMC", "solver": "Z3", "status": "error"}
    start = time.perf_counter()
    try:
        if unwind < 1 or timeout_seconds < 1:
            raise Unsupported("Unwind and timeout must be positive")
        harness, contract = make_harness(original, candidate, function, scalar_ranges)
        result.update(contract)
        harness_path = output_dir / "harness.c"
        harness_path.write_text(harness, encoding="utf-8")
        command = [str(executable.resolve()), str(harness_path.resolve()), "--z3", "--bv",
                   "--unwind", str(unwind), "--overflow-check", "--ub-shift-check",
                   "--uninitialised-vars-check", "--multi-property"]
        # ESBMC's own timeout is unimplemented on Windows; subprocess supplies
        # the wall-clock bound on all platforms.
        if os.name != "nt":
            command += ["--timeout", f"{timeout_seconds}s"]
        result.update(command=command, unwind=unwind, timeout_seconds=timeout_seconds)
        process = subprocess.run(command, capture_output=True, text=True, errors="replace",
                                 timeout=timeout_seconds + 10, cwd=output_dir)
        output = process.stdout + "\n" + process.stderr
        (output_dir / "esbmc.log").write_text(output, encoding="utf-8")
        result.update(status=classify_log(output, process.returncode), returncode=process.returncode)
        result["version"] = next((line for line in output.splitlines() if "ESBMC version" in line), "not reported")
        result["solver_report"] = next((line for line in output.splitlines() if "Z3" in line), "not reported")
    except Unsupported as error:
        result.update(status="unsupported", reason=str(error))
    except subprocess.TimeoutExpired as error:
        partial = (error.stdout or b"")
        errors = (error.stderr or b"")
        if isinstance(partial, bytes): partial = partial.decode("utf-8", errors="replace")
        if isinstance(errors, bytes): errors = errors.decode("utf-8", errors="replace")
        (output_dir / "esbmc.log").write_text(partial + "\n" + errors + "\nExternal wall-clock timeout.\n", encoding="utf-8")
        result.update(status="unknown", reason="External verifier exceeded its wall-clock timeout")
    except (OSError, ValueError, c_parser.ParseError) as error:
        result.update(status="error", reason=str(error))
    result["elapsed_seconds"] = round(time.perf_counter() - start, 6)
    (output_dir / "result.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    return result
