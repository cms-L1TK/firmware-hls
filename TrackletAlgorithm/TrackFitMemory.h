#ifndef TrackletAlgorithm_TrackFitMemory_h
#define TrackletAlgorithm_TrackFitMemory_h

#include "Constants.h"
#include "MemoryTemplate.h"

// TrackFitBase is where we define the bit widths.
class TrackFitBase
{
public:
  static const unsigned short kNBarrelStubs = 4;
  static const unsigned short kNDiskStubs = 4;
  static const unsigned short kNStubs = kNBarrelStubs + kNDiskStubs;

  enum BitWidths {
    // Bit size for track word fields
    kTFValidSize = 1,
    kTFSeedTypeSize = 3,
    kTFRinvSize = 14,
    kTFPhi0Size = 18,
    kTFZ0Size = 10,
    kTFTSize = 14,
    kTFHitCountSize = 3,
    kTFHitMapSize = kTFHitCountSize * kNStubs,
    // Bit size for stub word fields
    kTFTrackIndexSize = 7,
    kTFStubIndexSize = 10,
    kTFBarrelStubRSize = 7,
    kTFDiskStubRSize = 12,
    kTFPhiResidSize = 12,
    kTFZResidSize = 9,
    kTFRResidSize = 7,
    // Bit size for track and stub words
    kTrackWordSize =  kTFValidSize + kTFSeedTypeSize + kTFRinvSize + kTFPhi0Size + kTFZ0Size + kTFTSize + kTFHitMapSize,
    kBarrelStubSize = kTFValidSize + kTFTrackIndexSize + kTFStubIndexSize + kTFBarrelStubRSize + kTFPhiResidSize + kTFZResidSize,
    kDiskStubSize =   kTFValidSize + kTFTrackIndexSize + kTFStubIndexSize + kTFDiskStubRSize + kTFPhiResidSize + kTFRResidSize,
    // Bit size for full TrackFitMemory
    kTrackFitSize = kTrackWordSize + kNBarrelStubs * kBarrelStubSize + kNDiskStubs * kDiskStubSize
  };
};

// Intermediate class between TrackFitBase and TrackFit where some LSBs and
// MSBs are defined dynamically via constexpr.
class TrackFitBits : public TrackFitBase
{
public:
  static constexpr unsigned kTFStubRZResidLSB(const unsigned i) {
    return (i >= kNBarrelStubs ? ((kNStubs - i - 1) * kDiskStubSize) :
           (kNDiskStubs * kDiskStubSize + (kNBarrelStubs - i - 1) * kBarrelStubSize));
  }
  static constexpr unsigned kTFStubRZResidMSB(const unsigned i) {
    return (i >= kNBarrelStubs ? (kTFStubRZResidLSB(i) + TrackFitBase::kTFRResidSize - 1) :
           (kTFStubRZResidLSB(i) + TrackFitBase::kTFZResidSize - 1));
  }
  static constexpr unsigned kTFStubPhiResidLSB(const unsigned i) {
    return kTFStubRZResidMSB(i) + 1;
  }
  static constexpr unsigned kTFStubPhiResidMSB(const unsigned i) {
    return kTFStubPhiResidLSB(i) + TrackFitBase::kTFPhiResidSize - 1;
  }
  static constexpr unsigned kTFStubRLSB(const unsigned i) {
    return kTFStubPhiResidMSB(i) + 1;
  }
  static constexpr unsigned kTFStubRMSB(const unsigned i) {
    return (i >= kNBarrelStubs ? (kTFStubRLSB(i) + TrackFitBase::kTFDiskStubRSize - 1) :
           (kTFStubRLSB(i) + TrackFitBase::kTFBarrelStubRSize - 1));
  }
  static constexpr unsigned kTFStubIndexLSB(const unsigned i) {
    return kTFStubRMSB(i) + 1;
  }
  static constexpr unsigned kTFStubIndexMSB(const unsigned i) {
    return (kTFStubIndexLSB(i) + TrackFitBase::kTFStubIndexSize - 1);
  }
  static constexpr unsigned kTFTrackIndexLSB(const unsigned i) {
    return kTFStubIndexMSB(i) + 1;
  }
  static constexpr unsigned kTFTrackIndexMSB(const unsigned i) {
    return (kTFTrackIndexLSB(i) + TrackFitBase::kTFTrackIndexSize - 1);
  }
  static constexpr unsigned kTFStubValidLSB(const unsigned i) {
    return kTFTrackIndexMSB(i) + 1;
  }
  static constexpr unsigned kTFStubValidMSB(const unsigned i) {
    return (kTFStubValidLSB(i) + TrackFitBase::kTFValidSize - 1);
  }
  static constexpr unsigned kTFHitCountLSB(const unsigned i) {
    return (kTFStubValidMSB(0) + (kNStubs - i - 1) * TrackFitBase::kTFHitCountSize + 1);
  }
  static constexpr unsigned kTFHitCountMSB(const unsigned i) {
    return (kTFHitCountLSB(i) + TrackFitBase::kTFHitCountSize - 1);
  }
};

// Data object definition:
// Currently The TrackFit object is specific to L1L2-seeded tracks, containing
// four matched barrel stubs and four matched disk stubs, as well as a track
// word that contains the tracklet parameters.
class TrackFit : public TrackFitBits
{
public:
  enum BitLocations {
    // The location of the least significant bit (LSB) and most significant bit (MSB) in the TrackFitMemory word for different fields
    kTFHitMapLSB = TrackFitBits::kTFStubValidMSB(0) + 1,
    kTFHitMapMSB = kTFHitMapLSB + TrackFitBase::kTFHitMapSize - 1,
    kTFTLSB = kTFHitMapMSB + 1,
    kTFTMSB = kTFTLSB + TrackFitBase::kTFTSize - 1,
    kTFZ0LSB = kTFTMSB + 1,
    kTFZ0MSB = kTFZ0LSB + TrackFitBase::kTFZ0Size - 1,
    kTFPhi0LSB = kTFZ0MSB + 1,
    kTFPhi0MSB = kTFPhi0LSB + TrackFitBase::kTFPhi0Size - 1,
    kTFRinvLSB = kTFPhi0MSB + 1,
    kTFRinvMSB = kTFRinvLSB + TrackFitBase::kTFRinvSize - 1,
    kTFSeedTypeLSB = kTFRinvMSB + 1,
    kTFSeedTypeMSB = kTFSeedTypeLSB + TrackFitBase::kTFSeedTypeSize - 1,
    kTFTrackValidLSB = kTFSeedTypeMSB + 1,
    kTFTrackValidMSB = kTFTrackValidLSB + TrackFitBase::kTFValidSize - 1
  };

  typedef ap_uint<TrackFitBase::kTFValidSize> TFVALID;
  typedef ap_uint<TrackFitBase::kTFSeedTypeSize> TFSEEDTYPE;
  typedef ap_int<TrackFitBase::kTFRinvSize> TFRINV;
  typedef ap_uint<TrackFitBase::kTFPhi0Size> TFPHI0;
  typedef ap_int<TrackFitBase::kTFZ0Size> TFZ0;
  typedef ap_int<TrackFitBase::kTFTSize> TFT;
  typedef ap_uint<TrackFitBase::kTFHitMapSize> TFHITMAP;
  typedef ap_uint<TrackFitBase::kTFHitCountSize> TFHITCOUNT;
  typedef ap_uint<TrackFitBase::kTFTrackIndexSize> TFTRACKINDEX;
  typedef ap_uint<TrackFitBase::kTFStubIndexSize> TFSTUBINDEX;
  typedef ap_uint<TrackFitBase::kTFBarrelStubRSize> TFBARRELSTUBR;
  typedef ap_uint<TrackFitBase::kTFDiskStubRSize> TFDISKSTUBR;
  typedef ap_int<TrackFitBase::kTFPhiResidSize> TFSTUBPHIRESID;
  typedef ap_int<TrackFitBase::kTFZResidSize> TFSTUBZRESID;
  typedef ap_int<TrackFitBase::kTFRResidSize> TFSTUBRRESID;

  typedef ap_uint<TrackFitBase::kTrackWordSize> TrackWord;
  typedef ap_uint<TrackFitBase::kBarrelStubSize> BarrelStubWord;
  typedef ap_uint<TrackFitBase::kDiskStubSize> DiskStubWord;
  typedef ap_uint<TrackFitBase::kTrackFitSize> TrackFitData;

  // Constructors
  TrackFit(const TrackFitData& newdata):
    data_(newdata)
  {}

  TrackFit(const TFTRACKINDEX trackIndex, const TFSEEDTYPE seedtype) :
    data_( ((((((((((((((((((((((((((((((((((((((((((((((((((((((0,seedtype),TFRINV(0)),TFPHI0(0)),TFZ0(0)),TFT(0)),TFHITMAP(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFBARRELSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBZRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFBARRELSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBZRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFBARRELSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBZRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFBARRELSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBZRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFDISKSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBRRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFDISKSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBRRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFDISKSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBRRESID(0)),
             TFVALID(0)),trackIndex),TFSTUBINDEX(0)),TFDISKSTUBR(0)),TFSTUBPHIRESID(0)),TFSTUBRRESID(0)) )

  {}

  TrackFit() :
    data_(0)
  {}

  #ifndef __SYNTHESIS__
  TrackFit(const char* datastr, int base = 16)
  {
    TrackFitData newdata(datastr, base);
    data_ = newdata;
  }
  #endif

  // Getter
  static constexpr int getWidth() {return TrackFitBase::kTrackFitSize;}

  TrackFitData raw() const {return data_;}

  TFVALID getTrackValid() const {
    return data_.range(kTFTrackValidMSB,kTFTrackValidLSB);
  }

  TFSEEDTYPE getSeedType() const {
    return data_.range(kTFSeedTypeMSB,kTFSeedTypeLSB);
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
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFHitCountMSB(Hit),TrackFitBits::kTFHitCountLSB(Hit));
  }

  template<uint8_t Hit>
  TFVALID getStubValid() const {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubValidLSB(Hit));
  }

  template<uint8_t Hit>
  TFTRACKINDEX getTrackIndex() const {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFTrackIndexMSB(Hit),TrackFitBits::kTFTrackIndexLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBINDEX getStubIndex() const {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubIndexMSB(Hit),TrackFitBits::kTFStubIndexLSB(Hit));
  }

  template<uint8_t Hit>
  TFBARRELSTUBR getBarrelStubR() const {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubRMSB(Hit),TrackFitBits::kTFStubRLSB(Hit));
  }

  template<uint8_t Hit>
  TFDISKSTUBR getDiskStubR() const {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubRMSB(Hit),TrackFitBits::kTFStubRLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBPHIRESID getStubPhiResid() const {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubPhiResidMSB(Hit),TrackFitBits::kTFStubPhiResidLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBZRESID getStubZResid() const {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubRZResidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
  }

  template<uint8_t Hit>
  TFSTUBRRESID getStubRResid() const {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubRZResidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
  }

  TrackWord getTrackWord() const {
    return data_.range(kTFTrackValidMSB,kTFHitMapLSB);
  }

  template<uint8_t Hit>
  BarrelStubWord getBarrelStubWord() const {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
  }

  template<uint8_t Hit>
  DiskStubWord getDiskStubWord() const {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    return data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit));
  }

  // Setter
  void setTrackValid(const TFVALID valid) {
    data_.range(kTFTrackValidMSB,kTFTrackValidLSB) = valid;
  }

  void setSeedType(const TFSEEDTYPE seedtype) {
    data_.range(kTFSeedTypeMSB,kTFSeedTypeLSB) = seedtype;
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
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFHitCountMSB(Hit),TrackFitBits::kTFHitCountLSB(Hit)) = hitcount;
  }

  template<uint8_t Hit>
  void setStubValid(const TFVALID valid) {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubValidLSB(Hit)) = valid;
  }

  template<uint8_t Hit>
  void setTrackIndex(const TFTRACKINDEX trackindex) {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFTrackIndexMSB(Hit),TrackFitBits::kTFTrackIndexLSB(Hit)) = trackindex;
  }

  template<uint8_t Hit>
  void setStubIndex(const TFSTUBINDEX stubindex) {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubIndexMSB(Hit),TrackFitBits::kTFStubIndexLSB(Hit)) = stubindex;
  }

  template<uint8_t Hit>
  void setBarrelStubR(const TFBARRELSTUBR barrelstubr) {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubRMSB(Hit),TrackFitBits::kTFStubRLSB(Hit)) = barrelstubr;
  }

  template<uint8_t Hit>
  void setDiskStubR(const TFDISKSTUBR diskstubr) {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubRMSB(Hit),TrackFitBits::kTFStubRLSB(Hit)) = diskstubr;
  }

  template<uint8_t Hit>
  void setStubPhiResid(const TFSTUBPHIRESID stubphiresid) {
    static_assert(Hit >= 0 && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubPhiResidMSB(Hit),TrackFitBits::kTFStubPhiResidLSB(Hit)) = stubphiresid;
  }

  template<uint8_t Hit>
  void setStubZResid(const TFSTUBZRESID stubzresid) {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubRZResidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = stubzresid;
  }

  template<uint8_t Hit>
  void setStubRResid(const TFSTUBRRESID stubrresid) {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubRZResidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = stubrresid;
  }

  template<uint8_t Hit>
  void setBarrelStub(const TFVALID valid, const TFSTUBINDEX stubindex, const TFBARRELSTUBR r, const TFSTUBPHIRESID phiresid, const TFSTUBZRESID zresid) {
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    setStubValid<Hit>(valid);
    setStubIndex<Hit>(stubindex);
    setBarrelStubR<Hit>(r);
    setStubPhiResid<Hit>(phiresid);
    setStubZResid<Hit>(zresid);
    setHitCount<Hit>(valid ? 1 : 0);
  }

  template<uint8_t Hit>
  void setDiskStub(const TFVALID valid, const TFSTUBINDEX stubindex, const TFDISKSTUBR r, const TFSTUBPHIRESID phiresid, const TFSTUBRRESID rresid) {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
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
    static_assert(Hit >= 0 && Hit <= kNBarrelStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
  }

  template<uint8_t Hit>
  void setDiskStubWord(const DiskStubWord &word) {
    static_assert(Hit >= kNBarrelStubs && Hit <= kNStubs - 1, "Invalid hit number.");
    data_.range(TrackFitBits::kTFStubValidMSB(Hit),TrackFitBits::kTFStubRZResidLSB(Hit)) = word;
  }

private:

  TrackFitData data_;

};

// Memory definition
using TrackFitMemory = MemoryTemplate<TrackFit, 1, kNBits_MemAddr>;

#endif
