# Interpretation validation and freezing

`freeze_interpretations` takes admitted P0 views and proposed readings. It cannot
receive P1. It records each reading as valid, objectively invalid, or unresolved.
Only objectively invalid readings are discarded. The frozen JSON stores remaining
readings in ID order and hashes their canonical UTF-8 JSON. A separate record binds
the validation results to P0. The replay hash identifies the readings. The run
manifest must also bind the tool versions, P0, P1 and bounds.

| Check | Implementation |
| --- | --- |
| V-G | Parse and type the observers, then check them over exact input allocations and type-correct synthetic outputs. A failure involving synthetic old values remains unresolved until reachable old values can be characterized. |
| V-1 | Use call-free reachability of the input domain and of each clause zone. A provably empty keep region is allowed for a total change. |
| V-2 | Search for original-program UB within the union of change zones. If that region is safe, run P0 there and check whether it already satisfies all active clauses. |
| V-3 | Prove safe and deterministic original behaviour on the keep region. The current class generator also needs a full-profile certificate if a clause reads old outputs. |
| V-4 | Build one joint output tuple per input for the supported conjunction-of-equalities grammar. Assign every simultaneously active clause's proposed values and prove all active clauses hold. If this construction fails, globally unsatisfiable clauses can be discarded. One satisfiable input is insufficient to validate an interpretation. |
| V-5 | Shape plausibility is informational. No sampled plausibility cutoff removes a reading. |

Class grouping proves the same change region and conditional repair relation over
free outputs, on one exact profile. A failed or incomplete comparison leaves two
classes. All original members remain available for Ext and reach checks even when
their class proof is shared. The current run budget checks up to sixteen readings,
sixteen clauses per reading and thirty-six class comparisons. An unattempted
validation remains unresolved and blocks a universal verdict.

Tests cover the too-small sum profile, an already satisfied repair, inconsistent
outputs, unsupported constructs that remain in the set, stable hashes, equivalent
readings and the original argmax UB witness.
