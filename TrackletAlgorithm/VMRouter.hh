// VMRouter
// Log
// -------

// First tracklet 2.0 version -- December 2018 -- wittich

#pragma once
#include "ap_int.h"

#include "Constants.hh"
#include "InputStubMemory.hh"
#include "AllStubMemory.hh"
#include "VMStubMEMemory.hh"
#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"
#include <assert.h>

// I include this to get the constants. we should figure out if this is
// the right way to go.

constexpr double rmaxdisk = 120.0;
constexpr int nrbitsdisk = 12;
constexpr double kr = rmaxdisk / (1 << nrbitsdisk);

// from FPGAConstants.hh -- needs a final home
constexpr unsigned int nallstubslayers[6] = { 8, 4, 4, 4, 4, 4 }; // Number of AllStub memories, i.e. coarse phi regions, per sector
constexpr unsigned int nvmtelayers[6] = { 4, 8, 4, 8, 4, 8 }; // Number of TE VM modules per coarse phi region

constexpr unsigned int nallprojlayers[6] = { 8, 4, 4, 4, 4, 4 };
constexpr unsigned int nvmmelayers[6] = { 4, 8, 8, 8, 8, 8 };

constexpr unsigned int nallstubsdisks[5] = { 4, 4, 4, 4, 4 };
constexpr unsigned int nvmmedisks[5] = { 4, 4, 4, 4, 4 };

constexpr unsigned int nvmtedisks[5] = { 4, 4, 4, 4, 4 };

constexpr double rmindiskvm = 22.5;
constexpr double rmaxdiskvm = 67.0;

// need separate lookup values for inner two vs outer three disks for 2S modules
// these assume D11 geometry!
// Encoded r values for 2S disk modules. The r position in the middle of each strip
constexpr double rDSSinner[10] = { 66.7728, 71.7967, 77.5409, 82.5584, 84.8736,
		89.8953, 95.7791, 100.798, 102.495, 107.52 }; // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = { 65.1694, 70.1936, 75.6641, 80.6908, 83.9581,
		88.9827, 94.6539, 99.6772, 102.494, 107.519 }; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;

// TODO: fix the hacky underscores; probably pass in a pointer
// since we need to have different tables for different templated
// functions
// need to ensure this is recognized as a ROM
// Currently not used, but should be kept for creating the finebin LUTs
inline void init_finebintable(const int layer_, const int disk_,
		int finebintable_[kMaxFineBinTable], int & nbitsfinebintable_) {
#ifndef __SYNTHESIS__
// initialize
	for (auto i = 0; i < kMaxFineBinTable; i++) {
		finebintable_[i] = -1;
	}

	if (layer_ != 0) {
		nbitsfinebintable_ = 8;
		unsigned int nbins = 1 << nbitsfinebintable_;

		for (unsigned int i = 0; i < nbins; i++) {
			int ibin = (i >> (nbitsfinebintable_ - 3));

			int zfine = (i >> (nbitsfinebintable_ - 6)) - (ibin << 3);

			//awkward bit manipulations since the index is from a signed number...
			int index = i + (1 << (nbitsfinebintable_ - 1));

			if (index >= (1 << nbitsfinebintable_)) {
				index -= (1 << nbitsfinebintable_);
			}

			finebintable_[index] = zfine;

		}
	}

	if (disk_ != 0) {

		nbitsfinebintable_ = 8;
		unsigned int nbins = 1 << nbitsfinebintable_;

		for (unsigned int i = 0; i < nbins; i++) {

			double rstub = 0.0;

			if (i < 10) {
				if (disk_ <= 2) {
					rstub = rDSSinner[i];
				} else {
					rstub = rDSSouter[i];
				}
			} else {
				rstub = kr * (i << (nrbitsdisk - nbitsfinebintable_));
			}

			if (rstub < rmindiskvm) {
				finebintable_[i] = -1;
			} else {
				int bin = 8.0 * (rstub - rmindiskvm) / (rmaxdisk - rmindiskvm);
				assert(bin >= 0);
				//assert(bin<MEBinsDisks);
				int rfine = 64
						* ((rstub - rmindiskvm)
								- bin * (rmaxdisk - rmindiskvm) / 8.0)
						/ (rmaxdisk - rmindiskvm);
				finebintable_[i] = rfine;
			}
		}
	}
#else // __SYNTHESIS__
	int tmp[256]=
#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.tab"

	for (int i=0;i<256;i++) {
		finebintable_[i]=tmp[i];
	}
	nbitsfinebintable_ = 256;
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

// VMbits is the number of bits for the fine bins.
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
	assert(v1 == v2);
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

constexpr int MAXVMROUTER = kMaxProc; // 64; // TODO need right symbol here

template<regionType INTYPE, regionType METYPE, int LAYER, int DISK, int NINPUTS,
		uint32_t MEMASK>
void VMRouter(const BXType bx,
		// Input memories
		const InputStubMemory<INTYPE>* const i0,
		const InputStubMemory<INTYPE>* const i1,
		const InputStubMemory<INTYPE>* const i2,
		const InputStubMemory<INTYPE>* const i3,
		const InputStubMemory<INTYPE>* const i4,
		const InputStubMemory<INTYPE>* const i5,
		// AllStub memory
		AllStubMemory<INTYPE>* allstub,
		// ME memories
		VMStubMEMemory<INTYPE> *m0, VMStubMEMemory<INTYPE> *m1,
		VMStubMEMemory<INTYPE> *m2, VMStubMEMemory<INTYPE> *m3,
		VMStubMEMemory<INTYPE> *m4, VMStubMEMemory<INTYPE> *m5,
		VMStubMEMemory<INTYPE> *m6, VMStubMEMemory<INTYPE> *m7,
		VMStubMEMemory<INTYPE> *m8, VMStubMEMemory<INTYPE> *m9,
		VMStubMEMemory<INTYPE> *m10, VMStubMEMemory<INTYPE> *m11,
		VMStubMEMemory<INTYPE> *m12, VMStubMEMemory<INTYPE> *m13,
		VMStubMEMemory<INTYPE> *m14, VMStubMEMemory<INTYPE> *m15,
		VMStubMEMemory<INTYPE> *m16, VMStubMEMemory<INTYPE> *m17,
		VMStubMEMemory<INTYPE> *m18, VMStubMEMemory<INTYPE> *m19,
		VMStubMEMemory<INTYPE> *m20, VMStubMEMemory<INTYPE> *m21,
		VMStubMEMemory<INTYPE> *m22, VMStubMEMemory<INTYPE> *m23,
		VMStubMEMemory<INTYPE> *m24, VMStubMEMemory<INTYPE> *m25,
		VMStubMEMemory<INTYPE> *m26, VMStubMEMemory<INTYPE> *m27,
		VMStubMEMemory<INTYPE> *m28, VMStubMEMemory<INTYPE> *m29,
		VMStubMEMemory<INTYPE> *m30, VMStubMEMemory<INTYPE> *m31) {

	static int nbitsfinebintable_ = 8; // this appears to always be 8. Total number of bits the finebintable_ consists of
// // size of array here is the max possible value
// static int finebintable_[kMaxFineBinTable]; // lookup table - 2^nbinsfinbinetable entries actually filled
// static bool table_initialized = false;
// if ( ! table_initialized ) {
//   init_finebintable(layer_,disk_,finebintable_,nbitsfinebintable_);
//   table_initialized = true;
// }
// lookup table - 2^nbinsfinbinetable entries actually filled
// Table is filled with numbers between 0 and 7 (and -1): the finer region each z/r bin is divided into.
	static const int finebintable_[kMaxFineBinTable] =
#include "../emData/VMR/VMR_L1PHIE/VMR_L1PHIE_finebin.tab"
	;

// reset address counters in output memories
	allstub->clear(bx);
// Don't understand why it did not work with MEMask of type ap_uint<32>
	if (MEMASK & 0x1)
		m0->clear(bx);
	if (MEMASK & 0x2)
		m1->clear(bx);
	if (MEMASK & 0x4)
		m2->clear(bx);
	if (MEMASK & 0x8)
		m3->clear(bx);
	if (MEMASK & 0x10)
		m4->clear(bx);
	if (MEMASK & 0x20)
		m5->clear(bx);
	if (MEMASK & 0x40)
		m6->clear(bx);
	if (MEMASK & 0x80)
		m7->clear(bx);
	if (MEMASK & 0x100)
		m8->clear(bx);
	if (MEMASK & 0x200)
		m9->clear(bx);
	if (MEMASK & 0x400)
		m10->clear(bx);
	if (MEMASK & 0x800)
		m11->clear(bx);
	if (MEMASK & 0x1000)
		m12->clear(bx);
	if (MEMASK & 0x2000)
		m13->clear(bx);
	if (MEMASK & 0x4000)
		m14->clear(bx);
	if (MEMASK & 0x8000)
		m15->clear(bx);
	if (MEMASK & 0x10000)
		m16->clear(bx);
	if (MEMASK & 0x20000)
		m17->clear(bx);
	if (MEMASK & 0x40000)
		m18->clear(bx);
	if (MEMASK & 0x80000)
		m19->clear(bx);
	if (MEMASK & 0x100000)
		m20->clear(bx);
	if (MEMASK & 0x200000)
		m21->clear(bx);
	if (MEMASK & 0x400000)
		m22->clear(bx);
	if (MEMASK & 0x800000)
		m23->clear(bx);
	if (MEMASK & 0x1000000)
		m24->clear(bx);
	if (MEMASK & 0x2000000)
		m25->clear(bx);
	if (MEMASK & 0x4000000)
		m26->clear(bx);
	if (MEMASK & 0x8000000)
		m27->clear(bx);
	if (MEMASK & 0x10000000)
		m28->clear(bx);
	if (MEMASK & 0x20000000)
		m29->clear(bx);
	if (MEMASK & 0x40000000)
		m30->clear(bx);
	if (MEMASK & 0x80000000)
		m31->clear(bx);

// Number of data in each input memory
// Maybe find a better way to do this one day
	typename InputStubMemory<INTYPE>::NEntryT zero(0);

	auto n_i0 = zero;
	auto n_i1 = zero;
	auto n_i2 = zero;
	auto n_i3 = zero;
	auto n_i4 = zero;
	auto n_i5 = zero;

	if (0 < NINPUTS)
		n_i0 = i0->getEntries(bx);
	if (1 < NINPUTS)
		n_i1 = i1->getEntries(bx);
	if (2 < NINPUTS)
		n_i2 = i2->getEntries(bx);
	if (3 < NINPUTS)
		n_i3 = i3->getEntries(bx);
	if (4 < NINPUTS)
		n_i4 = i4->getEntries(bx);
	if (5 < NINPUTS)
		n_i5 = i5->getEntries(bx);

// need to figure out how to get the accurate total count of loop
// iterations here for nested loops. Count in innermost loop?
	ap_uint<kNBits_MemAddr> read_addr(0); // Determines which memory address to be read

	TOPLEVEL: for (auto i = 0; i < kMaxProc; ++i) {
#pragma HLS PIPELINE II=1
		const bool haveData = (n_i0 > 0) || (n_i1 > 0) || (n_i2 > 0)
				|| (n_i3 > 0) || (n_i4 > 0) || (n_i5 > 0);

		// Stop processing stubs if we have looped over the maximum number
		// that can be processed or if we have gone through all data
		if ((i > MAXVMROUTER) || !haveData)
			continue;
		//const InputStubMemory *next; // this method makes vivado crash

		bool resetNext = false;
		InputStub<INTYPE> stub;

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
		} else if (n_i4) { // if ( n_i4 )
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

		// add stub to all stub memory (memories?)
		// HACK fix me. What is the hack??
		AllStub<INTYPE> allstubd(stub.raw());
		std::cout << "Out put stub: " << std::hex << allstubd.raw() << std::dec
				<< std::endl;
		// END HACK
		allstub->write_mem(bx, allstubd, i);

		///////////////////////////////////////////
		// executeME() START ------------------------------
		// hourglass only

		VMStubME<METYPE> stubme;
		stubme.setBend(stub.getBend()); // Bit size of ME the same as for Input
		stubme.setIndex(typename VMStubME<METYPE>::VMSMEID(i));

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

		iphiRaw = iphiRaw * d; // The VM number
		iphiRawPlus = iphiRawPlus * d;
		iphiRawMinus = iphiRawMinus * d;
		if (iphiRawPlus >= nvm)
			iphiRawPlus = nvm - 1;
		if (iphiRawMinus >= nvm)
			iphiRawMinus = nvm - 1;

		// Stubs can only end up in the neighbouring VM after calculating iphivmrawplus/minus
		assert(std::abs(iphiRaw - iphiRawPlus) <= 1);
		assert(std::abs(iphiRaw - iphiRawMinus) <= 1);

		ap_uint<MEBinsBits> bin; // 3 bits, i.e. max 8 bins within each VM

		if (DISK) { // NOT IMPLEMENTED YET
			assert(1 == 0);
			auto r = stub.getR();

			// Get the 3 MSBs of r and add 4 as r is signed (takes values between -4 and 3)
			bin = (r >> (r.length() - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse r value

			// Ignoring the sign (MSB): the top 7 MSBs of r. Note, not the index that is being saved to the stub
			typename VMStubME<METYPE>::VMSMEID index = (r
					>> (r.length() - nbitsfinebintable_))
					& ((1 << nbitsfinebintable_) - 1);
			// set rfine: the r position within a bin
			typename VMStubME<METYPE>::VMSMEFINEZ rfine = finebintable_[index]; // is it the same table as for z?
			assert(rfine >= 0);
			stubme.setFineZ(rfine);
		} else { // layer
			auto z = stub.getZ();

			// Get the 3 MSBs of z and add 4 as z is signed (takes values between -4 and 3)
			bin = (z >> (z.length() - MEBinsBits)) + (1 << (MEBinsBits - 1)); // Coarse z value

			// Ignoring the sign (MSB): the top 7 MSBs of z. Note: not the index that is being saved to the stub
			typename VMStubME<METYPE>::VMSMEID index = (z
					>> (z.length() - nbitsfinebintable_))
					& ((1 << nbitsfinebintable_) - 1);
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

		std::cout << "iPhiRaw,Minus,Plus = " << std::dec << iphiRaw << " "
				<< iphiRawMinus << " " << iphiRawPlus << " " << "\t0x"
				<< std::setfill('0') << std::setw(4) << std::hex
				<< stubme.raw().to_int() << std::dec << ", to bin " << bin
				<< std::endl;
		// TODO add this debug thing again, using new memask
		// if ( ! memask[iphiRaw] ) {
		//   std::cerr << "Trying to write to non-existent memory for iphiRaw = "
		// << iphiRaw << std::endl;
		// }

#endif // DEBUG
		//0-9
		if (MEMASK & 0x1) {
			if ((iphiRaw == 0) || (iphiRawMinus == 0) || (iphiRawPlus == 0))
				m0->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x2) {
			if ((iphiRaw == 1) || (iphiRawMinus == 1) || (iphiRawPlus == 1))
				m1->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x4) {
			if (iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2)
				m2->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x8) {
			if (iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3)
				m3->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x10) {
			if (iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4)
				m4->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x20) {
			if (iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5)
				m5->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x40) {
			if (iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6)
				m6->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x80) {
			if (iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7)
				m7->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x100) {
			if (iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8)
				m8->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x200) {
			if (iphiRaw == 9 || iphiRawMinus == 9 || iphiRawPlus == 9)
				m9->write_mem(bx, bin, stubme);
		}
		// 10-19
		if (MEMASK & 0x400) {
			if ((iphiRaw == 10) || (iphiRawMinus == 10) || (iphiRawPlus == 10))
				m10->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x800) {
			if ((iphiRaw == 11) || (iphiRawMinus == 11) || (iphiRawPlus == 11))
				m11->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x1000) {
			if (iphiRaw == 12 || iphiRawMinus == 12 || iphiRawPlus == 12)
				m12->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x2000) {
			if (iphiRaw == 13 || iphiRawMinus == 13 || iphiRawPlus == 13)
				m13->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x4000) {
			if (iphiRaw == 14 || iphiRawMinus == 14 || iphiRawPlus == 14)
				m14->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x8000) {
			if (iphiRaw == 15 || iphiRawMinus == 15 || iphiRawPlus == 15)
				m15->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x10000) {
			if (iphiRaw == 16 || iphiRawMinus == 16 || iphiRawPlus == 16)
				m16->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x20000) {
			if (iphiRaw == 17 || iphiRawMinus == 17 || iphiRawPlus == 17)
				m17->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x40000) {
			if (iphiRaw == 18 || iphiRawMinus == 18 || iphiRawPlus == 18)
				m18->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x80000) {
			if (iphiRaw == 19 || iphiRawMinus == 19 || iphiRawPlus == 19)
				m19->write_mem(bx, bin, stubme);
		}
		// 20-29
		if (MEMASK & 0x100000) {
			if ((iphiRaw == 20) || (iphiRawMinus == 20) || (iphiRawPlus == 20))
				m20->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x200000) {
			if ((iphiRaw == 21) || (iphiRawMinus == 21) || (iphiRawPlus == 21))
				m21->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x400000) {
			if (iphiRaw == 22 || iphiRawMinus == 22 || iphiRawPlus == 22)
				m22->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x800000) {
			if (iphiRaw == 23 || iphiRawMinus == 23 || iphiRawPlus == 23)
				m23->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x1000000) {
			if (iphiRaw == 24 || iphiRawMinus == 24 || iphiRawPlus == 24)
				m24->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x2000000) {
			if (iphiRaw == 25 || iphiRawMinus == 25 || iphiRawPlus == 25)
				m25->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x4000000) {
			if (iphiRaw == 26 || iphiRawMinus == 26 || iphiRawPlus == 26)
				m26->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x8000000) {
			if (iphiRaw == 27 || iphiRawMinus == 27 || iphiRawPlus == 27)
				m27->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x10000000) {
			if (iphiRaw == 28 || iphiRawMinus == 28 || iphiRawPlus == 28)
				m28->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x20000000) {
			if (iphiRaw == 29 || iphiRawMinus == 29 || iphiRawPlus == 29)
				m29->write_mem(bx, bin, stubme);
		}
		// 30-31
		if (MEMASK & 0x40000000) {
			if ((iphiRaw == 30) || (iphiRawMinus == 30) || (iphiRawPlus == 30))
				m30->write_mem(bx, bin, stubme);
		}
		if (MEMASK & 0x80000000) {
			if ((iphiRaw == 31) || (iphiRawMinus == 31) || (iphiRawPlus == 31))
				m31->write_mem(bx, bin, stubme);
		}
		// executeME() END   ------------------------------

		// executeTE() START ------------------------------
		// BARREL -- LAYER

		// executeTE() END   ------------------------------

	} // outside loop

} // VMRouter
