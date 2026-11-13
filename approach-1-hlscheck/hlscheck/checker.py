"""Path-sensitive symbolic interpreter and bit-precise Z3 equivalence query.

Target data model: 32-bit int/unsigned int. Array parameters denote distinct,
nonoverlapping, valid arrays of the declared length. No globals, calls, pointer
arithmetic, expression side effects, symbolic signed integers or symbolic loop
bounds. Unsupported syntax is rejected rather than approximated.
"""

from __future__ import annotations

import re
import time
from dataclasses import dataclass, field
from pathlib import Path

import z3
from z3.z3util import get_vars
from pycparser import c_ast, c_parser


class Unsupported(Exception):
    pass


@dataclass(frozen=True)
class SignedExpression:
    """C int-valued predicates/conditionals, kept distinct from unsigned data."""

    bits: object


def bv(value):
    if isinstance(value, SignedExpression):
        return value.bits
    return z3.BitVecVal(value, 32) if isinstance(value, int) else value


def truth(value):
    return z3.BoolVal(value != 0) if isinstance(value, int) else bv(value) != 0


def concrete(value):
    if isinstance(value, int):
        return value
    signed = isinstance(value, SignedExpression)
    value = z3.simplify(bv(value))
    if z3.is_bv_value(value):
        return value.as_signed_long() if signed else value.as_long()
    raise Unsupported("A loop bound or array index depends on symbolic input")


def fixed_truth(value):
    simplified = z3.simplify(truth(value))
    if z3.is_true(simplified):
        return True
    if z3.is_false(simplified):
        return False
    raise Unsupported("Loop condition is symbolic; complete unrolling is required")


def signed_constant(value):
    if not -(2**31) <= value < 2**31:
        raise Unsupported("Signed constant arithmetic overflows 32-bit int")
    return value


@dataclass
class State:
    values: dict = field(default_factory=dict)
    types: dict = field(default_factory=dict)
    guard: object = field(default_factory=lambda: z3.BoolVal(True))
    returned: bool = False
    result: object = None

    def fork(self):
        # Z3 nodes are immutable; copy only the mutable Python containers.
        return State(
            {k: list(v) if isinstance(v, list) else v for k, v in self.values.items()},
            dict(self.types), self.guard, self.returned, self.result,
        )


def parse(source, function):
    source = re.sub(r"/\*.*?\*/|//[^\n]*", "", source, flags=re.S)
    lines = []
    for line in source.splitlines():
        if re.match(r"\s*#\s*include\s*[<\"]stdint.h[>\"]\s*$", line):
            continue
        if re.match(r"\s*#\s*pragma\s+HLS\b", line):
            continue
        if line.lstrip().startswith("#"):
            raise Unsupported("Preprocess macros/includes before checking (except stdint.h)")
        lines.append(line)
    tree = c_parser.CParser().parse("typedef unsigned int uint32_t;\n" + "\n".join(lines))
    functions = []
    for index, item in enumerate(tree.ext):
        if index == 0 and isinstance(item, c_ast.Typedef) and item.name == "uint32_t":
            continue
        if not isinstance(item, c_ast.FuncDef):
            raise Unsupported("Global declarations and custom typedefs are unsupported")
        functions.append(item)
    if len(functions) != 1:
        raise Unsupported("Exactly one function definition is required per file")
    fn = functions[0]
    if function and fn.decl.name != function:
        raise Unsupported(f"Function {function!r} not found")
    return fn


def type_name(node):
    if not isinstance(node, c_ast.TypeDecl) or not isinstance(node.type, c_ast.IdentifierType):
        raise Unsupported("Only 32-bit scalar integers and one-dimensional arrays are supported")
    if node.quals:
        raise Unsupported("Qualified types (including const) are outside this initial subset")
    names = node.type.names
    if names in (["uint32_t"], ["unsigned"], ["unsigned", "int"]):
        return "u32"
    if names in (["int"], ["signed"], ["signed", "int"]):
        return "int"
    if names == ["void"]:
        return "void"
    raise Unsupported(f"Unsupported type: {' '.join(names)}")


class Interpreter:
    def __init__(self, fn, inputs=None, max_unroll=256, max_paths=256):
        self.fn = fn
        self.max_unroll = max_unroll
        self.max_paths = max_paths
        self.steps = 0
        self.issues = []
        self.inputs = {} if inputs is None else inputs
        self.signature = []
        self.array_names = []
        self.return_type = type_name(fn.decl.type.type)
        if self.return_type not in ("u32", "void"):
            raise Unsupported("Return type must be uint32_t/unsigned int or void")

    def issue(self, state, condition, reason):
        self.issues.append((z3.And(state.guard, condition), reason))

    def coerce(self, value, kind):
        if kind == "u32":
            return z3.simplify(bv(value))
        if kind == "int" and isinstance(value, int):
            return signed_constant(value)
        raise Unsupported("Signed locals must stay concrete; symbolic signed arithmetic is unsupported")

    def initialize(self):
        state = State()
        params = self.fn.decl.type.args
        declarations = params.params if params else []
        if len(declarations) == 1 and isinstance(declarations[0], c_ast.Typename):
            if type_name(declarations[0].type) == "void":
                declarations = []
        for position, decl in enumerate(declarations):
            if not isinstance(decl, c_ast.Decl) or decl.storage or decl.funcspec:
                raise Unsupported("Unsupported parameter declaration")
            if decl.name in state.values:
                raise Unsupported("Duplicate parameter names")
            if isinstance(decl.type, c_ast.ArrayDecl):
                kind = type_name(decl.type.type)
                length = concrete(self.expr(decl.type.dim, state))
                if kind != "u32" or not 0 < length <= 4096 or decl.type.dim_quals:
                    raise Unsupported("Arrays require literal dimensions 1..4096 and uint32_t elements")
                self.signature.append(("array", kind, length))
                value = self.inputs.setdefault(str(position), [z3.BitVec(f"arg{position}_{i}", 32) for i in range(length)])
                self.array_names.append(decl.name)
            else:
                kind = type_name(decl.type)
                if kind != "u32":
                    raise Unsupported("Scalar input parameters must be uint32_t/unsigned int")
                self.signature.append(("scalar", kind))
                value = self.inputs.setdefault(str(position), z3.BitVec(f"arg{position}", 32))
            state.values[decl.name] = list(value) if isinstance(value, list) else value
            state.types[decl.name] = kind
        self.initial = state.fork()
        return state

    def read(self, node, state):
        if isinstance(node, c_ast.ID):
            if node.name not in state.values or state.values[node.name] is None:
                raise Unsupported(f"Read of undeclared/uninitialized variable {node.name}")
            if isinstance(state.values[node.name], list):
                raise Unsupported("An array may only be accessed through an element subscript")
            return state.values[node.name]
        if isinstance(node, c_ast.ArrayRef) and isinstance(node.name, c_ast.ID):
            name = node.name.name
            array = state.values.get(name)
            if not isinstance(array, list):
                raise Unsupported(f"Not an array: {name}")
            index = concrete(self.expr(node.subscript, state))
            if not 0 <= index < len(array):
                self.issue(state, z3.BoolVal(True), f"Out-of-bounds read: {name}[{index}]")
                return bv(0)
            if array[index] is None:
                raise Unsupported(f"Read of uninitialized array element {name}[{index}]")
            return array[index]
        raise Unsupported("Only scalar identifiers and concrete array elements are lvalues")

    def write(self, node, value, state):
        if isinstance(node, c_ast.ID):
            if node.name not in state.values or isinstance(state.values[node.name], list):
                raise Unsupported("Assignment to undeclared identifier or whole array")
            state.values[node.name] = self.coerce(value, state.types[node.name])
            return
        if isinstance(node, c_ast.ArrayRef) and isinstance(node.name, c_ast.ID):
            name = node.name.name
            array = state.values.get(name)
            if not isinstance(array, list):
                raise Unsupported(f"Not an array: {name}")
            index = concrete(self.expr(node.subscript, state))
            if not 0 <= index < len(array):
                self.issue(state, z3.BoolVal(True), f"Out-of-bounds write: {name}[{index}]")
                return
            array[index] = self.coerce(value, state.types[name])
            return
        raise Unsupported("Unsupported assignment target")

    def binary(self, op, a, b, state):
        if op in ("<<", ">>") and not z3.is_bv(a):
            raise Unsupported("Shift left operand must be unsigned; signed shifts have different C semantics")
        signed_symbolic = isinstance(a, SignedExpression) or isinstance(b, SignedExpression)
        unsigned_operand = (z3.is_bv(a) or z3.is_bv(b))
        if signed_symbolic and not unsigned_operand:
            raise Unsupported("Symbolic signed expression arithmetic/comparison is unsupported; cast to uint32_t")
        if isinstance(a, int) and isinstance(b, int):
            if op in ("==", "!=", "<", "<=", ">", ">="):
                return int({"==": a == b, "!=": a != b, "<": a < b, "<=": a <= b, ">": a > b, ">=": a >= b}[op])
            if op == "+": return signed_constant(a + b)
            if op == "-": return signed_constant(a - b)
            if op == "*": return signed_constant(a * b)
            if op in ("&", "|", "^", "<<", ">>", "/", "%"):
                # Signed bitwise and division corner cases are deliberately outside v0.1.
                raise Unsupported(f"Signed-only {op} is unsupported; use uint32_t operands")
        a, b = bv(a), bv(b)
        if op == "+": return a + b
        if op == "-": return a - b
        if op == "*": return a * b
        if op == "&": return a & b
        if op == "|": return a | b
        if op == "^": return a ^ b
        if op in ("/", "%"):
            self.issue(state, b == 0, "Division/remainder by zero")
            return z3.UDiv(a, b) if op == "/" else z3.URem(a, b)
        if op in ("<<", ">>"):
            self.issue(state, z3.UGE(b, bv(32)), "Shift amount is outside 0..31")
            return a << b if op == "<<" else z3.LShR(a, b)
        compares = {"==": lambda: a == b, "!=": lambda: a != b,
                    "<": lambda: z3.ULT(a, b), "<=": lambda: z3.ULE(a, b),
                    ">": lambda: z3.UGT(a, b), ">=": lambda: z3.UGE(a, b)}
        if op in compares:
            return SignedExpression(z3.If(compares[op](), bv(1), bv(0)))
        raise Unsupported(f"Unsupported binary operator {op}")

    def expr(self, node, state):
        if isinstance(node, (c_ast.ID, c_ast.ArrayRef)):
            return self.read(node, state)
        if isinstance(node, c_ast.Constant):
            if not re.fullmatch(r"(?:0[xX][0-9a-fA-F]+|0[0-7]*|[1-9][0-9]*)(?:[uU])?", node.value):
                raise Unsupported("Only int/unsigned int literals without long suffixes are supported")
            raw = re.sub(r"[uU]$", "", node.value)
            base = 16 if raw.lower().startswith("0x") else 8 if len(raw) > 1 and raw.startswith("0") else 10
            number = int(raw, base)
            if number > 0xFFFFFFFF:
                raise Unsupported("Literal exceeds 32 bits")
            unsigned = node.value[-1:] in ("u", "U") or (base != 10 and number >= 2**31)
            return bv(number) if unsigned else signed_constant(number)
        if isinstance(node, c_ast.BinaryOp):
            a = self.expr(node.left, state)
            if node.op in ("&&", "||"):
                take_right = truth(a) if node.op == "&&" else z3.Not(truth(a))
                if z3.is_false(z3.simplify(take_right)):
                    return 0 if node.op == "&&" else 1
                right_state = state.fork()
                right_state.guard = z3.And(state.guard, take_right)
                b = self.expr(node.right, right_state)
                result = z3.And(truth(a), truth(b)) if node.op == "&&" else z3.Or(truth(a), truth(b))
                result = z3.simplify(result)
                if z3.is_true(result): return 1
                if z3.is_false(result): return 0
                return SignedExpression(z3.If(result, bv(1), bv(0)))
            return self.binary(node.op, a, self.expr(node.right, state), state)
        if isinstance(node, c_ast.UnaryOp) and node.op in ("+", "-", "~", "!"):
            value = self.expr(node.expr, state)
            if node.op == "+": return value
            if node.op in ("-", "~") and isinstance(value, SignedExpression):
                raise Unsupported("Unary symbolic signed arithmetic is unsupported")
            if node.op == "-": return signed_constant(-value) if isinstance(value, int) else -value
            if node.op == "~": return ~value
            test = z3.simplify(z3.Not(truth(value)))
            if z3.is_true(test): return 1
            if z3.is_false(test): return 0
            return SignedExpression(z3.If(test, bv(1), bv(0)))
        if isinstance(node, c_ast.TernaryOp):
            condition = z3.simplify(truth(self.expr(node.cond, state)))
            yes, no = state.fork(), state.fork()
            yes.guard = z3.And(state.guard, condition)
            no.guard = z3.And(state.guard, z3.Not(condition))
            av, bv_ = self.expr(node.iftrue, yes), self.expr(node.iffalse, no)
            expression = z3.If(condition, bv(av), bv(bv_))
            if z3.is_bv(av) or z3.is_bv(bv_):
                return z3.simplify(expression)
            if z3.is_true(condition): return av
            if z3.is_false(condition): return bv_
            return SignedExpression(expression)
        if isinstance(node, c_ast.Cast):
            kind = type_name(node.to_type.type)
            return self.coerce(self.expr(node.expr, state), kind)
        raise Unsupported(f"Unsupported expression: {type(node).__name__}")

    def sequence(self, items, states):
        for item in items or []:
            new_states = []
            for state in states:
                if state.returned:
                    new_states.append(state)
                elif not z3.is_false(z3.simplify(state.guard)):
                    new_states.extend(self.statement(item, state))
            states = new_states
            if len(states) > self.max_paths:
                raise Unsupported(f"Path limit {self.max_paths} exceeded")
        return states

    def statement(self, node, state):
        self.steps += 1
        if self.steps > 200000:
            raise Unsupported("Symbolic execution step budget exceeded")
        if z3.is_false(z3.simplify(state.guard)):
            return []
        if node is None or isinstance(node, (c_ast.EmptyStatement, c_ast.Pragma)):
            return [state]
        if isinstance(node, c_ast.Compound):
            # Locals are flat, with block lifetimes handled by restoring names.
            before = set(state.values)
            states = self.sequence(node.block_items, [state])
            for output in states:
                for name in set(output.values) - before:
                    del output.values[name]
                    del output.types[name]
            return states
        if isinstance(node, c_ast.Label):
            return self.statement(node.stmt, state)
        if isinstance(node, c_ast.DeclList):
            return self.sequence(node.decls, [state])
        if isinstance(node, c_ast.Decl):
            if node.name in state.values:
                raise Unsupported("Variable shadowing/redeclaration is unsupported")
            if node.storage or node.funcspec or node.bitsize or node.align:
                raise Unsupported("Storage qualifiers, bitfields and alignment are unsupported")
            if isinstance(node.type, c_ast.ArrayDecl):
                kind = type_name(node.type.type)
                n = concrete(self.expr(node.type.dim, state))
                if kind != "u32" or not 0 < n <= 4096 or node.type.dim_quals:
                    raise Unsupported("Local arrays must have 1..4096 uint32_t elements")
                state.types[node.name] = kind
                state.values[node.name] = [None] * n
                if node.init:
                    if not isinstance(node.init, c_ast.InitList) or len(node.init.exprs) > n:
                        raise Unsupported("Unsupported local array initializer")
                    for i, expression in enumerate(node.init.exprs):
                        state.values[node.name][i] = self.coerce(self.expr(expression, state), kind)
                    for i in range(len(node.init.exprs), n):
                        state.values[node.name][i] = bv(0)
            else:
                kind = type_name(node.type)
                if kind not in ("u32", "int"):
                    raise Unsupported("Invalid local type")
                state.types[node.name] = kind
                state.values[node.name] = self.coerce(self.expr(node.init, state), kind) if node.init else None
            return [state]
        if isinstance(node, c_ast.Assignment):
            value = self.expr(node.rvalue, state)
            if node.op != "=":
                value = self.binary(node.op[:-1], self.read(node.lvalue, state), value, state)
            self.write(node.lvalue, value, state)
            return [state]
        if isinstance(node, c_ast.UnaryOp) and node.op in ("p++", "++", "p--", "--"):
            value = self.binary("+" if "+" in node.op else "-", self.read(node.expr, state), 1, state)
            self.write(node.expr, value, state)
            return [state]
        if isinstance(node, c_ast.If):
            condition = z3.simplify(truth(self.expr(node.cond, state)))
            if z3.is_true(condition): return self.statement(node.iftrue, state)
            if z3.is_false(condition): return self.statement(node.iffalse, state)
            yes, no = state.fork(), state.fork()
            yes.guard = z3.And(state.guard, condition)
            no.guard = z3.And(state.guard, z3.Not(condition))
            return self.statement(node.iftrue, yes) + self.statement(node.iffalse, no)
        if isinstance(node, c_ast.For):
            names_before = set(state.values)
            active = self.statement(node.init, state)
            finished = []
            for iteration in range(self.max_unroll + 1):
                continuing = []
                for current in active:
                    if current.returned or (node.cond is not None and not fixed_truth(self.expr(node.cond, current))):
                        finished.append(current)
                    else:
                        continuing.append(current)
                if not continuing:
                    for current in finished:
                        for name in set(current.values) - names_before:
                            del current.values[name]
                            del current.types[name]
                    return finished
                if iteration == self.max_unroll:
                    raise Unsupported(f"Loop exceeds complete-unrolling limit {self.max_unroll}")
                active = []
                for current in continuing:
                    for after_body in self.statement(node.stmt, current):
                        if after_body.returned:
                            active.append(after_body)
                        else:
                            active.extend(self.statement(node.next, after_body))
                if len(active) + len(finished) > self.max_paths:
                    raise Unsupported("Path limit exceeded inside a loop")
        if isinstance(node, c_ast.Return):
            if self.return_type == "void":
                if node.expr is not None:
                    raise Unsupported("Returning a value from a void function")
            else:
                if node.expr is None:
                    raise Unsupported("Missing return value")
                state.result = bv(self.expr(node.expr, state))
            state.returned = True
            return [state]
        raise Unsupported(f"Unsupported statement: {type(node).__name__}")

    def run(self):
        self.finals = self.statement(self.fn.body, self.initialize())
        for state in self.finals:
            if not state.returned and self.return_type != "void":
                raise Unsupported("Non-void function can reach its end without return")
        return self


def model_inputs(interpreter, model):
    result = {}
    for name, value in interpreter.initial.values.items():
        def evaluate(v): return model.eval(bv(v), model_completion=True).as_long()
        result[name] = [evaluate(v) for v in value] if isinstance(value, list) else evaluate(value)
    return result


def model_outputs(interpreter, model):
    for state in interpreter.finals:
        if z3.is_true(model.eval(state.guard, model_completion=True)):
            result = {name: [model.eval(v, model_completion=True).as_long() for v in state.values[name]]
                      for name in interpreter.array_names}
            if state.result is not None:
                result["return"] = model.eval(state.result, model_completion=True).as_long()
            return result
    raise Unsupported("No terminating execution for the solver model")


def check_equivalence(original, candidate, function=None, *, timeout_ms=10000,
                      max_unroll=256, max_paths=256, smt_path=None):
    """Check source strings; return a JSON-compatible verdict with assumptions.

    Equivalence is returned only after both programs are UB-free on the entire
    input domain and their final return/parameter-array values agree. Bounds are
    resource limits, never silently truncated proof domains.
    """
    started = time.perf_counter()
    result = {"status": "unsupported", "assumptions": [
        "32-bit int and unsigned int; uint32_t is unsigned int",
        "All array parameters are valid, separately allocated, and nonoverlapping",
        "Functional equality at function completion; no cycle-level RTL guarantee",
    ]}
    try:
        left_fn, right_fn = parse(original, function), parse(candidate, function)
        left = Interpreter(left_fn, max_unroll=max_unroll, max_paths=max_paths).run()
        # Validate signatures independently before sharing symbolic inputs.
        right = Interpreter(right_fn, max_unroll=max_unroll, max_paths=max_paths).run()
        if left.signature != right.signature or left.return_type != right.return_type:
            raise Unsupported("Function signatures differ (parameters are matched by position)")
        solver = z3.Solver()
        solver.set(timeout=timeout_ms)
        for interpreter, label in ((left, "source_undefined"), (right, "candidate_undefined")):
            if not interpreter.issues:
                continue
            bad = z3.Or(*(formula for formula, _ in interpreter.issues))
            solver.push()
            solver.add(bad)
            verdict = solver.check()
            if verdict == z3.sat:
                model = solver.model()
                reason = [reason for formula, reason in interpreter.issues if z3.is_true(model.eval(formula, model_completion=True))]
                result.update(status=label, reason="; ".join(dict.fromkeys(reason)),
                              counterexample=model_inputs(interpreter, model))
                return result
            if verdict == z3.unknown:
                result.update(status="unknown", reason=solver.reason_unknown())
                return result
            solver.pop()
        differences = []
        lemma_records=[]
        lemma_budget_started=time.perf_counter()
        def reduce_independent_terms(expression):
            """Remove only additive components independently proved zero.

            Components share no symbolic variables. This is an optional proof
            acceleration: an unknown/sat lemma remains in the final query.
            Universal zero lemmas are sound even when path guards constrain
            inputs, because no path assumptions are used in their proofs.
            """
            if not z3.is_app_of(expression,z3.Z3_OP_BADD):
                return expression
            terms=list(expression.children())
            groups=[]
            for term in terms:
                support={v.get_id() for v in get_vars(term)}
                linked=[g for g in groups if support & g['support'] or not support and not g['support']]
                merged={'support':set(support),'terms':[term]}
                for group in linked:
                    merged['support'].update(group['support']);merged['terms'].extend(group['terms']);groups.remove(group)
                groups.append(merged)
            if len(groups)<2 or len(groups)>64:
                return expression
            remaining=[]
            for group in groups:
                part=z3.simplify(sum(group['terms'],z3.BitVecVal(0,32)),som=True)
                if z3.is_bv_value(part):
                    remaining.append(part)
                    continue
                budget=5000-int(1000*(time.perf_counter()-lemma_budget_started))
                if budget<=0:
                    remaining.append(part)
                    continue
                lemma=z3.Solver();lemma.set(timeout=min(1000,budget));lemma.add(part!=0)
                verdict=lemma.check()
                record={'index':len(lemma_records)+1,'status':str(verdict),'variables':sorted(str(v) for v in get_vars(part))}
                if smt_path:
                    lemma_path=Path(smt_path).with_name(Path(smt_path).stem+f'.lemma{record["index"]:03d}.smt2')
                    lemma_path.parent.mkdir(parents=True,exist_ok=True)
                    lemma_path.write_text(lemma.to_smt2(),encoding='utf-8')
                    record['smt_file']=str(lemma_path)
                lemma_records.append(record)
                if verdict!=z3.unsat:
                    remaining.append(part)
            return z3.simplify(sum(remaining,z3.BitVecVal(0,32)),som=True)
        # Use Z3's semantics-preserving modular polynomial normalizer before
        # bit blasting. This exposes reassociation/factoring identities while
        # leaving comparisons, selects and bitwise structure to the solver.
        def output_diff(x, y):
            return reduce_independent_terms(z3.simplify(x - y, som=True)) != z3.BitVecVal(0, 32)
        for a in left.finals:
            for b in right.finals:
                unequal = []
                if left.return_type != "void":
                    unequal.append(output_diff(a.result, b.result))
                for aname, bname in zip(left.array_names, right.array_names):
                    unequal.extend(output_diff(x, y) for x, y in zip(a.values[aname], b.values[bname]))
                differences.append(z3.And(a.guard, b.guard, z3.Or(*unequal)))
        solver.add(z3.Or(*differences))
        if smt_path:
            Path(smt_path).parent.mkdir(parents=True, exist_ok=True)
            dependencies=''.join('; Proven-zero component dependency: '+r.get('smt_file','')+'\n' for r in lemma_records if r['status']=='unsat')
            Path(smt_path).write_text(dependencies+solver.to_smt2(), encoding="utf-8")
        verdict = solver.check()
        result.update(execution_steps=left.steps + right.steps,
                      paths={"original": len(left.finals), "candidate": len(right.finals)},
                      z3_version=z3.get_version_string())
        result['normalization'] = 'Z3 modular sum-of-monomials simplification of output differences'
        result['component_lemmas']=lemma_records
        result['main_query_requires_component_lemmas']=any(r['status']=='unsat' for r in lemma_records)
        if verdict == z3.unsat:
            result["status"] = "equivalent"
        elif verdict == z3.sat:
            model = solver.model()
            result.update(status="not_equivalent", counterexample=model_inputs(left, model),
                          original_outputs=model_outputs(left, model), candidate_outputs=model_outputs(right, model))
        else:
            result.update(status="unknown", reason=solver.reason_unknown())
    except Unsupported as error:
        result.update(status="unsupported", reason=str(error))
    except (c_parser.ParseError, ValueError, TypeError, z3.Z3Exception) as error:
        result.update(status="error", reason=str(error))
    finally:
        result["elapsed_seconds"] = round(time.perf_counter() - started, 6)
    return result
