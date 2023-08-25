#!/usr/bin/env python3

# This script generates TrackletParameter_parameters.h,
# TrackletParameterTop.h, and TrackletParameterTop.cc in the
# TopFunctions/ directory. Currently supports all TPs for L1L2, as well as
# TC_L3L4A, TC_L3L4D, TC_L5L6A, and TC_L5L6D.

from __future__ import absolute_import, print_function
import sys, re, os, argparse
from enum import Enum

# These enums must match those defined in
# TopFunctions/TrackletProcessor.h.
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
    D5PHIA = 16
    D5PHIB = 17
    D5PHIC = 18
    D5PHID = 19
    N_PROJOUT_DISK = 20

parser = argparse.ArgumentParser(description="This script generates TrackletProcessorTop.h, TrackletProcessorTop.cc, and\
TrackletProcessor_parameters.h in the TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/CombinedConfig/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTsCM/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with TPs in
# dictionaries with the TP names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
  asInnerMems = {}
  asOuterMems = {}
  vmsteMems = {}
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
      if memName.startswith("AS_"):
          memLayer= memName[3:5]
          if memLayer == innerLayer:
              if tpName not in asInnerMems:
                  asInnerMems[tpName] = []
              asInnerMems[tpName].append(memName)
          elif memLayer == outerLayer:
              if tpName not in asOuterMems:
                  asOuterMems[tpName] = []
              asOuterMems[tpName].append(memName)
      if memName.startswith("VMSTE_"):
          if tpName not in vmsteMems:
              vmsteMems[tpName] = []
          vmsteMems[tpName].append(memName)
      if memName.startswith("TPROJ_"):
          if tpName not in tprojMems:
              tprojMems[tpName] = []
          tprojMems[tpName].append(memName)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "TrackletProcessor_parameters.h"), "w") as parametersFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "TrackletProcessorTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "TrackletProcessorTop.cc"), "w") as topFile:
  parametersFile.write(
      "#ifndef TopFunctions_TrackletProcessor_parameters_h\n"
      "#define TopFunctions_TrackletProcessor_parameters_h\n"
      "\n"
      "// This file contains numbers of memories and bit masks that are specific to\n"
      "// each TrackletProcessor and that come directly from the wiring.\n"
      "//\n"
      "// The validity of each of the barrel TPROJ memories is determined by\n"
      "// TPROJMaskBarrel. The bits of this mask, from least significant to most\n"
      "// significant, represent the memories in the order they are passed to\n"
      "// TrackletProcessor; e.g., the LSB corresponds to\n"
      "// projout_barrel_ps[TC::L1PHIA]. If a bit is set, the corresponding memory is\n"
      "// valid, if it is not, the corresponding memory is not valid. Likewise, the\n"
      "// validity of each of the disk TPROJ memories is determined by TPROJMaskDisk\n"
      "// in the same way.\n"
      "namespace TC{\n"
      "  enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};\n"
      "   }\n"
      "template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskBarrel();\n"
      "template<TF::seed Seed, TC::itc iTC> constexpr uint32_t TPROJMaskDisk();\n"
      "template<TF::seed Seed, TC::itc iTC> const ap_uint<8>* getRegionLUT();\n"
      "template<TF::seed Seed, TC::itc iTC> const ap_uint<10>* getLUT();\n"
      "template<TF::seed Seed, TC::itc iTC> const ap_uint<1>* getPTInnerLUT();\n"
      "template<TF::seed Seed, TC::itc iTC> const ap_uint<1>* getPTOuterLUT();\n"
      "template<TF::seed Seed, TC::itc iTC> constexpr int nASMemInner();\n"
  )
  topHeaderFile.write(
      "#ifndef TopFunctions_TrackletProcessorTop_h\n"
      "#define TopFunctions_TrackletProcessorTop_h\n"
      "\n"
      "#include \"TrackletProcessor.h\"\n"
  )
  topFile.write(
      "#include \"TrackletProcessorTop.h\"\n"
      "\n"
      "////////////////////////////////////////////////////////////////////////////////\n"
      "// Top functions for various TrackletProcessors (TP). For each iteration of\n"
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
  for tpName in sorted(asInnerMems.keys()):
      seed = re.sub(r"TP_(....).", r"\1", tpName)
      iTC = re.sub(r"TP_....(.)", r"\1", tpName)
      # numbers of memories
      nASMemInner = len(asInnerMems[tpName])
      nASMemOuter = len(asOuterMems[tpName])
      nVMSTEMem = len(vmsteMems[tpName])
      # AS inner and outer masks
      asInnerMask = 0
      asOuterMask = 0
      asInnerMems[tpName].sort()
      asOuterMems[tpName].sort()
  
      # TPROJ masks for barrel and disks
      tprojMaskBarrel = 0
      for projout in ProjoutIndexBarrel:
          projoutName = "TPROJ_" + seed + iTC + "_" + projout.name
          projoutIndex = projout.value
          if projoutName in tprojMems[tpName]:
              tprojMaskBarrel = tprojMaskBarrel | (1 << projoutIndex)
      tprojMaskDisk = 0
      for projout in ProjoutIndexDisk:
          projoutName = "TPROJ_" + seed + iTC + "_" + projout.name
          projoutIndex = projout.value
          if projoutName in tprojMems[tpName]:
              tprojMaskDisk = tprojMaskDisk | (1 << projoutIndex)
      # Print out parameters for this TP.
      parametersFile.write(
          ("\n"
          "template<> constexpr uint32_t TPROJMaskBarrel<TF::" + seed + ", TC::" + iTC + ">() {\n"
          "  return 0x%X;\n"
          "}\n"
          "template<> constexpr uint32_t TPROJMaskDisk<TF::" + seed + ", TC::" + iTC + ">() {\n"
          "  return 0x%X;\n"
          "}\n"
          'template<> inline const ap_uint<8>* getRegionLUT<TF::'+ seed + ', TC::' + iTC + ' >(){\n'
          '  static ap_uint<8> lut[] =\n'
          '#if __has_include("../emData/TP/tables/TP_' + seed + iTC + '_usereg.tab")\n'
          '#  include "../emData/TP/tables/TP_' + seed + iTC + '_usereg.tab"\n'
          '#else\n'
          '  {};\n'
          '#endif\n'
          '  return lut;\n'
          '}\n'
          'template<> inline const ap_uint<10>* getLUT<TF::'+ seed + ', TC::' + iTC + ' >(){\n'
          '  static ap_uint<10> lut[] =\n'
          '#if __has_include("../emData/TP/tables/TP_' + seed + '.tab")\n'
          '#  include "../emData/TP/tables/TP_' + seed + '.tab"\n'
          '#else\n'
          '  {};\n'
          '#endif\n'
          '  return lut;\n'
          '}\n'
          'template<> inline const ap_uint<1>* getPTInnerLUT<TF::'+ seed + ', TC::' + iTC + ' >(){\n'
          '  static ap_uint<1> lut[] =\n'
          '#if __has_include("../emData/TP/tables/TP_' + seed + iTC +'_stubptinnercut.tab")\n'
          '#  include "../emData/TP/tables/TP_' + seed + iTC + '_stubptinnercut.tab"\n'
          '#else\n'
          '  {};\n'
          '#endif\n'
          '  return lut;\n'
          '}\n'
          'template<> inline const ap_uint<1>* getPTOuterLUT<TF::'+ seed + ', TC::' + iTC + ' >(){\n'
          '  static ap_uint<1> lut[] =\n'
          '#if __has_include("../emData/TP/tables/TP_' + seed + iTC +'_stubptoutercut.tab")\n'
          '#  include "../emData/TP/tables/TP_' + seed + iTC + '_stubptoutercut.tab"\n'
          '#else\n'
          '  {};\n'
          '#endif\n'
          '  return lut;\n'
          '}\n'
          'template<> constexpr int nASMemInner<TF::'+ seed + ', TC::' + iTC + '>(){\n'
          '  return ' + str(nASMemInner) + ';\n'
          '}\n'
)% (tprojMaskBarrel, tprojMaskDisk)
      )
  
      # Print out prototype for top function for this TC.
      topHeaderFile.write(
          "\n"
          "void TrackletProcessor_" + seed + iTC + "(\n"
          "    const BXType bx,\n"
          "    BXType& bx_o,\n"
          "    const AllStubInnerMemory<InnerRegion<TF::" + str(seed) + ">()> innerStubs[nASMemInner<TF::" + str(seed) + ", TC::" + iTC + ">()],\n"
          "    const AllStubMemory<OuterRegion<TF::" + str(seed) + ">()>* outerStubs,\n"
          "    const VMStubTEOuterMemoryCM<OuterRegion<TF::" + str(seed) + ">(), kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[TF::"+seed[2:]+"]>* outerVMStubs,\n"
          "    TrackletParameterMemory * trackletParameters,\n"
          "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[],\n"
          "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[],\n"
          "    TrackletProjectionMemory<DISK> projout_disk[]\n"
          ");\n"
      )
  
      # Print out definition of top function for this TP.
      topFile.write(
          "\n"
          "void TrackletProcessor_" + seed + iTC + "(\n"
          "    const BXType bx,\n"
          "    BXType& bx_o,\n"
          "    const AllStubInnerMemory<InnerRegion<TF::" + str(seed) + ">()> innerStubs[nASMemInner<TF::" + str(seed) + ", TC::" + iTC + ">()],\n"
          "    const AllStubMemory<OuterRegion<TF::" + str(seed) + ">()>* outerStubs ,\n"
          "    const VMStubTEOuterMemoryCM<OuterRegion<TF::" + str(seed) + ">(), kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[TF::"+ seed[2:] +"]>* outerVMStubs,\n"
          "    TrackletParameterMemory * trackletParameters,\n"
          "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],\n"
          "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],\n"
          "    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]\n"
          ") {\n"
          "#pragma HLS inline recursive\n"
          "#pragma HLS interface register port=bx_o\n"
      )
      for i in range(0, nASMemInner):
          topFile.write("#pragma HLS resource variable=innerStubs[" + str(i) + "].get_mem() latency=2\n")
      topFile.write("#pragma HLS resource variable=outerStubs->get_mem() latency=2\n")
      topFile.write("#pragma HLS resource variable=outerVMStubs.get_mem() latency=2\n")
      topFile.write(
          "#pragma HLS array_partition variable=projout_barrel_ps complete dim=1\n"
          "#pragma HLS array_partition variable=projout_barrel_2s complete dim=1\n"
          "#pragma HLS array_partition variable=projout_disk complete dim=1\n"
          "\n"
          "static const ap_uint<10>* lut = getLUT<TF::" + seed + ",TC::" +  iTC + ">();\n"
          "static const ap_uint<8>* regionlut = getRegionLUT<TF::" + seed + ", TC::" + iTC +">();\n"
          "\n"
          "TP_" + seed + iTC + ": TrackletProcessor<\n"
          "  TF::" + seed + ",\n"
          "  TC::" + iTC + ",\n"
          "  kNTEUnitsLayerDisk[TF::" +  seed[2:]+ "],\n"
          "  nASMemInner<TF::"+seed+",TC::"+iTC+">(),\n"
          " 108>(\n"
          "    bx,\n"
          "    bx_o,\n"
          "    lut,\n"
          "    regionlut,\n"
          "    innerStubs,\n"
          "    outerStubs,\n"
          "    outerVMStubs,\n"
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
  
