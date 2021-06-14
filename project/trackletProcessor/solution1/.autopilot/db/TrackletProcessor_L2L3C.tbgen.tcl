set moduleName TrackletProcessor_L2L3C
set isTopModule 1
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {TrackletProcessor_L2L3C}
set C_modelType { void 0 }
set C_modelArgList {
	{ bx_V int 3 regular  }
	{ lut_V int 10 regular {array 2048 { 1 3 } 2 1 }  }
	{ regionlut_V int 8 regular {array 2048 { 1 3 } 2 1 }  }
	{ innerStubs_dataarray_data_V int 51 regular {array 3072 { 1 3 } 2 1 }  }
	{ innerStubs_0_nentries_0_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_1_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_2_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_3_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_4_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_5_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_6_V int 7 regular {pointer 0}  }
	{ innerStubs_0_nentries_7_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_0_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_1_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_2_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_3_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_4_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_5_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_6_V int 7 regular {pointer 0}  }
	{ innerStubs_1_nentries_7_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_0_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_1_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_2_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_3_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_4_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_5_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_6_V int 7 regular {pointer 0}  }
	{ innerStubs_2_nentries_7_V int 7 regular {pointer 0}  }
	{ outerStubs_dataarray_data_V int 36 regular {array 1024 { 1 3 } 2 1 }  }
	{ outerVMStubs_dataarray_data_V_0 int 16 regular {array 2048 { 1 3 } 2 1 }  }
	{ outerVMStubs_dataarray_data_V_1 int 16 regular {array 2048 { 1 3 } 2 1 }  }
	{ outerVMStubs_binmask8_V_0_0 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_1 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_2 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_3 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_4 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_5 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_6 int 8 regular  }
	{ outerVMStubs_binmask8_V_0_7 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_0 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_1 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_2 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_3 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_4 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_5 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_6 int 8 regular  }
	{ outerVMStubs_binmask8_V_1_7 int 8 regular  }
	{ outerVMStubs_nentries8_V_0_0 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_1 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_2 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_3 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_4 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_5 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_6 int 32 regular  }
	{ outerVMStubs_nentries8_V_0_7 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_0 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_1 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_2 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_3 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_4 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_5 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_6 int 32 regular  }
	{ outerVMStubs_nentries8_V_1_7 int 32 regular  }
	{ trackletParameters_dataarray_data_V int 70 regular {array 1024 { 0 3 } 0 1 }  }
	{ projout_barrel_ps_3_dataarray_data_V int 60 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_ps_4_dataarray_data_V int 60 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_ps_5_dataarray_data_V int 60 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_ps_6_dataarray_data_V int 60 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_1_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_2_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_3_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_5_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_6_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_barrel_2s_7_dataarray_data_V int 58 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_1_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_2_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_3_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_5_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_6_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_7_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_9_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_10_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_11_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_13_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_14_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
	{ projout_disk_15_dataarray_data_V int 59 regular {array 256 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bx_V", "interface" : "wire", "bitwidth" : 3, "direction" : "READONLY", "bitSlice":[{"low":0,"up":2,"cElement": [{"cName": "bx.V","cData": "uint3","bit_use": { "low": 0,"up": 2},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "lut_V", "interface" : "memory", "bitwidth" : 10, "direction" : "READONLY", "bitSlice":[{"low":0,"up":9,"cElement": [{"cName": "lut.V","cData": "uint10","bit_use": { "low": 0,"up": 9},"cArray": [{"low" : 0,"up" : 2047,"step" : 1}]}]}]} , 
 	{ "Name" : "regionlut_V", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "regionlut.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 2047,"step" : 1}]}]}]} , 
 	{ "Name" : "innerStubs_dataarray_data_V", "interface" : "memory", "bitwidth" : 51, "direction" : "READONLY", "bitSlice":[{"low":0,"up":50,"cElement": [{"cName": "innerStubs.dataarray_.data_.V","cData": "uint51","bit_use": { "low": 0,"up": 50},"cArray": [{"low" : 0,"up" : 2,"step" : 1},{"low" : 0,"up" : 7,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_0_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_1_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_2_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_3_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_4_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_5_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_6_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_0_nentries_7_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_0_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_1_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_2_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_3_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_4_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_5_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_6_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_1_nentries_7_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_0_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_1_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_2_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_3_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_4_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_5_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_6_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "innerStubs_2_nentries_7_V", "interface" : "wire", "bitwidth" : 7, "direction" : "READONLY", "bitSlice":[{"low":0,"up":6,"cElement": [{"cName": "innerStubs.nentries_.V","cData": "uint7","bit_use": { "low": 0,"up": 6},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "outerStubs_dataarray_data_V", "interface" : "memory", "bitwidth" : 36, "direction" : "READONLY", "bitSlice":[{"low":0,"up":35,"cElement": [{"cName": "outerStubs.dataarray_.data_.V","cData": "uint36","bit_use": { "low": 0,"up": 35},"cArray": [{"low" : 0,"up" : 7,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "outerVMStubs_dataarray_data_V_0", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "outerVMStubs.dataarray_.data_.V","cData": "uint16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 1023,"step" : 1}]}]}]} , 
 	{ "Name" : "outerVMStubs_dataarray_data_V_1", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "outerVMStubs.dataarray_.data_.V","cData": "uint16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 1023,"step" : 1}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_0", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_1", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_2", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_3", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_4", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_5", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_6", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_0_7", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_0", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_1", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_2", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_3", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_4", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_5", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_6", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_binmask8_V_1_7", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "outerVMStubs.binmask8_.V","cData": "uint8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_3", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_4", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_5", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_6", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_0_7", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_3", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_4", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_5", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_6", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "outerVMStubs_nentries8_V_1_7", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "outerVMStubs.nentries8_.V","cData": "uint32","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "trackletParameters_dataarray_data_V", "interface" : "memory", "bitwidth" : 70, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":69,"cElement": [{"cName": "trackletParameters.dataarray_.data_.V","cData": "uint70","bit_use": { "low": 0,"up": 69},"cArray": [{"low" : 0,"up" : 7,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_ps_3_dataarray_data_V", "interface" : "memory", "bitwidth" : 60, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":59,"cElement": [{"cName": "projout_barrel_ps.dataarray_.data_.V","cData": "uint60","bit_use": { "low": 0,"up": 59},"cArray": [{"low" : 3,"up" : 3,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_ps_4_dataarray_data_V", "interface" : "memory", "bitwidth" : 60, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":59,"cElement": [{"cName": "projout_barrel_ps.dataarray_.data_.V","cData": "uint60","bit_use": { "low": 0,"up": 59},"cArray": [{"low" : 4,"up" : 4,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_ps_5_dataarray_data_V", "interface" : "memory", "bitwidth" : 60, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":59,"cElement": [{"cName": "projout_barrel_ps.dataarray_.data_.V","cData": "uint60","bit_use": { "low": 0,"up": 59},"cArray": [{"low" : 5,"up" : 5,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_ps_6_dataarray_data_V", "interface" : "memory", "bitwidth" : 60, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":59,"cElement": [{"cName": "projout_barrel_ps.dataarray_.data_.V","cData": "uint60","bit_use": { "low": 0,"up": 59},"cArray": [{"low" : 6,"up" : 6,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_1_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_2_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_3_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 3,"up" : 3,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_5_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 5,"up" : 5,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_6_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 6,"up" : 6,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_barrel_2s_7_dataarray_data_V", "interface" : "memory", "bitwidth" : 58, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":57,"cElement": [{"cName": "projout_barrel_2s.dataarray_.data_.V","cData": "uint58","bit_use": { "low": 0,"up": 57},"cArray": [{"low" : 7,"up" : 7,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_1_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_2_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_3_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 3,"up" : 3,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_5_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 5,"up" : 5,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_6_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 6,"up" : 6,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_7_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 7,"up" : 7,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_9_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 9,"up" : 9,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_10_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 10,"up" : 10,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_11_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 11,"up" : 11,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_13_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 13,"up" : 13,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_14_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 14,"up" : 14,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} , 
 	{ "Name" : "projout_disk_15_dataarray_data_V", "interface" : "memory", "bitwidth" : 59, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":58,"cElement": [{"cName": "projout_disk.dataarray_.data_.V","cData": "uint59","bit_use": { "low": 0,"up": 58},"cArray": [{"low" : 15,"up" : 15,"step" : 2},{"low" : 0,"up" : 1,"step" : 1},{"low" : 0,"up" : 127,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 173
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bx_V sc_in sc_lv 3 signal 0 } 
	{ lut_V_address0 sc_out sc_lv 11 signal 1 } 
	{ lut_V_ce0 sc_out sc_logic 1 signal 1 } 
	{ lut_V_q0 sc_in sc_lv 10 signal 1 } 
	{ regionlut_V_address0 sc_out sc_lv 11 signal 2 } 
	{ regionlut_V_ce0 sc_out sc_logic 1 signal 2 } 
	{ regionlut_V_q0 sc_in sc_lv 8 signal 2 } 
	{ innerStubs_dataarray_data_V_address0 sc_out sc_lv 12 signal 3 } 
	{ innerStubs_dataarray_data_V_ce0 sc_out sc_logic 1 signal 3 } 
	{ innerStubs_dataarray_data_V_q0 sc_in sc_lv 51 signal 3 } 
	{ innerStubs_0_nentries_0_V sc_in sc_lv 7 signal 4 } 
	{ innerStubs_0_nentries_1_V sc_in sc_lv 7 signal 5 } 
	{ innerStubs_0_nentries_2_V sc_in sc_lv 7 signal 6 } 
	{ innerStubs_0_nentries_3_V sc_in sc_lv 7 signal 7 } 
	{ innerStubs_0_nentries_4_V sc_in sc_lv 7 signal 8 } 
	{ innerStubs_0_nentries_5_V sc_in sc_lv 7 signal 9 } 
	{ innerStubs_0_nentries_6_V sc_in sc_lv 7 signal 10 } 
	{ innerStubs_0_nentries_7_V sc_in sc_lv 7 signal 11 } 
	{ innerStubs_1_nentries_0_V sc_in sc_lv 7 signal 12 } 
	{ innerStubs_1_nentries_1_V sc_in sc_lv 7 signal 13 } 
	{ innerStubs_1_nentries_2_V sc_in sc_lv 7 signal 14 } 
	{ innerStubs_1_nentries_3_V sc_in sc_lv 7 signal 15 } 
	{ innerStubs_1_nentries_4_V sc_in sc_lv 7 signal 16 } 
	{ innerStubs_1_nentries_5_V sc_in sc_lv 7 signal 17 } 
	{ innerStubs_1_nentries_6_V sc_in sc_lv 7 signal 18 } 
	{ innerStubs_1_nentries_7_V sc_in sc_lv 7 signal 19 } 
	{ innerStubs_2_nentries_0_V sc_in sc_lv 7 signal 20 } 
	{ innerStubs_2_nentries_1_V sc_in sc_lv 7 signal 21 } 
	{ innerStubs_2_nentries_2_V sc_in sc_lv 7 signal 22 } 
	{ innerStubs_2_nentries_3_V sc_in sc_lv 7 signal 23 } 
	{ innerStubs_2_nentries_4_V sc_in sc_lv 7 signal 24 } 
	{ innerStubs_2_nentries_5_V sc_in sc_lv 7 signal 25 } 
	{ innerStubs_2_nentries_6_V sc_in sc_lv 7 signal 26 } 
	{ innerStubs_2_nentries_7_V sc_in sc_lv 7 signal 27 } 
	{ outerStubs_dataarray_data_V_address0 sc_out sc_lv 10 signal 28 } 
	{ outerStubs_dataarray_data_V_ce0 sc_out sc_logic 1 signal 28 } 
	{ outerStubs_dataarray_data_V_q0 sc_in sc_lv 36 signal 28 } 
	{ outerVMStubs_dataarray_data_V_0_address0 sc_out sc_lv 11 signal 29 } 
	{ outerVMStubs_dataarray_data_V_0_ce0 sc_out sc_logic 1 signal 29 } 
	{ outerVMStubs_dataarray_data_V_0_q0 sc_in sc_lv 16 signal 29 } 
	{ outerVMStubs_dataarray_data_V_1_address0 sc_out sc_lv 11 signal 30 } 
	{ outerVMStubs_dataarray_data_V_1_ce0 sc_out sc_logic 1 signal 30 } 
	{ outerVMStubs_dataarray_data_V_1_q0 sc_in sc_lv 16 signal 30 } 
	{ outerVMStubs_binmask8_V_0_0 sc_in sc_lv 8 signal 31 } 
	{ outerVMStubs_binmask8_V_0_1 sc_in sc_lv 8 signal 32 } 
	{ outerVMStubs_binmask8_V_0_2 sc_in sc_lv 8 signal 33 } 
	{ outerVMStubs_binmask8_V_0_3 sc_in sc_lv 8 signal 34 } 
	{ outerVMStubs_binmask8_V_0_4 sc_in sc_lv 8 signal 35 } 
	{ outerVMStubs_binmask8_V_0_5 sc_in sc_lv 8 signal 36 } 
	{ outerVMStubs_binmask8_V_0_6 sc_in sc_lv 8 signal 37 } 
	{ outerVMStubs_binmask8_V_0_7 sc_in sc_lv 8 signal 38 } 
	{ outerVMStubs_binmask8_V_1_0 sc_in sc_lv 8 signal 39 } 
	{ outerVMStubs_binmask8_V_1_1 sc_in sc_lv 8 signal 40 } 
	{ outerVMStubs_binmask8_V_1_2 sc_in sc_lv 8 signal 41 } 
	{ outerVMStubs_binmask8_V_1_3 sc_in sc_lv 8 signal 42 } 
	{ outerVMStubs_binmask8_V_1_4 sc_in sc_lv 8 signal 43 } 
	{ outerVMStubs_binmask8_V_1_5 sc_in sc_lv 8 signal 44 } 
	{ outerVMStubs_binmask8_V_1_6 sc_in sc_lv 8 signal 45 } 
	{ outerVMStubs_binmask8_V_1_7 sc_in sc_lv 8 signal 46 } 
	{ outerVMStubs_nentries8_V_0_0 sc_in sc_lv 32 signal 47 } 
	{ outerVMStubs_nentries8_V_0_1 sc_in sc_lv 32 signal 48 } 
	{ outerVMStubs_nentries8_V_0_2 sc_in sc_lv 32 signal 49 } 
	{ outerVMStubs_nentries8_V_0_3 sc_in sc_lv 32 signal 50 } 
	{ outerVMStubs_nentries8_V_0_4 sc_in sc_lv 32 signal 51 } 
	{ outerVMStubs_nentries8_V_0_5 sc_in sc_lv 32 signal 52 } 
	{ outerVMStubs_nentries8_V_0_6 sc_in sc_lv 32 signal 53 } 
	{ outerVMStubs_nentries8_V_0_7 sc_in sc_lv 32 signal 54 } 
	{ outerVMStubs_nentries8_V_1_0 sc_in sc_lv 32 signal 55 } 
	{ outerVMStubs_nentries8_V_1_1 sc_in sc_lv 32 signal 56 } 
	{ outerVMStubs_nentries8_V_1_2 sc_in sc_lv 32 signal 57 } 
	{ outerVMStubs_nentries8_V_1_3 sc_in sc_lv 32 signal 58 } 
	{ outerVMStubs_nentries8_V_1_4 sc_in sc_lv 32 signal 59 } 
	{ outerVMStubs_nentries8_V_1_5 sc_in sc_lv 32 signal 60 } 
	{ outerVMStubs_nentries8_V_1_6 sc_in sc_lv 32 signal 61 } 
	{ outerVMStubs_nentries8_V_1_7 sc_in sc_lv 32 signal 62 } 
	{ trackletParameters_dataarray_data_V_address0 sc_out sc_lv 10 signal 63 } 
	{ trackletParameters_dataarray_data_V_ce0 sc_out sc_logic 1 signal 63 } 
	{ trackletParameters_dataarray_data_V_we0 sc_out sc_logic 1 signal 63 } 
	{ trackletParameters_dataarray_data_V_d0 sc_out sc_lv 70 signal 63 } 
	{ projout_barrel_ps_3_dataarray_data_V_address0 sc_out sc_lv 8 signal 64 } 
	{ projout_barrel_ps_3_dataarray_data_V_ce0 sc_out sc_logic 1 signal 64 } 
	{ projout_barrel_ps_3_dataarray_data_V_we0 sc_out sc_logic 1 signal 64 } 
	{ projout_barrel_ps_3_dataarray_data_V_d0 sc_out sc_lv 60 signal 64 } 
	{ projout_barrel_ps_4_dataarray_data_V_address0 sc_out sc_lv 8 signal 65 } 
	{ projout_barrel_ps_4_dataarray_data_V_ce0 sc_out sc_logic 1 signal 65 } 
	{ projout_barrel_ps_4_dataarray_data_V_we0 sc_out sc_logic 1 signal 65 } 
	{ projout_barrel_ps_4_dataarray_data_V_d0 sc_out sc_lv 60 signal 65 } 
	{ projout_barrel_ps_5_dataarray_data_V_address0 sc_out sc_lv 8 signal 66 } 
	{ projout_barrel_ps_5_dataarray_data_V_ce0 sc_out sc_logic 1 signal 66 } 
	{ projout_barrel_ps_5_dataarray_data_V_we0 sc_out sc_logic 1 signal 66 } 
	{ projout_barrel_ps_5_dataarray_data_V_d0 sc_out sc_lv 60 signal 66 } 
	{ projout_barrel_ps_6_dataarray_data_V_address0 sc_out sc_lv 8 signal 67 } 
	{ projout_barrel_ps_6_dataarray_data_V_ce0 sc_out sc_logic 1 signal 67 } 
	{ projout_barrel_ps_6_dataarray_data_V_we0 sc_out sc_logic 1 signal 67 } 
	{ projout_barrel_ps_6_dataarray_data_V_d0 sc_out sc_lv 60 signal 67 } 
	{ projout_barrel_2s_1_dataarray_data_V_address0 sc_out sc_lv 8 signal 68 } 
	{ projout_barrel_2s_1_dataarray_data_V_ce0 sc_out sc_logic 1 signal 68 } 
	{ projout_barrel_2s_1_dataarray_data_V_we0 sc_out sc_logic 1 signal 68 } 
	{ projout_barrel_2s_1_dataarray_data_V_d0 sc_out sc_lv 58 signal 68 } 
	{ projout_barrel_2s_2_dataarray_data_V_address0 sc_out sc_lv 8 signal 69 } 
	{ projout_barrel_2s_2_dataarray_data_V_ce0 sc_out sc_logic 1 signal 69 } 
	{ projout_barrel_2s_2_dataarray_data_V_we0 sc_out sc_logic 1 signal 69 } 
	{ projout_barrel_2s_2_dataarray_data_V_d0 sc_out sc_lv 58 signal 69 } 
	{ projout_barrel_2s_3_dataarray_data_V_address0 sc_out sc_lv 8 signal 70 } 
	{ projout_barrel_2s_3_dataarray_data_V_ce0 sc_out sc_logic 1 signal 70 } 
	{ projout_barrel_2s_3_dataarray_data_V_we0 sc_out sc_logic 1 signal 70 } 
	{ projout_barrel_2s_3_dataarray_data_V_d0 sc_out sc_lv 58 signal 70 } 
	{ projout_barrel_2s_5_dataarray_data_V_address0 sc_out sc_lv 8 signal 71 } 
	{ projout_barrel_2s_5_dataarray_data_V_ce0 sc_out sc_logic 1 signal 71 } 
	{ projout_barrel_2s_5_dataarray_data_V_we0 sc_out sc_logic 1 signal 71 } 
	{ projout_barrel_2s_5_dataarray_data_V_d0 sc_out sc_lv 58 signal 71 } 
	{ projout_barrel_2s_6_dataarray_data_V_address0 sc_out sc_lv 8 signal 72 } 
	{ projout_barrel_2s_6_dataarray_data_V_ce0 sc_out sc_logic 1 signal 72 } 
	{ projout_barrel_2s_6_dataarray_data_V_we0 sc_out sc_logic 1 signal 72 } 
	{ projout_barrel_2s_6_dataarray_data_V_d0 sc_out sc_lv 58 signal 72 } 
	{ projout_barrel_2s_7_dataarray_data_V_address0 sc_out sc_lv 8 signal 73 } 
	{ projout_barrel_2s_7_dataarray_data_V_ce0 sc_out sc_logic 1 signal 73 } 
	{ projout_barrel_2s_7_dataarray_data_V_we0 sc_out sc_logic 1 signal 73 } 
	{ projout_barrel_2s_7_dataarray_data_V_d0 sc_out sc_lv 58 signal 73 } 
	{ projout_disk_1_dataarray_data_V_address0 sc_out sc_lv 8 signal 74 } 
	{ projout_disk_1_dataarray_data_V_ce0 sc_out sc_logic 1 signal 74 } 
	{ projout_disk_1_dataarray_data_V_we0 sc_out sc_logic 1 signal 74 } 
	{ projout_disk_1_dataarray_data_V_d0 sc_out sc_lv 59 signal 74 } 
	{ projout_disk_2_dataarray_data_V_address0 sc_out sc_lv 8 signal 75 } 
	{ projout_disk_2_dataarray_data_V_ce0 sc_out sc_logic 1 signal 75 } 
	{ projout_disk_2_dataarray_data_V_we0 sc_out sc_logic 1 signal 75 } 
	{ projout_disk_2_dataarray_data_V_d0 sc_out sc_lv 59 signal 75 } 
	{ projout_disk_3_dataarray_data_V_address0 sc_out sc_lv 8 signal 76 } 
	{ projout_disk_3_dataarray_data_V_ce0 sc_out sc_logic 1 signal 76 } 
	{ projout_disk_3_dataarray_data_V_we0 sc_out sc_logic 1 signal 76 } 
	{ projout_disk_3_dataarray_data_V_d0 sc_out sc_lv 59 signal 76 } 
	{ projout_disk_5_dataarray_data_V_address0 sc_out sc_lv 8 signal 77 } 
	{ projout_disk_5_dataarray_data_V_ce0 sc_out sc_logic 1 signal 77 } 
	{ projout_disk_5_dataarray_data_V_we0 sc_out sc_logic 1 signal 77 } 
	{ projout_disk_5_dataarray_data_V_d0 sc_out sc_lv 59 signal 77 } 
	{ projout_disk_6_dataarray_data_V_address0 sc_out sc_lv 8 signal 78 } 
	{ projout_disk_6_dataarray_data_V_ce0 sc_out sc_logic 1 signal 78 } 
	{ projout_disk_6_dataarray_data_V_we0 sc_out sc_logic 1 signal 78 } 
	{ projout_disk_6_dataarray_data_V_d0 sc_out sc_lv 59 signal 78 } 
	{ projout_disk_7_dataarray_data_V_address0 sc_out sc_lv 8 signal 79 } 
	{ projout_disk_7_dataarray_data_V_ce0 sc_out sc_logic 1 signal 79 } 
	{ projout_disk_7_dataarray_data_V_we0 sc_out sc_logic 1 signal 79 } 
	{ projout_disk_7_dataarray_data_V_d0 sc_out sc_lv 59 signal 79 } 
	{ projout_disk_9_dataarray_data_V_address0 sc_out sc_lv 8 signal 80 } 
	{ projout_disk_9_dataarray_data_V_ce0 sc_out sc_logic 1 signal 80 } 
	{ projout_disk_9_dataarray_data_V_we0 sc_out sc_logic 1 signal 80 } 
	{ projout_disk_9_dataarray_data_V_d0 sc_out sc_lv 59 signal 80 } 
	{ projout_disk_10_dataarray_data_V_address0 sc_out sc_lv 8 signal 81 } 
	{ projout_disk_10_dataarray_data_V_ce0 sc_out sc_logic 1 signal 81 } 
	{ projout_disk_10_dataarray_data_V_we0 sc_out sc_logic 1 signal 81 } 
	{ projout_disk_10_dataarray_data_V_d0 sc_out sc_lv 59 signal 81 } 
	{ projout_disk_11_dataarray_data_V_address0 sc_out sc_lv 8 signal 82 } 
	{ projout_disk_11_dataarray_data_V_ce0 sc_out sc_logic 1 signal 82 } 
	{ projout_disk_11_dataarray_data_V_we0 sc_out sc_logic 1 signal 82 } 
	{ projout_disk_11_dataarray_data_V_d0 sc_out sc_lv 59 signal 82 } 
	{ projout_disk_13_dataarray_data_V_address0 sc_out sc_lv 8 signal 83 } 
	{ projout_disk_13_dataarray_data_V_ce0 sc_out sc_logic 1 signal 83 } 
	{ projout_disk_13_dataarray_data_V_we0 sc_out sc_logic 1 signal 83 } 
	{ projout_disk_13_dataarray_data_V_d0 sc_out sc_lv 59 signal 83 } 
	{ projout_disk_14_dataarray_data_V_address0 sc_out sc_lv 8 signal 84 } 
	{ projout_disk_14_dataarray_data_V_ce0 sc_out sc_logic 1 signal 84 } 
	{ projout_disk_14_dataarray_data_V_we0 sc_out sc_logic 1 signal 84 } 
	{ projout_disk_14_dataarray_data_V_d0 sc_out sc_lv 59 signal 84 } 
	{ projout_disk_15_dataarray_data_V_address0 sc_out sc_lv 8 signal 85 } 
	{ projout_disk_15_dataarray_data_V_ce0 sc_out sc_logic 1 signal 85 } 
	{ projout_disk_15_dataarray_data_V_we0 sc_out sc_logic 1 signal 85 } 
	{ projout_disk_15_dataarray_data_V_d0 sc_out sc_lv 59 signal 85 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "bx_V", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "bx_V", "role": "default" }} , 
 	{ "name": "lut_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "lut_V", "role": "address0" }} , 
 	{ "name": "lut_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lut_V", "role": "ce0" }} , 
 	{ "name": "lut_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "lut_V", "role": "q0" }} , 
 	{ "name": "regionlut_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "regionlut_V", "role": "address0" }} , 
 	{ "name": "regionlut_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "regionlut_V", "role": "ce0" }} , 
 	{ "name": "regionlut_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "regionlut_V", "role": "q0" }} , 
 	{ "name": "innerStubs_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "innerStubs_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "innerStubs_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "innerStubs_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "innerStubs_dataarray_data_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":51, "type": "signal", "bundle":{"name": "innerStubs_dataarray_data_V", "role": "q0" }} , 
 	{ "name": "innerStubs_0_nentries_0_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_0_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_1_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_1_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_2_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_2_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_3_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_3_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_4_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_4_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_5_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_5_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_6_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_6_V", "role": "default" }} , 
 	{ "name": "innerStubs_0_nentries_7_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_0_nentries_7_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_0_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_0_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_1_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_1_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_2_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_2_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_3_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_3_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_4_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_4_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_5_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_5_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_6_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_6_V", "role": "default" }} , 
 	{ "name": "innerStubs_1_nentries_7_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_1_nentries_7_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_0_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_0_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_1_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_1_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_2_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_2_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_3_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_3_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_4_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_4_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_5_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_5_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_6_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_6_V", "role": "default" }} , 
 	{ "name": "innerStubs_2_nentries_7_V", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "innerStubs_2_nentries_7_V", "role": "default" }} , 
 	{ "name": "outerStubs_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "outerStubs_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "outerStubs_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outerStubs_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "outerStubs_dataarray_data_V_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":36, "type": "signal", "bundle":{"name": "outerStubs_dataarray_data_V", "role": "q0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_0", "role": "address0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_0", "role": "ce0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_0", "role": "q0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":11, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_1", "role": "address0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_1", "role": "ce0" }} , 
 	{ "name": "outerVMStubs_dataarray_data_V_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "outerVMStubs_dataarray_data_V_1", "role": "q0" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_0", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_1", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_2", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_2", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_3", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_3", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_4", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_4", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_5", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_5", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_6", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_6", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_0_7", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_0_7", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_0", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_1", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_2", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_2", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_3", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_3", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_4", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_4", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_5", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_5", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_6", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_6", "role": "default" }} , 
 	{ "name": "outerVMStubs_binmask8_V_1_7", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "outerVMStubs_binmask8_V_1_7", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_0", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_1", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_2", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_3", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_3", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_4", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_4", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_5", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_5", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_6", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_6", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_0_7", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_0_7", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_0", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_1", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_2", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_3", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_3", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_4", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_4", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_5", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_5", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_6", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_6", "role": "default" }} , 
 	{ "name": "outerVMStubs_nentries8_V_1_7", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outerVMStubs_nentries8_V_1_7", "role": "default" }} , 
 	{ "name": "trackletParameters_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "trackletParameters_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "trackletParameters_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "trackletParameters_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "trackletParameters_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "trackletParameters_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "trackletParameters_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":70, "type": "signal", "bundle":{"name": "trackletParameters_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_ps_3_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_ps_3_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_ps_3_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_3_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_ps_3_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_3_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_ps_3_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":60, "type": "signal", "bundle":{"name": "projout_barrel_ps_3_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_ps_4_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_ps_4_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_ps_4_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_4_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_ps_4_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_4_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_ps_4_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":60, "type": "signal", "bundle":{"name": "projout_barrel_ps_4_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_ps_5_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_ps_5_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_ps_5_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_5_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_ps_5_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_5_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_ps_5_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":60, "type": "signal", "bundle":{"name": "projout_barrel_ps_5_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_ps_6_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_ps_6_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_ps_6_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_6_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_ps_6_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_ps_6_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_ps_6_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":60, "type": "signal", "bundle":{"name": "projout_barrel_ps_6_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_1_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_1_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_1_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_1_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_1_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_1_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_1_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_1_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_2_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_2_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_2_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_2_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_2_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_2_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_2_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_2_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_3_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_3_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_3_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_3_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_3_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_3_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_3_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_3_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_5_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_5_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_5_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_5_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_5_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_5_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_5_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_5_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_6_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_6_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_6_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_6_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_6_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_6_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_6_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_6_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_barrel_2s_7_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_barrel_2s_7_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_barrel_2s_7_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_7_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_barrel_2s_7_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_barrel_2s_7_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_barrel_2s_7_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "projout_barrel_2s_7_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_1_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_1_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_1_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_1_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_1_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_1_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_1_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_1_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_2_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_2_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_2_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_2_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_2_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_2_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_2_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_2_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_3_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_3_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_3_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_3_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_3_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_3_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_3_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_3_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_5_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_5_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_5_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_5_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_5_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_5_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_5_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_5_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_6_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_6_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_6_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_6_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_6_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_6_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_6_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_6_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_7_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_7_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_7_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_7_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_7_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_7_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_7_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_7_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_9_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_9_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_9_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_9_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_9_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_9_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_9_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_9_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_10_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_10_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_10_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_10_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_10_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_10_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_10_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_10_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_11_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_11_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_11_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_11_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_11_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_11_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_11_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_11_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_13_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_13_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_13_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_13_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_13_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_13_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_13_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_13_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_14_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_14_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_14_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_14_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_14_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_14_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_14_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_14_dataarray_data_V", "role": "d0" }} , 
 	{ "name": "projout_disk_15_dataarray_data_V_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "projout_disk_15_dataarray_data_V", "role": "address0" }} , 
 	{ "name": "projout_disk_15_dataarray_data_V_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_15_dataarray_data_V", "role": "ce0" }} , 
 	{ "name": "projout_disk_15_dataarray_data_V_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "projout_disk_15_dataarray_data_V", "role": "we0" }} , 
 	{ "name": "projout_disk_15_dataarray_data_V_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":59, "type": "signal", "bundle":{"name": "projout_disk_15_dataarray_data_V", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106"],
		"CDFG" : "TrackletProcessor_L2L3C",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "177", "EstimateLatencyMax" : "177",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "bx_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "lut_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "regionlut_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "innerStubs_dataarray_data_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_0_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_1_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_2_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_3_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_4_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_5_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_6_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_0_nentries_7_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_0_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_1_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_2_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_3_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_4_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_5_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_6_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_1_nentries_7_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_0_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_1_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_2_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_3_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_4_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_5_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_6_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "innerStubs_2_nentries_7_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerStubs_dataarray_data_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "outerStubs_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "outerVMStubs_dataarray_data_V_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "outerVMStubs_dataarray_data_V_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_0_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_binmask8_V_1_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_0_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "outerVMStubs_nentries8_V_1_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "trackletParameters_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "trackletParameters_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_0_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_1_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_2_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_3_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_ps_4_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_ps_5_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_ps_6_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_ps_7_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_8_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_9_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_10_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_11_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_12_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_13_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_14_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_15_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_0_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_1_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_2_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_3_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_4_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_5_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_6_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_7_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_8_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_9_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_10_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_11_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_12_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_13_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_14_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_ps_15_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_0_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_1_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_2_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_3_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_4_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_5_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_6_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_7_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_barrel_2s_8_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_9_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_10_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_11_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_0_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_1_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_2_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_3_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_4_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_5_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_6_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_7_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_8_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_9_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_10_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_barrel_2s_11_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_0_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_1_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_2_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_3_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_4_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_5_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_6_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_7_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_8_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_9_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_10_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_11_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_12_dataarray_data_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_13_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_14_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_15_dataarray_data_V", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "projout_disk_0_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_1_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_2_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_3_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_4_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_5_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_6_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_7_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_8_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_9_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_10_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_11_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_12_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_13_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_14_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "projout_disk_15_nentries_V", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "tebuffer_imemend_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_istub_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_imem_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_writeptr_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_readptr_V", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "LUT_drinv_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "LUT_invt_V", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "tebuffer_buffer_V_7", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_0", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_4", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "tebuffer_buffer_V_6", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.LUT_drinv_V_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.LUT_invt_V_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.teunits_0_stubids_V_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.teunits_1_stubids_V_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U1", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U2", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U3", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U4", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U5", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U6", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U7", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U8", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U9", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U10", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U11", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U12", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U13", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U14", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U15", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U16", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U17", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U18", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U19", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U20", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U21", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_164_32_1_1_U22", "Parent" : "0"},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_245_7_1_1_U23", "Parent" : "0"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_83_64_1_1_U24", "Parent" : "0"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_83_16_1_1_U25", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_2568_1_1_1_U26", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_2568_1_1_1_U27", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_2568_1_1_1_U28", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mux_2568_1_1_1_U29", "Parent" : "0"},
	{"ID" : "34", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16ns_16s_30_1_1_U30", "Parent" : "0"},
	{"ID" : "35", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_am_addmul_11ns_11ns_13ns_24_1_1_U31", "Parent" : "0"},
	{"ID" : "36", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16ns_11s_27_1_1_U32", "Parent" : "0"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_11ns_29_1_1_U33", "Parent" : "0"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_11ns_29_1_1_U34", "Parent" : "0"},
	{"ID" : "39", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_12ns_30_1_1_U35", "Parent" : "0"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_16s_30_1_1_U36", "Parent" : "0"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_16s_30_1_1_U37", "Parent" : "0"},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U38", "Parent" : "0"},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U39", "Parent" : "0"},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_11ns_26_1_1_U40", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_11ns_17s_28_1_1_U41", "Parent" : "0"},
	{"ID" : "46", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_17s_30_1_1_U42", "Parent" : "0"},
	{"ID" : "47", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_17s_30_1_1_U43", "Parent" : "0"},
	{"ID" : "48", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_17s_30_1_1_U44", "Parent" : "0"},
	{"ID" : "49", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_34_1_1_U45", "Parent" : "0"},
	{"ID" : "50", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_17s_32_1_1_U46", "Parent" : "0"},
	{"ID" : "51", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_16ns_31_1_1_U47", "Parent" : "0"},
	{"ID" : "52", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_17s_31_1_1_U48", "Parent" : "0"},
	{"ID" : "53", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_18s_33_1_1_U49", "Parent" : "0"},
	{"ID" : "54", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_33_1_1_U50", "Parent" : "0"},
	{"ID" : "55", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_33_1_1_U51", "Parent" : "0"},
	{"ID" : "56", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_33_1_1_U52", "Parent" : "0"},
	{"ID" : "57", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_17ns_17s_34_1_1_U53", "Parent" : "0"},
	{"ID" : "58", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U54", "Parent" : "0"},
	{"ID" : "59", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U55", "Parent" : "0"},
	{"ID" : "60", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U56", "Parent" : "0"},
	{"ID" : "61", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U57", "Parent" : "0"},
	{"ID" : "62", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U58", "Parent" : "0"},
	{"ID" : "63", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U59", "Parent" : "0"},
	{"ID" : "64", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U60", "Parent" : "0"},
	{"ID" : "65", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U61", "Parent" : "0"},
	{"ID" : "66", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U62", "Parent" : "0"},
	{"ID" : "67", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U63", "Parent" : "0"},
	{"ID" : "68", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U64", "Parent" : "0"},
	{"ID" : "69", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U65", "Parent" : "0"},
	{"ID" : "70", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_11ns_18s_29_1_1_U66", "Parent" : "0"},
	{"ID" : "71", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_U67", "Parent" : "0"},
	{"ID" : "72", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_U68", "Parent" : "0"},
	{"ID" : "73", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_13ns_18s_31_1_1_U69", "Parent" : "0"},
	{"ID" : "74", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16s_34_1_1_U70", "Parent" : "0"},
	{"ID" : "75", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_18s_34_1_1_U71", "Parent" : "0"},
	{"ID" : "76", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_17s_18s_34_1_1_U72", "Parent" : "0"},
	{"ID" : "77", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_17s_18s_34_1_1_U73", "Parent" : "0"},
	{"ID" : "78", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_17s_33_1_1_U74", "Parent" : "0"},
	{"ID" : "79", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_33_1_1_U75", "Parent" : "0"},
	{"ID" : "80", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_33_1_1_U76", "Parent" : "0"},
	{"ID" : "81", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_33_1_1_U77", "Parent" : "0"},
	{"ID" : "82", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_33_1_1_U78", "Parent" : "0"},
	{"ID" : "83", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_16s_16ns_31_1_1_U79", "Parent" : "0"},
	{"ID" : "84", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_31_1_1_U80", "Parent" : "0"},
	{"ID" : "85", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_31_1_1_U81", "Parent" : "0"},
	{"ID" : "86", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_16ns_31_1_1_U82", "Parent" : "0"},
	{"ID" : "87", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_17s_18s_32_1_1_U83", "Parent" : "0"},
	{"ID" : "88", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_17s_32_1_1_U84", "Parent" : "0"},
	{"ID" : "89", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_17s_32_1_1_U85", "Parent" : "0"},
	{"ID" : "90", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_17s_32_1_1_U86", "Parent" : "0"},
	{"ID" : "91", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U87", "Parent" : "0"},
	{"ID" : "92", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U88", "Parent" : "0"},
	{"ID" : "93", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U89", "Parent" : "0"},
	{"ID" : "94", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_36_1_1_U90", "Parent" : "0"},
	{"ID" : "95", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U91", "Parent" : "0"},
	{"ID" : "96", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U92", "Parent" : "0"},
	{"ID" : "97", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U93", "Parent" : "0"},
	{"ID" : "98", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U94", "Parent" : "0"},
	{"ID" : "99", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U95", "Parent" : "0"},
	{"ID" : "100", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U96", "Parent" : "0"},
	{"ID" : "101", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U97", "Parent" : "0"},
	{"ID" : "102", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18ns_18s_35_1_1_U98", "Parent" : "0"},
	{"ID" : "103", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_32_1_1_U99", "Parent" : "0"},
	{"ID" : "104", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_32_1_1_U100", "Parent" : "0"},
	{"ID" : "105", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_32_1_1_U101", "Parent" : "0"},
	{"ID" : "106", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.TrackletProcessor_L2L3C_mul_mul_18s_18s_32_1_1_U102", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	TrackletProcessor_L2L3C {
		bx_V {Type I LastRead 0 FirstWrite -1}
		lut_V {Type I LastRead 5 FirstWrite -1}
		regionlut_V {Type I LastRead 5 FirstWrite -1}
		innerStubs_dataarray_data_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_0_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_1_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_2_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_3_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_4_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_5_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_6_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_0_nentries_7_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_0_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_1_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_2_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_3_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_4_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_5_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_6_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_1_nentries_7_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_0_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_1_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_2_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_3_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_4_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_5_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_6_V {Type I LastRead 4 FirstWrite -1}
		innerStubs_2_nentries_7_V {Type I LastRead 4 FirstWrite -1}
		outerStubs_dataarray_data_V {Type I LastRead 9 FirstWrite -1}
		outerStubs_nentries_V {Type X LastRead -1 FirstWrite -1}
		outerVMStubs_dataarray_data_V_0 {Type I LastRead 6 FirstWrite -1}
		outerVMStubs_dataarray_data_V_1 {Type I LastRead 6 FirstWrite -1}
		outerVMStubs_binmask8_V_0_0 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_1 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_2 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_3 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_4 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_5 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_6 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_0_7 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_0 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_1 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_2 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_3 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_4 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_5 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_6 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_binmask8_V_1_7 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_0 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_1 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_2 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_3 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_4 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_5 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_6 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_0_7 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_0 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_1 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_2 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_3 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_4 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_5 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_6 {Type I LastRead 0 FirstWrite -1}
		outerVMStubs_nentries8_V_1_7 {Type I LastRead 0 FirstWrite -1}
		trackletParameters_dataarray_data_V {Type O LastRead -1 FirstWrite 20}
		trackletParameters_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_0_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_1_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_2_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_3_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_ps_4_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_ps_5_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_ps_6_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_ps_7_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_8_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_9_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_10_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_11_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_12_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_13_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_14_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_15_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_0_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_1_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_2_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_3_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_4_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_5_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_6_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_7_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_8_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_9_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_10_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_11_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_12_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_13_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_14_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_ps_15_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_0_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_1_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_2_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_3_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_4_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_5_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_6_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_7_dataarray_data_V {Type O LastRead -1 FirstWrite 24}
		projout_barrel_2s_8_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_9_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_10_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_11_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_0_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_1_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_2_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_3_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_4_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_5_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_6_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_7_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_8_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_9_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_10_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_barrel_2s_11_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_0_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_1_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_2_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_3_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_4_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_5_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_6_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_7_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_8_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_9_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_10_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_11_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_12_dataarray_data_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_13_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_14_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_15_dataarray_data_V {Type O LastRead -1 FirstWrite 28}
		projout_disk_0_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_1_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_2_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_3_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_4_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_5_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_6_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_7_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_8_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_9_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_10_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_11_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_12_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_13_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_14_nentries_V {Type X LastRead -1 FirstWrite -1}
		projout_disk_15_nentries_V {Type X LastRead -1 FirstWrite -1}
		tebuffer_imemend_V {Type IO LastRead -1 FirstWrite -1}
		tebuffer_istub_V {Type IO LastRead -1 FirstWrite -1}
		tebuffer_imem_V {Type IO LastRead -1 FirstWrite -1}
		tebuffer_writeptr_V {Type IO LastRead -1 FirstWrite -1}
		tebuffer_readptr_V {Type IO LastRead -1 FirstWrite -1}
		LUT_drinv_V {Type I LastRead -1 FirstWrite -1}
		LUT_invt_V {Type I LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_7 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_0 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_1 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_2 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_3 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_4 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_5 {Type IO LastRead -1 FirstWrite -1}
		tebuffer_buffer_V_6 {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "177", "Max" : "177"}
	, {"Name" : "Interval", "Min" : "178", "Max" : "178"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bx_V { ap_none {  { bx_V in_data 0 3 } } }
	lut_V { ap_memory {  { lut_V_address0 mem_address 1 11 }  { lut_V_ce0 mem_ce 1 1 }  { lut_V_q0 mem_dout 0 10 } } }
	regionlut_V { ap_memory {  { regionlut_V_address0 mem_address 1 11 }  { regionlut_V_ce0 mem_ce 1 1 }  { regionlut_V_q0 mem_dout 0 8 } } }
	innerStubs_dataarray_data_V { ap_memory {  { innerStubs_dataarray_data_V_address0 mem_address 1 12 }  { innerStubs_dataarray_data_V_ce0 mem_ce 1 1 }  { innerStubs_dataarray_data_V_q0 mem_dout 0 51 } } }
	innerStubs_0_nentries_0_V { ap_none {  { innerStubs_0_nentries_0_V in_data 0 7 } } }
	innerStubs_0_nentries_1_V { ap_none {  { innerStubs_0_nentries_1_V in_data 0 7 } } }
	innerStubs_0_nentries_2_V { ap_none {  { innerStubs_0_nentries_2_V in_data 0 7 } } }
	innerStubs_0_nentries_3_V { ap_none {  { innerStubs_0_nentries_3_V in_data 0 7 } } }
	innerStubs_0_nentries_4_V { ap_none {  { innerStubs_0_nentries_4_V in_data 0 7 } } }
	innerStubs_0_nentries_5_V { ap_none {  { innerStubs_0_nentries_5_V in_data 0 7 } } }
	innerStubs_0_nentries_6_V { ap_none {  { innerStubs_0_nentries_6_V in_data 0 7 } } }
	innerStubs_0_nentries_7_V { ap_none {  { innerStubs_0_nentries_7_V in_data 0 7 } } }
	innerStubs_1_nentries_0_V { ap_none {  { innerStubs_1_nentries_0_V in_data 0 7 } } }
	innerStubs_1_nentries_1_V { ap_none {  { innerStubs_1_nentries_1_V in_data 0 7 } } }
	innerStubs_1_nentries_2_V { ap_none {  { innerStubs_1_nentries_2_V in_data 0 7 } } }
	innerStubs_1_nentries_3_V { ap_none {  { innerStubs_1_nentries_3_V in_data 0 7 } } }
	innerStubs_1_nentries_4_V { ap_none {  { innerStubs_1_nentries_4_V in_data 0 7 } } }
	innerStubs_1_nentries_5_V { ap_none {  { innerStubs_1_nentries_5_V in_data 0 7 } } }
	innerStubs_1_nentries_6_V { ap_none {  { innerStubs_1_nentries_6_V in_data 0 7 } } }
	innerStubs_1_nentries_7_V { ap_none {  { innerStubs_1_nentries_7_V in_data 0 7 } } }
	innerStubs_2_nentries_0_V { ap_none {  { innerStubs_2_nentries_0_V in_data 0 7 } } }
	innerStubs_2_nentries_1_V { ap_none {  { innerStubs_2_nentries_1_V in_data 0 7 } } }
	innerStubs_2_nentries_2_V { ap_none {  { innerStubs_2_nentries_2_V in_data 0 7 } } }
	innerStubs_2_nentries_3_V { ap_none {  { innerStubs_2_nentries_3_V in_data 0 7 } } }
	innerStubs_2_nentries_4_V { ap_none {  { innerStubs_2_nentries_4_V in_data 0 7 } } }
	innerStubs_2_nentries_5_V { ap_none {  { innerStubs_2_nentries_5_V in_data 0 7 } } }
	innerStubs_2_nentries_6_V { ap_none {  { innerStubs_2_nentries_6_V in_data 0 7 } } }
	innerStubs_2_nentries_7_V { ap_none {  { innerStubs_2_nentries_7_V in_data 0 7 } } }
	outerStubs_dataarray_data_V { ap_memory {  { outerStubs_dataarray_data_V_address0 mem_address 1 10 }  { outerStubs_dataarray_data_V_ce0 mem_ce 1 1 }  { outerStubs_dataarray_data_V_q0 mem_dout 0 36 } } }
	outerVMStubs_dataarray_data_V_0 { ap_memory {  { outerVMStubs_dataarray_data_V_0_address0 mem_address 1 11 }  { outerVMStubs_dataarray_data_V_0_ce0 mem_ce 1 1 }  { outerVMStubs_dataarray_data_V_0_q0 mem_dout 0 16 } } }
	outerVMStubs_dataarray_data_V_1 { ap_memory {  { outerVMStubs_dataarray_data_V_1_address0 mem_address 1 11 }  { outerVMStubs_dataarray_data_V_1_ce0 mem_ce 1 1 }  { outerVMStubs_dataarray_data_V_1_q0 mem_dout 0 16 } } }
	outerVMStubs_binmask8_V_0_0 { ap_none {  { outerVMStubs_binmask8_V_0_0 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_1 { ap_none {  { outerVMStubs_binmask8_V_0_1 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_2 { ap_none {  { outerVMStubs_binmask8_V_0_2 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_3 { ap_none {  { outerVMStubs_binmask8_V_0_3 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_4 { ap_none {  { outerVMStubs_binmask8_V_0_4 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_5 { ap_none {  { outerVMStubs_binmask8_V_0_5 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_6 { ap_none {  { outerVMStubs_binmask8_V_0_6 in_data 0 8 } } }
	outerVMStubs_binmask8_V_0_7 { ap_none {  { outerVMStubs_binmask8_V_0_7 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_0 { ap_none {  { outerVMStubs_binmask8_V_1_0 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_1 { ap_none {  { outerVMStubs_binmask8_V_1_1 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_2 { ap_none {  { outerVMStubs_binmask8_V_1_2 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_3 { ap_none {  { outerVMStubs_binmask8_V_1_3 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_4 { ap_none {  { outerVMStubs_binmask8_V_1_4 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_5 { ap_none {  { outerVMStubs_binmask8_V_1_5 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_6 { ap_none {  { outerVMStubs_binmask8_V_1_6 in_data 0 8 } } }
	outerVMStubs_binmask8_V_1_7 { ap_none {  { outerVMStubs_binmask8_V_1_7 in_data 0 8 } } }
	outerVMStubs_nentries8_V_0_0 { ap_none {  { outerVMStubs_nentries8_V_0_0 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_1 { ap_none {  { outerVMStubs_nentries8_V_0_1 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_2 { ap_none {  { outerVMStubs_nentries8_V_0_2 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_3 { ap_none {  { outerVMStubs_nentries8_V_0_3 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_4 { ap_none {  { outerVMStubs_nentries8_V_0_4 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_5 { ap_none {  { outerVMStubs_nentries8_V_0_5 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_6 { ap_none {  { outerVMStubs_nentries8_V_0_6 in_data 0 32 } } }
	outerVMStubs_nentries8_V_0_7 { ap_none {  { outerVMStubs_nentries8_V_0_7 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_0 { ap_none {  { outerVMStubs_nentries8_V_1_0 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_1 { ap_none {  { outerVMStubs_nentries8_V_1_1 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_2 { ap_none {  { outerVMStubs_nentries8_V_1_2 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_3 { ap_none {  { outerVMStubs_nentries8_V_1_3 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_4 { ap_none {  { outerVMStubs_nentries8_V_1_4 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_5 { ap_none {  { outerVMStubs_nentries8_V_1_5 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_6 { ap_none {  { outerVMStubs_nentries8_V_1_6 in_data 0 32 } } }
	outerVMStubs_nentries8_V_1_7 { ap_none {  { outerVMStubs_nentries8_V_1_7 in_data 0 32 } } }
	trackletParameters_dataarray_data_V { ap_memory {  { trackletParameters_dataarray_data_V_address0 mem_address 1 10 }  { trackletParameters_dataarray_data_V_ce0 mem_ce 1 1 }  { trackletParameters_dataarray_data_V_we0 mem_we 1 1 }  { trackletParameters_dataarray_data_V_d0 mem_din 1 70 } } }
	projout_barrel_ps_3_dataarray_data_V { ap_memory {  { projout_barrel_ps_3_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_ps_3_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_ps_3_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_ps_3_dataarray_data_V_d0 mem_din 1 60 } } }
	projout_barrel_ps_4_dataarray_data_V { ap_memory {  { projout_barrel_ps_4_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_ps_4_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_ps_4_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_ps_4_dataarray_data_V_d0 mem_din 1 60 } } }
	projout_barrel_ps_5_dataarray_data_V { ap_memory {  { projout_barrel_ps_5_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_ps_5_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_ps_5_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_ps_5_dataarray_data_V_d0 mem_din 1 60 } } }
	projout_barrel_ps_6_dataarray_data_V { ap_memory {  { projout_barrel_ps_6_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_ps_6_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_ps_6_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_ps_6_dataarray_data_V_d0 mem_din 1 60 } } }
	projout_barrel_2s_1_dataarray_data_V { ap_memory {  { projout_barrel_2s_1_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_1_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_1_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_1_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_barrel_2s_2_dataarray_data_V { ap_memory {  { projout_barrel_2s_2_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_2_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_2_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_2_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_barrel_2s_3_dataarray_data_V { ap_memory {  { projout_barrel_2s_3_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_3_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_3_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_3_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_barrel_2s_5_dataarray_data_V { ap_memory {  { projout_barrel_2s_5_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_5_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_5_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_5_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_barrel_2s_6_dataarray_data_V { ap_memory {  { projout_barrel_2s_6_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_6_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_6_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_6_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_barrel_2s_7_dataarray_data_V { ap_memory {  { projout_barrel_2s_7_dataarray_data_V_address0 mem_address 1 8 }  { projout_barrel_2s_7_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_barrel_2s_7_dataarray_data_V_we0 mem_we 1 1 }  { projout_barrel_2s_7_dataarray_data_V_d0 mem_din 1 58 } } }
	projout_disk_1_dataarray_data_V { ap_memory {  { projout_disk_1_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_1_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_1_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_1_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_2_dataarray_data_V { ap_memory {  { projout_disk_2_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_2_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_2_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_2_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_3_dataarray_data_V { ap_memory {  { projout_disk_3_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_3_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_3_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_3_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_5_dataarray_data_V { ap_memory {  { projout_disk_5_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_5_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_5_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_5_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_6_dataarray_data_V { ap_memory {  { projout_disk_6_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_6_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_6_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_6_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_7_dataarray_data_V { ap_memory {  { projout_disk_7_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_7_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_7_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_7_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_9_dataarray_data_V { ap_memory {  { projout_disk_9_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_9_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_9_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_9_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_10_dataarray_data_V { ap_memory {  { projout_disk_10_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_10_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_10_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_10_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_11_dataarray_data_V { ap_memory {  { projout_disk_11_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_11_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_11_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_11_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_13_dataarray_data_V { ap_memory {  { projout_disk_13_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_13_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_13_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_13_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_14_dataarray_data_V { ap_memory {  { projout_disk_14_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_14_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_14_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_14_dataarray_data_V_d0 mem_din 1 59 } } }
	projout_disk_15_dataarray_data_V { ap_memory {  { projout_disk_15_dataarray_data_V_address0 mem_address 1 8 }  { projout_disk_15_dataarray_data_V_ce0 mem_ce 1 1 }  { projout_disk_15_dataarray_data_V_we0 mem_we 1 1 }  { projout_disk_15_dataarray_data_V_d0 mem_din 1 59 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
	{ lut_V 2 }
	{ regionlut_V 2 }
	{ innerStubs_dataarray_data_V 2 }
	{ outerStubs_dataarray_data_V 2 }
	{ outerVMStubs_dataarray_data_V_0 2 }
	{ outerVMStubs_dataarray_data_V_1 2 }
}
