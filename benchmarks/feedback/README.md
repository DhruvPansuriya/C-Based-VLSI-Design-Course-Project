# Two feedback-driven follow-ups

These pairs reuse the existing moving_sum16 and GEMM original references.
They extend the study from 48 to 50 pairs / 100 implementations, while the
number of distinct original C ASTs remains 47. They are additional candidates,
not additional independent algorithms.

The register-window sum follows an earlier area-regressing sliding recurrence.
The two-column GEMM tile follows the four-accumulator candidate, testing a
different area/latency balance. Both earlier candidates and all raw evidence
are retained. Outcomes are measured, not assumed. GEMM's MachSuite license is
preserved as LICENSE.MachSuite; dimensions and uint32_t adaptations remain the
same. Faulty versions are explicitly seeded one-bit output mutations.
