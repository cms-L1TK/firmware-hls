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
  static TrackletProjectionMemory tproj7;
  static TrackletProjectionMemory tproj8;

  // output memories
  static AllProjectionMemory allproj;
  static VMProjectionMemory vmproj1;
  static VMProjectionMemory vmproj2;
  static VMProjectionMemory vmproj3;
  static VMProjectionMemory vmproj4;
  static VMProjectionMemory vmproj5;
  static VMProjectionMemory vmproj6;
  static VMProjectionMemory vmproj7;
  static VMProjectionMemory vmproj8;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_tproj1;
  bool validin1 = openDataFile(fin_tproj1, "PR_L3PHIC/TrackletProjections_TPROJ_L1L2F_L3PHIC_04.dat");
  if (not validin1) return -1;

  ifstream fin_tproj2;
  bool validin2 = openDataFile(fin_tproj2, "PR_L3PHIC/TrackletProjections_TPROJ_L1L2G_L3PHIC_04.dat");
  if (not validin2) return -1;

  ifstream fin_tproj3;
  bool validin3 = openDataFile(fin_tproj3, "PR_L3PHIC/TrackletProjections_TPROJ_L1L2H_L3PHIC_04.dat");
  if (not validin3) return -1;

  ifstream fin_tproj4;
  bool validin4 = openDataFile(fin_tproj4, "PR_L3PHIC/TrackletProjections_TPROJ_L1L2I_L3PHIC_04.dat");
  if (not validin4) return -1;

  ifstream fin_tproj5;
  bool validin5 = openDataFile(fin_tproj5, "PR_L3PHIC/TrackletProjections_TPROJ_L1L2J_L3PHIC_04.dat");
  if (not validin5) return -1;

  ifstream fin_tproj6;
  bool validin6 = openDataFile(fin_tproj6, "PR_L3PHIC/TrackletProjections_TPROJ_L5L6B_L3PHIC_04.dat");
  if (not validin6) return -1;

  ifstream fin_tproj7;
  bool validin7 = openDataFile(fin_tproj7, "PR_L3PHIC/TrackletProjections_TPROJ_L5L6C_L3PHIC_04.dat");
  if (not validin7) return -1;

  ifstream fin_tproj8;
  bool validin8 = openDataFile(fin_tproj8, "PR_L3PHIC/TrackletProjections_TPROJ_L5L6D_L3PHIC_04.dat");
  if (not validin8) return -1;

  ///////////////////////////
  // open output files
  ifstream fout_aproj;
  bool valid_aproj = openDataFile(fout_aproj, "PR_L3PHIC/AllProj_AP_L3PHIC_04.dat");
  if (not valid_aproj) return -1;

  ifstream fout_vmproj1;
  bool valid_vmproj1 =  openDataFile(fout_vmproj1, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC17_04.dat");
  if (not valid_vmproj1) return -1;

  ifstream fout_vmproj2;
  bool valid_vmproj2 = openDataFile(fout_vmproj2, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC18_04.dat");
  if (not valid_vmproj2) return -1;

  ifstream fout_vmproj3;
  bool valid_vmproj3 = openDataFile(fout_vmproj3, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC19_04.dat");
  if (not valid_vmproj3) return -1;

  ifstream fout_vmproj4;
  bool valid_vmproj4 = openDataFile(fout_vmproj4, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC20_04.dat");
  if (not valid_vmproj4) return -1;

  ifstream fout_vmproj5;
  bool valid_vmproj5 =  openDataFile(fout_vmproj5, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC21_04.dat");
  if (not valid_vmproj5) return -1;

  ifstream fout_vmproj6;
  bool valid_vmproj6 = openDataFile(fout_vmproj6, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC22_04.dat");
  if (not valid_vmproj6) return -1;

  ifstream fout_vmproj7;
  bool valid_vmproj7 = openDataFile(fout_vmproj7, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC23_04.dat");
  if (not valid_vmproj7) return -1;

  ifstream fout_vmproj8;
  bool valid_vmproj8 = openDataFile(fout_vmproj8, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC24_04.dat");
  if (not valid_vmproj8) return -1;

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
    writeMemFromFile<TrackletProjectionMemory>(tproj7, fin_tproj7, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj8, fin_tproj8, ievt);
    
    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    ProjectionRouterTop(bx,
                        &tproj1, &tproj2, &tproj3, &tproj4,
                        &tproj5, &tproj6, &tproj7, &tproj8,
                        bx_out,
                        &allproj,
                        &vmproj1, &vmproj2, &vmproj3, &vmproj4,
                        &vmproj5, &vmproj6, &vmproj7, &vmproj8);

    // compare the computed outputs with the expected ones
    bool truncation = false;
    // AllProjection
    err += compareMemWithFile<AllProjectionMemory>(allproj, fout_aproj, ievt,
                                                   "AllProjection", truncation);
    // VMProjection1
    err += compareMemWithFile<VMProjectionMemory>(vmproj1, fout_vmproj1, ievt,
                                                  "VMProjection1", truncation);

    // VMProjection2
    err += compareMemWithFile<VMProjectionMemory>(vmproj2, fout_vmproj2, ievt,
                                                  "VMProjection2", truncation);

    // VMProjection3
    err += compareMemWithFile<VMProjectionMemory>(vmproj3, fout_vmproj3, ievt,
                                                  "VMProjection3", truncation);

    // VMProjection4
    err += compareMemWithFile<VMProjectionMemory>(vmproj4, fout_vmproj4, ievt,
                                                  "VMProjection4", truncation);

    // VMProjection5
    err += compareMemWithFile<VMProjectionMemory>(vmproj5, fout_vmproj5, ievt,
                                                  "VMProjection5", truncation);

    // VMProjection6
    err += compareMemWithFile<VMProjectionMemory>(vmproj6, fout_vmproj6, ievt,
                                                  "VMProjection6", truncation);

    // VMProjection7
    err += compareMemWithFile<VMProjectionMemory>(vmproj7, fout_vmproj7, ievt,
                                                  "VMProjection7", truncation);

    // VMProjection8
    err += compareMemWithFile<VMProjectionMemory>(vmproj8, fout_vmproj8, ievt,
                                                  "VMProjection8", truncation);
    
  } // end of event loop
  
  return err;
  
}
