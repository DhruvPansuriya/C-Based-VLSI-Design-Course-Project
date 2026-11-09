"""Foundation CLI. Verification subcommands arrive in milestone T08."""
from __future__ import annotations
import argparse
from . import __version__


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Verdicts with Evidence (foundation build)")
    parser.add_argument("--version", action="version", version=__version__)
    parser.parse_args(argv)
    parser.print_help()
    return 0
