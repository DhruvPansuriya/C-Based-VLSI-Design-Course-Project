# range8: Fuse minimum and maximum scans

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** comparison reduction.

**Rewrite:** Fuse minimum and maximum scans.

**Motivation:** Reuse each memory read to update both extrema; source reference computes both on the same unrestricted input.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `bde9f77244f0d0f8e73da6cfb25445e7cf837f13f609fc36950de7b48b4b5af8`.

[Standalone C file](../../benchmarks/expanded/range8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++) low=a[i]<low?a[i]:low;
    for(int j=1;j<8;j++) high=a[j]>high?a[j]:high;
    return high-low;
}
```

### Optimized

SHA-256: `fc2302c71eb082c92d53a2730ead450d28cf46af99c6cacb7adba1c3a4e7a49f`.

[Standalone C file](../../benchmarks/expanded/range8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse minimum and maximum scans. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
    return high-low;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.010488 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/range8_optimized.json) and [main SMT query](../../results/submission_verification/range8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/range8_buggy.c) and [counterexample record](../../results/submission_verification/range8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1822.63 | 1341.17 | 0.7358 |
| STA period estimate (ns) | 1.74355 | 1.45692 | 0.8356 |
| RTL latency cycles | 11 | 11 | 1 |
| Latency at 10 ns clock (ns) | 110 | 110 | 1 |
| Area x latency (um² ns) | 200490 | 147529 | 0.7358 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/range8_original/) / [candidate raw evidence](../../results/hls/range8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/range8_original.c benchmarks/expanded/range8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_range8.smt2
```
