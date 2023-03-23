# Copy LUTs to xsim or synth_1 directory
file delete -force ./LUTs
file copy -force ../../src/firmware-hls/emData/LUTsReduced ./LUTs
