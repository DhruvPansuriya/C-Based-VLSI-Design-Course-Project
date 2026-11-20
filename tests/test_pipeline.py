"""The public pipeline produces valid reports and matches the draft fixtures."""
from concurrent.futures import ThreadPoolExecutor
import json

from vwe.pipeline import verify
from vwe.schemas import validate
from .test_harness_equivalence import EXPECTED
from .test_harness_generator import EXAMPLES, REAL

CASES = [(name, int(i), want) for name, variants in EXPECTED.items()
         if not name.startswith("_") for i, want in variants.items()]


@REAL
def test_reports_for_all_golden_candidates(tmp_path):
    def check(case):
        task, variant, want = case
        report = verify(EXAMPLES / task, f"v{variant}", runs_root=tmp_path, parallel=False)
        assert [report.decision, report.evidence_class] == want, report.data
        validate("verdict_report", report.data)
        assert all(i["validation"] in {"valid", "invalid"} for i in report.data["interpretations"])
        assert report.folder.joinpath("report.html").is_file()
        manifest = json.loads(report.folder.joinpath("run_manifest.json").read_text())
        assert manifest["interpretation_set_sha256"] == report.data["interpretation_set_sha256"]
        if (task, variant) == ("ex2_argmax", 2):
            witness = report.data["witness"]
            assert int(witness["inputs"]["n"]) >= 2
            assert witness["p0_output"]["idx[0]"] != witness["p1_output"]["idx[0]"]
        if task == "ex3_avg_half_away" and variant == 1:
            assert "scope disagreement" in report.data["reason"]
            assert report.data["witness"]
        if task == "ex5_add32_ambiguous" and variant in (1, 2):
            assert "ambiguous" in report.data["reason"]
            assert len(report.data["facts"]["interpretations_satisfied"]) == 2
            assert len(report.data["facts"]["interpretations_violated"]) == 1
        if task == "ex6_copy_overflow":
            region = json.loads((report.folder / "regions/regions.json").read_text())
            assert region["exact_ub"] is not None
            assert region["universal_inside"]["outcome"] == "PROVED"
        if task == "ex7_build_views" and variant == 1:
            assert report.data["claim_target"] == "build_view_consistency"
        if want[0] == "ACCEPT":
            assert report.data["facts"]["synthesis_ready"] == "inconclusive"
            assert report.data["scope"]["native_acceptance"].startswith("confirmed:"), report.data
        if want[0] == "REJECT":
            assert report.data["witness"]["replayed_natively"], report.data
            assert all(r["status"] == "confirmed" for r in report.data["scope"]["native_replay"])

    with ThreadPoolExecutor(max_workers=3) as workers:
        list(workers.map(check, CASES))
