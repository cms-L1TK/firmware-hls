
#include "TrackletEngine.h"
#include "hls_math.h"
#include <iostream>
#include <fstream>


void readPtTable(bool table[32]){

  bool tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_ptcut.tab"
    
  for (int i=0;i<32;i++){
    table[i]=tmp[i];
  }

}


void readBendInnerTable(bool table[256]){

  bool tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_stubptinnercut.tab"
    
  for (int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}

void readBendOuterTable(bool table[256]){

  bool tmp[]=
#include "../emData/TE/TE_L1PHIE18_L2PHIC17/TE_L1PHIE18_L2PHIC17_stubptoutercut.tab"
    
  for (int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}


void TrackletEngine(
		    const ap_uint<3> bx,
		    const VMStubTEInnerMemory& instubinnerdata,
		    const VMStubTEOuterMemory& instubouterdata,
		    StubPairMemory& outstubpair) {


  std::cout << "In TrackletEngine "<<instubinnerdata.getEntries(bx);
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout<<" "<<instubouterdata.getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;

  bool pttable[32];
  readPtTable(pttable);
  
  bool bendinnertable[256];
  readBendInnerTable(bendinnertable);
  
  bool bendoutertable[256];
  readBendOuterTable(bendoutertable);
  
  outstubpair.clear(bx);

  for (unsigned int istubinner=0;istubinner<instubinnerdata.getEntries(bx);istubinner++) {
    VMStubTEInner innerstubdata = instubinnerdata.read_mem(bx,istubinner);
    VMStubTEInner::VMSTEIID innerstubindex=innerstubdata.getIndex();
    VMStubTEInner::VMSTEIBEND innerstubbend=innerstubdata.getBend();
    VMStubTEInner::VMSTEIFINEPHI innerstubfinephi=innerstubdata.getFinePhi();
    VMStubTEInner::VMSTEIZBITS innerstubzbits=innerstubdata.getZBits();
    int zdiffmax=innerstubzbits.range(9,7);
    int zbinfirst=innerstubzbits.range(2,0);
    int start=innerstubzbits.range(6,4);
    int last=start+innerstubzbits.range(3,3);

    //std::cout << "start last "<<start<<" "<<last<<std::endl;

    assert(last<8);
    for (unsigned int ibin=start;ibin<=last;ibin++) {
      int nstubs=instubouterdata.getEntries(bx,ibin);
      for (unsigned int istubouter=0;istubouter<nstubs;istubouter++) {
        VMStubTEOuter outerstubdata = instubouterdata.read_mem(bx,istubouter+16*ibin);
        VMStubTEOuter::VMSTEOID outerstubindex=outerstubdata.getIndex();
	VMStubTEOuter::VMSTEOFINEPHI outerstubfinephi=outerstubdata.getFinePhi();
	VMStubTEOuter::VMSTEOBEND outerstubbend=outerstubdata.getBend();
	VMStubTEOuter::VMSTEOFINEZ outerstubfinez=outerstubdata.getFineZ();

	int zbin=outerstubfinez;

	if (start!=ibin) zbin+=8;
	if ((zbin<zbinfirst)||(zbin-zbinfirst>zdiffmax)) {
	  continue;
	}

	//std::cout << "ibin istubouter "<<ibin<<" "<<istubouter<<std::endl;

	ap_uint<5> ptindex=innerstubfinephi.concat(outerstubfinephi);

	if (!pttable[ptindex]) {
	  continue;
	}

	ap_uint<8> bendinnerindex=ptindex.concat(innerstubbend);

	if (!bendinnertable[bendinnerindex]) {
	  continue;
	}

	ap_uint<8> bendouterindex=ptindex.concat(outerstubbend);

	if (!bendoutertable[bendouterindex]) {
	  continue;
	}
        StubPair spair(innerstubindex.concat(outerstubindex));
	outstubpair.write_mem(bx,spair);
      }
    }
  }

  std::cout << "Done in TrackletEngine"<<std::endl;

}
