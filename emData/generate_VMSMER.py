#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function

# This script generates VMStubMERouterTop.h and VMStubMERouterTop.cc in the TopFunctions/ directory.
# Supports all VMRs, but creates separate top function files foe each VMR specified.

import argparse

###################################
# Returns number of allstubs outputs a VMSMER has

def getNAllStubMem(wireconfig, vmr):

    allstub_count = 0

    # Open wiring file
    with open(wireconfig) as wires_file:

        # Loop over each line in the wiring
        for line in wires_file:
            module_name = line.split(" ")[-3].split(".")[0]
            if module_name == vmr and "AS" in line:
                allstub_count+=1


    return allstub_count

###################################
# Returns a list of all VMSMER in the given wiring

def getAllVMRs(wireconfig):

    vmr_list = []

    # Open wiring file
    with open(wireconfig) as wires_file:

        # Loop over each line in the wiring
        for line in wires_file:
            module_name = line.split(" ")[-1].split(".")[0]
            # Add module name if not already in vmr_list
            if "VMSMER" in module_name and module_name not in vmr_list:
                vmr_list.append(module_name)

    return vmr_list

#################################
# Writes the VMStubMERouterTop.h file

def writeTopHeader(vmr, noutcopy, output_dir):

    # Get layer/disk number and phi region
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    phi_region = vmr.split("PHI")[1]

    # Top file name
    file_name = "VMStubMERouterTop_" + vmr.split("_")[1]

    with open(output_dir + "/" + file_name  + ".h", "w") as header_file:

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
            "// Variables for that are specified with regards to the VMSMER region\n"
            "// Some are used by the Test Bench\n"
            "\n"
        )

        # Write the configuration
        header_file.write(
            "#define kLAYER " + str(layer) + " // Which barrel layer number the data is coming from\n"
            "#define kDISK " + str(disk) + " // Which disk number the data is coming from, 0 if not disk\n"
            "#define NOutCopy " + str(noutcopy) + " // Numberof copies of AS and VMSMER memories (assumed to be the same)\n"
            "constexpr TF::phiRegion phiRegion = TF::" + phi_region+ "; // Which AllStub/PhiRegion\n"
            "\n"
            "constexpr TF::layerDisk layerdisk = static_cast<TF::layerDisk>((kLAYER) ? kLAYER-1 : trklet::N_LAYER+kDISK-1);\n"
            "constexpr regionType inType = (kDISK ==0) ? getInputType<layerdisk>() : DISKPS;\n"
            "constexpr regionType outType = (kDISK ==0) ? getInputType<layerdisk>() : DISK;\n"
            "// Number of bits for the RZ bins \n"
            "constexpr int kNbitsrzbinME = kNbitsrzbin%s; // For the VMSME memories\n" % ("MELayer" if layer else "MEDisk") +\
            "\n\n"
        )

        # Write the top function for VMStubMERouter
        header_file.write(
            "/////////////////////////////////////////////////////\n"
            "// VMStubMERouter Top Function \n"
            "\n"
            "void %s(const BXType bx, BXType& bx_o,\n" % file_name +\
            "  // Input memories\n"
            "  AllStub<inType>& allStub,\n"
            "  // Output memories\n"
            "  VMStubMemory<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> memoryME[NOutCopy],\n"
            "  AllStubMemory<outType> memoriesAS[NOutCopy],\n"
            "  // Index of AllStub\n"
            "  unsigned int index,\n"
            "  // Bool if valid stub\n"
            "  bool valid\n"
            "  );\n"
            "\n"
            "#endif // TopFunctions_%s_h\n" % file_name
        )

# Writes the VMRouterCMTop.cc file
def writeTopFile(vmr, output_dir):

    # Top file name
    file_name = "VMStubMERouterTop_" + vmr.split("_")[1]

    with open(output_dir + "/" + file_name  + ".cc", "w") as top_file:

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
            "  VMStubMemory<outType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> memoryME[NOutCopy],\n"
            "  AllStubMemory<outType> memoriesAS[NOutCopy],\n"
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
            "\n"
            "  ///////////////////////////\n"
            "  // Open Lookup tables\n"
            "\n"
            "  // LUT with the corrected r/z for VMSMER. It is corrected for the average r (z) of the barrel (disk).\n"
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
            "  VMSMERouter<kLAYER, kDISK, inType, outType, kNbitsrzbinME, kNbitsphibin, NOutCopy>(\n"
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

###############################
# Main execution generate_VMSMER

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
        vmrList = getAllVMRs(args.wireconfig)
    else:
        vmrList = args.uut
    vmrList.sort()

    # Loop over all Units Under Test
    for aVMR in vmrList:
        # Check that the Unit Under Test is a VMR
        if "VMSMER" not in aVMR:
            raise IndexError("Unit under test has to be a VMSMER.")

        nallstubmem = getNAllStubMem(args.wireconfig, aVMR)

        # Create and write the files
        writeTopHeader(aVMR, nallstubmem, args.outputdir)
        writeTopFile(aVMR, args.outputdir)
