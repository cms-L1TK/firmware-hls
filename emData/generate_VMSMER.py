#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function
import sys, re, os, argparse

# This script generates VMStubMERouterTop.h and VMStubMERouterTop.cc in the TopFunctions/ directory.
# Supports all VMRs, but creates separate top function files foe each VMR specified.

import argparse
import collections

# Constants
num_layers = 6
num_disks = 5

###################################
# Returns a list of all VMRs in the given wiring

def getAllVMRs(wireconfig):

    vmsmer_list = []

    # Open wiring file
    wires_file = open(wireconfig)

    # Loop over each line in the wiring
    for line in wires_file:
        module_name = line.split(" ")[-1].split(".")[0]
        # Add module name if not already in vmsmer_list
        if "VMSMER" in module_name and module_name not in vmsmer_list:
            vmsmer_list.append(module_name)

    wires_file.close()

    return vmsmer_list

#################################
# Writes the VMStubMERouterTop.h file

def writeTopHeader(vmr, output_dir):

    # Get layer/disk number and phi region
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1
    phi_region = vmr.split("PHI")[1]

    # Top file name
    file_name = "VMStubMERouterTop_" + vmr.split("_")[1]

    header_file = open(output_dir + "/" + file_name  + ".h", "w")

    # Write preamble
    header_file.write(
        "#ifndef TopFunctions_" + file_name + "_h\n" +\
        "#define TopFunctions_" + file_name + "_h\n" +\
        "\n"
        "#include \"VMSMERouter.h\"\n"
        "#include \"VMRouterCM_parameters.h\"\n"
        "\n"
        "// VMStubMERouter Top Function\n"
        "// Sort AllStubs into smaller regions in phi, i.e. Virtual Modules (VMs). By writing VMStubME memories.\n"
        "\n"
        "////////////////////////////////////////////\n"
        "// Variables for that are specified with regards to the VMR region\n"
        "// Some are used by the Test Bench\n"
        "\n"
    )

    # Write the configuration
    header_file.write(
        "#define kLAYER " + str(layer) + " // Which barrel layer number the data is coming from\n"
        "#define kDISK " + str(disk) + " // Which disk number the data is coming from, 0 if not disk\n"
        "constexpr TF::phiRegion phiRegion = TF::" + phi_region+ "; // Which AllStub/PhiRegion\n"
        "\n"
        "constexpr TF::layerDisk layerdisk = static_cast<TF::layerDisk>((kLAYER) ? kLAYER-1 : trklet::N_LAYER+kDISK-1);\n"
        "constexpr regionType inType = (kDISK ==0) ? getInputType<layerdisk>() : DISKPS;\n"
        "constexpr regionType outType = (kDISK ==0) ? getInputType<layerdisk>() : DISK;\n"
        "// Number of bits for the RZ bins \n"
        "constexpr int kNbitsrzbinME = kNbitsrzbin%s; // For the VMSME memories\n" % ("MELayer" if layer else "MEDisk") +\
        "\n\n"
    )

    # Write the top function
    header_file.write(
        "/////////////////////////////////////////////////////\n"
        "// VMStubMERouter Top Function \n"
        "\n"
        "void %s(const BXType bx, BXType& bx_o,\n" % file_name +\
        "  // Input memories\n"
        "  AllStub<inType> allStub,\n"
        "  // Output memories\n"
        "  VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME,\n"
        "  AllStubMemory<outType> allStubCopy,\n"
        "  // Index of AllStub\n"
        "  const unsigned int index,\n"
        "  // Array to count how many VMStubs written in each slot\n"
		"  ap_uint<5> addrCountME[1 << (kNbitsrzbinME + kNbitsphibin)],\n"
        "  // Bool if valid stub\n"
        "  bool valid\n"
        "  );\n"
        "\n"
        "#endif // TopFunctions_%s_h\n" % file_name
    )

    header_file.close()


# Writes the VMRouterCMTop.cc file
def writeTopFile(vmr, output_dir):

    # Get layer/disk number
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1

    # Top file name
    file_name = "VMStubMERouterTop_" + vmr.split("_")[1]

    top_file = open(output_dir + "/" + file_name  + ".cc", "w")

    # Write the top function
    top_file.write(
        "#include \"" + file_name + ".h\"\n\n" +\
        "// VMStubMERouter Top Function\n"
        "// Sort AllStubs into smaller regions in phi, i.e. Virtual Modules (VMs). By writing VMStubME memories.\n"
        "\n"
        "void %s(\n" % file_name +\
        "  const BXType bx, BXType& bx_o,\n"
        "  // Input memories\n"
        "  AllStub<inType> allStub,\n"
        "  // Output memories\n"
        "  VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME,\n"
        "  AllStubMemory<outType> allStubCopy,\n"
        "  // Index of AllStub\n"
        "  const unsigned int index,\n"
        "  // Array to count how many VMStubs written in each slot\n"
		"  ap_uint<5> addrCountME[1 << (kNbitsrzbinME + kNbitsphibin)],\n"
        "  // Bool if valid stub\n"
        "  bool valid\n"
        "  ) {\n"
        "\n"
        "// Takes 2 clock cycles before one gets data, used at high frequencies\n"
    )

    top_file.write(
        "#pragma HLS interface register port=bx_o\n"
        "\n"
        "  ///////////////////////////\n"
        "  // Open Lookup tables\n"
        "\n"
        "  // LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).\n"
        "  // Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.\n"
        "  // Indexed using r and z position bits\n"
        "  static const int* METable = getMETable<layerdisk>();\n"
        "\n"
        "  // LUT with phi corrections to project the stub to the average radius in a layer.\n"
        "  // Only used by layers.\n"
        "  // Indexed using phi and bend bits\n"
        "  static const int* phiCorrTable = getPhiCorrTable<layerdisk>();\n"
        "\n"
        "  /////////////////////////\n"
        "  // Main function\n"
        "\n"
        "  VMSMERouter<kLAYER, kDISK, inType, outType, kNbitsrzbinME, kNbitsphibin>(\n"
        "    bx, bx_o,\n"
        "    // LUTs\n"
        "    METable,\n"
        "    phiCorrTable,\n"
        "    // Input memories\n"
        "    allStub,\n"
        "    // Output memories\n"
        "    memoryME,\n"
        "    allStubCopy,\n"
        "    // Index of AllStub\n"
        "    index,\n"
        "    addrCountME,\n"
        "    valid\n"
        "  );\n"
        "\n"
        "  return;\n"
        "}\n"
    )

    top_file.close()


###############################
# Main execution

parser = argparse.ArgumentParser(description="This script generates VMSMERouterTop.h, VMsMERouterTop.cc \
   in the TopFunctions/ directory.", epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/CombinedConfig/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTsCM/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()




# First, parse the wires file and store the memory names associated with VMSMERs in
# dictionaries with the VMSMER names as keys.
with open(arguments.wiresFileName, "r") as wiresFile:
  asMems = {}
  for line in wiresFile:
      if "VMSMER_" not in line :
        continue
      line = line.rstrip()
      vmsmerName = line.split("VMSMER_")[1].split(".")[0]
      memName = line.split()[0]

      print("line:", line)
      
      if memName.startswith("AS"):
        if vmsmerName not in asMems:
          asMems[vmsmerName] = []
          asMems[vmsmerName].append(memName)

# Open and print out preambles for the parameters and top files.
dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "VMSMERouterTop.h"), "w") as topHeaderFile, \
     open(os.path.join(dirname, arguments.outputDirectory, "VMSMERouterTop.cc"), "w") as topFile:
    topHeaderFile.write(
        "#ifndef TopFunctions_VMSMERouterTop_h\n"
        "#define TopFunctions_VMSMERouterTop_h\n"
        "\n"
        "#include \"VMSMERouter.h\"\n"
    )
    topFile.write(
        "#include \"VMSMERouterTop.h\"\n"
        "#include \"VMSMER_parameters.h\"\n" 
       "\n"
        "////////////////////////////////////////////////////////////////////////////////\n"
        "// Top functions for various VMSMERouters (VMSMER)."
        "////////////////////////////////////////////////////////////////////////////////\n"
    )

    for vmsmerName in sorted(asMems):
        layer = "0"
        disk = "0"
        if vmsmerName[0] == "L" :
            layer = vmsmerName[1]
        if vmsmerName[0] == "D" :
            disk = vmsmerName[1]
        asinType = "DISKPS"
        asoutType = "DISK"
        rzbinbits = "4"
        if "L1" in vmsmerName or "L2" in vmsmerName or "L3" in vmsmerName:
            asinType = "BARRELPS"
            asoutType = "BARRELPS"
            rzbinbits = "3"
        if "L4" in vmsmerName or "L5" in vmsmerName or "L6" in vmsmerName:
            asinType = "BARREL2S"
            asoutType = "BARREL2S"
            rzbinbits = "3"
        topHeaderFile.write(
            "\n"
            "void VMSMERouter_%s(const BXType bx, BXType& bx_o,\n" % vmsmerName +\
            "  // Input memories\n"
            "  AllStub<%s> allStub,\n" % asinType +\
            "  // Output memories\n"
            "  VMStubMEMemoryCM<%s, %s, kNbitsphibin, kNMatchEngines> *memoryME,\n" % (asoutType, rzbinbits) +\
            "  AllStubMemory<%s> allStubCopy,\n" % asoutType +\
            "  // Index of AllStub\n"
            "  const unsigned int index,\n"
            "  // Array to count how many VMStubs written in each slot\n"
	    "  ap_uint<5> addrCountME[1 << (%s + kNbitsphibin)],\n" % rzbinbits +\
            "  // Bool if valid stub\n"
            "  bool valid\n"
            "  );\n"
            "\n"
        )

        topFile.write(
            "\n"
            "void VMSMERouter_%s(\n" % vmsmerName +\
            "  const BXType bx, BXType& bx_o,\n"
            "  // Input memories\n"
            "  AllStub<%s> allStub,\n" %asinType +\
            "  // Output memories\n"
            "  VMStubMEMemoryCM<%s, %s, kNbitsphibin, kNMatchEngines> *memoryME,\n" %(asoutType, rzbinbits) +\
            "  AllStubMemory<%s> allStubCopy,\n" %asoutType +\
            "  // Index of AllStub\n"
            "  const unsigned int index,\n"
            "  // Array to count how many VMStubs written in each slot\n"
            "  ap_uint<5> addrCountME[1 << (%s + kNbitsphibin)],\n" %rzbinbits +\
            "  // Bool if valid stub\n"
            "  bool valid\n"
            "  ) {\n"
            "\n"
            "// Takes 2 clock cycles before one gets data, used at high frequencies\n"

            "#pragma HLS interface register port=bx_o\n"
            "\n"
            "  ///////////////////////////\n"
            "  // Open Lookup tables\n"
            "\n"
            "  // LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).\n"
            "  // Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.\n"
            "  // Indexed using r and z position bits\n"
            "  static const int* METable = getMETable<TF::%s>();\n" %vmsmerName[0:2] +\
            "\n"
            "  // LUT with phi corrections to project the stub to the average radius in a layer.\n"
            "  // Only used by layers.\n"
            "  // Indexed using phi and bend bits\n"
            "  static const int* phiCorrTable = getPhiCorrTable<TF::%s>();\n" %vmsmerName[0:2] +\
            "\n"
            "  /////////////////////////\n"
            "  // Main function\n"
            "\n"
            "  VMSMERouter< %s, %s, %s, %s, %s, kNbitsphibin>(\n" %(layer, disk, asinType, asoutType, rzbinbits) +\
            "    bx, bx_o,\n"
            "    // LUTs\n"
            "    METable,\n"
            "    phiCorrTable,\n"
            "    // Input memories\n"
            "    allStub,\n"
            "    // Output memories\n"
            "    memoryME,\n"
            "    allStubCopy,\n"
            "    // Index of AllStub\n"
            "    index,\n"
            "    addrCountME,\n"
            "    valid\n"
            "  );\n"
            "\n"
            "  return;\n"
            "}\n"
        )
    topHeaderFile.write(
        "#endif\n"
    )
