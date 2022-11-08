# relative path to IntegrationTests/ (modify if Makefile is moved)
INT_TESTS=../../..

# other useful definitions
MAKE_HLS=$(INT_TESTS)/common/script/makeHLSProject.tcl
COMPILE_HLS=$(INT_TESTS)/common/script/compileHLS.tcl
TOP_FUNCS=$(INT_TESTS)/../TopFunctions/ReducedConfig
TRK_ALGO=$(INT_TESTS)/../TrackletAlgorithm
EMDATA=$(INT_TESTS)/../emData

Work/Work.runs/impl_1: Work/Work.runs/synth_1
	vivado -mode batch -source ./common/script/impl.tcl

Work/Work.runs/synth_1: Work ../hdl/*.vhd $(INT_TESTS)/common/hdl/*.vhd
	vivado -mode batch -source ./common/script/synth.tcl

### Make Vivado project ###

Work: common MemPrints LUTs InputRouterTop_IR_DTC_PS10G_1_A InputRouterTop_IR_DTC_PS10G_2_A InputRouterTop_IR_DTC_PS10G_2_B InputRouterTop_IR_DTC_PS10G_3_A InputRouterTop_IR_DTC_PS10G_3_B InputRouterTop_IR_DTC_PS_1_A InputRouterTop_IR_DTC_PS_2_A InputRouterTop_IR_DTC_PS_2_B InputRouterTop_IR_DTC_2S_1_A InputRouterTop_IR_DTC_2S_1_B InputRouterTop_IR_DTC_2S_2_A InputRouterTop_IR_DTC_2S_2_B InputRouterTop_IR_DTC_2S_3_A InputRouterTop_IR_DTC_2S_4_A InputRouterTop_IR_DTC_2S_4_B VMRouterTop_L1PHID VMRouterTop_L2PHIB VMRouterTop_L3PHIB VMRouterTop_L4PHIB VMRouterTop_L5PHIB VMRouterTop_L6PHIB TrackletEngine_PS_PS TrackletCalculator_L1L2F ProjectionRouterTop_L3PHIB ProjectionRouterTop_L4PHIB ProjectionRouterTop_L5PHIB ProjectionRouterTop_L6PHIB MatchEngineTop_L3 MatchEngineTop_L4 MatchEngineTop_L5 MatchEngineTop_L6 MatchCalculator_L3PHIB MatchCalculator_L4PHIB MatchCalculator_L5PHIB MatchCalculator_L6PHIB TrackBuilder_L1L2
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrintsReduced MemPrints

LUTs:
	ln -sf $(EMDATA)/LUTsReduced LUTs

### Make HLS IPs ###

InputRouterTop_IR_DTC_PS10G_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_1_A

InputRouterTop_IR_DTC_PS10G_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_2_A

InputRouterTop_IR_DTC_PS10G_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_2_B

InputRouterTop_IR_DTC_PS10G_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_3_A

InputRouterTop_IR_DTC_PS10G_3_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_3_B

InputRouterTop_IR_DTC_PS_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_1_A

InputRouterTop_IR_DTC_PS_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_2_A

InputRouterTop_IR_DTC_PS_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_2_B

InputRouterTop_IR_DTC_2S_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_1_A

InputRouterTop_IR_DTC_2S_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_1_B

InputRouterTop_IR_DTC_2S_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_2_A

InputRouterTop_IR_DTC_2S_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_2_B

InputRouterTop_IR_DTC_2S_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_3_A

InputRouterTop_IR_DTC_2S_4_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_4_A

InputRouterTop_IR_DTC_2S_4_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_4_B

VMRouterTop_L1PHID: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L1PHID.cc $(TOP_FUNCS)/VMRouterTop_L1PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHID.cc VMRouterTop_L1PHID

VMRouterTop_L2PHIB: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L2PHIB.cc $(TOP_FUNCS)/VMRouterTop_L2PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHIB.cc VMRouterTop_L2PHIB

VMRouterTop_L3PHIB: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L3PHIB.cc $(TOP_FUNCS)/VMRouterTop_L3PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L3PHIB.cc VMRouterTop_L3PHIB

VMRouterTop_L4PHIB: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L4PHIB.cc $(TOP_FUNCS)/VMRouterTop_L4PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L4PHIB.cc VMRouterTop_L4PHIB

VMRouterTop_L5PHIB: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L5PHIB.cc $(TOP_FUNCS)/VMRouterTop_L5PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L5PHIB.cc VMRouterTop_L5PHIB

VMRouterTop_L6PHIB: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L6PHIB.cc $(TOP_FUNCS)/VMRouterTop_L6PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L6PHIB.cc VMRouterTop_L6PHIB

TrackletEngine_PS_PS: $(TOP_FUNCS)/TrackletEngineTop.cc $(TOP_FUNCS)/TrackletEngineTop.h $(TRK_ALGO)/TrackletEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletEngineTop.cc TrackletEngine_PS_PS

TrackletCalculator_L1L2F: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2F

ProjectionRouterTop_L3PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHIB

ProjectionRouterTop_L4PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L4PHIB

ProjectionRouterTop_L5PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L5PHIB

ProjectionRouterTop_L6PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L6PHIB

MatchEngineTop_L3: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L3

MatchEngineTop_L4: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L4

MatchEngineTop_L5: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L5

MatchEngineTop_L6: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L6

MatchCalculator_L3PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHIB

MatchCalculator_L4PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L4PHIB

MatchCalculator_L5PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L5PHIB

MatchCalculator_L6PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L6PHIB

TrackBuilder_L1L2: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L1L2

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints LUTs vivado*.log vivado*.jou InputRouterTop_IR_DTC_PS10G_1_A/ InputRouterTop_IR_DTC_PS10G_2_A/ InputRouterTop_IR_DTC_PS10G_2_B/ InputRouterTop_IR_DTC_PS10G_3_A/ InputRouterTop_IR_DTC_PS10G_3_B/ InputRouterTop_IR_DTC_PS_1_A/ InputRouterTop_IR_DTC_PS_2_A/ InputRouterTop_IR_DTC_PS_2_B/ InputRouterTop_IR_DTC_2S_1_A/ InputRouterTop_IR_DTC_2S_1_B/ InputRouterTop_IR_DTC_2S_2_A/ InputRouterTop_IR_DTC_2S_2_B/ InputRouterTop_IR_DTC_2S_3_A/ InputRouterTop_IR_DTC_2S_4_A/ InputRouterTop_IR_DTC_2S_4_B/ VMRouterTop_L1PHID/ VMRouterTop_L2PHIB/ VMRouterTop_L3PHIB/ VMRouterTop_L4PHIB/ VMRouterTop_L5PHIB/ VMRouterTop_L6PHIB/ TrackletEngine_PS_PS/ TrackletCalculator_L1L2F/ ProjectionRouterTop_L3PHIB/ ProjectionRouterTop_L4PHIB/ ProjectionRouterTop_L5PHIB/ ProjectionRouterTop_L6PHIB/ MatchEngineTop_L3/ MatchEngineTop_L4/ MatchEngineTop_L5/ MatchEngineTop_L6/ MatchCalculator_L3PHIB/ MatchCalculator_L4PHIB/ MatchCalculator_L5PHIB/ MatchCalculator_L6PHIB/ TrackBuilder_L1L2/ Work/
