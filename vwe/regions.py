"""P0-only computed regions, with separate coverage and exactness evidence."""
from __future__ import annotations

from dataclasses import asdict, dataclass, fields
from functools import lru_cache
from hashlib import sha256
import os
import tempfile
import json
from pathlib import Path
from typing import Any, Mapping

from pycparser import c_ast as C

from .config import Config
from .harness.generate import Generator
from .harness.layout import HarnessUnsupported, dimension
from .harness.model import HarnessBundle
from .proof_jobs import run_job
from .verdict import Obligation, Outcome
from .views import Views


@dataclass(frozen=True)
class RegionResult:
    profile_sha256: str
    p0_sha256: str
    proposed_ub: str
    exact_ub: str | None
    exact_nd: str | None
    reference_safe_guard: str | None
    ub_coverage: Obligation
    ub_witness: Obligation
    predicate_reach: Obligation
    universal_inside: Obligation
    determinism_outside: Obligation
    safe_guard_reach: Obligation


def _initial_buffer_read(gen: Generator) -> tuple[str, int] | None:
    """Recognize an unconditional read in the first local initializer.

    This narrow certificate establishes a specific undefined operation for
    every modeled input whose exact allocation cannot contain that element.
    It assumes no completion, output, or branch facts about the rest of P0.
    """
    a = gen.p0.sim.analysis
    function = next(n for n in a.ast.ext if isinstance(n, C.FuncDef)
                    and n.decl.name == a.function)
    body = function.body.block_items or []
    if not body or not isinstance(body[0], C.Decl):
        return None
    init = body[0].init
    if not isinstance(init, C.ArrayRef) or not isinstance(init.name, C.ID):
        return None
    if init.name.name not in {name for name, _, _ in gen.profile.lengths}:
        return None
    if not isinstance(init.subscript, C.Constant):
        return None
    # Only simple nonnegative C integer literals qualify.
    literal = init.subscript.value
    try:
        index = 0 if literal == "0" else dimension(literal)
    except HarnessUnsupported:
        return None
    return init.name.name, index


def _initial_buffer_write(gen: Generator) -> tuple[str, str] | None:
    """A first, unconditional plain store with side-effect-free operands.

    Only direct buffers and literal/input-scalar indices qualify. The RHS is
    a literal, an input scalar, or another plain buffer read. Thus evaluation
    either reaches the store or encounters an earlier undefined buffer access;
    it cannot call a function, change the index, or avoid the write by looping.
    """
    analysis = gen.p0.sim.analysis
    function = next(n for n in analysis.ast.ext if isinstance(n, C.FuncDef)
                    and n.decl.name == analysis.function)
    body = function.body.block_items or []
    if not body or not isinstance(body[0], C.Assignment) or body[0].op != "=":
        return None
    statement = body[0]
    buffers = {name for name, _, _ in gen.profile.lengths}

    def scalar(node: C.Node) -> str | None:
        if isinstance(node, C.ID):
            symbol = gen.profile.env.symbols.get(node.name)
            if symbol and symbol.role == "input" and node.name not in buffers:
                return node.name
        if isinstance(node, C.Constant) and node.type == "int":
            try:
                value = 0 if node.value == "0" else dimension(node.value)
            except HarnessUnsupported:
                return None
            return str(value)
        return None

    def access(node: C.Node) -> tuple[str, str] | None:
        if not isinstance(node, C.ArrayRef) or not isinstance(node.name, C.ID):
            return None
        index = scalar(node.subscript)
        if node.name.name in buffers and index is not None:
            return node.name.name, index
        return None

    target = access(statement.lvalue)
    if target and (scalar(statement.rvalue) is not None or access(statement.rvalue)):
        return target
    return None


def compute_regions(p0: Views, shape: Mapping[str, Any], out: Path, *,
                    proposed_ub: str | None = None, config: Config | None = None,
                    parallel: bool = True) -> RegionResult:
    """P0-only regions, optionally reused from an evaluation cache (off by default).

    Set VWE_REGION_CACHE to a directory to reuse results across candidates and
    baselines of one evaluation. The key covers P0's source and both preprocessed
    views, the exact profile, the proposed region, the full configuration and the
    hash of the verifier's own source code; every reuse leaves cache_hit.json.
    """
    cache_dir = os.environ.get("VWE_REGION_CACHE")
    if not cache_dir:
        return _compute_regions(p0, shape, out, proposed_ub=proposed_ub, config=config, parallel=parallel)
    cfg = config or Config()
    key = sha256(json.dumps({
        "p0": p0.source_sha256, "views": [p0.sim.sha256, p0.synth.sha256],
        "shape": _plain(shape), "proposed_ub": proposed_ub,
        "config": {k: asdict(getattr(cfg, k)) for k in ("bounds", "timeouts", "backends", "native")},
        "code": _code_hash()}, sort_keys=True, default=str).encode()).hexdigest()
    entry = Path(cache_dir) / f"{key}.json"
    out.mkdir(parents=True, exist_ok=True)
    if entry.is_file():
        result = _from_json(json.loads(entry.read_text()))
        (out / "regions.json").write_text(json.dumps(asdict(result), indent=2) + "\n")
        (out / "cache_hit.json").write_text(json.dumps({"key": key, "entry": str(entry)}) + "\n")
        return result
    result = _compute_regions(p0, shape, out, proposed_ub=proposed_ub, config=cfg, parallel=parallel)
    entry.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(dir=entry.parent, suffix=".tmp")
    with os.fdopen(fd, "w") as stream:
        json.dump(asdict(result), stream)
    os.replace(tmp, entry)
    return result


@lru_cache(maxsize=1)
def _code_hash() -> str:
    h = sha256()
    for path in sorted(Path(__file__).resolve().parent.rglob("*.py")):
        h.update(path.read_bytes())
    return h.hexdigest()


def _plain(value: Any) -> Any:
    if isinstance(value, Mapping):
        return {k: _plain(v) for k, v in value.items()}
    if isinstance(value, (list, tuple)):
        return [_plain(v) for v in value]
    return value


def _from_json(doc: Mapping[str, Any]) -> RegionResult:
    values = {}
    for f in fields(RegionResult):
        v = doc[f.name]
        if isinstance(v, dict) and "outcome" in v:
            v = Obligation(Outcome(v["outcome"]), v.get("witness"), v.get("note", ""))
        values[f.name] = v
    return RegionResult(**values)


def _compute_regions(p0: Views, shape: Mapping[str, Any], out: Path, *,
                     proposed_ub: str | None = None, config: Config | None = None,
                     parallel: bool = True) -> RegionResult:
    """Certify what the bounded queries support for one exact input profile.

    Safety outside P plus a witness inside P certifies an overapproximation.
    Exactness additionally requires a universally failing operation inside P.
    Initial direct-read and plain-store certificates are supported ways to establish it.
    """
    gen = Generator(p0, p0, shape, config=config)
    read = _initial_buffer_read(gen)
    lengths = {name: length for name, length, _ in gen.profile.lengths}
    write = _initial_buffer_write(gen)
    fault = f"({lengths[read[0]]}) <= {read[1]}" if read else (
        f"({write[1]}) < 0 || ({lengths[write[0]]}) <= ({write[1]})" if write else None)
    if proposed_ub is None:
        proposed_ub = fault or "false"
    predicate = proposed_ub
    complement = f"!({predicate})"

    def run(job: HarnessBundle) -> Obligation:
        return run_job(job, config=config, parallel=parallel).obligation

    coverage = run(gen.gen_reference_safety(out / "outside_safety", complement))
    inside_reach = run(gen.gen_input_rule(out / "inside_reach", "true", predicate, reachability=True))
    outside_reach = run(gen.gen_input_rule(out / "outside_reach", "true", complement, reachability=True))
    inside = Obligation(Outcome.INCONCLUSIVE, note="no reachable proposed UB region")
    if inside_reach.outcome is Outcome.VIOLATED:
        inside = run(gen.gen_reference_safety(out / "inside_safety", predicate))
    exact_inside = Obligation(Outcome.INCONCLUSIVE, note="no universal fault certificate")
    if inside_reach.outcome is Outcome.PROVED:
        exact_inside = Obligation(Outcome.PROVED, note="proposed region is empty")
    elif fault is not None:
        exact_inside = run(gen.gen_input_rule(out / "inside_implies_fault", predicate, fault))
    det = Obligation(Outcome.INCONCLUSIVE, note="no certified safe exterior")
    safe_guard = None
    if coverage.outcome is Outcome.PROVED and outside_reach.outcome is Outcome.VIOLATED:
        det = run(gen.gen_determinism(out / "outside_determinism", "p0", guard=complement))
        if det.outcome is Outcome.PROVED:
            safe_guard = complement

    exact_ub = None
    exact_nd = None
    if coverage.outcome is Outcome.PROVED and exact_inside.outcome is Outcome.PROVED:
        exact_ub = predicate
        # Defined executions are deterministic outside exact UB. UB executions
        # are not evidence of benign nondeterminism.
        if det.outcome is Outcome.PROVED:
            exact_nd = "false"
    result = RegionResult(gen.profile.sha256, p0.source_sha256, predicate, exact_ub,
                          exact_nd, safe_guard, coverage, inside, inside_reach,
                          exact_inside, det, outside_reach)
    (out / "regions.json").write_text(json.dumps(asdict(result), indent=2) + "\n")
    return result
