core_file = scripts/xciMaker
core_dir = cgn
input_file = mem/in.txt
proj_path = ../../../proj
#currently just build FPGA1 project
fpga1_hls_script_path = ../../CombinedConfig/IRtoTP/script 
fpga2_hls_script_path = ../../CombinedConfig_FPGA2/script

all: add_common_files $(core_file) hdl_add_files xciCreation kfin_adj $(input_file) apollo_input lut_inclusion

$(core_dir):
	@mkdir cgn mem
	#make -C $(fpga1_hls_script_path) -j 24 Work
	@make -C $(fpga2_hls_script_path) -j 24 Work
	@cd mem; ln -s ../../../../emData/LUTsCM LUTs
	@cd mem; ln -s ../../../../emData/MemPrintsCM MemPrintsCM
	@cd hdl; ln -s ../../../common common

$(core_file): $(core_dir)
	#@python3 scripts/include_cores.py -s $(fpga1_hls_script_path)
	@python3 scripts/include_cores.py -s $(fpga2_hls_script_path)

kfin_adj:
	@python3 scripts/kf_link_mod.py

xciCreation: $(core_file)
	make -f $(core_file) -j 8 all

add_common_files:
	@if [ ! -d ucf ]; then mkdir ucf; fi
	@cd ucf; ln -s ../../../common/ucf/*.tcl .
	@cd scripts; ln -s ../../../common/script/emp/* .
	#@cd scripts; ln -s ../../../common/script/emp/*.py .
	#@cd scripts; ln -s ../../../common/script/emp/*.tcl .

hdl_add_files: $(core_file)
	#cd hdl; ln -s ../../../CombinedConfig/IRtoTP/hdl/*.vhd .
	cd hdl; ln -s ../../../CombinedConfig_FPGA2/hdl/*.vhd .

lut_inclusion:
	@python3 scripts/lut_copy_dual.py

$(input_file): $(core_dir)
	@python3 scripts/convert_emData2EMP_Link.py -d mem/MemPrintsCM/InputStubs -o $(input_file)

apollo_input: $(input_file)
	@python3 scripts/split_emp_input.py

.PHONY: all add_common_files hdl_add_files xciCreation kfin_adj apollo_input lut_inclusion core_patch
