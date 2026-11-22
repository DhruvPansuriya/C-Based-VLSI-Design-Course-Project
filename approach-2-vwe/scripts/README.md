# scripts/ - commands for the demo and the evaluation

Run all of them from the VWE folder (the top of the `approach-2-vwe` branch, or `approach-2-vwe/` on `main`) with the virtual environment active.

**Demo**

| Script | What it does |
|---|---|
| `demo_steps.py` | runs one candidate and prints every stage (`--task`, `--candidate`, `--interactive`) |
| `demo.py` | runs the nine demo cases (`make demo`) and writes `runs/demo/index.html` |
| `demo_portal.py` | builds the demo web page `runs/index.html` from your latest runs (`make portal`) |
| `run_golden_examples.py` | runs the 20 golden example candidates (`make golden`) |
| `run_admission_examples.py`, `check_contracts.py` | small checks of stage 1 and of the reading language |

**Benchmarks and evaluation**

| Script | What it does |
|---|---|
| `fetch_benchmarks.py` | downloads Chrysalis-HLS, CHStone and MachSuite at fixed commits into `third_party/` |
| `adapt_chrysalis.py` | turns Chrysalis-HLS bugs into VWE tasks in `evaluation/benchmarks/tasks/` |
| `gen_mutants.py`, `gen_candidates.py` | build each task's candidate pool (mutants, and LLM fixes from P0 and N only) |
| `label_candidates.py`, `check_benchmark_refs.py` | label every candidate and check the reference fixes |
| `interpret_benchmarks.py` | ask the LLMs for readings of each benchmark request |
| `run_eval.py`, `run_baselines.py` | run VWE and the baselines on all labelled candidates (`make eval`) |
| `adapt_project3.py`, `eval_project3.py` | turn the HLSCheck (Approach-1) cases into tasks and run VWE on them |
| `compare_auto_handwritten.py`, `pool_stats.py`, `benchmark_stats.py` | small summaries for the report |
| `archive_results.py` | copy finished results into a dated folder in `evaluation/results/checkpoints/` |
| `run_handwritten_examples.py` | the early hand-written harnesses kept from the prototype |
