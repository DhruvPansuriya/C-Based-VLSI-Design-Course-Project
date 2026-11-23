#!/usr/bin/env bash
# Re-runs the tool-behaviour spikes T01-T06 and prints the decisive lines.
# Expected outcomes are documented in spikes/tool_behaviour/README.md.
set -u
cd "$(dirname "$0")"
r(){ echo "### $*"; "$@" 2>&1 | grep -E "VERIFICATION|FAILURE|\*\* [0-9]+ of|no unwinding assertion" | head -8; echo; }
cbmc --version
r cbmc t01_while1/harness.c --unwind 3
r cbmc t01_while1/harness.c --unwind 3 --unwinding-assertions --no-self-loops-to-assumptions
r cbmc t02_bodyless/harness.c
r cbmc t03_abort/harness.c
goto-cc t03_abort/harness.c -o /tmp/t03.gb
goto-instrument /tmp/t03.gb /tmp/t03b.gb --generate-function-body 'abort' --generate-function-body-options assert-false-assume-false >/dev/null 2>&1
r cbmc /tmp/t03b.gb
r cbmc t04_buffer_size/fixed.c --unwind 9 --unwinding-assertions --no-malloc-may-fail
r cbmc t04_buffer_size/exact.c --unwind 9 --unwinding-assertions --no-malloc-may-fail
r cbmc t04_buffer_size/exact.c --unwind 9 --unwinding-assertions
r cbmc t05_uninit/harness.c
r cbmc t06_build_views/p1b.c t06_build_views/harness.c
r cbmc -D__SYNTHESIS__ t06_build_views/p1b.c t06_build_views/harness.c
if command -v esbmc >/dev/null; then
  esbmc --version | head -1
  r esbmc t01_while1/harness.c --unwind 3
  r esbmc t03_abort/harness.c
  r esbmc t04_buffer_size/exact.c --unwind 9 --z3
fi
