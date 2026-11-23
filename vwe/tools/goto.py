"""Build and qualify a GOTO artifact before solver execution."""
from __future__ import annotations

from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path
import re
from typing import Sequence

from .frontend import CommandResult, execute

PATH_CUTS = frozenset({"abort", "exit", "_Exit", "_exit", "quick_exit",
                       "longjmp", "_longjmp", "siglongjmp"})
_TRAPS = "^(" + "|".join(sorted(PATH_CUTS)) + ")$"
_TRAP_INSTRUCTIONS = (
    "ASSERT false // undefined function should be unreachable",
    "ASSUME false",
    "END_FUNCTION",
)
_BODY_HEADING = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*) /\* [^\n]* \*/$", re.M)


@dataclass(frozen=True)
class PreparedGoto:
    artifact: Path | None
    sha256: str | None
    trapped: tuple[str, ...]
    commands: tuple[CommandResult, ...]
    reason: str = ""

    @property
    def ok(self) -> bool:
        return self.artifact is not None and not self.reason


def _functions(show: str) -> dict[str, tuple[str, ...]]:
    """Read the pinned goto-instrument textual GOTO listing."""
    result = {}
    for block in show.split("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"):
        header = _BODY_HEADING.search(block)
        if header:
            name = header[1]
            if name in result:
                raise ValueError(f"duplicate GOTO function {name}")
            result[name] = tuple(line.strip() for line in block[header.end():].splitlines()
                                 if line.strip() and not line.strip().startswith("//"))
    return result


def prepare(files: Sequence[Path], out: Path, *, timeout_s: int = 60,
            uninitialized_locals: bool = True) -> PreparedGoto:
    """Instrument local initialization, link models, replace cuts, then audit.

    The experimental uninitialized-local pass is additional coverage. Its
    presence does not qualify all C uninitialized reads.
    """
    out = out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    commands: list[CommandResult] = []
    trapped: tuple[str, ...] = ()

    def invoke(argv: list[str]) -> CommandResult:
        run = execute(argv, cwd=out, timeout_s=timeout_s)
        commands.append(run)
        (out / f"{len(commands):02}.stdout").write_text(run.stdout)
        (out / f"{len(commands):02}.stderr").write_text(run.stderr)
        return run

    def finish(reason: str = "") -> PreparedGoto:
        artifact = None if reason else out / "checked.goto"
        digest = sha256(artifact.read_bytes()).hexdigest() if artifact else None
        record = {
            "sha256": digest,
            "reason": reason,
            "traps": list(trapped),
            "uninitialized_local_pass": uninitialized_locals,
            "commands": [{k: v for k, v in c.record().items() if k not in {"stdout", "stderr"}}
                         for c in commands],
        }
        (out / "instrumentation.json").write_text(json.dumps(record, indent=2) + "\n")
        return PreparedGoto(artifact, digest, trapped, tuple(commands), reason)

    paths = [str(p.resolve()) for p in files]
    if not paths:
        return finish("no translation units")

    steps = [("compilation", ["goto-cc", "-std=c11", *paths, "-o", "raw.goto"])]
    link_input = "raw.goto"
    if uninitialized_locals:
        steps.append(("local initialization instrumentation",
                      ["goto-instrument", "--uninitialized-check", "raw.goto", "locals.goto"]))
        link_input = "locals.goto"
    steps.append(("library linking", ["goto-instrument", "--add-library", "--no-malloc-may-fail",
                                           link_input, "linked.goto"]))
    for phase, command in steps:
        run = invoke(command)
        if not run.ok:
            return finish(f"{phase}: {run.error or run.stderr[-800:]}")

    listed = invoke(["goto-instrument", "--list-goto-functions", "linked.goto"])
    if not listed.ok:
        return finish("could not inventory linked functions")
    linked_names = set(_BODY_HEADING.findall(listed.stdout))
    if not {"main", "__CPROVER__start"} <= linked_names:
        return finish("unrecognized linked function inventory")
    trapped = tuple(sorted(linked_names & PATH_CUTS))

    steps = [
        ("path cut removal", ["goto-instrument", "--remove-function-body-regex",
                              _TRAPS, "linked.goto", "removed.goto"]),
        ("path cut trap generation", ["goto-instrument", "--generate-function-body", _TRAPS,
                                      "--generate-function-body-options", "assert-false-assume-false",
                                      "removed.goto", "checked.goto"]),
    ]
    for phase, command in steps:
        run = invoke(command)
        if not run.ok:
            return finish(f"{phase}: {run.error or run.stderr[-800:]}")

    shown = invoke(["goto-instrument", "--show-goto-functions", "checked.goto"])
    if not shown.ok:
        return finish("could not inspect final GOTO instructions")
    try:
        functions = _functions(shown.stdout)
    except ValueError as exc:
        return finish(str(exc))
    if not {"main", "__CPROVER__start"} <= functions.keys():
        return finish("unrecognized final GOTO listing")
    if set(functions) & PATH_CUTS != set(trapped):
        return finish("path cut inventory changed")
    for name in trapped:
        if functions[name] != _TRAP_INSTRUCTIONS:
            return finish(f"missing assert/assume trap in {name}")
    return finish()
