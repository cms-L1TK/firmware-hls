#ifndef MATCHENGINEUNIT_H
#define MATCHENGINEUNIT_H

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "TrackletProjectionMemory.h"
#include "VMStubMEMemory.h"
#include "VMProjectionMemory.h"
#include "ProjectionRouterBuffer.h"
#include "AllStubMemory.h"
#include "AllProjectionMemory.h"
#include "FullMatchMemory.h"
#include "hls_math.h"
#include <iostream>
#include <fstream>
#include <bitset>

template<int VMProjType> class MatchEngineUnitBase {};

template<>
class MatchEngineUnitBase<BARREL> {
 public:
  enum BitWidths{
    kNBitsBuffer=7,
    kNMatchEngines=8
  };
};

template<int VMSMEType, int VMProjType, int VMPTYPE>
class MatchEngineUnit : public MatchEngineUnitBase<VMProjType> {

 public:
  typedef ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize> STUBID;
  typedef ap_uint<kNBits_MemAddrBinned> NSTUBS;
  typedef ap_uint<MatchEngineUnitBase<VMProjType>::kNBitsBuffer> INDEX;

MatchEngineUnit() {
  nstubs=0;
  idle_ = true;
  done_ = true;
  //stubids=nullptr;

}

~MatchEngineUnit() {
  //delete[] stubids;
}

inline void init(BXType bxin, const INDEX iproj, int iphi) {
//void init(BXType bxin, bool *tab, const VMStubMEMemory<VMSMEType>* instubdata, ProjectionRouterBuffer<BARREL> *proj, const INDEX iproj, int iphi) {
#pragma HLS inline
  //stubmem = instubdata;
  //projbuffer = proj;
  writeindex = iproj;
  readindex = 0;
  idle_ = false;
  done_ = false;
  //table = tab;
  bx = bxin;
  ivmphi = iphi;

}

inline bool empty() {
#pragma HLS inline  
  //buffernotempty=(writeindex!=readindex);
  return (writeindex==readindex);

}

inline bool idle() {
#pragma HLS inline  
  return idle_;
}

inline bool done() {
#pragma HLS inline  
  return done_;
}

inline STUBID* getStubIds() {
#pragma HLS inline  
  return stubids;

}

inline ProjectionRouterBuffer<BARREL>::TCID& getTCID() {
#pragma HLS inline  
  return tcid;
}

inline VMProjection<BARREL>::VMPID& getProjindex() {
#pragma HLS inline  
  return projindex;
}

inline NSTUBS getNStubs() {
#pragma HLS inline  
  return nstubs;
}

inline void read(ProjectionRouterBuffer<BARREL>::TCID& trackletid, VMProjection<BARREL>::VMPID& id, STUBID* stubid, NSTUBS& nstub) {
#pragma HLS inline  
  trackletid = tcid;
  id = projindex;
  nstub = nstubs;
  stubid = stubids;
  // Deep copy
  /*
  stubid = new ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize>[nstubs];
  for(int i = 0; i < nstubs; ++i)
    stubid[i] = stubids[i];
  */
  //idle_ = false;
  idle_ = readindex>writeindex;

}

inline void read() {
#pragma HLS inline  
  nstubs = 0;
  idle_ = readindex>writeindex;

}

inline bool step(bool *table, const VMStubMEMemory<VMSMEType>* stubmem, ProjectionRouterBuffer<BARREL> *projbuffer) {
#pragma HLS inline
#pragma HLS PIPELINE II=1
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=0
#pragma HLS ARRAY_PARTITION variable=stubids complete dim=0
#pragma HLS ARRAY_PARTITION variable=table complete dim=0

    ////////////////////////////////////////////
    //This seems like where the ME buffer starts
    //Goes outside if(valid) ?
    ////////////////////////////////////////////
    //If the buffer is not empty we have a projection that we need to 
    //process. 

    //Determin if buffere is empty
    //Buffer for projections
    //readindex = istep;
    //bool buffernotempty=(writeindex1!=readindex);
    bool buffernotempty=(writeindex!=readindex);
    //bool buffernotlarger=(readindex<=writeindex1);
    bool buffernotlarger=(readindex<=writeindex);
      /* FIXME
    std::cout << "buffernotempty=" << buffernotempty << std::endl;
    std::cout << std::dec << "istep=" << istep << "\tistub=" << istub << std::endl;
      std::cout << std::hex << "writeindex[iphi]=" << writeindex << "\treadindex[iphi]=" << readindex << std::endl;
    */
 
    // vmproj index
    typename VMProjection<VMPTYPE>::VMPZBIN projzbin;
  int ncmatchout = 0;

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
      //std::cout << "writeindex[" << ivmphi << "]=" << writeindex[ivmphi] << "\treadindex[" << ivmphi << "]=" << readindex << std::endl;
  if (!empty() && buffernotlarger) {

      ap_uint<kNBits_MemAddrBinned> istubtmp=istub;

      //std::cout << "readindex[" << ivmphi << "]=" << readindex << std::endl;
      //New projection
      if (istub==0) {
        //delete[] stubids;
        //stubids = new ap_uint<VMStubMEBase<VMSMEType>::kVMSMEIndexSize>[nstubs];
        for(int i = 0; i < 1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer; ++i)
          stubids[i]=0;

        //Need to read the information about the proj in the buffer
        //std::cout << "nproj=" << writeindex1 << std::endl;
        auto const qdata=projbuffer[readindex];
        //std::cout << "MEU "; projbuffer[readindex].Print();
        tcid=qdata.getTCID();
        //projbuffer[readindex].Print();
        /*
        ProjectionRouterBuffer<BARREL> *qdata;
        switch (ivmphi) {
          case 0: qdata=projbuffer1[readindex];
          break;
          case 1: qdata=projbuffer2[readindex];
          break;
          case 2: qdata=projbuffer3[readindex];
          break;
          case 3: qdata=projbuffer4[readindex];
          break;
          case 4: qdata=projbuffer5[readindex];
          break;
          case 5: qdata=projbuffer6[readindex];
          break;
          case 6: qdata=projbuffer7[readindex];
          break;
          case 7: qdata=projbuffer8[readindex];
          break;
        }
        */
        auto nstub = qdata.getNStubs();
        nstubs=qdata.getNStubs();
        VMProjection<BARREL> data(qdata.getProjection());
         zbin=qdata.getZBin();
      /* FIXME
      std::cout << std::hex << "data=" << data.raw() << std::endl;
      std::cout << "who's proj=" << data.raw() << std::endl;
      std::cout << std::dec << "nstubs=" << nstubs << std::endl;
      std::cout << std::hex << "zbin=" << zbin << "\tistubtmp=" << istubtmp << std::endl;
      std::cout << "concat=" << zbin.concat(istubtmp) << std::endl;
      */
    /* FIXME
    {
    auto iphiproj = allproj->read_mem(bx, istep).getPhi();
    auto iphi5 = iphiproj>>(iphiproj.length()-5);
constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};
constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmmedisks[5]={8,4,4,4,4};
    auto nvm = LAYER!=0 ? nvmmelayers[LAYER-1]*nallstubslayers[LAYER-1] :
      nvmmedisks[DISK-1]*nallstubsdisks[DISK-1];
    auto nbins = LAYER!=0 ? nvmmelayers[LAYER-1] : nvmmedisks[DISK-1];
    ap_uint<3> iphi = (iphi5/(32/nvm))&(nbins-1);  // OPTIMIZE ME
      if(iphi==3 || 1) {
      std::cout << "read from buffer address=" << readindex << std::endl;
      std::cout << std::hex << "vmproj=" << std::bitset<VMProjectionBase<BARREL>::kVMProjectionSize>( data.raw() ) << std::endl;
  std::cout << std::dec << std::bitset<VMProjectionBase<BARREL>::kVMProjIndexSize>(data.getIndex()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjZBinSize>(data.getZBin()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjFineZSize>(data.getFineZ()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjRinvSize>(data.getRInv()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjIsPSSeedSize>(data.getIsPSSeed()) << std::endl << std::endl;
      std::cout << std::hex << "projid=" << data.getIndex() << std::endl;
      std::cout << "###" << std::endl;
      std::cout << std::hex << "\treadindex[iphi]=" << readindex << std::endl;
      std::cout << "buffernotempty=" << buffernotempty << std::endl;
      }
    }
    */

        projindex=data.getIndex();
        auto projfinez=data.getFineZ();
        projrinv=data.getRInv();
        isPSseed=data.getIsPSSeed();
        auto projzbin=qdata.getZBin();

        auto second=qdata.hasSecond();
        //second=qdata.range(0,0);	

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
      /* FIXME
      std::cout << "zbin=" << zbin << "\tistubtmp=" << istubtmp << std::endl;
      std::cout << "stubadd=" << stubadd << std::endl;
      std::cout << "concat=" << zbin.concat(istubtmp) << std::endl;
      */
      //auto stubdata=instubdata->read_mem(bx,stubadd);
      const VMStubME<VMSMEType> stubdata=stubmem->read_mem(bx,stubadd);
      auto stubindex=stubdata.getIndex();
      auto stubfinez=stubdata.getFineZ();
      auto stubbend=stubdata.getBend();

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
      if (pass&&table[index]) {
        //outcandmatch->write_mem(bx,cmatch,ncmatchout);
        ncmatchout ++;
      /* FIXME
        std::cout << std::hex << "projindex[iphi]=" << projindex << " stubindex=" << stubindex << std::endl;
    std::cout << "stubadd=" << stubadd << std::endl;
        //istep is projid
      std::cout << "tproj" << std::endl;
  std::cout << std::dec <<  "index=" << projindex << std::endl
            << std::hex << "projfinez=" << projfinez << std::endl
            << "rinv=" << projrinv << std::endl
            << "isPSSeed=" << isPSseed << std::endl << std::endl;
      std::cout << "###" << std::endl;
      VMProjection<VMPTYPE> vmproj(projindex, projzbin, projfinez, projrinv, isPSseed);
      std::cout << std::hex << "vmproj=" << std::bitset<VMProjectionBase<BARREL>::kVMProjectionSize>( vmproj.raw() ) << std::endl;
  std::cout << std::dec << std::bitset<VMProjectionBase<BARREL>::kVMProjIndexSize>(vmproj.getIndex()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjZBinSize>(vmproj.getZBin()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjFineZSize>(vmproj.getFineZ()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjRinvSize>(vmproj.getRInv()) << " "
            << std::bitset<VMProjectionBase<BARREL>::kVMProjIsPSSeedSize>(vmproj.getIsPSSeed()) << std::endl << std::endl;
      */
      CandidateMatch cmatch(projindex.concat(stubindex));
      stubids[istubtmp]=stubindex;
      //delete qdata; //Free up mem when finished with projbuffer entry
    } // if(pass&&table[index])
    //if(istub==0 && stubids!=0) idle_ = true;
    if(istub==0 && nstubs>0) idle_ = true;
    if(readindex>writeindex) done_ = true;
 
    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // Use the stub and projection indices to pick up the stub and projection
    /*
    VMProjection<BARREL> data(qdata.getProjection());
    //VMProjection<BARREL> data(qdata.range(25,4));
    auto projid = data.getIndex();
    auto stubid = stubdata.getIndex();
	CandidateMatch cmatch(projindex.concat(stubindex));
    if(projindex == 39) std::cout << std::bitset<7>(stubindex) << std::endl;
    if(cmatch.raw() == 0x1135) std::cout << "found one!" << std::endl;
    MatchCalculator<ASTYPE, APTYPE, VMSMEType, FMTYPE, LAYER, PHISEC>
              (bx, allstub, allproj, istep, stubid, istep, bx_o,
               fullmatch1, fullmatch2, fullmatch3, fullmatch4, fullmatch5, fullmatch6, fullmatch7);
    delete qdata; //Free up mem when finished with projbuffer entry
    */

  } // if(buffernotempty)

  return idle_;
} // end step

 private:
  //ProjectionRouterBuffer<BARREL> *projbuffer;//[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];  //projbuffer = nstub+projdata+finez
  //const VMStubMEMemory<VMSMEType>* stubmem;
  INDEX writeindex;
  INDEX readindex;
  NSTUBS nstubs;
  bool idle_;
  bool done_;
  int istep_;
  int ivmphi;
  BXType bx;
  //bool *table;//[256];
  NSTUBS istub=0;
  STUBID stubids[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  ProjectionRouterBuffer<BARREL>::TCID tcid;
  ProjectionRouterBuffer<BARREL>::PRHASSEC isPSseed;
  ProjectionRouterBuffer<BARREL>::VMPZBIN zbin;
  VMProjection<BARREL>::VMPRINV projrinv;
  VMProjection<BARREL>::VMPID projindex;

}; // end class


#endif
