# EVAL-P3: VWE on the Project 3 team benchmarks

Separate evaluation with a different approach: their tool checks C-to-C equivalence of LLM-optimised HLS kernels; VWE treats each as a T5 request ("optimise without changing behaviour") with one computed preservation reading and no LLM. Labels and their checker outcomes come from their handoff (`eval/project3.json`), joined after all verdicts.

Profile `project3.toml` (K=32, max_unwind=40, 120 s solver timeouts); local CBMC/Z3 on this laptop. `#include <stdint.h>` was replaced by explicit typedefs (recorded per task).

| cohort | their label | n | VWE ACCEPT | VWE REJECT | VWE UNDECIDED | agree | disagree | their checker agrees with label |
|---|---|---|---|---|---|---|---|---|
| main | equivalent | 51 | 30 | 0 | 21 | 30 | 0 | 51/51 |
| main | not_equivalent | 50 | 0 | 35 | 15 | 35 | 0 | 50/50 |
| subtle_faults | candidate_undefined | 6 | 0 | 4 | 2 | 4 | 0 | 6/6 |
| subtle_faults | equivalent | 20 | 18 | 0 | 2 | 18 | 0 | 20/20 |
| subtle_faults | not_equivalent | 54 | 0 | 38 | 16 | 38 | 0 | 54/54 |

**Overall:** 181 candidates, 125 decided (coverage 0.69), 125 agree with the label, 0 disagree. Agreement among decided: 1.000 (Wilson [0.97, 1.00]; candidates within a kernel family are not independent, so treat the interval as indicative).

Evidence classes of VWE decisions: E0=4, E1=73, E2=48

Mean seconds per verdict: 80.7

## Disagreements (each must be explained)

None.

## Abstentions (VWE UNDECIDED)

- 48 x no certified safe and deterministic reference guard
- 5 x tool error: sat timeout
- 3 x native replay discrepancy: expected a candidate-only sanitizer finding
