// Test bench for ProjectionRouter
#include "ProjectionRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.hh"
#include "Constants.hh"

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{ 
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static TrackletProjectionMemory tproj1;
  static TrackletProjectionMemory tproj2;
  static TrackletProjectionMemory tproj3;
  static TrackletProjectionMemory tproj4;
  static TrackletProjectionMemory tproj5;
  static TrackletProjectionMemory tproj6;

  // output memories
  static AllProjectionMemory allproj;
  static VMProjectionMemory vmproj1;
  static VMProjectionMemory vmproj2;
  static VMProjectionMemory vmproj3;
  static VMProjectionMemory vmproj4;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_tproj1;
  bool validin1 = openDataFile(fin_tproj1, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4C_L1PHI3_04.dat");
  if (not validin1) return -1;

  ifstream fin_tproj2;
  bool validin2 = openDataFile(fin_tproj2, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4D_L1PHI3_04.dat");
  if (not validin2) return -1;

  ifstream fin_tproj3;
  bool validin3 = openDataFile(fin_tproj3, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4E_L1PHI3_04.dat");
  if (not validin3) return -1;

  ifstream fin_tproj4;
  bool validin4 = openDataFile(fin_tproj4, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4F_L1PHI3_04.dat");
  if (not validin4) return -1;

  ifstream fin_tproj5;
  bool validin5 = openDataFile(fin_tproj5, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_D1L2B_L1PHI3_04.dat");
  if (not validin5) return -1;

  ifstream fin_tproj6;
  bool validin6 = openDataFile(fin_tproj6, "PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4_L1PHI3FromPlus_04.dat");
  if (not validin6) return -1;

  ///////////////////////////
  // open output files
  ifstream fout_aproj;
  bool valid_aproj = openDataFile(fout_aproj, "PR_L3L4_L1PHI3/AllProj_AP_L3L4_L1PHI3_04.dat");
  if (not valid_aproj) return -1;

  ifstream fout_vmproj1;
  bool valid_vmproj1 =  openDataFile(fout_vmproj1, "PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI9_04.dat");
  if (not valid_vmproj1) return -1;

  ifstream fout_vmproj2;
  bool valid_vmproj2 = openDataFile(fout_vmproj2, "PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI10_04.dat");
  if (not valid_vmproj2) return -1;

  ifstream fout_vmproj3;
  bool valid_vmproj3 = openDataFile(fout_vmproj3, "PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI11_04.dat");
  if (not valid_vmproj3) return -1;

  ifstream fout_vmproj4;
  bool valid_vmproj4 = openDataFile(fout_vmproj4, "PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI12_04.dat");
  if (not valid_vmproj4) return -1;

  ///////////////////////////  
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<TrackletProjectionMemory>(tproj1, fin_tproj1, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj2, fin_tproj2, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj3, fin_tproj3, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj4, fin_tproj4, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj5, fin_tproj5, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj6, fin_tproj6, ievt);
    
    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    ProjectionRouterTop(bx,
                        &tproj1, &tproj2, &tproj3, &tproj4, &tproj5, &tproj6,
                        bx_out,
                        &allproj, &vmproj1, &vmproj2, &vmproj3, &vmproj4);

    // compare the computed outputs with the expected ones
    // AllProjection
    err += compareMemWithFile<AllProjectionMemory>(allproj, fout_aproj, ievt,
                                                   "AllProjection");
    // VMProjection1
    err += compareMemWithFile<VMProjectionMemory>(vmproj1, fout_vmproj1, ievt,
                                                  "VMProjection1");

    // VMProjection2
    err += compareMemWithFile<VMProjectionMemory>(vmproj2, fout_vmproj2, ievt,
                                                  "VMProjection2");

    // VMProjection3
    err += compareMemWithFile<VMProjectionMemory>(vmproj3, fout_vmproj3, ievt,
                                                  "VMProjection3");

    // VMProjection4
    err += compareMemWithFile<VMProjectionMemory>(vmproj4, fout_vmproj4, ievt,
                                                  "VMProjection4");
    
  } // end of event loop
  
  return err;
  
}
