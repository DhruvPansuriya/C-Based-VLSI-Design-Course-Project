"""ESBMC confirmation for a qualified source profile.

A successful run is corroboration only. The caller retains the CBMC proofs
and prerequisite checks that support the verdict.
"""
from __future__ import annotations

from dataclasses import dataclass
from enum import Enum
from pathlib import Path
import re
import shutil
from typing import Sequence

from .frontend import CommandResult, execute


class Confirmation(str, Enum):
    AGREE = "agree"
    DISAGREE = "disagree"
    UNSUPPORTED = "unsupported"


@dataclass(frozen=True)
class ConfirmationResult:
    status: Confirmation
    reason: str
    command: CommandResult | None = None


def available() -> bool:
    return shutil.which("esbmc") is not None


def confirm(files: Sequence[Path], *, unwind: int, cwd: Path, timeout_s: int = 600,
            defines: Sequence[str] = ()) -> ConfirmationResult:
    if unwind < 1:
        raise ValueError("ESBMC unwind bound must be positive")
    if not files:
        return ConfirmationResult(Confirmation.UNSUPPORTED, "no qualified source files")
    if not available():
        return ConfirmationResult(Confirmation.UNSUPPORTED, "ESBMC unavailable")
    # ESBMC cannot replay CBMC's pointer-identity intrinsics or its instrumented
    # GOTO image. Only the source-level confirmation subset is accepted here.
    unsupported = re.compile(r"\b(?:__CPROVER_(?!(?:assume|assert|output)\b)\w+|"
                             r"malloc|calloc|realloc|free|abort|exit|_Exit|_exit|"
                             r"quick_exit|longjmp|_longjmp|siglongjmp)\b")
    if any(p.suffix != ".c" or unsupported.search(p.read_text()) for p in files):
        return ConfirmationResult(Confirmation.UNSUPPORTED, "requires a different ESBMC model")
    if any(d.split("=", 1)[0].startswith(("__CPROVER", "__ESBMC")) for d in defines):
        return ConfirmationResult(Confirmation.UNSUPPORTED, "defines cannot override verifier intrinsics")
    intrinsics = ["-D__CPROVER_assume=__ESBMC_assume",
                  "-D__CPROVER_assert=__ESBMC_assert",
                  "-D__CPROVER_output(id,value)=((void)(value))"]
    command = ["esbmc", *[str(f.resolve()) for f in files],
               *intrinsics, *[f"-D{d}" for d in defines], "--unwind", str(unwind), "--z3", "--overflow-check"]
    run = execute(command, cwd=cwd, timeout_s=timeout_s)
    log = run.stdout + "\n" + run.stderr
    markers = re.findall(r"^\s*VERIFICATION (SUCCESSFUL|FAILED|UNKNOWN)\s*$", log, re.M)
    if run.error or len(markers) != 1:
        return ConfirmationResult(Confirmation.UNSUPPORTED, run.error or "no unique ESBMC result", run)
    if markers == ["SUCCESSFUL"] and run.returncode == 0:
        diagnostic = re.search(r"^.*\b(?:ignored|unsupported|assumed away|no body)\b.*$", log, re.I | re.M)
        if diagnostic:
            return ConfirmationResult(Confirmation.UNSUPPORTED, diagnostic[0].strip(), run)
        return ConfirmationResult(Confirmation.AGREE, "ESBMC completed the source check", run)
    if markers == ["FAILED"] and run.returncode == 1:
        if re.search(r"unwinding assertion", log, re.I):
            return ConfirmationResult(Confirmation.UNSUPPORTED, "ESBMC unwind bound exhausted", run)
        return ConfirmationResult(Confirmation.DISAGREE, "ESBMC reported a violation", run)
    return ConfirmationResult(Confirmation.UNSUPPORTED, "unclassified ESBMC result", run)
