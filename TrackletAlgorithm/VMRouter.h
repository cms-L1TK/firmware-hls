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
constexpr unsigned int nvmmedisks[5] = { 8, 4, 4, 4, 4 };

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
constexpr int vmbitsOverlap = 4;

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

	constexpr int rbins = 1 << 3; // The number of bins for r. Found hardcoded in VMRouterPhiCorrTable.h

	int rbin=(r+(1<<(r.length()-1)))>>(r.length()-3); // Which bin r belongs to. Note r = 0 is mid radius
	int index = bend * rbins + rbin; // index for where we find our correction value
	int corrval = corrtable[index]; // the amount we need to correct our phi
	int phicorr = phi - corrval; // the corrected phi

	if (phicorr < 0) phicorr = 0; // can't be less than 0
	if (phicorr >= 1 << phi.length()) phicorr = (1 << phi.length()) - 1;  // can't be more than the max value

	return phicorr;
}


// Get the number of the first ME/TE memory for the current VMRouter
inline int memStartVal(const ap_uint<32> mask) {
	int i = 0;
	int x = mask[i]; // Value of the i:th bit

	// Stop counter when we have reached the first non-zero bit
	while (x == 0 && i < 31) {
		//#pragma HLS UNROLL
		i++;
		x = mask[i];
	}

	return i;
}

// Main function
template<regionType INTYPE, regionType INTYPE2, regionType OUTTYPE, int LAYER, int DISK, int bendtablesize>
void VMRouter(const BXType bx, const int finebintable[], const int corrtable[], const int binlookuptable[], const int bendtable[][bendtablesize], const int bendtable2[][bendtablesize],
		const int overlaptable[],
		// Input memories
		const ap_uint<6>& imask,
		const InputStubMemory<INTYPE2>* const i0,
		const InputStubMemory<INTYPE>* const i1,
		const InputStubMemory<INTYPE>* const i2,
		const InputStubMemory<INTYPE2>* const i3,
		const InputStubMemory<INTYPE>* const i4,
		const InputStubMemory<INTYPE>* const i5,
		// AllStub memory
		AllStubMemory<OUTTYPE>* allstub,
		// ME memories
		const ap_uint<32>& memask, VMStubMEMemory<OUTTYPE> *m0,
		VMStubMEMemory<OUTTYPE> *m1, VMStubMEMemory<OUTTYPE> *m2,
		VMStubMEMemory<OUTTYPE> *m3, VMStubMEMemory<OUTTYPE> *m4,
		VMStubMEMemory<OUTTYPE> *m5, VMStubMEMemory<OUTTYPE> *m6,
		VMStubMEMemory<OUTTYPE> *m7, VMStubMEMemory<OUTTYPE> *m8,
		VMStubMEMemory<OUTTYPE> *m9, VMStubMEMemory<OUTTYPE> *m10,
		VMStubMEMemory<OUTTYPE> *m11, VMStubMEMemory<OUTTYPE> *m12,
		VMStubMEMemory<OUTTYPE> *m13, VMStubMEMemory<OUTTYPE> *m14,
		VMStubMEMemory<OUTTYPE> *m15, VMStubMEMemory<OUTTYPE> *m16,
		VMStubMEMemory<OUTTYPE> *m17, VMStubMEMemory<OUTTYPE> *m18,
		VMStubMEMemory<OUTTYPE> *m19, VMStubMEMemory<OUTTYPE> *m20,
		VMStubMEMemory<OUTTYPE> *m21, VMStubMEMemory<OUTTYPE> *m22,
		VMStubMEMemory<OUTTYPE> *m23, VMStubMEMemory<OUTTYPE> *m24,
		VMStubMEMemory<OUTTYPE> *m25, VMStubMEMemory<OUTTYPE> *m26,
		VMStubMEMemory<OUTTYPE> *m27, VMStubMEMemory<OUTTYPE> *m28,
		VMStubMEMemory<OUTTYPE> *m29, VMStubMEMemory<OUTTYPE> *m30,
		VMStubMEMemory<OUTTYPE> *m31,
		// // Inner TE memories, non-overlap
		const ap_uint<32>& teimask, VMStubTEInnerMemory<OUTTYPE> *mtei0,
		VMStubTEInnerMemory<OUTTYPE> *mtei1, VMStubTEInnerMemory<OUTTYPE> *mtei2,
		VMStubTEInnerMemory<OUTTYPE> *mtei3, VMStubTEInnerMemory<OUTTYPE> *mtei4,
		VMStubTEInnerMemory<OUTTYPE> *mtei5, VMStubTEInnerMemory<OUTTYPE> *mtei6,
		VMStubTEInnerMemory<OUTTYPE> *mtei7, VMStubTEInnerMemory<OUTTYPE> *mtei8,
		VMStubTEInnerMemory<OUTTYPE> *mtei9, VMStubTEInnerMemory<OUTTYPE> *mtei10,
		VMStubTEInnerMemory<OUTTYPE> *mtei11,
		VMStubTEInnerMemory<OUTTYPE> *mtei12,
		VMStubTEInnerMemory<OUTTYPE> *mtei13,
		VMStubTEInnerMemory<OUTTYPE> *mtei14,
		VMStubTEInnerMemory<OUTTYPE> *mtei15,
		VMStubTEInnerMemory<OUTTYPE> *mtei16,
		VMStubTEInnerMemory<OUTTYPE> *mtei17,
		VMStubTEInnerMemory<OUTTYPE> *mtei18,
		VMStubTEInnerMemory<OUTTYPE> *mtei19,
		VMStubTEInnerMemory<OUTTYPE> *mtei20,
		VMStubTEInnerMemory<OUTTYPE> *mtei21,
		VMStubTEInnerMemory<OUTTYPE> *mtei22,
		VMStubTEInnerMemory<OUTTYPE> *mtei23,
		VMStubTEInnerMemory<OUTTYPE> *mtei24,
		VMStubTEInnerMemory<OUTTYPE> *mtei25,
		VMStubTEInnerMemory<OUTTYPE> *mtei26,
		VMStubTEInnerMemory<OUTTYPE> *mtei27,
		VMStubTEInnerMemory<OUTTYPE> *mtei28,
		VMStubTEInnerMemory<OUTTYPE> *mtei29,
		VMStubTEInnerMemory<OUTTYPE> *mtei30,
		VMStubTEInnerMemory<OUTTYPE> *mtei31,
		// // TE Inner memories, overlap
		const ap_uint<16>& olmask, VMStubTEInnerMemory<BARRELOL> *mteol0,
		VMStubTEInnerMemory<BARRELOL> *mteol1,
		VMStubTEInnerMemory<BARRELOL> *mteol2,
		VMStubTEInnerMemory<BARRELOL> *mteol3,
		VMStubTEInnerMemory<BARRELOL> *mteol4,
		VMStubTEInnerMemory<BARRELOL> *mteol5,
		VMStubTEInnerMemory<BARRELOL> *mteol6,
		VMStubTEInnerMemory<BARRELOL> *mteol7,
		VMStubTEInnerMemory<BARRELOL> *mteol8,
		VMStubTEInnerMemory<BARRELOL> *mteol9,
		VMStubTEInnerMemory<BARRELOL> *mteol10,
		VMStubTEInnerMemory<BARRELOL> *mteol11,
		VMStubTEInnerMemory<BARRELOL> *mteol12,
		VMStubTEInnerMemory<BARRELOL> *mteol13,
		VMStubTEInnerMemory<BARRELOL> *mteol14,
		VMStubTEInnerMemory<BARRELOL> *mteol15,
		// // TE Outer memories
		const ap_uint<32>& teomask, VMStubTEOuterMemory<OUTTYPE> *mteo0,
		VMStubTEOuterMemory<OUTTYPE> *mteo1, VMStubTEOuterMemory<OUTTYPE> *mteo2,
		VMStubTEOuterMemory<OUTTYPE> *mteo3, VMStubTEOuterMemory<OUTTYPE> *mteo4,
		VMStubTEOuterMemory<OUTTYPE> *mteo5, VMStubTEOuterMemory<OUTTYPE> *mteo6,
		VMStubTEOuterMemory<OUTTYPE> *mteo7, VMStubTEOuterMemory<OUTTYPE> *mteo8,
		VMStubTEOuterMemory<OUTTYPE> *mteo9, VMStubTEOuterMemory<OUTTYPE> *mteo10,
		VMStubTEOuterMemory<OUTTYPE> *mteo11,
		VMStubTEOuterMemory<OUTTYPE> *mteo12,
		VMStubTEOuterMemory<OUTTYPE> *mteo13,
		VMStubTEOuterMemory<OUTTYPE> *mteo14,
		VMStubTEOuterMemory<OUTTYPE> *mteo15,
		VMStubTEOuterMemory<OUTTYPE> *mteo16,
		VMStubTEOuterMemory<OUTTYPE> *mteo17,
		VMStubTEOuterMemory<OUTTYPE> *mteo18,
		VMStubTEOuterMemory<OUTTYPE> *mteo19,
		VMStubTEOuterMemory<OUTTYPE> *mteo20,
		VMStubTEOuterMemory<OUTTYPE> *mteo21,
		VMStubTEOuterMemory<OUTTYPE> *mteo22,
		VMStubTEOuterMemory<OUTTYPE> *mteo23,
		VMStubTEOuterMemory<OUTTYPE> *mteo24,
		VMStubTEOuterMemory<OUTTYPE> *mteo25,
		VMStubTEOuterMemory<OUTTYPE> *mteo26,
		VMStubTEOuterMemory<OUTTYPE> *mteo27,
		VMStubTEOuterMemory<OUTTYPE> *mteo28,
		VMStubTEOuterMemory<OUTTYPE> *mteo29,
		VMStubTEOuterMemory<OUTTYPE> *mteo30,
		VMStubTEOuterMemory<OUTTYPE> *mteo31) {

	#pragma HLS inline
		static int nbitsfinebintable = 8; // this appears to always be 8. Total number of bits the finebintable consists of

//#pragma HLS array_partition variable=finebintable
//#pragma HLS array_partition variable=bendtable
//#pragma HLS array_partition variable=binlookuptable //max 1024 partitions
//#pragma HLS array_partition variable=overlaptable

	// Reset address counters in output memories
	allstub->clear(bx);

	if (memask[0])
		m0->clear(bx);
	if (memask[1])
		m1->clear(bx);
	if (memask[2])
		m2->clear(bx);
	if (memask[3])
		m3->clear(bx);
	if (memask[4])
		m4->clear(bx);
	if (memask[5])
		m5->clear(bx);
	if (memask[6])
		m6->clear(bx);
	if (memask[7])
		m7->clear(bx);
	if (memask[8])
		m8->clear(bx);
	if (memask[9])
		m9->clear(bx);
	if (memask[10])
		m10->clear(bx);
	if (memask[11])
		m11->clear(bx);
	if (memask[12])
		m12->clear(bx);
	if (memask[13])
		m13->clear(bx);
	if (memask[14])
		m14->clear(bx);
	if (memask[15])
		m15->clear(bx);
	if (memask[16])
		m16->clear(bx);
	if (memask[17])
		m17->clear(bx);
	if (memask[18])
		m18->clear(bx);
	if (memask[19])
		m19->clear(bx);
	if (memask[20])
		m20->clear(bx);
	if (memask[21])
		m21->clear(bx);
	if (memask[22])
		m22->clear(bx);
	if (memask[23])
		m23->clear(bx);
	if (memask[24])
		m24->clear(bx);
	if (memask[25])
		m25->clear(bx);
	if (memask[26])
		m26->clear(bx);
	if (memask[27])
		m27->clear(bx);
	if (memask[28])
		m28->clear(bx);
	if (memask[29])
		m29->clear(bx);
	if (memask[30])
		m30->clear(bx);
	if (memask[31])
		m31->clear(bx);


	if (teimask[0])
		mtei0->clear(bx);
	if (teimask[1])
		mtei1->clear(bx);
	if (teimask[2])
		mtei2->clear(bx);
	if (teimask[3])
		mtei3->clear(bx);
	if (teimask[4])
		mtei4->clear(bx);
	if (teimask[5])
		mtei5->clear(bx);
	if (teimask[6])
		mtei6->clear(bx);
	if (teimask[7])
		mtei7->clear(bx);
	if (teimask[8])
		mtei8->clear(bx);
	if (teimask[9])
		mtei9->clear(bx);
	if (teimask[10])
		mtei10->clear(bx);
	if (teimask[11])
		mtei11->clear(bx);
	if (teimask[12])
		mtei12->clear(bx);
	if (teimask[13])
		mtei13->clear(bx);
	if (teimask[14])
		mtei14->clear(bx);
	if (teimask[15])
		mtei15->clear(bx);
	if (teimask[16])
		mtei16->clear(bx);
	if (teimask[17])
		mtei17->clear(bx);
	if (teimask[18])
		mtei18->clear(bx);
	if (teimask[19])
		mtei19->clear(bx);
	if (teimask[20])
		mtei20->clear(bx);
	if (teimask[21])
		mtei21->clear(bx);
	if (teimask[22])
		mtei22->clear(bx);
	if (teimask[23])
		mtei23->clear(bx);
	if (teimask[24])
		mtei24->clear(bx);
	if (teimask[25])
		mtei25->clear(bx);
	if (teimask[26])
		mtei26->clear(bx);
	if (teimask[27])
		mtei27->clear(bx);
	if (teimask[28])
		mtei28->clear(bx);
	if (teimask[29])
		mtei29->clear(bx);
	if (teimask[30])
		mtei30->clear(bx);
	if (teimask[31])
		mtei31->clear(bx);


	if (olmask[0])
		mteol0->clear(bx);
	if (olmask[1])
		mteol1->clear(bx);
	if (olmask[2])
		mteol2->clear(bx);
	if (olmask[3])
		mteol3->clear(bx);
	if (olmask[4])
		mteol4->clear(bx);
	if (olmask[5])
		mteol5->clear(bx);
	if (olmask[6])
		mteol6->clear(bx);
	if (olmask[7])
		mteol7->clear(bx);
	if (olmask[8])
		mteol8->clear(bx);
	if (olmask[9])
		mteol9->clear(bx);
	if (olmask[10])
		mteol10->clear(bx);
	if (olmask[11])
		mteol11->clear(bx);
	if (olmask[12])
		mteol12->clear(bx);
	if (olmask[13])
		mteol13->clear(bx);
	if (olmask[14])
		mteol14->clear(bx);
	if (olmask[15])
		mteol15->clear(bx);


	if (teomask[0])
		mteo0->clear(bx);
	if (teomask[1])
		mteo1->clear(bx);
	if (teomask[2])
		mteo2->clear(bx);
	if (teomask[3])
		mteo3->clear(bx);
	if (teomask[4])
		mteo4->clear(bx);
	if (teomask[5])
		mteo5->clear(bx);
	if (teomask[6])
		mteo6->clear(bx);
	if (teomask[7])
		mteo7->clear(bx);
	if (teomask[8])
		mteo8->clear(bx);
	if (teomask[9])
		mteo9->clear(bx);
	if (teomask[10])
		mteo10->clear(bx);
	if (teomask[11])
		mteo11->clear(bx);
	if (teomask[12])
		mteo12->clear(bx);
	if (teomask[13])
		mteo13->clear(bx);
	if (teomask[14])
		mteo14->clear(bx);
	if (teomask[15])
		mteo15->clear(bx);
	if (teomask[16])
		mteo16->clear(bx);
	if (teomask[17])
		mteo17->clear(bx);
	if (teomask[18])
		mteo18->clear(bx);
	if (teomask[19])
		mteo19->clear(bx);
	if (teomask[20])
		mteo20->clear(bx);
	if (teomask[21])
		mteo21->clear(bx);
	if (teomask[22])
		mteo22->clear(bx);
	if (teomask[23])
		mteo23->clear(bx);
	if (teomask[24])
		mteo24->clear(bx);
	if (teomask[25])
		mteo25->clear(bx);
	if (teomask[26])
		mteo26->clear(bx);
	if (teomask[27])
		mteo27->clear(bx);
	if (teomask[28])
		mteo28->clear(bx);
	if (teomask[29])
		mteo29->clear(bx);
	if (teomask[30])
		mteo30->clear(bx);
	if (teomask[31])
		mteo31->clear(bx);


	// Number of data in each input memory
	const typename InputStubMemory<INTYPE>::NEntryT zero(0);

	auto n_i0 = imask[0] != 0 ? i0->getEntries(bx) : zero;
	auto n_i1 = imask[1] != 0 ? i1->getEntries(bx) : zero;
	auto n_i2 = imask[2] != 0 ? i2->getEntries(bx) : zero;
	auto n_i3 = imask[3] != 0 ? i3->getEntries(bx) : zero;
	auto n_i4 = imask[4] != 0 ? i4->getEntries(bx) : zero;
	auto n_i5 = imask[5] != 0 ? i5->getEntries(bx) : zero;


	// Create variables that keep track of which memory address to read and write to
	ap_uint<kNBits_MemAddr> read_addr(0); // Reading of input stubs

	int addrCountTEI[32]; // Writing of TE Inner stubs
#pragma HLS array_partition variable=addrCount
	for (int i = 0; i < 32; i++) {
		#pragma HLS UNROLL
		addrCountTEI[i] = 0;
	}

	int addrCountOL[16]; // Writing of TE Overlap stubs
#pragma HLS array_partition variable=addrCountOL
	for (int i = 0; i < 16; i++) {
		#pragma HLS UNROLL
		addrCountOL[i] = 0;
	}

	static const int firstmem = (teimask) ? memStartVal(teimask) : memStartVal(teomask); // The number of the first TE memory


	TOPLEVEL: for (auto i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1

		const bool haveData = (n_i0 > 0) || (n_i1 > 0) || (n_i2 > 0)
				|| (n_i3 > 0) || (n_i4 > 0) || (n_i5 > 0);

		// Stop processing stubs if we have looped over the maximum number
		// that can be processed or if we have gone through all data
		if ((i > MAXVMROUTER) || !haveData)
			continue;
		//const InputStubMemory *next; // this method makes vivado crash

		bool resetNext = false; // Used to reset read_addr
		bool isDisk2S = false; // Used to determine if first or 4th input, which are different for disks
		InputStub<INTYPE> stub;
		InputStub<INTYPE2> stub2; // Used for input 1 and 4 since they can be of different type in disks. find a better way to do this...
		// Read stub from memory in turn

		if (n_i0) {
			//next = i0;
			stub2 = i0->read_mem(bx, read_addr);
			isDisk2S = true;
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
			stub2 = i3->read_mem(bx, read_addr);
			isDisk2S  = true;
			--n_i3;
			if (n_i3 == 0)
				resetNext = true;
		} else if (n_i4) {
			stub = i4->read_mem(bx, read_addr);
			--n_i4;
			if (n_i4 == 0)
				resetNext = true;
		} else {
			stub = i5->read_mem(bx, read_addr);
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

		// add stub to AllStub memory
		// need two different ones depending on which stub...
		if (isDisk2S) {

			AllStub<OUTTYPE> allstubd(stub2.raw());
			allstub->write_mem(bx, allstubd, i);

// For debugging
#ifndef __SYNTHESIS__
		std::cout << "Out put stub: " << std::hex << allstubd.raw() << std::dec
				<< std::endl;
#endif // DEBUG
		} else {

			AllStub<OUTTYPE> allstubd(stub.raw());
			allstub->write_mem(bx, allstubd, i);

		// For debugging
		#ifndef __SYNTHESIS__
		std::cout << std::endl << "Out put stub: " << std::hex << allstubd.raw() << std::dec
				<< std::endl;
		#endif // DEBUG
		}

		// Variables that are going to be used by ME and TE memories
		int nrbits = (isDisk2S) ? stub2.getR().length() : stub.getR().length(); // Number of bits for r
		int nbendbits = (isDisk2S) ? stub2.getBend().length() : stub.getBend().length();
		auto z = (isDisk2S) ? stub2.getZ() : stub.getZ();
		int r = (isDisk2S) ? stub2.getR().range() : stub.getR().range();
		int bend = (isDisk2S) ? stub2.getBend().range() : stub.getBend().range();
		auto stubPhi_uncorr = (isDisk2S) ? stub2.getPhi() : stub.getPhi(); // Original phi, uncorrected. Should probably not be used, waiting for update of C++ emulation?
		auto stubPhi = getPhiCorr<INTYPE>(stubPhi_uncorr, r, bend, corrtable); // Corrected phi, i.e. phi at nominal radius (what about disks?)

		std::cout << "INDEX " << i << "     BEND "<< bend << "       NUMBER of bend bits: " << nbendbits << std::endl;


		/////////////////////////////////////////////
		// executeME() START ------------------------------
		// hourglass only

		// Total number of VMs for ME
		constexpr auto nvm =
				LAYER != 0 ?
						nallstubslayers[LAYER - 1] * nvmmelayers[LAYER - 1] :
						nallstubsdisks[DISK - 1] * nvmmedisks[DISK - 1];
		constexpr auto d = nvm / 32.0; // Some sort of normalisation thing

		VMStubME<OUTTYPE> stubme;
		stubme.setBend(bend); // how does it now if 3 or 4 bits? Same size as in InputStub thus no need to shift bits
		stubme.setIndex(typename VMStubME<OUTTYPE>::VMSMEID(i));

		auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
		auto iphiRawPlus = iphivmRawPlus<INTYPE>(stubPhi); // Top 5 bits of phi after adding a small number
		auto iphiRawMinus = iphivmRawMinus<INTYPE>(stubPhi); // Top 5 bits of phi after subtracting a small number

		int ivm = iphiRaw * d; // The VM number
		int ivmPlus = iphiRawPlus * d;
		int ivmMinus = iphiRawMinus * d;

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

			// Index of where to find the rfine value in finebintable
			// The top 7 MSBs of r, ignoring the sign.
			// Note: not the index that is being saved to the stub
			int index = (isDisk2S) ? r : (r
					>> (nrbits - nbitsfinebintable))
					& ((1 << nbitsfinebintable) - 1);


			// Set rfine: the r position within a bin
			//typename VMStubME<OUTTYPE>::VMSMEFINEZ rfine = finebintable[index]; // is it the same table as for z?
			int rfine = finebintable[index];
			int bajs = rfine & 7;
			stubme.setFineZ(bajs);

			// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
			bin = rfine >> 3;
			//bin = (r >> (nrbits - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse r value
			//if (isDisk2S) bin = r; // by looking at input files...

			std::cout  << "IS 2S: " << isDisk2S << "       bINNn "<< bin<< "   rfineee " << rfine << std::endl;
		} else { // layer

			// Get the 3 MSBs of z and add 4 as z is signed (z takes values between -4 and 3)
			bin = (z >> (z.length() - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse z value

			// Index of where to find the zfine value in finebintable
			// The top 7 MSBs of z, ignoring the sign.
			// Note: not the index that is being saved to the stub
			// TODO: change the type?? it's confusing. Same for the other memories
			typename VMStubME<OUTTYPE>::VMSMEID index = (z
					>> (z.length() - nbitsfinebintable))
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

		//0-9
		if (memask[0]) {

			if ((ivm == 0) || (ivmMinus == 0) || (ivmPlus == 0))
				m0->write_mem(bx, bin, stubme);
		}
		if (memask[1]) {
			if ((ivm == 1) || (ivmMinus == 1) || (ivmPlus == 1))
				m1->write_mem(bx, bin, stubme);
		}
		if (memask[2]) {
			if (ivm == 2 || ivmMinus == 2 || ivmPlus == 2)
				m2->write_mem(bx, bin, stubme);
		}
		if (memask[3]) {
			if (ivm == 3 || ivmMinus == 3 || ivmPlus == 3)
				m3->write_mem(bx, bin, stubme);
		}
		if (memask[4]) {
			if (ivm == 4 || ivmMinus == 4 || ivmPlus == 4)
				m4->write_mem(bx, bin, stubme);
		}
		if (memask[5]) {
			if (ivm == 5 || ivmMinus == 5 || ivmPlus == 5)
				m5->write_mem(bx, bin, stubme);
		}
		if (memask[6]) {
			if (ivm == 6 || ivmMinus == 6 || ivmPlus == 6)
				m6->write_mem(bx, bin, stubme);
		}
		if (memask[7]) {
			if (ivm == 7 || ivmMinus == 7 || ivmPlus == 7)
				m7->write_mem(bx, bin, stubme);
		}
		if (memask[8]) {
			if (ivm == 8 || ivmMinus == 8 || ivmPlus == 8)
				m8->write_mem(bx, bin, stubme);
		}
		if (memask[9]) {
			if (ivm == 9 || ivmMinus == 9 || ivmPlus == 9)
				m9->write_mem(bx, bin, stubme);
		}
		// 10-19
		if (memask[10]) {
			if ((ivm == 10) || (ivmMinus == 10) || (ivmPlus == 10))
				m10->write_mem(bx, bin, stubme);
		}
		if (memask[11]) {
			if ((ivm == 11) || (ivmMinus == 11) || (ivmPlus == 11))
				m11->write_mem(bx, bin, stubme);
		}
		if (memask[12]) {
			if (ivm == 12 || ivmMinus == 12 || ivmPlus == 12)
				m12->write_mem(bx, bin, stubme);
		}
		if (memask[13]) {
			if (ivm == 13 || ivmMinus == 13 || ivmPlus == 13)
				m13->write_mem(bx, bin, stubme);
		}
		if (memask[14]) {
			if (ivm == 14 || ivmMinus == 14 || ivmPlus == 14)
				m14->write_mem(bx, bin, stubme);
		}
		if (memask[15]) {
			if (ivm == 15 || ivmMinus == 15 || ivmPlus == 15)
				m15->write_mem(bx, bin, stubme);
		}
		if (memask[16]) {
			if (ivm == 16 || ivmMinus == 16 || ivmPlus == 16)
				m16->write_mem(bx, bin, stubme);
		}
		if (memask[17]) {
			if (ivm == 17 || ivmMinus == 17 || ivmPlus == 17)
				m17->write_mem(bx, bin, stubme);
		}
		if (memask[18]) {
			if (ivm == 18 || ivmMinus == 18 || ivmPlus == 18)
				m18->write_mem(bx, bin, stubme);
		}
		if (memask[19]) {
			if (ivm == 19 || ivmMinus == 19 || ivmPlus == 19)
				m19->write_mem(bx, bin, stubme);
		}
		// 20-29
		if (memask[20]) {
			if ((ivm == 20) || (ivmMinus == 20) || (ivmPlus == 20))
				m20->write_mem(bx, bin, stubme);
		}
		if (memask[21]) {
			if ((ivm == 21) || (ivmMinus == 21) || (ivmPlus == 21))
				m21->write_mem(bx, bin, stubme);
		}
		if (memask[22]) {
			if (ivm == 22 || ivmMinus == 22 || ivmPlus == 22)
				m22->write_mem(bx, bin, stubme);
		}
		if (memask[23]) {
			if (ivm == 23 || ivmMinus == 23 || ivmPlus == 23)
				m23->write_mem(bx, bin, stubme);
		}
		if (memask[24]) {
			if (ivm == 24 || ivmMinus == 24 || ivmPlus == 24)
				m24->write_mem(bx, bin, stubme);
		}
		if (memask[25]) {
			if (ivm == 25 || ivmMinus == 25 || ivmPlus == 25)
				m25->write_mem(bx, bin, stubme);
		}
		if (memask[26]) {
			if (ivm == 26 || ivmMinus == 26 || ivmPlus == 26)
				m26->write_mem(bx, bin, stubme);
		}
		if (memask[27]) {
			if (ivm == 27 || ivmMinus == 27 || ivmPlus == 27)
				m27->write_mem(bx, bin, stubme);
		}
		if (memask[28]) {
			if (ivm == 28 || ivmMinus == 28 || ivmPlus == 28)
				m28->write_mem(bx, bin, stubme);
		}
		if (memask[29]) {
			if (ivm == 29 || ivmMinus == 29 || ivmPlus == 29)
				m29->write_mem(bx, bin, stubme);
		}
		// 30-31
		if (memask[30]) {
			if ((ivm == 30) || (ivmMinus == 30) || (ivmPlus == 30))
				m30->write_mem(bx, bin, stubme);
		}
		if (memask[31]) {
			if ((ivm == 31) || (ivmMinus == 31) || (ivmPlus == 31))
				m31->write_mem(bx, bin, stubme);
		}
		// executeME() END   ------------------------------



		// 	// // executeTE() START ------------------------------

		// Total number of VMs for TE
		constexpr auto nvmte =
				LAYER != 0 ?
						nallstubslayers[LAYER - 1] * nvmtelayers[LAYER - 1] :
						nallstubsdisks[DISK - 1] * nvmtedisks[DISK - 1];

		iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi. TODO: we don't really need this...
		ivm = iphiRaw * nvmte / 32.0; // Which VM

		// TE Inner
		if (teimask != 0) {

			VMStubTEInner<OUTTYPE> stubTeInner;

			stubTeInner.setBend(bend);
			stubTeInner.setIndex(typename VMStubTEInner<OUTTYPE>::VMSTEIID(i));

			constexpr auto vmbits = (LAYER) ? vmbitsLayer[LAYER-1] : vmbitsDisk[DISK-1]; // Number of bits for VMs
			constexpr auto finephibits = (LAYER) ? nfinephibarrelinner : nfinephidiskinner; // Number of bits for finephi

			// The z/r information bits saved for TE Inner memories.
			// Which VMs to look at in the outer layer.
			// Note: not z/r coordinate for the inner stub
			// TODO: rename to e.g. rzTEbits
			int binlookup;

			// LAYER
			if (LAYER != 0) {

				constexpr int zbins = (1 << 7); // 7 = zbits
				constexpr int rbins = (1 << 4); // Number of bins in r
				ap_uint<7> zbin = (z + (1 << (z.length() - 1))) >> (z.length() - 7); // Make z positive and take the 7 MSBs TODO replace 7
				ap_uint<4> rbin = (r + (1 << (nrbits - 1))) >> (nrbits - 4);

				int index = zbin * rbins + rbin; // number of bins

				binlookup = binlookuptable[index];

				stubTeInner.setZBits(binlookup);
				stubTeInner.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));
			} else { // DISKS
				assert(DISK != 0);

				constexpr int zbins = (1 << 3); // 7 = zbits
				constexpr int rbins = (1 << 8); // Number of bins in r
				ap_uint<3> zbin = (z + (1 << (z.length() - 1))) >> (z.length() - 3); // Make z positive and take the 7 MSBs TODO replace 7
				ap_uint<8> rbin = r >> (nrbits-8);//(r + (1 << (nrbits - 1))) >> (nrbits - 8);

				int index = zbin * rbins + rbin; // number of bins

				binlookup = binlookuptable[index];

				stubTeInner.setZBits(binlookup);
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

			bool passbend = bendtable[ivm-firstmem][bend]; // Check if stub passes bend cut

			// Write the TE Inner stub to the correct memory
			// Only if it has a valid binlookup value, less than 1008 (table uses 1048575 as "-1"),
			// and a valid bend
			// TODO: implement VMR to write to the n memory copies, which are different depending on the bendcuts
			// TODO: doesn't it make more sense if < 1024?
			if (binlookup <= 1008 && passbend) {
				// 0-9
				if (teimask[0]) {
					if (ivm == 0) {
						mtei0->write_mem(bx, stubTeInner, addrCountTEI[0]);
						addrCountTEI[0] += 1;
					}
				}
				if (teimask[1]) {
					if (ivm == 1) {
						mtei1->write_mem(bx, stubTeInner, addrCountTEI[1]);
						addrCountTEI[1] += 1;
					}
				}
				if (teimask[2]) {
					if (ivm == 2) {
						mtei2->write_mem(bx, stubTeInner, addrCountTEI[2]);
						addrCountTEI[2] += 1;
					}
				}
				if (teimask[3]) {
					if (ivm == 3) {
						mtei3->write_mem(bx, stubTeInner, addrCountTEI[3]);
						addrCountTEI[3] += 1;
					}
				}
				if (teimask[4]) {
					if (ivm == 4) {
						mtei4->write_mem(bx, stubTeInner, addrCountTEI[4]);
						addrCountTEI[4] += 1;
					}
				}
				if (teimask[5]) {
					if (ivm == 5) {
						mtei5->write_mem(bx, stubTeInner, addrCountTEI[5]);
						addrCountTEI[5] += 1;
					}
				}
				if (teimask[6]) {
					if (ivm == 6) {
						mtei6->write_mem(bx, stubTeInner, addrCountTEI[6]);
						addrCountTEI[6] += 1;
					}
				}
				if (teimask[7]) {
					if (ivm == 7) {
						mtei7->write_mem(bx, stubTeInner, addrCountTEI[7]);
						addrCountTEI[7] += 1;
					}
				}
				if (teimask[8]) {
					if (ivm == 8) {
						mtei8->write_mem(bx, stubTeInner, addrCountTEI[8]);
						addrCountTEI[8] += 1;
					}
				}
				if (teimask[9]) {
					if (ivm == 9) {
						mtei9->write_mem(bx, stubTeInner, addrCountTEI[9]);
						addrCountTEI[9] += 1;
					}
				}
				// 10-19
				if (teimask[10]) {
					if (ivm == 10) {
						mtei10->write_mem(bx, stubTeInner, addrCountTEI[10]);
						addrCountTEI[10] += 1;
					}
				}
				if (teimask[11]) {
					if (ivm == 11) {
						mtei11->write_mem(bx, stubTeInner, addrCountTEI[11]);
						addrCountTEI[11] += 1;
					}
				}
				if (teimask[12]) {
					if (ivm == 12) {
						mtei12->write_mem(bx, stubTeInner, addrCountTEI[12]);
						addrCountTEI[12] += 1;
					}
				}
				if (teimask[13]) {
					if (ivm == 13) {
						mtei13->write_mem(bx, stubTeInner, addrCountTEI[13]);
					addrCountTEI[13] += 1;
					}
				}
				if (teimask[14]) {
					if (ivm == 14) {
						mtei14->write_mem(bx, stubTeInner, addrCountTEI[14]);
						addrCountTEI[14] += 1;
					}
				}
				if (teimask[15]) {
					if (ivm == 15) {
						mtei15->write_mem(bx, stubTeInner, addrCountTEI[15]);
						addrCountTEI[15] += 1;
					}
				}
				if (teimask[16]) {
					if (ivm == 16) {
						mtei16->write_mem(bx, stubTeInner, addrCountTEI[16]);
						addrCountTEI[16] += 1;
					}
					}
				if (teimask[17]) {
					if (ivm == 17) {
						mtei17->write_mem(bx, stubTeInner, addrCountTEI[17]);
						addrCountTEI[17] += 1;
					}
				}
				if (teimask[18]) {
					if (ivm == 18) {
						mtei18->write_mem(bx, stubTeInner, addrCountTEI[18]);
						addrCountTEI[18] += 1;
					}
				}
				if (teimask[19]) {
					if (ivm == 19) {
						mtei19->write_mem(bx, stubTeInner, addrCountTEI[19]);
						addrCountTEI[19] += 1;
					}
				}
				// 20-29
				if (teimask[20]) {
					if (ivm == 20) {
						mtei20->write_mem(bx, stubTeInner, addrCountTEI[20]);
						addrCountTEI[20] += 1;
					}
				}
				if (teimask[21]) {
					if (ivm == 21) {
						mtei21->write_mem(bx, stubTeInner, addrCountTEI[21]);
						addrCountTEI[21] += 1;
					}
				}
				if (teimask[22]) {
					if (ivm == 22) {
						mtei22->write_mem(bx, stubTeInner, addrCountTEI[22]);
						addrCountTEI[22] += 1;
					}
				}
				if (teimask[23]) {
					if (ivm == 23) {
						mtei23->write_mem(bx, stubTeInner, addrCountTEI[23]);
						addrCountTEI[23] += 1;
					}
				}
				if (teimask[24]) {
					if (ivm == 24) {
						mtei24->write_mem(bx, stubTeInner, addrCountTEI[24]);
						addrCountTEI[24] += 1;
					}
				}
				if (teimask[25]) {
					if (ivm == 25) {
						mtei25->write_mem(bx, stubTeInner, addrCountTEI[25]);
					addrCountTEI[25] += 1;
				}
				}
				if (teimask[26]) {
					if (ivm == 26) {
						mtei26->write_mem(bx, stubTeInner, addrCountTEI[26]);
						addrCountTEI[26] += 1;
					}
				}
				if (teimask[27]) {
					if (ivm == 27) {
						mtei27->write_mem(bx, stubTeInner, addrCountTEI[27]);
					addrCountTEI[27] += 1;
					}
				}
				if (teimask[28]) {
					if (ivm == 28) {
						mtei28->write_mem(bx, stubTeInner, addrCountTEI[28]);
					addrCountTEI[28] += 1;
					}
				}
				if (teimask[29]) {
					if (ivm == 29) {
						mtei29->write_mem(bx, stubTeInner, addrCountTEI[29]);
						addrCountTEI[29] += 1;
					}
				}
				// 30-31
				if (teimask[30]) {
					if (ivm == 30) {
						mtei30->write_mem(bx, stubTeInner, addrCountTEI[30]);
						addrCountTEI[30] += 1;
					}
				}
				if (teimask[31]) {
					if (ivm == 31) {
						mtei31->write_mem(bx, stubTeInner, addrCountTEI[31]);
						addrCountTEI[31] += 1;
					}
				}
		}
		}

		//  OVERLAP
		if (olmask != 0) {

			assert(LAYER == 1 || LAYER == 2); // Make sure that only layer 1 and 2 are overlapped

			int zbin = (z + (1 << (z.length() - 1))) >> (z.length() - 7); // Make z positive and take the 5 MSBs
			int rbin = (r + (1 << (nrbits - 1))) >> (nrbits - 3); // What is this doing... r already positive?! 4 MSBs??
			int index = zbin * rbin + rbin;

			int overlap = overlaptable[index];

			if (overlap != 1023) { // which is like "-1" if we had signed stuff?

				constexpr auto nvmol = nallstubslayers[LAYER] * 2; // Always 2 overlap vms?

				VMStubTEInner<BARRELOL> stubOL;

				// 16 overlap vms per layer
				stubPhi = getPhiCorr<INTYPE>(stub.getPhi(), stub.getR(), stub.getBend(), corrtable); // Could take from ME
				iphiRaw = iphivmRaw<INTYPE>(stubPhi) >> 1; // Top 4 bits of phi, NEED iphivmraw THAT RETURNS THE TOP 4?! CHECK THIS
				ivm = iphiRaw * nvmol / 16; // Which VM, BECAUSE WE HAVE 16 VMS?

				const auto nzbits = stubOL.getZBits().length();
				constexpr auto vmbits = vmbitsOverlap; // What is this still
				constexpr auto finephibits = 1; // or nfinephioverlapinner??? which is 2

				stubOL.setBend(bend);  //move so we don't call it all the time
				stubOL.setIndex(typename VMStubTEInner<BARRELOL>::VMSTEIID(i));
				stubOL.setZBits(overlap); // Maybe change so that we don't call getZ etc so many times? Manipulate bits?
				stubOL.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits)); // is this the right vmbits

// For debugging
#ifndef __SYNTHESIS__
				std::cout << "Overlap stub " << overlap << " " << std::hex
						<< stubOL.raw() << std::endl;
				std::cout << "ivm: " << std::dec << ivm << std::endl
						<< std::endl;
#endif // DEBUG

				// Save stub to memories
				// Note: the n copies seem to be the same
				// 0-9
				if (olmask[0]) {
					if (ivm == 0)
						mteol0->write_mem(bx, stubOL, addrCountOL[0]);
					addrCountOL[0] += 1;
				}
				if (olmask[1]) {
					if (ivm == 1)
						mteol1->write_mem(bx, stubOL, addrCountOL[1]);
					addrCountOL[1] += 1;
				}
				if (olmask[2]) {
					if (ivm == 2)
						mteol2->write_mem(bx, stubOL, addrCountOL[2]);
					addrCountOL[2] += 1;
				}
				if (olmask[3]) {
					if (ivm == 3)
						mteol3->write_mem(bx, stubOL, addrCountOL[3]);
					addrCountOL[3] += 1;
				}
				if (olmask[4]) {
					if (ivm == 4)
						mteol4->write_mem(bx, stubOL, addrCountOL[4]);
					addrCountOL[4] += 1;
				}
				if (olmask[5]) {
					if (ivm == 5)
						mteol5->write_mem(bx, stubOL, addrCountOL[5]);
					addrCountOL[5] += 1;
				}
				if (olmask[6]) {
					if (ivm == 6)
						mteol6->write_mem(bx, stubOL, addrCountOL[6]);
					addrCountOL[6] += 1;
				}
				if (olmask[7]) {
					if (ivm == 7)
						mteol7->write_mem(bx, stubOL, addrCountOL[7]);
					addrCountOL[7] += 1;
				}
				if (olmask[8]) {
					if (ivm == 8)
						mteol8->write_mem(bx, stubOL, addrCountOL[8]);
					addrCountOL[8] += 1;
				}
				if (olmask[9]) {
					if (ivm == 9)
						mteol9->write_mem(bx, stubOL, addrCountOL[9]);
					addrCountOL[9] += 1;
				}
				// 10-19
				if (olmask[10]) {
					if (ivm == 10)
						mteol10->write_mem(bx, stubOL, addrCountOL[10]);
					addrCountOL[10] += 1;
				}
				if (olmask[11]) {
					if (ivm == 11)
						mteol11->write_mem(bx, stubOL, addrCountOL[11]);
					addrCountOL[11] += 1;
				}
				if (olmask[12]) {
					if (ivm == 12)
						mteol12->write_mem(bx, stubOL, addrCountOL[12]);
					addrCountOL[12] += 1;
				}
				if (olmask[13]) {
					if (ivm == 13)
						mteol13->write_mem(bx, stubOL, addrCountOL[13]);
					addrCountOL[13] += 1;
				}
				if (olmask[14]) {
					if (ivm == 14)
						mteol14->write_mem(bx, stubOL, addrCountOL[14]);
					addrCountOL[14] += 1;
				}
				if (olmask[15]) {
					if (ivm == 15)
						mteol15->write_mem(bx, stubOL, addrCountOL[15]);
					addrCountOL[15] += 1;
				}
			} else {
				std::cout << "NO OVERLAP" << std::endl << std::endl;
			}
		}

		// TE Outer
		if (teomask != 0) {
			VMStubTEOuter<OUTTYPE> stubTeOuter;

			stubTeOuter.setBend(bend);
			stubTeOuter.setIndex(typename VMStubTEOuter<OUTTYPE>::VMSTEOID(i));

			ap_uint<TEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM
			iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi. TODO: we don't really need this...
			ivm = iphiRaw * nvmte / 32.0; // Which VM

			constexpr auto vmbits = (LAYER) ? vmbitsLayer[LAYER-1] : vmbitsDisk[DISK-1]; // Number of bits for VMs
			constexpr auto finephibits = (LAYER) ? nfinephibarrelouter : nfinephidiskouter; // Number of bits for finephi

			// LAYER
			if (LAYER != 0) {

				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits)); // is this the right vmbits

				// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
				bin = (z >> (z.length() - TEBinsBits))
						+ (1 << (TEBinsBits - 1)); // Coarse z value

				// Index of where to find the zfine value in finebintable
				// The top 7 MSBs of z, ignoring the sign.
				// Note: not the index that is being saved to the stub
				typename VMStubTEOuter<OUTTYPE>::VMSTEOID index = (z
						>> (z.length() - nbitsfinebintable))
						& ((1 << nbitsfinebintable) - 1);

				// Set zfine: the z position within a bin
				typename VMStubTEOuter<OUTTYPE>::VMSTEOFINEZ zfine =
						finebintable[index];
				stubTeOuter.setFineZ(zfine);
			} else { // DISKS
				assert(DISK != 0);

				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, vmbits, finephibits));

				// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
				bin = (r >> (nrbits - TEBinsBits))
						+ (1 << (TEBinsBits - 1)); // Coarse r value

				// Index of where to find the rfine value in finebintable
				// The top 7 MSBs of r, ignoring the sign.
				// Note: not the index that is being saved to the stub
				typename VMStubTEOuter<OUTTYPE>::VMSTEOID index = (r
						>> (nrbits - nbitsfinebintable))
						& ((1 << nbitsfinebintable) - 1);

				// set rfine: the r position within a bin
				typename VMStubTEOuter<OUTTYPE>::VMSTEOFINEZ rfine =
						finebintable[index]; // is it the same table as for z?
				assert(rfine >= 0);
				stubme.setFineZ(rfine);
			}

// For debugging
#ifndef __SYNTHESIS__
			std::cout << "TEOuter stub " << std::hex << stubTeOuter.raw()
					<< std::endl;
			std::cout << "ivm: " << std::dec << ivm << std::endl
					<< std::endl;
#endif // DEBUG

			bool passbend = (DISK == 1) ? bendtable2[ivm-firstmem][bend] : bendtable[ivm-firstmem][bend]; // Check if stub passes bend cut

			// Write the TE Outer stub to the correct memory
			// Only if it has a valid bend
			// TODO: implement VMR to write to the n memory copies, which are different depending on the bendcuts
			// TODO: can only use ivm if first memory is 0
			if (passbend) {
			// 0-9
			if (teomask[0]) {
				if (ivm == 0)
					mteo0->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[1]) {
				if (ivm == 1)
					mteo1->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[2]) {
				if (ivm == 2)
					mteo2->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[3]) {
				if (ivm == 3)
					mteo3->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[4]) {
				if (ivm == 4)
					mteo4->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[5]) {
				if (ivm == 5)
					mteo5->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[6]) {
				if (ivm == 6)
					mteo6->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[7]) {
				if (ivm == 7)
					mteo7->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[8]) {
				if (ivm == 8)
					mteo8->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[9]) {
				if (ivm == 9)
					mteo9->write_mem(bx, bin, stubTeOuter);
			}
			// 10-19
			if (teomask[10]) {
				if (ivm == 10)
					mteo10->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[11]) {
				if (ivm == 11)
					mteo11->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[12]) {
				if (ivm == 12)
					mteo12->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[13]) {
				if (ivm == 13)
					mteo13->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[14]) {
				if (ivm == 14)
					mteo14->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[15]) {
				if (ivm == 15)
					mteo15->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[16]) {
				if (ivm == 16)
					mteo16->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[17]) {
				if (ivm == 17)
					mteo17->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[18]) {
				if (ivm == 18)
					mteo18->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[19]) {
				if (ivm == 19)
					mteo19->write_mem(bx, bin, stubTeOuter);
			}
			// 20-29
			if (teomask[20]) {
				if (ivm == 20)
					mteo20->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[21]) {
				if (ivm == 21)
					mteo21->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[22]) {
				if (ivm == 22)
					mteo22->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[23]) {
				if (ivm == 23)
					mteo23->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[24]) {
				if (ivm == 24)
					mteo24->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[25]) {
				if (ivm == 25)
					mteo25->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[26]) {
				if (ivm == 26)
					mteo26->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[27]) {
				if (ivm == 27)
					mteo27->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[28]) {
				if (ivm == 28)
					mteo28->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[29]) {
				if (ivm == 29)
					mteo29->write_mem(bx, bin, stubTeOuter);
			}
			// 30-31
			if (teomask[30]) {
				if (ivm == 30)
					mteo30->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[31]) {
				if (ivm == 31)
					mteo31->write_mem(bx, bin, stubTeOuter);
			}
		}
		}

		// // executeTE() END   ------------------------------

	} // outside loop

} // VMRouter

#endif //VMROUTER_HH
