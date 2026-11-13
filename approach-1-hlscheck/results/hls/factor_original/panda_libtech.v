// 
// Politecnico di Milano
// Code created using PandA - Version: PandA 2026.11 - Revision 6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda - Date 2026-11-21T18:46:25
// Bambu executed with: '/home/ak05/cs5291_hls_tools/squashfs-root/usr/bin/bambu' '--top-fname=kernel' '--device-name=nangate45' '--clock-period=10' '--compiler=I386_CLANG16' '--experimental-setup=BAMBU-BALANCED-MP' '--seed=0' '--generate-tb=/home/ak05/cs5291_hls_runs/factor_original/tb.c' '--simulate' '--simulator=VERILATOR' '/home/ak05/cs5291_hls_runs/factor_original/kernel.c'
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
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_add_node_FU_DEFINED
`define _ui_add_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_add_node_FU(in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  assign out1 = in1 + in2;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_mul_node_FU_DEFINED
`define _ui_mul_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_mul_node_FU(clock,
  stall_port,
  in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1,
    PIPE_PARAMETER=0;
  // IN
  input clock;
  input stall_port;
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  generate
    if (PIPE_PARAMETER==0)
    begin
      assign out1 = in1 * in2;
    end
    else if (PIPE_PARAMETER==1)
    begin
      reg [BITSIZE_out1-1:0] product_reg;
      assign out1 = product_reg;
      always @(posedge clock)
      begin
        if (stall_port == 1'b0)
          product_reg <= in1 * in2;
      end
    end
    else if (PIPE_PARAMETER>1)
    begin
      reg [BITSIZE_out1-1:0] product_pipe [PIPE_PARAMETER-1:0];
      integer i;
      assign out1 = product_pipe[0];
      always @(posedge clock)
      begin
        if (stall_port == 1'b0)
        begin
          product_pipe[PIPE_PARAMETER-1] <= in1 * in2;
          for (i=0; i<PIPE_PARAMETER-1; i=i+1)
            product_pipe[i] <= product_pipe[i+1];
        end
      end
    end
  endgenerate
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


