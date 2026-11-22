# Open questions (resolve by checking; never by assumption)

Record each answer here with the date, the command that was run and its output, and update the affected task.

| # | Question | How to resolve | Affects |
|---|---|---|---|
| Q1 | The exact Vitis HLS 2026.1 CLI (`vitis-run` vs `vitis_hls -f`) and its report paths | Run `--help` on the installed machine; read the bundled docs | T20, T19 Gate B |
| Q2 | Does CBMC 6.11.0 accept `__CPROVER_forall` / `__CPROVER_exists` in assertions with the SAT and Z3 backends for our contract shapes? | Write a spike in `spikes/tool_behaviour/t07_quantifiers.c` and run it on both backends | T03, T04 (otherwise expand quantifiers over bounded loops) |
| Q3 | Codeflaws data is served over an http NUS link; is it still reachable and is its checksum stable? | Try the download from the project page; if it fails, drop Codeflaws (it is optional) | T15 |
| Q4 | Should cvc5 or Bitwuzla be added as a third backend for disagreement checks? | Only if the Z3/SAT disagreement rate in T18 is above 1 %; measure first | T05 |
| Q5 | The per-program licence terms of the CHStone files (the mirror has no single licence) | Read each file header; use only files whose headers permit academic use and redistribution in the repo, otherwise fetch at runtime | T15 |
| Q6 | R26: is the FIFO structural-summary exception acceptable to the professor? | Ask during the review meeting; if not, the FIFO track uses hand-instantiated templates only | T21 |
| Q7 | Which exact LLM model IDs are available on the team's accounts? | Check the provider consoles at setup time; pin in `config/llm.toml` | T12, T13, T16 |


## Import review resolutions / required corrections — 22 November 2026

- Q6 resolved for implementation: preserve the user's no-P1-to-LLM invariant without a structural-summary exception. Use deterministic/template FIFO invariants.
- Q8: T06's two region checks prove an overapproximation, not exact B_ub; exactness requires total semantics/both inclusions. Do not ship the proposed fallback as exact.
- Q9: T07's sampled V-4 is insufficient for universal realizability; use a checked joint constructive output or a proper quantified/finite query. V-5 is informational only.
- Q10: add scope-conflict/UNKNOWN veto and profile-local, domain-aware verdict premises before the general pipeline.
- Q11: local macOS checks installed CBMC 6.11.0 (Homebrew core bottle), plus venv Z3 5.4.1.0 (binary 5.4.1). `make test`: 26 passed including golden integration. Imported Linux logs are separate evidence.
- Q12: `actionlint 1.7.12 -shellcheck= .github/workflows/ci.yml` passes locally. Hosted CI/Docker/ESBMC/Vitis still need their own runs.
- Q13: exact Python distributions installed and pinned, including referencing 0.37.0 and z3-solver 5.4.1.0. Installer SHA-256 pins were checked against official GitHub release-asset digest metadata. Base image digest and apt snapshot remain unsealed.
- Q14: the golden selector can ignore failing contract properties; reproduced as PROVED with a `main.pointer_dereference` failure. A targeted T05 prerequisite fix must precede generalization.

Details and scenarios: `docs/CLAUDE_IMPORT_REVIEW.md`.

- Q15: first hosted CI exposed rpds-py 2026.9.1 requiring Python>=3.11. Preserve advertised Python3.10 support with verified rpds-py0.30.0 under a Python<3.11 marker; pin typing_extensions4.15.0 for Python<3.13. Matrix jobs now run independently. The first run installed both Linux verification tools successfully, but did not complete tests.


## T02 frontend qualification — 22 November 2026

- Q16 resolved locally: `cbmc --preprocess --verbosity 0` suppresses its banner. The tested concatenated `-U__SYNTHESIS__` option exits64; isolated #undef/#define wrappers implement the two analysis modes. Raw commands: `results/t02/frontend-capabilities.json`.
- Q17 resolved locally: undefined-function listings include internal CPROVER prototypes. Filter them only after candidate verifier identifiers have been refused, and check reachable user calls separately. Library prototypes are audited in config/whitelist.toml; body/model qualification remains T05.
- Q18: standard headers containing GCC/Clang extensions may be unrepresentable to pycparser. Current answer is UNDECIDED, not attribute erasure. A richer parser or expanded qualified frontend profile is future work.
- Q19: general local dependency snapshots, global pointer aliasing, and source-level macro idioms outside the closed dependency profile need qualification. Current frontend abstains on unsupported forms.
- Q20: AST alpha renaming is a trusted implementation component. Scope/collision/native regression tests exist; a universal compiler-correctness proof is not claimed. Function-name introspection is excluded so renaming cannot silently change it.


## T03 contract profile — 22 November 2026

- Q21 resolved for the initial implementation: finite quantifiers lower to checked loops; no unverified solver-quantifier feature is required. Range/complexity limits are explicit UNKNOWN capabilities.
- Q22: signed64 widening is not universal UB-freedom. V-G must check overflow/division/index/old-read guards; unsigned64/full mathematical integers and __int128 remain unsupported observer profiles until qualified.
- Q23 resolved locally: generated observers agree with an independent evaluator on525 cases; a real CBMC test detects an eager exists-body OOB after an earlier true witness. These are regression/qualification evidence, not formal correctness of the translation.
