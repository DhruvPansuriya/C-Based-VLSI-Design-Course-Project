"""Independent simulation/synthesis analysis views with immutable evidence."""
from __future__ import annotations
from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path
import re
from .c_frontend import Analysis, Finding, UnsupportedC, analyze, renamed, source_policy, without_comments
from .tools import frontend


class ViewError(ValueError):
    pass


class ForbiddenViewError(ViewError):
    def __init__(self, findings: tuple[Finding, ...]) -> None:
        self.findings = findings
        super().__init__("forbidden construct: " + "; ".join(f.detail for f in findings))


def _lexical_forbidden(text: str, mode: str) -> tuple[Finding, ...]:
    clean = without_comments(text)
    def mask(match: re.Match[str]) -> str:
        return "".join("\n" if c=="\n" else " " for c in match.group())
    clean = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', mask, clean)
    clean = re.sub(r"(?m)^[^\S\n]*#.*$", mask, clean)
    findings = []
    for match in re.finditer(r"\b[A-Za-z_][A-Za-z0-9_]*\b", clean):
        word = match.group()
        if word.startswith(("__CPROVER", "__ESBMC", "__VERIFIER", "__vwe_", "VE_")):
            code = "VERIFIER_IDENTIFIER"
        elif word in {"asm", "__asm", "__asm__"}:
            code = "INLINE_ASSEMBLY"
        else:
            continue
        findings.append(Finding(code, word, f"{mode}/preprocessed.c:{clean.count(chr(10),0,match.start())+1}"))
    return tuple(findings)


@dataclass(frozen=True)
class BuildView:
    mode: str
    preprocessed: Path
    renamed: Path
    sha256: str
    renamed_sha256: str
    canonical: str
    entry_point: str
    symbols: tuple[tuple[str, str], ...]
    preprocessor: str
    commands: tuple[frontend.CommandResult, ...]
    analysis: Analysis


@dataclass(frozen=True)
class Views:
    sim: BuildView
    synth: BuildView
    source_sha256: str

    @property
    def views_differ(self) -> bool:
        return self.sim.canonical != self.synth.canonical

    @property
    def qualified_preprocessing(self) -> bool:
        return all(v.preprocessor == "cbmc" for v in (self.sim, self.synth))


def make_views(src: str | Path, fn: str, out_dir: str | Path, *, prefix: str = "p1",
               timeout_s: int = 600, fallback_cc: str = "gcc") -> Views:
    """Snapshot one C translation unit; never share macros with the harness.

    Only direct standard headers are supported until task dependency snapshots
    are modeled. Fallback output is retained, but marked unqualified.
    """
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", fn):
        raise ViewError("Invalid function identifier")
    raw = Path(src).read_bytes()
    try:
        source = raw.decode("utf-8")
    except UnicodeError as exc:
        raise ViewError("C source must be UTF-8") from exc
    policy = source_policy(source)
    if policy:
        raise ViewError("; ".join(f"{p.code}: {p.detail}" for p in policy))
    out_dir = Path(out_dir).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "original.c").write_bytes(raw)
    built: list[BuildView] = []
    for mode in ("sim", "synth"):
        folder = out_dir / mode; folder.mkdir(parents=True, exist_ok=True)
        # CBMC6.11 has no -U option. An explicit wrapper clears any inherited
        # definition; synthesis analysis then defines it. Vitis sets its own.
        control = "#undef __SYNTHESIS__\n"
        if mode == "synth": control += "#define __SYNTHESIS__ 1\n"
        else: control += "\n"
        wrapper = folder / "unit.c"
        wrapper.write_text(control + '#line 1 "input.c"\n' + source, encoding="utf-8")
        text, commands, provider = frontend.preprocess(wrapper, synth=mode=="synth",
                                                       timeout_s=timeout_s, fallback_cc=fallback_cc)
        (folder / "preprocess-commands.json").write_text(json.dumps([c.record() for c in commands], indent=2)+"\n")
        if provider == "failed":
            raise ViewError(f"{mode} preprocessing failed: {commands[-1].error or commands[-1].stderr[-1000:]}")
        prepared = folder / "preprocessed.c"; prepared.write_text(text, encoding="utf-8")
        forbidden = _lexical_forbidden(text, mode)
        if forbidden:
            raise ForbiddenViewError(forbidden)
        try:
            analysis = analyze(text, fn)
            code, symbols = renamed(analysis, prefix)
        except UnsupportedC as exc:
            raise ViewError(str(exc)) from exc
        rewritten = folder / "renamed.c"; rewritten.write_text(code, encoding="utf-8")
        from pycparser import c_generator
        canonical = c_generator.CGenerator().visit(analysis.ast)
        built.append(BuildView(mode, prepared, rewritten, sha256(text.encode()).hexdigest(),
                               sha256(code.encode()).hexdigest(), canonical, f"{prefix}_{fn}",
                               symbols, provider, commands, analysis))
    result = Views(built[0], built[1], sha256(raw).hexdigest())
    manifest = {
        "source_sha256": result.source_sha256, "function": fn,
        "analysis_views_only": True, "views_differ": result.views_differ,
        "qualified_preprocessing": result.qualified_preprocessing,
        "views": [{"mode": v.mode, "preprocessed_sha256": v.sha256,
                   "renamed_sha256": v.renamed_sha256, "entry_point": v.entry_point,
                   "symbols": dict(v.symbols), "preprocessor": v.preprocessor} for v in built],
    }
    (out_dir / "views.json").write_text(json.dumps(manifest, indent=2)+"\n")
    return result
