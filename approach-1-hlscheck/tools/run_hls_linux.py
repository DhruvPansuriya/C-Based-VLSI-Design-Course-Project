"""Real Bambu -> Verilator -> Yosys -> OpenSTA experiments, run inside WSL.

All per-design working directories are on the Linux filesystem (tool scripts
do not reliably support spaces in paths). Evidence is copied back to results/.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import time
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
TOOLS = Path.home() / "cs5291_hls_tools"
USR = TOOLS / "squashfs-root/usr"
WORK = Path.home() / "cs5291_hls_runs"
LIB = ROOT / "tools/nangate45/NangateOpenCellLibrary_typical.lib"
OUT = ROOT / "results/hls"
ENV = dict(os.environ)
ENV["BAMBU_HLS"] = str(USR)
ENV["BAMBU_HLS_BACKEND_PATH"] = ":".join([str(TOOLS / "opt/yosys/bin"), str(TOOLS / "opt/openroad/bin"), ENV["PATH"]])
ENV["PATH"] = ":".join([str(USR / "bin"), str(USR / "compilers/clang-16/bin"), str(USR / "compilers/clang-13/bin"), ENV["BAMBU_HLS_BACKEND_PATH"]])
CONFIG = {"protocol_version": 1, "target":"nangate45", "clock_ns":10,
          "compiler":"I386_CLANG16", "setup":"BAMBU-BALANCED-MP", "seed":0,
          "simulator":"VERILATOR", "tb_calls":16, "yosys_deferred_elaboration":True,
          "abc":"default liberty mapping", "sta_io_delay_ns":0, "sta_input_transition_ns":0.05,
          "sta_output_load_ff":10, "library_sha256":hashlib.sha256(LIB.read_bytes()).hexdigest()}
CONFIG_HASH=hashlib.sha256(json.dumps(CONFIG,sort_keys=True).encode()).hexdigest()


def execute(command, cwd, log, timeout=600):
    start = time.perf_counter()
    with log.open("w") as stream:
        result = subprocess.run(command, cwd=cwd, env=ENV, stdout=stream, stderr=subprocess.STDOUT, timeout=timeout)
    return {"command": command, "exit_code": result.returncode, "elapsed_seconds": round(time.perf_counter()-start, 3)}


def audit_timing_coverage(work, output):
    design = json.loads((work / "mapped.json").read_text())["modules"]["kernel"]
    constant_ports = set()
    for name, port in design["ports"].items():
        if port["direction"] == "output":
            for i, bit in enumerate(port["bits"]):
                if isinstance(bit, str):
                    constant_ports.add(name + f"[{i}]")
                    if len(port["bits"]) == 1:
                        constant_ports.add(name)
    log = (output / "sta.log").read_text()
    match = re.search(r"unconstrained endpoints\.\n((?:  [^\n]+\n)+)", log)
    endpoints = set(x.strip() for x in match.group(1).splitlines()) if match else set()
    unexplained = sorted(endpoints - constant_ports)
    if unexplained or "missing set_input_delay" in log or "missing set_output_delay" in log:
        raise RuntimeError("Timing constraints incomplete: " + repr(unexplained[:5]))
    return {"reported_unconstrained_endpoints": len(endpoints), "all_are_constant_outputs": True,
            "unexplained_unconstrained_endpoints": unexplained}


def run_one(case, variant, force=False, *, source_override=None, testbench_override=None,
            proof_override=None, output_root=None, progress=None):
    def notify(stage, state, **details):
        if progress is not None:
            progress(stage, state, details)
    identifier = case["name"] + "_" + variant
    source = Path(source_override) if source_override else ROOT / case["directory"] / f"{identifier}.c"
    source_hash = hashlib.sha256(source.read_bytes()).hexdigest()
    testbench_source=Path(testbench_override) if testbench_override else ROOT/'results/native'/f"{case['name']}_hls_tb.c"
    testbench_hash=hashlib.sha256(testbench_source.read_bytes()).hexdigest()
    proof_file = Path(proof_override) if proof_override else ROOT / "results/submission_verification" / f"{case['name']}_optimized.json"
    proof = json.loads(proof_file.read_text())
    proof_key = "original_sha256" if variant == "original" else "candidate_sha256"
    if proof["verification"]["status"] != "equivalent" or proof[proof_key] != source_hash:
        raise RuntimeError(f"{identifier}: verify the exact current source pair before synthesis")
    output = (Path(output_root) if output_root else OUT) / identifier
    output.mkdir(parents=True, exist_ok=True)
    recorded = output / "metrics.json"
    if recorded.exists() and not force:
        row = json.loads(recorded.read_text())
        retained_tb=output/'tb.c'
        if (row.get("status") == "complete" and row["source_sha256"] == source_hash and row.get("configuration_sha256")==CONFIG_HASH
            and retained_tb.exists() and hashlib.sha256(retained_tb.read_bytes()).hexdigest()==testbench_hash):
            row['testbench_sha256']=testbench_hash
            recorded.write_text(json.dumps(row,indent=2)+'\n')
            notify('cache', 'reused', cycles=row['cycles'], area_um2=row['area_um2'], delay_ns=row['delay_ns'])
            print(identifier, "cached", flush=True)
            return row
    work = WORK / identifier
    work.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(source, work / "kernel.c")
    shutil.copyfile(testbench_source, work / "tb.c")
    shutil.copyfile(LIB, work / "cells.lib")
    source_label = str(source.relative_to(ROOT)) if source.is_relative_to(ROOT) else str(source)
    row = {"case": case["name"], "variant": variant, "source": source_label,
           "source_sha256": source_hash, "target": "Nangate45 typical", "clock_target_ns": 10.0,
           "configuration_sha256": CONFIG_HASH, "configuration":CONFIG,
           'testbench_sha256':testbench_hash,
           "optimization": "BAMBU-BALANCED-MP / -O2", "seed": 0, "status": "started",
           "area_definition": "mapped standard-cell area in um^2; includes logic/register memory, no physical placement",
           "delay_definition": "10 ns minus worst max-path slack; ideal clocks, zero IO delay, 0.01 pF output load, no extracted wires"}
    try:
        command = [str(USR / "bin/bambu"), str(work / "kernel.c"), "--top-fname=kernel", "--device-name=nangate45",
                   "--clock-period=10", "--compiler=I386_CLANG16", "--experimental-setup=BAMBU-BALANCED-MP", "--seed=0",
                   "--generate-tb=" + str(work / "tb.c"), "--simulate", "--simulator=VERILATOR"]
        notify('hls_rtl', 'running', tool='Bambu + Verilator')
        row["hls"] = execute(command, work, output / "bambu.log")
        if row["hls"]["exit_code"]:
            raise RuntimeError("Bambu or RTL simulation failed; see bambu.log")
        document = ET.parse(work / "bambu_results.xml").getroot()
        simulation = document.find("timing/simulation")
        cycles = [int(float(x.text)) for x in simulation.findall("run")]
        if simulation.attrib.get("return_value") != "0" or len(cycles) != 16:
            raise RuntimeError("Expected sixteen successful RTL simulation calls")
        row.update({"rtl_simulation_passed": True, "rtl_simulation_calls": len(cycles),
                    "cycles": sum(cycles)/len(cycles), "cycles_min": min(cycles), "cycles_max": max(cycles),
                    "latency_at_target_ns": sum(cycles)/len(cycles)*10.0,
                    "bambu_version": document.attrib["version"], "frontend_flags": document.find("sources").attrib["cflags"]})
        notify('hls_rtl', 'passed', transactions=len(cycles), cycles=row['cycles'],
               cycles_min=row['cycles_min'], cycles_max=row['cycles_max'])
        rtl = [x.text for x in document.findall("outputs/file")]
        for f in rtl:
            shutil.copyfile(work / f, output / f)
        shutil.copyfile(work / "bambu_results.xml", output / "bambu_results.xml")
        shutil.copyfile(work / "tb.c", output / "tb.c")
        for memory in work.glob("*.mem"):
            shutil.copyfile(memory, output / memory.name)
        simulation_log = work / "HLS_output/simulation/verilator_backend/simulation.log"
        if simulation_log.exists():
            shutil.copyfile(simulation_log, output / "rtl_simulation.log")
        generated_tb = work / "HLS_output/simulation/bambu_testbench.v"
        if generated_tb.exists():
            shutil.copyfile(generated_tb, output / "bambu_testbench.v")
        script = "\n".join([
            "read_liberty -lib cells.lib", "read_verilog -defer " + " ".join(rtl), "hierarchy -check -top kernel",
            "synth -top kernel -flatten", "dfflibmap -liberty cells.lib", "abc -liberty cells.lib", "clean",
            "check", "stat -liberty cells.lib", "write_verilog -noattr -simple-lhs mapped.v", "write_json mapped.json", ""])
        (work / "synth.ys").write_text(script)
        notify('mapping', 'running', tool='Yosys / Nangate45')
        row["synthesis"] = execute([str(TOOLS / "opt/yosys/bin/yosys"), "-s", "synth.ys"], work, output / "yosys.log")
        if row["synthesis"]["exit_code"]:
            raise RuntimeError("Yosys mapping failed")
        log = (output / "yosys.log").read_text()
        areas = re.findall(r"Chip area for (?:top )?module [^:]+:\s*([\d.]+)", log)
        if not areas:
            raise RuntimeError("No mapped cell area found")
        row["area_um2"] = float(areas[-1])
        notify('mapping', 'passed', area_um2=row['area_um2'])
        netlist = json.loads((work / "mapped.json").read_text())["modules"]["kernel"]
        row["mapped_cells"] = len(netlist["cells"])
        row["mapped_cell_types"] = {}
        for cell in netlist["cells"].values():
            kind = cell["type"]
            row["mapped_cell_types"][kind] = row["mapped_cell_types"].get(kind, 0) + 1
        sta = "\n".join([
            "read_liberty cells.lib", "read_verilog mapped.v", "link_design kernel",
            "create_clock -name core_clock -period 10 [get_ports clock]",
            "set data_inputs [lsearch -all -inline -not -exact [all_inputs] [lindex [get_ports clock] 0]]",
            "set_input_delay 0 -clock core_clock $data_inputs", "set_output_delay 0 -clock core_clock [all_outputs]",
            "set_input_transition 0.05 [all_inputs]", "set_load 10 [all_outputs]",
            "check_setup -verbose", "report_checks -path_delay max -group_count 1 -endpoint_count 1 -digits 6",
            "report_worst_slack -digits 6", "exit", ""])
        (work / "timing.tcl").write_text(sta)
        notify('timing', 'running', tool='OpenSTA')
        row["timing"] = execute([str(TOOLS / "opt/openroad/bin/sta"), "-exit", "timing.tcl"], work, output / "sta.log")
        log = (output / "sta.log").read_text()
        if row["timing"]["exit_code"] or re.search(r"\bError:", log):
            raise RuntimeError("OpenSTA timing failed")
        slack = re.findall(r"worst slack\s+(-?[\d.]+)", log)
        if not slack:
            raise RuntimeError("No constrained timing path found")
        row["worst_slack_ns"] = float(slack[-1])
        row["delay_ns"] = round(10 - row["worst_slack_ns"], 6)
        row["timing_coverage"] = audit_timing_coverage(work, output)
        row["meets_10ns"] = row["worst_slack_ns"] >= 0
        row["area_latency_product_um2_ns"] = row["area_um2"] * row["latency_at_target_ns"]
        row["status"] = "complete"
        notify('timing', 'passed', delay_ns=row['delay_ns'], meets_10ns=row['meets_10ns'])
        for f in ("synth.ys", "timing.tcl", "mapped.v"):
            shutil.copyfile(work / f, output / f)
    except Exception as error:
        row["status"] = "failed"
        row["error"] = str(error)
        notify('error', 'failed', reason=str(error))
    recorded.write_text(json.dumps(row, indent=2) + "\n")
    print(identifier, row["status"], {k:row[k] for k in ("cycles","area_um2","delay_ns","error") if k in row}, flush=True)
    return row


def retime_one(case, variant):
    """Reuse recorded synthesis, adapting netlist syntax for the bundled STA."""
    identifier = case["name"] + "_" + variant
    output = OUT / identifier
    work = WORK / identifier
    row = json.loads((output / "metrics.json").read_text())
    assert row["source_sha256"] == hashlib.sha256((ROOT / row["source"]).read_bytes()).hexdigest()
    try:
        if row.get("synthesis", {}).get("exit_code") != 0:
            raise RuntimeError("Synthesis has not succeeded")
        script = "read_json mapped.json\nwrite_verilog -noattr -simple-lhs mapped.v\n"
        (work / "export.ys").write_text(script)
        row["netlist_export"] = execute([str(TOOLS / "opt/yosys/bin/yosys"), "-s", "export.ys"], work, output / "netlist_export.log")
        sta = "\n".join([
            "read_liberty cells.lib", "read_verilog mapped.v", "link_design kernel",
            "create_clock -name core_clock -period 10 [get_ports clock]",
            "set data_inputs [lsearch -all -inline -not -exact [all_inputs] [lindex [get_ports clock] 0]]",
            "set_input_delay 0 -clock core_clock $data_inputs", "set_output_delay 0 -clock core_clock [all_outputs]",
            "set_input_transition 0.05 [all_inputs]", "set_load 10 [all_outputs]",
            "check_setup -verbose", "report_checks -path_delay max -group_count 1 -endpoint_count 1 -digits 6",
            "report_worst_slack -digits 6", "exit", ""])
        (work / "timing.tcl").write_text(sta)
        row["timing"] = execute([str(TOOLS / "opt/openroad/bin/sta"), "-exit", "timing.tcl"], work, output / "sta.log")
        log = (output / "sta.log").read_text()
        if row["timing"]["exit_code"] or re.search(r"\bError:", log):
            raise RuntimeError("OpenSTA timing failed")
        slack = re.findall(r"worst slack\s+(-?[\d.]+)", log)
        if not slack:
            raise RuntimeError("No constrained timing path found")
        row["worst_slack_ns"] = float(slack[-1])
        row["delay_ns"] = round(10 - row["worst_slack_ns"], 6)
        row["timing_coverage"] = audit_timing_coverage(work, output)
        row["meets_10ns"] = row["worst_slack_ns"] >= 0
        row["area_latency_product_um2_ns"] = row["area_um2"] * row["latency_at_target_ns"]
        row["status"] = "complete"
        row.pop("error", None)
        for f in ("synth.ys", "timing.tcl", "mapped.v", "export.ys"):
            shutil.copyfile(work / f, output / f)
        for f, dest in [("HLS_output/simulation/verilator_backend/simulation.log", "rtl_simulation.log"),
                        ("HLS_output/simulation/bambu_testbench.v", "bambu_testbench.v")]:
            if (work / f).exists():
                shutil.copyfile(work / f, output / dest)
    except Exception as error:
        row["status"], row["error"] = "failed", str(error)
    (output / "metrics.json").write_text(json.dumps(row,indent=2)+"\n")
    print(identifier, row["status"], {k:row[k] for k in ("cycles","area_um2","delay_ns","error") if k in row}, flush=True)
    return row


def resynth_one(case, variant):
    identifier = case["name"] + "_" + variant
    output, work = OUT / identifier, WORK / identifier
    row = json.loads((output / "metrics.json").read_text())
    assert row["source_sha256"] == hashlib.sha256((ROOT / row["source"]).read_bytes()).hexdigest()
    try:
        if not row.get("rtl_simulation_passed"):
            raise RuntimeError("HLS and RTL simulation have not succeeded")
        document = ET.parse(work / "bambu_results.xml").getroot()
        rtl = [x.text for x in document.findall("outputs/file")]
        # Defer elaboration until the real parameter values are known. Parsing
        # generic RAM defaults eagerly would request a nonexistent array.mem.
        script = "\n".join([
            "read_liberty -lib cells.lib", "read_verilog -defer " + " ".join(rtl), "hierarchy -check -top kernel",
            "synth -top kernel -flatten", "dfflibmap -liberty cells.lib", "abc -liberty cells.lib", "clean",
            "check", "stat -liberty cells.lib", "write_verilog -noattr -simple-lhs mapped.v", "write_json mapped.json", ""])
        (work / "synth.ys").write_text(script)
        row["synthesis"] = execute([str(TOOLS / "opt/yosys/bin/yosys"), "-s", "synth.ys"], work, output / "yosys.log")
        if row["synthesis"]["exit_code"]:
            raise RuntimeError("Yosys mapping failed")
        areas = re.findall(r"Chip area for (?:top )?module [^:]+:\s*([\d.]+)", (output / "yosys.log").read_text())
        row["area_um2"] = float(areas[-1])
        netlist = json.loads((work / "mapped.json").read_text())["modules"]["kernel"]
        row["mapped_cells"], row["mapped_cell_types"] = len(netlist["cells"]), {}
        for cell in netlist["cells"].values():
            kind = cell["type"]
            row["mapped_cell_types"][kind] = row["mapped_cell_types"].get(kind,0)+1
        for memory in work.glob("*.mem"):
            shutil.copyfile(memory,output/memory.name)
        (output / "metrics.json").write_text(json.dumps(row,indent=2)+"\n")
        return retime_one(case,variant)
    except Exception as error:
        row["status"],row["error"] = "failed",str(error)
        (output / "metrics.json").write_text(json.dumps(row,indent=2)+"\n")
        print(identifier,"failed",str(error),flush=True)
        return row


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cases", nargs="*")
    parser.add_argument("--jobs", type=int, default=2)
    parser.add_argument("--force", action="store_true")
    parser.add_argument("--retime-only", action="store_true")
    parser.add_argument("--resynth-only", action="store_true")
    args = parser.parse_args()
    OUT.mkdir(exist_ok=True, parents=True)
    cases = json.loads((ROOT / "experiments/catalog.json").read_text())["cases"]
    if args.cases:
        cases = [c for c in cases if c["name"] in args.cases]
    results = []
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [pool.submit(resynth_one, c, v) if args.resynth_only else
                   pool.submit(retime_one, c, v) if args.retime_only else pool.submit(run_one, c, v, args.force)
                   for c in cases for v in ("original", "optimized")]
        for future in as_completed(futures):
            results.append(future.result())
    results.sort(key=lambda x:(x["case"],x["variant"]))
    versions = {}
    for name, cmd in {"yosys":[str(TOOLS/'opt/yosys/bin/yosys'),'-V'], "opensta":[str(TOOLS/'opt/openroad/bin/sta'),'-version'], "verilator":['verilator','--version']}.items():
        p = subprocess.run(cmd, env=ENV, capture_output=True,text=True)
        versions[name] = (p.stdout+p.stderr).strip()
    summary = {"passed":all(r["status"]=="complete" for r in results), "tools":versions,
               "library_sha256":hashlib.sha256(LIB.read_bytes()).hexdigest(),
               "configuration":CONFIG,"configuration_sha256":CONFIG_HASH, "cases":results}
    (OUT / "summary.json").write_text(json.dumps(summary,indent=2)+"\n")
    return 0 if summary["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
