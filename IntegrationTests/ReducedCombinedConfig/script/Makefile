# relative path to IntegrationTests/ (modify if Makefile is moved)
INT_TESTS=../..

# other useful definitions
MAKE_HLS=$(INT_TESTS)/common/script/makeHLSProject.tcl
COMPILE_HLS=$(INT_TESTS)/common/script/compileHLS.tcl
TOP_FUNCS=$(INT_TESTS)/../TopFunctions/ReducedCombinedConfig
TRK_ALGO=$(INT_TESTS)/../TrackletAlgorithm
EMDATA=$(INT_TESTS)/../emData

Work/Work.runs/impl_1: Work/Work.runs/synth_1
	vivado -mode batch -source ./common/script/impl.tcl

Work/Work.runs/synth_1: Work ../hdl/*.vhd $(INT_TESTS)/common/hdl/*.vhd
	vivado -mode batch -source ./common/script/synth.tcl

### Make Vivado project ###

Work: common MemPrints LUTs InputRouterTop_IR_DTC_PS10G_1_A InputRouterTop_IR_DTC_PS10G_2_A InputRouterTop_IR_DTC_PS10G_3_A InputRouterTop_IR_DTC_PS_1_A InputRouterTop_IR_DTC_PS_2_A InputRouterTop_IR_DTC_2S_1_A InputRouterTop_IR_DTC_2S_2_A InputRouterTop_IR_DTC_2S_3_A InputRouterTop_IR_DTC_2S_4_A VMRouterCMTop_L1PHIB VMRouterCMTop_L2PHIA VMRouterCMTop_L3PHIA VMRouterCMTop_L4PHIA VMRouterCMTop_L5PHIA VMRouterCMTop_L6PHIA TrackletProcessor_L1L2C MatchProcessor_L3PHIA MatchProcessor_L4PHIA MatchProcessor_L5PHIA MatchProcessor_L6PHIA TrackBuilder_L1L2
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrintsReducedCM MemPrints

LUTs:
	ln -sf $(EMDATA)/LUTsCMReduced LUTs

### Make HLS IPs ###

InputRouterTop_IR_DTC_PS10G_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_1_A

InputRouterTop_IR_DTC_PS10G_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_2_A

InputRouterTop_IR_DTC_PS10G_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_3_A

InputRouterTop_IR_DTC_PS_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_1_A

InputRouterTop_IR_DTC_PS_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_2_A

InputRouterTop_IR_DTC_2S_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_1_A

InputRouterTop_IR_DTC_2S_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_2_A

InputRouterTop_IR_DTC_2S_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_3_A

InputRouterTop_IR_DTC_2S_4_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_4_A

VMRouterCMTop_L1PHIB: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L1PHIB.cc $(TOP_FUNCS)/VMRouterCMTop_L1PHIB.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L1PHIB.cc VMRouterCMTop_L1PHIB

VMRouterCMTop_L2PHIA: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L2PHIA.cc $(TOP_FUNCS)/VMRouterCMTop_L2PHIA.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L2PHIA.cc VMRouterCMTop_L2PHIA

VMRouterCMTop_L3PHIA: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L3PHIA.cc $(TOP_FUNCS)/VMRouterCMTop_L3PHIA.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L3PHIA.cc VMRouterCMTop_L3PHIA

VMRouterCMTop_L4PHIA: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L4PHIA.cc $(TOP_FUNCS)/VMRouterCMTop_L4PHIA.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L4PHIA.cc VMRouterCMTop_L4PHIA

VMRouterCMTop_L5PHIA: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L5PHIA.cc $(TOP_FUNCS)/VMRouterCMTop_L5PHIA.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L5PHIA.cc VMRouterCMTop_L5PHIA

VMRouterCMTop_L6PHIA: $(TOP_FUNCS)/VMRouterCM_parameters.h $(TOP_FUNCS)/VMRouterCMTop_L6PHIA.cc $(TOP_FUNCS)/VMRouterCMTop_L6PHIA.h $(TRK_ALGO)/VMRouterCM.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterCMTop_L6PHIA.cc VMRouterCMTop_L6PHIA

TrackletProcessor_L1L2C: $(TOP_FUNCS)/TrackletProcessor_parameters.h $(TOP_FUNCS)/TrackletProcessorTop.cc $(TOP_FUNCS)/TrackletProcessorTop.h $(TRK_ALGO)/TrackletEngineUnit.h $(TRK_ALGO)/TrackletProcessor.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletProcessorTop.cc TrackletProcessor_L1L2C

MatchProcessor_L3PHIA: $(TOP_FUNCS)/MatchProcessor_parameters.h $(TOP_FUNCS)/MatchProcessorTop.cc $(TOP_FUNCS)/MatchProcessorTop.h $(TRK_ALGO)/MatchEngineUnit.h $(TRK_ALGO)/MatchEngineUnit_parameters.h $(TRK_ALGO)/MatchProcessor.h $(TRK_ALGO)/ProjectionRouterBufferArray.h $(TRK_ALGO)/ProjectionRouterBuffer.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchProcessorTop.cc MatchProcessor_L3PHIA

MatchProcessor_L4PHIA: $(TOP_FUNCS)/MatchProcessor_parameters.h $(TOP_FUNCS)/MatchProcessorTop.cc $(TOP_FUNCS)/MatchProcessorTop.h $(TRK_ALGO)/MatchEngineUnit.h $(TRK_ALGO)/MatchEngineUnit_parameters.h $(TRK_ALGO)/MatchProcessor.h $(TRK_ALGO)/ProjectionRouterBufferArray.h $(TRK_ALGO)/ProjectionRouterBuffer.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchProcessorTop.cc MatchProcessor_L4PHIA

MatchProcessor_L5PHIA: $(TOP_FUNCS)/MatchProcessor_parameters.h $(TOP_FUNCS)/MatchProcessorTop.cc $(TOP_FUNCS)/MatchProcessorTop.h $(TRK_ALGO)/MatchEngineUnit.h $(TRK_ALGO)/MatchEngineUnit_parameters.h $(TRK_ALGO)/MatchProcessor.h $(TRK_ALGO)/ProjectionRouterBufferArray.h $(TRK_ALGO)/ProjectionRouterBuffer.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchProcessorTop.cc MatchProcessor_L5PHIA

MatchProcessor_L6PHIA: $(TOP_FUNCS)/MatchProcessor_parameters.h $(TOP_FUNCS)/MatchProcessorTop.cc $(TOP_FUNCS)/MatchProcessorTop.h $(TRK_ALGO)/MatchEngineUnit.h $(TRK_ALGO)/MatchEngineUnit_parameters.h $(TRK_ALGO)/MatchProcessor.h $(TRK_ALGO)/ProjectionRouterBufferArray.h $(TRK_ALGO)/ProjectionRouterBuffer.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchProcessorTop.cc MatchProcessor_L6PHIA

TrackBuilder_L1L2: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L1L2

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints LUTs vivado*.log vivado*.jou InputRouterTop_IR_DTC_PS10G_1_A/ InputRouterTop_IR_DTC_PS10G_2_A/ InputRouterTop_IR_DTC_PS10G_3_A/ InputRouterTop_IR_DTC_PS_1_A/ InputRouterTop_IR_DTC_PS_2_A/ InputRouterTop_IR_DTC_2S_1_A/ InputRouterTop_IR_DTC_2S_2_A/ InputRouterTop_IR_DTC_2S_3_A/ InputRouterTop_IR_DTC_2S_4_A/ VMRouterCMTop_L1PHIB/ VMRouterCMTop_L2PHIA/ VMRouterCMTop_L3PHIA/ VMRouterCMTop_L4PHIA/ VMRouterCMTop_L5PHIA/ VMRouterCMTop_L6PHIA/ TrackletProcessor_L1L2C/ MatchProcessor_L3PHIA/ MatchProcessor_L4PHIA/ MatchProcessor_L5PHIA/ MatchProcessor_L6PHIA/ TrackBuilder_L1L2/ Work/
