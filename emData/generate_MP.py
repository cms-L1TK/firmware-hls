#!/usr/bin/env python

# This script generates MatchProcessor_parameters.h,
# MatchProcessorTop.h, and MatchProcessorTop.cc in the
# TrackletAlgorithm/ directory. Currently supports all MPs for L3_PHIC.

from __future__ import absolute_import
from __future__ import print_function
import os
import re
import sys
import argparse

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


def VMStubMERegion(region):
    if region in ['L1', 'L2', 'L3']:
        return 'BARRELPS'
    elif region in ['L4', 'L5', 'L6']:
        return 'BARREL2S'
    else:
        return 'DISK'

def getTProjAndVMRegions(module):
    if any(psword in module for psword in ["L1","L2","L3"]): TProjRegion = "BARRELPS"
    elif any(psword in module for psword in ["L4","L5","L6"]): TProjRegion = "BARREL2S"
    else: TProjRegion = "DISK"

    if any(psword in module for psword in ["L1","L2","L3","L4","L5","L6"]): VMProjRegion = "BARREL"
    else: VMProjRegion = "DISK"

    if any(psword in module for psword in ["L1","L2","L3"]): VMStubRegion = "BARRELPS"
    elif any(psword in module for psword in ["L4","L5","L6"]): VMStubRegion = "BARREL2S"
    else: VMStubRegion = "DISK"

    return TProjRegion, VMProjRegion, VMStubRegion

def FMRegion(region):
    if region in ['L1', 'L2', 'L3', 'L4', 'L5', 'L6']:
        return 'BARREL'
    else:
        return 'DISK'

parser = argparse.ArgumentParser(description="This script generates MatchCalculatorTop.h, MatchCalculatorTop.cc, and\
MatchCalculator_parameters.h in the TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with MPs in
# dictionaries with the MP names as keys.
with open(arguments.wiresFileName) as wiresFile:
    TPMems = {}
    FMMems = {}
    for line in wiresFile:
        # Only barrel-only seeds are supported right now.
        if "MP_D" in line:
            continue # No disks for now
        line = line.rstrip()
        mpName = re.sub(r".*MP_(......).*", r"MP_\1", line)
        memName = line.split()[0]
        if memName.startswith("TPROJ_"):
            if mpName not in TPMems:
                TPMems[mpName] = []
            TPMems[mpName].append(memName)
        if memName.startswith("FM_"):
            FM = re.sub(r"FM_(....)_......", r"\1", memName)
            if mpName not in FMMems:
                FMMems[mpName] = []
            FMMems[mpName].append(FM)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessor_parameters.h"), "w") as parametersFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "MatchEngineUint_parameters.h"), "w") as meuParametersFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessorTop.cc"), "w") as topFile:
    meuParametersFile.write(
        "#ifndef TrackAlgorithm_MatchEngineUnit_parameters_h\n"
        "#define TrackAlgorithm_MatchEngineUnit_parameters_h\n"
        "\n"
        "// This file contains numbers of memories and bit masks that are specific to\n"
        "// each MEU and that come directly from the wiring.\n"
        "//\n"
        "\n"
        "template<int kNBitsBuffer>\n"
        "static const ap_uint<(1 << (2 * kNBitsBuffer))> nearFullUnit() {\n"
        "  ap_uint<(1 << (2 * kNBitsBuffer))> lut;\n"
        "  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {\n"
        "#pragma HLS unroll\n"
        "    ap_uint<kNBitsBuffer> wptr, rptr;\n"
        "    ap_uint<2 * kNBitsBuffer> address(i);\n"
        "    (rptr,wptr) = address;\n"
        "    auto wptr1 = wptr+1;\n"
        "    auto wptr2 = wptr+2;\n"
        "    bool result = wptr1==rptr || wptr2==rptr;\n"
        "    lut[i] = result;\n"
        "  }\n"
        "  return lut;\n"
        "}\n"
        "\n"
        "template<int kNBitsBuffer>\n"
        "static const ap_uint<(1 << (2 * kNBitsBuffer))> nearFull3Unit() {\n"
        "  ap_uint<(1 << (2 * kNBitsBuffer))> lut;\n"
        "  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {\n"
        "#pragma HLS unroll\n"
        "    ap_uint<kNBitsBuffer> wptr, rptr;\n"
        "    ap_uint<2 * kNBitsBuffer> address(i);\n"
        "    (rptr,wptr) = address;\n"
        "    ap_uint<kNBitsBuffer> wptr1 = wptr+1;\n"
        "    ap_uint<kNBitsBuffer> wptr2 = wptr+2;\n"
        "    ap_uint<kNBitsBuffer> wptr3 = wptr+3;\n"
        "    bool result = wptr1==rptr || wptr2==rptr || wptr3==rptr;\n"
        "    lut[i] = result;\n"
        "  }\n"
        "  return lut;\n"
        "}\n"
        "\n"
        "template<int kNBitsBuffer>\n"
        "static const ap_uint<(1 << (2 * kNBitsBuffer))> emptyUnit() {\n"
        "  ap_uint<(1 << (2 * kNBitsBuffer))> lut;\n"
        "  for(int i = 0; i < (1 << (2 * kNBitsBuffer)); ++i) {\n"
        "#pragma HLS unroll\n"
        "    ap_uint<kNBitsBuffer> wptr, rptr;\n"
        "    ap_uint<2 * kNBitsBuffer> address(i);\n"
        "    (rptr,wptr) = address;\n"
        "    bool result = wptr==rptr;\n"
        "    lut[i] = result;\n"
    )

    parametersFile.write(
        "#ifndef TrackletAlgorithm_MatchProcessor_parameters_h\n"
        "#define TrackletAlgorithm_MatchProcessor_parameters_h\n"
        "\n"
        "// This file contains numbers of memories and bit masks that are specific to\n"
        "// each MatchProcessor and that come directly from the wiring.\n"
        "//\n"
        "// The validity of each of the barrel Tracklet Parameter memories is determined by\n"
        "// FMMask. The bits of this mask, from least significant to most\n"
        "// significant, represent the memories in the order they are passed to\n"
        "// MatchProcessor; e.g., the LSB corresponds to\n"
        "// TF::L1L2. If a bit is set, the corresponding memory is\n"
        "// valid, if it is not, the corresponding memory is not valid.\n"
    )
    topHeaderFile.write(
        "#ifndef TrackletAlgorithm_MatchProcessorTop_h\n"
        "#define TrackletAlgorithm_MatchProcessorTop_h\n"
        "\n"
        "#include \"MatchProcessor.h\"\n"
        "\n"
    )
    topFile.write(
        "#include \"MatchProcessorTop.h\"\n"
        "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "// Top functions for various MatchProcessors (MP). For each iteration of\n"
        "// the main processing loop, a MP retrieves an array of Traklet Projections,\n"
        "// and computes Full Matches from each.\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
    )

    # Calculate parameters and print out parameters and top function for each MP.
    for mpName in sorted(TPMems.keys()):
        seed = re.sub(r"MP_(..)....", r"\1", mpName)
        iMP = re.sub(r"MP_.....(.)", r"\1", mpName)

        # numbers of memories
        nTPMem = len(TPMems[mpName])
        nFMMem = len(FMMems[mpName])
        FMMask = 0
        for FM in FMMems[mpName]:
            FMMask = FMMask | (1 << TF_index[FM])

        # Print out parameters for this MP.
        parametersFile.write(
            "\n"
            "// magic numbers for " + mpName + "\n"
            "template<> constexpr uint32_t FMMask<TF::" + seed + ", MC::" + iMP + ">() {\n"
            "  return 0x%X;\n"
            "}\n" % FMMask
        )

        TProjRegion, VMProjRegion, VMStubRegion = getTProjAndVMRegions(seed)
        # Print out prototype for top function for this MP.
        topHeaderFile.write(
            "\n"
            "constexpr int " + seed + "PHI" + iMP + "maxTrackletProjections(" + str(nTPMem) + ");\n"
            "constexpr int " + seed + "PHI" + iMP + "maxFullMatchCopies(" + str(nFMMem) + ");\n"
            "\n"
            "void MatchProcessor_" + seed + "PHI" + iMP + "(\n"
            "    const BXType bx,\n"
            "    const TrackletProjectionMemory<" + TProjRegion + "> projin[" + seed + "PHI" + iMP + "maxTrackletProjections],\n"
            "    const VMStubMEMemoryCM<" + VMStubMERegion(seed) + ", 3, 3, kNMatchEngines>& instubdata,\n"
            "    const AllStubMemory<" + ASRegion(seed) + ">* allstub,\n"
            "    BXType& bx_o,\n"
            "    FullMatchMemory<" + FMRegion(seed) + "> fullmatch[" + seed + "PHI" + iMP + "maxFullMatchCopies]\n"
            ");\n"
        )

        # Print out definition of top function for this MP.
        topFile.write(
            "\n"
            "void MatchProcessor_" + seed + "PHI" + iMP + "(\n"
            "    const BXType bx,\n"
            "    const TrackletProjectionMemory<" + TProjRegion + "> projin[" + seed + "PHI" + iMP + "maxTrackletProjections],\n"
            "    const VMStubMEMemoryCM<" + VMStubMERegion(seed) + ", 3, 3, kNMatchEngines>& instubdata,\n"
            "    const AllStubMemory<" + ASRegion(seed) + ">* allstub,\n"
            "    BXType& bx_o,\n"
            "    FullMatchMemory<" + FMRegion(seed) + "> fullmatch[" + seed + "PHI" + iMP + "maxFullMatchCopies]\n"
            ") {\n"
            "#pragma HLS inline off\n"
            "#pragma HLS interface register port=bx_o\n"
        )
        if nTPMem == 1:
            topFile.write("#pragma HLS resource variable=match.get_mem() latency=2\n")
        else:
            for i in range(nTPMem):
                topFile.write("#pragma HLS resource variable=match[" + str(i) + "].get_mem() latency=2\n")
        if nFMMem == 1:
            topFile.write("#pragma HLS resource variable=fullmatch.get_mem() latency=2\n")
        else:
            for i in range(nFMMem):
                topFile.write("#pragma HLS resource variable=fullmatch[" + str(i) + "].get_mem() latency=2\n")
        topFile.write(
            "#pragma HLS resource variable=allstub->get_mem() latency=2\n"
            "#pragma HLS resource variable=instubdata.get_mem() latency=2\n"
            "\n"
            "MP_" + seed + "PHI" + iMP + ": MatchProcessor<"
            "" + TProjRegion + ", " + VMStubRegion + ", " + VMProjRegion + ", "  + ASRegion(seed) + ", " + APRegion(seed) + ", " + FMRegion(seed) + ", " + seed + "PHI" + iMP + "maxTrackletProjections" + ", " + seed + "PHI" + iMP + "maxFullMatchCopies" + ",\n"
            " TF::" + seed + ", "
            "TF::" + "D1" + ", "
            "MC::" + iMP + "> (\n"
            "    bx,\n"
            "    projin,\n"
            "    instubdata,\n"
            "    allstub,\n"
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
