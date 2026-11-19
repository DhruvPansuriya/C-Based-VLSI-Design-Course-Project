"""T02 structural admission. An admitted program has not been proved correct."""
from __future__ import annotations
from dataclasses import dataclass, field
from hashlib import sha256
from pathlib import Path
import json
from types import MappingProxyType
from typing import Mapping
from uuid import uuid4
from . import verdict
from .c_frontend import Finding, PragmaUse, prototype_signature
from .config import Config, data_path, load_config, tomllib
from .tasks import Candidate, PipelineTask
from .tools import frontend
from .views import Views, ViewError, ForbiddenViewError, make_views


@dataclass(frozen=True)
class AdmissionResult:
    status: str
    reason: str
    artifact_dir: Path
    p0_views: Views | None = None
    p1_views: Views | None = None
    findings: tuple[Finding, ...] = ()
    undefined_functions: tuple[str, ...] = ()
    required_library_models: tuple[str, ...] = ()
    globals: Mapping[str, str] = field(default_factory=lambda: MappingProxyType({}))
    pragmas: tuple[PragmaUse, ...] = ()
    commands: tuple[frontend.CommandResult, ...] = ()

    @property
    def verdict(self) -> verdict.Verdict | None:
        return verdict.admission_verdict(self.status, self.reason)

    @property
    def decision(self) -> str:
        v = self.verdict
        return "ok" if v is None else v.decision.lower()

    @property
    def views_differ(self) -> bool:
        return self.p1_views.views_differ if self.p1_views else False


def _library_prototypes() -> dict[str, tuple]:
    with data_path("config/whitelist.toml").open("rb") as stream:
        doc = tomllib.load(stream)
    return {name: prototype_signature(text) for name, text in doc["functions"].items()}


def _program_checks(views: Views, *, candidate: bool,
                    timeout_s: int, library: dict[str, tuple]) -> tuple[str, str, tuple[Finding, ...], tuple[str, ...], tuple[str, ...], tuple[frontend.CommandResult, ...]]:
    commands = []
    missing: set[str] = set()
    required_models: set[str] = set()
    for v in (views.sim, views.synth):
        analysis = v.analysis
        if analysis.forbidden:
            return ("refused" if candidate else "unsupported", "forbidden construct", analysis.forbidden, (), (), tuple(commands))
        if analysis.unsupported:
            return "unsupported", "unsupported C", analysis.unsupported, (), (), tuple(commands)
        if not views.qualified_preprocessing:
            return "inconclusive", "fallback preprocessing is not qualified", (), (), (), tuple(commands)
        absent = set(analysis.calls) - set(analysis.definitions)
        unmodeled = absent - library.keys()
        # Use the independently compiled original view for a second namespace/model check.
        checked = frontend.list_undefined(v.preprocessed, timeout_s=timeout_s)
        commands.extend(checked.commands)
        if unmodeled:
            missing.update(unmodeled)
            return ("refused" if candidate else "unsupported", "unmodeled call", (), tuple(sorted(missing)), (), tuple(commands))
        if not checked.ok:
            return "inconclusive", checked.reason, (), (), (), tuple(commands)
        user_undefined = {name for name in checked.names if not name.startswith("__CPROVER_")}
        # Listing includes unused header prototypes; only reachable direct calls
        # need a body. Source-level verifier identifiers are separately forbidden.
        unexpected = user_undefined & set(analysis.calls) - library.keys()
        if unexpected:
            return ("refused" if candidate else "unsupported", "unmodeled GOTO call", (), tuple(sorted(unexpected)), (), tuple(commands))
        for name in absent & library.keys():
            actual = dict(analysis.prototypes).get(name)
            if actual != library[name]:
                return ("refused" if candidate else "unsupported", f"unqualified library signature: {name}", (), (name,), (), tuple(commands))
            required_models.add(name)
    return "ok", "structural admission passed; semantic obligations remain", (), (), tuple(sorted(required_models)), tuple(commands)


def admit(task: PipelineTask, candidate: str | Candidate, cfg: Config | None = None, *,
          out_dir: str | Path | None = None) -> AdmissionResult:
    cfg = cfg or load_config()
    selected = task.candidates[candidate] if isinstance(candidate, str) else candidate
    folder = Path(out_dir) if out_dir is not None else Path("runs")/task.task_id/selected.id/uuid4().hex/"admission"
    folder = folder.resolve(); folder.mkdir(parents=True, exist_ok=True)
    p0_views: Views | None = None
    p1_views: Views | None = None
    commands: list[frontend.CommandResult] = []
    library = _library_prototypes()

    def finish(status: str, reason: str, *, findings: tuple[Finding, ...] = (),
               undefined: tuple[str, ...] = (), models: tuple[str, ...] = ()) -> AdmissionResult:
        globals_found = {name: role for views in (p0_views,p1_views) if views
                         for v in (views.sim,views.synth) for name,role in v.analysis.globals}
        pragmas = tuple(p for views in (p0_views,p1_views) if views for v in (views.sim,views.synth) for p in v.analysis.pragmas)
        result = AdmissionResult(status, reason, folder, p0_views, p1_views, findings, undefined,
                                 models, MappingProxyType(globals_found), pragmas, tuple(commands))
        v = result.verdict
        report = {"status": status, "reason": reason, "decision": result.decision,
                  "evidence_class": v.evidence_class if v else None,
                  "claim_target": v.claim_target if v else "none",
                  "views_differ": result.views_differ, "globals": globals_found,
                  "undefined_functions": list(undefined), "required_library_models": list(models),
                  "findings": [{"code":f.code,"detail":f.detail,"location":f.location} for f in findings],
                  "pragmas": [{"program":kind,"mode":v.mode,"name":p.name,
                               "arguments":list(p.arguments),"options":dict(p.options),"location":p.location}
                              for kind,views in (("p0",p0_views),("p1",p1_views)) if views
                              for v in (views.sim,views.synth) for p in v.analysis.pragmas],
                  "globals_by_view": [{"program":kind,"mode":v.mode,"objects":dict(v.analysis.globals)}
                                      for kind,views in (("p0",p0_views),("p1",p1_views)) if views
                                      for v in (views.sim,views.synth)],
                  "commands": [c.record() for c in commands],
                  "functional_proof": "NOT_RUN", "build_view_equivalence": "NOT_RUN",
                  "pragma_policy": "NOT_RUN"}
        (folder/"admission.json").write_text(json.dumps(report,indent=2)+"\n")
        return result

    for kind, source in (("p0",task.p0),("p1",selected.source)):
        try:
            actual_hash = sha256(source.text.encode("utf-8")).hexdigest()
        except UnicodeError:
            return finish("inconclusive", f"{kind}: source snapshot is not UTF-8")
        if actual_hash != source.sha256:
            return finish("inconclusive", f"{kind}: source snapshot hash mismatch")
        snapshot = folder/kind/"input.c"; snapshot.parent.mkdir(parents=True, exist_ok=True)
        snapshot.write_text(source.text, encoding="utf-8")
        try:
            views = make_views(snapshot,task.function,snapshot.parent/"views",prefix=kind,
                               timeout_s=cfg.timeouts.cbmc_s,fallback_cc=cfg.native.cc)
        except ForbiddenViewError as exc:
            return finish("refused" if kind=="p1" else "unsupported", f"{kind}: forbidden construct", findings=exc.findings)
        except (ViewError,OSError) as exc:
            return finish("unsupported", str(exc))
        commands.extend(c for v in (views.sim,views.synth) for c in v.commands)
        if kind == "p0": p0_views = views
        else: p1_views = views
        if views.sim.analysis.signature != views.synth.analysis.signature:
            return finish("interface_change", f"{kind}: build-dependent function signature")
        if kind == "p1" and p0_views:
            if any(getattr(p0_views, mode).analysis.signature != getattr(views, mode).analysis.signature
                   for mode in ("sim", "synth")):
                return finish("interface_change", "interface change")
        state, reason, issues, undefined, models, extra = _program_checks(
            views,candidate=kind=="p1",timeout_s=cfg.timeouts.cbmc_s,library=library)
        commands.extend(extra)
        if state != "ok":
            return finish(state, f"{kind}: {reason}", findings=issues, undefined=undefined, models=models)
    assert p0_views is not None and p1_views is not None
    for mode in ("sim","synth"):
        old = getattr(p0_views,mode).analysis; new = getattr(p1_views,mode).analysis
        if old.signature != new.signature:
            return finish("interface_change", f"{mode}: interface change")
        added = set(new.all_global_names)-set(old.all_global_names)
        if added:
            return finish("refused", "new global/static objects", findings=tuple(Finding("NEW_GLOBAL",name) for name in sorted(added)))
        old_mutable = {name for name,role in old.globals if role=="input_output"}
        if not old_mutable <= set(new.all_global_names):
            return finish("interface_change", "observable global removed")
        if any(dict(old.global_types).get(n)!=dict(new.global_types).get(n) for n in old_mutable):
            return finish("interface_change", "observable global type changed")
        if any(dict(new.globals).get(n, role)!=role for n,role in old.globals):
            return finish("interface_change", "observable global classification changed")
    required = tuple(sorted({n for views in (p0_views,p1_views) for v in (views.sim,views.synth)
                             for n in set(v.analysis.calls)-set(v.analysis.definitions) if n in library}))
    return finish("ok", "structural admission passed; functional, build-view and pragma obligations remain", models=required)
