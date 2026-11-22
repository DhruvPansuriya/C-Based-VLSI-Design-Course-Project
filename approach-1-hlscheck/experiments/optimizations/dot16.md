# dot16: Four independent dot-product accumulators

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** reduction.

**Rewrite:** Four independent dot-product accumulators.

**Motivation:** Break the single accumulation dependency while preserving modulo arithmetic; extra multipliers may increase area.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `5ad5a6400b0ddf72312bf33fac9a581494b0f9a8ccc5ed1e20820931fc33fa19`.

[Standalone C file](../../benchmarks/expanded/dot16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16], uint32_t b[16]) {
    uint32_t sum=0u;
    for(int i=0;i<16;i++) sum+=a[i]*b[i];
    return sum;
}
```

### Optimized

SHA-256: `ab4ffb53233868c0e3844d664294fa1bcd49bc80f4e6693ceca214fb31473436`.

[Standalone C file](../../benchmarks/expanded/dot16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Four independent dot-product accumulators. */
uint32_t kernel(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
    return (s0+s1)+(s2+s3);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.006846 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/dot16_optimized.json) and [main SMT query](../../results/submission_verification/dot16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/dot16_buggy.c) and [counterexample record](../../results/submission_verification/dot16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 3993.72 | 8760.71 | 2.194 |
| STA period estimate (ns) | 2.00353 | 2.96748 | 1.481 |
| RTL latency cycles | 19 | 19 | 1 |
| Latency at 10 ns clock (ns) | 190 | 190 | 1 |
| Area x latency (um² ns) | 758808 | 1.66453e+06 | 2.194 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/dot16_original/) / [candidate raw evidence](../../results/hls/dot16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/dot16_original.c benchmarks/expanded/dot16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_dot16.smt2
```
