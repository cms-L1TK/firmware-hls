#!/usr/bin/env python

from __future__ import absolute_import, print_function
import re
import os

# return number of memories filled by each IR 
def getNmemsPerIR(wiresFiles='./LUTs/wires.dat') : 
  dtcNames=[]
  lines=[]
  for line in open(wiresFiles,'r') : 
    my_regex = 'output=> IR_'
    if re.search(my_regex, line, re.IGNORECASE):
      dtcNames.append(line.split()[0].split('DL_')[1])
    my_regex = 'input=> IR_'
    if re.search(my_regex, line, re.IGNORECASE):
      lines.append(line)
  lines =list(set(lines))
  dtcNames = list(set(dtcNames))
  nMemories = [] 
  for idx, dtcName in enumerate(dtcNames):
    irLines=[]
    for line in lines : 
      if re.search(dtcName, line, re.IGNORECASE) and ("neg" in dtcName) == ("neg" in line) : 
          irLines.append(line)
    print(dtcName, ' : ' , len(irLines))
    nMemories.append(len(irLines))
  return zip(dtcNames, nMemories)

# generate TopLevel declaration template 
def createDefinitionsTemplate() : 
  fileName='DefinitionsTemplate.dat'
  f = open(fileName,'w')
  f.write("\n"
        "void InputRouterTop_IR_{LinkName}(\n"
        "    const BXType bx\n"
        "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
        "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
        "    , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]//input stubs \n"
        "    , BXType & bx_o // output bx  \n"
        "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}])"
        "\n{{\n"
        "     #pragma HLS clock domain = slow_clock\n"
        "     #pragma HLS stream variable = hInputStubs depth = 1\n"
        "     #pragma HLS interface register port = bx_o\n"
        "     InputRouter<cNMemories_IR_{LinkName}>( bx\n"
        "       , hLinkWord\n"
        "       , hPhBnWord\n"
        "       , hInputStubs\n"
        "       , bx_o\n"
        "       , hOutputStubs);\n"
        "}}\n"
        )
  f.close()
  return fileName

# generate TopLevel declaration template 
def createDeclarationTemplate() : 
  fileName = 'DeclarationsTemplate.dat'
  f = open(fileName,'w')
  f.write("\n"
        "void InputRouterTop_IR_{LinkName}(\n"
        "    const BXType bx\n"
        "    , const ap_uint<kLINKMAPwidth> hLinkWord // input link LUT \n"
        "    , const ap_uint<kBINMAPwidth> hPhBnWord  // n phi bins LUT \n"
        "    , ap_uint<kNBits_DTC> hInputStubs[kMaxStubsFromLink]//input stubs \n"
        "    , BXType & bx_o // output bx  \n"
        "    , DTCStubMemory hOutputStubs[cNMemories_IR_{LinkName}]"
        ");\n")
  f.close()
  return fileName

# generate TopLevel parameters template 
def createParametersTemplate() : 
  fileName = 'ParametersTemplate.dat'
  f = open(fileName,'w')
  f.write("\n"
        "constexpr unsigned int cNMemories_IR_{LinkName} = {Noutputs};\n")
  f.close()
  return fileName

# generate all TopLevel parameters InputRouter_parameters.h
def createParameters(wiresFiles='./LUTs/wires.dat') : 
  IRs = getNmemsPerIR(wiresFiles)
  templateName = createParametersTemplate()
  file = open('../TrackletAlgorithm/InputRouter_parameters.h', 'w') 
  file.write('#ifndef TrackletAlgorithm_InputRouter_parameters_h\n')
  file.write('#define TrackletAlgorithm_InputRouter_parameters_h\n')
  for dtcName, nMemories in IRs : 
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
def createDeclarations(wiresFiles='./LUTs/wires.dat') : 
  IRs = getNmemsPerIR(wiresFiles)
  templateName = createDeclarationTemplate()
  file = open('../TrackletAlgorithm/InputRouterTop.h', 'w') 
  file.write('#ifndef TrackletAlgorithm_InputRouterTop_h\n')
  file.write('#define TrackletAlgorithm_InputRouterTop_h\n')
  file.write('#include \"InputRouter.h\"\n')
  file.write('#include \"InputRouter_parameters.h\"\n')
  for dtcName, nMemories in IRs : 
    d = {}
    d['LinkName'] = "DTC_" + dtcName
    with open(templateName, 'r') as ftemp:
      templateString = ftemp.read()
    file.write(templateString.format(**d))
  file.write('#endif\n')
  file.close()
  os.remove(templateName)

# generate all TopLevel definitions InputRouterTop.h 
def createDefinitions(wiresFiles='./LUTs/wires.dat') : 
  IRs = getNmemsPerIR(wiresFiles)
  templateName = createDefinitionsTemplate()
  file = open('../TrackletAlgorithm/InputRouterTop.cc', 'w') 
  file.write('#include \"InputRouterTop.h\"\n')
  for dtcName, nMemories in IRs : 
    d = {}
    d['LinkName'] = "DTC_" + dtcName
    with open(templateName, 'r') as ftemp:
      templateString = ftemp.read()
    file.write(templateString.format(**d))
  file.close()
  os.remove(templateName)

wiresFile = './LUTs/wires.dat'
# create InputRouter_parameters.h :
# contains constants that define number of output memories per link 
createParameters(wiresFile)
# create InputRouterTop.h 
# declaration of top level function for each instance of the IR 
createDeclarations(wiresFile)
# create InputRouterTop.cc
# definition of top level function for each instance of the IR 
createDefinitions(wiresFile)
