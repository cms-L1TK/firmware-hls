# Define base directory of firmware-hls clone.
FIRMWARE=$(shell git rev-parse --show-toplevel)

# MODIFY THESE LINES WHEN COPYING AND PASTING THIS MAKEFILE
TOP_FUNCS=$(FIRMWARE)/TopFunctions
MODULES=TrackletEngine_PS_PS TrackletCalculator_L1L2E

# Include rules for making the project.
include $(FIRMWARE)/IntegrationTests/common/script/Makefile.mk
