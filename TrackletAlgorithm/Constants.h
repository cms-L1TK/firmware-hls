#ifndef TrackletAlgorithm_Constants_h
#define TrackletAlgorithm_Constants_h

#include "ap_int.h"

//#include <cmath>
//#include "hls_math.h"

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

constexpr int kNBits_z = 3;

constexpr int MEBinsBits = 3;
constexpr int TEBinsBits = 3;

// stub digitization constants
constexpr double kr = 0.0292969;
constexpr double kphi = 7.71297e-06;
constexpr double kz = 0.0585938;

// tracklet digitization constants
constexpr double krinv = 1.0284e-06;
constexpr double kphi0 = 1.54259e-05;
constexpr double kt = 0.00195312;
constexpr double kz0 = 0.0585938;

// mean positions of layers and disks (the 1.0e-1 is a fudge factor needed to
// get the floating point truncation right)
constexpr int rmean[6] = {
  static_cast<int>(24.9316 / kr + 1.0e-1),
  static_cast<int>(37.1777 / kr + 1.0e-1),
  static_cast<int>(52.2656 / kr + 1.0e-1),
  static_cast<int>(68.7598 / kr + 1.0e-1),
  static_cast<int>(86.0156 / kr + 1.0e-1),
  static_cast<int>(108.311 / kr + 1.0e-1)
};
constexpr int zmean[5] = {
  static_cast<int>(131.191 / kz + 1.0e-1),
  static_cast<int>(154.98 / kz + 1.0e-1),
  static_cast<int>(185.332 / kz + 1.0e-1),
  static_cast<int>(221.602 / kz + 1.0e-1),
  static_cast<int>(265.02 / kz + 1.0e-1)
};

// List of regions for memory template parameters
enum regionType {BARRELPS, BARREL2S, BARRELOL, BARREL, DISKPS, DISK2S, DISK};

// Global BX type
typedef ap_uint<kNBits_BX> BXType;  // temporary definition. need to be revisited

#endif
