# Verdicts with Evidence — C-Based VLSI Design Course Project

**Current checkpoint: T00–T11 complete on `implementation-start`.** The working
tool checks bounded C repairs using handwritten interpretations, generated
CBMC SAT/Z3 proof jobs, fixed-input confirmation and isolated sanitizer replay.
The offline professor demo is implemented. T12/T13 add an LLM client and automatic
interpretation generation (`vwe interpret`, `verify --auto`), exercised only with
authored mock fixtures: no live model has been run. Benchmark evaluation and HLS
QoR measurements remain future work.

## Start here — no solver rerun required

1. [Methodology walkthrough](docs/METHODOLOGY_WALKTHROUGH.md): the complete idea,
   notation, examples, pipeline, code map and current limits.
2. [Preserved results](results/checkpoints/2026-11-23-t11/README.md): the twenty-case
   table, standalone reports, logs, provenance and checksums. [HTML report index](results/checkpoints/2026-11-23-t11/index.html).
3. [Progress and next actions](plan/PROGRESS.md): completed milestones and what remains.
4. [Professor demo guide](docs/DEMO_GUIDE.md): a short presentation script.
5. [Research draft](docs/research/Verdicts_with_Evidence_Final_Draft.md), then the
   [import review and required corrections](docs/CLAUDE_IMPORT_REVIEW.md).

The draft states the proposed research method. Its opening “No experimental
result is reported” belongs to that original design document. Later measured
implementation observations live in `results/`; the draft is not a completion
certificate. The import review governs corrections where the design overclaims.

## Recorded results

Implementation checkpoint: [`8ed772e`](https://github.com/DhruvPansuriya/C-Based-VLSI-Design-Course-Project/commit/8ed772e).

| Check | Observed result | Preserved evidence |
|---|---|---|
| Full core/demo test suite | **325 passed, 1 skipped**; local ESBMC unavailable | [Test log](results/checkpoints/2026-11-23-t11/logs/tests.log) |
| Public-pipeline golden suite | **20/20 match** across draft Examples 1–7 | [All cases and reports](results/checkpoints/2026-11-23-t11/README.md), [JSON](results/checkpoints/2026-11-23-t11/golden.json) |
| Offline professor demo | **9/9 rows match in 61.2 s**, slowest case 32.1 s | [Demo JSON](results/checkpoints/2026-11-23-t11/demo.json), [console log](results/checkpoints/2026-11-23-t11/logs/02-t11-demo-validation.log) |
| Hosted CI for T10/T11 | **Python 3.10 and 3.12 passed** | [Completed run/job records](results/ci/2026-11-23-t10-t11.json) |
| Archived evidence integrity | Payload checksums and portable report links; raw text evidence retained | [Metadata](results/checkpoints/2026-11-23-t11/metadata.json), [checksums](results/checkpoints/2026-11-23-t11/checksums.json) |

The twenty outcomes are **7 ACCEPT, 10 REJECT and 3 UNDECIDED**. They match
expectations derived before execution. These are authored regression fixtures,
not a measured accuracy rate on unseen repairs. In particular, the negative-only
rounding fix intentionally receives conditional ACCEPT under collapsed readings
while missing the full English request; the walkthrough explains why.

The standard golden size bound is K=4 with task-specific value/profile bounds.
The demo uses explicitly reduced K=2 copies and preserves the authoritative
tasks. Local tools recorded CBMC 6.11.0 and Z3 5.4.1; ESBMC was unavailable.
Timings are observations from this workstation, not cross-machine guarantees.

**Evidence provenance:** the recorded runs were executed before the corresponding
implementation commits. Their manifests retain the execution-time parent SHAs;
they have not been relabeled as clean post-commit runs. The snapshot explains
this and retains source/configuration hashes. Read its metadata before making
stronger reproducibility claims.

## What the tool decides

Inputs are buggy P0, English request N and candidate P1. It returns
**ACCEPT / REJECT / UNDECIDED**, a claim target, evidence class, conditions and
witnesses. Intended changes are checked against each reading; defined old behavior
is preserved elsewhere. Ambiguity, incomplete bounds and tool disagreement cause
abstention. `ACCEPT` remains conditional on adequate interpretation/profile
premises. Policy refusal, repair correctness and build-view consistency are
separate claims.

The current implementation is profile-local, with exact initialized disjoint
buffers and a restricted C/contract subset. Multiple distinct surviving shapes
remain unresolved. General exact UB-region inference is not implemented. Reports
do not turn repair acceptance into a global synthesis-ready claim.

## Running it

Reading the saved evidence requires no CBMC, provider account or native compiler.
For a new verification run, install the pinned tools and dependencies first:

```sh
python3 -m venv .venv
.venv/bin/python -m pip install -e .
make test
make golden
make demo
.venv/bin/vwe verify examples/tasks/ex2_argmax --candidate v2
```

**Offline does not mean prerecorded:** `make demo` performs fresh local
verification and native replay on each invocation, then writes
`runs/demo/index.html`. Opening that HTML file alone displays the last saved
results and performs no computation. The expected-verdict table checks the
results; it is not used by `vwe.pipeline.verify` to choose a verdict.

Current runs need no interactive decisions. Interpretations come either from task JSON
(handwritten) or from `--auto` generation (T13; mock-fixture-tested only).
The future automatic pipeline should also run without runtime human decisions,
returning UNDECIDED when required evidence cannot be established.

`make demo` writes `runs/demo/index.html`. `make golden` writes twenty individual
runs and `runs/golden/golden_results.json`. To run one golden task:

```sh
.venv/bin/python scripts/run_golden_examples.py --task ex5_add32_ambiguous
```

The original independent ten-case harness check is retained:

```sh
.venv/bin/python scripts/run_handwritten_examples.py --out runs/handwritten
```

`make admission` demonstrates structural checks; `make contracts` emits observers
without claiming V-G validation. Linux installation is `bash tools/install_tools.sh`.
macOS requires qualified native tools; the Docker recipe has not been qualified
on this workstation. `vwe interpret` / `--auto` work with mock fixtures (`docs/T13_INTERPRET.md`); live families need a pinned model id and API key in `config/llm.toml`.

## Which remaining tasks are necessary?

There are **23 cards, T00–T22**, not a separate T23. T00–T11 are the minimum
working-demo path and are complete.

| Remaining tasks | Required for this demo? | Additional result |
|---|---|---|
| T12–T13 | No | Automatic request-to-interpretation-to-verdict operation (implemented; live-model validation pending) |
| T14 | No | Repetition/union and stability measurements |
| T15–T18 | No | Benchmark candidates, independent labels, baselines and measured risk/coverage |
| T19–T20 | No | Full HLS pragma gate and actual hardware QoR measurements |
| T21 | No | Optional FIFO temporal extension |
| T22 | A concise write-up is recommended | Consolidated report, figures, limitations and reproducibility |

For a demo-only submission, use the present tool and a clear write-up. To claim
full automation, add T12–T13. To support research-quality empirical conclusions,
add an independently labeled evaluation. To claim area/delay/latency improvement,
perform actual HLS measurements; current C verification results cannot substitute
for them. FIFO and repeated-generation studies can be deferred independently.

See [the full plan](plan/01_PLAN.md), [task cards](plan/tasks/) and
[open questions](plan/OPEN_QUESTIONS.md).

## Code and documentation map

Start with `vwe/pipeline.py` for execution order and `vwe/verdict.py` for the pure
verdict rules. `vwe/tasks.py` excludes evaluation oracles. `vwe/contract/` implements
the restricted language; `vwe/harness/` generates exact-profile jobs.
`vwe/regions.py` and `vwe/validate.py` establish P0-only prerequisites.
`vwe/proof_jobs.py`, `vwe/obligations.py` and `vwe/tools/` handle audited tool
execution. `vwe/replay.py` confirms witnesses. `vwe/report.py` writes evidence.
The [walkthrough](docs/METHODOLOGY_WALKTHROUGH.md#9-code-map-and-the-most-useful-reading-path)
contains the detailed map and a suggested single-case reading path.

| Document | Purpose |
|---|---|
| [Research draft](docs/research/Verdicts_with_Evidence_Final_Draft.md) / [PDF](docs/research/Verdicts_with_Evidence_Final_Draft.pdf) | Theory, proposed pipeline and evaluation protocol |
| [Technical review](docs/technical-design/01_review_of_final_draft.md) | Imported tool qualification and design review |
| [Technical design](docs/technical-design/02_technical_design_document.md) | Intended architecture and interfaces |
| [Import review](docs/CLAUDE_IMPORT_REVIEW.md) | Required soundness corrections and unresolved theorem/profile issues |
| [T10 guide](docs/T10_GOLDEN.md) / [T09 guide](docs/T09_NATIVE.md) | Current golden coverage and native replay |

## Preserve future results

`results/` is committed evidence; `runs/` is ignored working output.
`results/golden/` is the **imported original ten-case** snapshot and is preserved
unchanged. Current evidence is under `results/checkpoints/`; its index identifies
which checkpoint each result belongs to. Do not mistake old prototype logs for a
new full-pipeline run.

After a validated milestone, package the existing observations with a **new**
label rather than regenerating them for a handover:

```sh
.venv/bin/python scripts/archive_results.py \
  --label YYYY-MM-DD-milestone \
  --test-log runs/full-validation.log \
  --log runs/golden-validation.log \
  --log runs/demo-validation.log
```

The exporter does not run solvers, compilers or candidates. It preserves reports,
logs, raw text evidence and hashes, rewrites report links portably, and refuses to
overwrite a checkpoint. Original execution manifests remain intact. Existing
results should be read first; rerun verification when code changes or a new
validation question actually requires it. Rules for coding agents are in
[AGENTS.md](AGENTS.md).
