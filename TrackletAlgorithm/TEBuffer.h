#ifndef TrackletAlgorithm_TEBuffer_h
#define TrackletAlgorithm_TEBuffer_h

#include "Constants.h"
#include "MemoryTemplate.h"
#include "AllStubInnerMemory.h"
#include "TrackletEngineUnit.h"
template <TF::seed Seed,TC::itc iTC, regionType innerRegion,regionType VMSTEType>
class TEData{

 public:

  enum BitWidths {
    kNBitsIMem = 2
  };

  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TEData word for different fields
    kTEDataStubMaskLSB = 0,
    kTEDataStubMaskMSB = kTEDataStubMaskLSB + 2*(1<<TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::kNBitsPhiBins) - 1,
    kTEDatarzbinfirstLSB = kTEDataStubMaskMSB+1,
    kTEDatarzbinfirstMSB = kTEDatarzbinfirstLSB + TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::kNBitsRZFine - 1,
    kTEDatastartLSB = kTEDatarzbinfirstMSB + 1,
    kTEDatastartMSB = kTEDatastartLSB + TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::kNBitsRZBin - 1,
    kTEDatarzdiffmaxLSB = kTEDatastartMSB + 1,
    kTEDatarzdiffmaxMSB = kTEDatarzdiffmaxLSB + TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::kNBitsRZFine - 1,
    kTEDataAllStubLSB = kTEDatarzdiffmaxMSB + 1,
    kTEDataAllStubMSB = kTEDataAllStubLSB + AllStubInner<innerRegion>::kAllStubInnerSize - 1
  };

  typedef ap_uint<kNBitsIMem> IMEM;
  typedef ap_uint<kTEDataAllStubMSB+1> TEDATA;

 TEData()
    {}

  typename AllStubInner<innerRegion>::AllStubInnerData getAllStub() const {
    return data_.range(kTEDataAllStubMSB,kTEDataAllStubLSB);
  }

  typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZBIN getStart() const {
    return data_.range(kTEDatastartMSB,kTEDatastartLSB);
  }

  typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZFINE getrzbinfirst() const {
    return data_.range(kTEDatarzbinfirstMSB,kTEDatarzbinfirstLSB);
  }

  typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZFINE getrzdiffmax() const {
    return data_.range(kTEDatarzdiffmaxMSB,kTEDatarzdiffmaxLSB);
  }

  const typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::MEMMASK getStubMask() const {
    return data_.range(kTEDataStubMaskMSB,kTEDataStubMaskLSB);
  }

 TEData(const TEData& tedata):
  data_(tedata.data_)
  {}

 TEData(const TEDATA& tedata):
  data_(tedata)
  {}
  
 TEData( const typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::MEMMASK stubmask,
	 const typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZFINE rzbinfirst, 
	 const typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZBIN start, 
	 const typename TrackletEngineUnit<Seed,iTC,innerRegion,VMSTEType>::RZFINE rzdiffmax, 
	 const typename AllStubInner<innerRegion>::AllStubInnerData stub
	 ):
  data_( (stub, rzdiffmax, start, rzbinfirst, stubmask) )
    {}

  TEDATA raw() const {return data_;}
  
 private:

  TEDATA data_;

};
  

// Data object definition
template <TF::seed Seed, TC::itc iTC,regionType innerRegion,regionType VMSTEType>
class TEBuffer {

 public:

  enum BitWidths {
    kNBufferDepthBits=3
  };

  typedef ap_uint<kNBufferDepthBits> TEBUFFERINDEX;
  typedef ap_uint<kNBits_MemAddr> NSTUBS;

  // Constructors
 TEBuffer():
  writeptr_(0), readptr_(0), istub_(0), imem_(0), imembegin_(0), imemend_(0)
    {
#pragma HLS array_partition variable=buffer_ complete dim=0
}
	
  void setMemBegin(const typename TEData<Seed,iTC,innerRegion,VMSTEType>::IMEM& begin) {
    imembegin_=begin;
  }
  
  void setMemEnd(const typename TEData<Seed,iTC,innerRegion,VMSTEType>::IMEM& end) {
    imemend_=end;
  }

  void reset() {
    imem_=imembegin_;
    writeptr_=0;
    readptr_=0;
  }

  typename TEData<Seed,iTC,innerRegion,VMSTEType>::IMEM& getMem() {
    return imem_;
  }

  const typename TEData<Seed,iTC,innerRegion,VMSTEType>::IMEM& getMemEnd() {
    return imemend_;
  }

  NSTUBS& getIStub() {
    return istub_;
  }

  void setIStub(const NSTUBS& istub) {
    istub_=istub;
  }

  void store(const typename TEData<Seed,iTC,innerRegion,VMSTEType>::TEDATA& tedata) {
    auto writeptrtmp=writeptr_;
    buffer_[writeptrtmp]=tedata;
    writeptr_++;
  }

  typename TEData<Seed,iTC,innerRegion,VMSTEType>::TEDATA peek() const {
    return buffer_[readptr_];
  }

  void increment_readptr() {
    readptr_++;
  }

  bool full() const {
    TEBUFFERINDEX writeptrnext=writeptr_+1;
    return writeptrnext==readptr_;
  }

  bool empty() const {
    return writeptr_==readptr_;
  }

  TEBUFFERINDEX readptr() const {
    return readptr_;
  }

  TEBUFFERINDEX writeptr() const {
    return writeptr_;
  }

  TEBUFFERINDEX writeptr_, readptr_;

  NSTUBS istub_;
  typename TEData<Seed,iTC,innerRegion,VMSTEType>::IMEM imem_, imembegin_, imemend_;
  
  typename TEData<Seed,iTC,innerRegion,VMSTEType>::TEDATA buffer_[1<<kNBufferDepthBits];
  
private:

};

#endif
