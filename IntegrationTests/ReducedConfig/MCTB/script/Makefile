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

Work: common MemPrints MatchCalculator_L3PHIB MatchCalculator_L4PHIB MatchCalculator_L5PHIB MatchCalculator_L6PHIB TrackBuilder_L1L2
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrintsReduced MemPrints

### Make HLS IPs ###

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
	rm -rfv common MemPrints vivado*.log vivado*.jou MatchCalculator_L3PHIB/ MatchCalculator_L4PHIB/ MatchCalculator_L5PHIB/ MatchCalculator_L6PHIB/ TrackBuilder_L1L2/ Work/
