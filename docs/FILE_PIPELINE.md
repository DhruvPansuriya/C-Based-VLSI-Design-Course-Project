# File-to-file proof and measured HLS pipeline

Run this from PowerShell in the project root:

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

The command reads those exact files, including your edits. It does not select
a hardcoded benchmark or show an old hardware result as a new run. It prints
each stage and retains all evidence under a new `results/demo_pipeline/run_*`
directory. `results/demo_pipeline/latest.json` records the newest run and its
status, including failed runs.

| Stage | What appears in the terminal | Saved evidence |
| --- | --- | --- |
| 1. Input validation | Actual paths, source hashes, C target, functions, array contract and scalar ranges | `inputs/`, `summary.json` |
| 2. Formal C-to-C checking | Region and residual obligations, engines, refinement actions, final verdict and elapsed time; counterexample when found | `proof/`; `counterexample/` for a reproduced mismatch |
| 3. Evidence replay and binding | Artifact/hash checks, accepted SMT query replay count, exact HLS input binding | `evidence_replay.json`, `hls_inputs/`, optional `normalization/` certificates |
| 4. Compiled-C validation | Pass/fail on 264 deterministic typed edge/random comparisons | `native/test.c`, `compile.log`, `run.log`, `result.json` |
| 5. HLS and RTL simulation | Bambu/Verilator start and completion per design; 16 transactions and their average/min/max cycles | `hls/*/bambu.log`, RTL, generated testbench, simulation logs, `bambu_results.xml` |
| 6. Mapping and timing | Yosys cell area; OpenSTA critical-path delay and 10 ns timing result | `hls/*/yosys.log`, `sta.log`, `mapped.v`, `synth.ys`, `timing.tcl`, `metrics.json` |
| 7. Comparison | Original/candidate area, cycles, latency, delay, area x latency, percentage improvements and speedup | `REPORT.md`, `hardware.json`, `summary.json` |

The two hardware implementations run in parallel by default. An original's
mapping message can therefore appear before the candidate's RTL completion.
Each line identifies the design. Stages 5 and 6 have live tool-start and
tool-completion messages; detailed tool output remains in the saved logs.

The integrated checker combines custom symbolic/Z3 region proofs with
ESBMC/Z3 residual verification. The subsequent compiled-C checks supplement
that proof. RTL simulation validates the sampled transactions; the pipeline
does not claim a formal C-to-RTL proof.

## Actual matmul run

The successful run in
`results/demo_pipeline_validation/run_ada9001fc0a9/console.log` shows:

```text
[2/7] FORMAL C-TO-C EQUIVALENCE
  region_equality: equivalent [custom symbolic execution / Z3]
  residual_0: equivalent [ESBMC / Z3]
  VERDICT: equivalent (0.532 s)
[3/7] REPLAY PROOF EVIDENCE AND BIND HLS INPUTS
  Proof artifact hashes: PASS; accepted SMT queries replayed: 1.
[4/7] COMPILED-C EDGE/RANDOM CHECKS
  PASS: 264 typed edge/random comparisons
[5/7] HLS GENERATION AND RTL SIMULATION
  [original] RTL simulation: PASS, 16 transactions, 266 average cycles
  [optimized] RTL simulation: PASS, 16 transactions, 314 average cycles
[6/7] CELL MAPPING AND STATIC TIMING (per design)
  [original] Mapped area: 4612.972 um^2
  [optimized] Mapped area: 5004.258 um^2
  [original] Critical-path delay: 1.865742 ns; meets 10 ns: True
  [optimized] Critical-path delay: 1.834684 ns; meets 10 ns: True
[7/7] MEASURED QUALITY COMPARISON
  Latency speedup: 0.847x
  Area x latency outcome: REGRESSED
Run status: complete
```

This excerpt omits some progress lines; the saved console contains the full
output and table. The k-i-j rewrite is equivalent, but its area increases
8.48% and its cycle latency increases 18.05%. Its critical path decreases
1.66%. The pipeline reports that measured regression without treating the
filename `matmul_opti.cpp` as evidence of improvement.

Cycle latency times the common 10 ns clock gives execution latency in ns.
The comparison uses `Improvement (%) = 100 * (original - optimized) / original`:
positive means better and negative means worse for every displayed cost.
For this matmul run, area improvement is -8.48%, cycle-latency improvement
is -18.05%, delay improvement is +1.66%, and area x latency improvement is
-28.06%. Earlier raw console logs retain their original `Change` convention;
regenerated reports and new runs use `Improvement`.

Critical-path delay is a separate static timing estimate. Area and timing
use Nangate45 typical standard cells and pre-layout assumptions; they are
not FPGA resource counts or routed timing results.

## Other commands and stop behavior

```powershell
# Proof, replay and compiled-C checks only:
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel --verify-only

# A known semantic error: counterexample, native witness, then stop before HLS:
.\.venv\Scripts\python.exe run_demo.py benchmarks/pipeline_smoke/wrong_original.c benchmarks/pipeline_smoke/wrong_optimized.c --function kernel

# Full-width 64-bit interface, with certified top-function renaming:
.\.venv\Scripts\python.exe run_demo.py benchmarks/pipeline_smoke/u64_original.c benchmarks/pipeline_smoke/u64_optimized.c --function sign

# See all options:
.\.venv\Scripts\python.exe run_demo.py --help
```

Useful options are `--output-dir PATH`, `--jobs 1`, `--wsl-distro Ubuntu`,
`--timeout-ms 60000`, `--native-trials 264` and `--ranges ranges.json`.
An example range file is `{"n": [0, 16]}`; these are explicit preconditions
on source parameter names, not inferred limits. The formal timeout is per
solver/verifier obligation, rather than a total wall-clock limit.

Exit codes: 0 for a completed equivalent run (full hardware or verify-only),
1 for non-equivalence, 2 for an unproved outcome, and 3 for a pipeline error.
Hardware regression still exits 0 because its measurement completed correctly.
Use `summary.json`'s `comparison.outcome` to determine hardware improvement.

Only a proved-equivalent pair with successful evidence and native checks can
enter HLS. The worker checks source snapshots, prepared HLS sources, proof
artifacts, checker implementation hashes, native harness and testbench hashes
again before starting hardware tools. Fresh run identifiers prevent stale
measurements from being reused. A failed stage reports the failure and leaves
its evidence for inspection.

## Input scope and dependencies

The existing integrated checker's C11/ILP32 contract applies. A `.cpp` suffix
is accepted for C-compatible source; it does not enable general C++. Use one
supported top function per file with matching typed scalar/fixed array
interfaces. Arrays must be valid, separate and nonoverlapping. All final
parameter-array elements and the return value are observed. Unsupported or
unproved code stops with an explicit status. HLS-synthesizability is an
additional requirement, checked by the actual hardware tools.

The prepared HLS source preserves supplied code and pragmas after line-ending
normalization. A literal non-`kernel` top declarator is renamed to `kernel`,
and that preparation is separately proved equivalent. Macro-generated top
names that cannot be safely identified are rejected. The simulation reference
adapts target `long32` locals/literals to the LP64 host; `long32` interfaces
and return types currently require an explicit adapter and are rejected.
Use fixed-width `int32_t`/`uint32_t` or `long long` interfaces where appropriate.

On this computer, the project venv, Windows Clang/ESBMC and WSL Ubuntu hardware
tools are installed. A fresh environment needs the dependencies in
`requirements.txt`, a compatible ILP32 native compiler/runtime and ESBMC.
The hardware setup is described in [REPRODUCE.md](REPRODUCE.md). No inference
API is called by this pipeline; the supplied candidate may come from any model.
