# Expanded fixed-size unsigned HLS study

Forty additional original/candidate pairs bring the study to 48 pairs and 96
synthesized implementations. These are educational kernels authored by the
Codex assistant, not untouched standard-suite programs or 48 independent
applications. Related min/max, reduction, matrix and data-movement variants
are grouped in the experiment catalog. No new downloaded dataset is implied.

The gemm_local4 reference reuses the documented reduced unsigned MachSuite GEMM
adaptation. Its upstream BSD-style license is retained as LICENSE.MachSuite;
this is a second candidate for the same original algorithm as the earlier GEMM
pair, and is not counted as a new independent upstream benchmark.

Every pair preserves the signature, fixed dimensions, final parameter arrays
and uint32_t modulo arithmetic. Arrays are valid and disjoint. The *_buggy.c
files deliberately flip one output bit to test rejection and witness replay;
they do not represent spontaneous LLM faults. Actual benefits are determined
by the common synthesis configuration, with unchanged and regressing cases
retained. Full source and transformation records are generated under
experiments/optimizations/ after measurement.
