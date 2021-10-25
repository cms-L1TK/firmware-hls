#!/usr/bin/env python3

# This script generates MatchCalculator_parameters.h,
# MatchCalculatorTop.h, and MatchCalculatorTop.cc in the
# TrackletAlgorithm/ directory. Currently supports all MCs for L3_PHIC.

from __future__ import absolute_import
from __future__ import print_function
import os
import re
import sys

TF_index = ['L1L2', 'L2L3', 'L3L4', 'L5L6', 'D1D2', 'D3D4', 'L1D1', 'L2D1']
TF_index = {k:v for v,k in enumerate(TF_index)}

def ASRegion(region):
    if region in ['L1', 'L2', 'L3']:
        return 'BARRELPS'
    elif region in ['L4', 'L5', 'L6']:
        return 'BARREL2S'
    else:
        return 'DISK'

def APRegion(region):
    if region in ['L1', 'L2', 'L3']:
        return 'BARRELPS'
    elif region in ['L4', 'L5', 'L6']:
        return 'BARREL2S'
    else:
        return 'DISK'

def FMRegion(region):
    if region in ['L1', 'L2', 'L3', 'L4', 'L5', 'L6']:
        return 'BARREL'
    else:
        return 'DISK'

if len(sys.argv) < 2:
    print("Usage: " + sys.argv[0] + " WIRES_FILE")
    sys.exit(1)
wiresFileName = sys.argv[1]

# First, parse the wires file and store the memory names associated with MCs in
# dictionaries with the MC names as keys.
with open(wiresFileName) as wiresFile:
    CMMems = {}
    FMMems = {}
    for line in wiresFile:
        # Only barrel-only seeds are supported right now.
        if "MC_D" in line:
            continue # No disks for now
        line = line.rstrip()
        mcName = re.sub(r".*MC_(......).*", r"MC_\1", line)
        memName = line.split()[0]
        if memName.startswith("CM_"):
            if mcName not in CMMems:
                CMMems[mcName] = []
            CMMems[mcName].append(memName)
        if memName.startswith("FM_"):
            FM = re.sub(r"FM_(....)_......", r"\1", memName)
            if mcName not in FMMems:
                FMMems[mcName] = []
            FMMems[mcName].append(FM)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, "../TrackletAlgorithm/MatchCalculator_parameters.h"), "w") as parametersFile, \
     open(os.path.join(dirname, "../TrackletAlgorithm/MatchCalculatorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, "../TrackletAlgorithm/MatchCalculatorTop.cc"), "w") as topFile:
    parametersFile.write(
        "#ifndef TrackletAlgorithm_MatchCalculator_parameters_h\n"
        "#define TrackletAlgorithm_MatchCalculator_parameters_h\n"
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
    topHeaderFile.write(
        "#ifndef TrackletAlgorithm_MatchCalculatorTop_h\n"
        "#define TrackletAlgorithm_MatchCalculatorTop_h\n"
        "\n"
        "#include \"MatchCalculator.h\"\n"
        "\n"
    )
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
    for mcName in sorted(CMMems.keys()):
        seed = re.sub(r"MC_(..)....", r"\1", mcName)
        iMC = re.sub(r"MC_.....(.)", r"\1", mcName)

        # numbers of memories
        nCMMem = len(CMMems[mcName])
        nFMMem = len(FMMems[mcName])
        FMMask = 0
        for FM in FMMems[mcName]:
            FMMask = FMMask | (1 << TF_index[FM])

        # Print out parameters for this MC.
        parametersFile.write(
            "\n"
            "// magic numbers for " + mcName + "\n"
            "template<> constexpr uint32_t FMMask<TF::" + seed + ", MC::" + iMC + ">() {\n"
            "  return 0x%X;\n"
            "}\n" % FMMask
        )

        # Print out prototype for top function for this MC.
        topHeaderFile.write(
            "\n"
            "constexpr int " + seed + "PHI" + iMC + "maxMatchCopies(" + str(nCMMem) + ");\n"
            "constexpr int " + seed + "PHI" + iMC + "maxFullMatchCopies(" + str(nFMMem) + ");\n"
            "\n"
            "void MatchCalculator_" + seed + "PHI" + iMC + "(\n"
            "    const BXType bx,\n"
            "    const CandidateMatchMemory match[" + seed + "PHI" + iMC + "maxMatchCopies],\n"
            "    const AllStubMemory<" + ASRegion(seed) + ">* allstub,\n"
            "    const AllProjectionMemory<" + APRegion(seed) + ">* allproj,\n"
            "    BXType& bx_o,\n"
            "    FullMatchMemory<" + FMRegion(seed) + "> fullmatch[" + seed + "PHI" + iMC + "maxFullMatchCopies]\n"
            ");\n"
        )

        # Print out definition of top function for this MC.
        topFile.write(
            "\n"
            "void MatchCalculator_" + seed + "PHI" + iMC + "(\n"
            "    const BXType bx,\n"
            "    const CandidateMatchMemory match[" + seed + "PHI" + iMC + "maxMatchCopies],\n"
            "    const AllStubMemory<" + ASRegion(seed) + ">* allstub,\n"
            "    const AllProjectionMemory<" + APRegion(seed) + ">* allproj,\n"
            "    BXType& bx_o,\n"
            "    FullMatchMemory<" + FMRegion(seed) + "> fullmatch[" + seed + "PHI" + iMC + "maxFullMatchCopies]\n"
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
            "" + ASRegion(seed) + ", " + APRegion(seed) + ", " + FMRegion(seed) + ", " + str(nCMMem) + ", " + str(nFMMem) + ",\n"
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
        "// return mask bit AND mask\n"
        "template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed> constexpr bool FMMask() {\n"
        "  return FMMask<Layer, PHI>() & (1<<Seed);\n"
        "}\n\n"
        "template<TF::layerDisk Layer, MC::imc PHI, TF::seed Seed>\n"
        "static const ap_uint<1 << Seed> FMCount() {\n"
        "  ap_uint<1<<Seed> bits(-1);\n"
        "  ap_uint<1<<Seed> mask = bits & FMMask<Layer, PHI>();\n"
        "  int slot = 0;\n"
        "  for(int i = 0; i < Seed; ++i) {\n"
        "    slot += mask.range(i,i);\n"
        "  }\n"
        "  return slot;\n"
        "}\n\n"
        "#endif\n"
    )
    topHeaderFile.write(
        "\n"
        "#endif\n"
    )
    topFile.write(
        "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
    )
