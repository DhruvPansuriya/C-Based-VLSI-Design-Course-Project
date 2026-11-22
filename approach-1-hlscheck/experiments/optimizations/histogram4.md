# histogram4: Fuse four fixed-bin histogram scans

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** predicate reduction.

**Rewrite:** Fuse four fixed-bin histogram scans.

**Motivation:** Read each input once and update four explicit counters; avoids symbolic output indices in the checker.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `334e1ce176da979e7557d706260e5fc3bc06c7bde09a84a67de87a7bf0397958`.

[Standalone C file](../../benchmarks/expanded/histogram4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[4]) {
    for(int bin=0;bin<4;bin++){uint32_t count=0u;for(int i=0;i<16;i++) count+=((a[i]&3u)==(uint32_t)bin?1u:0u);out[bin]=count;}
}
```

### Optimized

SHA-256: `16c13b4e21633447f59998b4a917255f6aaa0c9d637a000b07a200fff210b2a8`.

[Standalone C file](../../benchmarks/expanded/histogram4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse four fixed-bin histogram scans. */
void kernel(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.039787 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/histogram4_optimized.json) and [main SMT query](../../results/submission_verification/histogram4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/histogram4_buggy.c) and [counterexample record](../../results/submission_verification/histogram4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 833.112 | 2279.09 | 2.736 |
| STA period estimate (ns) | 1.30168 | 1.53767 | 1.181 |
| RTL latency cycles | 78 | 21 | 0.2692 |
| Latency at 10 ns clock (ns) | 780 | 210 | 0.2692 |
| Area x latency (um² ns) | 649827 | 478608 | 0.7365 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/histogram4_original/) / [candidate raw evidence](../../results/hls/histogram4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/histogram4_original.c benchmarks/expanded/histogram4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_histogram4.smt2
```
