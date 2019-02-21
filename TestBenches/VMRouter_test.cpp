// Test bench for VMRouter
#include "VMRouterTop.hh"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.hh"
#include "Constants.hh"

const int nevents = 2;  //number of events to run

using namespace std;

int main()
{ 
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static InputStubMemory<BARRELPS> ilink1;
  static InputStubMemory<BARRELPS> ilink2;
  static InputStubMemory<BARRELPS> ilink3;
  static InputStubMemory<BARRELPS> ilink4;
  static InputStubMemory<BARRELPS> ilink5;
  // static InputStubMemory<BARRELPS> ilink6;
  // static InputStubMemory<BARRELPS> ilink7;
  // static InputStubMemory<BARRELPS> ilink8;

  // output memories
  static AllStubMemory<BARRELPS> allstub;
  static VMStubMEMemory<BARRELPS> vmstubme1;
  static VMStubMEMemory<BARRELPS> vmstubme2;
  static VMStubMEMemory<BARRELPS> vmstubme3;
  static VMStubMEMemory<BARRELPS> vmstubme4;
  static VMStubMEMemory<BARRELPS> vmstubme5;
  static VMStubMEMemory<BARRELPS> vmstubme6;
  static VMStubMEMemory<BARRELPS> vmstubme7;
  static VMStubMEMemory<BARRELPS> vmstubme8;

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_ilink1;
  bool validin1 = openDataFile(fin_ilink1, "VMR/VMR_L1PHIE/InputStubs_IL_L1PHIE_PS10G_1_B_04.dat");
  if (not validin1) return -1;

  ifstream fin_ilink2;
  bool validin2 = openDataFile(fin_ilink2, "VMR/VMR_L1PHIE/InputStubs_IL_L1PHIE_neg_PS10G_1_B_04.dat");
  if (not validin2) return -1;

  ifstream fin_ilink3;
  bool validin3 = openDataFile(fin_ilink3, "VMR/VMR_L1PHIE/InputStubs_IL_L1PHIE_neg_PS10G_2_B_04.dat");
  if (not validin3) return -1;

  // ifstream fin_ilink4;
  // bool validin4 = openDataFile(fin_ilink4, "VMR/VMR_L1PHIE/Trackleilinkections_ILINK_L1L2I_L3PHIC_04.dat");
  // if (not validin4) return -1;

  // ifstream fin_ilink5;
  // bool validin5 = openDataFile(fin_ilink5, "VMR/VMR_L1PHIE/Trackleilinkections_ILINK_L1L2J_L3PHIC_04.dat");
  // if (not validin5) return -1;

  // ifstream fin_ilink6;
  // bool validin6 = openDataFile(fin_ilink6, "VMR/VMR_L1PHIE/Trackleilinkections_ILINK_L5L6B_L3PHIC_04.dat");
  // if (not validin6) return -1;

  // ifstream fin_ilink7;
  // bool validin7 = openDataFile(fin_ilink7, "VMR/VMR_L1PHIE/Trackleilinkections_ILINK_L5L6C_L3PHIC_04.dat");
  // if (not validin7) return -1;

  // ifstream fin_ilink8;
  // bool validin8 = openDataFile(fin_ilink8, "VMR/VMR_L1PHIE/Trackleilinkections_ILINK_L5L6D_L3PHIC_04.dat");
  // if (not validin8) return -1;

  ///////////////////////////
  // open output files
  ifstream fout_aproj;
  bool valid_aproj = openDataFile(fout_aproj, "VMR/VMR_L1PHIE/AllStubs_AS_L1PHIEn1_04.dat");
  if (not valid_aproj) return -1;

  ifstream fout_vmstubme1;
  bool valid_vmstubme1 =  openDataFile(fout_vmstubme1, "VMR/VMR_L1PHIE/VMStubs_VMSME_L1PHIE17n1_04.dat");
  if (not valid_vmstubme1) return -1;

  ifstream fout_vmstubme2;
  bool valid_vmstubme2 = openDataFile(fout_vmstubme2, "VMR/VMR_L1PHIE/VMStubs_VMSME_L1PHIE18n1_04.dat");
  if (not valid_vmstubme2) return -1;

  ifstream fout_vmstubme3;
  bool valid_vmstubme3 = openDataFile(fout_vmstubme3, "VMR/VMR_L1PHIE/VMStubs_VMSME_L1PHIE19n1_04.dat");
  if (not valid_vmstubme3) return -1;

  ifstream fout_vmstubme4;
  bool valid_vmstubme4 = openDataFile(fout_vmstubme4, "VMR/VMR_L1PHIE/VMStubs_VMSME_L1PHIE20n1_04.dat");
  if (not valid_vmstubme4) return -1;

//  ifstream fout_vmstubme5;
//  bool valid_vmstubme5 =  openDataFile(fout_vmstubme5, "VMR/VMR_L1PHIE/VMStubs_VMSTE_L1PHIE17n1_04.dat");
//  if (not valid_vmstubme5) return -1;
//
//  ifstream fout_vmstubme6;
//  bool valid_vmstubme6 = openDataFile(fout_vmstubme6, "VMR/VMR_L1PHIE/VMStubs_VMSTE_L1PHIE17n2_04.dat");
//  if (not valid_vmstubme6) return -1;
//
//  ifstream fout_vmstubme7;
//  bool valid_vmstubme7 = openDataFile(fout_vmstubme7, "VMR/VMR_L1PHIE/VMStubs_VMSTE_L1PHIE17n3_04.dat");
//  if (not valid_vmstubme7) return -1;
//
//  ifstream fout_vmstubme8;
//  bool valid_vmstubme8 = openDataFile(fout_vmstubme8, "VMR/VMR_L1PHIE/VMStubs_VMSTE_L1PHIE17n4_04.dat");
//  if (not valid_vmstubme8) return -1;

  ///////////////////////////  
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<InputStubMemory<BARRELPS>>(ilink1, fin_ilink1, ievt);
    writeMemFromFile<InputStubMemory<BARRELPS>>(ilink2, fin_ilink2, ievt);
    writeMemFromFile<InputStubMemory<BARRELPS>>(ilink3, fin_ilink3, ievt);
    // writeMemFromFile<InputStubMemory>(ilink4, fin_ilink4, ievt);
    // writeMemFromFile<InputStubMemory>(ilink5, fin_ilink5, ievt);
    // writeMemFromFile<InputStubMemory>(ilink6, fin_ilink6, ievt);
    // writeMemFromFile<InputStubMemory>(ilink7, fin_ilink7, ievt);
    // writeMemFromFile<InputStubMemory>(ilink8, fin_ilink8, ievt);
    
    // bx
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
    VMRouterTop(bx,
    		&ilink1, &ilink2, &ilink3, 0,0,//&ilink4, &ilink5,
		//&ilink6, &ilink7, &ilink8,
			&allstub,
		&vmstubme1, &vmstubme2, &vmstubme3, &vmstubme4,
		&vmstubme5, &vmstubme6, &vmstubme7, &vmstubme8
		);

    // compare the computed outputs with the expected ones
    bool truncation = false;
    // AllStub
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub, fout_aproj, ievt,
                                                   "AllStub", truncation);
    // VMStubME1
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme1, fout_vmstubme1, ievt,
                                                  "VMStubME17", truncation);

    // VMStubME2
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme2, fout_vmstubme2, ievt,
                                                  "VMStubME18", truncation);

    // VMStubME3
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme3, fout_vmstubme3, ievt,
                                                  "VMStubME19", truncation);

    // VMStubME4
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme4, fout_vmstubme4, ievt,
                                                  "VMStubME20", truncation);

//    // VMStubME5
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme5, fout_vmstubme5, ievt,
//                                                  "VMStubME5", truncation);
//
//    // VMStubME6
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme6, fout_vmstubme6, ievt,
//                                                  "VMStubME6", truncation);
//
//    // VMStubME7
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme7, fout_vmstubme7, ievt,
//                                                  "VMStubME7", truncation);
//
//    // VMStubME8
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme8, fout_vmstubme8, ievt,
//                                                  "VMStubME8", truncation);
  } // end of event loop
  std::cerr << "Exiting with return value " << err << std::endl;
  return err;
  
}
