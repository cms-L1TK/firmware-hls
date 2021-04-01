// Test bench for VMRouter
#include "VMRouterTop.h"
//#include "VMRouterTop_D1PHIA.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"

using namespace std;

const int nEvents = 100;  //number of events to run

// VMRouter Test that works for all regions
// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).

// NOTE: to run a different phi region, change the following
//          - the included top function in VMRouter_test.cpp (if file name is changed)
//          - the top function and memory directory in script_VMR.tcl (if file name is changed)
//          - add the phi region in emData/download.sh, make sure to also run clean
//          - and the changes listed in VMRouterTop.cc/h


// Finds all memory names for the specified processing module found in the wiring file,
// and adds them to the fileNames array with the memory files directory, excluding the copies nX.
// The number of copies are kept track in the numCopiesArray.
// E.g. finds all memories that start with "VMSME_L1PHIE", such as "VMSME_L1PHIE17" etc.
// Returns false if wiring file isn't found.
template<int arraySize>
bool findFileNames(string fileDirStart, string wireFileName, string memID, string nameList[arraySize], int numCopiesArray[arraySize]) {

  ifstream wireFile; // Will contain the wiring file

  int nvmMemories = 0; // Number of memories found
  char delimeter = (memID.substr(0,2) == "IL") ? ' ' : 'n'; // Different delimeter if input or output memories

  bool valid = openDataFile(wireFile, wireFileName); // Open the wiring file

  // Check if the wiring file was opened properly.
  if (not valid) {
    cout << "Could not find wiring file." << endl;
    return false;
  }

  // Loop over all lines in the wiring file
  for (string inputLine; getline(wireFile, inputLine); ) {

    // If we find the memory we are looking for
    if (inputLine.find(memID) != string::npos) {

      string tmpMemoryDir = fileDirStart + "_" + inputLine.substr(0, inputLine.find(delimeter)); // The directory and the name of the memory (first part of the line)

      auto isInNameList = find(nameList, nameList+arraySize, tmpMemoryDir); // Check if tmpMemoryDir is in nameList

      // Add the start of the memory name to the list if we haven't added it before, otherwise increment the number of copies
      if (isInNameList == nameList+arraySize) {
        nameList[nvmMemories] = tmpMemoryDir;
        numCopiesArray[nvmMemories]++;
        nvmMemories++;
      } else {
        numCopiesArray[distance(nameList, isInNameList)]++;
      }
    }
  }
  return true;
}

// Decides sorting order of modules: PS first, 2S last
bool sortByModule(string lhs, string rhs) {
  if((lhs.find("PS") != string::npos) && (rhs.find("2S") != string::npos)) return true;
}

int main() {

  ////////////////////////////////////////////////////////////////
  // Get lists of the input/output memory directory and file names
  // I.e. the names of the test vector files

  string layerID = (kLAYER) ? "L" + to_string(kLAYER) + "PHI" + phiRegion : "D" + to_string(kDISK) + "PHI" + phiRegion; // Which layer/disk and phi region
  string fileEnding = (sector < 10) ? "_0" + to_string(sector) + ".dat" :  "_" + to_string(sector) + ".dat"; //All files ends with .dat. "_XX" specifies which sector

  // Uses wires_hourglass.dat wiring file
  string wireFileName = "wires_hourglass.dat"; // The wiring file name with directory
  string testDataDirectory = "VMR_" + layerID; // Directory for the test data

  char overlapPhiRegion[] = {'X', 'Y', 'Z', 'W', 'Q', 'R', 'S', 'T'}; // Special naming for the TE overlap memories, and outer memories in Disk 1
  char extraPhiRegion[] = {'I', 'J', 'K', 'L'}; // Special naming for the extra memories TEInner L2 and TEOuter L3.

  // Input file names
  string inputNameList[numInputs + numInputsDisk2S];
  int inputNumCopies[numInputs + numInputsDisk2S] = {0}; // Array containing the number of copies of each memory

  string inputDir = testDataDirectory + "/InputStubs"; // Directory of InputStubs, including the first part of the file name
  string inMemID = "IL_" + layerID; // Input memory ID for the specified phi region

  // Get the input file names and check that the wiring file can be opened properly
  if (not findFileNames<numInputs + numInputsDisk2S>(inputDir, wireFileName, inMemID, inputNameList, inputNumCopies)) return -1;

  // Sort the inputNameList such that the 2S modules come last
  sort(inputNameList, inputNameList + (numInputs + numInputsDisk2S), sortByModule);


  // Start of AllStub file names, excluding the copy number
  string allstubName = testDataDirectory + "/AllStubs_AS_" + layerID;


  // Start of MEStub file names, excluding the copy number, i.e. "n1" as they only have one copy
  string nameListME[nvmME];
  int numCopiesME[nvmME] = {0}; // Array containing the number of copies of each memory

  string meDir = testDataDirectory + "/VMStubs"; // Directory of ME stubs, including the first part of the file name
  string meMemID  =  "VMSME_" + layerID; // ME memory ID for the specified phi region

  findFileNames<nvmME>(meDir, wireFileName, meMemID, nameListME, numCopiesME);


  // Start of TEInnerStub file names, excluding the copy number "nX"
  string nameListTEI[nvmTEI];
  int numCopiesTEI[nvmTEI] = {0}; // Array containing the number of copies of each memory

  if (maxTEICopies > 1) {
    string teiDir = testDataDirectory + "/VMStubs"; // Directory of TE stubs, including the first part of the file name
    string teiMemID = (kLAYER != 2) ? "VMSTE_" + layerID : string("VMSTE_L2PHI") + extraPhiRegion[phiRegion - 'A']; // TE Inner memory ID for the specified phi region

    findFileNames<nvmTEI>(teiDir, wireFileName, teiMemID, nameListTEI, numCopiesTEI);
  }


  // Start of TEInnerStub Overlap file names, excluding the copy number
  string nameListOL[nvmOL];
  int numCopiesOL[nvmOL] = {0}; // Array containing the number of copies of each memory

  if (maxOLCopies > 1) {
    string olDir = testDataDirectory + "/VMStubs"; // Directory of TE stubs, including the first part of the file name
    string olMemID = "VMSTE_L" + to_string(kLAYER) + "PHI" + overlapPhiRegion[phiRegion - 'A']; // TE Inner memory ID for the specified phi region

    findFileNames<nvmOL>(olDir, wireFileName, olMemID, nameListOL, numCopiesOL);
  }


  // Start of TEOuterStub file names, excluding the copy number "nX"
  string nameListTEO[nvmTEO];
  int numCopiesTEO[nvmTEO] = {0}; // Array containing the number of copies of each memory

  if (maxTEOCopies > 1) {
    string teoDir = testDataDirectory + "/VMStubs"; // Directory of TE stubs, including the first part of the file name
    string teoMemID; // TE Outer memory ID for the specified phi region

    if (kDISK == 1) {
      teoMemID = string("VMSTE_D1PHI") + overlapPhiRegion[phiRegion - 'A'];
    }
    else if (kLAYER == 3) {
      teoMemID = string("VMSTE_L3PHI") + extraPhiRegion[phiRegion - 'A'];
    }
    else {
      teoMemID = "VMSTE_" + layerID;
    }

    findFileNames<nvmTEO>(teoDir, wireFileName, teoMemID, nameListTEO, numCopiesTEO);
  }


  ///////////////////////////
  // input memories
  static InputStubMemory<inputType> inputStub[numInputs];
  static InputStubMemory<DISK2S> inputStubDisk2S[numInputsDisk2S]; //Only used for Disks

  // output memories
  static AllStubMemory<outputType> memoriesAS[maxASCopies];
  // ME memories
  static VMStubMEMemory<outputType, nbitsbin> memoriesME[nvmME];
  // TE Inner memories, including copies
  static VMStubTEInnerMemory<outputType> memoriesTEI[nvmTEI][maxTEICopies];
  // TE Inner Overlap memories, including copies
  static VMStubTEInnerMemory<BARRELOL> memoriesOL[nvmOL][maxOLCopies];
  // TE Outer memories
  static VMStubTEOuterMemory<outputType> memoriesTEO[nvmTEO][maxTEOCopies];


  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_inputstub[numInputs + numInputsDisk2S];

  for (unsigned int i = 0; i < numInputs + numInputsDisk2S; i++) {
    bool valid = openDataFile(fin_inputstub[i], inputNameList[i] + fileEnding);
    if (not valid) return -1;
  }


  ///////////////////////////
  // open output files

  // AllStub
  ifstream fout_allstub[maxASCopies];

  for (unsigned int i = 0; i < maxASCopies; i++) {
    bool valid = openDataFile(fout_allstub[i], allstubName + "n" + to_string(i+1) + fileEnding);
    if (not valid) return -1;
  }

  // ME memories
  ifstream fout_vmstubme[nvmME];

  for (unsigned int i = 0; i < nvmME; i++) {
    bool valid =  openDataFile(fout_vmstubme[i], nameListME[i] + "n1" + fileEnding);
    if (not valid) return -1;
  }

  // TE Inner
	ifstream fout_vmstubtei[nvmTEI][maxTEICopies];

  if (maxTEICopies > 1) {
    for (unsigned int i = 0; i < nvmTEI; i++) {
      for (unsigned int j = 0; j < numCopiesTEI[i]; j++) {
        bool valid = openDataFile(fout_vmstubtei[i][j], nameListTEI[i] + "n" + to_string(j+1) + fileEnding);
        if (not valid) return -1;
      }
    }
  }

  // TE Inner Overlap
	ifstream fout_vmstubteol[nvmOL][maxOLCopies];

  if (maxOLCopies > 1) {
    for (unsigned int i = 0; i < nvmOL; i++) {
      for (unsigned int j = 0; j < numCopiesOL[i]; j++) {
        bool valid = openDataFile(fout_vmstubteol[i][j], nameListOL[i] + "n" + to_string(j+1) + fileEnding);
        if (not valid) return -1;
      }
    }
  }

  // TE Outer
  ifstream fout_vmstubteo[nvmTEO][maxTEOCopies];

  if (maxTEOCopies > 1) {
    for (unsigned int i = 0; i < nvmTEO; i++) {
      for (unsigned int j = 0; j < numCopiesTEO[i]; j++) {
        bool valid = openDataFile(fout_vmstubteo[i][j], nameListTEO[i] + "n" + to_string(j+1) + fileEnding);
        if (not valid) return -1;
      }
    }
  }

  // error count
  int err = 0;

  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nEvents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // clear output memories
    for (int i=0; i<maxASCopies; ++i) {
      memoriesAS[i].clear();
    }
    for (int i=0; i<nvmME; ++i) {
      memoriesME[i].clear();
    }
    for (int i=0; i<nvmTEI; ++i) {
      for (int j=0; j<maxTEICopies; j++) {
        memoriesTEI[i][j].clear();
      }
    }
    for (int i=0; i<nvmOL; ++i) {
      for (int j=0; j<maxOLCopies; j++) {
        memoriesOL[i][j].clear();
      }
    }
    for (int i=0; i<nvmTEO; ++i) {
      for (int j=0; j<maxTEOCopies; j++) {
        memoriesTEO[i][j].clear();
      }
    }

    // read event and write to memories
    for (unsigned int i = 0; i < numInputs + numInputsDisk2S; i++) {
      if (kLAYER) {
        writeMemFromFile<InputStubMemory<inputType>>(inputStub[i], fin_inputstub[i], ievt);
      } else {
        if (i < numInputs) {
          writeMemFromFile<InputStubMemory<inputType>>(inputStub[i], fin_inputstub[i], ievt);
        } else {
          writeMemFromFile<InputStubMemory<DISK2S>>(inputStubDisk2S[i - numInputs], fin_inputstub[i], ievt);
        }
      }
    }

    // bx - bunch crossing
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    VMRouterTop(bx, bx_out, inputStub
#if kDISK > 0
        , inputStubDisk2S
#endif
        , memoriesAS, memoriesME
#if kLAYER == 1 || kLAYER  == 2 || kLAYER == 3 || kLAYER == 5 || kDISK == 1 || kDISK == 3
        , memoriesTEI
#endif
#if kLAYER == 1 || kLAYER == 2
        , memoriesOL
#endif
#if kLAYER == 2 || kLAYER == 3 || kLAYER == 4 || kLAYER == 6 || kDISK == 1 || kDISK == 2 || kDISK == 4
        , memoriesTEO
#endif
      );

    // compare the computed outputs with the expected ones
    // add 1 to the error count per stub that is incorrect

    bool truncation = false;

    // AllStub
    for (unsigned int i = 0; i < maxASCopies; i++) {
      err += compareMemWithFile<AllStubMemory<outputType>>(memoriesAS[i], fout_allstub[i], ievt, "AllStub", truncation);
    }

    // ME Memories
    for (unsigned int i = 0; i < nvmME; i++) {
      err += compareBinnedMemWithFile<VMStubMEMemory<outputType, nbitsbin>>(memoriesME[i], fout_vmstubme[i], ievt, "VMStubME" + to_string(i), truncation);
    }

    // TE Inner Memories
    if (maxTEICopies > 1) {
      for (unsigned int i = 0; i < nvmTEI; i++) {
        for (unsigned int j = 0; j < numCopiesTEI[i]; j++) {
          err += compareMemWithFile<VMStubTEInnerMemory<outputType>>(memoriesTEI[i][j], fout_vmstubtei[i][j], ievt, "VMStubTEInner" + to_string(i) + "n" + to_string(j+1), truncation);
        }
      }
    }

    // TE Inner Overlap memories
    if (maxOLCopies > 1) {
      for (unsigned int i = 0; i < nvmOL; i++) {
        for (unsigned int j = 0; j < numCopiesOL[i]; j++) {
          err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(memoriesOL[i][j], fout_vmstubteol[i][j], ievt, "VMStubTEOverlap" + to_string(i) + "n" + to_string(j+1), truncation);
        }
      }
    }

    // TE Outer memories
    if (maxTEOCopies > 1) {
      for (unsigned int i = 0; i < nvmTEO; i++) {
        for (unsigned int j = 0; j < numCopiesTEO[i]; j++) {
          err += compareBinnedMemWithFile<VMStubTEOuterMemory<outputType>>(memoriesTEO[i][j], fout_vmstubteo[i][j], ievt, "VMStubTEOuter" + to_string(i) + "n" + to_string(j+1), truncation);
        }
      }
    }
  } // end of event loop

	cerr << "Exiting with return value " << err << endl;
	// This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
	if (err > 255) err = 255;
	return err;

}
