#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function

# This script generates VMRouterCM_parameters.h, VMRouterCMTop.h,
# and VMRouterCMTop.cc for the Combined Module VMR in the TopFunctions/ directory.
# Supports all VMRs, but creates separate top function files foe each VMR specified.
# VMRouterCM_parameters.h contains functions and magic numbers.

import argparse
import collections

# Constants
num_layers = 6
num_disks = 5

# Lists of which layer/disk has AllStubInner ans VMSTE memories
has_allstub_inner = [True, True, True, False, True, False, True, False, True, False, False]
has_vmste_outer = [False, True, True, True, False, True, True, True, False, True, False]


#############################################
# Returns a dictionary of memories

# One key for every memory type in each layer/disk
# Value is a list of all memory names for that key

def getDictOfMemories(wireconfig, vmr_list):

    # Dictionary of all the input and output memories
    mem_dict = {}

    # Open wiring file
    wires_file = open(wireconfig)

    # Loop over each line in the wiring
    for line in wires_file:
        # Check if any of the VMRs exist in the line
        for vmr in vmr_list:
            if vmr in line:
                mem_name = line.split()[0]
                mem_type = mem_name.split("_")[0]
                # Check if memory type is Inner AllStub or IL DISK2S
                if "IL_D" in mem_name and "2S" in mem_name:
                    mem_type = mem_type + "_DISK2S_" + vmr
                elif "innerallstubin" in line:
                    mem_type = mem_type + "I_" + vmr
                else:
                    mem_type = mem_type + "_" + vmr
                # Add memory and memory type to dictionary
                if mem_type not in mem_dict:
                    mem_dict[mem_type] = [mem_name]
                else:
                    mem_dict[mem_type].append(mem_name)
                break

    # Loop over all memories and add an empty IL DISK2S, AllStub Inner, and VMSTE memory lists if missing in dictionary
    for vmr in vmr_list:
        if "IL_DISK2S_" + vmr not in mem_dict:
            mem_dict["IL_DISK2S_" + vmr] = []
        if "VMSTE_" + vmr not in mem_dict:
            mem_dict["VMSTE_" + vmr] = []
        if "AS_" + vmr not in mem_dict:
            mem_dict["AS_" + vmr] = []
        if "ASI_" + vmr not in mem_dict:
            mem_dict["ASI_" + vmr] = []

    wires_file.close()

    return mem_dict


###################################
# Returns a dictionary of memory copies

# Count the number of memories and copies, as the number of copies can differ

def getDictOfCopies(mem_list):

    mem_copy_dict = collections.OrderedDict() # Dictionary that counts the number of copies

    for mem in mem_list:
        mem_name = mem.split("n")[0] # Memory name without the copy number

        # Count the number of copies
        if mem_name not in mem_copy_dict:
            mem_copy_dict[mem_name] = 1
        else:
            mem_copy_dict[mem_name] += 1

    return mem_copy_dict


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
        if "VMR" in module_name and module_name not in vmr_list:
            vmr_list.append(module_name)

    wires_file.close()

    return vmr_list

###################################
# Returns a string of the AllStub Inner memory mask

# Masks of which AllStubInner memories that are being used in this phi region; represente by a "1"
# First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
# NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)

def getAllStubInnerMaskString(mem_list):

    as_inner_list = ["OR", "OM", "OL", "BR/DR", "BM/DM", "BL/DL", "BF", "BE", "BD", "BC", "BB", "BA"]
    mask = "0b";

    # Loop over all the different AllStub Inner type
    for mem_type in as_inner_list:
        if any(mem_type in mem for mem in mem_list):
            mask += "1"
        elif "/" in mem_type:
            if any(mem_type.split("/")[0] in mem for mem in mem_list) or any(mem_type.split("/")[1] in mem for mem in mem_list):
                mask += "1"
            else:
                mask += "0"
        else:
            mask += "0"

    return mask

###################################
# Returns the number of input memories for the Future Emulation

# Ignores the final character (A and B) in the memory names
# E.g. memory_A and memory_B are considered the same

def getNumFEInputs(mem_list):

    mem_list_fe = [m[:-1] for m in mem_list]

    return len(set(mem_list_fe))

##########################################
# Writes the VMRouterCM_parameters.h file

# Contains magic numbers for all VMRs specified.
# Make sure to add VMRs to download.sh and run it before running Vivado HLS.

def writeParameterFile(vmr_list, mem_dict, output_dir):

    parameter_file = open(output_dir + "/VMRouterCM_parameters.h", "w")

    # Write preamble
    parameter_file.write(
        "#ifndef TopFunctions_VMRouterCM_parameters_h\n"
        "#define TopFunctions_VMRouterCM_parameters_h\n"
        "\n"
        "// Hardcoded number of memories and masks from the wiring.\n"
        "// Generated by generate_VMRCM.py\n\n"
    )

    # Declare functions
    parameter_file.write(
        "// The functions that returns parameters and LUTs\n"
        "template<TF::layerDisk LayerDisk> const int* getPhiCorrTable();\n"
        "template<TF::layerDisk LayerDisk> const int* getMETable();\n"
        "template<TF::layerDisk LayerDisk> const int* getTETable();\n"
        "template<TF::layerDisk LayerDisk> constexpr regionType getInputType();\n"
        "template<TF::layerDisk LayerDisk> constexpr regionType getOutputType();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputs();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsDisk2S();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumASCopies();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumASInnerCopies();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumTEOCopies();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getAllStubInnerMask();\n"
        "// For Future Emulation\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsFE();\n"
        "template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsDisk2SFE();\n"
        "\n"
        "// VMPhiCorr LUTs\n"
    )

    # Write phi correction LUTs functions
    for i in range(num_layers):
        parameter_file.write(
            "template<> inline const int* getPhiCorrTable<TF::L" + str(i+1) + ">(){\n"
            "  static int lut[] = \n"
            "#if __has_include(\"../emData/VMRCM/tables/VMPhiCorrL" + str(i+1) + ".tab\")\n#  include \"../emData/VMRCM/tables/VMPhiCorrL" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n"
            "  return lut;\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> inline const int* getPhiCorrTable<TF::D" + str(i+1) + ">(){\n"
            "  return nullptr;\n"
            "}\n"
        )

    # Write ME Tables
    parameter_file.write("\n// ME Tables\n")
    for i in range(num_layers):
        parameter_file.write(
            "template<> inline const int* getMETable<TF::L" + str(i+1) + ">(){\n"
            "  static int lut[] =\n"
            "#if __has_include(\"../emData/VMRCM/tables/VMRME_L" + str(i+1) + ".tab\")\n#  include \"../emData/VMRCM/tables/VMRME_L" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> inline const int* getMETable<TF::D" + str(i+1) + ">(){\n"
            "  static int lut[] =\n"
            "#if __has_include(\"../emData/VMRCM/tables/VMRME_D" + str(i+1) + ".tab\")\n#  include \"../emData/VMRCM/tables/VMRME_D" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n"
            "}\n"
        )

    # Write TE Tables
    parameter_file.write("\n// TE Tables\n")
    for i in range(num_layers):
        parameter_file.write(
            "template<> inline const int* getTETable<TF::L" + str(i+1) + ">(){\n"
            "  return nullptr;\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> inline const int* getTETable<TF::D" + str(i+1) + ">(){\n"
            +("  static int lut[] =\n#if __has_include(\"../emData/VMRCM/tables/VMRTE_D" + str(i+1) + ".tab\")\n#  include \"../emData/VMRCM/tables/VMRTE_D" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_outer[i+num_layers] else "  return nullptr;\n")+
            "}\n"
        )

    # Write InputType functions
    parameter_file.write("\n// InputType\n")
    for i in range(num_layers):
        parameter_file.write(
            "template<> constexpr regionType getInputType<TF::L" + str(i+1) + ">(){\n"
            "  return " + ("BARRELPS" if i < 3 else "BARREL2S") + ";\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> constexpr regionType getInputType<TF::D" + str(i+1) + ">(){\n"
            "  return DISKPS;\n"
            "}\n"
        )

    # Write OutputType functions
    parameter_file.write("\n// OutputType\n")
    for i in range(num_layers):
        parameter_file.write(
            "template<> constexpr regionType getOutputType<TF::L" + str(i+1) + ">(){\n"
            "  return " + ("BARRELPS" if i < 3 else "BARREL2S") + ";\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> constexpr regionType getOutputType<TF::D" + str(i+1) + ">(){\n"
            "  return DISK;\n"
            "}\n"
        )

    # Write VMR specific functions
    for vmr in vmr_list:

        layer_disk_char = vmr.split("_")[1][0] # 'L' or 'D'
        layer_disk_num = int(vmr.split("_")[1][1])
        phi_region= vmr.split("PHI")[1]

        # Get the number of copies for the specified TE memory type
        mem_copy_dict = getDictOfCopies(mem_dict["VMSTE_" + vmr])
        max_copy_count = max(mem_copy_dict.values()) if mem_copy_dict else 0

        parameter_file.write(
            "\n////////////////\n// " + vmr + " //\n////////////////\n"
            "template<> constexpr int getNumInputs<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Number of input memories, EXCLUDING DISK2S\n"
            "  return " + str(len(mem_dict["IL_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumInputsDisk2S<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Number of DISK2S input memories\n"
            "  return " + str(len(mem_dict["IL_DISK2S_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumASCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Allstub memory\n"
            "  return " + str(len(mem_dict["AS_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumASInnerCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Allstub Inner memory\n"
            "  return " + str(len(mem_dict["ASI_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumTEOCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // TE Outer memories\n"
            "  return " + str(max_copy_count) + ";\n"
            "}\n"
            "template<> constexpr int getAllStubInnerMask<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){\n"
            "  return " + getAllStubInnerMaskString(mem_dict["ASI_"+vmr]) + ";\n"
            "}\n"
            "// For Future Emulation\n"
            "template<> constexpr int getNumInputsFE<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Number of input memories, EXCLUDING DISK2S\n"
            "  return " + str(getNumFEInputs(mem_dict["IL_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumInputsDisk2SFE<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::" + phi_region + ">(){ // Number of DISK2S input memories\n"
            "  return " + str(getNumFEInputs(mem_dict["IL_DISK2S_"+vmr])) + ";\n"
            "}\n"
        )

    # End parameter file
    parameter_file.write("\n#endif // TopFunctions_VMRouterCM_parameters_h\n")
    parameter_file.close()


#################################
# Writes the VMRouterCMTop.h file

def writeTopHeader(vmr, output_dir):

    # Get layer/disk number and phi region
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1
    phi_region = vmr.split("PHI")[1]

    # Top file name
    file_name = "VMRouterCMTop_" + vmr.split("_")[1]

    header_file = open(output_dir + "/" + file_name  + ".h", "w")

    # Write preamble
    header_file.write(
        "#ifndef TopFunctions_" + file_name + "_h\n" +\
        "#define TopFunctions_" + file_name + "_h\n" +\
        "\n"
        "#include \"VMRouterCM.h\"\n"
        "#include \"VMRouterCM_parameters.h\"\n"
        "\n"
        "// VMRouterCM Top Function\n"
        "// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).\n"
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
        "constexpr regionType inputType = getInputType<layerdisk>();\n"
        "constexpr regionType outputType = getOutputType<layerdisk>();\n"
        "// Number of inputs\n"
        "constexpr int numInputs = getNumInputs<layerdisk, phiRegion>(); // Number of input memories, EXCLUDING DISK2S\n"
        "constexpr int numInputsDisk2S = getNumInputsDisk2S<layerdisk, phiRegion>(); // Number of DISK2S input memories\n"
        "// Maximum number of memory \"copies\" for this Phi region\n"
        "constexpr int numASCopies = getNumASCopies<layerdisk, phiRegion>(); // Allstub memory\n"
        "constexpr int numASInnerCopies = getNumASInnerCopies<layerdisk, phiRegion>(); // Allstub Inner memory\n"
        "constexpr int numTEOCopies = getNumTEOCopies<layerdisk, phiRegion>(); // TE Outer memories, can be 0 when no TEOuter memories\n"
        "// Number of bits for the RZ bins \n"
        "constexpr int kNbitsrzbinME = kNbitsrzbin%s; // For the VMSME memories\n" % ("MELayer" if layer else "MEDisk") +\
        "\n\n"
    )

    # Write the top function
    header_file.write(
        "/////////////////////////////////////////////////////\n"
        "// VMRouterCM Top Function\n"
        "\n"
        "void %s(const BXType bx, BXType& bx_o,\n" % file_name +\
        "  // Input memories\n"
        "  const InputStubMemory<inputType> inputStubs[numInputs],\n"
        + ("  const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S],\n" if disk else "") +\
        "  // Output memories\n"
        "  AllStubMemory<outputType> memoriesAS[numASCopies],\n"
        + ("  AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies],\n" if has_allstub_inner[layerdisk] else "") +\
        "  VMStubMEMemoryCM<outputType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME" + (",\n" if has_vmste_outer[layerdisk] else "")
        + ("  VMStubTEOuterMemoryCM<outputType, kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[layerdisk]> memoriesTEO[numTEOCopies]\n" if has_vmste_outer[layerdisk] else "") +\
        "  );\n"
        "\n"
        "#endif // TopFunctions_%s_h\n" % file_name
    )

    header_file.close()


# Writes the VMRouterCMTop.cc file
def writeTopFile(vmr, num_inputs, num_inputs_disk2s, output_dir):

    # Get layer/disk number
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1

    # Top file name
    file_name = "VMRouterCMTop_" + vmr.split("_")[1]

    top_file = open(output_dir + "/" + file_name  + ".cc", "w")

    # Write the top function
    top_file.write(
        "#include \"" + file_name + ".h\"\n\n" +\
        "// VMRouterCM Top Function\n"
        "// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).\n"
        "\n"
        "void %s(\n" % file_name +\
        "  const BXType bx, BXType& bx_o,\n"
        "  // Input memories\n"
        "  const InputStubMemory<inputType> inputStubs[numInputs],\n"
        + ("  const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S],\n" if disk else "") +\
        "  // Output memories\n"
        "  AllStubMemory<outputType> memoriesAS[numASCopies],\n"
        + ("  AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies],\n" if has_allstub_inner[layerdisk] else "") +\
        "  VMStubMEMemoryCM<outputType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME" + (",\n" if has_vmste_outer[layerdisk] else "")
        + ("  VMStubTEOuterMemoryCM<outputType, kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[layerdisk]> memoriesTEO[numTEOCopies]\n" if has_vmste_outer[layerdisk] else "") +\
        "  ) {\n"
        "\n"
        "// Takes 2 clock cycles before one gets data, used at high frequencies\n"
    )

    # Write pragmas
    for i in range(num_inputs):
        top_file.write("#pragma HLS resource variable=inputStubs[%s].get_mem() latency=2\n" % str(i))
    for i in range(num_inputs_disk2s):
        top_file.write("#pragma HLS resource variable=inputStubsDisk2S[%s].get_mem() latency=2\n" % str(i))

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
        "  static const int* TETable = getTETable<layerdisk>();\n"
        "\n"
        "  // LUT with phi corrections to project the stub to the average radius in a layer.\n"
        "  // Only used by layers.\n"
        "  // Indexed using phi and bend bits\n"
        "  static const int* phiCorrTable = getPhiCorrTable<layerdisk>();\n"
        "\n"
        "  // Masks of which AllStubInner memories that are being used in this phi region; represented by a \"1\"\n"
        "  // First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap\n"
        "  // NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)\n"
        "  static const ap_uint<maskASIsize> maskASI = getAllStubInnerMask<layerdisk, phiRegion>();\n"
        "\n"
        "  /////////////////////////\n"
        "  // Main function\n"
        "\n"
        "  VMRouterCM<numInputs, numInputsDisk2S, numASCopies, numASInnerCopies, kLAYER, kDISK, inputType, outputType, kNbitsrzbinME, kNbitsrzbin, kNbitsphibin, numTEOCopies>(\n"
        "    bx, bx_o,\n"
        "    // LUTs\n"
        "    METable,\n"
        "    TETable,\n"
        "    phiCorrTable,\n"
        "    // Input memories\n"
        "    inputStubs,\n"
        + ("       inputStubsDisk2S,\n" if disk else "    nullptr,\n") +\
        "    // AllStub memories\n"
        "    memoriesAS,\n"
        "    maskASI,\n"
        + ("    memoriesASInner,\n" if has_allstub_inner[layerdisk] else "    nullptr,\n") +\
        "    // ME memories\n"
        "    memoryME,\n"
        "    // TEOuter memories\n"
        + ("    memoriesTEO\n" if has_vmste_outer[layerdisk] else "    nullptr\n") +\
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
Generates top function and parameter files for the VMRouterCM.
VMRouterCMTop*.h and VMRouterCMTop*.cc contain the top function for the units under test specified (default VMR_L2PHIA).
VMRouterCM_parameters.h contains the magic numbers for the specified units under test.

Examples:
python3 generate_VMRCM.py
python3 generate_VMRCM.py --uut VMR_L1PHIE VMR_L1PHID
python3 generate_VMRCM.py -a
""",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument("-a", "--all", default=False, action="store_true", help="Create files for all VMRouterCMs in a nonant.")
    parser.add_argument("--uut", default=["VMR_L2PHIA"], nargs="+", help="Unit Under Test (default = %(default)s)")
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

    # Dictionary of all memories sorted by type and Unit Under Test
    mem_dict = getDictOfMemories(args.wireconfig, vmr_list)

    # Loop over all Units Under Test
    for vmr in vmr_list:
        # Check that the Unit Under Test is a VMR
        if "VMR" not in vmr:
            raise IndexError("Unit under test has to be a VMR.")

        # Create and write the files
        writeTopHeader(vmr, args.outputdir)
        writeTopFile(vmr, len(mem_dict["IL_"+vmr]), len(mem_dict["IL_DISK2S_"+vmr]), args.outputdir)

    # Write parameters file
    writeParameterFile(vmr_list, mem_dict, args.outputdir)
