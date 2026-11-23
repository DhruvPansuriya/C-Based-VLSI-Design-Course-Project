"""Shared, typed C frontend for the integrated HLSCheck verifier.

The target integer model is ILP32 (char8, short16, int32, long32,
long-long64). Typedef resolution preserves primitive C type/rank and
qualifiers. Only stdint.h is modelled; other includes need explicit models.
"""
from copy import deepcopy
from dataclasses import asdict, dataclass
import re
import shutil
import subprocess

from pycparser import c_ast, c_generator, c_parser

from .checker import Unsupported

PRELUDE = '''
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;
'''
ABI_ASSERTIONS = '''
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");
'''
RESERVED = '__hlscheck_'


class InvalidC(Exception):
    pass


@dataclass(frozen=True)
class CType:
    c_type: str
    bits: int
    signed: bool

    @property
    def domain(self):
        if not self.bits:
            raise Unsupported('void has no input domain')
        return (-(1 << (self.bits-1)), (1 << (self.bits-1))-1) if self.signed else (0, (1 << self.bits)-1)


@dataclass
class Unit:
    function: object
    parameters: list
    return_type: CType
    canonical: str
    preprocessing: dict


def primitive(names):
    if names == ['void']:
        return CType('void', 0, False)
    if any(n not in ('signed', 'unsigned', 'char', 'short', 'int', 'long') for n in names):
        raise Unsupported('Unsupported primitive C type: ' + ' '.join(names))
    if names.count('long')>2 or any(names.count(n)>1 for n in ('signed','unsigned','char','short','int')):
        raise InvalidC('Repeated or invalid primitive type specifiers')
    if 'signed' in names and 'unsigned' in names:
        raise InvalidC('Type cannot be both signed and unsigned')
    unsigned = 'unsigned' in names
    if 'char' in names:
        if 'short' in names or 'long' in names or 'int' in names:
            raise InvalidC('Invalid char type')
        text = 'unsigned char' if unsigned else ('signed char' if 'signed' in names else 'char')
        return CType(text, 8, not unsigned)
    if 'short' in names:
        if 'long' in names:
            raise InvalidC('Invalid short/long type')
        text, width = 'short int', 16
    elif names.count('long') == 2:
        text, width = 'long long int', 64
    elif names.count('long') == 1:
        text, width = 'long int', 32
    else:
        text, width = 'int', 32
    return CType(('unsigned ' if unsigned else '') + text, width, not unsigned)


def integer_literal(value):
    value = re.sub(r'[uUlL]+$', '', value)
    if re.fullmatch(r'0[0-7]+', value):
        return int(value, 8)
    return int(value, 0) if value.lower().startswith(('0x', '0b')) else int(value, 10)


def constant_dimension(node):
    if isinstance(node, c_ast.Constant):
        try:
            return integer_literal(node.value)
        except ValueError as error:
            raise Unsupported('Array dimension is not an integer literal') from error
    if isinstance(node, c_ast.UnaryOp) and node.op in ('+', '-'):
        value = constant_dimension(node.expr)
        return value if node.op == '+' else -value
    if isinstance(node, c_ast.BinaryOp) and node.op in ('+', '-', '*'):
        a, b = constant_dimension(node.left), constant_dimension(node.right)
        return {'+': lambda:a+b, '-': lambda:a-b, '*': lambda:a*b}[node.op]()
    raise Unsupported('Array interfaces require constant integer dimensions')


def preprocess(source):
    # Run no user includes, command substitution, or shell. The fixed typedef
    # prelude avoids host libc/header-dependent integer widths.
    source = re.sub(r'\\\r?\n', '', source)
    tokens = r'"(?:\\.|[^"\\])*"|\x27(?:\\.|[^\x27\\])*\x27|/\*[\s\S]*?\*/|//[^\n]*'
    source = re.sub(tokens, lambda m: ' '+('\n'*m.group().count('\n')) if m.group().startswith(('/', '//')) else m.group(), source)
    lines = []
    for line in source.splitlines():
        if re.match(r'\s*#\s*include\s*[<"]stdint\.h[>"]\s*$', line):
            continue
        if re.match(r'\s*#\s*pragma\s+HLS\b', line):
            continue
        if re.match(r'\s*#\s*(include|include_next|import)\b', line):
            raise Unsupported('Only stdint.h is modelled; preprocess other headers with an explicit contract')
        if line.lstrip().startswith('#') and not re.match(r'\s*#\s*(define|undef|if|ifdef|ifndef|elif|else|endif|error|line)\b', line):
            raise Unsupported('Unsupported preprocessor directive')
        lines.append(line)
    compiler = shutil.which('clang')
    if not compiler:
        raise Unsupported('The integrated C frontend requires clang on PATH')
    command = [compiler, '--target=i686-w64-windows-gnu', '-std=c11', '-E', '-P', '-x', 'c', '-']
    process = subprocess.run(command, input=PRELUDE+'\n'+'\n'.join(lines), capture_output=True, text=True, timeout=15)
    if process.returncode:
        raise InvalidC(process.stderr.strip())
    return process.stdout, {'compiler': compiler, 'target': 'i686-w64-windows-gnu',
                            'method': 'Clang preprocessing with modelled stdint typedefs; no other includes',
                            'diagnostics': process.stderr}


def compile_unit(source, function=None):
    preprocessed, metadata = preprocess(source)
    try:
        tree = c_parser.CParser().parse(preprocessed)
    except c_parser.ParseError as error:
        raise InvalidC(str(error)) from error
    aliases = {}

    def resolve(node):
        if not isinstance(node, c_ast.TypeDecl) or not isinstance(node.type, c_ast.IdentifierType):
            raise Unsupported('Only integer scalar types and fixed one-dimensional arrays are modelled')
        if 'volatile' in node.quals or '_Atomic' in node.quals:
            raise Unsupported('Volatile/atomic state requires a separate observation model')
        names = node.type.names
        return aliases[names[0]] if len(names)==1 and names[0] in aliases else primitive(names)

    functions = []
    for item in tree.ext:
        if isinstance(item, c_ast.Typedef):
            if not isinstance(item.type, c_ast.TypeDecl) or item.type.quals:
                raise Unsupported('Pointer, aggregate and qualified typedefs are unsupported')
            kind = resolve(item.type)
            if item.name in aliases and aliases[item.name] != kind:
                raise Unsupported('Conflicting typedef: ' + item.name)
            aliases[item.name] = kind
        elif isinstance(item, c_ast.FuncDef):
            functions.append(item)
        else:
            raise Unsupported('Global state/prototypes are unsupported; supply one isolated function')
    if len(functions) != 1:
        raise Unsupported('Exactly one function definition is required per source')
    fn = functions[0]
    if function and fn.decl.name != function:
        raise Unsupported(f'Function {function!r} not found')
    if fn.decl.name == 'main' or fn.decl.name.startswith(RESERVED):
        raise Unsupported('Function uses a verifier-reserved name')
    result_type = resolve(fn.decl.type.type)
    params = fn.decl.type.args.params if fn.decl.type.args else []
    if len(params)==1 and isinstance(params[0], c_ast.Typename) and resolve(params[0].type).c_type=='void':
        params = []
    specs = []
    for position, p in enumerate(params):
        if not isinstance(p, c_ast.Decl) or not p.name:
            raise Unsupported('Named scalar/array parameters required')
        node = p.type; length = None
        if isinstance(node, c_ast.ArrayDecl):
            length = constant_dimension(node.dim)
            if not 1 <= length <= 4096:
                raise Unsupported('Array parameter length must be in 1..4096')
            node.dim = c_ast.Constant('int', str(length))
            node = node.type
        kind = resolve(node)
        if kind.bits == 0:
            raise InvalidC('void is not a parameter value type')
        specs.append({'position': position, 'name': p.name, 'length': length, **asdict(kind)})

    class Normalize(c_ast.NodeVisitor):
        def visit_TypeDecl(self, node):
            kind = resolve(node)
            node.type = c_ast.IdentifierType(kind.c_type.split())
        def visit_ID(self, node):
            if node.name.startswith(RESERVED):
                raise Unsupported('Input uses verifier-reserved identifiers')
        def visit_Decl(self, node):
            if node.name and node.name.startswith(RESERVED):
                raise Unsupported('Input uses verifier-reserved identifiers')
            if node.storage:
                raise Unsupported('Static/extern/thread-local declarations require a state model')
            self.generic_visit(node)
        def visit_FuncCall(self, node):
            raise Unsupported('Calls/recursion require explicit function models')
        def visit_PtrDecl(self, node):
            raise Unsupported('Unbounded pointer interfaces/casts are unsupported')
        def visit_Struct(self, node):
            raise Unsupported('Structs require an aggregate observation model')
        def visit_Union(self, node):
            raise Unsupported('Unions require an aggregate observation model')
    Normalize().visit(fn)
    canonical = c_generator.CGenerator().visit(fn)+'\n'
    checked = subprocess.run([metadata['compiler'], '--target=i686-w64-windows-gnu', '-std=c11', '-Werror=return-type', '-fsyntax-only', '-x', 'c', '-'],
        input=ABI_ASSERTIONS+canonical, capture_output=True, text=True, timeout=15)
    metadata['semantic_diagnostics'] = checked.stderr
    if checked.returncode:
        raise InvalidC(checked.stderr.strip())
    return Unit(fn, specs, result_type, canonical, metadata)


def compile_pair(original, candidate, function=None, scalar_ranges=None):
    left, right = compile_unit(original, function), compile_unit(candidate, function)
    shape = lambda unit: [(p['c_type'], p['length']) for p in unit.parameters]
    if shape(left) != shape(right) or left.return_type != right.return_type:
        raise Unsupported('Function interfaces differ; parameters are matched by position')
    ranges = scalar_ranges or {}
    if not isinstance(ranges, dict):
        raise Unsupported('Scalar ranges must be a parameter-to-[min,max] object')
    scalars = {p['name']: p for p in left.parameters if p['length'] is None}
    for name, limits in ranges.items():
        if name not in scalars or not isinstance(limits, (list, tuple)) or len(limits)!=2 or not all(type(x) is int for x in limits):
            raise Unsupported('Ranges must name original scalar parameters and contain two integers')
        p = scalars[name]; domain = CType(p['c_type'], p['bits'], p['signed']).domain
        if not domain[0] <= limits[0] <= limits[1] <= domain[1]:
            raise Unsupported('Empty or out-of-type-domain precondition')
    contract = {'integer_model': 'ILP32: char8/short16/int32/long32/long-long64; plain char signed',
        'parameters': left.parameters, 'return_type': asdict(left.return_type), 'scalar_ranges': ranges,
        'observations': 'Return value and every final parameter-array element',
        'memory': 'All parameter arrays valid and pairwise nonoverlapping; initial contents shared by value',
        'safety': 'Both programs must be free of modelled undefined behavior on the entire stated input domain',
        'proof_scope': 'Functional C equivalence at completion, not cycle-level or C-to-RTL equivalence'}
    return left, right, contract


def renamed_function(unit, name):
    fn = deepcopy(unit.function)
    fn.decl.name = fn.decl.type.type.declname = name
    return c_generator.CGenerator().visit(fn)
