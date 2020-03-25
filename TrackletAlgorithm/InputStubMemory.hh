#ifndef INPUTSTUBMEMORY_HH
#define INPUTSTUBMEMORY_HH

#include "Constants.hh"
#include "MemoryTemplate.hh"



// InputStubBase is where we define the bit widths, which depend on the class template parameter
template<int ISType> class InputStubBase {};

template<>
class InputStubBase<BARRELPS>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 3,
    kISAlphaSize = 0,
    kISPhiSize = 14,
    kISZSize = 12,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<BARREL2S>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 4,
    kISAlphaSize = 0,
    kISPhiSize = 17,
    kISZSize = 8,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<DISKPS>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 3,
    kISAlphaSize = 0,
    kISPhiSize = 14,
    kISZSize = 7,
    kISRSize = 12,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

template<>
class InputStubBase<DISK2S>
{
public:
  enum BitWidths {
    // Bit size for InputStubMemory fields
    kISBendSize = 4,
    kISAlphaSize = 4,
    kISPhiSize = 14,
    kISZSize = 7,
    kISRSize = 7,
    // Bit size for full InputStubMemory
    kInputStubSize = kISBendSize + kISAlphaSize + kISPhiSize + kISZSize + kISRSize
  };
};

// class TFStub 
// {
//   typedef ap_uint<kBRAMwidth> TFStubData;
// public:
  
//   // Constructors
//   TFStub(const TFStubData& newdata):
//     data_(newdata)
//   {}
  
//   template<int ISType> 
//   TFStub(const ap_uint<InputStubBase<ISType>::kInputStubSize>& newStub):
//     data_(newStub)
//   {
//     setBitLocations<ISType>();
//   }

//   TFStub():
//     data_(0)
//   {}

//   // templated assignment of bit locations 
//   template<int ISType> 
//   void setBitLocations()
//   {
//     kISBendLSB = 0;
//     kISBendMSB = kISBendLSB + InputStubBase<ISType>::kISBendSize - 1;
//     kISAlphaLSB = kISBendMSB + 1;
//     kISAlphaMSB = kISAlphaLSB + InputStubBase<ISType>::kISAlphaSize - 1;
//     kISPhiLSB = kISAlphaMSB + 1;
//     kISPhiMSB = kISPhiLSB + InputStubBase<ISType>::kISPhiSize - 1;
//     kISZLSB = kISPhiMSB + 1;
//     kISZMSB = kISZLSB + InputStubBase<ISType>::kISZSize - 1;
//     kISRLSB = kISZMSB + 1;
//     kISRMSB = kISRLSB + InputStubBase<ISType>::kISRSize - 1;
//   }

//   // Getters 
//   TFStubData raw() const {return data_; }

//   // templated getter 
//   template<int ISType> 
//   ap_uint<InputStubBase<ISType>::kISRSize> getR() const { return data_.range(kISRMSB,kISRLSB); }
  
//   template<int ISType> 
//   ap_uint<InputStubBase<ISType>::kISZSize> getZ() const { return data_.range(kISZMSB,kISZLSB); }

//   template<int ISType> 
//   ap_uint<InputStubBase<ISType>::kISPhiSize> getPhi() const { return data_.range(kISPhiMSB,kISPhiLSB); }

//   // This getter is only used for stubs in DISK2S
//   template<int ISType> 
//   ap_uint<InputStubBase<ISType>::kISAlphaSize> getAlpha() const 
//   {
//     static_assert(ISType == DISKPS, "Getter should only be used for Disk 2S stubs");
//     return data_.range(kISAlphaMSB,kISAlphaLSB);
//   }
  
//   template<int ISType> 
//   ap_uint<InputStubBase<ISType>::kISBendSize> getBend() const { return data_.range(kISBendMSB,kISBendLSB); }

//   // Setters 
//   template<int ISType> 
//   void setR(const ap_uint<InputStubBase<ISType>::kISRSize> r){ data_.range(kISRMSB,kISRLSB) = r; }

//   template<int ISType> 
//   void setZ(const ap_uint<InputStubBase<ISType>::kISZSize> z) { data_.range(kISZMSB,kISZLSB) = z; }

//   template<int ISType> 
//   void setPhi(const ap_uint<InputStubBase<ISType>::kISPhiSize> phi) { data_.range(kISPhiMSB,kISPhiLSB) = phi; }

//   // This setter is only used for stubs in DISK2S
//   template<int ISType> 
//   void setAlpha(const ap_uint<InputStubBase<ISType>::kISAlphaSize> alpha) {
//     static_assert(ISType == DISKPS, "Setter should only be used for Disk 2S stubs");
//     data_.range(kISAlphaMSB,kISAlphaLSB) = alpha;
//   }

//   template<int ISType> 
//   void setBend(const ap_uint<InputStubBase<ISType>::kISBendSize> bend) { data_.range(kISBendMSB,kISBendLSB) = bend; }

//   ap_uint<3> getCoarsePhiRegion(int cNbits=2) const { return data_.range(kISPhiMSB-1,kISPhiMSB-(cNbits-1));}

//   private:
//     TFStubData data_;
//     // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
//     ap_uint<8> kISBendLSB =0;
//     ap_uint<8> kISBendMSB =0;
//     ap_uint<8> kISAlphaLSB =0;
//     ap_uint<8> kISAlphaMSB =0;
//     ap_uint<8> kISPhiLSB =0;
//     ap_uint<8> kISPhiMSB =0;
//     ap_uint<8> kISZLSB =0;
//     ap_uint<8> kISZMSB =0;
//     ap_uint<8> kISRLSB =0;
//     ap_uint<8> kISRMSB =0;

// };
// Memory definition
//using TFStubMemory = MemoryTemplate<TFStub, 1, kNBits_MemAddr>;

template<class DataType, unsigned int NBIT_BX, unsigned int NBIT_ADDR>
class InputRouterMemory : public MemoryTemplate<DataType, NBIT_BX, NBIT_ADDR>
{
  public:
    //default constructor 
    InputRouterMemory(): 
    MemoryTemplate< DataType, NBIT_BX, NBIT_ADDR>(), 
    kIsPS{0}, kIsBarrel{0}, kLayerId{0}, kPhiRegion{0}
    {
      // figure out which type I am here .. 
      if( DataType::kISRSize == 12 ) // only endcap disks for PS modules use 12 bits 
      { 
        kIsPS=1; 
        kIsBarrel=0;
      }
      else if( DataType::kISRSize == 7 ) // all other modules use 7 bits for R 
      {
        kIsPS = ( DataType::kISZSize == 12 ) ; 
        kIsBarrel = ( DataType::kISZSize >= 8 ); 
      }
    }
    //default constructor 
    InputRouterMemory(ap_uint<3> pLayerId, ap_uint<3> pCoarsePhi): 
    InputRouterMemory()
    {
      kLayerId = pLayerId;
      kPhiRegion = pCoarsePhi;
    }

    // getter 
    ap_uint<1> isPS() const { return kIsPS;}
    ap_uint<1> IsBarrel() const { return kIsBarrel;}
    ap_uint<3> getLayerId() const { return kLayerId;}
    ap_uint<3> getPhiRegion() const { return kPhiRegion;}
    // setters
    void setLayerId(const ap_uint<3> pLayerId)  { kLayerId=pLayerId;}
    void setPhiRegion(const ap_uint<3> pCoarsePhi)  { kPhiRegion=pCoarsePhi;}
  private : 
    ap_uint<1> kIsPS;
    ap_uint<1> kIsBarrel;
    ap_uint<3> kLayerId;
    ap_uint<3> kPhiRegion; 
};

// template<class ... Types> struct InputRouterMemories {};

// Data object definition
template<int ISType>
class InputStub : public InputStubBase<ISType>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the InputStubMemory word for different fields
    kISBendLSB = 0,
    kISBendMSB = kISBendLSB + InputStubBase<ISType>::kISBendSize - 1,
    kISAlphaLSB = kISBendMSB + 1,
    kISAlphaMSB = kISAlphaLSB + InputStubBase<ISType>::kISAlphaSize - 1,
    kISPhiLSB = kISAlphaMSB + 1,
    kISPhiMSB = kISPhiLSB + InputStubBase<ISType>::kISPhiSize - 1,
    kISZLSB = kISPhiMSB + 1,
    kISZMSB = kISZLSB + InputStubBase<ISType>::kISZSize - 1,
    kISRLSB = kISZMSB + 1,
    kISRMSB = kISRLSB + InputStubBase<ISType>::kISRSize - 1
  };

  typedef ap_uint<InputStubBase<ISType>::kISRSize> ISR;
  typedef ap_int<InputStubBase<ISType>::kISZSize> ISZ;
  typedef ap_uint<InputStubBase<ISType>::kISPhiSize> ISPHI;
  typedef ap_uint<InputStubBase<ISType>::kISAlphaSize> ISALPHA;
  typedef ap_uint<InputStubBase<ISType>::kISBendSize> ISBEND;
  
  typedef ap_uint<InputStubBase<ISType>::kInputStubSize> InputStubData;

  // Constructors
  InputStub(const InputStubData& newdata):
    data_(newdata)
  {}

  InputStub(const ISR r, const ISZ z, const ISPHI phi, const ISBEND bend):
    data_( (((r,z),phi),bend) )
  {
    static_assert(ISType != DISKPS, "Constructor should not be used for Disk 2S stubs");
  }

  // This constructor is only used for stubs in DISK2S
  InputStub(const ISR r, const ISZ z, const ISPHI phi, const ISALPHA alpha, const ISBEND bend):
    data_( ((((r,z),phi),alpha),bend) ) 
  {
    static_assert(ISType == DISKPS, "Constructor should only be used for Disk 2S stubs");
  }

  InputStub():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  InputStub(const char* datastr, int base=16)
  {
    InputStubData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  InputStubData raw() const {return data_; }

  template<int NBitsRegion>
  ap_uint<NBitsRegion> getCoarsePhiRegion() const { return data_.range(kISPhiMSB-1,kISPhiMSB-(NBitsRegion-1)); } 

  ISR getR() const {
    return data_.range(kISRMSB,kISRLSB);
  }

  ISZ getZ() const {
    return data_.range(kISZMSB,kISZLSB);
  }

  ISPHI getPhi() const {
    return data_.range(kISPhiMSB,kISPhiLSB);
  }

  // This getter is only used for stubs in DISK2S
  ISALPHA getAlpha() const {
    static_assert(ISType == DISKPS, "Getter should only be used for Disk 2S stubs");
    return data_.range(kISAlphaMSB,kISAlphaLSB);
  }

  ISBEND getBend() const {
    return data_.range(kISBendMSB,kISBendLSB);
  }

  // Setter
  void setR(const ISR r) {
    data_.range(kISRMSB,kISRLSB) = r;
  }

  void setZ(const ISZ z) {
    data_.range(kISZMSB,kISZLSB) = z;
  }

  void setPhi(const ISPHI phi) {
    data_.range(kISPhiMSB,kISPhiLSB) = phi;
  }

  // This setter is only used for stubs in DISK2S
  void setAlpha(const ISALPHA alpha) {
    static_assert(ISType == DISKPS, "Setter should only be used for Disk 2S stubs");
    data_.range(kISAlphaMSB,kISAlphaLSB) = alpha;
  }

  void setBend(const ISBEND bend) {
    data_.range(kISBendMSB,kISBendLSB) = bend;
  }

private:

  InputStubData data_;

};
// Memory definition
//template<int ISType> using InputStubMemory = MemoryTemplate<InputStub<ISType>, kNBits_BX, kNBits_MemAddr>;
using IRMemory = MemoryTemplate<ap_uint<kBRAMwidth>, kNBits_BX, kNBits_MemAddr>;
template<int ISType> 
using InputStubMemory = InputRouterMemory<InputStub<ISType>, kNBits_BX, kNBits_MemAddr>;


// Data object definition
class DTCMap 
{
  public:
    typedef ap_uint<kLINKMAPwidth> DTCInfo;

    // Constructors
    DTCMap(const DTCInfo& newdata):
      data_(newdata)
    {}

    DTCMap():
      data_(0)
    {}

    #ifndef __SYNTHESIS__
    DTCMap(const char* datastr, int base=16)
    {
      DTCInfo newdata(datastr, base);
      data_ = newdata;
    }
    #endif

    // Getter
    DTCInfo raw() const {return data_; }


  private:
    DTCInfo data_;

};

using DTCMapMemory = MemoryTemplate<DTCMap, 1, kNBits_MemAddr>;
#endif
