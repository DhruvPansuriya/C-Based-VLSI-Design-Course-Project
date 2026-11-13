read_liberty cells.lib
read_verilog mapped.v
link_design kernel
create_clock -name core_clock -period 10 [get_ports clock]
set data_inputs [lsearch -all -inline -not -exact [all_inputs] [lindex [get_ports clock] 0]]
set_input_delay 0 -clock core_clock $data_inputs
set_output_delay 0 -clock core_clock [all_outputs]
set_input_transition 0.05 [all_inputs]
set_load 10 [all_outputs]
check_setup -verbose
report_checks -path_delay max -group_count 1 -endpoint_count 1 -digits 6
report_worst_slack -digits 6
exit
