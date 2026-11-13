# moving_sum16: Sliding four-element window sum

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** filter.

**Rewrite:** Sliding four-element window sum.

**Motivation:** Replace repeated window recomputation with one outgoing subtraction and incoming addition.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `cfa8d1d79c54aec578ff396c4379607c3eaa401a284144ef9f1860943e0192cb`.

[Standalone C file](../../benchmarks/expanded/moving_sum16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    for(int i=0;i<13;i++){uint32_t sum=0u;for(int j=0;j<4;j++) sum+=a[i+j];out[i]=sum;}
}
```

### Optimized

SHA-256: `501760f00c7f73a8b4a30cd44474af1f4dfe7b89a4043f63035e1b3b3898a4b2`.

[Standalone C file](../../benchmarks/expanded/moving_sum16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Sliding four-element window sum. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t sum=a[0]+a[1]+a[2]+a[3];out[0]=sum;for(int i=1;i<13;i++){sum=sum-a[i-1]+a[i+3];out[i]=sum;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.012757 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/moving_sum16_optimized.json) and [main SMT query](../../results/submission_verification/moving_sum16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/moving_sum16_buggy.c) and [counterexample record](../../results/submission_verification/moving_sum16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 978.082 | 3338.57 | 3.413 |
| STA period estimate (ns) | 1.54108 | 1.97341 | 1.281 |
| RTL latency cycles | 93 | 41 | 0.4409 |
| Latency at 10 ns clock (ns) | 930 | 410 | 0.4409 |
| Area x latency (um² ns) | 909616 | 1.36881e+06 | 1.505 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/moving_sum16_original/) / [candidate raw evidence](../../results/hls/moving_sum16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/moving_sum16_original.c benchmarks/expanded/moving_sum16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_moving_sum16.smt2
```
