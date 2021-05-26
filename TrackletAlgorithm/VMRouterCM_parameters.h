#ifndef TrackletAlgorithm_VMRouterCM_parameters_h
#define TrackletAlgorithm_VMRouterCM_parameters_h

// Hardcoded number of memories and masks from the wiring.
// NOTE: this file is incomplete. Please add the missing numbers

// Masks of which AllStubInner memories that are being used in this phi region; represente by a "1"
// First three bits (LSB) are the six A-F for Barrel, then the three after that are L,M,R for Barrel and disk, last three are L,M,R for Overlap
// NOTE: read from right to left (OR, OM, OL, BR/DR, BM/DM, BL/DL, BF, BE, BD, BC, BB, BA)

// Enums used to get the correct parameters
enum class phiRegions : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G', H = 'H'};

// The functions that returns the parameters
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputs();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputsDisk2S();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumASCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumASInnerCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumTEOCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getAllStubInnerMask();

// Numbers for VMRCM L1PHIA
template<> constexpr int getNumInputs<TF::L1, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L1, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L1, phiRegions::A>(){ // Allstub memory
  return 1;
}
template<> constexpr int getNumASInnerCopies<TF::L1, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 4;
}
template<> constexpr int getNumTEOCopies<TF::L1, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 0;
}
template<> constexpr int getAllStubInnerMask<TF::L1, phiRegions::A>(){
  return 0b110000110000;
}

// Numbers for VMRCM L2PHIA
template<> constexpr int getNumInputs<TF::L2, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L2, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L2, phiRegions::A>(){ // Allstub memory
  return 4;
}
template<> constexpr int getNumASInnerCopies<TF::L2, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 4;
}
template<> constexpr int getNumTEOCopies<TF::L2, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 3;
}
template<> constexpr int getAllStubInnerMask<TF::L2, phiRegions::A>(){
  return 0b110110000000;
}

// Numbers for VMRCM L3PHIA
template<> constexpr int getNumInputs<TF::L3, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L3, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L3, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumASInnerCopies<TF::L3, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 2;
}
template<> constexpr int getNumTEOCopies<TF::L3, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 1;
}
template<> constexpr int getAllStubInnerMask<TF::L3, phiRegions::A>(){
  return 0b110000000000;
}

// Numbers for VMRCM L4PHIA
template<> constexpr int getNumInputs<TF::L4, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L4, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L4, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumASInnerCopies<TF::L4, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L4, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 1;
}
template<> constexpr int getAllStubInnerMask<TF::L4, phiRegions::A>(){
  return 0b0;
}

// Numbers for VMRCM L5PHIA
template<> constexpr int getNumInputs<TF::L5, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L5, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L5, phiRegions::A>(){ // Allstub memory
  return 1;
}
template<> constexpr int getNumASInnerCopies<TF::L5, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 2;
}
template<> constexpr int getNumTEOCopies<TF::L5, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 0;
}
template<> constexpr int getAllStubInnerMask<TF::L5, phiRegions::A>(){
  return 0b110000000000;
}

// Numbers for VMRCM L6PHIA
template<> constexpr int getNumInputs<TF::L6, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L6, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L6, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumASInnerCopies<TF::L6, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L6, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 1;
}
template<> constexpr int getAllStubInnerMask<TF::L6, phiRegions::A>(){
  return 0b0;
}

// Numbers for VMRCM D1PHIA
template<> constexpr int getNumInputs<TF::D1, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 6;
}
template<> constexpr int getNumInputsDisk2S<TF::D1, phiRegions::A>(){ // Number of DISK2S input memories
  return 2;
}
template<> constexpr int getNumASCopies<TF::D1, phiRegions::A>(){ // Allstub memory
  return 3;
}
template<> constexpr int getNumASInnerCopies<TF::D1, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::D1, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 3;
}
template<> constexpr int getAllStubInnerMask<TF::D1, phiRegions::A>(){
  return 0b000110000000;
}

// Numbers for VMRCM D2PHIA
template<> constexpr int getNumInputs<TF::D2, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 8;
}
template<> constexpr int getNumInputsDisk2S<TF::D2, phiRegions::A>(){ // Number of DISK2S input memories
  return 2;
}
template<> constexpr int getNumASCopies<TF::D2, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumASInnerCopies<TF::D2, phiRegions::A>(){ // AllstubInner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::D2, phiRegions::A>(){ // TE Outer memories, can be 0 when no TEOuter memories
  return 1;
}
template<> constexpr int getAllStubInnerMask<TF::D2, phiRegions::A>(){
  return 0b0;
}

// Add more layers and phi regions

#endif // TrackletAlgorithm_VMRouterCMTop_parameters_h
