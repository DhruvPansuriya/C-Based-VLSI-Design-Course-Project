"""Native replay drivers share the verifier's materialization and adapters."""
from __future__ import annotations

from dataclasses import dataclass, replace
from hashlib import sha256
import json
from pathlib import Path
from typing import Any, Mapping, Sequence

from ..contract.env import scalar_type
from ..c_frontend import renamed
from .generate import Generator, _Builder, _literal
from .layout import HarnessUnsupported


@dataclass(frozen=True)
class InputSlot:
    name: str
    minimum: int
    maximum: int


@dataclass(frozen=True)
class Driver:
    folder: Path
    files: tuple[Path, ...]
    slots: tuple[InputSlot, ...]

    def arguments(self, values: dict[str, str]) -> tuple[str, ...]:
        args = []
        for slot in self.slots:
            raw = values.get(slot.name, "?")
            if raw.lower() in ("true", "false"):
                raw = "1" if raw.lower() == "true" else "0"
            try:
                value = int(raw, 10)
            except ValueError:
                args.append("?")
                continue
            args.append(str(value) if slot.minimum <= value <= slot.maximum else "?")
        return tuple(args)


class _NativeBuilder(_Builder):
    def __init__(self, generator: Generator, out: Path, *, build_views: bool = False) -> None:
        super().__init__(generator, out, "native", ())
        self.slots: list[InputSlot] = []
        self.build_views = build_views

    def nondet(self, ctype: str, name: str, limits: tuple[int, int] | None = None,
               *, watch: bool = False) -> None:
        if not watch:
            raise HarnessUnsupported("native driver requires explicit values")
        scalar = scalar_type(("qualified", (), (ctype,)))
        lo, hi = limits or (scalar.limits.low, scalar.limits.high)
        self.slots.append(InputSlot(name, lo, hi))
        position = len(self.slots)
        wide = "long long" if scalar.signed else "unsigned long long"
        fn = "strtoll" if scalar.signed else "strtoull"
        temp = f"__vwe_native_value_{position}"
        n = f"argv[{position}]"
        self.line("errno=0;")
        self.line(f"{wide} {temp}={fn}({n}, &__vwe_end, 10);")
        self.line(f"if (errno || __vwe_end=={n} || *__vwe_end || "
                  f"{temp} < {_literal(lo)} || {temp} > {_literal(hi)}) return 77;")
        self.line(f"{ctype} {name}=({ctype}){temp};")

    def output(self, label: str, value: str, ctype: str) -> None:
        scalar = scalar_type(("qualified", (), (ctype,)))
        wide = "long long" if scalar.signed else "unsigned long long"
        fmt = "%lld" if scalar.signed else "%llu"
        self.line(f'printf("%s\\t{fmt}\\n", {json.dumps(label)}, ({wide})({value}));')

    def driver(self, program: str, interps: Sequence[Mapping[str, Any]] = ()) -> Driver:
        if program not in {"p0", "p1", "checks"}:
            raise ValueError("native driver program must be p0, p1 or checks")
        if any(f.pointer for f in self.layout.returns):
            raise HarnessUnsupported("native replay of returned pointers needs pointer normalization")
        tag, role = ("a0", "zero") if program == "p0" else ("a1", "one")
        self.seed(("zero", "one") if program == "checks" else (role,))
        self.program_call(tag, role)
        if program == "checks":
            self.g._interpretations(interps)
            old_use = any(self.emit(c["behaviour"]).uses_old for it in interps for c in it["clauses"])
            needs_old = "1" if old_use else " || ".join(
                "!(" + self.expression(self.g._zone((it,))) + ")" for it in interps
            ) or "0"
            self.line("if (" + needs_old + ") {")
            self.program_call("a0", "zero")
            self.line("}")
            for i, interp in enumerate(interps):
                zone = self.expression(self.g._zone((interp,)))
                relation = self.clause_relation(interp)
                satisfied = f"(({zone}) || {self.equivalent()}) && ({relation})"
                self.output(f"__vwe_check_{i}", satisfied, "int")
        for j, field in enumerate(self.layout.returns):
            self.output(field.access("ret"), f"__vwe_{role}.r{j}", field.c_type)
        for glob in self.layout.globals:
            for j, field in enumerate(glob.fields):
                self.output(field.access("global " + glob.name),
                            f"__vwe_{role}.g{glob.index}_{j}", field.c_type)
        for p in self.buffers:
            for i in range(self.sizes[p.name][1]):
                self.line(f"if (__vwe_len_{p.index}>{i}) {{")
                for j, field in enumerate(p.fields):
                    self.output(field.access(f"{p.name}[{i}]"),
                                f"__vwe_{tag}_get_{p.index}(__vwe_{role}_b{p.index},{i}).f{j}",
                                field.c_type)
                self.line("}")
            self.line(f"free(__vwe_{role}_b{p.index});")
            if program == "checks":
                self.line(f"free(__vwe_zero_b{p.index});")
            self.line(f"free(__vwe_input_b{p.index});")
        self.line("return 0;")
        header = (
            '#include <stdlib.h>\n#include <stdio.h>\n#include <errno.h>\n#include "frame.h"\n'
            '#define __CPROVER_assume(c) do { if (!(c)) exit(77); } while (0)\n'
            '#define __CPROVER_assert(c,m) do { if (!(c)) exit(77); } while (0)\n'
            + self.layout.prototypes("a0") + self.layout.prototypes("a1")
            + "".join(f.source for f in self.observers)
        )
        main = self.out / "replay.c"
        main.write_text(header + "\nint main(int argc, char **argv) {\n"
                        f"  if (argc != {len(self.slots) + 1}) return 77;\n  char *__vwe_end;\n"
                        + "\n".join(self.lines) + "\n}\n")
        (self.out / "frame.h").write_text(self.layout.header())
        files = [main]
        views = (self.g.p1.sim, self.g.p1.synth) if self.build_views else (self.g.p0.sim, self.g.p1.sim)
        for unit, view in zip(("a0", "a1"), views):
            if unit == "a1" and views[0].entry_point == views[1].entry_point:
                code, symbols = renamed(view.analysis, "vwe_native_second")
                path = self.out / "second_renamed.txt"
                path.write_text(code)
                view = replace(view, renamed=path, renamed_sha256=sha256(code.encode()).hexdigest(),
                               entry_point="vwe_native_second_" + view.analysis.function, symbols=symbols)
            path = self.out / f"{unit}.c"
            path.write_text(self.layout.adapter(view, unit))
            files.append(path)
        return Driver(self.out, tuple(files), tuple(self.slots))


def generate_driver(gen: Generator, out: Path, program: str, *, build_views: bool = False) -> Driver:
    return _NativeBuilder(gen, out, build_views=build_views).driver(program)


def generate_checks(gen: Generator, out: Path, interps: Sequence[Mapping[str, Any]]) -> Driver:
    """Compile the same T03 observers used by formal per-class obligations."""
    return _NativeBuilder(gen, out).driver("checks", interps)
