# T17 — baselines

Code: `vwe/eval/baselines.py`; runner: `scripts/run_baselines.py` and `scripts/run_eval.py`.
Baselines are comparison points kept out of the production method and its CLI.

| Id | Baseline | Implemented rule | Deviation from the card |
|---|---|---|---|
| B1 | tests only | ACCEPT iff the candidate runs sanitizer-clean (no abort, no hang) on 1,000 profile-bounded random/boundary inputs; otherwise REJECT | tasks have no test oracle and P_ref is evaluation-only, so B1 tests crashes/UB, not functional outputs |
| B2 | LLM-as-judge | **not implemented** | sends P1 to an LLM; AGENTS.md rule 1 forbids it without an explicit, separately scoped user exception |
| B3 | single strict contract | the full pipeline restricted to the generated strict reading(s) | a "no Ext" variant is vetoed by the method's own scope-agreement check (observed on Example 1) |
| B4 | regression only | P1 == P0 outside the strict reading's region, anything allowed inside; run as the pipeline's E1 obligation after admission and P0-only guard certification | a no-change "reading" is (correctly) discarded by V-2, so B4 is not expressible as a reading; witnesses are not natively replayed |

B3/B4 use the same generated readings as the method (live Groq, P0 + N only) and the
same benchmark profile and timeouts. Example: on Example 1, `v3` (always returns 255) is
rejected by B3 and B4, and on the Chrysalis `abs_use` pool B4 accepts a deleted-guard
mutant that changes behaviour inside the strict reading's region (`tests/test_baselines.py`,
`results/eval/errors.md`).
