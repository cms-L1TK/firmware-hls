// Test bench for VMRouter
#include "VMRouterTop_D1.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 100;  //number of events to run

using namespace std;

// VMRouter Top Function for Layer 6, AllStub region A

int main()
{
  // error counts
  int err = 0;

  ///////////////////////////
  // input memories
  static InputStubMemory<DISK2S> inputStub1;
  static InputStubMemory<DISKPS> inputStub2;
  static InputStubMemory<DISKPS> inputStub3;
  static InputStubMemory<DISK2S> inputStub4;
  static InputStubMemory<DISKPS> inputStub5;
  static InputStubMemory<DISKPS> inputStub6;

  // output memories
  static AllStubMemory<DISK> allStub[6];
  // ME memories
  static VMStubMEMemory<DISK> meMemories[8];
	// TE Inner memories
	static VMStubTEInnerMemory<DISK> teiMemories[4][3];
  // TE Inner Overlap memories, including copies
  //static VMStubTEInnerMemory<BARRELOL> olMemories[1][1];
  // TE Outer memories
  static VMStubTEOuterMemory<DISK> teoMemories[4][5];
  
  
  ///////////////////////////
  // open input files
  cout << "Open files..." << endl;

  ifstream fin_inputstub1;
  bool validin1 = openDataFile(fin_inputstub1, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_2S_5_A_04.dat");
  if (not validin1) return -1;

  ifstream fin_inputstub2;
  bool validin2 = openDataFile(fin_inputstub2, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_PS10G_2_A_04.dat");
  if (not validin2) return -1;

  ifstream fin_inputstub3;
  bool validin3 = openDataFile(fin_inputstub3, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_PS5G_4_A_04.dat");
  if (not validin3) return -1;

  ifstream fin_inputstub4;
  bool validin4 = openDataFile(fin_inputstub4, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_neg_2S_5_A_04.dat");
  if (not validin4) return -1;

  ifstream fin_inputstub5;
  bool validin5 = openDataFile(fin_inputstub5, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_neg_PS10G_2_A_04.dat");
  if (not validin5) return -1;

  ifstream fin_inputstub6;
  bool validin6 = openDataFile(fin_inputstub6, "MemPrints/InputStubs/InputStubs_IL_D1PHIA_neg_PS5G_4_A_04.dat");
  if (not validin6) return -1;


  ///////////////////////////
  // open output files
  
  // AllStub
  ifstream fout_allstub_n1;
  bool valid_allstub_n1 = openDataFile(fout_allstub_n1, "MemPrints/Stubs/AllStubs_AS_D1PHIAn1_04.dat");
  if (not valid_allstub_n1) return -1;
  
  ifstream fout_allstub_n2;
  bool valid_allstub_n2 = openDataFile(fout_allstub_n2, "MemPrints/Stubs/AllStubs_AS_D1PHIAn2_04.dat");
  if (not valid_allstub_n2) return -1;
  
  ifstream fout_allstub_n3;
  bool valid_allstub_n3 = openDataFile(fout_allstub_n3, "MemPrints/Stubs/AllStubs_AS_D1PHIAn3_04.dat");
  if (not valid_allstub_n3) return -1;
  
  ifstream fout_allstub_n4;
  bool valid_allstub_n4 = openDataFile(fout_allstub_n4, "MemPrints/Stubs/AllStubs_AS_D1PHIAn4_04.dat");
  if (not valid_allstub_n4) return -1;
  
  ifstream fout_allstub_n5;
  bool valid_allstub_n5 = openDataFile(fout_allstub_n5, "MemPrints/Stubs/AllStubs_AS_D1PHIAn5_04.dat");
  if (not valid_allstub_n5) return -1;
  
  ifstream fout_allstub_n6;
  bool valid_allstub_n6 = openDataFile(fout_allstub_n6, "MemPrints/Stubs/AllStubs_AS_D1PHIAn6_04.dat");
  if (not valid_allstub_n6) return -1;
  
  // ME memories
  ifstream fout_vmstubme1;
  bool valid_vmstubme1 =  openDataFile(fout_vmstubme1, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA1n1_04.dat");
  if (not valid_vmstubme1) return -1;

  ifstream fout_vmstubme2;
  bool valid_vmstubme2 = openDataFile(fout_vmstubme2, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA2n1_04.dat");
  if (not valid_vmstubme2) return -1;

  ifstream fout_vmstubme3;
  bool valid_vmstubme3 = openDataFile(fout_vmstubme3, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA3n1_04.dat");
  if (not valid_vmstubme3) return -1;

  ifstream fout_vmstubme4;
  bool valid_vmstubme4 = openDataFile(fout_vmstubme4, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA4n1_04.dat");
  if (not valid_vmstubme4) return -1;

  ifstream fout_vmstubme5;
  bool valid_vmstubme5 =  openDataFile(fout_vmstubme5, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA5n1_04.dat");
  if (not valid_vmstubme5) return -1;

  ifstream fout_vmstubme6;
  bool valid_vmstubme6 = openDataFile(fout_vmstubme6, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA6n1_04.dat");
  if (not valid_vmstubme6) return -1;

  ifstream fout_vmstubme7;
  bool valid_vmstubme7 = openDataFile(fout_vmstubme7, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA7n1_04.dat");
  if (not valid_vmstubme7) return -1;

  ifstream fout_vmstubme8;
  bool valid_vmstubme8 = openDataFile(fout_vmstubme8, "MemPrints/VMStubsME/VMStubs_VMSME_D1PHIA8n1_04.dat");
  if (not valid_vmstubme8) return -1;

  // TE inner
  // 1
  ifstream fout_vmstubtei1_n1;
  bool valid_vmstubtei1_n1 =  openDataFile(fout_vmstubtei1_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA1n1_04.dat");
  if (not valid_vmstubtei1_n1) return -1;

  ifstream fout_vmstubtei1_n2;
  bool valid_vmstubtei1_n2 =  openDataFile(fout_vmstubtei1_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA1n2_04.dat");
  if (not valid_vmstubtei1_n2) return -1;
  
  // ifstream fout_vmstubtei1_n3;
  // bool valid_vmstubtei1_n3 =  openDataFile(fout_vmstubtei1_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA1n3_04.dat");
  // if (not valid_vmstubtei1_n3) return -1;
  
  // 2
  ifstream fout_vmstubtei2_n1;
  bool valid_vmstubtei2_n1 = openDataFile(fout_vmstubtei2_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA2n1_04.dat");
  if (not valid_vmstubtei2_n1) return -1;
  
  ifstream fout_vmstubtei2_n2;
  bool valid_vmstubtei2_n2 = openDataFile(fout_vmstubtei2_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA2n2_04.dat");
  if (not valid_vmstubtei2_n2) return -1;
  
  ifstream fout_vmstubtei2_n3;
  bool valid_vmstubtei2_n3 = openDataFile(fout_vmstubtei2_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA2n3_04.dat");
  if (not valid_vmstubtei2_n3) return -1;

  // 3
  ifstream fout_vmstubtei3_n1;
  bool valid_vmstubtei3_n1 = openDataFile(fout_vmstubtei3_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA3n1_04.dat");
  if (not valid_vmstubtei3_n1) return -1;

  ifstream fout_vmstubtei3_n2;
  bool valid_vmstubtei3_n2 = openDataFile(fout_vmstubtei3_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA3n2_04.dat");
  if (not valid_vmstubtei3_n2) return -1;
  
  ifstream fout_vmstubtei3_n3;
  bool valid_vmstubtei3_n3 = openDataFile(fout_vmstubtei3_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA3n3_04.dat");
  if (not valid_vmstubtei3_n3) return -1;
  
  // 4
  ifstream fout_vmstubtei4_n1;
  bool valid_vmstubtei4_n1 = openDataFile(fout_vmstubtei4_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA4n1_04.dat");
  if (not valid_vmstubtei4_n1) return -1;
  
  ifstream fout_vmstubtei4_n2;
  bool valid_vmstubtei4_n2 = openDataFile(fout_vmstubtei4_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA4n2_04.dat");
  if (not valid_vmstubtei4_n2) return -1;
  
  ifstream fout_vmstubtei4_n3;
  bool valid_vmstubtei4_n3 = openDataFile(fout_vmstubtei4_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA4n3_04.dat");
  if (not valid_vmstubtei4_n3) return -1;

  // ifstream fout_vmstubtei5;
  // bool valid_vmstubtei5 =  openDataFile(fout_vmstubtei5, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA5n1_04.dat");
  // if (not valid_vmstubtei5) return -1;
  //
  // ifstream fout_vmstubtei6;
  // bool valid_vmstubtei6 = openDataFile(fout_vmstubtei6, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA6n1_04.dat");
  // if (not valid_vmstubtei6) return -1;
  //
  // ifstream fout_vmstubtei7;
  // bool valid_vmstubtei7 = openDataFile(fout_vmstubtei7, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA7n1_04.dat");
  // if (not valid_vmstubtei7) return -1;
  //
  // ifstream fout_vmstubtei8;
  // bool valid_vmstubtei8 = openDataFile(fout_vmstubtei8, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIA8n1_04.dat");
  // if (not valid_vmstubtei8) return -1;

  // TE Outer
  // 1
  ifstream fout_vmstubteo1_n1;
  bool valid_vmstubteo1_n1 = openDataFile(fout_vmstubteo1_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX1n1_04.dat");
  if (not valid_vmstubteo1_n1) return -1;

  ifstream fout_vmstubteo1_n2;
  bool valid_vmstubteo1_n2 = openDataFile(fout_vmstubteo1_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX1n2_04.dat");
  if (not valid_vmstubteo1_n2) return -1;
  
  ifstream fout_vmstubteo1_n3;
  bool valid_vmstubteo1_n3 = openDataFile(fout_vmstubteo1_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX1n3_04.dat");
  if (not valid_vmstubteo1_n3) return -1;
  
  // ifstream fout_vmstubteo1_n4;
  // bool valid_vmstubteo1_n4 = openDataFile(fout_vmstubteo1_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX1n4_04.dat");
  // if (not valid_vmstubteo1_n4) return -1;
  
  // ifstream fout_vmstubteo1_n5;
  // bool valid_vmstubteo1_n5 = openDataFile(fout_vmstubteo1_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX1n5_04.dat");
  // if (not valid_vmstubteo1_n5) return -1;
  
  // 2
  ifstream fout_vmstubteo2_n1;
  bool valid_vmstubteo2_n1 = openDataFile(fout_vmstubteo2_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX2n1_04.dat");
  if (not valid_vmstubteo2_n1) return -1;
  
  ifstream fout_vmstubteo2_n2;
  bool valid_vmstubteo2_n2 = openDataFile(fout_vmstubteo2_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX2n2_04.dat");
  if (not valid_vmstubteo2_n2) return -1;
  
  ifstream fout_vmstubteo2_n3;
  bool valid_vmstubteo2_n3 = openDataFile(fout_vmstubteo2_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX2n3_04.dat");
  if (not valid_vmstubteo2_n3) return -1;
  
  ifstream fout_vmstubteo2_n4;
  bool valid_vmstubteo2_n4 = openDataFile(fout_vmstubteo2_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX2n4_04.dat");
  if (not valid_vmstubteo2_n4) return -1;
  
  // ifstream fout_vmstubteo2_n5;
  // bool valid_vmstubteo2_n5 = openDataFile(fout_vmstubteo2_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX2n5_04.dat");
  // if (not valid_vmstubteo2_n5) return -1;
  
  // 3
  ifstream fout_vmstubteo3_n1;
  bool valid_vmstubteo3_n1 = openDataFile(fout_vmstubteo3_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX3n1_04.dat");
  if (not valid_vmstubteo3_n1) return -1;
  
  ifstream fout_vmstubteo3_n2;
  bool valid_vmstubteo3_n2 = openDataFile(fout_vmstubteo3_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX3n2_04.dat");
  if (not valid_vmstubteo3_n2) return -1;
  
  ifstream fout_vmstubteo3_n3;
  bool valid_vmstubteo3_n3 = openDataFile(fout_vmstubteo3_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX3n3_04.dat");
  if (not valid_vmstubteo3_n3) return -1;
  
  ifstream fout_vmstubteo3_n4;
  bool valid_vmstubteo3_n4 = openDataFile(fout_vmstubteo3_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX3n4_04.dat");
  if (not valid_vmstubteo3_n4) return -1;
  
  ifstream fout_vmstubteo3_n5;
  bool valid_vmstubteo3_n5 = openDataFile(fout_vmstubteo3_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX3n5_04.dat");
  if (not valid_vmstubteo3_n5) return -1;

  // 4
  ifstream fout_vmstubteo4_n1;
  bool valid_vmstubteo4_n1 = openDataFile(fout_vmstubteo4_n1, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX4n1_04.dat");
  if (not valid_vmstubteo4_n1) return -1;

  ifstream fout_vmstubteo4_n2;
  bool valid_vmstubteo4_n2 = openDataFile(fout_vmstubteo4_n2, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX4n2_04.dat");
  if (not valid_vmstubteo4_n2) return -1;
  
  ifstream fout_vmstubteo4_n3;
  bool valid_vmstubteo4_n3 = openDataFile(fout_vmstubteo4_n3, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX4n3_04.dat");
  if (not valid_vmstubteo4_n3) return -1;
  
  ifstream fout_vmstubteo4_n4;
  bool valid_vmstubteo4_n4 = openDataFile(fout_vmstubteo4_n4, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX4n4_04.dat");
  if (not valid_vmstubteo4_n4) return -1;
  
  ifstream fout_vmstubteo4_n5;
  bool valid_vmstubteo4_n5 = openDataFile(fout_vmstubteo4_n5, "MemPrints/VMStubsTE/VMStubs_VMSTE_D1PHIX4n5_04.dat");
  if (not valid_vmstubteo4_n5) return -1;
  
  ///////////////////////////
  // loop over events
  cout << "Start event loop ..." << endl;
  for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
    cout << "Event: " << dec << ievt << endl;

  // read event and write to memories
  writeMemFromFile<InputStubMemory<DISK2S>>(inputStub1, fin_inputstub1, ievt);
  writeMemFromFile<InputStubMemory<DISKPS>>(inputStub2, fin_inputstub2, ievt);
  writeMemFromFile<InputStubMemory<DISKPS>>(inputStub3, fin_inputstub3, ievt);
  writeMemFromFile<InputStubMemory<DISK2S>>(inputStub4, fin_inputstub4, ievt);
  writeMemFromFile<InputStubMemory<DISKPS>>(inputStub5, fin_inputstub5, ievt);
  writeMemFromFile<InputStubMemory<DISKPS>>(inputStub6, fin_inputstub6, ievt);

  // bx
  BXType bx = ievt;
  BXType bx_out;

  // Unit Under Test
  VMRouterTop(bx,
  		&inputStub1, &inputStub2, &inputStub3, &inputStub4, &inputStub5, &inputStub6,
      allStub, meMemories, teiMemories, teoMemories
	);

  // compare the computed outputs with the expected ones
  bool truncation = false;
  // AllStub
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[0], fout_allstub_n1, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[1], fout_allstub_n2, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[2], fout_allstub_n3, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[3], fout_allstub_n4, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[4], fout_allstub_n5, ievt, "AllStub", truncation);
  err += compareMemWithFile<AllStubMemory<DISK>>(allStub[5], fout_allstub_n6, ievt, "AllStub", truncation);
  
  // VMStubME1
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[0], fout_vmstubme1, ievt,"VMStubME1", truncation);
  
  // VMStubME2
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[1], fout_vmstubme2, ievt,"VMStubME2", truncation);
  
  // VMStubME3
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[2], fout_vmstubme3, ievt,"VMStubME3", truncation);
  
  // VMStubME4
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[3], fout_vmstubme4, ievt,"VMStubME4", truncation);
  
  // VMStubME5
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[4], fout_vmstubme5, ievt,"VMStubME5", truncation);
  
   // VMStubME6
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[5], fout_vmstubme6, ievt,"VMStubME6", truncation);
  
   // VMStubME7
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[6], fout_vmstubme7, ievt,"VMStubME7", truncation);
  
   // VMStubME8
  err += compareBinnedMemWithFile<VMStubMEMemory<DISK>>(meMemories[7], fout_vmstubme8, ievt,"VMStubME8", truncation);


  // TE Memories
  //VMStubTEInner1
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[0][0], fout_vmstubtei1_n1, ievt, "VMStubTEInner1", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[0][1], fout_vmstubtei1_n2, ievt, "VMStubTEInner1", truncation);
  // VMStubTEInner2
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[1][0], fout_vmstubtei2_n1, ievt, "VMStubTEInner2", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[1][1], fout_vmstubtei2_n2, ievt, "VMStubTEInner2", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[1][2], fout_vmstubtei2_n3, ievt, "VMStubTEInner2", truncation);
  
  // VMStubTEInner3
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[2][0], fout_vmstubtei3_n1, ievt, "VMStubTEInner3", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[2][1], fout_vmstubtei3_n2, ievt, "VMStubTEInner3", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[2][2], fout_vmstubtei3_n3, ievt, "VMStubTEInner3", truncation);

  // VMStubTEInner4
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[3][0], fout_vmstubtei4_n1, ievt, "VMStubTEInner4", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[3][1], fout_vmstubtei4_n2, ievt, "VMStubTEInner4", truncation);
  err += compareMemWithFile<VMStubTEInnerMemory<DISK>>(teiMemories[3][2], fout_vmstubtei4_n3, ievt, "VMStubTEInner4", truncation);


  // TE Memories
  // VMStubTEOuter1
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[0][0], fout_vmstubteo1_n1, ievt, "VMStubTEOuter1", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[0][1], fout_vmstubteo1_n2, ievt, "VMStubTEOuter1", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[0][2], fout_vmstubteo1_n3, ievt, "VMStubTEOuter1", truncation);

  // VMStubTEOuter2
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[1][0], fout_vmstubteo2_n1, ievt, "VMStubTEOuter2", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[1][1], fout_vmstubteo2_n2, ievt, "VMStubTEOuter2", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[1][2], fout_vmstubteo2_n3, ievt, "VMStubTEOuter2", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[1][3], fout_vmstubteo2_n4, ievt, "VMStubTEOuter2", truncation);
  // err += compareMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[1][4], fout_vmstubteo2_n5, ievt, "VMStubTEOuter2", truncation);
  
  // VMStubTEOuter3
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[2][0], fout_vmstubteo3_n1, ievt, "VMStubTEOuter3", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[2][1], fout_vmstubteo3_n2, ievt, "VMStubTEOuter3", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[2][2], fout_vmstubteo3_n3, ievt, "VMStubTEOuter3", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[2][3], fout_vmstubteo3_n4, ievt, "VMStubTEOuter3", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[2][4], fout_vmstubteo3_n5, ievt, "VMStubTEOuter3", truncation);
  
  // VMStubTEOuter4
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[3][0], fout_vmstubteo4_n1, ievt, "VMStubTEOuter4", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[3][1], fout_vmstubteo4_n2, ievt, "VMStubTEOuter4", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[3][2], fout_vmstubteo4_n3, ievt, "VMStubTEOuter4", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[3][3], fout_vmstubteo4_n4, ievt, "VMStubTEOuter4", truncation);
  err += compareBinnedMemWithFile<VMStubTEOuterMemory<DISK>>(teoMemories[3][4], fout_vmstubteo4_n5, ievt, "VMStubTEOuter4", truncation);
  
  } // end of event loop
  std::cerr << "Exiting with return value " << err << std::endl;
  return err;

}
