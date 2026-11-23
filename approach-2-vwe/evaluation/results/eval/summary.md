# Evaluation summary

20 labelled tasks; 20 have generated readings for the method.
Labels: `vwe/eval/labels.py` (formal identity vs P_ref + native differential testing).
Benchmark requests are fixed templates, not human-authored; see docs/T15_BENCHMARKS.md.

| system | labelled | decided | coverage | ACCEPT prec. (Wilson) | REJECT prec. (Wilson) | wrong | unknown labels |
|---|---|---|---|---|---|---|---|
| vwe | 89 | 1 | 0.01 | - - n=0 | 1.00 [0.21, 1.00] n=1 | 0 | 8 |
| tests_only | 89 | 89 | 1.00 | 0.36 [0.25, 0.48] n=64 | 1.00 [0.87, 1.00] n=25 | 41 | 8 |
| single_contract | 89 | 1 | 0.01 | - - n=0 | 1.00 [0.21, 1.00] n=1 | 0 | 8 |
| regression_only | 89 | 43 | 0.48 | 0.69 [0.50, 0.83] n=26 | 0.88 [0.66, 0.97] n=17 | 10 | 8 |

Wilson intervals treat candidates as independent and are shown for reference only. Task-clustered bootstrap intervals (resampling tasks):

- vwe: coverage [0.00, 0.04], REJECT precision [1.00, 1.00], ACCEPT precision -
- tests_only: coverage [1.00, 1.00], REJECT precision [1.00, 1.00], ACCEPT precision [0.23, 0.53]
- single_contract: coverage [0.00, 0.04], REJECT precision [1.00, 1.00], ACCEPT precision -
- regression_only: coverage [0.25, 0.70], REJECT precision [0.80, 1.00], ACCEPT precision [0.48, 0.89]

## Predeclared selection policies (method)

Evidence classes are not calibrated probabilities; each policy keeps only decisions of the listed classes.

| policy | decided | coverage | ACCEPT prec. | REJECT prec. | wrong |
|---|---|---|---|---|---|
| E0 only | 1 | 0.01 | - | 1.00 | 0 |
| E0+E1 | 1 | 0.01 | - | 1.00 | 0 |
| all classes | 1 | 0.01 | - | 1.00 | 0 |

## Paired task-level comparison (method vs baseline)

Right decisions reward coverage; wrong decisions reward abstaining. Both are shown.

| baseline | tasks | more right (method/baseline) | net right | sign p | fewer wrong (method/baseline) | net wrong | sign p |
|---|---|---|---|---|---|---|---|
| tests_only | 20 | 0/18 | -47 | 0.000 | 12/0 | -41 | 0.000 |
| single_contract | 20 | 0/0 | 0 | - | 0/0 | 0 | - |
| regression_only | 20 | 0/9 | -32 | 0.004 | 5/0 | -10 | 0.062 |

## Breakdown by bug type (method)

| bug type | labelled | decided | wrong |
|---|---|---|---|
| INF | 8 | 0 | 0 |
| INIT | 21 | 1 | 0 |
| MLU | 9 | 0 | 0 |
| OOB | 11 | 0 | 0 |
| SHFT | 6 | 0 | 0 |
| USE | 17 | 0 | 0 |
| ZERO | 17 | 0 | 0 |

## Abstention reasons (method)

- 54 x no certified safe and deterministic reference guard
- 36 x one or more interpretations remain unresolved, or none survived
- 6 x scope is unresolved because an extended relation or reach is unknown
