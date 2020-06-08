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
#include <cassert>

// from Constants.hh -- needs a final home?
constexpr unsigned int nallstubslayers[6] = { 8, 4, 4, 4, 4, 4 }; // Number of AllStub memories, coarse phi regions, per sector
constexpr unsigned int nallstubsdisks[5] = { 4, 4, 4, 4, 4 };

constexpr unsigned int nvmmelayers[6] = { 4, 8, 8, 8, 8, 8 }; // Number of ME VM modules per coarse phi region
constexpr unsigned int nvmmedisks[5] = { 8, 4, 4, 4, 4 };

constexpr unsigned int nvmtelayers[6] = { 4, 8, 4, 8, 4, 8 }; // Number of TE VM modules per coarse phi region
constexpr unsigned int nvmtedisks[5] = { 4, 4, 4, 4, 4 };

constexpr unsigned int nvmteoverlaplayers[2] = {2, 2}; // Number of Overlap VM modules per coarse phi region

// Number of finephi bits used. Can't this be taken from the memories?
static const int nfinephibarrelinner = 2;
static const int nfinephibarrelouter = 3;

static const int nfinephidiskinner = 2;
static const int nfinephidiskouter = 3;

static const int nfinephioverlapinner = 2;
static const int nfinephioverlapouter = 3;

// Maximum number of stubs that can be processed (memory depth)
constexpr int MAXVMROUTER = kMaxProc;

// Number of bits used for the VMs for different layers and disks
// E.g. 32 VMs would use 5 vmbits
constexpr int vmbitslayer[6] = { 5, 5, 4, 5, 4, 5 }; // Could be computed using the number of VMs...
constexpr int vmbitsdisk[5] = { 4, 4, 4, 4, 4 };
constexpr int vmbitsoverlap[2] = { 4, 3 };

// Number of bits used for z and r in finebin LUTs
constexpr int nbitszfinebintablelayer = 7;
constexpr int nbitsrfinebintablelayer = 4;

constexpr int nbitszfinebintabledisk = 3;
constexpr int nbitsrfinebintabledisk = 7;

// Number of bits used for z and r in rzbits LUTs
constexpr int nzbitsinnertablelayer = 7;
constexpr int nrbitsinnertablelayer = 4;

constexpr int nzbitsinnertabledisk = 3;
constexpr int nrbitsinnertabledisk = 8;

constexpr int nzbitsoutertablelayer = 7;
constexpr int nrbitsoutertablelayer = 4;

constexpr int nzbitsoutertabledisk = 3;
constexpr int nrbitsoutertabledisk = 7;

constexpr int nzbitsoverlaptable = 7;
constexpr int nrbitsoverlaptable = 3;

// Number of bits used for r in phicorr LUTs
constexpr int nrbitsphiphicorrtable = 3;

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

	auto v1 = (phi.range(phi.length() - 1 - vmbits,
			phi.length() - vmbits - finebits));
//auto v2 = (phi >> (phi.length() - vmbits - finebits)) & ((1 << finebits) - 1);
//std::cout << "PHI: " << phi << "   v1: " << v1 << "    v2: " << v2 << std::endl;
//assert(v1 == v2);
	return v1;
}

// Returns a number from 0 to 31. for both the plus and the minus:
// we add a small amount to the raw value; if it's not the same
// as the central value we copy the data to the adjacent memory as well.
template<regionType INTYPE>
inline ap_uint<7> iphivmRawPlus(const typename AllStub<INTYPE>::ASPHI phi) {
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

// Get the corred_ted phi, i.e. phi at the nominal radius of the barrel
// Corred_ted phi is used by ME and TE memories for simplicity
template<regionType INTYPE>
inline typename AllStub<INTYPE>::ASPHI getPhiCorr(
		const typename AllStub<INTYPE>::ASPHI phi,
		const typename AllStub<INTYPE>::ASR r,
		const typename AllStub<INTYPE>::ASBEND bend, const int phicorrtable[]) {

	if (INTYPE == DISKPS || INTYPE == DISK2S)
		return phi; // Do nothing if disks

	constexpr auto rbins = 1 << nrbitsphiphicorrtable; // The number of bins for r. Found hardcoded in VMRouterPhiphicorrtable.h

	ap_uint<nrbitsphiphicorrtable> rbin = (r + (1 << (r.length() - 1)))
			>> (r.length() - nrbitsphiphicorrtable); // Which bin r belongs to. Note r = 0 is mid radius
	auto index = bend * rbins + rbin; // index for where we find our correction value
	auto corrval = phicorrtable[index]; // the amount we need to correct our phi

	typename AllStub<INTYPE>::ASPHI phicorr = phi - corrval; // the corred_ted phi

	if (phicorr < 0)
		phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length())
		phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}

// Get the number of the first ME/TE memory for the current VMRouter
// I.e. the position of the first non-zero bit in the mask
//template<int nbits>
inline ap_uint<5> memStartVal(const ap_uint<32> mask) {
	ap_uint<5> i = 0;
	ap_uint<1> x = mask[i]; // Value of the i:th bit

// Stop counter when we have reached the first non-zero bit
	while (x == 0 && i < 31) {
		i++;
		x = mask[i];
	}

	return i;
}

/////////////////////////////////
// Main function

// Two input region types INTYPE and INTYPE2 due to the disks having both 2S and PS inputs.
// According to wiring script for disks, the 0th and 2th input are always different
template<regionType INTYPE, regionType INTYPE2, regionType OUTTYPE, int LAYER, int DISK, int MAXNALL, int MAXNTEI, int MAXNTEOL, int MAXNTEO>
void VMRouter(const BXType bx, const int finebintable[], const int phicorrtable[], const int rzbitstable[], 
		const ap_uint<1>* bendtable[], const ap_uint<1>* bendextratable[], const int overlaptable[],
		// Input memories
		const ap_uint<6>& imask, 
		const InputStubMemory<INTYPE2>* const i0,
		const InputStubMemory<INTYPE>* const i1,
		const InputStubMemory<INTYPE>* const i2,
		const InputStubMemory<INTYPE2>* const i3,
		const InputStubMemory<INTYPE>* const i4,
		const InputStubMemory<INTYPE>* const i5,
		// AllStub memory
		AllStubMemory<OUTTYPE> allstub[],
		// ME memories
		const ap_uint<32>& memask, VMStubMEMemory<OUTTYPE> meMemories[],
		// // Inner TE memories, non-overlap
		const ap_uint<32>& teimask, VMStubTEInnerMemory<OUTTYPE> teiMemories[][MAXNTEI],
		// // TE Inner memories, overlap
		const ap_uint<16>& olmask, VMStubTEInnerMemory<BARRELOL> olMemories[][MAXNTEOL],
		// // TE Outer memories
		const ap_uint<32>& teomask, VMStubTEOuterMemory<OUTTYPE> teoMemories[][MAXNTEO]) {

#pragma HLS inline
#pragma HLS array_partition variable=bendtable complete dim=1
#pragma HLS array_partition variable=bendextratable complete dim=1
#pragma HLS array_partition variable = allstub complete
#pragma HLS array_partition variable = meMemories complete
#pragma HLS array_partition variable = teiMemories complete dim=2
#pragma HLS array_partition variable = olMemories complete dim=2
#pragma HLS array_partition variable = teoMemories complete 

// Some variables
constexpr int nbitszfinebintable =
		(LAYER) ? nbitszfinebintablelayer : nbitszfinebintabledisk; // Number of bits used for z in finebintable
constexpr int nbitsrfinebintable =
		(LAYER) ? nbitsrfinebintablelayer : nbitsrfinebintabledisk; // Number of bits used for r in finebintable
		
static const int firstme = memStartVal(memask); // The number of the first ME memory
static const int firstte = (teimask) ? memStartVal(teimask) : memStartVal(teomask); // The number of the first TE memory
static const int firstol = (olmask) ? static_cast<int>(memStartVal(olmask)) : 0; // The number pf the first OL memory. TODO: remove hardcoded value

constexpr int n_me = (LAYER) ? nvmmelayers[LAYER-1] : nvmmedisks[DISK-1]; // Number of ME memories/VM for this coarse phi region
constexpr int n_te = (LAYER) ? nvmtelayers[LAYER-1] : nvmtedisks[DISK-1]; // Number of TE memories for this coarse phi region
constexpr int n_ol = ((LAYER == 1) || (LAYER == 2)) ? nvmteoverlaplayers[LAYER-1] : 0; // Number of TE Overlap memories for this coarse phi region

// Total number of VMs for ME in a whole sector
constexpr auto ntotvmme =
		LAYER != 0 ?
				nallstubslayers[LAYER - 1]
						* nvmmelayers[LAYER - 1] :
				nallstubsdisks[DISK - 1] * nvmmedisks[DISK - 1];
// Total number of VMs for TE in a whole sector
constexpr auto ntotvmte =
		LAYER != 0 ?
				nallstubslayers[LAYER - 1] * nvmtelayers[LAYER - 1] :
				nallstubsdisks[DISK - 1] * nvmtedisks[DISK - 1];

//constexpr int nallcopies = 6; // Number of AllStub memory copies. TODO: Remove hardcoded value
//constexpr int ntecopies = 3; // Number of TE Inner memory copies. TODO: Remove hardcoded value
//constexpr int nolcopies = 5; // Number of copies for the extra overlap memories. TODO: Remove hardcoded value

const ap_ufixed<5, 4> d_me = ntotvmme / 32.0; // Some sort of normalisation thing
const ap_ufixed<5, 4> d_te = ntotvmte / 32.0;

	// Reset address counters in output memories
	// Only clear if the masks says that memory is used
ALLSTUB_CLEAR:	for (int i = 0; i < MAXNALL; i++) {
		#pragma HLS UNROLL
		allstub[i].clear(bx);
	}

if (memask) {
ME_CLEAR:	for (int i = 0; i < n_me; i++) {
		#pragma HLS UNROLL
		if (memask[i + firstme]) meMemories[i].clear(bx);
	}
}

if (teimask) {
TEI_CLEAR:	for (int i = 0; i < n_te; i++) {
		#pragma HLS UNROLL
		if (teimask[i + firstte]) {
			for (int j = 0; j < MAXNTEI; j++) {
				#pragma HLS UNROLL
				teiMemories[i][j].clear(bx);
			}
		}
	}
}

	if (teomask) {
	TEO_CLEAR:	for (int i = 0; i < n_te; i++) {
		#pragma HLS UNROLL
		if (teomask[i + firstte]) {
			for (int j = 0; j < MAXNTEO; j++) {
				#pragma HLS UNROLL
				teoMemories[i][j].clear(bx);
			}
		}
	}
}

	if (olmask) {
	OL_CLEAR:	for (int i = 0; i < n_ol; i++) {
			#pragma HLS UNROLL
			if (olmask[i + firstol]) {
				for (int j = 0; j < MAXNTEOL; j++) {
					#pragma HLS UNROLL
					olMemories[i][j].clear(bx);
			}
			}
		}
	}
	
	// Maximum depth of bendtable is 8?
	#pragma HLS interface ap_bus port=bendtable depth=20
	#pragma HLS interface ap_bus port=bendtable depth=6
	
	// Number of data in each input memory
	const typename InputStubMemory<INTYPE>::NEntryT zero(0);

	auto n_i0 = imask[0] != 0 ? i0->getEntries(bx) : zero;
	auto n_i1 = imask[1] != 0 ? i1->getEntries(bx) : zero;
	auto n_i2 = imask[2] != 0 ? i2->getEntries(bx) : zero;
	auto n_i3 = imask[3] != 0 ? i3->getEntries(bx) : zero;
	auto n_i4 = imask[4] != 0 ? i4->getEntries(bx) : zero;
	auto n_i5 = imask[5] != 0 ? i5->getEntries(bx) : zero;

	//const int n_tot = n_i0 + n_i1 + n_i2 + n_i3 + n_i4 + n_i5;
	//const int maxLoop = (kMaxProc < n_tot) ? kMaxProc : n_tot;
	
// Create variables that keep track of which memory address to read and write to
	ap_uint<kNBits_MemAddr> read_addr(0); // Reading of input stubs
	
	static int addrCountTEI[n_te][MAXNTEI]; // Writing of TE Inner stubs
		if (teimask) {
	#pragma HLS array_partition variable = addrCountTEI complete dim=0
	ADDR_TEI:	for (int i = 0; i < n_te; i++) {
			#pragma HLS UNROLL
			for (int j = 0; j < MAXNTEI; j++) {
				#pragma HLS UNROLL
					addrCountTEI[i][j] = 0;
			}
		}
}

	static int addrCountOL[n_ol][MAXNTEOL]; // Writing of TE Overlap stubs
		if (olmask) {
	#pragma HLS array_partition variable=addrCountOL complete dim=0
	ADDR_OL:	for (int i = 0; i < n_ol; i++) {
			#pragma HLS UNROLL
			for (int j = 0; j < MAXNTEOL; j++) {
				#pragma HLS UNROLL
				addrCountOL[i][j] = 0;
			}
		}
}
 
//#pragma HLS resource variable=addrCountTEI latency=2
//#pragma HLS resource variable=addrCountOL latency=2

/////////////////////////////////////
// Main Loop 

	TOPLEVEL: for (auto i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1

// max=4 yields latency of 5...
#pragma HLS latency max=5
		const bool haveData = (n_i0 > 0) || (n_i1 > 0) || (n_i2 > 0)
				|| (n_i3 > 0) || (n_i4 > 0) || (n_i5 > 0);

// Stop processing stubs if we have looped over the maximum number
// that can be processed or if we have gone through all data
		if ((i > MAXVMROUTER) || !haveData) //n_tot
			continue;

		bool resetNext = false; // Used to reset read_addr
		bool isSpecialStub = false; // Used to determine if first or fourth input memory, which are different for disks
		bool disk2S = false; // Used to determine if DISK2S
		bool negdisk = false; // Used to determine if it's negative disk, the last 3 inputs memories
		InputStub<INTYPE> stub;
		InputStub<INTYPE2> stubspec; // Used for input 1 and 4 since they can be of different type in disks. find a better way to do this...
		
// Read stub from memory in turn
		if (n_i0) {
			stubspec = i0->read_mem(bx, read_addr);
			isSpecialStub = true;
			--n_i0;
			if (n_i0 == 0)
				resetNext = true;
		} else if (n_i1) {
			stub = i1->read_mem(bx, read_addr);
			--n_i1;
			if (n_i1 == 0)
				resetNext = true;
		} else if (n_i2) {
			stub = i2->read_mem(bx, read_addr);
			--n_i2;
			if (n_i2 == 0)
				resetNext = true;
		} else if (n_i3) {
			stubspec = i3->read_mem(bx, read_addr);
			isSpecialStub = true;
			negdisk = (DISK) ? true : false;
			--n_i3;
			if (n_i3 == 0)
				resetNext = true;
		} else if (n_i4) {
			stub = i4->read_mem(bx, read_addr);
			negdisk = (DISK) ? true : false;
			--n_i4;
			if (n_i4 == 0)
				resetNext = true;
		} else {
			stub = i5->read_mem(bx, read_addr);
			negdisk = (DISK) ? true : false;
			--n_i5;
			if (n_i5 == 0)
				resetNext = true;
		}


// If the stub is from a DISK2S module
		if (isSpecialStub && DISK) {
			disk2S = true;
		}

// Increment the read address, or reset it to zero when all stubs in a memory has been read
		if (resetNext)
			read_addr = 0;
		else
			++read_addr;


		// Add stub to all AllStub memory copies
		AllStub<OUTTYPE> allstubd =
				(isSpecialStub) ? stubspec.raw() : stub.raw();
		for (int n = 0; n < MAXNALL; n++) {
			#pragma HLS UNROLL
			allstub[n].write_mem(bx, allstubd, i);
		}
		// For debugging
		#ifndef __SYNTHESIS__
				std::cout << "Out put stub: " << std::hex << allstubd.raw() << std::dec
						<< std::endl;
		#endif // DEBUG





// Variables that are going to be used by ME and TE memories
		auto z = (isSpecialStub) ? stubspec.getZ() : stub.getZ();
		int r = (isSpecialStub) ? stubspec.getR().range() : stub.getR().range();
		int bend =
				(isSpecialStub) ?
						stubspec.getBend().range() : stub.getBend().range();
		auto stubPhi_uncorr =
				(isSpecialStub) ? stubspec.getPhi() : stub.getPhi(); // Original phi, uncorred_ted.
		auto stubPhi = getPhiCorr<INTYPE>(stubPhi_uncorr, r, bend, phicorrtable); // Corred_ted phi, i.e. phi at nominal radius (what about disks?)

		int nrbits =
				(isSpecialStub) ?
						stubspec.getR().length() : stub.getR().length(); // Number of bits for r
		int nzbits =
				(isSpecialStub) ?
						stubspec.getZ().length() : stub.getZ().length(); // Number of bits for z
		int nbendbits =
				(isSpecialStub) ?
						stubspec.getBend().length() : stub.getBend().length();

/////////////////////////////////////////////
// executeME() START ------------------------------
// hourglass only

		if (memask != 0) {

			VMStubME<OUTTYPE> stubme;
			stubme.setBend(bend);
			stubme.setIndex(typename VMStubME<OUTTYPE>::VMSMEID(i));

			auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
			auto iphiRawPlus = iphivmRawPlus<INTYPE>(stubPhi); // Top 5 bits of phi after adding a small number
			auto iphiRawMinus = iphivmRawMinus<INTYPE>(stubPhi); // Top 5 bits of phi after subtracting a small number

			int ivm = iphiRaw * d_me; // The VM number
			int ivmPlus = iphiRawPlus * d_me;
			int ivmMinus = iphiRawMinus * d_me;

// To avoid overflow
			if (ivmMinus > ivm)
				ivmMinus = 0;
			if (ivmPlus < ivm)
				ivmPlus = ntotvmme - 1;

// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
			assert(std::abs(ivm - ivmPlus) <= 1);
			assert(std::abs(ivm - ivmMinus) <= 1);

// Indices used to find the rzfine value in finebintable
// finebintable returns the top 6 bits of a corred_ted z
// Note: not the index that is being saved to the stub
			ap_uint<nbitszfinebintable + nbitsrfinebintable> indexz = ((z
					+ (1 << (nzbits - 1))) >> (nzbits - nbitszfinebintable)); // Make z unsigned and take the top "nbitszfinebintable" bits
			ap_uint<nbitsrfinebintable> indexr = 0;

			if (DISK) {
				if (negdisk) {
					indexz = (1 << nbitszfinebintable) - indexz;
				}
				if (disk2S) {
					indexr = r;
				} else {
// Take the top "nbitsrfinebintable" bits
					indexr = r >> (nrbits - nbitsrfinebintable);
				}
			} else { // LAYER
				indexr = ((r + (1 << (nrbits - 1)))
						>> (nrbits - nbitsrfinebintable)); // Make r unsigned and take the top "nbitsrfinebintable" bits
			}

// The index for finebintable
			ap_uint<nbitszfinebintable + nbitsrfinebintable> index = (indexz
					<< nbitsrfinebintable) + indexr;

// Get the corred_ted r/z position
			int rzfine = finebintable[index];

// Coarse z. The bin the stub is going to be put it in the memory
			ap_uint<MEBinsBits> bin = rzfine >> 3; // 3 bits, i.e. max 8 bins within each VM
			if (negdisk)
				bin += 8; // Only needed if 16 ME bins

// Set rzfine, i.e. the r/z bits within a coarse r/z region
			rzfine = rzfine & 7; // the 3 LSB as rzfine
			stubme.setFineZ(rzfine);

			assert(rzfine >= 0);

// For debugging
#ifndef __SYNTHESIS__
			std::cout << "ME stub " << std::hex << stubme.raw() << std::endl;
			std::cout << "ivm,Minus,Plus = " << std::dec << ivm << " "
					<< ivmMinus << " " << ivmPlus << " " << "\t0x"
					<< std::setfill('0') << std::setw(4) << std::hex
					<< stubme.raw().to_int() << std::dec << ", to bin " << bin
					<< std::endl;
			if (!memask[ivm]) {
				std::cerr << "Trying to write to non-existent memory for ivm = "
						<< ivm << std::endl;
			}
#endif // DEBUG


		// Write the ME stub to the correct memory.
		// If stub is close to a border (ivmPlus/ivmMinus != ivm)
		// write it to the adjacent memory as well
		// Note that at least one of ivmPlus/Minus == ivm
		#pragma HLS dependence variable=meMemories intra false
		for (int i = 0; i < 32; i++) {
			#pragma HLS UNROLL
			if (memask[i]) {
					if ((ivmMinus == i) || (ivmPlus == i))
						meMemories[i-firstme].write_mem(bx, bin, stubme);
				}
		}
	}
		//executeME() END   ------------------------------



//////////////////////////////////
// executeTE() START ------------------------------

		auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi.
		
		int ivm = iphiRaw * d_te; // Which VM
		
// TE Inner
		if ((teimask != 0) && (!disk2S)) {

			VMStubTEInner<OUTTYPE> stubTeInner;

			stubTeInner.setBend(bend);
			stubTeInner.setIndex(typename VMStubTEInner<OUTTYPE>::VMSTEIID(i));

			constexpr auto vmbits =
					(LAYER) ? vmbitslayer[LAYER - 1] : vmbitsdisk[DISK - 1]; // Number of bits for VMs
			constexpr auto finephibits =
					(LAYER) ? nfinephibarrelinner : nfinephidiskinner; // Number of bits for finephi

// The z/r information bits saved for TE Inner memories.
// Which VMs to look at in the outer layer.
// Note: not the z/r coordinate for the inner stub
// Called binlookup in emulation
			int rzbits;

// LAYER
			if (LAYER != 0) {

				constexpr auto zbins = (1 << nzbitsinnertablelayer); // Number of bins in z
				constexpr auto rbins = (1 << nrbitsinnertablelayer); // Number of bins in r
				ap_uint<nzbitsinnertablelayer> zbin = (z + (1 << (nzbits - 1)))
						>> (nzbits - nzbitsinnertablelayer); // Make z positive and take the 7 (nzbitsinnertablelayer) MSBs
				ap_uint<nrbitsinnertablelayer> rbin = (r + (1 << (nrbits - 1)))
						>> (nrbits - nrbitsinnertablelayer);

				int index = zbin * rbins + rbin; // Index for LUT

				rzbits = rzbitstable[index];

				stubTeInner.setZBits(rzbits);
				stubTeInner.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));

			} else { // DISKS
				assert(DISK != 0);

				constexpr int zbins = (1 << nzbitsinnertabledisk); // Number of bins in z
				constexpr int rbins = (1 << nrbitsinnertabledisk); // Number of bins in r
				ap_uint<nzbitsinnertabledisk> zbin = (z + (1 << (nzbits - 1)))
						>> (nzbits - nzbitsinnertabledisk); // Make z positive and take the 7 (nzbitsinnertablelayer) MSBs
				ap_uint<nrbitsinnertabledisk> rbin = r
						>> (nrbits - nrbitsinnertabledisk);

// Special case if negative disk
				if (negdisk)
					zbin = 7 - zbin;

				int index = rbin * zbins + zbin; // number of bins

				rzbits = rzbitstable[index];

				stubTeInner.setZBits(rzbits);
				stubTeInner.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));
			}
			// For debugging
			#ifndef __SYNTHESIS__
						std::cout << "TEInner stub " << std::hex << stubTeInner.raw()
								<< std::endl;
						std::cout << "ivm: " << std::dec << ivm <<std::endl
								<< std::endl;
			#endif // DEBUG



						// Write the TE Inner stub to the correct memory
						// Only if it has a valid rzbits/binlookup value, less than 1024 (table uses 1048575 as "-1"),
						// and a valid bend
						// TODO: remove hardcoded value
						if (rzbits <= 1024 && teimask[ivm]) {
							int memindex = ivm-firstte;
							int bendindex = memindex*MAXNTEI;
								for (int n = 0; n < MAXNTEI; n++) {
									#pragma HLS UNROLL
									//int tempindex = bendindex+n; 
									bool passbend = bendtable[bendindex][bend];
									if (passbend) {
										teiMemories[memindex][n].write_mem(bx, stubTeInner, addrCountTEI[memindex][n]);
										addrCountTEI[memindex][n] += 1;
									}
									bendindex++;
								}
							}
					} // END TE INNER



// OVERLAP
		if (olmask != 0) {

			assert(LAYER == 1 || LAYER == 2); // Make sure that only layer 1 and 2 are overlapped

			constexpr auto zbins = (1 << nzbitsoverlaptable); // Number of bins in z
			constexpr auto rbins = (1 << nrbitsoverlaptable); // Number of bins in r
			ap_uint<nzbitsoverlaptable> zbin = (z + (1 << (nzbits - 1)))
					>> (nzbits - nzbitsoverlaptable); // Make z positive and take the 7 MSBs
			ap_uint<nrbitsoverlaptable> rbin = (r + (1 << (nrbits - 1)))
					>> (nrbits - nrbitsoverlaptable);

			int index = zbin * rbins + rbin; // Index for overlaptable

			int overlap = overlaptable[index];

			if (overlap != 1023) { // which is like "-1" if we had signed stuff...

				constexpr auto nvmol =
						(LAYER) ? nallstubslayers[LAYER - 1] * 2 : 0; // Always 2 overlap vms?

				VMStubTEInner<BARRELOL> stubOL;

// 16 overlap vms per layer
				auto iphiRaw = iphivmRaw<INTYPE>(stubPhi) >> 1; // Top 4 bits of phi
				const ap_ufixed<4, 3> d2 = nvmol / 16.; // Some normalisation thing
				int ivm = iphiRaw * d2; // Which VM it belongs to

				constexpr auto vmbits = (LAYER) ? vmbitsoverlap[LAYER - 1] : 0;

				stubOL.setBend(bend);
				stubOL.setIndex(typename VMStubTEInner<BARRELOL>::VMSTEIID(i));
				stubOL.setZBits(overlap);
				stubOL.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits,
								nfinephioverlapinner));


// For debugging
#ifndef __SYNTHESIS__
				std::cout << "Overlap stub " << overlap << " " << std::hex
						<< stubOL.raw() << std::endl;
				std::cout << "ivm: " << std::dec << ivm << std::endl
						<< std::endl;
#endif // DEBUG

				// Save stub to memories
				// Note: the n copies seem to be the same
				if (olmask[ivm]) {
					int memindex = ivm - firstol; // The memory index in array and addrcount
					int bendindex = memindex*MAXNTEOL;
					for (int n = 0; n < MAXNTEOL; n++) {
						#pragma HLS UNROLL
						bool passbend = bendextratable[bendindex+n][bend];
						if (passbend) {
							olMemories[memindex][n].write_mem(bx, stubOL, addrCountOL[memindex][n]);
							addrCountOL[memindex][n] += 1;
						}
					}
				}
			} else {
				#ifndef __SYNTHESIS__
				std::cout << "NO OVERLAP" << std::endl << std::endl;
				#endif // DEBUG
			}
		}



// TE Outer
		if ((teomask != 0) && (!disk2S)) {
			VMStubTEOuter<OUTTYPE> stubTeOuter;

			stubTeOuter.setBend(bend);
			stubTeOuter.setIndex(typename VMStubTEOuter<OUTTYPE>::VMSTEOID(i));

			ap_uint<TEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

			constexpr auto vmbits =
					(LAYER) ? vmbitslayer[LAYER - 1] : vmbitsdisk[DISK - 1]; // Number of bits for VMs
			constexpr auto finephibits =
					(LAYER) ? nfinephibarrelouter : nfinephidiskouter; // Number of bits for finephi

// LAYER
			if (LAYER != 0) {

				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits)); // is this the right vmbits

				constexpr auto zbins = (1 << nzbitsoutertablelayer); // Number of bins in z
				constexpr auto rbins = (1 << nrbitsoutertablelayer); // Number of bins in r
				ap_uint<nzbitsoutertablelayer> zbin = (z + (1 << (nzbits - 1)))
						>> (nzbits - nzbitsoutertablelayer); // Make z positive and take the 7 MSBs
				ap_uint<nrbitsoutertablelayer> rbin = (r + (1 << (nrbits - 1)))
						>> (nrbits - nrbitsoutertablelayer);

// Find the VM bit information in rzbits LUT
// First 3 MSB is the binning in z, and the 3 LSB is the fine z within a bin
				auto index = zbin * rbins + rbin; // number of bins
				ap_uint<6> rzbits = rzbitstable[index];

				bin = rzbits >> 3; // Remove the 3 LSBs, i.e. the finebin bits

// Set fine z
				ap_uint<3> zfine = rzbits & 7;
				stubTeOuter.setFineZ(zfine);

			} else { // DISKS
				assert(DISK != 0);

				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));

				constexpr auto zbins = (1 << nzbitsoutertabledisk); // Number of bins in z
				constexpr auto rbins = (1 << nrbitsoutertabledisk); // Number of bins in r
				ap_uint<nzbitsoutertabledisk> zbin = (z + (1 << (nzbits - 1)))
						>> (nzbits - nzbitsoutertabledisk); // Make z positive and take the 7 MSBs
				ap_uint<nrbitsoutertabledisk> rbin = r
						>> (nrbits - nrbitsoutertabledisk);

// Special case if negative disk
				if (negdisk) {
					zbin = 7 - zbin;
				}

// Find the VM bit information in rzbits LUT
// First 2 MSB is the binning in r, and the 3 LSB is the fine r within a bin
				auto index = rbin * zbins + zbin; // Index for LUT
				ap_uint<5> rzbits =
						(DISK == 1) ? overlaptable[index] : rzbitstable[index];

				bin = rzbits >> 3; // Remove the 3 LSBs, i.e. the finebin bits

// Bin 4-7 is used for negative disks
				if (negdisk)
					bin += 4;

// Set fine r
				ap_uint<3> rfine = rzbits & 7;
				stubTeOuter.setFineZ(rfine);
			}

// For debugging
#ifndef __SYNTHESIS__
			std::cout << "TEOuter stub " << std::hex << stubTeOuter.raw()
					<< std::endl;
			std::cout << "ivm: " << std::dec << ivm << "       to bin " << bin << std::endl
					<< std::endl;
#endif // DEBUG

			// Write the TE Outer stub to the correct memory
			// Only if it has a valid bend
			// TODO: implement VMR to write to the n memory copies, which are different depending on the bendcuts
			if (teomask[ivm]) {
				int memindex = ivm-firstte;
				int bendindex = memindex*MAXNTEO;
					for (int n = 0; n < MAXNTEO; n++) {
						#pragma HLS UNROLL
						bool passbend =
								(DISK == 1) ?
										bendextratable[bendindex+n][bend] :
										bendtable[bendindex+n][bend]; // Check if stub passes bend cut
						if (passbend) {
							teoMemories[memindex][n].write_mem(bx, bin, stubTeOuter);
						}
					}
				}
		}

// executeTE() END   ------------------------------
 
	} // outside loop
	
} // VMRouter

#endif //VMROUTER_HH
