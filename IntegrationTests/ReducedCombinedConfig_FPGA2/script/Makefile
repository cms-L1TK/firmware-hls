# Define base directory of firmware-hls clone.
FIRMWARE=$(shell git rev-parse --show-toplevel)

# MODIFY THESE LINES WHEN COPYING AND PASTING THIS MAKEFILE
TOP_FUNCS=$(FIRMWARE)/TopFunctions/ReducedCombinedConfig
MODULES=ProjectionCalculator_L5L6ABCD MatchProcessor_L1PHIA MatchProcessor_L1PHIB MatchProcessor_L1PHIC MatchProcessor_L1PHID MatchProcessor_L1PHIE MatchProcessor_L1PHIF MatchProcessor_L1PHIG MatchProcessor_L1PHIH MatchProcessor_L2PHIA MatchProcessor_L2PHIB MatchProcessor_L2PHIC MatchProcessor_L2PHID MatchProcessor_L3PHIA MatchProcessor_L3PHIB MatchProcessor_L3PHIC MatchProcessor_L3PHID MatchProcessor_L4PHIA MatchProcessor_L4PHIB MatchProcessor_L4PHIC MatchProcessor_L4PHID TrackBuilder_AAAA VMStubMERouterTop_L1PHIA VMStubMERouterTop_L1PHIB VMStubMERouterTop_L1PHIC VMStubMERouterTop_L1PHID VMStubMERouterTop_L1PHIE VMStubMERouterTop_L1PHIF VMStubMERouterTop_L1PHIG VMStubMERouterTop_L1PHIH VMStubMERouterTop_L2PHIA VMStubMERouterTop_L2PHIB VMStubMERouterTop_L2PHIC VMStubMERouterTop_L2PHID VMStubMERouterTop_L3PHIA VMStubMERouterTop_L3PHIB VMStubMERouterTop_L3PHIC VMStubMERouterTop_L3PHID VMStubMERouterTop_L4PHIA VMStubMERouterTop_L4PHIB VMStubMERouterTop_L4PHIC VMStubMERouterTop_L4PHID

# Include rules for making the project.
include $(FIRMWARE)/IntegrationTests/common/script/Makefile.mk
