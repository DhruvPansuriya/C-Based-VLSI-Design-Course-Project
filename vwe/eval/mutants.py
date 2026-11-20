"""Deterministic mutation operators on P_ref (T16) and token-level deduplication."""
from __future__ import annotations

from dataclasses import dataclass
import re
import subprocess

from ..c_frontend import without_comments

# Token patterns; `<<`, `>>`, `->` and `<=`/`>=` are matched as whole tokens first.
_TOKEN = re.compile(r"<<=?|>>=?|->|<=|>=|==|!=|&&|\|\||[<>]|\b\d+\b|\bif\s*\(|\bmin\b|\bmax\b")
_REL = {"<": "<=", "<=": "<", ">": ">=", ">=": ">", "==": "!=", "!=": "=="}


@dataclass(frozen=True)
class Mutant:
    operator: str
    site: int
    description: str
    text: str


def _code_spans(text: str) -> list[tuple[int, int]]:
    """Character spans outside preprocessor lines, comments and literals."""
    spans, pos = [], 0
    for line in text.splitlines(keepends=True):
        if not line.lstrip().startswith("#"):
            spans.append((pos, pos + len(line)))
        pos += len(line)
    return spans


def _sites(text: str) -> list[tuple[str, int, int, str, str]]:
    blanked = without_comments(text)
    if len(blanked) != len(text):  # comment removal must preserve offsets for site mapping
        blanked = text
    out = []
    for lo, hi in _code_spans(text):
        for m in _TOKEN.finditer(blanked, lo, hi):
            tok = m.group(0)
            if tok in _REL:
                out.append(("relational", m.start(), m.end(), tok, _REL[tok]))
            elif tok.isdigit():
                value = int(tok)
                out.append(("constant+1", m.start(), m.end(), tok, str(value + 1)))
                if value > 0:
                    out.append(("constant-1", m.start(), m.end(), tok, str(value - 1)))
            elif tok.startswith("if"):
                close = _matching_paren(text, m.end() - 1)
                if close is not None:
                    out.append(("delete-guard", m.end(), close, text[m.end():close], "1"))
            elif tok in ("min", "max"):
                out.append(("swap-min-max", m.start(), m.end(), tok, "max" if tok == "min" else "min"))
    return out


def _matching_paren(text: str, open_at: int) -> int | None:
    depth = 0
    for i in range(open_at, len(text)):
        depth += text[i] == "("
        depth -= text[i] == ")"
        if depth == 0:
            return i
    return None


def compiles(text: str, timeout_s: int = 30) -> bool:
    done = subprocess.run(["cc", "-fsyntax-only", "-std=c11", "-x", "c", "-"], input=text,
                          capture_output=True, text=True, timeout=timeout_s)
    return done.returncode == 0


def normalised(text: str) -> str:
    """Comment- and whitespace-insensitive token stream used for deduplication."""
    return " ".join(re.findall(r"[A-Za-z_]\w*|\d+|\S", without_comments(text)))


def mutants(p_ref: str, *, limit: int = 8) -> list[Mutant]:
    """Up to `limit` compiling mutants at evenly spaced sites (deterministic)."""
    sites = _sites(p_ref)
    if not sites:
        return []
    step = max(1, len(sites) // (limit * 2))
    chosen, seen = [], {normalised(p_ref)}
    for index in range(0, len(sites), step):
        op, lo, hi, old, new = sites[index]
        text = p_ref[:lo] + new + p_ref[hi:]
        key = normalised(text)
        if key in seen or not compiles(text):
            continue
        seen.add(key)
        line = p_ref[:lo].count("\n") + 1
        chosen.append(Mutant(op, index, f"line {line}: {old!r} -> {new!r}", text))
        if len(chosen) >= limit:
            break
    return chosen


def deduplicate(named: dict[str, str]) -> tuple[dict[str, str], dict[str, str]]:
    """Keep the first of each normalised duplicate; returns (kept, dropped->kept)."""
    kept, dropped, owner = {}, {}, {}
    for name, text in named.items():
        key = normalised(text)
        if key in owner:
            dropped[name] = owner[key]
        else:
            owner[key] = name
            kept[name] = text
    return kept, dropped
