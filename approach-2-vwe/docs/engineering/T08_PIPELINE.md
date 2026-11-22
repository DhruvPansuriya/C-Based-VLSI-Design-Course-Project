# Running the bounded verifier

```sh
vwe verify examples/tasks/ex2_argmax --candidate v2 --html /tmp/argmax.html
vwe verify-all examples/tasks/ex1_saturate
```

Each run records a schema-validated JSON report, a standalone HTML report, the
tool versions and commands, original and candidate source hashes, a canonical
interpretation-set hash, generated harnesses and solver traces. The CLI also
writes an atomically updated `runs/latest.json`. E1 and class counterexamples
include captured output fields when the program reached those observations.
The JSON distinguishes a solver trace from a native replay.

The pipeline computes the reference region from P0, validates and freezes
readings, and checks candidate safety under a certified reference guard. A
semantic E0 witness refers to the declared caller profile and that guard. An
admission policy refusal or build-view mismatch has a separate claim target.
Within the supported profile, the pipeline then checks E1, looks for
outside-clause Ext permission that conflicts with preservation, and checks each
equivalence class. A class's keep region may be omitted from the vacuity probes
only when the call-free query establishes that the region is empty. Clause
regions must be reachable after the candidate call.

T08 applies to the explicit initialized, disjoint caller profile in the task
file. It leaves different surviving input profiles unresolved until separate
profile proofs can be combined. E2 is conditional on a sound or complete
reading of the intended request, as appropriate. Repair correctness and
synthesis readiness have separate report fields. T09 adds native witness replay and acceptance differential checks; see
[T09_NATIVE.md](T09_NATIVE.md). Automatic interpretation, pragma obligations,
and synthesis remain later tasks.
