# This file contains the common rules for all the Makefiles in
# IntegrationTests/. It assumes the prior definitions of FIRMWARE, TOP_FUNCS,
# and MODULES.

# Useful path definitions
INT_TESTS=$(FIRMWARE)/IntegrationTests
COMPILE_HLS=$(INT_TESTS)/common/script/compileHLS.tcl
TRK_ALGO=$(FIRMWARE)/TrackletAlgorithm
EMDATA=$(FIRMWARE)/emData
DEPS=.deps

# Path of GCC version bundled with Vivado
XILINX_GCC=$(shell find $(XILINX_VIVADO)/tps -type f -name gcc)

### Synthesis and implementation ###

Work/Work.runs/impl_1: Work/Work.runs/synth_1
	@vivado -mode batch -source ./common/script/impl.tcl

Work/Work.runs/synth_1: Work ../hdl/*.vhd $(INT_TESTS)/common/hdl/*.vhd
	@vivado -mode batch -source ./common/script/synth.tcl

### Make Vivado project ###

Work: common MemPrints LUTs $(MODULES)
	@rm -rfv Work/; \
	 vivado -mode batch -source ./makeProject.tcl

### Make symbolic links ###

common:
	@ln -sf $(INT_TESTS)/common common

MemPrints:
	@BASE_DIR=`echo ${TOP_FUNCS} | sed 's,.*\/\([^/]\+\)\/*,\1,g'`; \
	 if [[ $${BASE_DIR} == "BarrelConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/MemPrintsBarrel MemPrints; \
	 elif [[ $${BASE_DIR} == "CombinedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/MemPrintsCM MemPrints; \
	 elif [[ $${BASE_DIR} == "ReducedCombinedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/MemPrintsReducedCM MemPrints; \
	 elif [[ $${BASE_DIR} == "ReducedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/MemPrintsReduced MemPrints; \
	 else \
	   ln -sf $(EMDATA)/MemPrints MemPrints; \
	 fi

LUTs:
	@BASE_DIR=`echo ${TOP_FUNCS} | sed 's,.*\/\([^/]\+\)\/*,\1,g'`; \
	 if [[ $${BASE_DIR} == "BarrelConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/LUTsBarrel LUTs; \
	 elif [[ $${BASE_DIR} == "CombinedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/LUTsCM LUTs; \
	 elif [[ $${BASE_DIR} == "ReducedCombinedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/LUTsCMReduced LUTs; \
	 elif [[ $${BASE_DIR} == "ReducedConfig" ]]; \
	 then \
	   ln -sf $(EMDATA)/LUTsReduced LUTs; \
	 else \
	   ln -sf $(EMDATA)/LUTs LUTs; \
	 fi

### Make HLS IPs ###

# Dependency files are created following the example in the manual for GNU make:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html

$(DEPS)/functions/%.d: $(EMDATA)/MemPrints
	@set -e; rm -f $@; mkdir -p $(DEPS)/functions; \
	 TOP_FUNC=`echo $@ | sed 's,.*\/\([^/]*\)\.d,\1,g'`; \
	 TOP_FILE=`grep -l $${TOP_FUNC} $(TOP_FUNCS)/*.cc | sed 's,.*\/\([^/]*\)\.cc,\1,g'`; \
	 echo "$${TOP_FUNC}: $(DEPS)/files/$${TOP_FILE}.d $(EMDATA)/MemPrints" > $@; \
	 echo "	vivado_hls -f $(COMPILE_HLS) $(TOP_FUNCS)/$${TOP_FILE}.cc $${TOP_FUNC}" >> $@; \
	 echo "" >> $@; \
	 echo "include $(DEPS)/files/$${TOP_FILE}.d" >> $@

$(DEPS)/files/%.d: $(TOP_FUNCS)/%.cc
	@set -e; rm -f $@; mkdir -p $(DEPS)/files; \
	 $(XILINX_GCC) -MM -I$(TRK_ALGO) -I$(TOP_FUNCS) -I$(XILINX_VIVADO)/include $< > $@.$$$$; \
	 sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	 rm -f $@.$$$$

include $(MODULES:%=$(DEPS)/functions/%.d)

### Run emData/download.sh before anything else ###

$(EMDATA)/MemPrints: $(EMDATA)/download.sh
	@cd $(EMDATA)/; \
	  ./clean.sh; \
	  ./download.sh; \
	  touch MemPrints

### Other targets ###

.PHONY: clean
clean:
	@rm -rfv common MemPrints LUTs vivado*.log vivado*.jou $(MODULES) Work/
