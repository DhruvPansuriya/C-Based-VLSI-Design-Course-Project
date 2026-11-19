"""The public pipeline produces valid reports and matches the draft fixtures."""
from concurrent.futures import ThreadPoolExecutor
import json

from vwe.pipeline import verify
from vwe.schemas import validate
from .test_harness_equivalence import CASES
from .test_harness_generator import EXAMPLES, REAL


@REAL
def test_reports_for_all_golden_candidates(tmp_path):
    def check(case):
        task, variant, want = case
        report = verify(EXAMPLES / task, f"v{variant}", runs_root=tmp_path, parallel=False)
        assert [report.decision, report.evidence_class] == want, report.data
        validate("verdict_report", report.data)
        assert report.folder.joinpath("report.html").is_file()
        manifest = json.loads(report.folder.joinpath("run_manifest.json").read_text())
        assert manifest["interpretation_set_sha256"] == report.data["interpretation_set_sha256"]
        if (task, variant) == ("ex2_argmax", 2):
            witness = report.data["witness"]
            assert int(witness["inputs"]["n"]) >= 2
            assert witness["p0_output"]["idx[0]"] != witness["p1_output"]["idx[0]"]
        if want[0] == "ACCEPT":
            assert report.data["facts"]["synthesis_ready"] == "inconclusive"
            assert report.data["scope"]["native_acceptance"].startswith("confirmed:"), report.data
        if want[0] == "REJECT":
            assert report.data["witness"]["replayed_natively"], report.data
            assert all(r["status"] == "confirmed" for r in report.data["scope"]["native_replay"])

    with ThreadPoolExecutor(max_workers=3) as workers:
        list(workers.map(check, CASES))
