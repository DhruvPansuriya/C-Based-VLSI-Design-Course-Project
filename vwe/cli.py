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
        command.add_argument("--auto", action="store_true",
                             help="use generated interpretations only (never the handwritten ones)")
        command.add_argument("--generated", type=Path,
                             help="saved generated_set.json to use with --auto")
    interpret = commands.add_parser("interpret", help="generate interpretations from P0 and the request only")
    interpret.add_argument("task_dir", type=Path)
    interpret.add_argument("--out", type=Path, help="output folder (default runs/<task>/interpret)")
    for command in (one, all_candidates, interpret):
        command.add_argument("--family", action="append", default=[],
                             help="configured LLM family from config/llm.toml (repeatable)")
        command.add_argument("--llm-config", type=Path)
        command.add_argument("--fixtures", type=Path, help="fixture directory for mock families")
        command.add_argument("--offline", action="store_true", help="read only the response cache")
        command.add_argument("--cache-dir", type=Path)
        command.add_argument("--runs", type=int, default=1)
        command.add_argument("--request", help="request id (default: first request)")
    args = parser.parse_args(argv)
    if args.command is None:
        parser.print_help()
        return 0
    from .config import ConfigError, load_config
    from .pipeline import verify
    from .report import write_json
    from .tasks import TaskError, load_pipeline_view

    def generate(out: Path):
        from .interpret import generate_interpretations
        from .llm import build_client, load_llm_settings
        if not args.family:
            parser.error("choose at least one --family (see config/llm.toml)")
        settings = load_llm_settings(args.llm_config)
        clients = [build_client(settings, f, offline=args.offline, cache_dir=args.cache_dir,
                                log_path=out / "llm_log.jsonl", fixture_dir=args.fixtures)
                   for f in args.family]
        task = load_pipeline_view(args.task_dir)
        return generate_interpretations(task, clients, request_id=args.request, runs=args.runs,
                                        out_dir=out)

    try:
        if args.command == "interpret":
            task_id = load_pipeline_view(args.task_dir).task_id
            out = args.out or Path("runs") / task_id / "interpret"
            result = generate(out)
            print(f"{len(result.members)} interpretation(s), set sha256 {result.sha256}")
            print(f"live families: {', '.join(result.generation['live_families']) or 'none'}")
            print(f"Explanation: {out / 'interpretations.md'}")
            return 0 if result.members else 1
        config = load_config(args.config)
        mode = "auto" if args.auto else "handwritten"
        generated = None
        if args.auto:
            from .interpret import load_generated
            task_id = load_pipeline_view(args.task_dir).task_id
            generated = (load_generated(args.generated) if args.generated
                         else generate(args.runs_root / task_id / "interpret"))
        ids = ((args.candidate,) if args.command == "verify"
               else tuple(load_pipeline_view(args.task_dir).candidates))
        for candidate in ids:
            report = verify(args.task_dir, candidate, config, mode, runs_root=args.runs_root,
                            generated=generated)
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
    except (ConfigError, TaskError, OSError, ValueError) as exc:
        parser.error(str(exc))
    return 0
