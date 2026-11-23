from pathlib import Path

import pytest

from hlscheck.pipeline import check_with_fallback


def test_no_external_tool_needed_for_supported_pair(tmp_path):
    a = "unsigned f(unsigned x){return x*8u;}"
    b = "unsigned f(unsigned x){return x<<3;}"
    result = check_with_fallback(a, b, output_dir=tmp_path)
    assert result["status"] == "equivalent"
    assert not result["fallback_used"]


@pytest.mark.skipif(not (Path(__file__).resolve().parents[1] / "tools/esbmc-v8.7/release/bin/esbmc.exe").exists(), reason="ESBMC unavailable")
def test_symbolic_index_falls_back_to_real_verifier(tmp_path):
    a = "unsigned f(unsigned a[8],unsigned i){return a[i&7u];}"
    b = "unsigned f(unsigned a[8],unsigned i){return a[i%8u];}"
    result = check_with_fallback(a, b, output_dir=tmp_path)
    assert result["initial_stage"]["status"] == "unsupported"
    assert result["status"] == "equivalent"
    assert result["fallback_used"]
    assert "Z3" in result["solver_report"]
