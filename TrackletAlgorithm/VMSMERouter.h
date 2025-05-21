// VMSMERouter

// Sort AllStubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// By writing VMStubME memories, with each VMSMERouter correspond to one phi/AllStub region.
// Needed for when project is split over both PFGAs

#ifndef TrackletAlgorithm_VMSMERouter_h
#define TrackletAlgorithm_VMSMERouter_h

#include "ap_int.h"
#include <cassert>

#include "Constants.h"
#include "AllStubMemory.h"
#include "VMStubMemory.h"
#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

/////////////////////////////////////////
// Constants

// Number of rz bin bits for ME
constexpr unsigned kNbitsrzbinMELayer = kNbitsrzbin;
constexpr unsigned kNbitsrzbinMEDisk = kNbitsrzbin + 1;

//////////////////////////////////////
// Functions used by the VMSMER

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

	constexpr auto nrbins = 1 << kNbitsrzbin; // The number of bins for r

	ap_uint<kNbitsrzbin> rbin = (r + (1 << (r.length() - 1))) >> (r.length() - kNbitsrzbin); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * nrbins + rbin; // Index for where we find our correction value
	auto corrValue = phiCorrTable[index]; // The amount we need to correct our phi

	auto phicorr = phi - corrValue; // the corrected phi

	// Check for overflow
	if (phicorr < 0) phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length()) phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}

// Returns a ME stub with all the values set
template<class T, regionType inType, int layer, int disk>
inline T createVMStubME(const AllStub<inType>& allStub,
		const unsigned int index, const bool negDisk, const int lutTable[],
		const int phiCorrTable[], int& slot) {
	// The stub that is going to be returned
	T stub;
	// Values from Input AllStub
	auto z = allStub.getZ();
	typename AllStub<inType>::ASR r = allStub.getR(); // reading in as ap_uint<12> to prevent exceeding '2048' limit for ap_uint<11>, which will be the size when using 'auto' 
	auto bend = allStub.getBend();
	auto phi = allStub.getPhi();
	auto phicorr = getPhiCorr<inType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius

	int nbitsr = r.length(); // Number of bits for r

	int nbitsz = z.length(); // Number of bits for z
	int nbitsfinerz = stub.getFineZ().length(); // Number of bits for finer/z
	int nbitsfinephi = stub.getFinePhi().length();  // Number of bits for finephi

	// Number of bits for table indices
	constexpr int nbitsztable = (layer) ? kNbitszfinebintable : kNbitszfinebintableDisk; // Number of MSBs of z used in LUT table
	constexpr int nbitsrtable = (layer) ? kNbitsrfinebintable : kNbitsrfinebintableDisk; // Number of MSBs of r used in LUT table
	constexpr auto vmbits = (layer) ? nbits_vmmeall[layer-1] : nbits_vmmeall[trklet::N_LAYER+disk-1]; // Number of bits for standard VMs
	constexpr unsigned int nbitsall = (layer) ? nbitsallstubs[layer-1] : nbitsallstubs[trklet::N_LAYER+disk-1]; // Number of bits for the number of Alltub memories in a layer/disk

	// Number of bits for the memory bins
	constexpr int nbitsbin = (layer) ? MEBinsBits : MEBinsBits + 1; // ME in disks has double the amount of bins

	// Set values to VMStub
	stub.setBend(bend);
	stub.setIndex(index);
	stub.setFinePhi(iphivmFineBins<inType>(phicorr, nbitsall + vmbits, nbitsfinephi));

	// Indices used to find the rzfine value in LUT table
	// LUT table returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nbitsztable + nbitsrtable> indexz = (z >> (nbitsz - nbitsztable)); // Make z unsigned and take the top "nbitsztable" bits
	ap_uint<nbitsrtable> indexr = -1;

	constexpr int rbins = (1 << nbitsrtable); // Number of bins in r in LUT table

	if (disk) {
		if (negDisk) {
			indexz = (1 << nbitsztable) -1 - indexz;
		}
		indexr = r;
		if (inType == DISKPS) {
			indexr = r >> (nbitsr - nbitsrtable); // Take the top "nbitsrtable" bits
		}
	} else { // layer
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
	const int nbinsphi = 3;
	slot = (bin << nbinsphi) + ivm;

	// Set rzfine, i.e. the r/z bits within a coarse r/z region
	auto rzfine = lutValue & ((1 << nbitsfinerz) - 1); // the 3 LSB as rzfine
	stub.setFineZ(rzfine);

	assert(rzfine >= 0);
	
	return stub;
};


/////////////////////////////////
// Main function

// Two input region types InType and DISK2S due to the disks having both 2S and PS inputs.
template<int Layer, int Disk, regionType InType, regionType OutType, int rzSizeME, int phiRegSize, int NOutCopy=1>
void VMSMERouter(const BXType bx, BXType& bx_o,
		// LUTs
		const int METable[],
		const int phiCorrTable[],
		// Input memories
		AllStub<InType>& allStub,
		VMStubMemory<OutType, rzSizeME, phiRegSize, kNMatchEngines> memoryME[],
		AllStubMemory<OutType> memoriesAS[],
		// Array to count how many VMStubs written in each slot
		unsigned int index,
		bool valid
		) {

#pragma HLS inline
#pragma HLS array_partition variable=memoryME dim=1
#pragma HLS array_partition variable=memoriesAS dim=1
#pragma HLS latency min=13 max=13

  
  bool disk2S = false; // Used to determine if DISK2S
  bool negDisk = false; // Used to determine if it's negative disk
	
  AllStub<DISKPS>       stub_ps = AllStub<DISKPS>(allStub.raw());
  AllStub<DISK2S>       stub_2s = AllStub<DISK2S>(allStub.raw());
  AllStub<OutType>      stub_copy = AllStub<OutType>(allStub.raw());

  
  ////////////////////////////////////////
  // AllStub memories
	
  ///AllStub<OutType> allstub = allStub.raw();

  
  // Write stub to all memory copies
  // It seems that the if (nAllCopies > 0) should not be needed,
  // but if nAllCopies is zero it generates an error in vivado_hls
  if (valid) {
    for (unsigned int i=0; i<NOutCopy; i++) {
#pragma HLS UNROLL
      memoriesAS[i].write_mem(stub_copy);
    }
  }

  constexpr bool isDisk = (Disk > 0);
  if (isDisk) {
    disk2S = !stub_ps.isPSStub();
    if (disk2S) negDisk = stub_2s.getND();
    else negDisk = stub_ps.getND();
  }

  /////////////////////////////////////////////
  // ME memories
  
  int slotME; // The bin the stub is going to be put in, in the memory
	
  // Create the ME stub to save

  if (valid) {
    VMStub<OutType> stubME = (disk2S) ? 
      createVMStubME<VMStub<OutType>, DISK2S, Layer, Disk>(stub_2s, index, negDisk, METable, phiCorrTable, slotME) : (isDisk) ?
      createVMStubME<VMStub<OutType>, DISKPS, Layer, Disk>(stub_ps, index, negDisk, METable, phiCorrTable, slotME) : 
      createVMStubME<VMStub<OutType>, InType, Layer, Disk>(allStub, index, negDisk, METable, phiCorrTable, slotME);
    
    // Write the ME stub
    for (unsigned int i=0; i<NOutCopy; i++) {
#pragma HLS UNROLL
      memoryME[i].write_mem(slotME, stubME);
    }
  }
  
  
  bx_o = bx;
} // End VMRouterCM

#endif // TrackletAlgorithm_VMRouterCM_h
