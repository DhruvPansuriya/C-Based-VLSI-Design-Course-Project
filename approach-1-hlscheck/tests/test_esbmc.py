from pathlib import Path

import pytest

from hlscheck.checker import Unsupported
from hlscheck.esbmc_backend import classify_log, make_harness, run_esbmc


EXE = Path(__file__).resolve().parents[1] / "tools/esbmc-v8.7/release/bin/esbmc.exe"


def test_no_success_from_exit_code_alone():
    assert classify_log("compiler error", 0) != "equivalent"


def test_failure_classification():
    assert classify_log("FAILED [f.unwinding.1] unwinding assertion\nVERIFICATION FAILED", 1) == "incomplete_unwind"
    assert classify_log("FAILED [f.array-bounds.1] out of bounds\nVERIFICATION FAILED", 1) == "safety_violation"
    assert classify_log("Violated property:\nEQUIV:return\nVERIFICATION FAILED", 1) == "not_equivalent"


def test_harness_matches_inputs_and_separates_memories():
    code, _ = make_harness("void f(unsigned a[4]){a[0]=1u;}", "void f(unsigned b[4]){b[0]=1u;}")
    assert "original_arg_0[4]" in code and "candidate_arg_0[4]" in code
    assert "original_arg_0[seed_0] = value" in code and "candidate_arg_0[seed_0] = value" in code


def test_empty_precondition_rejected():
    source = "unsigned f(unsigned n){return n;}"
    with pytest.raises(Unsupported):
        make_harness(source, source, scalar_ranges={"n": [8, 2]})


def test_calls_not_silently_abstracted():
    source = "unsigned f(unsigned n){return f(n); }"
    with pytest.raises(Unsupported):
        make_harness(source, source)


def test_persistent_state_not_silently_initialized_once():
    source = "unsigned f(unsigned n){static unsigned state=0u;return state++;}"
    with pytest.raises(Unsupported):
        make_harness(source, source)


@pytest.mark.skipif(not EXE.exists(), reason="ESBMC binary unavailable")
@pytest.mark.parametrize("a,b,options,expected", [
    ("unsigned f(unsigned x){return x*8u;}", "unsigned f(unsigned x){return x<<3;}", {}, "equivalent"),
    ("unsigned f(unsigned x){return x*8u;}", "unsigned f(unsigned x){return x<<2;}", {}, "not_equivalent"),
    ("unsigned f(unsigned x){return x;}", "unsigned f(unsigned x){return x<<32;}", {}, "safety_violation"),
    ("unsigned f(unsigned x){return x;}", "unsigned f(unsigned x){unsigned y;return y;}", {}, "safety_violation"),
    ("unsigned f(unsigned x){return x;}", "unsigned f(unsigned x){return x;}", {"unwind":1}, "equivalent"),
    ("void f(unsigned a[4]){for(int i=0;i<4;i++) a[i]=0u;}",
     "void f(unsigned a[4]){for(int i=0;i<4;i++) a[i]=0u;}", {"unwind":1}, "incomplete_unwind"),
    ("unsigned f(unsigned a[8],unsigned n){unsigned s=0u;for(unsigned i=0u;i<n;i++)s+=a[i];return s;}",
     "unsigned f(unsigned a[8],unsigned n){unsigned s=0u;for(unsigned i=0u;i<n;i++)s+=a[i];return s;}",
     {"scalar_ranges":{"n":[0,8]}}, "equivalent"),
])
def test_real_verifier(a, b, options, expected, tmp_path):
    result = run_esbmc(a, b, output_dir=tmp_path, **options)
    log = (tmp_path / "esbmc.log").read_text() if (tmp_path / "esbmc.log").exists() else str(result)
    assert result["status"] == expected, log
