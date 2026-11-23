# T00 — Foundations: Makefile, CI, packaging, config

**Priority:** must · **Depends on:** — · **Effort:** about 0.5 day

## Goal

One-command build and test locally and in CI, and a config file instead of hard-coded constants.

## Steps

1. **`pyproject.toml`.** Package `vwe`, Python ≥ 3.10, console script `vwe = vwe.cli:main` (the CLI itself is written in T08; create a stub that prints the version now). Dependencies come from `requirements.txt`; add `lark==1.3.1` (contract parser, T03).
2. **`Makefile`** with these targets:
   - `install` (`pip install -e .`)
   - `test` (`pytest -q tests`)
   - `golden` (`python3 scripts/run_golden_examples.py`)
   - `spikes` (`spikes/tool_behaviour/run_spikes.sh`)
   - `demo` (placeholder until T11)
   - `eval` (placeholder until T18)
   - `clean` (remove `runs/`)
3. **`vwe/config.py`** loading `config/default.toml` (use `tomllib`):
   - `[bounds] K = 4`, `max_unwind = 9`
   - `[timeouts] cbmc_s = 600`, `esbmc_s = 600`, `equiv_pair_s = 120`
   - `[backends] primary = ["sat", "z3"]`, `confirm = "esbmc"`
   - `[native] cc = "gcc"`, `sanitize = "address,undefined"`
   - `[llm]` (empty until T12)

   Expose `load_config(path=None) -> Config` (a frozen dataclass).
4. **`.github/workflows/ci.yml`:**
   - on push and pull_request, runner `ubuntu-24.04`;
   - steps: checkout → `tools/install_tools.sh` (with `PREFIX=$HOME/opt`) → add to `PATH` → `pip install -r requirements.txt && pip install -e .` → `make test`.
   - Cache the CBMC `.deb` and the ESBMC zip by version key.
5. **`vwe/__main__.py`** so that `python -m vwe --version` works.

## Acceptance criteria

```bash
make install && make test          # all existing tests pass (11 at the time of writing)
python -m vwe --version            # prints 0.1.0
python -c "from vwe.config import load_config; c=load_config(); assert c.bounds.K == 4"
```

CI runs green on a pushed branch, or, if GitHub Actions is unavailable, the workflow file passes `actionlint` (record which in `plan/OPEN_QUESTIONS.md`).

## Pitfalls

- `tools/install_tools.sh` installs CBMC by **extracting** the `.deb` (`dpkg -x`). `dpkg -i` failed in the reference environment because of an unmet `bash-completion` dependency.
- `pip` on Ubuntu 24.04 needs `--break-system-packages` outside a virtualenv. Prefer a venv in CI.
