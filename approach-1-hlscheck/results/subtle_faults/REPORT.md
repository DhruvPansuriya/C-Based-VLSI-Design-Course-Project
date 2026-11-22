# Controlled subtle-fault study

**These are deliberately injected faults and constructed semantic controls, not spontaneous LLM mistakes.** The real local-model mistakes are reported separately in [the local-model experiment](../local_llm/REPORT.md).

The suite contains 50 token-scale edits to already-proved candidates, four additional semantic pitfalls, 20 changed-code equivalent controls and six undefined-C controls. Expected labels are declared in the manifest before any verification. The 50 local edits retain the original algorithm and alter an index, bound, mask, coefficient, operation or recurrence; none simply flips the final result bit.

| Category | Expected | Observed |
|---|---:|---:|
| Safe non-equivalent | 54 | 54 |
| Equivalent semantic edits | 20 | 20 |
| Undefined candidate C | 6 | 6 |

All 80/80 expected categories matched. Every safe mismatch has a saved solver counterexample and compiled-C replay with exact solver/native output agreement. All available SMT replays passed, including accepted lemma dependencies. Undefined-C examples were not executed natively.

The equivalent controls matter: changing `<` to `<=` in a minimum expression still returns the same value on ties. Reassociation, unsigned modular subtraction identities and valid strength reductions must also remain accepted. A detector that rejects every syntactic edit would fail these controls.

Five faulty programs escaped all 264 conventional differential test inputs (eight fixed edge patterns and 256 deterministic random trials). SMT found and native C reproduced a counterexample for each:

| Case | Small error | Evidence |
|---|---|---|
| all_equal16 | differences cancel under XOR | [Witness and native replay](all_equal16/evaluation.json) |
| clamp16 | clamp activates one bit too early | [Witness and native replay](clamp16/evaluation.json) |
| threshold_pack8 | rare equality boundary | [Witness and native replay](threshold_pack8/evaluation.json) |
| search_count16 | odd lane duplicates even comparison | [Witness and native replay](search_count16/evaluation.json) |
| fault_rare_magic | rare special-case exception | [Witness and native replay](fault_rare_magic/evaluation.json) |

This is a demonstration on this particular test set, not a universal comparison with all possible directed testing. For example, explicitly testing threshold 128 would expose its equality-boundary fault.

## Reproduce

```powershell
.\.venv\Scripts\python.exe run_subtle_fault_study.py
```

Sources, rationale, expected labels, hashes and exact diffs are in `experiments/subtle_faults/manifest.json` and each case directory. Raw proofs and native logs are retained below this report.

| Case | Expected | Observed | Native witness |
|---|---|---|---|
| [scale](scale/evaluation.json) | not_equivalent | not_equivalent | True |
| [unswitch](unswitch/evaluation.json) | not_equivalent | not_equivalent | True |
| [gemm](gemm/evaluation.json) | not_equivalent | not_equivalent | True |
| [stencil](stencil/evaluation.json) | not_equivalent | not_equivalent | True |
| [prefix](prefix/evaluation.json) | not_equivalent | not_equivalent | True |
| [fir](fir/evaluation.json) | not_equivalent | not_equivalent | True |
| [boxfilter](boxfilter/evaluation.json) | not_equivalent | not_equivalent | True |
| [factor](factor/evaluation.json) | not_equivalent | not_equivalent | True |
| [dot16](dot16/evaluation.json) | not_equivalent | not_equivalent | True |
| [sum32](sum32/evaluation.json) | not_equivalent | not_equivalent | True |
| [xor32](xor32/evaluation.json) | not_equivalent | not_equivalent | True |
| [min8](min8/evaluation.json) | not_equivalent | not_equivalent | True |
| [max8](max8/evaluation.json) | not_equivalent | not_equivalent | True |
| [range8](range8/evaluation.json) | not_equivalent | not_equivalent | True |
| [count_nonzero16](count_nonzero16/evaluation.json) | not_equivalent | not_equivalent | True |
| [all_equal16](all_equal16/evaluation.json) | not_equivalent | not_equivalent | True |
| [parity32](parity32/evaluation.json) | not_equivalent | not_equivalent | True |
| [popcount8](popcount8/evaluation.json) | not_equivalent | not_equivalent | True |
| [bitreverse32](bitreverse32/evaluation.json) | not_equivalent | not_equivalent | True |
| [byteswap32](byteswap32/evaluation.json) | not_equivalent | not_equivalent | True |
| [crc8_byte](crc8_byte/evaluation.json) | not_equivalent | not_equivalent | True |
| [hamming8](hamming8/evaluation.json) | not_equivalent | not_equivalent | True |
| [clamp16](clamp16/evaluation.json) | not_equivalent | not_equivalent | True |
| [threshold_pack8](threshold_pack8/evaluation.json) | not_equivalent | not_equivalent | True |
| [absdiff16](absdiff16/evaluation.json) | not_equivalent | not_equivalent | True |
| [squared_distance8](squared_distance8/evaluation.json) | not_equivalent | not_equivalent | True |
| [saxpy16](saxpy16/evaluation.json) | not_equivalent | not_equivalent | True |
| [quadratic](quadratic/evaluation.json) | not_equivalent | not_equivalent | True |
| [convolution1d8](convolution1d8/evaluation.json) | not_equivalent | not_equivalent | True |
| [moving_sum16](moving_sum16/evaluation.json) | not_equivalent | not_equivalent | True |
| [triangular_fir16](triangular_fir16/evaluation.json) | not_equivalent | not_equivalent | True |
| [gaussian5](gaussian5/evaluation.json) | not_equivalent | not_equivalent | True |
| [integral_image4](integral_image4/evaluation.json) | not_equivalent | not_equivalent | True |
| [transpose4](transpose4/evaluation.json) | not_equivalent | not_equivalent | True |
| [matvec4](matvec4/evaluation.json) | not_equivalent | not_equivalent | True |
| [gemm_local4](gemm_local4/evaluation.json) | not_equivalent | not_equivalent | True |
| [syrk4](syrk4/evaluation.json) | not_equivalent | not_equivalent | True |
| [rank1_update4](rank1_update4/evaluation.json) | not_equivalent | not_equivalent | True |
| [triangular_matvec4](triangular_matvec4/evaluation.json) | not_equivalent | not_equivalent | True |
| [symv4](symv4/evaluation.json) | not_equivalent | not_equivalent | True |
| [matrix_trace4](matrix_trace4/evaluation.json) | not_equivalent | not_equivalent | True |
| [matrix_diagsum4](matrix_diagsum4/evaluation.json) | not_equivalent | not_equivalent | True |
| [histogram4](histogram4/evaluation.json) | not_equivalent | not_equivalent | True |
| [search_count16](search_count16/evaluation.json) | not_equivalent | not_equivalent | True |
| [reverse_copy16](reverse_copy16/evaluation.json) | not_equivalent | not_equivalent | True |
| [deinterleave16](deinterleave16/evaluation.json) | not_equivalent | not_equivalent | True |
| [interleave8](interleave8/evaluation.json) | not_equivalent | not_equivalent | True |
| [maxpool4](maxpool4/evaluation.json) | not_equivalent | not_equivalent | True |
| [moving_sum_register16](moving_sum_register16/evaluation.json) | not_equivalent | not_equivalent | True |
| [gemm_tile2](gemm_tile2/evaluation.json) | not_equivalent | not_equivalent | True |
| [eq_min_tie](eq_min_tie/evaluation.json) | equivalent | equivalent | None |
| [eq_max_tie](eq_max_tie/evaluation.json) | equivalent | equivalent | None |
| [eq_clamp_tie](eq_clamp_tie/evaluation.json) | equivalent | equivalent | None |
| [eq_strength_multiply](eq_strength_multiply/evaluation.json) | equivalent | equivalent | None |
| [eq_unsigned_divide](eq_unsigned_divide/evaluation.json) | equivalent | equivalent | None |
| [eq_unsigned_remainder](eq_unsigned_remainder/evaluation.json) | equivalent | equivalent | None |
| [eq_modular_subtract](eq_modular_subtract/evaluation.json) | equivalent | equivalent | None |
| [eq_xor_cancel](eq_xor_cancel/evaluation.json) | equivalent | equivalent | None |
| [eq_mask_partition](eq_mask_partition/evaluation.json) | equivalent | equivalent | None |
| [eq_threshold_adjacent](eq_threshold_adjacent/evaluation.json) | equivalent | equivalent | None |
| [eq_zero_predicate](eq_zero_predicate/evaluation.json) | equivalent | equivalent | None |
| [eq_distributivity](eq_distributivity/evaluation.json) | equivalent | equivalent | None |
| [eq_reassociate](eq_reassociate/evaluation.json) | equivalent | equivalent | None |
| [eq_rotate](eq_rotate/evaluation.json) | equivalent | equivalent | None |
| [eq_unsigned_double_not](eq_unsigned_double_not/evaluation.json) | equivalent | equivalent | None |
| [eq_max_operand_order](eq_max_operand_order/evaluation.json) | equivalent | equivalent | None |
| [eq_absdiff_operands](eq_absdiff_operands/evaluation.json) | equivalent | equivalent | None |
| [eq_demorgan](eq_demorgan/evaluation.json) | equivalent | equivalent | None |
| [eq_shift_mask](eq_shift_mask/evaluation.json) | equivalent | equivalent | None |
| [eq_guard_division](eq_guard_division/evaluation.json) | equivalent | equivalent | None |
| [fault_average_overflow](fault_average_overflow/evaluation.json) | not_equivalent | not_equivalent | True |
| [fault_rare_magic](fault_rare_magic/evaluation.json) | not_equivalent | not_equivalent | True |
| [fault_rounding_bias](fault_rounding_bias/evaluation.json) | not_equivalent | not_equivalent | True |
| [fault_unsigned_absdiff](fault_unsigned_absdiff/evaluation.json) | not_equivalent | not_equivalent | True |
| [ub_shift_32](ub_shift_32/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
| [ub_shift_input](ub_shift_input/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
| [ub_division_zero](ub_division_zero/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
| [ub_hoisted_division](ub_hoisted_division/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
| [ub_read_oob](ub_read_oob/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
| [ub_write_oob](ub_write_oob/evaluation.json) | candidate_undefined | candidate_undefined | not executed |
