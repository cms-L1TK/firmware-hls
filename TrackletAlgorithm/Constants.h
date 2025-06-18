#ifndef TrackletAlgorithm_Constants_h
#define TrackletAlgorithm_Constants_h

#include <cstdint>
#include "ap_int.h"

#ifdef CMSSW_GIT_HASH
#include "L1Trigger/TrackFindingTracklet/interface/Settings.h"
#endif

// Inline function to convert floating point values to integers, given a
// digitization constant. The 0.5 is needed to get the
// floating point truncation to agree exactly with the emulation.
inline constexpr int floatToInt(const double x, const double k) {
  return static_cast<int>(x / k + 0.5);
}

constexpr double sqrtsix = 2.4494897427831; //can not use sqrt for constexpr

//phi width of sector - including the hourglass shape for overlaps
//ideally this should be calculated, but C++ standard does not allow use of
//asin in constexpr at this time.
constexpr double phiHG_ = 1.02776;

  //Constants for coordinates and track parameter definitions
  const int n_phi_ = 17;
  const int n_r_ = 12;
  const int n_z_ = 11;
  const int n_phi0_ = 16;
  const int n_rinv_ = 13;
  const int n_t_ = 9;
  const int n_phidisk_ = n_phi_-3;
  const int n_rdisk_ = n_r_-1;

  //Constants used for tracklet parameter calculations
  const int n_delta0_ = 13;
  const int n_deltaz_ = 11;
  const int n_delta1_ = 13;
  const int n_delta2_ = 13;
  const int n_delta12_ = 13;
  const int n_a_ = 15;
  const int n_r6_ = 4;
  const int n_delta02_ = 14;
  const int n_x6_ = 15;
  const int n_HG_ = 15;  

  //Constants used for projectison to disks
  const int n_tinv_ = 12;
  const int n_y_ = 14;
  const int n_x_ = 14;
  const int n_xx6_ = 14;

  //L1L2 specific constants
  constexpr int n_Deltar_ = 24;
  constexpr int n_Deltar_Disk_ = 23;

  constexpr int n_Deltar_Overlap_ = 23;
  constexpr int n_delta0_Overlap_ = 14;
  constexpr int n_deltaz_Overlap_ = 9;
  constexpr int n_a_Overlap_ = 14;
  constexpr int n_r6_Overlap_ = 6;



  //Constants used for projectison to layers
  const int n_s_ = 12;
  const int n_s6_ = 14;


//projection layers for different seeds. Note that unused layers are indicated by
//10. This allows the use of templating to evaluate the radius for all seeds.

constexpr int kNTEUnits[8] = {5, 2, 5, 3, 3, 2, 3, 2}; // Number of TE units w.r.t. seed type
constexpr int kNTEUnitsLayerDisk[] = {0, 5, 2, 5, 0, 3, 3, 3, 0, 2, 0}; // Number of TE units w.r.t. the layer/disk number.
// The outer layerDisk of the seed type is used as index, e.g. kNTEUnits[TF::L1L2] == kNTEUnitsLayerDisk[TF::L2]. N.B.: D1 actually has two seed types (L1D1, L2D1), take the largest value for now...
constexpr int kNbitsrzbin = 3;
constexpr int kNbitsphibin = 3;

constexpr int kMaxStubsFromLink = 256;

constexpr int kTMUX = 18;   //For hourglass project
constexpr int kMaxProc(const int clockMult = 6) {
  return (kTMUX * clockMult);
}

constexpr unsigned int kNbitszfinebintable = 7;
constexpr unsigned int kNbitsrfinebintable = 4;
constexpr unsigned int kNbitszfinebintableDisk = 3;
constexpr unsigned int kNbitsrfinebintableDisk = 8;

// List of module types
namespace module {
  enum type {UNKNOWN, IR, VMR, TE, TC, PR, ME, MC, MP, NMODULES};
};

// Map from a module type to an offset used to reduce the number of iterations
// in the processing loop of that module type.
// N.B.: actual STL maps are not allowed in HLS, so this is an emulation of
// that container as a constexpr function.
constexpr unsigned kMaxProcOffset(const module::type m) {
  return (m == module::VMR ? 1 :
         (m == module::TE ? 0 :
         (m == module::TC ? 0 :
         (m == module::PR ? 0 :
         (m == module::ME ? 0 :
         (m == module::MC ? 0 :
         (m == module::MP ? 0 :
         (0))))))));
}

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kNBits_MemTPage = 2; //Max number of bits for the paged memory
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;
constexpr unsigned int kNMatchEngines=4;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);

constexpr int kNBits_bendinnertableTE[] = {8, 8, 8, 9, 11, 11, 11, 11};
constexpr int kNBits_bendoutertableTE[] = {8, 8, 9, 9, 11, 11, 11, 11};

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// physical constants
constexpr double c = 0.299792458; // m/ns

// detector constants
#ifndef CMSSW_GIT_HASH
namespace trklet{
  constexpr int N_LAYER = 6; // # of barrel layers assumed
  constexpr int N_DISK = 5; // # of endcap disks assumed
}
#endif
constexpr double bfield = 3.8112; // Tesla 
constexpr int rmean[trklet::N_LAYER + trklet::N_DISK] = { 851, 1269, 1784, 2347, 2936, 3697,   -1,   -1,   -1,   -1,   -1 }; // valid for layers
constexpr int zmean[trklet::N_LAYER + trklet::N_DISK] = {  -1,   -1,   -1,   -1,   -1,   -1, 2239, 2645, 3163, 3782, 4523 }; // valid for disks
constexpr double zlength = 120.0; // cm
constexpr double rmindiskvm = 22.5; // cm
constexpr double rmindisk = 20.0; // cm
constexpr double rmaxdisk = 120.0; // cm

// stub digitization constants
constexpr double kr = 0.0292969;
constexpr double kphi = 7.71867e-06;
constexpr double kz = 0.0585938;

// stub digitization constants for combined modules
constexpr double kz_cm[trklet::N_LAYER] = {2*zlength/(1<<12), 2*zlength/(1<<12), 2*zlength/(1<<12), 2*zlength/(1<<8), 2*zlength/(1<<8), 2*zlength/(1<<8)};

// tracklet digitization constants
constexpr double krinv = 1.04549e-06;
constexpr double kphi0 = 1.56824e-05;
constexpr double kt = 0.00195312;
constexpr double kz0 = 0.0585938;

// layer projection digitization constants
constexpr double kphiproj456 = 7.71867e-06;
constexpr double kphiderdisk = kphi / kr / 128;
constexpr double kphider = 8.23325e-06;
constexpr double kzproj = 0.0585938;
constexpr double kzder = 0.015625;

// disk projection digitization constants
constexpr double kphiprojdisk = 6.17494e-05;
constexpr double kphiprojderdisk = 1.64665e-05;
constexpr double krprojdisk = 0.0585938;
constexpr double krprojderdisk = 0.0078125;
constexpr int log2barrel = 3;//log2(kphi / (krprojdisk * kphider));
constexpr int log2disk = 6;//log2(kphi / (kz * kphiderdisk));

// cut constants for TC
constexpr int ifactor = 469;
constexpr int phicritmincut=10190;
constexpr int phicritmaxcut=55345;

constexpr double irmindisk = rmindisk/krprojdisk; // cm
constexpr double irmaxdisk = rmaxdisk/krprojdisk; // cm

// cut constants
constexpr double ptcut = 1.91; // GeV
constexpr double rinvcut = 0.01 * c * bfield / ptcut; // 0.01 to convert to 1/cm
constexpr double z0cut = 15.0; // cm

constexpr int itcut = floatToInt(1.0, kt);
constexpr int irinvcut = floatToInt(rinvcut, krinv);
constexpr int iz0cut = floatToInt(z0cut, kz0);

// cut constants for combined modules
#ifndef CMSSW_GIT_HASH
namespace trklet{
constexpr double VMROUTERCUTZL2 = 50.0;      //Min L2 z for inner allstub in cm
constexpr double VMROUTERCUTZL1L3L5 = 95.0;  //Max z for inner barrel layers in cm
constexpr double VMROUTERCUTZL1 = 70.0;      //Max z for L1 barrel seeding in cm
constexpr double VMROUTERCUTRD1D3 = 55.0;    //Max r for disk seeds in cm
}
#endif
// various bit widths
constexpr unsigned nbitsallstubs[trklet::N_LAYER + trklet::N_DISK] = {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
// number of bits used to distinguish VMs in one allstub block for each layer
constexpr unsigned int nbits_vmmeall[trklet::N_LAYER + trklet::N_DISK] = {2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2}; // ME memories
constexpr unsigned int nbits_vmte[trklet::N_LAYER + trklet::N_DISK] = {2, 3, 2, 3, 2, 3, 2, 2, 2, 2, 2}; // TE Inner and Outer memories
constexpr unsigned int nbits_vmte_overlap[trklet::N_LAYER + trklet::N_DISK] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Overlap memories for L1D1 and L2D1 seeding
constexpr unsigned int nbits_vmte_extra[trklet::N_LAYER + trklet::N_DISK] = {0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0}; // Extra memories for L2L3 seeding

constexpr unsigned int nbits_maxvm = 5; // number of bits needed for max number of VMs per layer/disk (max number is 32)
constexpr unsigned int nbits_maxvm_overlap = 4; // Overlap

namespace TP {
////////////////////////////////////////////////////////////////////////////////
// Typedefs, enums, and constants needed by TrackletCalculator.
////////////////////////////////////////////////////////////////////////////////
  namespace Types {
    typedef ap_uint<2> nASMem;
    typedef ap_uint<5> nSPMem; // needs to support up to 30 stub-pair memories
                               // in the current wiring
    typedef ap_uint<12> nSP;   // this should be large enough to index the entire
                               // list of stub pairs, across all memories

    typedef ap_int<13> rmean;
    typedef ap_int<14> zmean;
    typedef ap_int<15> rinv;
    typedef ap_int<11> z0;
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

 enum itc {UNDEF_ITC, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14};
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

  constexpr int izmaxcut = floatToInt(zlength, kz); 
  constexpr int irprojmincut = floatToInt(rmindisk, krprojdisk); 
  constexpr int irprojmaxcut = floatToInt(rmaxdisk, krprojdisk); 

}


// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK, BARREL_FOR_MC, DISK_FOR_MC};

namespace TF {
  // List of seeds
  enum seed {UNDEF_SEED, L1L2 = 0, L2L3 = 1, L3L4 = 2, L5L6 = 3, D1D2 = 4, D3D4 = 5, L1D1 = 6, L2D1 = 7, AAAA = 12, BBBB = 13};

  // List of layers and disks
  enum layerDisk {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5, D1 = 6, D2 = 7, D3 = 8, D4 = 9, D5 = 10};

  // List of layer and disk types
  constexpr regionType layerDiskType[trklet::N_LAYER + trklet::N_DISK] = {BARRELPS, BARRELPS, BARRELPS, BARREL2S, BARREL2S, BARREL2S, DISK, DISK, DISK, DISK, DISK};

  // List of layer and disk regions
  constexpr regionType layerDiskRegion[trklet::N_LAYER + trklet::N_DISK] = {BARREL, BARREL, BARREL, BARREL, BARREL, BARREL, DISK, DISK, DISK, DISK, DISK};

  // List of phi regions  //WARNING B_E and C_E should be B and C + 16!!!
  enum phiRegion {UNDEF_PHI, A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14, B_E = B + 16, C_E = C + 16};
}

// Layers used for each of the seeds
constexpr int seedLayers[8][2] = { {TF::L1, TF::L2},
				   {TF::L2, TF::L3},
				   {TF::L3, TF::L4},
				   {TF::L5, TF::L6},
				   {TF::D1, TF::D2},
				   {TF::D3, TF::D4},
				   {TF::L1, TF::D1},
				   {TF::L2, TF::D1}};

// Layers each seed projects to; up to four projections. TF::D5 indicates an unused projection. (Unfortunately we
// can not use a TF:Invalid as due to our templated code these will be used as indices into arrays for radial
// positions and this will generate an array out-of-bounds error.)
constexpr int projectionLayers[8][4] = { {TF::L3, TF::L4, TF::L5, TF::L6},
					 {TF::L1, TF::L4, TF::L5, TF::L6},
					 {TF::L1, TF::L2, TF::L5, TF::L6},
					 {TF::L1, TF::L2, TF::L3, TF::L4},
					 {TF::L1, TF::L2, TF::D5, TF::D5},
					 {TF::L1, TF::D5, TF::D5, TF::D5},
					 {TF::D5, TF::D5, TF::D5, TF::D5},
					 {TF::L1, TF::D5, TF::D5, TF::D5}};

// Disks each seed projects to; up to four projections. TF::L1 indicates an unused projection. (Unfortunately we
// can not use a TF:Invalid as due to our templated code these will be used as indices into arrays for radial
// positions and this will generate an array out-of-bounds error.)
constexpr int projectionDisks[8][4] = { {TF::D1, TF::D2, TF::D3, TF::D4},
					{TF::D1, TF::D2, TF::D3, TF::D4},
					{TF::D1, TF::D2, TF::D3, TF::D4},
					{TF::D1, TF::D2, TF::D3, TF::D4},
					{TF::D3, TF::D4, TF::D5, TF::L1},
					{TF::D1, TF::D2, TF::D5, TF::L1},
					{TF::D2, TF::D3, TF::D4, TF::D5},
					{TF::D2, TF::D3, TF::D4, TF::D5}};


// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


// FPGA constants
constexpr unsigned kBRAMwidth = 36;
constexpr int kNBits_DTC = 39;

//Future SW constants
constexpr int nBarrelPS = 3;

#endif
