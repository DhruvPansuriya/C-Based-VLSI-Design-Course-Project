# T08 — Orchestrator, CLI `vwe verify`, JSON and HTML reports

**Priority:** must · **Depends on:** T07 · **Effort:** about 2 days

## Goal

Run the whole pipeline from one command and produce the report the professor will look at.

## Steps

1. **`vwe/pipeline.py`: `verify(task_dir, candidate_id, cfg, interpretations="handwritten"|"auto") -> VerdictReport`.** Stages, in order (TDD §8.1):
   1. admission;
   2. views;
   3. regions;
   4. validation and freezing;
   5. pre-pass (stub until T09);
   6. `views_equiv` → core (E0, E1) → per-class;
   7. confirmation (replay stub until T09; ESBMC for ACCEPT);
   8. `vwe.verdict.decide`.

   Stop early on a confirmed E0 or E1.
2. **Evidence wiring:** map the bundle outcomes into `vwe.verdict.Evidence`. Admission rejections are reported as decision REJECT, class E0, reason "forbidden construct". Admission UNDECIDED short-circuits.
3. **`vwe/report.py`:**
   - JSON validated against `schemas/verdict_report.schema.json`. It contains: the printed conditional (draft §5.3; e.g. E2 ACCEPT: "correct if at least one listed interpretation is sound and true buffer sizes lie between the listed shapes"), the partitioned facts (draft §5.4), and the witness with `P0` and `P1` outputs (obtained by running both natively, or via CBMC trace values on the witness).
   - **HTML** (single self-contained file, no external assets):
     - a verdict banner;
     - an evidence-class explanation;
     - the witness table;
     - the interpretations rendered in English (`nl_rendering`) with their satisfied/violated status;
     - the partitioned facts;
     - obligations per backend;
     - tool versions;
     - the generated harness sources (collapsible).
4. **`vwe/cli.py`** (argparse):
   - `vwe verify <task_dir> --candidate <cid> [--json out.json] [--html out.html] [--auto]`
   - `vwe verify-all <task_dir>` (every candidate, prints a table)
   - `vwe interpret <task_dir>` (Phase 3)
   - `vwe --version`
5. **Run manifest:** `runs/<task>/<cid>/<run_id>/run_manifest.json` containing tool versions, git commit, config, interpretation-set hash and timings.

## Acceptance criteria

```bash
vwe verify examples/tasks/ex2_argmax --candidate v2 --html /tmp/r.html
# prints: REJECT  E1  regression outside B_max rejected by every Ext   witness: n=...
vwe verify-all examples/tasks/ex1_saturate
# 5 rows matching tests/golden/expected.json
python -c "import json;from vwe.schemas import validate;validate('verdict_report',json.load(open('runs/latest.json')))"
```

## Pitfalls

- The report must show **why** a verdict holds (the conditional), not only the verdict.
- Do not print LLM prompts in reports in Phase 3 unless the `--debug` flag is set (they can be long).
