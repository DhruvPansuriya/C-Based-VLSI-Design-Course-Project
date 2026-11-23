"""Type-preserving public-suite leaf functions verified with reused ESBMC/Z3.

This separate adapter study does not extend the custom uint32_t interpreter.
It does not claim equivalence of entire CHStone/MachSuite applications.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
from collections import Counter
import hashlib
import json
import re
import shutil
import subprocess

from hlscheck.esbmc_backend import classify_log

ROOT = Path(__file__).resolve().parents[1]
ESBMC = ROOT/'tools/esbmc-v8.7/release/bin/esbmc.exe'
ABI = '_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");\n'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def extract_function(text, name):
    # Selected functions contain no braces in strings or comments. Keep the
    # exact upstream function text, not an AST regeneration of the baseline.
    match = re.search(r'(?m)^[\w ]+\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{', text)
    if not match:
        # CHStone puts the return type on the preceding line.
        match = re.search(r'(?m)^\w+\s*\n' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{', text)
    if not match:
        raise ValueError('Cannot extract ' + name)
    depth = 1; end = match.end()
    while depth:
        if text[end] == '{': depth += 1
        if text[end] == '}': depth -= 1
        end += 1
    return text[match.start():end] + '\n'


def prepare():
    cases = []
    base = ROOT/'datasets/hls-eval/hls_eval_data/chstone'
    hls_leaves = [
        ('extractFloat64Sign', 'df_extractFloat64Sign', 'flag', 'float64 a',
         'return (a & 0x8000000000000000ULL)!=0;', 'return a>>62;', 'isolate sign bit', 'sign shift off by one'),
        ('extractFloat64Frac', 'df_extractFloat64Frac', 'bits64', 'float64 a',
         'return (a<<12)>>12;', 'return (a<<13)>>13;', 'unsigned shift pair extracts low 52 bits', 'one fraction bit lost'),
        ('extractFloat64Exp', 'df_extractFloat64Exp', 'int16', 'float64 a',
         'return (a & 0x7FF0000000000000ULL)>>52;', 'return (a & 0x7FF0000000000000ULL)>>51;', 'mask then shift', 'exponent shift off by one'),
        ('float64_abs', 'df_float64_abs', 'float64', 'float64 x',
         'return (x<<1)>>1;', 'return (x<<2)>>2;', 'clear sign with unsigned shift pair', 'exponent high bit also cleared'),
        ('float64_is_nan', 'df_float64_is_nan', 'flag', 'float64 a',
         'return ((a & 0x7FF0000000000000ULL)==0x7FF0000000000000ULL) && ((a & 0x000FFFFFFFFFFFFFULL)!=0);',
         'return ((a & 0x7FF0000000000000ULL)==0x7FF0000000000000ULL);', 'explicit exponent/fraction predicates', 'infinity incorrectly classified as NaN'),
    ]
    for name, directory, ret, params, good, bad, transform, fault in hls_leaves:
        source = base/directory/(name+'.cpp'); header = source.with_suffix('.h')
        prefix = '\n'.join(re.findall(r'(?m)^typedef[^;]+;', header.read_text())) + '\n'
        cases.append({'id': 'hlseval_'+name, 'suite': 'hls-eval', 'function': name, 'source_path': source,
            'header_path': header, 'prefix': prefix, 'return_type': ret, 'parameters': params,
            'good_body': good, 'bad_body': bad, 'transformation': transform, 'fault': fault,
            'input_kinds': ['unsigned long long'], 'native_trials': 4096})
    source = ROOT/'datasets/CHStone/gsm/add.c'; header = source.with_name('private.h')
    upstream = source.read_text()
    notice = upstream[:upstream.index('/* $Header:')]
    prefix = notice + '\ntypedef short word;\ntypedef long longword;\n#define MIN_WORD ((-32767)-1)\n#define MAX_WORD (32767)\n#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))\n'
    for name, params, good, bad, kinds, n in [
        ('gsm_abs', 'word a', 'if(a==MIN_WORD)return MAX_WORD;return a<0?-a:a;', 'return a<0?-a:a;', ['short'], 65536),
        ('gsm_add', 'word a, word b', 'longword s=(longword)a+(longword)b;if(s>MAX_WORD)return MAX_WORD;if(s<MIN_WORD)return MIN_WORD;return s;',
         'longword s=(longword)a+(longword)b;if(s>=MAX_WORD)return MAX_WORD-1;if(s<MIN_WORD)return MIN_WORD;return s;', ['short', 'short'], 10000),
    ]:
        cases.append({'id': 'chstone_'+name, 'suite': 'CHStone', 'function': name, 'source_path': source,
            'header_path': header, 'prefix': prefix, 'return_type': 'word', 'parameters': params,
            'good_body': good, 'bad_body': bad, 'transformation': 'explicit saturation guards',
            'fault': 'saturation boundary changed', 'input_kinds': kinds, 'native_trials': n})
    source = ROOT/'datasets/MachSuite/aes/aes/aes.c'; header = source.with_suffix('.h')
    cases.append({'id': 'machsuite_rj_xtime', 'suite': 'MachSuite', 'function': 'rj_xtime',
        'source_path': source, 'header_path': header, 'prefix': '#include <stdint.h>\n',
        'return_type': 'uint8_t', 'parameters': 'uint8_t x', 'input_kinds': ['unsigned char'], 'native_trials': 256,
        'good_body': 'return (x<<1)^((x>>7)*0x1b);', 'bad_body': 'return (x<<1)^((x>>7)*0x1d);',
        'transformation': 'branchless AES multiply by x', 'fault': 'one reduction-polynomial bit changed'})
    destination = ROOT/'experiments/dataset_leaves'; destination.mkdir(exist_ok=True)
    shutil.copyfile(ROOT/'datasets/MachSuite/LICENSE', destination/'MachSuite_LICENSE.txt')
    for case in cases:
        directory = destination/case['id']; directory.mkdir(exist_ok=True)
        baseline = extract_function(case['source_path'].read_text(), case['function'])
        (directory/'upstream_function.txt').write_text(baseline)
        for variant, body in [('original', None), ('optimized', case['good_body']), ('buggy', case['bad_body'])]:
            function = baseline if body is None else f"{case['return_type']} {case['function']}({case['parameters']}){{{body}}}\n"
            (directory/(variant+'.c')).write_text(case['prefix']+function)
        case['directory'] = directory.relative_to(ROOT).as_posix()
        case['upstream_source'] = case.pop('source_path').relative_to(ROOT).as_posix()
        case['upstream_header'] = case.pop('header_path').relative_to(ROOT).as_posix()
        case['upstream_source_sha256'] = sha(ROOT/case['upstream_source'])
        case['upstream_header_sha256'] = sha(ROOT/case['upstream_header'])
        case['exact_function_text_sha256'] = sha(directory/'upstream_function.txt')
        case['extraction_changes'] = 'Isolate one leaf; retain original function text, required typedefs/macros and type widths. Drop unrelated includes, prototypes and other functions. C-compatible .cpp bodies parsed as C. No uint32 conversion or dimension reduction.'
        case['provenance'] = 'Original from downloaded public suite. Candidate and seeded bug authored in this Codex session; not the Qwen experiment.'
    (destination/'manifest.json').write_text(json.dumps({'cases': cases}, indent=2)+'\n')
    return cases


def miter(case, variant):
    directory = ROOT/case['directory']; name = case['function']
    original = (directory/'original.c').read_text(); candidate = (directory/(variant+'.c')).read_text()
    original = re.sub(r'\b'+name+r'\b', '__original', original)
    candidate_fn = extract_function(candidate, name)
    candidate_fn = re.sub(r'\b'+name+r'\b', '__candidate', candidate_fn)
    lines = [original, candidate_fn, ABI, 'extern void __ESBMC_assert(_Bool, const char*);']
    for i, kind in enumerate(case['input_kinds']):
        lines += [f'extern {kind} nondet_{i}(void);']
    lines += ['int main(void){']
    args = []
    for i, kind in enumerate(case['input_kinds']):
        args.append('input_'+str(i)); lines += [f'{kind} input_{i}=nondet_{i}();']
    actuals = ','.join(args)
    lines += [f'{case["return_type"]} left=__original({actuals}),right=__candidate({actuals});',
              '__ESBMC_assert(left==right,"EQUIV:return");return 0;}']
    return '\n'.join(lines)+'\n'


def run_native(case, output):
    directory = ROOT/case['directory']; name = case['function']
    original = (directory/'original.c').read_text()
    lines = [re.sub(r'\b'+name+r'\b', '__original', original), '#include <stdio.h>', ABI]
    for variant in ('optimized', 'buggy'):
        fn = extract_function((directory/(variant+'.c')).read_text(), name)
        lines += [re.sub(r'\b'+name+r'\b', '__'+variant, fn)]
    lines += ['static unsigned long long state=0x5291abcddcba1234ULL;',
              'static unsigned long long next(void){state^=state<<13;state^=state>>7;state^=state<<17;return state;}',
              'int main(void){unsigned failures=0,bug_hits=0;',
              'unsigned long long edge[]={0ULL,1ULL,255ULL,32767ULL,32768ULL,65535ULL,0x8000000000000000ULL,0x4000000000000000ULL,0x7FF0000000000000ULL,0xFFF0000000000000ULL,0x7FF0000000000001ULL,0x0008000000000000ULL,0x0010000000000000ULL,0xffffffffffffffffULL};',
              f'for(unsigned t=0;t<{case["native_trials"]};++t){{']
    args = []
    for i, kind in enumerate(case['input_kinds']):
        var = f'input_{i}'; args.append(var)
        if case['id'] == 'chstone_gsm_abs':
            value = '(int)t-32768'
        elif case['id'] == 'machsuite_rj_xtime': value = 't'
        elif case['id'] == 'chstone_gsm_add': value = ('t<8?(int[]){0,32767,-32768,1,-1,32766,-32767,2}[t]:((int)(next()&65535ULL)-32768)' if i == 0 else 't<8?(int[]){32767,0,-1,32767,-32768,1,-1,-2}[t]:((int)(next()&65535ULL)-32768)')
        else: value = 't<14?edge[t]:next()'
        lines += [f'{kind} {var}=({kind})({value});']
    actuals = ','.join(args)
    lines += [f'failures+=(__original({actuals})!=__optimized({actuals}));',
              f'bug_hits+=(__original({actuals})!=__buggy({actuals}));',
              '}', 'printf("%u %u\\n",failures,bug_hits);return failures || !bug_hits;}']
    source = output/'native_differential.c'; source.write_text('\n'.join(lines)+'\n')
    executable = output/'leaf_check.exe'; compiler = shutil.which('clang') or shutil.which('gcc')
    built = subprocess.run([compiler, '-std=c11', '-O2', str(source), '-o', str(executable)], capture_output=True, text=True, timeout=30)
    (output/'native_compile.log').write_text(built.stdout+built.stderr)
    if built.returncode:
        return {'passed': False, 'reason': 'Native compilation failed'}
    run = subprocess.run([str(executable)], capture_output=True, text=True, timeout=15)
    (output/'native_run.log').write_text(run.stdout+run.stderr)
    failures, hits = map(int, run.stdout.split())
    return {'passed': run.returncode == 0, 'trials': case['native_trials'], 'equivalent_mismatches': failures,
            'seeded_bug_mismatches': hits, 'exhaustive_input_domain': case['id'] in ('chstone_gsm_abs', 'machsuite_rj_xtime'),
            'scope': 'Independent native differential tests; not a replay of ESBMC counterexample traces', 'harness_sha256': sha(source)}


def main():
    parser = argparse.ArgumentParser(); parser.add_argument('--timeout', type=int, default=30)
    args = parser.parse_args(); cases = prepare(); rows = []
    for case in cases:
        output = ROOT/'results/dataset_leaves'/case['id']; output.mkdir(exist_ok=True, parents=True)
        for variant, expected in [('optimized', 'equivalent'), ('buggy', 'not_equivalent')]:
            directory = output/variant; directory.mkdir(exist_ok=True)
            source = directory/'miter.c'; source.write_text(miter(case, variant))
            command = [str(ESBMC), str(source), '--32', '--z3', '--bv', '--unwind', '32', '--overflow-check',
                       '--ub-shift-check', '--uninitialised-vars-check', '--multi-property']
            try:
                run = subprocess.run(command, capture_output=True, text=True, timeout=args.timeout)
                log = run.stdout+run.stderr; status = classify_log(log, run.returncode)
            except subprocess.TimeoutExpired as error:
                log = (error.stdout or b'').decode(errors='replace')+(error.stderr or b'').decode(errors='replace')
                status = 'unknown'
            (directory/'esbmc.log').write_text(log)
            row = {'id': case['id'], 'variant': variant, 'status': status, 'expected': expected,
                   'matched_expected': status == expected, 'backend': 'Reused ESBMC 8.7 with Z3; separate scalar-leaf miter',
                   'full_domain': True, 'input_kinds': case['input_kinds'], 'command': command,
                   'miter_sha256': sha(source), 'assumptions': '32-bit ESBMC data model; native Windows LLP64. Static assertions enforce short16/int32/long32/longlong64. No range restrictions.'}
            (directory/'result.json').write_text(json.dumps(row, indent=2)+'\n'); rows.append(row)
            print(case['id'], variant, status, flush=True)
        native = run_native(case, output)
        (output/'native.json').write_text(json.dumps(native, indent=2)+'\n')
        print('native', case['id'], native, flush=True)
    summary = {'cases': rows, 'leaf_functions': len(cases), 'counts': dict(Counter(r['status'] for r in rows)),
        'matched_expected': sum(r['matched_expected'] for r in rows),
        'scope': '8 type-preserving public-suite leaf extractions, each with an LLM-authored candidate and a seeded bug. Reused ESBMC backend, not custom-interpreter coverage or whole-application proofs.'}
    (ROOT/'results/dataset_leaves/summary.json').write_text(json.dumps(summary, indent=2)+'\n')


if __name__ == '__main__':
    main()
