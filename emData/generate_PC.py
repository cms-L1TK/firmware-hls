#!/usr/bin/env python3

# This script generates 
# ProjectionCalculatorTop.h, and ProjectionCalculatorTop.cc in the
# TopFunctions/ directory. Currently supports all TPs for L1L2, as well as
# TC_L3L4A, TC_L3L4D, TC_L5L6A, and TC_L5L6D.

from __future__ import absolute_import, print_function
import sys, re, os, argparse
from enum import Enum

# These enums must match those defined in
# TopFunctions/TrackletProcessor.h.
# class ProjoutIndexBarrel(Enum):
#   L1PHIA = 0
#   L1PHIB = 1
#   L1PHIC = 2
#   L1PHID = 3
#   L1PHIE = 4
#   L1PHIF = 5
#   L1PHIG = 6
#   L1PHIH = 7
#   L2PHIA = 8
#   L2PHIB = 9
#   L2PHIC = 10
#   L2PHID = 11
#   L3PHIA = 12
#   L3PHIB = 13
#   L3PHIC = 14
#   L3PHID = 15
#   L4PHIA = 16
#   L4PHIB = 17
#   L4PHIC = 18
#   L4PHID = 19
#   L5PHIA = 20
#   L5PHIB = 21
#   L5PHIC = 22
#   L5PHID = 23
#   L6PHIA = 24
#   L6PHIB = 25
#   L6PHIC = 26
#   L6PHID = 27
#   N_PROJOUT_BARREL = 28

# class ProjoutIndexDisk(Enum):
#   D1PHIA = 0
#   D1PHIB = 1
#   D1PHIC = 2
#   D1PHID = 3
#   D2PHIA = 4
#   D2PHIB = 5
#   D2PHIC = 6
#   D2PHID = 7
#   D3PHIA = 8
#   D3PHIB = 9
#   D3PHIC = 10
#   D3PHID = 11
#   D4PHIA = 12
#   D4PHIB = 13
#   D4PHIC = 14
#   D4PHID = 15
#   D5PHIA = 16
#   D5PHIB = 17
#   D5PHIC = 18
#   D5PHID = 19
#   N_PROJOUT_DISK = 20

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
#with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculator_parameters.h"), "w") as parametersFile, \
with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.h"), "w") as topHeaderFile, \
open(os.path.join(dirname, arguments.outputDirectory, "ProjectionCalculatorTop.cc"), "w") as topFile:
  # parametersFile.write(
  #     "#ifndef TopFunctions_TrackletProcessor_parameters_h\n"
  #     "#define TopFunctions_TrackletProcessor_parameters_h\n"
  #     "\n"
  #     "// This file contains numbers of memories and bit masks that are specific to\n"
  #     "// each TrackletProcessor and that come directly from the wiring.\n"
  #     "//\n"
  #     "// The validity of each of the barrel TPROJ memories is determined by\n"
  #     "// TPROJMaskBarrel. The bits of this mask, from least significant to most\n"
  #     "// significant, represent the memories in the order they are passed to\n"
  #     "// TrackletProcessor; e.g., the LSB corresponds to\n"
  #     "// projout_barrel_ps[TC::L1PHIA]. If a bit is set, the corresponding memory is\n"
  #     "// valid, if it is not, the corresponding memory is not valid. Likewise, the\n"
  #     "// validity of each of the disk TPROJ memories is determined by TPROJMaskDisk\n"
  #     "// in the same way.\n"
  #     "namespace PC{\n"
  #     "  enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};\n"
  #     "   }\n"
  #     "template<TF::seed Seed, TC::itc iTC> constexpr uint32_t PCPROJMaskBarrel();\n"
  #     "template<TF::seed Seed, TC::itc iTC> constexpr uint32_t PCPROJMaskDisk();\n"
  # )
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
    # # numbers of memories
    # nASMemInner = len(asInnerMems[tpName])
    # nASMemOuter = len(asOuterMems[tpName])
    # nVMSTEMem = len(vmsteMems[tpName])
    # # AS inner and outer masks
    # asInnerMask = 0
    # asOuterMask = 0
    # asInnerMems[tpName].sort()
    # asOuterMems[tpName].sort()


    # Print out prototype for top function for this TC.
    topHeaderFile.write(
      "\n"
      "void ProjectionCalculator_" + seed + iTC + "(\n"
      "    const BXType bx,\n"
      "    BXType& bx_o,\n"
      "    TrackletParameterMemory * trackletParameters,\n"
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
      "    TrackletParameterMemory * trackletParameters,\n"
      "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],\n"
      "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],\n"
      "    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]\n"
      ") {\n"
      "#pragma HLS inline recursive\n"
      "#pragma HLS interface register port=bx_o\n"
      "#pragma HLS stream variable=trackletParameters depth=1\n"
      "#pragma HLS array_partition variable=projout_barrel_ps complete dim=1\n"
      "#pragma HLS array_partition variable=projout_barrel_2s complete dim=1\n"
      "#pragma HLS array_partition variable=projout_disk complete dim=1\n"
      "\n"
      "PC_" + seed + iTC + ": ProjectionCalculator<\n"
      "  TF::" + seed + ",\n"
      "  TC::" + iTC + ",\n"
      " 108>(\n"
      "    bx,\n"
      "    bx_o,\n"
      "    trackletParameters,\n"
      "    projout_barrel_ps,\n"
      "    projout_barrel_2s,\n"
      "    projout_disk\n"
      "  );\n"
      "}\n"
      )
        

  # Print out endifs and close files.
  # parametersFile.write(
  #     "\n"
  #     "#endif\n"
  # )
  topHeaderFile.write(
  "\n"
  "#endif\n"
  )
  topFile.write(
  "\n"
  "////////////////////////////////////////////////////////////////////////////////\n"
  )
