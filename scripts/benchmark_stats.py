#!/usr/bin/env python3
"""Print the suite/design/bug-type distribution of benchmarks/tasks."""
from __future__ import annotations

from collections import Counter
import json
from pathlib import Path
import sys


def main(root: Path = Path("benchmarks/tasks")) -> int:
    log = json.loads(Path("benchmarks/adaptation_log.json").read_text())
    rows = {r["task_id"]: r for r in log["selected"]}
    tasks = sorted(p.name for p in root.iterdir() if (p / "task.json").is_file())
    print(f"tasks: {len(tasks)}")
    for key in ("suite", "type"):
        counts = Counter(rows[t][key] for t in tasks)
        print(f"by {key}: " + ", ".join(f"{k}={v}" for k, v in sorted(counts.items())))
    designs = Counter((rows[t]["suite"], rows[t]["design"]) for t in tasks)
    print(f"distinct designs: {len(designs)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(*(Path(a) for a in sys.argv[1:])))
