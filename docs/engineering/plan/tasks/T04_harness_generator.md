# T04 — Harness generator

**Priority:** must · **Depends on:** T02, T03 · **Effort:** about 3 days

## Goal

Generate every harness kind in TDD §7.2 from (views, signature, shape, interpretation set). The generated harnesses must reproduce the hand-written golden harness results exactly.

## Steps

1. **`vwe/harness/templates/`:** Jinja2 templates or plain Python string builders. Prefer Python builders, so there is no extra dependency; if you add Jinja2, pin it.
2. **Input materialisation** (shared by all kinds):
   - scalar parameters: `T x = nondet_T(); __vwe_in_k = x;` (named-input rule, review R9);
   - buffer parameters: `T *a = malloc((size_t)(SIZE) * sizeof(T));` with symbolic `SIZE` from the shape, plus a loop that fills elements from `nondet_T()`;
   - **two copies** for relational kinds (identical values);
   - size bounds: `__CPROVER_assume(lo <= n && n <= hi)` from `shape.bounds`, with `hi <= K`;
   - mutable globals: assigned identically in both programs' renamed copies.
3. **Output capture:** return value plus the post-state of every pointer parameter and every `input_output` global; pointer-aware and field-wise comparison helpers (TDD §7.1 rule 5).
4. **Harness kinds.** Each returns a `HarnessBundle` (files, defines, unwind bound, watched inputs, the property-id prefixes that matter):
   - `gen_core`: E0 (no asserts; standard checks inside `p1_*`) plus E1, encoded as `assert(eq(y1,y0) || ext_1 || ... || ext_m)` on the keep region $A \setminus B_{\max}$ (review R10). If any `ext == "unknown"`, still emit the E1 assertion but mark the bundle `e1_decisive = False`, so that the verdict becomes UNDECIDED (scope).
   - `gen_class`: for one equivalence class, `zone_i ⇒ behaviour_i` for each clause, and `y1 == y0` outside $B_k$.
   - `gen_vacuity`: `assert(0)` after the call in the keep region and in each clause zone (each must FAIL).
   - `gen_views_equiv`: synth-view `P1` vs sim-view `P1` on identical inputs.
   - `gen_determinism(prog)`: self-composition (spike T05).
   - `gen_contract_ub(interp)`: evaluates only the contract functions under the shape (for V-G).
5. **Unwind bound:** from the shape (max size + 1) plus constant loop bounds found by a simple AST scan; else `config.bounds.max_unwind`.
6. **Golden equivalence test:** for Examples 1, 2 and 4, run the generated harnesses through `vwe.tools.cbmc.run` and check that the per-obligation outcomes equal those of the hand-written harnesses in `spikes/examples/` (as computed by `scripts/run_golden_examples.py`).

## Acceptance criteria

```bash
pytest -q tests/test_harness_generator.py      # compiles every generated harness with goto-cc
pytest -q tests/test_harness_equivalence.py    # generated vs hand-written outcomes identical (needs CBMC)
```

## Pitfalls

- **Never** use fixed-size arrays for buffers (spike T04).
- With exact-size `malloc`, `malloc(0)` is legal. Make sure the `n == 0` cases still run.
- Keep the generated C readable; it is shown in reports.
