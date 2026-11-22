"""Execute generated jobs and report bounded solver outcomes.

A PROVED result here records checked properties. Callers must still discharge
the bundle prerequisites before using it as evidence for a verdict.
"""
from __future__ import annotations

from collections import Counter
from concurrent.futures import ProcessPoolExecutor
from concurrent.futures.process import BrokenProcessPool
from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path
from typing import Callable, Mapping

from .config import Config
from .harness.model import HarnessBundle
from .obligations import classify
from .tools import cbmc, goto
from .verdict import Obligation, Outcome

Selector = Callable[[cbmc.PropertyResult], bool]


@dataclass(frozen=True)
class JobResult:
    obligation: Obligation
    instrumentation: goto.PreparedGoto
    runs: Mapping[str, cbmc.CbmcRun]


def _solve(path: Path, backend: str, unwind: int, watch: tuple[str, ...],
           timeout: int) -> cbmc.CbmcRun:
    # Library models were linked before trap insertion. Reloading the library
    # after the audit would introduce unanalyzed code.
    return cbmc.run([str(path)], backend=backend, unwind=unwind, watch=watch,
                    extra=("--no-library",), timeout_s=timeout, cwd=str(path.parent))


def _record_run(out: Path, backend: str, run: cbmc.CbmcRun) -> None:
    (out / f"{backend}.json").write_text(run.stdout)
    (out / f"{backend}.command.json").write_text(json.dumps({
        "command": run.command, "status": run.status, "returncode": run.returncode,
        "seconds": run.seconds, "stderr_tail": run.stderr_tail,
    }, indent=2) + "\n")


def _candidate_check(prop: cbmc.PropertyResult, owners: frozenset[str]) -> bool:
    return (prop.property_id.split(".", 1)[0] in owners
            and (".assertion." not in prop.property_id))


def _labels_ok(runs: Mapping[str, cbmc.CbmcRun], labels: tuple[str, ...]) -> bool:
    expected = Counter(labels)
    return all(
        Counter(p.description for p in run.properties
                if p.property_id.startswith("main.assertion.") and p.description.startswith("VWE."))
        == expected for run in runs.values()
    )


def check_vacuity(runs: Mapping[str, cbmc.CbmcRun], labels: tuple[str, ...], *,
                  proven_empty: frozenset[str] = frozenset()) -> Obligation:
    """Each required probe must fire. An empty-region exception requires a proof.

    Use `proven_empty` only for labels proved unreachable in a separate,
    call-free feasibility query on the same exact profile and input predicate.
    """
    probes = frozenset(label for label in labels if label.startswith("VWE.vacuity."))
    if not probes or not proven_empty <= probes or probes == proven_empty:
        return Obligation(Outcome.INCONCLUSIVE, note="no nonempty planned vacuity probe")
    if not _labels_ok(runs, labels):
        return Obligation(Outcome.INCONCLUSIVE, note="vacuity property inventory mismatch")
    result, _ = classify(runs, lambda p: p.description in probes, "vacuity")
    if result.outcome is Outcome.INCONCLUSIVE:
        return result
    for run in runs.values():
        for prop in run.properties:
            if prop.description in probes:
                expected = "SUCCESS" if prop.description in proven_empty else "FAILURE"
                if prop.status != expected:
                    return Obligation(Outcome.INCONCLUSIVE, note=f"vacuous: {prop.description}")
    return Obligation(Outcome.PROVED, note="all required regions reached after the call")


def run_job(bundle: HarnessBundle, *, config: Config | None = None,
            selector: Selector | None = None,
            proven_empty: frozenset[str] = frozenset(),
            parallel: bool = True) -> JobResult:
    cfg = config or Config()
    out = bundle.folder / "verification"
    if bundle.entry_point != "main":
        p = goto.PreparedGoto(None, None, (), (), "unsupported entry point")
    else:
        p = goto.prepare(bundle.files, out, timeout_s=cfg.timeouts.cbmc_s)
    if not p.ok or p.artifact is None:
        return JobResult(Obligation(Outcome.INCONCLUSIVE, note=p.reason), p, {})
    if sha256(p.artifact.read_bytes()).hexdigest() != p.sha256:
        return JobResult(Obligation(Outcome.INCONCLUSIVE, note="GOTO artifact changed"), p, {})
    fixed = (p.artifact, bundle.unwind, bundle.watch, cfg.timeouts.cbmc_s)
    backends = ("sat", "z3")
    if parallel:
        try:
            with ProcessPoolExecutor(max_workers=len(backends)) as pool:
                futures = {b: pool.submit(_solve, fixed[0], b, *fixed[1:]) for b in backends}
                runs = {b: future.result() for b, future in futures.items()}
        except BrokenProcessPool as exc:
            return JobResult(Obligation(Outcome.INCONCLUSIVE, note=f"solver worker failed: {exc}"), p, {})
    else:
        runs = {b: _solve(fixed[0], b, *fixed[1:]) for b in backends}
    for b, result in runs.items():
        _record_run(out, b, result)
    if any(not run.ok for run in runs.values()):
        failed = ", ".join(b for b, run in runs.items() if not run.ok)
        return JobResult(Obligation(Outcome.INCONCLUSIVE, note=f"tool error: {failed}"), p, runs)
    if not _labels_ok(runs, bundle.property_labels):
        return JobResult(Obligation(Outcome.INCONCLUSIVE, note="planned assertion inventory mismatch"), p, runs)
    if bundle.kind == "vacuity":
        return JobResult(check_vacuity(runs, bundle.property_labels, proven_empty=proven_empty), p, runs)

    def selected(prop: cbmc.PropertyResult) -> bool:
        if selector is not None:
            return selector(prop)
        if bundle.kind == "e0":
            if _candidate_check(prop, frozenset(bundle.program_symbols[1])):
                return True
            return (prop.property_id.split(".", 1)[0] in p.trapped
                    and prop.description == "undefined function should be unreachable")
        if bundle.kind == "validation_bug":
            return prop.description == "VWE.validation_bug.predicate" or _candidate_check(
                prop, frozenset(bundle.program_symbols[0]))
        if bundle.kind.startswith("validation_"):
            return prop.description == f"VWE.{bundle.kind}.predicate"
        if bundle.kind == "reference_safety":
            return prop.description == "VWE.reference_safety.completed" or _candidate_check(
                prop, frozenset(bundle.program_symbols[0]))
        if bundle.kind in {"feasibility", "input_rule"}:
            return prop.description == f"VWE.{bundle.kind}.predicate"
        if bundle.kind == "class":
            return prop.description.startswith("VWE.class.") or _candidate_check(
                prop, frozenset(bundle.program_symbols[1]))
        if bundle.kind == "contract_ub":
            return prop.property_id.startswith("vwe_observer_") or prop.description == "VWE.contract.evaluated"
        if bundle.kind == "scope":
            return prop.description == "VWE.scope.agreement"
        if bundle.kind == "e1":
            return prop.description == "VWE.E1.preservation"
        return prop.description == "VWE." + bundle.kind + ".equivalence"

    # A user-program trap, observation support issue, or instrumentation
    # disagreement in a different role makes this result inconclusive.
    obligation, _ = classify(runs, selected, bundle.kind, allow_empty=bundle.kind == "e0",
                             independent_safety_refutation=bundle.kind in {"e0", "reference_safety",
                                                                          "contract_ub"})
    return JobResult(obligation, p, runs)
