#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function

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

    vmr_list = []

    # Open wiring file
    wires_file = open(wireconfig)

    # Loop over each line in the wiring
    for line in wires_file:
        module_name = line.split(" ")[-1].split(".")[0]
        # Add module name if not already in vmr_list
        if "VMSMER" in module_name and module_name not in vmr_list:
            vmr_list.append(module_name)

    wires_file.close()

    return vmr_list

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
        "  AllStub<inType>& allStub,\n"
        "  // Output memories\n"
        "  VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME,\n"
        "  AllStubMemory<outType>& memoriesAS,\n"
        "  // Index of AllStub\n"
        "  unsigned int index,\n"
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

    LD = ""
     
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
        "  AllStub<inType>& allStub,\n"
        "  // Output memories\n"
        "  VMStubMEMemoryCM<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME,\n"
        "  AllStubMemory<outType>& memoriesAS,\n"
        "  // Index of AllStub\n"
        "  unsigned int index,\n"
        "  // Bool if valid stub\n"
        "  bool valid\n"
        "  ) {\n"
        "\n"
        "// Takes 2 clock cycles before one gets data, used at high frequencies\n"
    )

    top_file.write(
        "#pragma HLS interface ap_ctrl_none port=return\n"
        "#pragma HLS pipeline II=1\n"
#        "#pragma HLS interface register port=bx_o\n"
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
        "  VMSMERouter%s<kLAYER, kDISK, inType, outType, kNbitsrzbinME, kNbitsphibin>(\n" %LD +\
        "    bx, bx_o,\n"
        "    // LUTs\n"
        "    METable,\n"
        "    phiCorrTable,\n"
        "    // Input memories\n"
        "    allStub,\n"
        "    // Output memories\n"
        "    memoryME,\n"
        "    memoriesAS,\n"
        "    // Index of AllStub\n"
        "    index,\n"
        "    valid\n"
        "  );\n"
        "\n"
        "  return;\n"
        "}\n"
    )

    top_file.close()


###############################
# Main execution

if __name__ == "__main__":

    parser = argparse.ArgumentParser(
        description = """
Generates top function and parameter files for the VMStubMERouter.
VMStubMERouterTop*.h and VMStubMERouterTop*.cc contain the top function for the units under test specified (default VMSMER_L2PHIA).
VMRouterCM_parameters.h contains the magic numbers for the specified units under test (since generating VMStubMERouter parameters file would be redundant).

Examples:
python3 generate_VMRSMER.py
python3 generate_VMRSMER.py --uut VMR_L1PHIE VMR_L1PHID
python3 generate_VMRSMER.py -a
""",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument("-a", "--all", default=False, action="store_true", help="Create files for all VMStubMERouters in a nonant.")
    parser.add_argument("--uut", default=["VMSMER_L2PHIA"], nargs="+", help="Unit Under Test (default = %(default)s)")
    parser.add_argument("-o", "--outputdir", type=str, default="../TopFunctions/", help="The directory in which to write the output files (default=%(default)s)")
    parser.add_argument("-w", "--wireconfig", type=str, default="LUTsCM/wires.dat",
                        help="Name and directory of the configuration file for wiring (default = %(default)s)")

    args = parser.parse_args()

    # Get a list of the Units Under Test
    if args.all:
        vmr_list = getAllVMRs(args.wireconfig)
    else:
        vmr_list = args.uut
    vmr_list.sort()

    # Loop over all Units Under Test
    for vmr in vmr_list:
        # Check that the Unit Under Test is a VMR
        if "VMSMER" not in vmr:
            raise IndexError("Unit under test has to be a VMSMER.")

        # Create and write the files
        writeTopHeader(vmr, args.outputdir)
        writeTopFile(vmr, args.outputdir)
