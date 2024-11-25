#ifndef TopFunctions_VMRouterCM_parameters_h
#define TopFunctions_VMRouterCM_parameters_h

// Hardcoded number of memories and masks from the wiring.
// Generated by generate_VMRCM.py

// The functions that returns parameters and LUTs
template<TF::layerDisk LayerDisk> const int* getPhiCorrTable();
template<TF::layerDisk LayerDisk> const int* getMETable();
template<TF::layerDisk LayerDisk> const int* getTETable();
template<TF::layerDisk LayerDisk> constexpr regionType getInputType();
template<TF::layerDisk LayerDisk> constexpr regionType getOutputType();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputs();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsDisk2S();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumASCopies();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumASInnerCopies();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumTEOCopies();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getAllStubInnerMask();
// For Future Emulation
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsFE();
template<TF::layerDisk LayerDisk, TF::phiRegion Phi> constexpr int getNumInputsDisk2SFE();

// VMPhiCorr LUTs
template<> inline const int* getPhiCorrTable<TF::L1>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL1.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL1.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L2>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL2.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL2.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L3>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL3.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL3.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L4>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL4.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL4.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L5>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL5.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL5.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L6>(){
  static int lut[] = 
#if __has_include("../emData/VMRCM/tables/VMPhiCorrL6.tab")
#  include "../emData/VMRCM/tables/VMPhiCorrL6.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::D1>(){
  return nullptr;
}
template<> inline const int* getPhiCorrTable<TF::D2>(){
  return nullptr;
}
template<> inline const int* getPhiCorrTable<TF::D3>(){
  return nullptr;
}
template<> inline const int* getPhiCorrTable<TF::D4>(){
  return nullptr;
}
template<> inline const int* getPhiCorrTable<TF::D5>(){
  return nullptr;
}

// ME Tables
template<> inline const int* getMETable<TF::L1>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L1.tab")
#  include "../emData/VMRCM/tables/VMRME_L1.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::L2>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L2.tab")
#  include "../emData/VMRCM/tables/VMRME_L2.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::L3>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L3.tab")
#  include "../emData/VMRCM/tables/VMRME_L3.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::L4>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L4.tab")
#  include "../emData/VMRCM/tables/VMRME_L4.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::L5>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L5.tab")
#  include "../emData/VMRCM/tables/VMRME_L5.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::L6>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_L6.tab")
#  include "../emData/VMRCM/tables/VMRME_L6.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::D1>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_D1.tab")
#  include "../emData/VMRCM/tables/VMRME_D1.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::D2>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_D2.tab")
#  include "../emData/VMRCM/tables/VMRME_D2.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::D3>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_D3.tab")
#  include "../emData/VMRCM/tables/VMRME_D3.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::D4>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_D4.tab")
#  include "../emData/VMRCM/tables/VMRME_D4.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getMETable<TF::D5>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRME_D5.tab")
#  include "../emData/VMRCM/tables/VMRME_D5.tab"
#else
  {};
#endif
  return lut;
}

// TE Tables
template<> inline const int* getTETable<TF::L1>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::L2>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::L3>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::L4>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::L5>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::L6>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::D1>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRTE_D1.tab")
#  include "../emData/VMRCM/tables/VMRTE_D1.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getTETable<TF::D2>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRTE_D2.tab")
#  include "../emData/VMRCM/tables/VMRTE_D2.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getTETable<TF::D3>(){
  return nullptr;
}
template<> inline const int* getTETable<TF::D4>(){
  static int lut[] =
#if __has_include("../emData/VMRCM/tables/VMRTE_D4.tab")
#  include "../emData/VMRCM/tables/VMRTE_D4.tab"
#else
  {};
#endif
  return lut;
}
template<> inline const int* getTETable<TF::D5>(){
  return nullptr;
}

// InputType
template<> constexpr regionType getInputType<TF::L1>(){
  return BARRELPS;
}
template<> constexpr regionType getInputType<TF::L2>(){
  return BARRELPS;
}
template<> constexpr regionType getInputType<TF::L3>(){
  return BARRELPS;
}
template<> constexpr regionType getInputType<TF::L4>(){
  return BARREL2S;
}
template<> constexpr regionType getInputType<TF::L5>(){
  return BARREL2S;
}
template<> constexpr regionType getInputType<TF::L6>(){
  return BARREL2S;
}
template<> constexpr regionType getInputType<TF::D1>(){
  return DISKPS;
}
template<> constexpr regionType getInputType<TF::D2>(){
  return DISKPS;
}
template<> constexpr regionType getInputType<TF::D3>(){
  return DISKPS;
}
template<> constexpr regionType getInputType<TF::D4>(){
  return DISKPS;
}
template<> constexpr regionType getInputType<TF::D5>(){
  return DISKPS;
}

// OutputType
template<> constexpr regionType getOutputType<TF::L1>(){
  return BARRELPS;
}
template<> constexpr regionType getOutputType<TF::L2>(){
  return BARRELPS;
}
template<> constexpr regionType getOutputType<TF::L3>(){
  return BARRELPS;
}
template<> constexpr regionType getOutputType<TF::L4>(){
  return BARREL2S;
}
template<> constexpr regionType getOutputType<TF::L5>(){
  return BARREL2S;
}
template<> constexpr regionType getOutputType<TF::L6>(){
  return BARREL2S;
}
template<> constexpr regionType getOutputType<TF::D1>(){
  return DISK;
}
template<> constexpr regionType getOutputType<TF::D2>(){
  return DISK;
}
template<> constexpr regionType getOutputType<TF::D3>(){
  return DISK;
}
template<> constexpr regionType getOutputType<TF::D4>(){
  return DISK;
}
template<> constexpr regionType getOutputType<TF::D5>(){
  return DISK;
}

////////////////
// VMR_L1PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L1, TF::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L1, TF::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L1, TF::A>(){ // Allstub memory
  return 1;
}
template<> constexpr int getNumASInnerCopies<TF::L1, TF::A>(){ // Allstub Inner memory
  return 4;
}
template<> constexpr int getNumTEOCopies<TF::L1, TF::A>(){ // TE Outer memories
  return 0;
}
template<> constexpr int getAllStubInnerMask<TF::L1, TF::A>(){
  return 0b110000110000;
}
// For Future Emulation
template<> constexpr int getNumInputsFE<TF::L1, TF::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2SFE<TF::L1, TF::A>(){ // Number of DISK2S input memories
  return 0;
}

////////////////
// VMR_L1PHIB //
////////////////
template<> constexpr int getNumInputs<TF::L1, TF::B>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L1, TF::B>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L1, TF::B>(){ // Allstub memory
  return 1;
}
template<> constexpr int getNumASInnerCopies<TF::L1, TF::B>(){ // Allstub Inner memory
  return 6;
}
template<> constexpr int getNumTEOCopies<TF::L1, TF::B>(){ // TE Outer memories
  return 0;
}
template<> constexpr int getAllStubInnerMask<TF::L1, TF::B>(){
  return 0b111000001101;
}
// For Future Emulation
template<> constexpr int getNumInputsFE<TF::L1, TF::B>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2SFE<TF::L1, TF::B>(){ // Number of DISK2S input memories
  return 0;
}

#endif // TopFunctions_VMRouterCM_parameters_h
