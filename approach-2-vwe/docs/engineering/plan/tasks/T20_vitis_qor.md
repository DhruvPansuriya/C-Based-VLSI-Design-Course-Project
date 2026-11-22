# T20 — Vitis HLS QoR scripts

**Priority:** nice · **Depends on:** T19 · **Effort:** about 1 day · **Needs:** a machine with AMD Vitis HLS installed and licensed

## First: verify the CLI (OPEN_QUESTIONS Q1)

The exact command for the installed version must be checked on the target machine before anything is written. Run `vitis-run --help` and `vitis_hls -help` (one of them will exist, depending on the version). Record the outputs and the version in `docs/technical-design/03_links_versions_and_verification_log.md`. **Do not write scripts from memory.**

## Steps

1. `hls/run_csynth.tcl` (or the Python-config equivalent for newer versions), parameterised by top function, part and clock.
2. `scripts/qor.py <task> --candidate c`: run synthesis for `P0`, `P_ref` and the candidate; parse the report (latency, II, LUT, FF, DSP, BRAM) into `results/qor/<task>.json`.
3. **QoR is reported, never decisive:** it is shown next to the verdict as "QoR delta vs P0". A REJECT is never caused by QoR alone.
4. If Vitis is absent, `scripts/qor.py` exits with code 3 and the message "Vitis not found" (CI treats this as skipped).

## Acceptance criteria

On a Vitis machine: `python scripts/qor.py ex1_saturate --candidate v1` writes a JSON with all six fields. On other machines it exits with code 3.
