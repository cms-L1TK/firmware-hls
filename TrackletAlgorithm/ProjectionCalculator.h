#ifndef TrackletAlgorithm_ProjectionCalculator_h
#define TrackletAlgorithm_ProjectionCalculator_h

#include <cmath>

// #include "AllStubMemory.h"
// #include "AllStubInnerMemory.h"
#include "TrackletParameterMemory.h"
#include "TrackletProjectionMemory.h"
//#include "VMStubTEOuterMemoryCM.h"
// #include "TEBuffer.h"
#include "TrackletEngineUnit.h"
// #include "TrackletProcessor_parameters.h"

namespace PC {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by ProjectionCalculator.
////////////////////////////////////////////////////////////////////////////////
  namespace Types {
    typedef ap_uint<2> nASMem;

    typedef ap_int<13> rmean;
    typedef ap_int<14> zmean;
    typedef ap_int<15> rinv;
    typedef ap_int<12> z0;
    typedef ap_uint<20> phiL;
    typedef ap_int<15> zL;
    typedef ap_int<11> der_phiL;
    typedef ap_int<10> der_zL;
    typedef ap_uint<16> phiD;
    typedef ap_uint<14> rD;
    typedef ap_int<10> der_phiD;
    typedef ap_int<10> der_rD;
    typedef ap_uint<1> flag;
  }

  enum projout_index_barrel_ps {L1PHIA = 0, L1PHIB = 1, L1PHIC = 2, L1PHID = 3, L1PHIE = 4, L1PHIF = 5, L1PHIG = 6, L1PHIH = 7, L2PHIA = 8, L2PHIB = 9, L2PHIC = 10, L2PHID = 11, L3PHIA = 12, L3PHIB = 13, L3PHIC = 14, L3PHID = 15, N_PROJOUT_BARRELPS = 16};
  enum projout_index_barrel_2s {L4PHIA = 0, L4PHIB = 1, L4PHIC = 2, L4PHID = 3, L5PHIA = 4, L5PHIB = 5, L5PHIC = 6, L5PHID = 7, L6PHIA = 8, L6PHIB = 9, L6PHIC = 10, L6PHID = 11, N_PROJOUT_BARREL2S = 12};
  enum projout_index_disk      {D1PHIA = 0, D1PHIB = 1, D1PHIC = 2, D1PHID = 3, D2PHIA = 4, D2PHIB = 5, D2PHIC = 6, D2PHID = 7, D3PHIA = 8, D3PHIB = 9, D3PHIC = 10, D3PHID = 11, D4PHIA = 12, D4PHIB = 13, D4PHIC = 14, D4PHID = 15, D5PHIA = 16, D5PHIB = 17, D5PHIC = 18, D5PHID = 19, N_PROJOUT_DISK = 20};

  static const uint8_t nproj_L1 = L1PHIH - L1PHIA + 1;
  static const uint8_t nproj_L2 = L2PHID - L2PHIA + 1;
  static const uint8_t nproj_L3 = L3PHID - L3PHIA + 1;
  static const uint8_t nproj_L4 = L4PHID - L4PHIA + 1;
  static const uint8_t nproj_L5 = L5PHID - L5PHIA + 1;
  static const uint8_t nproj_L6 = L6PHID - L6PHIA + 1;
  static const uint8_t nproj_D1 = D1PHID - D1PHIA + 1;
  static const uint8_t nproj_D2 = D2PHID - D2PHIA + 1;
  static const uint8_t nproj_D3 = D3PHID - D3PHIA + 1;
  static const uint8_t nproj_D4 = D4PHID - D4PHIA + 1;
  static const uint8_t nproj_D5 = D5PHID - D5PHIA + 1;

  static const uint8_t shift_L1 = 0;
  static const uint8_t shift_L2 = shift_L1 + nproj_L1;
  static const uint8_t shift_L3 = shift_L2 + nproj_L2;
  static const uint8_t shift_L4 = shift_L3 + nproj_L3;
  static const uint8_t shift_L5 = shift_L4 + nproj_L4;
  static const uint8_t shift_L6 = shift_L5 + nproj_L5;

  static const uint8_t shift_D1 = 0;
  static const uint8_t shift_D2 = shift_D1 + nproj_D1;
  static const uint8_t shift_D3 = shift_D2 + nproj_D2;
  static const uint8_t shift_D4 = shift_D3 + nproj_D3;
  static const uint8_t shift_D5 = shift_D4 + nproj_D4;

  static const uint32_t mask_L1 = 0xFF << shift_L1;
  static const uint32_t mask_L2 = 0xF << shift_L2;
  static const uint32_t mask_L3 = 0xF << shift_L3;
  static const uint32_t mask_L4 = 0xF << shift_L4;
  static const uint32_t mask_L5 = 0xF << shift_L5;
  static const uint32_t mask_L6 = 0xF << shift_L6;
  static const uint32_t mask_D1 = 0xF << shift_D1;
  static const uint32_t mask_D2 = 0xF << shift_D2;
  static const uint32_t mask_D3 = 0xF << shift_D3;
  static const uint32_t mask_D4 = 0xF << shift_D4;
  static const uint32_t mask_D5 = 0xF << shift_D5;

  constexpr int itcut = floatToInt(1.0, kt);
  constexpr int irinvcut = floatToInt(rinvcut, krinv);
  constexpr int iz0cut = floatToInt(z0cut, kz0);
  constexpr int izmaxcut = floatToInt(zlength, kz); 
  constexpr int irprojmincut = floatToInt(rmindisk, krprojdisk); 
  constexpr int irprojmaxcut = floatToInt(rmaxdisk, krprojdisk); 

}
// #define LUTTYPE ap_uint<1+2*TrackletEngineUnit<Seed,iTC,InnerRegion<Seed>(), OuterRegion<Seed>()>::kNBitsRZFine+TrackletEngineUnit<Seed,iTC,InnerRegion<Seed>(),OuterRegion<Seed>()>::kNBitsRZBin>
// #define REGIONLUTTYPE ap_uint<(1<<TrackletEngineUnit<Seed,iTC,InnerRegion<Seed>(),OuterRegion<Seed>()>::kNBitsPhiBins)>
// #define lutsize  (1<<(kNbitszfinebintable+kNbitsrfinebintable))
// #define regionlutsize (1<<(AllStubInner<!(Seed==TF::D1D2||TF::D3D4) ? InnerRegion<Seed>() : DISKPS>::kASBendSize+AllStubInner<InnerRegion<Seed>()>::kASFinePhiSize))

// This is the primary interface for the ProjectionCalculator.
template<
  TF::seed Seed, // seed layer combination (TC::L1L2, TC::L3L4, etc.)
  TP::itc iTC, // letter at the end of the TC name (TC_L1L2A and TC_L5L6A have
// the same iTC); generally indicates the region of the phi sector
             // being processed
  uint8_t NTEUnits, //number of TE units
  uint8_t OuterPhiRegion, // outer phi region
  uint8_t RZBins,         // number of RZ bins in outer layer/disk
  uint8_t PhiBins,        // number of Phi bins in outer layer/dsik
  uint8_t NASMemInner, // number of inner all-stub memories
  uint16_t N // maximum number of steps
> void
  ProjectionCalculator(
		    const BXType bx,  
        BXType& bx_o,  
        TrackletParameterMemory * const trackletParameters, 
        TrackletProjectionMemory<BARRELPS> projout_barrel_ps[TC::N_PROJOUT_BARRELPS], 
        TrackletProjectionMemory<BARREL2S> projout_barrel_2s[TC::N_PROJOUT_BARREL2S], 
        TrackletProjectionMemory<DISK> projout_disk[TC::N_PROJOUT_DISK])
{
 
  

}

#endif

