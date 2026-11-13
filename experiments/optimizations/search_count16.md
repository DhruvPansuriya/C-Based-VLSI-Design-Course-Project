# search_count16: Two independent equality-count lanes

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** predicate reduction.

**Rewrite:** Two independent equality-count lanes.

**Motivation:** Split a scan into partial counters; an equality-count variant of the predicate-reduction family.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `84f41d4a7a558c35ff4f8a8816493477d2a8b734c3d54c83c783e4c9b0661f8b`.

[Standalone C file](../../benchmarks/expanded/search_count16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16], uint32_t key) {
    uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]==key?1u:0u);return n;
}
```

### Optimized

SHA-256: `c9e6e24452a87ad8b677ec780dd7c77c7ca658fd625fe88ea14cc7a74482ec37`.

[Standalone C file](../../benchmarks/expanded/search_count16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two independent equality-count lanes. */
uint32_t kernel(uint32_t a[16], uint32_t key) {
    uint32_t even=0u,odd=0u;for(int i=0;i<16;i+=2){even+=(a[i]==key?1u:0u);odd+=(a[i+1]==key?1u:0u);}return even+odd;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.011222 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/search_count16_optimized.json) and [main SMT query](../../results/submission_verification/search_count16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/search_count16_buggy.c) and [counterexample record](../../results/submission_verification/search_count16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 490.504 | 1427.89 | 2.911 |
| STA period estimate (ns) | 1.29108 | 2.05323 | 1.59 |
| RTL latency cycles | 19 | 11 | 0.5789 |
| Latency at 10 ns clock (ns) | 190 | 110 | 0.5789 |
| Area x latency (um² ns) | 93195.8 | 157068 | 1.685 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/search_count16_original/) / [candidate raw evidence](../../results/hls/search_count16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/search_count16_original.c benchmarks/expanded/search_count16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_search_count16.smt2
```
