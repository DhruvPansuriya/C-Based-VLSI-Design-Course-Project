"""Load versioned prompt files into PromptTemplates (hash covers included text)."""
from __future__ import annotations

from pathlib import Path
import re

from .client import PromptTemplate

PROMPT_DIR = Path(__file__).resolve().parent / "prompts"
PROMPT_NAMES = ("typing", "shape", "strict", "permissive", "adversarial")
_INCLUDE = re.compile(r"\{\{include:(_[a-z]+)\}\}")


def load_prompt(name: str, directory: Path = PROMPT_DIR) -> PromptTemplate:
    text = (directory / f"{name}.md").read_text(encoding="utf-8")
    version = re.match(r"<!-- version: (\w+) -->", text)
    parts = re.split(r"^## (system|user)\n", text, flags=re.M)
    if version is None or parts[1::2] != ["system", "user"]:
        raise ValueError(f"prompt {name}: expected a version comment and system/user sections")
    system, user = (_INCLUDE.sub(lambda m: (directory / f"{m.group(1)}.md").read_text(encoding="utf-8").strip(), body).strip()
                    for body in parts[2::2])
    return PromptTemplate(name, version.group(1), system, user)
