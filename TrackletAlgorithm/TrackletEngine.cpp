
#include "TrackletEngine.h"
#include "hls_math.h"



void readPtTable(ap_uint<1> table[32]){

  ap_uint<1> tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_ptcut.tab"

  for (unsigned int i=0;i<32;i++){
    table[i]=tmp[i];
  }

}


void readBendInnerTable(ap_uint<1> table[256]){

  ap_uint<1> tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_stubptinnercut.tab"

  for (unsigned int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}

void readBendOuterTable(ap_uint<1> table[256]){

  ap_uint<1> tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_stubptoutercut.tab"

  for (int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}


void TrackletEngine(
		    const ap_uint<3> bx,
		    const VMStubTEInnerMemory<BARRELPS>& instubinnerdata,
		    const VMStubTEOuterMemory<BARRELPS>& instubouterdata,
		    StubPairMemory& outstubpair) {

  ap_uint<1> pttable[32];
  readPtTable(pttable);

  ap_uint<1> bendinnertable[256];
  readBendInnerTable(bendinnertable);

  ap_uint<1> bendoutertable[256];
  readBendOuterTable(bendoutertable);

  outstubpair.clear(bx);

  //
  // Set up a FIFO based on a circular buffer structure
  // Each element consists of
  //   * kNBits_BufferAddr is the number of bits to handle buffer index (i.e. buffer size will be 1<<kNBits_BufferAddr).
  //   * kBufferDataSize is the size of each element in the buffer. The element data consists of, in order of MSB to LSB:
  //       [# of outer stubs in z-bin][inner stub data][index of z-bin][z-bin flag]
  //
  constexpr unsigned int kNBits_BufferAddr = 3;
  constexpr int kBufferDataSize =
		    5                                             // number of bits for outer stubs array size (size of NEntryT in MemoryTemplateBinned.h)
		  + VMStubTEInner<BARRELPS>::kVMStubTEInnerSize   // inner stub data size
		  + TEBinsBits                                    // number of bits for index of z-bin
		  + 1;                                            // z-bin flag (0 => first bin, 1 => second bin)

  ap_uint<kBufferDataSize> teBuffer[1<<kNBits_BufferAddr];
#pragma HLS ARRAY_PARTITION variable teBuffer complete dim=0
  ap_uint<kNBits_BufferAddr> writeindex = 0;     // handles current buffer index for writing
  ap_uint<kNBits_BufferAddr> readindex  = 0;     // handles current buffer index for reading


  ap_uint<kNBits_MemAddr> istubinner=0;
  auto const nstubinner = instubinnerdata.getEntries(bx);
  ap_uint<1> morestubinner = istubinner<nstubinner;

  // variables for inner stub information
  VMStubTEInner<BARRELPS>::VMSTEIID      innerstubindex;
  VMStubTEInner<BARRELPS>::VMSTEIBEND    innerstubbend;
  VMStubTEInner<BARRELPS>::VMSTEIFINEPHI innerstubfinephi;
  VMStubTEInner<BARRELPS>::VMSTEIZBITS   innerstubzbits;
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
  for (unsigned int istep=1; istep<kMaxProc; istep++) {
#pragma HLS pipeline II=1

	  // pre-fetch element from buffer
	  auto const bufdata = teBuffer[readindex];

	  // buffer is not full if 2 slots are available, as we may write stubs for up to 2 z-bins
	  ap_uint<kNBits_BufferAddr> writeindexplus     = writeindex+1;
	  ap_uint<kNBits_BufferAddr> writeindexplusplus = writeindex+2;
	  ap_uint<1> buffernotfull = (writeindexplus!=readindex) && (writeindexplusplus!=readindex);

	  // buffer is not empty when current write index and read index are different
	  ap_uint<1> buffernotempty = (writeindex!=readindex);

	  // buffer is not full and there are more inner stubs to read in...
	  if(morestubinner && buffernotfull) {
		  auto const innerstubdatatmp  = instubinnerdata.read_mem(bx,istubinner);
		  istubinner++;
		  morestubinner = istubinner<nstubinner;

		  auto const innerstubzbitstmp = innerstubdatatmp.getZBits();
		  ap_uint<TEBinsBits> zbinstart = innerstubzbitstmp.range(6,4);
		  ap_uint<TEBinsBits> zbinlast  = zbinstart + innerstubzbitstmp.range(3,3);

		  auto const nstubsstart = instubouterdata.getEntries(bx,zbinstart);
		  auto const nstubslast  = instubouterdata.getEntries(bx,zbinlast);
		  ap_uint<1> savestart = (nstubsstart != 0);
		  ap_uint<1> savelast  = (nstubslast  != 0) && innerstubzbitstmp.range(3,3);

		  if(savestart) {
			  ap_uint<1> zero = 0;
			  ap_uint<TEBinsBits+1> tmp1 = zbinstart.concat(zero);
			  ap_uint<VMStubTEInner<BARRELPS>::kVMStubTEInnerSize+TEBinsBits+1> tmp2 = innerstubdatatmp.raw().concat(tmp1);
			  teBuffer[writeindex] = nstubsstart.concat(tmp2);
		  }
		  if(savelast) {
			  ap_uint<1> one = 1;
			  ap_uint<TEBinsBits+1> tmp1 = zbinlast.concat(one);
			  ap_uint<VMStubTEInner<BARRELPS>::kVMStubTEInnerSize+TEBinsBits+1> tmp2 = innerstubdatatmp.raw().concat(tmp1);
			  if(savestart) {
				  teBuffer[writeindexplus] = nstubslast.concat(tmp2);
			  } else {
				  teBuffer[writeindex] = nstubslast.concat(tmp2);
			  }
		  }

		  if(savestart && savelast) {
			  writeindex = writeindexplusplus;
		  } else if (savestart || savelast){
			  writeindex = writeindexplus;
		  }
	  }

	  // buffer has elements to process...
	  if(buffernotempty) {
		  ap_uint<kNBits_MemAddrBinned> istuboutertmp = istubouter;
		  ap_uint<TEBinsBits> ibin;

		  if(istubouter==0) {
			  nstubs = bufdata.range(30,26);

			  ibin = bufdata.range(3,1);
			  VMStubTEInner<BARRELPS> data(bufdata.range(25,4));

			  innerstubindex   = data.getIndex();
			  innerstubbend    = data.getBend();
			  innerstubfinephi = data.getFinePhi();
			  innerstubzbits   = data.getZBits();
			  zdiffmax  = innerstubzbits.range(9,7);
			  zbinfirst = innerstubzbits.range(2,0);

			  second = bufdata.range(0,0);
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
		  ap_uint<1> z_tmp = (zbin>=zbinfirst) && (zbin-zbinfirst<=zdiffmax);

          	  // pT cut
          	  ap_uint<5> ptindex1=innerstubfinephi.concat(outerstubfinephi);
          	  ap_uint<5> ptindex2=ptindex1;
          	  ap_uint<1> pt_tmp = pttable[ptindex1];

          	  // inner stub bend consistency
          	  ap_uint<8> bendinnerindex=ptindex1.concat(innerstubbend);
          	  ap_uint<1> bi_tmp = bendinnertable[bendinnerindex];

          	  ap_uint<8> bendouterindex=ptindex2.concat(outerstubbend);
          	  ap_uint<1> bo_tmp = bendoutertable[bendouterindex];

          	  ap_uint<1> ifskip = (!z_tmp) || (!pt_tmp) || (!bi_tmp) || (!bo_tmp);

          	  if(!ifskip) {
                 	// good stub pair, so write it!
                  	StubPair spair(innerstubindex.concat(outerstubindex));
                  	outstubpair.write_mem(bx,spair);
          	  }
      	 }
  }
}
