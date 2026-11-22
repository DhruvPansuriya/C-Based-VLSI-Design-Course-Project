"""Proof-job generation. No verdict is inferred here and no LLM is called."""
from __future__ import annotations
from dataclasses import asdict
from hashlib import sha256
import json
from pathlib import Path
from typing import Any,Mapping,Sequence
from ..config import Config
from ..views import BuildView,Views
from ..contract.emit import emit_function,EmittedFunction
from ..contract.ast import Expr, Sort
from ..contract.parser import parse
from ..contract.typecheck import typecheck
from .adapter import Global, Layout
from .constructive import assignments
from .profile import Profile,plain
from .layout import HarnessUnsupported
from .model import HarnessBundle


def _literal(n: int) -> str:
    if n==-(1<<63): return '(-9223372036854775807LL-1LL)'
    if n<0: return f'({n}LL)'
    return f'{n}ULL' if n>(1<<63)-1 else f'{n}LL'


class Generator:
    """One exact profile; never transfers a proof between shapes.

    `reference_guard` is a proposed input-only sufficient safe/deterministic
    domain for P0. It becomes evidence only after a separate reference job.
    """
    def __init__(self,p0: Views,p1: Views,shape: Mapping[str,Any],*,config: Config|None=None,
                 reference_guard: str='true') -> None:
        self.p0,self.p1=p0,p1;self.config=config or Config()
        if p0.sim.analysis.signature!=p1.sim.analysis.signature:
            raise HarnessUnsupported('public signatures differ')
        for view in (p0.sim,p0.synth,p1.sim,p1.synth):
            if view.analysis.forbidden or view.analysis.unsupported:
                raise HarnessUnsupported('views must pass structural admission before harness generation')
        self.layout=Layout.make(p0.sim.analysis)
        self.profile=Profile.make(p0.sim.analysis,shape,self.config.bounds.K)
        self.reference_guard=reference_guard
        self._input_only(reference_guard)

    def _input_only(self,expr: str) -> None:
        typed=typecheck(expr,self.profile.env,expected=Sort.BOOL)
        if any(self.profile.env.symbols[n].role!='input' for n in typed.used_symbols):
            raise HarnessUnsupported('zone/guard/reach must depend only on input state')

    def _interpretations(self,interps: Sequence[Mapping[str,Any]]) -> None:
        for it in interps:
            if plain(it['shape'])!=plain(self.profile.shape):
                raise HarnessUnsupported('interpretation shape differs; emit a separate exact-profile job')
            for clause in it['clauses']: self._input_only(clause['zone'])
            if it.get('reach') not in (None,'unknown'): self._input_only(it['reach'])

    def _zone(self,interps: Sequence[Mapping[str,Any]],reach: bool=False) -> str:
        expressions=[c['zone'] for it in interps for c in it['clauses']]
        if reach: expressions += [it['reach'] for it in interps if it.get('reach') not in (None,'unknown')]
        return ' || '.join('('+x+')' for x in expressions) or 'false'

    def gen_core(self,out: str|Path,interps: Sequence[Mapping[str,Any]],*,part: str='e1') -> HarnessBundle:
        self._interpretations(interps)
        if part not in {'e0','e1'}: raise ValueError('core part must be e0 or e1')
        return self._generate(out,part,interps)

    def gen_class(self,out: str|Path,interp: Mapping[str,Any]) -> HarnessBundle:
        self._interpretations((interp,));return self._generate(out,'class',(interp,))

    def gen_vacuity(self,out: str|Path,interps: Sequence[Mapping[str,Any]],*,after_call: bool=True) -> HarnessBundle:
        self._interpretations(interps)
        return self._generate(out,'vacuity',interps,after_call=after_call)

    def gen_views_equiv(self,out: str|Path) -> HarnessBundle:
        return self._generate(out,'views',())

    def gen_determinism(self,out: str|Path,prog: str='p0',*,guard: str|None=None) -> HarnessBundle:
        if prog not in {'p0','p1'}: raise ValueError('prog must be p0 or p1')
        selected=guard if guard is not None else self.reference_guard if prog=='p0' else 'true'
        self._input_only(selected)
        return self._generate(out,'determinism',(),prog=prog,guard=selected)

    def gen_contract_ub(self,out: str|Path,interp: Mapping[str,Any]) -> HarnessBundle:
        self._interpretations((interp,));return self._generate(out,'contract_ub',(interp,))

    def gen_reference(self,out: str|Path,interps: Sequence[Mapping[str,Any]]=(),*,domain: str='guard') -> HarnessBundle:
        """Sufficient old-definedness certificate; a failure is not invalid intent."""
        self._interpretations(interps)
        if domain not in {'guard','keep','e1_keep','all'}: raise ValueError('reference domain')
        guard=self.reference_guard if domain=='guard' else '!('+self._zone(interps,domain=='e1_keep')+')' if domain in {'keep','e1_keep'} else 'true'
        return self.gen_determinism(out,'p0',guard=guard)

    def gen_reference_safety(self, out: str | Path, guard: str = "true") -> HarnessBundle:
        self._input_only(guard)
        return self._generate(out, "reference_safety", (), guard=guard)

    def gen_input_rule(self, out: str | Path, guard: str, predicate: str,
                       *, reachability: bool = False) -> HarnessBundle:
        self._input_only(guard)
        self._input_only(predicate)
        return self._generate(out, "feasibility" if reachability else "input_rule",
                              (), guard=guard, predicate=predicate)

    def gen_validation(self, out: str | Path, interps: Sequence[Mapping[str,Any]], mode: str) -> HarnessBundle:
        self._interpretations(interps)
        expected = {"bug": 1, "possible": 1, "constructive": 1, "equivalence": 2}
        if mode not in expected or len(interps) != expected[mode]:
            raise ValueError("invalid interpretation validation job")
        return self._generate(out, "validation_" + mode, interps)

    def _generate(self,out: str|Path,kind: str,interps: Sequence[Mapping[str,Any]],*,
                  after_call: bool=True,prog: str='p0',guard: str='true',
                  predicate: str='true') -> HarnessBundle:
        return _Builder(self,out,kind,interps).build(after_call,prog,guard,predicate)


class _Builder:
    def __init__(self,g: Generator,out: str|Path,kind: str,interps: Sequence[Mapping[str,Any]]) -> None:
        self.g,self.kind,self.interps=g,kind,interps
        self.layout,self.profile=g.layout,g.profile
        self.out=Path(out).resolve();self.out.mkdir(parents=True,exist_ok=True)
        self.lines=[];self.functions=[];self.watch=[];self.labels=[];self.requirements=[]
        self.bindings={};self.observers=[];self.selected=[]
        self.unwind=max(g.config.bounds.max_unwind,self.profile.K+1)
        self.buffers=[p for p in self.layout.parameters if p.buffer]
        self.sizes={name:(expr,hi) for name,expr,hi in self.profile.lengths}

    def line(self,text: str) -> None: self.lines.append('  '+text)

    def nondet(self,ctype: str,name: str,limits=None,*,watch: bool=False) -> None:
        fn='nondet___vwe_'+str(len(self.functions));self.functions.append(f'{ctype} {fn}(void);')
        self.line(f'{ctype} {name}={fn}();')
        if limits:
            lo,hi=limits
            self.line(f'__CPROVER_assume({_literal(lo)} <= {name} && {name} <= {_literal(hi)});')
        if watch:self.watch.append(name)

    def emit(self,expr: str | Expr,*,boolean: bool=True) -> EmittedFunction:
        f=emit_function(expr,self.profile.env,name='vwe_observer_'+str(len(self.observers)),boolean=boolean)
        self.observers.append(f)
        self.unwind=max(self.unwind,max((n+1 for _,n in f.loop_limits),default=1))
        return f

    def call(self,f: EmittedFunction,bindings=None) -> str:
        b=bindings if bindings is not None else self.bindings
        missing=set(f.parameters)-set(b)
        if missing: raise HarnessUnsupported('no observation binding for '+','.join(sorted(missing)))
        return f.name+'('+', '.join(b[n] for n in f.parameters)+')'

    def expression(self,expr: str | Expr,*,boolean: bool=True) -> str:
        return self.call(self.emit(expr,boolean=boolean))

    def assertion(self,expr: str,label: str) -> None:
        self.labels.append(label);self.line('__CPROVER_assert('+expr+', '+json.dumps(label)+');')

    def seed(self,roles: Sequence[str]) -> None:
        self.line('struct __vwe_input __vwe_in={0};')
        for p in self.layout.parameters:
            if p.buffer: continue
            for j,f in enumerate(p.fields):
                n=f'__vwe_in_scalar_{p.index}_{j}'
                bounds=self.profile.env.symbols[p.name].values if not f.path and p.name in self.profile.env.symbols else f.scalar.limits
                self.nondet(f.c_type,n,(bounds.low,bounds.high),watch=True)
                self.line(f'__vwe_in.s{p.index}_{j}={n};')
                if not f.path:self.bindings[p.name]=n
        for glob in self.layout.globals:
            for j,f in enumerate(glob.fields):
                n=f'__vwe_in_global_{glob.name}_{j}'
                self.nondet(f.c_type,n,watch=True);self.line(f'__vwe_in.g{glob.index}_{j}={n};')
                if not f.path:self.bindings['in_global_'+glob.name]=n
            self.bind_flat_global(glob,'in_global_',f'__vwe_in.g{glob.index}_')
        for p in self.buffers:
            expr,hi=self.sizes[p.name]
            self.line(f'long long __vwe_len_{p.index}={self.expression(expr,boolean=False)};')
            self.assertion(f'0 <= __vwe_len_{p.index} && __vwe_len_{p.index} <= {hi}',f'VWE.profile.length.{p.name}')
            self.nondet('_Bool',f'__vwe_in_null_{p.index}',watch=True)
            for role in ('input',*roles):
                tag='a1' if role=='one' else 'a0'
                # A symbolic object has exactly the declared logical size. The
                # explicit NULL branch preserves callers with zero-sized regions.
                self.line(f'void *__vwe_{role}_b{p.index}=(__vwe_len_{p.index}==0 && __vwe_in_null_{p.index}) ? (void *)0 : malloc((__vwe_size)__vwe_len_{p.index} * __vwe_{tag}_size_{p.index}());')
            for i in range(hi):
                self.line(f'if (__vwe_len_{p.index}>{i}) {{')
                self.line(f'struct __vwe_element_{p.index} __vwe_e_{p.index}_{i};')
                for j,f in enumerate(p.fields):
                    n=f'__vwe_in_buffer_{p.index}_{i}_{j}'
                    limits=self.profile.shape.get('value_bounds',{}).get(p.name)
                    if limits is not None:
                        bounded_limits=f.scalar.limits
                        if limits[0]<bounded_limits.low or limits[1]>bounded_limits.high: raise HarnessUnsupported('buffer value bounds exceed field type')
                    self.nondet(f.c_type,n,limits,watch=True)
                    self.line(f'__vwe_e_{p.index}_{i}.f{j}={n};')
                for role in ('input',*roles):
                    tag='a1' if role=='one' else 'a0'
                    self.line(f'__vwe_{tag}_set_{p.index}(__vwe_{role}_b{p.index},{i},__vwe_e_{p.index}_{i});')
                self.line('}')
            if len(p.fields)==1 and not p.fields[0].path:
                ctype=p.fields[0].c_type
                self.bindings[p.name]=f'((const {ctype} *)__vwe_input_b{p.index})'
                for role,key in (('one','out_'),('zero','old_')):
                    if role in roles:self.bindings[key+p.name]=f'((const {ctype} *)__vwe_{role}_b{p.index})'
        for role,prefix in (('one','out_'),('zero','old_')):
            self.line(f'struct __vwe_output __vwe_{role}={{0}};')
            if len(self.layout.returns)==1 and not self.layout.returns[0].path and not self.layout.returns[0].pointer:
                self.bindings[prefix+'ret']=f'__vwe_{role}.r0'
            for glob in self.layout.globals:
                if len(glob.fields)==1 and not glob.fields[0].path:
                    self.bindings[prefix+'global_'+glob.name]=f'__vwe_{role}.g{glob.index}_0'
                self.bind_flat_global(glob,prefix+'global_',f'__vwe_{role}.g{glob.index}_')
        # Old observer placeholders are initialized. A separate old-definedness
        # certificate must authorize every evaluation that can read them.

    def bind_flat_global(self,glob: Global,prefix: str,root: str) -> None:
        name=prefix+glob.name
        symbol=self.profile.env.symbols.get(name)
        if symbol is None or symbol.length is None:
            return
        tag='__vwe_snapshot_'+name
        count=len(glob.fields)
        self.line(f'{symbol.scalar.c_name} {tag}[{count}];')
        self.bindings[name]=tag
        for i in range(count):
            self.line(f'{tag}[{i}]=0;')
        if prefix=='in_global_':
            for i in range(count):
                self.line(f'{tag}[{i}]={root}{i};')

    def snapshot_globals(self,role: str) -> None:
        prefix='out_global_' if role=='one' else 'old_global_'
        for glob in self.layout.globals:
            name=prefix+glob.name
            symbol=self.profile.env.symbols.get(name)
            if symbol is not None and symbol.length is not None:
                buf=self.bindings[name]
                for i,_ in enumerate(glob.fields):
                    self.line(f'{buf}[{i}]=__vwe_{role}.g{glob.index}_{i};')

    def program_call(self,tag: str,role: str) -> None:
        args=['&__vwe_in',f'&__vwe_{role}']+[f'__vwe_{role}_b{p.index}' for p in self.buffers]
        self.line('__vwe_'+tag+'_call('+', '.join(args)+');')
        self.snapshot_globals(role)

    def equivalent(self) -> str:
        terms=[]
        for j,f in enumerate(self.layout.returns):
            a,b=f'__vwe_zero.r{j}',f'__vwe_one.r{j}'
            if f.pointer:
                # Only the identity/byte offset of registered input regions is
                # supported. Unknown pointers block the job via a separate check.
                for role,val in (('zero',a),('one',b)):
                    support=' || '.join([f'{val}==0']+[f'__CPROVER_same_object({val},__vwe_{role}_b{p.index})' for p in self.buffers])
                    self.assertion(support,f'VWE.observation.pointer.{role}.{j}')
                equal=[f'({a}==0 && {b}==0)']
                for p in self.buffers:
                    equal.append(f'({a}!=0 && {b}!=0 && __CPROVER_same_object({a},__vwe_zero_b{p.index}) && __CPROVER_same_object({b},__vwe_one_b{p.index}) && __CPROVER_POINTER_OFFSET({a})==__CPROVER_POINTER_OFFSET({b}))')
                terms.append('('+' || '.join(equal)+')')
            else:terms.append(a+'=='+b)
        for glob in self.layout.globals:
            terms += [f'__vwe_zero.g{glob.index}_{j}==__vwe_one.g{glob.index}_{j}' for j,_ in enumerate(glob.fields)]
        # Element observations are unrolled metadata, not oversized C buffers.
        for p in self.buffers:
            _,hi=self.sizes[p.name]
            for i in range(hi):
                for j,_ in enumerate(p.fields):
                    terms.append(f'(__vwe_len_{p.index}<={i} || __vwe_a0_get_{p.index}(__vwe_zero_b{p.index},{i}).f{j}==__vwe_a1_get_{p.index}(__vwe_one_b{p.index},{i}).f{j})')
        return '('+' && '.join('('+t+')' for t in terms)+')' if terms else '1'

    def fresh_outputs(self) -> None:
        for role in ('one','zero'):
            tag='a1' if role=='one' else 'a0'
            for j,f in enumerate(self.layout.returns):
                if f.pointer: raise HarnessUnsupported('pointer-valued contract outputs need a richer DSL')
                n=f'__vwe_{role}_result_{j}';self.nondet(f.c_type,n);self.line(f'__vwe_{role}.r{j}={n};')
            for glob in self.layout.globals:
                for j,f in enumerate(glob.fields):
                    n=f'__vwe_{role}_global_{glob.index}_{j}';self.nondet(f.c_type,n);self.line(f'__vwe_{role}.g{glob.index}_{j}={n};')
            for p in self.buffers:
                for i in range(self.sizes[p.name][1]):
                    self.line(f'if (__vwe_len_{p.index}>{i}) {{')
                    self.line(f'struct __vwe_element_{p.index} __vwe_fresh_{role}_{p.index}_{i};')
                    for j,f in enumerate(p.fields):
                        n=f'__vwe_{role}_fresh_{p.index}_{i}_{j}';self.nondet(f.c_type,n)
                        self.line(f'__vwe_fresh_{role}_{p.index}_{i}.f{j}={n};')
                    tag='a1' if role=='one' else 'a0'
                    self.line(f'__vwe_{tag}_set_{p.index}(__vwe_{role}_b{p.index},{i},__vwe_fresh_{role}_{p.index}_{i});')
                    self.line('}')
            self.snapshot_globals(role)
        # Conservatively all type-correct old values: UB-free here is sufficient
        # but not necessary on the reachable old-output relation.

    def clause_relation(self, interp: Mapping[str, Any]) -> str:
        terms = [f"(!({self.expression(c['zone'])}) || ({self.expression(c['behaviour'])}))"
                 for c in interp["clauses"]]
        return "(" + (" && ".join(terms) or "1") + ")"

    def validation(self, mode: str) -> None:
        interp = self.interps[0]
        zone = self.g._zone((interp,))
        clauses = interp["clauses"]
        if mode == "validation_bug":
            self.line("__CPROVER_assume(" + self.expression(zone) + ");")
            self.program_call("a0", "zero")
            # Compare each applicable repair predicate against P0's actual
            # output. Both roles refer to the same observed state.
            for name, symbol in self.profile.env.symbols.items():
                if symbol.role == "output" and name in self.bindings:
                    self.bindings[name] = self.bindings["old_" + name[4:]]
            self.assertion(self.clause_relation(interp), "VWE.validation_bug.predicate")
            return
        self.fresh_outputs()
        if mode == "validation_equivalence":
            other = self.interps[1]
            other_zone = self.g._zone((other,))
            region_equal = f"({self.expression(zone)}) == ({self.expression(other_zone)})"
            relation_equal = f"{self.clause_relation(interp)} == {self.clause_relation(other)}"
            self.assertion(f"({region_equal}) && ({relation_equal})",
                           "VWE.validation_equivalence.predicate")
            return
        if mode == "validation_possible":
            self.line("__CPROVER_assume(" + self.expression(zone) + ");")
            self.assertion("!(" + self.clause_relation(interp) + ")",
                           "VWE.validation_possible.predicate")
            return
        for clause in clauses:
            plan = assignments(parse(clause["behaviour"]), self.profile.env)
            if plan is None or any(
                self.emit(write.value, boolean=False).uses_old for write in plan
            ):
                raise HarnessUnsupported("no constructive input-only output tuple")
            self.line("if (" + self.expression(clause["zone"]) + ") {")
            for write in plan:
                symbol = self.profile.env.symbols[write.name]
                target = self.bindings[write.name]
                if write.index is not None:
                    target = f"(({symbol.scalar.c_name} *)({target}))[{write.index}]"
                value = self.expression(write.value, boolean=False)
                self.line(f"{target}=({symbol.scalar.c_name})({value});")
            self.line("}")
        self.assertion(self.clause_relation(interp), "VWE.validation_constructive.predicate")

    def build(self,after_call: bool,prog: str,guard: str,predicate: str) -> HarnessBundle:
        g=self.g;kind=self.kind
        self.seed(('zero','one'))
        base=['qualified-admission','qualified-path-cut-and-uninitialized-model','nonvacuous-profile']
        if kind=='e0':
            self.line('__CPROVER_assume('+self.expression(g.reference_guard)+');')
            self.program_call('a1','one');self.requirements+=['reference-guard-safe-and-deterministic']
        elif kind=='e1':
            keep='!('+g._zone(self.interps,True)+')'
            self.line('__CPROVER_assume('+self.expression(keep)+');')
            self.program_call('a1','one');self.program_call('a0','zero')
            ext=[]
            for it in self.interps:
                if it.get('ext') not in (None,'unknown'): ext.append(self.expression(it['ext']))
            self.assertion(self.equivalent()+''.join(' || '+e for e in ext),'VWE.E1.preservation')
            self.requirements+=['reference-safe-and-deterministic-on-E1-keep','all-interpretations-validated','scope-conflict-veto']
        elif kind=='class':
            it=self.interps[0];zone=g._zone(self.interps)
            self.program_call('a1','one')
            old_use=any(self.emit(c['behaviour']).uses_old for c in it['clauses'])
            if old_use:
                self.program_call('a0','zero');self.requirements+=['reference-safe-and-deterministic-on-entire-profile']
            self.line('if (!('+self.expression(zone)+')) {')
            if not old_use:self.program_call('a0','zero')
            self.assertion(self.equivalent(),'VWE.class.preservation');self.line('}')
            for i,c in enumerate(it['clauses']):
                self.line('if ('+self.expression(c['zone'])+') {')
                self.assertion(self.expression(c['behaviour']),f'VWE.class.clause.{i}');self.line('}')
            self.requirements+=['reference-safe-and-deterministic-on-class-keep','interpretation-validated']
        elif kind=='vacuity':
            if after_call:self.program_call('a1','one')
            self.line('if (!('+self.expression(g._zone(self.interps,True))+')) {')
            self.assertion('0','VWE.vacuity.keep');self.line('}')
            for i,it in enumerate(self.interps):
                for j,c in enumerate(it['clauses']):
                    self.line('if ('+self.expression(c['zone'])+') {')
                    self.assertion('0',f'VWE.vacuity.zone.{i}.{j}');self.line('}')
        elif kind in {'views','determinism'}:
            if kind=='determinism':self.line('__CPROVER_assume('+self.expression(guard)+');')
            self.program_call('a0','zero');self.program_call('a1','one')
            self.assertion(self.equivalent(),'VWE.'+kind+'.equivalence')
        elif kind.startswith('validation_'):
            self.validation(kind)
        elif kind=='reference_safety':
            self.line('__CPROVER_assume('+self.expression(guard)+');')
            self.program_call('a0','zero')
            self.assertion('1','VWE.reference_safety.completed')
        elif kind in {'input_rule','feasibility'}:
            self.line('__CPROVER_assume('+self.expression(guard)+');')
            value=self.expression(predicate)
            self.assertion('!('+value+')' if kind=='feasibility' else value,
                           'VWE.'+kind+'.predicate')
        elif kind=='contract_ub':
            self.fresh_outputs()
            for it in self.interps:
                for c in it['clauses']:
                    self.line('if ('+self.expression(c['zone'])+') {')
                    self.line('(void)'+self.expression(c['behaviour'])+';');self.line('}')
                for key in ('reach','ext'):
                    if it.get(key) not in (None,'unknown'):self.line('(void)'+self.expression(it[key])+';')
            self.assertion('1','VWE.contract.evaluated')
        else:raise ValueError(kind)
        if self.observers and kind!='contract_ub':self.requirements+=['observer-UB-freedom','old-observer-definedness']
        self.line('return 0;')
        views=(g.p1.sim,g.p1.synth) if kind=='views' else ((g.p0.sim,g.p0.sim) if prog=='p0' else (g.p1.sim,g.p1.sim)) if kind=='determinism' else (g.p0.sim,g.p1.sim)
        (self.out/'frame.h').write_text(self.layout.header())
        files=[]
        program_symbols=[]
        for tag,view in zip(('a0','a1'),views):
            # Deterministic self-composition uses the same unit twice. Existing
            # program symbols must be isolated a second time at the AST level.
            if views[0].entry_point==views[1].entry_point and tag=='a1':
                from ..c_frontend import renamed
                from dataclasses import replace
                code,symbols=renamed(view.analysis,'vwe_second')
                path=self.out/'second_renamed.txt';path.write_text(code)
                view=replace(view,renamed=path,renamed_sha256=sha256(code.encode()).hexdigest(),entry_point='vwe_second_'+view.analysis.function,symbols=symbols)
            names = dict(view.symbols)
            program_symbols.append(tuple(names[n] for n in view.analysis.definitions))
            path=self.out/(tag+'.c');path.write_text(self.layout.adapter(view,tag));files.append(path)
        header='#include <stdlib.h>\n#include "frame.h"\n'+self.layout.prototypes('a0')+self.layout.prototypes('a1')+'\n'
        # CPROVER built-ins are supplied by goto-cc/CBMC. ESBMC and native replay
        # require the qualified per-tool layer in T05/T09, never blind reuse.
        header+='\n'.join(self.functions)+'\n'+''.join(f.source for f in self.observers)
        main=self.out/'main.c';main.write_text(header+'\nint main(void) {\n'+'\n'.join(self.lines)+'\n}\n');files.append(main)
        decisive=kind=='e1' and bool(self.interps) and all(it.get('ext') not in (None,'unknown') and it.get('reach') not in (None,'unknown') for it in self.interps)
        identity={'profile':self.profile.sha256,'p0':g.p0.source_sha256,'p1':g.p1.source_sha256,
                  'views':[v.renamed_sha256 for v in views],'kind':kind,'guard':guard,'predicate':predicate,'unwind':self.unwind,
                  'reference_guard':g.reference_guard,'after_call':after_call,'interpretations':plain(self.interps)}
        bundle=HarnessBundle(kind,self.out,tuple(files),'main',self.unwind,tuple(self.watch),tuple(self.labels),
                             tuple(dict.fromkeys(base+self.requirements)),self.profile.sha256,g.reference_guard,decisive,tuple(program_symbols))
        manifest=asdict(bundle);manifest.update(folder=str(self.out),files=[str(p) for p in files],
            job_sha256=sha256(json.dumps(identity,sort_keys=True,separators=(',',':')).encode()).hexdigest(),
            generated_file_sha256={p.name:sha256(p.read_bytes()).hexdigest() for p in [self.out/'frame.h',*files]},
            emitted_not_proved=True,input_storage='initialized',old_placeholders='initialized; guard certificates required')
        (self.out/'bundle.json').write_text(json.dumps(manifest,indent=2)+'\n')
        return bundle
