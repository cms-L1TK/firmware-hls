#!/bin/sh

# Create HLS IP for TE & TC.
# Run this in IntegrationTests/xyz/script/ 

pushd ../../../project

vivado_hls -f script_TE.tcl
vivado_hls -f script_TC.tcl

popd
