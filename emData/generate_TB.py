#!/usr/bin/env python3

# This script generates TrackBuilderTop.h and TrackBuilderTop.cc in the
# TopFunctions/ directory.

from __future__ import absolute_import
import os
import re
import argparse

parser = argparse.ArgumentParser(description="This script generates TrackBuilderTop.h and TrackBuilderTop.cc in the\
TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with TBs in
# dictionaries with the TB names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
    tparMems = {}
    barrelFMMems = {}
    diskFMMems = {}
    for line in wiresFile:
        if " FT_" not in line:
            continue
        line = line.rstrip()
        tbName = re.sub(r".*FT_(....).*", r"FT_\1", line)
        seed = tbName.split("_")[1]
        memName = line.split()[0]
        if memName.startswith("TPAR"):
            if tbName not in tparMems:
                tparMems[tbName] = []
            tparMems[tbName].append(memName)
        if memName.startswith("FM"):
            if tbName not in barrelFMMems:
                barrelFMMems[tbName] = []
            if tbName not in diskFMMems:
                diskFMMems[tbName] = []
            if memName.startswith("FM_" + seed + "_L"):
                barrelFMMems[tbName].append(memName)
            if memName.startswith("FM_" + seed + "_D"):
                diskFMMems[tbName].append(memName)

# Open and print out preambles for the top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "TrackBuilderTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "TrackBuilderTop.cc"), "w") as topFile:
    topHeaderFile.write(
        "#ifndef TopFunctions_TrackBuilderTop_h\n"
        "#define TopFunctions_TrackBuilderTop_h\n"
        "\n"
        "#include \"TrackBuilder.h\"\n"
    )
    topFile.write(
        "#include \"TrackBuilderTop.h\"\n"
    )

    # Calculate parameters and print out top function for each TB.
    for tbName in sorted(tparMems.keys()):
        seed = re.sub(r"FT_(....)", r"\1", tbName)

        # numbers of memories
        nTPARMem = len(tparMems[tbName])
        nBarrelFMMem = len(barrelFMMems[tbName])
        nDiskFMMem = len(diskFMMems[tbName])

        # numbers of output stubs
        nBarrelStubs = len({fm[0:10] for fm in barrelFMMems[tbName]})
        nDiskStubs = len({fm[0:10] for fm in diskFMMems[tbName]})

        # Print out prototype for top function for this TB.
        topHeaderFile.write(
            "\n"
            "void TrackBuilder_" + seed + "(\n"
            "    const BXType bx,\n"
            "    const TrackletParameterMemory trackletParameters[],\n"
            "    const FullMatchMemory<BARREL> barrelFullMatches[],\n"
            "    const FullMatchMemory<DISK> diskFullMatches[],\n"
            "    BXType &bx_o,\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::TrackWord trackWord[],\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::BarrelStubWord barrelStubWords[][kMaxProc],\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::DiskStubWord diskStubWords[][kMaxProc]\n"
            ");\n"
        )

        # Print out definition of top function for this TB.
        topFile.write(
            "\n"
            "void TrackBuilder_" + seed + "(\n"
            "    const BXType bx,\n"
            "    const TrackletParameterMemory trackletParameters[" + str(nTPARMem) + "],\n"
            "    const FullMatchMemory<BARREL> barrelFullMatches[" + str(nBarrelFMMem) + "],\n"
            "    const FullMatchMemory<DISK> diskFullMatches[" + str(nDiskFMMem) + "],\n"
            "    BXType &bx_o,\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::TrackWord trackWord[kMaxProc],\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::BarrelStubWord barrelStubWords[" + str(nBarrelStubs) + "][kMaxProc],\n"
            "    TrackFit<" + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">::DiskStubWord diskStubWords[" + str(nDiskStubs) + "][kMaxProc]\n"
            ") {\n"
            "#pragma HLS inline recursive\n"
            "#pragma HLS array_partition variable=trackletParameters complete dim=1\n"
            "#pragma HLS array_partition variable=barrelFullMatches complete dim=1\n"
            "#pragma HLS array_partition variable=diskFullMatches complete dim=1\n"
        )
        for i in range(0, nTPARMem):
            topFile.write("#pragma HLS resource variable=trackletParameters[" + str(i) + "].get_mem() latency=2\n")
        for i in range(0, nBarrelFMMem):
            topFile.write("#pragma HLS resource variable=barrelFullMatches[" + str(i) + "].get_mem() latency=2\n")
        for i in range(0, nDiskFMMem):
            topFile.write("#pragma HLS resource variable=diskFullMatches[" + str(i) + "].get_mem() latency=2\n")
        topFile.write(
            "#pragma HLS interface register port=bx_o\n"
            "#pragma HLS array_partition variable=barrelStubWords complete dim=1\n"
            "#pragma HLS array_partition variable=diskStubWords complete dim=1\n"
            "#pragma HLS stream variable=trackWord depth=1 dim=1\n"
            "#pragma HLS stream variable=barrelStubWords depth=1 dim=2\n"
            "#pragma HLS stream variable=diskStubWords depth=1 dim=2\n"
            "\n"
            "TB_" + seed + ": TrackBuilder<" + str(nBarrelFMMem) + ", " + str(nDiskFMMem) + ", " + str(nBarrelStubs) + ", " + str(nDiskStubs) + ">(\n"
            "    bx,\n"
            "    trackletParameters,\n"
            "    barrelFullMatches,\n"
            "    diskFullMatches,\n"
            "    bx_o,\n"
            "    trackWord,\n"
            "    barrelStubWords,\n"
            "    diskStubWords\n"
            "  );\n"
            "}\n"
        )

    topHeaderFile.write(
        "\n"
        "#endif\n"
    )
