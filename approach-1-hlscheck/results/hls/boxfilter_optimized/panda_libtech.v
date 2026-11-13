// 
// Politecnico di Milano
// Code created using PandA - Version: PandA 2026.11 - Revision 6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda - Date 2026-11-21T18:46:11
// Bambu executed with: '/home/ak05/cs5291_hls_tools/squashfs-root/usr/bin/bambu' '--top-fname=kernel' '--device-name=nangate45' '--clock-period=10' '--compiler=I386_CLANG16' '--experimental-setup=BAMBU-BALANCED-MP' '--seed=0' '--generate-tb=/home/ak05/cs5291_hls_runs/boxfilter_optimized/tb.c' '--simulate' '--simulator=VERILATOR' '/home/ak05/cs5291_hls_runs/boxfilter_optimized/kernel.c'
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
`ifndef _register_SE_DEFINED
`define _register_SE_DEFINED
`timescale 1ns / 1ps
module register_SE(clock,
  reset,
  in1,
  wenable,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_out1=1;
  // IN
  input clock;
  input reset;
  input [BITSIZE_in1-1:0] in1;
  input wenable;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  
  reg [BITSIZE_out1-1:0] reg_out1 =0;
  assign out1 = reg_out1;
  always @(posedge clock)
    if (wenable)
      reg_out1 <= in1;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ADDRESS_DECODING_LOGIC_NN_DEFINED
`define _ADDRESS_DECODING_LOGIC_NN_DEFINED
`timescale 1ns / 1ps
module ADDRESS_DECODING_LOGIC_NN(clock,
  reset,
  in1,
  in2,
  in3,
  out1,
  sel_LOAD,
  sel_STORE,
  S_oe_ram,
  S_we_ram,
  S_addr_ram,
  S_Wdata_ram,
  Sin_Rdata_ram,
  Sout_Rdata_ram,
  S_data_ram_size,
  Sin_DataRdy,
  Sout_DataRdy,
  proxy_in1,
  proxy_in2,
  proxy_in3,
  proxy_sel_LOAD,
  proxy_sel_STORE,
  proxy_out1,
  dout_a,
  dout_b,
  memory_addr_a,
  memory_addr_b,
  din_value_aggregated_swapped,
  be_swapped,
  bram_write);
  parameter BITSIZE_in1=1, PORTSIZE_in1=1,
    BITSIZE_in2=1, PORTSIZE_in2=1,
    BITSIZE_in3=1, PORTSIZE_in3=1,
    BITSIZE_sel_LOAD=1, PORTSIZE_sel_LOAD=1,
    BITSIZE_sel_STORE=1, PORTSIZE_sel_STORE=1,
    BITSIZE_out1=1, PORTSIZE_out1=1,
    BITSIZE_S_oe_ram=1, PORTSIZE_S_oe_ram=1,
    BITSIZE_S_we_ram=1, PORTSIZE_S_we_ram=1,
    BITSIZE_Sin_DataRdy=1, PORTSIZE_Sin_DataRdy=1,
    BITSIZE_Sout_DataRdy=1, PORTSIZE_Sout_DataRdy=1,
    BITSIZE_S_addr_ram=1, PORTSIZE_S_addr_ram=1,
    BITSIZE_S_Wdata_ram=8, PORTSIZE_S_Wdata_ram=1,
    BITSIZE_Sin_Rdata_ram=8, PORTSIZE_Sin_Rdata_ram=1,
    BITSIZE_Sout_Rdata_ram=8, PORTSIZE_Sout_Rdata_ram=1,
    BITSIZE_S_data_ram_size=1, PORTSIZE_S_data_ram_size=1,
    address_space_begin=0,
    address_space_rangesize=4,
    BUS_PIPELINED=1,
    BRAM_BITSIZE=32,
    PRIVATE_MEMORY=0,
    READ_ONLY_MEMORY=0,
    USE_SPARSE_MEMORY=1,
    HIGH_LATENCY=0,
    BITSIZE_proxy_in1=1, PORTSIZE_proxy_in1=1,
    BITSIZE_proxy_in2=1, PORTSIZE_proxy_in2=1,
    BITSIZE_proxy_in3=1, PORTSIZE_proxy_in3=1,
    BITSIZE_proxy_sel_LOAD=1, PORTSIZE_proxy_sel_LOAD=1,
    BITSIZE_proxy_sel_STORE=1, PORTSIZE_proxy_sel_STORE=1,
    BITSIZE_proxy_out1=1, PORTSIZE_proxy_out1=1,
    BITSIZE_dout_a=1, PORTSIZE_dout_a=1,
    BITSIZE_dout_b=1, PORTSIZE_dout_b=1,
    BITSIZE_memory_addr_a=1, PORTSIZE_memory_addr_a=1,
    BITSIZE_memory_addr_b=1, PORTSIZE_memory_addr_b=1,
    BITSIZE_din_value_aggregated_swapped=1, PORTSIZE_din_value_aggregated_swapped=1,
    BITSIZE_be_swapped=1, PORTSIZE_be_swapped=1,
    BITSIZE_bram_write=1, PORTSIZE_bram_write=1,
    nbit_read_addr=32,
    n_byte_on_databus=4,
    n_elements=4,
    max_n_reads=2,
    max_n_writes=2,
    max_n_rw=2;
  // IN
  input clock;
  input reset;
  input [(PORTSIZE_in1*BITSIZE_in1)+(-1):0] in1;
  input [(PORTSIZE_in2*BITSIZE_in2)+(-1):0] in2;
  input [(PORTSIZE_in3*BITSIZE_in3)+(-1):0] in3;
  input [PORTSIZE_sel_LOAD-1:0] sel_LOAD;
  input [PORTSIZE_sel_STORE-1:0] sel_STORE;
  input [PORTSIZE_S_oe_ram-1:0] S_oe_ram;
  input [PORTSIZE_S_we_ram-1:0] S_we_ram;
  input [(PORTSIZE_S_addr_ram*BITSIZE_S_addr_ram)+(-1):0] S_addr_ram;
  input [(PORTSIZE_S_Wdata_ram*BITSIZE_S_Wdata_ram)+(-1):0] S_Wdata_ram;
  input [(PORTSIZE_Sin_Rdata_ram*BITSIZE_Sin_Rdata_ram)+(-1):0] Sin_Rdata_ram;
  input [(PORTSIZE_S_data_ram_size*BITSIZE_S_data_ram_size)+(-1):0] S_data_ram_size;
  input [PORTSIZE_Sin_DataRdy-1:0] Sin_DataRdy;
  input [(PORTSIZE_proxy_in1*BITSIZE_proxy_in1)+(-1):0] proxy_in1;
  input [(PORTSIZE_proxy_in2*BITSIZE_proxy_in2)+(-1):0] proxy_in2;
  input [(PORTSIZE_proxy_in3*BITSIZE_proxy_in3)+(-1):0] proxy_in3;
  input [PORTSIZE_proxy_sel_LOAD-1:0] proxy_sel_LOAD;
  input [PORTSIZE_proxy_sel_STORE-1:0] proxy_sel_STORE;
  input [(PORTSIZE_dout_a*BITSIZE_dout_a)+(-1):0] dout_a;
  input [(PORTSIZE_dout_b*BITSIZE_dout_b)+(-1):0] dout_b;
  // OUT
  output [(PORTSIZE_out1*BITSIZE_out1)+(-1):0] out1;
  output [(PORTSIZE_Sout_Rdata_ram*BITSIZE_Sout_Rdata_ram)+(-1):0] Sout_Rdata_ram;
  output [PORTSIZE_Sout_DataRdy-1:0] Sout_DataRdy;
  output [(PORTSIZE_proxy_out1*BITSIZE_proxy_out1)+(-1):0] proxy_out1;
  output [(PORTSIZE_memory_addr_a*BITSIZE_memory_addr_a)+(-1):0] memory_addr_a;
  output [(PORTSIZE_memory_addr_b*BITSIZE_memory_addr_b)+(-1):0] memory_addr_b;
  output [(PORTSIZE_din_value_aggregated_swapped*BITSIZE_din_value_aggregated_swapped)+(-1):0] din_value_aggregated_swapped;
  output [(PORTSIZE_be_swapped*BITSIZE_be_swapped)+(-1):0] be_swapped;
  output [PORTSIZE_bram_write-1:0] bram_write;
  `ifndef _SIM_HAVE_CLOG2
    function integer log2;
       input integer value;
       integer temp_value;
      begin
        temp_value = value-1;
        for (log2=0; temp_value>0; log2=log2+1)
          temp_value = temp_value>>1;
      end
    endfunction
  `endif
  `ifdef _SIM_HAVE_CLOG2
    localparam nbit_addr = BITSIZE_S_addr_ram/*n_bytes ==  1 ? 1 : $clog2(n_bytes)*/;
    localparam nbits_byte_offset = n_byte_on_databus==1 ? 1 : $clog2(n_byte_on_databus);
    localparam nbits_address_space_rangesize = $clog2(address_space_rangesize);
  `else
    localparam nbit_addr = BITSIZE_S_addr_ram/*n_bytes ==  1 ? 1 : log2(n_bytes)*/;
    localparam nbits_address_space_rangesize = log2(address_space_rangesize);
    localparam nbits_byte_offset = n_byte_on_databus==1 ? 1 : log2(n_byte_on_databus);
  `endif
   localparam memory_bitsize = 2*BRAM_BITSIZE;
  
  function [n_byte_on_databus*max_n_writes-1:0] CONV;
    input [n_byte_on_databus*max_n_writes-1:0] po2;
  begin
    case (po2)
      1:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<1)-1;
      2:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<2)-1;
      4:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<4)-1;
      8:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<8)-1;
      16:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<16)-1;
      32:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<32)-1;
      64:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<64)-1;
      128:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<128)-1;
      256:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<256)-1;
      512:CONV=({{n_byte_on_databus*2-1{1'b0}},1'b1}<<512)-1;
      default:CONV=-1;
    endcase
  end
  endfunction
  
  wire [(PORTSIZE_in2*BITSIZE_in2)+(-1):0] tmp_addr;
  wire [n_byte_on_databus*max_n_writes-1:0] conv_in;
  wire [n_byte_on_databus*max_n_writes-1:0] conv_out;
  wire [PORTSIZE_S_addr_ram-1:0] cs;
  wire [PORTSIZE_S_oe_ram-1:0] oe_ram_cs;
  wire [PORTSIZE_S_we_ram-1:0] we_ram_cs;
  wire [nbit_addr*max_n_rw-1:0] relative_addr;
  wire [memory_bitsize*max_n_writes-1:0] din_value_aggregated;
  wire [memory_bitsize*PORTSIZE_S_Wdata_ram-1:0] S_Wdata_ram_int;
  wire [memory_bitsize*max_n_reads-1:0] out1_shifted;
  wire [memory_bitsize*max_n_reads-1:0] dout;
  wire [nbits_byte_offset*max_n_rw-1:0] byte_offset;
  wire [n_byte_on_databus*max_n_writes-1:0] be;
  
  reg [PORTSIZE_S_we_ram-1:0] we_ram_cs_delayed;
  reg [PORTSIZE_S_oe_ram-1:0] oe_ram_cs_delayed;
  reg [PORTSIZE_S_oe_ram-1:0] oe_ram_cs_delayed_registered;
  reg [PORTSIZE_S_oe_ram-1:0] oe_ram_cs_delayed_registered1;
  reg [max_n_reads-1:0] delayed_swapped_bit;
  reg [max_n_reads-1:0] delayed_swapped_bit_registered;
  reg [max_n_reads-1:0] delayed_swapped_bit_registered1;
  reg [nbits_byte_offset*max_n_reads-1:0] delayed_byte_offset;
  reg [nbits_byte_offset*max_n_reads-1:0] delayed_byte_offset_registered;
  reg [nbits_byte_offset*max_n_reads-1:0] delayed_byte_offset_registered1;
  
  generate
  genvar ind2;
  for (ind2=0; ind2<PORTSIZE_in2; ind2=ind2+1)
    begin : Lind2
      assign tmp_addr[(ind2+1)*BITSIZE_in2-1:ind2*BITSIZE_in2] = (proxy_sel_LOAD[ind2]||proxy_sel_STORE[ind2]) ? proxy_in2[(ind2+1)*BITSIZE_proxy_in2-1:ind2*BITSIZE_proxy_in2] : in2[(ind2+1)*BITSIZE_in2-1:ind2*BITSIZE_in2];
    end
  endgenerate
  
  generate
  genvar i2;
    for (i2=0;i2<max_n_reads;i2=i2+1)
    begin : L_copy
        assign dout[(memory_bitsize/2)+memory_bitsize*i2-1:memory_bitsize*i2] = delayed_swapped_bit[i2] ? dout_a[(memory_bitsize/2)*(i2+1)-1:(memory_bitsize/2)*i2] : dout_b[(memory_bitsize/2)*(i2+1)-1:(memory_bitsize/2)*i2];
        assign dout[memory_bitsize*(i2+1)-1:memory_bitsize*i2+(memory_bitsize/2)] = delayed_swapped_bit[i2] ? dout_b[(memory_bitsize/2)*(i2+1)-1:(memory_bitsize/2)*i2] : dout_a[(memory_bitsize/2)*(i2+1)-1:(memory_bitsize/2)*i2];
        always @(posedge clock)
        begin
          if(HIGH_LATENCY == 0)
            delayed_swapped_bit[i2] <= !relative_addr[nbits_byte_offset+i2*nbit_addr-1];
          else if(HIGH_LATENCY == 1)
          begin
            delayed_swapped_bit_registered[i2] <= !relative_addr[nbits_byte_offset+i2*nbit_addr-1];
            delayed_swapped_bit[i2] <= delayed_swapped_bit_registered[i2];
          end
          else
          begin
            delayed_swapped_bit_registered1[i2] <= !relative_addr[nbits_byte_offset+i2*nbit_addr-1];
            delayed_swapped_bit_registered[i2] <= delayed_swapped_bit_registered1[i2];
            delayed_swapped_bit[i2] <= delayed_swapped_bit_registered[i2];
          end
        end
    end
  endgenerate
  
  generate
  genvar i3;
    for (i3=0; i3<PORTSIZE_S_addr_ram; i3=i3+1)
    begin : L3
      if(PRIVATE_MEMORY==0 && USE_SPARSE_MEMORY==0)
        assign cs[i3] = (S_addr_ram[(i3+1)*BITSIZE_S_addr_ram-1:i3*BITSIZE_S_addr_ram] >= (address_space_begin)) && (S_addr_ram[(i3+1)*BITSIZE_S_addr_ram-1:i3*BITSIZE_S_addr_ram] < (address_space_begin+address_space_rangesize));
      else if(PRIVATE_MEMORY==0 && nbits_address_space_rangesize < 32)
        assign cs[i3] = S_addr_ram[(i3+1)*BITSIZE_S_addr_ram-1:i3*BITSIZE_S_addr_ram+nbits_address_space_rangesize] == address_space_begin[((nbit_addr-1) < 32 ? (nbit_addr-1) : 31):nbits_address_space_rangesize];
      else
        assign cs[i3] = 1'b0;
    end
  endgenerate
  
  generate
  genvar i4;
    for (i4=0; i4<PORTSIZE_S_oe_ram; i4=i4+1)
    begin : L4
      assign oe_ram_cs[i4] = S_oe_ram[i4] & cs[i4];
    end
  endgenerate
  
  generate
  genvar i5;
    for (i5=0; i5<PORTSIZE_S_we_ram; i5=i5+1)
    begin : L5
      assign we_ram_cs[i5] = S_we_ram[i5] & cs[i5];
    end
  endgenerate
  
  generate
  genvar i6;
    for (i6=0; i6<max_n_rw; i6=i6+1)
    begin : L6
      if(USE_SPARSE_MEMORY==1 && address_space_rangesize==1)
        assign relative_addr[(i6+1)*nbit_addr-1:i6*nbit_addr] = {nbit_addr{1'b0}};
      else if(PRIVATE_MEMORY==0 && USE_SPARSE_MEMORY==0 && i6< PORTSIZE_S_addr_ram)
        assign relative_addr[(i6+1)*nbit_addr-1:i6*nbit_addr] = ((i6 < max_n_writes && (sel_STORE[i6]==1'b1 || proxy_sel_STORE[i6]==1'b1)) || (i6 < max_n_reads && (sel_LOAD[i6]==1'b1 || proxy_sel_LOAD[i6]==1'b1))) ? tmp_addr[(i6+1)*BITSIZE_in2-1:i6*BITSIZE_in2]-address_space_begin: S_addr_ram[(i6+1)*BITSIZE_S_addr_ram-1:i6*BITSIZE_S_addr_ram]-address_space_begin;
      else if(PRIVATE_MEMORY==0 && i6< PORTSIZE_S_addr_ram)
        assign relative_addr[(i6)*nbit_addr+nbits_address_space_rangesize-1:i6*nbit_addr] = ((i6 < max_n_writes && (sel_STORE[i6]==1'b1 || proxy_sel_STORE[i6]==1'b1)) || (i6 < max_n_reads && (sel_LOAD[i6]==1'b1 || proxy_sel_LOAD[i6]==1'b1))) ? tmp_addr[(i6)*BITSIZE_in2+nbits_address_space_rangesize-1:i6*BITSIZE_in2] : S_addr_ram[(i6)*BITSIZE_S_addr_ram+nbits_address_space_rangesize-1:i6*BITSIZE_S_addr_ram];
      else if(USE_SPARSE_MEMORY==1)
        assign relative_addr[(i6)*nbit_addr+nbits_address_space_rangesize-1:i6*nbit_addr] = tmp_addr[(i6)*BITSIZE_in2+nbits_address_space_rangesize-1:i6*BITSIZE_in2];
      else
        assign relative_addr[(i6+1)*nbit_addr-1:i6*nbit_addr] = tmp_addr[(i6+1)*BITSIZE_in2-1:i6*BITSIZE_in2]-address_space_begin;
    end
  endgenerate
  
  generate
  genvar i7;
    for (i7=0; i7<max_n_rw; i7=i7+1)
    begin : L7_A
      if (n_elements==1)
        assign memory_addr_a[(i7+1)*nbit_read_addr-1:i7*nbit_read_addr] = {nbit_read_addr{1'b0}};
      else
        assign memory_addr_a[(i7+1)*nbit_read_addr-1:i7*nbit_read_addr] = !relative_addr[nbits_byte_offset+i7*nbit_addr-1] ? relative_addr[nbit_read_addr+nbits_byte_offset-1+i7*nbit_addr:nbits_byte_offset+i7*nbit_addr] : (relative_addr[nbit_read_addr+nbits_byte_offset-1+i7*nbit_addr:nbits_byte_offset+i7*nbit_addr-1]+ 1'b1) >> 1;
    end
  endgenerate
  
  generate
    for (i7=0; i7<max_n_rw; i7=i7+1)
    begin : L7_B
      if (n_elements==1)
        assign memory_addr_b[(i7+1)*nbit_read_addr-1:i7*nbit_read_addr] = {nbit_read_addr{1'b0}};
      else
        assign memory_addr_b[(i7+1)*nbit_read_addr-1:i7*nbit_read_addr] = !relative_addr[nbits_byte_offset+i7*nbit_addr-1] ? (relative_addr[nbit_read_addr+nbits_byte_offset-1+i7*nbit_addr:nbits_byte_offset+i7*nbit_addr-1] + 1'b1) >> 1 : relative_addr[nbit_read_addr+nbits_byte_offset-1+i7*nbit_addr:nbits_byte_offset+i7*nbit_addr];
    end
  endgenerate
  
  generate
  genvar i8;
    for (i8=0; i8<max_n_rw; i8=i8+1)
    begin : L8
      if (n_byte_on_databus==2)
        assign byte_offset[(i8+1)*nbits_byte_offset-1:i8*nbits_byte_offset] = {nbits_byte_offset{1'b0}};
      else
        assign byte_offset[(i8+1)*nbits_byte_offset-1:i8*nbits_byte_offset] = {1'b0, relative_addr[nbits_byte_offset+i8*nbit_addr-2:i8*nbit_addr]};
    end
  endgenerate
  
  generate
  genvar i9, i10;
    for (i9=0; i9<max_n_writes; i9=i9+1)
    begin : byte_enable
      if(PRIVATE_MEMORY==0 && i9 < PORTSIZE_S_data_ram_size)
      begin
        assign conv_in[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = proxy_sel_STORE[i9] ? proxy_in3[BITSIZE_proxy_in3+BITSIZE_proxy_in3*i9-1:3+BITSIZE_proxy_in3*i9] : (sel_STORE[i9] ? in3[BITSIZE_in3+BITSIZE_in3*i9-1:3+BITSIZE_in3*i9] : S_data_ram_size[BITSIZE_S_data_ram_size+BITSIZE_S_data_ram_size*i9-1:3+BITSIZE_S_data_ram_size*i9]);
        assign conv_out[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = CONV(conv_in[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus]);
        assign be[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = conv_out[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] << byte_offset[(i9+1)*nbits_byte_offset-1:i9*nbits_byte_offset];
      end
      else
      begin
        assign conv_in[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = proxy_sel_STORE[i9] ? proxy_in3[BITSIZE_proxy_in3+BITSIZE_proxy_in3*i9-1:3+BITSIZE_proxy_in3*i9] : in3[BITSIZE_in3+BITSIZE_in3*i9-1:3+BITSIZE_in3*i9];
        assign conv_out[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = CONV(conv_in[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus]);
        assign be[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] = conv_out[(i9+1)*n_byte_on_databus-1:i9*n_byte_on_databus] << byte_offset[(i9+1)*nbits_byte_offset-1:i9*nbits_byte_offset];
      end
    end
  endgenerate
  
  generate
    for (i9=0; i9<max_n_writes; i9=i9+1)
    begin : L9_swapped
      for (i10=0; i10<n_byte_on_databus/2; i10=i10+1)
      begin  : byte_enable_swapped
        assign be_swapped[i10+i9*n_byte_on_databus] = !relative_addr[nbits_byte_offset+i9*nbit_addr-1] ? be[i10+i9*n_byte_on_databus] : be[i10+i9*n_byte_on_databus+n_byte_on_databus/2];
        assign be_swapped[i10+i9*n_byte_on_databus+n_byte_on_databus/2] =  !relative_addr[nbits_byte_offset+i9*nbit_addr-1] ? be[i10+i9*n_byte_on_databus+n_byte_on_databus/2] : be[i10+i9*n_byte_on_databus];
      end
    end
  endgenerate
  
  generate
  genvar i13;
    for (i13=0; i13<PORTSIZE_S_Wdata_ram; i13=i13+1)
    begin : L13
      if (BITSIZE_S_Wdata_ram < memory_bitsize)
        assign S_Wdata_ram_int[memory_bitsize*(i13+1)-1:memory_bitsize*i13] = {{memory_bitsize-BITSIZE_S_Wdata_ram{1'b0}}, S_Wdata_ram[(i13+1)*BITSIZE_S_Wdata_ram-1:BITSIZE_S_Wdata_ram*i13]};
      else
        assign S_Wdata_ram_int[memory_bitsize*(i13+1)-1:memory_bitsize*i13] = S_Wdata_ram[memory_bitsize+BITSIZE_S_Wdata_ram*i13-1:BITSIZE_S_Wdata_ram*i13];
    end
  endgenerate
  
  generate
  genvar i14;
    for (i14=0; i14<max_n_writes; i14=i14+1)
    begin : L14
      if(PRIVATE_MEMORY==0 && i14 < PORTSIZE_S_Wdata_ram)
        assign din_value_aggregated[(i14+1)*memory_bitsize-1:i14*memory_bitsize] = proxy_sel_STORE[i14] ? proxy_in1[(i14+1)*BITSIZE_proxy_in1-1:i14*BITSIZE_proxy_in1] << byte_offset[(i14+1)*nbits_byte_offset-1:i14*nbits_byte_offset]*8 : (sel_STORE[i14] ? in1[(i14+1)*BITSIZE_in1-1:i14*BITSIZE_in1] << byte_offset[(i14+1)*nbits_byte_offset-1:i14*nbits_byte_offset]*8 : S_Wdata_ram_int[memory_bitsize*(i14+1)-1:memory_bitsize*i14] << byte_offset[(i14+1)*nbits_byte_offset-1:i14*nbits_byte_offset]*8);
      else
        assign din_value_aggregated[(i14+1)*memory_bitsize-1:i14*memory_bitsize] = proxy_sel_STORE[i14] ? proxy_in1[(i14+1)*BITSIZE_proxy_in1-1:i14*BITSIZE_proxy_in1] << byte_offset[(i14+1)*nbits_byte_offset-1:i14*nbits_byte_offset]*8 : in1[(i14+1)*BITSIZE_in1-1:i14*BITSIZE_in1] << byte_offset[(i14+1)*nbits_byte_offset-1:i14*nbits_byte_offset]*8;
    end
  endgenerate
  
  generate
    for (i14=0; i14<max_n_writes; i14=i14+1)
    begin : L14_swapped
      assign din_value_aggregated_swapped[(i14)*memory_bitsize+memory_bitsize/2-1:i14*memory_bitsize] = !relative_addr[nbits_byte_offset+i14*nbit_addr-1] ? din_value_aggregated[(i14)*memory_bitsize+memory_bitsize/2-1:i14*memory_bitsize] : din_value_aggregated[(i14+1)*memory_bitsize-1:i14*memory_bitsize+memory_bitsize/2];
      assign din_value_aggregated_swapped[(i14+1)*memory_bitsize-1:i14*memory_bitsize+memory_bitsize/2] = !relative_addr[nbits_byte_offset+i14*nbit_addr-1] ?  din_value_aggregated[(i14+1)*memory_bitsize-1:i14*memory_bitsize+memory_bitsize/2] : din_value_aggregated[(i14)*memory_bitsize+memory_bitsize/2-1:i14*memory_bitsize];
    end
  endgenerate
  
  generate
  genvar i15;
    for (i15=0; i15<max_n_reads; i15=i15+1)
    begin : L15
      assign out1_shifted[(i15+1)*memory_bitsize-1:i15*memory_bitsize] = dout[(i15+1)*memory_bitsize-1:i15*memory_bitsize] >> delayed_byte_offset[(i15+1)*nbits_byte_offset-1:i15*nbits_byte_offset]*8;
    end
  endgenerate
  
  generate
  genvar i20;
    for (i20=0; i20<max_n_reads; i20=i20+1)
    begin : L20
      assign out1[(i20+1)*BITSIZE_out1-1:i20*BITSIZE_out1] = out1_shifted[i20*memory_bitsize+BITSIZE_out1-1:i20*memory_bitsize];
      assign proxy_out1[(i20+1)*BITSIZE_proxy_out1-1:i20*BITSIZE_proxy_out1] = out1_shifted[i20*memory_bitsize+BITSIZE_proxy_out1-1:i20*memory_bitsize];
    end
  endgenerate
  
  generate
  genvar i16;
    for (i16=0; i16<PORTSIZE_S_oe_ram; i16=i16+1)
    begin : L16
      always @(posedge clock )
      begin
        if(reset == 1'b0)
          begin
            oe_ram_cs_delayed[i16] <= 1'b0;
            if(HIGH_LATENCY != 0) oe_ram_cs_delayed_registered[i16] <= 1'b0;
            if(HIGH_LATENCY == 2) oe_ram_cs_delayed_registered1[i16] <= 1'b0;
          end
        else
          if(HIGH_LATENCY == 0)
          begin
            oe_ram_cs_delayed[i16] <= oe_ram_cs[i16] & (!oe_ram_cs_delayed[i16] | BUS_PIPELINED);
          end
          else if(HIGH_LATENCY == 1)
          begin
            oe_ram_cs_delayed_registered[i16] <= oe_ram_cs[i16] & ((!oe_ram_cs_delayed_registered[i16] & !oe_ram_cs_delayed[i16]) | BUS_PIPELINED);
            oe_ram_cs_delayed[i16] <= oe_ram_cs_delayed_registered[i16];
          end
          else
          begin
            oe_ram_cs_delayed_registered1[i16] <= oe_ram_cs[i16] & ((!oe_ram_cs_delayed_registered1[i16] & !oe_ram_cs_delayed_registered[i16] & !oe_ram_cs_delayed[i16]) | BUS_PIPELINED);
            oe_ram_cs_delayed_registered[i16] <= oe_ram_cs_delayed_registered1[i16];
            oe_ram_cs_delayed[i16] <= oe_ram_cs_delayed_registered[i16];
          end
        end
      end
  endgenerate
  
  always @(posedge clock)
  begin
    if(HIGH_LATENCY == 0)
      delayed_byte_offset <= byte_offset[nbits_byte_offset*max_n_reads-1:0];
    else if(HIGH_LATENCY == 1)
    begin
      delayed_byte_offset_registered <= byte_offset[nbits_byte_offset*max_n_reads-1:0];
      delayed_byte_offset <= delayed_byte_offset_registered;
    end
    else
    begin
      delayed_byte_offset_registered1 <= byte_offset[nbits_byte_offset*max_n_reads-1:0];
      delayed_byte_offset_registered <= delayed_byte_offset_registered1;
      delayed_byte_offset <= delayed_byte_offset_registered;
    end
  end
  
  
  generate
  genvar i17;
    for (i17=0; i17<PORTSIZE_S_we_ram; i17=i17+1)
    begin : L17
      always @(posedge clock )
      begin
        if(reset == 1'b0)
          we_ram_cs_delayed[i17] <= 1'b0;
        else
          we_ram_cs_delayed[i17] <= we_ram_cs[i17] & !we_ram_cs_delayed[i17];
      end
    end
  endgenerate
  
  generate
  genvar i18;
    for (i18=0; i18<PORTSIZE_Sout_Rdata_ram; i18=i18+1)
    begin : L18
      if(PRIVATE_MEMORY==1)
        assign Sout_Rdata_ram[(i18+1)*BITSIZE_Sout_Rdata_ram-1:i18*BITSIZE_Sout_Rdata_ram] = Sin_Rdata_ram[(i18+1)*BITSIZE_Sin_Rdata_ram-1:i18*BITSIZE_Sin_Rdata_ram];
      else if (BITSIZE_Sout_Rdata_ram <= memory_bitsize)
        assign Sout_Rdata_ram[(i18+1)*BITSIZE_Sout_Rdata_ram-1:i18*BITSIZE_Sout_Rdata_ram] = oe_ram_cs_delayed[i18] ? out1_shifted[BITSIZE_Sout_Rdata_ram+i18*memory_bitsize-1:i18*memory_bitsize] : Sin_Rdata_ram[(i18+1)*BITSIZE_Sin_Rdata_ram-1:i18*BITSIZE_Sin_Rdata_ram];
      else
        assign Sout_Rdata_ram[(i18+1)*BITSIZE_Sout_Rdata_ram-1:i18*BITSIZE_Sout_Rdata_ram] = oe_ram_cs_delayed[i18] ? {{BITSIZE_S_Wdata_ram-memory_bitsize{1'b0}}, out1_shifted[(i18+1)*memory_bitsize-1:i18*memory_bitsize]} : Sin_Rdata_ram[(i18+1)*BITSIZE_Sin_Rdata_ram-1:i18*BITSIZE_Sin_Rdata_ram];
    end
  endgenerate
  
  generate
  genvar i19;
    for (i19=0; i19<PORTSIZE_Sout_DataRdy; i19=i19+1)
    begin : L19
      if(PRIVATE_MEMORY==0)
        assign Sout_DataRdy[i19] = (i19 < PORTSIZE_S_oe_ram && oe_ram_cs_delayed[i19]) | Sin_DataRdy[i19] | (i19 < PORTSIZE_S_we_ram && we_ram_cs_delayed[i19]);
      else
        assign Sout_DataRdy[i19] = Sin_DataRdy[i19];
    end
  endgenerate
  
  generate
  genvar i21;
    for (i21=0; i21<PORTSIZE_bram_write; i21=i21+1)
    begin : L21
      if(i21 < PORTSIZE_S_we_ram)
        assign bram_write[i21] = (sel_STORE[i21] || proxy_sel_STORE[i21] || we_ram_cs[i21]);
      else
        assign bram_write[i21] = (sel_STORE[i21] || proxy_sel_STORE[i21]);
    end
    endgenerate

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2016-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _BRAM_MEMORY_CORE_SMALL_DEFINED
`define _BRAM_MEMORY_CORE_SMALL_DEFINED
`timescale 1ns / 1ps
module BRAM_MEMORY_CORE_SMALL(clock,
  bram_write,
  memory_addr_a,
  din_value_aggregated,
  be,
  dout_a);
  parameter BITSIZE_dout_a=1, PORTSIZE_dout_a=1,
    BITSIZE_bram_write=1, PORTSIZE_bram_write=1,
    BITSIZE_memory_addr_a=1, PORTSIZE_memory_addr_a=1,
    BITSIZE_din_value_aggregated=1, PORTSIZE_din_value_aggregated=1,
    BITSIZE_be=1, PORTSIZE_be=1,
    MEMORY_INIT_file="array.mem",
    n_byte_on_databus=4,
    n_elements=4,
    n_bytes=4,
    READ_ONLY_MEMORY=0,
    HIGH_LATENCY=0;
  // IN
  input clock;
  input [PORTSIZE_bram_write-1:0] bram_write;
  input [(PORTSIZE_memory_addr_a*BITSIZE_memory_addr_a)+(-1):0] memory_addr_a;
  input [(PORTSIZE_din_value_aggregated*BITSIZE_din_value_aggregated)+(-1):0] din_value_aggregated;
  input [(PORTSIZE_be*BITSIZE_be)+(-1):0] be;
  // OUT
  output [(PORTSIZE_dout_a*BITSIZE_dout_a)+(-1):0] dout_a;
  
  reg [PORTSIZE_bram_write-1:0] bram_write1;
  reg [(PORTSIZE_memory_addr_a*BITSIZE_memory_addr_a)-1:0] memory_addr_a1;
  reg [(PORTSIZE_be*BITSIZE_be)-1:0] be1;
  reg [(PORTSIZE_din_value_aggregated*BITSIZE_din_value_aggregated)-1:0] din_value_aggregated1;
  reg [(PORTSIZE_dout_a*BITSIZE_dout_a)-1:0] dout_a_tmp;
  reg [(PORTSIZE_dout_a*BITSIZE_dout_a)-1:0] dout_a_registered;
  (* ram_style = "registers" *) reg [(n_byte_on_databus)*8-1:0] memory [0:n_elements-1]/* synthesis syn_ramstyle = "registers,no_rw_check" */ ;
  integer p1;
  
  initial
  begin
    $readmemb(MEMORY_INIT_file, memory, 0, n_elements-1);
  end
  
  generate
    if(HIGH_LATENCY==2)
    begin
      always @ (posedge clock)
      begin
         memory_addr_a1 <= memory_addr_a;
         bram_write1 <= bram_write;
         be1 <= be;
         din_value_aggregated1 <= din_value_aggregated;
      end
    end
  endgenerate
  
  assign dout_a = dout_a_tmp;
  
    always @(posedge clock)
    begin
      for (p1=0; p1<PORTSIZE_memory_addr_a; p1=p1+1)
      begin
        if(HIGH_LATENCY == 0||HIGH_LATENCY == 1)
        begin
          if (bram_write[p1] && READ_ONLY_MEMORY==0)
          begin : L11_write
            integer i11;
            for (i11=0; i11<n_byte_on_databus; i11=i11+1)
            begin
              if(be[i11+p1*n_byte_on_databus])
  `ifdef VERILATOR
                memory[memory_addr_a[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]][i11*8+:8] = din_value_aggregated[p1*n_byte_on_databus*8+i11*8+:8];
  `else
                memory[memory_addr_a[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]][i11*8+:8] <= din_value_aggregated[p1*n_byte_on_databus*8+i11*8+:8];
  `endif
            end
          end
        end
        else
        begin
          if (bram_write1[p1] && READ_ONLY_MEMORY==0)
          begin : L11_write1
            integer i11;
            for (i11=0; i11<n_byte_on_databus; i11=i11+1)
            begin
              if(be1[i11+p1*n_byte_on_databus])
  `ifdef VERILATOR
                memory[memory_addr_a1[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]][i11*8+:8] = din_value_aggregated1[p1*n_byte_on_databus*8+i11*8+:8];
  `else
                memory[memory_addr_a1[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]][i11*8+:8] <= din_value_aggregated1[p1*n_byte_on_databus*8+i11*8+:8];
  `endif
            end
          end
        end
        if(HIGH_LATENCY == 0)
          dout_a_tmp[p1*BITSIZE_dout_a+:BITSIZE_dout_a] <= memory[memory_addr_a[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]];
        else if(HIGH_LATENCY == 1)
        begin
          dout_a_registered[p1*BITSIZE_dout_a+:BITSIZE_dout_a] <= memory[memory_addr_a[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]];
          dout_a_tmp[p1*BITSIZE_dout_a+:BITSIZE_dout_a] <= dout_a_registered[p1*BITSIZE_dout_a+:BITSIZE_dout_a];
        end
        else
        begin
          dout_a_registered[p1*BITSIZE_dout_a+:BITSIZE_dout_a] <= memory[memory_addr_a1[p1*BITSIZE_memory_addr_a+:BITSIZE_memory_addr_a]];
          dout_a_tmp[p1*BITSIZE_dout_a+:BITSIZE_dout_a] <= dout_a_registered[p1*BITSIZE_dout_a+:BITSIZE_dout_a];
        end
      end
    end

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2016-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _TRUE_DUAL_PORT_BYTE_ENABLING_RAM_DEFINED
`define _TRUE_DUAL_PORT_BYTE_ENABLING_RAM_DEFINED
`timescale 1ns / 1ps
module TRUE_DUAL_PORT_BYTE_ENABLING_RAM(clock,
  bram_write0,
  bram_write1,
  memory_addr_a,
  memory_addr_b,
  din_value_aggregated_a,
  din_value_aggregated_b,
  be_a,
  be_b,
  dout_a,
  dout_b);
  parameter BITSIZE_dout_a=1,
    BITSIZE_dout_b=1,
    BITSIZE_memory_addr_a=1,
    BITSIZE_memory_addr_b=1,
    BITSIZE_din_value_aggregated_a=1,
    BITSIZE_din_value_aggregated_b=1,
    BITSIZE_be_a=1,
    BITSIZE_be_b=1,
    MEMORY_INIT_file="array.mem",
    BRAM_BITSIZE=32,
    n_byte_on_databus=4,
    n_elements=4,
    READ_ONLY_MEMORY=0,
    HIGH_LATENCY=0;
  // IN
  input clock;
  input bram_write0;
  input bram_write1;
  input [BITSIZE_memory_addr_a-1:0] memory_addr_a;
  input [BITSIZE_memory_addr_b-1:0] memory_addr_b;
  input [BITSIZE_din_value_aggregated_a-1:0] din_value_aggregated_a;
  input [BITSIZE_din_value_aggregated_b-1:0] din_value_aggregated_b;
  input [BITSIZE_be_a-1:0] be_a;
  input [BITSIZE_be_b-1:0] be_b;
  // OUT
  output [BITSIZE_dout_a-1:0] dout_a;
  output [BITSIZE_dout_b-1:0] dout_b;
  
  wire [n_byte_on_databus-1:0] we_a;
  wire [n_byte_on_databus-1:0] we_b;
  reg [n_byte_on_databus-1:0] we_a1;
  reg [n_byte_on_databus-1:0] we_b1;
  reg [BITSIZE_din_value_aggregated_a-1:0] din_value_aggregated_a1;
  reg [BITSIZE_din_value_aggregated_b-1:0] din_value_aggregated_b1;
  
  reg [BITSIZE_dout_a-1:0] dout_a;
  reg [BITSIZE_dout_a-1:0] dout_a_registered;
  reg [BITSIZE_dout_b-1:0] dout_b;
  reg [BITSIZE_dout_b-1:0] dout_b_registered;
  reg [BITSIZE_memory_addr_a-1:0] memory_addr_a1;
  reg [BITSIZE_memory_addr_b-1:0] memory_addr_b1;
  reg [BRAM_BITSIZE-1:0] memory [0:n_elements-1] /* synthesis syn_ramstyle = "no_rw_check" */;
  integer i11, i12;
  
  initial
  begin
    $readmemb(MEMORY_INIT_file, memory, 0, n_elements-1);
  end
  
  always @(posedge clock)
  begin
    if(READ_ONLY_MEMORY==0)
    begin
      for (i11=0; i11<n_byte_on_databus; i11=i11+1)
      begin : L11_write_a
        if(HIGH_LATENCY==0||HIGH_LATENCY==1)
        begin
          if(we_a[i11])
            memory[memory_addr_a][i11*8+:8] <= din_value_aggregated_a[i11*8+:8];
        end
        else
        begin
          if(we_a1[i11])
            memory[memory_addr_a1][i11*8+:8] <= din_value_aggregated_a1[i11*8+:8];
        end
      end
    end
    if(HIGH_LATENCY==0)
    begin
      dout_a <= memory[memory_addr_a];
    end
    else if(HIGH_LATENCY==1)
    begin
      dout_a_registered <= memory[memory_addr_a];
      dout_a <= dout_a_registered;
    end
    else
    begin
      memory_addr_a1 <= memory_addr_a;
      we_a1 <= we_a;
      din_value_aggregated_a1 <= din_value_aggregated_a;
      dout_a_registered <= memory[memory_addr_a1];
      dout_a <= dout_a_registered;
    end
  end
  
  always @(posedge clock)
  begin
    if(READ_ONLY_MEMORY==0)
    begin
      for (i12=0; i12<n_byte_on_databus; i12=i12+1)
      begin : L12_write_b
        if(HIGH_LATENCY==0||HIGH_LATENCY==1)
        begin
          if(we_b[i12])
            memory[memory_addr_b][i12*8+:8] <= din_value_aggregated_b[i12*8+:8];
        end
        else
        begin
          if(we_b1[i12])
            memory[memory_addr_b1][i12*8+:8] <= din_value_aggregated_b1[i12*8+:8];
        end
      end
    end
    if(HIGH_LATENCY==0)
    begin
      dout_b <= memory[memory_addr_b];
    end
    else if(HIGH_LATENCY==1)
    begin
      dout_b_registered <= memory[memory_addr_b];
      dout_b <= dout_b_registered;
    end
    else
    begin
      memory_addr_b1 <= memory_addr_b;
      we_b1 <= we_b;
      din_value_aggregated_b1 <= din_value_aggregated_b;
      dout_b_registered <= memory[memory_addr_b1];
      dout_b <= dout_b_registered;
    end
  end
  
  generate
  genvar i2_a;
    for (i2_a=0; i2_a<n_byte_on_databus; i2_a=i2_a+1)
    begin  : write_enable_a
      assign we_a[i2_a] = (bram_write0) && be_a[i2_a];
    end
  endgenerate
  
  generate
  genvar i2_b;
    for (i2_b=0; i2_b<n_byte_on_databus; i2_b=i2_b+1)
    begin  : write_enable_b
      assign we_b[i2_b] = (bram_write1) && be_b[i2_b];
    end
  endgenerate
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2016-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _BRAM_MEMORY_NN_CORE_DEFINED
`define _BRAM_MEMORY_NN_CORE_DEFINED
`timescale 1ns / 1ps
module BRAM_MEMORY_NN_CORE(clock,
  bram_write,
  memory_addr_a,
  din_value_aggregated_swapped,
  be_swapped,
  dout_a);
  parameter BITSIZE_bram_write=1, PORTSIZE_bram_write=1,
    BITSIZE_dout_a=1, PORTSIZE_dout_a=1,
    BITSIZE_memory_addr_a=1, PORTSIZE_memory_addr_a=1,
    BITSIZE_din_value_aggregated_swapped=1, PORTSIZE_din_value_aggregated_swapped=1,
    BITSIZE_be_swapped=1, PORTSIZE_be_swapped=1,
    MEMORY_INIT_file="array.mem",
    BRAM_BITSIZE=32,
    n_bytes=32,
    n_byte_on_databus=4,
    n_elements=4,
    max_n_reads=2,
    max_n_writes=2,
    memory_offset=16,
    n_byte_on_databus_offset=2,
    READ_ONLY_MEMORY=0,
    HIGH_LATENCY=0;
  // IN
  input clock;
  input [PORTSIZE_bram_write-1:0] bram_write;
  input [(PORTSIZE_memory_addr_a*BITSIZE_memory_addr_a)+(-1):0] memory_addr_a;
  input [(PORTSIZE_din_value_aggregated_swapped*BITSIZE_din_value_aggregated_swapped)+(-1):0] din_value_aggregated_swapped;
  input [(PORTSIZE_be_swapped*BITSIZE_be_swapped)+(-1):0] be_swapped;
  // OUT
  output [(PORTSIZE_dout_a*BITSIZE_dout_a)+(-1):0] dout_a;
  
  wire [(n_byte_on_databus/2)*8-1:0] dina;
  wire [(n_byte_on_databus/2)*8-1:0] dinb;
  wire [n_byte_on_databus*8-1:0] din;
  wire [n_byte_on_databus/2-1:0] be0;
  wire [n_byte_on_databus/2-1:0] be1;
  wire [n_byte_on_databus-1:0] beTot;
  
  assign dina = din_value_aggregated_swapped[memory_offset+:(n_byte_on_databus/2)*8];
  assign dinb = din_value_aggregated_swapped[2*BRAM_BITSIZE+memory_offset+:(n_byte_on_databus/2)*8];
  assign din = {dinb,dina};
  assign be0 = be_swapped[n_byte_on_databus_offset+:n_byte_on_databus/2];
  assign be1 = be_swapped[n_byte_on_databus+n_byte_on_databus_offset+:n_byte_on_databus/2];
  assign beTot = {be1,be0};
  
  generate
  if(n_elements == 1 || n_byte_on_databus >= n_bytes)
  begin
    BRAM_MEMORY_CORE_SMALL #(.PORTSIZE_bram_write(PORTSIZE_bram_write),
    .BITSIZE_bram_write(BITSIZE_bram_write),
    .PORTSIZE_memory_addr_a(PORTSIZE_memory_addr_a),
    .BITSIZE_memory_addr_a(BITSIZE_memory_addr_a),
    .PORTSIZE_din_value_aggregated(PORTSIZE_din_value_aggregated_swapped),
    .BITSIZE_din_value_aggregated((n_byte_on_databus/2)*8),
    .PORTSIZE_be(PORTSIZE_be_swapped),
    .BITSIZE_be(n_byte_on_databus/PORTSIZE_be_swapped),
    .PORTSIZE_dout_a(PORTSIZE_dout_a),
    .BITSIZE_dout_a(BITSIZE_dout_a),
    .MEMORY_INIT_file(MEMORY_INIT_file),
    .n_byte_on_databus(n_byte_on_databus/2),
    .n_elements(n_elements),
    .n_bytes(n_bytes),
    .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
    .HIGH_LATENCY(HIGH_LATENCY)) BRAM_MEMORY_instance_small (.clock(clock),
    .bram_write(bram_write),
    .memory_addr_a(memory_addr_a),
    .din_value_aggregated(din),
    .be(beTot),
    .dout_a(dout_a));
  end
  else
  begin
    TRUE_DUAL_PORT_BYTE_ENABLING_RAM #(.BITSIZE_memory_addr_a(BITSIZE_memory_addr_a),
      .BITSIZE_memory_addr_b(BITSIZE_memory_addr_a),
      .BITSIZE_din_value_aggregated_a((n_byte_on_databus/2)*8),
      .BITSIZE_din_value_aggregated_b((n_byte_on_databus/2)*8),
      .BITSIZE_be_a(n_byte_on_databus/2),
      .BITSIZE_be_b(n_byte_on_databus/2),
      .BITSIZE_dout_a((n_byte_on_databus/2)*8),
      .BITSIZE_dout_b((n_byte_on_databus/2)*8),
      .MEMORY_INIT_file(MEMORY_INIT_file),
      .BRAM_BITSIZE(BRAM_BITSIZE),
      .n_byte_on_databus(n_byte_on_databus/2),
      .n_elements(n_elements),
      .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
      .HIGH_LATENCY(HIGH_LATENCY)
    ) TRUE_DUAL_PORT_BYTE_ENABLING_RAM_instance (.clock(clock),
      .bram_write0(bram_write[0]),
      .bram_write1(bram_write[1]),
      .memory_addr_a(memory_addr_a[BITSIZE_memory_addr_a-1:0]),
      .memory_addr_b(memory_addr_a[2*BITSIZE_memory_addr_a-1:BITSIZE_memory_addr_a]),
      .din_value_aggregated_a(dina),
      .din_value_aggregated_b(dinb),
      .be_a(be0),
      .be_b(be1),
      .dout_a(dout_a[BRAM_BITSIZE-1:0]),
      .dout_b(dout_a[2*BRAM_BITSIZE-1:BRAM_BITSIZE])
    );
  end
  endgenerate

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ARRAY_1D_STD_BRAM_NN_SP_DEFINED
`define _ARRAY_1D_STD_BRAM_NN_SP_DEFINED
`timescale 1ns / 1ps
module ARRAY_1D_STD_BRAM_NN_SP(clock,
  reset,
  in1,
  in2,
  in3,
  out1,
  sel_LOAD,
  sel_STORE,
  S_oe_ram,
  S_we_ram,
  S_addr_ram,
  S_Wdata_ram,
  Sin_Rdata_ram,
  Sout_Rdata_ram,
  S_data_ram_size,
  Sin_DataRdy,
  Sout_DataRdy,
  proxy_in1,
  proxy_in2,
  proxy_in3,
  proxy_sel_LOAD,
  proxy_sel_STORE,
  proxy_out1);
  parameter BITSIZE_in1=1, PORTSIZE_in1=1,
    BITSIZE_in2=1, PORTSIZE_in2=1,
    BITSIZE_in3=1, PORTSIZE_in3=1,
    BITSIZE_sel_LOAD=1, PORTSIZE_sel_LOAD=1,
    BITSIZE_sel_STORE=1, PORTSIZE_sel_STORE=1,
    BITSIZE_S_oe_ram=1, PORTSIZE_S_oe_ram=1,
    BITSIZE_S_we_ram=1, PORTSIZE_S_we_ram=1,
    BITSIZE_out1=1, PORTSIZE_out1=1,
    BITSIZE_S_addr_ram=1, PORTSIZE_S_addr_ram=1,
    BITSIZE_S_Wdata_ram=8, PORTSIZE_S_Wdata_ram=1,
    BITSIZE_Sin_Rdata_ram=8, PORTSIZE_Sin_Rdata_ram=1,
    BITSIZE_Sout_Rdata_ram=8, PORTSIZE_Sout_Rdata_ram=1,
    BITSIZE_S_data_ram_size=1, PORTSIZE_S_data_ram_size=1,
    BITSIZE_Sin_DataRdy=1, PORTSIZE_Sin_DataRdy=1,
    BITSIZE_Sout_DataRdy=1, PORTSIZE_Sout_DataRdy=1,
    MEMORY_INIT_file_a="array_a.mem",
    MEMORY_INIT_file_b="array_b.mem",
    n_elements=1,
    data_size=32,
    address_space_begin=0,
    address_space_rangesize=4,
    BUS_PIPELINED=1,
    BRAM_BITSIZE=32,
    PRIVATE_MEMORY=0,
    READ_ONLY_MEMORY=0,
    USE_SPARSE_MEMORY=1,
    HIGH_LATENCY=0,
    BITSIZE_proxy_in1=1, PORTSIZE_proxy_in1=1,
    BITSIZE_proxy_in2=1, PORTSIZE_proxy_in2=1,
    BITSIZE_proxy_in3=1, PORTSIZE_proxy_in3=1,
    BITSIZE_proxy_sel_LOAD=1, PORTSIZE_proxy_sel_LOAD=1,
    BITSIZE_proxy_sel_STORE=1, PORTSIZE_proxy_sel_STORE=1,
    BITSIZE_proxy_out1=1, PORTSIZE_proxy_out1=1;
  // IN
  input clock;
  input reset;
  input [(PORTSIZE_in1*BITSIZE_in1)+(-1):0] in1;
  input [(PORTSIZE_in2*BITSIZE_in2)+(-1):0] in2;
  input [(PORTSIZE_in3*BITSIZE_in3)+(-1):0] in3;
  input [PORTSIZE_sel_LOAD-1:0] sel_LOAD;
  input [PORTSIZE_sel_STORE-1:0] sel_STORE;
  input [PORTSIZE_S_oe_ram-1:0] S_oe_ram;
  input [PORTSIZE_S_we_ram-1:0] S_we_ram;
  input [(PORTSIZE_S_addr_ram*BITSIZE_S_addr_ram)+(-1):0] S_addr_ram;
  input [(PORTSIZE_S_Wdata_ram*BITSIZE_S_Wdata_ram)+(-1):0] S_Wdata_ram;
  input [(PORTSIZE_Sin_Rdata_ram*BITSIZE_Sin_Rdata_ram)+(-1):0] Sin_Rdata_ram;
  input [(PORTSIZE_S_data_ram_size*BITSIZE_S_data_ram_size)+(-1):0] S_data_ram_size;
  input [PORTSIZE_Sin_DataRdy-1:0] Sin_DataRdy;
  input [(PORTSIZE_proxy_in1*BITSIZE_proxy_in1)+(-1):0] proxy_in1;
  input [(PORTSIZE_proxy_in2*BITSIZE_proxy_in2)+(-1):0] proxy_in2;
  input [(PORTSIZE_proxy_in3*BITSIZE_proxy_in3)+(-1):0] proxy_in3;
  input [PORTSIZE_proxy_sel_LOAD-1:0] proxy_sel_LOAD;
  input [PORTSIZE_proxy_sel_STORE-1:0] proxy_sel_STORE;
  // OUT
  output [(PORTSIZE_out1*BITSIZE_out1)+(-1):0] out1;
  output [(PORTSIZE_Sout_Rdata_ram*BITSIZE_Sout_Rdata_ram)+(-1):0] Sout_Rdata_ram;
  output [PORTSIZE_Sout_DataRdy-1:0] Sout_DataRdy;
  output [(PORTSIZE_proxy_out1*BITSIZE_proxy_out1)+(-1):0] proxy_out1;
  `ifndef _SIM_HAVE_CLOG2
    function integer log2;
       input integer value;
       integer temp_value;
      begin
        temp_value = value-1;
        for (log2=0; temp_value>0; log2=log2+1)
          temp_value = temp_value>>1;
      end
    endfunction
  `endif
  parameter n_bytes = (n_elements*data_size)/8;
  parameter memory_bitsize = 2*BRAM_BITSIZE;
  parameter n_byte_on_databus = memory_bitsize/8;
  parameter n_elements_bus = n_bytes/(n_byte_on_databus) + (n_bytes%(n_byte_on_databus) == 0 ? 0 : 1);
  `ifdef _SIM_HAVE_CLOG2
    localparam nbit_read_addr = n_elements_bus == 1 ? 1 : $clog2(n_elements_bus);
  `else
    localparam nbit_read_addr = n_elements_bus == 1 ? 1 : log2(n_elements_bus);
  `endif
  parameter max_n_writes = PORTSIZE_sel_STORE > PORTSIZE_S_we_ram ? PORTSIZE_sel_STORE : PORTSIZE_S_we_ram;
  parameter max_n_reads = PORTSIZE_sel_LOAD > PORTSIZE_S_oe_ram ? PORTSIZE_sel_LOAD : PORTSIZE_S_oe_ram;
  parameter max_n_rw = max_n_writes > max_n_reads ? max_n_writes : max_n_reads;
  
  wire [max_n_writes-1:0] bram_write;
  
  wire [nbit_read_addr*max_n_rw-1:0] memory_addr_a;
  wire [nbit_read_addr*max_n_rw-1:0] memory_addr_b;
  wire [n_byte_on_databus*max_n_writes-1:0] be_swapped;
  
  wire [memory_bitsize*max_n_writes-1:0] din_value_aggregated_swapped;
  wire [(memory_bitsize/2)*max_n_reads-1:0] dout_a;
  wire [(memory_bitsize/2)*max_n_reads-1:0] dout_b;
  
  
  BRAM_MEMORY_NN_CORE #(.PORTSIZE_bram_write(max_n_writes),
    .BITSIZE_bram_write(1),
    .BITSIZE_dout_a(memory_bitsize/2),
    .PORTSIZE_dout_a(max_n_reads),
    .BITSIZE_memory_addr_a(nbit_read_addr),
    .PORTSIZE_memory_addr_a(max_n_rw),
    .BITSIZE_din_value_aggregated_swapped(memory_bitsize),
    .PORTSIZE_din_value_aggregated_swapped(max_n_writes),
    .BITSIZE_be_swapped(n_byte_on_databus),
    .PORTSIZE_be_swapped(max_n_writes),
    .MEMORY_INIT_file(MEMORY_INIT_file_a),
    .BRAM_BITSIZE(BRAM_BITSIZE),
    .n_bytes(n_bytes),
    .n_byte_on_databus(n_byte_on_databus),
    .n_elements(n_elements_bus),
    .max_n_reads(max_n_reads),
    .max_n_writes(max_n_writes),
    .memory_offset(0),
    .n_byte_on_databus_offset(0),
    .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
    .HIGH_LATENCY(HIGH_LATENCY)) BRAM_MEMORY_NN_instance_a(
    .clock(clock),
    .bram_write(bram_write),
    .memory_addr_a(memory_addr_a),
    .din_value_aggregated_swapped(din_value_aggregated_swapped),
    .be_swapped(be_swapped),
    .dout_a(dout_a));
  
  generate
    if (n_bytes > BRAM_BITSIZE/8)
    begin : SECOND_MEMORY
      BRAM_MEMORY_NN_CORE #(.PORTSIZE_bram_write(max_n_writes),
    .BITSIZE_bram_write(1),
    .BITSIZE_dout_a((memory_bitsize/2)),
    .PORTSIZE_dout_a(max_n_reads),
    .BITSIZE_memory_addr_a(nbit_read_addr),
    .PORTSIZE_memory_addr_a(max_n_rw),
    .BITSIZE_din_value_aggregated_swapped(memory_bitsize),
    .PORTSIZE_din_value_aggregated_swapped(max_n_writes),
    .BITSIZE_be_swapped(n_byte_on_databus),
    .PORTSIZE_be_swapped(max_n_writes),
    .MEMORY_INIT_file(MEMORY_INIT_file_b),
    .BRAM_BITSIZE(BRAM_BITSIZE),
    .n_bytes(n_bytes),
    .n_byte_on_databus(n_byte_on_databus),
    .n_elements(n_elements_bus),
    .max_n_reads(max_n_reads),
    .max_n_writes(max_n_writes),
    .memory_offset(memory_bitsize/2),
    .n_byte_on_databus_offset(n_byte_on_databus/2),
    .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
    .HIGH_LATENCY(HIGH_LATENCY)) BRAM_MEMORY_NN_instance_b(.clock(clock),
    .bram_write(bram_write),
    .memory_addr_a(memory_addr_b),
    .din_value_aggregated_swapped(din_value_aggregated_swapped),
    .be_swapped(be_swapped),
    .dout_a(dout_b));
    end
  else
    assign dout_b = {(memory_bitsize/2)*max_n_reads{1'b0}};
  endgenerate
  
  ADDRESS_DECODING_LOGIC_NN #(.BITSIZE_in1(BITSIZE_in1),
    .PORTSIZE_in1(PORTSIZE_in1),
    .BITSIZE_in2(BITSIZE_in2),
    .PORTSIZE_in2(PORTSIZE_in2),
    .BITSIZE_in3(BITSIZE_in3),
    .PORTSIZE_in3(PORTSIZE_in3),
    .BITSIZE_sel_LOAD(BITSIZE_sel_LOAD),
    .PORTSIZE_sel_LOAD(PORTSIZE_sel_LOAD),
    .BITSIZE_sel_STORE(BITSIZE_sel_STORE),
    .PORTSIZE_sel_STORE(PORTSIZE_sel_STORE),
    .BITSIZE_out1(BITSIZE_out1),
    .PORTSIZE_out1(PORTSIZE_out1),
    .BITSIZE_S_oe_ram(BITSIZE_S_oe_ram),
    .PORTSIZE_S_oe_ram(PORTSIZE_S_oe_ram),
    .BITSIZE_S_we_ram(BITSIZE_S_we_ram),
    .PORTSIZE_S_we_ram(PORTSIZE_S_we_ram),
    .BITSIZE_Sin_DataRdy(BITSIZE_Sin_DataRdy),
    .PORTSIZE_Sin_DataRdy(PORTSIZE_Sin_DataRdy),
    .BITSIZE_Sout_DataRdy(BITSIZE_Sout_DataRdy),
    .PORTSIZE_Sout_DataRdy(PORTSIZE_Sout_DataRdy),
    .BITSIZE_S_addr_ram(BITSIZE_S_addr_ram),
    .PORTSIZE_S_addr_ram(PORTSIZE_S_addr_ram),
    .BITSIZE_S_Wdata_ram(BITSIZE_S_Wdata_ram),
    .PORTSIZE_S_Wdata_ram(PORTSIZE_S_Wdata_ram),
    .BITSIZE_Sin_Rdata_ram(BITSIZE_Sin_Rdata_ram),
    .PORTSIZE_Sin_Rdata_ram(PORTSIZE_Sin_Rdata_ram),
    .BITSIZE_Sout_Rdata_ram(BITSIZE_Sout_Rdata_ram),
    .PORTSIZE_Sout_Rdata_ram(PORTSIZE_Sout_Rdata_ram),
    .BITSIZE_S_data_ram_size(BITSIZE_S_data_ram_size),
    .PORTSIZE_S_data_ram_size(PORTSIZE_S_data_ram_size),
    .address_space_begin(address_space_begin),
    .address_space_rangesize(address_space_rangesize),
    .BUS_PIPELINED(BUS_PIPELINED),
    .BRAM_BITSIZE(BRAM_BITSIZE),
    .PRIVATE_MEMORY(PRIVATE_MEMORY),
    .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
    .USE_SPARSE_MEMORY(USE_SPARSE_MEMORY),
    .HIGH_LATENCY(HIGH_LATENCY),
    .BITSIZE_proxy_in1(BITSIZE_proxy_in1),
    .PORTSIZE_proxy_in1(PORTSIZE_proxy_in1),
    .BITSIZE_proxy_in2(BITSIZE_proxy_in2),
    .PORTSIZE_proxy_in2(PORTSIZE_proxy_in2),
    .BITSIZE_proxy_in3(BITSIZE_proxy_in3),
    .PORTSIZE_proxy_in3(PORTSIZE_proxy_in3),
    .BITSIZE_proxy_sel_LOAD(BITSIZE_proxy_sel_LOAD),
    .PORTSIZE_proxy_sel_LOAD(PORTSIZE_proxy_sel_LOAD),
    .BITSIZE_proxy_sel_STORE(BITSIZE_proxy_sel_STORE),
    .PORTSIZE_proxy_sel_STORE(PORTSIZE_proxy_sel_STORE),
    .BITSIZE_proxy_out1(BITSIZE_proxy_out1),
    .PORTSIZE_proxy_out1(PORTSIZE_proxy_out1),
    .BITSIZE_dout_a(memory_bitsize/2),
    .PORTSIZE_dout_a(max_n_reads),
    .BITSIZE_dout_b(memory_bitsize/2),
    .PORTSIZE_dout_b(max_n_reads),
    .BITSIZE_memory_addr_a(nbit_read_addr),
    .PORTSIZE_memory_addr_a(max_n_rw),
    .BITSIZE_memory_addr_b(nbit_read_addr),
    .PORTSIZE_memory_addr_b(max_n_rw),
    .BITSIZE_din_value_aggregated_swapped(memory_bitsize),
    .PORTSIZE_din_value_aggregated_swapped(max_n_writes),
    .BITSIZE_be_swapped(n_byte_on_databus),
    .PORTSIZE_be_swapped(max_n_writes),
    .BITSIZE_bram_write(1),
    .PORTSIZE_bram_write(max_n_writes),
    .nbit_read_addr(nbit_read_addr),
    .n_byte_on_databus(n_byte_on_databus),
    .n_elements(n_elements_bus),
    .max_n_reads(max_n_reads),
    .max_n_writes(max_n_writes),
    .max_n_rw(max_n_rw)) ADDRESS_DECODING_LOGIC_NN_instance (.clock(clock),
    .reset(reset),
    .in1(in1),
    .in2(in2),
    .in3(in3),
    .out1(out1),
    .sel_LOAD(sel_LOAD),
    .sel_STORE(sel_STORE),
    .S_oe_ram(S_oe_ram),
    .S_we_ram(S_we_ram),
    .S_addr_ram(S_addr_ram),
    .S_Wdata_ram(S_Wdata_ram),
    .Sin_Rdata_ram(Sin_Rdata_ram),
    .Sout_Rdata_ram(Sout_Rdata_ram),
    .S_data_ram_size(S_data_ram_size),
    .Sin_DataRdy(Sin_DataRdy),
    .Sout_DataRdy(Sout_DataRdy),
    .proxy_in1(proxy_in1),
    .proxy_in2(proxy_in2),
    .proxy_in3(proxy_in3),
    .proxy_sel_LOAD(proxy_sel_LOAD),
    .proxy_sel_STORE(proxy_sel_STORE),
    .proxy_out1(proxy_out1),
    .dout_a(dout_a),
    .dout_b(dout_b),
    .memory_addr_a(memory_addr_a),
    .memory_addr_b(memory_addr_b),
    .din_value_aggregated_swapped(din_value_aggregated_swapped),
    .be_swapped(be_swapped),
    .bram_write(bram_write));
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ARRAY_1D_STD_BRAM_NN_DEFINED
`define _ARRAY_1D_STD_BRAM_NN_DEFINED
`timescale 1ns / 1ps
module ARRAY_1D_STD_BRAM_NN(clock,
  reset,
  in1,
  in2,
  in3,
  in4,
  out1,
  sel_LOAD,
  sel_STORE,
  S_oe_ram,
  S_we_ram,
  S_addr_ram,
  S_Wdata_ram,
  Sin_Rdata_ram,
  Sout_Rdata_ram,
  S_data_ram_size,
  Sin_DataRdy,
  Sout_DataRdy,
  proxy_in1,
  proxy_in2,
  proxy_in3,
  proxy_sel_LOAD,
  proxy_sel_STORE,
  proxy_out1);
  parameter BITSIZE_in1=1, PORTSIZE_in1=1,
    BITSIZE_in2=1, PORTSIZE_in2=1,
    BITSIZE_in3=1, PORTSIZE_in3=1,
    BITSIZE_in4=1, PORTSIZE_in4=1,
    BITSIZE_sel_LOAD=1, PORTSIZE_sel_LOAD=1,
    BITSIZE_sel_STORE=1, PORTSIZE_sel_STORE=1,
    BITSIZE_S_oe_ram=1, PORTSIZE_S_oe_ram=1,
    BITSIZE_S_we_ram=1, PORTSIZE_S_we_ram=1,
    BITSIZE_out1=1, PORTSIZE_out1=1,
    BITSIZE_S_addr_ram=1, PORTSIZE_S_addr_ram=1,
    BITSIZE_S_Wdata_ram=8, PORTSIZE_S_Wdata_ram=1,
    BITSIZE_Sin_Rdata_ram=8, PORTSIZE_Sin_Rdata_ram=1,
    BITSIZE_Sout_Rdata_ram=8, PORTSIZE_Sout_Rdata_ram=1,
    BITSIZE_S_data_ram_size=1, PORTSIZE_S_data_ram_size=1,
    BITSIZE_Sin_DataRdy=1, PORTSIZE_Sin_DataRdy=1,
    BITSIZE_Sout_DataRdy=1, PORTSIZE_Sout_DataRdy=1,
    MEMORY_INIT_file_a="array_a.mem",
    MEMORY_INIT_file_b="array_b.mem",
    n_elements=1,
    data_size=32,
    address_space_begin=0,
    address_space_rangesize=4,
    BUS_PIPELINED=1,
    BRAM_BITSIZE=32,
    PRIVATE_MEMORY=0,
    READ_ONLY_MEMORY=0,
    USE_SPARSE_MEMORY=1,
    BITSIZE_proxy_in1=1, PORTSIZE_proxy_in1=1,
    BITSIZE_proxy_in2=1, PORTSIZE_proxy_in2=1,
    BITSIZE_proxy_in3=1, PORTSIZE_proxy_in3=1,
    BITSIZE_proxy_sel_LOAD=1, PORTSIZE_proxy_sel_LOAD=1,
    BITSIZE_proxy_sel_STORE=1, PORTSIZE_proxy_sel_STORE=1,
    BITSIZE_proxy_out1=1, PORTSIZE_proxy_out1=1;
  // IN
  input clock;
  input reset;
  input [(PORTSIZE_in1*BITSIZE_in1)+(-1):0] in1;
  input [(PORTSIZE_in2*BITSIZE_in2)+(-1):0] in2;
  input [(PORTSIZE_in3*BITSIZE_in3)+(-1):0] in3;
  input [PORTSIZE_in4-1:0] in4;
  input [PORTSIZE_sel_LOAD-1:0] sel_LOAD;
  input [PORTSIZE_sel_STORE-1:0] sel_STORE;
  input [PORTSIZE_S_oe_ram-1:0] S_oe_ram;
  input [PORTSIZE_S_we_ram-1:0] S_we_ram;
  input [(PORTSIZE_S_addr_ram*BITSIZE_S_addr_ram)+(-1):0] S_addr_ram;
  input [(PORTSIZE_S_Wdata_ram*BITSIZE_S_Wdata_ram)+(-1):0] S_Wdata_ram;
  input [(PORTSIZE_Sin_Rdata_ram*BITSIZE_Sin_Rdata_ram)+(-1):0] Sin_Rdata_ram;
  input [(PORTSIZE_S_data_ram_size*BITSIZE_S_data_ram_size)+(-1):0] S_data_ram_size;
  input [PORTSIZE_Sin_DataRdy-1:0] Sin_DataRdy;
  input [(PORTSIZE_proxy_in1*BITSIZE_proxy_in1)+(-1):0] proxy_in1;
  input [(PORTSIZE_proxy_in2*BITSIZE_proxy_in2)+(-1):0] proxy_in2;
  input [(PORTSIZE_proxy_in3*BITSIZE_proxy_in3)+(-1):0] proxy_in3;
  input [PORTSIZE_proxy_sel_LOAD-1:0] proxy_sel_LOAD;
  input [PORTSIZE_proxy_sel_STORE-1:0] proxy_sel_STORE;
  // OUT
  output [(PORTSIZE_out1*BITSIZE_out1)+(-1):0] out1;
  output [(PORTSIZE_Sout_Rdata_ram*BITSIZE_Sout_Rdata_ram)+(-1):0] Sout_Rdata_ram;
  output [PORTSIZE_Sout_DataRdy-1:0] Sout_DataRdy;
  output [(PORTSIZE_proxy_out1*BITSIZE_proxy_out1)+(-1):0] proxy_out1;
  
  ARRAY_1D_STD_BRAM_NN_SP #(
    .BITSIZE_in1(BITSIZE_in1),
    .PORTSIZE_in1(PORTSIZE_in1),
    .BITSIZE_in2(BITSIZE_in2),
    .PORTSIZE_in2(PORTSIZE_in2),
    .BITSIZE_in3(BITSIZE_in3),
    .PORTSIZE_in3(PORTSIZE_in3),
    .BITSIZE_sel_LOAD(BITSIZE_sel_LOAD),
    .PORTSIZE_sel_LOAD(PORTSIZE_sel_LOAD),
    .BITSIZE_sel_STORE(BITSIZE_sel_STORE),
    .PORTSIZE_sel_STORE(PORTSIZE_sel_STORE),
    .BITSIZE_S_oe_ram(BITSIZE_S_oe_ram),
    .PORTSIZE_S_oe_ram(PORTSIZE_S_oe_ram),
    .BITSIZE_S_we_ram(BITSIZE_S_we_ram),
    .PORTSIZE_S_we_ram(PORTSIZE_S_we_ram),
    .BITSIZE_out1(BITSIZE_out1),
    .PORTSIZE_out1(PORTSIZE_out1),
    .BITSIZE_S_addr_ram(BITSIZE_S_addr_ram),
    .PORTSIZE_S_addr_ram(PORTSIZE_S_addr_ram),
    .BITSIZE_S_Wdata_ram(BITSIZE_S_Wdata_ram),
    .PORTSIZE_S_Wdata_ram(PORTSIZE_S_Wdata_ram),
    .BITSIZE_Sin_Rdata_ram(BITSIZE_Sin_Rdata_ram),
    .PORTSIZE_Sin_Rdata_ram(PORTSIZE_Sin_Rdata_ram),
    .BITSIZE_Sout_Rdata_ram(BITSIZE_Sout_Rdata_ram),
    .PORTSIZE_Sout_Rdata_ram(PORTSIZE_Sout_Rdata_ram),
    .BITSIZE_S_data_ram_size(BITSIZE_S_data_ram_size),
    .PORTSIZE_S_data_ram_size(PORTSIZE_S_data_ram_size),
    .BITSIZE_Sin_DataRdy(BITSIZE_Sin_DataRdy),
    .PORTSIZE_Sin_DataRdy(PORTSIZE_Sin_DataRdy),
    .BITSIZE_Sout_DataRdy(BITSIZE_Sout_DataRdy),
    .PORTSIZE_Sout_DataRdy(PORTSIZE_Sout_DataRdy),
    .MEMORY_INIT_file_a(MEMORY_INIT_file_a),
    .MEMORY_INIT_file_b(MEMORY_INIT_file_b),
    .n_elements(n_elements),
    .data_size(data_size),
    .address_space_begin(address_space_begin),
    .address_space_rangesize(address_space_rangesize),
    .BUS_PIPELINED(BUS_PIPELINED),
    .BRAM_BITSIZE(BRAM_BITSIZE),
    .PRIVATE_MEMORY(PRIVATE_MEMORY),
    .READ_ONLY_MEMORY(READ_ONLY_MEMORY),
    .USE_SPARSE_MEMORY(USE_SPARSE_MEMORY),
    .BITSIZE_proxy_in1(BITSIZE_proxy_in1),
    .PORTSIZE_proxy_in1(PORTSIZE_proxy_in1),
    .BITSIZE_proxy_in2(BITSIZE_proxy_in2),
    .PORTSIZE_proxy_in2(PORTSIZE_proxy_in2),
    .BITSIZE_proxy_in3(BITSIZE_proxy_in3),
    .PORTSIZE_proxy_in3(PORTSIZE_proxy_in3),
    .BITSIZE_proxy_sel_LOAD(BITSIZE_proxy_sel_LOAD),
    .PORTSIZE_proxy_sel_LOAD(PORTSIZE_proxy_sel_LOAD),
    .BITSIZE_proxy_sel_STORE(BITSIZE_proxy_sel_STORE),
    .PORTSIZE_proxy_sel_STORE(PORTSIZE_proxy_sel_STORE),
    .BITSIZE_proxy_out1(BITSIZE_proxy_out1),
    .PORTSIZE_proxy_out1(PORTSIZE_proxy_out1),
    .HIGH_LATENCY(0)
  ) ARRAY_1D_STD_BRAM_NN_instance (.out1(out1),
    .Sout_Rdata_ram(Sout_Rdata_ram),
    .Sout_DataRdy(Sout_DataRdy),
    .proxy_out1(proxy_out1),
    .clock(clock),
    .reset(reset),
    .in1(in1),
    .in2(in2),
    .in3(in3),
    .sel_LOAD(sel_LOAD & in4),
    .sel_STORE(sel_STORE & in4),
    .S_oe_ram(S_oe_ram),
    .S_we_ram(S_we_ram),
    .S_addr_ram(S_addr_ram),
    .S_Wdata_ram(S_Wdata_ram),
    .Sin_Rdata_ram(Sin_Rdata_ram),
    .S_data_ram_size(S_data_ram_size),
    .Sin_DataRdy(Sin_DataRdy),
    .proxy_in1(proxy_in1),
    .proxy_in2(proxy_in2),
    .proxy_in3(proxy_in3),
    .proxy_sel_LOAD(proxy_sel_LOAD),
    .proxy_sel_STORE(proxy_sel_STORE));
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _addr_node_FU_DEFINED
`define _addr_node_FU_DEFINED
`timescale 1ns / 1ps
module addr_node_FU(in1,
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

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _multi_read_cond_FU_DEFINED
`define _multi_read_cond_FU_DEFINED
`timescale 1ns / 1ps
module multi_read_cond_FU(in1,
  out1);
  parameter BITSIZE_in1=1, PORTSIZE_in1=1,
    BITSIZE_out1=1;
  // IN
  input [(PORTSIZE_in1*BITSIZE_in1)+(-1):0] in1;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  assign out1 = in1;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _BMEMORY_CTRLN_DEFINED
`define _BMEMORY_CTRLN_DEFINED
`timescale 1ns / 1ps
module BMEMORY_CTRLN(clock,
  in1,
  in2,
  in3,
  in4,
  sel_LOAD,
  sel_STORE,
  out1,
  Min_oe_ram,
  Mout_oe_ram,
  Min_we_ram,
  Mout_we_ram,
  Min_addr_ram,
  Mout_addr_ram,
  M_Rdata_ram,
  Min_Wdata_ram,
  Mout_Wdata_ram,
  Min_data_ram_size,
  Mout_data_ram_size,
  M_DataRdy);
  parameter BITSIZE_in1=1, PORTSIZE_in1=1,
    BITSIZE_in2=1, PORTSIZE_in2=1,
    BITSIZE_in3=1, PORTSIZE_in3=1,
    BITSIZE_in4=1, PORTSIZE_in4=1,
    BITSIZE_sel_LOAD=1, PORTSIZE_sel_LOAD=1,
    BITSIZE_sel_STORE=1, PORTSIZE_sel_STORE=1,
    BITSIZE_out1=1, PORTSIZE_out1=1,
    BITSIZE_Min_oe_ram=1, PORTSIZE_Min_oe_ram=1,
    BITSIZE_Min_we_ram=1, PORTSIZE_Min_we_ram=1,
    BITSIZE_Mout_oe_ram=1, PORTSIZE_Mout_oe_ram=1,
    BITSIZE_Mout_we_ram=1, PORTSIZE_Mout_we_ram=1,
    BITSIZE_M_DataRdy=1, PORTSIZE_M_DataRdy=1,
    BITSIZE_Min_addr_ram=1, PORTSIZE_Min_addr_ram=1,
    BITSIZE_Mout_addr_ram=1, PORTSIZE_Mout_addr_ram=1,
    BITSIZE_M_Rdata_ram=8, PORTSIZE_M_Rdata_ram=1,
    BITSIZE_Min_Wdata_ram=8, PORTSIZE_Min_Wdata_ram=1,
    BITSIZE_Mout_Wdata_ram=8, PORTSIZE_Mout_Wdata_ram=1,
    BITSIZE_Min_data_ram_size=1, PORTSIZE_Min_data_ram_size=1,
    BITSIZE_Mout_data_ram_size=1, PORTSIZE_Mout_data_ram_size=1;
  // IN
  input clock;
  input [(PORTSIZE_in1*BITSIZE_in1)+(-1):0] in1;
  input [(PORTSIZE_in2*BITSIZE_in2)+(-1):0] in2;
  input [(PORTSIZE_in3*BITSIZE_in3)+(-1):0] in3;
  input [PORTSIZE_in4-1:0] in4;
  input [PORTSIZE_sel_LOAD-1:0] sel_LOAD;
  input [PORTSIZE_sel_STORE-1:0] sel_STORE;
  input [PORTSIZE_Min_oe_ram-1:0] Min_oe_ram;
  input [PORTSIZE_Min_we_ram-1:0] Min_we_ram;
  input [(PORTSIZE_Min_addr_ram*BITSIZE_Min_addr_ram)+(-1):0] Min_addr_ram;
  input [(PORTSIZE_M_Rdata_ram*BITSIZE_M_Rdata_ram)+(-1):0] M_Rdata_ram;
  input [(PORTSIZE_Min_Wdata_ram*BITSIZE_Min_Wdata_ram)+(-1):0] Min_Wdata_ram;
  input [(PORTSIZE_Min_data_ram_size*BITSIZE_Min_data_ram_size)+(-1):0] Min_data_ram_size;
  input [PORTSIZE_M_DataRdy-1:0] M_DataRdy;
  // OUT
  output [(PORTSIZE_out1*BITSIZE_out1)+(-1):0] out1;
  output [PORTSIZE_Mout_oe_ram-1:0] Mout_oe_ram;
  output [PORTSIZE_Mout_we_ram-1:0] Mout_we_ram;
  output [(PORTSIZE_Mout_addr_ram*BITSIZE_Mout_addr_ram)+(-1):0] Mout_addr_ram;
  output [(PORTSIZE_Mout_Wdata_ram*BITSIZE_Mout_Wdata_ram)+(-1):0] Mout_Wdata_ram;
  output [(PORTSIZE_Mout_data_ram_size*BITSIZE_Mout_data_ram_size)+(-1):0] Mout_data_ram_size;
  
  parameter max_n_writes = PORTSIZE_sel_STORE > PORTSIZE_Mout_we_ram ? PORTSIZE_sel_STORE : PORTSIZE_Mout_we_ram;
  parameter max_n_reads = PORTSIZE_sel_LOAD > PORTSIZE_Mout_oe_ram ? PORTSIZE_sel_STORE : PORTSIZE_Mout_oe_ram;
  parameter max_n_rw = max_n_writes > max_n_reads ? max_n_writes : max_n_reads;
  wire  [(PORTSIZE_in2*BITSIZE_in2)-1:0] tmp_addr;
  wire [PORTSIZE_sel_LOAD-1:0] int_sel_LOAD;
  wire [PORTSIZE_sel_STORE-1:0] int_sel_STORE;
  assign int_sel_LOAD = sel_LOAD & in4;
  assign int_sel_STORE = sel_STORE & in4;
  assign tmp_addr = in2;
  generate
  genvar i;
    for (i=0; i<max_n_rw; i=i+1)
    begin : L0
      assign Mout_addr_ram[(i+1)*BITSIZE_Mout_addr_ram-1:i*BITSIZE_Mout_addr_ram] = ((i < PORTSIZE_sel_LOAD && int_sel_LOAD[i]) || (i < PORTSIZE_sel_STORE && int_sel_STORE[i])) ? (tmp_addr[(i+1)*BITSIZE_in2-1:i*BITSIZE_in2]) : Min_addr_ram[(i+1)*BITSIZE_Min_addr_ram-1:i*BITSIZE_Min_addr_ram];
    end
    endgenerate
  assign Mout_oe_ram = int_sel_LOAD | Min_oe_ram;
  assign Mout_we_ram = int_sel_STORE | Min_we_ram;
  generate
    for (i=0; i<max_n_reads; i=i+1)
    begin : L1
      assign out1[(i+1)*BITSIZE_out1-1:i*BITSIZE_out1] = M_Rdata_ram[i*BITSIZE_M_Rdata_ram+BITSIZE_out1-1:i*BITSIZE_M_Rdata_ram];
  end
  endgenerate
  generate
    for (i=0; i<max_n_rw; i=i+1)
    begin : L2
      assign Mout_Wdata_ram[(i+1)*BITSIZE_Mout_Wdata_ram-1:i*BITSIZE_Mout_Wdata_ram] = int_sel_STORE[i] ? in1[(i+1)*BITSIZE_in1-1:i*BITSIZE_in1] : Min_Wdata_ram[(i+1)*BITSIZE_Min_Wdata_ram-1:i*BITSIZE_Min_Wdata_ram];
  end
  endgenerate
  generate
    for (i=0; i<max_n_rw; i=i+1)
    begin : L3
      assign Mout_data_ram_size[(i+1)*BITSIZE_Mout_data_ram_size-1:i*BITSIZE_Mout_data_ram_size] = ((i < PORTSIZE_sel_LOAD && int_sel_LOAD[i]) || (i < PORTSIZE_sel_STORE && int_sel_STORE[i])) ? (in3[(i+1)*BITSIZE_in3-1:i*BITSIZE_in3]) : Min_data_ram_size[(i+1)*BITSIZE_Min_data_ram_size-1:i*BITSIZE_Min_data_ram_size];
    end
    endgenerate

endmodule
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
`ifndef _ui_and_node_FU_DEFINED
`define _ui_and_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_and_node_FU(in1,
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
  assign out1 = in1 & in2;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2016-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_concat_bit_node_FU_DEFINED
`define _ui_concat_bit_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_concat_bit_node_FU(in1,
  in2,
  in3,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_in3=1,
    BITSIZE_out1=1,
    OFFSET_PARAMETER=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  input [BITSIZE_in3-1:0] in3;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  localparam nbit_out = BITSIZE_out1 > OFFSET_PARAMETER ? BITSIZE_out1 : 1+OFFSET_PARAMETER;
  wire [nbit_out-1:0] tmp_in1;
  wire [OFFSET_PARAMETER-1:0] tmp_in2;
  generate
    if(BITSIZE_in1 >= nbit_out)
      assign tmp_in1=in1[nbit_out-1:0];
    else
      assign tmp_in1={{(nbit_out-BITSIZE_in1){1'b0}},in1};
  endgenerate
  generate
    if(BITSIZE_in2 >= OFFSET_PARAMETER)
      assign tmp_in2=in2[OFFSET_PARAMETER-1:0];
    else
      assign tmp_in2={{(OFFSET_PARAMETER-BITSIZE_in2){1'b0}},in2};
  endgenerate
  assign out1 = {tmp_in1[nbit_out-1:OFFSET_PARAMETER] , tmp_in2};
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_eq_node_FU_DEFINED
`define _ui_eq_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_eq_node_FU(in1,
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
  assign out1 = in1 == in2;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_gep_node_FU_DEFINED
`define _ui_gep_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_gep_node_FU(in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1,
    LSB_PARAMETER=-1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  wire [BITSIZE_out1-1:0] in1_tmp;
  wire [BITSIZE_out1-1:0] in2_tmp;
  assign in1_tmp = in1;
  assign in2_tmp = in2;generate if (BITSIZE_out1 > LSB_PARAMETER) assign out1[BITSIZE_out1-1:LSB_PARAMETER] = (in1_tmp[BITSIZE_out1-1:LSB_PARAMETER] + in2_tmp[BITSIZE_out1-1:LSB_PARAMETER]); else assign out1 = 0; endgenerate
  generate if (LSB_PARAMETER != 0 && BITSIZE_out1 > LSB_PARAMETER) assign out1[LSB_PARAMETER-1:0] = 0; endgenerate
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_shl_node_FU_DEFINED
`define _ui_shl_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_shl_node_FU(in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1,
    PRECISION=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  `ifndef _SIM_HAVE_CLOG2
    function integer log2;
       input integer value;
       integer temp_value;
      begin
        temp_value = value-1;
        for (log2=0; temp_value>0; log2=log2+1)
          temp_value = temp_value>>1;
      end
    endfunction
  `endif
  `ifdef _SIM_HAVE_CLOG2
    localparam arg2_bitsize = $clog2(PRECISION);
  `else
    localparam arg2_bitsize = log2(PRECISION);
  `endif
  generate
    if(BITSIZE_in2 > arg2_bitsize)
      assign out1 = in1 << in2[arg2_bitsize-1:0];
    else
      assign out1 = in1 << in2;
  endgenerate
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_shr_node_FU_DEFINED
`define _ui_shr_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_shr_node_FU(in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1,
    PRECISION=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  `ifndef _SIM_HAVE_CLOG2
    function integer log2;
       input integer value;
       integer temp_value;
      begin
        temp_value = value-1;
        for (log2=0; temp_value>0; log2=log2+1)
          temp_value = temp_value>>1;
      end
    endfunction
  `endif
  `ifdef _SIM_HAVE_CLOG2
    localparam arg2_bitsize = $clog2(PRECISION);
  `else
    localparam arg2_bitsize = log2(PRECISION);
  `endif
  generate
    if(BITSIZE_in2 > arg2_bitsize)
      assign out1 = in1 >> (in2[arg2_bitsize-1:0]);
    else
      assign out1 = in1 >> in2;
  endgenerate

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_ternary_add_node_FU_DEFINED
`define _ui_ternary_add_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_ternary_add_node_FU(in1,
  in2,
  in3,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_in3=1,
    BITSIZE_out1=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  input [BITSIZE_in3-1:0] in3;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  assign out1 = in1 + in2 + in3;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _ui_ternary_sa_node_FU_DEFINED
`define _ui_ternary_sa_node_FU_DEFINED
`timescale 1ns / 1ps
module ui_ternary_sa_node_FU(in1,
  in2,
  in3,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_in3=1,
    BITSIZE_out1=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  input [BITSIZE_in3-1:0] in3;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  assign out1 = in1 - in2 + in3;
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _UUdata_converter_FU_DEFINED
`define _UUdata_converter_FU_DEFINED
`timescale 1ns / 1ps
module UUdata_converter_FU(in1,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_out1=1;
  // IN
  input [BITSIZE_in1-1:0] in1;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  generate
  if (BITSIZE_out1 <= BITSIZE_in1)
  begin
    assign out1 = in1[BITSIZE_out1-1:0];
  end
  else
  begin
    assign out1 = {{(BITSIZE_out1-BITSIZE_in1){1'b0}},in1};
  end
  endgenerate
endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2024-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _MUX2_GATE_DEFINED
`define _MUX2_GATE_DEFINED
`timescale 1ns / 1ps
module MUX2_GATE(sel,
  in1,
  in2,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_in2=1,
    BITSIZE_out1=1;
  // IN
  input sel;
  input [BITSIZE_in1-1:0] in1;
  input [BITSIZE_in2-1:0] in2;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  
  reg [BITSIZE_out1-1:0] out1;
  always @(*)
  begin
    if (sel == 1'b0)
    begin
      out1 = in2;
    end
    else
    begin
      out1 = in1;
    end
  end

endmodule
`endif

// This component is part of the PANDA/BAMBU IP LIBRARY
// Copyright (C) 2004-2026 Politecnico di Milano
// Author(s): Fabrizio Ferrandi <fabrizio.ferrandi@polimi.it>
// License: MIT
`ifndef _register_AR_DEFINED
`define _register_AR_DEFINED
`timescale 1ns / 1ps
module register_AR(clock,
  reset,
  in1,
  out1);
  parameter BITSIZE_in1=1,
    BITSIZE_out1=1;
  // IN
  input clock;
  input reset;
  input [BITSIZE_in1-1:0] in1;
  // OUT
  output [BITSIZE_out1-1:0] out1;
  
  reg [BITSIZE_out1-1:0] reg_out1 =0;
  assign out1 = reg_out1;
  always @(posedge clock or negedge reset)
    if (reset == 1'b0)
      reg_out1 <= {BITSIZE_out1{1'b0}};
    else
      reg_out1 <= in1;
endmodule
`endif


