#ifndef TrackletAlgorithm_Constants_h
#define TrackletAlgorithm_Constants_h

#include "ap_int.h"

// Inline function to convert floating point values to integers, given a
// digitization constant. The 1.0e-1 is a fudge factor needed to get the
// floating point truncation to agree exactly with the emulation.
inline const int floatToInt(const double x, const double k) {
  return static_cast<int>(x / k + 1.0e-1);
}

constexpr int kNTEUnits = 5;
constexpr int kNbitsrzbin = 3;
constexpr int kNbitsphibin = 3;

constexpr int kMaxStubsFromLink = 256;

constexpr int kTMUX = 18;   //For hourglass project
constexpr int kMaxProc = kTMUX * 6;

constexpr unsigned int kNbitszfinebintable = 7;
constexpr unsigned int kNbitsrfinebintable = 4;

// List of module types
namespace module {
  enum type {UNKNOWN, IR, VMR, TE, TC, PR, ME, MC, NMODULES};
};

// Map from a module type to an offset used to reduce the number of iterations
// in the processing loop of that module type.
// N.B.: actual STL maps are not allowed in HLS, so this is an emulation of
// that container as a constexpr function.
constexpr unsigned kMaxProcOffset(const module::type m) {
  return (m == module::VMR ? 0 :
         (m == module::TE ? 0 :
         (m == module::TC ? 0 :
         (m == module::PR ? 0 :
         (m == module::ME ? 0 :
         (m == module::MC ? 0 :
         (0)))))));
}

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;
constexpr unsigned int kNMatchEngines=4;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);

constexpr int kNBits_bendinnertableTE = 8;
constexpr int kNBits_bendoutertableTE = 8;

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// physical constants
constexpr double c = 0.299792458; // m/ns

// detector constants
constexpr int N_LAYER = 6; // # of barrel layers assumed
constexpr int N_DISK = 5; // # of endcap disks assumed
constexpr double bfield = 3.8112; // T
constexpr int rmean[N_LAYER + N_DISK] = { 851, 1269, 1784, 2347, 2936, 3697,   -1,   -1,   -1,   -1,   -1 }; // valid for layers
constexpr int zmean[N_LAYER + N_DISK] = {  -1,   -1,   -1,   -1,   -1,   -1, 2239, 2645, 3163, 3782, 4523 }; // valid for disks
constexpr double zlength = 120.0; // cm
constexpr double rmindiskvm = 22.5; // cm
constexpr double rmindisk = 20.0; // cm
constexpr double rmaxdisk = 120.0; // cm

// stub digitization constants
constexpr double kr = 0.0292969;
constexpr double kphi = 7.71867e-06;
constexpr double kz = 0.0585938;

// stub digitization constants for combined modules
constexpr double kz_cm[N_LAYER] = {2*zlength/(1<<12), 2*zlength/(1<<12), 2*zlength/(1<<12), 2*zlength/(1<<8), 2*zlength/(1<<8), 2*zlength/(1<<8)};

// tracklet digitization constants
constexpr double krinv = 1.04549e-06;
constexpr double kphi0 = 1.56824e-05;
constexpr double kt = 0.00195312;
constexpr double kz0 = 0.0585938;

// layer projection digitization constants
constexpr double kphiproj456 = 7.71867e-06;
constexpr double kphider = 8.23325e-06;
constexpr double kzproj = 0.0585938;
constexpr double kzder = 0.015625;

// disk projection digitization constants
constexpr double kphiprojdisk = 6.17494e-05;
constexpr double kphiprojderdisk = 1.64665e-05;
constexpr double krprojdisk = 0.0585938;
constexpr double krprojderdisk = 0.0078125;

// cut constants
constexpr double ptcut = 1.91; // GeV
constexpr double rinvcut = 0.01 * c * bfield / ptcut; // 0.01 to convert to 1/cm
constexpr double z0cut = 15.0; // cm

// cut constants for combined modules
constexpr double VMROUTERCUTZL2 = 50.0;      //Min L2 z for inner allstub in cm
constexpr double VMROUTERCUTZL1L3L5 = 95.0;  //Max z for inner barrel layers in cm
constexpr double VMROUTERCUTZL1 = 70.0;      //Max z for L1 barrel seeding in cm
constexpr double VMROUTERCUTRD1D3 = 55.0;    //Max r for disk seeds in cm

// various bit widths
constexpr unsigned nbitsallstubs[N_LAYER + N_DISK] = {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
constexpr unsigned int nbits_maxvm = 5; // number of bits needed for max number of VMs per layer/disk (max number is 32)
// number of bits used to distinguish VMs in one allstub block for each layer
constexpr unsigned int nbits_vmmeall[N_LAYER + N_DISK]={2,3,3,3,3,3,3,2,2,2,2};

// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK, BARREL_FOR_MC, DISK_FOR_MC};

namespace TF {
  // List of seeds
  enum seed {UNDEF_SEED, L1L2 = 0, L2L3 = 1, L3L4 = 2, L5L6 = 3, D1D2 = 4, D3D4 = 5, L1D1 = 6, L2D1 = 7};

  // List of layers and disks
  enum layerDisk {L1 = 0, L2 = 1, L3 = 2, L4 = 3, L5 = 4, L6 = 5, D1 = 6, D2 = 7, D3 = 8, D4 = 9, D5 = 10};
}

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited


// FPGA constants 
constexpr unsigned kBRAMwidth = 36; 
constexpr int kNBits_DTC = 39; 

#endif
