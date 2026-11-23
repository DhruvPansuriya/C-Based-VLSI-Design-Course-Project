from hlscheck import check_equivalence


def test_ternary_uses_both_operand_types_even_for_constant_condition():
    a = "unsigned f(unsigned x){return (1 ? -1 : x) < 0;}"
    b = "unsigned f(unsigned x){return 0u;}"
    assert check_equivalence(a, b)["status"] == "equivalent"


def test_const_write_is_not_silently_accepted():
    source = "unsigned f(unsigned x){const unsigned y=x;y=0u;return y;}"
    assert check_equivalence(source, source)["status"] == "unsupported"


def test_array_self_initialization_not_assumed_zero():
    source = "unsigned f(unsigned x){unsigned a[2]={a[0],x};return a[0];}"
    assert check_equivalence(source, source)["status"] == "unsupported"


def test_malformed_code_returns_error():
    assert check_equivalence("unsigned f( {", "unsigned f( {")["status"] == "error"


def test_signed_predicate_conversion_to_unsigned():
    a = "unsigned f(unsigned x){return (unsigned)(x==0u)-1u;}"
    b = "unsigned f(unsigned x){return x==0u ? 0u : 0xffffffffu;}"
    assert check_equivalence(a, b)["status"] == "equivalent"


def test_signed_left_shift_not_modeled_as_unsigned():
    source = "unsigned f(unsigned x){return 1 << x;}"
    assert check_equivalence(source, source)["status"] == "unsupported"


def test_cannot_redefine_builtin_uint32_t():
    source = "typedef signed int uint32_t;uint32_t f(uint32_t x){return x;}"
    assert check_equivalence(source, source)["status"] == "unsupported"
