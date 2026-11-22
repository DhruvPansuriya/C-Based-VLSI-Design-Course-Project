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
