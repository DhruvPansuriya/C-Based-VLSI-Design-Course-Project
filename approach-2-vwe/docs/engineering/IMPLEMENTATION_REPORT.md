# Implementation report: what the draft proposes vs what is built

Draft: `docs/research/Verdicts_with_Evidence_Final_Draft.md`. Corrections that govern
where the draft overclaims: `docs/engineering/IMPORT_REVIEW.md`. Every row names the code
and the evidence; "not built" means not built.

## Pipeline stages (draft Section 6)

| Draft stage | Implemented as | Evidence / limits |
|---|---|---|
| 1 Admission and build views | `vwe/admission.py`, `vwe/views.py`, `vwe/c_frontend.py` | sim/synth views, forbidden constructs, unmodelled calls, new globals and interface changes; restricted C subset (`docs/engineering/T02_ADMISSION.md`) |
| 2 Interpretation set, never reads P1 | handwritten JSON, or `vwe/interpret.py` + `vwe/llm/` (strict, permissive, adversarial, typing, shape prompts) | `RequestContext` has no candidate field; canary tests through `--auto`. Live generation verified with two families on Groq (gpt-oss-120b, Qwen 3.8-27B); OpenAI wired but without credit. Computed T5 preservation readings are used for EVAL-P3; computed T3 readings are not built |
| 3 Objective validation, P0 only | `vwe/validate.py`, `vwe/regions.py` | V-G..V-4 with UNKNOWN kept; exact UB region only with both inclusions (import-review correction); `docs/engineering/T06_REGIONS.md`, `docs/engineering/T07_VALIDATION.md` |
| 4 Differential pre-pass | `vwe/replay.py` (native sampling as hints only) | hints are re-proved formally before use |
| 5 Formal checking | `vwe/harness/`, `vwe/proof_jobs.py`, `vwe/tools/cbmc.py` | mandatory `BASE_FLAGS`, exact-size `malloc`, audited path cuts, SAT and Z3 must agree; `docs/engineering/T05_VERIFICATION.md` |
| 6 Confirmation | fixed-input re-proof, ASan/UBSan replay, ESBMC (veto only) | ESBMC is unavailable locally and runs in CI; `docs/engineering/T09_NATIVE.md` |
| 7 Verdict and report | `vwe/verdict.py`, `vwe/report.py` | ACCEPT / REJECT / UNDECIDED, evidence class, claim target, conditions, witnesses, HTML/JSON |

Draft Section 5.3 theorems are **not proved** by this implementation. The checker is
profile-local: multiple surviving shapes cause abstention, and shape-transfer is
unresolved (import review).

## Worked examples (draft Section 9)

Examples 1–7 are golden fixtures: 20/20 match hand-derived expectations
(`evaluation/results/checkpoints/2026-11-23-t11/`). They are authored regression tests, not an
accuracy estimate. Example 8 (FIFO) and Section 10 (temporal track, T21) are not built.

## Evaluation (draft Section 11) — deviations

| Draft plan | What exists | Deviation |
|---|---|---|
| ~20 tasks, human-authored requests, independent `phi_ref` (11.1–11.3) | 20 Chrysalis-HLS tasks (`docs/engineering/T15_BENCHMARKS.md`) | requests are fixed per-bug-type templates; `phi_ref` = equality with P_ref; sizes scaled to K=4 with an explicit value profile; one agent, no independent authors |
| candidate pool incl. LLM fixes (11.4) | P_ref, unchanged P0, deterministic mutants (`docs/engineering/T16_POOLS.md`) | LLM candidate generation is implemented (`vwe/eval/candidate_gen.py`) but was not run, to conserve the free-tier token budget |
| ground truth | formal identity vs P_ref + native differential testing, conservative combination | the formal half reuses this verifier; labels are for the bounded profile |
| baselines B1–B4 (11.5) | B1 tests-only (crash/UB), B3 strict-only pipeline, B4 regression-only E1 | **B2 LLM-as-judge not built**: it sends P1 to an LLM (CONTRIBUTING.md rule 1) |
| per-candidate McNemar, evidence-class risk–coverage (11.6) | task-clustered bootstrap, task-level sign test, predeclared policies (`vwe/eval/metrics.py`) | import-review statistical corrections |

Results: `evaluation/results/eval/summary.md`, `evaluation/results/eval/errors.md` (written by `make eval`), and
`docs/engineering/T18_EVAL.md`. Summary: on 89 labelled Chrysalis candidates the method decides 1 (correct)
and abstains on the rest; tests-only and regression-only baselines make 41 and 10 wrong
decisions. A separate evaluation on the Project 3 team's 181 equivalence candidates
(`docs/engineering/EVAL_P3.md`) gives 125 decisions, all agreeing with their labels.

## HLS integration (draft Section 12)

Pragmas are extracted and recorded at admission. Synthesis-view consistency is checked.
The pragma obligation gate (T19) and Vitis QoR (T20) are **not built**. No area,
latency or timing number has been measured; C verification results are not QoR.

## Reproduce

```sh
make test && make golden && make demo && make demo-steps
python scripts/fetch_benchmarks.py && python scripts/adapt_chrysalis.py --limit 30
python scripts/check_benchmark_refs.py
python scripts/gen_mutants.py --all --limit 4 && python scripts/label_candidates.py --all
python scripts/interpret_benchmarks.py --family openai     # needs API credit
make eval
```
