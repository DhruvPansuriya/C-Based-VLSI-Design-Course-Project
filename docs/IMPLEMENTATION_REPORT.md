# Implementation report: what the draft proposes vs what is built

Draft: `docs/research/Verdicts_with_Evidence_Final_Draft.md`. Corrections that govern
where the draft overclaims: `docs/CLAUDE_IMPORT_REVIEW.md`. Every row names the code
and the evidence; "not built" means not built.

## Pipeline stages (draft Section 6)

| Draft stage | Implemented as | Evidence / limits |
|---|---|---|
| 1 Admission and build views | `vwe/admission.py`, `vwe/views.py`, `vwe/c_frontend.py` | sim/synth views, forbidden constructs, unmodelled calls, new globals and interface changes; restricted C subset (`docs/T02_ADMISSION.md`) |
| 2 Interpretation set, never reads P1 | handwritten JSON, or `vwe/interpret.py` + `vwe/llm/` (strict, permissive, adversarial, typing, shape prompts) | `RequestContext` has no candidate field; canary tests through `--auto` (`tests/test_llm_isolation.py`, `tests/test_interpret.py`). **Live generation not yet observed** (OpenAI account has no credit, Q24). Computed T3/T5 readings not built |
| 3 Objective validation, P0 only | `vwe/validate.py`, `vwe/regions.py` | V-G..V-4 with UNKNOWN kept; exact UB region only with both inclusions (import-review correction); `docs/T06_REGIONS.md`, `docs/T07_VALIDATION.md` |
| 4 Differential pre-pass | `vwe/replay.py` (native sampling as hints only) | hints are re-proved formally before use |
| 5 Formal checking | `vwe/harness/`, `vwe/proof_jobs.py`, `vwe/tools/cbmc.py` | mandatory `BASE_FLAGS`, exact-size `malloc`, audited path cuts, SAT and Z3 must agree; `docs/T05_VERIFICATION.md` |
| 6 Confirmation | fixed-input re-proof, ASan/UBSan replay, ESBMC (veto only) | ESBMC is unavailable locally and runs in CI; `docs/T09_NATIVE.md` |
| 7 Verdict and report | `vwe/verdict.py`, `vwe/report.py` | ACCEPT / REJECT / UNDECIDED, evidence class, claim target, conditions, witnesses, HTML/JSON |

Draft Section 5.3 theorems are **not proved** by this implementation. The checker is
profile-local: multiple surviving shapes cause abstention, and shape-transfer is
unresolved (import review).

## Worked examples (draft Section 9)

Examples 1–7 are golden fixtures: 20/20 match hand-derived expectations
(`results/checkpoints/2026-11-23-t11/`). They are authored regression tests, not an
accuracy estimate. Example 8 (FIFO) and Section 10 (temporal track, T21) are not built.

## Evaluation (draft Section 11) — deviations

| Draft plan | What exists | Deviation |
|---|---|---|
| ~20 tasks, human-authored requests, independent `phi_ref` (11.1–11.3) | 20 Chrysalis-HLS tasks (`docs/T15_BENCHMARKS.md`) | requests are fixed per-bug-type templates; `phi_ref` = equality with P_ref; sizes scaled to K=4 with an explicit value profile; one agent, no independent authors |
| candidate pool incl. LLM fixes (11.4) | P_ref, unchanged P0, deterministic mutants (`docs/T16_POOLS.md`) | no LLM fixes (no credit) |
| ground truth | formal identity vs P_ref + native differential testing, conservative combination | the formal half reuses this verifier; labels are for the bounded profile |
| baselines B1–B4 (11.5) | B1 tests-only (crash/UB), B3 strict-only pipeline, B4 regression-only E1 | **B2 LLM-as-judge not built**: it sends P1 to an LLM (AGENTS.md rule 1) |
| per-candidate McNemar, evidence-class risk–coverage (11.6) | task-clustered bootstrap, task-level sign test, predeclared policies (`vwe/eval/metrics.py`) | import-review statistical corrections |

Results: `results/eval/summary.md`, `results/eval/errors.md` (written by `make eval`).

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
