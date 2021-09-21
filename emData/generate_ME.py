#!/usr/bin/env python3

from __future__ import print_function
import argparse
import pprint
import re
import sys

def checkMemories(debug, vmsmeStubInMems, vmprojProjInMems, cmMatchoutMems):
    if debug:
        pprint.pprint(vmsmeStubInMems, depth=2, width=60)
        pprint.pprint(vmprojProjInMems, depth=2, width=60)
        pprint.pprint(cmMatchoutMems, depth=2, width=60)
        sys.exit(0)
    assert len(vmsmeStubInMems) == len(vmprojProjInMems) == len(cmMatchoutMems), "The length of the module lists are not the same for the VMSME, VMPROJ, and CM!"
    for meName in sorted(vmprojProjInMems.keys()):
        assert len(vmsmeStubInMems[meName]) == len(vmprojProjInMems[meName]) == len(cmMatchoutMems[meName]), "The length of the modules for %s are not the same for the VMSME, VMPROJ, and CM!" % (meName)

def getPrefixSpacing(funcName):
    spacing = len("void " + funcName + "(")
    prefix = ("\t" * (spacing // 4)) + (" " * (spacing % 4))
    return prefix

def parseWiresFile(wiresFileName):
    with open(wiresFileName) as wiresFile:
        vmsmeStubInMems = {}
        vmprojProjInMems = {}
        cmMatchoutMems = {}
        for line in wiresFile:
            line = line.rstrip()
            meName = re.sub(r".*ME_([L|D].(?:PHI).[0-9]{1,2}).*", r"ME_\1", line)
            memName = line.split()[0]
            if memName.startswith("VMSME_"):
                if meName not in vmsmeStubInMems:
                    vmsmeStubInMems[meName] = []
                vmsmeStubInMems[meName].append(memName)
            if memName.startswith("VMPROJ_"):
                if meName not in vmprojProjInMems:
                    vmprojProjInMems[meName] = []
                vmprojProjInMems[meName].append(memName)
            if memName.startswith("CM_"):
                if meName not in cmMatchoutMems:
                    cmMatchoutMems[meName] = []
                cmMatchoutMems[meName].append(memName)

    return (vmsmeStubInMems, vmprojProjInMems, cmMatchoutMems)

def writePreambles(topHeaderFile, topFile):
    topHeaderFile.write(
        "#ifndef TrackletAlgorithm_MatchEngineTop_h\n"
        "#define TrackletAlgorithm_MatchEngineTop_h\n"
        "\n"
        "#include \"MatchEngine.h\"\n"
        "\n"
    )
    topFile.write(
        "#include \"MatchEngineTop.h\"\n"
    )

def writeModuleToHeader(topHeaderFile, funcName, prefix, layerDisk):
    topHeaderFile.write(
        "void " + funcName + "(const BXType bx, BXType& bx_o,\n"
        + prefix + "const VMStubMEMemory<ModuleType<TF::" + layerDisk + ">(), NBitMemAddr<TF::" + layerDisk + ">(), NBitBin<TF::" + layerDisk + ">()>& inputStubData,\n"
        + prefix + "const VMProjectionMemory<ProjectionType<TF::" + layerDisk + ">()>& inputProjectionData,\n"
        + prefix + "CandidateMatchMemory& outputCandidateMatch);\n\n"
    )

def writeModuleToImplementation(topFile, funcName, prefix, layerDisk, label):
    topFile.write(
        "\nvoid " + funcName + "(const BXType bx, BXType& bx_o,\n"
        + prefix + "const VMStubMEMemory<ModuleType<TF::" + layerDisk + ">(), NBitMemAddr<TF::" + layerDisk + ">(), NBitBin<TF::" + layerDisk + ">()>& inputStubData,\n"
        + prefix + "const VMProjectionMemory<ProjectionType<TF::" + layerDisk + ">()>& inputProjectionData,\n"
        + prefix + "CandidateMatchMemory& outputCandidateMatch) {\n"
        "\n"
        "#ifdef  __VITIS_HLS__\n"
        "\t// For use with Vitis >=2020.1\n"
        "\t#pragma HLS LATENCY min=1 max=1\n"
        "\t#pragma HLS interface ap_memory port=inputStubData->get_mem() latency=2\n"
        "\t#pragma HLS interface ap_memory port=inputProjectionData->get_mem() latency=2\n"
        "#else\n"
        "\t#pragma HLS interface register port=bx_o\n"
        "\t#pragma HLS resource variable=inputStubData->get_mem() latency=2\n"
        "\t#pragma HLS resource variable=inputProjectionData->get_mem() latency=2\n"
        "#endif\n"
        "\n"
        "\t" + label + ": MatchEngine<TF::" + layerDisk + ">(bx, bx_o, inputStubData, inputProjectionData, outputCandidateMatch);\n"
        "}\n"
    )

def generateME(args = argparse.Namespace()):

    # Perform some basic checks on the arguments.
    if args.debug:
        print('Number of arguments:', len(sys.argv), 'arguments.')
        print('Argument List:', str(sys.argv))
        print("Argument", args)

    if args.layerDiskType == "disk" and 6 in args.iLayerDisk:
        print("WARNING: You have selected to only print top functions for the disks, but you have also selected a 6th disk layer."
              " Remember, there are only 5 disk. Don't worry, this is a filter and won't have a detrimental effect.")

    if args.grep is not None:
        args.grep.sort()
        print("Will select for the patterns:")
        print(*['\t' + s for s in args.grep], sep = "\n")

    if args.vgrep is not None:
        args.vgrep.sort()
        print("Will veto MEs with the patterns:")
        print(*['\t' + s for s in args.vgrep], sep = "\n")

    # First, parse the wires file and store the memory names associated with MEs in
    # dictionaries with the ME names as keys.
    # Returned as a tuple of three lists
    memoryTuple = parseWiresFile(args.wiresFileName)
    checkMemories(args.debug, *memoryTuple)
    _, vmprojProjInMems, _ = memoryTuple

    # Open the output files.
    with open(args.outputDirectory + "/MatchEngineTop.h", "w") as topHeaderFile, \
         open(args.outputDirectory + "/MatchEngineTop.cc", "w") as topFile:

        # Print out the preambles for the top files.
        writePreambles(topHeaderFile, topFile)

        # Calculate parameters and print out top function for each ME.
        skipped_me = []
        generatedLayerDisk = []
        for meName in sorted(vmprojProjInMems.keys()):
            if args.grep is not None and not any(re.search(pattern, meName) for pattern in args.grep):
                skipped_me.append(meName)
                continue
            if args.vgrep is not None and any(re.search(pattern, meName) for pattern in args.vgrep):
                skipped_me.append(meName)
                continue

            layerDisk = re.sub(r"ME_([L|D][0-9])(?:PHI).*", r"\1", meName)
            iME = re.sub(r"ME_[L|D][0-9]((?:PHI).[0-9]{1,2})", r"\1", meName)
            iLD = int(layerDisk[1:])
            funcName = "MatchEngineTop_" + layerDisk + (iME if not args.sparse else "")
            label = "ME_" + layerDisk + (iME if not args.sparse else "")


            # To save time, only generate one module per layer/disk
            if args.sparse and layerDisk in generatedLayerDisk:
                continue
            else:
                generatedLayerDisk.append(layerDisk)

            # Filter the top functions based on the arguments
            if args.layerDiskType == "layer" and layerDisk[0] == "D":
                continue
            elif args.layerDiskType == "disk" and layerDisk[0] == "L":
                continue

            if args.iLayerDisk is not None and len(args.iLayerDisk) > 0 and iLD not in args.iLayerDisk:
                continue

            # Print out prototype for top function for this ME.
            prefix = getPrefixSpacing(funcName)
            writeModuleToHeader(topHeaderFile, funcName, prefix, layerDisk)

            # Print out definition of top function for this ME.
            writeModuleToImplementation(topFile, funcName, prefix, layerDisk, label)

        # Print out endifs and close files.
        topHeaderFile.write(
            "#endif\n"
        )

    if args.verbose:
        print("Skipped the following MEs due to the grep/vgrep patterns:")
        print(*['\t' + me for me in skipped_me], sep = "\n")

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="This script generates MatchEngineTop.h and MatchEngineTop.cc \
in the TrackletAlgorithm/ directory. Currently supports all MEs in all layers/disks.",
                                     epilog="")
    parser.add_argument("-d", "--debug", action="store_true", help="Shows some extra information in order to debug this program (default=%(default)s)")
    parser.add_argument("-g", "--grep", default=None, type=str, nargs='+', help="Space separated list of patterns to select for (default = %(default)s)")
    parser.add_argument("-ild", "--iLayerDisk", choices=[1,2,3,4,5,6], nargs='+', type=int, help="Select the region for which to generate the top functions (default=%(default)s)")
    parser.add_argument("-ldt", "--layerDiskType", choices=["layer","disk","both"], default="both", help="Select the region for which to generate the top functions (default=%(default)s)")
    parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TrackletAlgorithm/", type=str, help="The directory in which to write the output files (default=%(default)s)")
    parser.add_argument("-s", "--sparse", action="store_true", help="Only generate one module per layer/disk (default=%(default)s)")
    parser.add_argument("-v", "--vgrep", default=None, type=str, nargs='+', help="Space separated list of patterns to ignore (default = %(default)s)")
    parser.add_argument("-V", "--verbose", action="store_true", help="Prints out extra information while running (default=%(default)s)")
    parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
    parser.add_argument("--version", action='version', version='%(prog)s v0.1b')
    arguments = parser.parse_args()

    generateME(arguments)
