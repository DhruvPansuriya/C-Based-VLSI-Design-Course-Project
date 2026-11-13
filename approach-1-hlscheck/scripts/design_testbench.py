"""Typed native and RTL-simulation testbenches for the admitted C model."""
from copy import deepcopy
import hashlib
import re


def value_at(spec, trial, element, ranges):
    bits = spec['bits']
    mask = (1 << bits) - 1
    edge = [0, 1, mask, 1 << (bits - 1), (1 << (bits - 1)) - 1,
            2, 0x5555555555555555 & mask, 0xAAAAAAAAAAAAAAAA & mask]
    if trial < len(edge):
        value = edge[trial]
    else:
        key = f'5291:{trial}:{spec["position"]}:{element}'.encode()
        value = int.from_bytes(hashlib.sha256(key).digest()[:8], 'little') & mask
    if spec['signed'] and value >= 1 << (bits - 1):
        value -= 1 << bits
    if spec['length'] is None and spec['name'] in ranges:
        low, high = ranges[spec['name']]
        if trial == 0:
            return low
        if trial == 1:
            return high
        return low + ((value - low) % (high - low + 1))
    return value


def golden_source(unit):
    """Lower target long32 to int32 in a host-LP64 simulation reference only."""
    from pycparser import c_ast, c_generator
    fn = deepcopy(unit.function)
    fn.decl.name = fn.decl.type.type.declname = 'reference'
    class LowerLong(c_ast.NodeVisitor):
        def visit_IdentifierType(self, node):
            if node.names.count('long') == 1:
                node.names = ['unsigned', 'int'] if 'unsigned' in node.names else ['int']
    LowerLong().visit(fn)
    # A host64 long literal can change usual arithmetic conversions even when
    # all declared long locals have been lowered. Preserve its ILP32 type too.
    def lower_literals(node):
        if not isinstance(node, c_ast.Node):
            return node
        for slot in node.__slots__:
            if slot in ('coord', '__weakref__'):
                continue
            value = getattr(node, slot, None)
            if isinstance(value, c_ast.Node):
                setattr(node, slot, lower_literals(value))
            elif isinstance(value, list):
                setattr(node, slot, [lower_literals(v) for v in value])
        if not isinstance(node, c_ast.Constant) or node.type == 'char':
            return node
        suffix = re.search(r'[uUlL]+$', node.value)
        if suffix is None or suffix.group().lower().count('l') != 1:
            return node
        text = node.value[:suffix.start()]
        radix = 16 if text.lower().startswith('0x') else (2 if text.lower().startswith('0b') else (8 if len(text)>1 and text.startswith('0') else 10))
        value = int(text, radix)
        unsigned = 'u' in suffix.group().lower()
        if value <= (0xffffffff if unsigned else 0x7fffffff):
            kind = ['unsigned', 'int'] if unsigned else ['int']
        elif not unsigned and radix != 10 and value <= 0xffffffff:
            kind = ['unsigned', 'int']
        else:
            return c_ast.Constant('unsigned long long int' if unsigned or value>0x7fffffffffffffff else 'long long int',
                                  str(value)+('ULL' if unsigned or value>0x7fffffffffffffff else 'LL'))
        typename = c_ast.Typename(None, [], None, c_ast.TypeDecl(None, [], None, c_ast.IdentifierType(kind)))
        return c_ast.Cast(typename, c_ast.Constant('unsigned long long int', str(value)+'ULL'))
    fn = lower_literals(fn)
    return c_generator.CGenerator().visit(fn)


def make_testbench(original, candidate=None, *, function=None, scalar_ranges=None,
                   trials=264, hls=False):
    from hlscheck.frontend import compile_pair, ABI_ASSERTIONS
    from hlscheck.miter import function_source, literal
    left, right, contract = compile_pair(original, candidate if candidate is not None else original,
                                         function, scalar_ranges=scalar_ranges)
    if hls:
        # The hardware adapter always supplies a top function named kernel.
        prototype = left.canonical.split('\n{', 1)[0]
        prototype = prototype.replace(left.function.decl.name + '(', 'kernel(', 1)
        lines = ['#include <stdint.h>', '#include <assert.h>', prototype + ';',
                 '_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");',
                 golden_source(left)]
    else:
        lines = ['#include <stdint.h>', '#include <stdio.h>', ABI_ASSERTIONS,
                 function_source(left, 'reference'), function_source(right, 'candidate')]
    lines.append('int main(void) {')
    for trial in range(trials):
        lines.append('{')
        args_a, args_b, equal = [], [], []
        for p in left.parameters:
            a, b = f'left_{p["position"]}', f'right_{p["position"]}'
            args_a.append(a)
            args_b.append(b)
            # HLS TB scalar interfaces cannot contain target long32 in a host64 prototype.
            kind = p['c_type']
            if hls and 'long' in kind.split() and kind.split().count('long') == 1:
                raise ValueError('A long32 scalar/array HLS interface needs an explicit host-width adapter')
            if p['length'] is None:
                value = literal(value_at(p, trial, 0, contract['scalar_ranges']), p)
                lines += [f'{kind} {a}={value};', f'{kind} {b}={a};']
            else:
                values = ','.join(literal(value_at(p, trial, j, {}), p) for j in range(p['length']))
                lines += [f'{kind} {a}[{p["length"]}]={{{values}}};',
                          f'{kind} {b}[{p["length"]}]={{{values}}};']
                equal += [f'{a}[{j}]=={b}[{j}]' for j in range(p['length'])]
        ca = 'reference(' + ','.join(args_a) + ');'
        cb = ('kernel' if hls else 'candidate') + '(' + ','.join(args_b) + ');'
        result_kind = left.return_type.c_type
        if hls and result_kind.split().count('long') == 1:
            raise ValueError('A long32 HLS return needs an explicit host-width adapter')
        if result_kind == 'void':
            lines += [ca, cb]
        else:
            lines += [result_kind + ' original_return=' + ca,
                      result_kind + ' candidate_return=' + cb]
            equal += ['original_return==candidate_return']
        condition = ' && '.join('(' + x + ')' for x in equal) or '1'
        lines += [f'assert({condition});' if hls else
                  f'if(!({condition})){{printf("Mismatch at trial {trial}\\n");return 1;}}', '}']
    if not hls:
        lines.append(f'printf("PASS: {trials} typed edge/random comparisons\\n");')
    lines += ['return 0;', '}']
    return '\n'.join(lines) + '\n'
