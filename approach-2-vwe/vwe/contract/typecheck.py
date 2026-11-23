"""Type/finite-range checks. UB-freedom remains a separate V-G obligation."""
from __future__ import annotations
from dataclasses import dataclass
from types import MappingProxyType
from typing import Mapping,Iterator
from .ast import (Expr,Literal,Name,Unary,Binary,Conditional,Index,Call,Reduction,
                  Sort,Interval,NodeType,ContractTypeError,ContractUnsupported)
from .env import TypeEnv,I64_MIN,I64_MAX
from .parser import parse


@dataclass(frozen=True)
class TypedAst:
    root: Expr
    env: TypeEnv
    nodes: Mapping[int,NodeType]
    used_symbols: tuple[str,...]
    old_symbols: tuple[str,...]

    @property
    def sort(self) -> Sort: return self.nodes[id(self.root)].sort
    @property
    def cost(self) -> int: return self.nodes[id(self.root)].cost


def children(node: Expr) -> tuple[Expr,...]:
    if isinstance(node,Unary): return (node.operand,)
    if isinstance(node,Binary): return (node.left,node.right)
    if isinstance(node,Conditional): return (node.condition,node.yes,node.no)
    if isinstance(node,Index): return (node.base,node.index)
    if isinstance(node,Call): return node.arguments
    if isinstance(node,Reduction): return (node.lower,node.upper,node.body)
    return ()


def _names(node: Expr) -> set[str]:
    if isinstance(node,Name): return {node.value}
    return set().union(*(_names(x) for x in children(node))) if children(node) else set()


def _arith(op: str,a: Interval,b: Interval) -> Interval:
    if op=='+': return Interval(a.low+b.low,a.high+b.high)
    if op=='-': return Interval(a.low-b.high,a.high-b.low)
    if op=='*':
        vals=[x*y for x in (a.low,a.high) for y in (b.low,b.high)]
        return Interval(min(vals),max(vals))
    if op=='/' and (b.low>0 or b.high<0):
        def trunc(x: int,y: int) -> int:
            q=abs(x)//abs(y);return -q if (x<0)!=(y<0) else q
        vals=[trunc(x,y) for x in (a.low,a.high) for y in (b.low,b.high)]
        return Interval(min(vals),max(vals))
    if op in {'<<','>>'}:
        if b.low<0 or b.high>=64:
            raise ContractUnsupported('shift-count range is not statically within 0..63')
        if op=='<<' and (a.low<0 or a.high>(I64_MAX>>b.high)):
            raise ContractUnsupported('signed left shift is not statically representable')
        vals=[x<<y if op=='<<' else x>>y for x in (a.low,a.high) for y in (b.low,b.high)]
        return Interval(min(vals),max(vals))
    # Division/modulo/bitwise/shift need checked runtime semantics; no guessed
    # tight bound is used to prove a loop finite.
    return Interval(I64_MIN,I64_MAX)


def typecheck(expr: Expr|str,env: TypeEnv,*,expected: Sort|None=None) -> TypedAst:
    root=parse(expr) if isinstance(expr,str) else expr
    annotations: dict[int,NodeType]={};used: set[str]=set();old: set[str]=set()
    def require(info: NodeType,sort: Sort) -> None:
        if info.sort is not sort: raise ContractTypeError(f'expected {sort.value}, got {info.sort.value}')
    def visit(node: Expr,locals: dict[str,Interval],depth: int=0) -> NodeType:
        if depth>64: raise ContractUnsupported('contract typing depth limit')
        def sub(n: Expr) -> NodeType: return visit(n,locals,depth+1)
        if isinstance(node,Literal):
            if type(node.value) is bool: result=NodeType(Sort.BOOL,Interval(int(node.value),int(node.value)))
            elif I64_MIN<=node.value<=I64_MAX: result=NodeType(Sort.INT,Interval(node.value,node.value))
            else: raise ContractUnsupported('integer literal exceeds signed64 observer profile')
        elif isinstance(node,Name):
            name=node.value
            if name.startswith(('__','VE_')): raise ContractTypeError('reserved identifier')
            if name in locals: result=NodeType(Sort.INT,locals[name])
            elif name in env.constants:
                v=env.constants[name];result=NodeType(Sort.INT,Interval(v,v))
            elif name in env.symbols:
                s=env.symbols[name]
                if s.role=='old':
                    if not env.allow_old: raise ContractTypeError('old output requires explicit permission and V-3 definedness proof')
                    old.add(name)
                used.add(name)
                if s.sort is not Sort.BUFFER and (s.values.low<I64_MIN or s.values.high>I64_MAX):
                    raise ContractUnsupported(f'{name} does not fit the signed64 observer profile')
                result=NodeType(s.sort,s.values if s.sort is not Sort.BUFFER else None)
            else: raise ContractTypeError(f'unknown name: {name}')
        elif isinstance(node,Index):
            if not isinstance(node.base,Name) or node.base.value not in env.symbols:
                raise ContractTypeError('only registered buffers may be indexed')
            base=sub(node.base);index=sub(node.index);require(base,Sort.BUFFER);require(index,Sort.INT)
            s=env.symbols[node.base.value]
            if s.values.low<I64_MIN or s.values.high>I64_MAX:
                raise ContractUnsupported('buffer element exceeds signed64 observer profile')
            result=NodeType(s.scalar.sort,s.values,1+base.cost+index.cost)
        elif isinstance(node,Unary):
            if node.op not in {'!','-','~'}: raise ContractTypeError('unknown unary operator')
            arg=sub(node.operand)
            if node.op=='!': require(arg,Sort.BOOL);result=NodeType(Sort.BOOL,Interval(0,1),arg.cost+1)
            else:
                require(arg,Sort.INT)
                r=Interval(-arg.interval.high,-arg.interval.low) if node.op=='-' else Interval(I64_MIN,I64_MAX)
                result=NodeType(Sort.INT,r,arg.cost+1)
        elif isinstance(node,Binary):
            if node.op not in {'+','-','*','/','%','<<','>>','&','|','^','==','!=','<','<=','>','>=','&&','||'}:
                raise ContractTypeError('unknown binary operator')
            a,b=sub(node.left),sub(node.right)
            if node.op in {'&&','||'}: require(a,Sort.BOOL);require(b,Sort.BOOL);sort=Sort.BOOL
            elif node.op in {'==','!='}:
                if a.sort is Sort.BUFFER or a.sort is not b.sort: raise ContractTypeError('incompatible equality operands')
                sort=Sort.BOOL
            elif node.op in {'<','<=','>','>='}: require(a,Sort.INT);require(b,Sort.INT);sort=Sort.BOOL
            else: require(a,Sort.INT);require(b,Sort.INT);sort=Sort.INT
            result=NodeType(sort,Interval(0,1) if sort is Sort.BOOL else _arith(node.op,a.interval,b.interval),1+a.cost+b.cost)
        elif isinstance(node,Conditional):
            c,a,b=sub(node.condition),sub(node.yes),sub(node.no);require(c,Sort.BOOL)
            if a.sort is Sort.BUFFER or a.sort is not b.sort: raise ContractTypeError('conditional branches must have the same scalar type')
            result=NodeType(a.sort,Interval(min(a.interval.low,b.interval.low),max(a.interval.high,b.interval.high)),c.cost+max(a.cost,b.cost)+1)
        elif isinstance(node,Call):
            if node.name not in {'min','max','abs'}: raise ContractTypeError('unknown helper')
            count=1 if node.name=='abs' else 2
            if len(node.arguments)!=count: raise ContractTypeError(f'{node.name} expects {count} argument(s)')
            args=[sub(x) for x in node.arguments]
            for a in args: require(a,Sort.INT)
            if node.name=='abs': r=Interval(0,max(abs(args[0].interval.low),abs(args[0].interval.high)))
            elif node.name=='min': r=Interval(min(a.interval.low for a in args),min(a.interval.high for a in args))
            else: r=Interval(max(a.interval.low for a in args),max(a.interval.high for a in args))
            result=NodeType(Sort.INT,r,1+sum(a.cost for a in args))
        elif isinstance(node,Reduction):
            if node.kind not in {'forall','exists','sum','count'}: raise ContractTypeError('unknown reduction')
            if node.binder in env.symbols or node.binder in env.constants or node.binder in locals or node.binder.startswith(('__','VE_')):
                raise ContractTypeError('reduction binder must be fresh')
            if (_names(node.lower)|_names(node.upper))-(set(env.size_parameters)|set(env.constants)):
                raise ContractTypeError('quantifier bounds may use only size parameters and constants')
            if any(isinstance(x,Reduction) for x in _walk(node.lower)) or any(isinstance(x,Reduction) for x in _walk(node.upper)):
                raise ContractTypeError('reductions cannot be used as quantifier bounds')
            lo,hi=sub(node.lower),sub(node.upper);require(lo,Sort.INT);require(hi,Sort.INT)
            span=max(0,hi.interval.high-lo.interval.low)
            if span>env.quantifier_limit: raise ContractUnsupported('quantifier range exceeds the finite observer limit')
            local_range=Interval(min(lo.interval.low,hi.interval.high),max(lo.interval.low,hi.interval.high-1))
            body=visit(node.body,{**locals,node.binder:local_range},depth+1)
            require(body,Sort.INT if node.kind=='sum' else Sort.BOOL)
            sort=Sort.INT if node.kind in {'sum','count'} else Sort.BOOL
            if node.kind=='sum': r=Interval(min(0,body.interval.low*span),max(0,body.interval.high*span))
            else: r=Interval(0,span if node.kind=='count' else 1)
            result=NodeType(sort,r,lo.cost+hi.cost+span*(body.cost+1)+1)
        else: raise ContractTypeError('unknown AST node')
        if result.cost>env.evaluation_limit: raise ContractUnsupported('contract evaluation budget exceeded')
        annotations[id(node)]=result
        return result
    info=visit(root,{})
    if expected is not None and info.sort is not expected: raise ContractTypeError(f'root must be {expected.value}')
    return TypedAst(root,env,MappingProxyType(annotations),tuple(sorted(used)),tuple(sorted(old)))


def _walk(node: Expr) -> Iterator[Expr]:
    yield node
    for child in children(node): yield from _walk(child)
