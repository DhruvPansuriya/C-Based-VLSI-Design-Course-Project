# Wrong decisions (audit)

Explanations by system: **tests_only** accepts any candidate that runs without a sanitizer finding, so functionally wrong but crash-free mutants are accepted. **regression_only** checks only outside the strict reading's region: it accepts changes inside that region and, where the generated region is narrower than the true fix, rejects P_ref itself (its witnesses are not replayed). Any **vwe** entry is listed individually and must be investigated.

Every ACCEPT of an incorrect candidate or REJECT of a correct one, per system. Each must be explained (bad label, reading miss, or tool/implementation bug). Wrong E0/E1 verdicts of the method are claimed impossible and fail the run.

- **tests_only** chrysalis_chstone_abs_use/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_chstone_abs_use/mut_delete_guard_0: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_chstone_abs_zero/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_init/mut_constant_1_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_init/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_init/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_init/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_use/mut_constant_1_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_use/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_use/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_filtep_use/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_init/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_init/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_init/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_init/mut_relational_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_init/unchanged: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_zero/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_zero/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_zero/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol1_zero/mut_relational_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_chstone_uppol1_zero/ref: REJECT - vs label correct - P1 differs from P0 outside the region (solver witness, not replayed)
- **tests_only** chrysalis_chstone_uppol1_zero/unchanged: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_chstone_uppol1_zero/unchanged: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_chstone_uppol2_shft/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_shft/mut_constantp1_6: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_shft/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_shft/mut_delete_guard_4: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_use/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_use/mut_constantp1_6: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_chstone_uppol2_use/mut_delete_guard_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_chstone_uppol2_use/mut_delete_guard_0: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_chstone_uppol2_use/mut_delete_guard_4: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_chstone_uppol2_use/mut_delete_guard_4: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_h_264_six_tab_init/mut_constant_1_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_init/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_init/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_init/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_mlu/mut_constant_1_1: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_mlu/mut_constant_1_3: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_mlu/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_h_264_six_tab_mlu/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_h_264_six_tab_mlu/ref: REJECT - vs label correct - P1 differs from P0 outside the region (solver witness, not replayed)
- **tests_only** chrysalis_h_264_six_tab_mlu/unchanged: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_h_264_six_tab_mlu/unchanged: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_machsuite_init_init/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_machsuite_init_init/mut_constantp1_0: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_machsuite_init_init/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **regression_only** chrysalis_machsuite_init_init/mut_constantp1_2: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **regression_only** chrysalis_machsuite_init_init/mut_relational_1: ACCEPT - vs label incorrect - P1 equals P0 outside the region
- **tests_only** chrysalis_machsuite_init_oob/mut_constantp1_0: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
- **tests_only** chrysalis_machsuite_init_oob/mut_constantp1_2: ACCEPT - vs label incorrect - sanitizer-clean on 1000 inputs
