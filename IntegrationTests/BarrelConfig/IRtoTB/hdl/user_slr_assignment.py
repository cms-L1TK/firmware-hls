#!/usr/bin/env python3

import sys, re

if len(sys.argv) < 3:
    print("Usage: " + sys.argv[0] + " MEM_UTIL SECTOR_PROCESSOR")
    sys.exit(1)

memUtilFileName = sys.argv[1]
sectorProcessorFileName = sys.argv[2]

fin = open(memUtilFileName)
enumVals = {}
for line in fin:
    if "type enum" not in line:
        continue

    enumName = line.split()[1]
    enumVals[enumName] = re.split(r"[(,)]", line)[1:-1]
fin.close()

fin = open(sectorProcessorFileName)
memLoopNames = {}
memEnumNames = {}
memNames = {}
inMem = False
currentLoopName = None
currentEnumName = None
currentMemName = None
inProc = False
currentProcName = None
procMems = {}
for line in fin:
    if "for var in enum_" in line:
        inMem = True
        currentLoopName = line.split()[0]
        currentEnumName = line.split()[5]
    elif inMem:
        if "entity work" in line:
            currentMemName = line.split()[0]
        elif " wea " in line:
            weaName = line.split()[2].split("(")[0]
            memLoopNames[weaName] = currentLoopName
            memEnumNames[weaName] = currentEnumName
            memNames[weaName] = currentMemName
        elif "end generate" in line:
            inMem = False

    elif "entity work" in line and "CreateStartSignal" not in line and "work.tf_" not in line:
        inProc = True
        currentProcName = line.split()[0]
        if currentProcName not in procMems:
            procMems[currentProcName] = []
    elif inProc:
        if "_wea" in line:
            weaName = line.split()[2].split("(")[0]
            enumVal = line.split()[2].split("(")[1].split(")")[0]
            memLoopName = memLoopNames[weaName]
            memEnumName = memEnumNames[weaName]
            memName = memNames[weaName]
            enumIndex = enumVals[memEnumName].index(enumVal)
            cellName = memLoopName + "[" + str(enumIndex) + "]." + memName
            procMems[currentProcName].append(cellName)
        elif ");" in line:
            inProc = False
fin.close()

for proc in procMems:
    mems = procMems[proc]
    if len(mems) > 0:
        print("set_property USER_SLR_ASSIGNMENT " + proc + "_group [get_cells {" + proc + " " + " ".join(mems) + "}]")
