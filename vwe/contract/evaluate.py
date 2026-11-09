"""Independent Python semantics for testing generated observers. Never eval()."""
from __future__ import annotations
from typing import Mapping,Any
from .ast import (Expr,Literal,Name,Unary,Binary,Conditional,Index,Call,Reduction,
                  Sort,ContractUndefined)
from .env import I64_MIN,I64_MAX
from .typecheck import TypedAst


def _integer(value: int) -> int:
    if not I64_MIN<=value<=I64_MAX: raise ContractUndefined('signed64 observer overflow')
    return value


def _div(a: int,b: int) -> int:
    if b==0: raise ContractUndefined('division by zero')
    if a==I64_MIN and b==-1: raise ContractUndefined('signed division overflow')
    q=abs(a)//abs(b)
    return -q if (a<0)!=(b<0) else q


def evaluate(typed: TypedAst,values: Mapping[str,Any]) -> int|bool:
    def read(name: str,value: Any) -> int|bool:
        s=typed.env.symbols[name]
        if type(value) not in {int,bool} or not s.values.low<=value<=s.values.high:
            raise ContractUndefined(f'invalid snapshot value for {name}')
        return bool(value) if s.scalar.sort is Sort.BOOL else int(value)
    def go(node: Expr,local: dict[str,int]) -> Any:
        if isinstance(node,Literal): return node.value
        if isinstance(node,Name):
            if node.value in local: return local[node.value]
            if node.value in typed.env.constants: return typed.env.constants[node.value]
            if node.value not in values: raise ContractUndefined(f'missing snapshot: {node.value}')
            s=typed.env.symbols[node.value]
            return values[node.value] if s.sort is Sort.BUFFER else read(node.value,values[node.value])
        if isinstance(node,Index):
            array=go(node.base,local);i=go(node.index,local)
            if not isinstance(array,(list,tuple)): raise ContractUndefined('null or invalid buffer snapshot')
            if i<0 or i>=len(array): raise ContractUndefined('contract array access outside object')
            return read(node.base.value,array[i])
        if isinstance(node,Unary):
            a=go(node.operand,local)
            return not a if node.op=='!' else _integer(-a if node.op=='-' else ~a)
        if isinstance(node,Binary):
            a=go(node.left,local)
            if node.op=='&&': return bool(a) and bool(go(node.right,local))
            if node.op=='||': return bool(a) or bool(go(node.right,local))
            b=go(node.right,local)
            if node.op=='+': return _integer(a+b)
            if node.op=='-': return _integer(a-b)
            if node.op=='*': return _integer(a*b)
            if node.op=='/': return _div(a,b)
            if node.op=='%': return a-_div(a,b)*b
            if node.op in {'<<','>>'}:
                if b<0 or b>=64 or (node.op=='<<' and a<0): raise ContractUndefined('invalid signed shift')
                return _integer(a<<b if node.op=='<<' else a>>b)
            if node.op=='&': return a&b
            if node.op=='|': return a|b
            if node.op=='^': return a^b
            if node.op=='==': return a==b
            if node.op=='!=': return a!=b
            if node.op=='<': return a<b
            if node.op=='<=': return a<=b
            if node.op=='>': return a>b
            if node.op=='>=': return a>=b
        if isinstance(node,Conditional): return go(node.yes if go(node.condition,local) else node.no,local)
        if isinstance(node,Call):
            args=[go(x,local) for x in node.arguments]
            return _integer(abs(args[0])) if node.name=='abs' else min(args) if node.name=='min' else max(args)
        if isinstance(node,Reduction):
            lo,hi=go(node.lower,local),go(node.upper,local)
            if max(0,hi-lo)>typed.env.quantifier_limit: raise ContractUndefined('snapshot exceeds finite range bound')
            result=True if node.kind=='forall' else False if node.kind=='exists' else 0
            for i in range(lo,hi):
                value=go(node.body,{**local,node.binder:i})
                if node.kind=='sum': result=_integer(result+value)
                elif node.kind=='count': result=_integer(result+int(bool(value)))
                elif node.kind=='forall': result=bool(value) and result
                else: result=bool(value) or result
            return result
        raise ContractUndefined('unhandled AST node')
    return go(typed.root,{})
