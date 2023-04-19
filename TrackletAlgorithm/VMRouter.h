// VMRouter
// Log
// -------
// First tracklet 2.0 version -- December 2018 -- wittich

// Sort stubs into smaller regions in phi, i.e. Virtual Modules (VMs).
// Several types of memories depending on which module that is going to read it.
// Each VMRouter correspond to one phi/AllStub region.
// Each VM correspond to one ME/TE memory.
// Each memory type contain different bits of the same stub.
// AllStub and TE memories has several versions/copies of the VM.

// NOTE: Nothing in VMRouter.h needs to be changed to run a different phi region


#ifndef TrackletAlgorithm_VMRouter_h
#define TrackletAlgorithm_VMRouter_h

#include "ap_int.h"
#include <cassert>

#include "Constants.h"
#include "InputStubMemory.h"
#include "AllStubMemory.h"
#include "VMStubMEMemory.h"
#include "VMStubTEInnerMemory.h"
#include "VMStubTEOuterMemory.h"
#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif
// #define VMR_DEBUG

/////////////////////////////////////////
// Constants

// Constants used for calculating which VM a stub belongs to
constexpr float maxvmbins = 1 << nbits_maxvm; // How many bins nbits_maxvm would correspond to
constexpr float maxvmolbins = 1 << nbits_maxvm_overlap; // Overlap

constexpr unsigned int nbitsphiraw = 7; // Number of bits used for calculating iPhiRawPlus/Minus

// Number of rz bin bits for ME
constexpr unsigned kNbitsrzbinMELayer = kNbitsrzbin;
constexpr unsigned kNbitsrzbinMEDisk = kNbitsrzbin + 1;

// The length of the masks used for the memories
constexpr int masksize = 1 << nbits_maxvm;
constexpr int maskOLsize = 1 << nbits_maxvm_overlap; // TEInner Overlap memories

//////////////////////////////////////
// Functions used by the VMR

// Returns top 5 (nbits_maxvm) bits of phi, i.e. max 31 in decimal
template<regionType InType>
inline ap_uint<nbits_maxvm> iphivmRaw(const typename AllStub<InType>::ASPHI phi) {

	ap_uint<nbits_maxvm> iphivm = phi.range(phi.length() - 1, phi.length() - nbits_maxvm);

	return iphivm;
}

// Returns a number from 0 to 31. for both the plus and the minus:
// we add a small amount to the raw value; if it's not the same
// as the central value we copy the data to the adjacent memory as well.
template<regionType InType>
inline ap_uint<nbits_maxvm> iphivmRawPlus(const typename AllStub<InType>::ASPHI phi) {

	ap_uint<nbitsphiraw> tmp(phi.range(phi.length() - 1, phi.length() - nbitsphiraw));
	++tmp;
	ap_uint<nbits_maxvm> plus(tmp.range(tmp.length() - 1, nbitsphiraw - nbits_maxvm));

	return plus;
}

// See above.
template<regionType InType>
inline ap_uint<nbits_maxvm> iphivmRawMinus(const typename AllStub<InType>::ASPHI phi) {

	ap_uint<nbitsphiraw> tmp(phi.range(phi.length() - 1, phi.length() - nbitsphiraw));
	--tmp;
	ap_uint<nbits_maxvm> minus(tmp.range(tmp.length() - 1, nbitsphiraw - nbits_maxvm));

	return minus;
}

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

	constexpr auto rBins = 1 << kNbitsrzbin; // The number of bins for r

	ap_uint<kNbitsrzbin> rBin = (r + (1 << (r.length() - 1)))
			>> (r.length() - kNbitsrzbin); // Which bin r belongs to. Note r = 0 is mid radius
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

// Returns the number of the first ME/TE memory for the current VMRouter
// I.e. the position of the first non-zero bit in the mask
// L1PHIE17 would return 16
inline ap_uint<nbits_maxvm> firstMemNumber(const ap_uint<static_cast<int>(maxvmbins)> mask) {
	ap_uint<static_cast<int>(maxvmbins)> i = 0;
	ap_uint<1> x = mask[i]; // Value of the i:th bit

	// Stop counter when we have reached the first non-zero bit
	while (x == 0 && i < (maxvmbins - 1)) {
		i++;
		x = mask[i];
	}

	return i;
}

// Clears a 2D array of ap_uints by setting everything to 0
// Don't put the first dimension in template parameter as synthesis
// will crash if you're not using OL memories (i.e. they are set to 0)
template<int dim2Length, int nbits>
void clear2DArray(int dim1Length, ap_uint<nbits> array[][dim2Length]) {
#pragma HLS inline
#pragma HLS array_partition variable=array complete dim=0
	for (int i = 0; i < dim1Length; i++) {
#pragma HLS UNROLL
		for (int j = 0; j < dim2Length; j++) {
#pragma HLS UNROLL
				array[i][j] = 0;
		}
	}
}

// Clears a 3D array of ap_uints by setting everything to 0
template<int dim2Length, int dim3Length, int nbits>
void clear3DArray(int dim1Length, ap_uint<nbits> array[][dim2Length][dim3Length]) {
#pragma HLS inline
#pragma HLS array_partition variable=array complete dim=0
	for (int i = 0; i < dim1Length; i++) {
#pragma HLS UNROLL
		for (int j = 0; j < dim2Length; j++) {
#pragma HLS UNROLL
			for (int k = 0; k < dim3Length; k++) {
#pragma HLS UNROLL
				array[i][j][k] = 0;
			}
		}
	}
}

// Returns a ME stub with all the values set
template<regionType InType, regionType OutType, int Layer, int Disk>
inline VMStubME<OutType> createStubME(const InputStub<InType> stub,
		const int index, const bool negDisk, const int fineBinTable[],
		const int phiCorrTable[], int& ivmPlus, int& ivmMinus, int& bin) {

	// The MEStub that is going to be returned
	VMStubME<OutType> stubME;

	// Values from InputStub
	auto z = stub.getZ();
	auto r = stub.getR();
	auto bend = stub.getBend();
	auto phi = stub.getPhi();
	auto phiCorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)

	int nrBits = r.length(); // Number of bits for r
	int nzBits = z.length(); // Number of bits for z
	int nbendBits = bend.length(); // Number of bits for bend
	int nfinerzbits = stubME.getFineZ().length(); // Number of bits for finer/z
	int nFinePhiBits = stubME.getFinePhi().length(); // Number of bits used for fine phi

	// Number of bits for table indices
	constexpr int nbitszfinebintable =
			(Layer) ? kNbitszfinebintable : kNbitszfinebintableDisk; // Number of MSBs of z used in finebintable
	constexpr int nbitsrfinebintable =
			(Layer) ? kNbitsrfinebintable : kNbitsrfinebintableDisk; // Number of MSBs of r used in finebintable

	// Number of bits needed for all MEs in a layer/disk in a sector
	constexpr auto vmbits =
			(Layer) ? nbitsallstubs[Layer - 1] + nbits_vmmeall[Layer - 1] : nbitsallstubs[trklet::N_LAYER + Disk - 1] + nbits_vmmeall[trklet::N_LAYER + Disk - 1];
	// Total number of VMs for ME
	constexpr int nvmTotME = 1 << vmbits;

	// Some sort of normalisation thing used for determining which VM the stub belongs to
	static const ap_ufixed<nbits_maxvm, nbits_maxvm-1> d_me = nvmTotME / maxvmbins;

	// Set values to VMStubME
	stubME.setBend(bend);
	stubME.setIndex(index);
	stubME.setFinePhi(
			iphivmFineBins<InType>(phiCorr, vmbits, nFinePhiBits)); // Set finephi, i.e. the phi bits within a vme region region

	auto iphiRaw = iphivmRaw<InType>(phiCorr); // Top 5 bits of phi
	auto iphiRawPlus = iphivmRawPlus<InType>(phiCorr); // Top 5 bits of phi after adding a small number
	auto iphiRawMinus = iphivmRawMinus<InType>(phiCorr); // Top 5 bits of phi after subtracting a small number

	int ivm = iphiRaw * d_me; // The VM number
	ivmPlus = iphiRawPlus * d_me;
	ivmMinus = iphiRawMinus * d_me;

	// To avoid overflow
	if (ivmMinus > ivm)
		ivmMinus = 0;
	if (ivmPlus < ivm)
		ivmPlus = nvmTotME - 1;

	// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
	assert(std::abs(ivmMinus - ivmPlus) <= 1);


	// Indices used to find the rzfine value in finebintable
	// finebintable returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nbitszfinebintable + nbitsrfinebintable> indexz =
			((z + (1 << (nzBits - 1))) >> (nzBits - nbitszfinebintable)); // Make z unsigned and take the top "nbitszfinebintable" bits
	ap_uint<nbitsrfinebintable> indexr = -1;

	constexpr int rbins = (1 << nbitsrfinebintable); // Number of bins in r in finebintable

	if (Disk) {
		if (negDisk) {
			indexz = (1 << nbitszfinebintable) - indexz;
		}
		indexr = r;
		if (InType == DISKPS) {
			indexr = r >> (nrBits - nbitsrfinebintable); // Take the top "nbitsrfinebintable" bits
		}
	} else { // Layer
		indexr = ((r + (1 << (nrBits - 1)))
				>> (nrBits - nbitsrfinebintable)); // Make r unsigned and take the top "nbitsrfinebintable" bits
	}

	// The index for finebintable
	ap_uint<nbitszfinebintable + nbitsrfinebintable> finebinindex = (indexz * rbins) + indexr;

	// Get the corrected r/z position
	auto rzCorr = fineBinTable[finebinindex];

	// Coarse z. The bin the stub is going to be put in, in the memory
	bin = rzCorr >> nfinerzbits; // 3 bits, i.e. max 8 bins within each VM

	if (negDisk)
		bin += 1 << MEBinsBits; // bin 8-16 are for negative disks

	// Set rzfine, i.e. the r/z bits within a coarse r/z region
	auto rzfine = rzCorr & ((1 << nfinerzbits) - 1); // the 3 LSB as rzfine
	stubME.setFineZ(rzfine);

	assert(rzfine >= 0);

	return stubME;
};


// Returns a TE Inner stub with all the values set
template<regionType InType, regionType OutType, int Layer, int Disk>
inline VMStubTEInner<OutType> createStubTEInner(const InputStub<InType> stub,
		const int index, const bool negDisk, const int rzbitsInnerTable[],
		const int phiCorrTable[], int& ivm, int& rzbits) {

	// The TEInner Stub that is going to be returned
	VMStubTEInner<OutType> stubTEI;

	// Values from InputStub
	auto z = stub.getZ();
	auto r = stub.getR();
	auto bend = stub.getBend();
	auto phi = stub.getPhi();
	auto phiCorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)

	int nrBits = r.length(); // Number of bits for r
	int nzBits = z.length(); // Number of bits for z
	int nbendBits = bend.length(); // Number of bits for bend
	int nFinePhiBits = stubTEI.getFinePhi().length(); // Number of bits used for fine phi

	// Number of bits used for table indices
	constexpr auto nzbitsinnertable =
			(Layer) ? kNbitszfinebintable : kNbitszfinebintableDisk; // Number of bits for zbins in Inner Table
	constexpr auto nrbitsinnertable =
			(Layer) ? kNbitsrfinebintable : kNbitsrfinebintableDisk; // Number of bits for rbins in Inner Table
	constexpr auto vmbitsTmp =
			(Layer) ? nbitsallstubs[Layer - 1] + nbits_vmte[Layer - 1] : nbitsallstubs[trklet::N_LAYER + Disk - 1] + nbits_vmte[trklet::N_LAYER + Disk - 1]; // Number of bits for standard VMs
	constexpr auto vmbits =
			(Layer != 2) ? vmbitsTmp : nbitsallstubs[Layer - 1] + nbits_vmte_extra[Layer - 1]; // Number of bits for VMs

	// Total number of VMs for TE in a whole sector
	constexpr int nvmTotTEI = 1 << vmbits;

	// Some sort of normalisation thing used for determining which VM the stub belongs to
	static const ap_ufixed<nbits_maxvm, nbits_maxvm-1> d_te = nvmTotTEI / maxvmbins;

	// Set values to VMStubeTEInner
	stubTEI.setBend(bend);
	stubTEI.setIndex(index);
	stubTEI.setFinePhi(
			iphivmFineBins<InType>(phiCorr, vmbits, nFinePhiBits));

	auto iphiRaw = iphivmRaw<InType>(phiCorr); // Top 5 bits of phi

	ivm = iphiRaw * d_te; // The VM number


	// Indices used to find the rzfine value in finebintable
	// finebintable returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nzbitsinnertable + nrbitsinnertable> indexz =
			((z + (1 << (nzBits- 1))) >> (nzBits- nzbitsinnertable)); // Make z unsigned and take the top "nbitszfinebintable" bits
	ap_uint<nrbitsinnertable> indexr = -1;

	constexpr auto rbins = (1 << nrbitsinnertable); // Number of bins in r

	if (Disk) {
		if (negDisk) {
			indexz = (1 << nzbitsinnertable) - indexz;
		}
		indexr = r;
		if (InType == DISKPS) {
			indexr = r >> (nrBits- nrbitsinnertable); // Take the top "nbitsrfinebintable" bits
		}
	} else { // Layer
		indexr = ((r + (1 << (nrBits- 1)))
				>> (nrBits- nrbitsinnertable)); // Make r unsigned and take the top "nbitsrfinebintable" bits
	}

	int rzbitsIndex = indexz * rbins + indexr; // Index for rzbits LUT

	rzbits = rzbitsInnerTable[rzbitsIndex]; // The z/r information bits saved for TE Inner memories.

	stubTEI.setZBits(rzbits);

	return stubTEI;
}


// Returns a TE Outer stub with all the values set
template<regionType InType, regionType OutType, int Layer, int Disk>
inline VMStubTEOuter<OutType> createStubTEOuter(const InputStub<InType> stub,
		const int index, const bool negDisk, const int rzbitsOuterTable[],
		const int phiCorrTable[], int& ivm, int& bin) {

	// The TEOuter stub that is going to be returned
	VMStubTEOuter<OutType> stubTEO;

	// Values from InputStub
	auto z = stub.getZ();
	auto r = stub.getR();
	auto bend = stub.getBend();
	auto phi = stub.getPhi();
	auto phiCorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius

	int nrBits = r.length(); // Number of bits for r
	int nzBits = z.length(); // Number of bits for z
	int nbendBits = bend.length(); // Number of bits for bend
	int nfinerzbits = stubTEO.getFineZ().length(); // Number of bits for finer/z
	int nFinePhiBits = stubTEO.getFinePhi().length();  // Number of bits for finephi

	// Number of bits used for LUT indices
	constexpr auto nzbitsoutertable =
			(Layer) ? kNbitszfinebintable : kNbitszfinebintableDisk; // Number of bits for zbins in Outer Table
	constexpr auto nrbitsoutertable =
			(Layer) ? kNbitsrfinebintable : kNbitsrfinebintableDisk; // Number of bits for rbins in Outer Table
	constexpr auto vmbitsTmp =
			(Layer) ? nbitsallstubs[Layer - 1] + nbits_vmte[Layer - 1] : nbitsallstubs[trklet::N_LAYER + Disk - 1] + nbits_vmte[trklet::N_LAYER + Disk - 1]; // Number of bits for standard VMs
	constexpr auto vmbits =
			(Layer != 3) ? vmbitsTmp : nbitsallstubs[Layer - 1] + nbits_vmte_extra[Layer - 1]; // Number of bits for VMs

	// Total number of VMs for TE in a whole sector
	constexpr int nvmTotTEO = 1 << vmbits;

	// Some sort of normalisation thing used for determining which VM the stub belongs to
	static const ap_ufixed<nbits_maxvm, nbits_maxvm-1> d_te = nvmTotTEO / maxvmbins;


	// Set values to VMSTubTE Outer
	stubTEO.setBend(bend);
	stubTEO.setIndex(index);
	stubTEO.setFinePhi(
				iphivmFineBins<InType>(phiCorr, vmbits, nFinePhiBits));

	auto iphiRaw = iphivmRaw<InType>(phiCorr); // Top 5 bits of phi

	ivm = iphiRaw * d_te; // The VM number

	// Indices used to find the rzfine value in finebintable
	// finebintable returns the top 6 bits of a corrected z
	// Note: not the index that is being saved to the stub
	ap_uint<nzbitsoutertable + nrbitsoutertable> indexz =
			((z + (1 << (nzBits- 1))) >> (nzBits- nzbitsoutertable)); // Make z unsigned and take the top "nbitszfinebintable" bits
	ap_uint<nrbitsoutertable> indexr = -1;

	constexpr auto rbins = (1 << nrbitsoutertable); // Number of bins in r

	if (Disk) {
		if (negDisk) {
			indexz = (1 << nzbitsoutertable) - indexz;
		}
		indexr = r;
		if (InType == DISKPS) {
			indexr = r >> (nrBits- nrbitsoutertable); // Take the top "nbitsrfinebintable" bits
		}
	} else { // Layer
		indexr = ((r + (1 << (nrBits- 1)))
				>> (nrBits- nrbitsoutertable)); // Make r unsigned and take the top "nbitsrfinebintable" bits
	}

	// Find the VM bit information in rzbits LUT
	// First 2/3 MSBs is the binning in r, and the 3 LSB is the fine r within a bin
	ap_uint<nzbitsoutertable + nrbitsoutertable> rzbitsIndex = indexz * rbins + indexr; // Index for LUT
	auto rzbits = rzbitsOuterTable[rzbitsIndex];

	bin = rzbits >> nfinerzbits; // Remove the 3 LSBs, i.e. the finebin bits

	// Half the bins, i.e. bin 4-7, are used for negative disks
	if (negDisk)
		bin += (1 << TEBinsBits)/2; // += 4

	// Set fine r
	auto rfine = rzbits & ((1 << nfinerzbits) - 1); // Take the 3 (nfinerzbits) LSBs
	stubTEO.setFineZ(rfine);

	return stubTEO;
}


// Returns a TE Overlap stub with all the values set
template<regionType InType, int Layer>
inline VMStubTEInner<BARRELOL> createStubTEOverlap(const InputStub<InType> stub,
		const int index, const int rzbitsOverlapTable[],
		const int phiCorrTable[], int& ivm, int& rzbits) {

	// The overlap stub that is going to be returned
	VMStubTEInner<BARRELOL> stubOL;

	// Values from InputStub
	auto z = stub.getZ();
	auto r = stub.getR();
	auto bend = stub.getBend();
	auto phi = stub.getPhi();
	auto phiCorr = getPhiCorr<InType>(phi, r, bend, phiCorrTable); // Corrected phi, i.e. phi at nominal radius (what about disks?)

	int nrBits = r.length(); // Number of bits for r
	int nzBits = z.length(); // Number of bits for z
	int nbendBits = bend.length(); // Number of bits for bend

	// Number of bits
	constexpr auto vmbits = ((Layer == 1) || (Layer == 2)) ? nbitsallstubs[Layer - 1] + nbits_vmte_overlap[Layer - 1] : 0; // Number of bits used for VMs
	constexpr auto nvmTotOL = 1 << vmbits; // Total number of VMs for Overlap in a whole sector
	static const auto nFinePhiBits = stubOL.getFinePhi().length(); // Number of bits used for fine phi

	// Some sort of normalisation thing used for determining which VM the stub belongs to
	static const ap_ufixed<nbits_maxvm, nbits_maxvm_overlap-1> d_ol = nvmTotOL / maxvmolbins;

	// Set values to Overlap stub

	// 16 overlap vms per layer
	auto iphiRawOl = iphivmRaw<InType>(phiCorr) >> 1; // Top 4 bits of phi

	ivm = iphiRawOl * d_ol; // Which VM it belongs to

	constexpr auto rbins = (1 << kNbitsrfinebintable); // Number of bins in r

	ap_uint<kNbitszfinebintable> zbin = (z + (1 << (nzBits- 1)))
			>> (nzBits- kNbitszfinebintable); // Make z positive and take the 7 MSBs
	ap_uint<kNbitsrfinebintable> rbin = (r + (1 << (nrBits- 1)))
			>> (nrBits- kNbitsrfinebintable);

	ap_uint<kNbitszfinebintable + kNbitsrfinebintable> rzbitsIndex = zbin * rbins + rbin; // Index for rzbitsoverlaptable

	rzbits = rzbitsOverlapTable[rzbitsIndex];

	stubOL.setBend(bend);
	stubOL.setIndex(index);
	stubOL.setZBits(rzbits);
	stubOL.setFinePhi(
	iphivmFineBins<InType>(phiCorr, vmbits,
			nFinePhiBits));

	return stubOL;
}


/////////////////////////////////
// Main function

// InType DISK2S - Two input region types InType and DISK2S due to the disks having both 2S and PS inputs.
// 		According to wiring script, there's two DISK2S and half the inputs are for negative disks.
// Layer Disk - Specifies the layer or disk number
// MAXCopies - The maximum number of copies of a memory type
// NBitsMemAddr number of bits used to address the stubs
// NBitsBin number of bits used for the bins in MEMemories
template<regionType InType, regionType OutType, int Layer, int Disk, int nInputMems, int nInputDisk2SMems, int MaxAllCopies, int MaxTEICopies, int MaxOLCopies, int MaxTEOCopies, int NBitsMemAddr, int NBitsBin, int BendCutTableSize>
void VMRouter(const BXType bx, BXType& bx_o, const int fineBinTable[], const int phiCorrTable[],
		// rzbitstables, aka binlookup in emulation
		const int rzbitsInnerTable[], const int rzbitsOverlapTable[], const int rzbitsOuterTable[],
		// bendcut tables
		const ap_uint<BendCutTableSize> bendCutInnerTable[], const ap_uint<BendCutTableSize> bendCutOverlapTable[], const ap_uint<BendCutTableSize> bendCutOuterTable[],
		// Input memories
		const InputStubMemory<InType> inputStubs[],
		const InputStubMemory<DISK2S> inputStubsDisk2S[],
		// AllStub memory
		AllStubMemory<OutType> memoriesAS[],
		// ME memories
		const ap_uint<masksize>& maskME, VMStubMEMemory<OutType, NBitsMemAddr, NBitsBin> memoriesME[],
		// Inner TE memories, non-overlap
		const ap_uint<masksize>& maskTEI, VMStubTEInnerMemory<OutType> memoriesTEI[][MaxTEICopies],
		// TE Inner memories, overlap
		const ap_uint<maskOLsize>& maskOL, VMStubTEInnerMemory<BARRELOL> memoriesOL[][MaxOLCopies],
		// TE Outer memories
		const ap_uint<masksize>& maskTEO, VMStubTEOuterMemory<OutType> memoriesTEO[][MaxTEOCopies],
                ap_uint<1> &almost_done) {

#pragma HLS inline

// Partition arrays
#pragma HLS array_partition variable=bendCutInnerTable complete dim=1
#pragma HLS array_partition variable=bendCutOverlapTable complete dim=1
#pragma HLS array_partition variable=bendCutOuterTable complete dim=1
#pragma HLS array_partition variable=inputStubs complete dim=1
#pragma HLS array_partition variable=inputStubsDisk2S complete dim=1
#pragma HLS array_partition variable=memoriesAS complete dim=1
#pragma HLS array_partition variable=memoriesME complete dim=1
#pragma HLS array_partition variable=memoriesTEI complete dim=1
#pragma HLS array_partition variable=memoriesTEI complete dim=2
#pragma HLS array_partition variable=memoriesOL complete dim=1
#pragma HLS array_partition variable=memoriesOL complete dim=2
#pragma HLS array_partition variable=memoriesTEO complete dim=1
#pragma HLS array_partition variable=memoriesTEO complete dim=2

// Take 2 clock cycles before on gets data, used at high frequencies
#pragma HLS resource variable=fineBinTable latency=2
#pragma HLS resource variable=rzbitsInnerTable latency=2
#pragma HLS resource variable=rzbitsOverlapTable latency=2
#pragma HLS resource variable=rzbitsOuterTable latency=2

	// The first memory numbers, the position of the first non-zero bit in the mask
	// Do not change these to ap_uint as cosim will fail
	static const int firstME = firstMemNumber(maskME); // ME memory
	static const int firstTEI = firstMemNumber(maskTEI); // TE Inner memory
	static const int firstOL = firstMemNumber(maskOL); // TE Overlap memory
	static const int firstTEO = firstMemNumber(maskTEO); // TE Inner memory

	// Number of memories/VMs for one coarse phi region
	constexpr int nvmME = (Layer) ? (1 << nbits_vmmeall[Layer-1]) : (1 << nbits_vmmeall[trklet::N_LAYER + Disk-1]); // ME memories
	constexpr int nvmTE = (Layer) ? (1 << nbits_vmte[Layer-1]) : (1 << nbits_vmte[trklet::N_LAYER + Disk-1]); // TE memories
	constexpr int nvmOL = ((Layer == 1) || (Layer == 2)) ? (1 << nbits_vmte_overlap[Layer-1]) : 0; // TE Overlap memories

	constexpr int nmaxbinsperpage = (Layer) ? 1 << MEBinsBits : 1 << (MEBinsBits + 1); // Number of bins per page in memories

	// Number of data in each input memory
	typename InputStubMemory<InType>::NEntryT nInputs[nInputMems + nInputDisk2SMems]; // Array containing the number of inputs. Last two indices are for DISK2S
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
	ap_uint<kNBits_MemAddr> addrCountME[nvmME][nmaxbinsperpage]; // Writing of ME stubs
	ap_uint<kNBits_MemAddr> addrCountTEI[nvmTE][MaxTEICopies]; // Writing of TE Inner stubs
	ap_uint<kNBits_MemAddr> addrCountOL[nvmOL][MaxOLCopies]; // Writing of TE Overlap stubs
	ap_uint<kNBits_MemAddr> addrCountTEO[nvmTE][MaxTEOCopies][nmaxbinsperpage]; // Writing of TE Outer stubs


	/////////////////////////////////////
	// Main Loop
	constexpr int maxLoop = kMaxProc - kMaxProcOffset(module::VMR);

	TOPLEVEL: for (int i = -1; i < maxLoop; ++i) {
#pragma HLS PIPELINE II=1 rewind

                almost_done = (i < maxLoop - 2) ? 0 : 1;

		// Use first loop iteration to clear the address count arrays.
		// Putting this inside the loop rather than outside reduces errors when simulating the VHDL top-level in Vivado for bxs
		// with around 108 stubs. Otherwise the write addresses did not get reset properly and stubs got written to the wrong address.
		if (i == -1) {
			if (maskME) {
				clear2DArray(nvmME, addrCountME);
			}
			if (maskTEI) {
				clear2DArray(nvmTE, addrCountTEI);
			}
			if (maskOL) {
				clear2DArray(nvmOL, addrCountOL);
			}
			if (maskTEO) {
				clear3DArray(nvmTE, addrCountTEO);
			}
			continue;
		}

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
			for (int n = 0; n < MaxAllCopies; n++) {
	#pragma HLS UNROLL
				memoriesAS[n].write_mem(bx, allstub, i);
			}

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			edm::LogVerbatim("L1trackHLS") << std::endl << "Stub index no. " << i << std::endl << "Out put stub: " << std::hex << allstub.raw() << std::dec;
#endif // VMR_DEBUG


		/////////////////////////////////////////////
		// ME memories

		if (maskME != 0) {

			// Virtual modules to write to
			int ivmPlus;
			int ivmMinus;

			int bin; // Coarse z. The bin the stub is going to be put in, in the memory

			// Create the ME stub to save
			VMStubME<OutType> stubME = (disk2S) ?
					createStubME<DISK2S, OutType, Layer, Disk>(stubDisk2S, i, negDisk, fineBinTable, phiCorrTable, ivmPlus, ivmMinus, bin) :
					createStubME<InType, OutType, Layer, Disk>(stub, i, negDisk, fineBinTable, phiCorrTable, ivmPlus, ivmMinus, bin);;

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			edm::LogVerbatim("L1trackHLS") << "ME stub " << std::hex << stubME.raw();
			edm::LogVerbatim("L1trackHLS") << "ivm Minus,Plus = " << std::dec << ivmMinus << " " << ivmPlus << " " << "\t0x"
					<< std::setfill('0') << std::setw(4) << std::hex << stubME.raw().to_int() << std::dec << ", to bin " << bin;
			if (!maskME[ivmPlus]) {
				std::cerr << "Trying to write to non-existent memory for ivm = " << ivmPlus << std::endl;
					}
			if (!maskME[ivmMinus]) {
				std::cerr << "Trying to write to non-existent memory for ivm = " << ivmMinus << std::endl;
			}
#endif // VMR_DEBUG

			// Write the ME stub to the correct memory.
			// If stub is close to a border (ivmPlus != ivmMinus)
			// write it to the adjacent memory as well
			// #pragma HLS dependence variable=memoriesME intra false
			for (int n = 0; n < maxvmbins; n++) {
#pragma HLS UNROLL
				if (maskME[n]) {
					if ((ivmMinus == n) || (ivmPlus == n)) {
#pragma HLS dependence variable=addrCountME intra WAR true
						int memIndex = n-firstME;
						memoriesME[memIndex].write_mem(bx, bin, stubME, addrCountME[memIndex][bin]);
						addrCountME[memIndex][bin] += 1;
					}
				}
			}
		} // End ME memories


		//////////////////////////////////
		// TE Inner Memories

		// No stubs for DISK2S
		if ((maskTEI != 0) && (!disk2S)) {

			int ivm;// Which VM to write to

			// The z/r information bits saved for TE Inner memories.
			// Which VMs to look at in the outer layer.
			// Note: not the z/r coordinate for the inner stub
			// Called binlookup in emulation
			int rzbits;

			// Create the TE Inner stub to save
			VMStubTEInner<OutType> stubTEI = createStubTEInner<InType, OutType, Layer, Disk>(stub, i, negDisk, rzbitsInnerTable, phiCorrTable, ivm, rzbits);

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			edm::LogVerbatim("L1trackHLS") << "TEInner stub " << std::hex << stubTEI.raw();
			edm::LogVerbatim("L1trackHLS") << "ivm: " << std::dec << ivm;
#endif // VMR_DEBUG

			// Write the TE Inner stub to the correct memory
			// Only if it has a valid rzbits/binlookup value, i.e. not -1,
			// and a valid bend
			if ((rzbits != -1) && maskTEI[ivm]) {
				int memIndex = ivm-firstTEI; // Index for the correct memory in memory array
				int bendIndex = memIndex*MaxTEICopies; // Index for bendcut LUTs

				for (int n = 0; n < MaxTEICopies; n++) {
#pragma HLS UNROLL
					bool passBend = bendCutInnerTable[bendIndex][stubTEI.getBend()];
					if (passBend) {
#pragma HLS dependence variable=addrCountTEI intra WAR true
						memoriesTEI[memIndex][n].write_mem(bx, stubTEI, addrCountTEI[memIndex][n]);
						addrCountTEI[memIndex][n] += 1; // Count the memory addresses we have written to
					}
					bendIndex++; // Use next bendcut table for the next memory "copy"
				}
			}
		} // End TE Inner memories


		////////////////////////////////////
		// TE Outer memories

		if ((maskTEO != 0) && (!disk2S)) {

			int ivm; // The VM number
			int bin; // Coarse z. The bin the stub is going to be put in, in the memory

			// Create the TE Outer stub to save
			VMStubTEOuter<OutType> stubTEO = createStubTEOuter<InType, OutType, Layer, Disk>(stub, i, negDisk, rzbitsOuterTable, phiCorrTable, ivm, bin);

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			edm::LogVerbatim("L1trackHLS") << "TEOuter stub " << std::hex << stubTEO.raw();
			edm::LogVerbatim("L1trackHLS") << "    ivm: " << std::dec << ivm << "       to bin " << bin;
#endif // VMR_DEBUG

			// Write the TE Outer stub to the correct memory
			// Only if it has a valid bend
			if (maskTEO[ivm]) {
				int memIndex = ivm-firstTEO; // Index for the correct memory in memory array and address
				int bendIndex = memIndex*MaxTEOCopies; // Index for bendcut LUTs
				for (int n = 0; n < MaxTEOCopies; n++) {
#pragma HLS UNROLL
					bool passBend = bendCutOuterTable[bendIndex][stubTEO.getBend()]; // Check if stub passes bend cut
					if (passBend) {
#pragma HLS dependence variable=addrCountTEO intra WAR true
						memoriesTEO[memIndex][n].write_mem(bx, bin, stubTEO, addrCountTEO[memIndex][n][bin]);
						addrCountTEO[memIndex][n][bin] += 1;
					}
					bendIndex++; // Use next bendcut table for the next memory "copy"
				}
			}
		} // End TE Outer memories


		/////////////////////////////////////
		// OVERLAP Memories

		if (maskOL != 0) {

			assert(Layer == 1 || Layer == 2); // Make sure that only run layer 1 and 2

			int ivm; // Which VM to write to

			// The z/r information bits saved for TE Inner memories.
			// Which VMs to look at in the outer layer.
			// Note: not the z/r coordinate for the inner stub
			// Called binlookup in emulation
			int rzbits;

			// Create the TE Inner Overlap stub to save
			VMStubTEInner<BARRELOL> stubOL = createStubTEOverlap<InType, Layer>(stub, i, rzbitsOverlapTable, phiCorrTable, ivm, rzbits);

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			edm::LogVerbatim("L1trackHLS") << "Overlap stub " << " " << std::hex << stubOL.raw();
			edm::LogVerbatim("L1trackHLS") << "ivm: " << std::dec << ivm;
#endif // VMR_DEBUG

			// Save stub to Overlap memories
			if (maskOL[ivm] && (rzbits != -1)) {
				int memIndex = ivm - firstOL; // The memory index in array and addrcount
				int bendIndex = memIndex*MaxOLCopies; // Index for bendcut LUTs
				for (int n = 0; n < MaxOLCopies; n++) {
#pragma HLS UNROLL
					bool passBend = bendCutOverlapTable[bendIndex][stubOL.getBend()];
					if (passBend) {
#pragma HLS dependence variable=addrCountOL intra WAR true
						memoriesOL[memIndex][n].write_mem(bx, stubOL, addrCountOL[memIndex][n]);
						addrCountOL[memIndex][n] += 1;
					}
					bendIndex++;
				}
			}

#if !defined(__SYNTHESIS__) && defined(VMRCM_DEBUG)
			else {
			  edm::LogVerbatim("L1trackHLS") << "NO OVERLAP";
			}
#endif // VMR_DEBUG

		} // End TE Overlap memories
	} // Outside main loop

	bx_o = bx;
} // End VMRouter

#endif // TrackletAlgorithm_VMRouter_h
