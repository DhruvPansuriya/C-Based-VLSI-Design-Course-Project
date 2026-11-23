# T07 — Interpretation validation, equivalence classes, freezing and hashing

**Priority:** must · **Depends on:** T06 · **Effort:** about 2 days

## Goal

Implement Stage 3: discard interpretations **only on objective grounds**, group the survivors, and freeze the set.

## Steps (`vwe/validate.py`)

1. **V-G:** the contract parses (T03); `gen_contract_ub` (T04) is PROVED under the interpretation's own shape. A failure in `main`/`vwe_clause_*` discards the interpretation. (Example 4's $(n-1)$ shape must be discarded; already demonstrated in `results/golden/`.)
2. **V-1 (non-vacuous):** $A_\sigma$, each zone, and $A_\sigma \setminus B_k$ (unless the interpretation is total) are satisfiable: `assume(region); assert(0);` must FAIL.
3. **V-2 (bug witness):** exists $x \in B_k$ where `P0` is unsafe, or `P0`'s output violates the clause: `assume(zone); y0 = P0(x); assert(behaviour(x, y0, y0));` must FAIL. Keep the witness.
4. **V-3 (reference validity):** `P0` is safe and deterministic on $A_\sigma \setminus (B_k \cup B_{ub} \cup B_{nd})$, and on every zone whose clause uses `old_*`.
5. **V-4 (realisable):** for each clause and each overlap of clauses, `assume(zone); y = nondet; assume(behaviour(x,y)); assert(0);` must FAIL (some $y$ exists). This checks satisfiability for *some* $x$; per-$x$ realisability is approximated by also checking on the V-2 witness. Document the approximation.
6. **V-5 (shape sanity):** from T06.
7. **Equivalence classes:** pairwise `equiv_pair(j,k)` with a free output $y$ (TDD §7.2). Exclude pairs with different shapes. Use union-find. An unresolved pair (timeout) is treated as **not** equivalent (safe direction, draft Lemma 5).
8. **Freeze:** build an `InterpretationSet` JSON (schema `interpretation_set`) with members, discarded items (with check and detail), informational data, the generation record and `sha256` of the canonical members JSON. Write it to `runs/.../interpretation_set.json`.
9. **Brackets:** $B_{\min}$ = conjunction of zones; $B_{\max}$ = disjunction of zones, `reach` and validated $B_{ub}$/$B_{nd}$; $\sigma_{\min}$/$\sigma_{\max}$ by comparing buffer-size expressions at the bound corners (for MVP shapes, sizes are linear in one parameter; compare at min and max of the bound).

## Acceptance criteria

```bash
pytest -q tests/test_validate.py
```

The tests must cover:

- Example 4's $(n-1)$ interpretation is discarded by V-G;
- an interpretation whose behaviour `P0` already satisfies everywhere on the zone is discarded by V-2;
- a contradictory behaviour (`out_ret == 1 && out_ret == 2`) is discarded by V-4;
- identical strict/permissive interpretations end up in one class;
- the hash is stable across two runs.

## Pitfalls

- Every query must use the same `BASE_FLAGS` and vacuity discipline as the verdict queries.
- Never discard an interpretation because LLM examples disagree (that is informational only, Phase 3).
