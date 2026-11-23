# stencil: filter-column source unrolling

**Origin:** MachSuite stencil2d adapted to uint32_t and 5x5 dimensions.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** filter-column source unrolling.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `8c46a73e96b8c5cf7b0b2ee7a25f26ac6f2bd090f01a4c9d6dc0479275937149`.

[Standalone C file](../../benchmarks/machsuite_u32/stencil_original.c)

```c
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    temp += filter[k1 * 3 + k2] * orig[(r + k1) * 5 + c + k2];
                }
            }
            sol[r * 5 + c] = temp;
        }
    }
}
```

### Optimized

SHA-256: `3b3b99ec35449cc4986ad4a87a64d884753438507dee5f0703260449c2010603`.

[Standalone C file](../../benchmarks/machsuite_u32/stencil_optimized.c)

```c
/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                int base = (r + k1) * 5 + c;
                temp += filter[k1 * 3] * orig[base];
                temp += filter[k1 * 3 + 1] * orig[base + 1];
                temp += filter[k1 * 3 + 2] * orig[base + 2];
            }
            sol[r * 5 + c] = temp;
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.030700 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/stencil_optimized.json) and [main SMT query](../../results/submission_verification/stencil_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/machsuite_u32/stencil_buggy.c) and [counterexample record](../../results/submission_verification/stencil_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4493.01 | 6646.54 | 1.479 |
| STA period estimate (ns) | 1.89648 | 2.45196 | 1.293 |
| RTL latency cycles | 158 | 116 | 0.7342 |
| Latency at 10 ns clock (ns) | 1580 | 1160 | 0.7342 |
| Area x latency (um² ns) | 7.09895e+06 | 7.70999e+06 | 1.086 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/stencil_original/) / [candidate raw evidence](../../results/hls/stencil_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/machsuite_u32/stencil_original.c benchmarks/machsuite_u32/stencil_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_stencil.smt2
```
