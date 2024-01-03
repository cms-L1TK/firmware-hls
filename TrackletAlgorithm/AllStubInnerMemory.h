#ifndef TrackletAlgorithm_AllStubInnerMemory_h
#define TrackletAlgorithm_AllStubInnerMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// AllStubInnerBase is where we define the bit widths, which depend on the class template parameter
template<int ASType> class AllStubInnerBase {};

template<>
class AllStubInnerBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for AllStubInnerMemory fields
    kASBendSize = 3,
    kASAlphaSize = 0,
    kASPhiSize = 14,
    kASZSize = 12,
    kASRSize = 7,
    kASIndexSize = 7,
    kASFinePhiSize = 8,
    kASNegDiskSize = 0,
    // Bit size for full AllStubInnerMemory
    kAllStubInnerSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize + kASIndexSize + kASFinePhiSize + kASNegDiskSize
  };
};

template<>
class AllStubInnerBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for AllStubInnerMemory fields
    kASBendSize = 4,
    kASAlphaSize = 0,
    kASPhiSize = 17,
    kASZSize = 8,
    kASRSize = 7,
    kASIndexSize = 7,
    kASFinePhiSize = 8,
    kASNegDiskSize = 0,
    // Bit size for full AllStubInnerMemory
    kAllStubInnerSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize + kASIndexSize + kASFinePhiSize + kASNegDiskSize
  };
};

template<>
class AllStubInnerBase<DISKPS>
{
public:
  enum BitWidths {
    // Bit size for AllStubInnerMemory fields
    kASBendSize = 3,
    kASAlphaSize = 0,
    kASPhiSize = 14,
    kASZSize = 7,
    kASRSize = 12,
    kASIndexSize = 7,
    kASFinePhiSize = 8,
    kASNegDiskSize = 1,
    // Bit size for full AllStubInnerMemory
    kAllStubInnerSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize + kASIndexSize + kASFinePhiSize + kASNegDiskSize
  };
};

template<>
class AllStubInnerBase<DISK2S>
{
public:
  enum BitWidths {
    // Bit size for AllStubInnerMemory fields
    kASBendSize = 4,
    kASAlphaSize = 4,
    kASPhiSize = 14,
    kASZSize = 7,
    kASRSize = 7,
    kASIndexSize = 7,
    kASFinePhiSize = 8,
    kASNegDiskSize = 1,
    // Bit size for full AllStubInnerMemory
    kAllStubInnerSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize + kASIndexSize + kASFinePhiSize + kASNegDiskSize
  };
};

template<>
class AllStubInnerBase<DISK> {
public:
   enum BitWidths {
     // Bit size for AllStubInnerMemory fields
     kASIndexSize = AllStubInnerBase<DISKPS>::kASIndexSize,
     kASFinePhiSize = AllStubInnerBase<DISKPS>::kASFinePhiSize,
     kASNegDiskSize = AllStubInnerBase<DISKPS>::kASNegDiskSize,
     // Bit size for full AllStubInnerMemory
     kAllStubInnerSize = AllStubInnerBase<DISKPS>::kAllStubInnerSize
   };
};


// Data object definition
template<int ASType>
class AllStubInner : public AllStubInnerBase<ASType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllStubInnerMemory word for different fields
    kASFinePhiLSB = 0,
    kASFinePhiMSB = kASFinePhiLSB + AllStubInnerBase<ASType>::kASFinePhiSize - 1,
    kASIndexLSB = kASFinePhiMSB +1,
    kASIndexMSB = kASIndexLSB + AllStubInnerBase<ASType>::kASIndexSize - 1,
    kASNegDiskLSB = kASIndexMSB + 1,
    kASNegDiskMSB = kASNegDiskLSB + AllStubInnerBase<ASType>::kASNegDiskSize - 1,
    kASBendLSB = kASNegDiskMSB + 1,
    kASBendMSB = kASBendLSB + AllStubInnerBase<ASType>::kASBendSize - 1,
    kASAlphaLSB = kASBendMSB + 1,
    kASAlphaMSB = kASAlphaLSB + AllStubInnerBase<ASType>::kASAlphaSize - 1,
    kASPhiLSB = kASAlphaMSB + 1,
    kASPhiMSB = kASPhiLSB + AllStubInnerBase<ASType>::kASPhiSize - 1,
    kASZLSB = kASPhiMSB + 1,
    kASZMSB = kASZLSB + AllStubInnerBase<ASType>::kASZSize - 1,
    kASRLSB = kASZMSB + 1,
    kASRMSB = kASRLSB + AllStubInnerBase<ASType>::kASRSize - 1
  };
  typedef ap_int<AllStubInnerBase<ASType>::kASRSize> ASR;
  typedef ap_int<AllStubInnerBase<ASType>::kASZSize> ASZ;
  typedef ap_uint<AllStubInnerBase<ASType>::kASPhiSize> ASPHI;
  typedef ap_uint<AllStubInnerBase<ASType>::kASAlphaSize> ASALPHA;
  typedef ap_uint<AllStubInnerBase<ASType>::kASBendSize> ASBEND;
  typedef ap_uint<AllStubInnerBase<ASType>::kASIndexSize> ASINDEX;
  typedef ap_uint<AllStubInnerBase<ASType>::kASFinePhiSize> ASFINEPHI;
  typedef ap_uint<AllStubInnerBase<ASType>::kAllStubInnerSize> AllStubInnerData;
  typedef ap_uint<AllStubInnerBase<ASType>::kAllStubInnerSize-AllStubInnerBase<ASType>::kASNegDiskSize-AllStubInnerBase<ASType>::kASIndexSize-AllStubInnerBase<ASType>::kASFinePhiSize> AllStubData;
  typedef ap_uint<1> ASNEGDISK; //FIXME this is always ap_uint<1> because csynth fails if this is ever 0 wide

  // Constructors
  AllStubInner(const AllStubInnerData& newdata):
    data_(newdata)
  {}

 AllStubInner(const ASR r, const ASZ z, const ASPHI phi, const ASBEND bend, const ASINDEX index, const ASFINEPHI finephi):
    data_( (r,z,phi,bend,index,finephi) )
  {
    static_assert((ASType != DISK2S) && (ASType != DISKPS), "Constructor should not be used for Disk 2S or PS stubs");
  }

 AllStubInner(const ASNEGDISK negdisk, const ASR r, const ASZ z, const ASPHI phi, const ASBEND bend, const ASINDEX index, const ASFINEPHI finephi):
    data_( (negdisk,r,z,phi,bend,index,finephi) )
  {
    static_assert(ASType == DISKPS, "Constructor should only be used for PS stubs");
  }

  // This constructor is only used for stubs in DISK2S
  AllStubInner(const ASNEGDISK negdisk, const ASR r, const ASZ z, const ASPHI phi, const ASALPHA alpha, const ASBEND bend, const ASINDEX index, const ASFINEPHI finephi):
    data_( (negdisk,r,z,phi,alpha,bend,index,finephi) )
  {
    static_assert(ASType == DISK2S, "Constructor should only be used for Disk 2S stubs");
  }

  AllStubInner()
  {}

  #ifndef __SYNTHESIS__
  AllStubInner(const char* datastr, int base=16)
  {
    AllStubInnerData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return AllStubInnerBase<ASType>::kAllStubInnerSize;}

  AllStubInnerData raw() const {return data_; }

  AllStubData getAllStub() const {
    return data_.range(kASRMSB,kASBendLSB);
  }

  ASR getR() const {
    return data_.range(kASRMSB,kASRLSB);
  }

  ASZ getZ() const {
    return data_.range(kASZMSB,kASZLSB);
  }

  ASPHI getPhi() const {
    return data_.range(kASPhiMSB,kASPhiLSB);
  }

  // This getter is only used for stubs in DISK2S
  ASALPHA getAlpha() const {
    static_assert(ASType == DISK2S, "Getter should only be used for Disk 2S stubs");
    return data_.range(kASAlphaMSB,kASAlphaLSB);
  }

  ASBEND getBend() const {
    return data_.range(kASBendMSB,kASBendLSB);
  }

  ASINDEX getIndex() const {
    return data_.range(kASIndexMSB,kASIndexLSB);
  }

  ASFINEPHI getFinePhi() const {
    return data_.range(kASFinePhiMSB,kASFinePhiLSB);
  }

  ASNEGDISK getNegDisk() const {
    return data_.range(kASNegDiskMSB,kASNegDiskLSB);
  }

  // Setter
  void setR(const ASR r) {
    data_.range(kASRMSB,kASRLSB) = r;
  }

  void setZ(const ASZ z) {
    data_.range(kASZMSB,kASZLSB) = z;
  }

  void setPhi(const ASPHI phi) {
    data_.range(kASPhiMSB,kASPhiLSB) = phi;
  }

  // This setter is only used for stubs in DISK2S
  void setAlpha(const ASALPHA alpha) {
    static_assert(ASType == DISK2S, "Setter should only be used for Disk 2S stubs");
    data_.range(kASAlphaMSB,kASAlphaLSB) = alpha;
  }

  void setBend(const ASBEND bend) {
    data_.range(kASBendMSB,kASBendLSB) = bend;
  }

  void setIndex(const ASINDEX index) {
    data_.range(kASIndexMSB,kASIndexLSB) = index;
  }

  void setFinePhi(const ASFINEPHI finephi) {
    data_.range(kASFinePhiMSB,kASFinePhiLSB) = finephi;
  }

  void setNegDisk(const ASNEGDISK negdisk) {
    data_.range(kASNegDiskMSB,kASNegDiskLSB) = negdisk;
  }

#ifdef CMSSW_GIT_HASH
  std::string getBitStr() const {
    std::string str = decodeToBits(getR());
    str += "|"+decodeToBits(getZ());
    str += "|"+decodeToBits(getPhi());
    str += "|"+decodeToBits(getBend());
    if (ASType == DISKPS || ASType == DISK2S) str += "|"+decodeToBits(getNegDisk());
    str += "|"+decodeToBits(getIndex());
    str += "|"+decodeToBits(getFinePhi());
    return str;
  }
#endif

private:

  AllStubInnerData data_;

};

// Special data object definition
template<>
class AllStubInner<6> : public AllStubInnerBase<DISK> // Can't generate cosim files if AllStubInner<DISK> for some reason...
{
  static_assert(DISK == 6, "DISK is assumed to be 6 in this class specialization.");
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllStubInnerMemory word for different fields
    kASFinePhiLSB = 0,
    kASFinePhiMSB = kASFinePhiLSB + AllStubInnerBase<DISK>::kASFinePhiSize - 1,
    kASIndexLSB = kASFinePhiMSB +1,
    kASIndexMSB = kASIndexLSB + AllStubInnerBase<DISK>::kASIndexSize - 1,
    kASNegDiskLSB = kASIndexMSB + 1,
    kASNegDiskMSB = kASNegDiskLSB + AllStubInnerBase<DISK>::kASNegDiskSize -1
  };

  typedef ap_uint<AllStubInnerBase<DISK>::kAllStubInnerSize> AllStubInnerData;
  typedef ap_uint<AllStubInnerBase<DISK>::kASFinePhiSize> ASFINEPHI;
  typedef ap_uint<AllStubInnerBase<DISK>::kASIndexSize> ASINDEX;
  typedef ap_uint<1> ASNEGDISK;//FIXME remove 1

  AllStubInner(const AllStubInnerData& newdata):
    data_(newdata)
  {}

  AllStubInner()
  {}

  #ifndef __SYNTHESIS__
  AllStubInner(const char* datastr, int base=16)
  {
    AllStubInnerData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return AllStubInnerBase<DISK>::kAllStubInnerSize;}

  ASFINEPHI getFinePhi() const {
    return data_.range(kASFinePhiMSB,kASFinePhiLSB);
  }

  ASNEGDISK getNegDisk() const {
    return data_.range(kASNegDiskMSB,kASNegDiskLSB);
  }

  AllStubInnerData raw() const {return data_;}

  // Setter
  void setIndex(const ASINDEX index) {
    data_.range(kASIndexMSB,kASIndexLSB) = index;
  }

  void setFinePhi(const ASFINEPHI finephi) {
    data_.range(kASFinePhiMSB,kASFinePhiLSB) = finephi;
  }

  void setNegDisk(const ASNEGDISK negdisk) {
    data_.range(kASNegDiskMSB,kASNegDiskLSB) = negdisk;
  }

private:

  AllStubInnerData data_;

};

// Memory definition
template<int ASType> using AllStubInnerMemory = MemoryTemplate<AllStubInner<ASType>, 1, kNBits_MemAddr>;

#endif
