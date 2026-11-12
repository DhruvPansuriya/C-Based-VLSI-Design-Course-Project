# Evidence checkpoint: 2026-11-23-t22

This is preserved evidence, not a new verification run. Read this before rerunning tools.

- Tests: **434 passed, 1 skipped in 566.32s (0:09:26)**.
- Golden cases: **20/20 matched**.
- Demo: **9/9 rows matched in 65.2s**, K=2.
- Inspect individual tool records for confirmation availability; do not infer an optional tool ran merely because the final verdict is present.
- Detailed provenance, configuration, hashes and original execution-parent commits are retained.

| Task | Candidate | Expected | Observed | Reason |
|---|---|---|---|---|
| ex1_saturate | v1 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex1_saturate | v2 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex1_saturate | v3 | REJECT E1 | REJECT E1 | regression outside B_max rejected by every Ext |
| ex1_saturate | v4 | REJECT E2 | REJECT E2 | violates every interpretation |
| ex1_saturate | v5 | REJECT E2 | REJECT E2 | violates every interpretation |
| ex2_argmax | v1 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex2_argmax | v2 | REJECT E1 | REJECT E1 | regression outside B_max rejected by every Ext |
| ex2_argmax | v3 | REJECT E0 | REJECT E0 | computed fact: e0: p1_argmax.pointer_dereference.41 dereference failure: pointer outside object bounds in a[(signed long int)i] |
| ex4_sum | v1 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex4_sum | v2 | REJECT E0 | REJECT E0 | computed fact: e0: p1_sum.pointer_dereference.5 dereference failure: pointer outside object bounds in a[(signed long int)i] |
| ex3_avg_half_away | v1 | UNDECIDED - | UNDECIDED - | scope disagreement or incomplete Ext comparison |
| ex3_avg_half_away | v2 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex3_avg_half_away | v3 | REJECT E2 | REJECT E2 | violates every interpretation |
| ex5_add32_ambiguous | v1 | UNDECIDED - | UNDECIDED - | ambiguous: interpretations disagree |
| ex5_add32_ambiguous | v2 | UNDECIDED - | UNDECIDED - | ambiguous: interpretations disagree |
| ex5_add32_ambiguous | v3 | REJECT E2 | REJECT E2 | violates every interpretation |
| ex6_copy_overflow | v1 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |
| ex6_copy_overflow | v2 | REJECT E1 | REJECT E1 | regression outside B_max rejected by every Ext |
| ex7_build_views | v1 | REJECT E0 | REJECT E0 | views: main.assertion.1 VWE.views.equivalence |
| ex7_build_views | v2 | ACCEPT E2 | ACCEPT E2 | satisfies every interpretation |

## Files

- `golden.json`, `demo.json`: portable aggregate results.
- `golden/`, `demo/`: standalone reports, manifests and validation/region evidence.
- `logs/`: exact captured test, golden and demo console logs.
- `raw-evidence.tar.gz`: generated sources and raw solver/native text evidence. Extract in a separate directory to inspect; no verification tools are needed.
- `source-inventory.json`: implementation file SHA-256 inventory at archival time.
- `checksums.json`: hashes of the archived payload.

The old `results/golden/` is a separate imported ten-case prototype snapshot. It is not this twenty-case public-pipeline run.

Run manifests retain execution-time HEADs. The checkpoint HEAD identifies packaging state, not a fresh execution. Preserve original SHAs; document tested uncommitted changes and later implementation commits separately rather than relabeling earlier observations.

Passing fixtures establishes these regressions and the runnable demo. It does not establish general natural-language correctness, benchmark accuracy, universal shape transfer, synthesis readiness or area/latency improvement.
