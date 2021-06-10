#!/bin/sh

# Create HLS IP for IR & VMR.
# Run this in IntegrationTests/xyz/script/ 

pushd ../../../project

vivado_hls -f script_IR.tcl
vivado_hls -f script_VMR.tcl

popd
