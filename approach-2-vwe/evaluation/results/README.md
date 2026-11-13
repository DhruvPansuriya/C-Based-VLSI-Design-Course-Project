# Committed evidence index

**Latest checkpoint:** [2026-11-23 / T22](checkpoints/2026-11-23-t22/README.md), a fresh
validation run on commit `08399e1`: full suite 434 passed / 1 skipped (ESBMC unavailable
locally), golden 20/20, demo 9/9 in 65.2 s. Evaluations: [Chrysalis T18](eval/summary.md),
[Project 3](eval_project3/summary.md), [live auto vs handwritten](auto_vs_handwritten_live.md).
The T11 checkpoint is unchanged and remains the record of that milestone.

| Snapshot | Meaning |
|---|---|
| `checkpoints/2026-11-23-t22/` | Release validation of T12–T18 + EVAL-P3 code: test, golden and demo logs, reports, raw text evidence; evaluation run logs |
| `eval/`, `eval_project3/` | Chrysalis T18 and Project 3 evaluation rows, summaries and audits |
| `checkpoints/2026-11-23-t11/` | Preserved local public pipeline: 20 golden candidates, 9 demo rows, 325 passed / 1 skipped core-suite log, standalone reports and compressed raw evidence |
| `golden/` | Imported original Linux handwritten ten-case prototype; not the latest twenty-case suite |
| `tool_behaviour/` | Imported tool-behavior qualification log |
| `t02/`, `t03/` | Earlier explicitly scoped frontend/contract evidence |
| `import-review/` | Original archive inventory and import qualification |

The latest checkpoint was assembled from existing files without rerunning
verification. The golden observations are authored regression expectations,
not benchmark accuracy measurements. The demo is bounded K=2; the standard
golden size bound is K=4 with per-task constraints. Local ESBMC was unavailable.

Use the checkpoint README/JSON for understanding results, HTML for presentation,
and `raw-evidence.tar.gz` to inspect original generated sources and solver/native
text evidence without executing anything. Binary GOTO artifacts and native
executables are excluded. Check `checksums.json` to verify payload integrity.

For later milestones, run `scripts/archive_results.py` after their acceptance
commands finish, choose a new label, update this index and `latest.json`, and keep
older snapshots immutable. Never replace an old log with a fresh run under the
same label. Treat live CI status separately from the status captured in a
checkpoint. `runs/` remains scratch output, not durable shared evidence.

## Completed hosted CI

[Final GitHub run/job metadata](ci/2026-11-23-t10-t11.json) records successful
Python 3.10 and 3.12 jobs for both `d7ebb71` (T10) and `8ed772e` (T11). The
immutable checkpoint's earlier CI snapshot remains unchanged: it records the
status observed during packaging, when those jobs were still running.
