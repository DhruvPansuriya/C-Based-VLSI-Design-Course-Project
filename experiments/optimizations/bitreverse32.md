# bitreverse32: Staged mask-and-swap bit reversal

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** Staged mask-and-swap bit reversal.

**Motivation:** Replace serial bit extraction with five permutation stages.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `1061706098a75b2fa2c0ff02ff2f876a32903df13e9a566a6cba83d5c0a8ff00`.

[Standalone C file](../../benchmarks/expanded/bitreverse32_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t y=0u;for(int i=0;i<32;i++){y=(y<<1)|(x&1u);x=x>>1;}return y;
}
```

### Optimized

SHA-256: `542c1b6257ae7214cad4806c96a67b38174f1cb962e5ae9d19232097747cef53`.

[Standalone C file](../../benchmarks/expanded/bitreverse32_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Staged mask-and-swap bit reversal. */
uint32_t kernel(uint32_t x) {
    x=((x>>1)&0x55555555u)|((x&0x55555555u)<<1);
    x=((x>>2)&0x33333333u)|((x&0x33333333u)<<2);
    x=((x>>4)&0x0f0f0f0fu)|((x&0x0f0f0f0fu)<<4);
    x=((x>>8)&0x00ff00ffu)|((x&0x00ff00ffu)<<8);
    return (x>>16)|(x<<16);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.014545 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/bitreverse32_optimized.json) and [main SMT query](../../results/submission_verification/bitreverse32_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/bitreverse32_buggy.c) and [counterexample record](../../results/submission_verification/bitreverse32_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 515.508 | 0.532 | 0.001032 |
| STA period estimate (ns) | 0.689333 | 0.054166 | 0.07858 |
| RTL latency cycles | 34 | 1 | 0.02941 |
| Latency at 10 ns clock (ns) | 340 | 10 | 0.02941 |
| Area x latency (um² ns) | 175273 | 5.32 | 3.035e-05 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/bitreverse32_original/) / [candidate raw evidence](../../results/hls/bitreverse32_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/bitreverse32_original.c benchmarks/expanded/bitreverse32_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_bitreverse32.smt2
```
