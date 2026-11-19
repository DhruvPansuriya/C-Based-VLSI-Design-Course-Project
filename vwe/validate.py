"""Validate and freeze P0-only interpretations before examining a candidate."""
from __future__ import annotations

from dataclasses import dataclass
from enum import Enum
from hashlib import sha256
import json
from pathlib import Path
from typing import Any, Mapping, Sequence

from .config import Config
from .contract.ast import ContractTypeError, ContractUnsupported, GrammarError, LoweringError
from .contract.typecheck import typecheck
from .harness.generate import Generator
from .harness.layout import HarnessUnsupported
from .harness.model import HarnessBundle
from .harness.profile import plain
from .proof_jobs import run_job
from .schemas import validate as validate_schema
from .verdict import Obligation, Outcome
from .views import Views

Interpretation = Mapping[str, Any]
_CAPABILITY_ERRORS = (ContractUnsupported, HarnessUnsupported, LoweringError)


class State(str, Enum):
    VALID = "valid"
    INVALID = "invalid"
    UNKNOWN = "unknown"


@dataclass(frozen=True)
class Validation:
    id: str
    state: State
    check: str
    detail: str
    witness: Mapping[str, str] | None = None


@dataclass(frozen=True)
class FrozenSet:
    path: Path
    sha256: str
    members: tuple[Interpretation, ...]
    results: tuple[Validation, ...]
    classes: tuple[tuple[str, ...], ...]

    @property
    def fully_validated(self) -> bool:
        return bool(self.classes) and all(r.state is not State.UNKNOWN for r in self.results)


def canonical(value: Any) -> bytes:
    return json.dumps(plain(value), ensure_ascii=False, sort_keys=True,
                      separators=(",", ":"), allow_nan=False).encode("utf-8")


class Validator:
    def __init__(self, p0: Views, out: Path, config: Config, parallel: bool) -> None:
        self.p0 = p0
        self.out = out
        self.config = config
        self.parallel = parallel

    def run(self, bundle: HarnessBundle, pair: bool = False) -> Obligation:
        cfg = self.config
        if pair:
            from dataclasses import replace
            cfg = replace(cfg, timeouts=replace(cfg.timeouts, cbmc_s=cfg.timeouts.equiv_pair_s))
        return run_job(bundle, config=cfg, parallel=self.parallel).obligation

    def generator(self, shape: Mapping[str, Any]) -> Generator:
        return Generator(self.p0, self.p0, shape, config=self.config)

    def one(self, interp: Interpretation, out: Path) -> Validation:
        identity = interp["id"]
        check = "V-G"

        def verdict(state: State, detail: str, ob: Obligation | None = None) -> Validation:
            return Validation(identity, state, check, detail, ob.witness if ob else None)

        try:
            gen = self.generator(interp["shape"])
            clauses = interp["clauses"]
            old_use = any(typecheck(c["behaviour"], gen.profile.env).old_symbols for c in clauses)
            ext = interp.get("ext")
            ext_old = ext != "unknown" and bool(typecheck(ext, gen.profile.env).old_symbols)
            vg = self.run(gen.gen_contract_ub(out / "contract_ub", interp))
            if vg.outcome is Outcome.VIOLATED:
                if old_use or ext_old:
                    return verdict(State.UNKNOWN, "observer can fail on synthetic old outputs", vg)
                return verdict(State.INVALID, vg.note, vg)
            if vg.outcome is not Outcome.PROVED:
                return verdict(State.UNKNOWN, vg.note, vg)

            check = "V-1"
            # An empty keep region is a valid total obligation. Empty clause
            # zones are skipped only through explicit invalidity evidence.
            regions = ["true", *[c["zone"] for c in clauses]]
            for i, predicate in enumerate(regions):
                outcome = self.run(gen.gen_input_rule(out / f"reach_{i}", "true", predicate,
                                                      reachability=True))
                if outcome.outcome is Outcome.PROVED:
                    return verdict(State.INVALID, "caller domain or clause zone is empty")
                if outcome.outcome is Outcome.INCONCLUSIVE:
                    return verdict(State.UNKNOWN, outcome.note, outcome)

            check = "V-2"
            zone = " || ".join(f"({c['zone']})" for c in clauses) or "false"
            bug = self.run(gen.gen_reference_safety(out / "bug_safety", zone))
            if bug.outcome is Outcome.PROVED:
                bug = self.run(gen.gen_validation(out / "bug", (interp,), "bug"))
            if bug.outcome is Outcome.PROVED:
                return verdict(State.INVALID, "P0 is safe and already satisfies all change clauses")
            if bug.outcome is Outcome.INCONCLUSIVE:
                return verdict(State.UNKNOWN, bug.note, bug)

            check = "V-3"
            # For the class generator, any old-value clause needs a full-profile
            # certificate. Ext is evaluated on the E1 keep region, a subset of
            # the class keep region, where old observations are available.
            reference = self.run(gen.gen_reference(out / "reference", (interp,),
                                                   domain="all" if old_use else "keep"))
            if reference.outcome is not Outcome.PROVED:
                return verdict(State.UNKNOWN, "P0 definedness or determinism unresolved", reference)

            check = "V-4"
            try:
                constructive = self.run(gen.gen_validation(out / "constructive", (interp,), "constructive"))
            except HarnessUnsupported as exc:
                constructive = Obligation(Outcome.INCONCLUSIVE, note=str(exc))
            if constructive.outcome is Outcome.PROVED:
                return verdict(State.VALID, "joint output tuple proved for every modeled input", bug)

            # Global existential unsatisfiability is sufficient to discard an
            # active clause. Satisfiability on one input is never validation.
            for i, clause in enumerate(clauses):
                single = {**interp, "clauses": [clause]}
                possible = self.run(gen.gen_validation(out / f"possible_{i}", (single,), "possible"))
                if possible.outcome is Outcome.PROVED:
                    return verdict(State.INVALID, "no modeled input/output pair satisfies an active clause")
            if len(clauses) > 1:
                possible = self.run(gen.gen_validation(out / "possible_joint", (interp,), "possible"))
                if possible.outcome is Outcome.PROVED:
                    return verdict(State.INVALID, "no modeled joint output on any active input")
            return verdict(State.UNKNOWN, "joint per-input realizability unresolved", constructive)
        except GrammarError as exc:
            return verdict(State.INVALID, str(exc))
        except (ContractTypeError, *_CAPABILITY_ERRORS) as exc:
            return verdict(State.UNKNOWN, str(exc))

    def group(self, validated: Sequence[Interpretation]) -> tuple[tuple[str, ...], ...]:
        groups: list[list[Interpretation]] = []
        pairs = 0
        for interp in validated:
            for group in groups:
                other = group[0]
                if canonical(other["shape"]) != canonical(interp["shape"]) or pairs >= 36:
                    continue
                try:
                    gen = self.generator(interp["shape"])
                    out = self.out / "pairs" / str(pairs)
                    pairs += 1
                    ob = self.run(gen.gen_validation(out, (other, interp), "equivalence"), pair=True)
                except _CAPABILITY_ERRORS:
                    continue
                if ob.outcome is Outcome.PROVED:
                    group.append(interp)
                    break
            else:
                groups.append([interp])
        return tuple(tuple(i["id"] for i in group) for group in groups)


def freeze_interpretations(task_id: str, p0: Views, interpretations: Sequence[Interpretation],
                           out: Path, *, config: Config | None = None, parallel: bool = True,
                           generation: Mapping[str, Any] | None = None) -> FrozenSet:
    """Freeze all non-invalid readings. UNKNOWN blocks a universal verdict."""
    from dataclasses import asdict
    from types import MappingProxyType
    out.mkdir(parents=True, exist_ok=True)
    checked = [plain(it) for it in interpretations]
    for item in checked:
        validate_schema("interpretation", item)
    if len({i["id"] for i in checked}) != len(checked):
        raise ValueError("interpretation IDs must be unique")
    items = sorted(checked, key=lambda it: it["id"])
    validator = Validator(p0, out, config or Config(), parallel)
    results = tuple(
        validator.one(it, out / "checks" / str(index))
        if index < 16 and len(it["clauses"]) <= 16 else
        Validation(it["id"], State.UNKNOWN, "V-G", "interpretation checking budget exhausted")
        for index, it in enumerate(items)
    )
    members = [it for it, r in zip(items, results) if r.state is not State.INVALID]
    classes = validator.group([it for it, r in zip(items, results) if r.state is State.VALID])
    digest = sha256(canonical(members)).hexdigest()
    record = {
        "task_id": task_id, "members": members, "sha256": digest,
        "discarded": [{"id": r.id, "check": r.check, "detail": r.detail}
                      for r in results if r.state is State.INVALID],
        "generation": plain(generation or {"runs": 1, "families": ["handwritten"],
                                          "p1_seen_by_any_llm": False}),
        "informational": {"equivalence_classes": classes},
    }
    # JSON Schema arrays require JSON lists, not internal tuples.
    record = plain(record)
    validate_schema("interpretation_set", record)
    path = out / "interpretation_set.json"
    path.write_text(json.dumps(record, indent=2, ensure_ascii=False) + "\n")
    (out / "validation.json").write_text(json.dumps({
        "p0_sha256": p0.source_sha256,
        "interpretation_set_sha256": digest,
        "checks": [asdict(r) for r in results],
    }, indent=2) + "\n")

    def immutable(value):
        if isinstance(value, dict):
            return MappingProxyType({k: immutable(v) for k, v in value.items()})
        if isinstance(value, list):
            return tuple(immutable(x) for x in value)
        return value

    return FrozenSet(path, digest, tuple(immutable(i) for i in members), results, classes)
