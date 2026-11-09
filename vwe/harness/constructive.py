"""A bounded witness plan for the equality fragment of VE-DSL-1."""
from __future__ import annotations

from dataclasses import dataclass

from ..contract.ast import Binary, Expr, Index, Literal, Name, Sort
from ..contract.env import TypeEnv
from ..contract.typecheck import typecheck


@dataclass(frozen=True)
class Assignment:
    name: str
    index: int | None
    value: Expr


def assignments(expression: Expr, env: TypeEnv) -> tuple[Assignment, ...] | None:
    """Recognize conjunctions of output = input-expression.

    Conflicting assignments are retained. The generated job checks the whole
    conjunction after writing the tuple, including simultaneous active clauses.
    """
    if isinstance(expression, Literal) and expression.value is True:
        return ()
    if isinstance(expression, Binary) and expression.op == "&&":
        left = assignments(expression.left, env)
        right = assignments(expression.right, env)
        return None if left is None or right is None else (*left, *right)
    if not isinstance(expression, Binary) or expression.op != "==":
        return None
    for target, value in ((expression.left, expression.right),
                          (expression.right, expression.left)):
        index = None
        if isinstance(target, Index):
            if not (isinstance(target.index, Literal) and type(target.index.value) is int
                    and 0 <= target.index.value < 64 and isinstance(target.base, Name)):
                continue
            index = target.index.value
            target = target.base
        if not isinstance(target, Name):
            continue
        symbol = env.symbols.get(target.value)
        if not symbol or symbol.role != "output" or (symbol.sort is Sort.BUFFER) != (index is not None):
            continue
        typed = typecheck(value, env)
        if all(env.symbols[n].role != "output" for n in typed.used_symbols):
            return (Assignment(symbol.name, index, value),)
    return None
