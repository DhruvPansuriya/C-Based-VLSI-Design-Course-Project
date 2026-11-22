"""T15: adapted benchmark tasks validate, keep provenance and P_ref is never REJECTed."""
from __future__ import annotations

import json
from pathlib import Path
import sys

import pytest

from vwe.tasks import load_full, load_pipeline_view

ROOT = Path(__file__).resolve().parent.parent
TASKS = ROOT / "evaluation/benchmarks/tasks"
LOG = json.loads((ROOT / "evaluation/benchmarks/adaptation_log.json").read_text())
if not TASKS.is_dir():
    pytest.skip("benchmark tasks are generated, not committed: run scripts/fetch_benchmarks.py "
                "and scripts/adapt_chrysalis.py", allow_module_level=True)
DIRS = sorted(p for p in TASKS.iterdir() if (p / "task.json").is_file())
sys.path.insert(0, str(ROOT / "scripts"))
from check_benchmark_refs import task_hash  # noqa: E402


def test_at_least_twenty_tasks_and_log_matches():
    assert len(DIRS) >= 20
    assert {r["task_id"] for r in LOG["selected"]} == {p.name for p in DIRS}


@pytest.mark.parametrize("root", DIRS, ids=lambda p: p.name)
def test_task_validates_with_provenance(root):
    full = load_full(root)
    pipe = load_pipeline_view(root)
    assert full.eval_only.p_ref.sha256 != pipe.p0.sha256, "P0 must differ from P_ref"
    manifest = json.loads((root / "task.json").read_text())
    src = manifest["source"]
    assert src["suite"] == "Chrysalis-HLS" and LOG["commit"] in src["origin"]
    assert any(a.startswith("applied documented") for a in src["adaptations"])
    assert all(r["origin"] == "agent_template" for r in manifest["requests"])  # honest authorship label
    assert pipe.candidates["ref"].source.text == full.eval_only.p_ref.text


def test_regenerated_tasks_match_committed_hashes_and_never_reject():
    """Determinism + P_ref check: regenerated files must hash to the recorded evidence."""
    path = ROOT / "evaluation/benchmarks/ref_check.json"
    if not path.is_file():
        pytest.skip("P_ref check evidence not recorded yet (scripts/check_benchmark_refs.py)")
    evidence = json.loads(path.read_text())
    rows = {r["task_id"]: r for r in evidence["rows"]}
    for root in DIRS:
        row = rows[root.name]
        assert row["task_sha256"] == task_hash(root), f"{root.name}: regenerated task differs from the recorded evidence"
        assert row["decision"] != "REJECT", f"{root.name}: P_ref rejected: {row['reason']}"
