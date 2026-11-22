# T06 — Computed regions $B_{ub}$ and $B_{nd}$

**Priority:** must · **Depends on:** T05 · **Effort:** about 2 days

## Goal

Compute the regions the draft takes from `P0` itself, instead of from the LLM. They are needed for request type T3 and for the E0 guard.

## Design: MVP that is sound and simple

The TDD's total instrumentation $P_0^\sharp$ is a stretch goal. The MVP represents each region as a **C predicate over the inputs** (from an interpretation or a hand-written candidate list) and **validates** it with two CBMC queries:

1. **Covers the UB:** `assume(A(x) && !PRED(x)); P0(x);` with standard checks → must be PROVED. ($P_0$ is safe outside the predicate.)
2. **Not empty / not vacuous:** `assume(A(x) && PRED(x)); P0(x);` → must have at least one VIOLATED standard check (the UB is real). Report the witnesses.
3. **Shape sanity (V-5):** estimate $|PRED| / |A|$ by sampling 10,000 random admitted inputs natively (count how often `PRED` holds). If it is above `config.regions.max_ub_fraction` (default 0.5) → `reference_unusable`.

For $B_{nd}$: the same pattern with the determinism harness (spike T05). PRED is proposed from the witnesses. If no predicate is given, enumerate witnesses (up to 20 via repeated CBMC runs that block previous witnesses) and fall back to the predicate `false`, marking the task "nd present, region unknown" → UNDECIDED for any verdict that needs preservation there.

**Where the candidate predicates come from:** hand-written in Phase 1 (`interpretations/*.json` with `provenance.source = "computed"`), and from the LLM in Phase 3 (T13). They are always validated by the queries above.

## Steps

1. Implement `vwe/regions.py` with the queries above.
2. Make the T04 core harness use the **validated** $B_{ub}$ predicate as the E0 guard: P1 safety is checked on `A \ (B_ub \ B_max)`. That is the draft's "P0 safe at x", expressed as a validated region (review R11).
3. Example 2: the validated $B_{ub}$ = `n == 0` (matches the side check in `results/golden/golden_results.json`).

## Acceptance criteria

```bash
pytest -q tests/test_regions.py
```

The tests must cover:

- Example 2, `n == 0` validates;
- the predicate `n == 1` fails query 1;
- the predicate `n < 0` (empty under the shape) fails query 2;
- the T05 spike's function gets a nondeterminism witness.

## Pitfalls

- Bound input values where arithmetic in `P0` can overflow; otherwise $B_{ub}$ will include overflow inputs, which is correct but surprising. Record the bounds in the scope.
