# scale: strength reduction and two-way unrolling

**Origin:** educational microkernel.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** strength reduction and two-way unrolling.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `711800ee8d53ca1e6d4d1441a8f0eecf1035dd68ded4a6733bf25d1d70556bb9`.

[Standalone C file](../../benchmarks/demo/scale_original.c)

```c
#include <stdint.h>

void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        out[i] = a[i] * 8u + 3u;
    }
}
```

### Optimized

SHA-256: `03c043c69d50003b08c552df3c2b6568c4e725d322b5e01375eb3593f9818f33`.

[Standalone C file](../../benchmarks/demo/scale_optimized.c)

```c
#include <stdint.h>

/* LLM-authored candidate: strength reduction and two-way source unrolling.
   Candidate status is determined independently by hlscheck. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = (a[i] << 3) + 3u;
        out[i + 1] = (a[i + 1] << 3) + 3u;
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.145598 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/scale_optimized.json) and [main SMT query](../../results/submission_verification/scale_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/demo/scale_buggy.c) and [counterexample record](../../results/submission_verification/scale_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 718.998 | 2122.15 | 2.952 |
| STA period estimate (ns) | 1.30368 | 1.427 | 1.095 |
| RTL latency cycles | 26 | 26 | 1 |
| Latency at 10 ns clock (ns) | 260 | 260 | 1 |
| Area x latency (um² ns) | 186939 | 551758 | 2.952 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/scale_original/) / [candidate raw evidence](../../results/hls/scale_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/demo/scale_original.c benchmarks/demo/scale_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_scale.smt2
```
