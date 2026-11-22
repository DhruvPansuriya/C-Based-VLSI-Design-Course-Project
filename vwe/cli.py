"""Command-line entry point for the bounded verification pipeline."""
from __future__ import annotations

import argparse
from pathlib import Path

from . import __version__


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Verdicts with Evidence")
    parser.add_argument("--version", action="version", version=__version__)
    commands = parser.add_subparsers(dest="command")
    one = commands.add_parser("verify", help="verify one candidate and write evidence")
    one.add_argument("task_dir", type=Path)
    one.add_argument("--candidate", required=True)
    one.add_argument("--json", type=Path)
    one.add_argument("--html", type=Path)
    all_candidates = commands.add_parser("verify-all", help="verify each candidate in a task")
    all_candidates.add_argument("task_dir", type=Path)
    for command in (one, all_candidates):
        command.add_argument("--runs-root", type=Path, default=Path("runs"))
        command.add_argument("--config", type=Path)
        command.add_argument("--auto", action="store_true")
    interpret = commands.add_parser("interpret", help="show interpretation generation availability")
    interpret.add_argument("task_dir", type=Path)
    args = parser.parse_args(argv)
    if args.command is None:
        parser.print_help()
        return 0
    if args.command == "interpret":
        parser.error("automatic interpretation generation is not configured")

    from .config import ConfigError, load_config
    from .pipeline import verify
    from .report import write_json
    from .tasks import TaskError, load_pipeline_view

    try:
        config = load_config(args.config)
        mode = "auto" if args.auto else "handwritten"
        ids = ((args.candidate,) if args.command == "verify"
               else tuple(load_pipeline_view(args.task_dir).candidates))
        for candidate in ids:
            report = verify(args.task_dir, candidate, config, mode, runs_root=args.runs_root)
            data = report.data
            values = data["witness"]["inputs"] if data.get("witness") else {}
            witness = ", ".join(f"{k}={v}" for k, v in values.items())
            suffix = f"  witness: {witness}" if witness else ""
            label = f"{candidate}  " if args.command == "verify-all" else ""
            print(f"{label}{data['decision']}  {data['evidence_class']}  {data['reason']}{suffix}", flush=True)
            if args.command == "verify":
                if args.json:
                    write_json(args.json, data)
                if args.html:
                    report.write_html(args.html)
                print(f"Report: {report.folder / 'report.html'}")
    except (ConfigError, TaskError, OSError) as exc:
        parser.error(str(exc))
    return 0
