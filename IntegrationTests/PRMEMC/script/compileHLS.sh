#!/bin/sh

# Create HLS IP for PR, ME & MC.
# Run this in IntegrationTests/xyz/script/ 

pushd ../../../project

vivado_hls -f script_PR.tcl
vivado_hls -f script_ME.tcl
vivado_hls -f script_MC.tcl

popd
