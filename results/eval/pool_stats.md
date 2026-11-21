# Candidate pools and labels

Labels: formal identity check against P_ref (VWE pipeline) combined with native
sanitizer differential testing; see `vwe/eval/labels.py` for the rule and its limits.
Pools contain P_ref, unchanged P0 and deterministic P_ref mutants. **No LLM-generated
candidates**: no live provider was configured.

| task | candidates | correct | incorrect | unknown | flags |
|---|---|---|---|---|---|
| chrysalis_chstone_abs_use | 5 | 4 | 1 | 0 |  |
| chrysalis_chstone_abs_zero | 5 | 4 | 1 | 0 |  |
| chrysalis_chstone_filtep_init | 6 | 0 | 4 | 2 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_chstone_filtep_use | 6 | 0 | 4 | 2 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_chstone_uppol1_init | 6 | 1 | 5 | 0 |  |
| chrysalis_chstone_uppol1_zero | 6 | 1 | 5 | 0 |  |
| chrysalis_chstone_uppol2_shft | 6 | 1 | 5 | 0 |  |
| chrysalis_chstone_uppol2_use | 6 | 2 | 4 | 0 |  |
| chrysalis_gnn_builder_gather_node_neighbors_and_edge_indices_inf | 4 | 0 | 4 | 0 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_gnn_builder_gather_node_neighbors_and_edge_indices_oob | 3 | 0 | 3 | 0 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_gnn_builder_gather_node_neighbors_inf | 4 | 0 | 4 | 0 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_gnn_builder_gather_node_neighbors_mlu | 3 | 0 | 3 | 0 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_h_264_inverserasterscan_oob | 6 | 0 | 4 | 2 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_h_264_inverserasterscan_zero | 6 | 0 | 4 | 2 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_h_264_six_tab_init | 6 | 2 | 4 | 0 |  |
| chrysalis_h_264_six_tab_mlu | 6 | 1 | 5 | 0 |  |
| chrysalis_machsuite_init_init | 5 | 2 | 3 | 0 |  |
| chrysalis_machsuite_init_oob | 4 | 1 | 3 | 0 |  |
| chrysalis_vitis_hls_introductory_examples_foo_use | 2 | 2 | 0 | 0 | task lacks a correct or an incorrect labelled candidate |
| chrysalis_vitis_hls_introductory_examples_foo_zero | 2 | 2 | 0 | 0 | task lacks a correct or an incorrect labelled candidate |

Totals over 20 tasks: 97 candidates, 23 correct, 66 incorrect, 8 unknown (unknown labels are excluded from metrics and reported).
