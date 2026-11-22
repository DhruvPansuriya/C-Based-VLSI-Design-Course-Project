# EVAL-P3 — VWE on the Project 3 team benchmarks (separate evaluation)

Input: the user-supplied `Project3_Team.zip` (another course team's handoff: LLM-optimised
HLS kernels checked for C-to-C equivalence, plus hardware QoR). It is extracted outside the
repository; its code is **not** committed. Only our adapter, runner, adaptation log (file
hashes and case ids) and our results are committed.

Mapping: each kernel is a **T5 request** ("improve hardware without changing behaviour").
P0 = their original, N = one fixed template, interpretation = one computed T5 preservation
reading (all mutable outputs equal P0's; no LLM). Candidates: their optimised rewrite and
seeded one-bit fault (main cohort, 51 kernels), or their subtle-fault control candidate
(80 cases: 54 not_equivalent, 20 equivalent, 6 candidate_undefined).

Adaptations: `#include <stdint.h>` → explicit fixed-width typedefs (their stated ILP32
integer scope; this host's SDK header is not parseable by the VWE frontend); profile
`config/project3.toml` (K=32, max_unwind=40, 120 s solver timeouts) because their arrays and
loops reach 32. No case was skipped.

What this compares: VWE's verdict vs their label and vs their own checker's outcome. It
does not compare hardware QoR (VWE does not synthesise). Their labels for the main cohort
are role-based (rewrite = proved equivalent, `_buggy` = seeded fault) as stated in their
RESULTS.md; subtle-fault labels are per case from their `summary.json`, checked by file hash.

```sh
python scripts/adapt_project3.py --handoff <extracted>/Project3_Team_Handoff
python scripts/eval_project3.py            # results/eval_project3/summary.md
```

## Results (2026-11-23, `results/eval_project3/summary.md`)

181 candidates; **125 decided (coverage 0.69); all 125 agree with Project 3's labels; 0
disagreements.** Evidence classes: E0 = 4 (all four decided candidate-UB controls), E1 = 73
(regressions, including every decided seeded one-bit fault), E2 = 48 (accepted rewrites).

| cohort | label | n | VWE ACCEPT | VWE REJECT | UNDECIDED |
|---|---|---|---|---|---|
| main | equivalent | 51 | 30 | 0 | 21 |
| main | not_equivalent | 50 | 0 | 35 | 15 |
| subtle faults | equivalent | 20 | 18 | 0 | 2 |
| subtle faults | not_equivalent | 54 | 0 | 38 | 16 |
| subtle faults | candidate_undefined | 6 | 0 | 4 | 2 |

Abstentions (56): 48 have no certified P0 reference guard. In 32 of those 34 tasks the cause is a
**SAT-backend timeout (120 s) on P0's determinism self-composition** for multiplication-heavy
kernels (dot16, gemm, matvec, convolution, ...); VWE requires SAT and Z3 to agree, so a SAT
timeout blocks the guard. 5 more are SAT timeouts on later obligations, and 3 are the CBMC
uninitialised-array false positive vetoed by native replay (Q27).

Comparison with their checker: their checker agrees with its labels on 181/181. For the main
cohort this is partly by construction (labels come from their proofs); the subtle-fault labels
were set before checking. VWE reaches the same conclusion independently on every case it
decides, with a different method (CBMC SAT/Z3 relational harnesses, fixed-input re-proof,
sanitizer replay) and no LLM. VWE decides fewer cases (0.69 vs their 1.00 coverage) under this
laptop's 120 s budget. Their checker is not rerun here; their outcomes are read from their
recorded results.

Mean time per verdict: 80.7 s (3 workers on an 8-core laptop, with the opt-in P0-only cache).
