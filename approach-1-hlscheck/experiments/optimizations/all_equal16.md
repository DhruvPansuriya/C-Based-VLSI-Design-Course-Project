# all_equal16: XOR/OR equality reduction

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** predicate reduction.

**Rewrite:** XOR/OR equality reduction.

**Motivation:** Replace repeated Boolean comparisons with a bitwise difference reduction followed by one equality test.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `ad70a27f2c1105734b4d01bc54bba28193fdc028a706716a1bdc1674397c3645`.

[Standalone C file](../../benchmarks/expanded/all_equal16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t same=1u;for(int i=1;i<16;i++) same&=(a[i]==a[0]?1u:0u);return same;
}
```

### Optimized

SHA-256: `0c3a335f12be926f3ff592eacfd34dbf0a3b6da0f5e958eb020c0ef2883090ea`.

[Standalone C file](../../benchmarks/expanded/all_equal16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   XOR/OR equality reduction. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t difference=0u;uint32_t first=a[0];
    for(int i=1;i<16;i++) difference|=a[i]^first;
    return difference==0u?1u:0u;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.042512 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/all_equal16_optimized.json) and [main SMT query](../../results/submission_verification/all_equal16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/all_equal16_buggy.c) and [counterexample record](../../results/submission_verification/all_equal16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 471.086 | 669.256 | 1.421 |
| STA period estimate (ns) | 0.696284 | 0.767285 | 1.102 |
| RTL latency cycles | 19 | 19 | 1 |
| Latency at 10 ns clock (ns) | 190 | 190 | 1 |
| Area x latency (um² ns) | 89506.3 | 127159 | 1.421 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/all_equal16_original/) / [candidate raw evidence](../../results/hls/all_equal16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/all_equal16_original.c benchmarks/expanded/all_equal16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_all_equal16.smt2
```
