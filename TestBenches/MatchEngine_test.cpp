// ProjectionRouter test bench

// cms-tracklet/firmware-hls Headers
#include "MatchEngineTop.h"
#include "CandidateMatchMemory.h"
#include "VMProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "FileReadUtility.h"

// HLS Headers
#include "hls_math.h"

// STL Headers
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int nevents = 100;  // number of events to run

int main() {
	// Error counter
	int err_count = 0;

	// Declare input memory arrays to be read from the emulation files
	VMProjectionMemory<kProjectionType> inputvmprojs;
	VMStubMEMemory<kModuleType, kNBitBin> inputvmstubs;
	//CandidateMatchMemory inputcandmatches;

	// Declare output memory array to be filled by hls simulation
	CandidateMatchMemory outputcandmatches;

	// Open file(s) with the input projections, stubs, and reference results
	ifstream fin_vmproj;
	ifstream fin_vmstub;
	ifstream fin_candmatch;
	bool validvmproj    = false;
	bool validvmstub    = false;
	bool validcandmatch = false;
	if (LayerDisk == TF::L1) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L1PHIC12/VMProjections_VMPROJ_L1PHIC12_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L1PHIC12/VMStubs_VMSME_L1PHIC12n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L1PHIC12/CandidateMatches_CM_L1PHIC12_04.dat");
	}
	else if (LayerDisk == TF::L2) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L2PHIC20/VMProjections_VMPROJ_L2PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L2PHIC20/VMStubs_VMSME_L2PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L2PHIC20/CandidateMatches_CM_L2PHIC20_04.dat");
	}
	else if (LayerDisk == TF::L3) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L3PHIC20/VMProjections_VMPROJ_L3PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L3PHIC20/VMStubs_VMSME_L3PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L3PHIC20/CandidateMatches_CM_L3PHIC20_04.dat");
	}
	else if (LayerDisk == TF::L4) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L4PHIC20/VMProjections_VMPROJ_L4PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L4PHIC20/VMStubs_VMSME_L4PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L4PHIC20/CandidateMatches_CM_L4PHIC20_04.dat");
	}
	else if (LayerDisk == TF::L5) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L5PHIC20/VMProjections_VMPROJ_L5PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L5PHIC20/VMStubs_VMSME_L5PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L5PHIC20/CandidateMatches_CM_L5PHIC20_04.dat");
	}
	else if (LayerDisk == TF::L6) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_L6PHIC20/VMProjections_VMPROJ_L6PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_L6PHIC20/VMStubs_VMSME_L6PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_L6PHIC20/CandidateMatches_CM_L6PHIC20_04.dat");
	}
	else if (LayerDisk == TF::D1) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_D1PHIC20/VMProjections_VMPROJ_D1PHIC20_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_D1PHIC20/VMStubs_VMSME_D1PHIC20n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_D1PHIC20/CandidateMatches_CM_D1PHIC20_04.dat");
	}
	else if (LayerDisk == TF::D2) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_D2PHIC12/VMProjections_VMPROJ_D2PHIC12_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_D2PHIC12/VMStubs_VMSME_D2PHIC12n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_D2PHIC12/CandidateMatches_CM_D2PHIC12_04.dat");
	}
	else if (LayerDisk == TF::D3) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_D3PHIC12/VMProjections_VMPROJ_D3PHIC12_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_D3PHIC12/VMStubs_VMSME_D3PHIC12n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_D3PHIC12/CandidateMatches_CM_D3PHIC12_04.dat");
	}
	else if (LayerDisk == TF::D4) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_D4PHIC12/VMProjections_VMPROJ_D4PHIC12_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_D4PHIC12/VMStubs_VMSME_D4PHIC12n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_D4PHIC12/CandidateMatches_CM_D4PHIC12_04.dat");
	}
	else if (LayerDisk == TF::D5) {
		validvmproj    = openDataFile(fin_vmproj,"ME/ME_D5PHIC12/VMProjections_VMPROJ_D5PHIC12_04.dat");
		validvmstub    = openDataFile(fin_vmstub,"ME/ME_D5PHIC12/VMStubs_VMSME_D5PHIC12n1_04.dat");
		validcandmatch = openDataFile(fin_candmatch,"ME/ME_D5PHIC12/CandidateMatches_CM_D5PHIC12_04.dat");
	}
	if (not validvmproj) return -1;
	if (not validvmstub) return -2;
	if (not validcandmatch) return -3;

	// Loop over events
	for (int ievt = 0; ievt < nevents; ++ievt) {
		cout << "Event: " << dec << ievt << endl;

                outputcandmatches.clear();

		writeMemFromFile<VMProjectionMemory<kProjectionType> >(inputvmprojs, fin_vmproj, ievt);
		writeMemFromFile<VMStubMEMemory<kModuleType, kNBitBin> >(inputvmstubs, fin_vmstub, ievt);

		//Set bunch crossing
		BXType bx=ievt&0x7;
		BXType bx_out;

		//Print the number of projections and stubs
		std::cout << "In MatchEngine #proj ="<<std::hex<<inputvmprojs.getEntries(bx)<<" #stubs=";
		for (unsigned int zbin=0;zbin<8;zbin++){
			std::cout <<" "<<inputvmstubs.getEntries(bx,zbin);
		}
		std::cout<<std::dec<<std::endl;

		// Unit Under Test
		MatchEngineTop(bx,bx_out,inputvmstubs,inputvmprojs,outputcandmatches);

		// Compare the computed outputs with the expected ones for the candidate matches
		bool truncation = false;
		err_count += compareMemWithFile<CandidateMatchMemory,16,2>(outputcandmatches, fin_candmatch, ievt, "CandidateMatch",truncation);

	}  // End of event loop
  
	// Close files
	fin_vmstub.close();
	fin_vmproj.close();
	fin_candmatch.close();

        // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
        if (err_count > 255) err_count = 255;
	return err_count;
}
