// 
// Politecnico di Milano
// Code created using PandA - Version: PandA 2026.11 - Revision 6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda - Date 2026-11-21T19:14:38
// Bambu executed with: '/home/ak05/cs5291_hls_tools/squashfs-root/usr/bin/bambu' '--top-fname=kernel' '--device-name=nangate45' '--clock-period=10' '--compiler=I386_CLANG16' '--experimental-setup=BAMBU-BALANCED-MP' '--seed=0' '--generate-tb=/home/ak05/cs5291_hls_runs/bitreverse32_optimized/tb.c' '--simulate' '--simulator=VERILATOR' '/home/ak05/cs5291_hls_runs/bitreverse32_optimized/kernel.c'
// 
// Send any bug to: panda-info@polimi.it
// ************************************************************************
// The following text holds for all the components tagged with MIT.
// They are all part of the PandA/Bambu IP LIBRARY.
// Copyright (C) 2004-2026 Politecnico di Milano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the \"Software\"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ************************************************************************


`ifndef _SIM_HAVE_CLOG2
`ifdef __ICARUS__
  `define _SIM_HAVE_CLOG2
`endif
`ifdef VERILATOR
  `define _SIM_HAVE_CLOG2
`endif
`ifdef MODEL_TECH
  `define _SIM_HAVE_CLOG2
`endif
`ifdef VCS
  `define _SIM_HAVE_CLOG2
`endif
`ifdef NCVERILOG
  `define _SIM_HAVE_CLOG2
`endif
`ifdef XILINX_SIMULATOR
  `define _SIM_HAVE_CLOG2
`endif
`ifdef XILINX_ISIM
  `define _SIM_HAVE_CLOG2
`endif
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2022-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _llvm_bitreverse_i32_FU_DEFINED
`define _llvm_bitreverse_i32_FU_DEFINED
`timescale 1ns / 1ps
module llvm_bitreverse_i32_FU(in1,
  out1);
  parameter BITSIZE_out1=32;
  // IN
  input [31:0] in1;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  
  reg [31:0] x;
  integer i;
  always @(*)
  begin
    for (i=0; i < 32; i=i+1)
    begin
       x[i] = in1[31-i];
    end
  end
  assign out1 = x;

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_bitcast_node_FU_DEFINED
`define _ui_bitcast_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_bitcast_node_FU(in1,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_out1=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  assign out1 = in1;
endmodule
`endif


