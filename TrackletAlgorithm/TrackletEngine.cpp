
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

/*
  std::cout << "In TrackletEngine "<<instubinnerdata.getEntries(bx);
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout<<" "<<instubouterdata.getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;
*/
  ap_uint<1> pttable[32];
  readPtTable(pttable);

  ap_uint<1> bendinnertable[256];
  readBendInnerTable(bendinnertable);

  ap_uint<1> bendoutertable[256];
  readBendOuterTable(bendoutertable);

  outstubpair.clear(bx);

  // istubinner is incremented whenever a new inner stub is to be processed
  unsigned int istubinner = 0;
  unsigned int nstubinner = instubinnerdata.getEntries(bx);

  // variables for inner stubs info
  VMStubTEInner<BARRELPS>                innerstubdata    = instubinnerdata.read_mem(bx,istubinner);
  VMStubTEInner<BARRELPS>::VMSTEIID      innerstubindex   = innerstubdata.getIndex();
  VMStubTEInner<BARRELPS>::VMSTEIBEND    innerstubbend    = innerstubdata.getBend();
  VMStubTEInner<BARRELPS>::VMSTEIFINEPHI innerstubfinephi = innerstubdata.getFinePhi();
  VMStubTEInner<BARRELPS>::VMSTEIZBITS   innerstubzbits   = innerstubdata.getZBits();

  // variables for z info
  ap_uint<3> zdiffmax  = innerstubzbits.range(9,7);
  ap_uint<3> zbinfirst = innerstubzbits.range(2,0);
  ap_uint<3> start     = innerstubzbits.range(6,4);
  ap_uint<3> last      = start+innerstubzbits.range(3,3);
  ap_uint<3> ibin      = start;

  // variables for outer stubs info
  unsigned int istubouter = 0;
  unsigned int nstubs     = instubouterdata.getEntries(bx,ibin);

  //
  // main loop
  //
  for (unsigned int istep=1; istep<kMaxProc; istep++) {
	  #pragma HLS pipeline II=1
	  if(istubinner < nstubinner) {

		  if(istubouter < nstubs) {
			  //
			  // Update variables for outer stubs info if there stubs in the current ibin
			  //
			  VMStubTEOuter<BARRELPS>                outerstubdata    = instubouterdata.read_mem(bx,istubouter+16*ibin);
			  VMStubTEOuter<BARRELPS>::VMSTEOID      outerstubindex   = outerstubdata.getIndex();
			  VMStubTEOuter<BARRELPS>::VMSTEOFINEPHI outerstubfinephi = outerstubdata.getFinePhi();
			  VMStubTEOuter<BARRELPS>::VMSTEOBEND    outerstubbend    = outerstubdata.getBend();
			  VMStubTEOuter<BARRELPS>::VMSTEOFINEZ   outerstubfinez   = outerstubdata.getFineZ();

			  ///// Check if stub-pair candidate pass requirements /////

			  // adjust z-bin index for the 2nd z-bin
			  int tmpz = outerstubfinez;
			  int zbin = (start!=ibin) ? (tmpz+8) : tmpz;

			  // pT cut
			  ap_uint<5> ptindex1=innerstubfinephi.concat(outerstubfinephi);
			  ap_uint<5> ptindex2=ptindex1;
			  ap_uint<1> pt_tmp = pttable[ptindex1];

			  // inner stub bend consistency
			  ap_uint<8> bendinnerindex=ptindex1.concat(innerstubbend);
			  ap_uint<1> bi_tmp = bendinnertable[bendinnerindex];

			  ap_uint<8> bendouterindex=ptindex2.concat(outerstubbend);
			  ap_uint<1> bo_tmp = bendoutertable[bendouterindex];

			  ap_uint<1> ifskip = 0;
			  ifskip = (zbin<zbinfirst) || (zbin-zbinfirst>zdiffmax)  // z-coordinate consistency
						|| (!pt_tmp) || (!bi_tmp) || (!bo_tmp);

			  if(!ifskip) {
				  // good stub pair, so write it!
				  StubPair spair(innerstubindex.concat(outerstubindex));
				  outstubpair.write_mem(bx,spair);
			  }

			  istubouter++;

		  } else {
			  istubouter = 0;

			  if(ibin!=last) {
				  ibin   = last;
				  nstubs = instubouterdata.getEntries(bx,ibin);

			  } else {
				  istubinner++;

				  innerstubdata    = instubinnerdata.read_mem(bx,istubinner);
				  innerstubindex   = innerstubdata.getIndex();
				  innerstubbend    = innerstubdata.getBend();
				  innerstubfinephi = innerstubdata.getFinePhi();
				  innerstubzbits   = innerstubdata.getZBits();

				  zdiffmax  = innerstubzbits.range(9,7);
				  zbinfirst = innerstubzbits.range(2,0);
				  start     = innerstubzbits.range(6,4);
				  last      = start+innerstubzbits.range(3,3);  // Note: only 2 possibilities: last==start OR last==start+1

				  ibin   = start;
			  	  nstubs = instubouterdata.getEntries(bx,ibin);
			  }
		  }
	  }


  }

//  std::cout << "Done in TrackletEngine"<<std::endl;

}
