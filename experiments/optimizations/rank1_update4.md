# rank1_update4: Hoist the row scalar and expand a rank-one update

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Hoist the row scalar and expand a rank-one update.

**Motivation:** Reuse x[r] across four output products and expose column parallelism.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `80d14fed9933c599cce8eec7034e39c842f6d957829373ae1b76db16eacac32b`.

[Standalone C file](../../benchmarks/expanded/rank1_update4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++) out[r*4+c]=a[r*4+c]+x[r]*y[c];
}
```

### Optimized

SHA-256: `78a270efce5cb4a99e112d33737ec4af9f7cedcd1352450e580d322227d5ef2c`.

[Standalone C file](../../benchmarks/expanded/rank1_update4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Hoist the row scalar and expand a rank-one update. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16]) {
    for(int r=0;r<4;r++){uint32_t v=x[r];out[r*4]=a[r*4]+v*y[0];out[r*4+1]=a[r*4+1]+v*y[1];out[r*4+2]=a[r*4+2]+v*y[2];out[r*4+3]=a[r*4+3]+v*y[3];}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.009051 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/rank1_update4_optimized.json) and [main SMT query](../../results/submission_verification/rank1_update4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/rank1_update4_buggy.c) and [counterexample record](../../results/submission_verification/rank1_update4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 5331.44 | 8667.34 | 1.626 |
| STA period estimate (ns) | 2.35069 | 3.50357 | 1.49 |
| RTL latency cycles | 74 | 54 | 0.7297 |
| Latency at 10 ns clock (ns) | 740 | 540 | 0.7297 |
| Area x latency (um² ns) | 3.94526e+06 | 4.68037e+06 | 1.186 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/rank1_update4_original/) / [candidate raw evidence](../../results/hls/rank1_update4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/rank1_update4_original.c benchmarks/expanded/rank1_update4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_rank1_update4.smt2
```
