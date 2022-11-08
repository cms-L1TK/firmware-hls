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

Work: common MemPrints LUTs TrackletEngine_PS_PS TrackletCalculator_L1L2E
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrints MemPrints

LUTs:
	ln -sf $(EMDATA)/LUTs LUTs

### Make HLS IPs ###

TrackletEngine_PS_PS: $(TOP_FUNCS)/TrackletEngineTop.cc $(TOP_FUNCS)/TrackletEngineTop.h $(TRK_ALGO)/TrackletEngine.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletEngineTop.cc TrackletEngine_PS_PS

TrackletCalculator_L1L2E: $(TOP_FUNCS)/TrackletCalculator_parameters.h $(TOP_FUNCS)/TrackletCalculatorTop.cc $(TOP_FUNCS)/TrackletCalculatorTop.h $(TRK_ALGO)/TrackletCalculator_calculate_LXLY.h $(TRK_ALGO)/TrackletCalculator.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/TrackletCalculatorTop.cc TrackletCalculator_L1L2E

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints LUTs vivado*.log vivado*.jou TrackletEngine_PS_PS/ TrackletCalculator_L1L2E/ Work/
