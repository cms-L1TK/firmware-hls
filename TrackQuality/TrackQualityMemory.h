#ifndef TrackQuality_TrackQualityMemory_h
#define TrackQuality_TrackQualityMemory_h

#include "ap_fixed.h"
#include "../TrackletAlgorithm/Constants.h"
#include "../TrackletAlgorithm/MemoryTemplate.h"

// Temporary definition of TTTrack word pending changes to KF output format
// https://twiki.cern.ch/twiki/bin/viewauth/CMS/HybridDataFormat#Final_output_to_L1_trigger

// Data object definition
class TTTrack
{
public:

  enum BitWidths {
    // Bit size for Track Memory fields
    InvRSize = 15,
    PhiSize = 12,
    TanLSize = 16,
    Z0Size = 12,
    D0Size = 13,
    Chi2rphiSize = 4,
    Chi2rzSize = 4,
    BendChi2Size = 3,
    HitPatternSize = 7,
    MVATQSize = 3,  //Track Quality
    MVAresSize = 6, //Reserved MVA bits
    TkValidSize = 1,
    
    // Bit size for full Track Memory 96-bits
    TrackSize = InvRSize + PhiSize + TanLSize + Z0Size 
              + D0Size + Chi2rphiSize + Chi2rzSize + BendChi2Size 
              + HitPatternSize + MVATQSize + MVAresSize + TkValidSize
  };

  enum BitLocations {
    // The location of the least significant bit (LSB) 
    // and most significant bit (MSB) in the Track Memory word for different fields
    InvRLSB = 0,
    InvRMSB = InvRLSB + InvRSize - 1,
    PhiLSB = InvRMSB + 1,
    PhiMSB = PhiLSB + PhiSize - 1,
    TanLLSB = PhiMSB + 1,
    TanLMSB = TanLLSB + TanLSize - 1,
    Z0LSB = TanLMSB + 1,
    Z0MSB = Z0LSB + Z0Size - 1,
    D0LSB = Z0MSB + 1,
    D0MSB = D0LSB + D0Size - 1,
    Chi2rphiLSB = D0MSB + 1,
    Chi2rphiMSB = Chi2rphiLSB + Chi2rphiSize - 1,
    Chi2rzLSB = Chi2rphiMSB + 1,
    Chi2rzMSB = Chi2rzLSB + Chi2rzSize - 1,
    BendChi2LSB = Chi2rzMSB + 1,
    BendChi2MSB = BendChi2LSB + BendChi2Size - 1,
    HitPatternLSB = BendChi2MSB + 1,
    HitPatternMSB = HitPatternLSB + HitPatternSize - 1,
    MVATQLSB = HitPatternMSB + 1,
    MVATQMSB = MVATQLSB + MVATQSize - 1,
    MVAresLSB = MVATQMSB + 1,
    MVAresMSB = MVAresLSB + MVAresSize- 1,
    TkValidLSB = MVAresMSB + 1, 
    TkValidMSB = TkValidLSB + TkValidSize - 1

  };

  // TODO update to output of KF, for now 96-bit track word pending correct parameter representations
  typedef ap_int<InvRSize> TTInvR;
  typedef ap_int<PhiSize> TTPhi;
  typedef ap_int<TanLSize> TTTanL;
  typedef ap_int<Z0Size> TTZ0;
  typedef ap_int<D0Size> TTD0;

  typedef ap_uint<Chi2rphiSize> TTChi2rphi;
  typedef ap_uint<Chi2rzSize> TTChi2rz;
  typedef ap_uint<BendChi2Size> TTBendChi2;
  typedef ap_uint<HitPatternSize> TTHitPattern;
  typedef ap_uint<MVATQSize> TTMVATQ;
  typedef ap_uint<MVAresSize> TTMVAres;
  typedef ap_uint<TkValidSize> TTTkValid;

  typedef ap_uint<TrackSize> TrackData;

  // Constructors
  TTTrack(const TrackData& newdata):
    data_(newdata)
  {}

  TTTrack(const TTInvR invr, const TTPhi phi, const TTTanL tanl, 
          const TTZ0 z0, const TTD0 d0, const TTChi2rphi chi2rphi,
          const TTChi2rz chi2rz, const TTBendChi2 bendchi2, const TTHitPattern hitpattern,
          const TTMVATQ mvatq, const TTMVAres mvares, const TTTkValid tkvalid):

    data_( (((((((((((invr,phi),tanl),z0),d0),chi2rphi),chi2rz),bendchi2),hitpattern),mvatq),mvares),tkvalid) )
  {}

  #ifndef __SYNTHESIS__
  TTTrack(const std::string& s){
      std::stringstream ss;
      ss << std::hex << s;  //convert 96-bit hex track word to 96-bit uint
      ss >> data_;
  }
  #endif

  TTTrack():
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  TTTrack(const char* datastr, int base=16)
  {
    TrackData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return TrackSize;}

  TrackData raw() const {return data_;}

  TTInvR getInvR() const {
    return data_.range(InvRMSB,InvRLSB);
  }

  TTPhi getPhi() const {
    return data_.range(PhiMSB,PhiLSB);
  }

  TTTanL getTanL() const {
    return data_.range(TanLMSB,TanLLSB);
  }

  TTZ0 getZ0() const {
    return data_.range(Z0MSB,Z0LSB);
  }

  TTD0 getD0() const {
    return data_.range(D0MSB,D0LSB);
  }

  TTChi2rphi getChi2rphi() const {
    return data_.range(Chi2rphiMSB,Chi2rphiLSB);
  }

  TTChi2rz getChi2rz() const {
    return data_.range(Chi2rzMSB,Chi2rzLSB);
  }

  TTBendChi2 getBendChi2() const {
    return data_.range(BendChi2MSB,BendChi2LSB);
  }

  TTHitPattern getHitPattern() const {
    return data_.range(HitPatternMSB,HitPatternLSB);
  }

  TTMVATQ getMVATQ() const {
    return data_.range(MVATQMSB,MVATQLSB);
  }

  TTMVAres getMVAres() const {
    return data_.range(MVAresMSB,MVAresLSB);
  }

  TTTkValid getTkValid() const {
    return data_.range(TkValidMSB,TkValidLSB);
  }

  // Setter

  void setInvR(TTInvR invr) const {
    data_.range(InvRMSB,InvRLSB) = invr;
  }

  void setPhi(TTPhi phi) const {
    data_.range(PhiMSB,PhiLSB) = phi;
  }

  void setTanL(TTTanL tanl) const {
    data_.range(TanLMSB,TanLLSB) = tanl;
  }

  void setZ0(TTZ0 z0) const {
    data_.range(Z0MSB,Z0LSB) = z0;
  }

  void setD0(TTD0 d0) const {
    data_.range(D0MSB,D0LSB) = d0;
  }

  void setChi2rphi(TTChi2rphi chi2rphi) const {
    data_.range(Chi2rphiMSB,Chi2rphiLSB) = chi2rphi;
  }

  void setChi2rz(TTChi2rz chi2rz) const {
    data_.range(Chi2rzMSB,Chi2rzLSB) = chi2rz;
  }

  void setBendChi2(TTBendChi2 bendchi2) const {
    data_.range(BendChi2MSB,BendChi2LSB) = bendchi2;
  }

  void setHitPattern(TTHitPattern hitpattern) const {
    data_.range(HitPatternMSB,HitPatternLSB) = hitpattern;
  }

  void setMVATQ(TTMVATQ mvatq) const {
    data_.range(MVATQMSB,MVATQLSB) = mvatq;
  }

  void setMVAres(TTMVAres mvares) const {
    data_.range(MVAresMSB,MVAresLSB) = mvares;
  }

  void setTkValid(TTTkValid tkvalid) const {
    data_.range(TkValidMSB,TkValidLSB) = tkvalid;
  }

private:

  TrackData data_;

};



#endif

