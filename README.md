# Approach-1: HLSCheck - LLM-optimized HLS code with formal equivalence

This is our first approach, HLSCheck, exactly as we packaged it (the full project ZIP),
plus our final report and slides in [report/](report/README.md). Start here, then read
[RESULTS.md](RESULTS.md) for all experiment groups, measured tables and links to their evidence.
Some older files still call it "Project 3"; that is the same work.

## What the project does

An LLM rewrites a C kernel to improve hardware. We first check whether the
rewrite preserves behavior, then measure its synthesized hardware. Correctness
and hardware benefit are separate decisions: a correct rewrite can be slower
or larger.

```text
Original C + LLM candidate
    -> input/contract checks
    -> formal C-to-C equivalence
    -> proof-evidence replay and input binding
    -> compiled-C edge/random checks
    -> Bambu HLS + Verilator RTL simulation
    -> Yosys area + OpenSTA timing
    -> original/candidate comparison
```

The checker lives in `hlscheck/`. Our symbolic executor and Z3 prove relations
between program regions. Those certified relations simplify a C product program
whose remaining behavior ESBMC/Z3 verifies. If an abstract mismatch loses a
necessary relationship, the checker refines the summary or restores original
code. This combines established verification ideas; ESBMC itself is reused
without modification. See [the algorithm](docs/INTEGRATED_ALGORITHM.md) when
you want the proof details.

## Run it

After installing the dependencies described in [SETUP.md](SETUP.md), run from
the extracted project root:

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

It prints all seven stages. Add `--verify-only` for proof and compiled-C checks
without HLS. Non-equivalent or unproved code stops before synthesis. Each run
gets a fresh `results/demo_pipeline/run_*` folder; `latest.json` points to it.
Use `python run_demo.py --help` for options.

The two top-level matmul files are a simple 4x4 example. `matmul.cpp` uses
i-j-k loops; `matmul_opti.cpp` uses k-i-j. Both first zero the output and add
`a[i*4+k] * b[k*4+j]` to `out[i*4+j]`. Arrays are flattened row-major uint32
values, with addition/multiplication modulo 2^32. They must not overlap.
The pair proves equivalent, but recorded hardware area/latency regress.
The ZIP uses the canonical equivalent example; it does not overwrite the
sender's current editor files.

A small negative example is ready too:

```powershell
.\.venv\Scripts\python.exe run_demo.py benchmarks/pipeline_smoke/wrong_original.c benchmarks/pipeline_smoke/wrong_optimized.c --function kernel
```

For a subtle matmul mistake, `matmul_wrong.cpp` changes multiplication to
addition. Comparing it with `matmul.cpp` should produce a non-equivalence
witness and stop before HLS:

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_wrong.cpp --function kernel
```

## Where to look

| Folder/file | Purpose |
| --- | --- |
| `RESULTS.md` | Combined results overview; positive percentage means improvement |
| `hlscheck/` | Frontend, symbolic reasoning, summaries, residual products and evidence checking |
| `scripts/design_pipeline.py`, `scripts/design_testbench.py` | Full pipeline and generated native/RTL reference harnesses |
| `tools/run_hls_linux.py` | Bambu, Verilator, Yosys and OpenSTA driver |
| `benchmarks/`, `matmul*.cpp` | Runnable originals, rewrites and negative controls |
| `experiments/`, `results/` | Plans, provenance, prompts, raw responses, candidates, proofs and hardware evidence |
| `tests/`, `docs/` | Regression checks and optional detailed explanations |
| `output/pdf/`, `output/presentation/` | Existing course report and slides |
| `datasets/papers/` | Eight downloaded related-work papers |

For the presentation, lead with the two-model study and use the 50-pair cohort
and fault controls as supporting evidence. The key finding is that formal
equivalence filters semantic mistakes, while measured HLS reveals whether a
correct optimization helps. There are substantial wins and real regressions.

Scope: supported C11/ILP32 integer kernels, valid nonoverlapping arrays, and
explicit input assumptions. `.cpp` examples use the C-compatible subset.
Hardware numbers are mapped pre-layout Nangate45 ASIC estimates. RTL simulation
is sampled validation, not a formal C-to-RTL proof. No paid inference API is
needed to inspect results or run the supplied candidate pairs.
