from pathlib import Path

import pytest

from hlscheck import check_equivalence


@pytest.mark.parametrize("family", ["scale", "unswitch"])
def test_demo_valid_and_invalid(family):
    directory = Path(__file__).resolve().parents[1] / "benchmarks" / "demo"
    original = (directory / f"{family}_original.c").read_text()
    for suffix, expected in (("optimized", "equivalent"), ("buggy", "not_equivalent")):
        candidate = (directory / f"{family}_{suffix}.c").read_text()
        assert check_equivalence(original, candidate, "kernel")["status"] == expected
