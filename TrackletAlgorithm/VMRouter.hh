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
//#include "MatchCalculator.hh"
// from FPGAConstants.hh -- needs a final home

constexpr double rmaxdisk           = 120.0;
constexpr int    nrbitsdisk         = 12;
constexpr double kr                 = rmaxdisk/(1<<nrbitsdisk);

constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4}; // Number of AllStub memories, coarse phi regions, per sector
constexpr unsigned int nvmtelayers[6]={4,8,4,8,4,8};  // Number of TE VM modules per coarse phi region

constexpr unsigned int nallprojlayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
constexpr unsigned int nvmmedisks[5]={4,4,4,4,4};

constexpr unsigned int nvmtedisks[5]={4,4,4,4,4};

constexpr double rmindiskvm=22.5;
constexpr double rmaxdiskvm=67.0;

//vm stubs
static const int nfinephibarrelinner=2;
static const int nfinephibarrelouter=3;

static const int nfinephidiskinner=2; //too small!
static const int nfinephidiskouter=3;

static const int nfinephioverlapinner=2;
static const int nfinephioverlapouter=3;

// need separate lookup values for inner two vs outer three disks for 2S modules
// these assume D11 geometry!
// Encoded r values for 2S disk modules? They are not used...
constexpr double rDSSinner[10] = {66.7728, 71.7967, 77.5409, 82.5584, 84.8736, 89.8953, 95.7791, 100.798, 102.495, 107.52};  // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = {65.1694, 70.1936, 75.6641, 80.6908, 83.9581, 88.9827, 94.6539, 99.6772, 102.494, 107.519}; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;


// TODO: fix the hacky underscores; probably pass in a pointer
// since we need to have different tables for different templated
// functions
// need to ensure this is recognized as a ROM
// Used to create LUT, kept for possible use in the non-synthesis context

// void init_finebintable(const int layer, const int disk,
//   int finebintable_[kMaxFineBinTable], int & nbitsfinebintable_)
//   {
//     #ifndef __SYNTHESIS__
//     // initialize
//     for(auto i=0;i<kMaxFineBinTable;i++) {
//       finebintable_[i] = -1;
//     }
//
//     if (layer!=0) {
//       nbitsfinebintable_=8;
//       unsigned int nbins=1<<nbitsfinebintable_;
//
//
//       for(unsigned int i=0;i<nbins;i++) {
//         int ibin=(i>>(nbitsfinebintable_-3));
//
//         int zfine=(i>>(nbitsfinebintable_-6))-(ibin<<3);
//
//         //awkward bit manipulations since the index is from a signed number...
//         int index=i+(1<<(nbitsfinebintable_-1));
//
//         if (index>=(1<<nbitsfinebintable_)){
//           index-=(1<<nbitsfinebintable_);
//         }
//
//         finebintable_[index]=zfine;
//
//       }
//     }
//
//     if (disk!=0) {
//
//       nbitsfinebintable_=8;
//       unsigned int nbins=1<<nbitsfinebintable_;
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
//           rstub=kr*(i<<(nrbitsdisk-nbitsfinebintable_));
//         }
//
//         if (rstub<rmindiskvm) {
//           finebintable_[i] = -1;
//         } else {
//           int bin=8.0*(rstub-rmindiskvm)/(rmaxdisk-rmindiskvm);
//           assert(bin>=0);
//           //assert(bin<MEBinsDisks);
//           int rfine=64*((rstub-rmindiskvm)-bin*(rmaxdisk-rmindiskvm)/8.0)/(rmaxdisk-rmindiskvm);
//           finebintable_[i] = rfine;
//         }
//       }
//     }
//     #else // __SYNTHESIS__
//     int tmp[256]=
//     #include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
//
//     for (int i=0;i<256;i++){
//       finebintable_[i]=tmp[i];
//     }
//     nbitsfinebintable_ = 256;
//     #endif // __SYNTHESIS__
//   }


// local files
// returns top 5 bits of phi, i.e. max 31 in decimal
template <regionType INTYPE>
inline ap_uint<5> iphivmRaw(const typename AllStub<INTYPE>::ASPHI phi)
{
	// TODO: get rid of hard-coded values
	ap_uint<5> iphivm=phi.range(phi.length()-1,phi.length()-5);
	return iphivm;
}

// VMbits is the number of bits for the fine bins. (MEI: isn't it for the VMs?)
// E.g. 32 bins would use VMbits=5
// finebits is the number of bits within the VM
template <regionType INTYPE>
inline int iphivmFineBins(const typename AllStub<INTYPE>::ASPHI phi, const int VMbits,
	const int finebits)
	{
		auto length= phi.length() - VMbits - finebits;
		//    return ap_uint<5>.range(phi.length()-length, phi.length()-1);
		auto v1 = ap_uint<5>(phi.range(phi.length()-1, phi.length()-length));
		auto v2 = (phi>>(phi.length()-VMbits-finebits))&((1<<finebits)-1);
		//assert(v1 == v2);
		return (phi>>(phi.length()-VMbits-finebits))&((1<<finebits)-1);;
	}


	// Returns a number from 0 to 31. for both the plus and the minus:
	// we add a small amount to the raw value; if it's not the same
	// as the central value we copy the data to the adjacent memory as well.
	template <regionType INTYPE>
	inline ap_uint<5> iphivmRawPlus(const typename AllStub<INTYPE>::ASPHI phi)
	{
		// // TODO: get rid of hard-coded values
		// ap_uint<7> tmp = phi.range(phi.length()-1,phi.length()-7);
		// auto iphivmp = ++tmp;
		// return ap_uint<5>(iphivmp(2,6));
		ap_uint<7> tmp(phi.range(phi.length()-1, phi.length()-7));
		++tmp;
		ap_uint<5> plus(tmp.range(tmp.length()-1,2));
		return plus;

	}

	// see above
	template <regionType INTYPE>
	inline ap_uint<5> iphivmRawMinus(const typename AllStub<INTYPE>::ASPHI phi)
	{
		ap_uint<7> tmp(phi.range(phi.length()-1,phi.length()-7));
		auto iphivmp = --tmp;
		return ap_uint<5>(iphivmp(6,2));
		//  // TODO: get rid of hard-coded values
		//  auto iphivm=((phi-(1<<(phi.length()-7)))>>(phi.length()-5));
		//  if (iphivm<0) iphivm=0;
		//  else if (iphivm>31) iphivm=0;
		//  return ap_uint<5>(iphivm);

	}

	// Maximum number of stubs that can be processed (memory depth)
	// originally 64, but then it won't pass test bench as it contains more than 64 stubs
	constexpr int MAXVMROUTER = kMaxProc; // TODO need right symbol here

	//template <int layer, int disk, bool isPSmodule>
	template <regionType INTYPE, regionType METYPE, int LAYER, int DISK, bool PSMODULE>
	void VMRouter(const BXType bx,
		ap_uint<6> imask,
		const InputStubMemory<INTYPE>* const i0,
		const InputStubMemory<INTYPE>* const i1,
		const InputStubMemory<INTYPE>* const i2,
		const InputStubMemory<INTYPE>* const i3,
		const InputStubMemory<INTYPE>* const i4,
		const InputStubMemory<INTYPE>* const i5,
		AllStubMemory<INTYPE>* allstub,
		ap_uint<32> memask,
		VMStubMEMemory<METYPE> *m0,
		VMStubMEMemory<METYPE> *m1,
		VMStubMEMemory<METYPE> *m2,
		VMStubMEMemory<METYPE> *m3,
		VMStubMEMemory<METYPE> *m4,
		VMStubMEMemory<METYPE> *m5,
		VMStubMEMemory<METYPE> *m6,
		VMStubMEMemory<METYPE> *m7,
		VMStubMEMemory<METYPE> *m8,
		VMStubMEMemory<METYPE> *m9,
		VMStubMEMemory<METYPE> *m10,
		VMStubMEMemory<METYPE> *m11,
		VMStubMEMemory<METYPE> *m12,
		VMStubMEMemory<METYPE> *m13,
		VMStubMEMemory<METYPE> *m14,
		VMStubMEMemory<METYPE> *m15,
		VMStubMEMemory<METYPE> *m16,
		VMStubMEMemory<METYPE> *m17,
		VMStubMEMemory<METYPE> *m18,
		VMStubMEMemory<METYPE> *m19,
		VMStubMEMemory<METYPE> *m20,
		VMStubMEMemory<METYPE> *m21,
		VMStubMEMemory<METYPE> *m22,
		VMStubMEMemory<METYPE> *m23,
		VMStubMEMemory<METYPE> *m24,
		VMStubMEMemory<METYPE> *m25,
		VMStubMEMemory<METYPE> *m26,
		VMStubMEMemory<METYPE> *m27,
		VMStubMEMemory<METYPE> *m28,
		VMStubMEMemory<METYPE> *m29,
		VMStubMEMemory<METYPE> *m30,
		VMStubMEMemory<METYPE> *m31,
		// // Inner TE memories, non-overlap
		ap_uint<32> teimask,
		VMStubTEInnerMemory<METYPE> *mtei0,
		VMStubTEInnerMemory<METYPE> *mtei1,
		VMStubTEInnerMemory<METYPE> *mtei2,
		VMStubTEInnerMemory<METYPE> *mtei3,
		VMStubTEInnerMemory<METYPE> *mtei4,
		VMStubTEInnerMemory<METYPE> *mtei5,
		VMStubTEInnerMemory<METYPE> *mtei6,
		VMStubTEInnerMemory<METYPE> *mtei7,
		VMStubTEInnerMemory<METYPE> *mtei8,
		VMStubTEInnerMemory<METYPE> *mtei9,
		VMStubTEInnerMemory<METYPE> *mtei10,
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
		VMStubTEInnerMemory<METYPE> *mtei31
		// // TE Inner memories, overlap
		// VMStubTEInnerMemory<BARRELOL> *mteol0,
		// VMStubTEInnerMemory<BARRELOL> *mteol1,
		// VMStubTEInnerMemory<BARRELOL> *mteol2,
		// VMStubTEInnerMemory<BARRELOL> *mteol3,
		// VMStubTEInnerMemory<BARRELOL> *mteol4,
		// VMStubTEInnerMemory<BARRELOL> *mteol5,
		// VMStubTEInnerMemory<BARRELOL> *mteol6,
		// VMStubTEInnerMemory<BARRELOL> *mteol7,
		// VMStubTEInnerMemory<BARRELOL> *mteol8,
		// VMStubTEInnerMemory<BARRELOL> *mteol9,
		// VMStubTEInnerMemory<BARRELOL> *mteol10,
		// VMStubTEInnerMemory<BARRELOL> *mteol11,
		// VMStubTEInnerMemory<BARRELOL> *mteol12,
		// VMStubTEInnerMemory<BARRELOL> *mteol13,
		// VMStubTEInnerMemory<BARRELOL> *mteol14,
		// VMStubTEInnerMemory<BARRELOL> *mteol15,
		// VMStubTEInnerMemory<BARRELOL> *mteol16,
		// // TE Outer memories
		// VMStubTEOuterMemory<METYPE> *mteo0,
		// VMStubTEOuterMemory<METYPE> *mteo1,
		// VMStubTEOuterMemory<METYPE> *mteo2,
		// VMStubTEOuterMemory<METYPE> *mteo3,
		// VMStubTEOuterMemory<METYPE> *mteo4,
		// VMStubTEOuterMemory<METYPE> *mteo5,
		// VMStubTEOuterMemory<METYPE> *mteo6,
		// VMStubTEOuterMemory<METYPE> *mteo7,
		// VMStubTEOuterMemory<METYPE> *mteo8,
		// VMStubTEOuterMemory<METYPE> *mteo9,
		// VMStubTEOuterMemory<METYPE> *mteo10,
		// VMStubTEOuterMemory<METYPE> *mteo11,
		// VMStubTEOuterMemory<METYPE> *mteo12,
		// VMStubTEOuterMemory<METYPE> *mteo13,
		// VMStubTEOuterMemory<METYPE> *mteo14,
		// VMStubTEOuterMemory<METYPE> *mteo15,
		// VMStubTEOuterMemory<METYPE> *mteo16,
		// VMStubTEOuterMemory<METYPE> *mteo17,
		// VMStubTEOuterMemory<METYPE> *mteo18,
		// VMStubTEOuterMemory<METYPE> *mteo19,
		// VMStubTEOuterMemory<METYPE> *mteo20,
		// VMStubTEOuterMemory<METYPE> *mteo21,
		// VMStubTEOuterMemory<METYPE> *mteo22,
		// VMStubTEOuterMemory<METYPE> *mteo23,
		// VMStubTEOuterMemory<METYPE> *mteo24,
		// VMStubTEOuterMemory<METYPE> *mteo25,
		// VMStubTEOuterMemory<METYPE> *mteo26,
		// VMStubTEOuterMemory<METYPE> *mteo27,
		// VMStubTEOuterMemory<METYPE> *mteo28,
		// VMStubTEOuterMemory<METYPE> *mteo29,
		// VMStubTEOuterMemory<METYPE> *mteo30,
		// VMStubTEOuterMemory<METYPE> *mteo31
	)
		{

			// // size of array here is the max possible value
			// static int finebintable_[kMaxFineBinTable]; // lookup table - 2^nbinsfinbinetable entries actually filled
			static int nbitsfinebintable_ = 8; // this appears to always be 8. Total number of bits the finebintable_ consists of
			// static bool table_initialized = false;
			// if ( ! table_initialized ) {
			//   init_finebintable(layer,disk,finebintable_,nbitsfinebintable_);
			//   table_initialized = true;
			// }

			// lookup table - 2^nbinsfinbinetable entries actually filled
			// Table is filled with numbers between 0 and 7 (and -1): the finer region each z/r bin is divided into.
			static const int finebintable_[kMaxFineBinTable] =
			#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
			;

			// static const int finebintable_[kMaxFineBinTable] =
			// #include "../emData/VMR/VMR_D1PHIA_finebin.txt"
			// ;
			// if (DISK == 1) { // TODO make finebintable_ statis const
			// 	finebintable_[kMaxFineBinTable] =
			// 	#include "../emData/VMR/VMR_D1PHIA_finebin.txt"
			// 	;}
		// 	} else { // Layer. Note, all layers and regions seem to have the same finebintable_
		// 		static const  int finebintable_[kMaxFineBinTable] =
		// 		#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
		// 		;
		// }

			//#pragma HLS array_partition variable=finebintable_
			// Reset address counters in output memories

			for (int i = 0; i < 32; i++) {
				std::cout << memask[i];
			}
				std::cout << std::endl;

			allstub->clear(bx);

			if ( memask[0] ) m0->clear(bx);
			if ( memask[1] ) m1->clear(bx);
			if ( memask[2] ) m2->clear(bx);
			if ( memask[3] ) m3->clear(bx);
			if ( memask[4] ) m4->clear(bx);
			if ( memask[5] ) m5->clear(bx);
			if ( memask[6] ) m6->clear(bx);
			if ( memask[7] ) m7->clear(bx);
			if ( memask[8] ) m8->clear(bx);
			if ( memask[9] ) m9->clear(bx);
			if ( memask[10] ) m10->clear(bx);
			if ( memask[11] ) m11->clear(bx);
			if ( memask[12] ) m12->clear(bx);
			if ( memask[13] ) m13->clear(bx);
			if ( memask[14] ) m14->clear(bx);
			if ( memask[15] ) m15->clear(bx);
			if ( memask[16] ) m16->clear(bx);
			if ( memask[17] ) m17->clear(bx);
			if ( memask[18] ) m18->clear(bx);
			if ( memask[19] ) m19->clear(bx);
			if ( memask[20] ) m20->clear(bx);
			if ( memask[21] ) m21->clear(bx);
			if ( memask[22] ) m22->clear(bx);
			if ( memask[23] ) m23->clear(bx);
			if ( memask[24] ) m24->clear(bx);
			if ( memask[25] ) m25->clear(bx);
			if ( memask[26] ) m26->clear(bx);
			if ( memask[27] ) m27->clear(bx);
			if ( memask[28] ) m28->clear(bx);
			if ( memask[29] ) m29->clear(bx);
			if ( memask[30] ) m30->clear(bx);
			if ( memask[31] ) m31->clear(bx);

			if ( teimask[0] ) mtei0->clear(bx);
			if ( teimask[1] ) mtei1->clear(bx);
			if ( teimask[2] ) mtei2->clear(bx);
			if ( teimask[3] ) mtei3->clear(bx);
			if ( teimask[4] ) mtei4->clear(bx);
			if ( teimask[5] ) mtei5->clear(bx);
			if ( teimask[6] ) mtei6->clear(bx);
			if ( teimask[7] ) mtei7->clear(bx);
			if ( teimask[8] ) mtei8->clear(bx);
			if ( teimask[9] ) mtei9->clear(bx);
			if ( teimask[10] ) mtei10->clear(bx);
			if ( teimask[11] ) mtei11->clear(bx);
			if ( teimask[12] ) mtei12->clear(bx);
			if ( teimask[13] ) mtei13->clear(bx);
			if ( teimask[14] ) mtei14->clear(bx);
			if ( teimask[15] ) mtei15->clear(bx);
			if ( teimask[16] ) mtei16->clear(bx);
			if ( teimask[17] ) mtei17->clear(bx);
			if ( teimask[18] ) mtei18->clear(bx);
			if ( teimask[19] ) mtei19->clear(bx);
			if ( teimask[20] ) mtei20->clear(bx);
			if ( teimask[21] ) mtei21->clear(bx);
			if ( teimask[22] ) mtei22->clear(bx);
			if ( teimask[23] ) mtei23->clear(bx);
			if ( teimask[24] ) mtei24->clear(bx);
			if ( teimask[25] ) mtei25->clear(bx);
			if ( teimask[26] ) mtei26->clear(bx);
			if ( teimask[27] ) mtei27->clear(bx);
			if ( teimask[28] ) mtei28->clear(bx);
			if ( teimask[29] ) mtei29->clear(bx);
			if ( teimask[30] ) mtei30->clear(bx);
			if ( teimask[31] ) mtei31->clear(bx);

			// Number of data in each input memory
			typename InputStubMemory<INTYPE>::NEntryT zero(0);

			auto n_i0 = zero;
			auto n_i1 = zero;
			auto n_i2 = zero;
			auto n_i3 = zero;
			auto n_i4 = zero;
			auto n_i5 = zero;

			if ( imask[0] ) n_i0 = i0->getEntries(bx);
			if ( imask[1] ) n_i1 = i1->getEntries(bx);
			if ( imask[2] ) n_i2 = i2->getEntries(bx);
			if ( imask[3] ) n_i3 = i3->getEntries(bx);
			if ( imask[4] ) n_i4 = i4->getEntries(bx);
			if ( imask[5] ) n_i5 = i5->getEntries(bx);

			// need to figure out how to get the accurate total count of loop
			// iterations here for nested loops. Count in innermost loop?

			ap_uint<kNBits_MemAddr> read_addr(0); // Determines which memory address to be read
			int addrCount[32] = {0}; // Keeps track of write address

			TOPLEVEL: for(auto i = 0; i < kMaxProc; ++i ) {
				#pragma HLS PIPELINE II=1
				const bool haveData = (n_i0>0)||(n_i1>0)||(n_i2>0)||(n_i3>0)||(n_i4>0);

				// Stop processing stubs if we have looped over the maximum number
				// that can be processed or if we have gone through all data
				if ((i > MAXVMROUTER) || !haveData )
				continue;
				//const InputStubMemory *next; // this method makes vivado crash

				bool resetNext = false; // Used to reset read_addr
				InputStub<INTYPE> stub;

				// Read stub from memory in turn
				if ( n_i0 ) {
					//next = i0;
					stub = i0->read_mem(bx, read_addr);
					--n_i0;
					if ( n_i0 == 0 )
					resetNext = true;
				}
				else if ( n_i1 ) {
					//next = i1;
					stub = i1->read_mem(bx, read_addr);
					--n_i1;
					if ( n_i1 == 0 )
					resetNext = true;
				}
				else if ( n_i2 ) {
					//next = i2;
					stub = i2->read_mem(bx, read_addr);
					--n_i2;
					if ( n_i2 == 0 )
					resetNext = true;
				}
				else if ( n_i3 ) {
					//next = i3;
					stub = i3->read_mem(bx, read_addr);
					--n_i3;
					if ( n_i3 == 0 )
					resetNext = true;
				}
				else if ( n_i4 ) {
					//next = i4;
					stub = i4->read_mem(bx, read_addr);
					--n_i4;
					if ( n_i4 == 0 )
					resetNext = true;
				}
				else { // if ( n_i5 )
					//next = i5;
					stub = i5->read_mem(bx, read_addr);
					--n_i5;
					if ( n_i5 == 0 )
					resetNext = true;
				}

				//auto stub=next->read_mem(bx, read_addr); // this caused vivado to crash

				// Increment the read address, or reset it to zero when all stubs in one memory has been read
				if ( resetNext )
				read_addr = 0;
				else
				++read_addr;

				// add stub to AllStub memory (memories?)
				// HACK fix me
				AllStub<INTYPE> allstubd(stub.raw());
				std::cout << "Out put stub: " << std::hex << allstubd.raw()
				<< std::dec << std::endl;
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
				auto nvm = LAYER!=0 ? nallstubslayers[LAYER-1]*nvmmelayers[LAYER-1] :
				nallstubsdisks[DISK-1]*nvmmedisks[DISK-1];

				auto stubPhi = stub.getPhi();
				auto iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
				auto iphiRawPlus = iphivmRawPlus<INTYPE>(stubPhi); // Top 5 bits of phi after adding a small number
				auto iphiRawMinus = iphivmRawMinus<INTYPE>(stubPhi); // Top 5 bits of phi after subtracting a small number
				auto d = nvm/32; // Some sort of normalisation thing
				// TODO: comment this
				iphiRaw = iphiRaw*d; // The VM number
				iphiRawPlus = iphiRawPlus*d;
				iphiRawMinus = iphiRawMinus*d;
				if (iphiRawPlus >= nvm) iphiRawPlus = nvm-1;
				if (iphiRawMinus >= nvm) iphiRawMinus = nvm-1;
				// if (! (std::abs(iphiRaw-iphiRawPlus) <= 1 )) {
				//   std::cout << "XXX+: " << iphiRaw << " " << iphiRawPlus << std::endl;
				// }

				// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
				assert(std::abs(iphiRaw-iphiRawPlus) <= 1 );
				assert(std::abs(iphiRaw-iphiRawMinus) <= 1 ) ;

				ap_uint<MEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

				if ( DISK ) { // Not implemented
					assert(1==0);
					auto r = stub.getR();

					// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
					bin =  (r>>(r.length()-MEBinsBits)) + (1<<(MEBinsBits-1)); // Coarse r value

					// Ignoring the sign (MSB): the top 7 MSBs of r. Note, not the index that is being saved to the stub
					typename VMStubME<METYPE>::VMSMEID index = (r>>(r.length()-nbitsfinebintable_))&((1<<nbitsfinebintable_)-1);
					// set rfine: the r position within a bin
					typename VMStubME<METYPE>::VMSMEFINEZ rfine=finebintable_[index]; // is it the same table as for z?
					assert(rfine>=0);
					stubme.setFineZ(rfine);
				}
				else { // layer
					auto z = stub.getZ();

					// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
					bin =  (z>>(z.length()-MEBinsBits)) + (1<<(MEBinsBits-1)); // Coarse z value

					// Ignoring the sign (MSB): the top 7 MSBs of z. Note: not the index that is being saved to the stub
					typename VMStubME<METYPE>::VMSMEID index = (z>>(z.length()-nbitsfinebintable_))&((1<<nbitsfinebintable_)-1);
					// Set zfine: the z position within a bin
					typename VMStubME<METYPE>::VMSMEFINEZ zfine = finebintable_[index]; // Using the bits 5 down to 2?
					stubme.setFineZ(zfine);

				}
				// put in a bunch of enables to decide which memories to write
				// to.

				// now actually update the stubs in the new memories
				// based on the Verilog version by MEZ


				#ifndef __SYNTHESIS__
				std::cout << "ME stub " << std::hex << stubme.raw() << std::endl;

				std::cout << "iPhiRaw,Minus,Plus = "  << std::dec
				<< iphiRaw << " " << iphiRawMinus << " "
				<< iphiRawPlus << " "
				<< "\t0x" << std::setfill('0') << std::setw(4)
				<< std::hex << stubme.raw().to_int() << std::dec << ", to bin " << bin
				<< std::endl;
				if ( ! memask[iphiRaw] ) {
					std::cerr << "Trying to write to non-existent memory for iphiRaw = "
					<< iphiRaw << std::endl;
				}
				#endif // DEBUG

				// Maybe faster to check memask first...? Nah, seems to be the same
				// 0-9
				if ( memask[0] ) {
					if ( (iphiRaw == 0) || (iphiRawMinus == 0) || (iphiRawPlus == 0) )
					m0->write_mem(bx, bin, stubme);
				}
				if ( memask[1] ) {
					if ( (iphiRaw == 1) || (iphiRawMinus == 1) || (iphiRawPlus == 1) )
					m1->write_mem(bx, bin, stubme);
				}
				if ( memask[2] ) {
					if ( iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2 )
					m2->write_mem(bx, bin, stubme);
				}
				if ( memask[3] ) {
					if ( iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3 )
					m3->write_mem(bx, bin, stubme);
				}
				if ( memask[4] ) {
					if ( iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4 )
					m4->write_mem(bx, bin, stubme);
				}
				if ( memask[5] ) {
					if ( iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5 )
					m5->write_mem(bx, bin, stubme);
				}
				if ( memask[6] ) {
					if ( iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6 )
					m6->write_mem(bx, bin, stubme);
				}
				if ( memask[7] ) {
					if ( iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7 )
					m7->write_mem(bx, bin, stubme);
				}
				if ( memask[8] ) {
					if ( iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8 )
					m8->write_mem(bx, bin, stubme);
				}
				if ( memask[9] ) {
					if ( iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9 )
					m9->write_mem(bx, bin, stubme);
				}
				// 10-19
				if ( memask[10] ) {
					if ( (iphiRaw == 10) || (iphiRawMinus == 10) || (iphiRawPlus == 10) )
					m10->write_mem(bx, bin, stubme);
				}
				if ( memask[11] ) {
					if ( (iphiRaw == 11) || (iphiRawMinus == 11) || (iphiRawPlus == 11) )
					m11->write_mem(bx, bin, stubme);
				}
				if ( memask[12] ) {
					if ( iphiRaw == 12 || iphiRawMinus == 12 || iphiRawPlus == 12 )
					m12->write_mem(bx, bin, stubme);
				}
				if ( memask[13] ) {
					if ( iphiRaw == 13 || iphiRawMinus == 13 || iphiRawPlus == 13 )
					m13->write_mem(bx, bin, stubme);
				}
				if ( memask[14] ) {
					if ( iphiRaw == 14 || iphiRawMinus == 14 || iphiRawPlus == 14 )
					m14->write_mem(bx, bin, stubme);
				}
				if ( memask[15] ) {
					if ( iphiRaw == 15 || iphiRawMinus == 15 || iphiRawPlus == 15 )
					m15->write_mem(bx, bin, stubme);
				}
				if ( memask[16] ) {
					if ( iphiRaw == 16 || iphiRawMinus == 16 || iphiRawPlus == 16 )
					m16->write_mem(bx, bin, stubme);
				}
				if ( memask[17] ) {
					if ( iphiRaw == 17 || iphiRawMinus == 17 || iphiRawPlus == 17 )
					m17->write_mem(bx, bin, stubme);
				}
				if ( memask[18] ) {
					if ( iphiRaw == 18 || iphiRawMinus == 18 || iphiRawPlus == 18 )
					m18->write_mem(bx, bin, stubme);
				}
				if ( memask[19] ) {
					if ( iphiRaw == 19 || iphiRawMinus == 19 || iphiRawPlus == 19 )
					m19->write_mem(bx, bin, stubme);
				}
				// 20-29
				if ( memask[20] ) {
					if ( (iphiRaw == 20) || (iphiRawMinus == 20) || (iphiRawPlus == 20) )
					m20->write_mem(bx, bin, stubme);
				}
				if ( memask[21] ) {
					if ( (iphiRaw == 21) || (iphiRawMinus == 21) || (iphiRawPlus == 21) )
					m21->write_mem(bx, bin, stubme);
				}
				if ( memask[22] ) {
					if ( iphiRaw == 22 || iphiRawMinus == 22 || iphiRawPlus == 22 )
					m22->write_mem(bx, bin, stubme);
				}
				if ( memask[23] ) {
					if ( iphiRaw == 23 || iphiRawMinus == 23 || iphiRawPlus == 23 )
					m23->write_mem(bx, bin, stubme);
				}
				if ( memask[24] ) {
					if ( iphiRaw == 24 || iphiRawMinus == 24 || iphiRawPlus == 24 )
					m24->write_mem(bx, bin, stubme);
				}
				if ( memask[25] ) {
					if ( iphiRaw == 25 || iphiRawMinus == 25 || iphiRawPlus == 25 )
					m25->write_mem(bx, bin, stubme);
				}
				if ( memask[26] ) {
					if ( iphiRaw == 26 || iphiRawMinus == 26 || iphiRawPlus == 26 )
					m26->write_mem(bx, bin, stubme);
				}
				if ( memask[27] ) {
					if ( iphiRaw == 27 || iphiRawMinus == 27 || iphiRawPlus == 27 )
					m27->write_mem(bx, bin, stubme);
				}
				if ( memask[28] ) {
					if ( iphiRaw == 28 || iphiRawMinus == 28 || iphiRawPlus == 28 )
					m28->write_mem(bx, bin, stubme);
				}
				if ( memask[29] ) {
					if ( iphiRaw == 29 || iphiRawMinus == 29 || iphiRawPlus == 29 )
					m29->write_mem(bx, bin, stubme);
				}
				// 30-31
				if ( memask[30] ) {
					if ( (iphiRaw == 30) || (iphiRawMinus == 30) || (iphiRawPlus == 30) )
					m30->write_mem(bx, bin, stubme);
				}
				if ( memask[31] ) {
					if ( (iphiRaw == 31) || (iphiRawMinus == 31) || (iphiRawPlus == 31) )
					m31->write_mem(bx, bin, stubme);
				}
				// executeME() END   ------------------------------








				// // executeTE() START ------------------------------

				// Total number of VMs for TE
				auto nvmte = LAYER!=0 ? nallstubslayers[LAYER-1]*nvmtelayers[LAYER-1] : //Shouldn't it be LAYER!=0, and LAYER-1?
				nallstubsdisks[DISK-1]*nvmtedisks[DISK-1];

				stubPhi = stub.getPhi(); // Could take from ME
				iphiRaw = iphivmRaw<INTYPE>(stubPhi); // Top 5 bits of phi
				iphiRaw = iphiRaw*nvmte/32; // Which VM
				auto bend = stub.getBend();


				// BARREL -- LAYER
				if ( LAYER != 0 ) {
					// INNER OVERLAP
					// not yet

					// layer non-overlap
					if ( LAYER == 1 || LAYER == 3 || LAYER == 5 ) {
						// INNER regular
						VMStubTEInner<INTYPE> stubTeInner;

						auto nphireg = 5; // Number of bits for VMs? Number of phi regions?
						if ( LAYER==3) nphireg=4;
						if ( LAYER==5) nphireg=4;
						auto nfinephi = nfinephibarrelinner; // Number of bits for finephi?

						stubTeInner.setBend(bend);
						stubTeInner.setIndex(typename VMStubTEInner<METYPE>::VMSTEIID(i));
						stubTeInner.setZBits(stub.getZ()>>2); // Maybe change so that we don't call getZ etc so many times? Remove hardcoded value
						stubTeInner.setFinePhi(iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi));  // is this the right nphireg

						std::cout << "TEInner stub " << std::hex << stubTeInner.raw() << std::endl;
						std::cout << "iphiRaw: " << std::dec << iphiRaw << std::endl << std::endl;
						// No coarse phi bins? Aaaah probably yes, since they correspond to the different VMs?

						// Save stub to memories
						// 0-9
						if ( teimask[0] ) {
							if ( iphiRaw == 0 ) mtei0->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[1] ) {
							if ( iphiRaw == 1 ) mtei1->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[2] ) {
							if ( iphiRaw == 2 ) mtei2->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[3] ) {
							if ( iphiRaw == 3 ) mtei3->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[4] ) {
							if ( iphiRaw == 4 ) mtei4->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[5] ) {
							if ( iphiRaw == 5 ) mtei5->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[6] ) {
							if ( iphiRaw == 6 ) mtei6->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[7] ) {
							if ( iphiRaw == 7 ) mtei7->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[8] ) {
							if ( iphiRaw == 8 ) mtei8->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[9] ) {
							if ( iphiRaw == 9 ) mtei9->write_mem(bx, stubTeInner, i);
						}
						// 10-19
						if ( teimask[10] ) {
							if ( iphiRaw == 10 ) mtei10->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[11] ) {
							if ( iphiRaw == 11 ) mtei11->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[12] ) {
							if ( iphiRaw == 12 ) mtei12->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[13] ) {
							if ( iphiRaw == 13 ) mtei13->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[14] ) {
							if ( iphiRaw == 14 ) mtei14->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[15] ) {
							if ( iphiRaw == 15 ) mtei15->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[16] ) {
							if ( iphiRaw == 16 ) {
								mtei16->write_mem(bx, stubTeInner, addrCount[16]);
								addrCount[16] += 1;
							}
						}
						if ( teimask[17] ) {
							if ( iphiRaw == 17 ) {
								mtei17->write_mem(bx, stubTeInner, addrCount[17]);
								addrCount[17] += 1;
							}
						}
						if ( teimask[18] ) {
							if ( iphiRaw == 18 ) {
								mtei18->write_mem(bx, stubTeInner, addrCount[18]);
								addrCount[18] += 1;
							}
						}
						if ( teimask[19] ) {
							if ( iphiRaw == 19 ) {
								mtei19->write_mem(bx, stubTeInner, addrCount[19]);
								addrCount[19] += 1;
							}
						}
						// 20-29
						if ( teimask[20] ) {
							if ( iphiRaw == 20 ) {
								mtei20->write_mem(bx, stubTeInner, addrCount[20]);
								addrCount[20] += 1;
							}
						}
						if ( teimask[21] ) {
							if ( iphiRaw == 21 ) mtei21->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[22] ) {
							if ( iphiRaw == 22 ) mtei22->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[23] ) {
							if ( iphiRaw == 23 ) mtei23->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[24] ) {
							if ( iphiRaw == 24 ) mtei24->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[25] ) {
							if ( iphiRaw == 25 ) mtei25->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[26] ) {
							if ( iphiRaw == 26 ) mtei26->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[27] ) {
							if ( iphiRaw == 27 ) mtei27->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[28] ) {
							if ( iphiRaw == 28 ) mtei28->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[29] ) {
							if ( iphiRaw == 29 ) mtei29->write_mem(bx, stubTeInner, i);
						}
						// 30-31
						if ( teimask[30] ) {
							if ( iphiRaw == 30 ) mtei30->write_mem(bx, stubTeInner, i);
						}
						if ( teimask[31] ) {
							if ( iphiRaw == 31 ) mtei31->write_mem(bx, stubTeInner, i);
						}

					// Double check number of entries in TE Inner Mem
					std::cout << "HOW MANY IN EACH MEM: ";
					for (int j = 0; j < 32; j++) {
							std::cout << addrCount[j] << " ";
					}
					std::cout << std::endl;

						//  Overlap stuff
						auto overlap(0);

						if (overlap) {
							assert(LAYER == 1  || LAYER == 2); // Make sure that only layer 1 and 2 are overlapped

							VMStubTEInner<BARRELOL> stubTeOl;

							nphireg = 4; // What is this still
							nfinephi = 1; // or nfinephioverlapinner???

							stubTeOl.setBend(bend);  //move so we don't call it all the time
							stubTeOl.setIndex(typename VMStubTEInner<BARRELOL>::VMSTEIID(i));
							stubTeOl.setZBits(stub.getZ()); // Maybe change so that we don't call getZ etc so many times? Manipulate bits?
							stubTeOl.setFinePhi(iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi));  // is this the right nphireg
						}
					}
				}

				if ( LAYER  ==  2 || LAYER == 4 || LAYER == 6) { // layers 2, 4 and 6
						// OUTER
						VMStubTEOuter<INTYPE> stubTeOuter;

						auto nphireg = 4;  // What value...
						auto nfinephi = nfinephibarrelouter;

						stubTeOuter.setBend(bend);
						stubTeOuter.setIndex(typename VMStubTEOuter<INTYPE>::VMSTEOID(i));
						stubTeOuter.setFinePhi(iphivmFineBins<INTYPE>(stubPhi, nphireg, nfinephi));  // is this the right nphireg

						// TODO Set fine z/r, using binlookup?

						// bin lookup stuff
						auto binlookup(0);
						auto binlookupextra(-1); // -1 if no overlap
						auto overlap(0); //

						// Why are they in a weird order
						switch (LAYER) {
						case 2 : // used for both inner and outer stubs
							// binlookup=lookupOuterLayer(stub);
							// binlookupextra=lookupInnerLayer(stub);
							break;
						case 4 :
							// binlookup=lookupOuterLayer(stub);
							break;
						case 6 :
							// binlookup=lookupOuterLayer(stub);
							break;
						case 1 :
							// binlookup=lookupInnerLayer(stub);
							break;
						case 3 : // used for both inner and outer stubs
							// binlookup=lookupInnerLayer(stub);
							// binlookupextra=lookupOuterLayer(stub);
							break;
						case 5 :
							// binlookup=lookupInnerLayer(stub);
							break;
						default : assert(0);
						}

						// non overlap stuff
						auto iphiRawTmp = iphiRaw*nvm/32; // Which VM?

						// save stubs
						if (binlookup != -1) { // only time it is -1 is when we're looking at overlap and it's not in the overlap region?
							// overlap stuff
					}
				}
				// DISK
				else if ( DISK != 0 ) {
					assert(1==0); // not yet
				}




				// // executeTE() END   ------------------------------


				#ifdef NOTDEF
				if (DISK!=5) {
					executeTE(false); // TEOuter -- no overlap
				}
				if (LAYER==1||LAYER==2||DISK==1) {
					executeTE(true); // TEInner -- overlap
				}
				#endif //
			} // outside loop



		} // VMRouter


		#endif //VMROUTER_HH
