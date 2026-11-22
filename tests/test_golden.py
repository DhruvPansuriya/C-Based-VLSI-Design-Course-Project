"""End-to-end golden test: runs real CBMC (skipped if CBMC is not installed)."""
import subprocess
import sys
from pathlib import Path

import pytest

from vwe.tools import cbmc

ROOT = Path(__file__).resolve().parent.parent


@pytest.mark.skipif(not cbmc.cbmc_available(), reason="cbmc not on PATH")
def test_golden_examples_match_expected(tmp_path):
    r = subprocess.run([sys.executable, str(ROOT / "scripts/run_golden_examples.py"), "--out", str(tmp_path)],
                       capture_output=True, text=True, timeout=1800)
    assert r.returncode == 0, r.stdout + r.stderr
