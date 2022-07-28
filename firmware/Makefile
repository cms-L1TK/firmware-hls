core_file = cfg/include_cores.tcl
core_dir = cgn
input_file = mem/in.txt
proj_path = ../../../../proj
hls_script_path = ../IntegrationTests/ReducedConfig/IRtoTB/script

all: $(core_file) hdl_add_files $(input_file)

$(core_dir):
	@mkdir cgn mem
	cd $(hls_script_path); vivado_hls -f compileHLSforEMP.tcl;

$(core_file): $(core_dir)
	@python3 scripts/include_cores.py

hdl_add_files: $(core_file)
	cd hdl; ln -s ../$(hls_script_path)/../hdl/*.vhd .

$(input_file): $(core_dir)
	@python3 scripts/convert_emData2EMP_Link.py -d mem/MemPrintsReduced/InputStubs -o $(input_file)

sim: $(input_file) $(core_file) $(core_dir)
	@ln -s $(proj_path)/vsim/vsim/vsim.sim/sim_1/behav/xsim/out.txt mem/out.txt
	@$(eval CORE_DIRS= $(wildcard $(core_dir)/*))
	@$(foreach core_dir,$(CORE_DIRS),ln -s ../../../../firmware/$(core_dir) $(hls_script_path);)
	@$(eval CORE_DIRS= $(wildcard $(core_dir)/*))
	@cd $(hls_script_path); vivado -mode batch -source makeProject.tcl
	@cd $(hls_script_path); vivado -mode batch -source runSim.tcl
	python3 scripts/fwtosim_comparison.py -e mem/out.txt -s $(hls_script_path)/dataOut/TF_L1L2.txt

.PHONY: sim all hdl_add_files
