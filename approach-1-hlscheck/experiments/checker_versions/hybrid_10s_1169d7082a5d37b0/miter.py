"""One typed C product program, optionally using certified relational summaries."""
from dataclasses import asdict
from pycparser import c_generator
from copy import deepcopy

from .frontend import ABI_ASSERTIONS


def literal(value, spec):
    if not spec['signed']:
        return f'(({spec["c_type"]}){value}ULL)'
    text = f'(-{abs(value)-1}LL-1LL)' if value < 0 else f'{value}LL'
    return f'(({spec["c_type"]}){text})'


def function_source(unit, name, region=None):
    node = deepcopy(region['residual_function'] if region else unit.function)
    node.decl.name = node.decl.type.type.declname = name
    return c_generator.CGenerator().visit(node)


def make_miter(left, right, contract, *, regions=None, abstraction='none', summary_source=None, input_values=None):
    """Return a shared-input miter with nonaliasing independent program states.

    none: actual original programs; shared_havoc: an overapproximation justified
    by a region-equality lemma; exact: common functional summary also certified
    against the source region. No abstract SAT result is conclusive by itself.
    """
    assert abstraction in ('none', 'shared_havoc', 'exact')
    if abstraction != 'none': assert regions
    if abstraction == 'none': assert regions is None
    if input_values is not None: assert abstraction == 'none'
    lines = [ABI_ASSERTIONS, 'extern void __ESBMC_assert(_Bool, const char *);',
             'extern void __ESBMC_assume(_Bool);']
    for p in left.parameters:
        lines += [f'extern {p["c_type"]} __hlscheck_nondet_{p["position"]}(void);']
    lines += [function_source(left, '__hlscheck_original', regions[0] if regions else None),
              function_source(right, '__hlscheck_candidate', regions[1] if regions else None)]
    if abstraction == 'exact':
        assert summary_source
        # Use the certified generated function with its original parameters.
        from .checker import parse
        summary = parse(summary_source, None)
        summary.decl.name = summary.decl.type.type.declname = '__hlscheck_summary'
        lines += [c_generator.CGenerator().visit(summary)]
    lines += ['int main(void) {']
    a_args=[]; b_args=[]; shared_args=[]; comparisons=[]
    for p in left.parameters:
        i, kind, n = p['position'], p['c_type'], p['length']
        shared = f'__hlscheck_input_{i}'; shared_args.append(shared)
        if n is None:
            value = literal(input_values[p['name']], p) if input_values is not None else f'__hlscheck_nondet_{i}()'
            lines += [f'{kind} {shared}={value};']
            if p['name'] in contract['scalar_ranges']:
                low, high = contract['scalar_ranges'][p['name']]
                lines += [f'__ESBMC_assume({shared}>={literal(low,p)} && {shared}<={literal(high,p)});']
            a_args.append(shared); b_args.append(shared)
        else:
            values=','.join(literal(input_values[p['name']][j], p) if input_values is not None else f'__hlscheck_nondet_{i}()' for j in range(n))
            lines += [f'{kind} {shared}[{n}]={{{values}}};',
                      f'{kind} __hlscheck_left_{i}[{n}], __hlscheck_right_{i}[{n}];']
            for j in range(n):
                value = f'__hlscheck_nondet_{i}()' if abstraction == 'shared_havoc' else f'{shared}[{j}]'
                lines += [f'__hlscheck_left_{i}[{j}]={value};',
                          f'__hlscheck_right_{i}[{j}]=__hlscheck_left_{i}[{j}];']
                comparisons += [f'__hlscheck_left_{i}[{j}]==__hlscheck_right_{i}[{j}]']
            a_args.append(f'__hlscheck_left_{i}'); b_args.append(f'__hlscheck_right_{i}')
    if regions and regions[0].get('lifted_return'):
        assert regions[1].get('lifted_return')
        lines += ['extern unsigned int __hlscheck_nondet_return(void);',
                  'unsigned int __hlscheck_return_value[1]={__hlscheck_nondet_return()};']
        a_args.append('__hlscheck_return_value'); b_args.append('__hlscheck_return_value')
    if abstraction == 'exact':
        lines += ['__hlscheck_summary('+','.join(a_args)+');']
        for p in left.parameters:
            for j in range(p['length'] or 0):
                i=p['position']
                lines += [f'__hlscheck_right_{i}[{j}]=__hlscheck_left_{i}[{j}];']
    a_call='__hlscheck_original('+','.join(a_args)+')'
    b_call='__hlscheck_candidate('+','.join(b_args)+')'
    if left.return_type.c_type == 'void':
        lines += [a_call+';', b_call+';']
    else:
        kind=left.return_type.c_type
        lines += [f'{kind} __hlscheck_left_return={a_call};', f'{kind} __hlscheck_right_return={b_call};',
                  ]
        comparisons += ['__hlscheck_left_return==__hlscheck_right_return']
    comparison=' && '.join('('+c+')' for c in comparisons) or '1'
    lines += [f'__ESBMC_assert({comparison},"EQUIV:observables");','return 0;', '}']
    return '\n'.join(lines)+'\n'
