#!/usr/bin/env python3
"""Ask configured model families for candidate fixes (P0 + N only; bounded call budget).

Families come from config/llm.toml. Unconfigured families are recorded as
unavailable; nothing is substituted. Output: candidates/llm_<family>_<k>.c and
candidates/llm_provenance.json. Run scripts/gen_mutants.py afterwards to rebuild pools.
"""
from __future__ import annotations

import argparse
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.eval.candidate_gen import CandidateGenerator  # noqa: E402
from vwe.llm import load_llm_settings, make_provider  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--family", action="append", required=True)
    ap.add_argument("--tasks", type=Path, default=Path("benchmarks/tasks"))
    ap.add_argument("--samples", type=int, default=5)
    ap.add_argument("--max-calls", type=int, default=50, help="total provider-call budget per family")
    ap.add_argument("--cache-dir", type=Path, default=Path("~/.cache/vwe/llm").expanduser())
    ap.add_argument("--fixtures", type=Path, help="mock fixture directory (label 'candidate')")
    args = ap.parse_args()
    settings = load_llm_settings()
    gens = {}
    for fam in args.family:
        cfg = settings.families[fam]
        provider = make_provider(cfg.adapter, fam, cfg.model_id, cfg.api_key_env,
                                 timeout_s=settings.timeout_s, fixture_dir=args.fixtures,
                                 api_key_file=cfg.api_key_file)
        gens[fam] = CandidateGenerator(provider, cfg.model_id, args.cache_dir, max_calls=args.max_calls)
    for root in sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file()):
        manifest = json.loads((root / "task.json").read_text())
        p0, request = (root / "p0.c").read_text(), (root / "request.txt").read_text().strip()
        prov = {}
        for fam, gen in gens.items():
            recs = gen.generate(p0, request, manifest["function"], root / "candidates", args.samples)
            prov[fam] = gen.provenance(recs)
            print(root.name, fam, [r.status for r in recs], flush=True)
        (root / "candidates/llm_provenance.json").write_text(json.dumps(prov, indent=2) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
