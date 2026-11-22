# C-Based VLSI Design Course Project


## Current implementation

Work proceeds on `implementation-start`. See [progress](plan/PROGRESS.md) and the [independent ZIP review](docs/CLAUDE_IMPORT_REVIEW.md), which records required soundness corrections before later tasks. The bounded `vwe verify` pipeline is implemented for handwritten interpretations, with generated proof jobs, SAT/Z3 agreement, JSON/HTML reports and native sanitizer replay. Automatic interpretation generation remains planned.

```bash
python3 -m venv .venv
.venv/bin/python -m pip install -e .
make test
.venv/bin/vwe --version
make golden
```

T01 adds three schema-validated task folders in `examples/tasks/` and `vwe.tasks.load_pipeline_view`. The immutable pipeline view excludes `eval_only`, acceptable-reading labels and all evaluation file contents; path traversal and symlinks into `eval/` are rejected. `load_full` is reserved for evaluation. The deliberately invalid n-1 reading is retained by the loader and discarded only after semantic validation establishes its invalidity.

T02 adds structural admission and isolated simulation/synthesis analysis views. Run `make admission` for the three example tasks; artifacts record hashes, globals, pragmas, missing-body checks and remaining obligations. Structural `ok` is not a correctness verdict. See [T02 details](docs/T02_ADMISSION.md).

T03 adds the restricted contract grammar, type checker and C observer emitter. Run `make contracts` to emit the stored examples without claiming validation; see [contract details](docs/T03_CONTRACTS.md).

T10 is in progress: `make golden` runs the public pipeline on 13 candidates from Examples 1–4, including the collapsed-scope rounding example. Its expected verdicts are documented before execution in the task README. Examples 5–7 remain to be added. The independent handwritten harness runner is retained as `scripts/run_handwritten_examples.py`.

Native CBMC 6.11.0 and Z3 are needed for the golden integration test; it is skipped when CBMC is absent. Linux tool installation is `bash tools/install_tools.sh`; macOS must use qualified native tools. The Docker recipe has not been run here and is not a sealed image.

## Implementation plan (for the coding agent)

Start at [`plan/00_START_HERE.md`](plan/00_START_HERE.md). The rules every change must respect are in [`AGENTS.md`](AGENTS.md). The phased plan and milestones are in [`plan/01_PLAN.md`](plan/01_PLAN.md), with one file per task in [`plan/tasks/`](plan/tasks/) (T00–T22). Unresolved facts are tracked in [`plan/OPEN_QUESTIONS.md`](plan/OPEN_QUESTIONS.md). Tasks T00–T11 are the minimum for a working end-to-end demo.

Formal verification of LLM-repaired and optimised HLS code.

**Verdicts with Evidence (VWE)** is being developed as a fully automatic tool. The existing prototype and completed milestones are listed above. The intended interface takes

- a buggy C function `P0`,
- a natural-language fix request `N`, and
- an AI-revised version `P1`,

it returns **ACCEPT / REJECT / UNDECIDED** with an evidence class (E0 computed, E1 behaviour-light, E2 interpretive), a concrete witness input and a report. It uses CBMC with an unmodified Z3 solver, ESBMC as a confirmation-only second verifier, and sanitizer replay.

## Documents

| Document | What it contains |
|---|---|
| `docs/research/Verdicts_with_Evidence_Final_Draft.pdf` | The research draft: theory, theorems, pipeline, worked examples, evaluation design |
| `docs/technical-design/01_review_of_final_draft.md` | Implementer's review of the draft, with tool behaviour checked by running CBMC 6.11.0 / ESBMC 8.7.0 |
| `docs/technical-design/02_technical_design_document.md` | Technical design: architecture, versions, modules, schemas, harness generation, orchestration, testing, benchmarks, evaluation, reproducibility, milestones, risks |
| `docs/technical-design/03_links_versions_and_verification_log.md` | Every external link and version, and how it was verified |

## Imported prototype (original status; see progress for new checks)

| Area | Path | Status |
|---|---|---|
| CBMC runner (pinned flags, JSON parsing, witness extraction) | `vwe/tools/cbmc.py` | implemented |
| Verdict rules (draft §5.2) | `vwe/verdict.py` | implemented, unit-tested including Lemma 5 |
| JSON Schemas (interpretation, interpretation set, task, verdict report) | `schemas/`, `vwe/schemas.py` | implemented, tested |
| Golden harnesses for draft Examples 1, 2, 4 (10 candidates) | `spikes/examples/`, `scripts/run_handwritten_examples.py` | 10/10 verdicts match the draft (SAT and Z3 agree) |
| Tool-behaviour spikes T01–T06 (path cuts, missing bodies, abort, buffer sizing, nondeterminism, build views) | `spikes/tool_behaviour/` | logs in `results/tool_behaviour/` |
| Native pre-pass and witness replay with ASan/UBSan | `vwe/replay.py`, [T09 guide](docs/T09_NATIVE.md) | implemented; fixed-input solver rechecks and executable contract checks |

## Original Linux prototype commands

```bash
tools/install_tools.sh                  # CBMC 6.11.0, ESBMC 8.7.0, Z3 5.4.1 (pinned)
export PATH=/opt/cbmc/usr/bin:/opt/esbmc/release/bin:$PATH
python3 -m pytest -q tests              # unit + schema + golden end-to-end
python3 scripts/run_handwritten_examples.py  # independent original harness check
spikes/tool_behaviour/run_spikes.sh     # re-runs the tool-behaviour spikes
```

Or with Docker: `docker build -f docker/Dockerfile -t vwe . && docker run --rm vwe`.
