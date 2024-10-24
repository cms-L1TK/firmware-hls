# firmware-hls : HLS implementation of the hybrid L1 track firmware

## Repo directory contents:

- IntegrationTests/ : HDL top files and simulations for chains of HLS modules and memories.
- TestBenches/ : Test bench code.
- TrackletAlgorithm/ : Algo source code.
- TrackQuality/ : BDT Track Quality specific source code.
- emData/ : .dat files with input/output test-bench data (corresponding to memory between algo steps) + .tab files of data for LUTs used internally by algos.
- project/ : .tcl scripts to create HLS project, compile & run code.

> Most of the following directions will reference Vivado HLS and the corresponding `vivado_hls` command. You may use Vitis HLS instead by replacing all of the `vivado_hls` commands with `vitis_hls`.

An HLS project can be generated by running tcl file with Vivado/Vitis HLS in firmware-hls/project/ directory. e.g. To do so for the ProjectionRouter:

        vivado_hls -f script_PR.tcl

This would create a project directory \<project> ("projrouter" in case of the above example). The project name is defined in the tcl script. To open the project in GUI:

        vivado_hls -p <project>

## Running chains (illustrated for IR to TB skinny chain)

1) `cd IntegrationTests/ReducedConfig/IRtoTB/script/`
2) `make -j $(nproc) Work` (makes HLS IP cores; run as many jobs as you have CPU cores).
3) `vivado -mode batch -source runSim.tcl` (runs Vivado simulation,
   which writes data output from chain to dataOut/*.txt).
4) `python ../../../common/script/CompareMemPrintsFW.py -p -s` (compares .txt files in emData and dataOut/ writing comparison to dataOut/*_cmp.txt. Uses Python 3.).
5) `make Work/Work.runs/synth_1` (runs synthesis, writes utilization & timing reports to current directory).
6) `make Work/Work.runs/impl_1` (runs implementation, writes utilization & timing reports to current directory). N.B. This step is optional, and not required for code validation.

## Format of emData/ files.

### .dat files (test bench input/output data)

These have test data corresponding to the contents of the memories between algo steps. Their data format is explained 
in https://twiki.cern.ch/twiki/bin/view/CMS/HybridDataFormat . 

e.g. AllStubs*.dat contains one row per stub: "stub_number stub_coords_(binary)[r|z|phi|...] ditto_but_in_hex"; StubPairs*.dat contains one row per stub pair "pair_number stub_index_in_allstubs_mem_(binary)[innerLayer|outerLayer] ditto_but_in_hex.

File naming convention: "L3" or "D5" indicate barrel or disk number; "PHIC" indicates 3rd course phi division given layer of nonant.

Some of the files are large, so not stored directly in git. These are automatically downloaded when any of the scripts in the project/ directory are executed within Vivado/Vitis HLS.

### .tab and .dat files 

These correspond to LUT used internally by the algo steps. The .tab file are in C++ and can be #include and compiled. The .dat files are a list of hex numbers which are easier to read in in hdl.

## Corresponding CMSSW L1 track emulation

### Full configuration with combined modules

The files that are downloaded by emData/download.sh were created by the CMSSSW L1 track emulation, with the the following recipe (adapted from the [L1TrackSoftware TWiki](https://twiki.cern.ch/twiki/bin/view/CMS/L1TrackSoftware)).

```bash
cmsrel CMSSW_13_3_0_pre2
cd CMSSW_13_3_0_pre2/src/
cmsenv
git cms-checkout-topic -u cms-L1TK:a2c799d8c30310fef875a722645c0b8bd120061e
```

A few configuration changes were made in order to output test vectors and lookup tables and adjust truncation. This required editing L1Trigger/TrackFindingTracklet/interface/Settings.h as follows:

```diff
--- a/L1Trigger/TrackFindingTracklet/interface/Settings.h
+++ b/L1Trigger/TrackFindingTracklet/interface/Settings.h
@@ -874,7 +874,7 @@ namespace trklet {
 
     //IR should be set to 108 to match the FW for the summer chain, but ultimately should be at 156
     std::unordered_map<std::string, unsigned int> maxstep_{
-        {"IR", 156},  //IR will run at a higher clock speed to handle
+        {"IR", 108},  //IR will run at a higher clock speed to handle
                       //input links running at 25 Gbits/s
         //Set to 108 to match firmware project 240 MHz clock
 
@@ -941,9 +941,9 @@ namespace trklet {
     bool warnNoDer_{false};  //If true will print out warnings about missing track fit derivatives
 
     //--- These used to create files needed by HLS code.
-    bool writeMem_{false};     //If true will print out content of memories (between algo steps) to files
-    bool writeTable_{false};   //If true will print out content of LUTs to files
-    bool writeConfig_{false};  //If true will print out the autogenerated configuration as files
+    bool writeMem_{true};     //If true will print out content of memories (between algo steps) to files
+    bool writeTable_{true};   //If true will print out content of LUTs to files
+    bool writeConfig_{true};  //If true will print out the autogenerated configuration as files
     std::string memPath_{"../data/MemPrints/"};  //path for writing memories
     std::string tablePath_{"../data/LUTs/"};     //path for writing LUTs
 
@@ -951,7 +951,7 @@ namespace trklet {
     bool writeVerilog_{false};      //Write out auto-generated Verilog mudules used by TCs
     bool writeHLS_{false};          //Write out auto-generated HLS mudules used by TCs
     bool writeInvTable_{false};     //Write out tables of drinv and invt in tracklet calculator for Verilog module
-    bool writeHLSInvTable_{false};  //Write out tables of drinv and invt in tracklet calculator for HLS module
+    bool writeHLSInvTable_{true};  //Write out tables of drinv and invt in tracklet calculator for HLS module
 
     unsigned int writememsect_{3};  //writemem only for this sector (note that the files will have _4 extension)
 
@@ -1027,7 +1027,7 @@ namespace trklet {
     bool inventStubs_{true};     // invent seeding stub coordinates based on tracklet traj
 
     // Use combined TP (TE+TC) and MP (PR+ME+MC) configuration (with prompt tracking)
-    bool combined_{false};
+    bool combined_{true};
     // N.B. To use combined modules with extended tracking, edit
     // Tracklet_cfi.py to refer to *_hourglassExtendedCombined.dat,
     // but leave combined_=false.
```

Then compilation was done with the usual command:

```bash
scram b -j8
```

The algorithm was set to HYBRID_NEWKF and the maximum number of events was set to 100 in L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py:

```diff
--- a/L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py
+++ b/L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py
@@ -20,7 +20,7 @@ GEOMETRY = "D88"
 # 'HYBRID_NEWKF' (baseline, 4par fit, with bit-accurate KF emulation),
 # 'HYBRID_REDUCED' to use the "Summer Chain" configuration with reduced inputs.
 # (Or legacy algos 'TMTT' or 'TRACKLET').
-L1TRKALGO = 'HYBRID'
+L1TRKALGO = 'HYBRID_NEWKF'
 
 WRITE_DATA = False
 
@@ -57,7 +57,7 @@ process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')
 # input and output
 ############################################################
 
-process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10))
+process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))
 
 #--- To use MCsamples scripts, defining functions get*data*() for easy MC access,
 #--- follow instructions in https://github.com/cms-L1TK/MCsamples
```

Finally, the emulation was run with:

```bash
cd L1Trigger/TrackFindingTracklet/test/
cmsRun L1TrackNtupleMaker_cfg.py
```

### Generation of LUTs and MemPrint files for the reduced combined module chain

The steps needed to generate the configurations files for the reduced combined module chains are explained below.

Step 1: Produce the reduced configuration

Copy over the wires.dat, memorymodules.dat, and processingmodules.dat from the full configuration for the reduced modules to the area where you are running the makeReducedConfig.py. I will assume that the names of these files are cm_wires.dat, cm_processingmodules.dat, and cm_memorymodules.dat.

We have three different reduced combined module configurations:

1) The "CM_Reduced" configuration which is a skinny chain with on TP. To generate the configuation files for this configuration run the command:

```bash
./makeReducedConfig.py -w cm_wires.dat -p cm_processingmodules.dat -m cm_memorymodules.dat -s C -o CM_Reduced_ -t TP --no-graph
```

2) The "CM_Reduced2" configuration which implementes all TP in L1L2 and all barrel MP is L3-L6. To generate this configuration run the command:

```bash
./makeReducedConfig.py -w cm_wires.dat -p cm_processingmodules.dat -m cm_memorymodules.dat -s All -o CM_Reduced2_ -t TP --no-graph
```

3) The "CM_Barrel" configuration which has all barrel TP and MP. To generate the configuation files for this configuration run the commands (removes all disk-related modules):

```bash
cat cm_memorymodules.dat | grep -v "D[1234]" > CM_Barrel_memorymodules.dat
cat cm_processingmodules.dat | grep -v "D[1234]" > CM_Barrel_processingmodules.dat
cat cm_wires.dat | grep -v "D[1234]" > CM_Barrel_wires.dat
```

This should produce the three files

 - CM_{Reduced,Reduced2,Barrel}_wires.dat
 - CM_{Reduced,Reduced2,Barrel}_memorymodules.dat
 - CM_{Reduced,Reduced2,Barrel}_processingmodules.dat

respectively for the different configurations.

Step 2: Run CMSSW to pruduce the test vectors

NOTE - This has been tested in CMSSW_12_6_0_pre5 with the code in the PR #220

Copy the three \*.dat files produced in Step 1 for the relevant configuration above to the 'data' directory where you run CMSSW (TrackletTrackFinding/data)

Assuming interface/Settings.h has already been modified as for the full configuration above, modify python/l1tTTTracksFromTrackletEmulation_cfi.py as follows:

```diff
--- a/L1Trigger/TrackFindingTracklet/python/l1tTTTracksFromTrackletEmulation_cfi.py
+++ b/L1Trigger/TrackFindingTracklet/python/l1tTTTracksFromTrackletEmulation_cfi.py
@@ -13,20 +13,20 @@ l1tTTTracksFromTrackletEmulation = cms.EDProducer("L1FPGATrackProducer",
                                                asciiFileName = cms.untracked.string(""),
                                                FailScenario = cms.untracked.int32(0),
                                                Extended = cms.bool(False),
-                                               Reduced = cms.bool(False),
+                                               Reduced = cms.bool(True),
                                                Hnpar = cms.uint32(4),
                                                # (if running on CRAB use "../../fitpattern.txt" etc instead)
                                                fitPatternFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/fitpattern.txt'),
-                                               memoryModulesFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/memorymodules_hourglassExtended.dat'),
-                                               processingModulesFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/processingmodules_hourglassExtended.dat'),
-                                               wiresFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/wires_hourglassExtended.dat'),
+                                               memoryModulesFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/CM_Barrel_memorymodules.dat'),
+                                               processingModulesFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/CM_Barrel_processingmodules.dat'),
+                                               wiresFile = cms.FileInPath('L1Trigger/TrackFindingTracklet/data/CM_Barrel_wires.dat'),
                                                # Quality Flag and Quality params
                                                TrackQuality = cms.bool(True),
                                                TrackQualityPSet = cms.PSet(TrackQualityParams),
                                                Fakefit = cms.bool(False), # True causes Tracklet reco to output TTTracks before DR & KF
                                                StoreTrackBuilderOutput = cms.bool(False), # if True EDProducts for TrackBuilder tracks and stubs will be filled
                                                RemovalType = cms.string("merge"), # Duplicate track removal
-                                               DoMultipleMatches = cms.bool(True) # Allow tracklet tracks multiple stubs per layer
+                                               DoMultipleMatches = cms.bool(False) # Allow tracklet tracks multiple stubs per layer
     )
 
 l1tTTTracksFromExtendedTrackletEmulation = l1tTTTracksFromTrackletEmulation.clone(
```

(and similar for CM_Reduced2 and CM_Barrel configurations)

If the code has already been compiled with scram, and test/L1TrackNtupleMaker_cfg.py has already been modified as for the full configuration above, then only one additional change is required before running with cmsRun:

```diff
--- a/L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py
+++ b/L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py
@@ -20,7 +20,7 @@ GEOMETRY = "D88"
 # 'HYBRID_NEWKF' (baseline, 4par fit, with bit-accurate KF emulation),
 # 'HYBRID_REDUCED' to use the "Summer Chain" configuration with reduced inputs.
 # (Or legacy algos 'TMTT' or 'TRACKLET').
-L1TRKALGO = 'HYBRID_NEWKF'
+L1TRKALGO = 'HYBRID'
 
 WRITE_DATA = False
 

```

After running (cmsRun L1TrackNtupleMaker_cfg.py) in the TrackFindingTracklet/test directory copy the configuration files:

 cp CM_Reduced_wires.dat LUTs/wires.dat
 cp CM_Reduced_memorymodules.dat LUTs/memorymodules.dat
 cp CM_Reduced_processingmodules.dat LUTs/processingmodules.dat

Then create the tarballs:

tar czf MemPrints_CM_Reduced_231205.tgz MemPrints
tar czf LUTs_CM_Reduced_231205.tgz LUTs

(and similar for CM_Reduced2 and CM_Barrel)

## Continuous Integration (CI) 

Purpose: Automatically run SW quality checks and build the HLS projects (csim, csynth, cosim, and export) for a PR to the master.

In order to keep the GitHub repository public we use GitHub Actions and GitLab CI/CD:

* GitHub Actions uses a public runner, the workflow is defined in .github/workflows/github_CI.yml
* GitHub Actions mirrors the repository to GitLab and runs GitLab CI/CD
* GitLab CI/CD uses a private runner (lnxfarm327.colorado.edu) and performs the SW quality checks and the HLS builds as defined in .gitlab-ci.yml
    - SW quality checks are based on clang-tidy (llvm-toolset-7.0) and are defined in .clang-tidy and .clang-format very similar to CMSSW
    - HLS builds are using Vivado HLS (or Vitis HLS) and are defined in the script files of the project folder
    - Results (logs and artifacts) of the SW quality checks and HLS builds can be found here https://gitlab.cern.ch/cms-l1tk/firmware-hls/pipelines
    - The default behavior blocks a stage (e.g. Hls-build) when a previous stage (e.g. Quality-check) failed 
* GitHub Actions pulls the GitLab CI/CD status and the pass/fail outcome

### Use CI for Personal Branch

* Add your branch name to the "on:" section of .github/workflows/GitLab_CI.yml 
    - In the "push:" subsection to trigger CI on each push, e.g. "branches: [feat_CI,<your_branch_name>]" and/or
    - in the "pull_request:" subsection to trigger CI on each PR, e.g. "branches: [master,<your_branch_name>]"

## EMP

This section details how to the track finder firmware can be integrated in the EMP framework and deployed on an Apollo board.

### Building EMP

In order to reduce the number of redundant locations for EMP build instructions (and thus to reduce out-of-date information), please find the most recent EMP build instructions on the [apollo site](https://apollo-lhc.gitlab.io/cornell-cm/Manual/TFFirmware/02-EMPTF/).

### Information for developers

Currently, the EMP build is created in multiple steps. First, one runs the fpga1, fpga2, or all rule in [this makefile](IntegrationTests/DualFPGA/firmware/Makefile), which in turns runs the makefiles in the `CombinedConfig_FPGA1` or `CombinedConfig_FPGA2` integration tests to download necessary LUTs/MemPrints, generate the pattern recognition VHDL wrapper, and compile the pattern recognition HLS modules. This is currently done with Vivado 2020 or earlier since the pattern recognition HLS is incompatible with Vitis, the successor to Vivado HLS.

Next, the project is generated using the ipbb tool. One points ipbb to one of the configuration files in [this directory](IntegrationTests/DualFPGA/firmware/cfg/), which ipbb uses to generate the project. This includes adding relevant source and constraint files, running any setup tcl scripts, and recursively calling other configuration files in other dependencies such as `emp-fwk` and the KalmanFilter fit, which is currently included as a submodule in this repository.
