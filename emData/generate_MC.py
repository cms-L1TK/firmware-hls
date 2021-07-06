#!/usr/bin/env python

# This script generates MatchCalculator_parameters.h,
# MatchCalculatorTop.h, and MatchCalculatorTop.cc in the
# TrackAlgorithm/ directory. Currently supports all MCs for L3_PHIC.

import sys, re

TF_index = ['L1L2', 'L2L3', 'L3L4', 'L5L6', 'D1D2', 'D3D4', 'L1D1', 'L2D1']
TF_index = {k:v for v,k in enumerate(TF_index)}

if len(sys.argv) < 2:
    print("Usage: " + sys.argv[0] + " WIRES_FILE")
    sys.exit(1)
wiresFileName = sys.argv[1]

# First, parse the wires file and store the memory names associated with MCs in
# dictionaries with the MC names as keys.
wiresFile = open(wiresFileName)
CMMems = {}
FMMems = {}
for line in wiresFile:
    # Only barrel-only seeds are supported right now.
    # Works for MC L3 phi sector C
    if "MC_L3PHIC" not in line:
        continue
    line = line.rstrip()
    tcName = re.sub(r".*MC_(......).*", r"MC_\1", line)
    memName = line.split()[0]
    if memName.startswith("CM_"):
        if tcName not in CMMems:
            CMMems[tcName] = []
        CMMems[tcName].append(memName)
    if memName.startswith("FM_"):
        FM = re.sub(r"FM_(....)_......", r"\1", memName)
        if tcName not in FMMems:
            FMMems[tcName] = []
        FMMems[tcName].append(FM)
wiresFile.close()

# Open and print out preambles for the parameters and top files.
parametersFile = open("MatchCalculator_parameters.h", "w")
parametersFile.write(
    "#ifndef TrackAlgorithm_MatchCalculator_parameters_h\n"
    "#define TrackAlgorithm_MatchCalculator_parameters_h\n"
    "\n"
    "// This file contains numbers of memories and bit masks that are specific to\n"
    "// each MatchCalculator and that come directly from the wiring.\n"
    "//\n"
    "// The validity of each of the barrel CM memories is determined by\n"
    "// FMMask. The bits of this mask, from least significant to most\n"
    "// significant, represent the memories in the order they are passed to\n"
    "// MatchCalculator; e.g., the LSB corresponds to\n"
    "// TF::L1L2. If a bit is set, the corresponding memory is\n"
    "// valid, if it is not, the corresponding memory is not valid.\n"
)
topHeaderFile = open("MatchCalculatorTop.h", "w")
topHeaderFile.write(
    "#ifndef TrackAlgorithm_MatchCalculatorTop_h\n"
    "#define TrackAlgorithm_MatchCalculatorTop_h\n"
    "\n"
    "#include \"MatchCalculator.h\"\n"
)
topFile = open("MatchCalculatorTop.cc", "w")
topFile.write(
    "#include \"MatchCalculatorTop.h\"\n"
    "\n"
    "////////////////////////////////////////////////////////////////////////////////\n"
    "// Top functions for various MatchCalculators (MC). For each iteration of\n"
    "// the main processing loop, a MC retrieves an array of Candidate Matches,\n"
    "// and computes Full Matches from each.\n"
    "////////////////////////////////////////////////////////////////////////////////\n"
)

# Calculate parameters and print out parameters and top function for each MC.
for tcName in sorted(CMMems.keys()):
    seed = re.sub(r"MC_(..)....", r"\1", tcName)
    iMC = re.sub(r"MC_.....(.)", r"\1", tcName)

    # numbers of memories
    nCMMem = len(CMMems[tcName])
    FMMask = 0
    for FM in FMMems[tcName]:
        FMMask = FMMask | (1 << TF_index[FM])

    # Print out parameters for this MC.
    parametersFile.write(
        "\n"
        "// magic numbers for " + tcName + "\n"
        "template<> constexpr uint32_t FMMask<TF::" + seed + ", MC::" + iMC + ">() {\n"
        "  return 0x%X;\n"
        "}\n" % FMMask
    )
    parametersFile.write(
        "template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {\n"
        "  return FMMask<Layer, PHI>() & (1<<Seed);\n"
        "}\n"
    )

    # Print out prototype for top function for this MC.
    topHeaderFile.write(
        "\n"
        "constexpr int maxMatchCopies(" + str(len(TF_index)) + ");\n"
        "constexpr int maxFullMatchCopies(" + str(len(TF_index)) + ");\n"
        "\n"
        "void MatchCalculator_" + seed + iMC + "(\n"
        "    const BXType bx,\n"
        "    const CandidateMatchMemory match[maxMatchCopies],\n"
        "    const AllStubMemory<BARRELPS>* allstub,\n"
        "    const AllProjectionMemory<BARRELPS>* allproj,\n"
        "    BXType& bx_o,\n"
        "    const FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]\n"
        ");\n"
    )

    # Print out definition of top function for this MC.
    topFile.write(
        "\n"
        "void MatchCalculator_" + seed + iMC + "(\n"
        "    const BXType bx,\n"
        "    const CandidateMatchMemory match[maxMatchCopies],\n"
        "    const AllStubMemory<BARRELPS>* allstub,\n"
        "    const AllProjectionMemory<BARRELPS>* allproj,\n"
        "    BXType& bx_o,\n"
        "    const FullMatchMemory<BARREL> fullmatch[maxFullMatchCopies]\n"
        ") {\n"
        "#pragma HLS inline off\n"
        "#pragma HLS interface register port=bx_o\n"
    )
    if nCMMem == 1:
        topFile.write("#pragma HLS resource variable=match.get_mem() latency=2\n")
    else:
        for i in range(nCMMem):
            topFile.write("#pragma HLS resource variable=match[" + str(i) + "].get_mem() latency=2\n")
    topFile.write(
        "#pragma HLS resource variable=allstub->get_mem() latency=2\n"
        "#pragma HLS resource variable=allproj->get_mem() latency=2\n"
        "\n"
        "MC_" + seed + "PHI" + iMC + ": MatchCalculator<"
	#ASTYPE, APTYPE, FMTYPE, MaxMatchCopies, MaxFullMatchCopies
        "MC::ASRegion<" + seed + ">, MC::APRegion<" + seed +">, MC::FMRegion<" + seed + ">, " + str(len(TF_index)) + ", " + str(len(TF_index)) + "\n"
        " TF::" + seed + ", "
        "TF::" + "D1" + ", "
        "MC::" + iMC + "> (\n"
        "    bx,\n"
        "    match,\n"
        "    allstub,\n"
        "    allproj,\n"
        "    bx_o,\n"
        "    fullmatch\n"
        "  );\n"
        "}\n"
    )

# Print out endifs and close files.
parametersFile.write(
    "\n"
    "#endif\n"
)
parametersFile.close()
topHeaderFile.write(
    "\n"
    "#endif\n"
)
topHeaderFile.close()
topFile.write(
    "\n"
    "////////////////////////////////////////////////////////////////////////////////\n"
)
topFile.close()
