// VMRouter
// Log
// -------
// First tracklet 2.0 version -- December 2018 -- wittich

#ifndef VMROUTER_HH
#define VMROUTER_HH

#pragma once
#include "ap_int.h"
#include "Constants.hh"
#include "InputStubMemory.hh"
#include "AllStubMemory.hh"
#include "VMStubMEMemory.hh"
#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"
#include <assert.h>
#include <bitset> // For debugging purposes

// I include this to get the constants. we should figure out if this is
// the right way to go.
#include "MatchCalculator.hh"
// from FPGAConstants.hh -- needs a final home

constexpr double rmaxdisk = 120.0;
constexpr int nrbitsdisk = 12;
constexpr double kr = rmaxdisk / (1 << nrbitsdisk);

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
// Encoded r values for 2S disk modules? They are not used...
constexpr double rDSSinner[10] = { 66.7728, 71.7967, 77.5409, 82.5584, 84.8736,
		89.8953, 95.7791, 100.798, 102.495, 107.52 }; // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = { 65.1694, 70.1936, 75.6641, 80.6908, 83.9581,
		88.9827, 94.6539, 99.6772, 102.494, 107.519 }; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;

// TODO: fix the hacky underscores; probably pass in a pointer
// since we need to have different tables for different templated
// functions
// need to ensure this is recognized as a ROM
// Used to create LUT, kept for possible use in the non-synthesis context

// void init_finebintable(const int layer, const int disk,
//   int finebintable[kMaxFineBinTable], int & nbitsfinebintable)
//   {
//     #ifndef __SYNTHESIS__
//     // initialize
//     for(auto i=0;i<kMaxFineBinTable;i++) {
//       finebintable[i] = -1;
//     }
//
//     if (layer!=0) {
//       nbitsfinebintable=8;
//       unsigned int nbins=1<<nbitsfinebintable;
//
//
//       for(unsigned int i=0;i<nbins;i++) {
//         int ibin=(i>>(nbitsfinebintable-3));
//
//         int zfine=(i>>(nbitsfinebintable-6))-(ibin<<3);
//
//         //awkward bit manipulations since the index is from a signed number...
//         int index=i+(1<<(nbitsfinebintable-1));
//
//         if (index>=(1<<nbitsfinebintable)){
//           index-=(1<<nbitsfinebintable);
//         }
//
//         finebintable[index]=zfine;
//
//       }
//     }
//
//     if (disk!=0) {
//
//       nbitsfinebintable=8;
//       unsigned int nbins=1<<nbitsfinebintable;
//
//       for(unsigned int i=0;i<nbins;i++) {
//
//         double rstub=0.0;
//
//         if (i<10) {
//           if (disk<=2) {
//             rstub=rDSSinner[i];
//           } else {
//             rstub=rDSSouter[i];
//           }
//         } else {
//           rstub=kr*(i<<(nrbitsdisk-nbitsfinebintable));
//         }
//
//         if (rstub<rmindiskvm) {
//           finebintable[i] = -1;
//         } else {
//           int bin=8.0*(rstub-rmindiskvm)/(rmaxdisk-rmindiskvm);
//           assert(bin>=0);
//           //assert(bin<MEBinsDisks);
//           int rfine=64*((rstub-rmindiskvm)-bin*(rmaxdisk-rmindiskvm)/8.0)/(rmaxdisk-rmindiskvm);
//           finebintable[i] = rfine;
//         }
//       }
//     }
//     #else // __SYNTHESIS__
//     int tmp[256]=
//     #include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
//
//     for (int i=0;i<256;i++){
//       finebintable[i]=tmp[i];
//     }
//     nbitsfinebintable = 256;
//     #endif // __SYNTHESIS__
//   }

// local files
// returns top 5 bits of phi, i.e. max 31 in decimal
template<regionType INTYPE>
inline ap_uint<5> iphivmRaw(const typename AllStub<INTYPE>::ASPHI phi) {
	// TODO: get rid of hard-coded values
	ap_uint<5> iphivm = phi.range(phi.length() - 1, phi.length() - 5);
	return iphivm;
}

// VMbits is the number of bits for the fine bins. (MEI: isn't it for the VMs?)
// E.g. 32 bins would use VMbits=5
// finebits is the number of bits within the VM
template<regionType INTYPE>
inline int iphivmFineBins(const typename AllStub<INTYPE>::ASPHI phi,
		const int VMbits, const int finebits) {
	auto length = phi.length() - VMbits - finebits;
	//    return ap_uint<5>.range(phi.length()-length, phi.length()-1);
	auto v1 = ap_uint<5>(phi.range(phi.length() - 1, phi.length() - length));
	auto v2 = (phi >> (phi.length() - VMbits - finebits))
			& ((1 << finebits) - 1);
	//assert(v1 == v2);
	return (phi >> (phi.length() - VMbits - finebits)) & ((1 << finebits) - 1);;
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

// Maximum number of stubs that can be processed (memory depth)
// originally 64, but then it won't pass test bench as it contains more than 64 stubs
constexpr int MAXVMROUTER = kMaxProc; // TODO need right symbol here

template<regionType INTYPE, regionType METYPE, int LAYER, int DISK> //, int NINPUTS, uint32_t MEMASK, uint32_t TEIMASK, uint16_t OLMASK, uint32_t TEOMASK>
void VMRouter(const BXType bx, const int finebintable[], const int binlookuptable[], const int bendtable[],
		const int overlaptable[],
		// Input memories
		const ap_uint<6>& imask, const InputStubMemory<INTYPE>* const i0,
		const InputStubMemory<INTYPE>* const i1,
		const InputStubMemory<INTYPE>* const i2,
		const InputStubMemory<INTYPE>* const i3,
		const InputStubMemory<INTYPE>* const i4,
		const InputStubMemory<INTYPE>* const i5,
		// AllStub memory
		AllStubMemory<INTYPE>* allstub,
		// ME memories
		const ap_uint<32>& memask, VMStubMEMemory<METYPE> *m0,
		VMStubMEMemory<METYPE> *m1, VMStubMEMemory<METYPE> *m2,
		VMStubMEMemory<METYPE> *m3, VMStubMEMemory<METYPE> *m4,
		VMStubMEMemory<METYPE> *m5, VMStubMEMemory<METYPE> *m6,
		VMStubMEMemory<METYPE> *m7, VMStubMEMemory<METYPE> *m8,
		VMStubMEMemory<METYPE> *m9, VMStubMEMemory<METYPE> *m10,
		VMStubMEMemory<METYPE> *m11, VMStubMEMemory<METYPE> *m12,
		VMStubMEMemory<METYPE> *m13, VMStubMEMemory<METYPE> *m14,
		VMStubMEMemory<METYPE> *m15, VMStubMEMemory<METYPE> *m16,
		VMStubMEMemory<METYPE> *m17, VMStubMEMemory<METYPE> *m18,
		VMStubMEMemory<METYPE> *m19, VMStubMEMemory<METYPE> *m20,
		VMStubMEMemory<METYPE> *m21, VMStubMEMemory<METYPE> *m22,
		VMStubMEMemory<METYPE> *m23, VMStubMEMemory<METYPE> *m24,
		VMStubMEMemory<METYPE> *m25, VMStubMEMemory<METYPE> *m26,
		VMStubMEMemory<METYPE> *m27, VMStubMEMemory<METYPE> *m28,
		VMStubMEMemory<METYPE> *m29, VMStubMEMemory<METYPE> *m30,
		VMStubMEMemory<METYPE> *m31,
		// // Inner TE memories, non-overlap
		const ap_uint<32>& teimask, VMStubTEInnerMemory<METYPE> *mtei0,
		VMStubTEInnerMemory<METYPE> *mtei1, VMStubTEInnerMemory<METYPE> *mtei2,
		VMStubTEInnerMemory<METYPE> *mtei3, VMStubTEInnerMemory<METYPE> *mtei4,
		VMStubTEInnerMemory<METYPE> *mtei5, VMStubTEInnerMemory<METYPE> *mtei6,
		VMStubTEInnerMemory<METYPE> *mtei7, VMStubTEInnerMemory<METYPE> *mtei8,
		VMStubTEInnerMemory<METYPE> *mtei9, VMStubTEInnerMemory<METYPE> *mtei10,
		VMStubTEInnerMemory<METYPE> *mtei11,
		VMStubTEInnerMemory<METYPE> *mtei12,
		VMStubTEInnerMemory<METYPE> *mtei13,
		VMStubTEInnerMemory<METYPE> *mtei14,
		VMStubTEInnerMemory<METYPE> *mtei15,
		VMStubTEInnerMemory<METYPE> *mtei16,
		VMStubTEInnerMemory<METYPE> *mtei17,
		VMStubTEInnerMemory<METYPE> *mtei18,
		VMStubTEInnerMemory<METYPE> *mtei19,
		VMStubTEInnerMemory<METYPE> *mtei20,
		VMStubTEInnerMemory<METYPE> *mtei21,
		VMStubTEInnerMemory<METYPE> *mtei22,
		VMStubTEInnerMemory<METYPE> *mtei23,
		VMStubTEInnerMemory<METYPE> *mtei24,
		VMStubTEInnerMemory<METYPE> *mtei25,
		VMStubTEInnerMemory<METYPE> *mtei26,
		VMStubTEInnerMemory<METYPE> *mtei27,
		VMStubTEInnerMemory<METYPE> *mtei28,
		VMStubTEInnerMemory<METYPE> *mtei29,
		VMStubTEInnerMemory<METYPE> *mtei30,
		VMStubTEInnerMemory<METYPE> *mtei31,
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
		const ap_uint<32>& teomask, VMStubTEOuterMemory<METYPE> *mteo0,
		VMStubTEOuterMemory<METYPE> *mteo1, VMStubTEOuterMemory<METYPE> *mteo2,
		VMStubTEOuterMemory<METYPE> *mteo3, VMStubTEOuterMemory<METYPE> *mteo4,
		VMStubTEOuterMemory<METYPE> *mteo5, VMStubTEOuterMemory<METYPE> *mteo6,
		VMStubTEOuterMemory<METYPE> *mteo7, VMStubTEOuterMemory<METYPE> *mteo8,
		VMStubTEOuterMemory<METYPE> *mteo9, VMStubTEOuterMemory<METYPE> *mteo10,
		VMStubTEOuterMemory<METYPE> *mteo11,
		VMStubTEOuterMemory<METYPE> *mteo12,
		VMStubTEOuterMemory<METYPE> *mteo13,
		VMStubTEOuterMemory<METYPE> *mteo14,
		VMStubTEOuterMemory<METYPE> *mteo15,
		VMStubTEOuterMemory<METYPE> *mteo16,
		VMStubTEOuterMemory<METYPE> *mteo17,
		VMStubTEOuterMemory<METYPE> *mteo18,
		VMStubTEOuterMemory<METYPE> *mteo19,
		VMStubTEOuterMemory<METYPE> *mteo20,
		VMStubTEOuterMemory<METYPE> *mteo21,
		VMStubTEOuterMemory<METYPE> *mteo22,
		VMStubTEOuterMemory<METYPE> *mteo23,
		VMStubTEOuterMemory<METYPE> *mteo24,
		VMStubTEOuterMemory<METYPE> *mteo25,
		VMStubTEOuterMemory<METYPE> *mteo26,
		VMStubTEOuterMemory<METYPE> *mteo27,
		VMStubTEOuterMemory<METYPE> *mteo28,
		VMStubTEOuterMemory<METYPE> *mteo29,
		VMStubTEOuterMemory<METYPE> *mteo30,
		VMStubTEOuterMemory<METYPE> *mteo31) {

	// // size of array here is the max possible value
	// static int finebintable[kMaxFineBinTable]; // lookup table - 2^nbinsfinbinetable entries actually filled
	static int nbitsfinebintable = 8; // this appears to always be 8. Total number of bits the finebintable consists of
	// static bool tableinitialized = false;
	// if ( ! tableinitialized ) {
	//   init_finebintable(layer,disk,finebintable,nbitsfinebintable);
	//   tableinitialized = true;
	// }

	// lookup table - 2^nbinsfinbinetable entries actually filled
	// Table is filled with numbers between 0 and 7 (and -1): the finer region each z/r bin is divided into.
	// static const int finebintable[kMaxFineBinTable] =
	// #include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
	// ;
	//
	// // Overlap LUT
	// static const int overlaptable[1024] = // 10 bits used for LUT
	// #include "../emData/VMR/VMTableInnerL1D1.txt" // Only for Layer 1
	// ;
	// static const int finebintable[kMaxFineBinTable] =
	// #include "../emData/VMR/VMR_D1PHIA_finebin.txt"
	// ;
	// if (DISK == 1) { // TODO make finebintable statis const
	// 	finebintable[kMaxFineBinTable] =
	// 	#include "../emData/VMR/VMR_D1PHIA_finebin.txt"
	// 	;}
	// 	} else { // Layer. Note, all layers and regions seem to have the same finebintable
	// 		static const  int finebintable[kMaxFineBinTable] =
	// 		#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
	// 		;
	// }

#pragma HLS array_partition variable=finebintable
	// Reset address counters in output memories

	allstub->clear(bx);
	// if ( MEMASK &  0x1        ) m0->clear(bx);
	// if ( MEMASK &  0x2        ) m1->clear(bx);
	// if ( MEMASK &  0x4        ) m2->clear(bx);
	// if ( MEMASK &  0x8        ) m3->clear(bx);
	// if ( MEMASK &  0x10       ) m4->clear(bx);
	// if ( MEMASK &  0x20       ) m5->clear(bx);
	// if ( MEMASK &  0x40       ) m6->clear(bx);
	// if ( MEMASK &  0x80       ) m7->clear(bx);
	// if ( MEMASK &  0x100      ) m8->clear(bx);
	// if ( MEMASK &  0x200      ) m9->clear(bx);
	// if ( MEMASK &  0x400      ) m10->clear(bx);
	// if ( MEMASK &  0x800      ) m11->clear(bx);
	// if ( MEMASK &  0x1000     ) m12->clear(bx);
	// if ( MEMASK &  0x2000     ) m13->clear(bx);
	// if ( MEMASK &  0x4000     ) m14->clear(bx);
	// if ( MEMASK &  0x8000     ) m15->clear(bx);
	// if ( MEMASK &  0x10000    ) m16->clear(bx);
	// if ( MEMASK &  0x20000    ) m17->clear(bx);
	// if ( MEMASK &  0x40000    ) m18->clear(bx);
	// if ( MEMASK &  0x80000    ) m19->clear(bx);
	// if ( MEMASK &  0x100000   ) m20->clear(bx);
	// if ( MEMASK &  0x200000   ) m21->clear(bx);
	// if ( MEMASK &  0x400000   ) m22->clear(bx);
	// if ( MEMASK &  0x800000   ) m23->clear(bx);
	// if ( MEMASK &  0x1000000  ) m24->clear(bx);
	// if ( MEMASK &  0x2000000  ) m25->clear(bx);
	// if ( MEMASK &  0x4000000  ) m26->clear(bx);
	// if ( MEMASK &  0x8000000  ) m27->clear(bx);
	// if ( MEMASK &  0x10000000 ) m28->clear(bx);
	// if ( MEMASK &  0x20000000 ) m29->clear(bx);
	// if ( MEMASK &  0x40000000 ) m30->clear(bx);
	// if ( MEMASK &  0x80000000 ) m31->clear(bx);
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

	// if ( TEIMASK & 0x1        ) mtei0->clear(bx);
	// if ( TEIMASK & 0x2        ) mtei1->clear(bx);
	// if ( TEIMASK & 0x4        ) mtei2->clear(bx);
	// if ( TEIMASK & 0x8        ) mtei3->clear(bx);
	// if ( TEIMASK & 0x10       ) mtei4->clear(bx);
	// if ( TEIMASK & 0x20       ) mtei5->clear(bx);
	// if ( TEIMASK & 0x40       ) mtei6->clear(bx);
	// if ( TEIMASK & 0x80       ) mtei7->clear(bx);
	// if ( TEIMASK & 0x100      ) mtei8->clear(bx);
	// if ( TEIMASK & 0x200      ) mtei9->clear(bx);
	// if ( TEIMASK & 0x400      ) mtei10->clear(bx);
	// if ( TEIMASK & 0x800      ) mtei11->clear(bx);
	// if ( TEIMASK & 0x1000     ) mtei12->clear(bx);
	// if ( TEIMASK & 0x2000     ) mtei13->clear(bx);
	// if ( TEIMASK & 0x4000     ) mtei14->clear(bx);
	// if ( TEIMASK & 0x8000     ) mtei15->clear(bx);
	// if ( TEIMASK & 0x10000    ) mtei16->clear(bx);
	// if ( TEIMASK & 0x20000    ) mtei17->clear(bx);
	// if ( TEIMASK & 0x40000    ) mtei18->clear(bx);
	// if ( TEIMASK & 0x80000    ) mtei19->clear(bx);
	// if ( TEIMASK & 0x100000   ) mtei20->clear(bx);
	// if ( TEIMASK & 0x200000   ) mtei21->clear(bx);
	// if ( TEIMASK & 0x400000   ) mtei22->clear(bx);
	// if ( TEIMASK & 0x800000   ) mtei23->clear(bx);
	// if ( TEIMASK & 0x1000000  ) mtei24->clear(bx);
	// if ( TEIMASK & 0x2000000  ) mtei25->clear(bx);
	// if ( TEIMASK & 0x4000000  ) mtei26->clear(bx);
	// if ( TEIMASK & 0x8000000  ) mtei27->clear(bx);
	// if ( TEIMASK & 0x10000000 ) mtei28->clear(bx);
	// if ( TEIMASK & 0x20000000 ) mtei29->clear(bx);
	// if ( TEIMASK & 0x40000000 ) mtei30->clear(bx);
	// if ( TEIMASK & 0x80000000 ) mtei31->clear(bx);

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

	// if ( OLMASK & 0x1        ) mteol0->clear(bx);
	// if ( OLMASK & 0x2        ) mteol1->clear(bx);
	// if ( OLMASK & 0x4        ) mteol2->clear(bx);
	// if ( OLMASK & 0x8        ) mteol3->clear(bx);
	// if ( OLMASK & 0x10       ) mteol4->clear(bx);
	// if ( OLMASK & 0x20       ) mteol5->clear(bx);
	// if ( OLMASK & 0x40       ) mteol6->clear(bx);
	// if ( OLMASK & 0x80       ) mteol7->clear(bx);
	// if ( OLMASK & 0x100      ) mteol8->clear(bx);
	// if ( OLMASK & 0x200      ) mteol9->clear(bx);
	// if ( OLMASK & 0x400      ) mteol10->clear(bx);
	// if ( OLMASK & 0x800      ) mteol11->clear(bx);
	// if ( OLMASK & 0x1000     ) mteol12->clear(bx);
	// if ( OLMASK & 0x2000     ) mteol13->clear(bx);
	// if ( OLMASK & 0x4000     ) mteol14->clear(bx);
	// if ( OLMASK & 0x8000     ) mteol15->clear(bx);
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

	// if ( TEOMASK & 0x1        ) mteo0->clear(bx);
	// if ( TEOMASK & 0x2        ) mteo1->clear(bx);
	// if ( TEOMASK & 0x4        ) mteo2->clear(bx);
	// if ( TEOMASK & 0x8        ) mteo3->clear(bx);
	// if ( TEOMASK & 0x10       ) mteo4->clear(bx);
	// if ( TEOMASK & 0x20       ) mteo5->clear(bx);
	// if ( TEOMASK & 0x40       ) mteo6->clear(bx);
	// if ( TEOMASK & 0x80       ) mteo7->clear(bx);
	// if ( TEOMASK & 0x100      ) mteo8->clear(bx);
	// if ( TEOMASK & 0x200      ) mteo9->clear(bx);
	// if ( TEOMASK & 0x400      ) mteo10->clear(bx);
	// if ( TEOMASK & 0x800      ) mteo11->clear(bx);
	// if ( TEOMASK & 0x1000     ) mteo12->clear(bx);
	// if ( TEOMASK & 0x2000     ) mteo13->clear(bx);
	// if ( TEOMASK & 0x4000     ) mteo14->clear(bx);
	// if ( TEOMASK & 0x8000     ) mteo15->clear(bx);
	// if ( TEOMASK & 0x10000    ) mteo16->clear(bx);
	// if ( TEOMASK & 0x20000    ) mteo17->clear(bx);
	// if ( TEOMASK & 0x40000    ) mteo18->clear(bx);
	// if ( TEOMASK & 0x80000    ) mteo19->clear(bx);
	// if ( TEOMASK & 0x100000   ) mteo20->clear(bx);
	// if ( TEOMASK & 0x200000   ) mteo21->clear(bx);
	// if ( TEOMASK & 0x400000   ) mteo22->clear(bx);
	// if ( TEOMASK & 0x800000   ) mteo23->clear(bx);
	// if ( TEOMASK & 0x1000000  ) mteo24->clear(bx);
	// if ( TEOMASK & 0x2000000  ) mteo25->clear(bx);
	// if ( TEOMASK & 0x4000000  ) mteo26->clear(bx);
	// if ( TEOMASK & 0x8000000  ) mteo27->clear(bx);
	// if ( TEOMASK & 0x10000000 ) mteo28->clear(bx);
	// if ( TEOMASK & 0x20000000 ) mteo29->clear(bx);
	// if ( TEOMASK & 0x40000000 ) mteo30->clear(bx);
	// if ( TEOMASK & 0x80000000 ) mteo31->clear(bx);

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
	// Maybe find a better way to do this one day
	typename InputStubMemory<INTYPE>::NEntryT zero(0);

	// auto n_i0 = zero;
	// auto n_i1 = zero;
	// auto n_i2 = zero;
	// auto n_i3 = zero;
	// auto n_i4 = zero;
	// auto n_i5 = zero;
	//
	// if ( 0 < NINPUTS ) n_i0 = i0->getEntries(bx);
	// if ( 1 < NINPUTS ) n_i1 = i1->getEntries(bx);
	// if ( 2 < NINPUTS ) n_i2 = i2->getEntries(bx);
	// if ( 3 < NINPUTS ) n_i3 = i3->getEntries(bx);
	// if ( 4 < NINPUTS ) n_i4 = i4->getEntries(bx);
	// if ( 5 < NINPUTS ) n_i5 = i5->getEntries(bx);

	auto n_i0 = imask[0] != 0 ? i0->getEntries(bx) : zero; // change to nullptr?
	auto n_i1 = imask[1] != 0 ? i1->getEntries(bx) : zero;
	auto n_i2 = imask[2] != 0 ? i2->getEntries(bx) : zero;
	auto n_i3 = imask[3] != 0 ? i3->getEntries(bx) : zero;
	auto n_i4 = imask[4] != 0 ? i4->getEntries(bx) : zero;
	auto n_i5 = imask[5] != 0 ? i5->getEntries(bx) : zero;

	// need to figure out how to get the accurate total count of loop
	// iterations here for nested loops. Count in innermost loop?

	ap_uint<kNBits_MemAddr> read_addr(0); // Determines which memory address to be read
	int addrCount[32] = { 0 }; // Keeps track of write address for TE inner
	int addrCountOL[16] = { 0 }; // Keeps track of write address for TE Inner Overlap
	int addrCountO[32] = { 0 }; // Keeps track of write address for TE Outer

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
		InputStub<INTYPE> stub;
		// auto stub =  ? // input type can changes in the disks

		// Read stub from memory in turn
		if (n_i0) {
			//next = i0;
			stub = i0->read_mem(bx, read_addr);
			--n_i0;
			if (n_i0 == 0)
				resetNext = true;
		} else if (n_i1) {
			//next = i1;
			stub = i1->read_mem(bx, read_addr);
			--n_i1;
			if (n_i1 == 0)
				resetNext = true;
		} else if (n_i2) {
			//next = i2;
			stub = i2->read_mem(bx, read_addr);
			--n_i2;
			if (n_i2 == 0)
				resetNext = true;
		} else if (n_i3) {
			//next = i3;
			stub = i3->read_mem(bx, read_addr);
			--n_i3;
			if (n_i3 == 0)
				resetNext = true;
		} else if (n_i4) {
			//next = i4;
			stub = i4->read_mem(bx, read_addr);
			--n_i4;
			if (n_i4 == 0)
				resetNext = true;
		} else { // if ( n_i5 )
				 //next = i5;
			stub = i5->read_mem(bx, read_addr);
			--n_i5;
			if (n_i5 == 0)
				resetNext = true;
		}

		//auto stub=next->read_mem(bx, read_addr); // this caused vivado to crash

		// Increment the read address, or reset it to zero when all stubs in one memory has been read
		if (resetNext)
			read_addr = 0;
		else
			++read_addr;

		// add stub to AllStub memory (memories?)
		// HACK fix me
		AllStub<INTYPE> allstubd(stub.raw());
		std::cout << "Out put stub: " << std::hex << allstubd.raw() << std::dec
				<< std::endl;
		// END HACK
		// What is the hack??
		allstub->write_mem(bx, allstubd, i);

		/////////////////////////////////////////////
		// executeME() START ------------------------------
		// hourglass only

		VMStubME<METYPE> stubme;
		stubme.setBend(stub.getBend()); // how does it now if 3 or 4 bits? Same size as in InputStub thus no need to shift bits
		stubme.setIndex(typename VMStubME<METYPE>::VMSMEID(i));

		//WHY ARE THESE HACKS? THEY ARE NOT NEEDED
		//auto layer_ = layer; // hack.
		//auto disk_  = disk; // hack --these are mutually exclusive so ...

		// Total number of VMs for ME
		auto nvm =
				LAYER != 0 ?
						nallstubslayers[LAYER - 1] * nvmmelayers[LAYER - 1] :
						nallstubsdisks[DISK - 1] * nvmmedisks[DISK - 1];

		auto stubPhi = stub.getPhi();
		auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
		auto iphiRawPlus = iphivmRawPlus<INTYPE>(stubPhi); // Top 5 bits of phi after adding a small number
		auto iphiRawMinus = iphivmRawMinus<INTYPE>(stubPhi); // Top 5 bits of phi after subtracting a small number
		auto d = nvm / 32; // Some sort of normalisation thing
		// TODO: comment this
		iphiRaw = iphiRaw * d; // The VM number
		iphiRawPlus = iphiRawPlus * d;
		iphiRawMinus = iphiRawMinus * d;
		if (iphiRawPlus >= nvm)
			iphiRawPlus = nvm - 1;
		if (iphiRawMinus >= nvm)
			iphiRawMinus = nvm - 1;
		// if (! (std::abs(iphiRaw-iphiRawPlus) <= 1 )) {
		//   std::cout << "XXX+: " << iphiRaw << " " << iphiRawPlus << std::endl;
		// }

		// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
		assert(std::abs(iphiRaw - iphiRawPlus) <= 1);
		assert(std::abs(iphiRaw-iphiRawMinus) <= 1 );

		ap_uint<MEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

		if (DISK) { // Not implemented
			assert(1 == 0);
			auto r = stub.getR();

			// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
			bin = (r >> (r.length() - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse r value

			// Ignoring the sign (MSB): the top 7 MSBs of r. Note, not the index that is being saved to the stub
			typename VMStubME<METYPE>::VMSMEID index = (r
					>> (r.length() - nbitsfinebintable))
					& ((1 << nbitsfinebintable) - 1);
			// set rfine: the r position within a bin
			typename VMStubME<METYPE>::VMSMEFINEZ rfine = finebintable[index]; // is it the same table as for z?
			assert(rfine >= 0);
			stubme.setFineZ(rfine);
		} else { // layer
			auto z = stub.getZ();

			// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
			bin = (z >> (z.length() - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse z value

			// Ignoring the sign (MSB): the top 7 MSBs of z. Note: not the index that is being saved to the stub
			typename VMStubME<METYPE>::VMSMEID index = (z
					>> (z.length() - nbitsfinebintable))
					& ((1 << nbitsfinebintable) - 1);
			// Set zfine: the z position within a bin
			typename VMStubME<METYPE>::VMSMEFINEZ zfine = finebintable[index]; // Using the bits 5 down to 2?
			stubme.setFineZ(zfine);

		}
		// put in a bunch of enables to decide which memories to write
		// to.

		// now actually update the stubs in the new memories
		// based on the Verilog version by MEZ

#ifndef __SYNTHESIS__
		std::cout << "ME stub " << std::hex << stubme.raw() << std::endl;

		std::cout << "iPhiRaw,Minus,Plus = " << std::dec << iphiRaw << " "
				<< iphiRawMinus << " " << iphiRawPlus << " " << "\t0x"
				<< std::setfill('0') << std::setw(4) << std::hex
				<< stubme.raw().to_int() << std::dec << ", to bin " << bin
				<< std::endl;
		//TODO add this debug thing again
		//if ( ! memask[iphiRaw] ) {
		//	std::cerr << "Trying to write to non-existent memory for iphiRaw = "
		//	<< iphiRaw << std::endl;
		//}
#endif // DEBUG

		//0-9
		if (memask[0]) {
			if ((iphiRaw == 0) || (iphiRawMinus == 0) || (iphiRawPlus == 0))
				m0->write_mem(bx, bin, stubme);
		}
		if (memask[1]) {
			if ((iphiRaw == 1) || (iphiRawMinus == 1) || (iphiRawPlus == 1))
				m1->write_mem(bx, bin, stubme);
		}
		if (memask[2]) {
			if (iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2)
				m2->write_mem(bx, bin, stubme);
		}
		if (memask[3]) {
			if (iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3)
				m3->write_mem(bx, bin, stubme);
		}
		if (memask[4]) {
			if (iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4)
				m4->write_mem(bx, bin, stubme);
		}
		if (memask[5]) {
			if (iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5)
				m5->write_mem(bx, bin, stubme);
		}
		if (memask[6]) {
			if (iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6)
				m6->write_mem(bx, bin, stubme);
		}
		if (memask[7]) {
			if (iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7)
				m7->write_mem(bx, bin, stubme);
		}
		if (memask[8]) {
			if (iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8)
				m8->write_mem(bx, bin, stubme);
		}
		if (memask[9]) {
			if (iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9)
				m9->write_mem(bx, bin, stubme);
		}
		// 10-19
		if (memask[10]) {
			if ((iphiRaw == 10) || (iphiRawMinus == 10) || (iphiRawPlus == 10))
				m10->write_mem(bx, bin, stubme);
		}
		if (memask[11]) {
			if ((iphiRaw == 11) || (iphiRawMinus == 11) || (iphiRawPlus == 11))
				m11->write_mem(bx, bin, stubme);
		}
		if (memask[12]) {
			if (iphiRaw == 12 || iphiRawMinus == 12 || iphiRawPlus == 12)
				m12->write_mem(bx, bin, stubme);
		}
		if (memask[13]) {
			if (iphiRaw == 13 || iphiRawMinus == 13 || iphiRawPlus == 13)
				m13->write_mem(bx, bin, stubme);
		}
		if (memask[14]) {
			if (iphiRaw == 14 || iphiRawMinus == 14 || iphiRawPlus == 14)
				m14->write_mem(bx, bin, stubme);
		}
		if (memask[15]) {
			if (iphiRaw == 15 || iphiRawMinus == 15 || iphiRawPlus == 15)
				m15->write_mem(bx, bin, stubme);
		}
		if (memask[16]) {
			if (iphiRaw == 16 || iphiRawMinus == 16 || iphiRawPlus == 16)
				m16->write_mem(bx, bin, stubme);
		}
		if (memask[17]) {
			if (iphiRaw == 17 || iphiRawMinus == 17 || iphiRawPlus == 17)
				m17->write_mem(bx, bin, stubme);
		}
		if (memask[18]) {
			if (iphiRaw == 18 || iphiRawMinus == 18 || iphiRawPlus == 18)
				m18->write_mem(bx, bin, stubme);
		}
		if (memask[19]) {
			if (iphiRaw == 19 || iphiRawMinus == 19 || iphiRawPlus == 19)
				m19->write_mem(bx, bin, stubme);
		}
		// 20-29
		if (memask[20]) {
			if ((iphiRaw == 20) || (iphiRawMinus == 20) || (iphiRawPlus == 20))
				m20->write_mem(bx, bin, stubme);
		}
		if (memask[21]) {
			if ((iphiRaw == 21) || (iphiRawMinus == 21) || (iphiRawPlus == 21))
				m21->write_mem(bx, bin, stubme);
		}
		if (memask[22]) {
			if (iphiRaw == 22 || iphiRawMinus == 22 || iphiRawPlus == 22)
				m22->write_mem(bx, bin, stubme);
		}
		if (memask[23]) {
			if (iphiRaw == 23 || iphiRawMinus == 23 || iphiRawPlus == 23)
				m23->write_mem(bx, bin, stubme);
		}
		if (memask[24]) {
			if (iphiRaw == 24 || iphiRawMinus == 24 || iphiRawPlus == 24)
				m24->write_mem(bx, bin, stubme);
		}
		if (memask[25]) {
			if (iphiRaw == 25 || iphiRawMinus == 25 || iphiRawPlus == 25)
				m25->write_mem(bx, bin, stubme);
		}
		if (memask[26]) {
			if (iphiRaw == 26 || iphiRawMinus == 26 || iphiRawPlus == 26)
				m26->write_mem(bx, bin, stubme);
		}
		if (memask[27]) {
			if (iphiRaw == 27 || iphiRawMinus == 27 || iphiRawPlus == 27)
				m27->write_mem(bx, bin, stubme);
		}
		if (memask[28]) {
			if (iphiRaw == 28 || iphiRawMinus == 28 || iphiRawPlus == 28)
				m28->write_mem(bx, bin, stubme);
		}
		if (memask[29]) {
			if (iphiRaw == 29 || iphiRawMinus == 29 || iphiRawPlus == 29)
				m29->write_mem(bx, bin, stubme);
		}
		// 30-31
		if (memask[30]) {
			if ((iphiRaw == 30) || (iphiRawMinus == 30) || (iphiRawPlus == 30))
				m30->write_mem(bx, bin, stubme);
		}
		if (memask[31]) {
			if ((iphiRaw == 31) || (iphiRawMinus == 31) || (iphiRawPlus == 31))
				m31->write_mem(bx, bin, stubme);
		}
		// executeME() END   ------------------------------

		// 	// // executeTE() START ------------------------------

		// Total number of VMs for TE
		auto nvmte =
				LAYER != 0 ?
						nallstubslayers[LAYER - 1] * nvmtelayers[LAYER - 1] : //Shouldn't it be LAYER!=0, and LAYER-1?
						nallstubsdisks[DISK - 1] * nvmtedisks[DISK - 1];

		stubPhi = stub.getPhi(); // Could take from ME
		iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
		iphiRaw = iphiRaw * nvmte / 32; // Which VM
		auto bend = stub.getBend();

		// TE Inner
		if (teimask != 0) {
			VMStubTEInner<INTYPE> stubTeInner;

			stubTeInner.setBend(bend);
			stubTeInner.setIndex(typename VMStubTEInner<METYPE>::VMSTEIID(i));
			ap_uint<11> binlookup; // make it nicer
			// LAYER
			if (LAYER != 0) {
				auto nphireg = 5; // Number of bits for VMs? Number of phi regions?
				if (LAYER == 3)
					nphireg = 4;
				if (LAYER == 5)
					nphireg = 4;
				auto nfinephi = nfinephibarrelinner; // Number of bits for finephi?
				auto z = stub.getZ();
				auto r = stub.getR();
				int zbins = (1 << 7); // 7 = zbits
				int rbins = (1 << 4); // Number of bins in r
				int zbin = (z + (1 << (z.length() - 1))) >> (z.length() - 7); // Make z positive and take the 5 MSBs TODO replace 7
				int rbin = (r + (1 << (r.length() - 1))) >> (r.length() - 4); // What is this doing... r already positive?! 4 MSBs??

				int index = zbin * rbins + rbin; // number of bins

				binlookup = binlookuptable[index];
				std::cout << "INDEX: " << index << "    binlookup: " << binlookup <<std::endl;

				stubTeInner.setZBits(binlookup);
				stubTeInner.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi)); // is this the right nphireg
			} else { // DISKS
				assert(DISK != 0);

				auto nphireg = 4; // Number of bits for VMs? Number of phi regions?
				auto nfinephi = nfinephidiskinner; // Number of bits for finephi?
				auto r = stub.getZ();
				auto nrbits = stubTeInner.getZBits().length();

				stubTeInner.setZBits(r >> (r.length() - nrbits)); // Maybe change so that we don't call getZ etc so many times? Remove hardcoded value
				stubTeInner.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi)); // is this the right nphireg
			}

			std::cout << "TEInner stub " << std::hex << stubTeInner.raw()
					<< std::endl;
			std::cout << "iphiRaw: " << std::dec << iphiRaw <<std::endl
					<< std::endl;
			// No coarse phi bins? Aaaah probably yes, since they correspond to the different VMs?
			bool passbend = bendtable[bend];
			if (binlookup <= 1008 && passbend) {
			// Save stub to memories
			// 0-9
			if (teimask[0]) {
				if (iphiRaw == 0) {
					mtei0->write_mem(bx, stubTeInner, addrCount[0]);
					addrCount[0] += 1;
				}
			}
			if (teimask[1]) {
				if (iphiRaw == 1) {
					mtei1->write_mem(bx, stubTeInner, addrCount[1]);
					addrCount[1] += 1;
				}
			}
			if (teimask[2]) {
				if (iphiRaw == 2) {
					mtei2->write_mem(bx, stubTeInner, addrCount[2]);
					addrCount[2] += 1;
				}
			}
			if (teimask[3]) {
				if (iphiRaw == 3) {
					mtei3->write_mem(bx, stubTeInner, addrCount[3]);
					addrCount[3] += 1;
				}
			}
			if (teimask[4]) {
				if (iphiRaw == 4) {
					mtei4->write_mem(bx, stubTeInner, addrCount[4]);
					addrCount[4] += 1;
				}
			}
			if (teimask[5]) {
				if (iphiRaw == 5) {
					mtei5->write_mem(bx, stubTeInner, addrCount[5]);
					addrCount[5] += 1;
				}
			}
			if (teimask[6]) {
				if (iphiRaw == 6) {
					mtei6->write_mem(bx, stubTeInner, addrCount[6]);
					addrCount[6] += 1;
				}
			}
			if (teimask[7]) {
				if (iphiRaw == 7) {
					mtei7->write_mem(bx, stubTeInner, addrCount[7]);
					addrCount[7] += 1;
				}
			}
			if (teimask[8]) {
				if (iphiRaw == 8) {
					mtei8->write_mem(bx, stubTeInner, addrCount[8]);
					addrCount[8] += 1;
				}
			}
			if (teimask[9]) {
				if (iphiRaw == 9) {
					mtei9->write_mem(bx, stubTeInner, addrCount[9]);
					addrCount[9] += 1;
				}
			}
			// 10-19
			if (teimask[10]) {
				if (iphiRaw == 10) {
					mtei10->write_mem(bx, stubTeInner, addrCount[10]);
					addrCount[10] += 1;
				}
			}
			if (teimask[11]) {
				if (iphiRaw == 11) {
					mtei11->write_mem(bx, stubTeInner, addrCount[11]);
					addrCount[11] += 1;
				}
			}
			if (teimask[12]) {
				if (iphiRaw == 12) {
					mtei12->write_mem(bx, stubTeInner, addrCount[12]);
					addrCount[12] += 1;
				}
			}
			if (teimask[13]) {
				if (iphiRaw == 13) {
					mtei13->write_mem(bx, stubTeInner, addrCount[13]);
				addrCount[13] += 1;
				}
			}
			if (teimask[14]) {
				if (iphiRaw == 14) {
					mtei14->write_mem(bx, stubTeInner, addrCount[14]);
					addrCount[14] += 1;
				}
			}
			if (teimask[15]) {
				if (iphiRaw == 15) {
					mtei15->write_mem(bx, stubTeInner, addrCount[15]);
					addrCount[15] += 1;
				}
			}
			if (teimask[16]) {
				if (iphiRaw == 16) {
					mtei16->write_mem(bx, stubTeInner, addrCount[16]);
					addrCount[16] += 1;
				}
				}
			if (teimask[17]) {
				if (iphiRaw == 17) {
					mtei17->write_mem(bx, stubTeInner, addrCount[17]);
					addrCount[17] += 1;
				}
			}
			if (teimask[18]) {
				if (iphiRaw == 18) {
					mtei18->write_mem(bx, stubTeInner, addrCount[18]);
					addrCount[18] += 1;
				}
			}
			if (teimask[19]) {
				if (iphiRaw == 19) {
					mtei19->write_mem(bx, stubTeInner, addrCount[19]);
					addrCount[19] += 1;
				}
			}
			// 20-29
			if (teimask[20]) {
				if (iphiRaw == 20) {
					mtei20->write_mem(bx, stubTeInner, addrCount[20]);
					addrCount[20] += 1;
				}
			}
			if (teimask[21]) {
				if (iphiRaw == 21) {
					mtei21->write_mem(bx, stubTeInner, addrCount[21]);
					addrCount[21] += 1;
				}
			}
			if (teimask[22]) {
				if (iphiRaw == 22) {
					mtei22->write_mem(bx, stubTeInner, addrCount[22]);
					addrCount[22] += 1;
				}
			}
			if (teimask[23]) {
				if (iphiRaw == 23) {
					mtei23->write_mem(bx, stubTeInner, addrCount[23]);
					addrCount[23] += 1;
				}
			}
			if (teimask[24]) {
				if (iphiRaw == 24) {
					mtei24->write_mem(bx, stubTeInner, addrCount[24]);
					addrCount[24] += 1;
				}
			}
			if (teimask[25]) {
				if (iphiRaw == 25) {
					mtei25->write_mem(bx, stubTeInner, addrCount[25]);
				addrCount[25] += 1;
			}
			}
			if (teimask[26]) {
				if (iphiRaw == 26) {
					mtei26->write_mem(bx, stubTeInner, addrCount[26]);
					addrCount[26] += 1;
				}
			}
			if (teimask[27]) {
				if (iphiRaw == 27) {
					mtei27->write_mem(bx, stubTeInner, addrCount[27]);
				addrCount[27] += 1;
				}
			}
			if (teimask[28]) {
				if (iphiRaw == 28) {
					mtei28->write_mem(bx, stubTeInner, addrCount[28]);
				addrCount[28] += 1;
				}
			}
			if (teimask[29]) {
				if (iphiRaw == 29) {
					mtei29->write_mem(bx, stubTeInner, addrCount[29]);
					addrCount[29] += 1;
				}
			}
			// 30-31
			if (teimask[30]) {
				if (iphiRaw == 30) {
					mtei30->write_mem(bx, stubTeInner, addrCount[30]);
					addrCount[30] += 1;
				}
			}
			if (teimask[31]) {
				if (iphiRaw == 31) {
					mtei31->write_mem(bx, stubTeInner, addrCount[31]);
					addrCount[31] += 1;
				}
			}
		}
		}

		//  OVERLAP
		if (olmask != 0) {//(LAYER == 1  || LAYER == 2) { // Make sure that only layer 1 and 2 are overlapped
			assert(LAYER == 1 || LAYER == 2);
			auto z = stub.getZ();
			auto r = stub.getR();
			int zbin = (z + (1 << (z.length() - 1))) >> (z.length() - 7); // Make z positive and take the 5 MSBs
			int rbin = (r + (1 << (r.length() - 1))) >> (r.length() - 3); // What is this doing... r already positive?! 4 MSBs??
			int index = zbin * rbin + rbin;
			//ap_int<10> overlap = overlaptable[index];
			int overlap = overlaptable[index];
			if (overlap != 1023) { // which is like -1 if we had signed stuff?
				VMStubTEInner<BARRELOL> stubOL;
				auto nvmol = nallstubslayers[LAYER] * 2; // Always 2 overlap vms?
				// 16 overlap vms per layer
				stubPhi = stub.getPhi(); // Could take from ME
				iphiRaw = iphivmRaw<INTYPE>(stubPhi) >> 1; // Top 4 bits of phi, NEED iphivmraw THAT RETURNS THE TOP 4?! CHECK THIS
				iphiRaw = iphiRaw * nvmol / 16; // Which VM, BECAUSE WE HAVE 16 VMS?

				auto nzbits = stubOL.getZBits().length();
				auto nphireg = 4; // What is this still
				auto nfinephi = 1; // or nfinephioverlapinner??? which is 2

				stubOL.setBend(bend);  //move so we don't call it all the time
				stubOL.setIndex(typename VMStubTEInner<BARRELOL>::VMSTEIID(i));
				stubOL.setZBits(z >> (z.length() - nzbits)); // Maybe change so that we don't call getZ etc so many times? Manipulate bits?
				stubOL.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi)); // is this the right nphireg

				std::cout << "Overlap stub " << overlap << " " << std::hex
						<< stubOL.raw() << std::endl;
				std::cout << "iphiRaw: " << std::dec << iphiRaw << std::endl
						<< std::endl;
				// No coarse phi bins? Aaaah probably yes, since they correspond to the different VMs?

				// Save stub to memories
				// 0-9
				if (olmask[0]) {
					if ((iphiRaw == 0) || (iphiRawMinus == 0)
							|| (iphiRawPlus == 0))
						mteol0->write_mem(bx, stubOL, addrCountOL[0]);
					addrCountOL[0] += 1;
				}
				if (olmask[1]) {
					if ((iphiRaw == 1) || (iphiRawMinus == 1)
							|| (iphiRawPlus == 1))
						mteol1->write_mem(bx, stubOL, addrCountOL[1]);
					addrCountOL[1] += 1;
				}
				if (olmask[2]) {
					if (iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2)
						mteol2->write_mem(bx, stubOL, addrCountOL[2]);
					addrCountOL[2] += 1;
				}
				if (olmask[3]) {
					if (iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3)
						mteol3->write_mem(bx, stubOL, addrCountOL[3]);
					addrCountOL[3] += 1;
				}
				if (olmask[4]) {
					if (iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4)
						mteol4->write_mem(bx, stubOL, addrCountOL[4]);
					addrCountOL[4] += 1;
				}
				if (olmask[5]) {
					if (iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5)
						mteol5->write_mem(bx, stubOL, addrCountOL[5]);
					addrCountOL[5] += 1;
				}
				if (olmask[6]) {
					if (iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6)
						mteol6->write_mem(bx, stubOL, addrCountOL[6]);
					addrCountOL[6] += 1;
				}
				if (olmask[7]) {
					if (iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7)
						mteol7->write_mem(bx, stubOL, addrCountOL[7]);
					addrCountOL[7] += 1;
				}
				if (olmask[8]) {
					if (iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8)
						mteol8->write_mem(bx, stubOL, addrCountOL[8]);
					addrCountOL[8] += 1;
				}
				if (olmask[9]) {
					if (iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9)
						mteol9->write_mem(bx, stubOL, addrCountOL[9]);
					addrCountOL[9] += 1;
				}
				// 10-19
				if (olmask[10]) {
					if ((iphiRaw == 10) || (iphiRawMinus == 10)
							|| (iphiRawPlus == 10))
						mteol10->write_mem(bx, stubOL, addrCountOL[10]);
					addrCountOL[10] += 1;
				}
				if (olmask[11]) {
					if ((iphiRaw == 11) || (iphiRawMinus == 11)
							|| (iphiRawPlus == 11))
						mteol11->write_mem(bx, stubOL, addrCountOL[11]);
					addrCountOL[11] += 1;
				}
				if (olmask[12]) {
					if (iphiRaw == 12 || iphiRawMinus == 12
							|| iphiRawPlus == 12)
						mteol12->write_mem(bx, stubOL, addrCountOL[12]);
					addrCountOL[12] += 1;
				}
				if (olmask[13]) {
					if (iphiRaw == 13 || iphiRawMinus == 13
							|| iphiRawPlus == 13)
						mteol13->write_mem(bx, stubOL, addrCountOL[13]);
					addrCountOL[13] += 1;
				}
				if (olmask[14]) {
					if (iphiRaw == 14 || iphiRawMinus == 14
							|| iphiRawPlus == 14)
						mteol14->write_mem(bx, stubOL, addrCountOL[14]);
					addrCountOL[14] += 1;
				}
				if (olmask[15]) {
					if (iphiRaw == 15 || iphiRawMinus == 15
							|| iphiRawPlus == 15)
						mteol15->write_mem(bx, stubOL, addrCountOL[15]);
					addrCountOL[15] += 1;
				}
			} else {
				std::cout << "NO OVERLAP" << std::endl << std::endl;
			}
		}

		// TE Outer
		if (teomask != 0) {
			VMStubTEOuter<INTYPE> stubTeOuter;

			stubTeOuter.setBend(bend);
			stubTeOuter.setIndex(typename VMStubTEOuter<METYPE>::VMSTEOID(i));

			ap_uint<TEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

			// LAYER
			if (LAYER != 0) {
				auto nphireg = 4;
				auto nfinephi = 3; //nfinephibarrelouter; // Number of bits for finephi?
				auto z = stub.getZ();

				// stubTeOuter.setFineR(); can I use finebintable?
				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi)); // is this the right nphireg

				// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
				bin = (z >> (z.length() - TEBinsBits))
						+ (1 << (TEBinsBits - 1)); // Coarse z value

				// Ignoring the sign (MSB): the top 7 MSBs of z. Note: not the index that is being saved to the stub
				typename VMStubTEOuter<METYPE>::VMSTEOID index = (z
						>> (z.length() - nbitsfinebintable))
						& ((1 << nbitsfinebintable) - 1);
				// Set zfine: the z position within a bin
				typename VMStubTEOuter<METYPE>::VMSTEOFINEZ zfine =
						finebintable[index]; // Using the bits 5 down to 2?
				stubme.setFineZ(zfine);
			} else { // DISKS
				assert(DISK != 0);

				auto nphireg = 4; // Number of bits for VMs? Number of phi regions?
				auto nfinephi = nfinephidiskouter; // Number of bits for finephi?
				auto r = stub.getZ();

				stubTeOuter.setFinePhi(
						iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi)); // is this the right nphireg

				// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
				bin = (r >> (r.length() - TEBinsBits))
						+ (1 << (TEBinsBits - 1)); // Coarse r value

				// Ignoring the sign (MSB): the top 7 MSBs of r. Note, not the index that is being saved to the stub
				typename VMStubTEOuter<METYPE>::VMSTEOID index = (r
						>> (r.length() - nbitsfinebintable))
						& ((1 << nbitsfinebintable) - 1);
				// set rfine: the r position within a bin
				typename VMStubTEOuter<METYPE>::VMSTEOFINEZ rfine =
						finebintable[index]; // is it the same table as for z?
				assert(rfine >= 0);
				stubme.setFineZ(rfine);
			}

			std::cout << "TEOuter stub " << std::hex << stubTeOuter.raw()
					<< std::endl;
			std::cout << "iphiRaw: " << std::dec << iphiRaw << std::endl
					<< std::endl;
			// No coarse phi bins? Aaaah probably yes, since they correspond to the different VMs?

			// Save stub to memories
			// 0-9
			if (teomask[0]) {
				if ((iphiRaw == 0) || (iphiRawMinus == 0) || (iphiRawPlus == 0))
					mteo0->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[1]) {
				if ((iphiRaw == 1) || (iphiRawMinus == 1) || (iphiRawPlus == 1))
					mteo1->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[2]) {
				if (iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2)
					mteo2->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[3]) {
				if (iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3)
					mteo3->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[4]) {
				if (iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4)
					mteo4->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[5]) {
				if (iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5)
					mteo5->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[6]) {
				if (iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6)
					mteo6->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[7]) {
				if (iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7)
					mteo7->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[8]) {
				if (iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8)
					mteo8->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[9]) {
				if (iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9)
					mteo9->write_mem(bx, bin, stubTeOuter);
			}
			// 10-19
			if (teomask[10]) {
				if ((iphiRaw == 10) || (iphiRawMinus == 10)
						|| (iphiRawPlus == 10))
					mteo10->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[11]) {
				if ((iphiRaw == 11) || (iphiRawMinus == 11)
						|| (iphiRawPlus == 11))
					mteo11->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[12]) {
				if (iphiRaw == 12 || iphiRawMinus == 12 || iphiRawPlus == 12)
					mteo12->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[13]) {
				if (iphiRaw == 13 || iphiRawMinus == 13 || iphiRawPlus == 13)
					mteo13->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[14]) {
				if (iphiRaw == 14 || iphiRawMinus == 14 || iphiRawPlus == 14)
					mteo14->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[15]) {
				if (iphiRaw == 15 || iphiRawMinus == 15 || iphiRawPlus == 15)
					mteo15->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[16]) {
				if (iphiRaw == 16 || iphiRawMinus == 16 || iphiRawPlus == 16)
					mteo16->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[17]) {
				if (iphiRaw == 17 || iphiRawMinus == 17 || iphiRawPlus == 17)
					mteo17->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[18]) {
				if (iphiRaw == 18 || iphiRawMinus == 18 || iphiRawPlus == 18)
					mteo18->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[19]) {
				if (iphiRaw == 19 || iphiRawMinus == 19 || iphiRawPlus == 19)
					mteo19->write_mem(bx, bin, stubTeOuter);
			}
			// 20-29
			if (teomask[20]) {
				if ((iphiRaw == 20) || (iphiRawMinus == 20)
						|| (iphiRawPlus == 20))
					mteo20->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[21]) {
				if ((iphiRaw == 21) || (iphiRawMinus == 21)
						|| (iphiRawPlus == 21))
					mteo21->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[22]) {
				if (iphiRaw == 22 || iphiRawMinus == 22 || iphiRawPlus == 22)
					mteo22->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[23]) {
				if (iphiRaw == 23 || iphiRawMinus == 23 || iphiRawPlus == 23)
					mteo23->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[24]) {
				if (iphiRaw == 24 || iphiRawMinus == 24 || iphiRawPlus == 24)
					mteo24->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[25]) {
				if (iphiRaw == 25 || iphiRawMinus == 25 || iphiRawPlus == 25)
					mteo25->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[26]) {
				if (iphiRaw == 26 || iphiRawMinus == 26 || iphiRawPlus == 26)
					mteo26->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[27]) {
				if (iphiRaw == 27 || iphiRawMinus == 27 || iphiRawPlus == 27)
					mteo27->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[28]) {
				if (iphiRaw == 28 || iphiRawMinus == 28 || iphiRawPlus == 28)
					mteo28->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[29]) {
				if (iphiRaw == 29 || iphiRawMinus == 29 || iphiRawPlus == 29)
					mteo29->write_mem(bx, bin, stubTeOuter);
			}
			// 30-31
			if (teomask[30]) {
				if ((iphiRaw == 30) || (iphiRawMinus == 30)
						|| (iphiRawPlus == 30))
					mteo30->write_mem(bx, bin, stubTeOuter);
			}
			if (teomask[31]) {
				if ((iphiRaw == 31) || (iphiRawMinus == 31)
						|| (iphiRawPlus == 31))
					mteo31->write_mem(bx, bin, stubTeOuter);
			}
		}

		// // executeTE() END   ------------------------------

	} // outside loop

	// Double check number of entries in TE Inner Mem
	std::cout << "HOW MANY IN EACH TEI MEM: ";
	for (int j = 0; j < 32; j++) {
		std::cout << addrCount[j] << " ";
	}
	std::cout << std::endl;

} // VMRouter

#endif //VMROUTER_HH
