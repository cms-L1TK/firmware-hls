#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function

# This script generates VMRouter_parameters.h, VMRouterTop.h,
# and VMRouterTop.cc in the TopFunctions/ directory.
# Supports all VMRs, but creates separate top function files each VMR specified.
# VMRouter_parameters.h contains functions and magic numbers.

import argparse
import collections

# Constants
num_layers = 6
num_disks = 5

# Lists of which layer/disk has VMSTE memories
has_vmste_inner = [True, True, True, False, True, False, True, False, True, False, False]
has_vmste_overlap = [True, True, False, False, False, False, False, False, False, False, False]
has_vmste_outer = [False, True, True, True, False, True, True, True, False, True, False]

# Number of entries in bendcut table
bendcuttable_size = [8, 8, 8, 16, 16, 16, 8, 8, 8, 8, 8]


#############################################
# Returns a dictionary of memories

# One key for every memory type in each layer/disk
# Value is a list of all memory names for that key

def getDictOfMemories(wireconfig, vmr_list):

    # Dictionary of all the input and output memories
    mem_dict = {}

    # Open wiring file
    with open(wireconfig, "r") as wires_file:

        # Loop over each line in the wiring
        for line in wires_file:
            # Check if any of the VMRs exist in the line
            for vmr in vmr_list:
                if vmr in line:
                    mem_name = line.split()[0]
                    mem_type = mem_name.split("_")[0]
                    # Check if memory type is VMSTE or IL DISK2S
                    if "IL_D" in mem_name and "2S" in mem_name:
                        mem_type = mem_type + "_DISK2S_" + vmr
                    elif "TEI" in line:
                        phi_region = mem_name.split("PHI")[1][0]
                        if phi_region <= "L":
                            mem_type = mem_type + "I_" + vmr
                        else: # Overlap
                            mem_type = mem_type + "OL_" + vmr
                    elif "TEO" in line:
                        mem_type = mem_type + "O_" + vmr
                    else:
                        mem_type = mem_type + "_" + vmr
                    # Add memory and memory type to dictionary
                    if mem_type not in mem_dict:
                        mem_dict[mem_type] = [mem_name]
                    else:
                        mem_dict[mem_type].append(mem_name)
                    break

        # Loop over all memories and add an empty IL DISK2S and VMSTE memory lists if missing in dictionary
        for vmr in vmr_list:
            if "IL_DISK2S_" + vmr not in mem_dict:
                mem_dict["IL_DISK2S_" + vmr] = []
            if "VMSTEI_" + vmr not in mem_dict:
                mem_dict["VMSTEI_" + vmr] = []
            if "VMSTEOL_" + vmr not in mem_dict:
                mem_dict["VMSTEOL_" + vmr] = []
            if "VMSTEO_" + vmr not in mem_dict:
                mem_dict["VMSTEO_" + vmr] = []

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
# Returns a number corresponding to the memory masks

def getMask(mem_list):

    mask = 0

    for i in range(32): # 32 is the maximum number of ME/TE memories in a sector layer
        for mem in mem_list:
            mem_number = int(mem.split("PHI")[1].split("n")[0][1:])
            if (i == mem_number - 1):
                mask += 2**i
                break;

    return mask

###################################
# Returns a list of all VMRs in the given wiring

def getAllVMRs(wireconfig):

    vmr_list = []

    # Open wiring file
    with open(wireconfig, "r") as wires_file:

        # Loop over each line in the wiring
        for line in wires_file:
            module_name = line.split(" ")[-1].split(".")[0]
            # Add module name if not already in vmr_list
            if "VMR" in module_name and module_name not in vmr_list:
                vmr_list.append(module_name)

    return vmr_list


#########################################
# Bendcut Table Helper Function

# Helper function that returns a string for writing the bendcut table
# functions in VMRouter_parameters.h file.

def getBendCutTable(mem_region, layer_disk_char, layer_disk_num, phi_region, max_copy_count, mem_copy_dict, mem_list):

    table_string = "template<> inline const ap_uint<getBendCutTableSize<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">()>* getBendCut" + mem_region + "Table<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){\n" +\
                   "  const int bendCutTableSize = getBendCutTableSize<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">();\n"

    # Sort memory list
    mem_list.sort(key=lambda mem: int("".join([i for i in mem[:-2] if i.isdigit()]))) # Sort by number (excluding the "copy" number nX)
    mem_list.sort(key=lambda mem: mem[:mem.index('PHI')]) # Sort alphabetically

    # Create temporary bendcut tables
    mem_index, mem_list_index = 0, 0

    for key in mem_copy_dict:
        mem_index += 1
        table_string += "  // TE " + mem_region + " Memory " + str(mem_index) + "\n"
        # Loop over the maximum number of copies, if the memory has less copies than that, add tables of zeros
        for i in range(max_copy_count):
            table_string += "  ap_uint<1> tmpBendTable" + str(mem_index) + "n" + str(i+1) + "[bendCutTableSize] ="
            if i < mem_copy_dict[key]:
                table_string += "\n#if __has_include(\"../emData/VMR/tables/" + mem_list[mem_list_index] + "_vmbendcut.tab\")\n#  include \"../emData/VMR/tables/" + mem_list[mem_list_index] + "_vmbendcut.tab\"\n#else\n  {};\n#endif\n"
                mem_list_index += 1
            else:
                table_string += " {0};\n"

    # Combine temporary bendcut tables and return it
    table_string += "\n  // Combine all the temporary tables into one big table\n" +\
                    "  static ap_uint<bendCutTableSize> bendCutTable[] = {"
    for i in range(len(mem_copy_dict)):
        table_string += "\n    "
        for j in range(max_copy_count):
            table_string += "arrayToInt<bendCutTableSize>(tmpBendTable" + str(i+1) + "n" + str(j+1) + "), "

    table_string = table_string[:-2] # Remove the last comma and space
    table_string += "\n  };\n\n" +\
                    "  return bendCutTable;\n" +\
                    "}\n"
    return table_string


##########################################
# Writes the VMRouter_parameters.h file

# Contains magic numbers for all VMRs specified.
# Make sure to add VMRs to download.sh and run it before running Vivado HLS.

def writeParameterFile(vmr_list, mem_dict, output_dir):

    with open(output_dir + "/VMRouter_parameters.h", "w") as parameter_file:

        # Write preamble
        parameter_file.write(
            "#ifndef TopFunctions_VMRouter_parameters_h\n"
            "#define TopFunctions_VMRouter_parameters_h\n"
            "\n"
            "// Hardcoded number of memories and masks from the wiring.\n"
            "// Generated by generate_VMR.py\n\n"
        )

        # Declare functions
        parameter_file.write(
            "// The functions that returns the LUTs and parameters\n"
            "template<TF::layerDisk LayerDisk> const int* getPhiCorrTable();\n"
            "template<TF::layerDisk LayerDisk> const int* getRzBitsInnerTable();\n"
            "template<TF::layerDisk LayerDisk> const int* getRzBitsOverlapTable();\n"
            "template<TF::layerDisk LayerDisk> const int* getRzBitsOuterTable();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> const int* getFineBinTable();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int size> const ap_uint<size>* getBendCutInnerTable();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int size> const ap_uint<size>* getBendCutOverlapTable();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int size> const ap_uint<size>* getBendCutOuterTable();\n"
            "\n"
            "template<TF::layerDisk LayerDisk> constexpr regionType getInputType();\n"
            "template<TF::layerDisk LayerDisk> constexpr regionType getOutputType();\n"
            "\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumInputs();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumInputsDisk2S();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumASCopies();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumVMSTEICopies();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumVMSTEOLCopies();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getNumVMSTEOCopies();\n"
            "\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int MaskSize> const ap_uint<MaskSize> getMaskME();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int MaskSize> const ap_uint<MaskSize> getMaskTEI();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int MaskSize> const ap_uint<MaskSize> getMaskOL();\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi, int MaskSize> const ap_uint<MaskSize> getMaskTEO();\n"
            "\n"
            "template<TF::layerDisk LayerDisk, TF::phiRegions Phi> constexpr int getBendCutTableSize();\n"
            "\n\n"
            "// Help function that converts an array of 0s and 1s to an ap_uint\n"
            "template<int arraySize>\n"
            "inline ap_uint<arraySize> arrayToInt(ap_uint<1> array[arraySize]) {\n"
            "  ap_uint<arraySize> number;\n"
            "  for(int i = 0; i < arraySize; i++) {\n"
            "    #pragma HLS unroll\n"
            "    number[i] = array[i];\n"
            "  }\n"
            "  return number;\n"
            "}\n"
            "\n"
            "// VMPhiCorr LUTs\n"
        )

        # Write phi correction LUTs functions
        for i in range(num_layers):
            parameter_file.write(
                "template<> inline const int* getPhiCorrTable<TF::L" + str(i+1) + ">(){\n"
                "  static int lut[] = \n"
                "#if __has_include(\"../emData/VMR/tables/VMPhiCorrL" + str(i+1) + ".tab\")\n#  include \"../emData/VMR/tables/VMPhiCorrL" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n"
                "  return lut;\n"
                "}\n"
            )
        for i in range(num_disks):
            parameter_file.write(
                "template<> inline const int* getPhiCorrTable<TF::D" + str(i+1) + ">(){\n"
                "  return nullptr;\n"
                "}\n"
            )

        # Write VMTableInner
        parameter_file.write("\n// VMTableInner\n")
        for i in range(num_layers):
            parameter_file.write(
                "template<> inline const int* getRzBitsInnerTable<TF::L" + str(i+1) + ">(){\n"
                +("  static int lut[] =\n#if __has_include(\"../emData/VMR/tables/VMTableInnerL" + str(i+1) + "L" + str(i+2) + ".tab\")\n#  include \"../emData/VMR/tables/VMTableInnerL" + str(i+1) + "L" + str(i+2) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_inner[i] else "  return nullptr;\n")+
                "}\n"
            )
        for i in range(num_disks):
            parameter_file.write(
                "template<> inline const int* getRzBitsInnerTable<TF::D" + str(i+1) + ">(){\n"
                +("  static int lut[] =\n#if __has_include(\"../emData/VMR/tables/VMTableInnerD" + str(i+1) + "D" + str(i+2) + ".tab\")\n#  include \"../emData/VMR/tables/VMTableInnerD" + str(i+1) + "D" + str(i+2) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_inner[i+num_layers] else "  return nullptr;\n")+
                "}\n"
            )

        # Write VMRTableInner - Overlap
        parameter_file.write("\n// VMTableInner - Overlap\n")
        for i in range(num_layers):
            parameter_file.write(
                "template<> inline const int* getRzBitsOverlapTable<TF::L" + str(i+1) + ">(){\n"
                +("  static int lut[] =\n#if __has_include(\"../emData/VMR/tables/VMTableInnerL" + str(i+1) + "D1.tab\")\n#  include \"../emData/VMR/tables/VMTableInnerL" + str(i+1) + "D1.tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_overlap[i] else "  return nullptr;\n")+
                "}\n"
            )
        for i in range(num_disks):
            parameter_file.write(
                "template<> inline const int* getRzBitsOverlapTable<TF::D" + str(i+1) + ">(){\n"
                "  return nullptr;\n"
                "}\n"
            )

        # Write VMTableOuter
        parameter_file.write("\n// VMTableOuter\n")
        for i in range(num_layers):
            parameter_file.write(
                "template<> inline const int* getRzBitsOuterTable<TF::L" + str(i+1) + ">(){\n"
                +("  static int lut[] =\n#if __has_include(\"../emData/VMR/tables/VMTableOuterL" + str(i+1) + ".tab\")\n#  include \"../emData/VMR/tables/VMTableOuterL" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_outer[i] else "  return nullptr;\n")+
                "}\n"
            )
        for i in range(num_disks):
            parameter_file.write(
                "template<> inline const int* getRzBitsOuterTable<TF::D" + str(i+1) + ">(){\n"
                +("  static int lut[] =\n#if __has_include(\"../emData/VMR/tables/VMTableOuterD" + str(i+1) + ".tab\")\n#  include \"../emData/VMR/tables/VMTableOuterD" + str(i+1) + ".tab\"\n#else\n  {};\n#endif\n  return lut;\n" if has_vmste_outer[i+num_layers] else "  return nullptr;\n")+
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

            parameter_file.write(
                "\n////////////////\n// " + vmr + " //\n////////////////\n"
                "template<> constexpr int getNumInputs<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){ // Number of input memories, EXCLUDING DISK2S\n"
                "  return " + str(len(mem_dict["IL_"+vmr])) + ";\n"
                "}\n"
                "template<> constexpr int getNumInputsDisk2S<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){ // Number of DISK2S input memories\n"
                "  return " + str(len(mem_dict["IL_DISK2S_"+vmr])) + ";\n"
                "}\n"
                "template<> constexpr int getNumASCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){ // Allstub memory\n"
                "  return " + str(len(mem_dict["AS_"+vmr])) + ";\n"
                "}\n"
                "template<> constexpr int getBendCutTableSize<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){\n"
                "  return " + str(bendcuttable_size[layer_disk_num-1]) + ";\n"
                "}\n"
                "template<> inline const ap_uint<masksize> getMaskME<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ", masksize>(){\n"
                "  return " + (str(getMask(mem_dict["VMSME_" + vmr])) if ("VMSME_" + vmr in mem_dict) else "0") + ";\n"
                "}\n"
                )

            for te_mem_type in ["VMSTEI", "VMSTEOL", "VMSTEO"]:

                if te_mem_type == "VMSTEI":
                    te_mem_region = "Inner"
                    te_mem_short = "TEI"
                elif te_mem_type == "VMSTEOL":
                    te_mem_region = "Overlap"
                    te_mem_short = "OL"
                elif te_mem_type == "VMSTEO":
                    te_mem_region = "Outer"
                    te_mem_short = "TEO"

                # Get the number of copies for the specified TE memory type
                mem_copy_dict = getDictOfCopies(mem_dict[te_mem_type + "_" + vmr])
                max_copy_count = max(mem_copy_dict.values()) if mem_copy_dict else 1

                parameter_file.write(
                    "template<> constexpr int getNum" + te_mem_type + "Copies<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){ // TE" + te_mem_region + "memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.\n"
                    "  return " + str(max_copy_count) + ";\n"
                    "}\n"
                    "template<> inline const ap_uint<mask%ssize> getMask" % (te_mem_short if te_mem_short == "OL" else "") + te_mem_short + "<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ", mask%ssize>(){\n" % (te_mem_short if te_mem_short == "OL" else "") +\
                    "  return " + (str(getMask(mem_dict[te_mem_type + "_" + vmr])) if (te_mem_type + "_" + vmr in mem_dict) else "0") + ";\n"
                    "}\n"
                )

                # Bendcut tables
                if mem_dict[te_mem_type + "_" + vmr]:
                    parameter_file.write(getBendCutTable(te_mem_region, layer_disk_char, layer_disk_num, phi_region, max_copy_count, mem_copy_dict, mem_dict[te_mem_type + "_" + vmr]))
                else:
                    parameter_file.write(
                    "template<> inline const ap_uint<getBendCutTableSize<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">()>* getBendCut" + te_mem_region + "Table<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){\n"
                    "  return nullptr;\n"
                    "}\n"
                    )

            parameter_file.write(
                "template<> inline const int* getFineBinTable<TF::" + layer_disk_char + str(layer_disk_num) + ", TF::phiRegions::" + phi_region + ">(){\n"
                "  static int lut[] =\n"
                "#if __has_include(\"../emData/VMR/tables/" + vmr + "_finebin.tab\")\n#  include \"../emData/VMR/tables/" + vmr + "_finebin.tab\"\n#else\n  {};\n#endif\n"
                "  return lut;\n"
                "}\n"
            )

        # End parameter file
        parameter_file.write("\n#endif // TopFunctions_VMRouter_parameters_h\n")

#################################
# Writes the VMRouterTop.h file

def writeTopHeader(vmr, output_dir):

    # Get layer/disk number and phi region
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1
    phi_region= vmr.split("PHI")[1]

    # Top file name
    file_name = "VMRouterTop_" + vmr.split("_")[1]

    with open(output_dir + "/" + file_name  + ".h", "w") as header_file:

        # Write preamble
        header_file.write(
            "#ifndef TopFunctions_%s_h\n" %file_name +\
            "#define TopFunctions_%s_h\n" %file_name +\
            "\n"
            "#include \"VMRouter.h\"\n"
            "#include \"VMRouter_parameters.h\"\n"
            "\n"
            "// VMRouter Top Function\n"
            "// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).\n"
            "\n"
            "////////////////////////////////////////////\n"
            "// Variables for that are specified with regards to the VMR region\n"
            "// Some are used by the Test Bench\n"
            "\n"
        )

        # Write the configuration
        if layer:
            nvm_tei = "(1 << nbits_vmte[kLAYER-1])" if layer != 2 else "(1 << nbits_vmte_extra[kLAYER-1])"
            nvm_ol = "(1 << nbits_vmte_overlap[kLAYER-1])" if layer < 3 else "1"
            nvm_teo = "(1 << nbits_vmte[kLAYER-1])" if layer != 3 else "(1 << nbits_vmte_extra[kLAYER-1])"
        else:
            nvm_tei = "(1 << nbits_vmte[trklet::N_LAYER+kDISK-1])"
            nvm_ol = "1"
            nvm_teo = "(1 << nbits_vmte[trklet::N_LAYER+kDISK-1])"

        header_file.write(
            "#define kLAYER %s // Which barrel layer number the data is coming from\n" %str(layer) +\
            "#define kDISK %s // Which disk number the data is coming from, 0 if not disk\n\n" %str(disk) +\
            "constexpr TF::phiRegions phiRegion = TF::phiRegions::%s; // Which AllStub/PhiRegion\n" % phi_region +\
            "\n"
            "constexpr TF::layerDisk layerdisk = static_cast<TF::layerDisk>((kLAYER) ? kLAYER-1 : trklet::N_LAYER+kDISK-1);\n"
            "constexpr regionType inputType = getInputType<layerdisk>();\n"
            "constexpr regionType outputType = getOutputType<layerdisk>();\n"
            "// Number of inputs\n"
            "constexpr int numInputs = getNumInputs<layerdisk, phiRegion>(); // Number of input memories, EXCLUDING DISK2S\n"
            "constexpr int numInputsDisk2S = getNumInputsDisk2S<layerdisk, phiRegion>(); // Number of DISK2S input memories\n"
            "// Maximum number of memory \"copies\" for this Phi region\n"
            "constexpr int maxASCopies = getNumASCopies<layerdisk, phiRegion>(); // Allstub memory\n"
            "constexpr int maxTEICopies = getNumVMSTEICopies<layerdisk, phiRegion>(); // TE Inner memories\n"
            "constexpr int maxOLCopies = getNumVMSTEOLCopies<layerdisk, phiRegion>(); // TE Inner memories\n"
            "constexpr int maxTEOCopies = getNumVMSTEOCopies<layerdisk, phiRegion>(); // TE Outer memories\n"
            "// Number of VMs\n"
            "constexpr int nvmME = %s; // ME memories\n" % ("(1 << nbits_vmmeall[kLAYER-1])" if layer else "(1 << nbits_vmmeall[trklet::N_LAYER+kDISK-1])") +\
            "constexpr int nvmTEI = %s; // TE Inner memories\n" % nvm_tei +\
            "constexpr int nvmOL = %s; // TE Inner Overlap memories, can't use 0 when we don't have any OL memories\n" % nvm_ol +\
            "constexpr int nvmTEO = %s; // TE Outer memories\n" % nvm_teo +\
            "\n"
            "// Number of bits used to address the stubs\n"
            "constexpr int kNBits_MemAddrME = kNBits_MemAddr%s;\n" % ("" if layer else " + 1") +\
            "// Number of bits for the RZ bins \n"
            "constexpr int kNbitsrzbinME = kNbitsrzbin%s; // For the VMSME memories\n" % ("MELayer" if layer else "MEDisk") +\
            "// Number of entries in each bendcut table\n"
            "constexpr int bendCutTableSize = getBendCutTableSize<layerdisk, phiRegion>();\n"
            "\n"
        )

        # Write the top function
        header_file.write(
            "/////////////////////////////////////////////////////\n"
            "// VMRouter Top Function\n"
            "\n"
            "void %s(const BXType bx, BXType& bx_o,\n" % file_name +\
            "  // Input memories\n"
            "  const InputStubMemory<inputType> inputStubs[numInputs],\n"
            + ("  const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S],\n" if disk else "") +\
            "  // Output memories\n"
            "  AllStubMemory<outputType> memoriesAS[maxASCopies],\n"
            "  VMStubMEMemory<outputType, kNBits_MemAddrME, kNbitsrzbinME> memoriesME[nvmME]" + ("\n" if disk == 5 else ",\n")
            + ("  VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies]" + (",\n" if has_vmste_overlap[layerdisk] or has_vmste_outer[layerdisk] else "") if has_vmste_inner[layerdisk] else "")
            + ("  VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies]" + (",\n" if has_vmste_outer[layerdisk] else "") if has_vmste_overlap[layerdisk] else "")
            + ("  VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies]\n" if has_vmste_outer[layerdisk] else "") +\
            "  );\n"
            "\n"
            "#endif // TopFunctions_%s_h\n" % file_name
            )

# Writes the VMRouterTop.cc file
def writeTopFile(vmr, num_inputs, num_inputs_disk2s, output_dir):

    # Get layer/disk number
    layer = int(vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0)
    disk = int(0 if layer else vmr.split("_")[1][1])
    layerdisk = layer-1 if layer else disk+num_layers-1

    # Top file name
    file_name = "VMRouterTop_" + vmr.split("_")[1]

    with open(output_dir + "/" + file_name  + ".cc", "w") as top_file:

        # Write the top function
        top_file.write(
            "#include \"%s.h\"\n" %file_name +\
            "\n"
            "// VMRouter Top Function\n"
            "// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).\n"
            "\n"
            "void %s(const BXType bx, BXType& bx_o,\n" % file_name +\
            "  // Input memories\n"
            "  const InputStubMemory<inputType> inputStubs[numInputs],\n"
            + ("  const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S],\n" if disk else "") +\
            "  // Output memories\n"
            "  AllStubMemory<outputType> memoriesAS[maxASCopies],\n"
            "  VMStubMEMemory<outputType, kNBits_MemAddrME, kNbitsrzbinME> memoriesME[nvmME]" + ("\n" if disk == 5 else ",\n")
            + ("  VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies]" + (",\n" if has_vmste_overlap[layerdisk] or has_vmste_outer[layerdisk] else "") if has_vmste_inner[layerdisk] else "")
            + ("  VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies]" + (",\n" if has_vmste_outer[layerdisk] else "") if has_vmste_overlap[layerdisk] else "")
            + ("  VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies]\n" if has_vmste_outer[layerdisk] else "") +\
            ") {\n"
            "\n"
            "// Takes 2 clock cycles before on gets data, used at high frequencies\n"
        )

        for i in range(num_inputs):
            top_file.write("#pragma HLS resource variable=inputStubs[" + str(i) + "].get_mem() latency=2\n")
        for i in range(num_inputs_disk2s):
            top_file.write("#pragma HLS resource variable=inputStubsDisk2S[" + str(i) + "].get_mem() latency=2\n")

        top_file.write(
            "#pragma HLS interface register port=bx_o\n"
            "\n"
            "  ///////////////////////////\n"
            "  // Open Lookup tables\n"
            "\n"
            "  // LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).\n"
            "  // Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.\n"
            "  // Indexed using r and z position bits\n"
            "  static const int* fineBinTable = getFineBinTable<layerdisk, phiRegion>();\n"
            "\n"
            "  // LUT with phi corrections to project the stub to the average radius in a layer.\n"
            "  // Only used by layers.\n"
            "  // Indexed using phi and bend bits\n"
            "  static const int* phiCorrTable = getPhiCorrTable<layerdisk>();\n"
            "\n"
            "  // LUT with the Z/R bits for TE memories\n"
            "  // Contain information about where in z to look for valid stub pairs\n"
            "  // Indexed using z and r position bits\n"
            "  static const int* rzBitsInnerTable = getRzBitsInnerTable<layerdisk>();\n"
            "  static const int* rzBitsOverlapTable = getRzBitsOverlapTable<layerdisk>();\n"
            "  static const int* rzBitsOuterTable = getRzBitsOuterTable<layerdisk>();\n"
            "\n"
            "  // LUT with bend-cuts for the TE memories\n"
            "  // The cuts are different depending on the memory version (nX)\n"
            "  // Indexed using bend bits\n"
            "  // Note: use an array of zeros for \"missing\" memories in the first and last Phi Region\n"
            "  static const ap_uint<bendCutTableSize>* bendCutInnerTable = getBendCutInnerTable<layerdisk, phiRegion, bendCutTableSize>();\n"
            "  static const ap_uint<bendCutTableSize>* bendCutOverlapTable = getBendCutOverlapTable<layerdisk, phiRegion, bendCutTableSize>();\n"
            "  static const ap_uint<bendCutTableSize>* bendCutOuterTable = getBendCutOuterTable<layerdisk, phiRegion, bendCutTableSize>();\n"
            "\n"
            "  //////////////////////////////////\n"
            "  // Get memory masks\n"
            "  // Masks of which memories that are being used. The first memory is represented by the LSB\n"
            "  // and a \"1\" implies that the specified memory is used for this phi region\n"
            "  // Create \"nvm\" 1s, e.g. \"1111\", shift the mask until it corresponds to the correct phi region\n"
            "\n"
            "  static const ap_uint<masksize> maskME = getMaskME<layerdisk, phiRegion, masksize>(); // ME memories\n"
            "  static const ap_uint<masksize> maskTEI = getMaskTEI<layerdisk, phiRegion, masksize>(); // TE Inner memories, only used for odd layers/disk and layer 2\n"
            "  static const ap_uint<maskOLsize> maskOL = getMaskOL<layerdisk, phiRegion, maskOLsize>(); // TE Inner Overlap memories, only used for layer 1 and 2\n"
            "  static const ap_uint<masksize> maskTEO = getMaskTEO<layerdisk, phiRegion, masksize>(); // TE Outer memories, only for even layers/disks, and layer and disk 1\n"
            "\n"
            "  /////////////////////////\n"
            "  // Main function\n"
            "\n"
            "  VMRouter<inputType, outputType, kLAYER, kDISK, numInputs, numInputsDisk2S, maxASCopies, maxTEICopies, maxOLCopies, maxTEOCopies, kNBits_MemAddrME, kNbitsrzbinME, bendCutTableSize>\n"
            "    (bx, bx_o, fineBinTable, phiCorrTable,\n"
            "    rzBitsInnerTable, rzBitsOverlapTable, rzBitsOuterTable,\n"
            "    bendCutInnerTable, bendCutOverlapTable, bendCutOuterTable,\n"
            "    // Input memories\n"
            "    inputStubs,\n"
            "    " + ("inputStubsDisk2S," if disk else "nullptr,") +\
            "    // AllStub memories\n"
            "    memoriesAS,\n"
            "    // ME memories\n"
            "    maskME, memoriesME,\n"
            "    // TEInner memories\n"
            "    maskTEI, " + ("memoriesTEI,\n" if has_vmste_inner[layerdisk] else "nullptr,\n") +\
            "    // TEInner Overlap memories\n"
            "    maskOL, " + ("memoriesOL,\n" if has_vmste_overlap[layerdisk] else "nullptr,\n") +\
            "    // TEOuter memories\n"
            "    maskTEO, " + ("memoriesTEO\n" if has_vmste_outer[layerdisk] else "nullptr\n") +\
            "    );\n\n"
            "  return;\n"
            "}\n"
        )

###############################
# Main execution

if __name__ == "__main__":

    parser = argparse.ArgumentParser(
        description = """
Generates top function and parameter files for the VMRouter.
VMRouterTop*.h and VMRouterTop*.cc contain the top function for the units under test specified (default VMR_L2PHIA).
VMRouter_parameters.h contains the magic numbers for the specified units under test.

Examples:
python3 generate_VMR.py
python3 generate_VMR.py --uut VMR_L1PHIE VMR_L1PHID
python3 generate_VMR.py -a
""",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument("-a", "--all", default=False, action="store_true", help="Create files for all VMRouters in a nonant.")
    parser.add_argument("--uut", default=["VMR_L2PHIA"], nargs="+", help="Unit Under Test (default = %(default)s)")
    parser.add_argument("-o", "--outputdir", type=str, default="../TopFunctions/", help="The directory in which to write the output files (default=%(default)s)")
    parser.add_argument("-w", "--wireconfig", type=str, default="LUTs/wires.dat",
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
