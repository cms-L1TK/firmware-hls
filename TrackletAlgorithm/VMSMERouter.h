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

// Number of rz bin bits for ME
constexpr unsigned kNbitsrzbinMELayer = kNbitsrzbin;
constexpr unsigned kNbitsrzbinMEDisk = kNbitsrzbin + 1;

//////////////////////////////////////
// Functions used by the VMSMERouter

// Returns the bits of phi corresponding to finephi, i.e. phi regions within a VM
// vmbits is the number of bits for the VMs, i.e. coarse phi region. E.g. 32 VMs would use vmbits=5
// finebits is the number of bits within the VM
template<regionType InType>
inline int iphivmFineBins(const typename AllStub<InType>::ASPHI phi, const int vmbits, const int finebits) {

	auto finebin = (phi.range(phi.length() - vmbits - 1, phi.length() - vmbits - finebits));

	return finebin;
}

// Get the corrected phi, i.e. phi at the average radius of the barrel
// Corrected phi is used by ME memories in the barrel
template<regionType inOutType>
inline typename AllStub<inOutType>::ASPHI getPhiCorr(
		const typename AllStub<inOutType>::ASPHI phi,
		const typename AllStub<inOutType>::ASR r,
		const typename AllStub<inOutType>::ASBEND bend, const int phiCorrTable[]) {

	if (inOutType == DISKPS || inOutType == DISK2S) return phi; // Do nothing if disks

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
template<class T, regionType InType, regionType OutType, int layer, int disk>
inline T createVMStubME(AllStub<InType> allstub,
		const int index, bool negDisk, const int lutTable[],
		const int phiCorrTable[], int& slot) {
	// The stub that is going to be returned
	T stub;
	// Values from Input AllStub

	auto nd = allstub.getND();

	negDisk = nd;

	auto z = allstub.getZ();
	ap_uint<AllStubBase<InType>::kASRSize> r = allstub.getR();
	if (allstub.isPSStub()) r += 256; 
	
	auto bend = allstub.getBend();
	auto phi = allstub.getPhi();
	auto phicorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius

	int nbitsr = r.length(); // Number of bits for r
	if (InType == DISKPS){
		nbitsr = 12; // needed to get correct index for LUT 
	}

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
	stub.setFinePhi(iphivmFineBins<InType>(phicorr, nbitsall + vmbits, nbitsfinephi));

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
		if (InType == DISKPS) {
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
	slot = ivm * (1 << nbitsbin) + bin;

	// Set rzfine, i.e. the r/z bits within a coarse r/z region
	auto rzfine = lutValue & ((1 << nbitsfinerz) - 1); // the 3 LSB as rzfine
	stub.setFineZ(rzfine);

	assert(rzfine >= 0);
	std::cout << "vmstub raw: " << std::hex << stub.raw() << "\n";
	return stub;
};

/////////////////////////////////
// Main function

// inOutType will be BARRELPS, BARREL2S, or DISK (since both DISKPS and DISK2S stubs contained in each AllStub memory)
// and VMStubME memories are also written out as DISK so need only one region type template parameter
template<int layer, int disk, regionType inOutType, int rzSizeME, int phiRegSize>
void VMSMERouter(const BXType bx, BXType& bx_o,
		// LUTs
		const int METable[],
		const int phiCorrTable[],
		// Input memories
		AllStubMemory<inOutType> allstub,
		// ME memories
		VMStubMEMemoryCM<inOutType, rzSizeME, phiRegSize, kNMatchEngines> *memoryME) {

#pragma HLS inline
//#pragma HLS array_partition variable=memoriesAS complete dim=1

	int entries = allstub.getEntries(bx);

	//Create variables that keep track of which memory address to read and write to
	ap_uint<kNBits_MemAddr> read_addr(0); // Reading of AllStubs
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
		bool disk2S = false; // Used to determine if DISK2S
		bool negDisk = false; // Used to determine if stub is in negative or positive Z region of detector

		AllStub<inOutType>       stub = allstub.read_mem(bx,read_addr); // read stubs, and if disk cast from DISK to DISKPS/2S
		AllStub<DISKPS>       stub_ps = AllStub<DISKPS>(stub.raw());
		AllStub<DISK2S>       stub_2s = AllStub<DISK2S>(stub.raw());
		
		constexpr bool isDisk = (disk > 0);
		if (isDisk) disk2S = !stub_ps.isPSStub();

		// Increment the read address
		++read_addr;

		/////////////////////////////////////////////
		// ME memories

		int slotME; // The bin the stub is going to be put in, in the memory
		// Create the ME stub to save
		/*VMStubMECM<inOutType> stubME = (disk2S) ? 
				createVMStubME<VMStubMECM<inOutType>, DISK2S, inOutType, layer, disk>(stub_2s, i, negDisk, METable, phiCorrTable, slotME) : (isDisk) ?
				createVMStubME<VMStubMECM<inOutType>, DISKPS, inOutType, layer, disk>(stub_ps, i, negDisk, METable, phiCorrTable, slotME) : 
				createVMStubME<VMStubMECM<inOutType>, inOutType, inOutType, layer, disk>(stub, i, negDisk, METable, phiCorrTable, slotME);*/

		VMStubMECM<inOutType> stubME = (disk <= 0) ? 
				createVMStubME<VMStubMECM<inOutType>, inOutType, inOutType, layer, disk>(stub, i, negDisk, METable, phiCorrTable, slotME) : (disk2S) ?
				createVMStubME<VMStubMECM<inOutType>, DISK2S, inOutType, layer, disk>(stub_2s, i, negDisk, METable, phiCorrTable, slotME) :
				createVMStubME<VMStubMECM<inOutType>, DISKPS, inOutType, layer, disk>(stub_ps, i, negDisk, METable, phiCorrTable, slotME);

		// Write the ME stub
		memoryME->write_mem(bx, slotME, stubME, addrCountME[slotME]);
		addrCountME[slotME] += 1;
		if (read_addr >= entries) break; // FIXME probably shouldn't break here? 
		// End ME memories
	} // Outside main loop

	bx_o = bx;
} // End VMSMERouter

#endif // TrackletAlgorithm_VMSMERouter_h
