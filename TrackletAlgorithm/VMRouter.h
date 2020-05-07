// VMRouter
// Log
// -------
// First tracklet 2.0 version -- December 2018 -- wittich

#ifndef VMROUTER_HH
#define VMROUTER_HH

#pragma once
#include "ap_int.h"

#include "Constants.h"
#include "InputStubMemory.h"
#include "AllStubMemory.h"
#include "VMStubMEMemory.h"
#include "VMStubTEInnerMemory.h"
#include "VMStubTEOuterMemory.h"
#include <assert.h>
#include <bitset> // For debugging purposes

// I include this to get the constants. we should figure out if this is
// the right way to go.
#include "MatchCalculator.h"
// from FPGAConstants.hh -- needs a final home

constexpr double rmaxdisk = 120.0;
constexpr int nrbitsdisk = 12;

constexpr unsigned int nallstubslayers[6] = { 8, 4, 4, 4, 4, 4 }; // Number of AllStub memories, coarse phi regions, per sector
constexpr unsigned int nvmtelayers[6] = { 4, 8, 4, 8, 4, 8 }; // Number of TE VM modules per coarse phi region

constexpr unsigned int nallprojlayers[6] = { 8, 4, 4, 4, 4, 4 };
constexpr unsigned int nvmmelayers[6] = { 4, 8, 8, 8, 8, 8 };

constexpr unsigned int nallstubsdisks[5] = { 4, 4, 4, 4, 4 };
constexpr unsigned int nvmmedisks[5] = { 4, 4, 4, 4, 4 };

constexpr unsigned int nvmtedisks[5] = { 4, 4, 4, 4, 4 };

constexpr double rmindiskvm = 22.5;
constexpr double rmaxdiskvm = 67.0;

//vm stubs
static const int nfinephibarrelinner = 2;
static const int nfinephibarrelouter = 3;

static const int nfinephidiskinner = 2; //too small!
static const int nfinephidiskouter = 3;

static const int nfinephioverlapinner = 2;
static const int nfinephioverlapouter = 3;

// need separate lookup values for inner two vs outer three disks for 2S modules
// these assume D11 geometry!
// Encoded r values for 2S disk modules
// TODO: only used for init_finebintable, remove or update
constexpr double rDSSinner[10] = { 66.7728, 71.7967, 77.5409, 82.5584, 84.8736,
		89.8953, 95.7791, 100.798, 102.495, 107.52 }; // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = { 65.1694, 70.1936, 75.6641, 80.6908, 83.9581,
		88.9827, 94.6539, 99.6772, 102.494, 107.519 }; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;

// Maximum number of stubs that can be processed (memory depth)
// originally 64, but then it won't pass test bench as it contains more than 64 stubs
constexpr int MAXVMROUTER = kMaxProc;

// Number of bits used for VMs and finephi, for different layers and disks
// TODO: maybe use something similar to updated C++ emulation
constexpr int vmbitsLayer[6] = {5, 5, 4, 5, 4, 5}; // Could be computed using the number of VMs...
constexpr int vmbitsDisk[5] = {4, 4, 4, 4, 4};
constexpr int vmbitsOverlap[2] = {4, 3};

// Currently not used, but should be kept for creating the finebin LUTs
// TODO: either remove this or write out function for all tables that are used?!
inline void init_finebintable(const int LAYER, const int DISK,
		int finebintable[kMaxFineBinTable], int & nbitsfinebintable) {
#ifndef __SYNTHESIS__
// initialize
	for (auto i = 0; i < kMaxFineBinTable; i++) {
		finebintable[i] = -1;
	}

	if (LAYER != 0) {
		nbitsfinebintable = 8;
		unsigned int nbins = 1 << nbitsfinebintable;

		for (unsigned int i = 0; i < nbins; i++) {
			int ibin = (i >> (nbitsfinebintable - 3));

			int zfine = (i >> (nbitsfinebintable - 6)) - (ibin << 3);

			//awkward bit manipulations since the index is from a signed number...
			int index = i + (1 << (nbitsfinebintable - 1));

			if (index >= (1 << nbitsfinebintable)) {
				index -= (1 << nbitsfinebintable);
			}

			finebintable[index] = zfine;

		}
	}

	if (DISK != 0) {

		nbitsfinebintable = 8;
		unsigned int nbins = 1 << nbitsfinebintable;

		for (unsigned int i = 0; i < nbins; i++) {

			double rstub = 0.0;

			if (i < 10) {
				if (DISK <= 2) {
					rstub = rDSSinner[i];
				} else {
					rstub = rDSSouter[i];
				}
			} else {
				rstub = kr * (i << (nrbitsdisk - nbitsfinebintable));
			}

			if (rstub < rmindiskvm) {
				finebintable[i] = -1;
			} else {
				int bin = 8.0 * (rstub - rmindiskvm) / (rmaxdisk - rmindiskvm);
				assert(bin >= 0);
				//assert(bin<MEBinsDisks);
				int rfine = 64
						* ((rstub - rmindiskvm)
								- bin * (rmaxdisk - rmindiskvm) / 8.0)
						/ (rmaxdisk - rmindiskvm);
				finebintable[i] = rfine;
			}
		}
	}
#else // __SYNTHESIS__
	int tmp[256]=
#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.tab"

	for (int i=0;i<256;i++) {
		finebintable[i]=tmp[i];
	}
	nbitsfinebintable = 256;
#endif // __SYNTHESIS__
}

// local files
// returns top 5 bits of phi, i.e. max 31 in decimal
template<regionType INTYPE>
inline ap_uint<5> iphivmRaw(const typename AllStub<INTYPE>::ASPHI phi) {
	// TODO: get rid of hard-coded values
	ap_uint<5> iphivm = phi.range(phi.length() - 1, phi.length() - 5);
	return iphivm;
}

// vmbits is the number of bits for the VMs, i.e. coarse phi region
// E.g. 32 VMs would use vmbits=5
// finebits is the number of bits within the VM
template<regionType INTYPE>
inline int iphivmFineBins(const typename AllStub<INTYPE>::ASPHI phi,
		const int vmbits, const int finebits) {

	auto v1 = (phi.range(phi.length() - 1 - vmbits, phi.length() - vmbits -finebits));
	//auto v2 = (phi >> (phi.length() - vmbits - finebits)) & ((1 << finebits) - 1);
	//std::cout << "PHI: " << phi << "   v1: " << v1 << "    v2: " << v2 << std::endl;
	//assert(v1 == v2);
	return v1;
}

// Returns a number from 0 to 31. for both the plus and the minus:
// we add a small amount to the raw value; if it's not the same
// as the central value we copy the data to the adjacent memory as well.
template<regionType INTYPE>
inline ap_uint<5> iphivmRawPlus(const typename AllStub<INTYPE>::ASPHI phi) {
	// // TODO: get rid of hard-coded values
	// ap_uint<7> tmp = phi.range(phi.length()-1,phi.length()-7);
	// auto iphivmp = ++tmp;
	// return ap_uint<5>(iphivmp(2,6));
	ap_uint<7> tmp(phi.range(phi.length() - 1, phi.length() - 7));
	++tmp;
	ap_uint<5> plus(tmp.range(tmp.length() - 1, 2));
	return plus;

}

// see above
template<regionType INTYPE>
inline ap_uint<5> iphivmRawMinus(const typename AllStub<INTYPE>::ASPHI phi) {
	ap_uint<7> tmp(phi.range(phi.length() - 1, phi.length() - 7));
	auto iphivmp = --tmp;
	return ap_uint<5>(iphivmp(6, 2));
	//  // TODO: get rid of hard-coded values
	//  auto iphivm=((phi-(1<<(phi.length()-7)))>>(phi.length()-5));
	//  if (iphivm<0) iphivm=0;
	//  else if (iphivm>31) iphivm=0;
	//  return ap_uint<5>(iphivm);

}

// Get the corrected phi, i.e. phi at the nominal radius of the barrel
// Corrected phi is used by TE (and ME?) for simplicity
template<regionType INTYPE>
inline typename AllStub<INTYPE>::ASPHI getPhiCorr(const typename AllStub<INTYPE>::ASPHI phi,
	const typename AllStub<INTYPE>::ASR r, const typename AllStub<INTYPE>::ASBEND bend, const int corrtable[]) {

	if (INTYPE == DISKPS || INTYPE == DISK2S) return phi; // Do nothing if disks

	constexpr auto rbins = 1 << 3; // The number of bins for r. Found hardcoded in VMRouterPhiCorrTable.h

	ap_uint<3> rbin=(r+(1<<(r.length()-1)))>>(r.length()-3); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * rbins + rbin; // index for where we find our correction value
	auto corrval = corrtable[index]; // the amount we need to correct our phi
	// TODO not safe from overflow?
	typename AllStub<INTYPE>::ASPHI phicorr = phi - corrval; // the corrected phi

	if (phicorr < 0) phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length()) phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}


// Get the number of the first ME/TE memory for the current VMRouter
//template<int nbits>
inline ap_uint<5> memStartVal(const ap_uint<32> mask) {
	ap_uint<5> i = 0;
	ap_uint<1> x = mask[i]; // Value of the i:th bit

	// Stop counter when we have reached the first non-zero bit
	while (x == 0 && i < 31) {
		//#pragma HLS UNROLL
		i++;
		x = mask[i];
	}

	return i;
}

/////////////////////////////////
// Main function

template<regionType INTYPE, regionType OUTTYPE, int LAYER, int DISK, int bendtablesize>
void VMRouter(const BXType bx, const int finebintable[], const int corrtable[], const int binlookuptable[], const int bendtable[][bendtablesize],
		const int overlaptable[],
		// Input memories
		const ap_uint<6>& imask, const InputStubMemory<INTYPE> inputStubs[],
		// AllStub memory
		AllStubMemory<INTYPE> allstub[],
		// ME memories
		const ap_uint<32>& memask, VMStubMEMemory<OUTTYPE> meMemories[],
		// // Inner TE memories, non-overlap
		const ap_uint<32>& teimask, VMStubTEInnerMemory<OUTTYPE> teiMemories[5][4],
		// // TE Inner memories, overlap
		const ap_uint<16>& olmask, VMStubTEInnerMemory<BARRELOL> olMemories[3][16],
		// // TE Outer memories
		const ap_uint<32>& teomask, VMStubTEOuterMemory<OUTTYPE> teoMemories[32]) {

	#pragma HLS inline

//#pragma HLS array_partition variable=finebintable
//#pragma HLS array_partition variable=bendtable
//#pragma HLS array_partition variable=binlookuptable //max 1024 partitions
//#pragma HLS array_partition variable=overlaptable
#pragma HLS array_partition variable = inputStubs complete
#pragma HLS array_partition variable = allstub complete
#pragma HLS array_partition variable = meMemories complete
#pragma HLS array_partition variable = teiMemories complete
#pragma HLS array_partition variable = olMemories complete
#pragma HLS array_partition variable = teoMemories complete

// Some variables
static int nbitsfinebintable = 8; // this appears to always be 8. Total number of bits the finebintable consists of

	// Reset address counters in output memories
	// Only clear if the masks says that memory is used
	constexpr int n_a = 6; // Number of AllStub memory copies. TODO: Remove hardcoded value
ALLSTUB_CLEAR:	for (int i = 0; i < n_a; i++) {
		#pragma HLS UNROLL
		allstub[i].clear(bx);
	}

		static const int startme = memStartVal(memask);
	if (memask) {

	constexpr int n_me = (LAYER) ? nvmmelayers[LAYER] : nvmmedisks[DISK]; // Number of used ME memories
ME_CLEAR:	for (int i = 0; i < n_me; i++) {
		#pragma HLS UNROLL
		if (memask[i + startme]) meMemories[i].clear(bx);
	}
}

	if (teimask) {
		static const int starttei = memStartVal(teimask);
		constexpr int n_tei = (LAYER) ? nvmtelayers[LAYER] : nvmtedisks[DISK]; //teimask.length();
		constexpr int n_cop = 5; // Number of TE Inner memory copies. TODO: Remove hardcoded value
	TEI_CLEAR:	for (int i = 0; i < n_tei; i++) {
			#pragma HLS UNROLL
			if (teimask[i + starttei]) {
				for (int j = 0; j < n_cop; j++) {
					#pragma HLS UNROLL
					teiMemories[j][i].clear(bx);
				}
			}
		}
	}

	if (teomask) {
	TEO_CLEAR:	for (int i; i < 32; i++) {
			#pragma HLS UNROLL
			teoMemories[i].clear(bx);
		}
	}

	if (olmask) {
		static const int nol = olmask.length();
	OL_CLEAR:	for (int i = 0; i < nol; i++) {
			#pragma HLS UNROLL
			if (olmask[i]) {
				for (int j = 0; j < 3; j++) {
					#pragma HLS UNROLL
				olMemories[j][i].clear(bx);
			}
			}
		}
	}

	// Number of data in each input memory
	const typename InputStubMemory<INTYPE>::NEntryT zero(0);

	auto n_i0 = imask[0] != 0 ? inputStubs[0].getEntries(bx) : zero;
	auto n_i1 = imask[1] != 0 ? inputStubs[1].getEntries(bx) : zero;
	auto n_i2 = imask[2] != 0 ? inputStubs[2].getEntries(bx) : zero;
	auto n_i3 = imask[3] != 0 ? inputStubs[3].getEntries(bx) : zero;
	auto n_i4 = imask[4] != 0 ? inputStubs[4].getEntries(bx) : zero;
	auto n_i5 = imask[5] != 0 ? inputStubs[5].getEntries(bx) : zero;


	// Create variables that keep track of which memory address to read and write to
	ap_uint<kNBits_MemAddr> read_addr(0); // Reading of input stubs

	int addrCountTEI[5][4]; // Writing of TE Inner stubs
#pragma HLS array_partition variable = addrCountTEI complete
ADDR_TEI:	for (int i = 0; i < 4; i++) {
		#pragma HLS UNROLL
		for (int j = 0; j < 5; j++) {
			#pragma HLS UNROLL
				addrCountTEI[j][i] = 0;
		}
	}

	int addrCountOL[16]; // Writing of TE Overlap stubs
#pragma HLS array_partition variable=addrCountOL complete
ADDR_OL:	for (int i = 0; i < 16; i++) {
		#pragma HLS UNROLL
		addrCountOL[i] = 0;
	}

	static const int firstmem = (teimask) ? memStartVal(teimask) : memStartVal(teomask); // The number of the first TE memory


	TOPLEVEL: for (auto i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1
//#pragma HLS latency max=4
		const bool haveData = (n_i0 > 0) || (n_i1 > 0) || (n_i2 > 0)
				|| (n_i3 > 0) || (n_i4 > 0) || (n_i5 > 0);

		// Stop processing stubs if we have looped over the maximum number
		// that can be processed or if we have gone through all data
		if ((i > MAXVMROUTER) || !haveData)
			continue;
		//const InputStubMemory *next; // this method makes vivado crash

		bool resetNext = false; // Used to reset read_addr
		InputStub<INTYPE> stub;

		// Read stub from memory in turn
		if (n_i0) {
			//next = i0;
			stub = inputStubs[0].read_mem(bx, read_addr);
			--n_i0;
			if (n_i0 == 0)
				resetNext = true;
		} else if (n_i1) {
			stub = inputStubs[1].read_mem(bx, read_addr);
			--n_i1;
			if (n_i1 == 0)
				resetNext = true;
		} else if (n_i2) {
			stub = inputStubs[2].read_mem(bx, read_addr);
			--n_i2;
			if (n_i2 == 0)
				resetNext = true;
		} else if (n_i3) {
			stub = inputStubs[3].read_mem(bx, read_addr);
			--n_i3;
			if (n_i3 == 0)
				resetNext = true;
		} else if (n_i4) {
			stub = inputStubs[4].read_mem(bx, read_addr);
			--n_i4;
			if (n_i4 == 0)
				resetNext = true;
		} else {
			stub = inputStubs[5].read_mem(bx, read_addr);
			--n_i5;
			if (n_i5 == 0)
				resetNext = true;
		}

		//auto stub=next->read_mem(bx, read_addr); // this caused vivado to crash

		// Increment the read address, or reset it to zero when all stubs in a memory has been read
		if (resetNext)
			read_addr = 0;
		else
			++read_addr;

		// add stub to all AllStub memory copies
		AllStub<INTYPE> allstubd(stub.raw());
		for (int n = 0; n < n_a; n++) {
			#pragma HLS UNROLL
			allstub[n].write_mem(bx, allstubd, i);
		}

// For debugging
#ifndef __SYNTHESIS__
		std::cout << "Out put stub: " << std::hex << allstubd.raw() << std::dec
				<< std::endl;
#endif // DEBUG

		// Variables that are used by ME and TE memories
		auto z = stub.getZ();
		auto r = stub.getR();
		auto nzbits = z.length(); // Number of z bits
		auto nrbits = r.length(); // Number of r bits
		auto bend = stub.getBend();
		auto stubPhi_uncorr = stub.getPhi(); // Original phi, uncorrected
		auto stubPhi = getPhiCorr<INTYPE>(stubPhi_uncorr, r, bend, corrtable); // Corrected phi, i.e. phi at nominal radius (what about disks?)



		///////////////////////////////////////////
		//executeME() START ------------------------------
		//hourglass only

		if (memask != 0) {
		// Total number of VMs for ME
		constexpr auto nvm =
				LAYER != 0 ?
						nallstubslayers[LAYER - 1] * nvmmelayers[LAYER - 1] :
						nallstubsdisks[DISK - 1] * nvmmedisks[DISK - 1];
		constexpr auto d = nvm / 32; // Some sort of normalisation thing

		//static const int startme = memStartVal(memask); // Number of the first ME memory

		VMStubME<OUTTYPE> stubme;
		stubme.setBend(bend);
		stubme.setIndex(typename VMStubME<OUTTYPE>::VMSMEID(i));

		auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
		auto iphiRawPlus = iphivmRawPlus<INTYPE>(stubPhi); // Top 5 bits of phi after adding a small number
		auto iphiRawMinus = iphivmRawMinus<INTYPE>(stubPhi); // Top 5 bits of phi after subtracting a small number

		ap_uint<5> ivm = iphiRaw * d; // The VM number
		ap_uint<5> ivmPlus = iphiRawPlus * d;
		ap_uint<5> ivmMinus = iphiRawMinus * d;

		// To avoid overflow
		if (ivmMinus > ivm)
			ivmMinus = 0;
		if (ivmPlus < ivm)
			ivmPlus = nvm - 1;

		// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
		assert(std::abs(ivm - ivmPlus) <= 1);
		assert(std::abs(ivm-ivmMinus) <= 1 );

		ap_uint<MEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

		if (DISK) { // Not implemented

			// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
			bin = (r >> (nrbits - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse r value

			// Index of where to find the rfine value in finebintable
			// The top 7 MSBs of r, ignoring the sign.
			// Note: not the index that is being saved to the stub
			typename VMStubME<OUTTYPE>::VMSMEID index = (r
					>> (r.length() - nbitsfinebintable))
					& ((1 << nbitsfinebintable) - 1);

			// Set rfine: the r position within a bin
			typename VMStubME<OUTTYPE>::VMSMEFINEZ rfine = finebintable[index]; // is it the same table as for z?
			assert(rfine >= 0);
			stubme.setFineZ(rfine);
		} else { // layer

			// Get the 3 MSBs of z and add 4 as z is signed (z takes values between -4 and 3)
			bin = (z >> (nzbits - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse z value

			// Index of where to find the zfine value in finebintable
			// The top 7 MSBs of z, ignoring the sign.
			// Note: not the index that is being saved to the stub
			// TODO: change the type?? it's confusing. Same for the other memories
			typename VMStubME<OUTTYPE>::VMSMEID index = (z
					>> (nzbits - nbitsfinebintable))
					& ((1 << nbitsfinebintable) - 1);

			// Set zfine: the z position within a bin
			typename VMStubME<OUTTYPE>::VMSMEFINEZ zfine = finebintable[index]; // Using the bits 5 down to 2?
			stubme.setFineZ(zfine);
		}

// For debugging
#ifndef __SYNTHESIS__
		std::cout << "ME stub " << std::hex << stubme.raw() << std::endl;
		std::cout << "ivm,Minus,Plus = " << std::dec << ivm << " "
				<< ivmMinus << " " << ivmPlus << " " << "\t0x"
				<< std::setfill('0') << std::setw(4) << std::hex
				<< stubme.raw().to_int() << std::dec << ", to bin " << bin
				<< std::endl;
		if ( ! memask[ivm] ) {
			std::cerr << "Trying to write to non-existent memory for ivm = "
			<< ivm << std::endl;
		}
#endif // DEBUG

		// Write the ME stub to the correct memory.
		// If stub is close to a border (ivmPlus/ivmMinus != ivm)
		// write it to the adjacent memory as well
		// Note that at least one of ivmPlus/Minus == ivm
		#pragma HLS dependence variable=meMemories intra false
		const int memIndexPlus = (memask[ivmPlus]) ? static_cast<int>(ivmPlus - startme) : -1;
		const int memIndexMinus = ((memask[ivmMinus]) && (ivmPlus != ivmMinus)) ? static_cast<int>(ivmMinus - startme) : -1;

		if (memIndexPlus != -1) {
			meMemories[memIndexPlus].write_mem(bx, bin, stubme);
		}
		if ((memIndexMinus != -1) && (memIndexPlus != memIndexMinus)) { // UUUUH WHY DOES IT THINK THERE'S A DEPENDENCYYYY
			meMemories[memIndexMinus].write_mem(bx, bin, stubme);
		}
	}
		//executeME() END   ------------------------------



			// // executeTE() START ------------------------------
//
// 		// Total number of VMs for TE
// 		constexpr auto nvmte =
// 				LAYER != 0 ?
// 						nallstubslayers[LAYER - 1] * nvmtelayers[LAYER - 1] :
// 						nallstubsdisks[DISK - 1] * nvmtedisks[DISK - 1];
//
// 		auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi. TODO: we don't really need this...
// 		static const ap_ufixed<5,4> d1 = nvmte / 32.; // Precision of 0.5, should be enough
// 		int ivm = iphiRaw * d1; // Which VM
//
// 		// TE Inner
// 		if (teimask != 0) {
//
// 			VMStubTEInner<INTYPE> stubTeInner;
//
// 			stubTeInner.setBend(bend);
// 			stubTeInner.setIndex(typename VMStubTEInner<OUTTYPE>::VMSTEIID(i));
//
// 			constexpr auto vmbits = (LAYER) ? vmbitsLayer[LAYER-1] : vmbitsDisk[DISK-1]; // Number of bits for VMs
// 			constexpr auto finephibits = (LAYER) ? nfinephibarrelinner : nfinephidiskinner; // Number of bits for finephi
//
// 			// The z/r information bits saved for TE Inner memories.
// 			// Which VMs to look at in the outer layer.
// 			// Note: not z/r coordinate for the inner stub
// 			// TODO: rename to e.g. rzTEbits
// 			int binlookup;
//
// 			// LAYER
// 			if (LAYER != 0) {
//
// 				constexpr auto zbins = (1 << 7); // 7 = zbits
// 				constexpr auto rbins = (1 << 4); // Number of bins in r
// 				ap_uint<7> zbin = (z + (1 << (nzbits - 1))) >> (nzbits - 7); // Make z positive and take the 7 MSBs TODO replace 7
// 				ap_uint<4> rbin = (r + (1 << (nrbits - 1))) >> (nrbits - 4);
//
// 				int index = zbin * rbins + rbin; // number of bins
//
// 				binlookup = binlookuptable[index];
//
// 				stubTeInner.setZBits(binlookup);
// 				stubTeInner.setFinePhi(
// 						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));
//
// 			} else { // DISKS
// 				assert(DISK != 0);
//
// 				stubTeInner.setZBits(r >> (nrbits - nrbits));
// 				stubTeInner.setFinePhi(
// 						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));
// 			}
//
// // For debugging
// #ifndef __SYNTHESIS__
// 			std::cout << "TEInner stub " << std::hex << stubTeInner.raw()
// 					<< std::endl;
// 			std::cout << "ivm: " << std::dec << ivm <<std::endl
// 					<< std::endl;
// #endif // DEBUG
//
//
//
// 			// Write the TE Inner stub to the correct memory
// 			// Only if it has a valid binlookup value, less than 1008 (table uses 1048575 as "-1"),
// 			// and a valid bend
// 			// TODO: implement VMR to write to the n memory copies, which are different depending on the bendcuts
// 			// TODO: doesn't it make more sense if < 1024?
// 			if (binlookup <= 1008 && teimask[ivm]) {
// 				if (teimask[ivm]) {
// 						for (int n = 0; n < 5; n++) {
// 							#pragma HLS UNROLL
// 							bool passbend = bendtable[ivm-firstmem][bend];
// 							if (passbend) {
// 							teiMemories[n][ivm-firstmem].write_mem(bx, stubTeInner, addrCountTEI[n][ivm-firstmem]);
// 							addrCountTEI[n][ivm-firstmem] += 1;
// 						}
// 					}
// 					}
// 				}
// 		} // END TE INNER
//
// 		//  OVERLAP
// 		if (olmask != 0) {
//
// 			assert(LAYER == 1 || LAYER == 2); // Make sure that only layer 1 and 2 are overlapped
//
// 			constexpr auto zbins = (1 << 7); // 7 = zbits
// 			constexpr auto rbins = (1 << 3); // Number of bins in r
// 			ap_uint<7> zbin = (z + (1 << (nzbits - 1))) >> (nzbits - 7); // Make z positive and take the 7 MSBs TODO replace 7
// 			ap_uint<3> rbin = (r + (1 << (nrbits - 1))) >> (nrbits - 3);
//
// 			int index = zbin * rbins + rbin; // number of bins
//
// 			int overlap = overlaptable[index];
//
// 			if (overlap != 1023) { // which is like "-1" if we had signed stuff?
// 				constexpr auto nvmol = nallstubslayers[LAYER-1] * 2; // Always 2 overlap vms?
//
// 				VMStubTEInner<BARRELOL> stubOL;
//
// 				// 16 overlap vms per layer
// 				auto iphiRaw = iphivmRaw<INTYPE>(stubPhi) >> 1; // Top 4 bits of phi
// 				static const ap_ufixed<4,3> d2 = nvmol / 16.; // Some normalisation thing
// 				int ivm = iphiRaw * d2; // Which VM, BECAUSE WE HAVE 16 VMS?
//
// 				bool passbend = bendtable[ivm-firstmem][bend]; // Check if stub passes bend cut TODO: we can skip the rest if false
//
// 				constexpr auto vmbits = (LAYER == 1) ? 4 :3; //vmbitsOverlap[LAYER-1];
// 				constexpr auto finephibits = 2; // or nfinephioverlapinner??? which is 2
//
// 				stubOL.setBend(bend);
// 				stubOL.setIndex(typename VMStubTEInner<BARRELOL>::VMSTEIID(i));
// 				stubOL.setZBits(overlap);
// 				stubOL.setFinePhi(
// 						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits)); // is this the right vmbits
//
// 				if (passbend) {
// // For debugging
// #ifndef __SYNTHESIS__
// 				std::cout << "Overlap stub " << overlap << " " << std::hex
// 						<< stubOL.raw() << std::endl;
// 				std::cout << "ivm: " << std::dec << ivm << std::endl
// 						<< std::endl;
// #endif // DEBUG
//
// 				// Save stub to memories
// 				// Note: the n copies seem to be the same
// 				if (olmask[ivm]) {
// 					for (int n = 0; n < 3; n++) {
// 						#pragma HLS UNROLL
// 						olMemories[n][ivm].write_mem(bx, stubOL, addrCountOL[ivm]);
// 					}
// 					addrCountOL[ivm] += 1;
// 				}
// 			}
// 			} else {
// 				#ifndef __SYNTHESIS__
// 				std::cout << "NO OVERLAP" << std::endl << std::endl;
// 				#endif // DEBUG
// 			}
// 		}
//
// 		// TE Outer
// 		if (teomask != 0) {
// 			VMStubTEOuter<INTYPE> stubTeOuter;
//
// 			stubTeOuter.setBend(bend);
// 			stubTeOuter.setIndex(typename VMStubTEOuter<OUTTYPE>::VMSTEOID(i));
//
// 			ap_uint<TEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM
// 			auto ivm = iphivmRaw<INTYPE>(stubPhi);
//
// 			constexpr auto vmbits = (LAYER) ? vmbitsLayer[LAYER-1] : vmbitsDisk[DISK-1]; // Number of bits for VMs
// 			constexpr auto finephibits = (LAYER) ? nfinephibarrelouter : nfinephidiskouter; // Number of bits for finephi
//
// 			// LAYER
// 			if (LAYER != 0) {
//
// 				stubTeOuter.setFinePhi(
// 						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits)); // is this the right vmbits
//
// 				// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
// 				//bin = (z >> (nzbits - TEBinsBits))
// 				//		+ (1 << (TEBinsBits - 1)); // Coarse z value
// 				constexpr auto zbins = (1 << 7); // 7 = zbits
// 				constexpr auto rbins = (1 << 4); // Number of bins in r
// 				ap_uint<7> zbin = (z + (1 << (nzbits - 1))) >> (nzbits - 7); // Make z positive and take the 7 MSBs TODO replace 7
// 				ap_uint<4> rbin = (r + (1 << (nrbits - 1))) >> (nrbits - 4);
//
// 				int indexo = zbin * rbins + rbin; // number of bins
//
// 				bin = binlookuptable[indexo]/8; // is >> 3 faster?
//
// 				// Index of where to find the zfine value in finebintable
// 				// The top 7 MSBs of z, ignoring the sign.
// 				// Note: not the index that is being saved to the stub
// 				typename VMStubTEOuter<OUTTYPE>::VMSTEOID index = (z
// 						>> (nzbits - nbitsfinebintable))
// 						& ((1 << nbitsfinebintable) - 1);
//
// 				// Set zfine: the z position within a bin
// 				typename VMStubTEOuter<OUTTYPE>::VMSTEOFINEZ zfine =
// 						finebintable[index];
// 				stubTeOuter.setFineZ(zfine);
// 			} else { // DISKS
// 				assert(DISK != 0);
//
// 				stubTeOuter.setFinePhi(
// 						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));
//
// 				// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
// 				bin = (r >> (nrbits - TEBinsBits))
// 						+ (1 << (TEBinsBits - 1)); // Coarse r value
//
// 				// Index of where to find the rfine value in finebintable
// 				// The top 7 MSBs of r, ignoring the sign.
// 				// Note: not the index that is being saved to the stub
// 				typename VMStubTEOuter<OUTTYPE>::VMSTEOID index = (r
// 						>> (nrbits - nbitsfinebintable))
// 						& ((1 << nbitsfinebintable) - 1);
//
// 				// set rfine: the r position within a bin
// 				typename VMStubTEOuter<OUTTYPE>::VMSTEOFINEZ rfine =
// 						finebintable[index]; // is it the same table as for z?
// 				assert(rfine >= 0);
// 				stubTeOuter.setFineZ(rfine);
// 			}
//
// // For debugging
// #ifndef __SYNTHESIS__
// 			std::cout << "TEOuter stub " << std::hex << stubTeOuter.raw()
// 					<< std::endl;
// 			std::cout << "ivm: " << std::dec << ivm << std::endl
// 					<< std::endl;
// #endif // DEBUG
//
// 			bool passbend = bendtable[ivm-firstmem][bend]; // Check if stub passes bend cut
//
// 			// Write the TE Outer stub to the correct memory
// 			// Only if it has a valid bend
// 			// TODO: implement VMR to write to the n memory copies, which are different depending on the bendcuts
//
// 			if (passbend) {
// 			// 0-9
// 			if (teomask[ivm]) {
// 				teoMemories[ivm].write_mem(bx, bin, stubTeOuter);
// 			}
// 		} else {
// 			#ifndef __SYNTHESIS__
// 			std::cout << "DIDN'T PASS BEND" << std::endl;
// 			#endif // DEBUG
// 		}
// 		}
//
// 		// // executeTE() END   ------------------------------

 } // TOP LEVEL loop

} // VMRouter

#endif //VMROUTER_HH
