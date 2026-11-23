"""Build sanitizer drivers and run them with network isolation."""
from __future__ import annotations

from dataclasses import asdict, dataclass
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import subprocess
import sys
import time
from typing import Sequence

from .frontend import CommandResult, execute

SANITIZER_FLAGS = ("-std=c11", "-g", "-O0", "-fno-sanitize-recover=all")
_FAULT = re.compile(r"(?:ERROR: AddressSanitizer: (?P<asan>[\w-]+)|runtime error: (?P<ubsan>[^\n]+))")


@dataclass(frozen=True)
class NativeResult:
    outcome: str
    outputs: dict[str, str]
    command: CommandResult | None
    detail: str = ""

    def record(self) -> dict:
        return asdict(self)


def _sandbox(executable: Path) -> tuple[str, ...] | None:
    if sys.platform == "darwin" and Path("/usr/bin/sandbox-exec").is_file():
        return ("/usr/bin/sandbox-exec", "-p",
                "(version 1) (allow default) (deny network*) (deny file-write*)",
                str(executable))
    if sys.platform.startswith("linux") and (tool := shutil.which("bwrap")):
        return (tool, "--unshare-all", "--die-with-parent", "--ro-bind", "/", "/",
                "--dev", "/dev", "--proc", "/proc", "--", str(executable))
    return None


def sandbox_available() -> bool:
    true = Path("/usr/bin/true")
    command = _sandbox(true)
    if command is None:
        return False
    return execute(command, cwd=Path.cwd(), timeout_s=5).ok


def compile_driver(files: Sequence[Path], out: Path, *, cc: str = "gcc",
                   sanitizers: str = "address,undefined", timeout_s: int = 30) -> CommandResult:
    allowed = {"address", "undefined"}
    chosen = sanitizers.split(",")
    if not chosen or not set(chosen) <= allowed:
        raise ValueError("native replay requires only supported sanitizer names")
    return execute([cc, *SANITIZER_FLAGS, "-fsanitize=" + sanitizers,
                    *[str(p.resolve()) for p in files], "-o", str(out.resolve())],
                   cwd=out.parent.resolve(), timeout_s=timeout_s)


def _execute_driver(command: Sequence[str], cwd: Path, timeout: int) -> CommandResult:
    # Set small CPU, output-file and descriptor bounds without capping the
    # large virtual address reservation needed by AddressSanitizer.
    executable = shutil.which("sh")
    if executable is None:
        return CommandResult(tuple(command), str(cwd), None, "", "", 0, "sh unavailable")
    shell = "ulimit -c 0 && ulimit -t 5 && ulimit -f 2048 && ulimit -n 64 && exec " + shlex.join(command)
    argv = [executable, "-c", shell]
    begin = time.monotonic()
    # Symbolization can launch slow helper processes under the isolated
    # runtime. Replay needs the sanitizer diagnostic, not symbolic stack names.
    env = {"PATH": "/usr/bin:/bin", "LC_ALL": "C",
           "ASAN_OPTIONS": "detect_leaks=0:symbolize=0",
           "UBSAN_OPTIONS": "halt_on_error=1:symbolize=0", "TMPDIR": str(cwd)}
    try:
        with subprocess.Popen(argv, cwd=cwd, env=env, stdin=subprocess.DEVNULL,
                              stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
                              encoding="utf-8", errors="replace", start_new_session=True) as process:
            try:
                stdout, stderr = process.communicate(timeout=timeout)
            except subprocess.TimeoutExpired:
                os.killpg(process.pid, signal.SIGKILL)
                stdout, stderr = process.communicate()
                return CommandResult(tuple(argv), str(cwd), None, stdout, stderr,
                                     time.monotonic() - begin, "timeout")
            return CommandResult(tuple(argv), str(cwd), process.returncode, stdout, stderr,
                                 time.monotonic() - begin)
    except OSError as exc:
        return CommandResult(tuple(argv), str(cwd), None, "", "", time.monotonic() - begin, str(exc))


def run_driver(executable: Path, arguments: Sequence[str], *, timeout_s: int = 10) -> NativeResult:
    if timeout_s < 1:
        raise ValueError("native timeout must be positive")
    executable = executable.resolve()
    sandbox = _sandbox(executable)
    if sandbox is None:
        return NativeResult("unsupported", {}, None, "no qualified network isolation facility")
    run = _execute_driver((*sandbox, *arguments), executable.parent, timeout_s)
    if run.error:
        return NativeResult("error", {}, run, run.error)
    fault = _FAULT.search(run.stderr)
    if fault and run.returncode:
        return NativeResult("sanitizer", {}, run, fault["asan"] or fault["ubsan"])
    if run.returncode == 77:
        return NativeResult("invalid_input", {}, run, "missing or out-of-profile input")
    if not run.ok:
        return NativeResult("error", {}, run, "native driver did not complete")
    outputs: dict[str, str] = {}
    for line in run.stdout.splitlines():
        name, separator, value = line.partition("\t")
        if not separator or name in outputs or not re.fullmatch(r"-?[0-9]+", value):
            return NativeResult("error", {}, run, "invalid native output record")
        outputs[name] = value
    return NativeResult("clean", outputs, run)
