"""C layout utilities for trusted adapters and field-wise observations."""
from __future__ import annotations
from copy import deepcopy
from dataclasses import dataclass
import re
from pycparser import c_ast as C,c_generator
from ..c_frontend import Analysis
from ..contract.env import ScalarType,scalar_type


class HarnessUnsupported(ValueError): pass


@dataclass(frozen=True)
class Field:
    path: tuple[str|int,...]
    scalar: ScalarType|None
    pointer: bool=False
    readonly: bool=False

    def access(self,root: str) -> str:
        return root+''.join(f'[{x}]' if isinstance(x,int) else '.'+x for x in self.path)

    @property
    def c_type(self) -> str:
        return 'const void *' if self.pointer else self.scalar.c_name


def dimension(text: str) -> int:
    # C expressions involving promotions, shifts, or sizeof cannot be folded
    # with Python arithmetic. The frontend profile admits only literal extents
    # here until their evaluated C values are available from the compiler.
    if len(text) > 32 or not re.fullmatch(r"(?:0[xX][0-9a-fA-F]+|0[0-7]*|[1-9][0-9]*)[uUlL]*", text):
        raise HarnessUnsupported("fixed arrays require a literal extent")
    digits = re.sub(r"[uUlL]+$", "", text)
    base = 16 if digits.lower().startswith("0x") else 8 if digits.startswith("0") else 10
    value = int(digits, base)
    if not 1 <= value <= 64:
        raise HarnessUnsupported("fixed array extent must be in 1..64")
    return value


def flatten(desc: tuple,*,path: tuple[str|int,...]=(),readonly: bool=False,ignore_root_const: bool=False) -> tuple[Field,...]:
    if desc[0]=='qualified':
        ro=readonly or ('const' in desc[1] and not ignore_root_const)
        inner=desc[2]
        if inner[0]=='struct':
            result=tuple(f for name,t in inner[1] for f in flatten(t,path=(*path,name),readonly=ro))
        else: result=(Field(path,scalar_type(desc),False,ro),)
    elif desc[0]=='pointer': result=(Field(path,None,True,readonly or 'const' in desc[1]),)
    elif desc[0]=='array':
        result=tuple(f for i in range(dimension(desc[1])) for f in flatten(desc[2],path=(*path,i),readonly=readonly))
    elif desc[0]=='struct':
        result=tuple(f for name,t in desc[1] for f in flatten(t,path=(*path,name),readonly=readonly))
    else: raise HarnessUnsupported('unsupported observation layout')
    if len(result)>64: raise HarnessUnsupported('too many fields in an observed value')
    return result


def declaration(type_node: C.Node,name: str|None,*,strip_const: bool=False) -> str:
    typ=deepcopy(type_node)
    class References(C.NodeVisitor):
        def visit_Struct(self,n: C.Struct) -> None:
            if n.name: n.decls=None
            else: self.generic_visit(n)
    References().visit(typ)
    cursor=typ
    if strip_const:
        # Strip only the top object qualification; named struct member types
        # retain their own qualifiers and are checked separately.
        if hasattr(cursor,'quals'): cursor.quals=[q for q in cursor.quals if q not in {'const','restrict'}]
    while hasattr(cursor,'type') and not isinstance(cursor,C.TypeDecl): cursor=cursor.type
    if not isinstance(cursor,C.TypeDecl): raise HarnessUnsupported('unsupported C declarator')
    cursor.declname=name
    return c_generator.CGenerator()._generate_type(typ)


def resolve_root(type_node: C.Node,analysis: Analysis) -> C.Node:
    aliases={n.name:n.type for n in analysis.ast.ext if isinstance(n,C.Typedef)}
    node=deepcopy(type_node);seen=set()
    while isinstance(node,C.TypeDecl) and isinstance(node.type,C.IdentifierType) and len(node.type.names)==1 and node.type.names[0] in aliases:
        name=node.type.names[0]
        if name in seen: raise HarnessUnsupported('recursive typedef')
        seen.add(name);quals=node.quals;node=deepcopy(aliases[name])
        if hasattr(node,'quals'): node.quals=list(set(node.quals or [])|set(quals or []))
    return node


def parameter_nodes(analysis: Analysis) -> tuple[C.Decl,...]:
    fn=next(n for n in analysis.ast.ext if isinstance(n,C.FuncDef) and n.decl.name==analysis.function)
    return tuple(p for p in (fn.decl.type.args.params if fn.decl.type.args else []) if isinstance(p,C.Decl))


def return_node(analysis: Analysis) -> C.Node:
    fn=next(n for n in analysis.ast.ext if isinstance(n,C.FuncDef) and n.decl.name==analysis.function)
    return fn.decl.type.type


def element_node(param: C.Decl,analysis: Analysis) -> C.Node:
    node=resolve_root(param.type,analysis)
    if isinstance(node,C.ArrayDecl) and 'static' in (node.dim_quals or []):
        raise HarnessUnsupported('static array-parameter contracts are not qualified')
    if not isinstance(node,(C.PtrDecl,C.ArrayDecl)): raise HarnessUnsupported('not a buffer parameter')
    return node.type
