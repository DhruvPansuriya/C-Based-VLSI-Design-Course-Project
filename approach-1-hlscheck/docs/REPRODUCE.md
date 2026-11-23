# Reproduce and present Project 3

## Full pipeline for two supplied files

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

This reads the actual top-level files and prints all seven stages: input
contract, formal equivalence, evidence replay and input binding, compiled-C
comparisons, HLS/RTL simulation, cell mapping/static timing, and a measured
comparison table. The default hardware stage uses the installed WSL Ubuntu
Bambu/Verilator/Yosys/OpenSTA tools. Both designs run independently with up to
two hardware workers; every invocation uses fresh hardware work directories.

Use `--verify-only` for proof and native validation without HLS. A mismatch,
inconclusive proof, stale input or failed validation stops the pipeline. The
latest run is identified by `results/demo_pipeline/latest.json`; complete
evidence stays in its unique `run_*` directory. No-file `run_demo.py` retains
the three predefined equivalence-only examples. See
[FILE_PIPELINE.md](FILE_PIPELINE.md) for output, failure controls and limits.

## Two-model study on twelve dataset-derived inputs

The new study is separate from the main50-pair cohort and the single-kernel
pilot. Its results are in `results/two_model_study/REPORT.md`, with a complete
CSV, comparison figures and twelve before/after source dossiers. Six inputs
are documented reduced unsigned32 compute adaptations; six are renamed
type-preserving scalar leaves from MachSuite, CHStone and HLS-Eval.

```powershell
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --report
.\.venv\Scripts\python.exe scripts/validate_two_model_study.py
```

The first command regenerates tables from recorded data. The second checks
the frozen originals and upstream hashes, exact raw-response extraction,
same-prompt records, checker and retained driver fingerprints, accepted SMT
queries, native harnesses and HLS source/testbench/configuration records. It
also runs a further264 typed compiled-C comparisons per equivalent pair with
independently varied scalar arguments, checks five deliberate native-harness
controls, and exports CSV/dossiers/figures. The controls are not model samples.
The reporting Python requires matplotlib/numpy; the validator uses the
installed base reporting Python when those are absent from the checker venv.

Generation uses one first response for each of twelve inputs from local
Qwen2.5-Coder-1.5B Q4_K_M and fresh GPT-6.1-Sol Codex tasks. Each case has the
same instruction and source text for both models. Codex sampling controls are
not exposed, so it is explicitly a reference rather than identical local
sampling. No repair, resampling or checker/HLS feedback is supplied.

```powershell
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --generate-qwen
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --import-codex
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --evaluate --models qwen15
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --evaluate --models gpt61sol
.\.venv\Scripts\python.exe scripts/run_two_model_study.py --hls --jobs 2 --report
```

Existing first responses are reused only with their recorded prompt/source
hashes; the local command never silently resamples them. The Codex import
checks actual saved response and invocation records; it cannot manufacture
missing Codex calls. HLS accepts only proved-equivalent pairs with passing
native checks and matching source/proof hashes. Exact source/configuration/TB
caches may be reused. HLS runs in Linux/WSL; new formal checks use the installed
Windows Clang/ESBMC target. No external paid inference API is used.

Verification remains at60 seconds per obligation. ATAX and BiCG Codex outputs
remain inconclusive and have no hardware numbers. Python SMT checks are
sequential or in separate processes because the default Z3 context must not
be shared across worker threads. The two-worker HLS pool invokes independent
external tool processes and does not share SMT contexts.

The exact first-batch driver is retained under
`experiments/script_versions/two_model_study_initial/`; later changes add
reporting only. Current checker implementation hashes remain unchanged.

## On this computer

Open PowerShell in the project folder. The virtual environment, native Clang,
ESBMC and WSL HLS tools are already installed.

```powershell
.\.venv\Scripts\python.exe scripts/demo.py
.\.venv\Scripts\python.exe run_submission.py --tests
```

The first command is a short live proof/counterexample demonstration. The
second validates the 100 core formal records and replays their SMT queries and
eight accepted component lemmas, then runs 13,200 compiled-C trials, 50
witness replays, the rare-input demonstration, provenance checks and unit /
external-backend tests. It reads the recorded hardware results.

To rerun hardware synthesis and RTL simulation, bypassing the cache:

```powershell
.\.venv\Scripts\python.exe run_submission.py --synthesize --force-hls
```

The expanded measured run used three parallel designs and took minutes on this
machine. Runtime varies with hardware and tool setup. All source hashes must
match successful proofs before hardware synthesis is permitted.

## Fresh checkout / source submission

Use Python 3.12 and a C11 compiler. `python -m venv .venv`, activate it and run
`python -m pip install -r requirements.txt`. ESBMC 8.7 is optional for the core
unsigned kernels; its Windows binaries belong under
`tools/esbmc-v8.7/release/bin/` or set `ESBMC_PATH` to the executable. The core
proofs do not require ESBMC, PAST, commercial HLS, or API credentials.

Install Ubuntu under WSL for the hardware rerun. Linux packages used here:
`libtcl8.6`, `verilator`, `gcc`, `g++`, and `make`. For example, from the Ubuntu
terminal: `sudo apt-get install libtcl8.6 verilator build-essential`.

```powershell
wsl -d Ubuntu -- python3 tools/bootstrap_hls_linux.py --download
wsl -d Ubuntu -- python3 tools/run_hls_linux.py --jobs 2
```

The bootstrap prints download sizes: Bambu 508.89 MiB and backend bundle
74.14 MiB. It verifies the locally recorded experiment hashes, extracts under
`~/cs5291_hls_tools`, and avoids FUSE. Missing or different archives stop the
setup. These are locally recorded hashes, not upstream-signed digests.
The 6.38 MiB Nangate45 typical Liberty file and its upstream license are under
`tools/nangate45`. The source package includes that library. Full binary
archives and temporary Linux working directories are excluded from the
portable submission ZIP.

The runner writes actual per-design sources/testbenches to
`~/cs5291_hls_runs`, invokes Bambu directly with its environment set, performs
16 RTL calls per design with Verilator, maps RTL with Yosys and applies the
retained `timing.tcl` in OpenSTA. Every design's logs, RTL, mapped netlist,
testbench, constraints, source hash and metrics are copied into `results/hls`.
`--resynth-only` and `--retime-only` reuse Linux intermediate artifacts; they
are troubleshooting conveniences, not substitutes for a fresh full rerun.

## Optional independent comparisons

```powershell
.\.venv\Scripts\python.exe scripts/run_benchmark_checks.py
.\.venv\Scripts\python.exe scripts/prepare_past_demo.py
.\.venv\Scripts\python.exe scripts/write_comparison_report.py
.\.venv\Scripts\python.exe scripts/run_eqbench.py --limit 14 --timeout-ms 3000 --max-unroll 32
.\.venv\Scripts\python.exe scripts/write_eqbench_report.py
```

PAST needs the authors' Linux CPython 3.12 wheel, unpacked at
`tools/past-linux`, and is invoked through WSL. Its result 0 is reported as
`not_proved`. EqBench needs the pinned upstream checkout at `datasets/EqBench`.
Existing measurements are retained so the main demonstration does not depend
on downloading or rebuilding optional tools.

The ESBMC/PAST implementation comparison remains the initial eight pairs; it
is not presented as a full-cohort external-tool ranking. The expanded main study
contains 50 C pairs / 100 hardware implementations, with complete per-pair
dossiers under `experiments/optimizations/`. Run `scripts/write_optimization_catalog.py`
after changing or remeasuring sources to refresh those records.

The verifier may reuse exact-source/engine cached verdicts. `run_submission.py`
always replays all final SMT queries and their accepted component dependencies.
UNSAT queries and lemmas replay unrestricted; SAT queries are checked at their
exact recorded counterexamples, avoiding another nonlinear model search.
Use `python scripts/verify_submission.py --force` to rerun symbolic interpretation too.
The original expanded hardware batch log is retained at
`results/hls/EXPANDED_BATCH_LOG.txt`; later reproduction runs may use hardware
caches. Cache acceptance checks both the configuration and exact retained C
testbench, as well as the C source hash.

## Presentation and report

Open `output/presentation/project3_slides.html` in a browser. Use arrow keys
or Page Up / Page Down; press F11 for full screen. Print mode lays out all
slides. `docs/PRESENTATION_NOTES.md` contains the speaking script and viva
questions. `output/pdf/Project3_Report.pdf` is the written report.

The report builder uses Python 3.12, matplotlib and ReportLab 5.1.0. The latter
is locally unpacked under `tools/report-deps`; install `requirements-report.txt`
in a separate reporting environment on a fresh machine. Run
`python tools/build_submission_artifacts.py` after regenerating the summaries.
The submission does not require a cloud slide editor or a paid LLM API.

## Local model, subtle faults and public-suite leaves

The user requested no paid inference calls. The supplementary study uses local
Qwen2.5-Coder-1.5B-Instruct Q4_K_M, with all 40 raw responses retained. Review
`results/local_llm/REPORT.md` for the complete sampling and verification protocol.

```powershell
.\.venv\Scripts\python.exe scripts/demo_local_model.py
.\.venv\Scripts\python.exe scripts/evaluate_local_candidates.py
.\.venv\Scripts\python.exe scripts/run_subtle_fault_study.py
.\.venv\Scripts\python.exe scripts/audit_hls_datasets.py
.\.venv\Scripts\python.exe scripts/run_dataset_leaf_study.py
.\.venv\Scripts\python.exe scripts/write_reliability_reports.py
.\.venv\Scripts\python.exe scripts/validate_reliability_evidence.py
```

The last command checks raw response extraction, source/engine hashes, native
harness hashes, available SMT evidence and local-model HLS source/configuration
bindings. It works in the extracted portable submission. Regenerating the
dataset audit/leaves additionally needs the upstream checkouts and ESBMC.

To run new local inference, use `tools/setup_local_coder.py`, then launch
`tools/serve_local_coder.py` and run `scripts/generate_local_candidates.py` in a second
terminal. The setup checks model/runtime hashes before use. Existing samples
are protected by their request hashes; archive them before changing the study.
Large model/runtime binaries are excluded from the submission package.

For the nine verified changed local-model outputs, prepare testbenches using
`tools/run_local_llm_hls_linux.py --prepare-only` with the project Python, then
run that script under WSL with `--jobs 3`. Its default uses exact-source/config
caches; add `--force` for new hardware runs. See the local-model report for the
current full WSL path. The 50-pair main cohort remains separately reproducible.

## Integrated relational-summary algorithm

The default `python -m hlscheck` command now builds a shared contract, proves
region relations with the custom SMT engine, and checks the residual C product
with ESBMC. Abstract counterexamples are refined using certified functional
summaries or by restoring original code. This is a proof-level combination,
not the historical `--backend auto` engine fallback.

```powershell
.\.venv\Scripts\python.exe scripts/demo_hybrid.py
.\.venv\Scripts\python.exe scripts/run_hybrid_study.py --ablation
.\.venv\Scripts\python.exe -m pytest -q
```

Results are separately retained under `results/hybrid/`; historical experiment
logs and hardware measurements are not relabelled as new-algorithm runs.
`hlscheck.evidence.verify_evidence` verifies artifact/implementation hashes and
replays accepted SMT lemmas. It requires no ESBMC invocation for recorded proof
inspection. Running new C residual checks requires the installed ESBMC binary
and Clang. See `docs/INTEGRATED_ALGORITHM.md` for proof rules and limits.
