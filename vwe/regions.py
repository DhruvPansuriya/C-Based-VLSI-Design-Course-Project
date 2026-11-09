"""P0-only computed regions, with separate coverage and exactness evidence."""
from __future__ import annotations

from dataclasses import asdict, dataclass
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


def compute_regions(p0: Views, shape: Mapping[str, Any], out: Path, *,
                    proposed_ub: str | None = None, config: Config | None = None,
                    parallel: bool = True) -> RegionResult:
    """Certify what the bounded queries support for one exact input profile.

    Safety outside P plus a witness inside P certifies an overapproximation.
    Exactness additionally requires a universally failing operation inside P.
    The initial direct-read certificate is one supported way to establish it.
    """
    gen = Generator(p0, p0, shape, config=config)
    read = _initial_buffer_read(gen)
    lengths = {name: length for name, length, _ in gen.profile.lengths}
    fault = f"({lengths[read[0]]}) <= {read[1]}" if read else None
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
