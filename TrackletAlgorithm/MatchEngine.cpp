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
// 2 - This version flattens the loops to one loop. Loop is pipelined
//     with II=4
// 3 - Version 2 has been modified to use a queue for the projections.
//     It reaches II=1
//
#define CODEVERSION 3

#if CODEVERSION==3

//Attempt at new version of code
void MatchEngine(const ap_uint<3> bx,
		 const VMStubMemory *instubdata,
		 const VMProjectionMemory* inprojdata,
		 CandidateMatchMemory* outcandmatch){


  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;

  bool table[256];

  readTable(table);

  outcandmatch->clear();

  //Read projections and check that there are stubs in memories
  ap_uint<3> writeindex=0;


  ap_uint<3> writeindex1=0;

  ap_uint<3> readindex=0;
  ap_uint<30> queue[8];

#pragma HLS ARRAY_PARTITION variable=queue complete dim=0


  ap_uint<7> iproj=0;

  ap_uint<3> zbin=0;
  VMProjection::VMPID projindex;
  VMProjection::VMPFINEZ projfinez;
  ap_int<5> projfinezadj;
  VMProjection::VMPRINV projbend;
  bool isPSseed;
  ap_uint<4> nstubs=0;
  ap_uint<4> istub=0;

#pragma HLS dependence variable=istub intra WAR true

  bool second=false;

  ap_uint<7> nproj=inprojdata->getEntries(bx);
  bool moreproj=iproj<nproj;
  
  for (unsigned int istep=0;istep<108;istep++) {
#pragma HLS PIPELINE II=1

    ap_uint<30> qdata=queue[readindex];

    writeindex=writeindex1;
    ap_uint<7> writeindexplus=writeindex1+1;
    ap_uint<7> writeindexplusplus=writeindex1+2;
    bool queuenotfull=(writeindex+1!=readindex)&&(writeindex+2!=readindex);
    bool queuenotempty=(writeindex!=readindex);
    if (moreproj&&queuenotfull){
      ap_uint<7> iprojtmp=iproj;
      VMProjection projdata=inprojdata->read_mem(bx,iprojtmp);
      VMProjection::VMPZBIN projzbin=projdata.GetZBin();
      iproj++;
      moreproj=iproj<nproj;
      ap_uint<3> zfirst=projzbin.range(3,1);
      ap_uint<3> zlast=zfirst+projzbin.range(0,0);
      assert(zlast<8);
      ap_uint<4> nstubfirst=instubdata->getEntries(bx,zfirst);
      ap_uint<4> nstublast=instubdata->getEntries(bx,zlast);
      bool savefirst=nstubfirst!=0;
      bool savelast=nstublast!=0&&projzbin.range(0,0);
      ap_uint<3> writeindextmp=writeindex1;

      if (savefirst) {
	if (savelast) {
	  writeindex1=writeindexplusplus;
	} else {
	  writeindex1=writeindexplus;
	}
      } else {
	if (savelast) {
	  writeindex1=writeindexplus;
	}
      }

      if (savefirst) {
	ap_uint<1> zero=0;
	ap_uint<4> tmp=zfirst.concat(zero);
	ap_uint<26> tmp2=projdata.raw().concat(tmp);
	queue[writeindextmp]=nstubfirst.concat(tmp2);
      }
      if (savelast) {
	ap_uint<1> one=1;
	ap_uint<4> tmp=zlast.concat(one);
	ap_uint<26> tmp2=projdata.raw().concat(tmp);
	if (savefirst) {
	  queue[writeindextmp+1]=nstublast.concat(tmp2);
	} else {
	  queue[writeindextmp]=nstublast.concat(tmp2);
	}
      }
    }

    if (queuenotempty) {
      ap_uint<4> istubtmp=istub;
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
      ap_uint<7> stubadd=zbin.concat(istubtmp);
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
      ap_uint<8> index=projbend.concat(stubbend);

      if (pass&&table[index]) {
	CandidateMatch cmatch(projindex.concat(stubindex));
	outcandmatch->write_mem(bx,cmatch);
      }
      
    }

  }

}

#endif

#if CODEVERSION==2

void MatchEngine(const ap_uint<3> bx,
		 const VMStubMemory* instubdata,
		 const VMProjectionMemory* inprojdata,
		 CandidateMatchMemory* outcandmatch){

  std::cout << "In MatchEngine #proj ="<<std::hex<<inprojdata->getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata->getEntries(bx,zbin);
  }
  std::cout<<std::dec<<std::endl;

  bool table[256];

  readTable(table);

  outcandmatch->clear();

  unsigned int iproj=0;
  int istub=0;
  int zbin=0;
  VMProjection::VMPID projindex;
  VMProjection::VMPZBIN projzbin;
  VMProjection::VMPFINEZ projfinez;
  VMProjection::VMPRINV projbend;
  bool isPSseed;
  int zfirst;
  int zlast;
  int nstubs;

  for (unsigned int istep=0;istep<108;istep++) {
#pragma HLS PIPELINE II=1
    if (istep==0||(istep>0&&zbin>zlast)) {
      if (istep>0&&zbin>zlast) {
	iproj++;
	if (iproj>=inprojdata->getEntries(bx)) continue;
      }
      VMProjection proj=inprojdata->read_mem(bx,iproj);
      projindex=proj.GetIndex();
      projzbin=proj.GetZBin();
      projfinez=proj.GetFineZ();
      projbend=proj.GetRInv();
      isPSseed=proj.GetIsPSSeed();
      //std::cout << "proj : "<<inprojdata[iproj]<<" "<<projindex<<" "<<projzbin 
    //      <<" "<<projfinez<<" "<<projbend<<" "<<isPSseed<< std::endl;
      zfirst=projzbin.range(3,1);
      zlast=zfirst+projzbin.range(0,0);
      assert(zlast<8);
      zbin=zfirst;
      nstubs=instubdata->getEntries(bx,zbin);
      //std::cout << "zfirst zlast : "<<zfirst<<" "<<zlast<<std::endl;
    }
    if (nstubs>0) {
      //std::cout << "zbin nstubs "<<zbin<<" "<<nstubs<<std::endl;
      VMStub stubdata=instubdata->read_mem(bx,istub+16*zbin);
      VMStub::VMSID stubindex=stubdata.GetIndex();
      VMStub::VMSFINEZ stubfinez=stubdata.GetFineZ();
      VMStub::VMSBEND stubbend=stubdata.GetBend();

      int idz=stubfinez-projfinez;
      if (zbin!=zfirst) idz+=8;
      //std::cout << "isPSseed idz "<<isPSseed<<" "<<idz<<" "<<stubfinez<<" "<<projfinez<<std::endl;
      bool pass=hls::abs(idz)<=5;
      if (isPSseed) {
	pass=hls::abs(idz)<=2;
      }
      int index=stubbend+projbend*8;

      //if (pass){
      //std::cout << "index table[index] : "<<index<<" "<<table[index]<<std::endl;
      //}

      //std::cout << "projindex stubindex index pass "<<projindex<<" "<<stubindex<<" "<<index<<" "<<pass<<std::endl;

      if (pass&&table[index]) {
	CandidateMatch cmatch(projindex.concat(stubindex));
	outcandmatch->write_mem(bx,cmatch);
      }

      //std::cout << "Cand match "<<projindex<<" "<<stubindex<<" "
      //	  <<pass<<" "<<table[index]<<" "<<projbend<<std::endl;
      //std::cout << "stubfinez projfinez "<<stubfinez<<" "<<projfinez<<endl;
    }
    if ((++istub)>=nstubs) {
      istub=0;
      if ((zbin++)<=zlast) {
	nstubs=instubdata->getEntries(bx,zbin);
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
  bool table[256];
  readTable(table);

  outcandmatch->clear();

  ap_uint<7> nproj=inprojdata->getEntries(bx);

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

