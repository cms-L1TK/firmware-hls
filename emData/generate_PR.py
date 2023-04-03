#!/usr/bin/env python3
from __future__ import absolute_import, print_function

# Automatically generates ProjectionRouterTop.h, and ProjectionRouterTop.cc
import os
import re
import argparse

def getListOfModules(wiresFileName):
    with open(wiresFileName) as wiresFile:
        wiresInfo = wiresFile.read()
    modulesToBuild = list(set(re.findall(r"PR_L\w+",wiresInfo))) # FIXME ProjectionRouterTop currently won't compile if DISK modules are included
    # modulesToBuild = list(set(re.findall(r"PR_\w+",wiresInfo))) # Use this one once DISK is working for ProjectionRouter
    modulesToBuild.sort()
    return modulesToBuild

def getNTProjAndNVMProj(module, wiresFileName):
    with open(wiresFileName) as wiresFile:
        wiresInfo = wiresFile.read()
    TProjCount = wiresInfo.count(module + ".projin")
    VMProjCount = wiresInfo.count(module + ".vmprojout")
    return TProjCount, VMProjCount

def getTProjAndVMProjRegions(module):
    if any(psword in module for psword in ["L1","L2","L3"]): TProjRegion = "BARRELPS"
    elif any(psword in module for psword in ["L4","L5","L6"]): TProjRegion = "BARREL2S"
    else: TProjRegion = "DISK"

    if any(psword in module for psword in ["L1","L2","L3","L4","L5","L6"]): VMProjRegion = "BARREL"
    else: VMProjRegion = "DISK"

    return TProjRegion, VMProjRegion

def getLayerAndDisk(module):
    layer = 0
    disk = 0
    if module[3] == 'L': layer = module[4]
    elif module[3] == 'D': disk = module[4]
    return layer, disk

def writeHeaderModuleInstance(module):
    TProjRegion, VMProjRegion = getTProjAndVMProjRegions(module)
    strHeader = ""
    strHeader += "void ProjectionRouterTop_" + module[3:] + "(BXType bx,\n"
    strHeader += "                         const TrackletProjectionMemory<" + TProjRegion + ">*,\n"
    strHeader += "                         BXType&,\n"
    strHeader += "                         AllProjectionMemory<" + TProjRegion + ">&,\n"
    strHeader += "                         VMProjectionMemory<" + VMProjRegion + ">*);\n\n"
    return strHeader

def writeHeaderPreamble():
    strPreamble = ""
    strPreamble += "#ifndef TopFunctions_ProjectionRouterTop_h\n"
    strPreamble += "#define TopFunctions_ProjectionRouterTop_h\n\n"
    strPreamble += "#include \"ProjectionRouter.h\"\n\n"
    return strPreamble

def writeHeaderPostamble():
    strPostamble = ""
    strPostamble += "#endif\n"
    return strPostamble

def writeSourceModuleInstance(module, wiresFileName):
    TProjCount, VMProjCount = getNTProjAndNVMProj(module, wiresFileName)
    TProjRegion, VMProjRegion = getTProjAndVMProjRegions(module)
    layer, disk = getLayerAndDisk(module)
    strSource =  ""
    strSource += "void ProjectionRouterTop_" + module[3:] + "(BXType bx,\n"
    strSource += "                         const TrackletProjectionMemory<" + TProjRegion + "> projin[" + str(TProjCount) + "],\n"
    strSource += "                         BXType& bx_o,\n"
    strSource += "                         AllProjectionMemory<" + TProjRegion + ">& allprojout,\n"
    strSource += "                         VMProjectionMemory<" + VMProjRegion + "> vmprojout[" + str(VMProjCount) + "])\n"
    strSource += "{\n"
    strSource += "#pragma HLS inline off\n"
    strSource += "#pragma HLS interface mode=ap_vld register port=bx_o\n"
    for i in range(TProjCount):

    strSource += "  constexpr unsigned int nInMem = " + str(TProjCount) + ";\n"
    strSource += "  constexpr unsigned int nOutMem = " + str(VMProjCount) + ";\n"
    strSource += "  constexpr int layer = " + str(layer) + ";\n"
    strSource += "  constexpr int disk = " + str(disk) + ";\n"
    strSource += module + ": ProjectionRouter<" + TProjRegion + ", " + VMProjRegion + ", nInMem, nOutMem, layer, disk>\n"
    strSource += "    (bx, projin, bx_o, allprojout, vmprojout);\n"
    strSource += "}\n\n"
    return strSource

def writeSourcePreamble():
    strPreamble = ""
    strPreamble += "#include \"ProjectionRouterTop.h\"\n\n"
    return strPreamble

parser = argparse.ArgumentParser(description="This script generates ProjectionRouterTop.h and ProjectionRouterTop.cc in the\
TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

headerString = writeHeaderPreamble()
sourceString = writeSourcePreamble()

modulesToBuild = getListOfModules(arguments.wiresFileName)
for module in modulesToBuild:
    headerString += writeHeaderModuleInstance(module)
    sourceString += writeSourceModuleInstance(module, arguments.wiresFileName)

headerString += writeHeaderPostamble()

dirname = os.path.dirname(os.path.realpath('__file__'))
with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionRouterTop.h"), "w") as headerFile:
    headerFile.write(headerString)
with open(os.path.join(dirname, arguments.outputDirectory, "ProjectionRouterTop.cc"), "w") as sourceFile:
    sourceFile.write(sourceString)
