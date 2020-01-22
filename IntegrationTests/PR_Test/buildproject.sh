# Simulate, synthesize, and export current version of ProjectionRouter
cd ../../project
vivado_hls -f script_PR.tcl

# Download needed data files to populate initial memories and compare final memories
cd ../IntegrationTests/PR_Test/emData
. download.sh

# Open the Vivado GUI and initialize the project
cd ../
vivado -source generate_project.tcl
