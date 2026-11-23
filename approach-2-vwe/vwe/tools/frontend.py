"""Recorded, timeout-bounded frontend commands. No verification verdicts here."""
from __future__ import annotations
from dataclasses import asdict, dataclass
from pathlib import Path
import re
import subprocess
import time
from typing import Sequence
from .cbmc import BASE_FLAGS


@dataclass(frozen=True)
class CommandResult:
    argv: tuple[str, ...]
    cwd: str
    returncode: int | None
    stdout: str
    stderr: str
    seconds: float
    error: str = ""

    @property
    def ok(self) -> bool:
        return self.returncode == 0 and not self.error

    def record(self) -> dict:
        return asdict(self)


def execute(argv: Sequence[str], *, cwd: Path, timeout_s: int) -> CommandResult:
    if timeout_s <= 0:
        raise ValueError("Frontend timeout must be positive")
    start = time.monotonic()
    try:
        p = subprocess.run(list(argv), cwd=cwd, capture_output=True, text=True,
                           encoding="utf-8", errors="replace", timeout=timeout_s)
        return CommandResult(tuple(argv), str(cwd), p.returncode, p.stdout, p.stderr,
                             time.monotonic() - start)
    except subprocess.TimeoutExpired as exc:
        def decode(value: str | bytes | None) -> str:
            return value.decode("utf-8", errors="replace") if isinstance(value, bytes) else value or ""
        return CommandResult(tuple(argv), str(cwd), None, decode(exc.stdout), decode(exc.stderr),
                             time.monotonic() - start, "timeout")
    except OSError as exc:
        return CommandResult(tuple(argv), str(cwd), None, "", "", time.monotonic()-start, str(exc))


def preprocess(src: Path, *, synth: bool, timeout_s: int,
               fallback_cc: str = "gcc") -> tuple[str, tuple[CommandResult, ...], str]:
    """Input is already macro-controlled by the caller's isolated wrapper.

    Fallback output is labeled provisional; admission does not silently qualify it.
    """
    defines = ["-D__SYNTHESIS__=1"] if synth else []
    first = execute(["cbmc", *BASE_FLAGS, "--c11", "--preprocess", "--verbosity", "0",
                     *defines, src.name], cwd=src.parent, timeout_s=timeout_s)
    if first.ok:
        return first.stdout, (first,), "cbmc"
    fallback = execute([fallback_cc, "-std=c11", "-E", "-P", *defines, src.name],
                       cwd=src.parent, timeout_s=timeout_s)
    if fallback.ok:
        return fallback.stdout, (first, fallback), "gcc-fallback-unqualified"
    return "", (first, fallback), "failed"


@dataclass(frozen=True)
class UndefinedFunctions:
    ok: bool
    names: tuple[str, ...]
    commands: tuple[CommandResult, ...]
    reason: str = ""


def list_undefined(src: Path, *, timeout_s: int) -> UndefinedFunctions:
    compiled = execute(["goto-cc", "-c", src.name, "-o", "unit.goto"],
                       cwd=src.parent, timeout_s=timeout_s)
    if not compiled.ok:
        return UndefinedFunctions(False, (), (compiled,), "goto-cc failed")
    listed = execute(["goto-instrument", "unit.goto", "--list-undefined-functions",
                      "--verbosity", "0"], cwd=src.parent, timeout_s=timeout_s)
    if not listed.ok:
        return UndefinedFunctions(False, (), (compiled, listed), "undefined-function listing failed")
    names = tuple(sorted(set(line.strip() for line in listed.stdout.splitlines() if line.strip())))
    # The pinned C-only listing contains one identifier per line. A new format
    # needs qualification instead of guessing around diagnostic banners.
    if any(not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", n) for n in names):
        return UndefinedFunctions(False, (), (compiled, listed), "unrecognized undefined-function listing")
    return UndefinedFunctions(True, names, (compiled, listed))
