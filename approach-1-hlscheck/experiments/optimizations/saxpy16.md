# saxpy16: Two-lane SAXPY source unrolling

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** elementwise.

**Rewrite:** Two-lane SAXPY source unrolling.

**Motivation:** Expose two independent multiply-add outputs while preserving unsigned wraparound.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `eaf2ba3906ea925de21de22c484f48b9e0eef31bc694627f62ceace51a32e05f`.

[Standalone C file](../../benchmarks/expanded/saxpy16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t k, uint32_t out[16]) {
    for(int i=0;i<16;i++) out[i]=a[i]*k+b[i];
}
```

### Optimized

SHA-256: `b3777be06600bbd53366cb9adde3bba6c570d96fba68298b9641edc0e4800f40`.

[Standalone C file](../../benchmarks/expanded/saxpy16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-lane SAXPY source unrolling. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t k, uint32_t out[16]) {
    for(int i=0;i<16;i+=2){out[i]=a[i]*k+b[i];out[i+1]=a[i+1]*k+b[i+1];}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.008090 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/saxpy16_optimized.json) and [main SMT query](../../results/submission_verification/saxpy16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/saxpy16_buggy.c) and [counterexample record](../../results/submission_verification/saxpy16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4469.86 | 6051.5 | 1.354 |
| STA period estimate (ns) | 1.92384 | 2.01845 | 1.049 |
| RTL latency cycles | 50 | 50 | 1 |
| Latency at 10 ns clock (ns) | 500 | 500 | 1 |
| Area x latency (um² ns) | 2.23493e+06 | 3.02575e+06 | 1.354 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/saxpy16_original/) / [candidate raw evidence](../../results/hls/saxpy16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/saxpy16_original.c benchmarks/expanded/saxpy16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_saxpy16.smt2
```
