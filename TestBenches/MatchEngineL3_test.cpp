// ProjectionRouter test bench
#include "MatchEngineTopL3.h"
#include "CandidateMatchMemory.hh"
#include "VMProjectionMemory.hh"
#include "VMStubMEMemory.hh"
#include "FileReadUtility.hh"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


const int nevents = 10;  // number of events to run

using namespace std;



int main() {
  // error counter
  int err_count = 0;

  // declare input memory arrays to be read from the emulation files
  VMProjectionMemory<BARREL> inputvmprojs;
  VMStubMEMemory<BARRELPS> inputvmstubs;
  //CandidateMatchMemory inputcandmatches;

  // declare output memory array to be filled by hls simulation
  CandidateMatchMemory outputcandmatches;

  ifstream fin_vmproj;
  bool validvmproj = openDataFile(fin_vmproj,"ME/ME_L3PHIC20/VMProjections_VMPROJ_L3PHIC20_04.dat");
  if (not validvmproj) return -1;

  ifstream fin_vmstub;
  bool validvmstub = openDataFile(fin_vmstub,"ME/ME_L3PHIC20/VMStubs_VMSME_L3PHIC20n1_04.dat");
  if (not validvmstub) return -1;

  // open file(s) with reference results

  ifstream fin_candmatch;
  bool validcandmatch = openDataFile(fin_candmatch,"ME/ME_L3PHIC20/CandidateMatches_CM_L3PHIC20_04.dat");
  if (not validcandmatch) return -1;

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    writeMemFromFile<VMProjectionMemory<BARREL> >(inputvmprojs, fin_vmproj, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS> >(inputvmstubs, fin_vmstub, ievt);

    //set bunch crossing
    BXType bx=ievt;
    BXType bx_out;

    // Unit Under Test
    MatchEngineTopL3(bx,bx_out,&inputvmstubs,&inputvmprojs,&outputcandmatches);

    // compare the computed outputs with the expected ones for the candidate 
    // matches
    bool truncation = true;
    err_count += compareMemWithFile<CandidateMatchMemory>(outputcandmatches, 
							  fin_candmatch, 
							  ievt,"CandidateMatch",truncation);
    

  }  // end of event loop
  
  // close files
  fin_vmstub.close();
  fin_vmproj.close();
  fin_candmatch.close();

  return err_count;

}
