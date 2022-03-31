#ifndef TrackletAlgorithm_AllStubMemory_h
#define TrackletAlgorithm_AllStubMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"
#include "globalFunctions.h"

// AllStubBase is where we define the bit widths, which depend on the class template parameter
template<int ASType> class AllStubBase {};

template<>
class AllStubBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for AllStubMemory fields
    kASBendSize = 3,
    kASAlphaSize = 0,
    kASPhiSize = 14,
    kASZSize = 12,
    kASRSize = 7,
    // Bit size for full AllStubMemory
    kAllStubSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize
  };
};

template<>
class AllStubBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for AllStubMemory fields
    kASBendSize = 4,
    kASAlphaSize = 0,
    kASPhiSize = 17,
    kASZSize = 8,
    kASRSize = 7,
    // Bit size for full AllStubMemory
    kAllStubSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize
  };
};

template<>
class AllStubBase<DISKPS>
{
public:
  enum BitWidths {
    // Bit size for AllStubMemory fields
    kASBendSize = 3,
    kASAlphaSize = 0,
    kASPhiSize = 14,
    kASZSize = 7,
    kASRSize = 12,
    // Bit size for full AllStubMemory
    kAllStubSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize
  };
};

template<>
class AllStubBase<DISK2S>
{
public:
  enum BitWidths {
    // Bit size for AllStubMemory fields
    kASBendSize = 4,
    kASAlphaSize = 4,
    kASPhiSize = 14,
    kASZSize = 7,
    kASRSize = 7,
    // Bit size for full AllStubMemory
   kAllStubSize = kASBendSize + kASAlphaSize + kASPhiSize + kASZSize + kASRSize
  };
};

template<>
class AllStubBase<DISK> {
public:
   enum BitWidths {
     kAllStubSize = AllStubBase<DISKPS>::kAllStubSize
   };
};


// Data object definition
template<int ASType>
class AllStub : public AllStubBase<ASType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the AllStubMemory word for different fields
    kASBendLSB = 0,
    kASBendMSB = kASBendLSB + AllStubBase<ASType>::kASBendSize - 1,
    kASAlphaLSB = kASBendMSB + 1,
    kASAlphaMSB = kASAlphaLSB + AllStubBase<ASType>::kASAlphaSize - 1,
    kASPhiLSB = kASAlphaMSB + 1,
    kASPhiMSB = kASPhiLSB + AllStubBase<ASType>::kASPhiSize - 1,
    kASZLSB = kASPhiMSB + 1,
    kASZMSB = kASZLSB + AllStubBase<ASType>::kASZSize - 1,
    kASRLSB = kASZMSB + 1,
    kASRMSB = kASRLSB + AllStubBase<ASType>::kASRSize - 1
  };
  
  typedef ap_int<AllStubBase<ASType>::kASRSize> ASR;
  typedef ap_int<AllStubBase<ASType>::kASZSize> ASZ;
  typedef ap_uint<AllStubBase<ASType>::kASPhiSize> ASPHI;
  typedef ap_int<AllStubBase<ASType>::kASAlphaSize> ASALPHA;
  typedef ap_int<AllStubBase<ASType>::kASBendSize> ASBEND;
  typedef ap_uint<AllStubBase<ASType>::kAllStubSize> AllStubData;

  // Constructors
  AllStub(const AllStubData& newdata):
    data_(newdata)
  {}

  AllStub(const ASR r, const ASZ z, const ASPHI phi, const ASBEND bend):
    data_( (((r,z),phi),bend) )
  {
    static_assert(ASType != DISK2S, "Constructor should not be used for Disk 2S stubs");
  }

  // This constructor is only used for stubs in DISK2S
  AllStub(const ASR r, const ASZ z, const ASPHI phi, const ASBEND bend, const ASALPHA alpha):
    data_( ((((r,z),phi),alpha),bend) )
  {
    //static_assert(ASType == DISK2S, "Constructor should only be used for Disk 2S stubs");
  }

  AllStub()
  {}

  #ifndef __SYNTHESIS__
  AllStub(const char* datastr, int base=16)
  {
    AllStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return AllStubBase<ASType>::kAllStubSize;}

  AllStubData raw() const {return data_; }

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

  bool isPSStub() const {
    if(ASType == BARRELPS) return true;
    else if(ASType == BARREL2S) return false;
    else if(ASType == DISKPS || ASType == DISK2S) {
      // Checks the radius 
      // if these are zero it means that you have 2S stubs where the radius 
      // just encodes the ring number and is less than 16
      return data_.range(getWidth()-1, getWidth()-3) > 0; // Check highest 3 bits regardless of template type
    }
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

#ifdef CMSSW_GIT_HASH
  std::string getBitStr() const {
    std::string str = decodeToBits(getR());
    str += "|"+decodeToBits(getZ());
    str += "|"+decodeToBits(getPhi());
    str += "|"+decodeToBits(getBend());
    return str;
  }
#endif

private:

  AllStubData data_;

};

#ifdef CMSSW_GIT_HASH
  template<>
  inline std::string AllStub<DISK2S>::getBitStr() const {
      std::string str = decodeToBits(getR());
      str += "|"+decodeToBits(getZ());
      str += "|"+decodeToBits(getPhi());
      str += "|"+decodeToBits(getAlpha());
      str += "|"+decodeToBits(getBend());
      return str;
  }
#endif

// Special data object definition
template<>
class AllStub<6> : public AllStubBase<DISK> // Can't generate cosim files if AllStub<DISK> for some reason...
{
  static_assert(DISK == 6, "DISK is assumed to be 6 in this class specialization.");
public:
  typedef ap_uint<AllStubBase<DISK>::kAllStubSize> AllStubData;

  AllStub(const AllStubData& newdata):
    data_(newdata)
  {}

  AllStub()
  {}

  #ifndef __SYNTHESIS__
  AllStub(const char* datastr, int base=16)
  {
    AllStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return AllStubBase<DISK>::kAllStubSize;}

  AllStubData raw() const {return data_;}

private:

  AllStubData data_;

};

// Memory definition
template<int ASType> using AllStubMemory = MemoryTemplate<AllStub<ASType>, 3, kNBits_MemAddr>;

#endif
