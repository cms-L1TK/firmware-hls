#!/usr/bin/env python3

import sys, os

if len(sys.argv) < 4:
    print("Usage: " + os.path.basename(sys.argv[0]) + " TOP_CELLS PIPELINE_CELLS PIPELINE_NETS")
    sys.exit(1)

topCellsFileName = sys.argv[1]
pipelineCellsFileName = sys.argv[2]
pipelineNetsFileName = sys.argv[3]

topCells = []
pipelineCells = {}
pipelineNets = {}

with open(topCellsFileName) as fin:
    for line in fin:
        topCells.append(line.rstrip())
isFPGA2 = len([a for a in topCells if a.startswith("PC_")]) > 0

with open(pipelineCellsFileName) as fin:
    for line in fin:
        topCell = line.split("/")[0]
        slrNum = line.split("/")[1].split(".")[0][-2:-1]
        pipelineType = "_".join(line.split("/")[1].split(".")[-1].split("_")[1:]).rstrip()

        groupName = topCell + "_" + pipelineType + "_" + slrNum
        if groupName not in pipelineCells:
            pipelineCells[groupName] = []
        pipelineCells[groupName].append(line.rstrip())

with open(pipelineNetsFileName) as fin:
    for line in fin:
        topCell = line.split("/")[0]
        slrNum = line.split("/")[1].split(".")[0][-2:-1]
        pipelineType = "_".join(line.split("/")[1].split(".")[-1].split("_")[1:]).rstrip()

        groupName = topCell + "_" + pipelineType + "_" + slrNum
        if groupName not in pipelineNets:
            pipelineNets[groupName] = []
        pipelineNets[groupName].append(line.rstrip())

if isFPGA2:
    with open("floorplan.xdc", "w") as fout:
        fout.write("#### Put the entire SectorProcessor in SLR0 and SLR1 ####\n")
        fout.write("create_pblock SectorProcessor\n")
        fout.write("resize_pblock [get_pblocks SectorProcessor] -add {SLR0:SLR1}\n")
        for cell in topCells:
            fout.write("add_cells_to_pblock [get_pblocks SectorProcessor] [get_cells " + cell + "]\n")
        fout.write("#########################################################\n")
        fout.write("\n")

with open("soft_floorplan.xdc", "w") as fout:
    fout.write("#### Avoid splitting submodules in SectorProcessor across SLRs ####\n")
    for cell in topCells:
        if cell.startswith("LATCH_") or cell.endswith("_DELAY") or "_reg" in cell:
            continue
        fout.write("set_property USER_SLR_ASSIGNMENT " + cell + " [get_cells " + cell + "]\n")
    fout.write("###################################################################\n")
    fout.write("\n")

    fout.write("#### Avoid splitting pipeline modules across SLRs ####\n")
    for group in pipelineCells:
        fout.write("set_property USER_SLR_ASSIGNMENT " + group + " [get_cells {" + " ".join(pipelineCells[group]) + "}]\n")
    fout.write("######################################################\n")
    fout.write("\n")

    if len(pipelineNets) > 0:
        fout.write("#### Enable auto-pipelining for pipeline nets ####\n")
        for group in pipelineNets:
            fout.write("set_property AUTOPIPELINE_GROUP " + group + " [get_nets {" + " ".join(pipelineNets[group]) + "}]\n")
        fout.write("##################################################\n")
        fout.write("\n")
