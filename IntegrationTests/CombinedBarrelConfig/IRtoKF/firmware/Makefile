core_file = scripts/xciMaker
core_dir = cgn
input_file = mem/in.txt
proj_path = ../../../../proj
hls_script_path = ../../script

all: add_common_files $(core_file) hdl_add_files xciCreation kfin_adj $(input_file) apollo_input lut_inclusion

$(core_dir):
	@mkdir cgn mem
	make -C $(hls_script_path) -j 8 Work
	ln -s ../../../../../emData/LUTsCMBarrel mem/LUTs
	ln -s ../../../../../emData/MemPrintsCMBarrel mem/MemPrintsCMBarrel
	ln -s ../../../../common hdl/common

$(core_file): $(core_dir)
	@python3 scripts/include_cores.py -s $(hls_script_path)

kfin_adj:
	@cd ../../../../KalmanFilter; git checkout 008f942
	@python3 scripts/kf_link_mod.py

xciCreation: $(core_file)
	make -f $(core_file) -j 8 all

add_common_files:
	@cd cfg; ln -s ../../../../common/cfg/*.dep .
	@cd ucf; ln -s ../../../../common/ucf/*.tcl .
	@cd scripts; ln -s ../../../../common/script/emp/*.py .
	@cd scripts; ln -s ../../../../common/script/emp/*.tcl .

hdl_add_files: $(core_file)
	cd hdl; ln -s ../../../hdl/*.vhd .

lut_inclusion:
	@python3 scripts/lut_copy.py

$(input_file): $(core_dir)
	@python3 scripts/convert_emData2EMP_Link.py -d mem/MemPrintsCMBarrel/InputStubs -o $(input_file)

apollo_input: $(input_file)
	@python3 scripts/split_emp_input.py

sim: $(input_file) $(core_file) $(core_dir)
	@ln -s $(proj_path)/vsim/vsim/vsim.sim/sim_1/behav/xsim/out.txt mem/out.txt
	@$(eval CORE_DIRS= $(wildcard $(core_dir)/*))
	@$(foreach core_dir,$(CORE_DIRS),ln -s ../../../../firmware/$(core_dir) $(hls_script_path);)
	@ln -s ../../../common $(hls_script_path)
	@ln -s ../../../../emData/MemPrintsCMBarrel $(hls_script_path)/MemPrints
	@ln -s ../../../../emData/LUTsCMBarrel $(hls_script_path)/LUTs
	@$(eval CORE_DIRS= $(wildcard $(core_dir)/*))
	@cd $(hls_script_path); vivado -mode batch -source makeProject.tcl
	@cd $(hls_script_path); vivado -mode batch -source runSim.tcl
	@python3 scripts/fwtosim_comparison.py -e mem/out.txt -s $(hls_script_path)/dataOut/TF_L1L2.txt

.PHONY: sim all hdl_add_files xciCreation kfin_adj apollo_input lut_inclusion core_patch
