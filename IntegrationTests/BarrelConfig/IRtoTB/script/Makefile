# relative path to IntegrationTests/ (modify if Makefile is moved)
INT_TESTS=../../..

# other useful definitions
MAKE_HLS=$(INT_TESTS)/common/script/makeHLSProject.tcl
COMPILE_HLS=$(INT_TESTS)/common/script/compileHLS.tcl
TOP_FUNCS=$(INT_TESTS)/../TopFunctions/BarrelConfig
TRK_ALGO=$(INT_TESTS)/../TrackletAlgorithm
EMDATA=$(INT_TESTS)/../emData

Work/Work.runs/impl_1: Work/Work.runs/synth_1
	vivado -mode batch -source ./common/script/impl.tcl

Work/Work.runs/synth_1: Work ../hdl/*.vhd $(INT_TESTS)/common/hdl/*.vhd
	vivado -mode batch -source ./common/script/synth.tcl

### Make Vivado project ###

Work: common MemPrints LUTs InputRouterTop_IR_DTC_2S_1_A InputRouterTop_IR_DTC_2S_1_B InputRouterTop_IR_DTC_2S_2_A InputRouterTop_IR_DTC_2S_2_B InputRouterTop_IR_DTC_2S_3_A InputRouterTop_IR_DTC_2S_3_B InputRouterTop_IR_DTC_2S_4_A InputRouterTop_IR_DTC_2S_4_B InputRouterTop_IR_DTC_neg2S_1_A InputRouterTop_IR_DTC_neg2S_1_B InputRouterTop_IR_DTC_neg2S_2_A InputRouterTop_IR_DTC_neg2S_2_B InputRouterTop_IR_DTC_neg2S_3_A InputRouterTop_IR_DTC_neg2S_3_B InputRouterTop_IR_DTC_neg2S_4_A InputRouterTop_IR_DTC_neg2S_4_B InputRouterTop_IR_DTC_negPS10G_1_A InputRouterTop_IR_DTC_negPS10G_1_B InputRouterTop_IR_DTC_negPS10G_2_A InputRouterTop_IR_DTC_negPS10G_2_B InputRouterTop_IR_DTC_negPS10G_3_A InputRouterTop_IR_DTC_negPS10G_3_B InputRouterTop_IR_DTC_negPS_1_A InputRouterTop_IR_DTC_negPS_1_B InputRouterTop_IR_DTC_negPS_2_A InputRouterTop_IR_DTC_negPS_2_B InputRouterTop_IR_DTC_PS10G_1_A InputRouterTop_IR_DTC_PS10G_1_B InputRouterTop_IR_DTC_PS10G_2_A InputRouterTop_IR_DTC_PS10G_2_B InputRouterTop_IR_DTC_PS10G_3_A InputRouterTop_IR_DTC_PS10G_3_B InputRouterTop_IR_DTC_PS_1_A InputRouterTop_IR_DTC_PS_1_B InputRouterTop_IR_DTC_PS_2_A InputRouterTop_IR_DTC_PS_2_B VMRouterTop_L1PHIA VMRouterTop_L1PHIB VMRouterTop_L1PHIC VMRouterTop_L1PHID VMRouterTop_L1PHIE VMRouterTop_L1PHIF VMRouterTop_L1PHIG VMRouterTop_L1PHIH VMRouterTop_L2PHIA VMRouterTop_L2PHIB VMRouterTop_L2PHIC VMRouterTop_L2PHID VMRouterTop_L3PHIA VMRouterTop_L3PHIB VMRouterTop_L3PHIC VMRouterTop_L3PHID VMRouterTop_L4PHIA VMRouterTop_L4PHIB VMRouterTop_L4PHIC VMRouterTop_L4PHID VMRouterTop_L5PHIA VMRouterTop_L5PHIB VMRouterTop_L5PHIC VMRouterTop_L5PHID VMRouterTop_L6PHIA VMRouterTop_L6PHIB VMRouterTop_L6PHIC VMRouterTop_L6PHID TrackletEngine_PS_PS TrackletEngine_PS_2S TrackletEngine_2S_2S TrackletCalculator_L1L2A TrackletCalculator_L1L2B TrackletCalculator_L1L2C TrackletCalculator_L1L2D TrackletCalculator_L1L2E TrackletCalculator_L1L2F TrackletCalculator_L1L2G TrackletCalculator_L1L2H TrackletCalculator_L1L2I TrackletCalculator_L1L2J TrackletCalculator_L1L2K TrackletCalculator_L1L2L TrackletCalculator_L2L3A TrackletCalculator_L2L3B TrackletCalculator_L2L3C TrackletCalculator_L2L3D TrackletCalculator_L3L4A TrackletCalculator_L3L4B TrackletCalculator_L3L4C TrackletCalculator_L3L4D TrackletCalculator_L5L6A TrackletCalculator_L5L6B TrackletCalculator_L5L6C TrackletCalculator_L5L6D ProjectionRouterTop_L1PHIA ProjectionRouterTop_L1PHIB ProjectionRouterTop_L1PHIC ProjectionRouterTop_L1PHID ProjectionRouterTop_L1PHIE ProjectionRouterTop_L1PHIF ProjectionRouterTop_L1PHIG ProjectionRouterTop_L1PHIH ProjectionRouterTop_L2PHIA ProjectionRouterTop_L2PHIB ProjectionRouterTop_L2PHIC ProjectionRouterTop_L2PHID ProjectionRouterTop_L3PHIA ProjectionRouterTop_L3PHIB ProjectionRouterTop_L3PHIC ProjectionRouterTop_L3PHID ProjectionRouterTop_L4PHIA ProjectionRouterTop_L4PHIB ProjectionRouterTop_L4PHIC ProjectionRouterTop_L4PHID ProjectionRouterTop_L5PHIA ProjectionRouterTop_L5PHIB ProjectionRouterTop_L5PHIC ProjectionRouterTop_L5PHID ProjectionRouterTop_L6PHIA ProjectionRouterTop_L6PHIB ProjectionRouterTop_L6PHIC ProjectionRouterTop_L6PHID MatchEngineTop_L1 MatchEngineTop_L2 MatchEngineTop_L3 MatchEngineTop_L4 MatchEngineTop_L5 MatchEngineTop_L6 MatchCalculator_L1PHIA MatchCalculator_L1PHIB MatchCalculator_L1PHIC MatchCalculator_L1PHID MatchCalculator_L1PHIE MatchCalculator_L1PHIF MatchCalculator_L1PHIG MatchCalculator_L1PHIH MatchCalculator_L2PHIA MatchCalculator_L2PHIB MatchCalculator_L2PHIC MatchCalculator_L2PHID MatchCalculator_L3PHIA MatchCalculator_L3PHIB MatchCalculator_L3PHIC MatchCalculator_L3PHID MatchCalculator_L4PHIA MatchCalculator_L4PHIB MatchCalculator_L4PHIC MatchCalculator_L4PHID MatchCalculator_L5PHIA MatchCalculator_L5PHIB MatchCalculator_L5PHIC MatchCalculator_L5PHID MatchCalculator_L6PHIA MatchCalculator_L6PHIB MatchCalculator_L6PHIC MatchCalculator_L6PHID TrackBuilder_L1L2 TrackBuilder_L2L3 TrackBuilder_L3L4 TrackBuilder_L5L6
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrintsBarrel MemPrints

LUTs:
	ln -sf $(EMDATA)/LUTsBarrel LUTs

### Make HLS IPs ###

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

InputRouterTop_IR_DTC_2S_3_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_3_B

InputRouterTop_IR_DTC_2S_4_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_4_A

InputRouterTop_IR_DTC_2S_4_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_2S_4_B

InputRouterTop_IR_DTC_neg2S_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_1_A

InputRouterTop_IR_DTC_neg2S_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_1_B

InputRouterTop_IR_DTC_neg2S_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_2_A

InputRouterTop_IR_DTC_neg2S_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_2_B

InputRouterTop_IR_DTC_neg2S_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_3_A

InputRouterTop_IR_DTC_neg2S_3_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_3_B

InputRouterTop_IR_DTC_neg2S_4_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_4_A

InputRouterTop_IR_DTC_neg2S_4_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_neg2S_4_B

InputRouterTop_IR_DTC_negPS10G_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_1_A

InputRouterTop_IR_DTC_negPS10G_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_1_B

InputRouterTop_IR_DTC_negPS10G_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_2_A

InputRouterTop_IR_DTC_negPS10G_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_2_B

InputRouterTop_IR_DTC_negPS10G_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_3_A

InputRouterTop_IR_DTC_negPS10G_3_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS10G_3_B

InputRouterTop_IR_DTC_negPS_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS_1_A

InputRouterTop_IR_DTC_negPS_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS_1_B

InputRouterTop_IR_DTC_negPS_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS_2_A

InputRouterTop_IR_DTC_negPS_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_negPS_2_B

InputRouterTop_IR_DTC_PS10G_1_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_1_A

InputRouterTop_IR_DTC_PS10G_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_1_B

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

InputRouterTop_IR_DTC_PS_1_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_1_B

InputRouterTop_IR_DTC_PS_2_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_2_A

InputRouterTop_IR_DTC_PS_2_B: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS_2_B

VMRouterTop_L1PHIA: $(TOP_FUNCS)/VMRouterTop_L1PHIA.cc $(TOP_FUNCS)/VMRouterTop_L1PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIA.cc VMRouterTop_L1PHIA

VMRouterTop_L1PHIB: $(TOP_FUNCS)/VMRouterTop_L1PHIB.cc $(TOP_FUNCS)/VMRouterTop_L1PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIB.cc VMRouterTop_L1PHIB

VMRouterTop_L1PHIC: $(TOP_FUNCS)/VMRouterTop_L1PHIC.cc $(TOP_FUNCS)/VMRouterTop_L1PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIC.cc VMRouterTop_L1PHIC

VMRouterTop_L1PHID: $(TOP_FUNCS)/VMRouterTop_L1PHID.cc $(TOP_FUNCS)/VMRouterTop_L1PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHID.cc VMRouterTop_L1PHID

VMRouterTop_L1PHIE: $(TOP_FUNCS)/VMRouterTop_L1PHIE.cc $(TOP_FUNCS)/VMRouterTop_L1PHIE.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIE.cc VMRouterTop_L1PHIE

VMRouterTop_L1PHIF: $(TOP_FUNCS)/VMRouterTop_L1PHIF.cc $(TOP_FUNCS)/VMRouterTop_L1PHIF.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIF.cc VMRouterTop_L1PHIF

VMRouterTop_L1PHIG: $(TOP_FUNCS)/VMRouterTop_L1PHIG.cc $(TOP_FUNCS)/VMRouterTop_L1PHIG.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIG.cc VMRouterTop_L1PHIG

VMRouterTop_L1PHIH: $(TOP_FUNCS)/VMRouterTop_L1PHIH.cc $(TOP_FUNCS)/VMRouterTop_L1PHIH.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L1PHIH.cc VMRouterTop_L1PHIH

VMRouterTop_L2PHIA: $(TOP_FUNCS)/VMRouterTop_L2PHIA.cc $(TOP_FUNCS)/VMRouterTop_L2PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHIA.cc VMRouterTop_L2PHIA

VMRouterTop_L2PHIB: $(TOP_FUNCS)/VMRouterTop_L2PHIB.cc $(TOP_FUNCS)/VMRouterTop_L2PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHIB.cc VMRouterTop_L2PHIB

VMRouterTop_L2PHIC: $(TOP_FUNCS)/VMRouterTop_L2PHIC.cc $(TOP_FUNCS)/VMRouterTop_L2PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHIC.cc VMRouterTop_L2PHIC

VMRouterTop_L2PHID: $(TOP_FUNCS)/VMRouterTop_L2PHID.cc $(TOP_FUNCS)/VMRouterTop_L2PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHID.cc VMRouterTop_L2PHID

VMRouterTop_L3PHIA: $(TOP_FUNCS)/VMRouterTop_L3PHIA.cc $(TOP_FUNCS)/VMRouterTop_L3PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L3PHIA.cc VMRouterTop_L3PHIA

VMRouterTop_L3PHIB: $(TOP_FUNCS)/VMRouterTop_L3PHIB.cc $(TOP_FUNCS)/VMRouterTop_L3PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L3PHIB.cc VMRouterTop_L3PHIB

VMRouterTop_L3PHIC: $(TOP_FUNCS)/VMRouterTop_L3PHIC.cc $(TOP_FUNCS)/VMRouterTop_L3PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L3PHIC.cc VMRouterTop_L3PHIC

VMRouterTop_L3PHID: $(TOP_FUNCS)/VMRouterTop_L3PHID.cc $(TOP_FUNCS)/VMRouterTop_L3PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L3PHID.cc VMRouterTop_L3PHID

VMRouterTop_L4PHIA: $(TOP_FUNCS)/VMRouterTop_L4PHIA.cc $(TOP_FUNCS)/VMRouterTop_L4PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L4PHIA.cc VMRouterTop_L4PHIA

VMRouterTop_L4PHIB: $(TOP_FUNCS)/VMRouterTop_L4PHIB.cc $(TOP_FUNCS)/VMRouterTop_L4PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L4PHIB.cc VMRouterTop_L4PHIB

VMRouterTop_L4PHIC: $(TOP_FUNCS)/VMRouterTop_L4PHIC.cc $(TOP_FUNCS)/VMRouterTop_L4PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L4PHIC.cc VMRouterTop_L4PHIC

VMRouterTop_L4PHID: $(TOP_FUNCS)/VMRouterTop_L4PHID.cc $(TOP_FUNCS)/VMRouterTop_L4PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L4PHID.cc VMRouterTop_L4PHID

VMRouterTop_L5PHIA: $(TOP_FUNCS)/VMRouterTop_L5PHIA.cc $(TOP_FUNCS)/VMRouterTop_L5PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L5PHIA.cc VMRouterTop_L5PHIA

VMRouterTop_L5PHIB: $(TOP_FUNCS)/VMRouterTop_L5PHIB.cc $(TOP_FUNCS)/VMRouterTop_L5PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L5PHIB.cc VMRouterTop_L5PHIB

VMRouterTop_L5PHIC: $(TOP_FUNCS)/VMRouterTop_L5PHIC.cc $(TOP_FUNCS)/VMRouterTop_L5PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L5PHIC.cc VMRouterTop_L5PHIC

VMRouterTop_L5PHID: $(TOP_FUNCS)/VMRouterTop_L5PHID.cc $(TOP_FUNCS)/VMRouterTop_L5PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L5PHID.cc VMRouterTop_L5PHID

VMRouterTop_L6PHIA: $(TOP_FUNCS)/VMRouterTop_L6PHIA.cc $(TOP_FUNCS)/VMRouterTop_L6PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L6PHIA.cc VMRouterTop_L6PHIA

VMRouterTop_L6PHIB: $(TOP_FUNCS)/VMRouterTop_L6PHIB.cc $(TOP_FUNCS)/VMRouterTop_L6PHIB.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L6PHIB.cc VMRouterTop_L6PHIB

VMRouterTop_L6PHIC: $(TOP_FUNCS)/VMRouterTop_L6PHIC.cc $(TOP_FUNCS)/VMRouterTop_L6PHIC.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L6PHIC.cc VMRouterTop_L6PHIC

VMRouterTop_L6PHID: $(TOP_FUNCS)/VMRouterTop_L6PHID.cc $(TOP_FUNCS)/VMRouterTop_L6PHID.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L6PHID.cc VMRouterTop_L6PHID

TrackletEngine_PS_PS: $(TOP_FUNCS)/TrackletEngineTop.cc $(TOP_FUNCS)/TrackletEngineTop.h $(TRK_ALGO)/TrackletEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletEngineTop.cc TrackletEngine_PS_PS

TrackletEngine_PS_2S: $(TOP_FUNCS)/TrackletEngineTop.cc $(TOP_FUNCS)/TrackletEngineTop.h $(TRK_ALGO)/TrackletEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletEngineTop.cc TrackletEngine_PS_2S

TrackletEngine_2S_2S: $(TOP_FUNCS)/TrackletEngineTop.cc $(TOP_FUNCS)/TrackletEngineTop.h $(TRK_ALGO)/TrackletEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletEngineTop.cc TrackletEngine_2S_2S

TrackletCalculator_L1L2A: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2A

TrackletCalculator_L1L2B: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2B

TrackletCalculator_L1L2C: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2C

TrackletCalculator_L1L2D: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2D

TrackletCalculator_L1L2E: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2E

TrackletCalculator_L1L2F: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2F

TrackletCalculator_L1L2G: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2G

TrackletCalculator_L1L2H: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2H

TrackletCalculator_L1L2I: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2I

TrackletCalculator_L1L2J: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2J

TrackletCalculator_L1L2K: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2K

TrackletCalculator_L1L2L: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2L

TrackletCalculator_L2L3A: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L2L3A

TrackletCalculator_L2L3B: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L2L3B

TrackletCalculator_L2L3C: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L2L3C

TrackletCalculator_L2L3D: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L2L3D

TrackletCalculator_L3L4A: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L3L4A

TrackletCalculator_L3L4B: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L3L4B

TrackletCalculator_L3L4C: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L3L4C

TrackletCalculator_L3L4D: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L3L4D

TrackletCalculator_L5L6A: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L5L6A

TrackletCalculator_L5L6B: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L5L6B

TrackletCalculator_L5L6C: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L5L6C

TrackletCalculator_L5L6D: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L5L6D

ProjectionRouterTop_L1PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIA

ProjectionRouterTop_L1PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIB

ProjectionRouterTop_L1PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIC

ProjectionRouterTop_L1PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHID

ProjectionRouterTop_L1PHIE: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIE

ProjectionRouterTop_L1PHIF: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIF

ProjectionRouterTop_L1PHIG: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIG

ProjectionRouterTop_L1PHIH: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L1PHIH

ProjectionRouterTop_L2PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L2PHIA

ProjectionRouterTop_L2PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L2PHIB

ProjectionRouterTop_L2PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L2PHIC

ProjectionRouterTop_L2PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L2PHID

ProjectionRouterTop_L3PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHIA

ProjectionRouterTop_L3PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHIB

ProjectionRouterTop_L3PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHIC

ProjectionRouterTop_L3PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHID

ProjectionRouterTop_L4PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L4PHIA

ProjectionRouterTop_L4PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L4PHIB

ProjectionRouterTop_L4PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L4PHIC

ProjectionRouterTop_L4PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L4PHID

ProjectionRouterTop_L5PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L5PHIA

ProjectionRouterTop_L5PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L5PHIB

ProjectionRouterTop_L5PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L5PHIC

ProjectionRouterTop_L5PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L5PHID

ProjectionRouterTop_L6PHIA: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L6PHIA

ProjectionRouterTop_L6PHIB: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L6PHIB

ProjectionRouterTop_L6PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L6PHIC

ProjectionRouterTop_L6PHID: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L6PHID

MatchEngineTop_L1: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L1

MatchEngineTop_L2: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L2

MatchEngineTop_L3: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L3

MatchEngineTop_L4: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L4

MatchEngineTop_L5: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L5

MatchEngineTop_L6: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L6

MatchCalculator_L1PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIA

MatchCalculator_L1PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIB

MatchCalculator_L1PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIC

MatchCalculator_L1PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHID

MatchCalculator_L1PHIE: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIE

MatchCalculator_L1PHIF: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIF

MatchCalculator_L1PHIG: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIG

MatchCalculator_L1PHIH: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L1PHIH

MatchCalculator_L2PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L2PHIA

MatchCalculator_L2PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L2PHIB

MatchCalculator_L2PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L2PHIC

MatchCalculator_L2PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L2PHID

MatchCalculator_L3PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHIA

MatchCalculator_L3PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHIB

MatchCalculator_L3PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHIC

MatchCalculator_L3PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHID

MatchCalculator_L4PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L4PHIA

MatchCalculator_L4PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L4PHIB

MatchCalculator_L4PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L4PHIC

MatchCalculator_L4PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L4PHID

MatchCalculator_L5PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L5PHIA

MatchCalculator_L5PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L5PHIB

MatchCalculator_L5PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L5PHIC

MatchCalculator_L5PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L5PHID

MatchCalculator_L6PHIA: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L6PHIA

MatchCalculator_L6PHIB: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L6PHIB

MatchCalculator_L6PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L6PHIC

MatchCalculator_L6PHID: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L6PHID

TrackBuilder_L1L2: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L1L2

TrackBuilder_L2L3: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L2L3

TrackBuilder_L3L4: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L3L4

TrackBuilder_L5L6: $(TOP_FUNCS)/TrackBuilderTop.cc $(TOP_FUNCS)/TrackBuilderTop.h $(TRK_ALGO)/TrackBuilder.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackBuilderTop.cc TrackBuilder_L5L6

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints LUTs vivado*.log vivado*.jou InputRouterTop_IR_DTC_2S_1_A/ InputRouterTop_IR_DTC_2S_1_B/ InputRouterTop_IR_DTC_2S_2_A/ InputRouterTop_IR_DTC_2S_2_B/ InputRouterTop_IR_DTC_2S_3_A/ InputRouterTop_IR_DTC_2S_3_B/ InputRouterTop_IR_DTC_2S_4_A/ InputRouterTop_IR_DTC_2S_4_B/ InputRouterTop_IR_DTC_neg2S_1_A/ InputRouterTop_IR_DTC_neg2S_1_B/ InputRouterTop_IR_DTC_neg2S_2_A/ InputRouterTop_IR_DTC_neg2S_2_B/ InputRouterTop_IR_DTC_neg2S_3_A/ InputRouterTop_IR_DTC_neg2S_3_B/ InputRouterTop_IR_DTC_neg2S_4_A/ InputRouterTop_IR_DTC_neg2S_4_B/ InputRouterTop_IR_DTC_negPS10G_1_A/ InputRouterTop_IR_DTC_negPS10G_1_B/ InputRouterTop_IR_DTC_negPS10G_2_A/ InputRouterTop_IR_DTC_negPS10G_2_B/ InputRouterTop_IR_DTC_negPS10G_3_A/ InputRouterTop_IR_DTC_negPS10G_3_B/ InputRouterTop_IR_DTC_negPS_1_A/ InputRouterTop_IR_DTC_negPS_1_B/ InputRouterTop_IR_DTC_negPS_2_A/ InputRouterTop_IR_DTC_negPS_2_B/ InputRouterTop_IR_DTC_PS10G_1_A/ InputRouterTop_IR_DTC_PS10G_1_B/ InputRouterTop_IR_DTC_PS10G_2_A/ InputRouterTop_IR_DTC_PS10G_2_B/ InputRouterTop_IR_DTC_PS10G_3_A/ InputRouterTop_IR_DTC_PS10G_3_B/ InputRouterTop_IR_DTC_PS_1_A/ InputRouterTop_IR_DTC_PS_1_B/ InputRouterTop_IR_DTC_PS_2_A/ InputRouterTop_IR_DTC_PS_2_B/ VMRouterTop_L1PHIA/ VMRouterTop_L1PHIB/ VMRouterTop_L1PHIC/ VMRouterTop_L1PHID/ VMRouterTop_L1PHIE/ VMRouterTop_L1PHIF/ VMRouterTop_L1PHIG/ VMRouterTop_L1PHIH/ VMRouterTop_L2PHIA/ VMRouterTop_L2PHIB/ VMRouterTop_L2PHIC/ VMRouterTop_L2PHID/ VMRouterTop_L3PHIA/ VMRouterTop_L3PHIB/ VMRouterTop_L3PHIC/ VMRouterTop_L3PHID/ VMRouterTop_L4PHIA/ VMRouterTop_L4PHIB/ VMRouterTop_L4PHIC/ VMRouterTop_L4PHID/ VMRouterTop_L5PHIA/ VMRouterTop_L5PHIB/ VMRouterTop_L5PHIC/ VMRouterTop_L5PHID/ VMRouterTop_L6PHIA/ VMRouterTop_L6PHIB/ VMRouterTop_L6PHIC/ VMRouterTop_L6PHID/ TrackletEngine_PS_PS/ TrackletEngine_PS_2S/ TrackletEngine_2S_2S/ TrackletCalculator_L1L2A/ TrackletCalculator_L1L2B/ TrackletCalculator_L1L2C/ TrackletCalculator_L1L2D/ TrackletCalculator_L1L2E/ TrackletCalculator_L1L2F/ TrackletCalculator_L1L2G/ TrackletCalculator_L1L2H/ TrackletCalculator_L1L2I/ TrackletCalculator_L1L2J/ TrackletCalculator_L1L2K/ TrackletCalculator_L1L2L/ TrackletCalculator_L2L3A/ TrackletCalculator_L2L3B/ TrackletCalculator_L2L3C/ TrackletCalculator_L2L3D/ TrackletCalculator_L3L4A/ TrackletCalculator_L3L4B/ TrackletCalculator_L3L4C/ TrackletCalculator_L3L4D/ TrackletCalculator_L5L6A/ TrackletCalculator_L5L6B/ TrackletCalculator_L5L6C/ TrackletCalculator_L5L6D/ ProjectionRouterTop_L1PHIA/ ProjectionRouterTop_L1PHIB/ ProjectionRouterTop_L1PHIC/ ProjectionRouterTop_L1PHID/ ProjectionRouterTop_L1PHIE/ ProjectionRouterTop_L1PHIF/ ProjectionRouterTop_L1PHIG/ ProjectionRouterTop_L1PHIH/ ProjectionRouterTop_L2PHIA/ ProjectionRouterTop_L2PHIB/ ProjectionRouterTop_L2PHIC/ ProjectionRouterTop_L2PHID/ ProjectionRouterTop_L3PHIA/ ProjectionRouterTop_L3PHIB/ ProjectionRouterTop_L3PHIC/ ProjectionRouterTop_L3PHID/ ProjectionRouterTop_L4PHIA/ ProjectionRouterTop_L4PHIB/ ProjectionRouterTop_L4PHIC/ ProjectionRouterTop_L4PHID/ ProjectionRouterTop_L5PHIA/ ProjectionRouterTop_L5PHIB/ ProjectionRouterTop_L5PHIC/ ProjectionRouterTop_L5PHID/ ProjectionRouterTop_L6PHIA/ ProjectionRouterTop_L6PHIB/ ProjectionRouterTop_L6PHIC/ ProjectionRouterTop_L6PHID/ MatchEngineTop_L1/ MatchEngineTop_L2/ MatchEngineTop_L3/ MatchEngineTop_L4/ MatchEngineTop_L5/ MatchEngineTop_L6/ MatchCalculator_L1PHIA/ MatchCalculator_L1PHIB/ MatchCalculator_L1PHIC/ MatchCalculator_L1PHID/ MatchCalculator_L1PHIE/ MatchCalculator_L1PHIF/ MatchCalculator_L1PHIG/ MatchCalculator_L1PHIH/ MatchCalculator_L2PHIA/ MatchCalculator_L2PHIB/ MatchCalculator_L2PHIC/ MatchCalculator_L2PHID/ MatchCalculator_L3PHIA/ MatchCalculator_L3PHIB/ MatchCalculator_L3PHIC/ MatchCalculator_L3PHID/ MatchCalculator_L4PHIA/ MatchCalculator_L4PHIB/ MatchCalculator_L4PHIC/ MatchCalculator_L4PHID/ MatchCalculator_L5PHIA/ MatchCalculator_L5PHIB/ MatchCalculator_L5PHIC/ MatchCalculator_L5PHID/ MatchCalculator_L6PHIA/ MatchCalculator_L6PHIB/ MatchCalculator_L6PHIC/ MatchCalculator_L6PHID/ TrackBuilder_L1L2/ TrackBuilder_L2L3/ TrackBuilder_L3L4/ TrackBuilder_L5L6/ Work/
