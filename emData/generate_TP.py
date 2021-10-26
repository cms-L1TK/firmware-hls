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
    N_PROJOUT_DISK = 16

iAllStub_index = {
  "A" : 0,
  "B" : 1,
  "C" : 2,
  "D" : 3,
  "I" : 0,
  "J" : 1,
  "K" : 2,
  "L" : 3,
  "X" : 0,
  "Y" : 1,
  "Z" : 2,
  "W" : 3,
}

parser = argparse.ArgumentParser(description="This script generates TrackletProcessorTop.h, TrackletProcessorTop.cc, and\
TrackletProcessor_parameters.h in the TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# First, parse the wires file and store the memory names associated with TPs in
# dictionaries with the TP names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
  asInnerMems = {}
  innerType = {}
  outerType = {}
  asOuterMems = {}
  vmsteMems = {}
  tprojMems = {}
  outerPhiRegion = {}
  for line in wiresFile:
      # Only barrel-only seeds are supported right now.
      if "TP_L1L2" not in line \
        and "TP_L2L3" not in line \
        and "TP_L3L4" not in line \
        and "TP_L5L6" not in line:
          continue      
      line = line.rstrip()
      tpName = re.sub(r".*TP_(.....).*", r"TP_\1", line)
  
      if "TP_L1L2" in line or "TP_L2L3" in line or "TP_L3L4" in line:
        innerType[tpName] = "BARRELPS"
      else:
        innerType[tpName] = "BARREL2S"
      if "TP_L1L2" in line or "TP_L2L3" in line:
        outerType[tpName] = "BARRELPS"
      else:
        outerType[tpName] = "BARREL2S"
      memName = line.split()[0]
  
      if "TP_L2L3" in line:
          if memName.startswith("AS_L2"):
              if tpName not in asInnerMems:
                  asInnerMems[tpName] = []
              asInnerMems[tpName].append(memName)
          if memName.startswith("AS_L3"):
              if tpName not in asOuterMems:
                  asOuterMems[tpName] = []
              asOuterMems[tpName].append(memName)
      else:
          if memName.startswith("AS_L1") or memName.startswith("AS_L3") or memName.startswith("AS_L5"):
              if tpName not in asInnerMems:
                  asInnerMems[tpName] = []
              asInnerMems[tpName].append(memName)
          if memName.startswith("AS_L2") or memName.startswith("AS_L4") or memName.startswith("AS_L6"):
              if tpName not in asOuterMems:
                  asOuterMems[tpName] = []
              asOuterMems[tpName].append(memName)
      if memName.startswith("VMSTE_"):
          if tpName not in vmsteMems:
              vmsteMems[tpName] = []
          vmsteMems[tpName].append(memName)
          outerPhiRegion[tpName] = iAllStub_index[memName[11]]
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
      "ap_uint<1> nearFullTEBuff(const ap_uint<TEBuffer<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBufferDepthBits>& writeptr,\n" 
      "			  const ap_uint<TEBuffer<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBufferDepthBits>& readptr) {\n"
      "  ap_uint<3> writeptr1=writeptr+1;\n"
      "  ap_uint<3> writeptr2=writeptr+2;\n"
      "  ap_uint<3> writeptr3=writeptr+3;\n"
      "  ap_uint<1> result=writeptr1==readptr||writeptr2==readptr||writeptr3==readptr;\n"
      "  return result;\n"
      "}\n"
      "ap_uint<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer))> nearFullTEUnitInit() {\n"
      "  ap_uint<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer))> lut(0);\n"
      "  int i;\n"
      "  for(i=0;i<(1<<(2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer));i++) {\n"
      "    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr,rptr;\n"
      "    ap_uint<2*TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> address(i);\n"
      "    (rptr,wptr)=address;\n"
      "    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr1=wptr+1;\n"
      "    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr2=wptr+2;\n"
      "    ap_uint<TrackletEngineUnit<TF::L1L2,TC::C,BARRELPS,BARRELPS>::kNBitsBuffer> wptr3=wptr+3;\n"
      "    ap_uint<1> result=wptr1==rptr||wptr2==rptr||wptr3==rptr;\n"
      "    lut[i]=result;\n"
      "  }\n"
      "  return lut;\n"
      " }\n"
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
      regionlutlen = 2048
      if seed == "L5L6":
        regionlutlen = 4096
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
          "}\n")
          % (tprojMaskBarrel, tprojMaskDisk)
      )
  
      # Print out prototype for top function for this TC.
      topHeaderFile.write(
          "\n"
          "void TrackletProcessor_" + seed + iTC + "(\n"
          "    const BXType bx,\n"
          "    const ap_uint<1+2*TrackletEngineUnit<TF::"+seed+", TC::"+iTC+","+innerType[tpName]+","+outerType[tpName]+">::kNBitsRZFine+TrackletEngineUnit<TF::"+seed+", TC::"+iTC+","+innerType[tpName]+","+outerType[tpName]+">::kNBitsRZBin> lut[1<<(kNbitszfinebintable+kNbitsrfinebintable)],\n"
          "    const ap_uint<(1<<TrackletEngineUnit<TF::"+seed+", TC::"+iTC+","+innerType[tpName]+","+outerType[tpName]+">::kNBitsPhiBins)> regionlut[1<<(AllStubInner<"+innerType[tpName]+">::kASBendSize+AllStubInner<"+innerType[tpName]+">::kASFinePhiSize)],\n" 
          "    const AllStubInnerMemory<"+innerType[tpName]+"> innerStubs["+str(nASMemInner)+"],\n"
          "    const AllStubMemory<OuterRegion<TF::" + seed + ">()>* outerStubs,\n"
          "    const VMStubTEOuterMemoryCM<"+outerType[tpName]+", kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::"+seed+"]> outerVMStubs,\n"
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
          "    const ap_uint<10> lut[2048],\n"
          "    const ap_uint<8> regionlut["+str(regionlutlen)+"],\n"
          "    const AllStubInnerMemory<"+innerType[tpName]+"> innerStubs[" + str(nASMemInner) + "],\n"
          "    const AllStubMemory<OuterRegion<TF::" + seed + ">()>* outerStubs ,\n"
          "    const VMStubTEOuterMemoryCM<" + outerType[tpName] + ", kNbitsrzbin, kNbitsphibin, kNTEUnits[TF::"+ seed +"]> outerVMStubs,\n"
          "    TrackletParameterMemory * trackletParameters,\n"
          "    TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS],\n"
          "    TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S],\n"
          "    TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK]\n"
          ") {\n"
          "#pragma HLS inline recursive\n"
          "#pragma HLS resource variable=lut core=ROM_2P_BRAM  latency=2\n"
          "#pragma HLS resource variable=regionlut core=ROM_2P_BRAM latency=2\n"
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
          "TP_" + seed + iTC + ": TrackletProcessor<\n"
          "  TF::" + seed + ",\n"
          "  TC::" + iTC + ",\n"
          "  kNTEUnits[TF::"+seed+"],\n"
          "  "+innerType[tpName]+",\n"
          "  "+outerType[tpName]+",\n"
          "  "+str(outerPhiRegion[tpName])+",\n"
          "  kNbitsrzbin,\n"
          "  kNbitsphibin,\n"
          "  "+str(nASMemInner)+",\n"
          " 108>(\n"
          "    bx,\n"
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
  
