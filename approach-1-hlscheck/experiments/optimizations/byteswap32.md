# byteswap32: Two-stage byte permutation

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** Two-stage byte permutation.

**Motivation:** Replace the byte-collection loop with pairwise byte swaps and a half-word swap.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `90795d45851e75030af958450b91a9464cec16e5b7a67ace125c646238917ec9`.

[Standalone C file](../../benchmarks/expanded/byteswap32_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t y=0u;for(int i=0;i<4;i++) y|=((x>>(i*8))&255u)<<((3-i)*8);return y;
}
```

### Optimized

SHA-256: `f2183f4979a28c346de4bb849091595348f73b134746d21e14e8c69a8e762c01`.

[Standalone C file](../../benchmarks/expanded/byteswap32_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-stage byte permutation. */
uint32_t kernel(uint32_t x) {
    uint32_t t=((x&0x00ff00ffu)<<8)|((x>>8)&0x00ff00ffu);return (t<<16)|(t>>16);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.003889 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/byteswap32_optimized.json) and [main SMT query](../../results/submission_verification/byteswap32_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/byteswap32_buggy.c) and [counterexample record](../../results/submission_verification/byteswap32_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 308.826 | 0.532 | 0.001723 |
| STA period estimate (ns) | 0.498322 | 0.054166 | 0.1087 |
| RTL latency cycles | 6 | 1 | 0.1667 |
| Latency at 10 ns clock (ns) | 60 | 10 | 0.1667 |
| Area x latency (um² ns) | 18529.6 | 5.32 | 0.0002871 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/byteswap32_original/) / [candidate raw evidence](../../results/hls/byteswap32_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/byteswap32_original.c benchmarks/expanded/byteswap32_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_byteswap32.smt2
```
