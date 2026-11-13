# Example 5: ambiguous overflow handling

These expectations are derived before running the verifier. Inputs are unsigned
32-bit values. The return type is a signed 64-bit carrier, allowing a reserved
-1 error result outside the valid unsigned 32-bit value range. P0 computes
unsigned wraparound and is defined everywhere. Strict requires UINT_MAX on
overflow; permissive accepts UINT_MAX or -1; adversarial requires -1.

| Candidate | Expected | Hand-derived reason |
|---|---|---|
| v1 saturation | UNDECIDED, ambiguous | Satisfies strict and permissive, violates adversarial. |
| v2 error code | UNDECIDED, ambiguous | Satisfies permissive and adversarial, violates strict. |
| v3 unchanged wrap | REJECT E2 | All three readings fail, e.g. UINT_MAX + 2 wraps to 1, neither permitted overflow result. |

All candidates preserve P0 when a+b fits, so no E1 rejection applies. The two
nonwrapping candidates differ only inside the zone and do not raise a scope
conflict. Changing the interpretation set changes the conditional verdict:
with strict alone, saturation is ACCEPT and the error candidate is REJECT E2.
The initial fixture retains all three readings. The permissive disjunction
needs a proved joint output witness, not a satisfiable sample.
