# Define base directory of firmware-hls clone.
FIRMWARE=$(shell git rev-parse --show-toplevel)

# MODIFY THESE LINES WHEN COPYING AND PASTING THIS MAKEFILE
TOP_FUNCS=$(FIRMWARE)/TopFunctions
MODULES=InputRouterTop_IR_DTC_PS10G_3_A VMRouterTop_L2PHIA

# Include rules for making the project.
include $(FIRMWARE)/IntegrationTests/common/script/Makefile.mk
