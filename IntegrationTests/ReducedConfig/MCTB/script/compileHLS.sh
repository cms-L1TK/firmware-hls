#!/bin/sh

# Create HLS IP for MC & TB.
# Run this in IntegrationTests/xyz/script/ 

pushd ../../../project

vivado_hls -f script_MC.tcl
vivado_hls -f script_TB.tcl

popd
