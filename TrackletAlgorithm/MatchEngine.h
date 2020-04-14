#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "Constants.h"
#include "VMProjectionMemory.h"
#include "CandidateMatchMemory.h"
#include "VMStubMEMemory.h"
#include "hls_math.h"
#include <iostream>
#include <fstream>


template<int L>
void readTable(bool table[256]){

  if (L==1) {
    bool tmp[256]=
#include "../emData/ME/ME_L3PHIC20/METable_L1.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

  if (L==2) {
    bool tmp[256]=
#include "../emData/ME/ME_L3PHIC20/METable_L2.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

  if (L==3) {
    bool tmp[256]=
#include "../emData/ME/ME_L3PHIC20/METable_L3.tab"
    for (int i=0;i<256;i++){
      table[i]=tmp[i];
    }
  }

  if (L==4) {
    bool tmp[512]=
#include "../emData/ME/ME_L3PHIC20/METable_L4.tab"
    for (int i=0;i<512;i++){
      table[i]=tmp[i];
    }
  }

  if (L==5) {
    bool tmp[512]=
#include "../emData/ME/ME_L3PHIC20/METable_L5.tab"
    for (int i=0;i<512;i++){
      table[i]=tmp[i];
    }
  }

  if (L==6) {
    bool tmp[512]=
#include "../emData/ME/ME_L3PHIC20/METable_L6.tab"
    for (int i=0;i<512;i++){
      table[i]=tmp[i];
    }
  }



}


// There are two different implementations of the MatchEngine. 
// By selecting 'CODEVERSION' on the line below you select which
// implementation to use:
// 1 - Version of the code is closest to emulation. Triple nested loop
//     which can not be pipelined
// 2 - Loop structure has been flattened and code modified to use 
//     a buffer for the projections. It reaches II=1 for the loop
//
#define CODEVERSION 2

#if CODEVERSION==2

//Attempt at new version of code
template<int L, regionType VMSMEType>
void MatchEngine(BXType bx, BXType& bx_o,
		 const VMStubMEMemory<VMSMEType>* instubdata,
		 const VMProjectionMemory<BARREL>* inprojdata,
		 CandidateMatchMemory* outcandmatch){

#pragma HLS inline
#ifndef __SYNTHESIS__
  //Prinout of number of projections and stubs
  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;
#endif

  //Initialize table for bend-rinv consistency
  bool table[(L<4)?256:512]; //FIXME Need to figure out how to replace 256 with meaningful const.
  readTable<L>(table);

  outcandmatch->clear();

  //Buffer of projections. Projection memory is read and if projections points
  //to nonempty zbin for the stubs it is stored on this buffer. The buffer is 
  //circular, and the projection reading will stop if buffer is full and continue 
  //after the buffer is drained

  constexpr unsigned int kNBitsBuffer=3;
  constexpr int kNBits_ProjBuffer =kNBits_MemAddrBinned + VMProjectionBase<BARREL>::kVMProjectionSize + 1 +kNBits_z +1;

  ap_uint<kNBitsBuffer> writeindex=0;
  ap_uint<kNBitsBuffer> readindex=0;
  ap_uint<kNBits_ProjBuffer> projbuffer[1<<kNBitsBuffer];  //projbuffer = nstub+projdata+finez
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=0

  //The next projection to read, the number of projections and flag if we have
  //more projections to read
  ap_uint<kNBits_MemAddr> iproj=0; //counter
  auto const nproj=inprojdata->getEntries(bx);
  bool moreproj=iproj<nproj;

  //Projection that is read from the buffer and compared to stubs  
  ap_uint<TEBinsBits> zbin=0;
  VMProjection<BARREL>::VMPID projindex;
  VMProjection<BARREL>::VMPFINEZ projfinez;
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  VMProjection<BARREL>::VMPRINV projrinv;
  bool isPSseed;
  bool second;

  //Number of stubs for current zbin and the stub being processed on this clock
  ap_uint<kNBits_MemAddrBinned> nstubs=0;
  ap_uint<kNBits_MemAddrBinned> istub=0;
#pragma HLS dependence variable=istub intra WAR true
  
// declare counter for output to CandidateMatch // !!!                                                                                                                                                       
  int ncmatchout = 0;

  //Main processing loops starts here  
  for (ap_uint<kNBits_MemAddr> istep=0;istep<kMaxProc-8;istep++) {
#pragma HLS PIPELINE II=1

    //prefetch and calculate write pointers for buffer
    auto const qdata=projbuffer[readindex];
    ap_uint<kNBitsBuffer> writeindexplus=writeindex+1;
    ap_uint<kNBitsBuffer> writeindexplusplus=writeindex+2;

    //Determine if buffere is full - or near full as a projection
    //can point to two z bins we might fill two slots in the buffer
    bool buffernotfull=(writeindexplus!=readindex)&&(writeindexplusplus!=readindex);
    //Determin if buffere is empty
    bool buffernotempty=(writeindex!=readindex);

    //If we have more projections and the buffer is not full we read
    //next projection and put in buffer if there are stubs in the 
    //memory the projection points to
    if (moreproj&&buffernotfull){
      auto const iprojtmp=iproj;
      auto const projdata=inprojdata->read_mem(bx,iprojtmp);
      auto const projzbin=projdata.getZBin();
      iproj++;
      moreproj=iproj<nproj;

      //The first and last zbin the projection points to
      ap_uint<TEBinsBits> zfirst=projzbin.range(3,1);
      ap_uint<TEBinsBits> zlast=zfirst+projzbin.range(0,0);

      //Check if there are stubs in the memory
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
	  ap_uint<kNBitsBuffer> writeindextmpplus=writeindextmp+1;
	  projbuffer[writeindextmpplus]=nstublast.concat(tmp2);
	} else {
	  projbuffer[writeindextmp]=nstublast.concat(tmp2);
	}
      }
    }


    //If the buffer is not empty we have a projection that we need to 
    //process. 
    if (buffernotempty) {

      ap_uint<kNBits_MemAddrBinned> istubtmp=istub;

      //New projection
      if (istub==0) {

	//Need to read the information about the proj in the buffer
        nstubs=qdata.range(29,26);
	zbin=qdata.range(3,1);
	VMProjection<BARREL> data(qdata.range(25,4));

	projindex=data.getIndex();
	projfinez=data.getFineZ();
	projrinv=data.getRInv();
	isPSseed=data.getIsPSSeed();

	second=qdata.range(0,0);	

	//Calculate fine z position
	if (second) {
	  projfinezadj=projfinez-8;
	} else {
	  projfinezadj=projfinez;
	}

	if (nstubs==1) {
	  istub=0;
	  readindex++;
	} else {
	  istub++;
	}
      } else {
	//Check if last stub, if so, go to next buffer entry 
	if (istub+1>=nstubs){
	  istub=0;
	  readindex++;
	} else {
	  istub++;
	}
      }
      
      //Read stub memory and extract data fields
      auto const  stubadd=zbin.concat(istubtmp);
      //typename VMStubME<VMSMEType> stubdata=instubdata->read_mem(bx,stubadd);
      //typename VMStubME<VMSMEType>::VMSMEID stubindex=stubdata.getIndex();
      //typename VMStubME<VMSMEType>::VMSMEFINEZ stubfinez=stubdata.getFineZ();
      //typename VMStubME<VMSMEType>::VMSMEBEND stubbend=stubdata.getBend();
      auto stubdata=instubdata->read_mem(bx,stubadd);
      auto stubindex=stubdata.getIndex();
      auto stubfinez=stubdata.getFineZ();
      auto stubbend=stubdata.getBend();

      //std::cout << "projindex stubindex "<<projindex<<" "<<stubindex<<std::endl;

      //Check if stub z position consistent
      ap_int<5> idz=stubfinez-projfinezadj;
      bool pass;
      if (isPSseed) {
	pass=idz>=-2&&idz<=2;
      } else {
	pass=idz>=-5&&idz<=5;
      }

      //Check if stub bend and proj rinv consistent
      auto const index=projrinv.concat(stubbend);
      //if (pass) {
      //	std::cout << "index "<<index<<" "<<table[index]<<std::endl;
      //}
      if (pass&&table[index]) {
	CandidateMatch cmatch(projindex.concat(stubindex));
	outcandmatch->write_mem(bx,cmatch,ncmatchout);
	ncmatchout ++;
      } // if(pass&&table[index])
      
    } // if(buffernotempty)

    if (istep==kMaxProc-1-8) bx_o = bx;
  } // for (ap_uint<kNBits_MemAddr> istep=0;istep<kMaxProc;istep++) 

} // void MatchEngine()

#endif



#if CODEVERSION==1

//
// This version closely follows the code in the emulations. This version can
// not be pipelined
// This version has not been updated to be compatible with the new memory formats

void MatchEngine(const BXType bx, BXType& bx_o,
		 const VMStubMEMemory* instubdata,
		 const VMProjectionMemory* inprojdata,
		 CandidateMatchMemory* outcandmatch){


#ifndef __SYNTHESIS__
  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;
#endif

  // Initialize the pt-bend lookup table
  bool table[256]; //Need to figure out how to replace 256 with some 
                   //meaning full constant
  readTable(table);

  outcandmatch->clear();

  auto const nproj=inprojdata->getEntries(bx);

  // declare counter for output to CandidateMatch // !!!
  int ncmatchout = 0;
  //Outermost loop is over the projections
  for (ap_uint<kNBits_MemAddr> iproj=0;iproj<nproj;iproj++) {
    //Read projection from memory and extract the elements of the projection
    VMProjection proj=inprojdata->read_mem(bx,iproj);
    VMProjection::VMPID projindex=proj.getIndex();
    VMProjection::VMPZBIN projzbin=proj.getZBin();
    VMProjection::VMPFINEZ projfinez=proj.getFineZ();
    VMProjection::VMPRINV projrinv=proj.getRInv();
    bool isPSseed=proj.getIsPSSeed();
    
    //Calculate first and last zbin that need to searched for stubs
    ap_uint<TEBinsBits> zfirst=projzbin.range(3,1);
    ap_uint<TEBinsBits> zlast=zfirst+projzbin.range(0,0);


    //Loop over the zbins. There are at most two zbins that needs to be searched
    for (ap_uint<TEBinsBits> zbin=zfirst;zbin<=zlast;zbin++){
      ap_uint<kNBits_MemAddrBinned> nstub=instubdata->getEntries(bx,zbin);

      //Loop over the stubs in the bin
      for (ap_uint<kNBits_MemAddrBinned> istub=0;istub<nstub;istub++) {
        //Read the stub memory and extract the elements of the projection
        //VMStubME stubdata=instubdata->read_mem(bx,zbin.concat(istub));
	//VMStubME::VMSMEID stubindex=stubdata.getIndex();
	//VMStubME::VMSMEFINEZ stubfinez=stubdata.getFineZ();
	//VMStubME::VMSMEBEND stubbend=stubdata.getBend();

        auto const stubdata=instubdata->read_mem(bx,zbin.concat(istub));
	auto const stubindex=stubdata.getIndex();
	auto const stubfinez=stubdata.getFineZ();
	auto const stubbend=stubdata.getBend();
	
	//Check is stub and projection satisfies the z cut 
	ap_int<5> idz=stubfinez-projfinez;
	if (zbin!=zfirst) idz+=8;
	bool pass=hls::abs(idz)<=5;
	if (isPSseed) {
	  pass=hls::abs(idz)<=2;
	}

	//Use lookup table for pt-bend matchcing and if stub passes
	//the cut save the projection-stub pair as a candidate match
	auto const index=projrinv.concat(stubbend);
	if (pass&&table[index]) {
	  CandidateMatch cmatch(projindex.concat(stubindex));
	  outcandmatch->write_mem(bx,cmatch,ncmatchout);
	  ncmatchout ++;
	}

      }
    }
  }
}

#endif


#endif
