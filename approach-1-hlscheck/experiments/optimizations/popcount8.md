# popcount8: Byte-wide SWAR population count

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** Byte-wide SWAR population count.

**Motivation:** Count the low eight bits with parallel masked add/subtract stages; all high input bits are ignored in both versions.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `172bdc0fed00501725a4d43d15729bd91ffd8fa2c27d9a97bc8674a9cf55ff5c`.

[Standalone C file](../../benchmarks/expanded/popcount8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t count=0u;for(int i=0;i<8;i++) count+=(x>>i)&1u;return count;
}
```

### Optimized

SHA-256: `a48187ad913cfdf6e0c356d2a2d0d4d7f141412f84e71d877ef0a4cffab6d9fa`.

[Standalone C file](../../benchmarks/expanded/popcount8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Byte-wide SWAR population count. */
uint32_t kernel(uint32_t x) {
    uint32_t v=x&255u;v=v-((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);return (v+(v>>4))&15u;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.035658 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/popcount8_optimized.json) and [main SMT query](../../results/submission_verification/popcount8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/popcount8_buggy.c) and [counterexample record](../../results/submission_verification/popcount8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 329.308 | 29.26 | 0.08885 |
| STA period estimate (ns) | 0.747034 | 0.254551 | 0.3407 |
| RTL latency cycles | 10 | 1 | 0.1 |
| Latency at 10 ns clock (ns) | 100 | 10 | 0.1 |
| Area x latency (um² ns) | 32930.8 | 292.6 | 0.008885 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/popcount8_original/) / [candidate raw evidence](../../results/hls/popcount8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/popcount8_original.c benchmarks/expanded/popcount8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_popcount8.smt2
```
