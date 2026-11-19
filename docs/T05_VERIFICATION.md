# Proof job execution

`vwe.proof_jobs.run_job` compiles generated C with `goto-cc`, inserts CBMC's
experimental uninitialized-local checks, and links CBMC's C library models.
It removes existing bodies for the named path-cut functions, generates trap
bodies, and audits the final GOTO instructions. Every expected trap must
contain an assertion of false followed by an assumption of false. The SAT and
Z3 runs use the same binary, with library relinking disabled. The output
directory contains the commands, tool outputs, and the instrumented artifact
hash. [Pinned GOTO instrumentation source](https://github.com/diffblue/cbmc/blob/cbmc-6.11.0/src/goto-instrument/goto_instrument_parse_options.cpp)

The allocator must be configured at library linking time with
`--no-malloc-may-fail`. Passing it only to CBMC after prelinking admitted
spurious NULL and invalid-address counterexamples on the exact-size buffer
fixture. The regression test requires both backends to report only the
candidate's out-of-range read. The uninitialized-local pass runs before library
linking and trap insertion. On a linked trap fixture the pass otherwise failed
with a missing analysis state.

The executor compares the two backends' property IDs and statuses and checks
the harness assertion labels. An incomplete unwind, missing callee model,
backend disagreement, missing label or tool error gives INCONCLUSIVE. After
the monitored call, each required probe must fire. A successful probe only
certifies that a region is empty when it comes from a separate query without
the call. A solver outcome supplies one part of the evidence. Verification
still needs the bundle's input-model, admission, interpretation and reference
certificates. Uninitialized-local instrumentation catches the included scalar
read fixture. Other cases, such as partial struct initialization and alias-based
reads, still need coverage qualification before the pipeline relies on them.

The optional ESBMC adapter checks the qualified source subset and returns
agreement, disagreement, or unsupported. Cross-tool disagreement may veto an
ACCEPT. A source profile requiring CBMC pointer identity, allocation, or trap
instrumentation has no qualified ESBMC adapter yet. CI exercises the correct
saturation example against the pinned Linux binary. The macOS ARM64 asset
matched the published checksum but requires compatible dynamic libraries. The
local installation could not load the packaged executable against its Boost
library. [ESBMC v8.7 release](https://github.com/esbmc/esbmc/releases/tag/v8.7)
