# Matrix multiplication: move k to the outermost loop

`matmul_ijk.cpp` and `matmul_kij.cpp` multiply two 4 x 4 matrices. The only
transformation is the accumulation loop order: i-j-k becomes k-i-j. Both
versions first initialize all output elements to zero.

Matrices use row-major one-dimensional arrays: element (i,j) is at `i*4+j`.
Inputs and outputs are unsigned 32-bit values; multiplication and addition
wrap modulo 2^32. The arrays must be valid and nonoverlapping.

These are C-compatible C++ sources. The current checker models their C
semantics, and the native demonstration compiles them as C++17. The existing
Bambu pipeline receives byte-identical `.c` copies, compiles them as C11 and
checks sixteen RTL transactions against the original reference. This is an
integer C-subset demonstration, not general C++ verification.

From the project root:

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

This is the generic seven-stage pipeline: it reads the actual top-level files
and prints formal, native, RTL, area, timing and comparison outputs. Evidence
is saved in a fresh `results/demo_pipeline/run_*` folder. Add `--verify-only`
to omit hardware. See [the walkthrough](../../docs/FILE_PIPELINE.md).

The earlier dedicated example driver remains reproducible:

```powershell
.\.venv\Scripts\python.exe scripts/run_matmul_demo.py --verify-only
.\.venv\Scripts\python.exe scripts/run_matmul_demo.py
```

The first command proves equivalence and runs compiled C++ comparisons. The
second additionally runs fresh Bambu, Verilator, Yosys and OpenSTA measurements
for both versions. It stops before HLS unless the exact source pair is proved
equivalent. Evidence and a comparison report are saved under
`results/matmul_loop_order/`. A loop interchange is only an optimization
candidate: its area, delay and latency are measured rather than assumed better.
