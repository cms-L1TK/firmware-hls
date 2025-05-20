core_file_fpga1 = scripts/xciMaker_fpga1
core_file_fpga2 = scripts/xciMaker_fpga2
core_dir = cgn
input_file_fpga1 = mem/in_fpga1.txt
input_file_fpga2 = mem/in_fpga2.txt
fpga1_hls_script_path = ../../CombinedConfig_FPGA1/script 
fpga2_hls_script_path = ../../CombinedConfig_FPGA2/script

all: add_common_files $(core_file_fpga1) $(core_file_fpga2) hdl_add_files_fpga1 hdl_add_files_fpga2 xciCreation_fpga1 xciCreation_fpga2 kfin_adj $(input_file_fpga1) $(input_file_fpga2)

fpga1: add_common_files $(core_file_fpga1) hdl_add_files_fpga1 xciCreation_fpga1 kfin_adj $(input_file_fpga1)

fpga2: add_common_files $(core_file_fpga2) hdl_add_files_fpga2 xciCreation_fpga2 kfin_adj $(input_file_fpga2)

$(core_dir):
	@mkdir cgn mem
	@mkdir cgn/f1
	@mkdir cgn/f2
	@cd mem; ln -s ../../../../emData/LUTsSplit LUTs
	@cd mem; ln -s ../../../../emData/MemPrintsSplit MemPrintsSplit
	@cd hdl; ln -s ../../../common common

$(core_file_fpga1): $(core_dir)
	make -C $(fpga1_hls_script_path) -j 64 Work
	@python3 scripts/include_cores.py -s $(fpga1_hls_script_path) -o $(core_file_fpga1) -f f1

$(core_file_fpga2): $(core_dir)
	make -C $(fpga2_hls_script_path) -j 64 Work
	@python3 scripts/include_cores.py -s $(fpga2_hls_script_path) -o $(core_file_fpga2) -f f2

kfin_adj:
	@python3 scripts/kf_link_mod.py

xciCreation_fpga1: $(core_file_fpga1)
	make -f $(core_file_fpga1) -j 64 all

xciCreation_fpga2: $(core_file_fpga2)
	make -f $(core_file_fpga2) -j 64 all

add_common_files:
	@if [ ! -d ucf ]; then mkdir ucf; fi
	@cd ucf; ln -s ../../../common/ucf/*.tcl .
	@cd scripts; ln -s ../../../common/script/emp/* .

hdl_add_files_fpga1: $(core_file)
	cd hdl; ln -s ../../../CombinedConfig_FPGA1/hdl/SectorProcessor.vhd SectorProcessor_f1.vhd
	cd hdl; ln -s ../../../CombinedConfig_FPGA1/hdl/memUtil_pkg.vhd memUtil_pkg_f1.vhd

hdl_add_files_fpga2: $(core_file)
	cd hdl; ln -s ../../../CombinedConfig_FPGA2/hdl/SectorProcessor.vhd SectorProcessor_f2.vhd
	cd hdl; ln -s ../../../CombinedConfig_FPGA2/hdl/memUtil_pkg.vhd memUtil_pkg_f2.vhd

$(input_file_fpga1): $(core_dir)
	@python3 scripts/generate_fpga1_input.py -i mem/MemPrintsSplit/ -o $(input_file_fpga1)

$(input_file_fpga2): $(core_dir)
	@python3 scripts/generate_fpga2_input.py -i mem/MemPrintsSplit/ -o $(input_file_fpga2)

.PHONY: all fpga1 fpga2 add_common_files hdl_add_files_fpga1 hdl_add_files_fpga2 xciCreation_fpga1 xciCreation_fpga2 kfin_adj
