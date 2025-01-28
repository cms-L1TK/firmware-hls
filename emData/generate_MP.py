#!/usr/bin/env python3

# This script generates MatchProcessor_parameters.h,
# MatchProcessorTop.h, and MatchProcessorTop.cc in the
# TrackletAlgorithm/ directory. Currently supports all MPs for L3_PHIC.

from __future__ import absolute_import
from __future__ import print_function
import os
import re
import sys
import argparse

TF_index = {}
TF_index['L1L2'] = 0
TF_index['L2L3'] = 0
TF_index['L3L4'] = 1
TF_index['L5L6'] = 0
TF_index['D1D2'] = 1
TF_index['D3D4'] = 1
TF_index['L1D1'] = 1
TF_index['L2D1'] = 0
TF_index['AAAA'] = 0
TF_index['BBBB'] = 1


maxTPMems = "constexpr int maxTPMemories["
maxFMMems = "constexpr int maxFMMemories["

def ASRegion(region):
    if region in ['L1', 'L2', 'L3']:
        return 'BARRELPS'
    elif region in ['L4', 'L5', 'L6']:
        return 'BARREL2S'
    elif region in ['D1', 'D2']:
        return 'DISKPS'
    else:
        return 'DISK2S'

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
parser.add_argument("-sp", "--split", action='store_true', help="Split project so use MPROJ - not TPROJ memories")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with MPs in
# dictionaries with the MP names as keys.
with open(arguments.wiresFileName) as wiresFile:
    TPMems = {}
    FMMems = {}
    for line in wiresFile:
        line = line.rstrip()
        mpName = line.split()[-1].split(".")[0]
        if not mpName.startswith("MP_"):
            mpName = line.split()[-3].split(".")[0]
        memName = line.split()[0]
        projtype = "TPROJ_"
        if arguments.split : projtype = "MPROJ_"
        if memName.startswith(projtype):
            if mpName not in TPMems:
                TPMems[mpName] = []
            TPMems[mpName].append(memName)
        if memName.startswith("FM_"):
            FM = re.sub(r"FM_(....)_......*", r"\1", memName)
            if mpName not in FMMems:
                FMMems[mpName] = []
            FMMems[mpName].append(FM)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessor_parameters.h"), "w") as parametersFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "MatchProcessorTop.cc"), "w") as topFile:

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

    maxTPMems += str(len(TPMems.keys())) + "] = {"
    maxFMMems += str(len(TPMems.keys())) + "] = {"

    # Calculate parameters and print out parameters and top function for each MP.
    for mpName in sorted(TPMems.keys(), key = lambda x: x.startswith('L')):
        seed = mpName[3:5]
        iMP = re.sub(r"MP_.....(.)", r"\1", mpName)

        # numbers of memories
        nTPMem = len(TPMems[mpName])
        nFMMem = len(FMMems[mpName])
        FMMask = 0
        for FM in FMMems[mpName]:
            FMMask = FMMask | (1 << TF_index[FM])

        NPage = 0
        NPageSum = 0
        index = 0
        for TPROJ in TPMems[mpName]:
            npage = len(TPROJ)-17
            if TPROJ.endswith("_E"):
                npage = len(TPROJ)-19
            NPageSum += npage
            NPage = NPage | ((npage-1) << (2*index))
            index+=1
            
        maxTPMems += seed + "PHI" + iMP + "maxTrackletProjections"
        maxFMMems += seed + "PHI" + iMP + "maxFullMatchCopies"
        if mpName != sorted(TPMems.keys(), key=lambda x: x.startswith('L'))[-1]:
            maxTPMems += ",\n				   "
            maxFMMems += ",\n				   " 

        # Print out parameters for this MP.
        parametersFile.write(
            "\n"
            "// magic numbers for " + mpName + "\n"
            "template<> constexpr uint32_t FMMask<TF::" + seed + ", TF::" + iMP + ">() {\n"
            "  return 0x%X;\n"
            "}\n" % FMMask
        )

        parametersFile.write(
            "\n"
            "// magic numbers for " + mpName + "\n"
            "template<> constexpr uint64_t NPage<TF::" + seed + ", TF::" + iMP + ">() {\n"
            "  return 0x%X;\n"
            "}\n" % NPage
        )

        parametersFile.write(
            "\n"
            "// magic numbers for " + mpName + "\n"
            "template<> constexpr uint32_t NPageSum<TF::" + seed + ", TF::" + iMP + ">() {\n"
            "  return 0x%X;\n"
            "}\n" % NPageSum
        )

        TProjRegion, VMProjRegion, VMStubRegion = getTProjAndVMRegions(seed)
        nrz = 'kNbitsrzbinMPBarrel' if 'BARREL' in VMStubRegion else 'kNbitsrzbinMPDisk'
        nphi = 'kNbitsphibinMPBarrel' if 'BARREL' in VMStubRegion else 'kNbitsphibinMPDisk'
        # Print out prototype for top function for this MP.
        topHeaderFile.write(
            "\n"
            "constexpr int " + seed + "PHI" + iMP + "maxTrackletProjections(" + str(nTPMem) + ");\n"
            "constexpr int " + seed + "PHI" + iMP + "maxFullMatchCopies(" + str(nFMMem) + ");\n"
            "\n"
            "void MatchProcessor_" + seed + "PHI" + iMP + "(\n"
            "    const BXType bx,\n"
            "    const TrackletProjectionMemory<" + TProjRegion + "> projin[" + seed + "PHI" + iMP + "maxTrackletProjections],\n"
            "    const VMStubMemory<" + VMStubMERegion(seed) + ", " + nrz + ", kNbitsphibin, kNMatchEngines>& instubdata,\n"
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
            "    const VMStubMemory<" + VMStubMERegion(seed) + ", " + nrz + ", kNbitsphibin, kNMatchEngines>& instubdata,\n"
            "    const AllStubMemory<" + ASRegion(seed) + ">* allstub,\n"
            "    BXType& bx_o,\n"
            "    FullMatchMemory<" + FMRegion(seed) + "> fullmatch[" + seed + "PHI" + iMP + "maxFullMatchCopies]\n"
            ") {\n"
            "#pragma HLS inline off\n"
            "#pragma HLS interface register port=bx_o\n"
        )
        if nTPMem == 0:
            topFile.write("#pragma HLS resource variable=projin.get_mem() latency=2\n")
        else:
            for i in range(nTPMem):
                topFile.write("#pragma HLS resource variable=projin[" + str(i) + "].get_mem() latency=2\n")
        if nFMMem == 0:
            topFile.write("#pragma HLS resource variable=fullmatch.get_mem() latency=2\n")
        else:
            for i in range(nFMMem):
                topFile.write("#pragma HLS resource variable=fullmatch[" + str(i) + "].get_mem() latency=2\n")
        topFile.write(
            "#pragma HLS resource variable=allstub->get_mem() latency=2\n"
            "#pragma HLS resource variable=instubdata.get_mem() latency=2\n"
#            "#pragma HLS resource variable=instubdata.get_mem_entries8A() latency=1\n"
#            "#pragma HLS resource variable=instubdata.get_mem_entries8B() latency=1\n"
           "\n"
            "MP_" + seed + "PHI" + iMP + ": MatchProcessor<"
            "" + TProjRegion + ", " + VMStubRegion + ", " + nrz + ", " + VMProjRegion + ", "  + ASRegion(seed) + ", " + FMRegion(seed) + ", " + seed + "PHI" + iMP + "maxTrackletProjections" + ", " + seed + "PHI" + iMP + "maxFullMatchCopies" + ",\n"
            " TF::" + seed + ", "
            "TF::" + iMP + "> (\n"
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
        "template<TF::layerDisk Layer, TF::phiRegion PHI, TF::seed Seed> constexpr bool FMMask() {\n"
        "  return FMMask<Layer, PHI>() & (1<<Seed);\n"
        "}\n\n"
        "template<TF::layerDisk Layer, TF::phiRegion PHI, TF::seed Seed>\n"
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
        "\n" + maxTPMems + "};\n"
        "\n" + maxFMMems + "};\n"
        "\n"
        "\n#endif\n"
    )
    topFile.write(
        "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
    )
