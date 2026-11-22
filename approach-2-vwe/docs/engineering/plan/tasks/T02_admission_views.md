# T02 — Admission and build views

**Priority:** must · **Depends on:** T01 · **Effort:** about 2 days

## Goal

Implement Stage 1 of the draft: decide whether the code can be analysed soundly, and produce the exact preprocessed views.

## Steps

1. **`vwe/views.py`: `make_views(src, fn, out_dir) -> Views`.**
   - Synth view: `cbmc --preprocess -D__SYNTHESIS__ src` (CBMC 6.11 has `--preprocess`; record the command). Sim view: the same without the macro.
   - Fallback if the CBMC preprocessor rejects something: `gcc -E -P`. Record which one was used.
   - Rename the target function to `p0_<fn>` / `p1_<fn>` **after** preprocessing (token-level rename with a regex on word boundaries; check that `pycparser` parses the result).
   - Return the paths plus a hash of each view.
2. **`vwe/admission.py`: `admit(task, candidate) -> AdmissionResult`** (see TDD §4.1). Its checks:
   - **(a) Parse** both views with `pycparser` (on the preprocessed text). Failure → UNDECIDED("unsupported C").
   - **(b) Signature equality** of `P0` and `P1` (return type, parameter types and order). Different → UNDECIDED("interface change").
   - **(c) Forbidden constructs in `P1`** (AST walk): any identifier starting with `__CPROVER`, `setjmp`/`longjmp`, `goto` into a scope, declarations inside `switch` bodies, `volatile`, floating-point types, recursion (call-graph cycle), new file-scope `static` or global objects not present in `P0`, inline `asm`. Forbidden → REJECT (E0, "forbidden construct") for `P1`, UNDECIDED for `P0`.
   - **(d) Undefined functions:** `goto-cc` each view, then `goto-instrument --list-undefined-functions`. Anything not in `config/whitelist.toml` (start with `memcpy`, `memset`, `abs`, `labs`) → REJECT for `P1`, UNDECIDED for `P0`. *Note:* CBMC 6.11 also reports `*.no-body.*` properties during analysis (review R4). Classify those as admission failures in T05.
   - **(e) Globals:** collect file-scope objects read or written by the function; classify as `const_program` or `input_output` (TDD §7.1 rule 4).
   - **(f) Pragmas:** extract `#pragma HLS ...` lines with location and key=value pairs (the policy itself is T19). Unknown pragmas are recorded now and enforced in T19.
3. **Build-view equivalence** is a harness (T04). Admission only records whether the two views differ textually (a cheap signal).

## Acceptance criteria

```bash
pytest -q tests/test_admission.py
```

The tests must cover:

- the three example tasks are admitted;
- a candidate using `__CPROVER_assume` → REJECT E0;
- a candidate calling an undeclared `helper()` → REJECT (spike T02 source can be reused);
- a candidate with a different signature → UNDECIDED;
- a candidate with `#ifdef __SYNTHESIS__` → admitted, with `views_differ = True` (spike T06 source);
- a `float` parameter → UNDECIDED.

## Pitfalls

- `pycparser` needs preprocessed C without GCC extensions. Add `-D__attribute__(x)=` and similar defines when needed, and record them.
- Keep views byte-identical across runs (hashes are part of the report).


## Implementation note — 22 November 2026

Implemented in `vwe/admission.py`, `vwe/views.py`, `vwe/c_frontend.py` and `vwe/tools/frontend.py`; demo command: `make admission`. See `docs/T02_ADMISSION.md` for interfaces and current capability limits.

Correctness adjustments: use scope-aware AST alpha renaming instead of word-boundary replacement; do not erase attributes/layout features; retain GCC fallback as explicitly unqualified; clear the simulation macro in an isolated wrapper because the probed `-U__SYNTHESIS__` spelling is rejected. Policy E0 carries `claim_target=admission_policy`. Pragma/build equivalence and library-model linking remain later proof obligations.
