#!/usr/bin/env python3

import sys, os, shutil, tempfile, zipfile

def getDanglingPorts():
  topFunction = ""
  danglingPorts = []
  with open("./.autopilot/db/autopilot.flow.log") as fin:
    for line in fin:
      if "set_directive_top" in line:
        topFunction = line.split()[2]
      if "is left dangling" not in line:
        continue
      portName = line.split()[4].split("/")[1][0:-1]

      # FIXME: A subset of the projin_nentries_* ports of the MPs are marked as
      # dangling, and it is unclear why these particular subsets would be
      # dangling. For now, they are left in the designs.
      if not portName.startswith("projin_nentries_"):
        danglingPorts.append(portName)

  return (topFunction, danglingPorts)

def trimVHDLFile(fileName):
  vhdFile = []
  inPortList = False
  currentLine = ""
  previousLine = ""
  isFirstLine = True
  currentHasDanglingPort = False
  with open(fileName) as fin:
    for line in fin:
      currentLine = line[0:-1]
      if inPortList and previousLine.startswith("end;"):
        inPortList = False

      currentHasDanglingPort = False
      for port in danglingPorts:
        if (" " + port + " ") in currentLine:
          currentHasDanglingPort = True
          break

      if inPortList and currentHasDanglingPort:
        nOpen = currentLine.count("(")
        nClose = currentLine.count(")")
        if nClose > nOpen:
          previousLine = previousLine[0:-1] + " );"

      if previousLine.startswith("port ("):
        inPortList = True

      if not currentHasDanglingPort:
        if not isFirstLine:
          vhdFile.append(previousLine)
        isFirstLine = False
        previousLine = currentLine
        previousHasDanglingPort = currentHasDanglingPort
  vhdFile.append(previousLine)

  with open(fileName, "w") as fout:
    for line in vhdFile:
      fout.write(line + "\n")

def trimVerilogFile(fileName):
  vFile = []
  inPortList = False
  currentLine = ""
  previousLine = ""
  isFirstLine = True
  currentHasDanglingPort = False
  with open(fileName) as fin:
    for line in fin:
      currentLine = line[0:-1]
      if inPortList and previousLine.startswith(");"):
        inPortList = False

      currentHasDanglingPort = False
      for port in danglingPorts:
        if (" " + port + " ") in currentLine \
        or (" " + port + ",") in currentLine \
        or (" " + port + ";") in currentLine:
          currentHasDanglingPort = True
          break

      if inPortList and currentHasDanglingPort:
        nComma = currentLine.count(",")
        if nComma == 0:
          previousLine = previousLine[0:-1]

      if previousLine.startswith("module "):
        inPortList = True

      if not currentHasDanglingPort:
        if not isFirstLine:
          vFile.append(previousLine)
        isFirstLine = False
        previousLine = currentLine
        previousHasDanglingPort = currentHasDanglingPort
  vFile.append(previousLine)

  with open(fileName, "w") as fout:
    for line in vFile:
      fout.write(line + "\n")

def trimXMLFile(fileName):
  xmlFile = []
  portTags = []
  isDanglingPort = False
  with open(fileName) as fin:
    for line in fin:
      if "<spirit:busInterface>" in line \
      or "<spirit:port>" in line:
        portTags.append(line[0:-1])
      elif "</spirit:busInterface>" in line \
        or "</spirit:port>" in line:
        portTags.append(line[0:-1])
        if not isDanglingPort:
          xmlFile.extend(portTags)
        portTags = []
        isDanglingPort = False
      elif len(portTags) > 0:
        portTags.append(line[0:-1])
        if not isDanglingPort:
          for port in danglingPorts:
            if (">" + port + "<") in line:
              isDanglingPort = True
              break
      else:
        xmlFile.append(line[0:-1])

  with open(fileName, "w") as fout:
    for line in xmlFile:
      fout.write(line + "\n")

def unpackZipFile(topFunction, zipFileName = "./impl/export.zip", dirName = "."):
  with zipfile.ZipFile(zipFileName) as zipFile:
    zipFile.extractall(path = dirName)
    contents = {"VHDL" : [], "Verilog" : [], "XML" : [], "Other" : []}
    for name in zipFile.namelist():
      if name.endswith("/" + topFunction + ".vhd"):
        contents["VHDL"].append(name)
      elif name.endswith("/" + topFunction + ".v"):
        contents["Verilog"].append(name)
      elif name.endswith(".xml"):
        contents["XML"].append(name)
      else:
        contents["Other"].append(name)

  return contents

def repackZipFile(contents, zipFileName = "./impl/export.zip", dirName = "."):
  with zipfile.ZipFile(zipFileName, "w") as zipFile:
    for fileType in contents:
      for fileName in contents[fileType]:
        zipFile.write(dirName + "/" + fileName, arcname = fileName)

if len(sys.argv) < 2:
  print("Usage: " + os.path.basename(sys.argv[0]) + " SOLUTION_DIR")
  sys.exit(1)
os.chdir(sys.argv[1])

(topFunction, danglingPorts) = getDanglingPorts()
with tempfile.TemporaryDirectory() as tmpDirName:
  contents = unpackZipFile(topFunction, dirName = tmpDirName)
  for f in contents["VHDL"]:
    trimVHDLFile(tmpDirName + "/" + f)
  for f in contents["Verilog"]:
    trimVerilogFile(tmpDirName + "/" + f)
  for f in contents["XML"]:
    trimXMLFile(tmpDirName + "/" + f)
  repackZipFile(contents, dirName = tmpDirName)

for name in os.listdir("./impl/ip"):
  if not name.endswith(".zip"):
    continue
  os.unlink("./impl/ip/" + name)
  shutil.copyfile("./impl/export.zip", "./impl/ip/" + name)

with zipfile.ZipFile("./impl/export.zip") as zipFile:
  zipFile.extractall(path = "./impl/ip")
