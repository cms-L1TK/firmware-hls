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
  ptr = 0;
  idle_ = true;
  done_ = true;

}

inline void init(BXType bxin, ProjectionRouterBuffer<BARREL> projbuffer_, const INDEX iproj, int unit) {
#pragma HLS inline
  writeindex = iproj;
  readindex = 0;
  idle_ = false;
  done_ = false;
  bx = bxin;
  projbuffer = projbuffer_;
  projindex = projbuffer_.getIndex();
  ivmphi = projbuffer_.getPhi();
  ptr = 0;
  unit_ = unit;
  //std::cout << "Initializing MEU " << unit_ << std::endl;
  //print();
  //stubmem = stubmem_;
  //std::cout << std::hex << "Initializing iphi=" << ivmphi << "\t" << projbuffer.raw() << " Received writeindex=" << writeindex << std::endl;
  //projbuffer.Print();

}

bool empty() {
#pragma HLS inline  
  return (readindex==0);

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

bool ready() {
#pragma HLS inline  
  return ptr < readindex;
}

STUBID* getStubIds() {
#pragma HLS inline  
  return stubids;

}

ProjectionRouterBuffer<BARREL>::TCID& getTCID() {
#pragma HLS inline  
  return tcid;
}

VMProjection<BARREL>::VMPID getProjindex() {
#pragma HLS inline  
  //std::cout << "projindex=" << projindex << "\tprojid=" << projbuffer.getIndex() << std::endl;
  return projbuffer.getIndex();
}

NSTUBS getNStubs() {
#pragma HLS inline  
  return nstubs;
}

void read(ProjectionRouterBuffer<BARREL>::TCID& trackletid, VMProjection<BARREL>::VMPID& id, STUBID* stubid, NSTUBS& nstub) {
#pragma HLS inline  
  //std::cout << "reading MEU " << projbuffer.raw() << "\tprojid=" << projbuffer.getIndex() << "\t" << "iphi=" << ivmphi << "\treading=" << readindex << "\tmax=" << writeindex << std::endl;
  trackletid = getTCID();
  id = getProjindex();
  stubid = getStubIds();
  nstub = getNStubs();
  idle_ = true;

}

void readNext(ProjectionRouterBuffer<BARREL>::TCID& trackletid, VMProjection<BARREL>::VMPID& projid, STUBID& stubid) {
#pragma HLS inline  
  //print();
  trackletid = getTCID();
  projid = getProjindex();
  stubid = stubids[ptr];
  //std::cout << std::hex << "reading MEU " << projbuffer.raw() << "\tprojid=" << projbuffer.getIndex() << "\tstubid=" << stubid << "\t" << "iphi=" << ivmphi << "\treading=" << readindex << "\tptr=" << ptr << "\tmax=" << writeindex << std::endl;
  ptr++;
  idle_ = ptr >= readindex ? true : idle_;

}

#ifndef __SYNTHESIS__
void print() {
  if(empty()) 
    std::cout << "Empty MEU projid=" << projbuffer.getIndex() << unit_ << std::endl;
  else {
    std::cout << "Unread contents in MEU projid=" << projbuffer.getIndex() << unit_ << std::endl;
    for(int i = ptr; i < readindex; ++i){
      std::cout << std::hex << i << ": " << stubids[i] << std::endl;
    }
  }
}
#endif

//inline bool step(bool *table, const VMStubMEMemory<VMSMEType,3>* stubmem, ProjectionRouterBuffer<BARREL> *projbuffer) {
inline bool step(bool *table, const VMStubMEMemory<VMSMEType,3> *stubmem) {
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
  if (!done()) {// && buffernotlarger) {
      auto readindextmp = readindex;

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

        std::cout << "nstubs=" << nstubs << std::endl;
        std::cout << "istub before =" << istub << std::endl;
        if (nstubs==1) {
          istub=0;
          readindex++;
          std::cout << "one" << std::endl;
        } else {
          istub++;
          std::cout << "new and incrementing" << std::endl;
        }
        std::cout << "istub after =" << istub << std::endl;
      } else {
        //Check if last stub, if so, go to next buffer entry 
        std::cout << "NOT new projection" << std::endl;
        std::cout << "nstubs=" << nstubs << std::endl;
        std::cout << "istub before =" << istub << std::endl;
        if (istub+1>=nstubs){
          istub=0;
          readindex++;
          std::cout << "larger" << std::endl;
        } else {
          istub++;
          std::cout << "incrementing" << std::endl;
        }
        std::cout << "istub after =" << istub << std::endl;
      }
      
      //Read stub memory and extract data fields
      auto const  stubadd=zbin.concat(istubtmp);
      const VMStubME<VMSMEType> stubdata=stubmem[ivmphi].read_mem(bx,stubadd);
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
      stubids[readindextmp]=stubindex;
      //std::cout << std::hex << "MEU found stubid=" << stubindex << std::endl;
    } // if(pass&&table[index])
    //if(istub==0 && nstubs>0) idle_ = true;
    if(readindex>nstubs) done_ = true;
    //if(readindex>writeindex) done_ = true;
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
  INDEX ptr;
  NSTUBS nstubs;
  bool idle_;
  bool done_;
  int istep_;
  int ivmphi;
  int unit_;
  BXType bx;
  NSTUBS istub=0;
  STUBID stubids[1<<MatchEngineUnitBase<VMProjType>::kNBitsBuffer];
  ap_int<5> projfinezadj; //FIXME Need replace 5 with const
  ProjectionRouterBuffer<BARREL>::TCID tcid;
  ProjectionRouterBuffer<BARREL>::PRHASSEC isPSseed;
  ProjectionRouterBuffer<BARREL>::VMPZBIN zbin;
  VMProjection<BARREL>::VMPRINV projrinv;
  VMProjection<BARREL>::VMPID projindex;
  //const VMStubMEMemory<VMSMEType,3> *stubmem;
  ProjectionRouterBuffer<BARREL> projbuffer;

}; // end class


#endif
