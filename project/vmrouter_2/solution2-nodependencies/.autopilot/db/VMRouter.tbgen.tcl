set moduleName VMRouter
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set C_modelName {VMRouter}
set C_modelType { int 48 }
set C_modelArgList {
	{ stubsInLayer_0_data int 36 regular {array 64 { 1 3 } 1 1 }  }
	{ stubsInLayer_1_data int 36 regular {array 64 { 1 3 } 1 1 }  }
	{ stubsInLayer_2_data int 36 regular {array 64 { 1 3 } 1 1 }  }
	{ stubsInLayer_3_data int 36 regular {array 64 { 1 3 } 1 1 }  }
	{ stubsInLayer_4_data int 36 regular {array 64 { 1 3 } 1 1 }  }
	{ tmp_1 int 10 regular  }
	{ allStubs_0_data_V int 36 regular {array 64 { 0 3 } 0 1 }  }
	{ allStubs_1_data_V int 36 regular {array 64 { 0 3 } 0 1 }  }
	{ allStubs_2_data_V int 36 regular {array 64 { 0 3 } 0 1 }  }
	{ allStubs_3_data_V int 36 regular {array 64 { 0 3 } 0 1 }  }
	{ allStubs_4_data_V int 36 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_11 int 10 regular  }
	{ vmStubsPH1Z1_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z1_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z1_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z1_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z1_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_12 int 10 regular  }
	{ vmStubsPH2Z1_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z1_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z1_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z1_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z1_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_13 int 10 regular  }
	{ vmStubsPH3Z1_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z1_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z1_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z1_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z1_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_14 int 10 regular  }
	{ vmStubsPH4Z1_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z1_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z1_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z1_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z1_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_15 int 10 regular  }
	{ vmStubsPH1Z2_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z2_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z2_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z2_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH1Z2_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_16 int 10 regular  }
	{ vmStubsPH2Z2_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z2_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z2_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z2_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH2Z2_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_17 int 10 regular  }
	{ vmStubsPH3Z2_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z2_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z2_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z2_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH3Z2_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_18 int 10 regular  }
	{ vmStubsPH4Z2_0_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z2_1_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z2_2_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z2_3_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ vmStubsPH4Z2_4_data int 18 regular {array 64 { 0 3 } 0 1 }  }
	{ tmp_19 int 10 regular  }
	{ nStubs int 32 regular  }
	{ nPH1Z1_V_read int 6 regular  }
	{ nPH2Z1_V_read int 6 regular  }
	{ nPH3Z1_V_read int 6 regular  }
	{ nPH4Z1_V_read int 6 regular  }
	{ nPH1Z2_V_read int 6 regular  }
	{ nPH2Z2_V_read int 6 regular  }
	{ nPH3Z2_V_read int 6 regular  }
	{ nPH4Z2_V_read int 6 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "stubsInLayer_0_data", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "stubsInLayer_1_data", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "stubsInLayer_2_data", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "stubsInLayer_3_data", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "stubsInLayer_4_data", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY"} , 
 	{ "Name" : "tmp_1", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "allStubs_0_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "allStubs_1_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "allStubs_2_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "allStubs_3_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "allStubs_4_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_11", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH1Z1_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z1_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z1_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z1_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z1_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_12", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH2Z1_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z1_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z1_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z1_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z1_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_13", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH3Z1_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z1_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z1_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z1_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z1_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_14", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH4Z1_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z1_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z1_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z1_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z1_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_15", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH1Z2_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z2_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z2_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z2_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH1Z2_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_16", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH2Z2_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z2_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z2_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z2_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH2Z2_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_17", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH3Z2_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z2_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z2_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z2_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH3Z2_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_18", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "vmStubsPH4Z2_0_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z2_1_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z2_2_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z2_3_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "vmStubsPH4Z2_4_data", "interface" : "memory", "bitwidth" : 18, "direction" : "WRITEONLY"} , 
 	{ "Name" : "tmp_19", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY"} , 
 	{ "Name" : "nStubs", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "nPH1Z1_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH2Z1_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH3Z1_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH4Z1_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH1Z2_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH2Z2_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH3Z2_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "nPH4Z2_V_read", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 48} ]}
# RTL Port declarations: 
set portNum 228
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ stubsInLayer_0_data_address0 sc_out sc_lv 6 signal 0 } 
	{ stubsInLayer_0_data_ce0 sc_out sc_logic 1 signal 0 } 
	{ stubsInLayer_0_data_q0 sc_in sc_lv 36 signal 0 } 
	{ stubsInLayer_1_data_address0 sc_out sc_lv 6 signal 1 } 
	{ stubsInLayer_1_data_ce0 sc_out sc_logic 1 signal 1 } 
	{ stubsInLayer_1_data_q0 sc_in sc_lv 36 signal 1 } 
	{ stubsInLayer_2_data_address0 sc_out sc_lv 6 signal 2 } 
	{ stubsInLayer_2_data_ce0 sc_out sc_logic 1 signal 2 } 
	{ stubsInLayer_2_data_q0 sc_in sc_lv 36 signal 2 } 
	{ stubsInLayer_3_data_address0 sc_out sc_lv 6 signal 3 } 
	{ stubsInLayer_3_data_ce0 sc_out sc_logic 1 signal 3 } 
	{ stubsInLayer_3_data_q0 sc_in sc_lv 36 signal 3 } 
	{ stubsInLayer_4_data_address0 sc_out sc_lv 6 signal 4 } 
	{ stubsInLayer_4_data_ce0 sc_out sc_logic 1 signal 4 } 
	{ stubsInLayer_4_data_q0 sc_in sc_lv 36 signal 4 } 
	{ tmp_1 sc_in sc_lv 10 signal 5 } 
	{ allStubs_0_data_V_address0 sc_out sc_lv 6 signal 6 } 
	{ allStubs_0_data_V_ce0 sc_out sc_logic 1 signal 6 } 
	{ allStubs_0_data_V_we0 sc_out sc_logic 1 signal 6 } 
	{ allStubs_0_data_V_d0 sc_out sc_lv 36 signal 6 } 
	{ allStubs_1_data_V_address0 sc_out sc_lv 6 signal 7 } 
	{ allStubs_1_data_V_ce0 sc_out sc_logic 1 signal 7 } 
	{ allStubs_1_data_V_we0 sc_out sc_logic 1 signal 7 } 
	{ allStubs_1_data_V_d0 sc_out sc_lv 36 signal 7 } 
	{ allStubs_2_data_V_address0 sc_out sc_lv 6 signal 8 } 
	{ allStubs_2_data_V_ce0 sc_out sc_logic 1 signal 8 } 
	{ allStubs_2_data_V_we0 sc_out sc_logic 1 signal 8 } 
	{ allStubs_2_data_V_d0 sc_out sc_lv 36 signal 8 } 
	{ allStubs_3_data_V_address0 sc_out sc_lv 6 signal 9 } 
	{ allStubs_3_data_V_ce0 sc_out sc_logic 1 signal 9 } 
	{ allStubs_3_data_V_we0 sc_out sc_logic 1 signal 9 } 
	{ allStubs_3_data_V_d0 sc_out sc_lv 36 signal 9 } 
	{ allStubs_4_data_V_address0 sc_out sc_lv 6 signal 10 } 
	{ allStubs_4_data_V_ce0 sc_out sc_logic 1 signal 10 } 
	{ allStubs_4_data_V_we0 sc_out sc_logic 1 signal 10 } 
	{ allStubs_4_data_V_d0 sc_out sc_lv 36 signal 10 } 
	{ tmp_11 sc_in sc_lv 10 signal 11 } 
	{ vmStubsPH1Z1_0_data_address0 sc_out sc_lv 6 signal 12 } 
	{ vmStubsPH1Z1_0_data_ce0 sc_out sc_logic 1 signal 12 } 
	{ vmStubsPH1Z1_0_data_we0 sc_out sc_logic 1 signal 12 } 
	{ vmStubsPH1Z1_0_data_d0 sc_out sc_lv 18 signal 12 } 
	{ vmStubsPH1Z1_1_data_address0 sc_out sc_lv 6 signal 13 } 
	{ vmStubsPH1Z1_1_data_ce0 sc_out sc_logic 1 signal 13 } 
	{ vmStubsPH1Z1_1_data_we0 sc_out sc_logic 1 signal 13 } 
	{ vmStubsPH1Z1_1_data_d0 sc_out sc_lv 18 signal 13 } 
	{ vmStubsPH1Z1_2_data_address0 sc_out sc_lv 6 signal 14 } 
	{ vmStubsPH1Z1_2_data_ce0 sc_out sc_logic 1 signal 14 } 
	{ vmStubsPH1Z1_2_data_we0 sc_out sc_logic 1 signal 14 } 
	{ vmStubsPH1Z1_2_data_d0 sc_out sc_lv 18 signal 14 } 
	{ vmStubsPH1Z1_3_data_address0 sc_out sc_lv 6 signal 15 } 
	{ vmStubsPH1Z1_3_data_ce0 sc_out sc_logic 1 signal 15 } 
	{ vmStubsPH1Z1_3_data_we0 sc_out sc_logic 1 signal 15 } 
	{ vmStubsPH1Z1_3_data_d0 sc_out sc_lv 18 signal 15 } 
	{ vmStubsPH1Z1_4_data_address0 sc_out sc_lv 6 signal 16 } 
	{ vmStubsPH1Z1_4_data_ce0 sc_out sc_logic 1 signal 16 } 
	{ vmStubsPH1Z1_4_data_we0 sc_out sc_logic 1 signal 16 } 
	{ vmStubsPH1Z1_4_data_d0 sc_out sc_lv 18 signal 16 } 
	{ tmp_12 sc_in sc_lv 10 signal 17 } 
	{ vmStubsPH2Z1_0_data_address0 sc_out sc_lv 6 signal 18 } 
	{ vmStubsPH2Z1_0_data_ce0 sc_out sc_logic 1 signal 18 } 
	{ vmStubsPH2Z1_0_data_we0 sc_out sc_logic 1 signal 18 } 
	{ vmStubsPH2Z1_0_data_d0 sc_out sc_lv 18 signal 18 } 
	{ vmStubsPH2Z1_1_data_address0 sc_out sc_lv 6 signal 19 } 
	{ vmStubsPH2Z1_1_data_ce0 sc_out sc_logic 1 signal 19 } 
	{ vmStubsPH2Z1_1_data_we0 sc_out sc_logic 1 signal 19 } 
	{ vmStubsPH2Z1_1_data_d0 sc_out sc_lv 18 signal 19 } 
	{ vmStubsPH2Z1_2_data_address0 sc_out sc_lv 6 signal 20 } 
	{ vmStubsPH2Z1_2_data_ce0 sc_out sc_logic 1 signal 20 } 
	{ vmStubsPH2Z1_2_data_we0 sc_out sc_logic 1 signal 20 } 
	{ vmStubsPH2Z1_2_data_d0 sc_out sc_lv 18 signal 20 } 
	{ vmStubsPH2Z1_3_data_address0 sc_out sc_lv 6 signal 21 } 
	{ vmStubsPH2Z1_3_data_ce0 sc_out sc_logic 1 signal 21 } 
	{ vmStubsPH2Z1_3_data_we0 sc_out sc_logic 1 signal 21 } 
	{ vmStubsPH2Z1_3_data_d0 sc_out sc_lv 18 signal 21 } 
	{ vmStubsPH2Z1_4_data_address0 sc_out sc_lv 6 signal 22 } 
	{ vmStubsPH2Z1_4_data_ce0 sc_out sc_logic 1 signal 22 } 
	{ vmStubsPH2Z1_4_data_we0 sc_out sc_logic 1 signal 22 } 
	{ vmStubsPH2Z1_4_data_d0 sc_out sc_lv 18 signal 22 } 
	{ tmp_13 sc_in sc_lv 10 signal 23 } 
	{ vmStubsPH3Z1_0_data_address0 sc_out sc_lv 6 signal 24 } 
	{ vmStubsPH3Z1_0_data_ce0 sc_out sc_logic 1 signal 24 } 
	{ vmStubsPH3Z1_0_data_we0 sc_out sc_logic 1 signal 24 } 
	{ vmStubsPH3Z1_0_data_d0 sc_out sc_lv 18 signal 24 } 
	{ vmStubsPH3Z1_1_data_address0 sc_out sc_lv 6 signal 25 } 
	{ vmStubsPH3Z1_1_data_ce0 sc_out sc_logic 1 signal 25 } 
	{ vmStubsPH3Z1_1_data_we0 sc_out sc_logic 1 signal 25 } 
	{ vmStubsPH3Z1_1_data_d0 sc_out sc_lv 18 signal 25 } 
	{ vmStubsPH3Z1_2_data_address0 sc_out sc_lv 6 signal 26 } 
	{ vmStubsPH3Z1_2_data_ce0 sc_out sc_logic 1 signal 26 } 
	{ vmStubsPH3Z1_2_data_we0 sc_out sc_logic 1 signal 26 } 
	{ vmStubsPH3Z1_2_data_d0 sc_out sc_lv 18 signal 26 } 
	{ vmStubsPH3Z1_3_data_address0 sc_out sc_lv 6 signal 27 } 
	{ vmStubsPH3Z1_3_data_ce0 sc_out sc_logic 1 signal 27 } 
	{ vmStubsPH3Z1_3_data_we0 sc_out sc_logic 1 signal 27 } 
	{ vmStubsPH3Z1_3_data_d0 sc_out sc_lv 18 signal 27 } 
	{ vmStubsPH3Z1_4_data_address0 sc_out sc_lv 6 signal 28 } 
	{ vmStubsPH3Z1_4_data_ce0 sc_out sc_logic 1 signal 28 } 
	{ vmStubsPH3Z1_4_data_we0 sc_out sc_logic 1 signal 28 } 
	{ vmStubsPH3Z1_4_data_d0 sc_out sc_lv 18 signal 28 } 
	{ tmp_14 sc_in sc_lv 10 signal 29 } 
	{ vmStubsPH4Z1_0_data_address0 sc_out sc_lv 6 signal 30 } 
	{ vmStubsPH4Z1_0_data_ce0 sc_out sc_logic 1 signal 30 } 
	{ vmStubsPH4Z1_0_data_we0 sc_out sc_logic 1 signal 30 } 
	{ vmStubsPH4Z1_0_data_d0 sc_out sc_lv 18 signal 30 } 
	{ vmStubsPH4Z1_1_data_address0 sc_out sc_lv 6 signal 31 } 
	{ vmStubsPH4Z1_1_data_ce0 sc_out sc_logic 1 signal 31 } 
	{ vmStubsPH4Z1_1_data_we0 sc_out sc_logic 1 signal 31 } 
	{ vmStubsPH4Z1_1_data_d0 sc_out sc_lv 18 signal 31 } 
	{ vmStubsPH4Z1_2_data_address0 sc_out sc_lv 6 signal 32 } 
	{ vmStubsPH4Z1_2_data_ce0 sc_out sc_logic 1 signal 32 } 
	{ vmStubsPH4Z1_2_data_we0 sc_out sc_logic 1 signal 32 } 
	{ vmStubsPH4Z1_2_data_d0 sc_out sc_lv 18 signal 32 } 
	{ vmStubsPH4Z1_3_data_address0 sc_out sc_lv 6 signal 33 } 
	{ vmStubsPH4Z1_3_data_ce0 sc_out sc_logic 1 signal 33 } 
	{ vmStubsPH4Z1_3_data_we0 sc_out sc_logic 1 signal 33 } 
	{ vmStubsPH4Z1_3_data_d0 sc_out sc_lv 18 signal 33 } 
	{ vmStubsPH4Z1_4_data_address0 sc_out sc_lv 6 signal 34 } 
	{ vmStubsPH4Z1_4_data_ce0 sc_out sc_logic 1 signal 34 } 
	{ vmStubsPH4Z1_4_data_we0 sc_out sc_logic 1 signal 34 } 
	{ vmStubsPH4Z1_4_data_d0 sc_out sc_lv 18 signal 34 } 
	{ tmp_15 sc_in sc_lv 10 signal 35 } 
	{ vmStubsPH1Z2_0_data_address0 sc_out sc_lv 6 signal 36 } 
	{ vmStubsPH1Z2_0_data_ce0 sc_out sc_logic 1 signal 36 } 
	{ vmStubsPH1Z2_0_data_we0 sc_out sc_logic 1 signal 36 } 
	{ vmStubsPH1Z2_0_data_d0 sc_out sc_lv 18 signal 36 } 
	{ vmStubsPH1Z2_1_data_address0 sc_out sc_lv 6 signal 37 } 
	{ vmStubsPH1Z2_1_data_ce0 sc_out sc_logic 1 signal 37 } 
	{ vmStubsPH1Z2_1_data_we0 sc_out sc_logic 1 signal 37 } 
	{ vmStubsPH1Z2_1_data_d0 sc_out sc_lv 18 signal 37 } 
	{ vmStubsPH1Z2_2_data_address0 sc_out sc_lv 6 signal 38 } 
	{ vmStubsPH1Z2_2_data_ce0 sc_out sc_logic 1 signal 38 } 
	{ vmStubsPH1Z2_2_data_we0 sc_out sc_logic 1 signal 38 } 
	{ vmStubsPH1Z2_2_data_d0 sc_out sc_lv 18 signal 38 } 
	{ vmStubsPH1Z2_3_data_address0 sc_out sc_lv 6 signal 39 } 
	{ vmStubsPH1Z2_3_data_ce0 sc_out sc_logic 1 signal 39 } 
	{ vmStubsPH1Z2_3_data_we0 sc_out sc_logic 1 signal 39 } 
	{ vmStubsPH1Z2_3_data_d0 sc_out sc_lv 18 signal 39 } 
	{ vmStubsPH1Z2_4_data_address0 sc_out sc_lv 6 signal 40 } 
	{ vmStubsPH1Z2_4_data_ce0 sc_out sc_logic 1 signal 40 } 
	{ vmStubsPH1Z2_4_data_we0 sc_out sc_logic 1 signal 40 } 
	{ vmStubsPH1Z2_4_data_d0 sc_out sc_lv 18 signal 40 } 
	{ tmp_16 sc_in sc_lv 10 signal 41 } 
	{ vmStubsPH2Z2_0_data_address0 sc_out sc_lv 6 signal 42 } 
	{ vmStubsPH2Z2_0_data_ce0 sc_out sc_logic 1 signal 42 } 
	{ vmStubsPH2Z2_0_data_we0 sc_out sc_logic 1 signal 42 } 
	{ vmStubsPH2Z2_0_data_d0 sc_out sc_lv 18 signal 42 } 
	{ vmStubsPH2Z2_1_data_address0 sc_out sc_lv 6 signal 43 } 
	{ vmStubsPH2Z2_1_data_ce0 sc_out sc_logic 1 signal 43 } 
	{ vmStubsPH2Z2_1_data_we0 sc_out sc_logic 1 signal 43 } 
	{ vmStubsPH2Z2_1_data_d0 sc_out sc_lv 18 signal 43 } 
	{ vmStubsPH2Z2_2_data_address0 sc_out sc_lv 6 signal 44 } 
	{ vmStubsPH2Z2_2_data_ce0 sc_out sc_logic 1 signal 44 } 
	{ vmStubsPH2Z2_2_data_we0 sc_out sc_logic 1 signal 44 } 
	{ vmStubsPH2Z2_2_data_d0 sc_out sc_lv 18 signal 44 } 
	{ vmStubsPH2Z2_3_data_address0 sc_out sc_lv 6 signal 45 } 
	{ vmStubsPH2Z2_3_data_ce0 sc_out sc_logic 1 signal 45 } 
	{ vmStubsPH2Z2_3_data_we0 sc_out sc_logic 1 signal 45 } 
	{ vmStubsPH2Z2_3_data_d0 sc_out sc_lv 18 signal 45 } 
	{ vmStubsPH2Z2_4_data_address0 sc_out sc_lv 6 signal 46 } 
	{ vmStubsPH2Z2_4_data_ce0 sc_out sc_logic 1 signal 46 } 
	{ vmStubsPH2Z2_4_data_we0 sc_out sc_logic 1 signal 46 } 
	{ vmStubsPH2Z2_4_data_d0 sc_out sc_lv 18 signal 46 } 
	{ tmp_17 sc_in sc_lv 10 signal 47 } 
	{ vmStubsPH3Z2_0_data_address0 sc_out sc_lv 6 signal 48 } 
	{ vmStubsPH3Z2_0_data_ce0 sc_out sc_logic 1 signal 48 } 
	{ vmStubsPH3Z2_0_data_we0 sc_out sc_logic 1 signal 48 } 
	{ vmStubsPH3Z2_0_data_d0 sc_out sc_lv 18 signal 48 } 
	{ vmStubsPH3Z2_1_data_address0 sc_out sc_lv 6 signal 49 } 
	{ vmStubsPH3Z2_1_data_ce0 sc_out sc_logic 1 signal 49 } 
	{ vmStubsPH3Z2_1_data_we0 sc_out sc_logic 1 signal 49 } 
	{ vmStubsPH3Z2_1_data_d0 sc_out sc_lv 18 signal 49 } 
	{ vmStubsPH3Z2_2_data_address0 sc_out sc_lv 6 signal 50 } 
	{ vmStubsPH3Z2_2_data_ce0 sc_out sc_logic 1 signal 50 } 
	{ vmStubsPH3Z2_2_data_we0 sc_out sc_logic 1 signal 50 } 
	{ vmStubsPH3Z2_2_data_d0 sc_out sc_lv 18 signal 50 } 
	{ vmStubsPH3Z2_3_data_address0 sc_out sc_lv 6 signal 51 } 
	{ vmStubsPH3Z2_3_data_ce0 sc_out sc_logic 1 signal 51 } 
	{ vmStubsPH3Z2_3_data_we0 sc_out sc_logic 1 signal 51 } 
	{ vmStubsPH3Z2_3_data_d0 sc_out sc_lv 18 signal 51 } 
	{ vmStubsPH3Z2_4_data_address0 sc_out sc_lv 6 signal 52 } 
	{ vmStubsPH3Z2_4_data_ce0 sc_out sc_logic 1 signal 52 } 
	{ vmStubsPH3Z2_4_data_we0 sc_out sc_logic 1 signal 52 } 
	{ vmStubsPH3Z2_4_data_d0 sc_out sc_lv 18 signal 52 } 
	{ tmp_18 sc_in sc_lv 10 signal 53 } 
	{ vmStubsPH4Z2_0_data_address0 sc_out sc_lv 6 signal 54 } 
	{ vmStubsPH4Z2_0_data_ce0 sc_out sc_logic 1 signal 54 } 
	{ vmStubsPH4Z2_0_data_we0 sc_out sc_logic 1 signal 54 } 
	{ vmStubsPH4Z2_0_data_d0 sc_out sc_lv 18 signal 54 } 
	{ vmStubsPH4Z2_1_data_address0 sc_out sc_lv 6 signal 55 } 
	{ vmStubsPH4Z2_1_data_ce0 sc_out sc_logic 1 signal 55 } 
	{ vmStubsPH4Z2_1_data_we0 sc_out sc_logic 1 signal 55 } 
	{ vmStubsPH4Z2_1_data_d0 sc_out sc_lv 18 signal 55 } 
	{ vmStubsPH4Z2_2_data_address0 sc_out sc_lv 6 signal 56 } 
	{ vmStubsPH4Z2_2_data_ce0 sc_out sc_logic 1 signal 56 } 
	{ vmStubsPH4Z2_2_data_we0 sc_out sc_logic 1 signal 56 } 
	{ vmStubsPH4Z2_2_data_d0 sc_out sc_lv 18 signal 56 } 
	{ vmStubsPH4Z2_3_data_address0 sc_out sc_lv 6 signal 57 } 
	{ vmStubsPH4Z2_3_data_ce0 sc_out sc_logic 1 signal 57 } 
	{ vmStubsPH4Z2_3_data_we0 sc_out sc_logic 1 signal 57 } 
	{ vmStubsPH4Z2_3_data_d0 sc_out sc_lv 18 signal 57 } 
	{ vmStubsPH4Z2_4_data_address0 sc_out sc_lv 6 signal 58 } 
	{ vmStubsPH4Z2_4_data_ce0 sc_out sc_logic 1 signal 58 } 
	{ vmStubsPH4Z2_4_data_we0 sc_out sc_logic 1 signal 58 } 
	{ vmStubsPH4Z2_4_data_d0 sc_out sc_lv 18 signal 58 } 
	{ tmp_19 sc_in sc_lv 10 signal 59 } 
	{ nStubs sc_in sc_lv 32 signal 60 } 
	{ nPH1Z1_V_read sc_in sc_lv 6 signal 61 } 
	{ nPH2Z1_V_read sc_in sc_lv 6 signal 62 } 
	{ nPH3Z1_V_read sc_in sc_lv 6 signal 63 } 
	{ nPH4Z1_V_read sc_in sc_lv 6 signal 64 } 
	{ nPH1Z2_V_read sc_in sc_lv 6 signal 65 } 
	{ nPH2Z2_V_read sc_in sc_lv 6 signal 66 } 
	{ nPH3Z2_V_read sc_in sc_lv 6 signal 67 } 
	{ nPH4Z2_V_read sc_in sc_lv 6 signal 68 } 
	{ ap_return_0 sc_out sc_lv 6 signal -1 } 
	{ ap_return_1 sc_out sc_lv 6 signal -1 } 
	{ ap_return_2 sc_out sc_lv 6 signal -1 } 
	{ ap_return_3 sc_out sc_lv 6 signal -1 } 
	{ ap_return_4 sc_out sc_lv 6 signal -1 } 
	{ ap_return_5 sc_out sc_lv 6 signal -1 } 
	{ ap_return_6 sc_out sc_lv 6 signal -1 } 
	{ ap_return_7 sc_out sc_lv 6 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "stubsInLayer_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "stubsInLayer_0_data", "role": "address0" }} , 
 	{ "name": "stubsInLayer_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stubsInLayer_0_data", "role": "ce0" }} , 
 	{ "name": "stubsInLayer_0_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "stubsInLayer_0_data", "role": "q0" }} , 
 	{ "name": "stubsInLayer_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "stubsInLayer_1_data", "role": "address0" }} , 
 	{ "name": "stubsInLayer_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stubsInLayer_1_data", "role": "ce0" }} , 
 	{ "name": "stubsInLayer_1_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "stubsInLayer_1_data", "role": "q0" }} , 
 	{ "name": "stubsInLayer_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "stubsInLayer_2_data", "role": "address0" }} , 
 	{ "name": "stubsInLayer_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stubsInLayer_2_data", "role": "ce0" }} , 
 	{ "name": "stubsInLayer_2_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "stubsInLayer_2_data", "role": "q0" }} , 
 	{ "name": "stubsInLayer_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "stubsInLayer_3_data", "role": "address0" }} , 
 	{ "name": "stubsInLayer_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stubsInLayer_3_data", "role": "ce0" }} , 
 	{ "name": "stubsInLayer_3_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "stubsInLayer_3_data", "role": "q0" }} , 
 	{ "name": "stubsInLayer_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "stubsInLayer_4_data", "role": "address0" }} , 
 	{ "name": "stubsInLayer_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stubsInLayer_4_data", "role": "ce0" }} , 
 	{ "name": "stubsInLayer_4_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "stubsInLayer_4_data", "role": "q0" }} , 
 	{ "name": "tmp_1", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_1", "role": "default" }} , 
 	{ "name": "allStubs_0_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "allStubs_0_data_V", "role": "address0" }} , 
 	{ "name": "allStubs_0_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_0_data_V", "role": "ce0" }} , 
 	{ "name": "allStubs_0_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_0_data_V", "role": "we0" }} , 
 	{ "name": "allStubs_0_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "allStubs_0_data_V", "role": "d0" }} , 
 	{ "name": "allStubs_1_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "allStubs_1_data_V", "role": "address0" }} , 
 	{ "name": "allStubs_1_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_1_data_V", "role": "ce0" }} , 
 	{ "name": "allStubs_1_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_1_data_V", "role": "we0" }} , 
 	{ "name": "allStubs_1_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "allStubs_1_data_V", "role": "d0" }} , 
 	{ "name": "allStubs_2_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "allStubs_2_data_V", "role": "address0" }} , 
 	{ "name": "allStubs_2_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_2_data_V", "role": "ce0" }} , 
 	{ "name": "allStubs_2_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_2_data_V", "role": "we0" }} , 
 	{ "name": "allStubs_2_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "allStubs_2_data_V", "role": "d0" }} , 
 	{ "name": "allStubs_3_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "allStubs_3_data_V", "role": "address0" }} , 
 	{ "name": "allStubs_3_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_3_data_V", "role": "ce0" }} , 
 	{ "name": "allStubs_3_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_3_data_V", "role": "we0" }} , 
 	{ "name": "allStubs_3_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "allStubs_3_data_V", "role": "d0" }} , 
 	{ "name": "allStubs_4_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "allStubs_4_data_V", "role": "address0" }} , 
 	{ "name": "allStubs_4_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_4_data_V", "role": "ce0" }} , 
 	{ "name": "allStubs_4_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "allStubs_4_data_V", "role": "we0" }} , 
 	{ "name": "allStubs_4_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "allStubs_4_data_V", "role": "d0" }} , 
 	{ "name": "tmp_11", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_11", "role": "default" }} , 
 	{ "name": "vmStubsPH1Z1_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z1_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z1_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z1_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z1_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z1_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z1_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z1_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z1_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z1_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z1_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z1_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z1_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z1_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z1_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z1_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z1_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z1_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z1_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z1_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z1_4_data", "role": "d0" }} , 
 	{ "name": "tmp_12", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_12", "role": "default" }} , 
 	{ "name": "vmStubsPH2Z1_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z1_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z1_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z1_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z1_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z1_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z1_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z1_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z1_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z1_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z1_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z1_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z1_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z1_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z1_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z1_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z1_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z1_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z1_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z1_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z1_4_data", "role": "d0" }} , 
 	{ "name": "tmp_13", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_13", "role": "default" }} , 
 	{ "name": "vmStubsPH3Z1_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z1_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z1_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z1_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z1_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z1_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z1_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z1_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z1_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z1_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z1_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z1_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z1_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z1_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z1_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z1_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z1_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z1_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z1_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z1_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z1_4_data", "role": "d0" }} , 
 	{ "name": "tmp_14", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_14", "role": "default" }} , 
 	{ "name": "vmStubsPH4Z1_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z1_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z1_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z1_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z1_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z1_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z1_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z1_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z1_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z1_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z1_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z1_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z1_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z1_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z1_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z1_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z1_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z1_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z1_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z1_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z1_4_data", "role": "d0" }} , 
 	{ "name": "tmp_15", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_15", "role": "default" }} , 
 	{ "name": "vmStubsPH1Z2_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z2_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z2_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z2_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z2_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z2_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z2_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z2_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z2_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z2_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z2_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z2_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z2_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z2_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z2_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z2_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH1Z2_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH1Z2_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH1Z2_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH1Z2_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH1Z2_4_data", "role": "d0" }} , 
 	{ "name": "tmp_16", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_16", "role": "default" }} , 
 	{ "name": "vmStubsPH2Z2_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z2_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z2_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z2_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z2_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z2_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z2_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z2_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z2_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z2_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z2_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z2_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z2_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z2_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z2_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z2_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH2Z2_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH2Z2_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH2Z2_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH2Z2_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH2Z2_4_data", "role": "d0" }} , 
 	{ "name": "tmp_17", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_17", "role": "default" }} , 
 	{ "name": "vmStubsPH3Z2_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z2_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z2_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z2_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z2_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z2_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z2_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z2_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z2_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z2_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z2_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z2_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z2_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z2_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z2_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z2_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH3Z2_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH3Z2_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH3Z2_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH3Z2_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH3Z2_4_data", "role": "d0" }} , 
 	{ "name": "tmp_18", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_18", "role": "default" }} , 
 	{ "name": "vmStubsPH4Z2_0_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_0_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z2_0_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_0_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z2_0_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_0_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z2_0_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_0_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z2_1_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_1_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z2_1_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_1_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z2_1_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_1_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z2_1_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_1_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z2_2_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_2_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z2_2_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_2_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z2_2_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_2_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z2_2_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_2_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z2_3_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_3_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z2_3_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_3_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z2_3_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_3_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z2_3_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_3_data", "role": "d0" }} , 
 	{ "name": "vmStubsPH4Z2_4_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_4_data", "role": "address0" }} , 
 	{ "name": "vmStubsPH4Z2_4_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_4_data", "role": "ce0" }} , 
 	{ "name": "vmStubsPH4Z2_4_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_4_data", "role": "we0" }} , 
 	{ "name": "vmStubsPH4Z2_4_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":18, "type": "signal", "bundle":{"name": "vmStubsPH4Z2_4_data", "role": "d0" }} , 
 	{ "name": "tmp_19", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "tmp_19", "role": "default" }} , 
 	{ "name": "nStubs", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "nStubs", "role": "default" }} , 
 	{ "name": "nPH1Z1_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH1Z1_V_read", "role": "default" }} , 
 	{ "name": "nPH2Z1_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH2Z1_V_read", "role": "default" }} , 
 	{ "name": "nPH3Z1_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH3Z1_V_read", "role": "default" }} , 
 	{ "name": "nPH4Z1_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH4Z1_V_read", "role": "default" }} , 
 	{ "name": "nPH1Z2_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH1Z2_V_read", "role": "default" }} , 
 	{ "name": "nPH2Z2_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH2Z2_V_read", "role": "default" }} , 
 	{ "name": "nPH3Z2_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH3Z2_V_read", "role": "default" }} , 
 	{ "name": "nPH4Z2_V_read", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "nPH4Z2_V_read", "role": "default" }} , 
 	{ "name": "ap_return_0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_0", "role": "default" }} , 
 	{ "name": "ap_return_1", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_1", "role": "default" }} , 
 	{ "name": "ap_return_2", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_2", "role": "default" }} , 
 	{ "name": "ap_return_3", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_3", "role": "default" }} , 
 	{ "name": "ap_return_4", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_4", "role": "default" }} , 
 	{ "name": "ap_return_5", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_5", "role": "default" }} , 
 	{ "name": "ap_return_6", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_6", "role": "default" }} , 
 	{ "name": "ap_return_7", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_7", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "VMRouter",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "AlignedPipeline" : "0", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"VariableLatency" : "1",
		"Port" : [
			{"Name" : "stubsInLayer_0_data", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stubsInLayer_1_data", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stubsInLayer_2_data", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stubsInLayer_3_data", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "stubsInLayer_4_data", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "tmp_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "allStubs_0_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "allStubs_1_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "allStubs_2_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "allStubs_3_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "allStubs_4_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_11", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH1Z1_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z1_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z1_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z1_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z1_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_12", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH2Z1_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z1_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z1_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z1_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z1_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_13", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH3Z1_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z1_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z1_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z1_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z1_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_14", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH4Z1_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z1_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z1_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z1_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z1_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_15", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH1Z2_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z2_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z2_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z2_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH1Z2_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_16", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH2Z2_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z2_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z2_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z2_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH2Z2_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_17", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH3Z2_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z2_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z2_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z2_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH3Z2_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_18", "Type" : "None", "Direction" : "I"},
			{"Name" : "vmStubsPH4Z2_0_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z2_1_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z2_2_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z2_3_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "vmStubsPH4Z2_4_data", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "tmp_19", "Type" : "None", "Direction" : "I"},
			{"Name" : "nStubs", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH1Z1_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH2Z1_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH3Z1_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH4Z1_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH1Z2_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH2Z2_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH3Z2_V_read", "Type" : "None", "Direction" : "I"},
			{"Name" : "nPH4Z2_V_read", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.VMRouterDispatchebkb_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	VMRouter {
		stubsInLayer_0_data {Type I LastRead 2 FirstWrite -1}
		stubsInLayer_1_data {Type I LastRead 2 FirstWrite -1}
		stubsInLayer_2_data {Type I LastRead 2 FirstWrite -1}
		stubsInLayer_3_data {Type I LastRead 2 FirstWrite -1}
		stubsInLayer_4_data {Type I LastRead 2 FirstWrite -1}
		tmp_1 {Type I LastRead 0 FirstWrite -1}
		allStubs_0_data_V {Type O LastRead -1 FirstWrite 4}
		allStubs_1_data_V {Type O LastRead -1 FirstWrite 4}
		allStubs_2_data_V {Type O LastRead -1 FirstWrite 4}
		allStubs_3_data_V {Type O LastRead -1 FirstWrite 4}
		allStubs_4_data_V {Type O LastRead -1 FirstWrite 4}
		tmp_11 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH1Z1_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z1_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z1_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z1_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z1_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_12 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH2Z1_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z1_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z1_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z1_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z1_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_13 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH3Z1_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z1_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z1_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z1_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z1_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_14 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH4Z1_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z1_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z1_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z1_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z1_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_15 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH1Z2_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z2_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z2_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z2_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH1Z2_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_16 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH2Z2_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z2_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z2_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z2_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH2Z2_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_17 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH3Z2_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z2_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z2_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z2_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH3Z2_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_18 {Type I LastRead 0 FirstWrite -1}
		vmStubsPH4Z2_0_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z2_1_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z2_2_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z2_3_data {Type O LastRead -1 FirstWrite 4}
		vmStubsPH4Z2_4_data {Type O LastRead -1 FirstWrite 4}
		tmp_19 {Type I LastRead 0 FirstWrite -1}
		nStubs {Type I LastRead 0 FirstWrite -1}
		nPH1Z1_V_read {Type I LastRead 0 FirstWrite -1}
		nPH2Z1_V_read {Type I LastRead 0 FirstWrite -1}
		nPH3Z1_V_read {Type I LastRead 0 FirstWrite -1}
		nPH4Z1_V_read {Type I LastRead 0 FirstWrite -1}
		nPH1Z2_V_read {Type I LastRead 0 FirstWrite -1}
		nPH2Z2_V_read {Type I LastRead 0 FirstWrite -1}
		nPH3Z2_V_read {Type I LastRead 0 FirstWrite -1}
		nPH4Z2_V_read {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "5", "Max" : "68"}
	, {"Name" : "Interval", "Min" : "5", "Max" : "68"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	stubsInLayer_0_data { ap_memory {  { stubsInLayer_0_data_address0 mem_address 1 6 }  { stubsInLayer_0_data_ce0 mem_ce 1 1 }  { stubsInLayer_0_data_q0 mem_dout 0 36 } } }
	stubsInLayer_1_data { ap_memory {  { stubsInLayer_1_data_address0 mem_address 1 6 }  { stubsInLayer_1_data_ce0 mem_ce 1 1 }  { stubsInLayer_1_data_q0 mem_dout 0 36 } } }
	stubsInLayer_2_data { ap_memory {  { stubsInLayer_2_data_address0 mem_address 1 6 }  { stubsInLayer_2_data_ce0 mem_ce 1 1 }  { stubsInLayer_2_data_q0 mem_dout 0 36 } } }
	stubsInLayer_3_data { ap_memory {  { stubsInLayer_3_data_address0 mem_address 1 6 }  { stubsInLayer_3_data_ce0 mem_ce 1 1 }  { stubsInLayer_3_data_q0 mem_dout 0 36 } } }
	stubsInLayer_4_data { ap_memory {  { stubsInLayer_4_data_address0 mem_address 1 6 }  { stubsInLayer_4_data_ce0 mem_ce 1 1 }  { stubsInLayer_4_data_q0 mem_dout 0 36 } } }
	tmp_1 { ap_none {  { tmp_1 in_data 0 10 } } }
	allStubs_0_data_V { ap_memory {  { allStubs_0_data_V_address0 mem_address 1 6 }  { allStubs_0_data_V_ce0 mem_ce 1 1 }  { allStubs_0_data_V_we0 mem_we 1 1 }  { allStubs_0_data_V_d0 mem_din 1 36 } } }
	allStubs_1_data_V { ap_memory {  { allStubs_1_data_V_address0 mem_address 1 6 }  { allStubs_1_data_V_ce0 mem_ce 1 1 }  { allStubs_1_data_V_we0 mem_we 1 1 }  { allStubs_1_data_V_d0 mem_din 1 36 } } }
	allStubs_2_data_V { ap_memory {  { allStubs_2_data_V_address0 mem_address 1 6 }  { allStubs_2_data_V_ce0 mem_ce 1 1 }  { allStubs_2_data_V_we0 mem_we 1 1 }  { allStubs_2_data_V_d0 mem_din 1 36 } } }
	allStubs_3_data_V { ap_memory {  { allStubs_3_data_V_address0 mem_address 1 6 }  { allStubs_3_data_V_ce0 mem_ce 1 1 }  { allStubs_3_data_V_we0 mem_we 1 1 }  { allStubs_3_data_V_d0 mem_din 1 36 } } }
	allStubs_4_data_V { ap_memory {  { allStubs_4_data_V_address0 mem_address 1 6 }  { allStubs_4_data_V_ce0 mem_ce 1 1 }  { allStubs_4_data_V_we0 mem_we 1 1 }  { allStubs_4_data_V_d0 mem_din 1 36 } } }
	tmp_11 { ap_none {  { tmp_11 in_data 0 10 } } }
	vmStubsPH1Z1_0_data { ap_memory {  { vmStubsPH1Z1_0_data_address0 mem_address 1 6 }  { vmStubsPH1Z1_0_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z1_0_data_we0 mem_we 1 1 }  { vmStubsPH1Z1_0_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z1_1_data { ap_memory {  { vmStubsPH1Z1_1_data_address0 mem_address 1 6 }  { vmStubsPH1Z1_1_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z1_1_data_we0 mem_we 1 1 }  { vmStubsPH1Z1_1_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z1_2_data { ap_memory {  { vmStubsPH1Z1_2_data_address0 mem_address 1 6 }  { vmStubsPH1Z1_2_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z1_2_data_we0 mem_we 1 1 }  { vmStubsPH1Z1_2_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z1_3_data { ap_memory {  { vmStubsPH1Z1_3_data_address0 mem_address 1 6 }  { vmStubsPH1Z1_3_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z1_3_data_we0 mem_we 1 1 }  { vmStubsPH1Z1_3_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z1_4_data { ap_memory {  { vmStubsPH1Z1_4_data_address0 mem_address 1 6 }  { vmStubsPH1Z1_4_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z1_4_data_we0 mem_we 1 1 }  { vmStubsPH1Z1_4_data_d0 mem_din 1 18 } } }
	tmp_12 { ap_none {  { tmp_12 in_data 0 10 } } }
	vmStubsPH2Z1_0_data { ap_memory {  { vmStubsPH2Z1_0_data_address0 mem_address 1 6 }  { vmStubsPH2Z1_0_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z1_0_data_we0 mem_we 1 1 }  { vmStubsPH2Z1_0_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z1_1_data { ap_memory {  { vmStubsPH2Z1_1_data_address0 mem_address 1 6 }  { vmStubsPH2Z1_1_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z1_1_data_we0 mem_we 1 1 }  { vmStubsPH2Z1_1_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z1_2_data { ap_memory {  { vmStubsPH2Z1_2_data_address0 mem_address 1 6 }  { vmStubsPH2Z1_2_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z1_2_data_we0 mem_we 1 1 }  { vmStubsPH2Z1_2_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z1_3_data { ap_memory {  { vmStubsPH2Z1_3_data_address0 mem_address 1 6 }  { vmStubsPH2Z1_3_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z1_3_data_we0 mem_we 1 1 }  { vmStubsPH2Z1_3_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z1_4_data { ap_memory {  { vmStubsPH2Z1_4_data_address0 mem_address 1 6 }  { vmStubsPH2Z1_4_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z1_4_data_we0 mem_we 1 1 }  { vmStubsPH2Z1_4_data_d0 mem_din 1 18 } } }
	tmp_13 { ap_none {  { tmp_13 in_data 0 10 } } }
	vmStubsPH3Z1_0_data { ap_memory {  { vmStubsPH3Z1_0_data_address0 mem_address 1 6 }  { vmStubsPH3Z1_0_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z1_0_data_we0 mem_we 1 1 }  { vmStubsPH3Z1_0_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z1_1_data { ap_memory {  { vmStubsPH3Z1_1_data_address0 mem_address 1 6 }  { vmStubsPH3Z1_1_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z1_1_data_we0 mem_we 1 1 }  { vmStubsPH3Z1_1_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z1_2_data { ap_memory {  { vmStubsPH3Z1_2_data_address0 mem_address 1 6 }  { vmStubsPH3Z1_2_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z1_2_data_we0 mem_we 1 1 }  { vmStubsPH3Z1_2_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z1_3_data { ap_memory {  { vmStubsPH3Z1_3_data_address0 mem_address 1 6 }  { vmStubsPH3Z1_3_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z1_3_data_we0 mem_we 1 1 }  { vmStubsPH3Z1_3_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z1_4_data { ap_memory {  { vmStubsPH3Z1_4_data_address0 mem_address 1 6 }  { vmStubsPH3Z1_4_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z1_4_data_we0 mem_we 1 1 }  { vmStubsPH3Z1_4_data_d0 mem_din 1 18 } } }
	tmp_14 { ap_none {  { tmp_14 in_data 0 10 } } }
	vmStubsPH4Z1_0_data { ap_memory {  { vmStubsPH4Z1_0_data_address0 mem_address 1 6 }  { vmStubsPH4Z1_0_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z1_0_data_we0 mem_we 1 1 }  { vmStubsPH4Z1_0_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z1_1_data { ap_memory {  { vmStubsPH4Z1_1_data_address0 mem_address 1 6 }  { vmStubsPH4Z1_1_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z1_1_data_we0 mem_we 1 1 }  { vmStubsPH4Z1_1_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z1_2_data { ap_memory {  { vmStubsPH4Z1_2_data_address0 mem_address 1 6 }  { vmStubsPH4Z1_2_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z1_2_data_we0 mem_we 1 1 }  { vmStubsPH4Z1_2_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z1_3_data { ap_memory {  { vmStubsPH4Z1_3_data_address0 mem_address 1 6 }  { vmStubsPH4Z1_3_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z1_3_data_we0 mem_we 1 1 }  { vmStubsPH4Z1_3_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z1_4_data { ap_memory {  { vmStubsPH4Z1_4_data_address0 mem_address 1 6 }  { vmStubsPH4Z1_4_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z1_4_data_we0 mem_we 1 1 }  { vmStubsPH4Z1_4_data_d0 mem_din 1 18 } } }
	tmp_15 { ap_none {  { tmp_15 in_data 0 10 } } }
	vmStubsPH1Z2_0_data { ap_memory {  { vmStubsPH1Z2_0_data_address0 mem_address 1 6 }  { vmStubsPH1Z2_0_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z2_0_data_we0 mem_we 1 1 }  { vmStubsPH1Z2_0_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z2_1_data { ap_memory {  { vmStubsPH1Z2_1_data_address0 mem_address 1 6 }  { vmStubsPH1Z2_1_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z2_1_data_we0 mem_we 1 1 }  { vmStubsPH1Z2_1_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z2_2_data { ap_memory {  { vmStubsPH1Z2_2_data_address0 mem_address 1 6 }  { vmStubsPH1Z2_2_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z2_2_data_we0 mem_we 1 1 }  { vmStubsPH1Z2_2_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z2_3_data { ap_memory {  { vmStubsPH1Z2_3_data_address0 mem_address 1 6 }  { vmStubsPH1Z2_3_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z2_3_data_we0 mem_we 1 1 }  { vmStubsPH1Z2_3_data_d0 mem_din 1 18 } } }
	vmStubsPH1Z2_4_data { ap_memory {  { vmStubsPH1Z2_4_data_address0 mem_address 1 6 }  { vmStubsPH1Z2_4_data_ce0 mem_ce 1 1 }  { vmStubsPH1Z2_4_data_we0 mem_we 1 1 }  { vmStubsPH1Z2_4_data_d0 mem_din 1 18 } } }
	tmp_16 { ap_none {  { tmp_16 in_data 0 10 } } }
	vmStubsPH2Z2_0_data { ap_memory {  { vmStubsPH2Z2_0_data_address0 mem_address 1 6 }  { vmStubsPH2Z2_0_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z2_0_data_we0 mem_we 1 1 }  { vmStubsPH2Z2_0_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z2_1_data { ap_memory {  { vmStubsPH2Z2_1_data_address0 mem_address 1 6 }  { vmStubsPH2Z2_1_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z2_1_data_we0 mem_we 1 1 }  { vmStubsPH2Z2_1_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z2_2_data { ap_memory {  { vmStubsPH2Z2_2_data_address0 mem_address 1 6 }  { vmStubsPH2Z2_2_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z2_2_data_we0 mem_we 1 1 }  { vmStubsPH2Z2_2_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z2_3_data { ap_memory {  { vmStubsPH2Z2_3_data_address0 mem_address 1 6 }  { vmStubsPH2Z2_3_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z2_3_data_we0 mem_we 1 1 }  { vmStubsPH2Z2_3_data_d0 mem_din 1 18 } } }
	vmStubsPH2Z2_4_data { ap_memory {  { vmStubsPH2Z2_4_data_address0 mem_address 1 6 }  { vmStubsPH2Z2_4_data_ce0 mem_ce 1 1 }  { vmStubsPH2Z2_4_data_we0 mem_we 1 1 }  { vmStubsPH2Z2_4_data_d0 mem_din 1 18 } } }
	tmp_17 { ap_none {  { tmp_17 in_data 0 10 } } }
	vmStubsPH3Z2_0_data { ap_memory {  { vmStubsPH3Z2_0_data_address0 mem_address 1 6 }  { vmStubsPH3Z2_0_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z2_0_data_we0 mem_we 1 1 }  { vmStubsPH3Z2_0_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z2_1_data { ap_memory {  { vmStubsPH3Z2_1_data_address0 mem_address 1 6 }  { vmStubsPH3Z2_1_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z2_1_data_we0 mem_we 1 1 }  { vmStubsPH3Z2_1_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z2_2_data { ap_memory {  { vmStubsPH3Z2_2_data_address0 mem_address 1 6 }  { vmStubsPH3Z2_2_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z2_2_data_we0 mem_we 1 1 }  { vmStubsPH3Z2_2_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z2_3_data { ap_memory {  { vmStubsPH3Z2_3_data_address0 mem_address 1 6 }  { vmStubsPH3Z2_3_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z2_3_data_we0 mem_we 1 1 }  { vmStubsPH3Z2_3_data_d0 mem_din 1 18 } } }
	vmStubsPH3Z2_4_data { ap_memory {  { vmStubsPH3Z2_4_data_address0 mem_address 1 6 }  { vmStubsPH3Z2_4_data_ce0 mem_ce 1 1 }  { vmStubsPH3Z2_4_data_we0 mem_we 1 1 }  { vmStubsPH3Z2_4_data_d0 mem_din 1 18 } } }
	tmp_18 { ap_none {  { tmp_18 in_data 0 10 } } }
	vmStubsPH4Z2_0_data { ap_memory {  { vmStubsPH4Z2_0_data_address0 mem_address 1 6 }  { vmStubsPH4Z2_0_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z2_0_data_we0 mem_we 1 1 }  { vmStubsPH4Z2_0_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z2_1_data { ap_memory {  { vmStubsPH4Z2_1_data_address0 mem_address 1 6 }  { vmStubsPH4Z2_1_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z2_1_data_we0 mem_we 1 1 }  { vmStubsPH4Z2_1_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z2_2_data { ap_memory {  { vmStubsPH4Z2_2_data_address0 mem_address 1 6 }  { vmStubsPH4Z2_2_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z2_2_data_we0 mem_we 1 1 }  { vmStubsPH4Z2_2_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z2_3_data { ap_memory {  { vmStubsPH4Z2_3_data_address0 mem_address 1 6 }  { vmStubsPH4Z2_3_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z2_3_data_we0 mem_we 1 1 }  { vmStubsPH4Z2_3_data_d0 mem_din 1 18 } } }
	vmStubsPH4Z2_4_data { ap_memory {  { vmStubsPH4Z2_4_data_address0 mem_address 1 6 }  { vmStubsPH4Z2_4_data_ce0 mem_ce 1 1 }  { vmStubsPH4Z2_4_data_we0 mem_we 1 1 }  { vmStubsPH4Z2_4_data_d0 mem_din 1 18 } } }
	tmp_19 { ap_none {  { tmp_19 in_data 0 10 } } }
	nStubs { ap_none {  { nStubs in_data 0 32 } } }
	nPH1Z1_V_read { ap_none {  { nPH1Z1_V_read in_data 0 6 } } }
	nPH2Z1_V_read { ap_none {  { nPH2Z1_V_read in_data 0 6 } } }
	nPH3Z1_V_read { ap_none {  { nPH3Z1_V_read in_data 0 6 } } }
	nPH4Z1_V_read { ap_none {  { nPH4Z1_V_read in_data 0 6 } } }
	nPH1Z2_V_read { ap_none {  { nPH1Z2_V_read in_data 0 6 } } }
	nPH2Z2_V_read { ap_none {  { nPH2Z2_V_read in_data 0 6 } } }
	nPH3Z2_V_read { ap_none {  { nPH3Z2_V_read in_data 0 6 } } }
	nPH4Z2_V_read { ap_none {  { nPH4Z2_V_read in_data 0 6 } } }
}
