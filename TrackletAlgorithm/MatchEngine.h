#ifndef TrackletAlgorithm_MatchEngine_h
#define TrackletAlgorithm_MatchEngine_h

// cms-tracklet/firmware-hls Headers
#include "Constants.h"
#include "Macros.h"
#include "VMProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "CandidateMatchMemory.h"

#ifndef __SYNTHESIS__
#ifdef CMSSW_GIT_HASH
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#else
#include "DummyMessageLogger.h"
#endif
#endif

// HLS Headers
#include "hls_math.h"

// STL Headers
#include <iostream>
#include <fstream>

/////////////////////////////
// -- MATCH ENGINE FUNCTIONS
template<TF::layerDisk LayerDisk> constexpr regionType ProjectionType() {
	return TF::layerDiskRegion[LayerDisk];
}

template<TF::layerDisk LayerDisk> constexpr regionType ModuleType() {
	return TF::layerDiskType[LayerDisk];
}

template<TF::layerDisk LayerDisk> constexpr unsigned int NBitBin() {
	return (
		(LayerDisk <= TF::L6) ? 3 : 4
	);
}

template<TF::layerDisk LayerDisk> inline const ap_uint<1>* readTable() {
	printf("The LayerDisk value must be between TF::L1 (0) and TF::D5 (10)");
	static ap_uint<1> lut[] = {};
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L1>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L1.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L2>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L2.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L3>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L3.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L4>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L4.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L5>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L5.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::L6>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_L6.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::D1>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_D1.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::D2>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_D2.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::D3>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_D3.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::D4>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_D4.tab"
	return lut;
}
template<> inline const ap_uint<1>* readTable<TF::D5>() {
	static ap_uint<1> lut[] = 
#include "../emData/ME/tables/METable_D5.tab"
	return lut;
}

template<TF::layerDisk LayerDisk>
void MatchEngine(const BXType bx, BXType& bx_o,
								 const VMStubMEMemory<ModuleType<LayerDisk>(), NBitBin<LayerDisk>()>& inputStubData,
								 const VMProjectionMemory<ProjectionType<LayerDisk>()>& inputProjectionData,
								 CandidateMatchMemory& outputCandidateMatch) {
#pragma HLS inline

	//
	//Constants
	//
	constexpr regionType kProjectionType = ProjectionType<LayerDisk>();
	constexpr regionType kModuleType = ModuleType<LayerDisk>();
	constexpr unsigned int kNBitBin = NBitBin<LayerDisk>();
	constexpr unsigned int kRInvSteps = 32;
	constexpr unsigned int kRInvBits = BITS_TO_REPRESENT(kRInvSteps - 1);
	constexpr unsigned int kBufferSize = 8;
	constexpr unsigned int kNBits_BufferAddr=BITS_TO_REPRESENT(kBufferSize - 1);
	constexpr int kBufferDataSize = VMStubMEMemory<kModuleType,kNBitBin>::kNBitDataAddr   // number of bits for stubs array size
								  + VMProjection<kProjectionType>::kVMProjectionSize	// projection data size
								  + VMProjection<kProjectionType>::kVMProjZBinSize;	// number of bits for index of z-bin + z-bin flag (0 => first bin, 1 => second bin)
	constexpr unsigned int kZAdjustment = 8;

	enum BitLocations {
		// The location of the least significant bit (LSB) and most significant bit (MSB) in the ME buffer word for different fields
		kVMMESecondLSB = 0,
		kVMMESecondMSB = 0,
		kVMMEZBinLSB = kVMMESecondMSB + 1,
		kVMMEZBinMSB = kVMMEZBinLSB + (VMProjection<kProjectionType>::kVMProjZBinSize - 1) - 1,
		kVMMEProjectionLSB = kVMMEZBinMSB + 1,
		kVMMEProjectionMSB = kVMMEProjectionLSB + VMProjection<kProjectionType>::kVMProjectionSize - 1,
		kVMMENStubsLSB = kVMMEProjectionMSB + 1,
		kVMMENStubsMSB = kVMMENStubsLSB + VMStubMEMemory<kModuleType,kNBitBin>::kNBitDataAddr - 1
	};
	enum StubZPositionBarrelConsistency {
		kBarrelPSMin = -1,
		kBarrelPSMax = 1,
		kBarrel2SMin = -5,
		kBarrel2SMax = 5
	};
	enum StubZPositionDiskConsistency {
		kDiskPSMin = -1,
		kDiskPSMax = 1,
		kDisk2SMin = -3,
		kDisk2SMax = 3
	};
	enum StubPhiPositionConsistency {
		kMin = 3,
		kMax = 5
	};

	//
	//Initialize table for bend-rinv consistency
	//
	static const ap_uint<1>* table = readTable<LayerDisk>();

	//
	// Set up a FIFO based on a circular buffer structure.
	// Projection memory is read and if projections points to nonempty zbin for the stubs it is stored on this buffer.
	// The projection reading will stop if buffer is full and continue after the buffer is drained.
	// Each element consists of
	//   * kNBits_BufferAddr is the number of bits to handle buffer index (i.e. buffer size will be 1<<kNBits_BufferAddr).
	//   * kBufferDataSize is the size of each element in the buffer. The element data consists of, in order of MSB to LSB:
	//       [# of stubs in z-bin][projection data][index of z-bin][z-bin flag]
	//
	ap_uint<kBufferDataSize> projectionBuffer[1<<kNBits_BufferAddr];
	#pragma HLS ARRAY_PARTITION variable=projectionBuffer complete dim=0
	ap_uint<kNBits_BufferAddr> head_writeindex = 0;	// handles current buffer index for writing
	ap_uint<kNBits_BufferAddr> tail_readindex = 0;	// handles current buffer index for reading

	// The next projection to read, the number of projections and flag if we have more projections to read
	ap_uint<kNBits_MemAddr> iprojection = 0;
	auto const nproj = inputProjectionData.getEntries(bx);
	bool moreProjectionsAvailable = iprojection < nproj;

	// Variables for the projection
	typename VMProjection<kProjectionType>::VMPID projindex;
	typename VMProjection<kProjectionType>::VMPFINEZ projfinez;
	typename VMProjection<kProjectionType>::VMPFINEPHI projfinephi;
	typename VMProjection<kProjectionType>::VMPRINV projrinv;
	ap_uint<VMProjection<kProjectionType>::kVMProjZBinSize> zbin = 0;
	ap_uint<kNBits_MemAddr> ncmatch = 0;
	bool isPSseed;
	bool second;

	// Number of stubs for current zbin and the stub being processed on this clock
	ap_uint<kNBits_MemAddrBinned> nstubs=0;
	ap_uint<kNBits_MemAddrBinned> istub=0;
	#pragma HLS dependence variable=istub intra WAR true

#ifdef DEBUG
	std::cout << "ProjectionIndex\tStubIndex\t<=== (PASS/FAIL)" << std::endl;
#endif

	// Main processing loops starts here.
	// Seven iterations are subtracted so that the total latency is 108 clock
	// cycles. Pipeline rewinding does not currently work.
	STEP_LOOP: for (ap_uint<kNBits_MemAddr> istep=0; istep<kMaxProc - kMaxProcOffset(module::ME); istep++) {
		#pragma HLS PIPELINE II=1 rewind
		#pragma HLS DEPENDENCE variable=tail_readindex inter false

#ifdef DEBUG
		std::cout << "Circular buffer iteration: " << istep << std::endl;
#endif

		// Pre-fetch an element from the buffer
		auto const qdata=projectionBuffer[tail_readindex];

		// The buffer is not full if 2 slots are available as we may write stubs for up to 2 z-bins
		ap_uint<kNBits_BufferAddr> head_writeindexplus     = head_writeindex+1;
		ap_uint<kNBits_BufferAddr> head_writeindexplusplus = head_writeindex+2;
		bool bufferNotFull = (head_writeindexplus!=tail_readindex) && (head_writeindexplusplus!=tail_readindex);

		// The buffer is not empty when current write index and read index are different
		// With this you have to assume the buffer will never be absolutely full
		bool bufferNotEmpty = head_writeindex != tail_readindex;

		// If we have more projections and the buffer is not full we read
		// next projection and put in buffer if there are stubs in the 
		// memory the to which the projection points
		if (moreProjectionsAvailable && bufferNotFull) {
			auto const iprojectiontmp=iprojection;
			auto const projectiondatatmp=inputProjectionData.read_mem(bx,iprojectiontmp);
			iprojection++;
			moreProjectionsAvailable=iprojection<nproj;

			// The first and last zbin the projection points to
			auto const projectionzbitstmp=projectiondatatmp.getZBin();
			ap_uint<VMProjection<kProjectionType>::kVMProjZBinSize - 1> zbinfirst=projectionzbitstmp.range(VMProjection<kProjectionType>::kVMProjZBinSize-1,1);
			ap_uint<VMProjection<kProjectionType>::kVMProjZBinSize - 1> zbinlast=zbinfirst + projectionzbitstmp.range(0,0);

			// Check if there are stubs in the memory
			auto const nstubfirst = inputStubData.getEntries(bx,zbinfirst);
			auto const nstublast  = inputStubData.getEntries(bx,zbinlast);
			bool savefirst = (nstubfirst != 0);
			bool savelast  = (nstublast != 0) && projectionzbitstmp.range(0,0);
			auto const head_writeindex_tmp=head_writeindex;

			if (savefirst) {
				ap_uint<1> zero=0;
				ap_uint<VMProjection<kProjectionType>::kVMProjZBinSize> tmp=zbinfirst.concat(zero);
				ap_uint<VMProjection<kProjectionType>::kVMProjectionSize + VMProjection<kProjectionType>::kVMProjZBinSize> tmp2=projectiondatatmp.raw().concat(tmp);
				projectionBuffer[head_writeindex_tmp] = nstubfirst.concat(tmp2);
			}
			if (savelast) {
				ap_uint<1> one=1;
				ap_uint<VMProjection<kProjectionType>::kVMProjZBinSize> tmp=zbinlast.concat(one);
				ap_uint<VMProjection<kProjectionType>::kVMProjectionSize + VMProjection<kProjectionType>::kVMProjZBinSize> tmp2=projectiondatatmp.raw().concat(tmp);
				ap_uint<kNBits_BufferAddr> head_writeindex_tmp_last = head_writeindex_tmp+savefirst;
				projectionBuffer[head_writeindex_tmp_last] = nstublast.concat(tmp2);
			}
#ifdef DEBUG
			std::cout << "Writing " << savefirst+savelast << " z-bins ==> head_writeindex " << head_writeindex << "-->";
#endif
			head_writeindex = head_writeindex + savefirst + savelast;
#ifdef DEBUG
			std::cout << head_writeindex << std::endl;
			if (savefirst) std::cout << "\tNew data: " << projectionBuffer[head_writeindex_tmp].to_string(2) << std::endl;
			if (savelast) std::cout << "\tNew data: " << projectionBuffer[head_writeindex_tmp+savefirst].to_string(2) << std::endl;
#endif
		}

		// If the buffer is not empty we have a projection that we need to process ...
		if (bufferNotEmpty) {
			ap_uint<kNBits_MemAddrBinned> istubtmp=istub;

			//Need to read the information about the proj in the buffer
			second = qdata.range(BitLocations::kVMMESecondMSB, BitLocations::kVMMESecondLSB);
			nstubs = qdata.range(BitLocations::kVMMENStubsMSB, BitLocations::kVMMENStubsLSB);
			VMProjection<kProjectionType> data(qdata.range(BitLocations::kVMMEProjectionMSB, BitLocations::kVMMEProjectionLSB));
			zbin = qdata.range(BitLocations::kVMMEZBinMSB, BitLocations::kVMMEZBinLSB);

			projindex = data.getIndex();
			projfinez = data.getFineZ();
			projfinephi = data.getFinePhi();
			projrinv = data.getRInv();
			isPSseed = (kProjectionType == BARREL) ? data.getIsPSSeed() : 1;

			// Check if last stub, if so, go to next buffer entry 
			if (istub + 1 >= nstubs){
			  istub = 0;
			  tail_readindex++;
			}
			else {
			  istub++;
			}

			// Read stub memory and extract data fields
			auto const stubdata    = inputStubData.read_mem(bx, zbin, istubtmp);
			auto const stubindex   = stubdata.getIndex();
			auto const stubfinez   = stubdata.getFineZ();
			auto const stubfinephi = stubdata.getFinePhi();
			auto const stubbend    = stubdata.getBend();
			//auto const isPSmodule  = ;

			// Calculate fine z position
			ap_int<VMProjectionBase<kProjectionType>::kVMProjFineZSize+1> projfinezadj = projfinez;
			if (second) projfinezadj = projfinezadj - kZAdjustment;
			ap_int<VMProjectionBase<kProjectionType>::kVMProjFineZSize+1> idz          = stubfinez - projfinezadj;
			ap_int<VMProjectionBase<kProjectionType>::kVMProjFinePhiSize+1> idphi      = projfinephi - stubfinephi;

			// Check if stub z position consistent
			bool pass = false;
			if (kProjectionType == BARREL) {
				pass = (isPSseed) ? (idz >= StubZPositionBarrelConsistency::kBarrelPSMin && idz <= StubZPositionBarrelConsistency::kBarrelPSMax)
													: (idz >= StubZPositionBarrelConsistency::kBarrel2SMin && idz <= StubZPositionBarrelConsistency::kBarrel2SMax);
			}
//			else {
//				pass = (isPSmodule) ? (idz >= StubZPositionDiskConsistency::kDiskPSMin && idz <= StubZPositionDiskConsistency::kDiskPSMax)
//														: (idz >= StubZPositionDiskConsistency::kDisk2SMin && idz <= StubZPositionDiskConsistency::kDisk2SMax);	
//			}

			// Check is stub phi positions are consistent
			bool passphi = ((idphi<StubPhiPositionConsistency::kMin) && (idphi>-StubPhiPositionConsistency::kMin)) ||
										 ((idphi>StubPhiPositionConsistency::kMax) || (idphi<-StubPhiPositionConsistency::kMax));

			// Check if stub bend and proj rinv consistent
			auto const index = projrinv.concat(stubbend) ;//+ ((kProjectionType == DISK && isPSmodule) ? (1 << (kRInvBits + kNBitBin)) : 0);

#ifdef DEBUG
			std::cout << projindex.to_string(2) << "\t" << stubindex.to_string(2) << "\t<=== ";
#endif
			if ( passphi && pass && table[index]) {
				CandidateMatch cmatch(projindex.concat(stubindex));
				outputCandidateMatch.write_mem(bx,cmatch,ncmatch);
				ncmatch++;
#ifdef DEBUG
				std::cout << "PASS -- " << ncmatch-1 << "\n";
#endif
			}
#ifdef DEBUG
			else {
				std::cout << "FAIL" << "\n";
			}
			std::cout << "\ttail_readindex: " << tail_readindex - ((istub +1 >= nstubs) ? 1 : 0) << "\n"
					  << "\thead_writeindex: " << head_writeindex << "\n"
					  << "\tsecond: " << second << "\n"
					  << "\tprojfinez: " << projfinez << "\n"
					  << "\tprojfinezadj: " << projfinezadj << "\n"
					  << "\tstubfinez: " << stubfinez << "\n"
					  << "\tidz: " << idz.to_string() << "\n"
					  << "\tisPSseed: " << isPSseed << "\n"
					  << "\tpass: " << pass << "\n"
					  << "\tpassphi: " << passphi << "\n"
					  << "\tindex: " << index.get().to_string() << "\n"
					  << "\ttable[index]: " << table[index] << "\n"
					  << "\tnstubs:" << nstubs << "\n"
					  << "\tistub:" << istubtmp << std::endl;
#endif
		}
	}

	bx_o = bx;
}

#endif
