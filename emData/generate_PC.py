#!/usr/bin/env python3

# This script generates
# ProjectionCalculatorTop.h, and ProjectionCalculatorTop.cc in the
# TopFunctions/ directory. Currently supports all TPs
#

from __future__ import absolute_import, print_function
import os
import argparse

# These enums must match those defined in
# TopFunctions/TrackletProcessor.h.
ProjoutIndexBarrel = {
   "L1PHIA":0,
   "L1PHIB":1,
   "L1PHIC":2,
   "L1PHID":3,
   "L1PHIE":4,
   "L1PHIF":5,
   "L1PHIG":6,
   "L1PHIH":7,
   "L2PHIA":8,
   "L2PHIB":9,
   "L2PHIC":10,
   "L2PHID":11,
   "L3PHIA":12,
   "L3PHIB":13,
   "L3PHIC":14,
   "L3PHID":15,
   "L4PHIA":16,
   "L4PHIB":17,
   "L4PHIC":18,
   "L4PHID":19,
   "L5PHIA":20,
   "L5PHIB":21,
   "L5PHIC":22,
   "L5PHID":23,
   "L6PHIA":24,
   "L6PHIB":25,
   "L6PHIC":26,
   "L6PHID":27
}


ProjoutIndexDisk = {
   "D1PHIA":0,
   "D1PHIB":1,
   "D1PHIC":2,
   "D1PHID":3,
   "D2PHIA":4,
   "D2PHIB":5,
   "D2PHIC":6,
   "D2PHID":7,
   "D3PHIA":8,
   "D3PHIB":9,
   "D3PHIC":10,
   "D3PHID":11,
   "D4PHIA":12,
   "D4PHIB":13,
   "D4PHIC":14,
   "D4PHID":15,
   "D5PHIA":16,
   "D5PHIB":17,
   "D5PHIC":18,
   "D5PHID":19
}

parser = argparse.ArgumentParser(description="This script generates ProjectionCalculatorTop.h, ProjectionCalculatorTop.cc \
   in the TopFunctions/ directory.",
  epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/CombinedConfig/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTsCM/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
parser.add_argument("-sp", "--split", action='store_true', help="Split project so use MPROJ - not TPROJ memories")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with PCs in
# dictionaries with the PC names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
    tprojMems = {}
    for line in wiresFile:
        proctype = "PC_"
        if proctype not in line :
            continue
        line = line.rstrip()
        pcName = line.split(proctype)[1].split(".")[0]
        innerLayer = pcName[3:5]
        outerLayer = pcName[5:7]
        memName = line.split()[0]

        projtype = "MPROJ_"
        if memName.startswith(projtype):
            if pcName not in tprojMems:
                tprojMems[pcName] = []
            tprojMems[pcName].append(memName)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))

with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.cc"), "w") as topFile:

    topHeaderFile.write(
        "#ifndef TopFunctions_ProjectionCalculatorTop_h\n"
        "#define TopFunctions_ProjectionCalculatorTop_h\n"
        "\n"
        "\n"
        "#include \"ProjectionCalculator.h\"\n"
    )

    topFile.write(
        "#include \"ProjectionCalculatorTop.h\"\n"
        "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "// Top functions for various ProjectionCalculators (PC). For each track parameter\n"
        "// the projections to additional layers and disks are also calculated and are\n"
        "// written to the appropriate tracklet-projection memories.\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
    )
    # Calculate parameters and print out parameters and top function for each TP.
    for pcName in sorted(tprojMems):
        seed = pcName[0:4]
        iTC = pcName[4:]
        # # numbers of memories
        # nASMemInner = len(asInnerMems[pcName])
        # nASMemOuter = len(asOuterMems[pcName])
        # nVMSTEMem = len(vmsteMems[pcName])
        # # AS inner and outer masks
        # asInnerMask = 0
        # asOuterMask = 0
        # asInnerMems[pcName].sort()
        # asOuterMems[pcName].sort()

        # TPROJ masks for barrel and disks
        tprojMaskBarrel = 0
        tprojMaskDisk = 0
        for projmem in tprojMems[pcName]:
            projlayreg = projmem.split("_")[2]
            if projlayreg in ProjoutIndexBarrel:
                tprojMaskBarrel = tprojMaskBarrel | (1 << ProjoutIndexBarrel[projlayreg])
            if projlayreg in ProjoutIndexDisk:
                tprojMaskDisk = tprojMaskDisk | (1 << ProjoutIndexDisk[projlayreg])

        # Print out prototype for top function for this PC.
        topHeaderFile.write(
          "\n"
          "void ProjectionCalculator_" + seed + iTC + "(\n"
          "    const BXType bx,\n"
          "    BXType& bx_o,\n"
          "    TrackletParameters tPar,\n"
          "    ap_uint<9> trackletIndex,\n"
          "    bool valid,\n"
          "    TrackletParameterMemory& tparout,\n"
          "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],\n"
          "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],\n"
          "    TrackletProjectionMemory<DISK> projout_disk[]\n"
          ");\n"
        )

        # Print top function definition for this PC.
        topFile.write(
          "\n"
          "void ProjectionCalculator_" + seed + iTC + "(\n"
          "    const BXType bx,\n"
          "    BXType& bx_o,\n"
          "    TrackletParameters tPar,\n"
          "    ap_uint<9> trackletIndex,\n"
          "    bool valid,\n"
          "    TrackletParameterMemory& tparout,\n"
          "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TP::N_PROJOUT_BARRELPS],\n"
          "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TP::N_PROJOUT_BARREL2S],\n"
          "    TrackletProjectionMemory<DISK> projout_disk[TP::N_PROJOUT_DISK]\n"
          ") {\n"
          "#pragma HLS latency min=13 max=13\n"
          "#pragma HLS pipeline II=1\n"
          "#pragma HLS inline recursive\n"
          "#pragma HLS array_partition variable=projout_barrel_ps dim=1\n"
          "#pragma HLS array_partition variable=projout_barrel_2s dim=1\n"
          "#pragma HLS array_partition variable=projout_disk dim=1\n"
          "\n"
          "PC_" + seed + iTC + ": ProjectionCalculator<\n"
          "  TF::" + seed + ",\n"
          "  TP::" + iTC[0] + ",\n"
          "  0x%x, \n  0x%x" %(tprojMaskBarrel, tprojMaskDisk) +\
          " >(\n"
          "    bx,\n"
          "    bx_o,\n"
          "    tPar,\n"
          "    trackletIndex,\n"
          "    valid,\n"
          "    tparout,\n"
          "    projout_barrel_ps,\n"
          "    projout_barrel_2s,\n"
          "    projout_disk\n"
          "  );\n"
          "}\n\n"
        )

    # Print out endif
    topHeaderFile.write(
      "\n"
      "#endif\n"
    )
    topFile.write(
      "\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
    )
