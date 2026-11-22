# maxpool4: Balanced two-by-two max pooling

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** image.

**Rewrite:** Balanced two-by-two max pooling.

**Motivation:** Expose a fixed comparison tree and avoid a generic nested reduction loop; same comparison family as max8.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `e1217242bf0f753c72c9bbb4fb464e1afe6481d35c0e92e04d42a440f7086615`.

[Standalone C file](../../benchmarks/expanded/maxpool4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){uint32_t best=image[r*8+c*2];for(int i=0;i<2;i++) for(int j=0;j<2;j++){uint32_t v=image[(r*2+i)*4+c*2+j];best=v>best?v:best;}out[r*2+c]=best;}
}
```

### Optimized

SHA-256: `7f85223f15d6f3e86830101941fd162bdf9bdbdbd68a9170cba8912f79fb0f40`.

[Standalone C file](../../benchmarks/expanded/maxpool4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Balanced two-by-two max pooling. */
void kernel(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.453591 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/maxpool4_optimized.json) and [main SMT query](../../results/submission_verification/maxpool4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/maxpool4_buggy.c) and [counterexample record](../../results/submission_verification/maxpool4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1074.64 | 2170.29 | 2.02 |
| STA period estimate (ns) | 1.38692 | 2.60575 | 1.879 |
| RTL latency cycles | 48 | 20 | 0.4167 |
| Latency at 10 ns clock (ns) | 480 | 200 | 0.4167 |
| Area x latency (um² ns) | 515827 | 434059 | 0.8415 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/maxpool4_original/) / [candidate raw evidence](../../results/hls/maxpool4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/maxpool4_original.c benchmarks/expanded/maxpool4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_maxpool4.smt2
```
