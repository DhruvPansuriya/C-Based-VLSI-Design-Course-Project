# Supporting scripts

Run commands from the project root using the project Python environment.

```powershell
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
.\.venv\Scripts\python.exe run_demo.py
.\.venv\Scripts\python.exe run_submission.py --tests
```

With two supplied files, the first command runs the full seven-stage pipeline
and prints proof, native, RTL, mapping, timing and comparison outputs. Add
`--verify-only` to stop before hardware. Without files, `run_demo.py` presents
three predefined integrated-checker examples. `run_submission.py` reproduces
the core submission checks. The C-to-C checker itself remains in `hlscheck/` and
can also be invoked with `python -m hlscheck`.

| Purpose | Scripts in this directory |
| --- | --- |
| Generic file-to-file pipeline | `design_pipeline.py` (root `run_demo.py` entry point), `design_testbench.py`: typed native and RTL reference harnesses; see `docs/FILE_PIPELINE.md` |
| Integrated and scaling studies | `run_hybrid_study.py`, `run_large_study.py`, `run_loop_budget_study.py` |
| Public datasets and comparison tools | `audit_hls_datasets.py`, `run_dataset_leaf_study.py`, `run_eqbench.py`, `run_benchmark_checks.py`, `prepare_past_demo.py` |
| Model generation and fault studies | `generate_local_candidates.py`, `evaluate_local_candidates.py`, `run_subtle_fault_study.py` |
| Verification and evidence replay | `verify_submission.py`, `replay_smt_evidence.py`, `validate_native.py`, `validate_reliability_evidence.py`, `validate_hybrid_evidence.py`, `validate_large_evidence.py` |
| Reports and catalogs | `analyze_results.py`, all `write_*.py` files |
| Demos | `demo_hybrid.py`, `demo_local_model.py`, `demo.py`, `run_demo.py`, `run_esbmc_demo.py`, `run_rare_bug_demo.py` |
| Worked proof-to-HLS example | `run_matmul_demo.py`: 4 x 4 matrix multiplication, i-j-k versus k-i-j |
| Quick model-family pilot | `run_model_pilot.py`: SmolLM2, Qwen and IBM Granite on the same short prompt; saved GPT-6.1-Sol reference |
| Two-model dataset study | `run_two_model_study.py`: 12 fixed dataset-derived sources, generation/equivalence/HLS/report; `validate_two_model_study.py`: evidence, typed native-harness controls, CSV and figures |

For example:

```powershell
.\.venv\Scripts\python.exe scripts/run_hybrid_study.py --ablation
.\.venv\Scripts\python.exe scripts/validate_reliability_evidence.py
.\.venv\Scripts\python.exe -m scripts.run_large_study --help
```

Older recorded reports may show commands such as `python run_large_study.py`.
Their current equivalent is `python scripts/run_large_study.py`; all 30 former
root-level supporting scripts retain their filenames here. The original
`scripts/run_demo.py` is the first milestone demo; root `run_demo.py` launches
the current file-to-file pipeline or, without files, the integrated examples.

The original evaluator and native helper used for saved experiment fingerprints
are retained byte-for-byte under
`experiments/script_versions/root_layout_2026-11-22/`. Evidence validation checks
those hashes when inspecting historical results; moving files does not relabel
old experiments as new runs.
