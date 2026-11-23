"""Compile independent C differential tests and replay all solver witnesses."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import argparse
import hashlib
import json
import re
import shutil
import subprocess

from pycparser import c_ast
from hlscheck.checker import parse, type_name

ROOT = Path(__file__).resolve().parents[1]


def interface(source):
    fn = parse(source, "kernel")
    params = []
    for p in fn.decl.type.args.params:
        length = int(p.type.dim.value) if isinstance(p.type, c_ast.ArrayDecl) else None
        params.append((p.name, length))
    return type_name(fn.decl.type.type) != "void", params


def renamed(source, name):
    return re.sub(r"\bkernel\b", name, source)


def declarations(params, suffix, values=None, copy=None):
    lines, args = [], []
    for name, length in params:
        var = name + suffix
        args.append(var)
        if length:
            lines.append(f"uint32_t {var}[{length}];")
            for i in range(length):
                value = f"{values[name][i]}u" if values is not None else (f"{name}{copy}[{i}]" if copy else "next_value(t)")
                lines.append(f"{var}[{i}]={value};")
        else:
            value = f"{values[name]}u" if values is not None else (name + copy if copy else "next_value(t)")
            lines.append(f"uint32_t {var}={value};")
    return lines, ",".join(args)


RANDOM = """
static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}
"""


def comparison(returns, params, left="_a", right="_b"):
    conditions = [f"ret{left}!=ret{right}"] if returns else []
    conditions += [f"{n}{left}[{i}]!={n}{right}[{i}]" for n, length in params if length for i in range(length)]
    return " || ".join(conditions) or "0"


def calls(returns, largs, rargs, right="optimized"):
    prefix = "uint32_t ret_a=" if returns else ""
    prefix_b = "uint32_t ret_b=" if returns else ""
    return [f"{prefix}original({largs});", f"{prefix_b}{right}({rargs});"]


def hls_testbench(original, count=16):
    returns, params = interface(original)
    # The top implementation is supplied by Bambu, while the local golden
    # function is compiled only into the C testbench.
    prototype = ("uint32_t" if returns else "void") + " kernel(" + ",".join(
        f"uint32_t {n}[{length}]" if length else f"uint32_t {n}" for n, length in params) + ");"
    lines = ["#include <stdint.h>", "#include <assert.h>", prototype, renamed(original, "original"), RANDOM,
             "int main(void){", f"for(unsigned t=0;t<{count};++t){{"]
    decl_a, args_a = declarations(params, "_a")
    decl_b, args_b = declarations(params, "_b", copy="_a")
    lines += decl_a + decl_b + calls(returns, args_a, args_b, "kernel")
    lines += [f"assert(!({comparison(returns, params)}));", "}", "return 0;}"]
    return "\n".join(lines) + "\n"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--trials", type=int, default=264)
    args = parser.parse_args()
    compiler = shutil.which("clang") or shutil.which("gcc")
    if not compiler:
        raise SystemExit("Install clang or gcc to run the independent native checks")
    out = ROOT / "results/native"
    out.mkdir(parents=True, exist_ok=True)
    rows = []
    catalog = json.loads((ROOT / "experiments/catalog.json").read_text())
    for case in catalog["cases"]:
        name = case["name"]
        folder = ROOT / case["directory"]
        sources = {v: (folder / f"{name}_{v}.c").read_text() for v in ("original", "optimized", "buggy")}
        returns, params = interface(sources["original"])
        witness = json.loads((ROOT / f"results/submission_verification/{name}_buggy.json").read_text())["verification"]
        lines = ["#include <stdint.h>", "#include <stdio.h>", '_Static_assert(sizeof(unsigned)==4,"requires unsigned32");']
        lines += [renamed(sources[v], v) for v in sources] + [RANDOM, "int main(void){", "unsigned failures=0;", f"for(unsigned t=0;t<{args.trials};++t){{"]
        da, aa = declarations(params, "_a")
        db, ab = declarations(params, "_b", copy="_a")
        lines += da + db + calls(returns, aa, ab)
        lines += [f"if({comparison(returns,params)}) ++failures;", "}", "{"]
        da, aa = declarations(params, "_a", values=witness["counterexample"])
        db, ab = declarations(params, "_b", values=witness["counterexample"])
        lines += da + db + calls(returns, aa, ab, "buggy")
        lines += [f"unsigned witness_mismatch=({comparison(returns,params)});", "unsigned witness_agrees=1;"]
        for n, length in params:
            if length:
                for i in range(length):
                    lines.append(f"witness_agrees &= ({n}_a[{i}]=={witness['original_outputs'][n][i]}u && {n}_b[{i}]=={witness['candidate_outputs'][n][i]}u);")
        if returns:
            lines.append(f"witness_agrees &= (ret_a=={witness['original_outputs']['return']}u && ret_b=={witness['candidate_outputs']['return']}u);")
        lines += ['printf("%u %u %u\\n",failures,witness_mismatch,witness_agrees);', "return failures || !witness_mismatch || !witness_agrees;", "}", "}"]
        source = out / f"{name}_differential.c"
        # Avoid Windows installer-detection keywords such as "update" in a
        # test executable's filename: these are ordinary console checks.
        executable = out / (f"native_check_{len(rows):03d}" + (".exe" if __import__('os').name == 'nt' else ".out"))
        source.write_text("\n".join(lines) + "\n")
        command = [compiler, "-std=c11", "-O2", str(source), "-o", str(executable)]
        built = subprocess.run(command, capture_output=True, text=True, timeout=60)
        (out / f"{name}_compile.log").write_text(built.stdout+built.stderr)
        if built.returncode:
            raise RuntimeError(built.stderr)
        result = subprocess.run([str(executable)], capture_output=True, text=True, timeout=30)
        (out / f"{name}_run.log").write_text(result.stdout + result.stderr)
        failures, mismatch, agrees = map(int, result.stdout.strip().split())
        row = {"case": name, "trials": args.trials, "directed_trials": 8, "random_trials": args.trials-8,
               "optimized_mismatches": failures, "bug_witness_replayed": bool(mismatch),
               "concrete_outputs_match_solver": bool(agrees), "command": command,
               "harness_sha256": hashlib.sha256(source.read_bytes()).hexdigest(), "exit_code": result.returncode,
               'source_sha256':{v:hashlib.sha256((folder/f'{name}_{v}.c').read_bytes()).hexdigest() for v in sources}}
        rows.append(row)
        (out / f"{name}_hls_tb.c").write_text(hls_testbench(sources["original"]))
        print(name, "native trials", args.trials, "witness replay", bool(mismatch and agrees), flush=True)
    version = subprocess.run([compiler,"--version"], capture_output=True,text=True).stdout.splitlines()[0]
    summary = {"compiler":version, "seed":"0x5291abcd", "passed": all(r["exit_code"]==0 for r in rows), "cases":rows}
    (out / "summary.json").write_text(json.dumps(summary,indent=2)+"\n")
    return 0 if summary["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
