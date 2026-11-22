"""P0-only type environments; no candidate or evaluation data is accepted."""
from __future__ import annotations
from dataclasses import dataclass
from types import MappingProxyType
from typing import Mapping,Any
from pycparser import c_ast as C
from ..c_frontend import Analysis,analyze,without_comments,UnsupportedC
from ..tasks import PipelineTask
from .ast import Sort,Interval,Expr,ContractTypeError,ContractUnsupported
from .parser import ContractParser

I64_MIN=-(1<<63)
I64_MAX=(1<<63)-1


@dataclass(frozen=True)
class ScalarType:
    c_name: str
    bits: int
    signed: bool
    sort: Sort=Sort.INT

    @property
    def limits(self) -> Interval:
        if self.sort is Sort.BOOL: return Interval(0,1)
        return Interval(-(1<<(self.bits-1)),(1<<(self.bits-1))-1) if self.signed else Interval(0,(1<<self.bits)-1)


@dataclass(frozen=True)
class Symbol:
    name: str
    scalar: ScalarType
    role: str
    values: Interval
    length: Expr | None=None

    @property
    def sort(self) -> Sort:
        return Sort.BUFFER if self.length is not None else self.scalar.sort


@dataclass(frozen=True)
class TypeEnv:
    symbols: Mapping[str,Symbol]
    constants: Mapping[str,int]
    size_parameters: frozenset[str]
    allow_old: bool=False
    quantifier_limit: int=64
    evaluation_limit: int=4096

    def with_old(self,allowed: bool) -> TypeEnv:
        from dataclasses import replace
        return replace(self,allow_old=allowed)

    @classmethod
    def from_analysis(cls,analysis: Analysis,shape: Mapping[str,Any],*,allow_old: bool=False) -> TypeEnv:
        symbols: dict[str,Symbol]={}
        parser=ContractParser()
        def add(name: str,typ: ScalarType,role: str,values: Interval|None=None,length: Expr|None=None) -> None:
            if name in symbols or name in constants:
                raise ContractUnsupported(f'contract namespace collision: {name}')
            symbols[name]=Symbol(name,typ,role,values or typ.limits,length)
        constants=standard_constants()
        definition=next(n for n in analysis.ast.ext if isinstance(n,C.FuncDef) and n.decl.name==analysis.function)
        params=[p for p in (definition.decl.type.args.params if definition.decl.type.args else []) if isinstance(p,C.Decl)]
        if len(params)!=len(analysis.signature[1]):
            raise ContractUnsupported('unnamed public parameters are not supported in contracts')
        buffers=shape.get('buffers',{})
        bounds=shape.get('bounds',{})
        values=shape.get('value_bounds',{})
        for p,desc in zip(params,analysis.signature[1]):
            if not p.name: raise ContractUnsupported('parameters need names')
            if desc[0]=='pointer':
                if p.name not in buffers: raise ContractUnsupported(f'missing exact shape for {p.name}')
                typ=scalar_type(desc[2]);length=parser.parse(buffers[p.name])
                add(p.name,typ,'input',bounded(typ,values.get(p.name)),length)
                add('out_'+p.name,typ,'output',length=length)
                add('old_'+p.name,typ,'old',length=length)
            else:
                typ=scalar_type(desc)
                a,b=bounded(typ,bounds.get(p.name)),bounded(typ,values.get(p.name))
                low,high=max(a.low,b.low),min(a.high,b.high)
                if low>high: raise ContractTypeError('conflicting scalar bounds')
                add(p.name,typ,'input',Interval(low,high))
        ret=analysis.signature[0]
        if ret!=('qualified',(),('void',)):
            typ=scalar_type(ret)
            add('out_ret',typ,'output');add('old_ret',typ,'old')
        for name,_ in analysis.globals:
            desc=dict(analysis.global_types)[name]
            if desc[0]=='array':
                typ=scalar_type(desc[2]);length=parser.parse(desc[1])
            else: typ=scalar_type(desc);length=None
            add('in_global_'+name,typ,'input',length=length)
            add('out_global_'+name,typ,'output',length=length)
            add('old_global_'+name,typ,'old',length=length)
        if set(buffers)-{p.name for p in params}:
            raise ContractTypeError('shape names an unknown buffer parameter')
        scalar_inputs={n for n,s in symbols.items() if s.role=='input' and s.sort is Sort.INT}
        if set(bounds)-scalar_inputs:
            raise ContractTypeError('size bounds must name integer input scalars')
        result=cls(MappingProxyType(symbols),MappingProxyType(constants),frozenset(bounds),allow_old)
        from .typecheck import typecheck,_names
        for symbol in symbols.values():
            if symbol.length is not None:
                if _names(symbol.length)-(set(bounds)|set(constants)):
                    raise ContractTypeError('buffer lengths may use only size parameters and constants')
                typecheck(symbol.length,result,expected=Sort.INT)
        return result

    @classmethod
    def from_task(cls,task: PipelineTask,shape: Mapping[str,Any]|None=None,*,allow_old: bool=False) -> TypeEnv:
        # For source requiring preprocessing, the caller supplies T02's P0-only
        # Analysis through from_analysis. No header erasure or P1 access here.
        try: analysis=analyze(without_comments(task.p0.text),task.function)
        except UnsupportedC as exc:
            raise ContractUnsupported('P0 needs a supported preprocessed Analysis: '+str(exc)) from exc
        return cls.from_analysis(analysis,shape if shape is not None else task.caller_domain,allow_old=allow_old)


def scalar_type(desc: tuple) -> ScalarType:
    if desc[0]!='qualified' or len(desc[2])!=1:
        raise ContractUnsupported('contract observers currently support scalar integer fields/buffers')
    name=desc[2][0]
    if name=='_Bool': return ScalarType('_Bool',1,False,Sort.BOOL)
    types={'char':(8,True),'signed char':(8,True),'unsigned char':(8,False),
           'short':(16,True),'unsigned short':(16,False),'int':(32,True),'unsigned int':(32,False),
           'long':(64,True),'unsigned long':(64,False),'long long':(64,True),'unsigned long long':(64,False)}
    if name not in types: raise ContractUnsupported(f'unsupported scalar type: {name}')
    bits,signed=types[name];return ScalarType(name,bits,signed)


def bounded(typ: ScalarType,limits: Any) -> Interval:
    if limits is None: return typ.limits
    if len(limits)!=2 or any(type(x) is not int for x in limits): raise ContractTypeError('invalid value bounds')
    if limits[0]>limits[1]: raise ContractTypeError('inconsistent value bounds')
    result=Interval(*limits)
    if result.low<typ.limits.low or result.high>typ.limits.high: raise ContractTypeError('bounds exceed the C type')
    return result


def standard_constants() -> dict[str,int]:
    return {'INT_MIN':-(1<<31),'INT_MAX':(1<<31)-1,'UINT_MAX':(1<<32)-1,
            'LONG_MIN':I64_MIN,'LONG_MAX':I64_MAX,'LLONG_MIN':I64_MIN,'LLONG_MAX':I64_MAX,
            'UINT8_MAX':255,'INT8_MIN':-128,'INT8_MAX':127,'INT16_MIN':-(1<<15),'INT16_MAX':(1<<15)-1,
            'UINT16_MAX':(1<<16)-1,'INT32_MIN':-(1<<31),'INT32_MAX':(1<<31)-1,'UINT32_MAX':(1<<32)-1,
            'INT64_MIN':I64_MIN,'INT64_MAX':I64_MAX}
