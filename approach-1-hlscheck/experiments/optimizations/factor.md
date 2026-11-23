# factor: distributive factoring

**Origin:** educational arithmetic control.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** distributive factoring.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `4c5ab0c47fe19460d398b0ac0b97c451aa195b9a8a78967aa4d96700a1827e9a`.

[Standalone C file](../../benchmarks/submission/factor_original.c)

```c
#include <stdint.h>

uint32_t kernel(uint32_t x, uint32_t y, uint32_t z) {
    return x * y + x * z;
}
```

### Optimized

SHA-256: `d0e015a648ca615554b15139b7c2e24a3483efa67bff3e95d348d9d33d177878`.

[Standalone C file](../../benchmarks/submission/factor_optimized.c)

```c
#include <stdint.h>

/* LLM rewrite: distributive factoring, valid in the uint32_t ring. */
uint32_t kernel(uint32_t x, uint32_t y, uint32_t z) {
    return x * (y + z);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.002000 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/factor_optimized.json) and [main SMT query](../../results/submission_verification/factor_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/submission/factor_buggy.c) and [counterexample record](../../results/submission_verification/factor_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 3412.25 | 3412.25 | 1 |
| STA period estimate (ns) | 2.69641 | 2.69641 | 1 |
| RTL latency cycles | 1 | 1 | 1 |
| Latency at 10 ns clock (ns) | 10 | 10 | 1 |
| Area x latency (um² ns) | 34122.5 | 34122.5 | 1 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/factor_original/) / [candidate raw evidence](../../results/hls/factor_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/submission/factor_original.c benchmarks/submission/factor_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_factor.smt2
```
