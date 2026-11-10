"""End-to-end golden test: runs real CBMC (skipped if CBMC is not installed)."""
import subprocess
import json
import sys
from pathlib import Path

import pytest

from vwe.tools import cbmc

ROOT = Path(__file__).resolve().parent.parent


@pytest.mark.skipif(not cbmc.cbmc_available(), reason="cbmc not on PATH")
def test_golden_examples_match_expected(tmp_path):
    r = subprocess.run([sys.executable, str(ROOT / "scripts/run_golden_examples.py"), "--out", str(tmp_path), "--task", "ex3_avg_half_away"],
                       capture_output=True, text=True, timeout=1800)
    assert r.returncode == 0, r.stdout + r.stderr
    rows = json.loads((tmp_path / "golden_results.json").read_text())["rows"]
    assert len(rows) == 3 and all(row["match"] for row in rows)
    assert {row["example"] for row in rows} == {"ex3_avg_half_away"}
