"""Closed grammar. No eval, C parsing, source substitution or arbitrary calls."""
from __future__ import annotations
from importlib.resources import files
from typing import Any
from lark import Lark,Transformer,UnexpectedInput
from lark.exceptions import VisitError
from .ast import (Expr,Literal,Name,Unary,Binary,Conditional,Index,Call,Reduction,GrammarError,ContractUnsupported)


class _Build(Transformer):
    def integer(self,items: list[Any]) -> Literal:
        s=str(items[0]);return Literal(int(s,16 if s.lower().startswith('0x') else 10))
    def true(self,_: list[Any]) -> Literal: return Literal(True)
    def false(self,_: list[Any]) -> Literal: return Literal(False)
    def name(self,items: list[Any]) -> Name: return Name(str(items[0]))
    def unary(self,items: list[Any]) -> Expr:
        op,node=items
        # Normalize the one signed64 minimum literal without generating an
        # unrepresentable positive signed C literal.
        if str(op)=='-' and isinstance(node,Literal) and type(node.value) is int:
            return Literal(-node.value)
        return Unary(str(op),node)
    def binary_chain(self,items: list[Any]) -> Expr:
        result=items[0]
        for i in range(1,len(items),2): result=Binary(str(items[i]),result,items[i+1])
        return result
    def conditional(self,items: list[Any]) -> Conditional: return Conditional(*items)
    def postfix(self,items: list[Any]) -> Expr:
        result=items[0]
        for index in items[1:]: result=Index(result,index)
        return result
    def arguments(self,items: list[Any]) -> tuple[Expr,...]: return tuple(items)
    def call(self,items: list[Any]) -> Expr:
        name=str(items[0]);args=items[1] if len(items)>1 else ()
        if name in {'forall','exists','sum','count'}:
            if len(args)!=4 or not isinstance(args[0],Name):
                raise GrammarError(f'{name} requires (binder,lower,upper,body)')
            return Reduction(name,args[0].value,*args[1:])
        if name not in {'min','max','abs'}:
            raise GrammarError(f'call not allowed: {name}')
        return Call(name,tuple(args))


class ContractParser:
    def __init__(self,max_length: int=4000,max_nodes: int=1024,max_depth: int=64) -> None:
        self.max_length,self.max_nodes,self.max_depth=max_length,max_nodes,max_depth
        grammar=files('vwe.contract').joinpath('grammar.lark').read_text(encoding='utf-8')
        self._parser=Lark(grammar,parser='lalr',start='start')

    def parse(self,text: str) -> Expr:
        if not isinstance(text,str) or not text.strip(): raise GrammarError('empty contract')
        if len(text)>self.max_length: raise ContractUnsupported('contract length budget exceeded')
        if any(s in text for s in ('++','--','/*','//',';','{','}','#','"',"'")):
            raise GrammarError('statements, comments, literals and increment/decrement are forbidden')
        try:
            tree=self._parser.parse(text)
            # Check tree depth before the recursive transformer runs.
            stack=[(tree,0)];count=0
            while stack:
                node,depth=stack.pop();count+=1
                if count>self.max_nodes*8 or depth>self.max_depth*8:
                    raise ContractUnsupported('contract syntax complexity limit')
                stack.extend((x,depth+1) for x in getattr(node,'children',()))
            result=_Build().transform(tree)
        except UnexpectedInput as exc:
            raise GrammarError(f'invalid expression at line {exc.line}, column {exc.column}') from exc
        except VisitError as exc:
            if isinstance(exc.orig_exc,GrammarError): raise exc.orig_exc from exc
            raise GrammarError('invalid contract syntax') from exc
        nodes=[(result,0)];count=0
        while nodes:
            node,depth=nodes.pop();count+=1
            if count>self.max_nodes or depth>self.max_depth:
                raise ContractUnsupported('contract AST complexity limit')
            for value in vars(node).values():
                if isinstance(value,tuple): nodes.extend((v,depth+1) for v in value if hasattr(v,'__dataclass_fields__'))
                elif hasattr(value,'__dataclass_fields__'): nodes.append((value,depth+1))
        return result


def parse(text: str) -> Expr:
    return ContractParser().parse(text)
