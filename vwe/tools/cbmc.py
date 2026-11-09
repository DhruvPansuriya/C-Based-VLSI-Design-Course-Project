"""Thin, testable wrapper around CBMC 6.x.

Every flag used here was checked against `cbmc --help` of CBMC 6.11.0 (see
docs/technical-design/03_links_versions_and_verification_log.md).
"""
from __future__ import annotations

import json
import shutil
import subprocess
import time
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Sequence

# Flags applied to every obligation check. Rationale per flag is in the TDD (Section 8.3).
BASE_FLAGS: List[str] = [
    "--bounds-check", "--pointer-check", "--div-by-zero-check",
    "--signed-overflow-check", "--undefined-shift-check", "--pointer-primitive-check",
    "--unwinding-assertions",            # bounded results are flagged, never silently accepted
    "--no-self-loops-to-assumptions",    # keep while(1){} as a loop (spike T01)
    "--no-malloc-may-fail",              # harness buffers model callers' memory, which exists (spike T04)
]

BACKENDS: Dict[str, List[str]] = {
    "sat": [],                                               # CBMC default SAT backend
    "z3": ["--z3"],                                          # CBMC's SMT2 interface to Z3
    "z3-incremental": ["--incremental-smt2-solver", "z3 -smt2 -in"],
}


@dataclass
class PropertyResult:
    property_id: str
    status: str                     # "SUCCESS" | "FAILURE" | other CBMC statuses
    description: str
    witness: Dict[str, str] = field(default_factory=dict)   # last assigned value of each watched input


@dataclass
class CbmcRun:
    ok: bool                        # process ran and produced parseable output
    status: str                     # "success" | "failure" | "error"
    properties: List[PropertyResult]
    seconds: float
    command: List[str]
    stderr_tail: str = ""

    def failed(self, pred=lambda p: True) -> List[PropertyResult]:
        return [p for p in self.properties if p.status == "FAILURE" and pred(p)]


def cbmc_available() -> bool:
    return shutil.which("cbmc") is not None


def version() -> Optional[str]:
    if not cbmc_available():
        return None
    out = subprocess.run(["cbmc", "--version"], capture_output=True, text=True)
    return out.stdout.strip()


def _witness(trace: Sequence[dict], watch: Sequence[str]) -> Dict[str, str]:
    values: Dict[str, str] = {}
    for step in trace:
        if step.get("stepType") == "assignment" and step.get("lhs") in watch:
            values[step["lhs"]] = step.get("value", {}).get("data", "?")
    return values


def run(files: Sequence[str], *, defines: Sequence[str] = (), unwind: Optional[int] = None,
        backend: str = "sat", extra: Sequence[str] = (), watch: Sequence[str] = (),
        timeout_s: int = 600, cwd: Optional[str] = None) -> CbmcRun:
    cmd = ["cbmc", *files, *BASE_FLAGS, *BACKENDS[backend], "--json-ui"]
    cmd += [f"-D{d}" for d in defines]
    if unwind is not None:
        cmd += ["--unwind", str(unwind)]
    cmd += list(extra)
    t0 = time.monotonic()
    try:
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout_s, cwd=cwd)
    except subprocess.TimeoutExpired:
        return CbmcRun(False, "error", [], time.monotonic() - t0, cmd, "timeout")
    dt = time.monotonic() - t0
    try:
        msgs = json.loads(proc.stdout)
    except json.JSONDecodeError:
        return CbmcRun(False, "error", [], dt, cmd, proc.stderr[-2000:] or proc.stdout[-2000:])
    props: List[PropertyResult] = []
    status = "error"
    for m in msgs:
        for r in m.get("result", []) or []:
            props.append(PropertyResult(r["property"], r["status"], r.get("description", ""),
                                        _witness(r.get("trace", []), watch)))
        if "cProverStatus" in m:
            status = m["cProverStatus"]
    return CbmcRun(status in ("success", "failure"), status, props, dt, cmd, proc.stderr[-2000:])
