"""Per-translation-unit adapters: real C types stay in their original unit.

Frames contain leaves, never padding. Returned pointers are normalized later
against corresponding caller buffers; arbitrary pointer graphs are unsupported.
"""
from __future__ import annotations
from dataclasses import dataclass
from hashlib import sha256
from pycparser import c_ast as C
from ..c_frontend import Analysis,_constant_object
from ..views import BuildView
from .layout import (Field,HarnessUnsupported,flatten,parameter_nodes,return_node,
                     element_node,declaration,resolve_root)


@dataclass(frozen=True)
class Parameter:
    index: int
    name: str
    fields: tuple[Field,...]
    buffer: bool


@dataclass(frozen=True)
class Global:
    index: int
    name: str
    fields: tuple[Field,...]


@dataclass(frozen=True)
class Layout:
    parameters: tuple[Parameter,...]
    returns: tuple[Field,...]
    globals: tuple[Global,...]

    @classmethod
    def make(cls,a: Analysis) -> Layout:
        params=[]
        for i,(p,d) in enumerate(zip(parameter_nodes(a),a.signature[1])):
            isbuf=d[0]=='pointer'
            fields=flatten(d[2] if isbuf else d,ignore_root_const=True)
            if any(f.pointer or f.readonly for f in fields):
                raise HarnessUnsupported('pointer-bearing or const-member input storage needs another profile')
            if isbuf: element_node(p,a)  # reject unqualified static array parameters
            params.append(Parameter(i,p.name,fields,isbuf))
        ret=a.signature[0]
        returns=() if ret==('qualified',(),('void',)) else flatten(ret)
        globals=[]
        for n,d in a.global_types:
            if _constant_object(d): continue
            fields=flatten(d)
            if any(f.pointer or f.readonly for f in fields):
                raise HarnessUnsupported('mutable globals with pointers/const members need another profile')
            globals.append(Global(len(globals),n,fields))
        if sum(len(p.fields) for p in params)+sum(len(g.fields) for g in globals)>128:
            raise HarnessUnsupported('input field budget exceeded')
        return cls(tuple(params),returns,tuple(globals))

    def header(self) -> str:
        lines=['#ifndef VWE_FRAME_H','#define VWE_FRAME_H',
               'typedef __typeof__(sizeof(int)) __vwe_size;',
               '_Static_assert(sizeof(int)==4 && sizeof(long)==8 && sizeof(void*)==8 && (char)-1<0, "VWE LP64 signed-char profile");',
               'struct __vwe_input {']
        fields=[]
        for p in self.parameters:
            if not p.buffer:
                fields += [f'{f.c_type} s{p.index}_{j};' for j,f in enumerate(p.fields)]
        for g in self.globals:
            fields += [f'{f.c_type} g{g.index}_{j};' for j,f in enumerate(g.fields)]
        lines += ['  '+x for x in fields or ['int dummy;']];lines+=['};','struct __vwe_output {']
        fields=[f'{f.c_type} r{j};' for j,f in enumerate(self.returns)]
        for g in self.globals: fields += [f'{f.c_type} g{g.index}_{j};' for j,f in enumerate(g.fields)]
        lines += ['  '+x for x in fields or ['int dummy;']];lines+=['};']
        for p in self.parameters:
            if p.buffer:
                lines += [f'struct __vwe_element_{p.index} {{']
                lines += [f'  {f.c_type} f{j};' for j,f in enumerate(p.fields)]
                lines += ['};']
        lines += ['#endif','']
        return '\n'.join(lines)

    def prototypes(self,tag: str) -> str:
        params=['const struct __vwe_input *in','struct __vwe_output *out']
        params += [f'void *b{p.index}' for p in self.parameters if p.buffer]
        lines=[f'void __vwe_{tag}_call('+', '.join(params)+');']
        for p in self.parameters:
            if p.buffer:
                lines += [f'__vwe_size __vwe_{tag}_size_{p.index}(void);',
                          f'void __vwe_{tag}_set_{p.index}(void *, __vwe_size, struct __vwe_element_{p.index});',
                          f'struct __vwe_element_{p.index} __vwe_{tag}_get_{p.index}(const void *, __vwe_size);']
        return '\n'.join(lines)+'\n'

    def adapter(self,view: BuildView,tag: str) -> str:
        a=view.analysis;actual=Layout.make(a)
        # Names may change between versions; positions/types/field paths may not.
        if tuple((p.fields,p.buffer) for p in actual.parameters)!=tuple((p.fields,p.buffer) for p in self.parameters) or actual.returns!=self.returns or actual.globals!=self.globals:
            raise HarnessUnsupported('incompatible adapter layouts')
        code = view.renamed.read_bytes()
        if sha256(code).hexdigest() != view.renamed_sha256:
            raise HarnessUnsupported("renamed build view changed after admission")
        lines=['#include "frame.h"', code.decode("utf-8")]
        nodes=parameter_nodes(a);names=dict(view.symbols)
        for p in self.parameters:
            if not p.buffer: continue
            typ=resolve_root(element_node(nodes[p.index],a),a)
            # Anonymous element definitions cannot be repeated as a C cast type.
            if isinstance(typ,C.TypeDecl) and isinstance(typ.type,C.Struct) and not typ.type.name:
                raise HarnessUnsupported('anonymous buffer element types need named typedefs')
            ctype=declaration(typ,None,strip_const=True)
            lines += [f'__vwe_size __vwe_{tag}_size_{p.index}(void) {{ return sizeof({ctype}); }}',
                      f'void __vwe_{tag}_set_{p.index}(void *raw, __vwe_size i, struct __vwe_element_{p.index} e) {{',
                      f'  {ctype} *v=({ctype} *)raw;']
            lines += [f'  {f.access("v[i]")}=e.f{j};' for j,f in enumerate(p.fields)]
            lines += ['}',f'struct __vwe_element_{p.index} __vwe_{tag}_get_{p.index}(const void *raw, __vwe_size i) {{',
                      f'  const {ctype} *v=(const {ctype} *)raw;',f'  struct __vwe_element_{p.index} e;']
            lines += [f'  e.f{j}={f.access("v[i]")};' for j,f in enumerate(p.fields)]
            lines += ['  return e;','}']
        params=['const struct __vwe_input *in','struct __vwe_output *out']+[f'void *b{p.index}' for p in self.parameters if p.buffer]
        lines += [f'void __vwe_{tag}_call('+', '.join(params)+') {']
        args=[]
        for p in self.parameters:
            node=nodes[p.index]
            if p.buffer:
                # Array parameters are adjusted by C; use a pointer to the element.
                elem=element_node(node,a);ptr=C.PtrDecl(quals=[],type=elem)
                args.append('('+declaration(ptr,None)+f')b{p.index}')
            else:
                root=f'__vwe_arg_{p.index}'
                lines += ['  '+declaration(resolve_root(node.type,a),root,strip_const=True)+';']
                lines += [f'  {f.access(root)}=in->s{p.index}_{j};' for j,f in enumerate(p.fields)]
                args.append(root)
        for g in self.globals:
            lines += [f'  {f.access(names.get(g.name,g.name))}=in->g{g.index}_{j};' for j,f in enumerate(g.fields)]
        call=view.entry_point+'('+', '.join(args)+')'
        if self.returns:
            lines+=['  '+declaration(resolve_root(return_node(a),a),'__vwe_ret')+'='+call+';']
            lines += [f'  out->r{j}={f.access("__vwe_ret")};' for j,f in enumerate(self.returns)]
        else: lines += ['  '+call+';']
        for g in self.globals:
            lines += [f'  out->g{g.index}_{j}={f.access(names.get(g.name,g.name))};' for j,f in enumerate(g.fields)]
        lines += ['}','']
        return '\n'.join(lines)
