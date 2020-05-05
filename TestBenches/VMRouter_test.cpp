// Test bench for VMRouter
#include "VMRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 1;  //number of events to run

using namespace std;

// VMRouter Test for Layer 1, Allstub region E

int main()
{
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static InputStubMemory<BARRELPS> inputMemories[6];

  // output memories
  static AllStubMemory<BARRELPS> allstub[6];
  // ME memories
  static VMStubMEMemory<BARRELPS> meMemories[32];
	// TE Inner memories
	static VMStubTEInnerMemory<BARRELPS> teiMemories[32];
	// TE Inner Overlap memories, including copies
	static VMStubTEInnerMemory<BARRELOL> olMemories[3][16];
  // TE Outer memories
  static VMStubTEOuterMemory<BARRELPS> teoMemories[32];

  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_ilink1;
  bool validin1 = openDataFile(fin_ilink1, "VMR/MemPrints3/InputStubs/InputStubs_IL_L1PHIE_PS10G_1_B_04.dat");
  if (not validin1) return -1;

  ifstream fin_ilink2;
  bool validin2 = openDataFile(fin_ilink2, "VMR/MemPrints3/InputStubs/InputStubs_IL_L1PHIE_PS10G_2_B_04.dat");
  if (not validin2) return -1;

  ifstream fin_ilink3;
  bool validin3 = openDataFile(fin_ilink3, "VMR/MemPrints3/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_1_B_04.dat");
  if (not validin3) return -1;

  ifstream fin_ilink4;
  bool validin4 = openDataFile(fin_ilink4, "VMR/MemPrints3/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_2_B_04.dat");
  if (not validin4) return -1;

  // ifstream fin_ilink5;
  // bool validin5 = openDataFile(fin_ilink5, "VMR/MemPrints3/Trackleilinkections_ILINK_L1L2J_L3PHIC_04.dat");
  // if (not validin5) return -1;

  // ifstream fin_ilink6;
  // bool validin6 = openDataFile(fin_ilink6, "VMR/MemPrints3/Trackleilinkections_ILINK_L5L6B_L3PHIC_04.dat");
  // if (not validin6) return -1;

  // ifstream fin_ilink7;
  // bool validin7 = openDataFile(fin_ilink7, "VMR/MemPrints3/Trackleilinkections_ILINK_L5L6C_L3PHIC_04.dat");
  // if (not validin7) return -1;

  // ifstream fin_ilink8;
  // bool validin8 = openDataFile(fin_ilink8, "VMR/MemPrints3/Trackleilinkections_ILINK_L5L6D_L3PHIC_04.dat");
  // if (not validin8) return -1;

  ///////////////////////////
  // open output files

  // AllStub
  ifstream fout_allstub_n1;
  bool valid_allstub_n1 = openDataFile(fout_allstub_n1, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn1_04.dat");
  if (not valid_allstub_n1) return -1;

  ifstream fout_allstub_n2;
  bool valid_allstub_n2 = openDataFile(fout_allstub_n2, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn2_04.dat");
  if (not valid_allstub_n2) return -1;

  ifstream fout_allstub_n3;
  bool valid_allstub_n3 = openDataFile(fout_allstub_n3, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn3_04.dat");
  if (not valid_allstub_n3) return -1;

  ifstream fout_allstub_n4;
  bool valid_allstub_n4 = openDataFile(fout_allstub_n4, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn4_04.dat");
  if (not valid_allstub_n4) return -1;

  ifstream fout_allstub_n5;
  bool valid_allstub_n5 = openDataFile(fout_allstub_n5, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn5_04.dat");
  if (not valid_allstub_n5) return -1;

  ifstream fout_allstub_n6;
  bool valid_allstub_n6 = openDataFile(fout_allstub_n6, "VMR/MemPrints3/Stubs/AllStubs_AS_L1PHIEn6_04.dat");
  if (not valid_allstub_n6) return -1;

  // ME memories
  ifstream fout_vmstubme1;
  bool valid_vmstubme1 =  openDataFile(fout_vmstubme1, "VMR/MemPrints3/VMStubsME/VMStubs_VMSME_L1PHIE17n1_04.dat");
  if (not valid_vmstubme1) return -1;

  ifstream fout_vmstubme2;
  bool valid_vmstubme2 = openDataFile(fout_vmstubme2, "VMR/MemPrints3/VMStubsME/VMStubs_VMSME_L1PHIE18n1_04.dat");
  if (not valid_vmstubme2) return -1;

  ifstream fout_vmstubme3;
  bool valid_vmstubme3 = openDataFile(fout_vmstubme3, "VMR/MemPrints3/VMStubsME/VMStubs_VMSME_L1PHIE19n1_04.dat");
  if (not valid_vmstubme3) return -1;

  ifstream fout_vmstubme4;
  bool valid_vmstubme4 = openDataFile(fout_vmstubme4, "VMR/MemPrints3/VMStubsME/VMStubs_VMSME_L1PHIE20n1_04.dat");
  if (not valid_vmstubme4) return -1;

//  ifstream fout_vmstubme5;
//  bool valid_vmstubme5 =  openDataFile(fout_vmstubme5, "VMR/MemPrints3/VMStubs_VMSTE_L1PHIE17n1_04.dat");
//  if (not valid_vmstubme5) return -1;
//
//  ifstream fout_vmstubme6;
//  bool valid_vmstubme6 = openDataFile(fout_vmstubme6, "VMR/MemPrints3/VMStubs_VMSTE_L1PHIE17n2_04.dat");
//  if (not valid_vmstubme6) return -1;
//
//  ifstream fout_vmstubme7;
//  bool valid_vmstubme7 = openDataFile(fout_vmstubme7, "VMR/MemPrints3/VMStubs_VMSTE_L1PHIE17n3_04.dat");
//  if (not valid_vmstubme7) return -1;
//
//  ifstream fout_vmstubme8;
//  bool valid_vmstubme8 = openDataFile(fout_vmstubme8, "VMR/MemPrints3/VMStubs_VMSTE_L1PHIE17n4_04.dat");
//  if (not valid_vmstubme8) return -1;

// TE Inner
	ifstream fout_vmstubtei1;
	bool valid_vmstubtei1 = openDataFile(fout_vmstubtei1,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIE17n1_04.dat");
	if (not valid_vmstubtei1)
		return -1;

	ifstream fout_vmstubtei2;
	bool valid_vmstubtei2 = openDataFile(fout_vmstubtei2,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIE18n1_04.dat");
	if (not valid_vmstubtei2)
		return -1;

	ifstream fout_vmstubtei3;
	bool valid_vmstubtei3 = openDataFile(fout_vmstubtei3,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIE19n1_04.dat");
	if (not valid_vmstubtei3)
		return -1;

	ifstream fout_vmstubtei4;
	bool valid_vmstubtei4 = openDataFile(fout_vmstubtei4,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIE20n1_04.dat");
	if (not valid_vmstubtei4)
		return -1;

// TE Inner Overlap
	ifstream fout_vmstubteol1_n1;
	bool valid_vmstubteol1_n1 = openDataFile(fout_vmstubteol1_n1,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n1_04.dat");
	if (not valid_vmstubteol1_n1)
		return -1;

  ifstream fout_vmstubteol1_n2;
	bool valid_vmstubteol1_n2 = openDataFile(fout_vmstubteol1_n2,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n2_04.dat");
	if (not valid_vmstubteol1_n2)
		return -1;

  ifstream fout_vmstubteol1_n3;
	bool valid_vmstubteol1_n3 = openDataFile(fout_vmstubteol1_n3,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n3_04.dat");
	if (not valid_vmstubteol1_n3)
		return -1;

	ifstream fout_vmstubteol2_n1;
	bool valid_vmstubteol2_n1 = openDataFile(fout_vmstubteol2_n1,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n1_04.dat");
  if (not valid_vmstubteol2_n1)
		return -1;

  ifstream fout_vmstubteol2_n2;
	bool valid_vmstubteol2_n2 = openDataFile(fout_vmstubteol2_n2,
			"VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n2_04.dat");
      if (not valid_vmstubteol2_n2)
    		return -1;

  ifstream fout_vmstubteol2_n3;
  bool valid_vmstubteol2_n3 = openDataFile(fout_vmstubteol2_n3,
      "VMR/MemPrints3/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n3_04.dat");
  if (not valid_vmstubteol2_n3)
		return -1;


  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

    // read event and write to memories
    writeMemFromFile<InputStubMemory<BARRELPS>>(inputMemories[0], fin_ilink1, ievt);
    writeMemFromFile<InputStubMemory<BARRELPS>>(inputMemories[1], fin_ilink2, ievt);
    writeMemFromFile<InputStubMemory<BARRELPS>>(inputMemories[2], fin_ilink3, ievt);
    writeMemFromFile<InputStubMemory<BARRELPS>>(inputMemories[3], fin_ilink4, ievt);
    // writeMemFromFile<InputStubMemory>(ilink5, fin_ilink5, ievt);
    // writeMemFromFile<InputStubMemory>(ilink6, fin_ilink6, ievt);
    // writeMemFromFile<InputStubMemory>(ilink7, fin_ilink7, ievt);
    // writeMemFromFile<InputStubMemory>(ilink8, fin_ilink8, ievt);

    // bx - bunch crossing
    BXType bx = ievt;
    BXType bx_out;

    // Unit Under Test
		// Unit Under Test
				VMRouterTop(bx, inputMemories,
						allstub, meMemories, teiMemories, olMemories, teoMemories);

    // compare the computed outputs with the expected ones
    // add 1 per stub that is incorrect
    bool truncation = false;

    // AllStub
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[0], fout_allstub_n1, ievt,
                                                   "AllStub", truncation);
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[1], fout_allstub_n2, ievt,
                                                  "AllStub", truncation);
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[2], fout_allstub_n3, ievt,
                                                  "AllStub", truncation);
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[3], fout_allstub_n4, ievt,
                                                  "AllStub", truncation);
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[4], fout_allstub_n5, ievt,
                                                  "AllStub", truncation);
    err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub[5], fout_allstub_n6, ievt,
                                                  "AllStub", truncation);

    // ME Memories
    // VMStubME1
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[16], fout_vmstubme1, ievt,
                                                  "VMStubME17", truncation);
    // VMStubME2
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[17], fout_vmstubme2, ievt,
                                                  "VMStubME18", truncation);
    // VMStubME3
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[18], fout_vmstubme3, ievt,
                                                  "VMStubME19", truncation);
    // VMStubME4
    err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[19], fout_vmstubme4, ievt,
                                                  "VMStubME20", truncation);
//    // VMStubME5
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme5, fout_vmstubme5, ievt,
//                                                  "VMStubME5", truncation);
//    // VMStubME6
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme6, fout_vmstubme6, ievt,
//                                                  "VMStubME6", truncation);
//    // VMStubME7
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme7, fout_vmstubme7, ievt,
//                                                  "VMStubME7", truncation);
//    // VMStubME8
//    err += compareMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme8, fout_vmstubme8, ievt,
//                                                  "VMStubME8", truncation);

// TE Memories
//VMStubTEInner1
err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[16], fout_vmstubtei1, ievt,
                                              "VMStubTEInner17", truncation);

// VMStubTEInner2
err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[17], fout_vmstubtei2, ievt,
                                              "VMStubTEInner18", truncation);

// VMStubTEInner3
err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[18], fout_vmstubtei3, ievt,
                                              "VMStubTEInner19", truncation);

// VMStubTEInner4
err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[19], fout_vmstubtei4, ievt,
                                              "VMStubTEInner20", truncation);


// TE Inner Overlap memories
// VMStubTEInner1 Overlap
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[0][8], fout_vmstubteol1_n1, ievt,
                                              "VMStubTEOverlap1", truncation);
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[1][8], fout_vmstubteol1_n2, ievt,
                                              "VMStubTEOverlap1", truncation);
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[2][8], fout_vmstubteol1_n3, ievt,
                                              "VMStubTEOverlap1", truncation);
// VMStubTEInner2 Overlap
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[0][9], fout_vmstubteol2_n1, ievt,
                                              "VMStubTEOverlap2", truncation);
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[1][9], fout_vmstubteol2_n2, ievt,
                                              "VMStubTEOverlap2", truncation);
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[2][9], fout_vmstubteol2_n3, ievt,
                                              "VMStubTEOverlap2", truncation);

  } // end of event loop
	std::cerr << "Exiting with return value " << err << std::endl;
	return err;

}
