"""Interactive file-to-file equivalence, native validation and measured HLS."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import threading
import traceback
import uuid

ROOT = Path(__file__).resolve().parents[1]
if __package__ in (None, ''):
    sys.path.insert(0, str(ROOT))
EVENT = 'HLSCHECK_EVENT '


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def text_sha(text):
    return hashlib.sha256(text.encode('utf-8')).hexdigest()


def write(path, text):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(text.encode('utf-8'))


def save(path, value):
    write(path, json.dumps(value, indent=2) + '\n')


def hls_source(source, name):
    """Keep supplied code/pragmas, changing only a supported top declarator."""
    if name == 'kernel':
        return source
    pattern = (r'/\*[\s\S]*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|'
               r"'(?:\\.|[^'\\])*'|\b" + re.escape(name) + r'\b(?=\s*\()')
    count = 0
    def replace(match):
        nonlocal count
        if match.group() == name:
            count += 1
            return 'kernel'
        return match.group()
    result = re.sub(pattern, replace, source)
    if count != 1:
        raise ValueError('Cannot identify exactly one literal top declarator to rename for HLS')
    return result


def ranges_for(unit, original_unit, ranges):
    return {unit.parameters[p['position']]['name']: ranges[p['name']]
            for p in original_unit.parameters if p['name'] in ranges}


def verify_saved_proof(folder, expected):
    """Pure hash checks also work in the Linux worker without Python Z3."""
    folder = Path(folder)
    result = json.loads((folder / 'result.json').read_text())
    if result['status'] != 'equivalent' or result['source_sha256'] != expected:
        raise ValueError('An equivalence prerequisite does not cover the supplied source snapshots')
    for name, value in result['artifact_sha256'].items():
        if sha(folder / name) != value:
            raise ValueError('Changed proof artifact: ' + name)
    for name, value in result['implementation_sha256'].items():
        if sha(ROOT / 'hlscheck' / name) != value:
            raise ValueError('Checker changed after verification: ' + name)
    return result


def validate_hardware_gate(manifest):
    directory = Path(manifest['run_directory'])
    for requirement in manifest['proof_requirements']:
        folder = directory / requirement['folder']
        if sha(folder / 'result.json') != requirement['result_sha256']:
            raise ValueError('Changed equivalence result')
        verify_saved_proof(folder, requirement['source_sha256'])
    for variant in ('original', 'optimized'):
        item = manifest['inputs'][variant]
        if sha(directory / item['snapshot']) != item['snapshot_sha256']:
            raise ValueError('Source snapshot changed after verification')
        if sha(directory / item['hls_source']) != item['hls_sha256']:
            raise ValueError('HLS input changed after verification')
    native = json.loads((directory / 'native/result.json').read_text())
    if not native['passed'] or sha(directory / 'native/test.c') != native['harness_sha256']:
        raise ValueError('Missing or changed compiled-C validation')
    if sha(directory / 'native/result.json') != manifest['native_result_sha256']:
        raise ValueError('Compiled-C validation result changed')
    if sha(directory / 'hls_inputs/tb.c') != manifest['testbench_sha256']:
        raise ValueError('HLS testbench changed after verification')
    gate = json.loads((directory / 'hls_gate.json').read_text())
    if gate['verification']['status'] != 'equivalent':
        raise ValueError('HLS requires a proved-equivalent pair')
    if gate['original_sha256'] != manifest['inputs']['original']['hls_sha256'] or gate['candidate_sha256'] != manifest['inputs']['optimized']['hls_sha256']:
        raise ValueError('HLS gate does not cover the prepared hardware inputs')
    return directory


def hardware_worker(manifest_path):
    manifest = json.loads(Path(manifest_path).read_text())
    lock = threading.Lock()
    def emit(variant, stage, state, details):
        with lock:
            print(EVENT + json.dumps(dict(variant=variant, stage=stage, state=state, details=details)), flush=True)
    try:
        directory = validate_hardware_gate(manifest)
        from tools.run_hls_linux import run_one
        def task(variant):
            # Fresh per-run names and directories: no old hardware measurements.
            return variant, run_one({'name': 'demo_' + manifest['run_id']}, variant, force=True,
                source_override=directory / manifest['inputs'][variant]['hls_source'],
                testbench_override=directory / 'hls_inputs/tb.c', proof_override=directory / 'hls_gate.json',
                output_root=directory / 'hls', progress=lambda stage, state, details: emit(variant, stage, state, details))
        rows = {}
        with ThreadPoolExecutor(max_workers=manifest['jobs']) as pool:
            for future in as_completed([pool.submit(task, v) for v in ('original', 'optimized')]):
                variant, row = future.result()
                rows[variant] = row
        result = {'status': 'complete' if all(r['status'] == 'complete' for r in rows.values()) else 'failed', 'measurements': rows}
        save(directory / 'hardware.json', result)
        return 0 if result['status'] == 'complete' else 3
    except Exception as error:
        emit('pipeline', 'error', 'failed', {'reason': str(error)})
        traceback.print_exc()
        return 3


def run_hardware(manifest_path, args, say, on_mapping=None):
    if os.name == 'nt':
        def to_linux(path):
            result = subprocess.run(['wsl.exe', '-d', args.wsl_distro, '--', 'wslpath', '-a', Path(path).resolve().as_posix()],
                                    capture_output=True, text=True, timeout=30)
            if result.returncode:
                raise RuntimeError('WSL path conversion failed: ' + result.stderr.strip())
            return result.stdout.strip()
        manifest = json.loads(Path(manifest_path).read_text())
        linux_directory = to_linux(Path(manifest_path).parent)
        manifest['run_directory'] = linux_directory
        save(Path(manifest_path).parent / 'linux_manifest.json', manifest)
        command = ['wsl.exe', '-d', args.wsl_distro, '--', 'python3', to_linux(__file__),
                   '--_hls-worker', linux_directory + '/linux_manifest.json']
    else:
        command = [sys.executable, str(Path(__file__).resolve()), '--_hls-worker', str(manifest_path)]
    mapping_heading = False
    with (Path(manifest_path).parent / 'hardware_worker.log').open('w', encoding='utf-8') as log:
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                   text=True, encoding='utf-8', errors='replace')
        try:
            for line in process.stdout:
                log.write(line)
                log.flush()
                if not line.startswith(EVENT):
                    continue
                event = json.loads(line[len(EVENT):])
                stage, state, d = event['stage'], event['state'], event['details']
                if stage in ('mapping', 'timing') and not mapping_heading:
                    if on_mapping is not None:
                        on_mapping()
                    else:
                        say('\n[6/7] CELL MAPPING AND STATIC TIMING (per design)')
                    mapping_heading = True
                prefix = '  [' + event['variant'] + '] '
                if stage == 'hls_rtl':
                    say(prefix + ('Bambu + Verilator: running...' if state == 'running' else
                        f'RTL simulation: PASS, {d["transactions"]} transactions, {d["cycles"]:g} average cycles (range {d["cycles_min"]}..{d["cycles_max"]})'))
                elif stage == 'mapping':
                    say(prefix + ('Yosys mapping: running...' if state == 'running' else f'Mapped area: {d["area_um2"]:.3f} um^2'))
                elif stage == 'timing':
                    say(prefix + ('OpenSTA: running...' if state == 'running' else
                        f'Critical-path delay: {d["delay_ns"]:.6f} ns; meets 10 ns: {d["meets_10ns"]}'))
                elif stage == 'error':
                    say(prefix + 'FAILED: ' + d['reason'])
            if process.wait():
                raise RuntimeError('Hardware pipeline failed; inspect hardware_worker.log and per-tool logs')
        finally:
            if process.poll() is None:
                process.terminate()
                process.wait(timeout=15)
    return json.loads((Path(manifest_path).parent / 'hardware.json').read_text())


def compile_native(original, candidate, function, ranges, trials, directory):
    from scripts.design_testbench import make_testbench
    source = directory / 'test.c'
    write(source, make_testbench(original, candidate, function=function, scalar_ranges=ranges, trials=trials))
    executable = directory / ('check.exe' if os.name == 'nt' else 'check.out')
    compiler = shutil.which('clang')
    if not compiler:
        raise RuntimeError('Clang is required for compiled-C validation')
    built = subprocess.run([compiler, '-std=c11', '-O1', str(source), '-o', str(executable)],
                           capture_output=True, text=True, timeout=60)
    write(directory / 'compile.log', built.stdout + built.stderr)
    if built.returncode:
        raise RuntimeError('Native harness compilation failed; see native/compile.log')
    run = subprocess.run([str(executable.resolve())], capture_output=True, text=True, timeout=30)
    write(directory / 'run.log', run.stdout + run.stderr)
    result = {'passed': run.returncode == 0, 'trials': trials, 'stdout': run.stdout,
              'harness_sha256': sha(source), 'source_model': 'C11/ILP32'}
    save(directory / 'result.json', result)
    if not result['passed']:
        raise RuntimeError('Compiled-C comparison failed; HLS stopped. See native/run.log')
    return result


def compare(measurements):
    a, b = measurements['original'], measurements['optimized']
    keys = [('Cell area (um^2)', 'area_um2'), ('Execution latency (cycles)', 'cycles'),
            ('Execution latency at 10 ns (ns)', 'latency_at_target_ns'),
            ('Critical-path delay (ns)', 'delay_ns'), ('Area x execution latency', 'area_latency_product_um2_ns')]
    rows = []
    for label, key in keys:
        # All displayed costs are lower-is-better: positive means improvement.
        rows.append({'metric': label, 'original': a[key], 'optimized': b[key],
                     'improvement_percent': 100 * (1 - b[key] / a[key])})
    ratio = b['area_latency_product_um2_ns'] / a['area_latency_product_um2_ns']
    outcome = 'improved' if ratio < .999 and b['meets_10ns'] else ('regressed' if ratio > 1.001 else 'unchanged')
    if not b['meets_10ns']:
        outcome = 'does_not_meet_clock'
    return {'metrics': rows, 'latency_speedup': a['cycles'] / b['cycles'],
            'area_latency_ratio': ratio, 'outcome': outcome, 'clock_ns': 10,
            'scope': 'Mapped pre-layout Nangate45 ASIC estimates; no routed timing, FPGA or formal C-to-RTL claim'}


def run_pipeline(args):
    from hlscheck import verify_equivalence
    from hlscheck.frontend import compile_pair
    from hlscheck.evidence import verify_evidence, replay_native_witness
    output = args.output_dir.resolve()
    run_id = uuid.uuid4().hex[:12]
    directory = output / ('run_' + run_id)
    directory.mkdir(parents=True, exist_ok=False)
    record = {'run_id': run_id, 'status': 'running', 'hls_requested': args.hls,
              'run_directory': str(directory), 'stages': [], 'inputs': {},
              'pipeline_sha256': sha(__file__),
              'testbench_generator_sha256': sha(ROOT / 'scripts/design_testbench.py')}
    def persist():
        save(directory / 'summary.json', record)
        save(output / 'latest.json', {'run_directory': str(directory), 'status': record['status'],
                                     'summary': str(directory / 'summary.json')})
    with (directory / 'console.log').open('w', encoding='utf-8') as console:
        def say(message):
            print(message, flush=True)
            console.write(message + '\n')
            console.flush()
        def stage(number, title):
            say(f'\n[{number}/7] {title}')
            record['stages'].append({'number': number, 'name': title})
            persist()
        try:
            say('HLSCheck: source equivalence -> native checks -> measured HLS comparison')
            say('Fresh run: ' + str(directory))
            stage(1, 'READ AND VALIDATE THE SUPPLIED FILES')
            sources = {}
            for variant, path in [('original', args.original), ('optimized', args.optimized)]:
                path = path.resolve()
                raw = path.read_bytes()
                source = raw.decode('utf-8-sig').replace('\r\n', '\n').replace('\r', '\n')
                snapshot = f'inputs/{variant}_source.c'
                write(directory / snapshot, source)
                record['inputs'][variant] = {'file': str(path), 'raw_sha256': hashlib.sha256(raw).hexdigest(),
                    'snapshot': snapshot, 'snapshot_sha256': text_sha(source)}
                sources[variant] = source
                say(f'  {variant}: {path}\n    source SHA256: {record["inputs"][variant]["raw_sha256"]}')
            ranges = json.loads(args.ranges.read_text()) if args.ranges else {}
            left, right, contract = compile_pair(sources['original'], sources['optimized'], args.function, scalar_ranges=ranges)
            record['contract'] = contract
            say('  Target: C11 / ILP32; .cpp files must use the supported C-compatible subset.')
            say('  Functions: ' + left.function.decl.name + ' vs ' + right.function.decl.name)
            say('  Arrays: valid and nonoverlapping. Compare every final array element and the return value.')
            say('  Scalar preconditions: ' + json.dumps(ranges))

            stage(2, 'FORMAL C-TO-C EQUIVALENCE')
            say(f'  Running HLSCheck; limit {args.timeout_ms/1000:g} s per solver/verifier obligation...')
            proof = directory / 'proof'
            result = verify_equivalence(sources['original'], sources['optimized'], args.function,
                output_dir=proof, scalar_ranges=ranges, timeout_ms=args.timeout_ms, max_unroll=args.max_unroll, max_paths=args.max_paths)
            for obligation in result.get('obligations', []):
                suffix = ' (abstract mismatch; subject to refinement)' if obligation.get('abstraction') == 'shared_havoc' and obligation['status'] == 'not_equivalent' else ''
                say(f'  {obligation["id"]}: {obligation["status"]} [{obligation["engine"]}]' + suffix)
            for refinement in result.get('refinements', []):
                say('  Refinement: ' + refinement.get('action', str(refinement)))
            say(f'  VERDICT: {result["status"]} ({result["elapsed_seconds"]:.3f} s)')
            record['verification'] = {'status': result['status'], 'elapsed_seconds': result['elapsed_seconds'], 'proof': 'proof/result.json'}
            if result['status'] != 'equivalent':
                record['status'] = result['status']
                if result.get('reason'):
                    say('  Reason: ' + result['reason'])
                if result.get('counterexample'):
                    say('  Counterexample: ' + json.dumps(result['counterexample']))
                    if result['status'] == 'not_equivalent':
                        witness = replay_native_witness(proof, directory / 'counterexample')
                        record['native_witness'] = witness
                        say('  Compiled-C witness reproduced: ' + str(witness.get('passed')))
                say('  STOP: stages 3-7 and HLS are skipped because equivalence was not proved.')
                return 1 if result['status'] == 'not_equivalent' else 2

            stage(3, 'REPLAY PROOF EVIDENCE AND BIND HLS INPUTS')
            evidence = verify_evidence(proof, timeout_ms=args.timeout_ms)
            if not evidence['passed']:
                raise RuntimeError('Accepted SMT dependency replay failed')
            save(directory / 'evidence_replay.json', evidence)
            say(f'  Proof artifact hashes: PASS; accepted SMT queries replayed: {len(evidence["queries"])}.')
            requirements = [{'folder': 'proof', 'result_sha256': sha(proof / 'result.json'), 'source_sha256': result['source_sha256']}]
            for variant, unit in [('original', left), ('optimized', right)]:
                normalized = hls_source(sources[variant], unit.function.decl.name)
                name = f'hls_inputs/{variant}.c'
                write(directory / name, normalized)
                record['inputs'][variant].update(hls_source=name, hls_sha256=text_sha(normalized))
                if normalized != sources[variant]:
                    destination = directory / 'normalization' / variant
                    certificate = verify_equivalence(sources[variant], normalized, output_dir=destination,
                        scalar_ranges=ranges_for(unit, left, ranges), timeout_ms=args.timeout_ms,
                        max_unroll=args.max_unroll, max_paths=args.max_paths)
                    if certificate['status'] != 'equivalent' or not verify_evidence(destination, timeout_ms=args.timeout_ms)['passed']:
                        raise RuntimeError('HLS top-name preparation was not proved equivalent')
                    requirements.append({'folder': destination.relative_to(directory).as_posix(),
                        'result_sha256': sha(destination / 'result.json'), 'source_sha256': certificate['source_sha256']})
                    say('  ' + variant + ': top renamed to kernel; equivalence certified.')
                else:
                    say('  ' + variant + ': HLS input is byte-identical to the verified source snapshot.')

            stage(4, 'COMPILED-C EDGE/RANDOM CHECKS')
            native = compile_native(sources['original'], sources['optimized'], args.function, ranges, args.native_trials, directory / 'native')
            record['native'] = native
            say('  ' + native['stdout'].strip())
            say('  These checks supplement the formal proof; they do not replace it.')
            if not args.hls:
                record['status'] = 'equivalent_verified_only'
                say('\n[5/7] HLS/RTL: SKIPPED (--verify-only)\n[6/7] Mapping/timing: SKIPPED\n[7/7] Hardware comparison: SKIPPED')
                return 0
            from scripts.design_testbench import make_testbench
            write(directory / 'hls_inputs/tb.c', make_testbench(sources['original'], function=args.function, scalar_ranges=ranges, trials=16, hls=True))
            manifest = {'run_id': run_id, 'run_directory': str(directory), 'inputs': record['inputs'],
                        'proof_requirements': requirements, 'jobs': args.jobs,
                        'testbench_sha256': sha(directory / 'hls_inputs/tb.c'),
                        'native_result_sha256': sha(directory / 'native/result.json')}
            save(directory / 'manifest.json', manifest)
            save(directory / 'hls_gate.json', {'verification': {'status': 'equivalent'},
                'original_sha256': record['inputs']['original']['hls_sha256'],
                'candidate_sha256': record['inputs']['optimized']['hls_sha256']})
            validate_hardware_gate(manifest)

            stage(5, 'HLS GENERATION AND RTL SIMULATION')
            say(f'  Fresh hardware runs; up to {args.jobs} designs in parallel. Target: Nangate45, 10 ns.')
            say('  Each design continues from Bambu/Verilator into Yosys and OpenSTA independently.')
            hardware = run_hardware(directory / 'manifest.json', args, say,
                                    on_mapping=lambda: stage(6, 'CELL MAPPING AND STATIC TIMING (per design)'))
            record['hardware'] = hardware
            if hardware['status'] != 'complete':
                raise RuntimeError('One or more hardware measurements failed')
            measurements = hardware['measurements']
            for variant, row in measurements.items():
                if row['source_sha256'] != record['inputs'][variant]['hls_sha256'] or row['testbench_sha256'] != manifest['testbench_sha256']:
                    raise RuntimeError('Hardware evidence does not match this run inputs')
                if not row['rtl_simulation_passed'] or row['rtl_simulation_calls'] != 16:
                    raise RuntimeError('RTL validation incomplete')
            if len({row['configuration_sha256'] for row in measurements.values()}) != 1:
                raise RuntimeError('Hardware configurations differ')
            say('  Hardware input/testbench/configuration checks: PASS. RTL transactions: 16 + 16 PASS.')

            stage(7, 'MEASURED QUALITY COMPARISON')
            comparison = compare(measurements)
            record.update(status='complete', comparison=comparison)
            say(f'  {"Metric":34s} {"Original":>12s} {"Optimized":>12s} {"Improvement":>12s}')
            for row in comparison['metrics']:
                say(f'  {row["metric"]:34s} {row["original"]:12.6g} {row["optimized"]:12.6g} {row["improvement_percent"]:+11.2f}%')
            say('  Improvement (%) = 100 x (original - optimized) / original; positive is better.')
            say(f'  Latency speedup: {comparison["latency_speedup"]:.3f}x')
            say('  Area x latency outcome: ' + comparison['outcome'].upper())
            say('  Critical-path delay is distinct from execution latency. Estimates are pre-layout ASIC values.')
            report = ['# File-to-file HLSCheck pipeline', '', f'Original: `{record["inputs"]["original"]["file"]}`',
                      f'Candidate: `{record["inputs"]["optimized"]["file"]}`', '', 'Equivalence: **equivalent**.',
                      f'Native comparisons: {args.native_trials} passed. RTL transactions: 32 passed.', '',
                      '| Metric | Original | Optimized | Improvement |', '| --- | ---: | ---: | ---: |']
            report += [f'| {r["metric"]} | {r["original"]:.6g} | {r["optimized"]:.6g} | {r["improvement_percent"]:+.2f}% |' for r in comparison['metrics']]
            report += ['', 'Improvement (%) = 100 x (original - optimized) / original; positive is better.', '',
                       'Area x execution latency outcome: **' + comparison['outcome'] + '**.', '', comparison['scope'], '',
                       'The .cpp extension uses C-compatible C11 semantics. HLS sources preserve the supplied code/pragmas; only a non-kernel top declarator is renamed and certified when needed.', '',
                       'See console.log, proof/, evidence_replay.json, native/, hls_inputs/, and hls/ for the complete evidence.']
            write(directory / 'REPORT.md', '\n'.join(report) + '\n')
            return 0
        except Exception as error:
            record.update(status='pipeline_error', error=str(error))
            write(directory / 'error.log', traceback.format_exc())
            say('  FAILED: ' + str(error))
            say('  The pipeline did not complete; no successful hardware comparison is reported.')
            return 3
        finally:
            persist()
            say('\nRun status: ' + record['status'])
            say('Summary: ' + str(directory / 'summary.json'))
            say('Latest-run pointer: ' + str(output / 'latest.json'))


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', nargs='?', type=Path)
    parser.add_argument('optimized', nargs='?', type=Path)
    parser.add_argument('--function', help='Function to compare; inferred when each input has one function')
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'results/demo_pipeline')
    parser.add_argument('--ranges', type=Path, help='Explicit scalar preconditions as JSON')
    parser.add_argument('--timeout-ms', type=int, default=60000, help='Per formal solver/verifier obligation')
    parser.add_argument('--max-unroll', type=int, default=256)
    parser.add_argument('--max-paths', type=int, default=256)
    parser.add_argument('--native-trials', type=int, default=264)
    parser.add_argument('--jobs', type=int, choices=(1, 2), default=2)
    parser.add_argument('--wsl-distro', default='Ubuntu')
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument('--hls', dest='hls', action='store_true', help='Run full hardware pipeline (default for two files)')
    mode.add_argument('--verify-only', '--no-hls', dest='hls', action='store_false', help='Stop after formal and compiled-C checks')
    parser.set_defaults(hls=True)
    parser.add_argument('--examples', action='store_true', help='Run the three predefined equivalence-only examples')
    parser.add_argument('--_hls-worker', type=Path, help=argparse.SUPPRESS)
    args = parser.parse_args(argv)
    if args._hls_worker:
        return hardware_worker(args._hls_worker)
    if args.original is None and args.optimized is None:
        print('No input pair: running the three predefined equivalence-only examples.\n'
              'For the full pipeline: python run_demo.py original.c optimized.c --function kernel\n', flush=True)
        from scripts.demo_hybrid import main as examples
        return examples()
    if args.original is None or args.optimized is None or args.examples:
        parser.error('Supply both source files, or use --examples without source files')
    if min(args.timeout_ms, args.max_unroll, args.max_paths, args.native_trials) <= 0:
        parser.error('Resource limits and trial count must be positive')
    return run_pipeline(args)


if __name__ == '__main__':
    raise SystemExit(main())
