"""Portable C observers; lazy guards are preserved, UB is never assumed away."""
from __future__ import annotations
from dataclasses import dataclass
import argparse
import re
from pathlib import Path
from .ast import (Expr,Literal,Name,Unary,Binary,Conditional,Index,Call,Reduction,
                  Sort,LoweringError,GrammarError,ContractTypeError,ContractUnsupported)
from .env import TypeEnv,I64_MIN
from .typecheck import TypedAst,typecheck


@dataclass(frozen=True)
class EmittedFunction:
    source: str
    name: str
    parameters: tuple[str,...]
    uses_old: tuple[str,...]
    loop_limits: tuple[tuple[str,int],...]=()
    vg_required: bool=True


def _literal(value: int|bool) -> str:
    if type(value) is bool: return '1' if value else '0'
    if value==I64_MIN: return '(-9223372036854775807LL - 1LL)'
    return f'({value}LL)'


class _Emitter:
    def __init__(self,typed: TypedAst) -> None:
        self.typed=typed;self.counter=0;self.binders: dict[str,str]={}
        self.arguments={name:f've_arg_{i}' for i,name in enumerate(typed.used_symbols)}
        self.loop_limits: list[tuple[str,int]]=[]

    def temp(self) -> str:
        value=f've_t_{self.counter}';self.counter+=1;return value

    @staticmethod
    def block(lines: list[str]) -> list[str]: return ['  '+line for line in lines]

    def lower(self,node: Expr) -> tuple[list[str],str]:
        if isinstance(node,Literal): return [],_literal(node.value)
        if isinstance(node,Name):
            if node.value in self.binders: return [],self.binders[node.value]
            if node.value in self.typed.env.constants: return [],_literal(self.typed.env.constants[node.value])
            value=self.arguments[node.value]
            if self.typed.nodes[id(node)].sort is Sort.INT: value=f'((long long){value})'
            return [],value
        if isinstance(node,Index):
            before,index=self.lower(node.index)
            base=self.arguments[node.base.value]
            value=f'{base}[{index}]'
            if self.typed.nodes[id(node)].sort is Sort.INT: value=f'((long long){value})'
            return before,value
        if isinstance(node,Unary):
            before,arg=self.lower(node.operand);return before,f'({node.op}({arg}))'
        if isinstance(node,Binary):
            left,a=self.lower(node.left);right,b=self.lower(node.right)
            if node.op in {'&&','||'}:
                temp=self.temp()
                guard=temp if node.op=='&&' else '!'+temp
                return [*left,f'int {temp} = !!({a});',f'if ({guard}) {{',
                        *self.block([*right,f'{temp} = !!({b});']),'}'],temp
            return [*left,*right],f'(({a}) {node.op} ({b}))'
        if isinstance(node,Conditional):
            cond,c=self.lower(node.condition);yes,a=self.lower(node.yes);no,b=self.lower(node.no)
            temp=self.temp();ctype='int' if self.typed.nodes[id(node)].sort is Sort.BOOL else 'long long'
            return [*cond,f'{ctype} {temp};',f'if ({c}) {{',*self.block([*yes,f'{temp} = {a};']),
                    '} else {',*self.block([*no,f'{temp} = {b};']),'}'],temp
        if isinstance(node,Call):
            statements=[];args=[]
            for arg in node.arguments:
                before,value=self.lower(arg);temp=self.temp()
                statements.extend([*before,f'long long {temp} = {value};']);args.append(temp)
            if node.name=='abs': value=f'({args[0]} < 0 ? -{args[0]} : {args[0]})'
            else:
                op='<' if node.name=='min' else '>'
                value=f'({args[0]} {op} {args[1]} ? {args[0]} : {args[1]})'
            return statements,value
        if isinstance(node,Reduction):
            lo,a=self.lower(node.lower);hi,b=self.lower(node.upper)
            low,high,acc,index=(self.temp() for _ in range(4))
            lo_type=self.typed.nodes[id(node.lower)].interval
            hi_type=self.typed.nodes[id(node.upper)].interval
            self.loop_limits.append((index,max(0,hi_type.high-lo_type.low)))
            self.binders[node.binder]=index
            body,value=self.lower(node.body)
            del self.binders[node.binder]
            initial='1' if node.kind=='forall' else '0'
            ctype='int' if node.kind in {'forall','exists'} else 'long long'
            if node.kind=='sum': update=f'{acc} += {value};'
            elif node.kind=='count': update=f'{acc} += !!({value});'
            elif node.kind=='forall': update=f'{acc} = !!({value}) && {acc};'
            else: update=f'{acc} = !!({value}) || {acc};'
            # Every body instance is evaluated: no quantifier short-circuit can
            # conceal a later invalid array access. Inner guards remain lazy.
            return [*lo,f'long long {low} = {a};',*hi,f'long long {high} = {b};',
                    f'{ctype} {acc} = {initial};',f'for (long long {index} = {low}; {index} < {high}; ++{index}) {{',
                    *self.block([*body,update]),'}'],acc
        raise LoweringError('unsupported AST node')


def emit_function(expr: Expr|str|TypedAst,env: TypeEnv|None=None,*,name: str='vwe_clause',wide: str='long long',boolean: bool=True) -> EmittedFunction:
    if wide!='long long': raise ContractUnsupported('only the signed64 C observer profile is qualified')
    if not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*',name) or name.startswith('__'):
        raise LoweringError('invalid observer function name')
    if isinstance(expr,TypedAst): typed=expr
    else:
        if env is None: raise LoweringError('type environment required')
        typed=typecheck(expr,env)
    if typed.sort is Sort.BUFFER: raise LoweringError('observer cannot return a buffer')
    if boolean and typed.sort is not Sort.BOOL: raise ContractTypeError('a clause must be Boolean')
    emitter=_Emitter(typed);declarations=[]
    for key in typed.used_symbols:
        s=typed.env.symbols[key];ctype=s.scalar.c_name
        if s.sort is Sort.BUFFER: ctype='const '+ctype+' *'
        declarations.append(f'{ctype} {emitter.arguments[key]}')
    lines,value=emitter.lower(typed.root)
    ret='int' if boolean or typed.sort is Sort.BOOL else 'long long'
    text='/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */\n'
    text+=f'static inline {ret} {name}('+(', '.join(declarations) or 'void')+') {\n'
    text+='\n'.join('  '+x for x in [*lines,f'return {value};'])+'\n}\n'
    return EmittedFunction(text,name,typed.used_symbols,typed.old_symbols,tuple(emitter.loop_limits))


def emit_c(expr: Expr|str|TypedAst,env: TypeEnv|None=None,wide: str='long long') -> str:
    return emit_function(expr,env,wide=wide).source


def main(argv: list[str]|None=None) -> int:
    from ..tasks import load_pipeline_view
    p=argparse.ArgumentParser(description='Emit an observer; this command produces no repair verdict.')
    p.add_argument('expression');p.add_argument('--task',type=Path,required=True)
    args=p.parse_args(argv)
    try:
        # Preview accepts old names; T07 must independently prove their guards.
        env=TypeEnv.from_task(load_pipeline_view(args.task),allow_old=True)
        print(emit_c(args.expression,env),end='')
    except (GrammarError,ContractTypeError,ContractUnsupported,LoweringError) as exc:
        p.exit(2,f'contract: {exc}\n')
    return 0


if __name__=='__main__': raise SystemExit(main())
