# T03 — Contract expression language

**Priority:** must · **Depends on:** T01 · **Effort:** about 2 days · **Can run in parallel with T02**

## Goal

Parse, type-check and translate the restricted expressions used in interpretations (`zone`, `behaviour`, `ext`, `reach`) into side-effect-free C (TDD §6).

## Steps

1. **`vwe/contract/grammar.lark`:** the EBNF from TDD §6 (Lark, LALR). Include `forall`, `exists`, `min`, `max`, `abs`, `sum`, `count`.
2. **`vwe/contract/ast.py`:** typed AST nodes (dataclasses).
3. **`vwe/contract/typecheck.py`.** The environment is built from the `P0` signature and shape.
   - Names: inputs (parameters; buffer parameters are arrays), `out_ret`, `out_<param>` for pointer parameters (post-state), `old_ret` and `old_<param>` (only if `uses_old_output`), and constants `INT_MIN`, `INT_MAX`, `UINT8_MAX`, ...
   - Quantifier bounds may use only size parameters and literals.
   - Reject: unknown names, calls other than helpers, assignments, `++`, pointer arithmetic, casts to pointers, `__CPROVER*`.
4. **`vwe/contract/emit.py`:** `emit_c(expr, env, wide="long long") -> str`. It produces a `static int vwe_clause_<id>(...)` C function.
   - All arithmetic is done in `wide` (review R12).
   - `sum`/`count`/`forall`/`exists` become loops over the declared bounds.
   - The output must compile with `gcc -std=c11 -Wall -Werror -fsyntax-only`.
5. **Tests (`tests/test_contract.py`):**
   - round-trip all expressions in `examples/tasks/*/interpretations/*.json`;
   - error cases for each forbidden construct;
   - emitted code compiles;
   - property test (hypothesis optional): emitted C evaluates to the same truth value as a Python evaluator on random small inputs.

## Acceptance criteria

```bash
pytest -q tests/test_contract.py
python -m vwe.contract.emit 'n == 0 ? (out_ret == INT_MIN && out_idx[0] == -1) : (out_ret == old_ret)' --task examples/tasks/ex2_argmax
# prints a compilable C function
```

## Pitfalls

- Comparisons between a wide arithmetic result and a narrow output must cast the output to `wide` first.
- Integer division by zero inside a contract is UB. V-G (T07) catches it; do not silently guard it here.
