# parity32: XOR-fold parity

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** XOR-fold parity.

**Motivation:** Reduce a 32-iteration bit scan to five XOR-fold stages.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `2144016aecc1ec992f7d016d7bb9c024f686c2735ae638889370b1dd88e7c784`.

[Standalone C file](../../benchmarks/expanded/parity32_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t parity=0u;for(int i=0;i<32;i++) parity^=(x>>i)&1u;return parity;
}
```

### Optimized

SHA-256: `8cff69ae6ee0e94d89df26cb645383a7cf22a0d9f4c8312c8bfab55efa3dd7fc`.

[Standalone C file](../../benchmarks/expanded/parity32_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   XOR-fold parity. */
uint32_t kernel(uint32_t x) {
    x^=x>>16;x^=x>>8;x^=x>>4;x^=x>>2;x^=x>>1;return x&1u;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.008703 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/parity32_optimized.json) and [main SMT query](../../results/submission_verification/parity32_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/parity32_buggy.c) and [counterexample record](../../results/submission_verification/parity32_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 130.34 | 50.008 | 0.3837 |
| STA period estimate (ns) | 0.545412 | 0.276039 | 0.5061 |
| RTL latency cycles | 34 | 1 | 0.02941 |
| Latency at 10 ns clock (ns) | 340 | 10 | 0.02941 |
| Area x latency (um² ns) | 44315.6 | 500.08 | 0.01128 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/parity32_original/) / [candidate raw evidence](../../results/hls/parity32_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/parity32_original.c benchmarks/expanded/parity32_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_parity32.smt2
```
