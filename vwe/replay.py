"""Bounded native sampling and same-input replay for formal witnesses."""
from __future__ import annotations

from dataclasses import dataclass, replace
import json
from pathlib import Path
from random import Random
import re
import shutil
from time import monotonic
from typing import Any, Iterator, Mapping, Sequence

from .config import Native
from .contract.ast import ContractUndefined, Sort
from .contract.evaluate import evaluate
from .contract.typecheck import typecheck
from .harness.generate import Generator, _literal
from .harness.layout import HarnessUnsupported
from .harness.model import HarnessBundle
from .harness.native import Driver, InputSlot, generate_checks, generate_driver
from .tools import native

_SLOT = re.compile(r"^\s*(?:_Bool|(?:signed |unsigned )?\w+(?: \w+)?) "
                   r"(__vwe_in_\w+)=nondet___vwe_\d+\(\);$", re.M)


@dataclass(frozen=True)
class Observation:
    p0: native.NativeResult
    p1: native.NativeResult


@dataclass(frozen=True)
class Hint:
    kind: str
    inputs: dict[str, str]
    observation: Observation


@dataclass(frozen=True)
class Replay:
    status: str
    reason: str
    observation: Observation | None = None


def _value(raw: str) -> int:
    return {"true": 1, "false": 0}[raw.lower()] if raw.lower() in {"true", "false"} else int(raw, 10)


def bind_inputs(bundle: HarnessBundle, values: Mapping[str, str], out: Path) -> HarnessBundle:
    """Pin every materialized witness slot before its first use.

    Missing slots prune their own branches. Thus a reproduced failure cannot
    rely on an active input that was absent from the recorded witness.
    """
    out.mkdir(parents=True, exist_ok=True)
    files = []
    pinned: set[str] = set()

    def add_constraint(match: re.Match[str]) -> str:
        key = match[1]
        text = values.get(key)
        if text is None:
            return match[0] + "\n  __CPROVER_assume(0); /* missing replay slot */"
        try:
            n = _value(text)
        except (ValueError, AttributeError) as exc:
            raise HarnessUnsupported("witness input is not an integer") from exc
        if not -(1 << 63) <= n < (1 << 64):
            raise HarnessUnsupported("witness value is outside the C integer profile")
        pinned.add(key)
        return match[0] + f"\n  __CPROVER_assume({key} == {_literal(n)});"

    for src in bundle.files:
        dest = out / src.name
        if src.name == "main.c":
            original = src.read_text()
            rebound = _SLOT.sub(add_constraint, original)
            expected = [name for name in bundle.watch if name.startswith("__vwe_in_")]
            matched = {match[1] for match in _SLOT.finditer(original)}
            if set(expected) != matched:
                raise HarnessUnsupported("could not bind the full planned witness inventory")
            dest.write_text(rebound)
        else:
            shutil.copyfile(src, dest)
        files.append(dest)
    shutil.copyfile(bundle.folder / "frame.h", out / "frame.h")
    (out / "fixed-inputs.json").write_text(json.dumps({k: values[k] for k in sorted(pinned)}, indent=2) + "\n")
    return replace(bundle, folder=out, files=tuple(files))


def samples(slots: Sequence[InputSlot], count: int, seed: int) -> Iterator[dict[str, str]]:
    """Try joint boundary vectors, then deterministic independent samples."""
    seen = set()
    rng = Random(seed)
    for index in range(count + 5):
        if len(seen) >= count:
            break
        if index < 5:
            base = (0, 1, -1, -(1 << 63), (1 << 64) - 1)[index]
            vector = tuple(max(s.minimum, min(s.maximum, base)) for s in slots)
        else:
            vector = tuple(rng.randint(s.minimum, s.maximum) for s in slots)
        if vector in seen:
            continue
        seen.add(vector)
        yield {slot.name: str(value) for slot, value in zip(slots, vector)}


class NativeSession:
    def __init__(self, gen: Generator, folder: Path, config: Native, *, build_views: bool = False) -> None:
        self.gen = gen
        self.folder = folder
        self.config = config
        self.drivers: dict[str, Driver] = {}
        self.reason = ""
        self.sampled_inputs: list[dict[str, str]] = []
        self.prepass_stopped = "not run"
        self.folder.mkdir(parents=True, exist_ok=True)
        if not native.sandbox_available():
            self.reason = "native network isolation is unavailable"
            return
        for program in ("p0", "p1"):
            try:
                driver = generate_driver(gen, folder / program, program, build_views=build_views)
            except HarnessUnsupported as exc:
                self.reason = str(exc)
                return
            build = native.compile_driver(driver.files, driver.folder / "driver",
                                          cc=config.cc, sanitizers=config.sanitize)
            (driver.folder / "build.json").write_text(json.dumps(build.record(), indent=2) + "\n")
            if not build.ok:
                self.reason = program + " native sanitizer compilation failed"
                return
            self.drivers[program] = driver

    @property
    def ready(self) -> bool:
        return len(self.drivers) == 2

    def observe(self, inputs: dict[str, str], name: str | None = None) -> Observation:
        runs = {}
        for program, driver in self.drivers.items():
            runs[program] = native.run_driver(driver.folder / "driver", driver.arguments(inputs))
        observation = Observation(runs["p0"], runs["p1"])
        if name:
            (self.folder / f"{name}.json").write_text(json.dumps({
                "inputs": inputs, **{p: r.record() for p, r in runs.items()},
            }, indent=2) + "\n")
        return observation

    def snapshot(self, inputs: dict[str, str], observations: Observation) -> dict[str, Any]:
        values: dict[str, Any] = {}
        for name, symbol in self.gen.profile.env.symbols.items():
            values[name] = [] if symbol.sort is Sort.BUFFER else None

        def put(key: str, raw: str) -> None:
            if "[" not in key:
                if key in values:
                    values[key] = _value(raw)
                return
            match = re.fullmatch(r"(\w+)\[(\d+)\]", key)
            if match and isinstance(values.get(match[1]), list):
                index = int(match[2])
                items = values[match[1]]
                items.extend([None] * max(0, index + 1 - len(items)))
                items[index] = _value(raw)

        layout = self.gen.layout
        for p in layout.parameters:
            key = f"__vwe_in_scalar_{p.index}_0"
            if not p.buffer and key in inputs:
                put(p.name, inputs[key])
        for p in layout.parameters:
            if p.buffer:
                expression = dict((n, e) for n, e, _ in self.gen.profile.lengths)[p.name]
                length = int(evaluate(typecheck(expression, self.gen.profile.env), values))
                values[p.name] = [None] * length
                initial = {key: raw for key, raw in inputs.items() if key.startswith(f"__vwe_in_buffer_{p.index}_")}
                for key, raw in initial.items():
                    index, field = key.removeprefix(f"__vwe_in_buffer_{p.index}_").split("_")
                    if field == "0" and int(index) < length:
                        put(f"{p.name}[{index}]", raw)
        for glob in layout.globals:
            for index, field in enumerate(glob.fields):
                key = f"__vwe_in_global_{glob.name}_{index}"
                if key in inputs:
                    put(field.access("in_global_" + glob.name), inputs[key])
        for prefix, observation in (("old_", observations.p0), ("out_", observations.p1)):
            for label, raw in observation.outputs.items():
                key = label.replace("global ", "global_", 1) if label.startswith("global ") else label
                put(prefix + key, raw)
        return values

    def prepass(self, interps: Sequence[Mapping[str, Any]], count: int,
                seed: int) -> tuple[Hint | None, int]:
        if not self.ready:
            self.prepass_stopped = self.reason
            return None, 0
        env = self.gen.profile.env
        e0_guard = typecheck(self.gen.reference_guard, env)
        zones = [typecheck(c["zone"], env) for it in interps for c in it["clauses"]]
        reaches = [typecheck(it["reach"], env) for it in interps if it["reach"] != "unknown"]
        exts = [typecheck(it["ext"], env) for it in interps if it["ext"] != "unknown"]
        e1_known = bool(interps) and len(exts) == len(interps) == len(reaches)
        sampled = 0
        deadline = monotonic() + self.config.prepass_seconds
        self.prepass_stopped = "sample budget"
        for inputs in samples(self.drivers["p1"].slots, count, seed):
            if sampled and monotonic() >= deadline:
                self.prepass_stopped = "time budget"
                break
            sampled += 1
            self.sampled_inputs.append(inputs)
            obs = self.observe(inputs)
            if obs.p0.outcome != "clean":
                continue
            try:
                values = self.snapshot(inputs, obs)
                if obs.p1.outcome == "sanitizer" and evaluate(e0_guard, values):
                    self.observe(inputs, "prepass-hint")
                    self.prepass_stopped = "safety hint"
                    return Hint("e0", inputs, obs), sampled
                if (obs.p1.outcome == "clean" and e1_known and obs.p0.outputs != obs.p1.outputs
                        and not any(evaluate(e, values) for e in (*zones, *reaches, *exts))):
                    self.observe(inputs, "prepass-hint")
                    self.prepass_stopped = "preservation hint"
                    return Hint("e1", inputs, obs), sampled
            except ContractUndefined:
                continue
        return None, sampled

    def check_acceptance(self, interps: Sequence[Mapping[str, Any]]) -> Replay:
        if not self.ready:
            return Replay("unsupported", self.reason)
        if not self.sampled_inputs:
            return Replay("not_sampled", "no pre-pass inputs were executed")
        try:
            driver = generate_checks(self.gen, self.folder / "checks", interps)
        except HarnessUnsupported as exc:
            return Replay("unsupported", str(exc))
        build = native.compile_driver(driver.files, driver.folder / "driver",
                                      cc=self.config.cc, sanitizers=self.config.sanitize)
        (driver.folder / "build.json").write_text(json.dumps(build.record(), indent=2) + "\n")
        if not build.ok:
            return Replay("unsupported", "native executable contract compilation failed")
        for inputs in self.sampled_inputs:
            result = native.run_driver(driver.folder / "driver", driver.arguments(inputs))
            failed = [i["id"] for j, i in enumerate(interps)
                      if result.outputs.get(f"__vwe_check_{j}") == "0"]
            if failed or result.outcome == "sanitizer":
                (driver.folder / "discrepancy.json").write_text(json.dumps({
                    "inputs": inputs, "failed_interpretations": failed, "native": result.record(),
                }, indent=2) + "\n")
                return Replay("discrepancy", "native contract checks disagree with ACCEPT: "
                              + (", ".join(failed) or result.detail))
            if result.outcome != "clean" or any(
                result.outputs.get(f"__vwe_check_{j}") != "1" for j in range(len(interps))
            ):
                return Replay("unsupported", "native contract driver did not complete")
        return Replay("confirmed", f"all {len(interps)} interpretations checked on "
                      f"{len(self.sampled_inputs)} sampled inputs")

    def confirm(self, evidence_class: str, values: dict[str, str], name: str) -> Replay:
        if not self.ready:
            return Replay("unsupported", self.reason)
        obs = self.observe(values, name)
        if any(run.outcome in {"error", "unsupported"} for run in (obs.p0, obs.p1)):
            return Replay("unsupported", "native driver or sanitizer runtime was unavailable", obs)
        if any(run.outcome == "invalid_input" for run in (obs.p0, obs.p1)):
            return Replay("discrepancy", "fixed witness is missing or violates a native input constraint", obs)
        if evidence_class == "E0":
            matches = obs.p0.outcome == "clean" and obs.p1.outcome == "sanitizer"
            return Replay("confirmed" if matches else "discrepancy",
                          obs.p1.detail if matches else "expected a candidate-only sanitizer finding", obs)
        expected = {}
        for program, role in (("p0", "zero"), ("p1", "one")):
            prefix = f"__vwe_out_{role}_"
            expected[program] = {k.removeprefix(prefix): str(_value(v))
                                 for k, v in values.items() if k.startswith(prefix)}
        if not expected["p1"]:
            return Replay("unsupported", "the formal trace did not expose candidate outputs", obs)
        for program, run in (("p0", obs.p0), ("p1", obs.p1)):
            trace = expected[program]
            if trace and (run.outcome != "clean" or
                          any(run.outputs.get(key) != value for key, value in trace.items())):
                return Replay("discrepancy", f"{program} outputs differ from the formal witness", obs)
        if evidence_class in {"E1", "views"} and obs.p0.outputs == obs.p1.outputs:
            return Replay("discrepancy", "the reported regression did not replay", obs)
        if obs.p0.outcome == "sanitizer" and not expected["p0"] and obs.p1.outcome == "clean":
            return Replay("p0_undefined", "the formal class witness does not require defined P0 output", obs)
        return Replay("confirmed", "captured observations match the fixed solver witness", obs)
