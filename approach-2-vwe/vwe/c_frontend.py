"""Structural C analysis and namespace isolation for the admitted C fragment.

pycparser supplies syntax, not a proof of CBMC equivalence. Unsupported syntax
is retained as a failure; attributes/layout constructs are never erased.
"""
from __future__ import annotations
from copy import deepcopy
from dataclasses import dataclass
import re
from typing import Any
from pycparser import c_ast as C, c_generator, c_parser


class UnsupportedC(ValueError):
    pass


@dataclass(frozen=True)
class Finding:
    code: str
    detail: str
    location: str = ""


@dataclass(frozen=True)
class PragmaUse:
    name: str
    arguments: tuple[str, ...]
    options: tuple[tuple[str, str], ...]
    location: str


@dataclass(frozen=True)
class Analysis:
    ast: C.FileAST
    function: str
    signature: tuple[Any, ...]
    definitions: tuple[str, ...]
    calls: tuple[str, ...]
    globals: tuple[tuple[str, str], ...]
    all_global_names: tuple[str, ...]
    global_types: tuple[tuple[str, tuple], ...]
    prototypes: tuple[tuple[str, tuple], ...]
    pragmas: tuple[PragmaUse, ...]
    forbidden: tuple[Finding, ...]
    unsupported: tuple[Finding, ...]


# Preserve literals and newlines while removing comments. Apply translation-phase
# line splicing first so a continued // comment cannot hide an include.
_LEX = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*', re.S)


def without_comments(text: str) -> str:
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    text = re.sub(r"\\\r?\n", "", text)
    def replace(m: re.Match[str]) -> str:
        token = m.group()
        if token.startswith(("/*", "//")):
            return "".join("\n" if c == "\n" else " " for c in token)
        return token
    return _LEX.sub(replace, text)


def source_policy(text: str) -> tuple[Finding, ...]:
    """Keep snapshot preprocessing within the supported dependency boundary."""
    clean = without_comments(text)
    allowed = {"limits.h", "stdint.h", "stdbool.h", "stddef.h", "string.h", "stdlib.h", "assert.h"}
    findings: list[Finding] = []
    if "\x00" in text:
        findings.append(Finding("UNSUPPORTED_LEXICAL_FORM", "NUL bytes are unsupported"))
    if "\ufeff" in text or re.search(r"\?\?[=/\'()!<>-]", text):
        findings.append(Finding("UNSUPPORTED_LEXICAL_FORM", "BOM/trigraph source forms need separate qualification"))
    for number, line in enumerate(clean.splitlines(), 1):
        if not re.match(r"\s*#", line):
            continue
        if re.match(r"\s*#\s*include\b", line):
            match = re.fullmatch(r'\s*#\s*include\s*[<"]([A-Za-z0-9_.]+)[>"]\s*', line)
            if not match or match[1] not in allowed:
                findings.append(Finding("UNSUPPORTED_INCLUDE", "only direct audited standard headers are supported", f"input.c:{number}"))
        elif re.match(r"\s*#\s*(include_next|import|embed|line)\b", line):
            findings.append(Finding("UNSUPPORTED_DIRECTIVE", line.strip(), f"input.c:{number}"))
        elif re.match(r"\s*#\s*pragma\b", line) and not re.match(r"\s*#\s*pragma\s+HLS\b", line):
            findings.append(Finding("UNSUPPORTED_DIRECTIVE", "only direct HLS pragmas are supported", f"input.c:{number}"))
    # Tokens in strings/comments are not executable identifiers.
    stripped = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', ' ', clean)
    if "%:" in stripped:
        findings.append(Finding("UNSUPPORTED_LEXICAL_FORM", "digraph preprocessing directives are unsupported"))
    for name in ("__DATE__", "__TIME__", "__TIMESTAMP__", "__FILE__", "__BASE_FILE__",
                 "__func__", "__FUNCTION__", "__PRETTY_FUNCTION__",
                 "__has_include", "__has_include_next", "__has_embed", "_Pragma"):
        if re.search(rf"\b{re.escape(name)}\b", stripped):
            findings.append(Finding("ENVIRONMENT_MACRO", name))
    return tuple(findings)


def _plain_type(node: C.Node, typedefs: dict[str, C.Node], structs: dict[str, C.Struct],
                seen: frozenset[str] = frozenset()) -> tuple:
    if isinstance(node, C.TypeDecl):
        if "_Atomic" in (node.quals or []):
            raise UnsupportedC("atomic types are outside the C profile")
        inner = _plain_type(node.type, typedefs, structs, seen)
        quals = set(node.quals or [])
        if inner[0] == "qualified":
            quals.update(inner[1]); inner = inner[2]
        if inner[0] == "pointer":
            return ("pointer", tuple(sorted(quals | set(inner[1]))), inner[2])
        return ("qualified", tuple(sorted(quals)), inner)
    if isinstance(node, C.IdentifierType):
        names = node.names
        if len(names) == 1 and names[0] in typedefs:
            if names[0] in seen:
                raise UnsupportedC("recursive typedef")
            return _plain_type(typedefs[names[0]], typedefs, structs, seen | {names[0]})
        if any(n in {"float", "double", "_Complex"} for n in names):
            raise UnsupportedC("floating-point types are outside the C profile")
        if any(n not in {"void", "_Bool", "char", "short", "int", "long", "signed", "unsigned"} for n in names):
            raise UnsupportedC(f"unresolved type {' '.join(names)}")
        unsigned = "unsigned" in names
        if "void" in names or "_Bool" in names:
            return (names[0],)
        if "char" in names:
            return ("unsigned char" if unsigned else "signed char" if "signed" in names else "char",)
        width = "short" if "short" in names else "long long" if names.count("long") == 2 else "long" if "long" in names else "int"
        return (("unsigned " if unsigned else "") + width,)
    if isinstance(node, C.PtrDecl):
        if isinstance(node.type, C.FuncDecl):
            raise UnsupportedC("function pointers are unsupported")
        return ("pointer", tuple(sorted(node.quals or [])), _plain_type(node.type, typedefs, structs, seen))
    if isinstance(node, C.ArrayDecl):
        return ("array", c_generator.CGenerator().visit(node.dim) if node.dim else "",
                _plain_type(node.type, typedefs, structs, seen))
    if isinstance(node, C.Struct):
        definition = node if node.decls is not None else structs.get(node.name)
        if definition is None or (node.name and f"struct:{node.name}" in seen):
            raise UnsupportedC("incomplete or recursive struct")
        fields = []
        for field in definition.decls or []:
            if field.bitsize is not None:
                raise UnsupportedC("bit fields are unsupported")
            fields.append((field.name, _plain_type(field.type, typedefs, structs,
                          seen | {f"struct:{node.name}"})))
        return ("struct", tuple(fields))
    raise UnsupportedC(f"unsupported type {type(node).__name__}")


def _signature(decl: C.Decl, typedefs: dict[str, C.Node], structs: dict[str, C.Struct]) -> tuple:
    fn = decl.type
    if not isinstance(fn, C.FuncDecl):
        raise UnsupportedC("entry is not a function")
    params = []
    for p in fn.args.params if fn.args else []:
        if isinstance(p, C.EllipsisParam):
            raise UnsupportedC("variadic functions are unsupported")
        typ = p.type
        # C array parameters adjust to pointers; parameter names are not types.
        if isinstance(typ, C.ArrayDecl):
            typ = C.PtrDecl(quals=typ.dim_quals or [], type=typ.type)
        value = _plain_type(typ, typedefs, structs)
        if value == ("qualified", (), ("void",)) and len(fn.args.params) == 1:
            continue
        # Parameter object qualifiers do not change C function type compatibility.
        if value[0] in {"qualified", "pointer"}:
            value = (value[0], (), value[2])
        params.append(value)
    return (_plain_type(fn.type, typedefs, structs), tuple(params))


def prototype_signature(text: str) -> tuple:
    ast = c_parser.CParser().parse(text)
    if len(ast.ext) != 1 or not isinstance(ast.ext[0], C.Decl):
        raise UnsupportedC("expected one function prototype")
    return _signature(ast.ext[0], {}, {})


def _has_qualifier(desc: tuple, qualifier: str) -> bool:
    if desc[0] in {"qualified", "pointer"}:
        return qualifier in desc[1] or _has_qualifier(desc[2], qualifier)
    if desc[0] == "array": return _has_qualifier(desc[2], qualifier)
    if desc[0] == "struct": return any(_has_qualifier(field[1], qualifier) for field in desc[1])
    return False


def _constant_object(desc: tuple) -> bool:
    if desc[0] == "qualified":
        return "const" in desc[1] or _constant_object(desc[2])
    if desc[0] == "array": return _constant_object(desc[2])
    if desc[0] == "struct": return bool(desc[1]) and all(_constant_object(f[1]) for f in desc[1])
    return False


def _contains_pointer(desc: tuple) -> bool:
    if desc[0] == "pointer": return True
    if desc[0] in {"qualified", "array"}: return _contains_pointer(desc[2])
    if desc[0] == "struct": return any(_contains_pointer(f[1]) for f in desc[1])
    return False


class _Body(C.NodeVisitor):
    def __init__(self, typedefs: dict[str, C.Node], structs: dict[str, C.Struct],
                 variables: dict[str, tuple] | None = None) -> None:
        self.typedefs, self.structs = typedefs, structs
        self.calls: set[str] = set()
        self.ids: set[str] = set()
        self.forbidden: list[Finding] = []
        self.unsupported: list[Finding] = []
        self.pragmas: list[PragmaUse] = []
        self.parameter_context = False
        self.scalars: set[str] = set()
        self.pointers: set[str] = set()
        self.integer_arrays: set[str] = set()
        for name, desc in (variables or {}).items(): self._register(name, desc)

    def _register(self, name: str, desc: tuple) -> None:
        if desc[0] == "qualified":
            kind = desc[2][0]
            if kind not in {"struct", "array", "void"}: self.scalars.add(name)
            desc = desc[2]
        if desc[0] in {"pointer", "array"}:
            self.pointers.add(name)
            elem = desc[2]
            if elem[0] == "qualified" and elem[2][0] not in {"struct", "array", "void"}:
                self.integer_arrays.add(name)

    def issue(self, node: C.Node, code: str, detail: str, *, unsupported: bool = False) -> None:
        target = self.unsupported if unsupported else self.forbidden
        target.append(Finding(code, detail, str(node.coord or "")))

    def visit_ID(self, node: C.ID) -> None:
        self.ids.add(node.name)
        if node.name.startswith(("__CPROVER", "__ESBMC", "__VERIFIER", "__vwe_", "VE_")):
            self.issue(node, "VERIFIER_IDENTIFIER", node.name)

    def visit_FuncCall(self, node: C.FuncCall) -> None:
        if not isinstance(node.name, C.ID):
            self.issue(node, "INDIRECT_CALL", "only direct function calls are supported", unsupported=True)
        else:
            self.calls.add(node.name.name)
            if node.name.name in {"setjmp", "_setjmp", "sigsetjmp", "longjmp", "siglongjmp",
                                  "__builtin_unreachable", "__builtin_assume", "__assume",
                                  "asm", "__asm", "__asm__"}:
                self.issue(node, "PATH_CUT", node.name.name)
            if node.name.name in {"malloc", "calloc", "realloc", "free"}:
                self.issue(node, "DESIGN_HEAP", node.name.name)
        self.generic_visit(node)

    def visit_Decl(self, node: C.Decl) -> None:
        if node.name and node.name.startswith(("__CPROVER", "__ESBMC", "__VERIFIER", "__vwe_", "VE_")):
            self.issue(node, "VERIFIER_IDENTIFIER", node.name)
        if "static" in node.storage and not isinstance(node.type, C.FuncDecl):
            self.issue(node, "PERSISTENT_LOCAL", node.name or "unnamed")
        try:
            if not isinstance(node.type, C.FuncDecl):
                desc = _plain_type(node.type, self.typedefs, self.structs)
                if node.name: self._register(node.name, desc)
                if _has_qualifier(desc, "volatile"):
                    self.issue(node, "VOLATILE", "volatile object or aliased type")
            else:
                ret, params = _signature(node, self.typedefs, self.structs)
                if any(_has_qualifier(desc, "volatile") for desc in (ret, *params)):
                    self.issue(node, "VOLATILE", "volatile function type")
        except UnsupportedC as exc:
            self.issue(node, "UNSUPPORTED_TYPE", str(exc), unsupported=True)
        self.generic_visit(node)

    def visit_Typename(self, node: C.Typename) -> None:
        try:
            _plain_type(node.type, self.typedefs, self.structs)
        except UnsupportedC as exc:
            self.issue(node, "UNSUPPORTED_TYPE", str(exc), unsupported=True)
        self.generic_visit(node)

    def visit_Cast(self, node: C.Cast) -> None:
        def integer_expr(n: C.Node) -> bool:
            if isinstance(n, C.ID): return n.name in self.scalars and n.name not in self.pointers
            if isinstance(n, C.Constant): return n.type not in {"string", "float", "double", "long double"}
            if isinstance(n, C.BinaryOp): return integer_expr(n.left) and integer_expr(n.right)
            if isinstance(n, C.UnaryOp):
                return n.op in {"sizeof", "_Alignof"} or (n.op in {"+", "-", "~", "!"} and integer_expr(n.expr))
            if isinstance(n, C.ArrayRef):
                return isinstance(n.name, C.ID) and n.name.name in self.integer_arrays
            if isinstance(n, C.Cast): return integer_expr(n.expr)
            if isinstance(n, C.TernaryOp): return integer_expr(n.iftrue) and integer_expr(n.iffalse)
            return False
        try:
            desc = _plain_type(node.to_type.type, self.typedefs, self.structs)
            if desc[0] == "pointer" or not integer_expr(node.expr):
                self.issue(node, "UNSUPPORTED_CAST", "cast is not a qualified scalar conversion", unsupported=True)
        except UnsupportedC as exc:
            self.issue(node, "UNSUPPORTED_CAST", str(exc), unsupported=True)
        self.generic_visit(node)

    def visit_TypeDecl(self, node: C.TypeDecl) -> None:
        if "volatile" in (node.quals or []):
            self.issue(node, "VOLATILE", "volatile object")
        self.generic_visit(node)

    def visit_ArrayDecl(self, node: C.ArrayDecl) -> None:
        # Parameter arrays are adjusted by the signature checker, but local
        # variable-length storage needs a separate lifetime/size model.
        def constant(n: C.Node | None) -> bool:
            if isinstance(n, C.Constant): return n.type in {"int", "unsigned int", "long int", "unsigned long int"}
            if isinstance(n, C.ID): return self.parameter_context
            if isinstance(n, C.UnaryOp): return n.op in {"+", "-", "~"} and constant(n.expr)
            if isinstance(n, C.BinaryOp): return constant(n.left) and constant(n.right)
            return False
        if node.dim is not None and not constant(node.dim):
            self.issue(node, "VARIABLE_LENGTH_ARRAY", "nonconstant array declarator", unsupported=True)
        self.generic_visit(node)

    def visit_FuncDecl(self, node: C.FuncDecl) -> None:
        self.visit(node.type)
        previous = self.parameter_context
        self.parameter_context = True
        if node.args: self.visit(node.args)
        self.parameter_context = previous

    def visit_PtrDecl(self, node: C.PtrDecl) -> None:
        if "volatile" in (node.quals or []):
            self.issue(node, "VOLATILE", "volatile pointer")
        self.generic_visit(node)

    def visit_Goto(self, node: C.Goto) -> None:
        # Deliberately conservative: no need to infer jump-into-scope legality.
        self.issue(node, "GOTO", "goto is unsupported in the first admission profile")

    def visit_Switch(self, node: C.Switch) -> None:
        class Declarations(C.NodeVisitor):
            found = False
            def visit_Decl(self, child: C.Decl) -> None:
                self.found = True
        scan = Declarations(); scan.visit(node.stmt)
        if scan.found:
            self.issue(node, "SWITCH_DECLARATION", "declaration within switch scope")
        self.generic_visit(node)

    def visit_Pragma(self, node: C.Pragma) -> None:
        words = node.string.split()
        if words and words[0] == "HLS":
            options = tuple(tuple(w.split("=", 1)) for w in words[2:] if "=" in w)
            self.pragmas.append(PragmaUse(words[1] if len(words)>1 else "", tuple(words[2:]), options, str(node.coord or "")))
        else:
            self.issue(node, "NON_HLS_PRAGMA", node.string, unsupported=True)

    def visit_Constant(self, node: C.Constant) -> None:
        if node.type in {"float", "double", "long double"}:
            self.issue(node, "FLOAT_CONSTANT", node.value, unsupported=True)


def analyze(text: str, fn: str) -> Analysis:
    try:
        ast = c_parser.CParser().parse(text, filename="input.c")
    except Exception as exc:
        raise UnsupportedC(f"C parse failed: {exc}") from exc
    typedefs = {n.name: n.type for n in ast.ext if isinstance(n, C.Typedef)}
    structs: dict[str, C.Struct] = {}
    class Structs(C.NodeVisitor):
        def visit_FuncDef(self, n: C.FuncDef) -> None:
            # Block-scope tags must never overwrite the public layout map.
            # A full scoped type resolver is outside this frontend profile.
            pass
        def visit_Struct(self, n: C.Struct) -> None:
            if n.name and n.decls is not None: structs[n.name] = n
            self.generic_visit(n)
    Structs().visit(ast)
    definitions = {n.decl.name: n for n in ast.ext if isinstance(n, C.FuncDef)}
    if fn not in definitions:
        raise UnsupportedC(f"function {fn!r} has no definition")
    signature = _signature(definitions[fn].decl, typedefs, structs)
    global_decls = [n for n in ast.ext if isinstance(n, C.Decl) and not isinstance(n.type, C.FuncDecl) and n.name]
    variables = {}
    for n in global_decls:
        try: variables[n.name] = _plain_type(n.type, typedefs, structs)
        except UnsupportedC: pass
    scans: dict[str, _Body] = {}
    for name, definition in definitions.items():
        scan = _Body(typedefs, structs, variables); scan.visit(definition)
        scans[name] = scan
    reachable: set[str] = set()
    recursive = False
    def walk(name: str, active: frozenset[str]) -> None:
        nonlocal recursive
        if name in active:
            recursive = True; return
        if name in reachable or name not in scans: return
        reachable.add(name)
        for child in scans[name].calls: walk(child, active | {name})
    walk(fn, frozenset())
    forbidden = [f for s in scans.values() for f in s.forbidden]
    unsupported = [f for s in scans.values() for f in s.unsupported]
    if recursive:
        forbidden.append(Finding("RECURSION", "recursive call graph"))
    global_scan = _Body(typedefs, structs)
    for n in global_decls:
        # File statics are classified separately; only persistent local state is forbidden here.
        storage = n.storage; n.storage = [x for x in storage if x != "static"]
        global_scan.visit(n); n.storage = storage
    forbidden += global_scan.forbidden; unsupported += global_scan.unsupported
    class ReservedNames(C.NodeVisitor):
        def generic_visit(self, node: C.Node) -> None:
            name = getattr(node, "name", None)
            if isinstance(name, str) and name.startswith(("__CPROVER", "__ESBMC", "__VERIFIER", "__vwe_", "VE_")):
                forbidden.append(Finding("VERIFIER_IDENTIFIER", name, str(node.coord or "")))
            super().generic_visit(node)
    ReservedNames().visit(ast)
    collector = _Namespacer({n.name: n.name for n in global_decls})
    collector.translation_unit(deepcopy(C.FileAST([definitions[n] for n in sorted(reachable)])))
    used_ids = collector.references
    global_roles = []
    global_types = []
    for n in global_decls:
        try:
            desc = _plain_type(n.type, typedefs, structs)
            global_types.append((n.name, desc))
            if _contains_pointer(desc):
                unsupported.append(Finding("GLOBAL_POINTER", "global pointer storage needs an explicit alias model", str(n.coord or "")))
        except UnsupportedC:
            pass  # already recorded by the global scan
        if n.name in used_ids:
            const = _constant_object(dict(global_types).get(n.name, ("unsupported",)))
            global_roles.append((n.name, "const_program" if const else "input_output"))
    # Unknown external calls are checked against GOTO and the audited library list later.
    calls = set().union(*(scans[n].calls for n in reachable))
    prototypes = []
    for n in ast.ext:
        if isinstance(n, C.Decl) and isinstance(n.type, C.FuncDecl) and n.name in calls:
            try:
                prototypes.append((n.name, _signature(n, typedefs, structs)))
            except UnsupportedC as exc:
                unsupported.append(Finding("UNSUPPORTED_CALLEE_TYPE", str(exc), str(n.coord or "")))
    pragmas = [p for s in scans.values() for p in s.pragmas]
    for n in ast.ext:
        if isinstance(n, C.Pragma):
            scan = _Body(typedefs, structs); scan.visit(n)
            pragmas += scan.pragmas; unsupported += scan.unsupported
    return Analysis(ast, fn, signature, tuple(sorted(definitions)), tuple(sorted(calls)),
                    tuple(sorted(global_roles)), tuple(sorted(n.name for n in global_decls)),
                    tuple(sorted(global_types)), tuple(sorted(prototypes)),
                    tuple(pragmas), tuple(forbidden), tuple(unsupported))


class _Namespacer(C.NodeVisitor):
    """Rename ordinary global symbols without touching fields/literals/shadows."""
    def __init__(self, names: dict[str, str]) -> None:
        self.names = names
        self.scopes: list[set[str]] = []
        self.references: set[str] = set()

    def _decl_name(self, node: C.Decl, name: str) -> None:
        node.name = name
        typ = node.type
        while hasattr(typ, "type") and not isinstance(typ, C.TypeDecl):
            typ = typ.type
        if isinstance(typ, C.TypeDecl): typ.declname = name

    def visit_ID(self, node: C.ID) -> None:
        if node.name in self.names and not any(node.name in s for s in self.scopes):
            self.references.add(node.name)
            node.name = self.names[node.name]

    def visit_StructRef(self, node: C.StructRef) -> None:
        self.visit(node.name)  # field identifiers belong to a different namespace

    def visit_Struct(self, node: C.Struct) -> None:
        # Fields do not introduce ordinary local bindings. Supported layouts
        # contain no VLA/bit-field expressions requiring a value-symbol rewrite.
        pass

    def visit_NamedInitializer(self, node: C.NamedInitializer) -> None:
        for designator in node.name:
            if not isinstance(designator, C.ID): self.visit(designator)
        self.visit(node.expr)

    def visit_Decl(self, node: C.Decl) -> None:
        if "extern" in node.storage or isinstance(node.type, C.FuncDecl):
            if node.name in self.names: self._decl_name(node, self.names[node.name])
            return
        self.visit(node.type)
        if self.scopes and node.name: self.scopes[-1].add(node.name)
        if node.init: self.visit(node.init)

    def visit_Typedef(self, node: C.Typedef) -> None:
        pass

    def visit_Compound(self, node: C.Compound) -> None:
        self.scopes.append(set())
        for child in node.block_items or []: self.visit(child)
        self.scopes.pop()

    def visit_For(self, node: C.For) -> None:
        self.scopes.append(set())
        for child in (node.init, node.cond, node.next, node.stmt):
            if child is not None: self.visit(child)
        self.scopes.pop()

    def translation_unit(self, ast: C.FileAST) -> None:
        for node in ast.ext:
            if isinstance(node, C.FuncDef):
                if node.decl.name in self.names: self._decl_name(node.decl, self.names[node.decl.name])
                params = node.decl.type.args
                self.scopes.append(set())
                for p in params.params if params else []:
                    if isinstance(p, C.Decl):
                        self.visit(p.type)
                        if p.name: self.scopes[-1].add(p.name)
                self.visit(node.body)
                self.scopes.pop()
            elif isinstance(node, C.Decl):
                if node.name in self.names: self._decl_name(node, self.names[node.name])
                if node.init: self.visit(node.init)


def renamed(analysis: Analysis, prefix: str) -> tuple[str, tuple[tuple[str, str], ...]]:
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", prefix):
        raise ValueError("namespace prefix must be a C identifier")
    names = {n: f"{prefix}_{n}" for n in (*analysis.definitions, *analysis.all_global_names)}
    identifiers: set[str] = set()
    class Identifiers(C.NodeVisitor):
        def generic_visit(self, node: C.Node) -> None:
            name = getattr(node, "name", None)
            if isinstance(name, str): identifiers.add(name)
            super().generic_visit(node)
    Identifiers().visit(analysis.ast)
    collisions = set(names.values()) & identifiers
    if collisions:
        raise UnsupportedC(f"namespace collision: {sorted(collisions)}")
    ast = deepcopy(analysis.ast)
    _Namespacer(names).translation_unit(ast)
    text = c_generator.CGenerator().visit(ast) + "\n"
    # A malformed rewrite is a setup failure, never an admission proof.
    try:
        c_parser.CParser().parse(text, filename="renamed.c")
    except Exception as exc:
        raise UnsupportedC(f"renamed C failed to parse: {exc}") from exc
    return text, tuple(sorted(names.items()))
