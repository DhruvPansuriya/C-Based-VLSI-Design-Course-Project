# Public-pipeline golden regression suite

`make golden` invokes `vwe.pipeline.verify` on every case in
`tests/golden/expected.json`, validates each JSON report, and returns nonzero
if any decision or evidence class differs. The aggregate file is
`runs/golden/golden_results.json`; each row links to its individual report.
`--workers 1` runs sequentially; the default runs three independent cases.

The current checkpoint covers 13 candidates in Examples 1–4. Expectations
were written before executing the new rounding fixtures. See
[the Example 3 reasoning](../examples/tasks/ex3_avg_half_away/README.md).
The complete rounding fix must abstain because both interpretations omit
positive odd sums from their change zones while their extended relation allows
the correction. The negative-only fix is accepted conditionally and remains
incorrect against the full request. This distinction is intentional and is
explained in the task README and the report's conditional claim.

The previous independent harness runner remains available:

```sh
.venv/bin/python scripts/run_handwritten_examples.py --out runs/handwritten
```

It covers only its original ten cases, including the argmax UB-region and
invalid sum-shape side checks. The generated-harness cross-check also remains
limited to those original fixtures; new examples use the complete public
pipeline, which performs validation and scope checks before aggregating E2.

T10 remains in progress. Examples 5–7 need their own prederived expectations
and supporting engine checks. In particular, ambiguous output relations need
joint realizability evidence; copy safety zones need a qualified P0-only
region certificate; and empty-zone T5 identity interpretations need validation
that does not wrongly demand a repair bug witness. None of those capabilities
is claimed by this checkpoint. The professor demo is T11 and remains pending.
