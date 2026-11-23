# Example 3: collapsed scope and half-away rounding

Expectations derived before executing the verifier, using draft Section 9 and
its conditional verdict rules. Inputs are bounded to [-1000,1000], so addition
cannot overflow. C division truncates toward zero, including negative sums.

| Candidate | Expected | Reason |
|---|---|---|
| v1: complete half-away fix | UNDECIDED, scope disagreement | Positive odd sums change outside both clause zones, but Ext permits the change; (1,2) is a hand-derived witness. |
| v2: negative odd sums only | ACCEPT E2, conditional | Satisfies both deliberately incomplete readings and preserves their keep region. It still fails the full natural-language request on positive odd sums. This demonstrates interpretation collapse, not unconditional correctness. |
| v3: unchanged truncation | REJECT E2 | Both readings fail at (-1,-2), where -2 is required and P0 returns -1. |

The evaluation oracle uses magnitude rounding independently of the candidate
formula. Evaluation files remain excluded from the pipeline view.
