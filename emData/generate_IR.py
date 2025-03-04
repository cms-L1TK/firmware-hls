#!/usr/bin/env python3

from __future__ import absolute_import, print_function
import re
import os
import argparse

# return number of memories filled by each IR
def getNmemsPerIR(wiresfiles='./LUTs/wires.dat'):
    dtc_names=[]
    lines=[]
    for line in open(wiresfiles,'r'):
        my_regex = 'output=> IR_'
        if re.search(my_regex, line, re.IGNORECASE):
            dtc_names.append(line.split()[0].split('DL_')[1])
        my_regex = 'input=> IR_'
        if re.search(my_regex, line, re.IGNORECASE):
            lines.append(line)
    lines = list(set(lines))
    dtc_names = list(set(dtc_names))
    nmemories = []
    for dtc_name in dtc_names:
        irlines=[]
        for line in lines:
            if re.search(dtc_name, line, re.IGNORECASE) and ("neg" in dtc_name) == ("neg" in line):
                irlines.append(line)
        nmemories.append(len(irlines))
    dtc_names, nmemories = (list(t) for t in zip(*sorted(zip(dtc_names, nmemories))))
    return zip(dtc_names, nmemories)

# generate TopLevel declaration template
def createDefinitionsTemplate():
    file_name='DefinitionsTemplate.dat'
    with open(file_name,'w') as fout:
        fout.write("\n"
                   "void InputRouterTop_IR_{LinkName}(\n"
                   "    const BXType bx\n"
                   "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
                   "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
                   "    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs \n"
                   "    , BXType & bx_o // output bx  \n"
                   "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}])"
                   "\n{{\n"
                   "     #pragma HLS clock domain = slow_clock\n"
                   "     #pragma HLS stream variable = hInputStubs depth = 108\n"
                   "     #pragma HLS interface register port = bx_o\n"
                   "     InputRouter<cNMemories_IR_{LinkName}>( bx\n"
                   "       , hLinkWord\n"
                   "       , hPhBnWord\n"
                   "       , hInputStubs\n"
                   "       , bx_o\n"
                   "       , hOutputStubs);\n"
                   "}}\n"
              )
    return file_name

# generate TopLevel declaration template
def createDeclarationTemplate():
    file_name = 'DeclarationsTemplate.dat'
    with open(file_name,'w') as fout:
        fout.write("\n"
                   "void InputRouterTop_IR_{LinkName}(\n"
                   "    const BXType bx\n"
                   "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
                   "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
                   "    , ap_uint<kNBits_DTC> hInputStubs[kMaxProc]//input stubs \n"
                   "    , BXType & bx_o // output bx  \n"
                   "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}]"
                   ");\n")
    return file_name

# generate TopLevel parameters template
def createParametersTemplate():
    file_name = 'ParametersTemplate.dat'
    with open(file_name,'w') as fout:
        fout.write("\n"
                   "constexpr unsigned int cNMemories_IR_{LinkName} = {Noutputs};\n")
    return file_name

# generate all TopLevel parameters InputRouter_parameters.h
def createParameters(wiresfiles='./LUTs/wires.dat', output_directory='../TopFunctions/'):
    irs = getNmemsPerIR(wiresfiles)
    template_name = createParametersTemplate()
    with open(output_directory + '/InputRouter_parameters.h', 'w') as file:
        file.write('#ifndef TopFunctions_InputRouter_parameters_h\n')
        file.write('#define TopFunctions_InputRouter_parameters_h\n')
        for dtc_name, nmemories in irs:
            dtcs = {}
            dtcs['LinkName'] = "DTC_" + dtc_name
            dtcs['Noutputs'] = str(nmemories)
            with open(template_name, 'r') as ftemp:
                template_string = ftemp.read()
            file.write(template_string.format(**dtcs))
        file.write('#endif\n')
    os.remove(template_name)

# generate all TopLevel declarations InputRouterTop.cc
def createDeclarations(wiresfiles='./LUTs/wires.dat', output_directory='../TopFunctions/'):
    irs = getNmemsPerIR(wiresfiles)
    template_name = createDeclarationTemplate()
    with open(output_directory + '/InputRouterTop.h', 'w') as file:
        file.write('#ifndef TopFunctions_InputRouterTop_h\n')
        file.write('#define TopFunctions_InputRouterTop_h\n')
        file.write('#include \"InputRouter.h\"\n')
        file.write('#include \"InputRouter_parameters.h\"\n')
        for dtc_name, _ in irs:
            dtcs = {}
            dtcs['LinkName'] = "DTC_" + dtc_name
            with open(template_name, 'r') as ftemp:
                template_string = ftemp.read()
            file.write(template_string.format(**dtcs))
        file.write('#endif\n')
    os.remove(template_name)

# generate all TopLevel definitions InputRouterTop.h
def createDefinitions(wiresfiles='./LUTs/wires.dat', output_directory='../TopFunctions/'):
    irs = getNmemsPerIR(wiresfiles)
    template_name = createDefinitionsTemplate()
    with open(output_directory + '/InputRouterTop.cc', 'w') as file:
        file.write('#include \"InputRouterTop.h\"\n')
        for dtc_name, _ in irs:
            dtcs = {}
            dtcs['LinkName'] = "DTC_" + dtc_name
            with open(template_name, 'r') as ftemp:
                template_string = ftemp.read()
        file.write(template_string.format(**dtcs))
    os.remove(template_name)

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
