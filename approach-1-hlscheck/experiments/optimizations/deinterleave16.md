# deinterleave16: Fuse even/odd extraction loops

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** data movement.

**Rewrite:** Fuse even/odd extraction loops.

**Motivation:** Combine two related output scans, retaining independent observable arrays.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `a45e28b99abffd43c8eca90b75bf3a978c7fa832ab85ced146c8f94b7afb13f1`.

[Standalone C file](../../benchmarks/expanded/deinterleave16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++) even[i]=a[2*i];for(int j=0;j<8;j++) odd[j]=a[2*j+1];
}
```

### Optimized

SHA-256: `3cd419e9f10cc5796a43fb71d94a136d599d2ea624e00e4f7524b5ab55edf786`.

[Standalone C file](../../benchmarks/expanded/deinterleave16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse even/odd extraction loops. */
void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.006735 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/deinterleave16_optimized.json) and [main SMT query](../../results/submission_verification/deinterleave16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/deinterleave16_buggy.c) and [counterexample record](../../results/submission_verification/deinterleave16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1166.94 | 1426.82 | 1.223 |
| STA period estimate (ns) | 1.69108 | 2.04819 | 1.211 |
| RTL latency cycles | 50 | 34 | 0.68 |
| Latency at 10 ns clock (ns) | 500 | 340 | 0.68 |
| Area x latency (um² ns) | 583471 | 485120 | 0.8314 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/deinterleave16_original/) / [candidate raw evidence](../../results/hls/deinterleave16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/deinterleave16_original.c benchmarks/expanded/deinterleave16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_deinterleave16.smt2
```
