// Test bench for VMRouter
#include "VMRouterTop.hh"

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
  static InputStubMemory ilink1;
  static InputStubMemory ilink2;
  static InputStubMemory ilink3;
  static InputStubMemory ilink4;
  static InputStubMemory ilink5;
  static InputStubMemory ilink6;
  static InputStubMemory ilink7;
  static InputStubMemory ilink8;

  // output memories
  static AllStubMemory allstub;
  static VMStubMEMemory vmstubme1;
  static VMStubMEMemory vmstubme2;
  static VMStubMEMemory vmstubme3;
  static VMStubMEMemory vmstubme4;
  static VMStubMEMemory vmstubme5;
  static VMStubMEMemory vmstubme6;
  static VMStubMEMemory vmstubme7;
  static VMStubMEMemory vmstubme8;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_ilink1;
  bool validin1 = openDataFile(fin_ilink1, "PR_L3PHIC/Trackleilinkections_ILINK_L1L2F_L3PHIC_04.dat");
  if (not validin1) return -1;

  ifstream fin_ilink2;
  bool validin2 = openDataFile(fin_ilink2, "PR_L3PHIC/Trackleilinkections_ILINK_L1L2G_L3PHIC_04.dat");
  if (not validin2) return -1;

  ifstream fin_ilink3;
  bool validin3 = openDataFile(fin_ilink3, "PR_L3PHIC/Trackleilinkections_ILINK_L1L2H_L3PHIC_04.dat");
  if (not validin3) return -1;

  ifstream fin_ilink4;
  bool validin4 = openDataFile(fin_ilink4, "PR_L3PHIC/Trackleilinkections_ILINK_L1L2I_L3PHIC_04.dat");
  if (not validin4) return -1;

  ifstream fin_ilink5;
  bool validin5 = openDataFile(fin_ilink5, "PR_L3PHIC/Trackleilinkections_ILINK_L1L2J_L3PHIC_04.dat");
  if (not validin5) return -1;

  ifstream fin_ilink6;
  bool validin6 = openDataFile(fin_ilink6, "PR_L3PHIC/Trackleilinkections_ILINK_L5L6B_L3PHIC_04.dat");
  if (not validin6) return -1;

  ifstream fin_ilink7;
  bool validin7 = openDataFile(fin_ilink7, "PR_L3PHIC/Trackleilinkections_ILINK_L5L6C_L3PHIC_04.dat");
  if (not validin7) return -1;

  ifstream fin_ilink8;
  bool validin8 = openDataFile(fin_ilink8, "PR_L3PHIC/Trackleilinkections_ILINK_L5L6D_L3PHIC_04.dat");
  if (not validin8) return -1;

  ///////////////////////////
  // open output files
  ifstream fout_aproj;
  bool valid_aproj = openDataFile(fout_aproj, "PR_L3PHIC/AllProj_AP_L3PHIC_04.dat");
  if (not valid_aproj) return -1;

  ifstream fout_vmstubme1;
  bool valid_vmstubme1 =  openDataFile(fout_vmstubme1, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC17_04.dat");
  if (not valid_vmstubme1) return -1;

  ifstream fout_vmstubme2;
  bool valid_vmstubme2 = openDataFile(fout_vmstubme2, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC18_04.dat");
  if (not valid_vmstubme2) return -1;

  ifstream fout_vmstubme3;
  bool valid_vmstubme3 = openDataFile(fout_vmstubme3, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC19_04.dat");
  if (not valid_vmstubme3) return -1;

  ifstream fout_vmstubme4;
  bool valid_vmstubme4 = openDataFile(fout_vmstubme4, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC20_04.dat");
  if (not valid_vmstubme4) return -1;

  ifstream fout_vmstubme5;
  bool valid_vmstubme5 =  openDataFile(fout_vmstubme5, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC21_04.dat");
  if (not valid_vmstubme5) return -1;

  ifstream fout_vmstubme6;
  bool valid_vmstubme6 = openDataFile(fout_vmstubme6, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC22_04.dat");
  if (not valid_vmstubme6) return -1;

  ifstream fout_vmstubme7;
  bool valid_vmstubme7 = openDataFile(fout_vmstubme7, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC23_04.dat");
  if (not valid_vmstubme7) return -1;

  ifstream fout_vmstubme8;
  bool valid_vmstubme8 = openDataFile(fout_vmstubme8, "PR_L3PHIC/VMProjections_VMPROJ_L3PHIC24_04.dat");
  if (not valid_vmstubme8) return -1;

  ///////////////////////////  
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<InputStubMemory>(ilink1, fin_ilink1, ievt);
    writeMemFromFile<InputStubMemory>(ilink2, fin_ilink2, ievt);
    writeMemFromFile<InputStubMemory>(ilink3, fin_ilink3, ievt);
    writeMemFromFile<InputStubMemory>(ilink4, fin_ilink4, ievt);
    writeMemFromFile<InputStubMemory>(ilink5, fin_ilink5, ievt);
    writeMemFromFile<InputStubMemory>(ilink6, fin_ilink6, ievt);
    writeMemFromFile<InputStubMemory>(ilink7, fin_ilink7, ievt);
    writeMemFromFile<InputStubMemory>(ilink8, fin_ilink8, ievt);
    
    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    VMRouterTop(bx,
                        &ilink1, &ilink2, &ilink3, &ilink4,
                        &ilink5, &ilink6, &ilink7, &ilink8,
                        &allstub,
                        &vmstubme1, &vmstubme2, &vmstubme3, &vmstubme4,
                        &vmstubme5, &vmstubme6, &vmstubme7, &vmstubme8);

    // compare the computed outputs with the expected ones
    bool truncation = false;
    // AllStub
    err += compareMemWithFile<AllStubMemory>(allstub, fout_aproj, ievt,
                                                   "AllStub", truncation);
#ifdef NOTDEF
    // VMStubME1
    err += compareMemWithFile<VMStubMEMemory>(vmstubme1, fout_vmstubme1, ievt,
                                                  "VMStubME1", truncation);

    // VMStubME2
    err += compareMemWithFile<VMStubMEMemory>(vmstubme2, fout_vmstubme2, ievt,
                                                  "VMStubME2", truncation);

    // VMStubME3
    err += compareMemWithFile<VMStubMEMemory>(vmstubme3, fout_vmstubme3, ievt,
                                                  "VMStubME3", truncation);

    // VMStubME4
    err += compareMemWithFile<VMStubMEMemory>(vmstubme4, fout_vmstubme4, ievt,
                                                  "VMStubME4", truncation);

    // VMStubME5
    err += compareMemWithFile<VMStubMEMemory>(vmstubme5, fout_vmstubme5, ievt,
                                                  "VMStubME5", truncation);

    // VMStubME6
    err += compareMemWithFile<VMStubMEMemory>(vmstubme6, fout_vmstubme6, ievt,
                                                  "VMStubME6", truncation);

    // VMStubME7
    err += compareMemWithFile<VMStubMEMemory>(vmstubme7, fout_vmstubme7, ievt,
                                                  "VMStubME7", truncation);

    // VMStubME8
    err += compareMemWithFile<VMStubMEMemory>(vmstubme8, fout_vmstubme8, ievt,
                                                  "VMStubME8", truncation);
#endif // NOTDEF
  } // end of event loop
  
  return err;
  
}
