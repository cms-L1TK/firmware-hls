// Test bench for ProjectionRouter
#include "ProjectionRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.hh"

const int nevents = 100;  //number of events to run

using namespace std;

int main()
{ 
  // error counts
  int err = 0;

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
  
  // open input files
  cout << "Open files..." << endl;
  ifstream fin_tproj1("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4C_L1PHI3_04.dat");
  ifstream fin_tproj2("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4D_L1PHI3_04.dat");
  ifstream fin_tproj3("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4E_L1PHI3_04.dat");
  ifstream fin_tproj4("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4F_L1PHI3_04.dat");
  ifstream fin_tproj5("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_D1L2B_L1PHI3_04.dat");
  ifstream fin_tproj6("PR_L3L4_L1PHI3/TrackletProjections_TPROJ_L3L4_L1PHI3FromPlus_04.dat");

  assert(fin_tproj1.good());
  assert(fin_tproj2.good());
  assert(fin_tproj3.good());
  assert(fin_tproj4.good());
  assert(fin_tproj5.good());
  assert(fin_tproj6.good());

  // open output files
  ifstream fout_aproj("PR_L3L4_L1PHI3/AllProj_AP_L3L4_L1PHI3_04.dat");
  ifstream fout_vmproj1("PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI9_04.dat");
  ifstream fout_vmproj2("PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI10_04.dat");
  ifstream fout_vmproj3("PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI11_04.dat");
  ifstream fout_vmproj4("PR_L3L4_L1PHI3/VMProjections_VMPROJ_L3L4_L1PHI12_04.dat");

  assert(fout_aproj.good());
  assert(fout_vmproj1.good());
  assert(fout_vmproj2.good());
  assert(fout_vmproj3.good());
  assert(fout_vmproj4.good());

  // loop over events
  cout << "Start event loop ..." << endl;
  for (int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<TrackletProjectionMemory>(tproj1, fin_tproj1, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj2, fin_tproj2, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj3, fin_tproj3, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj4, fin_tproj4, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj5, fin_tproj5, ievt);
    writeMemFromFile<TrackletProjectionMemory>(tproj6, fin_tproj6, ievt);
    
    // bx
    ap_uint<3> bx = ievt&0x7;
    ap_uint<3> bx_out;

    // Unit Under Test
    ProjectionRouterTop(bx,
                        &tproj1, &tproj2, &tproj3, &tproj4, &tproj5, &tproj6,
                        bx_out,
                        &allproj, &vmproj1, &vmproj2, &vmproj3, &vmproj4);

    // compare the computed outputs with the expected ones
    cout << "AllProjection:" << endl;
    err += compareMemWithFile<AllProjectionMemory>(allproj, fout_aproj, ievt);

    cout << "VMProjection1:" << endl;
    err += compareMemWithFile<VMProjectionMemory>(vmproj1, fout_vmproj1, ievt);

    cout << "VMProjection2:" << endl;
    err += compareMemWithFile<VMProjectionMemory>(vmproj2, fout_vmproj2, ievt);

    cout << "VMProjection3:" << endl;
    err += compareMemWithFile<VMProjectionMemory>(vmproj3, fout_vmproj3, ievt);

    cout << "VMProjection4:" << endl;
    err += compareMemWithFile<VMProjectionMemory>(vmproj4, fout_vmproj4, ievt);
    
  } // end of event loop
  
  return err;
  
}
