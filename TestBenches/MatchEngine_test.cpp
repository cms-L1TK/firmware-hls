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

const int nevents = 100;  // number of events to run

using namespace std;

int main() {
	// Error counter
	int err_count = 0;

	// Declare input memory arrays to be read from the emulation files
	VMProjectionMemory<kProjectionType> inputvmprojs;
	VMStubMEMemory<kModuleType, kNBitBin> inputvmstubs;
	//CandidateMatchMemory inputcandmatches;

	// Declare output memory array to be filled by hls simulation
	CandidateMatchMemory outputcandmatches;

	// Define memory name patterns
	const string vmProjectionsPattern = "VMProjections*";
	const string vmStubsPattern = "VMStubs*";
	const string candidateMatchPattern = "CandidateMatches*";
        string meName = "";

	if (kLayerDisk == TF::L1) meName = "ME_L1PHIC12";
	else if (kLayerDisk == TF::L2) meName = "ME_L2PHIC20";
	else if (kLayerDisk == TF::L3) meName = "ME_L3PHIC20";
	else if (kLayerDisk == TF::L4) meName = "ME_L4PHIC20";
	else if (kLayerDisk == TF::L5) meName = "ME_L5PHIC20";
	else if (kLayerDisk == TF::L6) meName = "ME_L6PHIC20";
	else if (kLayerDisk == TF::D1) meName = "ME_D1PHIC20";
	else if (kLayerDisk == TF::D2) meName = "ME_D2PHIC12";
	else if (kLayerDisk == TF::D3) meName = "ME_D3PHIC12";
	else if (kLayerDisk == TF::D4) meName = "ME_D4PHIC12";
	else if (kLayerDisk == TF::D5) meName = "ME_D5PHIC12";
        assert(meName != "");

	// Open the file(s) with the input projections, the stubs, and the reference results
	TBHelper tbh("ME/" + meName);
	if (tbh.nFiles(vmProjectionsPattern) != 1)  return -1;
	if (tbh.nFiles(vmStubsPattern) != 1)        return -2;
	if (tbh.nFiles(candidateMatchPattern) != 1) return -3;

	std::cout << "Loaded the input files:\n"
			  << "\t" << tbh.fileNames(vmProjectionsPattern).at(0) << "\n"
			  << "\t" << tbh.fileNames(vmStubsPattern).at(0) << "\n"
			  << "\t" << tbh.fileNames(candidateMatchPattern).at(0) << std::endl;

	auto & fin_vmproj = tbh.files(vmProjectionsPattern).at(0);
	auto & fin_vmstub = tbh.files(vmStubsPattern).at(0);
	auto & fin_candmatch = tbh.files(candidateMatchPattern).at(0);

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

	// This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
	if (err_count > 255) err_count = 255;
	return err_count;
}
