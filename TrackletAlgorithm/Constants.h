#ifndef TrackletAlgorithm_Constants_h
#define TrackletAlgorithm_Constants_h

#include "ap_int.h"

// Inline function to convert floating point values to integers, given a
// digitization constant. The 1.0e-1 is a fudge factor needed to get the
// floating point truncation to agree exactly with the emulation.
inline const int floatToInt(const double x, const double k) {
  return static_cast<int>(x / k + 1.0e-1);
}

constexpr int kMaxStubsFromLink = 256;

constexpr int kTMUX = 18;   //For hourglass project
constexpr int kMaxProc = kTMUX * 6;

// List of module types
namespace module {
  enum type {UNKNOWN, IR, VMR, VMR_LAYER, VMR_DISK, TE, TC, PR, ME, MC, NMODULES};
};

// Map from a module type to an offset used to reduce the number of iterations
// in the processing loop of that module type.
// N.B.: actual STL maps are not allowed in HLS, so this is an emulation of
// that container as a constexpr function.
constexpr unsigned kMaxProcOffset(const module::type m) {
  return (m == module::VMR_LAYER ? 7 :
         (m == module::VMR_DISK ? 8 :
         (m == module::TE ? 7 :
         (m == module::TC ? 0 :
         (m == module::PR ? 0 :
         (m == module::ME ? 7 :
         (m == module::MC ? 0 :
         (0))))))));
}

// Memory
constexpr int kNBits_MemAddr = 7;
constexpr int kMemDepth = (1<<kNBits_MemAddr);
constexpr int kNBits_BX = 3;

constexpr int kNBits_MemAddrBinned = 4;
constexpr int kMemDepthBinned = (1<<kNBits_MemAddrBinned);

constexpr int kNBits_pttableTE = 5;
constexpr int kNBits_bendinnertableTE = 8;
constexpr int kNBits_bendoutertableTE = 8;

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// physical constants
constexpr double c = 0.3; // m/ns

// stub digitization constants
constexpr double kr = 0.0292969;
constexpr double kphi = 7.71297e-06;
constexpr double kz = 0.0585938;

// tracklet digitization constants
constexpr double krinv = 1.0284e-06;
constexpr double kphi0 = 1.54259e-05;
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

// detector constants
constexpr int N_LAYER = 6; // # of barrel layers assumed
constexpr int N_DISK = 5; // # of endcap disks assumed
constexpr double bfield = 3.8; // T
constexpr int rmean[N_LAYER] = { 851, 1269, 1784, 2347, 2936, 3697 };
constexpr int zmean[N_DISK] = { 2239, 2645, 3163, 3782, 4523 };
constexpr double zlength = 120.0; // cm
constexpr double rmindiskvm = 22.5; // cm
constexpr double rmindisk = 20.0; // cm
constexpr double rmaxdisk = 120.0; // cm
constexpr double rmindisktc = 12.0; // cm
constexpr double rmaxdisktc = 112.0; // cm

// cut constants
constexpr double ptcut = 1.91; // GeV
constexpr double rinvcut = 0.01 * c * bfield / ptcut; // 0.01 to convert to 1/cm
constexpr double z0cut = 15.0; // cm

// various bit widths
constexpr unsigned nbitsallstubs[N_LAYER + N_DISK] = {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
constexpr unsigned int nbits_maxvm = 5; // number of bits needed for max number of VMs per layer/disk (max number is 32)

// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK};

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited

#endif
