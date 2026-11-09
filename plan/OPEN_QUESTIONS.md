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
