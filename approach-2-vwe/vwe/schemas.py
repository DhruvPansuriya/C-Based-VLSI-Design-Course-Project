"""Load and validate the project's JSON Schemas (directory: schemas/).

Schemas reference each other by file name (e.g. interpretation_set -> interpretation),
so a referencing.Registry with all schemas is built once.
"""
from __future__ import annotations

import json
from functools import lru_cache
from pathlib import Path

from jsonschema import Draft202012Validator
from referencing import Registry, Resource
from .config import data_path

SCHEMA_DIR = data_path("schemas")


@lru_cache(maxsize=None)
def _registry() -> Registry:
    reg = Registry()
    for p in SCHEMA_DIR.glob("*.schema.json"):
        doc = json.loads(p.read_text())
        res = Resource.from_contents(doc)
        reg = reg.with_resource(doc["$id"], res).with_resource(p.name, res)
    return reg


def load(name: str) -> dict:
    return json.loads((SCHEMA_DIR / f"{name}.schema.json").read_text())


def validate(name: str, instance: dict) -> None:
    Draft202012Validator(load(name), registry=_registry()).validate(instance)
