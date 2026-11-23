# xor32: Four-way XOR reduction

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** reduction.

**Rewrite:** Four-way XOR reduction.

**Motivation:** Use associativity of XOR to shorten a dependency chain; shares the reduction family with sum32, not an independent application.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `d0e4135d774f107dcfb6637d6dfa5452ec0c21e6b6d32fa29e90e69f65fe3c7a`.

[Standalone C file](../../benchmarks/expanded/xor32_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[32]) {
    uint32_t sum=0u;for(int i=0;i<32;i++) sum^=a[i];return sum;
}
```

### Optimized

SHA-256: `8b6517be52d3128d8ac4f235ba0a64f4c27b3abd4144aadb94801e7a22db3646`.

[Standalone C file](../../benchmarks/expanded/xor32_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Four-way XOR reduction. */
uint32_t kernel(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
    return (s0^s1)^(s2^s3);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.008566 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/xor32_optimized.json) and [main SMT query](../../results/submission_verification/xor32_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/xor32_buggy.c) and [counterexample record](../../results/submission_verification/xor32_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 439.166 | 2488.96 | 5.667 |
| STA period estimate (ns) | 1.12875 | 3.206 | 2.84 |
| RTL latency cycles | 35 | 19 | 0.5429 |
| Latency at 10 ns clock (ns) | 350 | 190 | 0.5429 |
| Area x latency (um² ns) | 153708 | 472903 | 3.077 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/xor32_original/) / [candidate raw evidence](../../results/hls/xor32_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/xor32_original.c benchmarks/expanded/xor32_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_xor32.smt2
```
