#ifndef TrackletAlgorithm_TrackFitMemory_h
#define TrackletAlgorithm_TrackFitMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// TrackFitBase is where we define the bit widths.
template<int NBarrelStubs, int NDiskStubs>
class TrackFitBase
{
public:
  static const unsigned short kNStubs = NBarrelStubs + NDiskStubs;

  enum BitWidths {
    // Bit size for track word fields
    kTFValidSize = 1,
    kTFSeedTypeSize = 3,
    kTFPhiRegionSize = 3, //phi region size. Used for combined modules, set to zero for non-CM
    kTFRinvSize = 14,
    kTFPhi0Size = 18,
    kTFZ0Size = 10,
    kTFTSize = 14,
    kTFHitCountSize = 3,
    kTFHitMapSize = kTFHitCountSize * 8,
    // Bit size for stub word fields
    kTFTrackIndexSize = 7,
    kTFStubIndexSize = 10,
    kTFBarrelStubRSize = 7,
    kTFDiskStubRSize = 12,
    kTFPhiResidSize = 12,
    kTFZResidSize = 9,
    kTFRResidSize = 7,
    // Bit size for track and stub words
    kTrackWordSize =  kTFValidSize + kTFSeedTypeSize + 2 * kTFPhiRegionSize + 2 * kNBits_MemAddr + kTFRinvSize + kTFPhi0Size + kTFZ0Size + kTFTSize + kTFHitMapSize,
    kBarrelStubSize = kTFValidSize + kTFTrackIndexSize + kTFStubIndexSize + kTFBarrelStubRSize + kTFPhiResidSize + kTFZResidSize,
    kDiskStubSize =   kTFValidSize + kTFTrackIndexSize + kTFStubIndexSize + kTFDiskStubRSize + kTFPhiResidSize + kTFRResidSize,
    // Bit size for full TrackFitMemory
    kTrackFitSize = kTrackWordSize + NBarrelStubs * kBarrelStubSize + NDiskStubs * kDiskStubSize
  };
};

// Intermediate class between TrackFitBase and TrackFit where some LSBs and
// MSBs are defined dynamically via constexpr.
template<int NBarrelStubs, int NDiskStubs>
class TrackFitBits : public TrackFitBase<NBarrelStubs, NDiskStubs>
{
public:
  static constexpr unsigned kTFStubRZResidLSB(const int i) {
    return (i >= NBarrelStubs ? ((TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - i - 1) * TrackFitBase<NBarrelStubs, NDiskStubs>::kDiskStubSize) :
           (NDiskStubs * TrackFitBase<NBarrelStubs, NDiskStubs>::kDiskStubSize + (NBarrelStubs - i - 1) * TrackFitBase<NBarrelStubs, NDiskStubs>::kBarrelStubSize));
  }
  static constexpr unsigned kTFStubRZResidMSB(const int i) {
    return (i >= NBarrelStubs ? (kTFStubRZResidLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFRResidSize - 1) :
           (kTFStubRZResidLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFZResidSize - 1));
  }
  static constexpr unsigned kTFStubPhiResidLSB(const int i) {
    return kTFStubRZResidMSB(i) + 1;
  }
  static constexpr unsigned kTFStubPhiResidMSB(const int i) {
    return kTFStubPhiResidLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhiResidSize - 1;
  }
  static constexpr unsigned kTFStubRLSB(const int i) {
    return kTFStubPhiResidMSB(i) + 1;
  }
  static constexpr unsigned kTFStubRMSB(const int i) {
    return (i >= NBarrelStubs ? (kTFStubRLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFDiskStubRSize - 1) :
           (kTFStubRLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFBarrelStubRSize - 1));
  }
  static constexpr unsigned kTFStubIndexLSB(const int i) {
    return kTFStubRMSB(i) + 1;
  }
  static constexpr unsigned kTFStubIndexMSB(const int i) {
    return (kTFStubIndexLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFStubIndexSize - 1);
  }
  static constexpr unsigned kTFTrackIndexLSB(const int i) {
    return kTFStubIndexMSB(i) + 1;
  }
  static constexpr unsigned kTFTrackIndexMSB(const int i) {
    return (kTFTrackIndexLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFTrackIndexSize - 1);
  }
  static constexpr unsigned kTFStubValidLSB(const int i) {
    return kTFTrackIndexMSB(i) + 1;
  }
  static constexpr unsigned kTFStubValidMSB(const int i) {
    return (kTFStubValidLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFValidSize - 1);
  }
  static constexpr unsigned kTFHitCountSizeLSB(const int i) {
    return (kTFStubValidMSB(0) + (7 - i) * TrackFitBase<NBarrelStubs, NDiskStubs>::kTFHitCountSize + 1);
  }
  static constexpr unsigned kTFHitCountSizeMSB(const int i) {
    return (kTFHitCountSizeLSB(i) + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFHitCountSize - 1);
  }
};

// Data object definition:
// Currently The TrackFit object is specific to L1L2-seeded tracks, containing
// four matched barrel stubs and four matched disk stubs, as well as a track
// word that contains the tracklet parameters.
template<int NBarrelStubs, int NDiskStubs>
class TrackFit : public TrackFitBits<NBarrelStubs, NDiskStubs>
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackFitMemory word for different fields
    kTFHitMapLSB = TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(0) + 1,
    kTFHitMapMSB = kTFHitMapLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFHitMapSize - 1,
    kTFTLSB = kTFHitMapMSB + 1,
    kTFTMSB = kTFTLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFTSize - 1,
    kTFZ0LSB = kTFTMSB + 1,
    kTFZ0MSB = kTFZ0LSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFZ0Size - 1,
    kTFPhi0LSB = kTFZ0MSB + 1,
    kTFPhi0MSB = kTFPhi0LSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhi0Size - 1,
    kTFRinvLSB = kTFPhi0MSB + 1,
    kTFRinvMSB = kTFRinvLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFRinvSize - 1,
    kTFStubIndexOuterLSB = kTFRinvMSB + 1,
    kTFStubIndexOuterMSB = kTFStubIndexOuterLSB + kNBits_MemAddr - 1,
    kTFStubIndexInnerLSB = kTFStubIndexOuterMSB + 1,
    kTFStubIndexInnerMSB = kTFStubIndexInnerLSB + kNBits_MemAddr - 1,
    kTFPhiRegionOuterLSB = kTFStubIndexInnerMSB + 1,
    kTFPhiRegionOuterMSB = kTFPhiRegionOuterLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhiRegionSize - 1,
    kTFPhiRegionInnerLSB = kTFPhiRegionOuterMSB + 1,
    kTFPhiRegionInnerMSB = kTFPhiRegionInnerLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhiRegionSize - 1,
    kTFSeedTypeLSB = kTFPhiRegionInnerMSB + 1,
    kTFSeedTypeMSB = kTFSeedTypeLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFSeedTypeSize - 1,
    kTFTrackValidLSB = kTFSeedTypeMSB + 1,
    kTFTrackValidMSB = kTFTrackValidLSB + TrackFitBase<NBarrelStubs, NDiskStubs>::kTFValidSize - 1
  };

  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFValidSize> TFVALID;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFSeedTypeSize> TFSEEDTYPE;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhiRegionSize> TFPHIREGION;
  typedef ap_uint<kNBits_MemAddr> TFSEEDSTUBINDEX;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFRinvSize> TFRINV;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhi0Size> TFPHI0;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFZ0Size> TFZ0;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFTSize> TFT;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFHitMapSize> TFHITMAP;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFHitCountSize> TFHITCOUNT;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFTrackIndexSize> TFTRACKINDEX;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFStubIndexSize> TFSTUBINDEX;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFBarrelStubRSize> TFBARRELSTUBR;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFDiskStubRSize> TFDISKSTUBR;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFPhiResidSize> TFSTUBPHIRESID;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFZResidSize> TFSTUBZRESID;
  typedef ap_int<TrackFitBase<NBarrelStubs, NDiskStubs>::kTFRResidSize> TFSTUBRRESID;

  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTrackWordSize> TrackWord;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kBarrelStubSize> BarrelStubWord;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kDiskStubSize> DiskStubWord;
  typedef ap_uint<TrackFitBase<NBarrelStubs, NDiskStubs>::kTrackFitSize> TrackFitData;

  // Constructors
  TrackFit(const TrackFitData& newdata):
    data_(newdata)
  {}

  TrackFit(const TFSEEDTYPE seedtype) :
    data_(0)
  {
    setSeedType(seedtype);
  }

  TrackFit()
  {}

  #ifndef __SYNTHESIS__
  TrackFit(const char* datastr, int base = 16)
  {
    TrackFitData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return TrackFitBase<NBarrelStubs, NDiskStubs>::kTrackFitSize;}

  TrackFitData raw() const {return data_;}

  TFVALID getTrackValid() const {
    return data_.range(kTFTrackValidMSB,kTFTrackValidLSB);
  }

  TFSEEDTYPE getSeedType() const {
    return data_.range(kTFSeedTypeMSB,kTFSeedTypeLSB);
  }

  TFPHIREGION getPhiRegionInner() const {
    return data_.range(kTFPhiRegionInnerMSB,kTFPhiRegionInnerLSB);
  }

  TFPHIREGION getPhiRegionOuter() const {
    return data_.range(kTFPhiRegionOuterMSB,kTFPhiRegionOuterLSB);
  }

  TFSEEDSTUBINDEX getStubIndexInner() const {
    return data_.range(kTFStubIndexInnerMSB,kTFStubIndexInnerLSB);
  }

  TFSEEDSTUBINDEX getStubIndexOuter() const {
    return data_.range(kTFStubIndexOuterMSB,kTFStubIndexOuterLSB);
  }

  TFRINV getRinv() const {
    return data_.range(kTFRinvMSB,kTFRinvLSB);
  }

  TFPHI0 getPhi0() const {
    return data_.range(kTFPhi0MSB,kTFPhi0LSB);
  }

  TFZ0 getZ0() const {
    return data_.range(kTFZ0MSB,kTFZ0LSB);
  }

  TFT getT() const {
    return data_.range(kTFTMSB,kTFTLSB);
  }

  // The hit map tells how many stubs are matched to the track in each possible
  // layer/disk. For example, for L1L2-seeded tracks, there are four possible
  // layers with matches (L3, L4, L5, and L6) and four possible disks (D1, D2,
  // D3, and D4). Each of these corresponds to three bits in the hit map that
  // count the number of actual matches in that layer/disk. An L1L2-seeded
  // track with a match in each possible layer would have the following hit
  // map:
  // --- L3  L4  L5  L6  D1  D2  D3  D4 ---
  // 0b(001 001 001 001 000 000 000 000) = 0x249000
  TFHITMAP getHitMap() const {
    return data_.range(kTFHitMapMSB,kTFHitMapLSB);
  }

  template<uint8_t Hit>
  TFHITCOUNT getHitCount() const {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFHitCountSizeMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFHitCountSizeLSB(Hit));
  }

  template<uint8_t Hit>
  TFVALID getStubValid() const {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidLSB(Hit));
  }

  template<uint8_t Hit>
  TFTRACKINDEX getTrackIndex() const {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFTrackIndexMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFTrackIndexLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBINDEX getStubIndex() const {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubIndexMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubIndexLSB(Hit));
  }

  template<uint8_t Hit>
  TFBARRELSTUBR getBarrelStubR() const {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRLSB(Hit));
  }

  template<uint8_t Hit>
  TFDISKSTUBR getDiskStubR() const {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBPHIRESID getStubPhiResid() const {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubPhiResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubPhiResidLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBZRESID getStubZResid() const {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBRRESID getStubRResid() const {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit));
  }

  TrackWord getTrackWord() const {
    return data_.range(kTFTrackValidMSB,kTFHitMapLSB);
  }

  template<uint8_t Hit>
  BarrelStubWord getBarrelStubWord() const {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit));
  }

  template<uint8_t Hit>
  DiskStubWord getDiskStubWord() const {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit));
  }

  // Setter
  void setTrackValid(const TFVALID valid) {
    data_.range(kTFTrackValidMSB,kTFTrackValidLSB) = valid;
  }

  void setSeedType(const TFSEEDTYPE seedtype) {
    data_.range(kTFSeedTypeMSB,kTFSeedTypeLSB) = seedtype;
  }

  void setPhiRegionInner(const TFPHIREGION phiRegion) {
    data_.range(kTFPhiRegionInnerMSB,kTFPhiRegionInnerLSB) = phiRegion;
  }

  void setPhiRegionOuter(const TFPHIREGION phiRegion) {
    data_.range(kTFPhiRegionOuterMSB,kTFPhiRegionOuterLSB) = phiRegion;
  }

  void setStubIndexInner(const TFSEEDSTUBINDEX seedStubIndex) {
    data_.range(kTFStubIndexInnerMSB,kTFStubIndexInnerLSB) = seedStubIndex;
  }

  void setStubIndexOuter(const TFSEEDSTUBINDEX seedStubIndex) {
    data_.range(kTFStubIndexOuterMSB,kTFStubIndexOuterLSB) = seedStubIndex;
  }

  void setRinv(const TFRINV rinv) {
    data_.range(kTFRinvMSB,kTFRinvLSB) = rinv;
  }

  void setPhi0(const TFPHI0 phi0) {
    data_.range(kTFPhi0MSB,kTFPhi0LSB) = phi0;
  }

  void setZ0(const TFZ0 z0) {
    data_.range(kTFZ0MSB,kTFZ0LSB) = z0;
  }

  void setT(const TFT t) {
    data_.range(kTFTMSB,kTFTLSB) = t;
  }

  void setHitMap(const TFHITMAP hitmap) {
    data_.range(kTFHitMapMSB,kTFHitMapLSB) = hitmap;
  }

  template<uint8_t Hit>
  void setHitCount(const TFHITCOUNT hitcount) {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFHitCountSizeMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFHitCountSizeLSB(Hit)) = hitcount;
  }

  template<uint8_t Hit>
  void setStubValid(const TFVALID valid) {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidLSB(Hit)) = valid;
  }

  template<uint8_t Hit>
  void setTrackIndex(const TFTRACKINDEX trackindex) {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFTrackIndexMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFTrackIndexLSB(Hit)) = trackindex;
  }

  template<uint8_t Hit>
  void setStubIndex(const TFSTUBINDEX stubindex) {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubIndexMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubIndexLSB(Hit)) = stubindex;
  }

  template<uint8_t Hit>
  void setBarrelStubR(const TFBARRELSTUBR barrelstubr) {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRLSB(Hit)) = barrelstubr;
  }

  template<uint8_t Hit>
  void setDiskStubR(const TFDISKSTUBR diskstubr) {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRLSB(Hit)) = diskstubr;
  }

  template<uint8_t Hit>
  void setStubPhiResid(const TFSTUBPHIRESID stubphiresid) {
    //static_assert(Hit >= 0 && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubPhiResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubPhiResidLSB(Hit)) = stubphiresid;
  }

  template<uint8_t Hit>
  void setStubZResid(const TFSTUBZRESID stubzresid) {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit)) = stubzresid;
  }

  template<uint8_t Hit>
  void setStubRResid(const TFSTUBRRESID stubrresid) {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit)) = stubrresid;
  }

  template<uint8_t Hit>
  void setBarrelStub(const TFVALID valid, const TFSTUBINDEX stubindex, const TFBARRELSTUBR r, const TFSTUBPHIRESID phiresid, const TFSTUBZRESID zresid) {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    setStubValid<Hit>(valid);
    setStubIndex<Hit>(stubindex);
    setBarrelStubR<Hit>(r);
    setStubPhiResid<Hit>(phiresid);
    setStubZResid<Hit>(zresid);
    setHitCount<Hit>(valid ? 1 : 0);
  }

  template<uint8_t Hit>
  void setDiskStub(const TFVALID valid, const TFSTUBINDEX stubindex, const TFDISKSTUBR r, const TFSTUBPHIRESID phiresid, const TFSTUBRRESID rresid) {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    setStubValid<Hit>(valid);
    setStubIndex<Hit>(stubindex);
    setDiskStubR<Hit>(r);
    setStubPhiResid<Hit>(phiresid);
    setStubRResid<Hit>(rresid);
    setHitCount<Hit>(valid ? 1 : 0);
  }

  void setTrackWord(const TrackWord &word) {
    data_.range(kTFTrackValidMSB,kTFHitMapLSB) = word;
  }

  template<uint8_t Hit>
  void setBarrelStubWord(const BarrelStubWord &word) {
    //static_assert(Hit >= 0 && Hit <= NBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit)) = word;
  }

  template<uint8_t Hit>
  void setDiskStubWord(const DiskStubWord &word) {
    //static_assert(Hit >= NBarrelStubs && Hit <= TrackFitBase<NBarrelStubs, NDiskStubs>::kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubValidMSB(Hit),TrackFitBits<NBarrelStubs, NDiskStubs>::kTFStubRZResidLSB(Hit)) = word;
  }

#ifdef CMSSW_GIT_HASH
  template<uint8_t Hit>
  std::string hitStr(bool isDisk) const {
    std::string str = decodeToBits(getStubValid<Hit>());
    str += "|"+decodeToBits(getTrackIndex<Hit>());
    str += "|"+decodeToBits(getStubIndex<Hit>());
    if(isDisk) str += "|"+decodeToBits(getDiskStubR<Hit>());
    else str += "|"+decodeToBits(getBarrelStubR<Hit>());
    str += "|"+decodeToBits(getStubPhiResid<Hit>());
    if(isDisk) str += "|"+decodeToBits(getStubRResid<Hit>());
    else str += "|"+decodeToBits(getStubZResid<Hit>());
    return str;
  }

  std::string getBitStr() const {
    std::string str = decodeToBits(getTrackValid());
    str += "|"+decodeToBits(getSeedType());
    str += "|"+decodeToBits(getPhiRegionInner());
    str += "|"+decodeToBits(getPhiRegionOuter());
    str += "|"+decodeToBits(getStubIndexInner());
    str += "|"+decodeToBits(getStubIndexOuter());
    str += "|"+decodeToBits(getRinv());
    str += "|"+decodeToBits(getPhi0());
    str += "|"+decodeToBits(getZ0());
    str += "|"+decodeToBits(getT());
    str += "|"+decodeToBits(getHitMap());
    for(int i=0; i < NBarrelStubs; i++){
      switch (i) {
        case 0:
          str += "|"+hitStr<0>(false);
          break;
        case 1:
          str += "|"+hitStr<1>(false);
          break;
        case 2:
          str += "|"+hitStr<2>(false);
          break;
        case 3:
          str += "|"+hitStr<3>(false);
          break;
      }
    }
    for(int i=0; i < NDiskStubs; i++){
      switch (i) {
        case 0:
          str += "|"+hitStr<NBarrelStubs+0>(true);
          break;
        case 1:
          str += "|"+hitStr<NBarrelStubs+1>(true);
          break;
        case 2:
          str += "|"+hitStr<NBarrelStubs+2>(true);
          break;
        case 3:
          str += "|"+hitStr<NBarrelStubs+3>(true);
          break;
      }
    }

    return str;
  }


#endif

private:

  TrackFitData data_;

};

// Memory definition
template<int NBarrelStubs, int NDiskStubs> using TrackFitMemory = MemoryTemplate<TrackFit<NBarrelStubs, NDiskStubs>, 1, kNBits_MemAddr>;

#endif
