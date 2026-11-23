"""Independent oracle: replay Z3's witnesses in compiled C, not the interpreter."""

import re
import shutil
import subprocess
from pathlib import Path

import pytest

from hlscheck import check_equivalence


@pytest.mark.parametrize("family", ["scale", "unswitch", "gemm", "stencil"])
def test_counterexample_compiled_c(tmp_path, family):
    compiler = shutil.which("clang") or shutil.which("gcc")
    if compiler is None:
        pytest.skip("Requires a native C compiler")
    subdir = "machsuite_u32" if family in ("gemm", "stencil") else "demo"
    folder = Path(__file__).resolve().parents[1] / "benchmarks" / subdir
    original = (folder / f"{family}_original.c").read_text()
    candidate = (folder / f"{family}_buggy.c").read_text()
    # Match the project's configured per-obligation budget. Nonlinear GEMM
    # witness search can exceed the legacy symbolic API's 10-second default.
    result = check_equivalence(original, candidate, "kernel", timeout_ms=60000)
    assert result["status"] == "not_equivalent"
    inputs = result["counterexample"]
    harness = ['#include <stdint.h>', '#include <stdio.h>',
               '_Static_assert(sizeof(unsigned)==4, "requires unsigned32");',
               re.sub(r"\bkernel\b", "original", original),
               re.sub(r"\bkernel\b", "candidate", candidate),
               'int main(void) {']
    left_args, right_args, prints = [], [], []
    for name, value in inputs.items():
        if isinstance(value, list):
            initializer = ','.join(f'{x}u' for x in value)
            for suffix in ('a', 'b'):
                harness.append(f'uint32_t {name}_{suffix}[{len(value)}] = {{{initializer}}};')
            left_args.append(f'{name}_a')
            right_args.append(f'{name}_b')
            for i in range(len(value)):
                prints.append(f'printf("%u %u\\n", {name}_a[{i}], {name}_b[{i}]);')
        else:
            left_args.append(f'{value}u')
            right_args.append(f'{value}u')
    harness += [f'original({",".join(left_args)});', f'candidate({",".join(right_args)});']
    harness += prints + ['return 0;', '}']
    source = tmp_path / 'replay.c'
    executable = tmp_path / 'replay.exe'
    source.write_text('\n'.join(harness), encoding='utf-8')
    built = subprocess.run([compiler, '-std=c11', '-O0', str(source), '-o', str(executable)],
                           capture_output=True, text=True, timeout=30)
    assert built.returncode == 0, built.stderr
    run = subprocess.run([str(executable)], capture_output=True, text=True, timeout=10, check=True)
    observed = [tuple(map(int, line.split())) for line in run.stdout.splitlines()]
    assert any(a != b for a, b in observed)
    expected = []
    for name, value in inputs.items():
        if isinstance(value, list):
            expected.extend(zip(result['original_outputs'][name], result['candidate_outputs'][name]))
    assert observed == expected
