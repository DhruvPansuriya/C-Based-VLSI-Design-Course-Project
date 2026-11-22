#!/usr/bin/env python3
"""Fetch benchmark sources at pinned commits into third_party/ (git-ignored).

Pins were the remote HEADs observed with `git ls-remote` on 2026-11-23. A fetch of
a different commit is refused. MANIFEST.json records commit, license-file hashes
and the fetch time; it does not grant any license beyond the upstream terms.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
from hashlib import sha256
import json
from pathlib import Path
import subprocess

SOURCES = {
    "Chrysalis-HLS": ("https://github.com/UIUC-ChenLab/Chrysalis-HLS.git",
                      "63be1a13a706cdbef4b88fab25aa21167f978b74"),
    "MachSuite": ("https://github.com/breagen/MachSuite.git",
                  "6236e593012cb86b0d2f08d9fb9ba0411ff989b4"),
    "CHStone": ("https://github.com/ferrandi/CHStone.git",
                "2b7e20ffd3365016faf1e4e2b86496a5c95445fb"),
}
LICENSE_NAMES = ("LICENSE", "LICENSE.txt", "LICENSE.md", "COPYING", "README", "README.md")


def git(args: list[str], cwd: Path, timeout: int = 600) -> str:
    done = subprocess.run(["git", *args], cwd=cwd, capture_output=True, text=True, timeout=timeout)
    if done.returncode != 0:
        raise RuntimeError(f"git {' '.join(args)} failed: {done.stderr.strip()[:400]}")
    return done.stdout.strip()


def fetch(name: str, url: str, commit: str, root: Path) -> dict:
    dest = root / name
    if not (dest / ".git").is_dir():
        dest.mkdir(parents=True, exist_ok=True)
        git(["init", "-q"], dest)
        git(["remote", "add", "origin", url], dest)
    probe = subprocess.run(["git", "rev-parse", "-q", "--verify", "HEAD"], cwd=dest,
                           capture_output=True, text=True, timeout=30)
    current = probe.stdout.strip() if probe.returncode == 0 else ""
    if current != commit:
        git(["fetch", "-q", "--depth", "1", "origin", commit], dest)
        git(["checkout", "-q", "--detach", "FETCH_HEAD"], dest)
    head = git(["rev-parse", "HEAD"], dest)
    if head != commit:
        raise RuntimeError(f"{name}: checked out {head}, expected pinned {commit}")
    licenses = {p.name: sha256(p.read_bytes()).hexdigest() for n in LICENSE_NAMES
                if (p := dest / n).is_file()}
    return {"url": url, "commit": head, "path": str(dest.relative_to(root.parent)),
            "license_files_sha256": licenses}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", type=Path, default=Path("third_party"))
    ap.add_argument("--only", action="append", choices=sorted(SOURCES))
    args = ap.parse_args()
    args.root.mkdir(exist_ok=True)
    manifest = {"fetched_utc": datetime.now(timezone.utc).isoformat(), "sources": {}}
    for name in args.only or SOURCES:
        url, commit = SOURCES[name]
        manifest["sources"][name] = fetch(name, url, commit, args.root.resolve())
        print(f"{name}: {commit}", flush=True)
    (args.root / "MANIFEST.json").write_text(json.dumps(manifest, indent=2) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
