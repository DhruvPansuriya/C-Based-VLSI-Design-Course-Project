# Native pre-pass and witness replay

T09 adds ASan/UBSan execution to the T08 pipeline. The formal verifier remains
the decision source. Native findings are hints until CBMC's SAT and Z3 backends
reproduce the failure with every active input slot fixed. Missing input slots
prune their own branches, so a replay cannot silently fill in a missing input.

Every semantic REJECT rechecks its deciding counterexamples with fixed inputs
and executes separate P0/P1 sanitizer drivers. E0 expects a candidate-only
sanitizer finding. E1/E2 compare captured outputs with the formal witness; E1
also requires an actual output difference. A native discrepancy or unavailable
rejection replay gives UNDECIDED. A class witness that does not require P0's
output may legitimately encounter P0 UB; the report labels that exception
`p0_undefined` and sets `replayed_natively` to false. Structural policy refusals
have no executable semantic witness. Build-view counterexamples replay the
simulation and synthesis views in separate namespaces.

The pre-pass tries joint boundary vectors, then seeded random vectors. These
are concrete initialized calls with exactly sized buffers, including the
zero-length/NULL alternatives from the formal profile. Input sizes and field
bounds come from the same harness layout. E1 hints are considered only after
all interpretations have been validated and their exact profiles agree.

Before returning ACCEPT, the pipeline executes T03's emitted C observers for
every surviving interpretation on the pre-pass inputs. This driver calls P0
only when a preservation comparison or old-value observer needs it. Any
observed contract or sanitizer failure vetoes ACCEPT and writes
`native/checks/discrepancy.json`. Unavailable optional acceptance testing is
reported explicitly; it does not create acceptance evidence.

## Configuration and execution

```toml
[native]
cc = "gcc"
sanitize = "address,undefined"
prepass_samples = 10000
seed = 0
prepass_seconds = 2
```

Sampling stops at either budget, or at the first eligible hint. Thus 10,000 is
a maximum, not a claim that every run executes that many samples. The report
records the requested and executed counts, seed, time budget and stop reason.
The time budget is checked between calls; each call has its own ten-second
timeout. `prepass_samples = 0` disables sampling and acceptance differential
testing, while rejection replay remains required. Increase `prepass_seconds`
(maximum 600) for a larger pre-pass.

Native execution requires macOS `sandbox-exec` or Linux `bubblewrap`. Drivers
run without network access, with read-only filesystem access, CPU/output-file/
descriptor limits and a wall timeout that kills the process group. ASan needs
a large virtual address reservation, so a virtual-memory ulimit is deliberately
not applied. Both sanitizers are required. Compilation uses the configured
compiler and records its command and diagnostics. Unsupported platforms never
fall back to unsandboxed execution. Hosted CI installs bubblewrap and the Ubuntu `apparmor-profiles` package,
loads its `bwrap-userns-restrict` profile, and probes isolation before running
tests. Ubuntu 24.04 restricts capabilities in unprivileged namespaces without
an application profile; see the [Ubuntu release notes](https://documentation.ubuntu.com/release-notes/24.04/#unprivileged-user-namespace-restrictions).
The first hosted T09 run failed at loopback setup before tests; the profile
setup is a CI prerequisite.

Artifacts live under the run directory: `native/{p0,p1}/`, `native/checks/`,
`native_views/`, `fixed/`, pre-pass hints and per-witness JSON. JSON and HTML
reports include replay statuses and explanations.

## Validation

```bash
.venv/bin/python -m pytest -q tests/test_native.py
make test
make golden
```

The focused tests exercise the argmax `n=3` heap-buffer-overflow, early
outside-scope saturation hints, emitted acceptance checks, incorrect witnesses,
missing isolation, fixed-slot inventory checks, P0 UB and replay disagreements
that downgrade would-be REJECT/ACCEPT results to UNDECIDED. The public pipeline
regression checks all ten existing golden candidates, including native replay
for every REJECT and differential checking for every ACCEPT.
