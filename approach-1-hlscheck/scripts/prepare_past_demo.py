"""Prepare PAST's annotated-region format and invoke it in Ubuntu/WSL.

Inputs remain unchanged; generated region files are derived comparison inputs.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import json
import subprocess

from pycparser import c_ast, c_generator

from hlscheck.checker import Unsupported, parse
from hlscheck.esbmc_backend import parameter_specs


def region(source):
    fn = parse(source, "kernel")
    parameters = parameter_specs(fn)
    if any(p["length"] is None for p in parameters):
        raise Unsupported("This PAST adapter currently supports array-only interfaces")
    if fn.decl.type.type.type.names != ["void"]:
        raise Unsupported("This PAST adapter requires a void-returning kernel")
    generator = c_generator.CGenerator()
    declarations = [generator.visit(p) + ";" for p in fn.decl.type.args.params]
    text = "\n".join(declarations) + "\n#pragma pocc-region-start\n" + generator.visit(fn.body) + "\n#pragma pocc-region-end\n"
    return text.replace("uint32_t", "unsigned int"), ",".join(p["name"] for p in parameters)


def main():
    root = Path(__file__).resolve().parents[1]
    output = root / "results/past"
    output.mkdir(parents=True, exist_ok=True)
    directory = root / "benchmarks/demo"
    original, liveouts = region((directory / "scale_original.c").read_text())
    (output / "original.c").write_text(original)
    cases = []
    for name, filename in (("self", "scale_original.c"), ("unroll_only", "scale_unrolled.c"),
                           ("strength_reduction", "scale_optimized.c"), ("seeded_bug", "scale_buggy.c")):
        candidate, candidate_liveouts = region((directory / filename).read_text())
        assert liveouts == candidate_liveouts
        path = output / f"{name}.c"
        path.write_text(candidate)
        cases.append({"name": name, "original": "results/past/original.c",
                      "candidate": str(path.relative_to(root)).replace("\\", "/"), "liveouts": liveouts})
    cases.append({"name": "strength_reduction_all_normalizations", "original": "results/past/original.c",
                  "candidate": "results/past/strength_reduction.c", "liveouts": liveouts,
                  "all_normalizations": 1})
    for family in ("gemm", "stencil"):
        source_dir = root / "benchmarks/machsuite_u32"
        text, names = region((source_dir / f"{family}_original.c").read_text())
        source_path = output / f"{family}_original.c"
        source_path.write_text(text)
        for variant in ("optimized", "buggy"):
            text, candidate_names = region((source_dir / f"{family}_{variant}.c").read_text())
            assert names == candidate_names
            path = output / f"{family}_{variant}.c"
            path.write_text(text)
            cases.append({"name": f"{family}_{variant}",
                          "original": str(source_path.relative_to(root)).replace("\\", "/"),
                          "candidate": str(path.relative_to(root)).replace("\\", "/"), "liveouts": names})
    request = output / "request.json"
    request.write_text(json.dumps({"cases": cases}, indent=2) + "\n")
    completed = subprocess.run(["wsl", "-d", "Ubuntu", "--", "python3", "tools/past_worker.py", "results/past/request.json"], cwd=root)
    return completed.returncode


if __name__ == "__main__":
    raise SystemExit(main())
