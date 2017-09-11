set moduleName VMRouterDispatcher_AddStub
set isCombinational 1
set isDatapathOnly 0
set isPipelined 0
set pipeline_type function
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set C_modelName {VMRouterDispatcher_AddStub}
set C_modelType { int 18 }
set C_modelArgList {
	{ HLSReducedStubLayer_z_V_write int 4 regular  }
	{ HLSReducedStubLayer_phi_V_write int 3 regular  }
	{ HLSReducedStubLayer_r_V_write int 2 regular  }
	{ HLSReducedStubLayer_pt_V_write int 3 regular  }
	{ HLSReducedStubLayer_index_V_write int 6 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "HLSReducedStubLayer_z_V_write", "interface" : "wire", "bitwidth" : 4, "direction" : "READONLY"} , 
 	{ "Name" : "HLSReducedStubLayer_phi_V_write", "interface" : "wire", "bitwidth" : 3, "direction" : "READONLY"} , 
 	{ "Name" : "HLSReducedStubLayer_r_V_write", "interface" : "wire", "bitwidth" : 2, "direction" : "READONLY"} , 
 	{ "Name" : "HLSReducedStubLayer_pt_V_write", "interface" : "wire", "bitwidth" : 3, "direction" : "READONLY"} , 
 	{ "Name" : "HLSReducedStubLayer_index_V_write", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 18} ]}
# RTL Port declarations: 
set portNum 10
set portList { 
	{ HLSReducedStubLayer_z_V_write sc_in sc_lv 4 signal 0 } 
	{ HLSReducedStubLayer_phi_V_write sc_in sc_lv 3 signal 1 } 
	{ HLSReducedStubLayer_r_V_write sc_in sc_lv 2 signal 2 } 
	{ HLSReducedStubLayer_pt_V_write sc_in sc_lv 3 signal 3 } 
	{ HLSReducedStubLayer_index_V_write sc_in sc_lv 6 signal 4 } 
	{ ap_return_0 sc_out sc_lv 4 signal -1 } 
	{ ap_return_1 sc_out sc_lv 3 signal -1 } 
	{ ap_return_2 sc_out sc_lv 2 signal -1 } 
	{ ap_return_3 sc_out sc_lv 3 signal -1 } 
	{ ap_return_4 sc_out sc_lv 6 signal -1 } 
}
set NewPortList {[ 
	{ "name": "HLSReducedStubLayer_z_V_write", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "HLSReducedStubLayer_z_V_write", "role": "default" }} , 
 	{ "name": "HLSReducedStubLayer_phi_V_write", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "HLSReducedStubLayer_phi_V_write", "role": "default" }} , 
 	{ "name": "HLSReducedStubLayer_r_V_write", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "HLSReducedStubLayer_r_V_write", "role": "default" }} , 
 	{ "name": "HLSReducedStubLayer_pt_V_write", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "HLSReducedStubLayer_pt_V_write", "role": "default" }} , 
 	{ "name": "HLSReducedStubLayer_index_V_write", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "HLSReducedStubLayer_index_V_write", "role": "default" }} , 
 	{ "name": "ap_return_0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ap_return_0", "role": "default" }} , 
 	{ "name": "ap_return_1", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "ap_return_1", "role": "default" }} , 
 	{ "name": "ap_return_2", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ap_return_2", "role": "default" }} , 
 	{ "name": "ap_return_3", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "ap_return_3", "role": "default" }} , 
 	{ "name": "ap_return_4", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "ap_return_4", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : [], "CDFG" : "VMRouterDispatcher_AddStub", "VariableLatency" : "0", "AlignedPipeline" : "0", "UnalignedPipeline" : "0", "ProcessNetwork" : "0", "Combinational" : "1", "ControlExist" : "0",
		"Port" : [
		{"Name" : "HLSReducedStubLayer_z_V_write", "Type" : "None", "Direction" : "I", "BlockSignal" : [], "SubConnect" : []}, 
		{"Name" : "HLSReducedStubLayer_phi_V_write", "Type" : "None", "Direction" : "I", "BlockSignal" : [], "SubConnect" : []}, 
		{"Name" : "HLSReducedStubLayer_r_V_write", "Type" : "None", "Direction" : "I", "BlockSignal" : [], "SubConnect" : []}, 
		{"Name" : "HLSReducedStubLayer_pt_V_write", "Type" : "None", "Direction" : "I", "BlockSignal" : [], "SubConnect" : []}, 
		{"Name" : "HLSReducedStubLayer_index_V_write", "Type" : "None", "Direction" : "I", "BlockSignal" : [], "SubConnect" : []}],
		"WaitState" : [],
		"SubBlockPort" : []}]}

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "0", "Max" : "0"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set Spec2ImplPortList { 
	HLSReducedStubLayer_z_V_write { ap_none {  { HLSReducedStubLayer_z_V_write in_data 0 4 } } }
	HLSReducedStubLayer_phi_V_write { ap_none {  { HLSReducedStubLayer_phi_V_write in_data 0 3 } } }
	HLSReducedStubLayer_r_V_write { ap_none {  { HLSReducedStubLayer_r_V_write in_data 0 2 } } }
	HLSReducedStubLayer_pt_V_write { ap_none {  { HLSReducedStubLayer_pt_V_write in_data 0 3 } } }
	HLSReducedStubLayer_index_V_write { ap_none {  { HLSReducedStubLayer_index_V_write in_data 0 6 } } }
}
