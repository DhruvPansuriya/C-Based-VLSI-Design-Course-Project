"""T18 metrics: hand-computed values and the dependence-aware design."""
from __future__ import annotations

import pytest

from vwe.eval.metrics import (POLICIES, Row, cluster_bootstrap, paired_by_task, sign_test, summary,
                              unsound_core, wilson)


def row(task, cand, decision, evidence, label, claim="repair_correctness", system="vwe"):
    return Row(system, task, cand, decision, evidence, claim if decision != "UNDECIDED" else "none", label)


def test_wilson_matches_hand_computation():
    lo, hi = wilson(8, 10)
    assert lo == pytest.approx(0.4901625, abs=1e-6) and hi == pytest.approx(0.9433178, abs=1e-6)
    assert wilson(0, 0) is None
    lo, hi = wilson(0, 5)
    assert lo == 0 and hi == pytest.approx(0.4344825, abs=1e-6)


def test_exact_sign_test():
    assert sign_test(5, 0) == pytest.approx(0.0625)      # 2 * (1/32)
    assert sign_test(3, 3) == 1.0
    assert sign_test(9, 1) == pytest.approx(2 * 11 / 1024)
    assert sign_test(0, 0) is None


def test_summary_excludes_unknown_and_separates_policy():
    rows = [row("t1", "a", "ACCEPT", "E2", "correct"), row("t1", "b", "ACCEPT", "E2", "incorrect"),
            row("t1", "c", "REJECT", "E1", "incorrect"), row("t2", "d", "UNDECIDED", "-", "correct"),
            row("t2", "e", "REJECT", "E0", "incorrect", claim="admission_policy"),
            row("t2", "f", "ACCEPT", "E2", "unknown")]
    s = summary(rows)
    assert (s["candidates"], s["labelled"], s["unknown_labels"]) == (6, 5, 1)
    assert s["decided"] == 3 and s["coverage"] == pytest.approx(3 / 5)
    assert s["accept_precision"] == 0.5 and s["reject_precision"] == 1.0
    assert s["policy_refusals"] == 1 and s["wrong"] == 1
    strict = summary(rows, policy=POLICIES["E0+E1"])
    assert strict["decided"] == 1 and strict["accept"] == 0


def test_unsound_core_flags_wrong_e0_e1_only():
    rows = [row("t", "a", "REJECT", "E1", "correct"), row("t", "b", "ACCEPT", "E2", "incorrect"),
            row("t", "c", "REJECT", "E0", "incorrect")]
    assert [r.candidate for r in unsound_core(rows)] == ["a"]


def test_paired_comparison_is_per_task_not_per_candidate():
    method = [row("t1", c, "REJECT", "E1", "incorrect") for c in "abcde"] + [row("t2", "x", "UNDECIDED", "-", "incorrect")]
    base = [row("t1", c, "ACCEPT", "-", "incorrect", system="b") for c in "abcde"] + [row("t2", "x", "REJECT", "-", "incorrect", system="b")]
    p = paired_by_task(method, base)
    # five candidate wins in t1 count as ONE task win; t2 is one task loss
    assert (p["wins"], p["losses"], p["tasks_compared"]) == (1, 1, 2)
    assert p["net_right_decisions"] == 4 and p["sign_test_p"] == 1.0
    assert p["net_wrong_decisions"] == -5 and (p["tasks_fewer_wrong"], p["tasks_more_wrong"]) == (1, 0)


def test_cluster_bootstrap_is_deterministic_and_needs_two_tasks():
    rows = [row(f"t{i}", "a", "REJECT", "E1", "incorrect" if i % 3 else "correct") for i in range(9)]
    first = cluster_bootstrap(rows, "reject_precision", resamples=300)
    assert first == cluster_bootstrap(rows, "reject_precision", resamples=300)
    assert 0 <= first[0] <= first[1] <= 1
    assert cluster_bootstrap(rows[:1], "reject_precision") is None


def test_report_writer_lists_every_wrong_decision(tmp_path):
    import importlib.util, sys
    from pathlib import Path
    spec = importlib.util.spec_from_file_location("run_eval", Path(__file__).resolve().parent.parent / "scripts/run_eval.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    rows = [row("t1", "a", "REJECT", "E1", "correct"), row("t1", "b", "ACCEPT", "E2", "correct"),
            row("t2", "c", "UNDECIDED", "-", "incorrect"), row("t2", "c", "ACCEPT", "-", "incorrect", system="tests_only"),
            row("t1", "a", "REJECT", "-", "correct", system="tests_only"), row("t1", "b", "ACCEPT", "-", "correct", system="tests_only")]
    reasons = {(r.system, r.task, r.candidate): "because" for r in rows}
    mod.write_reports(rows, reasons, {"t1": "OOB", "t2": "INIT"}, tmp_path, ["note"])
    errors = (tmp_path / "errors.md").read_text()
    assert "**vwe** t1/a: REJECT E1" in errors and "**tests_only** t2/c: ACCEPT" in errors
    summary_md = (tmp_path / "summary.md").read_text()
    assert "| vwe | 3 | 2 |" in summary_md and "fewer wrong" in summary_md
    assert "| OOB |" in summary_md
