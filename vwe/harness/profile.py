"""Bounded input profiles independent of candidates and solver outcomes."""
from __future__ import annotations
from dataclasses import dataclass
from hashlib import sha256
import json
from typing import Any,Mapping
from types import MappingProxyType
from ..c_frontend import Analysis,_constant_object
from ..contract.env import TypeEnv,Symbol,bounded,standard_constants
from ..contract.ast import Sort,ContractUnsupported
from ..contract.parser import parse
from ..contract.typecheck import typecheck,_names
from .layout import HarnessUnsupported


def plain(value: Any) -> Any:
    if isinstance(value,Mapping): return {k:plain(v) for k,v in value.items()}
    if isinstance(value,(list,tuple)): return [plain(v) for v in value]
    return value


def observer_env(a: Analysis,shape: Mapping[str,Any]) -> TypeEnv:
    """Expose integer leaves supported by VE-DSL-1; composites stay opaque.

    Opaque values are still observed field-wise by the relational harness.
    Mentioning them in a contract is a type error, never a silently true clause.
    """
    from .layout import parameter_nodes
    symbols={};constants=standard_constants();buffers=shape.get('buffers',{})
    def add(name,desc,role,length=None,limits=None):
        from ..contract.env import scalar_type
        try: typ=scalar_type(desc)
        except ContractUnsupported: return
        if name in symbols or name in constants: raise HarnessUnsupported('contract namespace collision')
        symbols[name]=Symbol(name,typ,role,bounded(typ,limits),length)
    for p,d in zip(parameter_nodes(a),a.signature[1]):
        if d[0]=='pointer':
            length=parse(buffers[p.name]);typ=d[2]
            add(p.name,typ,'input',length,shape.get('value_bounds',{}).get(p.name))
            add('out_'+p.name,typ,'output',length);add('old_'+p.name,typ,'old',length)
        else:
            add(p.name,d,'input',limits=shape.get('bounds',{}).get(p.name))
            if p.name in symbols and p.name in shape.get('value_bounds',{}):
                s=symbols[p.name];r=bounded(s.scalar,shape['value_bounds'][p.name])
                from ..contract.ast import Interval
                low,high=max(s.values.low,r.low),min(s.values.high,r.high)
                if low>high: raise HarnessUnsupported('empty input interval')
                symbols[p.name]=Symbol(s.name,s.scalar,s.role,Interval(low,high))
    if a.signature[0]!=('qualified',(),('void',)):
        add('out_ret',a.signature[0],'output');add('old_ret',a.signature[0],'old')
    for n,d in a.global_types:
        if _constant_object(d): continue
        if d[0]=='array': typ,length=d[2],parse(d[1])
        else: typ,length=d,None
        add('in_global_'+n,typ,'input',length)
        add('out_global_'+n,typ,'output',length);add('old_global_'+n,typ,'old',length)
    return TypeEnv(MappingProxyType(symbols),MappingProxyType(constants),frozenset(shape.get('bounds',{})),True)


@dataclass(frozen=True)
class Profile:
    shape: Mapping[str,Any]
    env: TypeEnv
    lengths: tuple[tuple[str,str,int],...]
    K: int
    sha256: str

    @classmethod
    def make(cls,a: Analysis,shape: Mapping[str,Any],K: int=4) -> Profile:
        from .layout import parameter_nodes
        if type(K) is not int or K<1 or K>64: raise HarnessUnsupported('K must be in 1..64')
        if shape.get('alias')!='disjoint': raise HarnessUnsupported('only disjoint input regions are qualified')
        params=parameter_nodes(a)
        buffer_names={p.name for p,d in zip(params,a.signature[1]) if d[0]=='pointer'}
        if set(shape.get('buffers',{}))!=buffer_names: raise HarnessUnsupported('shape must name every pointer parameter exactly once')
        env=observer_env(a,shape)
        scalar_names={p.name for p,d in zip(params,a.signature[1]) if d[0]!='pointer' and p.name in env.symbols}
        if set(shape.get('bounds',{}))-scalar_names: raise HarnessUnsupported('bounds must name supported scalar parameters')
        if set(shape.get('value_bounds',{}))-{p.name for p in params}: raise HarnessUnsupported('unknown value bound')
        for n,(lo,hi) in shape.get('bounds',{}).items():
            if lo<0 or hi>K: raise HarnessUnsupported('size bounds must be nonnegative and <= K')
        lengths=[]
        for name,expr in shape.get('buffers',{}).items():
            tree=parse(expr)
            if _names(tree)-(set(env.size_parameters)|set(env.constants)):
                raise HarnessUnsupported('buffer length must depend only on bounded size parameters')
            typed=typecheck(tree,env,expected=Sort.INT);interval=typed.nodes[id(tree)].interval
            if interval.low<0 or interval.high>K: raise HarnessUnsupported('buffer length is not statically in 0..K')
            lengths.append((name,expr,interval.high))
        record={'shape':plain(shape),'K':K,'signature':a.signature,
                'input_storage':'initialized','zero_size':'null-or-malloc-zero','alias':'disjoint',
                'globals':'all mutable fields are caller state','layout':'LP64-signed-char'}
        def freeze(value):
            if isinstance(value,dict): return MappingProxyType({k:freeze(v) for k,v in value.items()})
            if isinstance(value,list): return tuple(freeze(v) for v in value)
            return value
        frozen=freeze(plain(shape))
        return cls(frozen,env,tuple(lengths),K,sha256(json.dumps(record,sort_keys=True,separators=(',',':')).encode()).hexdigest())
