"""Thin, testable wrapper around CBMC 6.x.

Every flag used here was checked against `cbmc --help` of CBMC 6.11.0 (see
docs/technical-design/03_links_versions_and_verification_log.md).
"""
from __future__ import annotations

import json
import re
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
    returncode: Optional[int] = None
    stdout: str = ""

    def failed(self, pred=lambda p: True) -> List[PropertyResult]:
        return [p for p in self.properties if p.status == "FAILURE" and pred(p)]


def cbmc_available() -> bool:
    return shutil.which("cbmc") is not None


def version() -> Optional[str]:
    if not cbmc_available():
        return None
    try:
        out = subprocess.run(["cbmc", "--version"], capture_output=True, text=True, timeout=10)
    except (OSError, subprocess.TimeoutExpired):
        return None
    return out.stdout.strip() if out.returncode == 0 else None


def _trace_data(value: dict) -> str:
    """Normalize the decimal integer tokens emitted by CBMC's C printer."""
    data = value.get("data", "?")
    if not isinstance(data, str):
        return "?"
    if value.get("name") == "integer":
        match = re.fullmatch(r"([+-]?[0-9]+)(?:[uU](?:[lL]{1,2})?|[lL]{1,2}[uU]?)?", data)
        if match:
            return str(int(match[1], 10))
    return data


def _witness(trace: Sequence[dict], watch: Sequence[str]) -> Dict[str, str]:
    values: Dict[str, str] = {}
    for step in trace:
        if step.get("stepType") == "assignment" and step.get("lhs") in watch:
            values[step["lhs"]] = _trace_data(step.get("value", {}))
        if step.get("stepType") == "output" and step.get("outputID") in watch:
            outputs = step.get("values", [])
            if len(outputs) == 1 and isinstance(outputs[0].get("data"), str):
                values[step["outputID"]] = _trace_data(outputs[0])
    return values


def run(files: Sequence[str], *, defines: Sequence[str] = (), unwind: Optional[int] = None,
        backend: str = "sat", extra: Sequence[str] = (), watch: Sequence[str] = (),
        timeout_s: int = 600, cwd: Optional[str] = None) -> CbmcRun:
    if backend not in BACKENDS:
        raise ValueError(f"Unknown CBMC backend: {backend}")
    if timeout_s <= 0 or (unwind is not None and unwind <= 0):
        raise ValueError("Timeout and supplied unwind must be positive")
    forbidden = {"--no-standard-checks", "--no-assertions", "--partial-loops",
                 "--no-unwinding-assertions", "--no-bounds-check", "--no-pointer-check",
                 "--no-div-by-zero-check", "--no-signed-overflow-check",
                 "--no-undefined-shift-check", "--no-pointer-primitive-check",
                 "--assert-to-assume"}
    if any(option.split("=", 1)[0] in forbidden for option in extra):
        raise ValueError("Extra options cannot disable required verification checks")
    cmd = ["cbmc", *files, *BASE_FLAGS, *BACKENDS[backend], "--json-ui", "--trace"]
    cmd += [f"-D{d}" for d in defines]
    if unwind is not None:
        cmd += ["--unwind", str(unwind)]
    cmd += list(extra)
    t0 = time.monotonic()
    try:
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout_s, cwd=cwd)
    except subprocess.TimeoutExpired:
        return CbmcRun(False, "error", [], time.monotonic() - t0, cmd, "timeout")
    except OSError as exc:
        return CbmcRun(False, "error", [], time.monotonic() - t0, cmd, str(exc))
    dt = time.monotonic() - t0
    try:
        msgs = json.loads(proc.stdout)
    except json.JSONDecodeError:
        return CbmcRun(False, "error", [], dt, cmd, proc.stderr[-2000:] or proc.stdout[-2000:],
                       proc.returncode, proc.stdout)
    props: List[PropertyResult] = []
    status = "error"
    seen_status = False
    try:
        if not isinstance(msgs, list):
            raise ValueError("Expected a JSON message array")
        for m in msgs:
            if not isinstance(m, dict):
                raise ValueError("Expected JSON message objects")
            if m.get("messageType") == "ERROR":
                raise ValueError("Tool error message")
            results = m.get("result", [])
            if not isinstance(results, list):
                raise ValueError("Expected result array")
            for r in results:
                if (not isinstance(r, dict) or not isinstance(r.get("property"), str)
                        or not isinstance(r.get("status"), str)):
                    raise ValueError("Malformed property result")
                props.append(PropertyResult(r["property"], r["status"], r.get("description", ""),
                                            _witness(r.get("trace", []), watch)))
            if "cProverStatus" in m:
                if seen_status:
                    raise ValueError("Duplicate overall status")
                seen_status = True
                status = m["cProverStatus"]
                if not isinstance(status, str):
                    raise ValueError("Malformed overall status")
    except (ValueError, TypeError, KeyError, AttributeError) as exc:
        return CbmcRun(False, "error", [], dt, cmd, f"malformed CBMC JSON: {exc}",
                       proc.returncode, proc.stdout)
    # CBMC 6.11: 0 is success, 10 a verified property failure. Errors cannot
    # become proof evidence even if an incomplete log says success.
    expected_code = {"success": 0, "failure": 10}.get(status)
    ok = expected_code is not None and proc.returncode == expected_code
    return CbmcRun(ok, status if ok else "error", props, dt, cmd, proc.stderr[-2000:],
                   proc.returncode, proc.stdout)
