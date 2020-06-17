// Test bench for VMRouter
#include "VMRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 100;  //number of events to run

using namespace std;

// VMRouter Test for Layer 1, Allstub region E

int main()
{
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static InputStubMemory<BARRELPS> inputStub[4];
  // output memories
  static AllStubMemory<BARRELPS> allStub[6];
  // ME memories
  static VMStubMEMemory<BARRELPS> meMemories[4];
  // TE Inner memories
  static VMStubTEInnerMemory<BARRELPS> teiMemories[4][5];
  // TE Inner Overlap memories, including copies
  static VMStubTEInnerMemory<BARRELOL> olMemories[2][3];


///////////////////////////
// open input files
  cout << "Open files..." << endl;

  ifstream fin_inputstub1;
  bool validin1 = openDataFile(fin_inputstub1, "MemPrints/InputStubs/InputStubs_IL_L1PHIE_PS10G_1_B_04.dat");
  if (not validin1) return -1;

  ifstream fin_inputstub2;
  bool validin2 = openDataFile(fin_inputstub2, "MemPrints/InputStubs/InputStubs_IL_L1PHIE_PS10G_2_B_04.dat");
  if (not validin2) return -1;

  ifstream fin_inputstub3;
  bool validin3 = openDataFile(fin_inputstub3, "MemPrints/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_1_B_04.dat");
  if (not validin3) return -1;

  ifstream fin_inputstub4;
  bool validin4 = openDataFile(fin_inputstub4, "MemPrints/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_2_B_04.dat");
  if (not validin4) return -1;


  ///////////////////////////
  // open output files

  // AllStub
  ifstream fout_allstub_n1;
  bool valid_allstub_n1 = openDataFile(fout_allstub_n1, "MemPrints/Stubs/AllStubs_AS_L1PHIEn1_04.dat");
  if (not valid_allstub_n1) return -1;

  ifstream fout_allstub_n2;
  bool valid_allstub_n2 = openDataFile(fout_allstub_n2, "MemPrints/Stubs/AllStubs_AS_L1PHIEn2_04.dat");
  if (not valid_allstub_n2) return -1;

  ifstream fout_allstub_n3;
  bool valid_allstub_n3 = openDataFile(fout_allstub_n3, "MemPrints/Stubs/AllStubs_AS_L1PHIEn3_04.dat");
  if (not valid_allstub_n3) return -1;

  ifstream fout_allstub_n4;
  bool valid_allstub_n4 = openDataFile(fout_allstub_n4, "MemPrints/Stubs/AllStubs_AS_L1PHIEn4_04.dat");
  if (not valid_allstub_n4) return -1;

  ifstream fout_allstub_n5;
  bool valid_allstub_n5 = openDataFile(fout_allstub_n5, "MemPrints/Stubs/AllStubs_AS_L1PHIEn5_04.dat");
  if (not valid_allstub_n5) return -1;

  ifstream fout_allstub_n6;
  bool valid_allstub_n6 = openDataFile(fout_allstub_n6, "MemPrints/Stubs/AllStubs_AS_L1PHIEn6_04.dat");
  if (not valid_allstub_n6) return -1;

  // ME memories
  ifstream fout_vmstubme1;
  bool valid_vmstubme1 =  openDataFile(fout_vmstubme1, "MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE17n1_04.dat");
  if (not valid_vmstubme1) return -1;

  ifstream fout_vmstubme2;
  bool valid_vmstubme2 = openDataFile(fout_vmstubme2, "MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE18n1_04.dat");
  if (not valid_vmstubme2) return -1;

  ifstream fout_vmstubme3;
  bool valid_vmstubme3 = openDataFile(fout_vmstubme3, "MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE19n1_04.dat");
  if (not valid_vmstubme3) return -1;

  ifstream fout_vmstubme4;
  bool valid_vmstubme4 = openDataFile(fout_vmstubme4, "MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE20n1_04.dat");
  if (not valid_vmstubme4) return -1;


// TE Inner
// 17
	ifstream fout_vmstubtei1_n1;
	if (not openDataFile(fout_vmstubtei1_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n1_04.dat")) return -1;

  ifstream fout_vmstubtei1_n2;
	if (not openDataFile(fout_vmstubtei1_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n2_04.dat")) return -1;

  ifstream fout_vmstubtei1_n3;
  if (not openDataFile(fout_vmstubtei1_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n3_04.dat")) return -1;

  ifstream fout_vmstubtei1_n4;
  if (not openDataFile(fout_vmstubtei1_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n4_04.dat")) return -1;

  ifstream fout_vmstubtei1_n5;
  if (not openDataFile(fout_vmstubtei1_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n5_04.dat")) return -1;

// 18
	ifstream fout_vmstubtei2_n1;
	if (not openDataFile(fout_vmstubtei2_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n1_04.dat")) return -1;

  ifstream fout_vmstubtei2_n2;
  if (not openDataFile(fout_vmstubtei2_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n2_04.dat")) return -1;

  ifstream fout_vmstubtei2_n3;
	if (not openDataFile(fout_vmstubtei2_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n3_04.dat")) return -1;

  ifstream fout_vmstubtei2_n4;
  if (not openDataFile(fout_vmstubtei2_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n4_04.dat")) return -1;

  ifstream fout_vmstubtei2_n5;
  if (not openDataFile(fout_vmstubtei2_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n5_04.dat")) return -1;

// 19
	ifstream fout_vmstubtei3_n1;
	if (not openDataFile(fout_vmstubtei3_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n1_04.dat")) return -1;

  ifstream fout_vmstubtei3_n2;
	if (not openDataFile(fout_vmstubtei3_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n2_04.dat")) return -1;

  ifstream fout_vmstubtei3_n3;
  if (not openDataFile(fout_vmstubtei3_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n3_04.dat")) return -1;

  ifstream fout_vmstubtei3_n4;
  if (not openDataFile(fout_vmstubtei3_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n4_04.dat")) return -1;

  ifstream fout_vmstubtei3_n5;
  if (not openDataFile(fout_vmstubtei3_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n5_04.dat")) return -1;

// 20
	ifstream fout_vmstubtei4_n1;
	if (not openDataFile(fout_vmstubtei4_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n1_04.dat")) return -1;

  ifstream fout_vmstubtei4_n2;
	if (not openDataFile(fout_vmstubtei4_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n2_04.dat")) return -1;

  ifstream fout_vmstubtei4_n3;
  if (not openDataFile(fout_vmstubtei4_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n3_04.dat")) return -1;

  ifstream fout_vmstubtei4_n4;
  if (not openDataFile(fout_vmstubtei4_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n4_04.dat")) return -1;

  ifstream fout_vmstubtei4_n5;
  if (not openDataFile(fout_vmstubtei4_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n5_04.dat")) return -1;


// TE Inner Overlap
	ifstream fout_vmstubteol1_n1;
	bool valid_vmstubteol1_n1 = openDataFile(fout_vmstubteol1_n1,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n1_04.dat");
	if (not valid_vmstubteol1_n1)
		return -1;

  ifstream fout_vmstubteol1_n2;
	bool valid_vmstubteol1_n2 = openDataFile(fout_vmstubteol1_n2,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n2_04.dat");
	if (not valid_vmstubteol1_n2)
		return -1;

  ifstream fout_vmstubteol1_n3;
	bool valid_vmstubteol1_n3 = openDataFile(fout_vmstubteol1_n3,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n3_04.dat");
	if (not valid_vmstubteol1_n3)
		return -1;

	ifstream fout_vmstubteol2_n1;
	bool valid_vmstubteol2_n1 = openDataFile(fout_vmstubteol2_n1,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n1_04.dat");
  if (not valid_vmstubteol2_n1)
		return -1;

  ifstream fout_vmstubteol2_n2;
	bool valid_vmstubteol2_n2 = openDataFile(fout_vmstubteol2_n2,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n2_04.dat");
      if (not valid_vmstubteol2_n2)
    		return -1;

  ifstream fout_vmstubteol2_n3;
  bool valid_vmstubteol2_n3 = openDataFile(fout_vmstubteol2_n3,
      "MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n3_04.dat");
  if (not valid_vmstubteol2_n3)
		return -1;


  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

  // read event and write to memories
  writeMemFromFile<InputStubMemory<BARRELPS>>(inputStub[0], fin_inputstub1, ievt);
  writeMemFromFile<InputStubMemory<BARRELPS>>(inputStub[1], fin_inputstub2, ievt);
  writeMemFromFile<InputStubMemory<BARRELPS>>(inputStub[2], fin_inputstub3, ievt);
  writeMemFromFile<InputStubMemory<BARRELPS>>(inputStub[3], fin_inputstub4, ievt);
  // writeMemFromFile<InputStubMemory>(inputStub5, fin_inputstub5, ievt);
  // writeMemFromFile<InputStubMemory>(inputStub6, fin_inputstub6, ievt);
  // writeMemFromFile<InputStubMemory>(inputStub7, fin_inputstub7, ievt);
  // writeMemFromFile<InputStubMemory>(inputStub8, fin_inputstub8, ievt);

  // bx - bunch crossing
  BXType bx = ievt;
  BXType bx_out;

  // Unit Under Test
	VMRouterTop(bx, inputStub,
			allStub, meMemories, teiMemories, olMemories);

  // compare the computed outputs with the expected ones
  // add 1 per stub that is incorrect
  bool truncation = false;

  // AllStub
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[0], fout_allstub_n1, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[1], fout_allstub_n2, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[2], fout_allstub_n3, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[3], fout_allstub_n4, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[4], fout_allstub_n5, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<BARRELPS>>(allStub[5], fout_allstub_n6, ievt, "AllStub", truncation);

  // ME Memories
  // VMStubME1
  err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[0], fout_vmstubme1, ievt, "VMStubME17", truncation);
  // VMStubME2
  err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[1], fout_vmstubme2, ievt, "VMStubME18", truncation);
  // VMStubME3
  err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[2], fout_vmstubme3, ievt, "VMStubME19", truncation);
  // VMStubME4
  err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(meMemories[3], fout_vmstubme4, ievt, "VMStubME20", truncation);

  // TE Memories
  //VMStubTEInner1
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[0][0], fout_vmstubtei1_n1, ievt, "VMStubTEInner17", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[0][1], fout_vmstubtei1_n2, ievt, "VMStubTEInner17", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[0][2], fout_vmstubtei1_n3, ievt, "VMStubTEInner17", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[0][3], fout_vmstubtei1_n4, ievt, "VMStubTEInner17", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[0][4], fout_vmstubtei1_n5, ievt, "VMStubTEInner17", truncation);
  // VMStubTEInner2
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[1][0], fout_vmstubtei2_n1, ievt, "VMStubTEInner18", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[1][1], fout_vmstubtei2_n2, ievt, "VMStubTEInner18", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[1][2], fout_vmstubtei2_n3, ievt, "VMStubTEInner18", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[1][3], fout_vmstubtei2_n4, ievt, "VMStubTEInner18", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[1][4], fout_vmstubtei2_n5, ievt, "VMStubTEInner18", truncation);

  // VMStubTEInner3
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[2][0], fout_vmstubtei3_n1, ievt, "VMStubTEInner19", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[2][1], fout_vmstubtei3_n2, ievt, "VMStubTEInner19", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[2][2], fout_vmstubtei3_n3, ievt, "VMStubTEInner19", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[2][3], fout_vmstubtei3_n4, ievt, "VMStubTEInner19", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[2][4], fout_vmstubtei3_n5, ievt, "VMStubTEInner19", truncation);

  // VMStubTEInner4
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[3][0], fout_vmstubtei4_n1, ievt, "VMStubTEInner20", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[3][1], fout_vmstubtei4_n2, ievt, "VMStubTEInner20", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[3][2], fout_vmstubtei4_n3, ievt, "VMStubTEInner20", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[3][3], fout_vmstubtei4_n4, ievt, "VMStubTEInner20", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(teiMemories[3][4], fout_vmstubtei4_n5, ievt, "VMStubTEInner20", truncation);

  // TE Inner Overlap memories
  // VMStubTEInner1 Overlap
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[0][0], fout_vmstubteol1_n1, ievt, "VMStubTEOverlap1", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[0][1], fout_vmstubteol1_n2, ievt, "VMStubTEOverlap1", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[0][2], fout_vmstubteol1_n3, ievt, "VMStubTEOverlap1", truncation);
  // VMStubTEInner2 Overlap
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[1][0], fout_vmstubteol2_n1, ievt, "VMStubTEOverlap2", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[1][1], fout_vmstubteol2_n2, ievt, "VMStubTEOverlap2", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(olMemories[1][2], fout_vmstubteol2_n3, ievt, "VMStubTEOverlap2", truncation);

  } // end of event loop

	std::cerr << "Exiting with return value " << err << std::endl;
	return err;

}
