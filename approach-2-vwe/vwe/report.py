"""Validated run reports and a standalone HTML view of the same evidence."""
from __future__ import annotations

from dataclasses import dataclass
from html import escape
import json
from pathlib import Path
from typing import Any
from uuid import uuid4

from .schemas import validate


def write_json(path: Path, record: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + "." + uuid4().hex + ".tmp")
    try:
        temp.write_text(json.dumps(record, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
        temp.replace(path)
    finally:
        temp.unlink(missing_ok=True)


@dataclass(frozen=True)
class VerdictReport:
    folder: Path
    data: dict[str, Any]

    @property
    def decision(self) -> str:
        return self.data["decision"]

    @property
    def evidence_class(self) -> str:
        return self.data["evidence_class"]

    def write(self) -> None:
        validate("verdict_report", self.data)
        write_json(self.folder / "report.json", self.data)
        self.write_html(self.folder / "report.html")

    def write_html(self, destination: Path) -> None:
        def fmt(value: Any) -> str:
            return escape(json.dumps(value, ensure_ascii=False, indent=2))

        d = self.data
        html = ['''<!doctype html>
<html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Verdicts with Evidence</title>
<style>
body {max-width: 68rem; margin: 2rem auto; padding: 0 1rem; font: 1rem/1.55 system-ui,sans-serif; color: #182536}
header {background:#eef3f8; padding:1.2rem; border-left:.4rem solid #2e536d}
pre {background:#f3f6f9; padding:.8rem; overflow:auto; font-size:.85rem}
table {border-collapse:collapse; width:100%}
th,td {text-align:left; padding:.5rem; border-bottom:1px solid #cbd6df; vertical-align:top}
summary {cursor:pointer} h1 {margin:.2rem 0}
</style>
<body>''']
        html += [f'<header><div>{escape(d["task_id"])} / {escape(d["candidate_id"])}</div>',
                 f'<h1>{escape(d["decision"])} {escape(d["evidence_class"])}</h1>',
                 f'<p>{escape(d["reason"])}</p><p>{escape(d["conditional"])}</p></header>']
        html += ["<h2>Witness</h2>"]
        if d.get("witness"):
            html += ["<table><thead><tr><th>Observation</th><th>Value</th></tr></thead><tbody>"]
            for name, value in d["witness"].items():
                html.append(f"<tr><td>{escape(name)}</td><td><pre>{fmt(value)}</pre></td></tr>")
            html.append("</tbody></table>")
        else:
            html.append("<p>No counterexample was reported.</p>")
        html += ["<h2>Interpretations</h2>"]
        for item in d.get("interpretations", ()):
            identity = escape(item["id"])
            rendering = escape(item.get("nl_rendering", ""))
            validation = escape(item["validation"])
            outcome = escape(item.get("outcome", "not checked"))
            html.append(f"<p><strong>{identity}</strong> · {validation} · {outcome}<br>{rendering}</p>")
        html += ["<h2>Obligations</h2><table><tr><th>Query</th><th>Outcome</th><th>Backends and detail</th></tr>"]
        for row in d["obligations"]:
            html.append(f'<tr><td>{escape(row["name"])}</td><td>{escape(row["outcome"])}</td>'
                        f'<td>{escape(row.get("note", ""))}<pre>{fmt(row["backends"])}</pre></td></tr>')
        html.append("</table>")
        for key in ("facts", "scope", "tools", "timing"):
            html.append(f"<h2>{escape(key.title())}</h2><pre>{fmt(d[key])}</pre>")
        html.append("<h2>Generated job sources</h2>")
        for path in sorted(self.folder.rglob("main.c")):
            title = escape(path.parent.relative_to(self.folder).as_posix())
            files = [path, *(p for p in (path.parent / "frame.h", path.parent / "a0.c",
                                       path.parent / "a1.c") if p.is_file())]
            html.append(f"<details><summary>{title}</summary>")
            for source in files:
                html.append(f"<h3>{escape(source.name)}</h3><pre>{escape(source.read_text())}</pre>")
            html.append("</details>")
        html.append("</body></html>")
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text("\n".join(html), encoding="utf-8")
