#!/usr/bin/env python3

# This script generates TrackletCalculator_parameters.h,
# TrackletCalculatorTop.h, and TrackletCalculatorTop.cc in the
# TopFunctions/ directory. Currently supports all TCs for L1L2, as well as
# TC_L3L4A, TC_L3L4D, TC_L5L6A, and TC_L5L6D.

from __future__ import absolute_import, print_function
import os
import re
import argparse
from enum import Enum

# These enums must match those defined in
# TrackletAlgorithm/TrackletCalculator.h.
class ProjoutIndexBarrel(Enum):
    L1PHIA = 0
    L1PHIB = 1
    L1PHIC = 2
    L1PHID = 3
    L1PHIE = 4
    L1PHIF = 5
    L1PHIG = 6
    L1PHIH = 7
    L2PHIA = 8
    L2PHIB = 9
    L2PHIC = 10
    L2PHID = 11
    L3PHIA = 12
    L3PHIB = 13
    L3PHIC = 14
    L3PHID = 15
    L4PHIA = 16
    L4PHIB = 17
    L4PHIC = 18
    L4PHID = 19
    L5PHIA = 20
    L5PHIB = 21
    L5PHIC = 22
    L5PHID = 23
    L6PHIA = 24
    L6PHIB = 25
    L6PHIC = 26
    L6PHID = 27
    N_PROJOUT_BARREL = 28

class ProjoutIndexDisk(Enum):
    D1PHIA = 0
    D1PHIB = 1
    D1PHIC = 2
    D1PHID = 3
    D2PHIA = 4
    D2PHIB = 5
    D2PHIC = 6
    D2PHID = 7
    D3PHIA = 8
    D3PHIB = 9
    D3PHIC = 10
    D3PHID = 11
    D4PHIA = 12
    D4PHIB = 13
    D4PHIC = 14
    D4PHID = 15
    N_PROJOUT_DISK = 16

parser = argparse.ArgumentParser(description="This script generates TrackletCalculatorTop.h, TrackletCalculatorTop.cc, and\
TrackletCalculator_parameters.h in the TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with TCs in
# dictionaries with the TC names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
    asInnerMems = {}
    asOuterMems = {}
    spMems = {}
    tprojMems = {}
    for line in wiresFile:
        # Only barrel-only seeds are supported right now.
        if "TC_L1L2" not in line and "TC_L2L3" not in line \
          and "TC_L3L4" not in line and "TC_L5L6" not in line:
            continue
        line = line.rstrip()
        tcName = re.sub(r".*TC_(.....).*", r"TC_\1", line)
        memName = line.split()[0]
        if ("TC_L2L3" in line and memName.startswith("AS_L2")) or ("TC_L2L3" not in line and \
          (memName.startswith("AS_L1") or memName.startswith("AS_L3") or memName.startswith("AS_L5"))):
            if tcName not in asInnerMems:
                asInnerMems[tcName] = []
            asInnerMems[tcName].append(memName)
        if ("TC_L2L3" in line and memName.startswith("AS_L3")) or ("TC_L2L3" not in line and \
          (memName.startswith("AS_L2") or memName.startswith("AS_L4") or memName.startswith("AS_L6"))):
            if tcName not in asOuterMems:
                asOuterMems[tcName] = []
            asOuterMems[tcName].append(memName)
        if memName.startswith("SP_"):
            if tcName not in spMems:
                spMems[tcName] = []
            spMems[tcName].append(memName)
        if memName.startswith("TPROJ_"):
            if tcName not in tprojMems:
                tprojMems[tcName] = []
            tprojMems[tcName].append(memName)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "TrackletCalculator_parameters.h"), "w") as parametersFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "TrackletCalculatorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "TrackletCalculatorTop.cc"), "w") as topFile:
    parametersFile.write(
        "#ifndef TopFunctions_TrackletCalculator_parameters_h\n"
        "#define TopFunctions_TrackletCalculator_parameters_h\n"
        "#ifndef __SYNTHESIS__\n"
        '#include "SWLUTReader.h"\n'
        "#endif\n"
        "\n"
        "// This file contains numbers of memories and bit masks that are specific to\n"
        "// each TrackletCalculator and that come directly from the wiring.\n"
        "//\n"
        "// The specific inner all-stub memory that the indices in a given stub-pair\n"
        "// memory correspond to is determined by ASInnerMask. The bits of this mask,\n"
        "// from least significant to most significant, represent the stub-pair memories\n"
        "// in the order they are passed to TrackletCalculator; e.g., the LSB\n"
        "// corresponds to stubPairs[0]. The bit for a given stub-pair memory is the\n"
        "// index (0 or 1) of the inner all-stub memory that should be used. Likewise,\n"
        "// the specific outer all-stub memories are determined by ASOuterMask.\n"
        "//\n"
        "// The validity of each of the barrel TPROJ memories is determined by\n"
        "// TPROJMaskBarrel. The bits of this mask, from least significant to most\n"
        "// significant, represent the memories in the order they are passed to\n"
        "// TrackletCalculator; e.g., the LSB corresponds to\n"
        "// projout_barrel_ps[TC::L1PHIA]. If a bit is set, the corresponding memory is\n"
        "// valid, if it is not, the corresponding memory is not valid. Likewise, the\n"
        "// validity of each of the disk TPROJ memories is determined by TPROJMaskDisk\n"
        "// in the same way.\n"
        "template<TF::seed Seed> const ap_int<18>* getDRinvLUT();\n"
        "template<TF::seed Seed> const ap_int<18>* getInvtLUT();\n"
    )
    topHeaderFile.write(
        "#ifndef TopFunctions_TrackletCalculatorTop_h\n"
        "#define TopFunctions_TrackletCalculatorTop_h\n"
        "\n"
        "#include \"TrackletCalculator.h\"\n"
    )
    topFile.write(
        "#include \"TrackletCalculatorTop.h\"\n"
        "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "// Top functions for various TrackletCalculators (TC). For each iteration of\n"
        "// the main processing loop, a TC retrieves a pair of stub indices from one of\n"
        "// the stub-pair memories, and in turn, these indices are used to retrieve one\n"
        "// stub each from an inner and an outer all-stub memory. This pair of stubs is\n"
        "// used to calculate a rough set of helix parameters, which are written to the\n"
        "// tracklet-parameter memory if the tracklet passes cuts on rinv and z0. Rough\n"
        "// projections to additional layers and disks are also calculated and are\n"
        "// written to the appropriate tracklet-projection memories.\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
    )

    # Calculate parameters and print out parameters and top function for each TC.
    for tcName in sorted(asInnerMems.keys()):
        seed = re.sub(r"TC_(....).", r"\1", tcName)
        iTC = re.sub(r"TC_....(.)", r"\1", tcName)

        # numbers of memories
        nASMemInner = len(asInnerMems[tcName])
        nASMemOuter = len(asOuterMems[tcName])
        nSPMem = len(spMems[tcName])
        #print("tcName: " + tcName)
        #print("nSPMem: " + str(nSPMem))
        assert nSPMem <= 32

        # AS inner and outer masks
        asInnerMask = 0
        asOuterMask = 0
        asInnerMems[tcName].sort()
        asOuterMems[tcName].sort()
        for i in range(0, nSPMem):
            innerPart = re.sub(r".*_(..PHI.).*_(..PHI.).*", r"\1", spMems[tcName][i])
            outerPart = re.sub(r".*_(..PHI.).*_(..PHI.).*", r"\2", spMems[tcName][i])
            innerIndex = -1
            outerIndex = -1

            # for L2L3, the letters in the AS names are shifted relative to
            # those in the SP names
            innerPart = re.sub(r"PHII", r"PHIA", innerPart)
            innerPart = re.sub(r"PHIJ", r"PHIB", innerPart)
            innerPart = re.sub(r"PHIK", r"PHIC", innerPart)
            innerPart = re.sub(r"PHIL", r"PHID", innerPart)
            outerPart = re.sub(r"PHII", r"PHIA", outerPart)
            outerPart = re.sub(r"PHIJ", r"PHIB", outerPart)
            outerPart = re.sub(r"PHIK", r"PHIC", outerPart)
            outerPart = re.sub(r"PHIL", r"PHID", outerPart)

            for j in range(0, nASMemInner):
                if innerPart in asInnerMems[tcName][j]:
                    innerIndex = j
                    break
            asInnerMask = asInnerMask | (innerIndex << (2 * i))
            for j in range(0, nASMemOuter):
                if outerPart in asOuterMems[tcName][j]:
                    outerIndex = j
                    break
            asOuterMask = asOuterMask | (outerIndex << (2 * i))

        # TPROJ masks for barrel and disks
        tprojMaskBarrel = 0
        for projout in ProjoutIndexBarrel:
            projoutName = "TPROJ_" + seed + iTC + "_" + projout.name
            projoutIndex = projout.value
            if projoutName in tprojMems[tcName]:
                tprojMaskBarrel = tprojMaskBarrel | (1 << projoutIndex)
        tprojMaskDisk = 0
        for projout in ProjoutIndexDisk:
            projoutName = "TPROJ_" + seed + iTC + "_" + projout.name
            projoutIndex = projout.value
            if projoutName in tprojMems[tcName]:
                tprojMaskDisk = tprojMaskDisk | (1 << projoutIndex)

        # Print out parameters for this TC.
        parametersFile.write(
            ("\n"
            "// magic numbers for " + tcName + "\n"
            "template<> constexpr uint64_t ASInnerMask<TF::" + seed + ", TF::" + iTC + ">() {\n"
            "  return 0x%X;\n"
            "}\n"
            "template<> constexpr uint64_t ASOuterMask<TF::" + seed + ", TF::" + iTC + ">() {\n"
            "  return 0x%X;\n"
            "}\n"
            "template<> constexpr uint32_t TPROJMaskBarrel<TF::" + seed + ", TF::" + iTC + ">() {\n"
            "  return 0x%X;\n"
            "}\n"
            "template<> constexpr uint32_t TPROJMaskDisk<TF::" + seed + ", TF::" + iTC + ">() {\n"
            "  return 0x%X;\n"
            "}\n")
            % (asInnerMask, asOuterMask, tprojMaskBarrel, tprojMaskDisk)
        )
        if iTC == 'A':
            parametersFile.write(
                'template<> inline const ap_int<18>* getDRinvLUT<TF::'+ seed + '>(){\n'
                '#ifndef __SYNTHESIS__\n'
                '  static ap_int<18> lut[512];\n'
                '  static bool init;\n'
                '  if (!init)\n'
                '    init = readSWLUT<ap_int<18>,512>(lut,"LUTs/TC_' + seed + '_drinv.tab",false,true);\n'
                '#else\n'
                '  static ap_int<18> lut[] = {\n'
                '#if __has_include("../emData/LUTs/TC_' + seed +'_drinv.tab")\n'
                '#  include "../emData/LUTs/TC_' + seed + '_drinv.tab"\n'
                '#endif\n'
                '};\n'
                '#endif\n'
                '  return lut;\n'
                '}\n'
                'template<> inline const ap_int<18>* getInvtLUT<TF::'+ seed + '>(){\n'
                '#ifndef __SYNTHESIS__\n'
                '  static ap_int<18> lut[4096];\n'
                '  static bool init;\n'
                '  if (!init)\n'
                '    init = readSWLUT<ap_int<18>,4096>(lut,"LUTs/TC_' + seed + '_invt.tab",false,true);\n'
                '#else\n'
                '  static ap_int<18> lut[] ={\n'
                '#if __has_include("../emData/LUTs/TC_' + seed +'_invt.tab")\n'
                '#  include "../emData/LUTs/TC_' + seed + '_invt.tab"\n'
                '#endif\n'
                '};\n'
                '#endif\n'
                '  return lut;\n'
                '}\n'
        )
        # Print out prototype for top function for this TC.
        topHeaderFile.write(
            "\n"
            "void TrackletCalculator_" + seed + iTC + "(\n"
            "    const BXType bx,\n"
            "    const AllStubMemory<InnerRegion<TF::" + seed + ">()> innerStubs[],\n"
            "    const AllStubMemory<OuterRegion<TF::" + seed + ">()> outerStubs[],\n"
            "    const StubPairMemory stubPairs[],\n"
            "    BXType& bx_o,\n"
            "    TrackletParameterMemory * trackletParameters,\n"
            "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],\n"
            "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],\n"
            "    TrackletProjectionMemory<DISK> projout_disk[]\n"
            ");\n"
        )

        # Print out definition of top function for this TC.
        topFile.write(
            "\n"
            "void TrackletCalculator_" + seed + iTC + "(\n"
            "    const BXType bx,\n"
            "    const AllStubMemory<InnerRegion<TF::" + seed + ">()> innerStubs[" + str(nASMemInner) + "],\n"
            "    const AllStubMemory<OuterRegion<TF::" + seed + ">()> outerStubs[" + str(nASMemOuter) + "],\n"
            "    const StubPairMemory stubPairs[" + str(nSPMem) + "],\n"
            "    BXType& bx_o,\n"
            "    TrackletParameterMemory * trackletParameters,\n"
            "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],\n"
            "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],\n"
            "    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]\n"
            ") {\n"
            "#pragma HLS inline recursive\n"
            "#pragma HLS array_partition variable=innerStubs complete dim=1\n"
            "#pragma HLS array_partition variable=outerStubs complete dim=1\n"
            "#pragma HLS array_partition variable=stubPairs complete dim=1\n"
        )
        for i in range(0, nASMemInner):
            topFile.write("#pragma HLS resource variable=innerStubs[" + str(i) + "].get_mem() latency=2\n")
        for i in range(0, nASMemOuter):
            topFile.write("#pragma HLS resource variable=outerStubs[" + str(i) + "].get_mem() latency=2\n")
        for i in range(0, nSPMem):
            topFile.write("#pragma HLS resource variable=stubPairs[" + str(i) + "].get_mem() latency=2\n")
        topFile.write(
            "#pragma HLS interface register port=bx_o\n"
            "#pragma HLS array_partition variable=projout_barrel_ps complete dim=1\n"
            "#pragma HLS array_partition variable=projout_barrel_2s complete dim=1\n"
            "#pragma HLS array_partition variable=projout_disk complete dim=1\n"
            "\n"
            "TC_" + seed + iTC + ": TrackletCalculator<\n"
            "  TF::" + seed + ",\n"
            "  TF::" + iTC + ",\n"
            "  " + str(nSPMem) + "\n"
            " >(\n"
            "    bx,\n"
            "    innerStubs,\n"
            "    outerStubs,\n"
            "    stubPairs,\n"
            "    bx_o,\n"
            "    trackletParameters,\n"
            "    projout_barrel_ps,\n"
            "    projout_barrel_2s,\n"
            "    projout_disk\n"
            "  );\n"
            "}\n"
        )

    # Print out endifs and close files.
    parametersFile.write(
        "\n"
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
