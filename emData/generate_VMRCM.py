#!/usr/bin/env python3

## python 2/3 inter-compatibility
from __future__ import absolute_import, print_function

# This script generates VMRouterCM_parameters.h, VMRouterCMTop.h, 
# and VMRouterCMTop.cc for the Combined Module VMR in the TopFunctions/ directory. 
# Supports all VMRs, but creates separate top function files each
# VMR specified. VMRouterCM_parameters.h contains magic numbers 
# for all "default" VMRs plus additonals VMR if specified.

import argparse
import collections

# Constants
num_layers = 6
num_disks = 5

# Number of bits for RZ bins, for the VMSME memories
nbits_me_layer = 3
nbits_me_disk = 4

# The VMRs specified in download.sh
default_vmr_list = ["VMR_L1PHIA", "VMR_L2PHIA", "VMR_L3PHIA" ,"VMR_L4PHIA", "VMR_L5PHIA", "VMR_L6PHIA", "VMR_D1PHIA", "VMR_D2PHIA", "VMR_D3PHIA", "VMR_D4PHIA", "VMR_D5PHIA"]

# Lists of which layer/disk has VMSTE memories
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


##########################################
# Writes the VMRouterCM_parameters.h file

# Contains magic numbers for all default VMRs specified in download.sh
# and the specified units under test if non-default. Make sure to add
# non-default VMRs to download.sh and run it before running Vivado HLS

def writeParameterFile(vmr_list, mem_dict, output_dir):

    parameter_file = open(output_dir + "/VMRouterCM_parameters.h", "w")

    # Write preamble
    parameter_file.write(
"""#ifndef TopFunctions_VMRouterCM_parameters_h
#define TopFunctions_VMRouterCM_parameters_h

// Hardcoded number of memories and masks from the wiring.
// Generated by generate_VMRCM.py
""")

    parameter_file.write("// Contains number for the following VMRs: " + " ".join(vmr for vmr in vmr_list) + "\n")

    # Declare functions
    parameter_file.write("""
// Enums used to get the correct parameters
enum class phiRegions : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G', H = 'H'};

// The functions that returns parameters and LUTs
template<TF::layerDisk LayerDisk> const int* getPhiCorrTable();
template<TF::layerDisk LayerDisk> const int* getMETable();
template<TF::layerDisk LayerDisk> const int* getTETable();
template<TF::layerDisk LayerDisk> constexpr int getMEBits();
template<TF::layerDisk LayerDisk> constexpr regionType getInputType();
template<TF::layerDisk LayerDisk> constexpr regionType getOutputType();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputs();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputsDisk2S();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumASCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumASInnerCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumTEOCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getAllStubInnerMask();

// VMPhiCorr LUTs
"""
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

    # Write kNbitsrzbinME
    parameter_file.write("\n// kNbitsrzbinME\n")
    for i in range(num_layers):
        parameter_file.write(
            "template<> constexpr int getMEBits<TF::L" + str(i+1) + ">(){\n"
            "  return " + str(nbits_me_layer) + ";\n"
            "}\n"
        )
    for i in range(num_disks):
        parameter_file.write(
            "template<> constexpr int getMEBits<TF::D" + str(i+1) + ">(){\n"
            "  return " + str(nbits_me_disk) + ";\n"
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
            "template<> constexpr int getNumInputs<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){ // Number of input memories, EXCLUDING DISK2S\n"
            "  return " + str(len(mem_dict["IL_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumInputsDisk2S<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){ // Number of DISK2S input memories\n"
            "  return " + str(len(mem_dict["IL_DISK2S_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumASCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){ // Allstub memory\n"
            "  return " + str(len(mem_dict["AS_"+vmr])) + ";\n"
            "}\n"
            "template<> constexpr int getNumASInnerCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){ // Allstub Inner memory\n"
            "  return " + str(len(mem_dict["ASI_"+vmr]) if mem_dict["ASI_"+vmr] else 1) + ";\n"
            "}\n"
            "template<> constexpr int getNumTEOCopies<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){ // TE Outer memories\n"
            "  return " + str(max_copy_count) + ";\n"
            "}\n"
            "template<> constexpr int getAllStubInnerMask<TF::" + layer_disk_char + str(layer_disk_num) + ", phiRegions::" + phi_region + ">(){\n"
            "  return " + getAllStubInnerMaskString(mem_dict["ASI_"+vmr]) + ";\n"
            "}\n"
        )

    # End parameter file
    parameter_file.write("\n#endif // TopFunctions_VMRouterCM_parameters_h\n")
    parameter_file.close()


#################################
# Writes the VMRouterCMTop.h file

def writeTopHeader(vmr_specific_name, vmr, output_dir):

    # Get layer/disk number and phi region
    layer = vmr.split("_")[1][1] if vmr.split("_")[1][0] == "L" else 0
    disk = 0 if layer else vmr.split("_")[1][1]
    phi_region= vmr.split("PHI")[1]

    # Top file name
    file_name = "VMRouterCMTop" + ("_" + vmr.split("_")[1] if vmr_specific_name else "")

    header_file = open(output_dir + "/" + file_name  + ".h", "w")

    # Write preamble
    header_file.write(
"#ifndef TopFunctions_" + file_name + "_h\n" +\
"#define TopFunctions_" + file_name + "_h\n" +\
"""
#include "VMRouterCM.h"
#include "VMRouterCM_parameters.h"

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

////////////////////////////////////////////
// Variables for that are specified with regards to the VMR region

"""
    )

    # Write the configuration
    header_file.write(
"#define kLAYER " + str(layer) + " // Which barrel layer number the data is coming from\n"
"#define kDISK " + str(disk) + " // Which disk number the data is coming from, 0 if not disk\n\n"

"constexpr phiRegions phiRegion = phiRegions::" + phi_region+ "; // Which AllStub/PhiRegion\n"
    )

    # Write the rest...
    header_file.write("""

///////////////////////////////////////////////
// Values that don't need manual changing

constexpr TF::layerDisk layerdisk = static_cast<TF::layerDisk>((kLAYER) ? kLAYER-1 : trklet::N_LAYER+kDISK-1);

constexpr regionType inputType = getInputType<layerdisk>();
constexpr regionType outputType = getOutputType<layerdisk>();

// Number of inputs
constexpr int numInputs = getNumInputs<layerdisk, phiRegion>(); // Number of input memories, EXCLUDING DISK2S
constexpr int numInputsDisk2S = getNumInputsDisk2S<layerdisk, phiRegion>(); // Number of DISK2S input memories

// Maximum number of memory "copies" for this Phi region
constexpr int numASCopies = getNumASCopies<layerdisk, phiRegion>(); // Allstub memory
constexpr int numASInnerCopies = getNumASInnerCopies<layerdisk, phiRegion>(); // Allstub Inner memory
constexpr int numTEOCopies = getNumTEOCopies<layerdisk, phiRegion>(); // TE Outer memories, can be 0 when no TEOuter memories

// Masks of which AllStubInner memories that are being used in this phi region; represented by a "1"
// First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
// NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)
static const ap_uint<maskASIsize> maskASI = getAllStubInnerMask<layerdisk, phiRegion>();

constexpr int kNbitsrzbinME = getMEBits<layerdisk>(); // Number of bits for the RZ bins, for the VMSME memories


/////////////////////////////////////////////////////
// VMRouterCM Top Function

void %s(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 || kDISK == 3
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType, kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[layerdisk]> memoriesTEO[numTEOCopies]
#endif
	);

#endif // TopFunctions_VMRouterCMTop_h
""" % file_name
    )

    header_file.close()


# Writes the VMRouterCMTop.cc file
def writeTopFile(vmr_specific_name, vmr, num_inputs, num_inputs_disk2s, output_dir):

    # Top file name
    file_name = "VMRouterCMTop" + ("_" + vmr.split("_")[1] if vmr_specific_name else "")

    top_file = open(output_dir + "/" + file_name  + ".cc", "w")

    # Write preamble
    top_file.write("#include \"" + file_name + ".h\"" +\
"""

// VMRouterCM Top Function
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

void %s(const BXType bx, BXType& bx_o
	// Input memories
	, const InputStubMemory<inputType> inputStubs[numInputs]
#if kDISK > 0
  , const InputStubMemory<DISK2S> inputStubsDisk2S[numInputsDisk2S]
#endif

	// Output memories
	, AllStubMemory<outputType> memoriesAS[numASCopies]
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
	, AllStubInnerMemory<outputType> memoriesASInner[numASInnerCopies]
#endif
	, VMStubMEMemoryCM<outputType, kNbitsrzbinME, kNbitsphibin, kNMatchEngines> *memoryME
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
	, VMStubTEOuterMemoryCM<outputType, kNbitsrzbin, kNbitsphibin, kNTEUnitsLayerDisk[layerdisk]> memoriesTEO[numTEOCopies]
#endif
	) {

// Takes 2 clock cycles before on gets data, used at high frequencies
""" % file_name
    )

    for i in range(num_inputs):
        top_file.write("#pragma HLS resource variable=inputStubs[" + str(i) + "].get_mem() latency=2\n")
    for i in range(num_inputs_disk2s):
        top_file.write("#pragma HLS resource variable=inputStubsDisk2S[" + str(i) + "].get_mem() latency=2\n")

    top_file.write("""
#pragma HLS interface register port=bx_o

	///////////////////////////
	// Open Lookup tables

	// LUT with the corrected r/z. It is corrected for the average r (z) of the barrel (disk).
	// Includes both coarse r/z position (bin), and finer region each r/z bin is divided into.
	// Indexed using r and z position bits
	static const int* METable = getMETable<layerdisk>();
	static const int* TETable = getTETable<layerdisk>();

	// LUT with phi corrections to project the stub to the average radius in a layer.
	// Only used by layers.
	// Indexed using phi and bend bits
	static const int* phiCorrTable = getPhiCorrTable<layerdisk>();


	/////////////////////////
	// Main function

	VMRouterCM<numInputs, numInputsDisk2S, numASCopies, numASInnerCopies, kLAYER, kDISK, inputType, outputType, kNbitsrzbinME, kNbitsrzbin, kNbitsphibin, numTEOCopies>
	(bx, bx_o, 

		// LUTs
		METable,
		TETable,
		phiCorrTable,

		// Input memories
		inputStubs, 
#if kDISK > 0
		inputStubsDisk2S,
#else
		nullptr,
#endif

		// AllStub memories
		memoriesAS, 
		maskASI, 
#if kLAYER == 1 || kLAYER == 2 || kLAYER == 3 || kLAYER ==  5 || kDISK == 1 || kDISK == 3
		memoriesASInner,
#else
		nullptr,
#endif

		// ME memories
		memoryME,

		// TEOuter memories
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
		memoriesTEO
#else
		nullptr
#endif
		);

	return;
}
"""
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
python3 generate_VMRCM.py --uut VMR_L1PHIE -o
python3 generate_VMRCM.py --uut VMR_L1PHIE VMR_L1PHID
python3 generate_VMRCM.py -a
""",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument("-a", "--all", default=False, action="store_true", help="Create files for all VMRouterCMs in a nonant.")
    parser.add_argument("-d", "--default", default=False, action="store_true", help="Create files for VMRs: " + " ".join(vmr for vmr in default_vmr_list) + "(default = %(default)s)")
    parser.add_argument("-O", "--overwrite", default=False, action="store_true", help="Overwrite the default VMRouterCMTop.h/cc files (instead of creating files e.g. VMRouterCMTop_L1PHIE.h/cc). Only works if a single VMR has been specified (default = %(default)s)")
    parser.add_argument("--uut", default=["VMR_L2PHIA"], nargs="+", help="Unit Under Test (default = %(default)s)")
    parser.add_argument("-o", "--outputdir", type=str, default="../TopFunctions/", help="The directory in which to write the output files (default=%(default)s)")
    parser.add_argument("-w", "--wireconfig", type=str, default="LUTsCM/wires.dat",
                        help="Name and directory of the configuration file for wiring (default = %(default)s)")

    args = parser.parse_args()

    # Include the VMR name in the names of VMRouterCMTop files
    if len(args.uut) > 1 or not args.overwrite or args.all:
        vmr_specific_name = True
    else:
        vmr_specific_name = False

    # Get a list of the Units Under Test
    if args.all:
        vmr_list = getAllVMRs(args.wireconfig)
    elif args.default:
        vmr_list = default_vmr_list.copy()
        # Add explicitly defined UUTs if any
        for vmr in args.uut:
            if vmr not in vmr_list: vmr_list.append(vmr)
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
        writeTopHeader(vmr_specific_name, vmr, args.outputdir)
        writeTopFile(vmr_specific_name, vmr, len(mem_dict["IL_"+vmr]), len(mem_dict["IL_DISK2S_"+vmr]), args.outputdir)

    # Write parameters file
    writeParameterFile(vmr_list, mem_dict, args.outputdir)
