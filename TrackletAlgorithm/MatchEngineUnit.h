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

}

inline void init(BXType bxin, ProjectionRouterBuffer<BARREL> projbuffer_, const VMStubMEMemory<VMSMEType,3>* stubmem_, const INDEX iproj) {
#pragma HLS inline
  writeindex = iproj;
  readindex = 0;
  idle_ = false;
  done_ = false;
  bx = bxin;
  projbuffer = projbuffer_;
  ivmphi = projbuffer_.getPhi();
  stubmem = stubmem_;
  //std::cout << std::hex << "Initializing iphi=" << ivmphi << "\t" << projbuffer.raw() << " Received writeindex=" << writeindex << std::endl;
  //projbuffer.Print();

}

bool empty() {
#pragma HLS inline  
  return (writeindex==0);

}

bool idle() {
#pragma HLS inline  
  //std::cout << std::hex << "iphi=" << ivmphi << (idle_ ? "": " not") << " idle!" << std::endl;
  return idle_;
}

bool done() {
#pragma HLS inline  
  //std::cout << projbuffer.raw() << " " << " iphi=" << ivmphi << (done_ ? "": " not") << " done!" << std::endl;
  return done_;
}

STUBID* getStubIds() {
#pragma HLS inline  
  return stubids;

}

ProjectionRouterBuffer<BARREL>::TCID& getTCID() {
#pragma HLS inline  
  return tcid;
}

VMProjection<BARREL>::VMPID& getProjindex() {
#pragma HLS inline  
  return projindex;
}

NSTUBS getNStubs() {
#pragma HLS inline  
  return nstubs;
}

void read(ProjectionRouterBuffer<BARREL>::TCID& trackletid, VMProjection<BARREL>::VMPID& id, STUBID* stubid, NSTUBS& nstub) {
#pragma HLS inline  
  //std::cout << "reading MEU " << projbuffer.raw() << "\tprojid=" << projbuffer.getIndex() << "\t" << "iphi=" << ivmphi << "\treading=" << readindex << "\tmax=" << writeindex << std::endl;
  trackletid = tcid;
  id = projindex;
  nstub = nstubs;
  idle_ = true;

}

//inline bool step(bool *table, const VMStubMEMemory<VMSMEType,3>* stubmem, ProjectionRouterBuffer<BARREL> *projbuffer) {
inline bool step(bool *table) {//, const VMStubMEMemory<VMSMEType,3>* stubmem) {
#pragma HLS inline
#pragma HLS dependence variable=istub inter WAR true
    //std::cout << "step " << projbuffer.raw() << "\t" << "iphi=" << ivmphi << "\treading=" << readindex << "\tmax=" << writeindex << std::endl;
    if(idle() || done()) return true;

    ////////////////////////////////////////////
    //This seems like where the ME buffer starts
    //Goes outside if(valid) ?
    ////////////////////////////////////////////
    //If the buffer is not empty we have a projection that we need to 
    //process. 

    //Determin if buffere is empty
    //Buffer for projections
    bool buffernotempty=(writeindex!=readindex);
    bool buffernotlarger=(readindex<=writeindex);
 
    // vmproj index
    typename VMProjection<VMPTYPE>::VMPZBIN projzbin;

  // Buffer still has projections to read out
  //If the buffer is not empty we have a projection that we need to 
  //process. 
  if (!empty() && !done()) {// && buffernotlarger) {

      ap_uint<kNBits_MemAddrBinned> istubtmp=istub;

      if (istub==0) {
        SID_LOOP: for(int i = 0; i < 1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer; ++i) {
//#pragma HLS PIPELINE II=1
#pragma HLS unroll
          stubids[i]=0;
        }

        //Need to read the information about the proj in the buffer
        auto const qdata=projbuffer;
        tcid=qdata.getTCID();
        auto nstub = qdata.getNStubs();
        nstubs=qdata.getNStubs();
        VMProjection<BARREL> data(qdata.getProjection());
        zbin=qdata.getZBin();

        projindex=data.getIndex();
        auto projfinez=data.getFineZ();
        projrinv=data.getRInv();
        isPSseed=data.getIsPSSeed();
        auto projzbin=qdata.getZBin();

        auto second=qdata.hasSecond();

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
      stubids[istubtmp]=stubindex;
      //std::cout << std::hex << "MEU found stubid=" << stubindex << std::endl;
    } // if(pass&&table[index])
    //if(istub==0 && nstubs>0) idle_ = true;
    if(readindex>writeindex) done_ = true;
    //if(istub==0 && nstubs>0) return true;
    if(done_) return true;
 
    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // Use the stub and projection indices to pick up the stub and projection

  } // if(buffernotempty)
  return false;

} // end step

 private:
  INDEX writeindex;
  INDEX readindex;
  NSTUBS nstubs;
  bool idle_;
  bool done_;
  int istep_;
  int ivmphi;
  BXType bx;
  NSTUBS istub=0;
  STUBID stubids[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  ProjectionRouterBuffer<BARREL>::TCID tcid;
  ProjectionRouterBuffer<BARREL>::PRHASSEC isPSseed;
  ProjectionRouterBuffer<BARREL>::VMPZBIN zbin;
  VMProjection<BARREL>::VMPRINV projrinv;
  VMProjection<BARREL>::VMPID projindex;
  const VMStubMEMemory<VMSMEType,3>* stubmem;
  ProjectionRouterBuffer<BARREL> projbuffer;

}; // end class


#endif
