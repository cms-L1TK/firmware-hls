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


#define NEWCODE 1

#ifdef NEWCODE

//Attempt at new version of code
void MatchEngine(const ap_uint<3> bx,
		    const VMStubs& instubdata,
		    const VMProjections& inprojdata,
		    CandidateMatches& outcandmatch){


  std::cout << "In MatchEngine #proj ="<<hex<<inprojdata.getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata.getEntries(bx,zbin);
  }
  std::cout<<dec<<std::endl;

  bool table[256];

  readTable(table);

  outcandmatch.clear();

  //Read projections and check that there are stubs in memories
  ap_uint<3> writeindex=0;
#pragma HLS dependence variable=writeindex intra WAR true
#pragma HLS dependence variable=writeindex intra RAW true
#pragma HLS dependence variable=writeindex intra WAW true
  ap_uint<3> writeindexa=0;
  ap_uint<3> writeindex1=0;
#pragma HLS dependence variable=writeindex1 intra WAR true
  //#pragma HLS dependence variable=writeindex1 intra RAW true
    //#pragma HLS dependence variable=writeindex1 intra WAW true

  ap_uint<3> readindex=0;
  ap_uint<30> queue[8];
  //  ap_uint<30> queuer[8];

#pragma HLS ARRAY_PARTITION variable=queue complete dim=0
  //#pragma HLS ARRAY_PARTITION variable=queuer complete dim=0

  
  ap_uint<7> iproj=0;
#pragma HLS dependence variable=iproj intra WAR true
#pragma HLS dependence variable=iproj intra RAW true
#pragma HLS dependence variable=iproj intra WAW true

  ap_uint<3> zbin=0;
  VMPID projindex;
  VMPFINEZ projfinez;
  ap_int<5> projfinezadj;
  VMPBEND projbend;
  bool isPSseed;
  ap_uint<4> nstubs=0;
  ap_uint<4> istub=0;

#pragma HLS dependence variable=istub intra WAR true
  //#pragma HLS dependence variable=nstubs inter WAR true

  bool second=false;
  //bool wrotefirst=false;

  ap_uint<7> nproj=inprojdata.getEntries(bx);
  bool moreproj=iproj<nproj;
  
  for (unsigned int istep=0;istep<108;istep++) {
#pragma HLS PIPELINE II=1

    //#pragma HLS dependence variable=queue intra false
    //#pragma HLS dependence variable=queue inter false
    


    writeindex=writeindexa;
    writeindexa=writeindex1;
    ap_uint<7> writeindexplus=writeindex1+1;
    ap_uint<7> writeindexplusplus=writeindex1+2;
    bool queuenotfull=(writeindex+1!=readindex)&&(writeindex+2!=readindex);
    bool queuenotempty=(writeindex!=readindex);
    if (moreproj&&queuenotfull){
      ap_uint<7> iprojtmp=iproj;
      VMProj projdata=inprojdata.read_mem(bx,iprojtmp);
      VMPZBIN projzbin=VMProjections::get_zbin(projdata);
      iproj++;
      moreproj=iproj<nproj;
      ap_uint<3> zfirst=projzbin.range(3,1);
      ap_uint<3> zlast=zfirst+projzbin.range(0,0);
      assert(zlast<8);
      ap_uint<4> nstubfirst=instubdata.getEntries(bx,zfirst);
      ap_uint<4> nstublast=instubdata.getEntries(bx,zlast);
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

      //bool wroteonce=false;
      if (savefirst) {
	//std::cout << "Save in queue iproj="<<iproj<<" at index ="<<writeindex<<" zbin="<<zfirst<<std::endl;
	ap_uint<1> zero=0;
	ap_uint<4> tmp=zfirst.concat(zero);
	ap_uint<26> tmp2=projdata.concat(tmp);
	queue[writeindextmp]=nstubfirst.concat(tmp2);
      }
      if (savelast) {
	//std::cout << "Save in queue iproj="<<iproj<<" at index ="<<writeindex<<" zbin="<<zlast<<std::endl;
	ap_uint<1> one=1;
	ap_uint<4> tmp=zlast.concat(one);
	ap_uint<26> tmp2=projdata.concat(tmp);
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

	ap_uint<30> qdata=queue[readindex];
        nstubs=qdata.range(29,26);
	zbin=qdata.range(3,1);
	VMProj data=qdata.range(25,4);

	projindex=VMProjections::get_index(data);
	projfinez=VMProjections::get_finez(data);
	projbend=VMProjections::get_bend(data);
	isPSseed=VMProjections::get_PSseed(data);

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
      //std::cout << "zbin nstubs "<<zbin<<" "<<nstubs<<std::endl;
      ap_uint<7> stubadd=zbin.concat(istubtmp);
      VMStubs::VMStub stubdata=instubdata.read_mem(bx,stubadd);
      VMPID stubindex=VMStubs::get_index(stubdata);
      VMPFINEZ stubfinez=VMStubs::get_finez(stubdata);
      VMStubs::VMSBEND stubbend=VMStubs::get_bend(stubdata);
      //std::cout << "istub zbin nstub second "<<istub<<" "<<zbin<<" "<<instubdata.getEntries(bx,zbin)<<" "<<second<<std::endl;

      //std::cout << "projfinez projfinezadj second : "<<projfinez<<" "<<projfinezadj<<" "<<second<<endl;
      ap_int<5> idz=stubfinez-projfinezadj;
      //if (second!=0) idz+=8;
      bool pass;
      if (isPSseed) {
	pass=idz>=-2&&idz<=2;
      } else {
	pass=idz>=-5&&idz<=5;
      }
      ap_uint<8> index=projbend.concat(stubbend);
      
      //std::cout << "projindex stubindex index pass "<<projindex<<" "<<stubindex<<" "<<index<<" "<<pass<<std::endl;

      if (pass&&table[index]) {
	CandidateMatch cmatch=projindex.concat(stubindex);
	outcandmatch.write_mem(bx,cmatch);
      }
      
    }

  }

}


#else

void MatchEngine(const ap_uint<3> bx,
		 const VMStubs& instubdata,
		 const VMProjections& inprojdata,
		 CandidateMatches& outcandmatch){

  std::cout << "In MatchEngine #proj ="<<hex<<inprojdata.getEntries(bx)<<" #stubs=";
  for (unsigned int zbin=0;zbin<8;zbin++){
    std::cout <<" "<<instubdata.getEntries(bx,zbin);
  }
  std::cout<<dec<<std::endl;

  bool table[256];

  readTable(table);

  outcandmatch.clear();

  unsigned int iproj=0;
  int istub=0;
  int zbin=0;
  VMPID projindex;
  VMPZBIN projzbin;
  VMPFINEZ projfinez;
  VMPBEND projbend;
  bool isPSseed;
  int zfirst;
  int zlast;
  int nstubs;

  for (unsigned int istep=0;istep<108;istep++) {
#pragma HLS PIPELINE II=1
    if (istep==0||(istep>0&&zbin>zlast)) {
      if (istep>0&&zbin>zlast) {
	iproj++;
	if (iproj>=inprojdata.getEntries(bx)) continue;
      }
      VMProj proj=inprojdata.read_mem(bx,iproj);
      projindex=VMProjections::get_index(proj);
      projzbin=VMProjections::get_zbin(proj);
      projfinez=VMProjections::get_finez(proj);
      projbend=VMProjections::get_bend(proj);
      isPSseed=VMProjections::get_PSseed(proj);
      //std::cout << "proj : "<<inprojdata[iproj]<<" "<<projindex<<" "<<projzbin 
    //      <<" "<<projfinez<<" "<<projbend<<" "<<isPSseed<< std::endl;
      zfirst=projzbin.range(3,1);
      zlast=zfirst+projzbin.range(0,0);
      assert(zlast<8);
      zbin=zfirst;
      nstubs=instubdata.getEntries(bx,zbin);
      //std::cout << "zfirst zlast : "<<zfirst<<" "<<zlast<<std::endl;
    }
    if (nstubs>0) {
      //std::cout << "zbin nstubs "<<zbin<<" "<<nstubs<<std::endl;
      VMPID stubindex=VMStubs::get_index(instubdata.read_mem(bx,istub+16*zbin));
      VMPFINEZ stubfinez=VMStubs::get_finez(instubdata.read_mem(bx,istub+16*zbin));
      VMPBEND stubbend=VMStubs::get_bend(instubdata.read_mem(bx,istub+16*zbin));

      int idz=stubfinez-projfinez;
      if (zbin!=zfirst) idz+=8;
      bool pass=hls::abs(idz)<=5;
      if (isPSseed) {
	pass=hls::abs(idz)<=2;
      }
      int index=stubbend+projbend*8;

      //if (pass){
      //std::cout << "index table[index] : "<<index<<" "<<table[index]<<std::endl;
      //}

      std::cout << "projindex stubindex index pass "<<projindex<<" "<<stubindex<<" "<<index<<" "<<pass<<std::endl;

      if (pass&&table[index]) {
	CandidateMatch cmatch=projindex;
	cmatch=(cmatch<<7)+stubindex;
	outcandmatch.write_mem(bx,cmatch);
      }

      //std::cout << "Cand match "<<projindex<<" "<<stubindex<<" "
      //	  <<pass<<" "<<table[index]<<" "<<projbend<<std::endl;
      //std::cout << "stubfinez projfinez "<<stubfinez<<" "<<projfinez<<endl;
    }
    if ((++istub)>=nstubs) {
      istub=0;
      if ((zbin++)<=zlast) {
	nstubs=instubdata.getEntries(bx,zbin);
      }
    }
  }

}

#endif
