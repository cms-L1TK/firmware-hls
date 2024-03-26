#!/usr/bin/env python3

# This script generates ProjectionCalculatorTop.h, and
# ProjectionCalculatorTop.cc in the TopFunctions/ directory.

from __future__ import absolute_import, print_function
import re, os, argparse

parser = argparse.ArgumentParser(description="This script generates ProjectionCalculatorTop.h, ProjectionCalculatorTop.cc \
   in the TopFunctions/ directory.",
  epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/CombinedConfig/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTsCM/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with PCs in
# dictionaries with the PC names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
  tprojMems = {}
  for line in wiresFile:
      # Only barrel-only seeds are supported right now.
      if "TP_L1L2" not in line \
      and "TP_L2L3" not in line \
      and "TP_L3L4" not in line \
      and "TP_L5L6" not in line \
      and "TP_L2D1" not in line \
      and "TP_L1D1" not in line \
      and "TP_D1D2" not in line \
      and "TP_D3D4" not in line:
        continue
      line = line.rstrip()
      tpName = re.sub(r".*TP_(.....).*", r"TP_\1", line)
      innerLayer = tpName[3:5]
      outerLayer = tpName[5:7]
      memName = line.split()[0]

      if memName.startswith("TPROJ_"):
        if tpName not in tprojMems:
          tprojMems[tpName] = []
          tprojMems[tpName].append(memName)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.h"), "w") as topHeaderFile, \
open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.cc"), "w") as topFile:
  topHeaderFile.write(
    "#ifndef TopFunctions_ProjectionCalculatorTop_h\n"
    "#define TopFunctions_ProjectionCalculatorTop_h\n"
    "\n"
    "#include \"ProjectionCalculator.h\"\n"
    )
  topFile.write(
    "#include \"ProjectionCalculatorTop.h\"\n"
    "\n"
    "////////////////////////////////////////////////////////////////////////////////\n"
    "// Top functions for various ProjectionCalculators (PC). For each iteration of\n"
    "// the main processing loop, a TC retrieves a pair of stub indices from one of\n"
    "// the stub-pair memories, and in turn, these indices are used to retrieve one\n"
    "// stub each from an inner and an outer all-stub memory. This pair of stubs is\n"
    "// used to calculate a rough set of helix parameters, which are written to the\n"
    "// tracklet-parameter memory if the tracklet passes cuts on rinv and z0. Rough\n"
    "// projections to additional layers and disks are also calculated and are\n"
    "// written to the appropriate tracklet-projection memories.\n"
    "////////////////////////////////////////////////////////////////////////////////\n"
    )
  # Calculate parameters and print out parameters and top function for each TP.
  for tpName in sorted(tprojMems):
    seed = re.sub(r"TP_(....).", r"\1", tpName)
    iTC = re.sub(r"TP_....(.)", r"\1", tpName)

    # Print out prototype for top function for this TC.
    topHeaderFile.write(
      "\n"
      "void ProjectionCalculator_" + seed + iTC + "(\n"
      "    const BXType bx,\n"
      "    BXType& bx_o,\n"
      "    TrackletParameters tPars,\n"
      "    int trackletIndex,\n"
      "    bool valid,\n"
      "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],\n"
      "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],\n"
      "    TrackletProjectionMemory<DISK> projout_disk[]\n"
      ");\n"
      )

    # Print out definition of top function for this TP.
    topFile.write(
      "\n"
      "void ProjectionCalculator_" + seed + iTC + "(\n"
      "    const BXType bx,\n"
      "    BXType& bx_o,\n"
      "    TrackletParameters tPars,\n"
      "    int trackletIndex,\n"
      "    bool valid,\n"
      "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],\n"
      "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],\n"
      "    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]\n"
      ") {\n"
      "#pragma HLS pipeline II=1\n"
      "#pragma HLS latency min=13 max=13\n"
      "#pragma HLS inline recursive\n"
      "#pragma HLS interface register port=bx_o\n"
      "#pragma HLS array_partition variable=projout_barrel_ps complete dim=1\n"
      "#pragma HLS array_partition variable=projout_barrel_2s complete dim=1\n"
      "#pragma HLS array_partition variable=projout_disk complete dim=1\n"
      "\n"
      "PC_" + seed + iTC + ": ProjectionCalculator<\n"
      "  TF::" + seed + ",\n"
      "  TC::" + iTC + ">(\n"
      "    bx,\n"
      "    bx_o,\n"
      "    tPars,\n"
      "    trackletIndex,\n"
      "    valid,\n"
      "    projout_barrel_ps,\n"
      "    projout_barrel_2s,\n"
      "    projout_disk\n"
      "  );\n"
      "}\n"
      )

  topHeaderFile.write(
  "\n"
  "#endif\n"
  )
  topFile.write(
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  )
