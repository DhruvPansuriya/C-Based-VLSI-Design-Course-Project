# count_nonzero16: Parallel predicate counters

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** predicate reduction.

**Rewrite:** Parallel predicate counters.

**Motivation:** Expose four independent count accumulators without input-dependent loop bounds.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `a4f0566a2ce187c3a234bb78d9b760ed7591ab9bfe01c70cd3ccc9c3b929cd64`.

[Standalone C file](../../benchmarks/expanded/count_nonzero16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]!=0u?1u:0u);return n;
}
```

### Optimized

SHA-256: `bb464a59a0289cc17317b24e600040ba69438c4bd80fb6fa2fd055b3e5a1b0b5`.

[Standalone C file](../../benchmarks/expanded/count_nonzero16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Parallel predicate counters. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t n0=0u,n1=0u,n2=0u,n3=0u;
    for(int i=0;i<16;i+=4){n0+=(a[i]!=0u?1u:0u);n1+=(a[i+1]!=0u?1u:0u);n2+=(a[i+2]!=0u?1u:0u);n3+=(a[i+3]!=0u?1u:0u);}
    return (n0+n1)+(n2+n3);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.012391 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/count_nonzero16_optimized.json) and [main SMT query](../../results/submission_verification/count_nonzero16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/count_nonzero16_buggy.c) and [counterexample record](../../results/submission_verification/count_nonzero16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 437.304 | 3587.81 | 8.204 |
| STA period estimate (ns) | 1.41411 | 4.39954 | 3.111 |
| RTL latency cycles | 19 | 11 | 0.5789 |
| Latency at 10 ns clock (ns) | 190 | 110 | 0.5789 |
| Area x latency (um² ns) | 83087.8 | 394659 | 4.75 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/count_nonzero16_original/) / [candidate raw evidence](../../results/hls/count_nonzero16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/count_nonzero16_original.c benchmarks/expanded/count_nonzero16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_count_nonzero16.smt2
```
