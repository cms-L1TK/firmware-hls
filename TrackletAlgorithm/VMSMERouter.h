// VMStubRouter

// Sort AllStubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// By writing VMStubME memories
// Each VMStubRouter correspond to one phi/AllStub region.
// Needed for when project is split over both PFGAs

#ifndef TrackletAlgorithm_VMStubRouter_h
#define TrackletAlgorithm_VMStubRouter_h

#include "ap_int.h"
#include <cassert>

#include "Constants.h"
#include "AllStubMemory.h"
#include "VMStubMEMemoryCM.h"
#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

/////////////////////////////////////////
// Constants


//////////////////////////////////////
// Functions used by the VMStubRouter

// 
// 
// 

// Returns a ME stub with all the values set
template<class T, regionType InOutType, int Layer, int Disk, bool isMEStub>
inline T createVMStubMEME(AllStub<InOutType> InputAS,
		const int index, const bool negDisk, const int lutTable[],
		const int phiCorrTable[], int& slot) {

	// The stub that is going to be returned
	T stub;

	// Values from Input AllStub
	auto z = InputAS.getZ();
	auto r = InputAS.getR();
	auto bend = InputAS.getBend();
	auto phi = InputAS.getPhi();
	auto phicorr = getPhiCorr<InOutType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius

	int nbitsr = r.length(); // Number of bits for r
	int nbitsz = z.length(); // Number of bits for z
	int nbitsfinerz = stub.getFineZ().length(); // Number of bits for finer/z
	int nbitsfinephi = stub.getFinePhi().length();  // Number of bits for finephi

	// Number of bits for table indices
	constexpr int nbitsztable = (Layer) ? kNbitszfinebintable : kNbitszfinebintableDisk; // Number of MSBs of z used in LUT table
	constexpr int nbitsrtable = (Layer) ? kNbitsrfinebintable : kNbitsrfinebintableDisk; // Number of MSBs of r used in LUT table
	constexpr auto vmbits = (Layer) ? nbits_vmmeall[Layer-1] : ((isMEStub) ? nbits_vmmeall[trklet::N_LAYER+Disk-1] : nbitsvmtedisk[Disk-1]); // Number of bits for standard VMs
	constexpr unsigned int nbitsall = (Layer) ? nbitsallstubs[Layer-1] : nbitsallstubs[trklet::N_LAYER+Disk-1]; // Number of bits for the number of Alltub memories in a layer/disk

	// Number of bits for the memory bins
	constexpr int nbitsbin = (isMEStub) ? ((Layer) ? MEBinsBits : MEBinsBits + 1) : TEBinsBits; // ME in disks has double the amount of bins

	// Set values to VMStub
	stub.setBend(bend);
	stub.setIndex(index);
	stub.setFinePhi(iphivmFineBins<InOutType>(phicorr, nbitsall + vmbits, nbitsfinephi));

	// Indices used to find the rzfine value in LUT table
	// LUT table returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nbitsztable + nbitsrtable> indexz = (z >> (nbitsz - nbitsztable)); // Make z unsigned and take the top "nbitsztable" bits
	ap_uint<nbitsrtable> indexr = -1;

	constexpr int rbins = (1 << nbitsrtable); // Number of bins in r in LUT table

	if (Disk) {
		if (negDisk) {
			indexz = (1 << nbitsztable) -1 - indexz;
		}
		indexr = r;
		if (InOutType == DISKPS) {
			indexr = r >> (nbitsr - nbitsrtable); // Take the top "nbitsrtable" bits
		}
	} else { // Layer
		indexr = (r >> (nbitsr- nbitsrtable));// Make r unsigned and take the top "nbitsrtable" bits
	}

	// The index for LUT table
	ap_uint<nbitsztable + nbitsrtable> lutIndex = (indexz * rbins) + indexr;

	// Get the LUT value
	auto lutValue = lutTable[lutIndex];

	// Coarse z. The bin the stub is going to be put in, in the memory
	int bin = lutValue >> nbitsfinerz; // 3 bits, i.e. max 8 bins within each VM

	if (negDisk) bin += 1 << (nbitsbin-1); // The upper half of the bins are for negative disks
	
	auto ivm = phicorr.range(phicorr.length() - nbitsall - 1, phicorr.length() - (nbitsall + vmbits)); //get the phi bits that corresponds to the old vms
	slot = ivm * (1 << nbitsbin) + bin;

	// Set rzfine, i.e. the r/z bits within a coarse r/z region
	auto rzfine = lutValue & ((1 << nbitsfinerz) - 1); // the 3 LSB as rzfine
	stub.setFineZ(rzfine);

	assert(rzfine >= 0);

	return stub;
};

/////////////////////////////////
// Main function

// Two input region types InOutType and DISK2S due to the disks having both 2S and PS inputs.
template<int Layer, regionType InOutType, int rzSizeME, int phiRegSize>
void VMSMERouter(const BXType bx, BXType& bx_o,
		// LUTs
		const int METable[],
		const int phiCorrTable[],
		// Input memories
		AllStubMemory<InOutType> memoriesAS,
		// ME memories
		VMStubMEMemoryCM<InOutType, rzSizeME, phiRegSize, kNMatchEngines> *memoryME) {

#pragma HLS inline
#pragma HLS array_partition variable=memoriesAS complete dim=1

	// Number of data in each input memory
	typename InputStubMemory<InOutType>::NEntryT nInputs[nInputMems
			+ nInputDisk2SMems]; // Array containing the number of inputs
#pragma HLS array_partition variable=nInputs complete dim=0

	//Keeps track of input memories that still have stubs to process, one bit per memory
	ap_uint<nInputMems + nInputDisk2SMems> hasStubs;

	for (int i = 0; i < nInputMems; i++) {
#pragma HLS UNROLL
		nInputs[i] = inputStubs[i].getEntries(bx);
		hasStubs[i] = nInputs[i];
	}
	// For DISK2S
	for (int i = nInputMems; i < nInputMems + nInputDisk2SMems; i++) {
#pragma HLS UNROLL
		nInputs[i] = inputStubsDisk2S[i - nInputMems].getEntries(bx);
		hasStubs[i] = nInputs[i];
	}

	//Create variables that keep track of which memory address to read and write to
	ap_uint<kNBits_MemAddr> read_addr(0); // Reading of input stubs
	ap_uint<5> addrCountME[1 << (rzSizeME + phiRegSize)]; // Writing of ME stubs, number of bits taken from whatever is defined in the memories: (4+rzSize + phiRegSize)-(rzSize + phiRegSize)+1
#pragma HLS array_partition variable=addrCountME complete dim=0

	for (int i = 0; i < 1 << (rzSizeME + phiRegSize); i++) {
#pragma HLS unroll
		addrCountME[i] = 0;
	}

	/////////////////////////////////////
	// Main Loop

	constexpr int maxLoop = kMaxProc;

	TOPLEVEL: for (int i = 0; i < maxLoop; ++i) {
#pragma HLS PIPELINE II=1 rewind
#pragma HLS latency min = 12 //this ensures latencies of different vmrs match in a reduced configuration.
		bool noStubsLeft = !hasStubs.or_reduce(); // Determines if we have processed all stubs. Is true if hasStubs is all 0s
		bool resetNext = false; // Used to reset read_addr
		bool disk2S = false; // Used to determine if DISK2S
		bool negDisk = false; // Used to determine if it's negative disk

		AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);
		AllStub<DISKPS>       stub_ps = AllStub<DISKPS>(stub.raw());
		AllStub<DISK2S>       stub_2s = AllStub<DISK2S>(stub.raw());

		constexpr bool isDisk = LAYER >= TF::D1;

		auto isPSStub = stub_ps.isPSStub();

		// Read a stub. The input memories are in the order PS, negPS, 2S, neg2S
		int mem_index = __builtin_ctz(hasStubs); // The first non-zero index

		if (!noStubsLeft) {
			if (mem_index < nInputMems) {
				stub = inputStubs[mem_index].read_mem(bx, read_addr);
				if (InOutType == DISKPS) {
					negDisk = mem_index >= (nInputMems >> 1);
				}
			} else { // For DISK2S
				stubDisk2S = inputStubsDisk2S[mem_index - nInputMems].read_mem(bx, read_addr);
				disk2S = true;
				negDisk = mem_index >= nInputMems + (nInputDisk2SMems >> 1);
			}
			resetNext = nInputs[mem_index] == 1;
			hasStubs[mem_index] = !resetNext;
			--nInputs[mem_index];
		}

		// Increment the read address, or reset it to zero when all stubs in a memory has been read
		if (resetNext) read_addr = 0;
		else ++read_addr;

		if (noStubsLeft) continue; // End here if we already have processed all stubs
		// Note: putting the continue here rather than at the start of the loop seems to yield better timing.

		/////////////////////////////////////////////
		// ME memories

		int slotME; // The bin the stub is going to be put in, in the memory

		// Create the ME stub to save
		VMStubMECM<InOutType> stubME = (disk2S) ? 
				createVMStubME<VMStubMECM<InOutType>, DISK2S, InOutType, Layer, Disk, true>(stubDisk2S, i, negDisk,METable, phiCorrTable, slotME) :
				createVMStubME<VMStubMECM<InOutType>, InOutType, InOutType, Layer, Disk, true>(stub, i, negDisk, METable, phiCorrTable, slotME);

		// Write the ME stub
		memoryME->write_mem(bx, slotME, stubME, addrCountME[slotME]);
		addrCountME[slotME] += 1;

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
		edm::LogVerbatim("L1trackHLS") << "ME stub " << std::hex << stubME.raw() << std::dec << "       to slot " << slotME;
#endif // VMRCM_DEBUG
		// End ME memories

	} // Outside main loop

	bx_o = bx;
} // End VMRouterCM

#endif // TrackletAlgorithm_VMRouterCM_h
