import pytest
import z3

from hlscheck import check_equivalence


def check(a, b=None, **kwargs):
    return check_equivalence(a, b or a, **kwargs)


def scalar(expression):
    return f"unsigned kernel(unsigned x, unsigned y) {{ return {expression}; }}"


@pytest.mark.parametrize("a,b", [
    ("x * 8u", "x << 3"),
    ("x / 8u", "x >> 3"),
    ("x % 8u", "x & 7u"),
    ("(x + y) - y", "x"),
    ("x * 0xffffffffu + y", "y - x"),
    ("x < y ? x : y", "y > x ? x : y"),
    ("(x & y) | (x & ~y)", "x"),
])
def test_unsigned_equivalences(a, b):
    assert check(scalar(a), scalar(b))["status"] == "equivalent"


def test_counterexample_replays_mathematically():
    r = check(scalar("x / 8u"), scalar("x >> 2"))
    assert r["status"] == "not_equivalent"
    x = r["counterexample"]["x"]
    assert x // 8 != x >> 2


def test_unsigned_comparison_high_bit():
    r = check(scalar("x > 0x7fffffffu"), scalar("0u"))
    assert r["status"] == "not_equivalent"
    assert r["counterexample"]["x"] >= 2**31


def test_branches_and_early_returns():
    a = "unsigned f(unsigned x){if (x < 10u) return x+1u; return x-1u;}"
    b = "unsigned f(unsigned y){return y < 10u ? y+1u : y-1u;}"
    assert check(a, b)["status"] == "equivalent"


def test_array_and_fully_unrolled_loop():
    a = "void f(unsigned a[4],unsigned b[4]){for(int i=0;i<4;i++){b[i]=a[i]*8u;}}"
    b = "void f(unsigned a[4],unsigned b[4]){b[0]=a[0]<<3;b[1]=a[1]<<3;b[2]=a[2]<<3;b[3]=a[3]<<3;}"
    assert check(a, b)["status"] == "equivalent"
    bad = b.replace("b[3]=a[3]<<3", "b[3]=a[2]<<3")
    r = check(a, bad)
    assert r["status"] == "not_equivalent"
    a_input = r["counterexample"]["a"]
    assert (a_input[2] * 8) % 2**32 != (a_input[3] * 8) % 2**32


def test_parameter_array_mutations_are_observable():
    a = "unsigned f(unsigned a[2]){return a[0];}"
    b = "unsigned f(unsigned a[2]){a[1]=0u;return a[0];}"
    assert check(a, b)["status"] == "not_equivalent"


def test_block_local_lifetime_inside_loop():
    a = "unsigned f(unsigned a[4]){unsigned s=0u;for(int i=0;i<4;i++){unsigned t=a[i]+1u;s+=t;}return s;}"
    b = "unsigned f(unsigned a[4]){return a[0]+a[1]+a[2]+a[3]+4u;}"
    assert check(a, b)["status"] == "equivalent"


@pytest.mark.parametrize("source,expected", [
    ("unsigned f(unsigned x){return x << 32;}", "source_undefined"),
    ("unsigned f(unsigned x){return 5u / x;}", "source_undefined"),
    ("unsigned f(unsigned a[2]){return a[2];}", "source_undefined"),
    ("unsigned f(unsigned a[2]){a[2]=1u;return 0u;}", "source_undefined"),
    ("unsigned f(int x){return x;}", "unsupported"),
    ("unsigned f(unsigned x){unsigned a;return a;}", "unsupported"),
    ("unsigned f(unsigned x){for(unsigned i=0u;i<x;i++){} return x;}", "unsupported"),
    ("unsigned f(unsigned *x){return x[0];}", "unsupported"),
    ("unsigned g;unsigned f(unsigned x){return x;}", "unsupported"),
    ("unsigned f(unsigned x){static unsigned s=0u;return s;}", "unsupported"),
    ("unsigned f(unsigned x){return (x < 1u) - 1 < 0;}", "unsupported"),
    ("unsigned f(unsigned x){return (x ? -1 : 1) < 0;}", "unsupported"),
])
def test_reject_unsafe_or_unsupported(source, expected):
    assert check(source)["status"] == expected


def test_candidate_undefined_is_distinct():
    assert check(scalar("x"), scalar("x / y"))["status"] == "candidate_undefined"


def test_short_circuit_guards_division():
    source = scalar("y != 0u && x / y > 2u")
    assert check(source)["status"] == "equivalent"


def test_guarded_division_in_branch():
    source = "unsigned f(unsigned x){if(x != 0u) return 5u/x;return 0u;}"
    assert check(source)["status"] == "equivalent"


def test_guarded_division_in_ternary():
    assert check(scalar("y != 0u ? x / y : 0u"))["status"] == "equivalent"


def test_loop_limit_is_not_a_partial_proof():
    source = "unsigned f(unsigned x){for(int i=0;i<8;i++){x+=1u;}return x;}"
    assert check(source, max_unroll=4)["status"] == "unsupported"
    assert check(source, max_unroll=8)["status"] == "equivalent"


def test_signature_mismatch():
    assert check("void f(unsigned a[2]){}", "void f(unsigned a[3]){}")["status"] == "unsupported"


def test_exported_smt_is_replayable(tmp_path):
    destination = tmp_path / "proof.smt2"
    r = check(scalar("x*8u"), scalar("x<<3"), smt_path=destination)
    solver = z3.Solver()
    solver.from_file(str(destination))
    assert r["status"] == "equivalent"
    assert solver.check() == z3.unsat
