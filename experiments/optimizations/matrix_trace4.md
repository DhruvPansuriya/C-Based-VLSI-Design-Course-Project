# matrix_trace4: Traverse only diagonal indices

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Traverse only diagonal indices.

**Motivation:** Remove a scan over non-diagonal entries; this is a small control/memory microkernel.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `66cc52bfb2df6950820be529dd8c5fcb3d206036779a2588862f3bc96942c96c`.

[Standalone C file](../../benchmarks/expanded/matrix_trace4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) for(int c=0;c<4;c++) if(r==c) sum+=a[r*4+c];return sum;
}
```

### Optimized

SHA-256: `80aae252076126370d6bc2b3c9a0080ff28b289911e3a4203c98432845f6775c`.

[Standalone C file](../../benchmarks/expanded/matrix_trace4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Traverse only diagonal indices. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int i=0;i<4;i++) sum+=a[i*5];return sum;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.005368 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/matrix_trace4_optimized.json) and [main SMT query](../../results/submission_verification/matrix_trace4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/matrix_trace4_buggy.c) and [counterexample record](../../results/submission_verification/matrix_trace4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 850.934 | 544.502 | 0.6399 |
| STA period estimate (ns) | 1.36156 | 1.42923 | 1.05 |
| RTL latency cycles | 50 | 7 | 0.14 |
| Latency at 10 ns clock (ns) | 500 | 70 | 0.14 |
| Area x latency (um² ns) | 425467 | 38115.1 | 0.08958 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/matrix_trace4_original/) / [candidate raw evidence](../../results/hls/matrix_trace4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/matrix_trace4_original.c benchmarks/expanded/matrix_trace4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_matrix_trace4.smt2
```
