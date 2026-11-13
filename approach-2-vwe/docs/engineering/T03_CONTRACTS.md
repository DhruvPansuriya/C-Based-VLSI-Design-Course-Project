# T03 — Restricted contract observers

VE-DSL-1 now has a closed Lark grammar, immutable syntax nodes, P0-only type environments, a type checker, a portable C observer emitter and an independent Python evaluator. **Parsing/emission is not interpretation validation or a repair verdict.** V-G safety and V-3 old-definedness checks remain mandatory.

## Commands and API

```bash
make contracts
python -m vwe.contract.emit 'n == 0 ? (out_ret == INT_MIN && out_idx[0] == -1) : (out_ret == old_ret)' --task examples/tasks/ex2_argmax
pytest -q tests/test_contract.py
```

`make contracts` emits 28 observers for the stored examples, including the deliberately invalid n-1 shape. Its artifacts say `EMITTED_UNVALIDATED` and `vg_required=true`; this stage does not discard that shape.

```python
from vwe.contract.env import TypeEnv
from vwe.contract.typecheck import typecheck
from vwe.contract.emit import emit_function
from vwe.contract.evaluate import evaluate

env = TypeEnv.from_task(pipeline_task, shape, allow_old=True)
typed = typecheck('out_ret == sum(i,0,n,a[i])', env)
artifact = emit_function(typed, name='vwe_clause_0')
# artifact.source, parameters, uses_old, loop_limits, vg_required
```

For P0 that needs preprocessing, use `TypeEnv.from_analysis(p0_views.sim.analysis, shape, ...)`. No headers or attributes are erased. The task convenience API reads P0 and caller/interpretation shape only; it never uses candidates or `eval_only`.

## Grammar and types

The packaged [grammar](../../vwe/contract/grammar.lark) implements C-like precedence for integer literals, registered names, array indexing, unary `- ! ~`, arithmetic/comparison/bitwise/logical operators and `?:`. Decimal and hexadecimal literals are supported; decimal strings with leading zero remain decimal. It does not accept statements, assignments, increment/decrement, casts, pointer arithmetic, string literals, arbitrary calls or verifier identifiers.

Registered helpers:

- `min(x,y)`, `max(x,y)`, `abs(x)`;
- `sum(i,lo,hi,body)`, `count(i,lo,hi,predicate)`;
- `forall(i,lo,hi,predicate)`, `exists(i,lo,hi,predicate)`.

Ranges are half-open. Binders must be fresh. Bounds use size parameters/constants only; they cannot depend on outputs or array contents. The default range limit is64 and the worst-case evaluation budget4096. Nested bounded loops are allowed within that budget. Empty sum/count is0, empty forall true, and empty exists false.

The sorts are Integer, Boolean and Buffer. Arithmetic operands must be integers, logical operands Booleans, and buffer values can only be indexed. Conditions and final clauses must be Boolean. Use `true`/`false` for Boolean constants rather than relying on C's implicit truthiness. Arrays are checked structurally here; actual access safety belongs to V-G.

Inputs use their P0 names; output snapshots use `out_ret`/`out_<buffer>` and old snapshots `old_ret`/`old_<buffer>`. Global snapshots use `in_global_<name>`, `out_global_<name>`, `old_global_<name>`. Scalar integer types and flat scalar buffers are supported by these observers. Struct/pointer-valued observations require additional capabilities; structural admission does not imply that this DSL can describe every admitted return type.

Input ranges come from the C type and explicit caller bounds. Overlapping scalar constraints are intersected. Output/old-output ranges retain the full C type range; input element bounds are never silently imposed on candidate output arrays.

## Arithmetic profile and safety

The qualified lowering profile is **signed64**, with LP64 C input types. It lifts scalar operands before arithmetic and compares widened values. It supports signed64 literals including LLONG_MIN without emitting an overflowing positive C literal. Used unsigned64 values that cannot fit this representation produce `ContractUnsupported`; __int128 is not claimed as qualified.

Widening is not a proof of UB-freedom. Division by zero, abs(LLONG_MIN), overflowing arithmetic, invalid shifts and invalid accesses must not disappear. The emitter does not insert assumptions or return convenient values on those cases. V-G must check the actual generated evaluator under its evaluation guards. The Python evaluator raises `ContractUndefined` on such concrete inputs. Division/remainder truncate toward zero, not Python's floor division. Bitwise operations use the stated signed64 profile; right shift of negative values follows the selected arithmetic-shift GCC/Clang profile. Left shifts and shift counts require conservative representability/range checks; unsupported interval reasoning is not an invalidity proof.

`GrammarError`/`ContractTypeError` describe malformed/ill-typed generated expressions. `ContractUnsupported` describes a capability or resource limit and **must become UNKNOWN, not silent interpretation deletion**, in T07. Native compilation failures also need classification before any interpretation can be discarded. No general quantified SMT support is assumed: these quantifiers become finite loops.

## Guard preservation and old outputs

The emitter lowers `&&`, `||` and `?:` to guarded statements. A loop/helper/index expression in an inactive branch stays inactive. It must not be hoisted before the guard. Old names require explicit permission during typing; that permission is not a proof that P0 returned there. T07 must prove old execution is defined on each actual read guard.

Observer arguments are ordinary C arguments and are evaluated before entering the observer. Therefore T04 must initialize old scalar placeholders without executing unsafe P0, and use them only under proved old-defined guards. Passing an uninitialized `old_ret` argument is a harness fault even when the observer's internal branch would not read it.

Quantifier bodies are evaluated at every index in range. A first true exists witness cannot hide a later invalid body access. Inner Boolean/conditional guards remain lazy. A real CBMC regression checks this by giving a one-element object to `exists(i,0,2,a[i]==0)`: the first element is zero, but the later access still produces a bounds failure. This is a frontend qualification example, not a universal verifier-correctness proof.

The emitter reports each loop's conservative maximum iteration count. T04/T05 must derive adequate unwinding settings and retain unwinding assertions. Failure to cover a loop remains inconclusive.

## Validation evidence and remaining work

Tests parse/type/emit all stored expressions, reject injection/type errors, exercise empty/nested reductions and scalar limits, preserve lazy old/index/division guards and compare generated C against independent Python semantics on525 deterministic cases. The exact CLI example runs without a verifier. A real CBMC test catches the deliberately malformed eager-quantifier access. Generated C compiles under C11 with `-Wall -Werror`.

Lark1.3.1 was already pinned in T00; no dependency was added. The implementation uses documented LALR rules, token priorities and Transformer APIs: [grammar](https://lark-parser.readthedocs.io/en/stable/grammar.html), [visitors](https://lark-parser.readthedocs.io/en/stable/visitors.html), [API](https://lark-parser.readthedocs.io/en/stable/classes.html). The grammar is shipped as package data.

T04 consumes these typed observers to build real verification harnesses. T07 still needs complete evaluator-UB, old-definedness, realizability and interpretation validation obligations. No ACCEPT is justified by this stage alone.
