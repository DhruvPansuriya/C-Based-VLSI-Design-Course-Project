# Part C — External links, versions and verification log

Checked on 22 November 2026, from an Ubuntu 24.04.5 container.

**Methods:**

- **git** = `git ls-remote` / shallow clone of the repository succeeded;
- **dl** = binary downloaded and executed;
- **pypi** = installed from PyPI;
- **web** = page fetched and read;
- **docs** = official documentation page (cited in the research draft).

## Tools

| Item | Link | Version used | Verified how | Status |
|---|---|---|---|---|
| CBMC | https://github.com/diffblue/cbmc (release asset `ubuntu-24.04-cbmc-6.11.0-Linux.deb`) | 6.11.0 (latest tag `cbmc-6.11.0`) | dl, ran `cbmc --version`, all spikes | verified |
| CBMC documentation | https://diffblue.github.io/cbmc/ | — | web/docs | verified |
| CBMC flags used | `cbmc --help`, `goto-instrument --help` (6.11.0) | — | grep of help output: `--no-self-loops-to-assumptions`, `--unwinding-assertions`, `--no-malloc-may-fail`, `--z3`, `--incremental-smt2-solver`, `--cvc5`, `--bitwuzla`, `--list-undefined-functions`, `--generate-function-body(-options)`, `--uninitialized-check`, `--apply-loop-contracts`, `--nondet-static` | verified |
| ESBMC | https://github.com/esbmc/esbmc (release v8.7, asset `esbmc-linux.zip`) | 8.7.0 (bundles Z3 4.13.3) | dl, ran spikes | verified |
| Z3 | https://github.com/Z3Prover/z3, PyPI `z3-solver` | 5.4.1 (latest tag `z3-5.4.1`) | pypi, `z3` executable used by CBMC | verified |
| GCC | Ubuntu 24.04 package | 13.3.0 | ASan/UBSan replay ran | verified |
| Clang | Ubuntu 24.04 package | 18.1.3 | sanitizer runtime missing in this environment | verified (not used) |
| Python packages | PyPI | jsonschema 4.26.0, pycparser 3.0, pytest 9.1.1 | installed | verified |
| AMD Vitis HLS user guide | https://docs.amd.com/r/en-US/ug1399-vitis-hls | 2026.1 pages (release date 2026-06-23); System Calls page 2025.2 | docs (draft refs) | verified (docs); CLI on the installed tool **unverified** |
| cvc5 / Bitwuzla binaries | — | — | not installed | unverified |

## Benchmarks

| Item | Link | Verified how | Notes |
|---|---|---|---|
| Chrysalis-HLS | https://github.com/UIUC-ChenLab/Chrysalis-HLS | git (shallow clone, about 104 MB) | Apache-2.0; bug files are JSON (`Error Type`, `Original Code`, `Faulty Code`) |
| CHStone (mirror) | https://github.com/ferrandi/CHStone | git | README states CHStone v1.11 and per-program copyright |
| MachSuite | https://github.com/breagen/MachSuite | git | LICENSE present |
| PolyBench/C 4.2.1 (mirror) | https://github.com/MatthiasJReisinger/PolyBenchC-4.2.1 | git | mostly floating point |
| IntroClass | https://github.com/ProgramRepair/IntroClass ; http://repairbenchmarks.cs.umass.edu/ | git (about 2.2 GB) | BSD-style LICENSE |
| BugZoo (ManyBugs runner) | https://github.com/squaresLab/BugZoo | git | optional |
| Codeflaws | https://github.com/codeflaws/codeflaws | git | MIT; data tarball at http://www.comp.nus.edu.sg/~release/codeflaws/codeflaws.tar.gz (http link from README; **not downloaded**) |
| Mastora & Sullivan benchmark | https://arxiv.org/abs/2610.03971 | web | no artifact link on the abstract page |

## Spike and golden-run logs (in this repository)

- `results/tool_behaviour/spikes_cbmc-6.11.0_esbmc-8.7.0.log`: T01–T06 outputs.
- `results/golden/golden_run.log` and `results/golden/golden_results.json`: Examples 1, 2, 4 (10 candidates), with SAT/Z3 agreement and side checks.
