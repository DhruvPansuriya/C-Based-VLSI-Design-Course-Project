# EqBench public C dataset: initial evaluation

Repository snapshot: `3724fce5b287cc63165028444daf904f25b0158b`.

The upstream README advertises 147 equivalent and 125 non-equivalent
cases across C and Java. We report what is actually present in this
pinned C snapshot, rather than treating advertised counts as measured.

- Indexed old-version C files: 247.
- Complete old/new C file pairs: 246.
- Labels among indexed records: {'equivalent': 134, 'not_equivalent': 113}.
- Compatible with the current generated-harness adapter: 14.
- Evaluated: 14 (all currently eligible cases).
- Status counts: {'unknown': 3, 'incomplete_unwind': 9, 'equivalent': 2}.
- Conclusive verdicts: 2; agreements with upstream labels: 2.

## Interpretation

The two conclusive checks match their labels. This is **not 100%
accuracy on EqBench**: the other evaluated pairs are inconclusive,
and most indexed pairs are excluded by current frontend restrictions.
All evaluated pairs have signed-int interfaces, so our uint32-only
interpreter rejects them and the pipeline uses ESBMC/Z3. Thus these
results evaluate the composite tool's fallback, not signed-integer
capabilities of our own interpreter.

The experiment uses unmodified source semantics, full scalar type
domains, no added range preconditions, unwind bound 32, a requested
3000 ms solver wall-clock budget, and an external process grace period
of 10 seconds. Unwinding assertions remain enabled. `incomplete_unwind`
does not imply a program mismatch. An `unknown` result is not an
incorrect classification. These limitations expose genuine next steps
in support for general loops and richer C interfaces.

## Every evaluated case

| Pair | Published label | Composite result |
|---|---|---|
| REVE/barthe/Eq | equivalent | unknown |
| REVE/barthe/Neq | not_equivalent | incomplete_unwind |
| REVE/barthe2/Eq | equivalent | incomplete_unwind |
| REVE/loop5/Neq | not_equivalent | incomplete_unwind |
| REVE/barthe2big2/Eq | equivalent | incomplete_unwind |
| REVE/nestedwhile/Neq | not_equivalent | incomplete_unwind |
| REVE/bug15/Eq | equivalent | equivalent |
| REVE/digits10/Eq | equivalent | unknown |
| REVE/loop2/Eq | equivalent | incomplete_unwind |
| REVE/loop3/Eq | equivalent | incomplete_unwind |
| REVE/loop5/Eq | equivalent | incomplete_unwind |
| REVE/nestedwhile/Eq | equivalent | unknown |
| REVE/simpleloop/Eq | equivalent | equivalent |
| REVE/whileif/Eq | equivalent | incomplete_unwind |

## Exclusions and labels

See `audit.json` for every included/excluded record, its original
metadata, source hashes and exclusion reason. Common exclusions are
includes, helper functions, unsupported types and missing metadata.
`cases/` preserves the symbolic-stage result, generated ESBMC C
harness, command line, constraints, output and final verdict.

[Upstream issue #15](https://github.com/shrBadihi/EqBench/issues/15)
reports disputed labels related to logic, signed overflow and NaN
semantics. This is an external report, not our own discovery. No
labels have been changed, and the present run does not evaluate
those reported cases.

Reproduce with `python run_eqbench.py --limit 14 --timeout-ms 3000
--max-unroll 32`, then `python write_eqbench_report.py` using the
project virtual environment.
