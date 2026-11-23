# File-to-file HLSCheck pipeline

Original: `C:\Users\ARYAN\Desktop\7th Semester\C-Based VLSI Design\Course_Project\benchmarks\pipeline_smoke\u64_original.c`
Candidate: `C:\Users\ARYAN\Desktop\7th Semester\C-Based VLSI Design\Course_Project\benchmarks\pipeline_smoke\u64_optimized.c`

Equivalence: **equivalent**.
Native comparisons: 264 passed. RTL transactions: 32 passed.

| Metric | Original | Optimized | Improvement |
| --- | ---: | ---: | ---: |
| Cell area (um^2) | 0.532 | 0.532 | +0.00% |
| Execution latency (cycles) | 1 | 1 | +0.00% |
| Execution latency at 10 ns (ns) | 10 | 10 | +0.00% |
| Critical-path delay (ns) | 0.054166 | 0.054166 | +0.00% |
| Area x execution latency | 5.32 | 5.32 | +0.00% |

Improvement (%) = 100 x (original - optimized) / original; positive is better.

Area x execution latency outcome: **unchanged**.

Mapped pre-layout Nangate45 ASIC estimates; no routed timing, FPGA or formal C-to-RTL claim

The .cpp extension uses C-compatible C11 semantics. HLS sources preserve the supplied code/pragmas; only a non-kernel top declarator is renamed and certified when needed.

See console.log, proof/, evidence_replay.json, native/, hls_inputs/, and hls/ for the complete evidence.
