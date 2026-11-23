# Measured HLS results

Bambu 2026.11 / Clang 16, BAMBU-BALANCED-MP (-O2), seed 0; Yosys 0.36; OpenSTA 2.0.18.
Nangate45 typical (1.1 V, 25 C), common 10 ns clock. Cell area includes the mapped accelerator; external host/memory is excluded.
Delay is 10 ns minus worst max-path slack: ideal clocks, zero input/output delays, 50 ps input transition, 10 fF output load, no extracted interconnect.
These are pre-layout synthesis estimates, not FPGA LUT counts or routed timing. 100/100 implementations meet the chosen clock in this model.

| Kernel | Area original → candidate (um²) | Delay original → candidate (ns) | Cycles original → candidate | ADP ratio | ADP choice |
|---|---:|---:|---:|---:|---|
| scale | 719.00 → 2122.15 | 1.304 → 1.427 | 26 → 26 | 2.952 | original |
| unswitch | 1125.98 → 1863.06 | 1.537 → 1.928 | 14 → 14 | 1.655 | original |
| gemm | 4506.57 → 4760.07 | 1.903 → 2.218 | 122 → 266 | 2.303 | original |
| stencil | 4493.01 → 6646.54 | 1.896 → 2.452 | 158 → 116 | 1.086 | original |
| prefix | 1857.48 → 913.18 | 1.901 → 1.510 | 62 → 26 | 0.2062 | optimized |
| fir | 5558.07 → 5092.57 | 3.182 → 3.209 | 5 → 5 | 0.9162 | optimized |
| boxfilter | 1135.82 → 9712.99 | 1.559 → 5.976 | 158 → 87 | 4.709 | original |
| factor | 3412.25 → 3412.25 | 2.696 → 2.696 | 1 → 1 | 1 | original |
| dot16 | 3993.72 → 8760.71 | 2.004 → 2.967 | 19 → 19 | 2.194 | original |
| sum32 | 572.96 → 3992.39 | 1.455 → 3.890 | 35 → 19 | 3.783 | original |
| xor32 | 439.17 → 2488.96 | 1.129 → 3.206 | 35 → 19 | 3.077 | original |
| min8 | 803.05 → 4145.08 | 1.394 → 2.802 | 11 → 5 | 2.346 | original |
| max8 | 779.91 → 4228.07 | 0.972 → 2.915 | 11 → 5 | 2.464 | original |
| range8 | 1822.63 → 1341.17 | 1.744 → 1.457 | 11 → 11 | 0.7358 | optimized |
| count_nonzero16 | 437.30 → 3587.81 | 1.414 → 4.400 | 19 → 11 | 4.75 | original |
| all_equal16 | 471.09 → 669.26 | 0.696 → 0.767 | 19 → 19 | 1.421 | original |
| parity32 | 130.34 → 50.01 | 0.545 → 0.276 | 34 → 1 | 0.01128 | optimized |
| popcount8 | 329.31 → 29.26 | 0.747 → 0.255 | 10 → 1 | 0.008885 | optimized |
| bitreverse32 | 515.51 → 0.53 | 0.689 → 0.054 | 34 → 1 | 3.035e-05 | optimized |
| byteswap32 | 308.83 → 0.53 | 0.498 → 0.054 | 6 → 1 | 0.0002871 | optimized |
| crc8_byte | 119.43 → 119.97 | 0.323 → 0.323 | 10 → 6 | 0.6027 | optimized |
| hamming8 | 628.29 → 567.64 | 1.089 → 1.112 | 90 → 11 | 0.1104 | optimized |
| clamp16 | 619.78 → 619.78 | 1.323 → 1.323 | 50 → 50 | 1 | original |
| threshold_pack8 | 250.84 → 326.65 | 1.062 → 1.009 | 11 → 7 | 0.8287 | optimized |
| absdiff16 | 1261.64 → 1258.18 | 1.402 → 1.578 | 50 → 50 | 0.9973 | optimized |
| squared_distance8 | 3889.98 → 10618.99 | 2.834 → 1.961 | 11 → 11 | 2.73 | original |
| saxpy16 | 4469.86 → 6051.50 | 1.924 → 2.018 | 50 → 50 | 1.354 | original |
| quadratic | 6971.59 → 6971.59 | 3.454 → 3.454 | 1 → 1 | 1 | original |
| convolution1d8 | 2310.48 → 2125.07 | 2.125 → 1.722 | 26 → 26 | 0.9198 | optimized |
| moving_sum16 | 978.08 → 3338.57 | 1.541 → 1.973 | 93 → 41 | 1.505 | original |
| triangular_fir16 | 1958.03 → 1510.61 | 1.685 → 2.214 | 58 → 45 | 0.5986 | optimized |
| gaussian5 | 1800.82 → 8919.25 | 2.229 → 5.689 | 158 → 102 | 3.197 | original |
| integral_image4 | 3076.02 → 3029.21 | 2.337 → 2.786 | 262 → 102 | 0.3834 | optimized |
| transpose4 | 804.65 → 1390.38 | 1.490 → 1.380 | 58 → 34 | 1.013 | original |
| matvec4 | 4250.95 → 11156.04 | 1.945 → 5.074 | 30 → 26 | 2.274 | original |
| gemm_local4 | 4506.57 → 11236.90 | 1.903 → 6.758 | 122 → 66 | 1.349 | original |
| syrk4 | 4528.92 → 4692.51 | 1.895 → 1.976 | 122 → 86 | 0.7304 | optimized |
| rank1_update4 | 5331.44 → 8667.34 | 2.351 → 3.504 | 74 → 54 | 1.186 | original |
| triangular_matvec4 | 4971.01 → 5360.96 | 2.386 → 2.029 | 62 → 24 | 0.4175 | optimized |
| symv4 | 4248.55 → 7941.96 | 1.855 → 8.508 | 30 → 78 | 4.86 | original |
| matrix_trace4 | 850.93 → 544.50 | 1.362 → 1.429 | 50 → 7 | 0.08958 | optimized |
| matrix_diagsum4 | 865.83 → 806.78 | 1.374 → 1.611 | 58 → 7 | 0.1125 | optimized |
| histogram4 | 833.11 → 2279.09 | 1.302 → 1.538 | 78 → 21 | 0.7365 | optimized |
| search_count16 | 490.50 → 1427.89 | 1.291 → 2.053 | 19 → 11 | 1.685 | original |
| reverse_copy16 | 784.70 → 1412.73 | 1.327 → 1.791 | 50 → 34 | 1.224 | original |
| deinterleave16 | 1166.94 → 1426.82 | 1.691 → 2.048 | 50 → 34 | 0.8314 | optimized |
| interleave8 | 1284.51 → 1426.29 | 1.308 → 1.958 | 50 → 50 | 1.11 | original |
| maxpool4 | 1074.64 → 2170.29 | 1.387 → 2.606 | 48 → 20 | 0.8415 | optimized |
| moving_sum_register16 | 978.08 → 4111.03 | 1.541 → 1.899 | 93 → 41 | 1.853 | original |
| gemm_tile2 | 4506.57 → 5770.60 | 1.903 → 3.858 | 122 → 94 | 0.9866 | optimized |

ADP = mapped area × cycles × 10 ns; a ratio below 1 is better. The choice is objective-specific: a latency-first objective can choose stencil or boxfilter despite their area cost.
All 50 candidates are formally equivalent; correctness alone does not establish hardware benefit. Related kernels are grouped in the catalog; this is not a claim of 50 independent applications. Seeded mutants are excluded from QoR acceptance.

Evidence: 13200 compiled-C candidate tests, 50 compiled witness replays, 1600 RTL calls, and 100 formal verdicts.

Raw logs, RTL, mapped netlists, constraints, exact commands, source hashes and timing-coverage audits are retained under `results/hls/`. Reported unconstrained endpoints were checked against mapped-netlist constants; no nonconstant endpoint was silently ignored.
