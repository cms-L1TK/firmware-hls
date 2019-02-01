// MatchCalculator test bench
#include "MC.h"
#include "AllStubMemory.hh"
#include "AllProjectionMemory.hh"
#include "CandidateMatchMemory.hh"
#include "FullMatchMemory.hh"
#include "FileReadUtility.hh"
#include "hls_math.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


const int nevents = 1; // number of events to run
bool truncation = false; // compare results to truncated emulation

using namespace std;



int main() {
  // error counter
  int err_count = 0;

  // declare input memory arrays to be read from the emulation files
  AllStubMemory        inputstub;
  AllProjectionMemory  inputproj;
  CandidateMatchMemory inputcandmatch1;
  CandidateMatchMemory inputcandmatch2;
  CandidateMatchMemory inputcandmatch3;
  CandidateMatchMemory inputcandmatch4;
  CandidateMatchMemory inputcandmatch5;
  CandidateMatchMemory inputcandmatch6;
  CandidateMatchMemory inputcandmatch7;
  CandidateMatchMemory inputcandmatch8;

  // declare output memory array to be filled by hls simulation
  FullMatchMemory      outputfullmatch_seed1;  
  FullMatchMemory      outputfullmatch_seed2;  

  // read in input files
  ifstream fin_as;
  bool validas = openDataFile(fin_as,"MC/MC_L3PHIC/AllStubs_AS_L3PHICn4_04.dat");
  if (not validas) return -1;              // exit if file not found

  ifstream fin_ap;
  bool validap = openDataFile(fin_ap,"MC/MC_L3PHIC/AllProj_AP_L3PHIC_04.dat");
  if (not validap) return -1;              // exit if file not found 

  ifstream fin_cm1;
  bool validcm1 = openDataFile(fin_cm1,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC17_04.dat");
  if (not validcm1) return -1;             // exit if file not found

  ifstream fin_cm2;
  bool validcm2 = openDataFile(fin_cm2,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC18_04.dat");
  if (not validcm2) return -1;             // exit if file not found

  ifstream fin_cm3;
  bool validcm3 = openDataFile(fin_cm3,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC19_04.dat");
  if (not validcm3) return -1;             // exit if file not found

  ifstream fin_cm4;
  bool validcm4 = openDataFile(fin_cm4,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC20_04.dat");
  if (not validcm4) return -1;             // exit if file not found

  ifstream fin_cm5;
  bool validcm5 = openDataFile(fin_cm5,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC21_04.dat");
  if (not validcm5) return -1;             // exit if file not found

  ifstream fin_cm6;
  bool validcm6 = openDataFile(fin_cm6,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC22_04.dat");
  if (not validcm6) return -1;             // exit if file not found

  ifstream fin_cm7;
  bool validcm7 = openDataFile(fin_cm7,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC23_04.dat");
  if (not validcm7) return -1;             // exit if file not found

  ifstream fin_cm8;
  bool validcm8 = openDataFile(fin_cm8,"MC/MC_L3PHIC/CandidateMatches_CM_L3PHIC24_04.dat");
  if (not validcm8) return -1;             // exit if file not found

  // open file(s) with reference results
  ifstream fin_fm_seed1;
  bool validfm1 = openDataFile(fin_fm_seed1,"MC/MC_L3PHIC/FullMatches_FM_L1L2_L3PHIC_04.dat");
  if (not validfm1) return -1;             // exit if file not found
  ifstream fin_fm_seed2;
  bool validfm2 = openDataFile(fin_fm_seed2,"MC/MC_L3PHIC/FullMatches_FM_L5L6_L3PHIC_04.dat");
  if (not validfm2) return -1;             // exit if file not found


  // loop over events
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // make memories from the input text files
    writeMemFromFile<AllStubMemory>(inputstub, fin_as, ievt);
    writeMemFromFile<AllProjectionMemory>(inputproj, fin_ap, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch1, fin_cm1, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch2, fin_cm2, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch3, fin_cm3, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch4, fin_cm4, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch5, fin_cm5, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch6, fin_cm6, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch7, fin_cm7, ievt);
    writeMemFromFile<CandidateMatchMemory>(inputcandmatch8, fin_cm8, ievt);

    //set bunch crossing
    BXType bx=ievt&0x7;

    // Unit Under Test
    MC(bx,
                    &inputcandmatch1, &inputcandmatch2, &inputcandmatch3, &inputcandmatch4,
                    &inputcandmatch5, &inputcandmatch6, &inputcandmatch7, &inputcandmatch8,
                    &inputproj, &inputstub, &outputfullmatch_seed1, &outputfullmatch_seed2);

    // compare the computed outputs with the expected ones 
    err_count += compareMemWithFile<FullMatchMemory>(outputfullmatch_seed1, fin_fm_seed1, ievt, "FullMatch", truncation);
    err_count += compareMemWithFile<FullMatchMemory>(outputfullmatch_seed2, fin_fm_seed2, ievt, "FullMatch", truncation);

  }  // end of event loop
  
  // close files
  fin_as.close();
  fin_ap.close();
  fin_cm1.close();
  fin_cm2.close();
  fin_cm3.close();
  fin_cm4.close();
  fin_cm5.close();
  fin_cm6.close();
  fin_cm7.close();
  fin_cm8.close();
  fin_fm_seed1.close();
  fin_fm_seed2.close();

  return err_count;

}
