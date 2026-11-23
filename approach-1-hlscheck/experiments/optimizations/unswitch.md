# unswitch: loop unswitching

**Origin:** CS5291 course example adapted to unsigned data and fixed bounds.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** loop unswitching.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `7c5365ca9545acc01de39421dd4632b0c3b3d9c0ef9c4354400084308baf7d35`.

[Standalone C file](../../benchmarks/demo/unswitch_original.c)

```c
#include <stdint.h>

/* Adapted from the loop-unswitching example in CS5291 W10L2.
   Uses uint32_t, zero-based indexing, and a fixed dimension. */
void kernel(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    for (int i = 0; i < 4; i++) {
        if (x > 10u) {
            a[i] = b[i] + c[i];
        } else {
            a[i] = b[i] - c[i];
        }
    }
}
```

### Optimized

SHA-256: `6fc9674226bc6a9e318fa147dcde12f2c263f64ad5c87a091f8273b662475db6`.

[Standalone C file](../../benchmarks/demo/unswitch_optimized.c)

```c
#include <stdint.h>

/* LLM-authored adaptation: hoist the invariant branch outside the loop. */
void kernel(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    if (x > 10u) {
        for (int i = 0; i < 4; i++) {
            a[i] = b[i] + c[i];
        }
    } else {
        for (int j = 0; j < 4; j++) {
            a[j] = b[j] - c[j];
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.034207 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/unswitch_optimized.json) and [main SMT query](../../results/submission_verification/unswitch_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/demo/unswitch_buggy.c) and [counterexample record](../../results/submission_verification/unswitch_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1125.98 | 1863.06 | 1.655 |
| STA period estimate (ns) | 1.53734 | 1.92765 | 1.254 |
| RTL latency cycles | 14 | 14 | 1 |
| Latency at 10 ns clock (ns) | 140 | 140 | 1 |
| Area x latency (um² ns) | 157637 | 260829 | 1.655 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/unswitch_original/) / [candidate raw evidence](../../results/hls/unswitch_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/demo/unswitch_original.c benchmarks/demo/unswitch_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_unswitch.smt2
```
