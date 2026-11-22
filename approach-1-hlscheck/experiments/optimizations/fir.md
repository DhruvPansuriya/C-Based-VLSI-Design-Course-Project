# fir: symmetric pre-addition

**Origin:** educational symmetric FIR reference.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** symmetric pre-addition.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `40a9fd8465748b12a5f6db5af5ccf2fecc21a213960b86668b28e71a3da9f995`.

[Standalone C file](../../benchmarks/submission/fir_original.c)

```c
#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t sum = a[0] * 3u;
    sum += a[1] * 5u;
    sum += a[2] * 7u;
    sum += a[3] * 11u;
    sum += a[4] * 11u;
    sum += a[5] * 7u;
    sum += a[6] * 5u;
    sum += a[7] * 3u;
    return sum;
}
```

### Optimized

SHA-256: `a19b9fac0ecdfe3f96a7ea82213763d53367cadd60ac48c38fd93bc2a1e2e18c`.

[Standalone C file](../../benchmarks/submission/fir_optimized.c)

```c
#include <stdint.h>

/* LLM rewrite: exploit coefficient symmetry through pre-addition. */
uint32_t kernel(uint32_t a[8]) {
    return (a[0] + a[7]) * 3u + (a[1] + a[6]) * 5u
         + (a[2] + a[5]) * 7u + (a[3] + a[4]) * 11u;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.003660 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/fir_optimized.json) and [main SMT query](../../results/submission_verification/fir_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/submission/fir_buggy.c) and [counterexample record](../../results/submission_verification/fir_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 5558.07 | 5092.57 | 0.9162 |
| STA period estimate (ns) | 3.18167 | 3.20851 | 1.008 |
| RTL latency cycles | 5 | 5 | 1 |
| Latency at 10 ns clock (ns) | 50 | 50 | 1 |
| Area x latency (um² ns) | 277904 | 254628 | 0.9162 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/fir_original/) / [candidate raw evidence](../../results/hls/fir_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/submission/fir_original.c benchmarks/submission/fir_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_fir.smt2
```
