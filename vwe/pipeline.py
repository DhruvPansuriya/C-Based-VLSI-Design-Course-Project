"""Deterministic orchestration for the bounded handwritten interpretation track."""
from __future__ import annotations

from dataclasses import asdict
from datetime import datetime, timezone
from hashlib import sha256
from pathlib import Path
from time import monotonic
from uuid import uuid4

from .admission import admit
from .config import Config, load_config
from .contract.ast import ContractTypeError, ContractUnsupported, GrammarError, LoweringError
from .harness.generate import Generator
from .harness.layout import HarnessUnsupported
from .harness.model import HarnessBundle
from .harness.profile import plain
from .proof_jobs import JobResult, run_job
from .regions import compute_regions
from .report import VerdictReport, write_json
from .replay import NativeSession, bind_inputs
from .tasks import TaskError, load_pipeline_view
from .tools import cbmc, esbmc
from .tools.frontend import execute
from .validate import FrozenSet, canonical, freeze_interpretations
from .verdict import Evidence, Obligation, Outcome, Verdict, decide


def _unknown(reason: str, witness: dict[str, str] | None = None) -> Verdict:
    return Verdict("UNDECIDED", "-", reason, witness, claim_target="none")


def _version(tool: str, folder: Path) -> str:
    result = execute([tool, "--version"], cwd=folder, timeout_s=10)
    return (result.stdout or result.stderr).strip().splitlines()[0] if result.ok and (
        result.stdout.strip() or result.stderr.strip()) else "unavailable"


def _conditional(verdict: Verdict) -> str:
    if verdict.claim_target == "admission_policy":
        return "The candidate violates the documented admission policy for this verifier."
    if verdict.claim_target == "build_view_consistency":
        return "The recorded input distinguishes the two build views under the declared caller profile."
    if verdict.decision == "UNDECIDED":
        return "The recorded evidence does not establish a repair verdict on the declared profile."
    if verdict.evidence_class == "E0":
        return ("The recorded input belongs to the exact caller profile and the certified "
                "safe and deterministic reference guard. The candidate violates a modeled check there.")
    if verdict.evidence_class == "E1":
        return ("Within the declared caller profile, the witness lies outside the validated "
                "scope union and its change is rejected by every surviving extended relation.")
    premise = ("The claim is bounded to the declared input profile, instrumented C checks, "
               "and reported unwind bounds. It also requires an adequate reading of the request.")
    if verdict.decision == "ACCEPT":
        return premise + " Acceptance requires at least one surviving interpretation that is sound for the intended repair."
    return premise + " Rejection requires at least one surviving interpretation complete for the intended repair."


def _witness(trace: dict[str, str] | None, names: dict[str, str]) -> dict | None:
    if not trace:
        return None
    return {
        "inputs": {names.get(k, k): v for k, v in trace.items() if not k.startswith("__vwe_out_")},
        "p0_output": {k.removeprefix("__vwe_out_zero_"): v for k, v in trace.items()
                      if k.startswith("__vwe_out_zero_")} or None,
        "p1_output": {k.removeprefix("__vwe_out_one_"): v for k, v in trace.items()
                      if k.startswith("__vwe_out_one_")} or None,
        "replayed_natively": False,
    }


def verify(task_dir: str | Path, candidate_id: str, cfg: Config | None = None,
           interpretations: str = "handwritten", *, runs_root: Path = Path("runs"),
           parallel: bool = True) -> VerdictReport:
    cfg = cfg or load_config()
    started = monotonic()
    task = load_pipeline_view(task_dir)
    if candidate_id not in task.candidates:
        raise TaskError(f"Unknown candidate {candidate_id!r}")
    if task.task_id in {".", ".."} or candidate_id in {".", ".."}:
        raise TaskError("Dot path components cannot be run identifiers")
    root = runs_root.resolve()
    out = (root / task.task_id / candidate_id / uuid4().hex).resolve()
    if not out.is_relative_to(root):
        raise TaskError("Run directory escapes the configured root")
    out.mkdir(parents=True, exist_ok=False)
    facts: dict = {"preserves_outside_B_max": "inconclusive", "synthesis_ready": "inconclusive",
                   "interpretations_satisfied": [], "interpretations_violated": []}
    queries = []
    frozen: FrozenSet | None = None
    class_status: dict[str, str] = {}
    witness_names: dict[str, str] = {}
    reference_guard: str | None = None
    change_brackets: dict[str, str] = {}
    native_session: NativeSession | None = None
    replay_results: list[dict[str, str]] = []
    samples_checked = 0
    acceptance_check = "not applicable"

    def record(label: str, result: JobResult) -> Obligation:
        ob = result.obligation
        queries.append({"name": label, "outcome": ob.outcome.value, "note": ob.note,
                        "backends": {b: r.status for b, r in result.runs.items()},
                        "witness": _witness(ob.witness, witness_names)})
        return ob

    def run(bundle: HarnessBundle, label: str | None = None, **kwargs) -> Obligation:
        witness_names.update(bundle.witness_names)
        return record(label or bundle.kind, run_job(bundle, config=cfg, parallel=parallel, **kwargs))

    def finish(verdict: Verdict) -> VerdictReport:
        tool_versions = {tool: _version(tool, out) for tool in ("cbmc", "z3", "esbmc")}
        evaluated = {r.id: r.state.value for r in frozen.results} if frozen else {}
        shape = plain(task.caller_domain)
        digest = frozen.sha256 if frozen else sha256(canonical([])).hexdigest()
        reported_witness = _witness(verdict.witness, witness_names)
        if reported_witness:
            reported_witness["replayed_natively"] = bool(replay_results) and all(
                r["status"] == "confirmed" for r in replay_results)
            reported_witness["replay_results"] = replay_results
        report = VerdictReport(out, {
            "task_id": task.task_id, "candidate_id": candidate_id, "decision": verdict.decision,
            "evidence_class": verdict.evidence_class, "claim_target": verdict.claim_target,
            "reason": verdict.reason, "conditional": _conditional(verdict),
            "witness": reported_witness, "interpretation_set_sha256": digest,
            "interpretations": [{"id": i["id"], "nl_rendering": i.get("nl_rendering", ""),
                                 "validation": evaluated.get(i["id"], "not checked"),
                                 "outcome": class_status.get(i["id"], "not checked")}
                                for i in task.interpretations],
            "facts": facts, "obligations": queries,
            "scope": {"K": cfg.bounds.K, "shape_min": shape, "shape_max": shape,
                      "bounded_only": True, "profiles": [shape], "reference_safe_guard": reference_guard,
                      "change_brackets": change_brackets,
                      "prepass": {"samples": samples_checked, "seed": cfg.native.seed,
                                  "requested_samples": cfg.native.prepass_samples,
                                  "seconds_budget": cfg.native.prepass_seconds,
                                  "stopped": native_session.prepass_stopped if native_session else "not run"},
                      "native_replay": replay_results, "native_acceptance": acceptance_check,
                      "uninitialized_model": "CBMC experimental local checks"},
            "tools": tool_versions, "timing": {"wall_seconds": monotonic() - started},
        })
        commit = execute(["git", "rev-parse", "HEAD"], cwd=Path(__file__).resolve().parent,
                         timeout_s=10)
        write_json(out / "run_manifest.json", {
            "run_id": out.name, "task_id": task.task_id, "candidate_id": candidate_id,
            "timestamp_utc": datetime.now(timezone.utc).isoformat(),
            "p0_sha256": task.p0.sha256, "p1_sha256": task.candidates[candidate_id].source.sha256,
            "requests": {r.id: sha256(r.text.encode("utf-8")).hexdigest() for r in task.requests},
            "interpretation_set_sha256": digest, "config": {
                "bounds": asdict(cfg.bounds), "timeouts": asdict(cfg.timeouts),
                "backends": asdict(cfg.backends), "native": asdict(cfg.native),
            },
            "tools": tool_versions, "timing": report.data["timing"],
            "git_commit": commit.stdout.strip() if commit.ok else None,
        })
        report.write()
        write_json(root / "latest.json", report.data)
        return report

    def session(generator: Generator) -> NativeSession:
        nonlocal native_session
        if native_session is None:
            native_session = NativeSession(generator, out / "native", cfg.native)
        return native_session

    def confirm_rejection(verdict: Verdict, generator: Generator,
                          checks: list[tuple[HarnessBundle, Obligation]]) -> Verdict:
        for index, (job, obligation) in enumerate(checks):
            if obligation.witness is None:
                return _unknown("solver counterexample has no input trace")
            fixed = bind_inputs(job, obligation.witness, out / "fixed" / str(index))
            verified = run(fixed, "counterexample with fixed inputs " + str(index))
            if verified.outcome is not Outcome.VIOLATED:
                return _unknown("counterexample did not reproduce with its inputs fixed", verdict.witness)
            result = session(generator).confirm(verdict.evidence_class, obligation.witness,
                                                f"witness-{index}")
            replay_results.append({"status": result.status, "reason": result.reason})
            if result.status not in {"confirmed", "p0_undefined"}:
                return _unknown("native replay " + result.status + ": " + result.reason, verdict.witness)
        return verdict

    if not cbmc.cbmc_available():
        return finish(_unknown("CBMC is unavailable"))
    if interpretations != "handwritten":
        return finish(_unknown("automatic interpretation generation is not configured"))
    admission = admit(task, candidate_id, cfg, out_dir=out / "admission")
    if admission.verdict is not None:
        return finish(admission.verdict)
    if not admission.p0_views or not admission.p1_views:
        return finish(_unknown("admission did not provide qualified C views"))
    if admission.required_library_models:
        return finish(_unknown("candidate or reference needs additional library model qualification"))
    p0, p1 = admission.p0_views, admission.p1_views
    try:
        regions = compute_regions(p0, task.caller_domain, out / "regions",
                                  config=cfg, parallel=parallel)
        frozen = freeze_interpretations(task.task_id, p0, task.interpretations,
                                        out / "interpretations", config=cfg, parallel=parallel)
        reference_guard = regions.reference_safe_guard
        if reference_guard is None:
            return finish(_unknown("no certified safe and deterministic reference guard"))
        gen = Generator(p0, p1, task.caller_domain, config=cfg, reference_guard=reference_guard)
        e0_job = gen.gen_core(out / "e0", (), part="e0")
        eligible = frozen.fully_validated and all(
            canonical(i["shape"]) == canonical(task.caller_domain) for i in frozen.members
        )
        hint = None
        if cfg.native.prepass_samples:
            hint, samples_checked = session(gen).prepass(
                frozen.members if eligible else (), cfg.native.prepass_samples, cfg.native.seed)
        e0 = None
        if hint and hint.kind == "e0":
            candidate = run(bind_inputs(e0_job, hint.inputs, out / "prepass_e0"), "pre-pass safety hint")
            if candidate.outcome is Outcome.VIOLATED:
                e0 = candidate
        if e0 is None:
            e0 = run(e0_job, "candidate safety on reference guard")
        if e0.outcome is Outcome.VIOLATED:
            verdict = decide(Evidence(e0, Obligation(Outcome.INCONCLUSIVE), False))
            return finish(confirm_rejection(verdict, gen, [(e0_job, e0)]))
        if e0.outcome is Outcome.INCONCLUSIVE:
            return finish(_unknown(e0.note))
        if not frozen.fully_validated:
            return finish(_unknown("one or more interpretations remain unresolved, or none survived"))
        if any(canonical(i["shape"]) != canonical(task.caller_domain) for i in frozen.members):
            return finish(_unknown("multiple exact input profiles require separate proof orchestration"))
        members = frozen.members
        by_id = {i["id"]: i for i in members}
        clauses = [" || ".join(f"({c['zone']})" for c in i["clauses"]) or "false"
                   for i in members]
        change_brackets.update(
            B_min=" && ".join(f"({zone})" for zone in clauses),
            B_max=" || ".join([*(f"({zone})" for zone in clauses),
                               *(f"({i['reach']})" for i in members if i["reach"] != "unknown")]),
        )
        if p1.views_differ:
            view_job = gen.gen_views_equiv(out / "views")
            views = run(view_job, "build-view consistency")
            if views.outcome is Outcome.VIOLATED:
                if views.witness is None:
                    return finish(_unknown("build-view counterexample has no input trace"))
                fixed = bind_inputs(view_job, views.witness, out / "fixed_views")
                check = run(fixed, "build-view counterexample with fixed inputs")
                if check.outcome is not Outcome.VIOLATED:
                    return finish(_unknown("build-view counterexample did not reproduce", views.witness))
                view_session = NativeSession(gen, out / "native_views", cfg.native, build_views=True)
                replay = view_session.confirm("views", views.witness, "witness")
                replay_results.append({"status": replay.status, "reason": replay.reason})
                if replay.status != "confirmed":
                    return finish(_unknown("native replay " + replay.status + ": " + replay.reason,
                                           views.witness))
                return finish(Verdict("REJECT", "E0", views.note, views.witness, "build_view_consistency"))
            if views.outcome is Outcome.INCONCLUSIVE:
                return finish(_unknown("build-view consistency is unresolved", views.witness))
        e1_job = gen.gen_core(out / "e1", members)
        if not e1_job.e1_decisive:
            return finish(_unknown("scope is unresolved because an extended relation or reach is unknown"))
        keep = run(gen.gen_reference(out / "e1_keep", members, domain="e1_keep"),
                   "reference on common keep region")
        if keep.outcome is not Outcome.PROVED:
            return finish(_unknown("reference behaviour on the common keep region is unresolved"))
        e1 = None
        if hint and hint.kind == "e1":
            candidate = run(bind_inputs(e1_job, hint.inputs, out / "prepass_e1"), "pre-pass preservation hint")
            if candidate.outcome is Outcome.VIOLATED:
                e1 = candidate
        if e1 is None:
            e1 = run(e1_job, "preservation or Ext outside scope union")
        facts["preservation_or_ext_outside_B_max"] = e1.outcome.value
        if e1.outcome is Outcome.VIOLATED:
            return finish(confirm_rejection(decide(Evidence(e0, e1, True)), gen, [(e1_job, e1)]))
        if e1.outcome is Outcome.INCONCLUSIVE:
            return finish(_unknown(e1.note))

        for index, interp in enumerate(members):
            scope = run(gen.gen_scope_check(out / "scope" / str(index), interp),
                        "scope agreement for " + interp["id"])
            if scope.outcome is not Outcome.PROVED:
                return finish(_unknown("scope disagreement or incomplete Ext comparison", scope.witness))

        assessed: dict[str, Obligation] = {}
        confirmations: list[HarnessBundle] = []
        refutations: list[tuple[HarnessBundle, Obligation]] = []
        for index, group in enumerate(frozen.classes):
            interp = by_id[group[0]]
            base = out / "classes" / str(index)
            keep_zone = "!(" + " || ".join(f"({c['zone']})" for c in interp["clauses"]) + ")"
            if not interp["clauses"]:
                keep_zone = "true"
            keep_reach = run(gen.gen_input_rule(base / "keep_reach", "true", keep_zone, reachability=True),
                             "class keep reachability for " + group[0])
            if keep_reach.outcome is Outcome.INCONCLUSIVE:
                assessed[group[0]] = keep_reach
                continue
            probe = gen.gen_vacuity(base / "vacuity", (interp,), include_reach=False)
            empty = frozenset({"VWE.vacuity.keep"}) if keep_reach.outcome is Outcome.PROVED else frozenset()
            vacuity = run(probe, "class path reachability for " + group[0], proven_empty=empty)
            if vacuity.outcome is Outcome.PROVED:
                check = gen.gen_class(base / "obligation", interp)
                assessed[group[0]] = run(check, "interpretation " + group[0])
                if assessed[group[0]].outcome is Outcome.PROVED:
                    confirmations.append(check)
                elif assessed[group[0]].outcome is Outcome.VIOLATED:
                    refutations.append((check, assessed[group[0]]))
            else:
                assessed[group[0]] = vacuity
            for name in group:
                class_status[name] = assessed[group[0]].outcome.value
        for name, outcome in class_status.items():
            if outcome == Outcome.PROVED.value:
                facts["interpretations_satisfied"].append(name)
            elif outcome == Outcome.VIOLATED.value:
                facts["interpretations_violated"].append(name)
        verdict = decide(Evidence(e0, e1, True, assessed))
        if verdict.decision == "REJECT":
            verdict = confirm_rejection(verdict, gen, refutations)
        if verdict.decision == "ACCEPT":
            native_check = session(gen).check_acceptance(members)
            acceptance_check = native_check.status + ": " + native_check.reason
            if native_check.status == "discrepancy":
                return finish(_unknown(native_check.reason))
            for bundle in confirmations:
                check = esbmc.confirm(bundle.files, unwind=bundle.unwind,
                                      cwd=bundle.folder, timeout_s=cfg.timeouts.esbmc_s)
                if check.command:
                    write_json(bundle.folder / "esbmc.json", check.command.record())
                facts.setdefault("esbmc", []).append({"status": check.status.value,
                                                       "detail": check.reason})
                if check.status is esbmc.Confirmation.DISAGREE:
                    verdict = _unknown("ESBMC disagrees with the CBMC result")
                    break
        return finish(verdict)
    except (HarnessUnsupported, GrammarError, LoweringError, ContractUnsupported, ContractTypeError) as exc:
        return finish(_unknown(str(exc)))
