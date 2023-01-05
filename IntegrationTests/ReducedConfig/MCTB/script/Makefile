# Define base directory of firmware-hls clone.
FIRMWARE=$(shell git rev-parse --show-toplevel)

# MODIFY THESE LINES WHEN COPYING AND PASTING THIS MAKEFILE
TOP_FUNCS=$(FIRMWARE)/TopFunctions/ReducedConfig
MODULES=MatchCalculator_L3PHIB MatchCalculator_L4PHIB MatchCalculator_L5PHIB MatchCalculator_L6PHIB TrackBuilder_L1L2

# Include rules for making the project.
include $(FIRMWARE)/IntegrationTests/common/script/Makefile.mk
