core_file = cfg/include_cores.tcl
core_dir = cgn
input_file = mem/in.txt
core_append = /impl/ip/component.xml
core_path = ../../../src/firmware-hls/firmware
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

.PHONY: hdl_add_files
