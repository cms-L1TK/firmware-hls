// ProjectionRouter test bench

// cms-tracklet/firmware-hls Headers
#include "MatchEngineTop.h"
#include "CandidateMatchMemory.h"
#include "VMProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "FileReadUtility.h"
#include "Macros.h"

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

// No macros can be defined from the command line in the case of C/RTL
// cosimulation, so we define defaults here.
#if !defined KLAYERDISK
  #define KLAYERDISK 10 // e.g. a value of 2 corresponds to TF::L3
#endif

constexpr auto kLayerDisk = static_cast<TF::layerDisk>(KLAYERDISK);

#define LAYER_1 ME_L1PHIC12_
#define LAYER_2 ME_L2PHIC20_
#define LAYER_3 ME_L3PHIC20_
#define LAYER_4 ME_L4PHIC20_
#define LAYER_5 ME_L5PHIC20_
#define LAYER_6 ME_L6PHIC20_
#define DISK_1 ME_D1PHIC20_
#define DISK_2 ME_D2PHIC12_
#define DISK_3 ME_D3PHIC12_
#define DISK_4 ME_D4PHIC12_
#define DISK_5 ME_D5PHIC12_


#if !defined KMODULE
	#if (KLAYERDISK == 0)
		#define KMODULE LAYER_1
	#elif (KLAYERDISK == 1)
		#define KMODULE LAYER_2
	#elif (KLAYERDISK == 2)
		#define KMODULE LAYER_3
	#elif (KLAYERDISK == 3)
		#define KMODULE LAYER_4
	#elif (KLAYERDISK == 4)
		#define KMODULE LAYER_5
	#elif (KLAYERDISK == 5)
		#define KMODULE LAYER_6
	#elif (KLAYERDISK == 6)
                #define KMODULE DISK_1
	#elif (KLAYERDISK == 7)
                #define KMODULE DISK_2
	#elif (KLAYERDISK == 8)
                #define KMODULE DISK_3
	#elif (KLAYERDISK == 9)
                #define KMODULE DISK_4
	#elif (KLAYERDISK == 10)
                #define KMODULE DISK_5
	#else
		
	#endif
#endif
#if !defined TOPFUNCTION
	#if (KLAYERDISK == 0)
		#define TOPFUNCTION MatchEngineTop_L1
	#elif (KLAYERDISK == 1)
		#define TOPFUNCTION MatchEngineTop_L2
	#elif (KLAYERDISK == 2)
		#define TOPFUNCTION MatchEngineTop_L3
	#elif (KLAYERDISK == 3)
		#define TOPFUNCTION MatchEngineTop_L4
	#elif (KLAYERDISK == 4)
		#define TOPFUNCTION MatchEngineTop_L5
	#elif (KLAYERDISK == 5)
		#define TOPFUNCTION MatchEngineTop_L6
	#elif (KLAYERDISK == 6)
                #define TOPFUNCTION MatchEngineTop_D1
        #elif (KLAYERDISK == 7)
                #define TOPFUNCTION MatchEngineTop_D2
        #elif (KLAYERDISK == 8)
                #define TOPFUNCTION MatchEngineTop_D3
        #elif (KLAYERDISK == 9)
                #define TOPFUNCTION MatchEngineTop_D4
        #elif (KLAYERDISK == 10)
                #define TOPFUNCTION MatchEngineTop_D5
	#else
		
	#endif
#endif


template<TF::layerDisk LayerDisk> constexpr int getLayerDiskNumber() {
	// Convert from the enum index (0-based) to the module name indexing (1-based)
  return LayerDisk <= TF::L6 ? LayerDisk + 1 : LayerDisk - (trklet::N_LAYER - 1);
}

int main() {
	// Error counter
	int err_count = 0;

	// Declare input memory arrays to be read from the emulation files
	VMProjectionMemory<ProjectionType<kLayerDisk>()> inputvmprojs;
	VMStubMEMemory<ModuleType<kLayerDisk>(), NBitMemAddr<kLayerDisk>(), NBitBin<kLayerDisk>()> inputvmstubs;
	//CandidateMatchMemory inputcandmatches;

	// Declare output memory array to be filled by hls simulation
	CandidateMatchMemory outputcandmatches;

	// Define memory name patterns
	const string vmProjectionsPattern = "VMProjections*";
	const string vmStubsPattern = "VMStubs*";
	const string candidateMatchPattern = "CandidateMatches*";
	string meName = module_name[KMODULE];

	// Check that the module name is valid and consistent
	std::cout << "Using the module " << meName << " (layer/disk 0-index enum = " << kLayerDisk
						<< ", label = " << getLayerDiskNumber<kLayerDisk>() << ")" << std::endl;
	assert(!meName.empty()); // Make sure the x-macros returned a name
	assert(meName.find(std::to_string(getLayerDiskNumber<kLayerDisk>())) != std::string::npos); // Make sure the kLayerDisk matches the module name

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

		writeMemFromFile<VMProjectionMemory<ProjectionType<kLayerDisk>()> >(inputvmprojs, fin_vmproj, ievt);
		writeMemFromFile<VMStubMEMemory<ModuleType<kLayerDisk>(), NBitMemAddr<kLayerDisk>(), NBitBin<kLayerDisk>()> >(inputvmstubs, fin_vmstub, ievt);

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
		TOPFUNCTION(bx,bx_out,inputvmstubs,inputvmprojs,outputcandmatches);

		// Compare the computed outputs with the expected ones for the candidate matches
		bool truncation = false;
		err_count += compareMemWithFile<CandidateMatchMemory,16,2>(outputcandmatches, fin_candmatch, ievt, "CandidateMatch",truncation);

	}  // End of event loop

	// This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
	if (err_count > 255) err_count = 255;
	return err_count;
}
