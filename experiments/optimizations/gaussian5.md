# gaussian5: Separable integer Gaussian filter

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** image.

**Rewrite:** Separable integer Gaussian filter.

**Motivation:** Factor the 3x3 outer-product coefficient matrix into horizontal and vertical filters. Buffer cost is included in hardware area.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `a64ef1188617924164578c9576f83a79f6ad1dcaf05c3c8db4dbf5611a715084`.

[Standalone C file](../../benchmarks/expanded/gaussian5_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    for(int r=0;r<3;r++) for(int c=0;c<3;c++){
    uint32_t sum=0u;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){uint32_t wi=i==1?2u:1u;uint32_t wj=j==1?2u:1u;sum+=wi*wj*image[(r+i)*5+c+j];}
    out[r*3+c]=sum;}
}
```

### Optimized

SHA-256: `ea2e070a3d18b0a1aeffdc51dd79ba908a634ebcec1662349307b60004e454c0`.

[Standalone C file](../../benchmarks/expanded/gaussian5_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Separable integer Gaussian filter. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for(int r=0;r<5;r++) for(int c=0;c<3;c++) horizontal[r*3+c]=image[r*5+c]+2u*image[r*5+c+1]+image[r*5+c+2];
    for(int r=0;r<3;r++) for(int c=0;c<3;c++) out[r*3+c]=horizontal[r*3+c]+2u*horizontal[(r+1)*3+c]+horizontal[(r+2)*3+c];
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.050752 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/gaussian5_optimized.json) and [main SMT query](../../results/submission_verification/gaussian5_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/gaussian5_buggy.c) and [counterexample record](../../results/submission_verification/gaussian5_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1800.82 | 8919.25 | 4.953 |
| STA period estimate (ns) | 2.22854 | 5.68942 | 2.553 |
| RTL latency cycles | 158 | 102 | 0.6456 |
| Latency at 10 ns clock (ns) | 1580 | 1020 | 0.6456 |
| Area x latency (um² ns) | 2.8453e+06 | 9.09763e+06 | 3.197 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/gaussian5_original/) / [candidate raw evidence](../../results/hls/gaussian5_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/gaussian5_original.c benchmarks/expanded/gaussian5_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_gaussian5.smt2
```
