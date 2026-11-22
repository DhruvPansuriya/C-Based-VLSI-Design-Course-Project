"""Immutable syntax and type records for VE-DSL-1."""
from __future__ import annotations
from dataclasses import dataclass
from enum import Enum
from typing import Union


class GrammarError(ValueError): pass
class ContractTypeError(ValueError): pass
class LoweringError(ValueError): pass
class ContractUndefined(ValueError): pass


@dataclass(frozen=True)
class Literal:
    value: int | bool

@dataclass(frozen=True)
class Name:
    value: str

@dataclass(frozen=True)
class Unary:
    op: str
    operand: Expr

@dataclass(frozen=True)
class Binary:
    op: str
    left: Expr
    right: Expr

@dataclass(frozen=True)
class Conditional:
    condition: Expr
    yes: Expr
    no: Expr

@dataclass(frozen=True)
class Index:
    base: Expr
    index: Expr

@dataclass(frozen=True)
class Call:
    name: str
    arguments: tuple[Expr, ...]

@dataclass(frozen=True)
class Reduction:
    kind: str
    binder: str
    lower: Expr
    upper: Expr
    body: Expr

Expr = Union[Literal,Name,Unary,Binary,Conditional,Index,Call,Reduction]


class Sort(str,Enum):
    INT='integer'
    BOOL='boolean'
    BUFFER='buffer'


@dataclass(frozen=True)
class Interval:
    low: int
    high: int

    def __post_init__(self) -> None:
        if self.low > self.high: raise ValueError('invalid interval')


@dataclass(frozen=True)
class NodeType:
    sort: Sort
    interval: Interval | None
    cost: int = 1


class ContractUnsupported(ValueError):
    """A capability/resource limit: downstream validation must remain UNKNOWN."""
