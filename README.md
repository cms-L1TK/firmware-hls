# firmware-hls : HLS implementation of the hybrid L1 track firmware

## Repo directory contents:

- TrackletAlgorithm/ : Algo source code.
- project/ : .tcl scripts to create HLS project, compile & run code. 
- TestBenches/ : test bench code
- emData/ : .dat files with input/output test-bench data (corresponding to memory between algo steps) + .tab files of data for LUTs used internally by algos.

An HLS project can be generated by running tcl file with Vivado HLS in firmware-hls/project/ directory. e.g. To do so for the ProjectionRouter:

        vivado_hls -f script_PR.tcl

This would create a project directory \<project> ("projrouter" in case of the above example). The project name is defined in the tcl script. To open the project in GUI:

        vivado_hls -p <project>

## Format of emData/ files.

### .dat files (test bench input/output data)

These have test data corresponding to the contents of the memories between algo steps. Their data format is explained 
in https://twiki.cern.ch/twiki/bin/view/CMS/HybridDataFormat . 

e.g. AllStubs*.dat contains one row per stub: "stub_number stub_coords_(binary)[r|z|phi|...] ditto_but_in_hex"; StubPairs*.dat contains one row per stub pair "pair_number stub_index_in_allstubs_mem_(binary)[innerLayer|outerLayer] ditto_but_in_hex.

File naming convention: "L3" or "D5" indicate barrel or disk number; "PHIC" indicates 3rd course phi division given layer of nonant.

Some of the files are large, so not stored directly in git. These are automatically downloaded when any of the scripts in the project/ directory are executed within Vivado HLS.

### .tab files 

These correspond to LUT used internally by the algo steps.

## Corresponding C++ emulation

The C++ emulation was used to create the files that are downloaded by emData/download.sh. The version used to create these files can be obtained with the following recipe:

```bash
cmsrel CMSSW_11_1_0_pre8
cd CMSSW_11_1_0_pre8/src/
cmsenv 
git cms-checkout-topic -u cms-L1TK:L1TK-dev-11_1_0_pre8
git clone https://github.com/cms-data/L1Trigger-TrackFindingTracklet.git L1Trigger/TrackFindingTracklet/data
cd L1Trigger/TrackFindingTracklet/data/
mkdir -p LUTs \
  MemPrints/CleanTrack \
  MemPrints/FitTrack \
  MemPrints/InputStubs \
  MemPrints/Matches \
  MemPrints/StubPairs \
  MemPrints/Stubs \
  MemPrints/TrackletParameters \
  MemPrints/TrackletProjections \
  MemPrints/VMProjections \
  MemPrints/VMStubsME \
  MemPrints/VMStubsTE
cd -
```

A few changes need to be made in order to enable truncation, to output test vectors and lookup tables, and to disable multiple matches in the MatchCalculator. So open L1Trigger/TrackFindingTracklet/interface/Settings.h and change the parameters to match the following:

```c++
…
    //Offset to the maximum number of steps in each processing step. Set to 0 for standard
    //trunction. Set to large value, e.g. 10000 to remove truncation
    unsigned int maxstepoffset_{0};
…
    bool writeMem_{true};    //If true will print out content of memories to files
    bool writeTable_{true};  //If true will print out content of LUTs to files
…
    bool writeHLSInvTable_{true};  //Write out tables of drinv and invt in tracklet calculator for HLS module
…
    // When false, match calculator does not save multiple matches, even when doKF=true.
    // This is a temporary fix for compatibilty with HLS. We will need to implement multiple match
    // printing in emulator eventually, possibly after CMSSW-integration inspired rewrites
    // Use false when generating HLS files, use true when doing full hybrid tracking
    bool doMultipleMatches_{false};
…
```

Then build the release with the usual command:

```bash
scram b -j8
```

Finally, increase the maximum number of events in L1Trigger/TrackFindingTracklet/test/L1TrackNtupleMaker_cfg.py to 100:

```python
…
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))
…
```

and run the emulation:

```bash
cd L1Trigger/TrackFindingTracklet/test/
cmsRun L1TrackNtupleMaker_cfg.py
```

## Continuous Integration (CI) 

Purpose: Automatically run SW quality checks and build the HLS projects (csim, csynth, cosim, and export) for a PR to the master.

In order to keep the GitHub repository public we use GitHub Actions and GitLab CI/CD:

* GitHub Actions uses a public runner, the workflow is defined in .github/workflows/GitLab_CI.yml
* GitHub Actions mirrors the repository to GitLab and runs GitLab CI/CD
* GitLab CI/CD uses a private runner (lnxfarm327.colorado.edu) and performs the SW quality checks and the HLS builds as defined in .gitlab-ci.yml
    - SW quality checks are based on clang-tidy (llvm-toolset-7.0) and are defined in .clang-tidy and .clang-format very similar to CMSSW
    - HLS builds are using Vivado HLS (or Vitis HLS) and are defined in the script files of the project folder
    - Results (logs and artifacts) of the SW quality checks and HLS builds can be found here https://gitlab.cern.ch/rglein/firmware-hls_actions/pipelines 
    - The default behavior blocks a stage (e.g. Hls-build) when a previous stage (e.g. Quality-check) failed 
* GitHub Actions pulls the GitLab CI/CD status and the pass/fail outcome

### Use CI for Personal Branch

* Add your branch name to the "on:" section of .github/workflows/GitLab_CI.yml 
    - In the "push:" subsection to trigger CI on each push, e.g. "branches: [feat_CI,<your_branch_name>]" and/or
    - in the "pull_request:" subsection to trigger CI on each PR, e.g. "branches: [master,<your_branch_name>]"
