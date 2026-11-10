# Example 7: simulation/synthesis consistency

Inputs are bounded to -100..100, isolating build-view behavior from integer
overflow. No pragma scheduling or synthesis QoR claim is made by this fixture.

Expectations derived before execution:

| Candidate | Expected | Reason |
|---|---|---|
| v1 synthesis-only change | REJECT E0, build_view_consistency | At x=0 simulation returns 1 and synthesis returns 2. |
| v2 pure rearrangement | ACCEPT E2 | Preserves P0 on the entire declared domain; the change zone is empty. |

An empty-zone T5 reading is identity and must not require evidence that P0 has
a repair bug. It still requires a safe deterministic reference, nonvacuous
caller domain, and complete preservation proofs. The divergent candidate must
reproduce with fixed inputs in both CBMC backends and isolated native views.
