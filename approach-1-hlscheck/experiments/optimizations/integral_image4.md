# integral_image4: Dynamic-programming summed-area table

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** image.

**Rewrite:** Dynamic-programming summed-area table.

**Motivation:** Reuse already computed rectangle sums rather than recomputing every rectangle; preserves all final output cells.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `747a095197a660314353e99f4521b8ae537ca631e6bdcb186026e2a6f9eba94d`.

[Standalone C file](../../benchmarks/expanded/integral_image4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){uint32_t sum=0u;for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) sum+=image[i*4+j];out[r*4+c]=sum;}
}
```

### Optimized

SHA-256: `df71ae1a84d9d1db42103736f797617a0078bf8c50c7b04403ee4d6c90163f71`.

[Standalone C file](../../benchmarks/expanded/integral_image4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Dynamic-programming summed-area table. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){
    uint32_t value=image[r*4+c];
    if(r>0) value+=out[(r-1)*4+c];
    if(c>0) value+=out[r*4+c-1];
    if(r>0 && c>0) value-=out[(r-1)*4+c-1];
    out[r*4+c]=value;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.026848 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/integral_image4_optimized.json) and [main SMT query](../../results/submission_verification/integral_image4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/integral_image4_buggy.c) and [counterexample record](../../results/submission_verification/integral_image4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 3076.02 | 3029.21 | 0.9848 |
| STA period estimate (ns) | 2.33723 | 2.78627 | 1.192 |
| RTL latency cycles | 262 | 102 | 0.3893 |
| Latency at 10 ns clock (ns) | 2620 | 1020 | 0.3893 |
| Area x latency (um² ns) | 8.05918e+06 | 3.08979e+06 | 0.3834 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/integral_image4_original/) / [candidate raw evidence](../../results/hls/integral_image4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/integral_image4_original.c benchmarks/expanded/integral_image4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_integral_image4.smt2
```
