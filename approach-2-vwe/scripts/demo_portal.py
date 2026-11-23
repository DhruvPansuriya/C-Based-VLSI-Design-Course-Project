#!/usr/bin/env python3
"""Write runs/index.html: one local web page for the live demo.

It shows the pipeline, the commands to run (copy into a terminal), where the code, inputs,
benchmarks and results are, the saved evaluation numbers (computed from the committed result
files) and every run found under runs/ with a link to its report. It only reads files; it never
runs a verifier. Re-run it after new runs to refresh the table:

    python scripts/demo_portal.py && open runs/index.html
"""
from __future__ import annotations

import argparse
from collections import Counter
from datetime import datetime
import html
import json
import os
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
REPO_URL = "https://github.com/DhruvPansuriya/C-Based-VLSI-Design-Course-Project/tree/main/approach-2-vwe"
EXPECT_P3 = {"equivalent": "ACCEPT", "not_equivalent": "REJECT", "candidate_undefined": "REJECT"}

DEMO_STEPS = [
    ("Bad fix, every stage, pausing after each", "python scripts/demo_steps.py --task ex1_saturate --candidate v3 --interactive",
     "REJECT E1: a=0, b=0 gives 0 in P0 but 255 in P1", "~20 s"),
    ("Correct fix of the same task", "python scripts/demo_steps.py --task ex1_saturate --candidate v1", "ACCEPT E2", "~25 s"),
    ("Subtle tie-break regression", "python scripts/demo_steps.py --task ex2_argmax --candidate v2 --interactive",
     "REJECT E1: all values INT_MAX, idx 0 vs 3", "~30 s"),
    ("HLSCheck fault that passed 264 tests", "python scripts/demo_steps.py --task evaluation/benchmarks/project3/tasks/p3_sf_clamp16 "
     "--candidate candidate --config config/project3.toml", "REJECT E1", "~20 s"),
    ("HLSCheck correct optimisation", "python scripts/demo_steps.py --task evaluation/benchmarks/project3/tasks/p3_expanded_clamp16 "
     "--candidate optimized --config config/project3.toml", "ACCEPT E2", "~25 s"),
    ("All 9 demo cases in one table", "make demo", "9 of 9 rows match; then refresh this page", "1 to 3 min"),
    ("Live LLM readings (needs internet)", "python scripts/demo_steps.py --task ex1_saturate --candidate v3 --auto groq",
     "REJECT E1, with the two models' readings printed", "~1 min"),
    ("Refresh this page with the newest runs", "python scripts/demo_portal.py", "rewrites runs/index.html", "1 s"),
]

STAGES = [
    ("1", "Admission", "parse P0 and P1, same signature, supported C", "vwe/admission.py"),
    ("2", "Readings", "meanings of the request, from P0 + N only", "vwe/interpret.py"),
    ("3a", "P0 regions", "where P0 is safe and deterministic", "vwe/regions.py"),
    ("3b", "Validate", "check readings on P0, then freeze", "vwe/validate.py"),
    ("4", "Prove", "E0 safety, E1 preservation, E2 readings", "vwe/obligations.py"),
    ("5", "Confirm", "fixed-input re-proof, ASan/UBSan replay", "vwe/replay.py"),
    ("6", "Verdict", "ACCEPT / REJECT / UNDECIDED + evidence", "vwe/verdict.py"),
    ("7", "Report", "report.html and report.json", "vwe/report.py"),
]

CODE_MAP = [
    ("vwe/pipeline.py", "the whole pipeline: verify() runs stages 1 to 7"),
    ("vwe/tasks.py", "loads a task; hides the eval/ answers from the pipeline"),
    ("vwe/admission.py, vwe/views.py, vwe/c_frontend.py", "stage 1: admission and build views"),
    ("vwe/contract/", "the small language readings are written in (grammar, type check, evaluation)"),
    ("vwe/interpret.py, vwe/llm/", "stage 2: LLM readings from P0 and the request only (never P1)"),
    ("vwe/regions.py", "stage 3a: P0-only regions and the reference guard"),
    ("vwe/validate.py", "stage 3b: reading checks V-G, V-1 to V-4, freezing"),
    ("vwe/obligations.py, vwe/proof_jobs.py, vwe/harness/", "stage 4: proof obligations and generated C harnesses"),
    ("vwe/tools/cbmc.py", "every CBMC call; BASE_FLAGS are the mandatory flags"),
    ("vwe/replay.py, vwe/tools/native.py", "stage 5: fixed-input re-proof and sanitizer replay"),
    ("vwe/verdict.py", "stage 6: the only place a verdict is decided"),
    ("vwe/report.py", "stage 7: HTML and JSON reports"),
    ("vwe/cli.py", "command line: python -m vwe verify / verify-all / interpret / stability"),
    ("vwe/eval/", "evaluation: labels, mutants, baselines, metrics"),
    ("config/", "bounds and timeouts: default.toml, benchmark.toml, project3.toml, llm.toml"),
    ("tests/", "436 automatic tests (make test); golden expectations in tests/golden/"),
]

DATA_MAP = [
    ("examples/tasks/", "7 golden tasks, 20 candidates, written by us from the design draft", "inputs"),
    ("evaluation/benchmarks/tasks/", "20 Chrysalis-HLS tasks, 97 candidates (generated, not in git)", "inputs"),
    ("evaluation/benchmarks/generated/", "LLM readings for the Chrysalis tasks (gpt-oss-120b, Qwen)", "inputs"),
    ("evaluation/benchmarks/project3/tasks/", "131 HLSCheck (Approach-1) tasks, 181 candidates (generated, not in git)", "inputs"),
    ("runs/", "every run's evidence: runs/&lt;task&gt;/&lt;candidate&gt;/&lt;run id&gt;/ (git-ignored)", "outputs"),
    ("runs/demo/index.html", "the last make demo table", "outputs"),
    ("evaluation/results/eval/summary.md", "Chrysalis evaluation, VWE vs baselines", "saved results"),
    ("evaluation/results/eval_project3/summary.md", "VWE on the 181 HLSCheck cases", "saved results"),
    ("evaluation/results/checkpoints/2026-11-23-t22/", "release checkpoint: golden 20/20, demo, logs", "saved results"),
    ("evaluation/results/auto_vs_handwritten_live.md", "live LLM readings compared with ours", "saved results"),
    ("docs/report/", "reports (PDF) and slides (PPTX) for VWE and HLSCheck", "documents"),
    ("docs/LIVE_DEMO.md", "the demo guide this page summarises", "documents"),
]

RUN_FOLDERS = [
    ("run_manifest.json", "tool versions, file hashes, config"),
    ("admission/", "stage 1 result and parsed programs"),
    ("interpretations/", "stage 3b: validation.json and the frozen reading set"),
    ("regions/", "stage 3a: regions.json"),
    ("e0/, e1/, e1_keep/", "stage 4: harness main.c and verification/ (CBMC commands and SAT/Z3 results)"),
    ("prepass_e1/", "native hint that was then proved formally"),
    ("fixed/0/", "stage 5: re-proof with the witness inputs fixed"),
    ("native/", "stage 5: compiled replay and witness-0.json (real outputs)"),
    ("report.json, report.html", "stages 6 and 7: verdict, evidence, every proof"),
]


def esc(x) -> str:
    return html.escape(str(x))


def rel(target: Path, base: Path) -> str:
    return Path(os.path.relpath(target, base)).as_posix()


def badge(decision: str, cls: str = "") -> str:
    kind = {"ACCEPT": "ok", "REJECT": "bad", "UNDECIDED": "unk"}.get(decision, "unk")
    tail = f" {esc(cls)}" if cls and cls != "-" else ""
    return f'<span class="badge {kind}">{esc(decision)}{tail}</span>'


def load_jsonl(path: Path) -> list[dict]:
    return [json.loads(l) for l in path.read_text().splitlines() if l.strip()] if path.is_file() else []


def find_runs(runs: Path, limit: int) -> list[dict]:
    out = []
    for rep in runs.rglob("report.json"):
        if "checkpoints" in rep.parts:
            continue
        try:
            d = json.loads(rep.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        if "decision" not in d or "task_id" not in d:
            continue
        wit = d.get("witness")
        wtxt = ""
        if isinstance(wit, dict) and isinstance(wit.get("inputs"), dict):
            wtxt = ", ".join(f"{k}={v}" for k, v in list(wit["inputs"].items())[:4])
            p0, p1 = wit.get("p0_output"), wit.get("p1_output")
            if isinstance(p0, dict) and isinstance(p1, dict):
                short = lambda o: ", ".join(f"{k}={v}" for k, v in list(o.items())[:2])
                wtxt += f"  (P0: {short(p0)}; P1: {short(p1)})"
        timing = d.get("timing") if isinstance(d.get("timing"), dict) else {}
        secs = timing.get("wall_seconds")
        out.append({"mtime": rep.stat().st_mtime, "task": d["task_id"], "cand": d.get("candidate_id", "?"),
                    "decision": d["decision"], "cls": d.get("evidence_class") or "-", "reason": d.get("reason", ""),
                    "witness": wtxt, "secs": secs, "dir": rep.parent,
                    "html": rep.with_name("report.html") if rep.with_name("report.html").is_file() else None})
    out.sort(key=lambda r: r["mtime"], reverse=True)
    return out[:limit]


def results_section() -> str:
    parts = []
    gold = ROOT / "evaluation/results/checkpoints/2026-11-23-t22/golden.json"
    if gold.is_file():
        rows = json.loads(gold.read_text())["rows"]
        ok = sum(r["match"] for r in rows)
        parts.append(("Golden examples", f"{ok}/{len(rows)}", "match the hand-worked verdicts"))
    p3 = load_jsonl(ROOT / "evaluation/results/eval_project3/joined.jsonl")
    if p3:
        dec = [r for r in p3 if r["decision"] != "UNDECIDED"]
        agree = sum(EXPECT_P3[r["label"]] == r["decision"] for r in dec)
        parts.append(("HLSCheck cases", f"{agree}/{len(dec)}", f"decided cases agree with the label ({len(dec)} of {len(p3)} decided)"))
    ch = load_jsonl(ROOT / "evaluation/results/eval/raw.jsonl")
    wrong = Counter()
    if ch:
        for r in ch:
            if r["label"] in ("correct", "incorrect") and r["decision"] != "UNDECIDED":
                wrong[r["system"]] += (r["decision"] == "ACCEPT") != (r["label"] == "correct")
        parts.append(("Chrysalis wrong calls", f"{wrong['vwe']} vs {wrong['tests_only']}", "VWE vs a tests-only checker (89 labelled)"))
    cards = "".join(f'<div class="stat"><div class="num">{esc(n)}</div><div class="cap"><b>{esc(t)}</b><br>{esc(c)}</div></div>'
                    for t, n, c in parts)
    tables = ""
    if p3:
        by = Counter()
        for r in p3:
            by[(r["cohort"], r["label"], r["decision"])] += 1
        groups = sorted({(r["cohort"], r["label"]) for r in p3})
        rows = "".join(f"<tr><td>{esc(c)}</td><td>{esc(l)}</td><td>{by[(c, l, 'ACCEPT')]}</td><td>{by[(c, l, 'REJECT')]}</td>"
                       f"<td>{by[(c, l, 'UNDECIDED')]}</td></tr>" for c, l in groups)
        tables += ("<div><h3>VWE on the HLSCheck (Approach-1) cases</h3><table><tr><th>group</th><th>label</th><th>ACCEPT</th>"
                   f"<th>REJECT</th><th>UNDECIDED</th></tr>{rows}</table></div>")
    if ch:
        names = {"vwe": "VWE", "tests_only": "B1 tests only", "single_contract": "B3 strict reading only",
                 "regression_only": "B4 regression only"}
        rows = ""
        for sysname, label in names.items():
            rs = [r for r in ch if r["system"] == sysname and r["label"] in ("correct", "incorrect")]
            dec = sum(r["decision"] != "UNDECIDED" for r in rs)
            rows += f"<tr><td>{esc(label)}</td><td>{len(rs)}</td><td>{dec}</td><td>{wrong[sysname]}</td></tr>"
        tables += ("<div><h3>Chrysalis-HLS benchmark</h3><table><tr><th>system</th><th>labelled</th><th>decided</th>"
                   f"<th>wrong</th></tr>{rows}</table></div>")
    return f'<div class="stats">{cards}</div><div class="two">{tables}</div>'


def example_section(out_dir: Path) -> str:
    t = ROOT / "examples/tasks/ex1_saturate"
    if not t.is_dir():
        return ""
    def code(p: Path) -> str:
        return esc(p.read_text().strip()) if p.is_file() else ""
    return (f'<div class="ex"><div><h4>P0 (original) <a href="{rel(t / "p0.c", out_dir)}">p0.c</a></h4><pre>{code(t / "p0.c")}</pre>'
            f'<h4>N (request) <a href="{rel(t / "request.txt", out_dir)}">request.txt</a></h4><pre>{code(t / "request.txt")}</pre></div>'
            f'<div><h4>P1 v1 (correct)</h4><pre>{code(t / "candidates/v1.c")}</pre>'
            f'<h4>P1 v3 (bad: always 255)</h4><pre>{code(t / "candidates/v3.c")}</pre></div></div>'
            f'<p class="muted">Folder <a href="{rel(t, out_dir)}">examples/tasks/ex1_saturate/</a> also has '
            "<code>task.json</code> (input bounds), <code>interpretations/</code> (our readings) and <code>eval/</code> "
            "(the true answer, used only for scoring, never by the pipeline).</p>")


def build(out: Path, limit: int) -> None:
    out_dir = out.parent
    runs = find_runs(ROOT / "runs", limit)
    run_rows = ""
    for r in runs:
        when = datetime.fromtimestamp(r["mtime"]).strftime("%d %b, %H:%M")
        link = f'<a href="{rel(r["html"], out_dir)}">report</a>' if r["html"] else ""
        folder = f'<a href="{rel(r["dir"], out_dir)}">folder</a>'
        secs = "" if r["secs"] is None else f"{r['secs']:.0f} s"
        run_rows += (f"<tr><td class='nw'>{when}</td><td>{esc(r['task'])}</td><td>{esc(r['cand'])}</td><td>{badge(r['decision'], r['cls'])}</td>"
                     f"<td class='reason'>{esc(r['reason'][:90])}</td><td>{esc(r['witness'])}</td>"
                     f"<td>{secs}</td><td>{link} &middot; {folder}</td></tr>")
    if not run_rows:
        run_rows = '<tr><td colspan="8">No runs yet. Run a command from the list above, then refresh this page.</td></tr>'
    demo = ROOT / "runs/demo/summary.json"
    demo_html = ""
    if demo.is_file():
        d = json.loads(demo.read_text())
        rows = ""
        for r in d.get("rows", []):
            link = f'<a href="{rel(Path(r["report"]), out_dir)}">report</a>' if r.get("report") else ""
            rows += (f"<tr><td>{esc(r.get('label', ''))}</td><td>{badge(r.get('decision', ''), r.get('evidence_class', ''))}</td>"
                     f"<td>{'yes' if r.get('match') else 'NO'}</td><td>{(r.get('seconds') or 0):.1f} s</td><td>{link}</td></tr>")
        when = datetime.fromtimestamp(demo.stat().st_mtime).strftime("%d %b %H:%M")
        demo_html = (f"<h3>Last <code>make demo</code> ({when}, total {d.get('seconds', 0):.0f} s)</h3>"
                     f"<table><tr><th>case</th><th>verdict</th><th>expected</th><th>time</th><th></th></tr>{rows}</table>")
    stages = "".join(f'<div class="stage"><div class="n">{n}</div><b>{esc(h)}</b><span>{esc(t)}</span>'
                     f'<a href="{rel(ROOT / f, out_dir)}"><code>{esc(f)}</code></a></div>' for n, h, t, f in STAGES)
    cmds = "".join(f'<div class="cmd"><div class="ch"><b>{i}. {esc(h)}</b><span>{esc(t)}</span></div>'
                   f'<div class="cl"><code>{esc(c)}</code><button onclick="cp(this)">Copy</button></div>'
                   f'<div class="exp">expected: {esc(e)}</div></div>' for i, (h, c, e, t) in enumerate(DEMO_STEPS, 1))
    def link_of(path: str) -> str:
        first = path.split(",")[0].strip()
        return f'<a href="{rel(ROOT / first, out_dir)}"><code>{esc(path)}</code></a>'
    code_rows = "".join(f"<tr><td>{link_of(p)}</td><td>{esc(t)}</td></tr>" for p, t in CODE_MAP)
    data_rows = "".join(f"<tr><td>{link_of(p)}</td><td>{t}</td><td>{esc(k)}</td></tr>" for p, t, k in DATA_MAP)
    run_folder_rows = "".join(f"<tr><td><code>{esc(p)}</code></td><td>{esc(t)}</td></tr>" for p, t in RUN_FOLDERS)
    docs = ROOT / "docs/report"
    hdocs = ROOT.parent / "approach-1-hlscheck/report"
    doc_links = " &middot; ".join(f'<a href="{rel(d / f, out_dir)}">{esc(n)}</a>' for d, f, n in [
        (docs, "VWE_report.pdf", "VWE report"), (docs, "VWE_slides.pptx", "VWE slides"),
        (hdocs, "HLSCheck_report.pdf", "HLSCheck report"), (hdocs, "HLSCheck_slides.pptx", "HLSCheck slides")])
    dgdir = ROOT / "docs/demo_diagrams"
    figs = [("1_where_is_the_run.png", "1. Terminal STEP heading, phase, code file and run folder"),
            ("2_inside_one_proof.png", "2. Inside one proof: harness, SAT + Z3, witness, confirmations"),
            ("3_verdict_rules.png", "3. How the verdict is decided"), ("4_repo_map.png", "4. Where everything is")]
    diagrams = "".join(f'<figure><a href="{rel(dgdir / f, out_dir)}"><img src="{rel(dgdir / f, out_dir)}" alt="{esc(c)}"></a>'
                       f"<figcaption>{esc(c)} (click to enlarge)</figcaption></figure>" for f, c in figs if (dgdir / f).is_file())
    diagrams = f'<div class="dg">{diagrams}</div>' if diagrams else '<p class="muted">Diagrams not found in docs/demo_diagrams/.</p>'
    page = TEMPLATE.format(diagrams=diagrams, 
        generated=datetime.now().strftime("%d %B %Y, %H:%M"), repo=REPO_URL, stages=stages, cmds=cmds,
        example=example_section(out_dir), runs=run_rows, nruns=len(runs), demo=demo_html, results=results_section(),
        code_rows=code_rows, data_rows=data_rows, run_folder_rows=run_folder_rows, docs=doc_links)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(page)


TEMPLATE = """<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1">
<title>VWE live demo</title>
<style>
body{{font-family:Arial,Helvetica,sans-serif;font-size:15px;line-height:1.45;color:#000;background:#fff;max-width:1100px;margin:20px auto;padding:0 20px}}
h1{{font-size:24px;margin:0 0 4px}} h2{{font-size:19px;margin:28px 0 8px;border-bottom:1px solid #999;padding-bottom:3px}}
h3{{font-size:16px;margin:16px 0 6px}} h4{{font-size:14px;margin:8px 0 4px}}
code,pre{{font-family:Courier New,monospace;font-size:13px}} pre{{background:#f4f4f4;border:1px solid #ccc;padding:6px;white-space:pre-wrap;margin:0}}
table{{border-collapse:collapse;width:100%;font-size:14px;margin:4px 0}} th,td{{border:1px solid #bbb;padding:4px 6px;text-align:left;vertical-align:top}}
th{{background:#eee}} td.nw{{white-space:nowrap}} .muted{{color:#444;font-size:13px}}
.pipe{{display:grid;grid-template-columns:repeat(4,1fr);gap:6px}} .stage{{border:1px solid #bbb;padding:6px;font-size:13px}}
.stage .n{{font-weight:bold}} .stage span{{display:block}}
.cmd{{border:1px solid #bbb;padding:6px 8px;margin:6px 0}} .cl{{display:flex;gap:8px;align-items:flex-start;margin:4px 0}} .cl code{{flex:1;word-break:break-all;background:#f4f4f4;padding:3px}}
.ch span{{float:right;font-size:13px}} .exp{{font-size:13px}}
.stats .stat{{display:inline-block;border:1px solid #bbb;padding:6px 10px;margin:0 6px 6px 0;font-size:13px}} .stat .num{{font-size:20px;font-weight:bold}}
.two,.ex,.dg{{display:grid;grid-template-columns:1fr 1fr;gap:16px}} .dg figure{{margin:0}} .dg img{{width:100%;border:1px solid #bbb}} .dg figcaption{{font-size:13px}}
.badge{{font-weight:bold}} nav a{{margin-right:14px}} section{{margin:0}} header p{{margin:2px 0}} footer{{font-size:12px;color:#444;margin:30px 0}}
@media(max-width:800px){{.two,.ex,.dg,.pipe{{grid-template-columns:1fr}}}}
</style></head><body>
<header><h1>Verdicts with Evidence (VWE): demo page</h1>
<p>C-Based VLSI Design (CS5291), IIT Guwahati &middot; Dhruvkumar R Pansuriya (230101071), Aryan Kaushik (230101018),
Lasya Madhu Sundar (230101058) &middot; Instructor: Dr. Chandan Karfa</p>
<p>Code: <a href="{repo}">GitHub, folder approach-2-vwe</a> &middot; {docs} &middot; page generated {generated}</p></header>
<nav><a href="#pipeline">Pipeline</a><a href="#diagrams">Diagrams</a><a href="#run">Run it</a><a href="#example">Example input</a><a href="#runs">Latest runs</a>
<a href="#results">Results</a><a href="#where">Where things are</a></nav>
<main>
<section id="pipeline"><h2>The pipeline</h2>
<p>Inputs: the original buggy function <b>P0</b>, the request in English <b>N</b>, and the AI's new version <b>P1</b>.
The readings of N are made from P0 and N only; no language model ever sees P1. Every proof runs CBMC twice (SAT and Z3) and
both must agree; every counterexample is re-run as real code. Anything not proved gives UNDECIDED.</p>
<div class="pipe">{stages}</div>
<p><b>E0</b>: P1 has new undefined behaviour where P0 was safe. <b>E1</b>: P1 changed P0's behaviour outside the part the request may change. <b>E2</b>: P1 meets every surviving reading (ACCEPT) or none (REJECT).</p></section>

<section id="diagrams"><h2>Diagrams to explain where the run is</h2>{diagrams}</section>

<section id="run"><h2>Run it (VS Code terminal)</h2>
<p class="muted">Open the repository folder in VS Code, open a terminal (<code>Ctrl + backtick</code>), activate the environment once with
<code>source .venv/bin/activate</code>, then copy the commands below. Each run prints every stage and ends with
<code>Full evidence: runs/.../report.html</code> (Cmd-click it in the VS Code terminal). Run <code>python scripts/demo_portal.py</code> and refresh this page to see it in
the table below.</p>
<div class="cmds">{cmds}</div></section>

<section id="example"><h2>Example input: saturating 8-bit addition</h2>{example}</section>

<section id="runs"><h2>Latest runs ({nruns} shown, newest first)</h2>
<table><tr><th>when</th><th>task</th><th>candidate</th><th>verdict</th><th>reason</th><th>witness</th><th>time</th><th>evidence</th></tr>{runs}</table>
{demo}</section>

<section id="results"><h2>Saved evaluation results</h2>{results}
<p class="muted">Numbers are computed from the committed files in <code>evaluation/results/</code> when this page is generated.
Results hold for each task's declared input sizes and value ranges.</p></section>

<section id="where"><h2>Where things are</h2>
<div class="two"><div><h3>Main code</h3><table><tr><th>path</th><th>what it does</th></tr>{code_rows}</table></div>
<div><h3>Inputs, test cases, results</h3><table><tr><th>path</th><th>what it is</th><th>kind</th></tr>{data_rows}</table>
<h3>Inside one run folder: runs/&lt;task&gt;/&lt;candidate&gt;/&lt;run id&gt;/</h3>
<table><tr><th>file / folder</th><th>what it holds</th></tr>{run_folder_rows}</table></div></div></section>
</main>
<footer>Generated by scripts/demo_portal.py. It only reads files; it does not run any verification.</footer>
<script>function cp(b){{const t=b.previousElementSibling.innerText;navigator.clipboard.writeText(t).then(()=>{{b.innerText="Copied";setTimeout(()=>b.innerText="Copy",1200)}})}}</script>
</body></html>
"""


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", type=Path, default=ROOT / "runs/index.html")
    ap.add_argument("--limit", type=int, default=15, help="how many recent runs to list")
    args = ap.parse_args()
    build(args.out.resolve(), args.limit)
    print(f"wrote {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
