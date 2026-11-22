# Five-minute professor demo

Run `make demo` after installing the pinned tools. It runs offline, prints a
verdict table, and writes `runs/demo/index.html` linking to complete reports.
Open that index during the presentation. `make demo` performs new local proofs
and replay on every invocation; opening the index alone shows saved results.
The expected table is checked after verification and does not supply verdicts. The demo materializes private task
copies with size bound **K=2**, max unwind 5, initialized disjoint buffers and
handwritten interpretations. The authoritative examples remain at their
original profiles. Reports show the exact reduced caller domain and the
conditional nature of each claim. No LLM or synthesis tool is invoked.

**Opening (30 seconds).** A repair should meet its requested change and preserve
behavior elsewhere. Ordinary equivalence rejects intended changes; a narrow
postcondition can overlook unrelated regressions. VWE combines computed safety
facts, preservation checks and multiple validated readings, then reports the
evidence behind ACCEPT, REJECT or UNDECIDED.

| Case | Point to explain while the report is open |
|---|---|
| Saturation v1: ACCEPT E2 | It differs from the buggy wraparound code but satisfies every supplied interpretation. Acceptance is bounded and requires an adequate interpretation. |
| Saturation v3: REJECT E1 | Returning 255 meets the overflow-only requirement but changes ordinary sums. Show the replayed input and old/new outputs. |
| Argmax v2: REJECT E1 | An empty-array fix accidentally selects the last tied maximum. Preservation catches this without inventing a tie-breaking specification. |
| Argmax v3: REJECT E0 | Reading `a[n]` creates a new bounds error on an old-safe input. Show fixed SAT/Z3 confirmation and the candidate-only native sanitizer finding. |
| Sum v1 / v2: ACCEPT E2 / REJECT E0 | The request requires n allocated elements. Contract validation discards the n-1 reading; reading element n still fails. |
| Add32 error result: UNDECIDED | Permissive and error-code readings pass; saturation fails. The partition states exactly which readings disagree. |
| Build-view v1: REJECT E0 | Simulation and synthesis select different bodies. Show their different outputs and native replay, under the separate build-view claim. |
| Abort defence | The unprotected library model reports SUCCESS because abort removes hard paths. The audited assert-false/assume-false trap is caught by both backends. This comparison is not a repair ACCEPT. |

**Close (30 seconds).** E0 means a computed safety or build-view fact; E1 means
an unjustified regression outside the allowed change scope; E2 means agreement
or refutation across validated interpretations. UNDECIDED records unresolved
proofs or conflicting readings. These examples demonstrate the bounded repair
checker. Automatic interpretation generation, research-scale evaluation and
actual HLS area/delay/latency measurements remain later milestones.

Artifacts include per-run source hashes, interpretation hashes, solver
commands/traces, sanitizer replay records, the demo summary and the path-cut
comparison. Each row must match its expected result, each case must take under
60 seconds, and the complete command must finish in under 300 seconds; the
command returns nonzero on a verdict mismatch or timing-budget violation.

Validated locally on 23 November 2026: nine rows match in **61.2 seconds**,
with the slowest case at **32.1 seconds**. The full suite passes **325 tests**,
with one local ESBMC-unavailable skip. The artifact index's nine links resolve.

## Step-by-step demo (`make demo-steps`)

`scripts/demo_steps.py` runs the real pipeline on one candidate and prints each
stage as it completes: inputs, readings, admission, P0-only regions, reading
validation/freezing, every proof obligation (with witnesses and P0/P1 outputs),
native replay and the verdict. `--interactive` pauses between steps. The stages are
observed through `verify(on_step=...)`, which receives copies and cannot change a
decision.

```sh
make demo-steps                                                     # ex2_argmax v2, pauses
python scripts/demo_steps.py --task ex1_saturate --candidate v3     # no pauses
python scripts/demo_steps.py --task ex1_saturate --candidate v3 --auto mock    # generated readings (fixtures)
python scripts/demo_steps.py --task ex1_saturate --candidate v3 --auto openai  # live; needs API credit
```
