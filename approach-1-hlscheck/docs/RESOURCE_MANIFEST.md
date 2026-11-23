# Project 3 resource manifest

Downloaded on 2026-10-07 for **Formal Equivalence Checking of LLM-Optimized HLS Code**.

## Python environment

- Virtual environment: `.venv`
- Python: 3.12.10
- Z3 Python bindings: 5.1.0.0
- pycparser: 3.0
- pytest: 9.1.1
- Pinned dependencies: `requirements.txt`
- Offline Z3 wheel: `tools/z3_solver-5.1.0.0-py3-none-win_amd64.whl`

Activate on PowerShell with:

```powershell
.\.venv\Scripts\Activate.ps1
```

## Benchmarks and frameworks

| Local path | Source | Snapshot | Scope |
|---|---|---|---|
| `datasets/MachSuite` | https://github.com/breagen/MachSuite | `6236e593012cb86b0d2f08d9fb9ba0411ff989b4` | Complete shallow clone |
| `datasets/CHStone` | https://github.com/ferrandi/CHStone | `2b7e20ffd3365016faf1e4e2b86496a5c95445fb` | Complete shallow clone |
| `datasets/hls-eval` | https://github.com/stefanpie/hls-eval | `e373bc0a005f0a6030f77f27b3f0d71b16a35a0b` | Sparse checkout: framework, tests, design scripts, leaderboard, and lightweight 94-design data; accelerator and experiment artifacts excluded |
| `third_party/HLSFactory` | https://github.com/sharc-lab/HLSFactory | `2aba8756de8e2fab1d1095b2483cfa695bf3be10` | Sparse checkout: framework plus MachSuite, CHStone-new, PolyBench, Rosetta, and C2HLSC datasets |
| `third_party/alive2` | https://github.com/AliveToolkit/alive2 | `5d0eb277235b73f71000501c3a4f5ab9b2586915` | Complete shallow clone for comparison/reference |

Each repository retains its upstream license files. Check those licenses before redistributing benchmark or framework contents.

## Papers

1. `datasets/papers/01_black_box_equivalence_aplas2017.pdf` — Dahiya and Bansal, *Black-box equivalence checking across compiler optimizations*.
2. `datasets/papers/02_formal_source_transformations_hls_fpga2024.pdf` — Pouchet et al., *Formal Verification of Source-to-Source Transformations for HLS*.
3. `datasets/papers/03_alive2_pldi2021.pdf` — Lopes et al., *Alive2: Bounded Translation Validation for LLVM*.
4. `datasets/papers/04_hlspilot_2024.pdf` — *HLSPilot: LLM-based High-Level Synthesis*.
5. `datasets/papers/05_hls_eval_2025.pdf` — *HLS-Eval: A Benchmark and Framework for Evaluating LLMs on High-Level Synthesis Design Tasks*.
6. `datasets/papers/06_c2hlsc_2024.pdf` — *C2HLSC: Can LLMs Bridge the Software-to-Hardware Design Gap?*

## Disk usage after setup

Approximate measured usage, including Git metadata:

| Resource | MiB |
|---|---:|
| `.venv` | 63.61 |
| MachSuite | 2.87 |
| CHStone | 0.87 |
| HLS-Eval lightweight checkout | 7.32 |
| HLSFactory focused checkout | 37.88 |
| Alive2 | 4.30 |
| Papers | 5.32 |
| Offline Z3 wheel | 16.25 |
| **Total workspace contents** | **138.41** |

## Not downloaded

- Full HLSFactory working tree: approximately 1.245 GiB; unnecessary datasets were excluded.
- HLS-Eval accelerator and experiment artifacts: excluded from the 373.88 MiB full working tree.
- Vitis/Vivado: not installed or visible on `PATH`; this is a separate multi-gigabyte commercial tool installation.
- Google XLS: not installed. Bambu was deferred in the original setup and has now been installed as described below.

## Checker implementations added on 2026-11-21

The preceding size table describes the original October setup, not current
workspace usage after these additions.

| Resource | Download | Extracted | Location |
|---|---:|---:|---|
| ESBMC Windows v8.7 | 44.11 MiB | 151.89 MiB | `tools/esbmc-v8.7/release/` |
| PAST 0.7.2 Linux CPython 3.12 wheel, release `65f989b` | 3.41 MiB | 11.90 MiB | `tools/past-linux/` |
| PEQcheck paper | 0.46 MiB | PDF | `datasets/papers/07_peqcheck_2021.pdf` |
| ESBMC v7.6 journal paper | 0.59 MiB | PDF | `datasets/papers/08_esbmc_v76_2025.pdf` |

- ESBMC: https://github.com/esbmc/esbmc/releases/tag/v8.7
- Verified ESBMC archive SHA-256 against GitHub release metadata:
  `b813a916d955c0790a3bb7c8766c510e6b639392c40f92b284662ca2fadf1bca`.
- PAST wheel: https://github.com/cornell-zhang/past-python-bindings/releases/tag/65f989b
- Locally recorded PAST wheel SHA-256 (no upstream digest was provided):
  `b79fd4c75c902c6be6f583f2abab44ebf3f32f0be9267a5986e2b21b2491f938`.
- PAST is loaded from the project directory using Ubuntu 24.04/WSL and Python
  3.12; no system Python package installation was required.
- Preserve the ESBMC bundled license directory and PAST `.dist-info` license
  files when redistributing. The PAST wheel includes LGPLv3 notices; ESBMC
  bundles its own and third-party component notices, including Z3's.
- The PyPI package named `past` is unrelated to this HLS checker and was not
  installed.

New project code: `hlscheck/esbmc_backend.py`, `tools/past_worker.py`,
`scripts/prepare_past_demo.py`, and the benchmark/comparison runners. Raw measured
evidence is under `results/esbmc`, `results/past`, and `results/benchmarks`.

## Public equivalence dataset added on 2026-11-21

- EqBench: https://github.com/shrBadihi/EqBench
- Location: `datasets/EqBench`; shallow clone, MIT license preserved.
- Snapshot: `3724fce5b287cc63165028444daf904f25b0158b`.
- Current source tree: 2.13 MiB before download; this excludes Git metadata.
- Audit found 247 old-version C records and 246 complete old/new C file pairs.
  The upstream README's advertised case totals differ from this pinned C tree.
- Public-data audit/evaluation runner: `scripts/run_eqbench.py`.
- All exclusions, source hashes, metadata, generated harnesses and verdicts:
  `results/eqbench/`.
- Dataset choices and limitations: `docs/PUBLIC_DATASETS.md`.

## Hardware tools and submission artifacts added on 2026-11-21/22

Download sizes were reported while preparing the HLS installation.

| Resource | Download size | Installed location |
|---|---:|---|
| Bambu 2026.11 AppImage | 508.89 MiB (533,607,616 bytes) | WSL `~/cs5291_hls_tools/squashfs-root` |
| Official OpenROAD/Yosys backend bundle | 74.14 MiB (77,746,307 bytes) | WSL `~/cs5291_hls_tools/opt` |
| Nangate45 typical Liberty | 6.38 MiB (6,692,032 bytes) | `tools/nangate45` |
| ReportLab 5.1.0 wheel | 1.93 MiB (2,018,647 bytes) | `tools/report-deps` |
| Linux simulation / Tcl dependencies | 13.0 MB package download; 52.4 MB installed | Ubuntu packages |

Official binary URLs:

- https://release.bambuhls.eu/bambu-2026.11.AppImage
- https://release.bambuhls.eu/openroad-yosys-opt.tar

Locally recorded SHA-256 values (not upstream-signed checksums):

- Bambu: `6e8cd7049c09ef48ec7ea2ece88e91f2c70bf67547c77a71b6ff44c4e008fa06`
- Backend bundle: `fb49a19ea1c062cae18eba291672fbbd723e36f57799c083de3b187a55c5c09f`
- Liberty: `8d540a4d4cf6d09d27c87ad067857a9c0c2eeb023ab7a56e058cd3113db4e9b1`

The Liberty download's Git blob hash was also checked against GitHub API
metadata: `90e4afb274cfc6514c587c434c77903d554117d1`. Its header and upstream
Nangate45 license are preserved. Installed Bambu files occupy about 1.55 GiB;
the backend bundle occupies about 249 MiB in WSL, separate from workspace
archives. Linux per-design working directories are under `~/cs5291_hls_runs`.

Actual Bambu version: PandA 2026.11, revision
`6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda`. The downloaded AppImage's
embedded revision is authoritative for these experiments, rather than an
assumed source tag revision. Other executed versions: Clang 16 frontend,
Verilator 5.020, Yosys 0.36 (`8f07a0d84`), OpenSTA 2.0.18 (`41f678fb6a`).

Main results: `results/submission/`; raw synthesis evidence: `results/hls/`.
The report and presentation are under `output/`. Large downloaded binaries,
upstream repository clones and research PDFs remain in the workspace but are
excluded from the portable source ZIP. See `docs/THIRD_PARTY_NOTICES.md`.

## Expanded study on 22 November 2026

No additional dataset or HLS tool download was needed. Forty new recorded
educational source pairs extend the study to 48 pairs / 96 hardware
implementations. There are 47 distinct original C ASTs because gemm_local4 is
an explicitly identified second candidate for the existing GEMM reference.
Source definitions: `tools/expand_benchmarks.py`; exact files:
`benchmarks/expanded/`; before/after records and results:
`experiments/OPTIMIZATION_CATALOG.md` and `experiments/optimizations/`.

The main experiment includes 48 positive equivalence results, 48 rejected
seeded controls, 12,672 paired native trials, 48 compiled witness replays and
1,536 RTL simulation calls. The proof chain includes eight accepted component
lemmas for the Hamming case, all exported and replayed. The initial 30-second
monolithic timeout is retained under `experiments/attempts/`.

All 96 hardware runs use the same previously installed tools and configuration.
The initial expanded hardware batch log is `results/hls/EXPANDED_BATCH_LOG.txt`.
Per-design source/testbench/configuration hashes and raw logs remain under
`results/hls`. Updated report: 14 pages; presentation: 19 slides.

Final feedback round: two additional shared-baseline candidates bring the
current submission to **50 pairs / 100 synthesized implementations**, still
47 distinct original ASTs. The code is under `benchmarks/feedback/`; the raw
batch log is `results/hls/FEEDBACK_BATCH_LOG.txt`. Current totals are 50 proofs,
50 rejected controls, 13,200 native paired trials, 50 compiled witness replays
and 1,600 RTL calls. The final report has 15 pages and the deck 19 slides.

## Local-model extension on 22 November 2026

The user declined paid inference APIs. Local inference used these hash-verified
downloads; their sizes were stated before downloading:

| Resource | Download bytes | Location |
|---|---:|---|
| Qwen2.5-Coder-1.5B-Instruct Q4_K_M GGUF | 1,117,320,768 (1.04 GiB) | `tools/local_llm/` |
| llama.cpp b12619 Windows Vulkan archive | 38,863,716 (37.06 MiB) | `tools/local_llm/` |

Model revision: `f86cb2c1fa58255f8052cc32aeede1b7482d4361`.
Model SHA-256: `cc324af070c2ecbfd324a30884d2f951a7ff756aba85cb811a6ec436933bb046`.
Runtime SHA-256: `175d9013769997ab9145cc932f0dd2d89ab3cb6123aecbd83a9645e1cf5e5b9d`.
`tools/setup_local_coder.py` records official URLs and verifies both hashes.
No paid or free external inference API was called; generation ran locally.

The separate study retains all 40 genuine attempts, nine additional measured
implementations, an 80-case subtle-edit/control suite and eight type-preserving
public-suite leaf functions. The existing downloaded datasets were reused;
there was no additional dataset download. Reports and raw evidence are in
`results/local_llm/`, `results/subtle_faults/`, `results/dataset_audit/` and
`results/dataset_leaves/`. The model and runtime binaries are excluded from the
portable ZIP, while provenance and model license are included. Earlier page and
slide counts above describe earlier rounds; the current report/deck include the
supplementary studies.
