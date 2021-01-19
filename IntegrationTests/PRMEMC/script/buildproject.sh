#!/bin/sh
PROJECT="PRMEMC"

# Simulate, synthesize, and export current version of PR, ME, MC
cd ../../../project
vivado_hls -f script_PR.tcl
vivado_hls -f script_ME.tcl
vivado_hls -f script_MC.tcl

# Download needed data files to populate initial memories and compare final memories
cd ../emData
./download.sh

# Open the Vivado GUI and initialize the project
cd ../IntegrationTests/$PROJECT
vivado -mode tcl -source script/generate_project.tcl -tclargs $PROJECT
vivado -mode tcl -source ../common/script/synth.tcl -tclargs $PROJECT
