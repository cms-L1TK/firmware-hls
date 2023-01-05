# Define base directory of firmware-hls clone.
FIRMWARE=$(shell git rev-parse --show-toplevel)

# MODIFY THESE LINES WHEN COPYING AND PASTING THIS MAKEFILE
TOP_FUNCS=$(FIRMWARE)/TopFunctions
MODULES=MatchCalculator_L3PHIC MatchEngineTop_L3 ProjectionRouterTop_L3PHIC

# Include rules for making the project.
include $(FIRMWARE)/IntegrationTests/common/script/Makefile.mk
