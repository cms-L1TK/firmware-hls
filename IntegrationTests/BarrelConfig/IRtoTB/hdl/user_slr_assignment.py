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
procMemDelays = {}
inLatch = False
procDones = {}
doneProcs = {}
for line in fin:
    if "for var in enum_" in line and "_delay_" not in line:
        inMem = True
        currentLoopName = line.split()[0]
        currentEnumName = line.split()[5]
    elif inMem:
        if "entity work" in line:
            currentMemName = line.split()[0]
        elif " doutb " in line:
            doutbName = line.split()[2].split("(")[0]
            memLoopNames[doutbName] = currentLoopName
            memEnumNames[doutbName] = currentEnumName
            memNames[doutbName] = currentMemName
        elif "end generate" in line:
            inMem = False

    elif "entity work" in line and "CreateStartSignal" not in line and "work.tf_" not in line:
        inProc = True
        currentProcName = line.split()[0]
        if currentProcName not in procMems:
            procMems[currentProcName] = []
            procMemDelays[currentProcName] = []
    elif inProc:
        if "_dout" in line and "_nent" not in line and "DL_" not in line and "bendinnertable" not in line and "bendoutertable" not in line:
            doutbName = line.split()[2].split("(")[0]
            enumVal = line.split()[2].split("(")[1].split(")")[0]
            memLoopName = memLoopNames[doutbName]
            memEnumName = memEnumNames[doutbName]
            memName = memNames[doutbName]
            enumIndex = enumVals[memEnumName].index(enumVal)
            cellName = memLoopName + "[" + str(enumIndex) + "]." + memName
            procMems[currentProcName].append(cellName)
        elif "ap_done" in line and "open" not in line:
            doneSignal = line.split()[2][:-1]
            procDones[currentProcName] = doneSignal
        elif "_din" in line and "TW_" not in line and "BW_" not in line and "TPAR_" not in line and "FM_" not in line:
            doutbName = line.split()[2].split("(")[0][:-3] + "dout"
            enumVal = line.split()[2].split("(")[1].split(")")[0]
            memLoopName = memLoopNames[doutbName][:-4] + "delay_loop"
            memEnumName = memEnumNames[doutbName]
            memName = memNames[doutbName]
            enumIndex = enumVals[memEnumName].index(enumVal)
            cellName = memLoopName + "[" + str(enumIndex) + "]." + memName
            procMemDelays[currentProcName].append(cellName)
        elif ");" in line:
            inProc = False

    elif "CreateStartSignal" in line and "_LATCH_0" not in line:
        inLatch = True
        currentProcName = line.split()[0]
    elif inLatch:
        if "done" in line:
            doneSignal = line.split()[2][:-1]
            if doneSignal not in doneProcs:
                doneProcs[doneSignal] = []
            doneProcs[doneSignal].append(currentProcName)
        elif ");" in line:
            inLatch = False
fin.close()

for proc in procMems:
    associatedLatch = " "
    if proc in procDones:
        doneSignal = procDones[proc]
        if doneSignal in doneProcs:
            associatedLatch += " ".join(doneProcs[procDones[proc]])
    procLatch = " " + proc + "_LATCH_0"
    memDelays = " "
    if len(procMemDelays[proc]) > 0:
        memDelays += " ".join(procMemDelays[proc])
    print("set_property USER_SLR_ASSIGNMENT " + proc + "_group [get_cells {" + proc + associatedLatch + procLatch + memDelays, end = "")
    for mem in procMems[proc]:
        memDelay = re.sub(r"_loop", r"_delay_loop_0", mem)
        print(" " + mem + " " + memDelay, end = "")
    print("}]")
