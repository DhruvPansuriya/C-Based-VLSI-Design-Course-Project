# Public-pipeline golden regression suite

`make golden` invokes `vwe.pipeline.verify` on all 20 candidates in
`tests/golden/expected.json`, validates each JSON report, and returns nonzero
if any decision or evidence class differs. The aggregate file is
`runs/golden/golden_results.json`; each row links to its individual report.
`--workers 1` runs sequentially; the default runs three independent cases.
`--task ex5_add32_ambiguous` selects one task when passed to the runner:

```sh
.venv/bin/python scripts/run_golden_examples.py --task ex5_add32_ambiguous
```

Results print as ordered cases
finish. An unknown task returns a command-line error.

## Coverage and hand-derived expectations

Every new fixture documents its expectations before verifier execution:

| Example | Cases | Evidence exercised |
|---|---:|---|
| 1: saturation | 5 | Correct repairs; E1 regression; E2 semantic refutation |
| 2: argmax | 3 | Old UB; tie-break regression; candidate-only ASan overflow |
| [3: rounding](../examples/tasks/ex3_avg_half_away/README.md) | 3 | Scope conflict; conditional acceptance under collapsed readings |
| 4: sum | 2 | Exact shape; invalid contract shape; off-by-one safety |
| [5: add32](../examples/tasks/ex5_add32_ambiguous/README.md) | 3 | Conflicting valid readings; unchanged wrapping rejected by all |
| [6: copy](../examples/tasks/ex6_copy_overflow/README.md) | 2 | P0-only exact store-fault region; preservation outside it |
| [7: build views](../examples/tasks/ex7_build_views/README.md) | 2 | Native simulation/synthesis divergence; identity optimization |

The complete rounding fix abstains because both readings omit positive odd
sums from their zones while Ext allows the correction. The negative-only fix
gets conditional ACCEPT and remains incorrect against the full request. This
is an explicit interpretation-collapse example, not unconditional correctness.

For add32, saturation satisfies strict and permissive readings; the error code
satisfies permissive and adversarial readings. Both therefore give UNDECIDED.
The unchanged candidate violates all three and gives REJECT E2. Tests also
restrict the set to strict alone, showing the resulting ACCEPT/REJECT change.
The return carrier reserves -1 outside the unsigned 32-bit result range.

## Qualified engine additions

- Constructive disjunctions choose a witness branch and prove the complete
  original relation universally. An unproved construction stays UNKNOWN.
- Empty-clause T5 identity readings require preservation rather than a repair
  bug witness; all reference and nonvacuity premises remain mandatory.
- Initial plain stores can supply a narrow P0-only UB certificate. Calls,
  conditional stores and side-effecting indices do not qualify. General loop
  UB-region inference is not claimed.
- CBMC decimal integer traces with C suffixes are normalized for fixed-input
  solver checks and native replay. Unsupported representations stay unresolved.

See [region details](T06_REGIONS.md) and [validation details](T07_VALIDATION.md).

## Independent checks and validation

The previous independent harness runner remains available:

```sh
.venv/bin/python scripts/run_handwritten_examples.py --out runs/handwritten
make golden
make test
```

It covers its original ten cases, including the argmax UB-region and invalid
sum-shape side checks. The generated-harness comparison also stays restricted
to those fixtures. New examples use the complete pipeline's validation, scope
and replay stages. The CLI smoke test selects the rounding task while the
public-pipeline test checks all twenty cases, avoiding duplicate full sweeps.

The 13-case checkpoint passed 291 tests with one ESBMC-unavailable skip.
The complete 20-case suite passes: `make golden` matches 20/20; `make test`
passes 323 tests with one ESBMC-unavailable skip. Focused fixture/soundness
checks pass 77 tests. This completes milestone M1. T11 adds the [professor demo](DEMO_GUIDE.md).
