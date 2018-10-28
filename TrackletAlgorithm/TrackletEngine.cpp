
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
		    const VMStubsTEInner& instubinnerdata,
		    const VMStubsTEOuter& instubouterdata,
		    StubPairs& outstubpair) {


  std::cout << "In TrackletEngine "<<instubinnerdata.getEntries(bx);
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout<<" "<<instubouterdata.getEntries(bx,zbin);
  }
  std::cout<<dec<<std::endl;

  bool pttable[32];
  readPtTable(pttable);
  
  bool bendinnertable[256];
  readBendInnerTable(bendinnertable);
  
  bool bendoutertable[256];
  readBendOuterTable(bendoutertable);
  
  outstubpair.clear(bx);

  for (unsigned int istubinner=0;istubinner<instubinnerdata.getEntries(bx);istubinner++) {
    VMSTEIID innerstubindex=VMStubsTEInner::get_index(instubinnerdata.read_mem(bx,istubinner));
    VMSTEIBEND innerstubbend=VMStubsTEInner::get_bend(instubinnerdata.read_mem(bx,istubinner));
    VMSTEIFINEPHI innerstubfinephi=VMStubsTEInner::get_finephi(instubinnerdata.read_mem(bx,istubinner));
    VMSTEIZBITS innerstubzbits=VMStubsTEInner::get_zbits(instubinnerdata.read_mem(bx,istubinner));
    int zdiffmax=innerstubzbits.range(9,7);
    int zbinfirst=innerstubzbits.range(2,0);
    int start=innerstubzbits.range(6,4);
    int last=start+innerstubzbits.range(3,3);

    //std::cout << "start last "<<start<<" "<<last<<std::endl;

    assert(last<8);
    for (unsigned int ibin=start;ibin<=last;ibin++) {
      int nstubs=instubouterdata.getEntries(bx,ibin);
      for (unsigned int istubouter=0;istubouter<nstubs;istubouter++) {
	VMSTEOID outerstubindex=VMStubsTEOuter::get_index(instubouterdata.read_mem(bx,istubouter+16*ibin));
	VMSTEOFINEPHI outerstubfinephi=VMStubsTEOuter::get_finephi(instubouterdata.read_mem(bx,istubouter+16*ibin));
	VMSTEOBEND outerstubbend=VMStubsTEOuter::get_bend(instubouterdata.read_mem(bx,istubouter+16*ibin));
	VMSTEOFINEZ outerstubfinez=VMStubsTEOuter::get_finez(instubouterdata.read_mem(bx,istubouter+16*ibin));

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

	outstubpair.write_mem(bx,innerstubindex.concat(outerstubindex));
      }
    }
  }

  std::cout << "Done in TrackletEngine"<<std::endl;

}
