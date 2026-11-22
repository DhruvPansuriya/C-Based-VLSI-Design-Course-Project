"""Certified relational loop summaries used inside one C verification problem.

A summary is applied only after a universal SMT proof. Shared havoc is a
sound overapproximation of the equal poststates. A failed abstract check must
be refined before reporting a mismatch or a C safety violation.
"""
from copy import deepcopy

from pycparser import c_ast, c_generator
import z3

from .checker import Unsupported, Interpreter, parse


def identifiers(node):
    result = set()
    class Visit(c_ast.NodeVisitor):
        def visit_ID(self, item): result.add(item.name)
    Visit().visit(node)
    return result


def split_region(unit):
    """Find a leading static-region candidate, excluding live local state.

    Leading declarations may support the loops, but no declared local may
    escape into the suffix. Scalar parameter writes and returns are excluded.
    Different loop nests/counts can be compared at the common array interface.
    """
    items = unit.function.body.block_items or []
    end = 0; saw_loop = False
    for i, item in enumerate(items):
        if isinstance(item, c_ast.Decl):
            # Keep declarations after a loop in the suffix; their initializers
            # may depend on the completed region, and they may be live later.
            if saw_loop: break
        elif isinstance(item, c_ast.For):
            saw_loop = True; end = i+1
        else:
            break
    if not saw_loop:
        raise Unsupported('No leading loop region with an explicit state boundary')
    region, suffix = items[:end], items[end:]
    locals_at_cut = {n.name for n in region if isinstance(n, c_ast.Decl)}
    future = set().union(*(identifiers(n) for n in suffix)) if suffix else set()
    if locals_at_cut & future:
        raise Unsupported('Region has local live-outs: ' + ', '.join(sorted(locals_at_cut & future)))
    scalar_params = {p['name'] for p in unit.parameters if p['length'] is None}
    class Check(c_ast.NodeVisitor):
        def visit_Return(self, node):
            raise Unsupported('Region contains a return; no completion-state summary')
        def visit_Assignment(self, node):
            if isinstance(node.lvalue, c_ast.ID) and node.lvalue.name in scalar_params:
                raise Unsupported('Region modifies a scalar parameter used by the suffix')
            self.generic_visit(node)
        def visit_UnaryOp(self, node):
            if node.op in ('p++','p--','++','--') and isinstance(node.expr, c_ast.ID) and node.expr.name in scalar_params:
                raise Unsupported('Region modifies a scalar parameter used by the suffix')
            self.generic_visit(node)
    for node in region: Check().visit(node)
    wrapper = deepcopy(unit.function)
    wrapper.body.block_items = deepcopy(region)
    wrapper.decl.type.type.type = c_ast.IdentifierType(['void'])
    wrapper.decl.type.type.quals = []
    residual = deepcopy(unit.function)
    residual.body.block_items = deepcopy(suffix)
    return {'region_source': c_generator.CGenerator().visit(wrapper)+'\n',
            'residual_function': residual, 'statement_count': end,
            'whole_function': False,
            'at_function_exit': not suffix and unit.return_type.c_type=='void',
            'boundary': 'All parameter arrays; unchanged scalar parameters; no local live-outs'}


def whole_function_region(unit):
    """A function-exit cut observes returns as well as parameter arrays.

    The lemma is checked on the actual function, preserving non-void return
    safety checks. The residual returns one shared symbolic return-state cell.
    """
    residual = deepcopy(unit.function)
    lifted_return = unit.return_type.c_type != 'void'
    if lifted_return:
        if unit.return_type.c_type != 'unsigned int':
            raise Unsupported('Whole-function SMT summary requires an unsigned-32 or void return')
        extra = parse('void f(unsigned int __hlscheck_return_state[1]){}', None).decl.type.args.params[0]
        if residual.decl.type.args is None:
            residual.decl.type.args = c_ast.ParamList([extra])
        elif len(residual.decl.type.args.params)==1 and isinstance(residual.decl.type.args.params[0], c_ast.Typename):
            residual.decl.type.args.params = [extra]
        else:
            residual.decl.type.args.params.append(extra)
        residual.body.block_items = [c_ast.Return(c_ast.ArrayRef(c_ast.ID('__hlscheck_return_state'), c_ast.Constant('int','0')))]
    else:
        residual.body.block_items = []
    return {'region_source': unit.canonical, 'residual_function': residual,
            'statement_count': len(unit.function.body.block_items or []), 'whole_function': True,
            'at_function_exit': True,
            'lifted_return': lifted_return,
            'boundary': 'Function exit: every parameter-array element and the return value'}


def c_expression(expression, symbols):
    """Emit exact unsigned-32 C for a restricted Z3 bit-vector expression."""
    if z3.is_bv_value(expression):
        return str(expression.as_long())+'u'
    if z3.is_true(expression): return '1'
    if z3.is_false(expression): return '0'
    if expression.num_args() == 0:
        name = str(expression)
        if name not in symbols:
            raise Unsupported('Summary contains an unmodelled symbol: '+name)
        return symbols[name]
    kind = expression.decl().kind()
    children = [c_expression(e, symbols) for e in expression.children()]
    binary = {z3.Z3_OP_BADD:'+', z3.Z3_OP_BSUB:'-', z3.Z3_OP_BMUL:'*',
              z3.Z3_OP_BAND:'&', z3.Z3_OP_BOR:'|', z3.Z3_OP_BXOR:'^',
              z3.Z3_OP_BSHL:'<<', z3.Z3_OP_BLSHR:'>>', z3.Z3_OP_BUDIV:'/',
              z3.Z3_OP_BUREM:'%', z3.Z3_OP_EQ:'==', z3.Z3_OP_DISTINCT:'!=',
              z3.Z3_OP_ULT:'<', z3.Z3_OP_ULEQ:'<=', z3.Z3_OP_UGT:'>', z3.Z3_OP_UGEQ:'>=',
              z3.Z3_OP_AND:'&&', z3.Z3_OP_OR:'||'}
    if kind in binary and len(children) >= 2:
        return '('+(' '+binary[kind]+' ').join(children)+')'
    if kind == z3.Z3_OP_BNOT: return '(~'+children[0]+')'
    if kind == z3.Z3_OP_BNEG: return '(0u-'+children[0]+')'
    if kind == z3.Z3_OP_NOT: return '(!'+children[0]+')'
    if kind == z3.Z3_OP_ITE:
        return '('+children[0]+' ? '+children[1]+' : '+children[2]+')'
    raise Unsupported('Unsupported summary-expression operator: '+str(expression.decl()))


def exact_summary(unit, region, *, max_unroll=256, max_paths=256):
    """Generate a candidate summary; the caller MUST separately prove it.

    Snapshot every input array before assignments, so in-place updates retain
    the initial-state semantics. Source path guards become conditional terms.
    """
    if region.get('whole_function'):
        raise Unsupported('A full exit-state summary has no residual behavior to refine; restore the original C if required')
    fn = parse(region['region_source'], None)
    interpreted = Interpreter(fn, max_unroll=max_unroll, max_paths=max_paths).run()
    symbols = {}; declarations = []; assignments = []
    for position, p in enumerate(unit.parameters):
        if p['length'] is None:
            symbols[f'arg{position}'] = p['name']
        else:
            # A generated local snapshot avoids observing earlier summary stores.
            snapshot = f'__summary_input_{position}'
            if snapshot in {p['name'] for p in unit.parameters} or any(n.name == snapshot for n in (unit.function.body.block_items or []) if isinstance(n, c_ast.Decl)):
                raise Unsupported('Summary snapshot identifier collision')
            declarations.append(f'unsigned int {snapshot}[{p["length"]}];')
            for i in range(p['length']):
                declarations.append(f'{snapshot}[{i}]={p["name"]}[{i}];')
                symbols[f'arg{position}_{i}'] = f'{snapshot}[{i}]'
    for p in unit.parameters:
        if p['length'] is None: continue
        for i in range(p['length']):
            value = interpreted.initial.values[p['name']][i]
            for state in reversed(interpreted.finals):
                value = z3.If(state.guard, state.values[p['name']][i], value)
            value = z3.simplify(value)
            assignments.append(f'{p["name"]}[{i}]={c_expression(value, symbols)};')
    prototype = deepcopy(fn)
    # Parse generated statements through the same C AST machinery. This source
    # is not trusted until check_equivalence proves it against the real region.
    signature = c_generator.CGenerator().visit(prototype.decl)
    return signature+' {\n'+'\n'.join(declarations+assignments)+'\n}\n'
