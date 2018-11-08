// ProjectionRouter test bench
#include "MatchEngine.h"
#include "CandidateMatchMemory.hh"
//#include "VMStubMemory.hh"
#include "VMProjectionMemory.hh"
#include "FileReadUtility.hh"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


const int nevents = 1;  // number of events to run

using namespace std;



int main() {
  // error counter
  int err_count = 0;

  // declare input memory arrays to be read from the emulation files
  VMProjectionMemory inputvmprojs;
  VMStubMemory inputvmstubs;
  //CandidateMatchMemory inputcandmatches;

  // declare output memory array to be filled by hls simulation
  CandidateMatchMemory outputcandmatches;

  // open input files
  //ifstream fin_vmstub("../../../../../emData/ME/ME_L1PHIE20/VMStubs_VMSME_L1PHIE20n1_04.dat");
  //ifstream fin_vmproj("../../../../../emData/ME/ME_L1PHIE20/VMProjections_VMPROJ_L1PHIE20_04.dat");
  //ifstream fin_candmatch("../../../../../emData/ME/ME_L1PHIE20/CandidateMatches_CM_L1PHIE20_04.dat");

  ifstream fin_vmproj;
  bool validvmproj = openDataFile(fin_vmproj,"../../../../../emData/ME/ME_L1PHIE20/VMProjections_VMPROJ_L1PHIE20_04.dat");
  if (not validvmproj) return -1;

  ifstream fin_vmstub;
  bool validvmstub = openDataFile(fin_vmstub,"../../../../../emData/ME/ME_L1PHIE20/VMStubs_VMSME_L1PHIE20n1_04.dat");
  if (not validvmstub) return -1;

  // open file(s) with reference results

  ifstream fout_candmatch;
  bool validcandmatch = openDataFile(fout_candmatch,"../../../../../emData/ME/ME_L1PHIE20/CandidateMatches_CM_L1PHIE20_04.dat");
  if (not validcandmatch) return -1;





  //assert(fin_vmstub.good());
  //assert(fin_vmproj.good());
  //assert(fin_candmatch.good());

  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    //read next event
    //readEventFromFile<VMProjectionMemory>(inputvmprojs, fin_vmproj,ievt);
    //readEventFromFile<VMStubMemory>(inputvmstubs, fin_vmstub,ievt);

    writeMemFromFile<VMProjectionMemory>(inputvmprojs, fin_vmproj, ievt);
    writeMemFromFile<VMStubMemory>(inputvmstubs, fin_vmstub, ievt);

    //readEventFromFile<CandidateMatchMemory>(inputcandmatches, fin_candmatch,ievt);

    //set bunch crossing
    ap_uint<3> bx=ievt&0x7;

    // Unit Under Test
    MatchEngine(
		bx,
		&inputvmstubs,
		&inputvmprojs,
		&outputcandmatches
		);


    // compare calculated outputs with those read from emulation printout
    //err_count+=inputcandmatches.compare(outputcandmatches,bx);

    // compare the computed outputs with the expected ones
    // AllProjection
    err_count += compareMemWithFile<CandidateMatchMemory>(outputcandmatches, fout_candmatch, 
							  ievt,"CandidateMatch");
    

  }  // end of event loop
  
  // close files
  fin_vmstub.close();
  fin_vmproj.close();
  fout_candmatch.close();

  return err_count;

}
