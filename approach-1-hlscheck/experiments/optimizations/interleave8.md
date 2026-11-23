# interleave8: Fuse interleaving output loops

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** data movement.

**Rewrite:** Fuse interleaving output loops.

**Motivation:** Pair adjacent destination writes; related to the inverse deinterleave operation.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `615628c06000abf72239d97241f194a52be959bcf4e5cac6a7de24a9f457dc79`.

[Standalone C file](../../benchmarks/expanded/interleave8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[8], uint32_t b[8], uint32_t out[16]) {
    for(int i=0;i<8;i++) out[2*i]=a[i];for(int j=0;j<8;j++) out[2*j+1]=b[j];
}
```

### Optimized

SHA-256: `8d1a181bb94b7d12e87d48194bbd541c793667a5a97b331eb146ebb422ee274f`.

[Standalone C file](../../benchmarks/expanded/interleave8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse interleaving output loops. */
void kernel(uint32_t a[8], uint32_t b[8], uint32_t out[16]) {
    for(int i=0;i<8;i++){out[2*i]=a[i];out[2*i+1]=b[i];}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.006099 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/interleave8_optimized.json) and [main SMT query](../../results/submission_verification/interleave8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/interleave8_buggy.c) and [counterexample record](../../results/submission_verification/interleave8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1284.51 | 1426.29 | 1.11 |
| STA period estimate (ns) | 1.30843 | 1.95842 | 1.497 |
| RTL latency cycles | 50 | 50 | 1 |
| Latency at 10 ns clock (ns) | 500 | 500 | 1 |
| Area x latency (um² ns) | 642257 | 713146 | 1.11 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/interleave8_original/) / [candidate raw evidence](../../results/hls/interleave8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/interleave8_original.c benchmarks/expanded/interleave8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_interleave8.smt2
```
