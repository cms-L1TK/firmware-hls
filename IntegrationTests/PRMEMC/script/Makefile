# relative path to IntegrationTests/ (modify if Makefile is moved)
INT_TESTS=../..

# other useful definitions
MAKE_HLS=$(INT_TESTS)/common/script/makeHLSProject.tcl
COMPILE_HLS=$(INT_TESTS)/common/script/compileHLS.tcl
TOP_FUNCS=$(INT_TESTS)/../TopFunctions
TRK_ALGO=$(INT_TESTS)/../TrackletAlgorithm
EMDATA=$(INT_TESTS)/../emData

Work/Work.runs/impl_1: Work/Work.runs/synth_1
	vivado -mode batch -source ./common/script/impl.tcl

Work/Work.runs/synth_1: Work ../hdl/*.vhd $(INT_TESTS)/common/hdl/*.vhd
	vivado -mode batch -source ./common/script/synth.tcl

### Make Vivado project ###

Work: common MemPrints ProjectionRouterTop_L3PHIC MatchEngineTop_L3 MatchCalculator_L3PHIC
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrints MemPrints

### Make HLS IPs ###

ProjectionRouterTop_L3PHIC: $(TOP_FUNCS)/ProjectionRouterTop.cc $(TOP_FUNCS)/ProjectionRouterTop.h $(TRK_ALGO)/ProjectionRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/ProjectionRouterTop.cc ProjectionRouterTop_L3PHIC

MatchEngineTop_L3: $(TOP_FUNCS)/MatchEngineTop.cc $(TOP_FUNCS)/MatchEngineTop.h $(TRK_ALGO)/MatchEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchEngineTop.cc MatchEngineTop_L3

MatchCalculator_L3PHIC: $(TOP_FUNCS)/MatchCalculator_parameters.h $(TOP_FUNCS)/MatchCalculatorTop.cc $(TOP_FUNCS)/MatchCalculatorTop.h $(TRK_ALGO)/MatchCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/MatchCalculatorTop.cc MatchCalculator_L3PHIC

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints vivado*.log vivado*.jou ProjectionRouterTop_L3PHIC/ MatchEngineTop_L3/ MatchCalculator_L3PHIC/ Work/
