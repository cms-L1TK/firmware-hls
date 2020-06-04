// Test bench for VMRouter
#include "VMRouterTop.h"

#include <algorithm>
#include <iterator>

#include "FileReadUtility.h"
#include "Constants.h"

const int nevents = 100;  //number of events to run

using namespace std;

// VMRouter Test for Layer 1, Allstub region E

int main() {
// error counts
	int err = 0;

///////////////////////////
// input memories
	static InputStubMemory<BARRELPS> ilink1;
	static InputStubMemory<BARRELPS> ilink2;
	static InputStubMemory<BARRELPS> ilink3;
	static InputStubMemory<BARRELPS> ilink4;
	static InputStubMemory<BARRELPS> ilink5;
	static InputStubMemory<BARRELPS> ilink6;
// static InputStubMemory<BARRELPS> ilink7;
// static InputStubMemory<BARRELPS> ilink8;

// output memories
	static AllStubMemory<BARRELPS> allstub;
// ME memories
	static VMStubMEMemory<BARRELPS> vmstubme1;
	static VMStubMEMemory<BARRELPS> vmstubme2;
	static VMStubMEMemory<BARRELPS> vmstubme3;
	static VMStubMEMemory<BARRELPS> vmstubme4;
	static VMStubMEMemory<BARRELPS> vmstubme5;
	static VMStubMEMemory<BARRELPS> vmstubme6;
	static VMStubMEMemory<BARRELPS> vmstubme7;
	static VMStubMEMemory<BARRELPS> vmstubme8;
// TE Inner
	static VMStubTEInnerMemory<BARRELPS> vmstubtei1;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei2;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei3;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei4;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei5;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei6;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei7;
	static VMStubTEInnerMemory<BARRELPS> vmstubtei8;
// TE Inner Overlap
	static VMStubTEInnerMemory<BARRELOL> vmstubteol1;
	static VMStubTEInnerMemory<BARRELOL> vmstubteol2;

///////////////////////////
// open input files
	cout << "Open files..." << endl;

	ifstream fin_ilink1;
	bool validin1 = openDataFile(fin_ilink1,
			"MemPrints/InputStubs/InputStubs_IL_L1PHIE_PS10G_1_B_04.dat");
	if (not validin1)
		return -1;

	ifstream fin_ilink2;
	bool validin2 = openDataFile(fin_ilink2,
			"MemPrints/InputStubs/InputStubs_IL_L1PHIE_PS10G_2_B_04.dat");
	if (not validin2)
		return -1;

	ifstream fin_ilink3;
	bool validin3 = openDataFile(fin_ilink3,
			"MemPrints/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_1_B_04.dat");
	if (not validin3)
		return -1;

	ifstream fin_ilink4;
	bool validin4 = openDataFile(fin_ilink4,
			"MemPrints/InputStubs/InputStubs_IL_L1PHIE_neg_PS10G_2_B_04.dat");
	if (not validin4)
		return -1;

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
	bool valid_aproj = openDataFile(fout_aproj,
			"MemPrints/Stubs/AllStubs_AS_L1PHIEn1_04.dat");
	if (not valid_aproj)
		return -1;

	ifstream fout_vmstubme1;
	bool valid_vmstubme1 = openDataFile(fout_vmstubme1,
			"MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE17n1_04.dat");
	if (not valid_vmstubme1)
		return -1;

	ifstream fout_vmstubme2;
	bool valid_vmstubme2 = openDataFile(fout_vmstubme2,
			"MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE18n1_04.dat");
	if (not valid_vmstubme2)
		return -1;

	ifstream fout_vmstubme3;
	bool valid_vmstubme3 = openDataFile(fout_vmstubme3,
			"MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE19n1_04.dat");
	if (not valid_vmstubme3)
		return -1;

	ifstream fout_vmstubme4;
	bool valid_vmstubme4 = openDataFile(fout_vmstubme4,
			"MemPrints/VMStubsME/VMStubs_VMSME_L1PHIE20n1_04.dat");
	if (not valid_vmstubme4)
		return -1;

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

// TE Inner
	ifstream fout_vmstubtei1;
	bool valid_vmstubtei1 = openDataFile(fout_vmstubtei1,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE17n1_04.dat");
	if (not valid_vmstubtei1)
		return -1;

	ifstream fout_vmstubtei2;
	bool valid_vmstubtei2 = openDataFile(fout_vmstubtei2,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE18n1_04.dat");
	if (not valid_vmstubtei2)
		return -1;

	ifstream fout_vmstubtei3;
	bool valid_vmstubtei3 = openDataFile(fout_vmstubtei3,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE19n1_04.dat");
	if (not valid_vmstubtei3)
		return -1;

	ifstream fout_vmstubtei4;
	bool valid_vmstubtei4 = openDataFile(fout_vmstubtei4,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIE20n1_04.dat");
	if (not valid_vmstubtei4)
		return -1;

// TE Inner Overlap
	ifstream fout_vmstubteol1;
	bool valid_vmstubteol1 = openDataFile(fout_vmstubteol1,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ9n1_04.dat");
	if (not valid_vmstubteol1)
		return -1;

	ifstream fout_vmstubteol2;
	bool valid_vmstubteol2 = openDataFile(fout_vmstubteol2,
			"MemPrints/VMStubsTE/VMStubs_VMSTE_L1PHIQ10n1_04.dat");

///////////////////////////
// loop over events
	cout << "Start event loop ..." << endl;
	for (unsigned int ievt = 0; ievt < nevents; ++ievt) {
		cout << "Event: " << dec << ievt << endl;

		// read event and write to memories
		writeMemFromFile<InputStubMemory<BARRELPS>>(ilink1, fin_ilink1, ievt);
		writeMemFromFile<InputStubMemory<BARRELPS>>(ilink2, fin_ilink2, ievt);
		writeMemFromFile<InputStubMemory<BARRELPS>>(ilink3, fin_ilink3, ievt);
		writeMemFromFile<InputStubMemory<BARRELPS>>(ilink4, fin_ilink4, ievt);
		// writeMemFromFile<InputStubMemory>(ilink5, fin_ilink5, ievt);
		// writeMemFromFile<InputStubMemory>(ilink6, fin_ilink6, ievt);
		// writeMemFromFile<InputStubMemory>(ilink7, fin_ilink7, ievt);
		// writeMemFromFile<InputStubMemory>(ilink8, fin_ilink8, ievt);

		// bx - bunch crossing
		BXType bx = ievt;
		BXType bx_out;

		// Unit Under Test
		// Unit Under Test
		VMRouterTop(bx, &ilink1, &ilink2, &ilink3, &ilink4, nullptr, nullptr,
				//&ilink7, &ilink8,
				&allstub, &vmstubme1, &vmstubme2, &vmstubme3, &vmstubme4,
				&vmstubme5, &vmstubme6, &vmstubme7, &vmstubme8, &vmstubtei1,
				&vmstubtei2, &vmstubtei3, &vmstubtei4, &vmstubtei5, &vmstubtei6,
				&vmstubtei7, &vmstubtei8, &vmstubteol1, &vmstubteol2);

		// compare the computed outputs with the expected ones
		// add 1 per stub that is incorrect
		bool truncation = false;
		// AllStub
		err += compareMemWithFile<AllStubMemory<BARRELPS>>(allstub, fout_aproj,
				ievt, "AllStub", truncation);
		// VMStubME1
		err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme1,
				fout_vmstubme1, ievt, "VMStubME17", truncation);

		// VMStubME2
		err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme2,
				fout_vmstubme2, ievt, "VMStubME18", truncation);

		// VMStubME3
		err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme3,
				fout_vmstubme3, ievt, "VMStubME19", truncation);

		// VMStubME4
		err += compareBinnedMemWithFile<VMStubMEMemory<BARRELPS>>(vmstubme4,
				fout_vmstubme4, ievt, "VMStubME20", truncation);

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

//VMStubTEInner1
		err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(vmstubtei1,
				fout_vmstubtei1, ievt, "VMStubTEInner17", truncation);

// VMStubTEInner2
		err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(vmstubtei2,
				fout_vmstubtei2, ievt, "VMStubTEInner18", truncation);

// VMStubTEInner3
		err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(vmstubtei3,
				fout_vmstubtei3, ievt, "VMStubTEInner19", truncation);

// VMStubTEInner4
		err += compareMemWithFile<VMStubTEInnerMemory<BARRELPS>>(vmstubtei4,
				fout_vmstubtei4, ievt, "VMStubTEInner20", truncation);

//VMStubTEInner1 Overlap
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(vmstubteol1, fout_vmstubteol1, ievt,
                                              "VMStubTEOverlap1", truncation);

// VMStubTEInner2 Overlap
err += compareMemWithFile<VMStubTEInnerMemory<BARRELOL>>(vmstubteol2, fout_vmstubteol2, ievt,
                                              "VMStubTEOverlap2", truncation);
	} // end of event loop
	std::cerr << "Exiting with return value " << err << std::endl;
	return err;

}
