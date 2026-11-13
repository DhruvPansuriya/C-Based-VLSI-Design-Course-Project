# evaluation/ - benchmarks, results and experiments

Everything we measured is here. Nothing in this folder needs to be re-run to read the results.

| Folder | What it holds |
|---|---|
| `results/` | saved results quoted in the report: evaluation tables, raw rows, logs and checkpoints |
| `benchmarks/` | benchmark tasks and the LLM readings generated for them |
| `sample_runs/` | one complete run folder from the live demo, so you can see every output file |
| `tool_spikes/` | small experiments that check how CBMC and ESBMC behave on tricky cases |

## Main numbers and where they come from

| Experiment | Result | File |
|---|---|---|
| Golden examples (our 20 candidates) | 20/20 match | `results/checkpoints/2026-11-23-t22/` |
| Demo cases | 9/9 match | `results/checkpoints/2026-11-23-t22/` |
| HLSCheck (Approach-1) cases | 125 of 181 decided, all 125 agree with the label | `results/eval_project3/summary.md` |
| Chrysalis-HLS bugs | 0 wrong decisions (tests-only baseline: 41 wrong) | `results/eval/summary.md` |
| Live LLM readings vs ours | see table | `results/auto_vs_handwritten_live.md` |

## How to run each one again

From the `approach-2-vwe` folder, with `.venv` active:

```sh
make golden                                    # golden examples
make demo                                      # the nine demo cases
python scripts/adapt_project3.py --handoff ../approach-1-hlscheck
python scripts/eval_project3.py                # HLSCheck cases (several hours)
python scripts/fetch_benchmarks.py && python scripts/adapt_chrysalis.py
make eval                                      # Chrysalis-HLS evaluation (several hours)
make spikes                                    # tool behaviour checks
```

New runs write to `runs/` (git-ignored). The files here are the ones from our runs.
