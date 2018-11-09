#include "MatchEngine.h"
#include "hls_math.h"
#include <iostream>
#include <fstream>


void readTable(bool table[256]){

  bool tmp[256]=
#include "../emData/ME/ME_L1PHIE20/METable_ME_L1PHIE20.tab"

  for (int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}


// There are three different implementations of the MatchEngine. 
// By selecting 'CODEVERSION' on the line below you select which
// implementation to use:
// 1 - Version of code closest to emulation. Triple nested loop
//     which can not be pipelined
// 2 - Loop structure has been flattend and code modified to use 
//     a buffer for the projections. It reaches II=1 for the loop
//
#define CODEVERSION 2

#if CODEVERSION==2

//Attempt at new version of code
void MatchEngine(const ap_uint<3> bx,
		 const VMStubMemory* const instubdata,
		 const VMProjectionMemory* const inprojdata,
		 CandidateMatchMemory* const outcandmatch){


#ifndef __SYNTHESIS__
  //Prinout of number of projections and stubs
  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;
#endif

  //Initialize table for bend-rinv consistency
  bool table[256]; //FIXME Need to figure out how to replace 256 with meaningful const.
  readTable(table);

  outcandmatch->clear();

  //Buffer of projections. Projection memory is read and if projections points
  //to nonempty zbin for the stubs it is stored on this buffer. The buffer is 
  //circular, and the projection reading will stop if buffer is full and continue 
  //after the buffer is drained

  constexpr unsigned int kNBitsBuffer=3;  

  ap_uint<kNBitsBuffer> writeindex=0;
  ap_uint<kNBitsBuffer> readindex=0;
  ap_uint<30> projbuffer[1<<kNBitsBuffer];  //FIXME How to replace 30 with const?
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=0

  //The next projection to read, the number of projections and flag if we have
  //more projections to read
  ap_uint<kNBits_MemAddr> iproj=0;
  auto const nproj=inprojdata->getEntries(bx);
  bool moreproj=iproj<nproj;

  //Projection that is read from the buffer and compared to stubs  
  ap_uint<TEBinsBits> zbin=0;
  VMProjection::VMPID projindex;
  VMProjection::VMPFINEZ projfinez;
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  VMProjection::VMPRINV projbend;
  bool isPSseed;
  bool second;

  //Number of stubs for current zbin and the stub being processed on this clock
  ap_uint<kNBits_MemAddrBinned> nstubs=0;
  ap_uint<kNBits_MemAddrBinned> istub=0;
#pragma HLS dependence variable=istub intra WAR true


  
  for (ap_uint<kNBits_MemAddr> istep=0;istep<kMaxProc;istep++) {
#pragma HLS PIPELINE II=1

    auto const qdata=projbuffer[readindex];

    ap_uint<kNBitsBuffer> writeindexplus=writeindex+1;
    ap_uint<kNBitsBuffer> writeindexplusplus=writeindex+2;
    bool buffernotfull=(writeindex+1!=readindex)&&(writeindex+2!=readindex);
    bool buffernotempty=(writeindex!=readindex);
    if (moreproj&&buffernotfull){
      auto const iprojtmp=iproj;
      auto const projdata=inprojdata->read_mem(bx,iprojtmp);
      auto const projzbin=projdata.GetZBin();
      iproj++;
      moreproj=iproj<nproj;
      ap_uint<TEBinsBits> zfirst=projzbin.range(3,1);
      ap_uint<TEBinsBits> zlast=zfirst+projzbin.range(0,0);
      //assert(zlast<8);
      auto const nstubfirst=instubdata->getEntries(bx,zfirst);
      auto const  nstublast=instubdata->getEntries(bx,zlast);
      bool savefirst=nstubfirst!=0;
      bool savelast=nstublast!=0&&projzbin.range(0,0);
      auto const writeindextmp=writeindex;

      if (savefirst&&savelast) {
	writeindex=writeindexplusplus;
      } else if (savefirst||savelast) {
	writeindex=writeindexplus;
      }

      if (savefirst) { //FIXME code needs to be cleaner
	ap_uint<1> zero=0;
	ap_uint<4> tmp=zfirst.concat(zero);
	ap_uint<26> tmp2=projdata.raw().concat(tmp);
	projbuffer[writeindextmp]=nstubfirst.concat(tmp2);
      }
      if (savelast) {
	ap_uint<1> one=1;
	ap_uint<4> tmp=zlast.concat(one);
	ap_uint<26> tmp2=projdata.raw().concat(tmp);
	if (savefirst) {
	  projbuffer[writeindextmp+1]=nstublast.concat(tmp2);
	} else {
	  projbuffer[writeindextmp]=nstublast.concat(tmp2);
	}
      }
    }

    if (buffernotempty) {
      ap_uint<kNBits_MemAddrBinned> istubtmp=istub;
      if (istub==0) {

        nstubs=qdata.range(29,26);
	zbin=qdata.range(3,1);
	VMProjection data(qdata.range(25,4));

	projindex=data.GetIndex();
	projfinez=data.GetFineZ();
	projbend=data.GetRInv();
	isPSseed=data.GetIsPSSeed();

	second=qdata.range(0,0);	

	if (second) {
	  projfinezadj=projfinez-8;
	} else {
	  projfinezadj=projfinez;
	}

	istub++;

      } else {
	if (istub+1>=nstubs){
	  istub=0;
	  readindex++;
	} else {
	  istub++;
	}
      }
      auto const  stubadd=zbin.concat(istubtmp);
      VMStub stubdata=instubdata->read_mem(bx,stubadd);
      VMStub::VMSID stubindex=stubdata.GetIndex();
      VMStub::VMSFINEZ stubfinez=stubdata.GetFineZ();
      VMStub::VMSBEND stubbend=stubdata.GetBend();

      ap_int<5> idz=stubfinez-projfinezadj;
      bool pass;
      if (isPSseed) {
	pass=idz>=-2&&idz<=2;
      } else {
	pass=idz>=-5&&idz<=5;
      }
      auto const index=projbend.concat(stubbend);

      if (pass&&table[index]) {
	CandidateMatch cmatch(projindex.concat(stubindex));
	outcandmatch->write_mem(bx,cmatch);
      }
      
    }

  }

}

#endif



#if CODEVERSION==1

//
// This version closely follows the code in the emulations. This version can
// not be pipelined
//

void MatchEngine(const ap_uint<3> bx,
		 const VMStubMemory* instubdata,
		 const VMProjectionMemory* inprojdata,
		 CandidateMatchMemory* outcandmatch){

  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;

  // Initialize the pt-bend lookup table
  bool table[256]; //Need to figure out how to replace 256 with some 
                   //meaning full constant
  readTable(table);

  outcandmatch->clear();

  ap_uint<kNBits_MemAddr> nproj=inprojdata->getEntries(bx);

  //Outermost loop is over the projections
  for (ap_uint<7> iproj=0;iproj<nproj;iproj++) {
    //Read projection from memory and extract the elements of the projection
    VMProjection proj=inprojdata->read_mem(bx,iproj);
    VMProjection::VMPID projindex=proj.GetIndex();
    VMProjection::VMPZBIN projzbin=proj.GetZBin();
    VMProjection::VMPFINEZ projfinez=proj.GetFineZ();
    VMProjection::VMPRINV projrinv=proj.GetRInv();
    bool isPSseed=proj.GetIsPSSeed();
    
    //Calculate first and last zbin that need to searched for stubs
    int zfirst=projzbin.range(3,1);
    int zlast=zfirst+projzbin.range(0,0);
    assert(zlast<8);

    //Loop over the zbins. There are at most two zbins that needs to be searched
    for (int zbin=zfirst;zbin<=zlast;zbin++){
      int nstub=instubdata->getEntries(bx,zbin);

      //Loop over the stubs in the bin
      for (int istub=0;istub<nstub;istub++) {
	//Read the stub memory and extract the elements of the projection
	VMStub stubdata=instubdata->read_mem(bx,istub+16*zbin);
	VMStub::VMSID stubindex=stubdata.GetIndex();
	VMStub::VMSFINEZ stubfinez=stubdata.GetFineZ();
	VMStub::VMSBEND stubbend=stubdata.GetBend();
	
	//Check is stub and projection satisfies the z cut 
	int idz=stubfinez-projfinez;
	if (zbin!=zfirst) idz+=8;
	bool pass=hls::abs(idz)<=5;
	if (isPSseed) {
	  pass=hls::abs(idz)<=2;
	}

	//Use lookup table for pt-bend matchcing and if stub passes
	//the cut save the projection-stub pair as a candidate match
	int index=stubbend+projrinv*8;	
	if (pass&&table[index]) {
	  CandidateMatch cmatch(projindex.concat(stubindex));
	  outcandmatch->write_mem(bx,cmatch);
	}

      }
    }
  }
}

#endif

