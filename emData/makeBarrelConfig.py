#!/usr/bin/env python

import sys

if len(sys.argv) < 2:
    print("Usage: " + sys.argv[0] + " WIRES_FILE")
    sys.exit(1)

wiresFileName = sys.argv[1]
fin = open(wiresFileName)
outputWires = []
processingModules = []
memoryModules = []
dtcs = {}
for line in fin:
    splitLine = line.split()
    assert(len(splitLine) == 4 or len(splitLine) == 5)

    memName = splitLine[0]

    inputModule = None
    outputModule = None
    if len(splitLine) == 5:
        inputModule = splitLine[2].split(".")[0]
        outputModule = splitLine[4].split(".")[0]
    else:
        if splitLine[-1] == "output=>":
            inputModule = splitLine[2].split(".")[0]
        else:
            outputModule = splitLine[-1].split(".")[0]

    dtc = None
    if inputModule is not None and inputModule.startswith("IR_"):
        assert(memName.startswith("IL_"))
        dtc = inputModule[3:]
        if dtc not in dtcs:
            dtcs[dtc] = 0
        else:
            dtcs[dtc] += 1

    if "_D" in line or "L1D1" in line or "L2D1" in line:
        if dtc is not None:
            dtcs[dtc] -= 1
        continue

    outputWires.append(line)
    memoryModules.append(memName)
    if inputModule is not None:
        processingModules.append(inputModule)
    if outputModule is not None:
        processingModules.append(outputModule)

fin.close()

fout = open("barrel_wires.dat", "w")
for line in outputWires:
    output = True
    for dtc in dtcs:
        if dtcs[dtc] > 0:
            continue
        if dtc in line:
            output = False
            break
    if not output:
        continue
    fout.write(line)
fout.close()

fout = open("barrel_processingmodules.dat", "w")
for p in sorted(set(processingModules)):
    output = True
    for dtc in dtcs:
        if dtcs[dtc] > 0:
            continue
        if dtc in p:
            output = False
            break
    if not output:
        continue
    if p.startswith("IR_"):
        fout.write("InputRouter: " + p + "\n")
    elif p.startswith("VMR_"):
        fout.write("VMRouter: " + p + "\n")
    elif p.startswith("TE_"):
        fout.write("TrackletEngine: " + p + "\n")
    elif p.startswith("TC_"):
        fout.write("TrackletCalculator: " + p + "\n")
    elif p.startswith("PR_"):
        fout.write("ProjectionRouter: " + p + "\n")
    elif p.startswith("ME_"):
        fout.write("MatchEngine: " + p + "\n")
    elif p.startswith("MC_"):
        fout.write("MatchCalculator: " + p + "\n")
    elif p.startswith("FT_"):
        fout.write("FitTrack: " + p + "\n")
    elif p.startswith("PD"):
        fout.write("PurgeDuplicate: " + p + "\n")
fout.close()

fout = open("barrel_memorymodules.dat", "w")
for m in sorted(set(memoryModules)):
    output = True
    for dtc in dtcs:
        if dtcs[dtc] > 0:
            continue
        if dtc in m:
            output = False
            break
    if not output:
        continue
    if m.startswith("AP_"):
        fout.write("AllProj: " + m + " [56]\n")
    elif m.startswith("AS_"):
        fout.write("AllStubs: " + m + " [42]\n")
    elif m.startswith("CM_"):
        fout.write("CandidateMatch: " + m + " [12]\n")
    elif m.startswith("CT_"):
        fout.write("CleanTrack: " + m + " [126]\n")
    elif m.startswith("DL_"):
        fout.write("DTCLink: " + m + " [36]\n")
    elif m.startswith("FM_"):
        fout.write("FullMatch: " + m + " [36]\n")
    elif m.startswith("IL_"):
        fout.write("InputLink: " + m + " [36]\n")
    elif m.startswith("SP_"):
        fout.write("StubPairs: " + m + " [12]\n")
    elif m.startswith("TF_"):
        fout.write("TrackFit: " + m + " [126]\n")
    elif m.startswith("TPAR_"):
        fout.write("TrackletParameters: " + m + " [56]\n")
    elif m.startswith("TPROJ_"):
        fout.write("TrackletProjections: " + m + " [54]\n")
    elif m.startswith("VMPROJ_"):
        fout.write("VMProjections: " + m + " [13]\n")
    elif m.startswith("VMSME_"):
        fout.write("VMStubsME: " + m + " [18]\n")
    elif m.startswith("VMSTE_"):
        fout.write("VMStubsTE: " + m + " [18]\n")
fout.close()
