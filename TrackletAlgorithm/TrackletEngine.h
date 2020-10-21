#ifndef TrackletAlgorithm_TrackletEngine_h
#define TrackletAlgorithm_TrackletEngine_h

#include "VMStubTEInnerMemory.h"
#include "VMStubTEOuterMemory.h"
#include "StubPairMemory.h"

#include "hls_math.h"
#include <string>

class CandMatch;

namespace TE {

enum seed {L1L2=0, L3L4=1, L5L6=2, D1D2=3, D3D4=4, L1D1=5, L2D1=6};

enum phireg {
	 A1,  A2,  A3,  A4,  A5,  A6,  A7,  A8,
	 B5,  B6,  B7,  B8,  B9, B10, B11, B12, B13, B14, B15, B16,
	 C9, C10, C11, C12, C17, C18, C19, C20, C21, C22, C23, C24,
	D13, D14, D15, D16, D25, D26, D27, D28, D29, D30, D31, D32,
	E17, E18, E19, E20,
	F21, F22, F23, F24,
	G25, G26, G27, G28,
	H29, H30, H31, H32,
	 Q9, Q10,
	R11, R12,
	S13, S14,
	T15, T16,
	 W6,  W7,  W8, W13, W14, W15, W16,
	 X1,  X2,  X3,  X4,
	 Y3,  Y4,  Y5,  Y6,  Y7,  Y8,
	 Z5,  Z6,  Z9, Z10, Z11, Z12
};

}//namespace TE

//----------------------------
// Tracklet Engine main code
//============================
template<int innertype, int outertype,
  unsigned int stubptinnerdepth, unsigned int stubptouterdepth>
void TrackletEngine(
		    const BXType bx,
		    const VMStubTEInnerMemory<innertype>& instubinnerdata,
		    const VMStubTEOuterMemory<outertype>& instubouterdata,
                    const ap_uint<1> bendinnertable[stubptinnerdepth],
                    const ap_uint<1> bendoutertable[stubptouterdepth],
		    StubPairMemory& outstubpair) {

#pragma HLS inline
  int nstubpairs = 0;
#pragma HLS dependence variable=nstubpairs intra WAR true

  outstubpair.clear(bx);

  //
  // Set up a FIFO based on a circular buffer structure
  // Each element consists of
  //   * kNBits_BufferAddr is the number of bits to handle buffer index (i.e. buffer size will be 1<<kNBits_BufferAddr).
  //   * kBufferDataSize is the size of each element in the buffer. The element data consists of, in order of MSB to LSB:
  //       [# of outer stubs in z-bin][inner stub data][index of z-bin][z-bin flag]
  //
  constexpr unsigned int kNBits_BufferAddr = 3;
  constexpr unsigned int kNOuterStubsSize = 5;
  constexpr unsigned int kZBinFlagSize = 1;
  constexpr int kBufferDataSize =
                  kNOuterStubsSize                              // number of bits for outer stubs array size (size of NEntryT in MemoryTemplateBinned.h)
                + VMStubTEInner<innertype>::kVMStubTEInnerSize  // inner stub data size
                + TEBinsBits                                    // number of bits for index of z-bin
                + kZBinFlagSize;                                // z-bin flag (0 => first bin, 1 => second bin)

  constexpr unsigned int kZBinFlagLSB = 0;
  constexpr unsigned int kZBinFlagMSB = kZBinFlagLSB + kZBinFlagSize - 1;
  constexpr unsigned int kZBinIndexLSB = kZBinFlagMSB + 1;
  constexpr unsigned int kZBinIndexMSB = kZBinIndexLSB + TEBinsBits - 1;
  constexpr unsigned int kInnerStubDataLSB = kZBinIndexMSB + 1;
  constexpr unsigned int kInnerStubDataMSB = kInnerStubDataLSB + VMStubTEInner<innertype>::kVMStubTEInnerSize - 1;
  constexpr unsigned int kNOuterStubsLSB = kInnerStubDataMSB + 1;
  constexpr unsigned int kNOuterStubsMSB = kNOuterStubsLSB + kNOuterStubsSize - 1;

  ap_uint<kBufferDataSize> teBuffer[1<<kNBits_BufferAddr];
#pragma HLS ARRAY_PARTITION variable teBuffer complete dim=0
  ap_uint<kNBits_BufferAddr> writeindex = 0;     // handles current buffer index for writing
  ap_uint<kNBits_BufferAddr> readindex  = 0;     // handles current buffer index for reading


  ap_uint<kNBits_MemAddr> istubinner=0;
  auto const nstubinner = instubinnerdata.getEntries(bx);
  ap_uint<1> morestubinner = istubinner<nstubinner;

  // variables for inner stub information
  typename VMStubTEInner<innertype>::VMSTEIID      innerstubindex;
  typename VMStubTEInner<innertype>::VMSTEIBEND    innerstubbend;
  typename VMStubTEInner<innertype>::VMSTEIFINEPHI innerstubfinephi;
  ap_uint<TEBinsBits> zdiffmax;
  ap_uint<TEBinsBits> zbinfirst;
  ap_uint<1> second;

  // variables for outer stub information
  ap_uint<kNBits_MemAddrBinned> nstubs     = 0;
  ap_uint<kNBits_MemAddrBinned> istubouter = 0;
#pragma HLS dependence variable=istubouter intra WAR true

  //
  // main loop
  //
  // Seven iterations are subtracted so that the total latency is 108 clock
  // cycles. Pipeline rewinding does not currently work.
  for (unsigned int istep=0; istep<kMaxProc - kMaxProcOffset(module::TE); istep++) {
#pragma HLS pipeline II=1

	  // pre-fetch element from buffer
	  auto const bufdata = teBuffer[readindex];

	  // buffer is not full if 2 slots are available, as we may write stubs for up to 2 z-bins
	  const ap_uint<kNBits_BufferAddr> writeindexplus     = writeindex+1;
	  const ap_uint<kNBits_BufferAddr> writeindexplusplus = writeindex+2;
	  const ap_uint<1> buffernotfull = (writeindexplus!=readindex) && (writeindexplusplus!=readindex);

	  // buffer is not empty when current write index and read index are different
	  const ap_uint<1> buffernotempty = (writeindex!=readindex);

	  // buffer is not full and there are more inner stubs to read in...
	  if(morestubinner && buffernotfull) {
		  auto const innerstubdatatmp  = instubinnerdata.read_mem(bx,istubinner);
		  istubinner++;
		  morestubinner = istubinner<nstubinner;

		  const ap_uint<TEBinsBits> zbinstart = innerstubdatatmp.getZBinStart();
		  const ap_uint<TEBinsBits> zbinlast  = zbinstart + innerstubdatatmp.getZBinDiff();

		  auto const nstubsstart = instubouterdata.getEntries(bx,zbinstart);
		  auto const nstubslast  = instubouterdata.getEntries(bx,zbinlast);
		  const ap_uint<1> savestart = (nstubsstart != 0);
		  const ap_uint<1> savelast  = (nstubslast  != 0) && innerstubdatatmp.getZBinDiff();
		  auto const writeindextmp = writeindex;

		  if(savestart && savelast) {
			  writeindex = writeindexplusplus;
		  } else if (savestart || savelast){
			  writeindex = writeindexplus;
		  }

		  if(savestart) {
			  const ap_uint<1> zero = 0;
			  const ap_uint<TEBinsBits+1> tmp1 = zbinstart.concat(zero);
			  const ap_uint<VMStubTEInner<innertype>::kVMStubTEInnerSize+TEBinsBits+1> tmp2 = innerstubdatatmp.raw().concat(tmp1);
			  teBuffer[writeindextmp] = nstubsstart.concat(tmp2);
		  }
		  if(savelast) {
			  const ap_uint<1> one = 1;
			  const ap_uint<TEBinsBits+1> tmp1 = zbinlast.concat(one);
			  const ap_uint<VMStubTEInner<innertype>::kVMStubTEInnerSize+TEBinsBits+1> tmp2 = innerstubdatatmp.raw().concat(tmp1);
			  if(savestart) {
				  const ap_uint<kNBits_BufferAddr> writeindextmpplus = writeindextmp+1;
				  teBuffer[writeindextmpplus] = nstubslast.concat(tmp2);
			  } else {
				  teBuffer[writeindextmp] = nstubslast.concat(tmp2);
			  }
		  }
	  }

	  // buffer has elements to process...
	  if(buffernotempty) {
		  const ap_uint<kNBits_MemAddrBinned> istuboutertmp = istubouter;
		  ap_uint<TEBinsBits> ibin;

		  if(istubouter==0) {
			  nstubs = bufdata.range(kNOuterStubsMSB, kNOuterStubsLSB);

			  ibin = bufdata.range(kZBinIndexMSB, kZBinIndexLSB);
			  VMStubTEInner<innertype> data(bufdata.range(kInnerStubDataMSB, kInnerStubDataLSB));

			  innerstubindex   = data.getIndex();
			  innerstubbend    = data.getBend();
			  innerstubfinephi = data.getFinePhi();
			  zdiffmax  = data.getZDiffMax();
			  zbinfirst = data.getZBinFirst();

			  second = bufdata.range(kZBinFlagMSB, kZBinFlagLSB);
		  }

		  // if there are no more outer stubs to process, advance the read index pointer to the next buffer element,
		  // otherwise increment the outer stub counter
		  if(istubouter+1 >= nstubs) {
			  istubouter=0;
			  readindex++;
		  } else {
			  istubouter++;
		  }

		  ///// Check if stub-pair candidate pass requirements /////

		  auto const outerstubdata    = instubouterdata.read_mem(bx,istuboutertmp+16*ibin);
		  auto const outerstubindex   = outerstubdata.getIndex();
		  auto const outerstubfinephi = outerstubdata.getFinePhi();
		  auto const outerstubbend    = outerstubdata.getBend();
		  auto const outerstubfinez   = outerstubdata.getFineZ();

		  // z-coordinate consistency
		  int tmpz = outerstubfinez;
		  int zbin = (second) ? (tmpz+8) : tmpz;
		  const ap_uint<1> z_tmp = (zbin>=zbinfirst) && (zbin-zbinfirst<=zdiffmax);

          	  // pT cut
          	  auto const ptindex=innerstubfinephi.concat(outerstubfinephi).get();

          	  // inner stub bend consistency
          	  auto const bendinnerindex=ptindex.concat(innerstubbend).get();
          	  auto const bi_tmp = bendinnertable[bendinnerindex];

          	  auto const bendouterindex=ptindex.concat(outerstubbend).get();
          	  auto const bo_tmp = bendoutertable[bendouterindex];

          	  const ap_uint<1> ifskip = (!z_tmp) || (!bi_tmp) || (!bo_tmp);

          	  if(!ifskip) {
                 	// good stub pair, so write it!
                  	StubPair spair(innerstubindex.concat(outerstubindex));
                  	outstubpair.write_mem(bx,spair,nstubpairs++);
          	  }
      	 }
  }
}

#endif
