# Example 6: copy safety and preservation

P0 copies n+1 elements, writing the last element first, into an exactly cap-sized
destination. The source has exactly n+1 elements; n is 0..3 and cap is 1..4.
This evaluation order exposes an unconditional first store for the P0-only
certificate. It has the same defined observable result as a forward copy.

Expectations derived before execution:

| Candidate | Expected | Reason |
|---|---|---|
| v1 bounded copy | ACCEPT E2 | Defined everywhere and identical to P0 when n < cap. |
| v2 one-element truncation | REJECT E1 | Defined, but changes ordinary multi-element copies, e.g. n=1, cap=2. |

The UB region n >= cap is proposed from the first store and must be certified
by independent exterior-safety, interior-fault and determinism checks. It is
not inferred from either candidate or evaluation metadata. The safety clause
requires definedness only inside that region; it does not claim full copying
semantics there. Evaluation checks the chosen bounded-copy reference separately.
