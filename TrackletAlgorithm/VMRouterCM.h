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


/////////////////////////////////////////
// Constants

// Number of bits used for the VMs for different layers and disks
// E.g. 32 VMs would use 5 vmbits
constexpr int nbitsallstubslayer[6] = { 3, 2, 2, 2, 2, 2}; // Number of bits for the Allstub memories in each layer
constexpr int nbitsallstubsdisk[5] = {2};
constexpr int nbitsvmlayer[6] = { 5, 5, 5, 5, 5, 5 }; // Could be computed using the number of VMs...
constexpr int nbitsvmdisk[5] = { 4, 4, 4, 4, 4 };
constexpr int nbitsvmextra[3] = { 0, 4, 4 };

// Number of most significant bits (MSBs) of z and r used for index in the LUTs
constexpr int nbitsztablelayer = 7;
constexpr int nbitsrtablelayer = 4;

constexpr int nbitsztabledisk = 3;
constexpr int nbitsrtabledisk = 8;

// Number of MSBs used for r index in phiCorr LUTs
constexpr int nbitsrphicorrtable = 3; // Found hardcoded in VMRouterphiCorrTable.h

// The length of the masks used for the memories
constexpr int maskASIsize = 12; // Allstub Inner memories


//////////////////////////////////////
// Functions used by the VMR CM

// Returns the bits of phi corresponding to finephi, i.e. phi regions within a VM
// vmbits is the number of bits for the VMs, i.e. coarse phi region. E.g. 32 VMs would use vmbits=5
// finebits is the number of bits within the VM
template<regionType InType>
inline int iphivmFineBins(const typename AllStub<InType>::ASPHI phi,
		const int vmbits, const int finebits) {

	auto finebin = (phi.range(phi.length() - 1 - vmbits, phi.length() - vmbits - finebits));

	return finebin;
}

// Get the corrected phi, i.e. phi at the average radius of the barrel
// Corrected phi is used by ME and TE memories in the barrel
template<regionType InType>
inline typename AllStub<InType>::ASPHI getPhiCorr(
		const typename AllStub<InType>::ASPHI phi,
		const typename AllStub<InType>::ASR r,
		const typename AllStub<InType>::ASBEND bend, const int phiCorrTable[]) {

	if (InType == DISKPS || InType == DISK2S)
		return phi; // Do nothing if disks

	constexpr auto rBins = 1 << nbitsrphicorrtable; // The number of bins for r

	ap_uint<nbitsrphicorrtable> rBin = (r + (1 << (r.length() - 1)))
			>> (r.length() - nbitsrphicorrtable); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * rBins + rBin; // Index for where we find our correction value
	auto corrValue = phiCorrTable[index]; // The amount we need to correct our phi

	auto phiCorr = phi - corrValue; // the corrected phi

	// Check for overflow
	if (phiCorr < 0)
		phiCorr = 0; // can't be less than 0
	if (phiCorr >= 1 << phi.length())
		phiCorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phiCorr;
}


// Returns a ME/TE stub with all the values set
template<class T, regionType InType, regionType OutType, int Layer, int Disk>
inline T createVMStub(bool isMEStub, const InputStub<InType> inputStub,
		const int index, const bool negDisk, const int fineBinTable[],
		const int phiCorrTable[], int& slot) {

	// The stub that is going to be returned
	T stub;

	// Values from InputStub
	auto z = inputStub.getZ();
	auto r = inputStub.getR();
	auto bend = inputStub.getBend();
	auto phi = inputStub.getPhi();
	auto phiCorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)

	int nrBits = r.length(); // Number of bits for r
	int nzBits = z.length(); // Number of bits for z
	int nbendBits = bend.length(); // Number of bits for bend
	int nfinerzbits = stub.getFineZ().length(); // Number of bits for finer/z
	int nFinePhiBits = stub.getFinePhi().length();  // Number of bits for finephi

	// Number of bits for table indices
	constexpr int nbitsztable =
			(Layer) ? nbitsztablelayer : nbitsztabledisk; // Number of MSBs of z used in finebintable
	constexpr int nbitsrtable =
			(Layer) ? nbitsrtablelayer : nbitsrtabledisk; // Number of MSBs of r used in finebintable
	constexpr auto vmbitsTmp =
			(Layer) ? nbitsvmlayer[Layer - 1] : nbitsvmdisk[Disk - 1]; // Number of bits for standard VMs
	constexpr auto vmbits =
			((Layer == 3) && !isMEStub) ? nbitsvmextra[Layer - 1] : vmbitsTmp; // Number of bits for VMs
	constexpr unsigned int nbitsallstubs = 
			(Layer) ? nbitsallstubslayer[Layer] : nbitsallstubsdisk[Disk]; // Number of bits for the number of Alltub memories in a layer/disk

	// Set values to VMStub
	stub.setBend(bend);
	stub.setIndex(index);
	stub.setFinePhi(
				iphivmFineBins<InType>(phiCorr, vmbits, nFinePhiBits));

	// Indices used to find the rzfine value in finebintable
	// finebintable returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nbitsztable + nbitsrtable> indexz =
			//((z + (1 << (nzBits - 1))) >> (nzBits - nbitsztable)); // Make z unsigned and take the top "nbitsztable" bits
			(z >> (nzBits - nbitsztable));
	ap_uint<nbitsrtable> indexr = -1;

	constexpr int rbins = (1 << nbitsrtable); // Number of bins in r in finebintable

	if (Disk) {
		if (negDisk) {
			indexz = (1 << nbitsztable) - indexz;
		}
		indexr = r;
		if (InType == DISKPS) {
			indexr = r >> (nrBits - nbitsrtable); // Take the top "nbitsrtable" bits
		}
	} else { // Layer
		indexr = (r >> (nrBits- nbitsrtable));// Make r unsigned and take the top "nbitsrtable" bits
	}

	// The index for finebintable
	ap_uint<nbitsztable + nbitsrtable> finebinindex = (indexz * rbins) + indexr;

	// Get the corrected r/z position
	auto rzCorr = fineBinTable[finebinindex];

	// Coarse z. The bin the stub is going to be put in, in the memory
	int bin = rzCorr >> nfinerzbits; // 3 bits, i.e. max 8 bins within each VM

	if (negDisk) {
		if (isMEStub) bin += 1 << MEBinsBits; // bin 8-16 are for negative disk
		else bin += (1 << TEBinsBits)/2; // += 4
	}
	
	auto ivm = phiCorr.range(phiCorr.length() - nbitsallstubs - 1, phiCorr.length() - vmbits); //get the phi bits that corresponds to the old TE vms. what is 2? because we have 2 bits all stubs?? and 3 buts for te?
	slot = ivm * 8 + bin; //1 << 3 is the number of bins NBINS?

	// Set rzfine, i.e. the r/z bits within a coarse r/z region
	auto rzfine = rzCorr & ((1 << nfinerzbits) - 1); // the 3 LSB as rzfine
	stub.setFineZ(rzfine);

	assert(rzfine >= 0);

	return stub;
};


/////////////////////////////////
// Main function

// Two input region types InType and DISK2S due to the disks having both 2S and PS inputs.
template<int nInputMems, int nInputDisk2SMems, int nAllCopies, int nAllInnerCopies, int Layer, int Disk, regionType InType, regionType OutType, int rzSize, int phiRegSize, int nTEOCopies>
void VMRouterCM(const BXType bx, BXType& bx_o, 
		const int METable[], const int phiCorrTable[],
		// Input memories
		const InputStubMemory<InType> inputStubs[],
		const InputStubMemory<DISK2S> inputStubsDisk2S[],
		// AllStub memory
		AllStubMemory<OutType> memoriesAS[nAllCopies],
		const ap_uint<maskASIsize>& maskASI, AllStubInnerMemory<OutType> memoriesASInner[],
		// ME memories
		VMStubMEMemoryCM<OutType, rzSize, phiRegSize>& memoryME,
		// TE Outer memories
		VMStubTEOuterMemoryCM<OutType,rzSize,phiRegSize,nTEOCopies>& memoryTEO) {

#pragma HLS inline
#pragma HLS array_partition variable=inputStubs complete dim=1
#pragma HLS array_partition variable=inputStubsDisk2S complete dim=1
#pragma HLS array_partition variable=memoriesAS complete dim=1
#pragma HLS array_partition variable=memoriesASInner complete dim=1

	// Number of data in each input memory
	typename InputStubMemory<InType>::NEntryT nInputs[nInputMems + nInputDisk2SMems]; // Array containing the number of inputs
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
	ap_uint<5> addrCountME[1 << (rzSize + phiRegSize)]; // Writing of ME stubs, number of bits taken from whatever is defined in the memories: (4+rzSize + phiRegSize)-(rzSize + phiRegSize)+1
	ap_uint<kNBits_MemAddr> addrCountASI[nAllInnerCopies]; // Writing of Inner Allstubs
	
	#pragma HLS array_partition variable=addrCountME complete dim=0
	#pragma HLS array_partition variable=addrCountASI complete dim=0
	
	for (int i = 0; i < 1 << (rzSize + phiRegSize); i++) {
		#pragma HLS unroll
		addrCountME[i] = 0;
	}
	for (int i = 0; i < nAllInnerCopies; i++) {
		#pragma HLS unroll
		addrCountASI[i] = 0;
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

		if(!noStubsLeft) {
		  if (mem_index < nInputMems) {
		    stub = inputStubs[mem_index].read_mem(bx, read_addr);
		    if (InType == DISKPS) {
		      negDisk = mem_index >= (nInputMems>>1);
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
		if (resetNext)
			read_addr = 0;
		else
			++read_addr;

		if (noStubsLeft) continue; // End here if we already have processed all stubs
		// Note: putting the continue here rather than at the start of the loop seems to yield better timing.


		////////////////////////////////////////
		// AllStub memories

			AllStub<OutType> allstub =
					(disk2S) ? stubDisk2S.raw() : stub.raw();

			// Write stub to all memory copies
			for (int n = 0; n < nAllCopies; n++) {
#pragma HLS UNROLL
				memoriesAS[n].write_mem(bx, allstub, i);
			}

			// For debugging
			#ifndef __SYNTHESIS__
						std::cout << std::endl << "Stub index no. " << i << std::endl << "Out put stub: " << std::hex << allstub.raw() << std::dec
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
					constexpr float comparison_value = 95.0 / kz;
					constexpr float comparison_value2 = 70 / kz;
					passRZCut = !(comparison_rz > comparison_value);
					passRZSpecialCut = !(comparison_rz < comparison_value2);
				} else if (Layer == 2) {
					constexpr float comparison_value = 50.0 / kz;
					passRZCut = !(comparison_rz < comparison_value);
				} else if (Layer == 3 || Layer == 5) {
					constexpr float comparison_value = 95.0 / kz;
					passRZCut = !(comparison_rz > comparison_value);
				} else if (Disk == 1 || Disk == 3) {
					constexpr float comparison_value = 55.0 / kr;
					constexpr float comparison_value2 = 2*N_DISK; // 2*int(N_DSS_MOD) in emulation
					passRZCut = !((comparison_rz > comparison_value) && (comparison_rz < comparison_value2));
				}

				// Write the stubs that pass the RZ cuts
				if (passRZCut || passRZSpecialCut) {

					AllStubInner<OutType> allstubinner;
					allstubinner = (disk2S) ? static_cast<ap_uint<allstubinner.getWidth()>>(stubDisk2S.raw()) << (allstubinner.getWidth() - stubDisk2S.getWidth()) 
								: static_cast<ap_uint<allstubinner.getWidth()>>(stub.raw()) << (allstubinner.getWidth() - stub.getWidth()); // shift by finephi and index

					allstubinner.setIndex(i);
					auto phiCorr = getPhiCorr<InType>(stub.getPhi(), stub.getR(), stub.getBend(), phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)
					allstubinner.setFinePhi(phiCorr.range(phiCorr.length() - 1, phiCorr.length() - allstubinner.getFinePhi().length())); // top 8 bits of phicorr

					constexpr unsigned int phicutmax = (Layer == 1) ? 4 : 6; // I have no idea where these numbers come from, see emulation
					constexpr unsigned int phicutmin = (Layer == 1) ? 4 : 2;

					constexpr unsigned int nbitsallstubs = (Layer) ? nbitsallstubslayer[Layer] : nbitsallstubsdisk[Disk]; // Number of bits for the number of Alltub memories in a layer/disk

					auto iphipos = phiCorr.range(phiCorr.length() - nbitsallstubs -1, phiCorr.length() - (nbitsallstubs + 3)); // Top three bits after the allstub bits 
					unsigned int inner_mem_index = 0; // Keeps track of which allstub inner memory to write to


					for (int n = 0; n < maskASIsize; n++) {
#pragma HLS UNROLL

						if (maskASI[n]) {
							bool passPhiCut = false;
							bool passSpecialCut = (Layer != 1) ? true : ((n < 3 || n > 8) && passRZSpecialCut) || (!(n < 3 || n > 8) && passRZCut); // For layer 1 the LMR memories have different cuts

							if (n==0 || n==9) {
								passPhiCut = !(iphipos>=phicutmin);
							} else if (n == 2 || n==11) {
								passPhiCut = !(iphipos<phicutmax);
							} else if (n == 3 || n==6 || n==8) {
								passPhiCut = !(iphipos<4);
							} else if (n == 4 || n==5 || n==7) {
								passPhiCut = !(iphipos>=4);
							} else { // 1 and 10
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
					#ifndef __SYNTHESIS__
								std::cout << std::endl << "Allstub Inner: " << std::hex << allstubinner.raw() << std::dec << std::endl;
					#endif // DEBUG

				}
			}


		/////////////////////////////////////////////
		// ME memories

		int slot; // Coarse z. The bin the stub is going to be put in, in the memory

		// Create the ME stub to save
		VMStubMECM<OutType> stubME = (disk2S) ?
				createVMStub<VMStubMECM<OutType>, DISK2S, OutType, Layer, Disk>(true, stubDisk2S, i, negDisk, METable, phiCorrTable, slot) :
				createVMStub<VMStubMECM<OutType>, InType, OutType, Layer, Disk>(true, stub, i, negDisk, METable, phiCorrTable, slot);

		// Write the ME stub
		memoryME.write_mem(bx, slot, stubME, addrCountME[slot]);
		addrCountME[slot] += 1;

		// For debugging
		#ifndef __SYNTHESIS__
					std::cout << "ME stub " << std::hex << stubME.raw()
							<< std::dec << "       to slot " << slot << std::endl;
		#endif // DEBUG
		// End ME memories


		////////////////////////////////////
		// TE Outer memories

		if (nTEOCopies && (!disk2S)) {

			int slot; // Coarse z. The bin the stub is going to be put in, in the memory

			// Create the TE Outer stub to save
			VMStubTEOuter<OutType> stubTEO = createVMStub<VMStubTEOuter<OutType>, InType, OutType, Layer, Disk>(false, stub, i, negDisk, METable, phiCorrTable, slot);

			// Write the TE Outer stub if bin isn't negative
			memoryTEO.write_mem(bx, slot, stubTEO);

			// For debugging
			#ifndef __SYNTHESIS__
						std::cout << "TEOuter stub " << std::hex << stubTEO.raw()
								<< std::dec << "       to slot " << slot << std::endl;
			#endif // DEBUG
			
		} // End TE Outer memories

	} // Outside main loop

	bx_o = bx;
} // End VMRouterCM

#endif // TrackletAlgorithm_VMRouterCM_h
