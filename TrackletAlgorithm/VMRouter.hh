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

constexpr double rmaxdisk           = 120.0;
constexpr int    nrbitsdisk         = 12;
constexpr double kr                 = rmaxdisk/(1<<nrbitsdisk);

// from FPGAConstants.hh -- needs a final home
constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmtelayers[6]={4,8,4,8,4,8};

constexpr unsigned int nallprojlayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
constexpr unsigned int nvmmedisks[5]={4,4,4,4,4};

constexpr double rmindiskvm=22.5;
constexpr double rmaxdiskvm=67.0;

// ...
// need separate lookup values for inner two vs outer three disks for 2S modules
// these assume D11 geometry!
// what are these values and why is it using such an old geometry...
constexpr double rDSSinner[10] = {66.7728, 71.7967, 77.5409, 82.5584, 84.8736, 89.8953, 95.7791, 100.798, 102.495, 107.52};  // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = {65.1694, 70.1936, 75.6641, 80.6908, 83.9581, 88.9827, 94.6539, 99.6772, 102.494, 107.519}; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;

// local files
// returns top 5 bits of phi, i.e. max 31 in decimal
//template <int ASType>
inline ap_uint<5> iphivmRaw(const typename AllStub<BARRELPS>::ASPHI phi)
{
	// TODO: get rid of hard-coded values
	ap_uint<5> iphivm=phi.range(phi.length()-1,phi.length()-5);
	return iphivm;
}

// VMbits is the number of bits for the fine bins.
// E.g. 32 bins would use VMbits=5
// finebits is the number of bits within the VM
inline int iphivmFineBins(const AllStub<BARRELPS>::ASPHI phi, const int VMbits,
	const int finebits)
	{
		auto length= phi.length() - VMbits - finebits;
		//    return ap_uint<5>.range(phi.length()-length, phi.length()-1);
		auto v1 = ap_uint<5>(phi.range(phi.length()-1, phi.length()-length));
		auto v2 = (phi>>(phi.length()-VMbits-finebits))&((1<<finebits)-1);
		assert(v1 == v2);
		return (phi>>(phi.length()-VMbits-finebits))&((1<<finebits)-1);;
	}


	// Returns a number from 0 to 31. for both the plus and the minus:
	// we add a small amount to the raw value; if it's not the same
	// as the central value we copy the data to the adjacent memory as well.
	inline
	ap_uint<5> iphivmRawPlus(const AllStub<BARRELPS>::ASPHI phi)
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
	inline
	ap_uint<5> iphivmRawMinus(const AllStub<BARRELPS>::ASPHI phi)
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
	template <int ASType>
	inline void VMRouter(
		const int layer, const int disk, const bool isPSmodule,
		const BXType bx,
		const InputStubMemory<ASType>* const i0,
		const InputStubMemory<ASType>* const i1,
		const InputStubMemory<ASType>* const i2,
		const InputStubMemory<ASType>* const i3,
		const InputStubMemory<ASType>* const i4,
		AllStubMemory<ASType>* allstub,
		ap_uint<32> memask,
		VMStubMEMemory<BARRELPS> *m0,
		VMStubMEMemory<BARRELPS> *m1,
		VMStubMEMemory<BARRELPS> *m2,
		VMStubMEMemory<BARRELPS> *m3,
		VMStubMEMemory<BARRELPS> *m4,
		VMStubMEMemory<BARRELPS> *m5,
		VMStubMEMemory<BARRELPS> *m6,
		VMStubMEMemory<BARRELPS> *m7,
		VMStubMEMemory<BARRELPS> *m8,
		VMStubMEMemory<BARRELPS> *m9,
		VMStubMEMemory<BARRELPS> *m10,
		VMStubMEMemory<BARRELPS> *m11,
		VMStubMEMemory<BARRELPS> *m12,
		VMStubMEMemory<BARRELPS> *m13,
		VMStubMEMemory<BARRELPS> *m14,
		VMStubMEMemory<BARRELPS> *m15,
		VMStubMEMemory<BARRELPS> *m16,
		VMStubMEMemory<BARRELPS> *m17,
		VMStubMEMemory<BARRELPS> *m18,
		VMStubMEMemory<BARRELPS> *m19,
		VMStubMEMemory<BARRELPS> *m20,
		VMStubMEMemory<BARRELPS> *m21,
		VMStubMEMemory<BARRELPS> *m22,
		VMStubMEMemory<BARRELPS> *m23,
		VMStubMEMemory<BARRELPS> *m24,
		VMStubMEMemory<BARRELPS> *m25,
		VMStubMEMemory<BARRELPS> *m26,
		VMStubMEMemory<BARRELPS> *m27,
		VMStubMEMemory<BARRELPS> *m28,
		VMStubMEMemory<BARRELPS> *m29,
		VMStubMEMemory<BARRELPS> *m30,
		VMStubMEMemory<BARRELPS> *m31)
		{

			static int nbitsfinebintable_ = 8; // this appears to always be 8
			static const  int finebintable_[kMaxFineBinTable] =  // lookup table - 2^nbinsfinbinetable entries actually filled
			#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.txt"
			;
			//std::cout << std::hex << memask << std::endl;
			// reset address counters in output memories
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


			// Number of data in each input memory
			typename InputStubMemory<ASType>::NEntryT zero(0);

			auto n_i0 =            i0->getEntries(bx);
			auto n_i1 =            i1->getEntries(bx);
			auto n_i2 =            i2->getEntries(bx);
			auto n_i3 =  zero;//          i3->getEntries(bx);
			auto n_i4 =  zero;//          i4->getEntries(bx);
			// auto n_i0 = i0==0?zero:i0->getEntries(bx);
			// auto n_i1 = i1==0?zero:i1->getEntries(bx);
			// auto n_i2 = i2==0?zero:i2->getEntries(bx);
			// auto n_i3 = i3==0?zero:i3->getEntries(bx);
			// auto n_i4 = i4==0?zero:i4->getEntries(bx);
			// need to figure out how to get the accurate total count of loop
			// iterations here for nested loops. Count in innermost loop?

			ap_uint<kNBits_MemAddr> read_addr(0); // Determines which memory address to be read


			TOPLEVEL: for(auto i = 0; i < kMaxProc; ++i ) {
				#pragma HLS PIPELINE II=1
				const bool haveData = (n_i0>0)||(n_i1>0)||(n_i2>0)||(n_i3>0)||(n_i4>0);

				if ((i > MAXVMROUTER) || !haveData )
				continue;
				//const InputStubMemory *next; // this method makes vivado crash
				bool resetNext = false;
				InputStub<ASType> stub;

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
				else  { // if ( n_i4 )
					//next = i4;
					stub = i4->read_mem(bx, read_addr);
					--n_i4;
					if ( n_i4 == 0 )
					resetNext = true;
				}

				//auto stub=next->read_mem(bx, read_addr); // this caused vivado to crash

				// Increment the read address, or reset it to zero
				if ( resetNext )
				read_addr = 0;
				else
				++read_addr;

				// add stub to AllStub memory (memories?)
				// HACK fix me
				AllStub<ASType> allstubd(stub.raw());
				std::cout << "Out put stub: " << std::hex << allstubd.raw()
				<< std::dec << std::endl;
				// END HACK
				allstub->write_mem(bx, allstubd, i);

				// executeME() START ------------------------------
				// hourglass only
				VMStubME<BARRELPS> stubme;
				stubme.setBend(stub.getBend()); stubme.setIndex(VMStubME<BARRELPS>::VMSMEID(i));

				//WHY ARE THESE HACKS? THEY ARE NOT NEEDED
				//auto layer_ = layer; // hack.
				//auto disk_  = disk; // hack --these are mutually exclusive so ...

				// Total number of VMs
				auto nvm = layer!=-1 ? nallstubslayers[layer]*nvmmelayers[layer] :
				nallstubsdisks[disk-1]*nvmmedisks[disk-1];

				auto stubPhi = stub.getPhi();
				auto iphiRaw = iphivmRaw(stubPhi);
				auto iphiRawPlus = iphivmRawPlus(stubPhi);
				auto iphiRawMinus = iphivmRawMinus(stubPhi);
				auto d = nvm/32; // Some sort of normalisation thing as iphivmRaw returns at most 31... shouldn't one divide by 31 then...
				// TODO: comment this
				iphiRaw = iphiRaw*d;
				iphiRawPlus = iphiRawPlus*d;
				iphiRawMinus = iphiRawMinus*d;
				if (iphiRawPlus >= nvm) iphiRawPlus = nvm-1;
				if (iphiRawMinus >= nvm) iphiRawMinus = nvm-1;
				// if (! (std::abs(iphiRaw-iphiRawPlus) <= 1 )) {
				//   std::cout << "XXX+: " << iphiRaw << " " << iphiRawPlus << std::endl;
				// }
				assert(std::abs(iphiRaw-iphiRawPlus) <= 1 );
				assert(std::abs(iphiRaw-iphiRawMinus) <= 1 ) ;

				if ( disk ) { // Not implemented
					assert(1==0);
					VMStubME<BARRELPS>::VMSMEID index=stub.getR();
					// how to check this?
					if (isPSmodule) {
						index=stub.getR()>>(stub.getR().length()-nbitsfinebintable_);
					}

					auto rfine=finebintable_[index.to_int()];

					//assert(rfine>=0);
					//stubme.setFineR(rfine); not yet
				}
				else { // layer
					VMStubME<BARRELPS>::VMSMEID index = (stub.getZ()>>(stub.getZ().length()-nbitsfinebintable_))&((1<<nbitsfinebintable_)-1);
					// WHAT IS INDEX
					VMStubME<BARRELPS>::VMSMEFINEZ zfine = finebintable_[index.to_int()];

					stubme.setFineZ(zfine); //WHY does it save a number between 0 and 7, but we want stubme to have 4 bit precision

					#ifndef __SYNTHESIS__
					std::cout << "      index: " << index << "      zfine: " << zfine << std::endl;
					#endif
				}
				// put in a bunch of enables to decide which memories to write
				// to.

				// now actually update the stubs in the new memories
				// based on the Verilog version by MEZ
				ap_uint<MEBinsBits> bin;
				if ( ! disk ) { // barrel
					auto z = stub.getZ();
					bin = (1<<(MEBinsBits-1)) + (z>>(z.length()-MEBinsBits));
				}
				else { // disk
					assert(1==0);
				}

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
				// 0-9
				if ( (iphiRaw == 0) || (iphiRawMinus == 0) || (iphiRawPlus == 0) ) {
					if ( memask[0] )
					m0->write_mem(bx, bin, stubme);
				}
				if ( (iphiRaw == 1) || (iphiRawMinus == 1) || (iphiRawPlus == 1) ) {
					if ( memask[1] )
					m1->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2 ) {
					if ( memask[2] )
					m2->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3 ) {
					if ( memask[3] )
					m3->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4 ) {
					if ( memask[4] )
					m4->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5 ) {
					if ( memask[5] )
					m5->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6 ) {
					if ( memask[6] )
					m6->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7 ) {
					if ( memask[7] )
					m7->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8 ) {
					if ( memask[8] )
					m8->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9 ) {
					if ( memask[9] )
					m9->write_mem(bx, bin, stubme);
				}
				// 10-19
				if ( (iphiRaw == 10) || (iphiRawMinus == 10) || (iphiRawPlus == 10) ) {
					if ( memask[10] )
					m10->write_mem(bx, bin, stubme);
				}
				if ( (iphiRaw == 11) || (iphiRawMinus == 11) || (iphiRawPlus == 11) ) {
					if ( memask[11] )
					m11->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 12 || iphiRawMinus == 12 || iphiRawPlus == 12 ) {
					if ( memask[12] )
					m12->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 13 || iphiRawMinus == 13 || iphiRawPlus == 13 ) {
					if ( memask[13] )
					m13->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 14 || iphiRawMinus == 14 || iphiRawPlus == 14 ) {
					if ( memask[14] )
					m14->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 15 || iphiRawMinus == 15 || iphiRawPlus == 15 ) {
					if ( memask[15] )
					m15->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 16 || iphiRawMinus == 16 || iphiRawPlus == 16 ) {
					if ( memask[16] )
					m16->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 17 || iphiRawMinus == 17 || iphiRawPlus == 17 ) {
					if ( memask[17] )
					m17->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 18 || iphiRawMinus == 18 || iphiRawPlus == 18 ) {
					if ( memask[18] )
					m18->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 19 || iphiRawMinus == 19 || iphiRawPlus == 19 ) {
					if ( memask[19] )
					m19->write_mem(bx, bin, stubme);
				}
				// 20-29
				if ( (iphiRaw == 20) || (iphiRawMinus == 20) || (iphiRawPlus == 20) ) {
					if ( memask[20] )
					m20->write_mem(bx, bin, stubme);
				}
				if ( (iphiRaw == 21) || (iphiRawMinus == 21) || (iphiRawPlus == 21) ) {
					if ( memask[21] )
					m21->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 22 || iphiRawMinus == 22 || iphiRawPlus == 22 ) {
					if ( memask[22] )
					m22->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 23 || iphiRawMinus == 23 || iphiRawPlus == 23 ) {
					if ( memask[23] )
					m23->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 24 || iphiRawMinus == 24 || iphiRawPlus == 24 ) {
					if ( memask[24] )
					m24->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 25 || iphiRawMinus == 25 || iphiRawPlus == 25 ) {
					if ( memask[25] )
					m25->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 26 || iphiRawMinus == 26 || iphiRawPlus == 26 ) {
					if ( memask[26] )
					m26->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 27 || iphiRawMinus == 27 || iphiRawPlus == 27 ) {
					if ( memask[27] )
					m27->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 28 || iphiRawMinus == 28 || iphiRawPlus == 28 ) {
					if ( memask[28] )
					m28->write_mem(bx, bin, stubme);
				}
				if ( iphiRaw == 29 || iphiRawMinus == 29 || iphiRawPlus == 29 ) {
					if ( memask[29] )
					m29->write_mem(bx, bin, stubme);
				}
				// 30-31
				if ( (iphiRaw == 30) || (iphiRawMinus == 30) || (iphiRawPlus == 30) ) {
					if ( memask[30] )
					m30->write_mem(bx, bin, stubme);
				}
				if ( (iphiRaw == 31) || (iphiRawMinus == 31) || (iphiRawPlus == 31) ) {
					if ( memask[31] )
					m31->write_mem(bx, bin, stubme);
				}
				// executeME() END   ------------------------------

				// executeTE() START ------------------------------
				// BARREL -- LAYER
				if ( layer != -1 ) {
					// INNER OVERLAP
					// not yet

					// layer non-overlap
					if ( layer == 1 || layer == 3 || layer == 5 ) {
						// INNER regular
						VMStubTEInner<BARRELPS> stubTeInner;
					}
					else { // layers 2, 4 and 6
						// OUTER
						VMStubTEOuter<BARRELPS> stubTeOuter;

					}
				}
				// DISK
				else if ( disk != 0 ) {
					assert(1==0); // not yet
				}
				// executeTE() END   ------------------------------


				#ifdef NOTDEF
				if (disk!=5) {
					executeTE(false); // TEOuter -- no overlap
				}
				if (layer==1||layer==2||disk==1) {
					executeTE(true); // TEInner -- overlap
				}
				#endif //
			} // outside loop



		} // VMRouter

		#endif //VMROUTER_HH
