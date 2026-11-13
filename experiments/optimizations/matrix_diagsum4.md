# matrix_diagsum4: Direct traversal of two disjoint diagonals

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Direct traversal of two disjoint diagonals.

**Motivation:** For the fixed even dimension the two diagonals do not overlap; no data-domain restriction is required. Related to matrix_trace4.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `27e66e5c14585f11eda6d8533bb43bd46da1b6b18864fd9f4b8e8e357de61e4c`.

[Standalone C file](../../benchmarks/expanded/matrix_diagsum4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) for(int c=0;c<4;c++) if(r==c || r+c==3) sum+=a[r*4+c];return sum;
}
```

### Optimized

SHA-256: `85d10f2901245f956b87f2d29690bbea65600ecdec2af131a8090706fd86c43a`.

[Standalone C file](../../benchmarks/expanded/matrix_diagsum4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Direct traversal of two disjoint diagonals. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) sum+=a[r*4+r]+a[r*4+3-r];return sum;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.006997 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/matrix_diagsum4_optimized.json) and [main SMT query](../../results/submission_verification/matrix_diagsum4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/matrix_diagsum4_buggy.c) and [counterexample record](../../results/submission_verification/matrix_diagsum4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 865.83 | 806.778 | 0.9318 |
| STA period estimate (ns) | 1.37437 | 1.61132 | 1.172 |
| RTL latency cycles | 58 | 7 | 0.1207 |
| Latency at 10 ns clock (ns) | 580 | 70 | 0.1207 |
| Area x latency (um² ns) | 502181 | 56474.5 | 0.1125 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/matrix_diagsum4_original/) / [candidate raw evidence](../../results/hls/matrix_diagsum4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/matrix_diagsum4_original.c benchmarks/expanded/matrix_diagsum4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_matrix_diagsum4.smt2
```
