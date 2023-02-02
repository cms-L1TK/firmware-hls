#!/usr/bin/env python3

from __future__ import absolute_import, print_function
import re
import os
import argparse

# return number of memories filled by each IR
def getNmemsPerIR(wiresFiles='./LUTs/wires.dat'):
    dtcNames=[]
    lines=[]
    for line in open(wiresFiles,'r'):
        my_regex = 'output=> IR_'
        if re.search(my_regex, line, re.IGNORECASE):
            dtcNames.append(line.split()[0].split('DL_')[1])
        my_regex = 'input=> IR_'
        if re.search(my_regex, line, re.IGNORECASE):
            lines.append(line)
    lines =list(set(lines))
    dtcNames = list(set(dtcNames))
    nMemories = []
    for dtcName in dtcNames:
        irLines=[]
        for line in lines:
            if re.search(dtcName, line, re.IGNORECASE) and ("neg" in dtcName) == ("neg" in line):
                irLines.append(line)
        nMemories.append(len(irLines))
    dtcNames, nMemories = (list(t) for t in zip(*sorted(zip(dtcNames, nMemories))))
    return zip(dtcNames, nMemories)

# generate TopLevel declaration template
def createDefinitionsTemplate():
    fileName='DefinitionsTemplate.dat'
    with open(fileName,'w') as f:
        f.write("\n"
              "void InputRouterTop_IR_{LinkName}(\n"
              "    const BXType bx\n"
              "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
              "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
              "    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs \n"
              "    , BXType & bx_o // output bx  \n"
              "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}])"
              "\n{{\n"
              "     #pragma HLS interface mode=ap_fifo port=hInputStubs depth = 108\n"
              "     #pragma HLS interface mode=ap_vld register port = bx_o\n"
              "     InputRouter<cNMemories_IR_{LinkName}>( bx\n"
              "       , hLinkWord\n"
              "       , hPhBnWord\n"
              "       , hInputStubs\n"
              "       , bx_o\n"
              "       , hOutputStubs);\n"
              "}}\n"
              )
    return fileName

# generate TopLevel declaration template
def createDeclarationTemplate():
    fileName = 'DeclarationsTemplate.dat'
    with open(fileName,'w') as f:
        f.write("\n"
              "void InputRouterTop_IR_{LinkName}(\n"
              "    const BXType bx\n"
              "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
              "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
              "    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs \n"
              "    , BXType & bx_o // output bx  \n"
              "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}]"
              ");\n")
    return fileName

# generate TopLevel parameters template
def createParametersTemplate():
    fileName = 'ParametersTemplate.dat'
    with open(fileName,'w') as f:
        f.write("\n"
            "constexpr unsigned int cNMemories_IR_{LinkName} = {Noutputs};\n")
    return fileName

# generate all TopLevel parameters InputRouter_parameters.h
def createParameters(wiresFiles='./LUTs/wires.dat', outputDirectory='../TopFunctions/'):
    IRs = getNmemsPerIR(wiresFiles)
    templateName = createParametersTemplate()
    file = open(outputDirectory + '/InputRouter_parameters.h', 'w')
    file.write('#ifndef TopFunctions_InputRouter_parameters_h\n')
    file.write('#define TopFunctions_InputRouter_parameters_h\n')
    for dtcName, nMemories in IRs:
        d = {}
        d['LinkName'] = "DTC_" + dtcName
        d['Noutputs'] = str(nMemories)
        with open(templateName, 'r') as ftemp:
            templateString = ftemp.read()
        file.write(templateString.format(**d))
    file.write('#endif\n')
    file.close()
    os.remove(templateName)

# generate all TopLevel declarations InputRouterTop.cc
def createDeclarations(wiresFiles='./LUTs/wires.dat', outputDirectory='../TopFunctions/'):
    IRs = getNmemsPerIR(wiresFiles)
    templateName = createDeclarationTemplate()
    file = open(outputDirectory + '/InputRouterTop.h', 'w')
    file.write('#ifndef TopFunctions_InputRouterTop_h\n')
    file.write('#define TopFunctions_InputRouterTop_h\n')
    file.write('#include \"InputRouter.h\"\n')
    file.write('#include \"InputRouter_parameters.h\"\n')
    for dtcName, _ in IRs:
        d = {}
        d['LinkName'] = "DTC_" + dtcName
        with open(templateName, 'r') as ftemp:
            templateString = ftemp.read()
        file.write(templateString.format(**d))
    file.write('#endif\n')
    file.close()
    os.remove(templateName)

# generate all TopLevel definitions InputRouterTop.h
def createDefinitions(wiresFiles='./LUTs/wires.dat', outputDirectory='../TopFunctions/'):
    IRs = getNmemsPerIR(wiresFiles)
    templateName = createDefinitionsTemplate()
    file = open(outputDirectory + '/InputRouterTop.cc', 'w')
    file.write('#include \"InputRouterTop.h\"\n')
    for dtcName, _ in IRs:
        d = {}
        d['LinkName'] = "DTC_" + dtcName
        with open(templateName, 'r') as ftemp:
            templateString = ftemp.read()
        file.write(templateString.format(**d))
    file.close()
    os.remove(templateName)

parser = argparse.ArgumentParser(description="This script generates InputRouterTop.h, InputRouterTop.cc, and\
InputRouter_parameters.h in the TopFunctions/ directory.",
                                 epilog="")
parser.add_argument("-o", "--outputDirectory", metavar="DIR", default="../TopFunctions/", type=str, help="The directory in which to write the output files (default=%(default)s)")
parser.add_argument("-w", "--wiresFileName", metavar="WIRES_FILE", default="LUTs/wires.dat", type=str, help="Name and directory of the configuration file for wiring (default = %(default)s)")
arguments = parser.parse_args()

# create InputRouter_parameters.h :
# contains constants that define number of output memories per link
createParameters(arguments.wiresFileName, arguments.outputDirectory)
# create InputRouterTop.h
# declaration of top level function for each instance of the IR
createDeclarations(arguments.wiresFileName, arguments.outputDirectory)
# create InputRouterTop.cc
# definition of top level function for each instance of the IR
createDefinitions(arguments.wiresFileName, arguments.outputDirectory)
