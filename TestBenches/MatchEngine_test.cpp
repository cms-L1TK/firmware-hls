// ProjectionRouter test bench
#include "MatchEngine.h"
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


const int nevents = 100;  // number of events to run

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
  bool validvmproj = openDataFile(fin_vmproj,"ME/ME_L1PHIE20/VMProjections_VMPROJ_L1PHIE20_04.dat");
  if (not validvmproj) return -1;

  ifstream fin_vmstub;
  bool validvmstub = openDataFile(fin_vmstub,"ME/ME_L1PHIE20/VMStubs_VMSME_L1PHIE20n1_04.dat");
  if (not validvmstub) return -1;

  // open file(s) with reference results

  ifstream fin_candmatch;
  bool validcandmatch = openDataFile(fin_candmatch,"ME/ME_L1PHIE20/CandidateMatches_CM_L1PHIE20_04.dat");
  if (not validcandmatch) return -1;

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    writeMemFromFile<VMProjectionMemory<BARREL> >(inputvmprojs, fin_vmproj, ievt);
    writeMemFromFile<VMStubMEMemory<BARRELPS> >(inputvmstubs, fin_vmstub, ievt);

    //set bunch crossing
    BXType bx=ievt&0x7;

    // Unit Under Test
    MatchEngine<1>(bx,&inputvmstubs,&inputvmprojs,&outputcandmatches);

    // compare the computed outputs with the expected ones for the candidate 
    // matches
    err_count += compareMemWithFile<CandidateMatchMemory>(outputcandmatches, 
							  fin_candmatch, 
							  ievt,"CandidateMatch");
    

  }  // end of event loop
  
  // close files
  fin_vmstub.close();
  fin_vmproj.close();
  fin_candmatch.close();

  return err_count;

}
