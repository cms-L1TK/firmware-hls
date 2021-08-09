// VMRouterCM

// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// Several types of memories depending on which module that is going to read it.
// Each VMRouterCM correspond to one phi/AllStub region.
// Each memory type contain different bits of the same stub.

// NOTE: Nothing in VMRouterCM.h needs to be changed to run a different phi region

#ifndef TrackletAlgorithm_VMRouterCM_h
#define TrackletAlgorithm_VMRouterCM_h

#include "ap_int.h"
#include <cassert>

#include "Constants.h"
#include "InputStubMemory.h"
#include "AllStubMemory.h"
#include "AllStubInnerMemory.h"
#include "VMStubMEMemoryCM.h"
#include "VMStubTEOuterMemoryCM.h"
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif

/////////////////////////////////////////
// Constants

// Number of bits used for the VMs for different layers and disks
// E.g. 32 VMs would use 5 vmbits
constexpr int nbitsvmlayer[6] = { 2, 3, 3, 3, 3, 3 };
constexpr int nbitsvmdisk[5] = { 3, 2, 2, 2, 2 };

// Number of most significant bits (MSBs) of z and r used for index in the LUTs
constexpr int nbitsztablelayer = 7;
constexpr int nbitsrtablelayer = 4;

constexpr int nbitsztabledisk = 3;
constexpr int nbitsrtabledisk = 8;

// Number of MSBs used for r index in phicorr LUTs
constexpr int nbitsrphicorrtable = 3;

// The length of the masks used for the memories
constexpr int maskASIsize = 12; // Allstub Inner memories

// Enum for the different versions of Allstub Inner memories. L,M,R can be used for both barrel and disks
enum allStubInnerVersions {A, B, C, D, E, F, L, M, R, OL, OM, OR};

//////////////////////////////////////
// Functions used by the VMR CM

// Returns the bits of phi corresponding to finephi, i.e. phi regions within a VM
// vmbits is the number of bits for the VMs, i.e. coarse phi region. E.g. 32 VMs would use vmbits=5
// finebits is the number of bits within the VM
template<regionType InType>
inline int iphivmFineBins(const typename AllStub<InType>::ASPHI phi, const int vmbits, const int finebits) {

	auto finebin = (phi.range(phi.length() - vmbits - 1, phi.length() - vmbits - finebits));

	return finebin;
}

// Get the corrected phi, i.e. phi at the average radius of the barrel
// Corrected phi is used by ME and TE memories in the barrel
template<regionType InType>
inline typename AllStub<InType>::ASPHI getPhiCorr(
		const typename AllStub<InType>::ASPHI phi,
		const typename AllStub<InType>::ASR r,
		const typename AllStub<InType>::ASBEND bend, const int phiCorrTable[]) {

	if (InType == DISKPS || InType == DISK2S) return phi; // Do nothing if disks

	constexpr auto nrbins = 1 << nbitsrphicorrtable; // The number of bins for r

	ap_uint<nbitsrphicorrtable> rbin = (r + (1 << (r.length() - 1))) >> (r.length() - nbitsrphicorrtable); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * nrbins + rbin; // Index for where we find our correction value
	auto corrValue = phiCorrTable[index]; // The amount we need to correct our phi

	auto phicorr = phi - corrValue; // the corrected phi

	// Check for overflow
	if (phicorr < 0) phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length()) phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}

// Returns a ME/TE stub with all the values set
template<class T, regionType InType, regionType OutType, int Layer, int Disk, bool isMEStub>
inline T createVMStub(const InputStub<InType> inputStub,
		const int index, const bool negDisk, const int lutTable[],
		const int phiCorrTable[], int& slot) {

	// The stub that is going to be returned
	T stub;

	// Values from InputStub
	auto z = inputStub.getZ();
	auto r = inputStub.getR();
	auto bend = inputStub.getBend();
	auto phi = inputStub.getPhi();
	auto phicorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius

	int nbitsr = r.length(); // Number of bits for r
	int nbitsz = z.length(); // Number of bits for z
	int nbitsfinerz = stub.getFineZ().length(); // Number of bits for finer/z
	int nbitsfinephi = stub.getFinePhi().length();  // Number of bits for finephi

	// Number of bits for table indices
	constexpr int nbitsztable = (Layer) ? nbitsztablelayer : nbitsztabledisk; // Number of MSBs of z used in LUT table
	constexpr int nbitsrtable = (Layer) ? nbitsrtablelayer : nbitsrtabledisk; // Number of MSBs of r used in LUT table
	constexpr auto vmbits = (Layer) ? nbitsvmlayer[Layer-1] : nbitsvmdisk[Disk-1]; // Number of bits for standard VMs
	constexpr unsigned int nbitsall = (Layer) ? nbitsallstubs[Layer-1] : nbitsallstubs[N_LAYER+Disk-1]; // Number of bits for the number of Alltub memories in a layer/disk

	// Number of bits for the memory bins
	constexpr int nbitsbin = (isMEStub) ? ((Layer) ? MEBinsBits : MEBinsBits + 1) : TEBinsBits; // ME in disks has double the amount of bins

	// Set values to VMStub
	stub.setBend(bend);
	stub.setIndex(index);
	stub.setFinePhi(iphivmFineBins<InType>(phicorr, nbitsall + vmbits, nbitsfinephi));

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
		if (InType == DISKPS) {
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

// Two input region types InType and DISK2S due to the disks having both 2S and PS inputs.
template<int nInputMems, int nInputDisk2SMems, int nAllCopies, int nAllInnerCopies, int Layer, int Disk, regionType InType, regionType OutType, int rzSizeME, int rzSizeTE, int phiRegSize, int nTEOCopies>
void VMRouterCM(const BXType bx, BXType& bx_o,
		// LUTs
		const int METable[],
		const int TEDiskTable[], 
		const int phiCorrTable[],
		// Input memories
		const InputStubMemory<InType> inputStubs[],
		const InputStubMemory<DISK2S> inputStubsDisk2S[],
		// AllStub memory
		AllStubMemory<OutType> memoriesAS[],
		const ap_uint<maskASIsize>& maskASI,
		AllStubInnerMemory<OutType> memoriesASInner[],
		// ME memories
		VMStubMEMemoryCM<OutType, rzSizeME, phiRegSize, kNMatchEngines> *memoryME,
		// TE Outer memories
		VMStubTEOuterMemoryCM<OutType, rzSizeTE, phiRegSize, kNTEUnits> memoriesTEO[]) {

#pragma HLS inline
#pragma HLS array_partition variable=inputStubs complete dim=1
#pragma HLS array_partition variable=inputStubsDisk2S complete dim=1
#pragma HLS array_partition variable=memoriesAS complete dim=1
#pragma HLS array_partition variable=memoriesASInner complete dim=1
#pragma HLS array_partition variable=memoriesTEO complete dim=1

	// Number of data in each input memory
	typename InputStubMemory<InType>::NEntryT nInputs[nInputMems
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
	ap_uint<kNBits_MemAddr> addrCountASI[nAllInnerCopies]; // Writing of Inner Allstubs
	ap_uint<5> addrCountME[1 << (rzSizeME + phiRegSize)]; // Writing of ME stubs, number of bits taken from whatever is defined in the memories: (4+rzSize + phiRegSize)-(rzSize + phiRegSize)+1
	ap_uint<5> addrCountTE[1 << (rzSizeTE + phiRegSize)]; // Writing of TE stubs
#pragma HLS array_partition variable=addrCountASI complete dim=0
#pragma HLS array_partition variable=addrCountME complete dim=0
#pragma HLS array_partition variable=addrCountTE complete dim=0

	for (int i = 0; i < nAllInnerCopies; i++) {
#pragma HLS unroll
		addrCountASI[i] = 0;
	}
	for (int i = 0; i < 1 << (rzSizeME + phiRegSize); i++) {
#pragma HLS unroll
		addrCountME[i] = 0;
	}
	for (int i = 0; i < 1 << (rzSizeTE + phiRegSize); i++) {
#pragma HLS unroll
		addrCountTE[i] = 0;
	}

	/////////////////////////////////////
	// Main Loop

	constexpr int maxLoop = kMaxProc;

	TOPLEVEL: for (int i = 0; i < maxLoop; ++i) {
#pragma HLS PIPELINE II=1 rewind

		bool noStubsLeft = !hasStubs.or_reduce(); // Determines if we have processed all stubs. Is true if hasStubs is all 0s
		bool resetNext = false; // Used to reset read_addr
		bool disk2S = false; // Used to determine if DISK2S
		bool negDisk = false; // Used to determine if it's negative disk

		InputStub<InType> stub;
		InputStub<DISK2S> stubDisk2S; // Used for disks. TODO: Find a better way to do this...?

		// Read a stub. The input memories are in the order PS, negPS, 2S, neg2S
		int mem_index = __builtin_ctz(hasStubs); // The first non-zero index

		if (!noStubsLeft) {
			if (mem_index < nInputMems) {
				stub = inputStubs[mem_index].read_mem(bx, read_addr);
				if (InType == DISKPS) {
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

		////////////////////////////////////////
		// AllStub memories

		AllStub<OutType> allstub = (disk2S) ? stubDisk2S.raw() : stub.raw();

		// Write stub to all memory copies
		for (int n = 0; n < nAllCopies; n++) {
#pragma HLS UNROLL
			memoriesAS[n].write_mem(bx, allstub, i);
		}

// For debugging
#if !(defined(__SYNTHESIS__) || defined(CMSSW_GIT_HASH))
		edm::LogVerbatim("FWHLS") << std::endl << "Stub index no. " << i << std::endl
				<< "Out put stub: " << std::hex << allstub.raw() << std::dec
				<< std::endl;
#endif // DEBUG

		////////////////////////////////////////
		// AllStubInner memories

		if (maskASI) {

			int comparison_rz = (Layer) ? static_cast<int>(abs(stub.getZ())) : static_cast<int>(stub.getR());
			bool passRZCut = false;
			bool passRZSpecialCut = false;

			// Use comparison_rz to check if they pass the RZ cuts
			if (Layer == 1) { // TODO: use comparison value 2 for LMR memories
				constexpr float comparison_value = (Layer) ? VMROUTERCUTZL1L3L5 / kz_cm[Layer - 1] : 0;
				constexpr float comparison_valueLMR = (Layer) ? VMROUTERCUTZL1 / kz_cm[Layer - 1] : 0; // For LMR memories
				passRZCut = !(comparison_rz > comparison_value);
				passRZSpecialCut = !(comparison_rz < comparison_valueLMR);
			} else if (Layer == 2) {
				constexpr float comparison_value = (Layer) ? VMROUTERCUTZL2 / kz_cm[Layer - 1] : 0;
				passRZCut = !(comparison_rz < comparison_value);
			} else if (Layer == 3 || Layer == 5) {
				constexpr float comparison_value = (Layer) ? VMROUTERCUTZL1L3L5 / kz_cm[Layer - 1] : 0;
				passRZCut = !(comparison_rz > comparison_value);
			} else if (Disk == 1 || Disk == 3) {
				constexpr float comparison_value = VMROUTERCUTRD1D3 / kr;
				constexpr float comparison_value2 = 2 * N_DISK; // 2*int(N_DSS_MOD) in emulation
				passRZCut = !(comparison_rz > comparison_value) && !(comparison_rz < comparison_value2);
			}

			// Write the stubs that pass the RZ cuts
			if (passRZCut || passRZSpecialCut) {

				AllStubInner<OutType> allstubinner;
				allstubinner = (disk2S) ? 
						static_cast<ap_uint<allstubinner.getWidth()>>(stubDisk2S.raw()) << (allstubinner.getWidth() - stubDisk2S.getWidth()) : 
						static_cast<ap_uint<allstubinner.getWidth()>>(stub.raw()) << (allstubinner.getWidth() - stub.getWidth()); // shift by finephi and index

				allstubinner.setIndex(i);
				auto phicorr = getPhiCorr<InType>(stub.getPhi(), stub.getR(), stub.getBend(), phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)
				allstubinner.setFinePhi( phicorr.range(phicorr.length() - 1, phicorr.length() - allstubinner.getFinePhi().length())); // top 8 bits of phicorr

				constexpr unsigned int phicutmax = (Layer == 1) ? 4 : 6; // I have no idea what these numbers are, see emulation
				constexpr unsigned int phicutmin = (Layer == 1) ? 4 : 2;

				constexpr unsigned int nbitsall = (Layer) ? nbitsallstubs[Layer - 1] : nbitsallstubs[N_LAYER + Disk - 1]; // Number of bits for the number of Alltub memories in a layer/disk

				auto iphipos = phicorr.range(phicorr.length() - nbitsall - 1, phicorr.length() - (nbitsall + phiRegSize)); // Top three bits after the allstub bits
				unsigned int inner_mem_index = 0; // Keeps track of which allstub inner memory to write to

				// Loop over all possible memory versions
				for (int n = 0; n < maskASIsize; n++) {
#pragma HLS UNROLL

					if (maskASI[n]) {
						bool passPhiCut = false;
						bool passSpecialCut = (Layer != 1) ? true : ((n > F) && passRZSpecialCut) || (!(n > F) && passRZCut); // For layer 1 the LMR memories have different cuts

						if (n == L || n == OL) {
							passPhiCut = !(iphipos >= phicutmin);
						} else if (n == R || n == OR) {
							passPhiCut = !(iphipos < phicutmax);
						} else if (n == A || n == D || n == F) {
							passPhiCut = !(iphipos < 4);
						} else if (n == B || n == C || n == E) {
							passPhiCut = !(iphipos >= 4);
						} else if (n == M || n == OM) {
							passPhiCut = true;
						}

						if (passPhiCut && passSpecialCut) {
							memoriesASInner[inner_mem_index].write_mem(bx, allstubinner, addrCountASI[inner_mem_index]);
							addrCountASI[inner_mem_index]++;
						}

						inner_mem_index++;
					}
				}

// For debugging
#if !(defined(__SYNTHESIS__) || defined(CMSSW_GIT_HASH))
				edm::LogVerbatim("FWHLS") << std::endl << "Allstub Inner: " << std::hex
						<< allstubinner.raw() << std::dec << std::endl;
#endif // DEBUG

			}
		}

		/////////////////////////////////////////////
		// ME memories

		int slotME; // The bin the stub is going to be put in, in the memory

		// Create the ME stub to save
		VMStubMECM<OutType> stubME = (disk2S) ? 
				createVMStub<VMStubMECM<OutType>, DISK2S, OutType, Layer, Disk, true>(stubDisk2S, i, negDisk,METable, phiCorrTable, slotME) :
				createVMStub<VMStubMECM<OutType>, InType, OutType, Layer, Disk, true>(stub, i, negDisk, METable, phiCorrTable, slotME);

		// Write the ME stub
		memoryME->write_mem(bx, slotME, stubME, addrCountME[slotME]);
		addrCountME[slotME] += 1;

// For debugging
#if !(defined(__SYNTHESIS__) || defined(CMSSW_GIT_HASH))
		edm::LogVerbatim("FWHLS") << "ME stub " << std::hex << stubME.raw() << std::dec
				<< "       to slot " << slotME << std::endl;
#endif // DEBUG
		// End ME memories

		////////////////////////////////////
		// TE Outer memories

		if (nTEOCopies && !disk2S) {

			int slotTE; // The bin the stub is going to be put in, in the memory

			// Create the TE Outer stub to save
			VMStubTEOuter<OutType> stubTEO = (Layer) ?
					createVMStub<VMStubTEOuter<OutType>, InType, OutType, Layer, Disk, false>(stub, i, negDisk, METable, phiCorrTable, slotTE) :
					createVMStub<VMStubTEOuter<OutType>, InType, OutType, Layer, Disk, false>(stub, i, negDisk, TEDiskTable, phiCorrTable, slotTE);

			// Write stub to all TE memory copies
			for (int n = 0; n < nTEOCopies; n++) {
#pragma HLS UNROLL
				memoriesTEO[n].write_mem(bx, slotTE, stubTEO, addrCountTE[slotTE]);
			}
			addrCountTE[slotTE] += 1;

// For debugging
#if !(defined(__SYNTHESIS__) || defined(CMSSW_GIT_HASH))
			edm::LogVerbatim("FWHLS") << "TEOuter stub " << std::hex << stubTEO.raw()
					<< std::dec << "       to slot " << slotTE << std::endl;
#endif // DEBUG

		} // End TE Outer memories

	} // Outside main loop

	bx_o = bx;
} // End VMRouterCM

#endif // TrackletAlgorithm_VMRouterCM_h
