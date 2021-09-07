#!/usr/bin/env python
from __future__ import absolute_import, print_function

# Automatically generates ProjectionRouterTop.h, and ProjectionRouterTop.cc
import sys, re, os

def getListOfModules(wiresFileName):
    wiresFile = open(wiresFileName)
    wiresInfo = wiresFile.read()
    wiresFile.close()
    modulesToBuild = list(set(re.findall(r"PR_L\w+",wiresInfo))) # FIXME ProjectionRouterTop currently won't compile if DISK modules are included
    # modulesToBuild = list(set(re.findall(r"PR_\w+",wiresInfo))) # Use this one once DISK is working for ProjectionRouter
    return modulesToBuild

def getNTProjAndNVMProj(module, wiresFileName):
    wiresFile = open(wiresFileName)
    wiresInfo = wiresFile.read()
    wiresFile.close()
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
    strPreamble += "#ifndef TrackletAlgorithm_ProjectionRouterTop_h\n"
    strPreamble += "#define TrackletAlgorithm_ProjectionRouterTop_h\n\n"
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
    strSource += "#pragma HLS interface register port=bx_o\n"
    for i in range(TProjCount):
        strSource += "#pragma HLS resource variable=projin[" + str(i) + "]->get_mem() latency=2\n"
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

if len(sys.argv) < 2:
    print("Usage: " + sys.argv[0] + " WIRES_FILE")
    sys.exit(1)

wiresFileName = sys.argv[1]
headerString = writeHeaderPreamble()
sourceString = writeSourcePreamble()

modulesToBuild = getListOfModules(wiresFileName)
for module in modulesToBuild:
    headerString += writeHeaderModuleInstance(module)
    sourceString += writeSourceModuleInstance(module, wiresFileName)

headerString += writeHeaderPostamble()

dirname = os.path.dirname(os.path.realpath('__file__'))
headerFile = open(os.path.join(dirname, "../TrackletAlgorithm/ProjectionRouterTop.h"), "w")
headerFile.write(headerString)
headerFile.close()
sourceFile = open(os.path.join(dirname, "../TrackletAlgorithm/ProjectionRouterTop.cc"), "w")
sourceFile.write(sourceString)
sourceFile.close()

