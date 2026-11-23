# T18 — evaluation on the adapted Chrysalis-HLS tasks

Results: [`evaluation/results/eval/summary.md`](../../evaluation/results/eval/summary.md), audit
[`evaluation/results/eval/errors.md`](../../evaluation/results/eval/errors.md), raw rows `evaluation/results/eval/raw.jsonl`.
Command: `VWE_REGION_CACHE=runs/region-cache python scripts/run_eval.py --jobs 2`.

## Setup

* 20 tasks / 97 candidates (89 labelled: 23 correct, 66 incorrect; 8 unknown labels excluded
  and counted). Tasks, pools and labels: `docs/engineering/T15_BENCHMARKS.md`, `docs/engineering/T16_POOLS.md`.
* Method readings: generated live on 2026-11-23 from P0's signature and the template request
  by **gpt-oss-120b and Qwen 3.8-27B via Groq** (prompts v2, seed 0). Five tasks lack some
  gpt-oss readings because the free tier's 200k tokens/day cap was reached; the failed calls
  are recorded in `evaluation/benchmarks/generated/<task>/generated_set.json`.
* Profile `config/benchmark.toml` (K=4, 120 s solver timeouts); laptop, CBMC 6.11, Z3 5.4.1;
  ESBMC unavailable locally (confirmation-only, so it can only remove ACCEPTs).

## Results (89 labelled candidates)

| System | Decided | Coverage | Wrong | Notes |
|---|---|---|---|---|
| VWE | 1 | 0.01 | **0** | the one decision: REJECT E0, a mutant introducing an out-of-bounds dereference |
| B1 tests only | 89 | 1.00 | 41 | ACCEPT precision 0.36: crash-free is not correct |
| B3 strict reading only | 1 | 0.01 | 0 | same abstention pattern as VWE |
| B4 regression only | 43 | 0.48 | 10 | misses changes inside the region; rejects P_ref twice |

No wrong E0/E1 decision (the run would have failed). Task-level paired comparison:
VWE has fewer wrong decisions than B1 on 12 tasks and more on none (sign test p < 0.001),
and fewer than B4 on 5 tasks, more on none (p = 0.06). It makes fewer right decisions than
either, because it abstains.

## Why the method abstains here (96 of 97 candidates)

| Reason | Candidates | Cause |
|---|---|---|
| no certified safe P0 reference guard | 54 | SAT timeouts on 64-bit products, loops beyond max_unwind, unqualified CBMC initialisation instrumentation, or P0 undefined on the profile (`docs/engineering/T15_BENCHMARKS.md`) |
| no reading survives validation | 36 | mostly V-2: under the K=4 / [-1000,1000] profile the injected bug is not observable, so every "P0 must change" reading is (correctly) discarded |
| scope unresolved | 6 | a generated reading with unknown Ext (Q26) |

So on this benchmark the result is **no errors and almost no coverage**. It says as much about
the adaptation (scaled sizes, template requests, many bugs invisible in the profile) as about
the method. It is not an accuracy estimate for real repair requests. The Project 3 evaluation
(`docs/engineering/EVAL_P3.md`), whose requests are precise, exercises the decision path far more.
