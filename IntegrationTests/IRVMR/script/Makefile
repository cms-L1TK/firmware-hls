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

Work: common MemPrints InputRouterTop_IR_DTC_PS10G_3_A VMRouterTop_L2PHIA
	rm -rfv Work/
	vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	ln -sf $(INT_TESTS)/common common

MemPrints:
	ln -sf $(EMDATA)/MemPrints MemPrints

### Make HLS IPs ###

InputRouterTop_IR_DTC_PS10G_3_A: $(TOP_FUNCS)/InputRouter_parameters.h $(TOP_FUNCS)/InputRouterTop.cc $(TOP_FUNCS)/InputRouterTop.h $(TRK_ALGO)/InputRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/InputRouterTop.cc InputRouterTop_IR_DTC_PS10G_3_A

VMRouterTop_L2PHIA: $(TOP_FUNCS)/VMRouter_parameters.h $(TOP_FUNCS)/VMRouterTop_L2PHIA.cc $(TOP_FUNCS)/VMRouterTop_L2PHIA.h $(TRK_ALGO)/VMRouter.h
	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/VMRouterTop_L2PHIA.cc VMRouterTop_L2PHIA

### Other targets ###

.PHONY: clean
clean:
	rm -rfv common MemPrints vivado*.log vivado*.jou InputRouterTop_IR_DTC_PS10G_3_A/ VMRouterTop_L2PHIA/ Work/
