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


/* 

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

  ap_uint<1> write=1;
  ap_uint<3> writeindex=0;
  ap_uint<3> readindex=0;
  ap_uint<20> queue[8];
  unsigned int iproj=0;

  int istub=0;
  int zbin=0;
  VMPID projindex;
  VMPZBIN projzbin;
  VMPFINEZ projfinez;
  VMPBEND projbend;
  bool isPSseed;
  ap_uint<3> zfirst;
  ap_uint<3> zlast;
  int nstubs;

  ap_uint<1> wrotefirst=0;
  
  for (unsigned int istep=0;istep<108;istep++) {
#pragma HLS PIPELINE II=1
    if (iproj<inprojdata.getEntries(bx)){
      projindex=VMProjections::get_index(inprojdata.read_mem(bx,iproj));
      projzbin=VMProjections::get_zbin(inprojdata.read_mem(bx,iproj));
      projfinez=VMProjections::get_finez(inprojdata.read_mem(bx,iproj));
      projbend=VMProjections::get_bend(inprojdata.read_mem(bx,iproj));
      isPSseed=VMProjections::get_PSseed(inprojdata.read_mem(bx,iproj));
      //std::cout << "proj : "<<inprojdata[iproj]<<" "<<projindex<<" "<<projzbin 
    //      <<" "<<projfinez<<" "<<projbend<<" "<<isPSseed<< std::endl;
      zfirst=projzbin.range(3,1);
      zlast=zfirst+projzbin.range(0,0);
      assert(zlast<8);
      ap_uint<1> wroteonce=0;
      if ((instubdata.getEntries(bx,zfirst)>0)&&(!wrotefirst)) {
	queue[writeindex++]=inprojdata.read_mem(bx,iproj).concat(zfirst);
	wrotefirst=1;
	wroteonce=1;
      }
      if ((instubdata.getEntries(bx,zlast)>0)&&(!wroteonce)) {
	queue[writeindex++]=inprojdata.read_mem(bx,iproj).concat(zlast);
	wrotefirst=1;
      }

    }

    if (istub==0) {
      if (writeindex!=readindex) {
	
	ap_uint<3> zbin=queue[readindex].range(2,0);
	VMProj data=queue[readindex].range(24,3);
	readindex++;
	
	projindex=VMProjections::get_index(data);
	projfinez=VMProjections::get_finez(data);
	projbend=VMProjections::get_bend(data);
	isPSseed=VMProjections::get_PSseed(data);
  

	//std::cout << "zbin nstubs "<<zbin<<" "<<nstubs<<std::endl;
	VMPID stubindex=VMStubs::get_index(instubdata.read_mem(bx,istub+16*zbin));
	VMPFINEZ stubfinez=VMStubs::get_finez(instubdata.read_mem(bx,istub+16*zbin));
	VMPBEND stubbend=VMStubs::get_bend(instubdata.read_mem(bx,istub+16*zbin));
	istub++;
	if (istub>=instubdata.getEntries(bx,zbin)){
	  istub=0;
	}

	int idz=stubfinez-projfinez;
	if (zbin!=zfirst) idz+=8;
	bool pass=hls::abs(idz)<=5;
	if (isPSseed) {
	  pass=hls::abs(idz)<=2;
	}
	int index=stubbend+projbend*8;

	if (pass&&table[index]) {
	  CandidateMatch cmatch=projindex;
	  cmatch=(cmatch<<7)+stubindex;
	  outcandmatch.write_mem(bx,cmatch);
	}

      }
    } else {

	//std::cout << "zbin nstubs "<<zbin<<" "<<nstubs<<std::endl;
	VMPID stubindex=VMStubs::get_index(instubdata.read_mem(bx,istub+16*zbin));
	VMPFINEZ stubfinez=VMStubs::get_finez(instubdata.read_mem(bx,istub+16*zbin));
	VMPBEND stubbend=VMStubs::get_bend(instubdata.read_mem(bx,istub+16*zbin));
	istub++;
	if (istub>=instubdata.getEntries(bx,zbin)){
	  istub=0;
	}

	int idz=stubfinez-projfinez;
	if (zbin!=zfirst) idz+=8;
	bool pass=hls::abs(idz)<=5;
	if (isPSseed) {
	  pass=hls::abs(idz)<=2;
	}
	int index=stubbend+projbend*8;

	if (pass&&table[index]) {
	  CandidateMatch cmatch=projindex;
	  cmatch=(cmatch<<7)+stubindex;
	  outcandmatch.write_mem(bx,cmatch);
	}

    }

  }

}


*/

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
      projindex=VMProjections::get_index(inprojdata.read_mem(bx,iproj));
      projzbin=VMProjections::get_zbin(inprojdata.read_mem(bx,iproj));
      projfinez=VMProjections::get_finez(inprojdata.read_mem(bx,iproj));
      projbend=VMProjections::get_bend(inprojdata.read_mem(bx,iproj));
      isPSseed=VMProjections::get_PSseed(inprojdata.read_mem(bx,iproj));
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

