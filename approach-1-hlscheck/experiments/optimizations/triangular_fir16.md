# triangular_fir16: Reuse adjacent pair sums

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** filter.

**Rewrite:** Reuse adjacent pair sums.

**Motivation:** Factor a [1,2,1] filter into reusable pair sums, avoiding a temporary array.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `beee4ce07f96f6446f113a7738a61ca34fc14fb1399847f3141474ea62d1f23f`.

[Standalone C file](../../benchmarks/expanded/triangular_fir16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[14]) {
    for(int i=0;i<14;i++) out[i]=a[i]+2u*a[i+1]+a[i+2];
}
```

### Optimized

SHA-256: `5c267b676f106ae9bce618070e9c9c9f2dd2338d931139c41feb62bce93af92e`.

[Standalone C file](../../benchmarks/expanded/triangular_fir16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reuse adjacent pair sums. */
void kernel(uint32_t a[16], uint32_t out[14]) {
    uint32_t previous=a[0]+a[1];for(int i=0;i<14;i++){uint32_t next=a[i+1]+a[i+2];out[i]=previous+next;previous=next;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.008446 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/triangular_fir16_optimized.json) and [main SMT query](../../results/submission_verification/triangular_fir16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/triangular_fir16_buggy.c) and [counterexample record](../../results/submission_verification/triangular_fir16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1958.03 | 1510.61 | 0.7715 |
| STA period estimate (ns) | 1.68471 | 2.2141 | 1.314 |
| RTL latency cycles | 58 | 45 | 0.7759 |
| Latency at 10 ns clock (ns) | 580 | 450 | 0.7759 |
| Area x latency (um² ns) | 1.13566e+06 | 679776 | 0.5986 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/triangular_fir16_original/) / [candidate raw evidence](../../results/hls/triangular_fir16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/triangular_fir16_original.c benchmarks/expanded/triangular_fir16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_triangular_fir16.smt2
```
