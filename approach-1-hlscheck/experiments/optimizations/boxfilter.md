# boxfilter: separable sliding-window reuse

**Origin:** educational 3x3 box-filter reference.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** separable sliding-window reuse.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `503d18c2a8751ab64fd28dc52079e24907d1c305d661e2ddb3354f5e3485fa59`.

[Standalone C file](../../benchmarks/submission/boxfilter_original.c)

```c
#include <stdint.h>

/* Educational 3x3 box sum over the nine valid windows of a 5x5 image. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t sum = 0u;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    sum += image[(r + y) * 5 + c + x];
                }
            }
            out[r * 3 + c] = sum;
        }
    }
}
```

### Optimized

SHA-256: `38f69bf2f33ce50dea73695e2f6f93ee31f6413cb892a043fe1633d64dc6819a`.

[Standalone C file](../../benchmarks/submission/boxfilter_optimized.c)

```c
#include <stdint.h>

/* LLM rewrite: separable filtering, reusing horizontal sums across rows. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for (int r = 0; r < 5; r++) {
        uint32_t sum = image[r * 5] + image[r * 5 + 1] + image[r * 5 + 2];
        horizontal[r * 3] = sum;
        for (int c = 1; c < 3; c++) {
            sum = sum - image[r * 5 + c - 1] + image[r * 5 + c + 2];
            horizontal[r * 3 + c] = sum;
        }
    }
    for (int r2 = 0; r2 < 3; r2++) {
        for (int c2 = 0; c2 < 3; c2++) {
            out[r2 * 3 + c2] = horizontal[r2 * 3 + c2]
                + horizontal[(r2 + 1) * 3 + c2] + horizontal[(r2 + 2) * 3 + c2];
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.023178 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/boxfilter_optimized.json) and [main SMT query](../../results/submission_verification/boxfilter_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/submission/boxfilter_buggy.c) and [counterexample record](../../results/submission_verification/boxfilter_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1135.82 | 9712.99 | 8.552 |
| STA period estimate (ns) | 1.5586 | 5.97588 | 3.834 |
| RTL latency cycles | 158 | 87 | 0.5506 |
| Latency at 10 ns clock (ns) | 1580 | 870 | 0.5506 |
| Area x latency (um² ns) | 1.7946e+06 | 8.4503e+06 | 4.709 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/boxfilter_original/) / [candidate raw evidence](../../results/hls/boxfilter_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/submission/boxfilter_original.c benchmarks/submission/boxfilter_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_boxfilter.smt2
```
