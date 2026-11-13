# hamming8: Replace nested bit scans with byte SWAR

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** Replace nested bit scans with byte SWAR.

**Motivation:** Reuse the byte-popcount technique across eight XOR differences; belongs to the same population-count family as popcount8.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `e71a55c25cae5c4e78276d4a37a4451746381ed56d9e1635e699aa2d252851a6`.

[Standalone C file](../../benchmarks/expanded/hamming8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;for(int bit=0;bit<8;bit++) total+=(v>>bit)&1u;}return total;
}
```

### Optimized

SHA-256: `bc50655c6c6ea5a21c16dbd2a44e97899b5198e3597052598daeef7883737d3e`.

[Standalone C file](../../benchmarks/expanded/hamming8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Replace nested bit scans with byte SWAR. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);total+=(v+(v>>4))&15u;}return total;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.399973 s. Z3: 5.1.0. Accepted unconditional component lemmas: 8.

[Proof record](../../results/submission_verification/hamming8_optimized.json) and [main SMT query](../../results/submission_verification/hamming8_optimized.smt2).

The main query is simplified using the following separately proved-zero components. Replay all of these queries as well as the main query:

- [hamming8_optimized.lemma001.smt2](../../results/submission_verification/hamming8_optimized.lemma001.smt2)
- [hamming8_optimized.lemma002.smt2](../../results/submission_verification/hamming8_optimized.lemma002.smt2)
- [hamming8_optimized.lemma003.smt2](../../results/submission_verification/hamming8_optimized.lemma003.smt2)
- [hamming8_optimized.lemma004.smt2](../../results/submission_verification/hamming8_optimized.lemma004.smt2)
- [hamming8_optimized.lemma005.smt2](../../results/submission_verification/hamming8_optimized.lemma005.smt2)
- [hamming8_optimized.lemma006.smt2](../../results/submission_verification/hamming8_optimized.lemma006.smt2)
- [hamming8_optimized.lemma007.smt2](../../results/submission_verification/hamming8_optimized.lemma007.smt2)
- [hamming8_optimized.lemma008.smt2](../../results/submission_verification/hamming8_optimized.lemma008.smt2)

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/hamming8_buggy.c) and [counterexample record](../../results/submission_verification/hamming8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 628.292 | 567.644 | 0.9035 |
| STA period estimate (ns) | 1.08905 | 1.11218 | 1.021 |
| RTL latency cycles | 90 | 11 | 0.1222 |
| Latency at 10 ns clock (ns) | 900 | 110 | 0.1222 |
| Area x latency (um² ns) | 565463 | 62440.8 | 0.1104 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/hamming8_original/) / [candidate raw evidence](../../results/hls/hamming8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/hamming8_original.c benchmarks/expanded/hamming8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_hamming8.smt2
```
