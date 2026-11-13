"""Controlled token-scale mistakes, equivalent edits, and undefined-C controls.

These are deliberately injected examples, never spontaneous LLM outputs.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
from collections import Counter
import difflib
import json

from scripts.evaluate_local_candidates import ROOT, evaluate_pair, digest


# One small semantic edit to each of the 50 existing optimized candidates.
# The original full-input-domain reference remains the comparison baseline.
EDITS = {
    'scale': ('a[i + 1] << 3', 'a[i] << 3', 'unrolled lane reuses the preceding input'),
    'unswitch': ('x > 10u', 'x >= 10u', 'threshold equality changes branch'),
    'gemm': ('m2[k * 4 + j]', 'm2[j * 4 + k]', 'transposed matrix access'),
    'stencil': ('filter[k1 * 3 + 1]', 'filter[k1 * 3]', 'wrong filter coefficient'),
    'prefix': ('running += a[i]', 'running += a[0]', 'recurrence reuses first input'),
    'fir': ('a[0] + a[7]', 'a[0] + a[6]', 'wrong symmetric tap'),
    'boxfilter': ('image[r * 5 + c + 2]', 'image[r * 5 + c + 1]', 'sliding window incoming column off by one'),
    'factor': ('y + z', 'y - z', 'incorrect distributive sign'),
    'dot16': ('a[i+3]*b[i+3]', 'a[i+2]*b[i+3]', 'dot-product lane index'),
    'sum32': ('(s2+s3)', '(s2+s2)', 'partial reduction duplicated'),
    'xor32': ('(s2^s3)', '(s2|s3)', 'OR substituted for XOR'),
    'min8': ('return q0<q1?q0:q1', 'return q0>q1?q0:q1', 'reversed final comparison'),
    'max8': ('return q0>q1?q0:q1', 'return q0<q1?q0:q1', 'reversed final comparison'),
    'range8': ('return high-low', 'return low-high', 'subtraction order reversed'),
    'count_nonzero16': ('a[i+3]!=0u', 'a[i+3]==0u', 'one lane tests zero instead of nonzero'),
    'all_equal16': ('difference|=', 'difference^=', 'differences cancel under XOR'),
    'parity32': ('x>>8', 'x>>7', 'bit-fold shift off by one'),
    'popcount8': ('&15u', '&7u', 'result mask loses count eight'),
    'bitreverse32': ('0x55555555u', '0x55555554u', 'one mask bit omitted'),
    'byteswap32': ('t>>16', 't>>15', 'halfword shift off by one'),
    'crc8_byte': ('?7u:0u', '?5u:0u', 'wrong CRC polynomial bit'),
    'hamming8': ('a[i]^b[i]', 'a[i]|b[i]', 'OR substituted for Hamming XOR'),
    'clamp16': ('v>>8', 'v>>7', 'clamp activates one bit too early'),
    'threshold_pack8': ('a[i]>128u', 'a[i]>=128u', 'rare equality boundary'),
    'absdiff16': ('low=x>y?y:x', 'low=x>y?x:y', 'minimum replaced by maximum'),
    'squared_distance8': ('2u*ab', 'ab', 'cross term loses factor two'),
    'saxpy16': ('k+b[i+1]', 'k+b[i]', 'second output uses preceding bias'),
    'quadratic': ('(a*x+b)*x+c', 'a*x+b*x+c', 'quadratic term loses a factor'),
    'convolution1d8': ('a[i]+a[i+2]', 'a[i]+a[i+1]', 'wrong convolution neighbor'),
    'moving_sum16': ('sum-a[i-1]', 'sum-a[i]', 'wrong outgoing window sample'),
    'triangular_fir16': ('previous=next', 'previous=out[i]', 'recurrence retains accumulated output'),
    'gaussian5': ('2u*horizontal[(r+1)*3+c]', '1u*horizontal[(r+1)*3+c]', 'vertical center coefficient'),
    'integral_image4': ('value-=out', 'value+=out', 'overlap is added instead of subtracted'),
    'transpose4': ('out[(c+1)*4+r]=y', 'out[(c+1)*4+r]=x', 'second transposed lane duplicated'),
    'matvec4': ('a[r*4+3]*x[3]', 'a[r*4+3]*x[2]', 'last vector index'),
    'gemm_local4': ('prod[i*4+3]=s3', 'prod[i*4+3]=s2', 'last accumulator store duplicated'),
    'syrk4': ('out[j*4+i]=sum', 'out[i*4+j]=sum', 'symmetric output store lost'),
    'rank1_update4': ('v*y[3]', 'v*y[2]', 'last rank-one lane index'),
    'triangular_matvec4': ('c<=r', 'c<r', 'diagonal omitted'),
    'symv4': ('if(c!=r)', 'if(c==r)', 'diagonal handling reversed'),
    'matrix_trace4': ('a[i*5]', 'a[i*4]', 'diagonal stride'),
    'matrix_diagsum4': ('a[r*4+3-r]', 'a[r*4+r]', 'antidiagonal replaced by diagonal'),
    'histogram4': ('v==3u', 'v==2u', 'two histogram bins count same value'),
    'search_count16': ('a[i+1]==key', 'a[i]==key', 'odd lane duplicates even comparison'),
    'reverse_copy16': ('out[15-i]=x', 'out[15-i]=y', 'swap loses saved input'),
    'deinterleave16': ('odd[i]=y', 'odd[i]=x', 'odd lane duplicates even'),
    'interleave8': ('out[2*i+1]=b[i]', 'out[2*i+1]=a[i]', 'second input stream lost'),
    'maxpool4': ('m0>m1?m0:m1', 'm0>m1?m1:m0', 'minimum of pair maxima'),
    'moving_sum_register16': ('w1=w2', 'w1=w3', 'shift-register stage skipped'),
    'gemm_tile2': ('m2[k*4+j+1]', 'm2[k*4+j]', 'second tiled column duplicates first'),
}


def scalar(body, params='uint32_t x, uint32_t y'):
    return '#include <stdint.h>\nuint32_t kernel(' + params + '){' + body + '}\n'


def controls():
    # Positive edits deliberately resemble plausible faults. Ties select the
    # same numerical value, and unsigned arithmetic has modular semantics.
    positives = [
        ('min_tie', 'return x<y?x:y;', 'return x<=y?x:y;'),
        ('max_tie', 'return x>y?x:y;', 'return x>=y?x:y;'),
        ('clamp_tie', 'return x>255u?255u:x;', 'return x>=255u?255u:x;'),
        ('strength_multiply', 'return x*8u;', 'return x<<3;'),
        ('unsigned_divide', 'return x/8u;', 'return x>>3;'),
        ('unsigned_remainder', 'return x%8u;', 'return x&7u;'),
        ('modular_subtract', 'return x-y;', 'return x+(~y)+1u;'),
        ('xor_cancel', 'return x;', 'return (x^y)^y;'),
        ('mask_partition', 'return x;', 'return (x&0x55555555u)|(x&0xaaaaaaaau);'),
        ('threshold_adjacent', 'return x>128u?1u:0u;', 'return x>=129u?1u:0u;'),
        ('zero_predicate', 'return x==0u?y:x;', 'return !x?y:x;'),
        ('distributivity', 'return x*y+x*3u;', 'return x*(y+3u);'),
        ('reassociate', 'return (x+y)+0xffffffffu;', 'return x+(y+0xffffffffu);'),
        ('rotate', 'return (x<<8)|(x>>24);', 'return (x>>24)|(x<<8);'),
        ('unsigned_double_not', 'return x;', 'return ~(~x);'),
        ('max_operand_order', 'return x>y?x:y;', 'return y>x?y:x;'),
        ('absdiff_operands', 'return x>y?x-y:y-x;', 'return y>x?y-x:x-y;'),
        ('demorgan', 'return ~(x|y);', 'return (~x)&(~y);'),
        ('shift_mask', 'return (x>>8)&255u;', 'return (x&0xff00u)>>8;'),
        ('guard_division', 'return y!=0u?x/y:0u;', 'if(y==0u)return 0u;return x/y;'),
    ]
    for name, left, right in positives:
        yield 'eq_' + name, scalar(left), scalar(right), 'equivalent', 'Equivalent semantic control'
    negatives = [
        ('average_overflow', 'return x/2u+y/2u+((x&1u)+(y&1u))/2u;', 'return (x+y)/2u;', 'overflow before division'),
        ('rare_magic', 'return x+1u;', 'return x==0xdeadbeefu?x:x+1u;', 'rare special-case exception'),
        ('rounding_bias', 'return (x>>8)+((x&255u)>=128u?1u:0u);', 'return x>>8;', 'rounding changed to truncation'),
        ('unsigned_absdiff', 'return x>y?x-y:y-x;', 'return x-y;', 'absolute difference became modular subtraction'),
    ]
    for name, left, right, why in negatives:
        yield 'fault_' + name, scalar(left), scalar(right), 'not_equivalent', why
    undefined = [
        ('shift_32', 'return x;', 'return x<<32;'),
        ('shift_input', 'return x;', 'return x<<y;'),
        ('division_zero', 'return y?x/y:0u;', 'return x/y;'),
        ('hoisted_division', 'return y?x/y:0u;', 'uint32_t q=x/y;return y?q:0u;'),
    ]
    for name, left, right in undefined:
        yield 'ub_' + name, scalar(left), scalar(right), 'candidate_undefined', 'Undefined behavior must not become equivalence'
    yield 'ub_read_oob', scalar('return x[3];', 'uint32_t x[4]'), scalar('return x[4];', 'uint32_t x[4]'), 'candidate_undefined', 'Array read just beyond end'
    yield 'ub_write_oob', scalar('x[3]=1u;return 0u;', 'uint32_t x[4]'), scalar('x[4]=1u;return 0u;', 'uint32_t x[4]'), 'candidate_undefined', 'Array write just beyond end'


def prepare():
    catalog = json.loads((ROOT / 'experiments/catalog.json').read_text())
    target = ROOT / 'experiments/subtle_faults'; target.mkdir(exist_ok=True)
    rows = []
    def save(name, original, candidate, expected, why, origin):
        folder = target / name; folder.mkdir(exist_ok=True)
        (folder / 'original.c').write_text(original)
        (folder / 'candidate.c').write_text(candidate)
        patch = ''.join(difflib.unified_diff(original.splitlines(True), candidate.splitlines(True), fromfile='original.c', tofile='candidate.c'))
        (folder / 'change.diff').write_text(patch)
        rows.append({'id': name, 'directory': folder.relative_to(ROOT).as_posix(), 'expected': expected,
                     'rationale': why, 'origin': origin, 'original_sha256': digest(folder/'original.c'), 'candidate_sha256': digest(folder/'candidate.c')})
    assert set(EDITS) == {c['name'] for c in catalog['cases']}
    for case in catalog['cases']:
        name = case['name']; path = ROOT / case['directory'] / (name + '_optimized.c')
        source = path.read_text(); old, new, why = EDITS[name]
        if old not in source:
            raise ValueError(name + ': missing exact edit token ' + old)
        # Baseline the equivalent optimized source here. This isolates the
        # injected small edit and keeps the patch useful for human review.
        save(name, source, source.replace(old, new, 1), 'not_equivalent', why,
             'Controlled fault in an already-proved candidate; deliberately injected by this script')
    for name, left, right, expected, why in controls():
        save(name, left, right, expected, why, 'Constructed semantic control, not a spontaneous LLM output')
    plan = {'description': '50 token-scale edits + 4 semantic pitfalls + 20 equivalent edits + 6 undefined-C controls',
            'ground_truth': 'Expected labels declared before verification. Counterexamples must be independently replayed.', 'cases': rows}
    (target / 'manifest.json').write_text(json.dumps(plan, indent=2) + '\n')
    return plan


def main():
    parser = argparse.ArgumentParser(); parser.add_argument('--timeout-ms', type=int, default=15000)
    parser.add_argument('--force', action='store_true'); args = parser.parse_args()
    plan = prepare(); rows = []
    for i, case in enumerate(plan['cases']):
        source = ROOT / case['directory']; folder = ROOT / 'results/subtle_faults' / case['id']
        row = evaluate_pair(source/'original.c', source/'candidate.c', folder, i, args.timeout_ms, args.force)
        rows.append({**case, **row, 'expected_status_matched': row['status'] == case['expected']})
        print(case['id'], row['status'], 'expected', case['expected'], 'native', row.get('native', {}).get('passed'), flush=True)
    summary = {'origin': 'Controlled injected faults and semantic controls. Not model-generated errors.',
               'counts': dict(Counter(r['status'] for r in rows)), 'total': len(rows),
               'matched_expected': sum(r['expected_status_matched'] for r in rows),
               'all_available_native_passed': all(r.get('native', {}).get('passed', True) for r in rows),
               'all_available_smt_replays_passed': all(r.get('smt_replay', {}).get('passed', True) for r in rows),
               'cases': rows}
    (ROOT/'results/subtle_faults/summary.json').write_text(json.dumps(summary, indent=2)+'\n')
    print({k:v for k,v in summary.items() if k!='cases'}, flush=True)


if __name__ == '__main__':
    main()
