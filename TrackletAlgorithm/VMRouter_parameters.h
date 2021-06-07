#ifndef TrackletAlgorithm_VMRouter_parameters_h
#define TrackletAlgorithm_VMRouter_parameters_h

// Hardcoded number of memories and masks from the wiring.
// NOTE: this file is incomplete. Please add the missing numbers

// Enums used to get the correct parameters
enum class phiRegions : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G', H = 'H'};

// The functions that returns the LUTs and parameters
template<TF::layerDisk LayerDisk> const int* getPhiCorrTable();
template<TF::layerDisk LayerDisk> const int* getRzBitsInnerTable();
template<TF::layerDisk LayerDisk> const int* getRzBitsOverlapTable();
template<TF::layerDisk LayerDisk> const int* getRzBitsOuterTable();
template<TF::layerDisk LayerDisk, phiRegions Phi> const int* getFineBinTable();
template<TF::layerDisk LayerDisk, phiRegions Phi, int size> const ap_uint<size>* getBendCutInnerTable();
template<TF::layerDisk LayerDisk, phiRegions Phi, int size> const ap_uint<size>* getBendCutOverlapTable();
template<TF::layerDisk LayerDisk, phiRegions Phi, int size> const ap_uint<size>* getBendCutOuterTable();

template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputs();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumInputsDisk2S();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumASCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumTEICopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumOLCopies();
template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getNumTEOCopies();

template<TF::layerDisk LayerDisk, phiRegions Phi> constexpr int getBendCutTableSize();

// Help function that converts an array of 0s and 1s to an ap_uint
template<int arraySize>
inline ap_uint<arraySize> arrayToInt(ap_uint<1> array[arraySize]) {
  ap_uint<arraySize> number;
  for(int i = 0; i < arraySize; i++) {
    #pragma HLS unroll
    number[i] = array[i];
  }
  return number;
}

// VMPhiCorr LUTs
template<> inline const int* getPhiCorrTable<TF::L1>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL1.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L2>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL2.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L3>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL3.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L4>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL4.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L5>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL5.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<TF::L6>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL6.tab"
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

// VMTableInner
template<> inline const int* getRzBitsInnerTable<TF::L1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL1L2.tab"
  return lut;
}
template<> inline const int* getRzBitsInnerTable<TF::L2>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL2L3.tab"
  return lut;
}
template<> inline const int* getRzBitsInnerTable<TF::L3>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL3L4.tab"
  return lut;
}
template<> inline const int* getRzBitsInnerTable<TF::L4>(){
  return nullptr;
}
template<> inline const int* getRzBitsInnerTable<TF::L5>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL5L6.tab"
  return lut;
}
template<> inline const int* getRzBitsInnerTable<TF::L6>(){
  return nullptr;
}
template<> inline const int* getRzBitsInnerTable<TF::D1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerD1D2.tab"
  return lut;
}
template<> inline const int* getRzBitsInnerTable<TF::D2>(){
  return nullptr;
}

// VMTableInner - Overlap
template<> inline const int* getRzBitsOverlapTable<TF::L1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL1D1.tab"
  return lut;
}
template<> inline const int* getRzBitsOverlapTable<TF::L2>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL2D1.tab"
  return lut;
}
template<> inline const int* getRzBitsOverlapTable<TF::L3>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::L4>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::L5>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::L6>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::D1>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::D2>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::D3>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::D4>(){
  return nullptr;
}
template<> inline const int* getRzBitsOverlapTable<TF::D5>(){
  return nullptr;
}

//VMTableOuter
template<> inline const int* getRzBitsOuterTable<TF::L1>(){
  return nullptr;
}
template<> inline const int* getRzBitsOuterTable<TF::L2>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterL2.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::L3>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterL3.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::L4>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterL4.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::L5>(){
  return nullptr;
}
template<> inline const int* getRzBitsOuterTable<TF::L6>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterL6.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::D1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterD1.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::D2>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableOuterD2.tab"
  return lut;
}
template<> inline const int* getRzBitsOuterTable<TF::D3>(){
  return nullptr;
}
// Uncomment when needed
// template<> inline const int* getRzBitsOuterTable<TF::D4>(){
//   static int lut[] =
// #include "../emData/VMR/tables/VMTableOuterD4.tab"
//   return lut;
// }
template<> inline const int* getRzBitsOuterTable<TF::D5>(){
  return nullptr;
}


////////////////
// VMR_L1PHID //
////////////////
template<> constexpr int getNumInputs<TF::L1, phiRegions::D>(){ // Number of input memories, EXCLUDING DISK2S
  return 7;
}
template<> constexpr int getNumInputsDisk2S<TF::L1, phiRegions::D>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L1, phiRegions::D>(){ // Allstub memory
  return 5;
}
template<> constexpr int getNumTEICopies<TF::L1, phiRegions::D>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getNumOLCopies<TF::L1, phiRegions::D>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumTEOCopies<TF::L1, phiRegions::D>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getBendCutTableSize<TF::L1, phiRegions::D>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::L1, phiRegions::D>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L1PHID_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::D>()>* getBendCutInnerTable<TF::L1, phiRegions::D>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L1, phiRegions::D>();
  // TE Memory 1
  ap_uint<1> tmpBendInnerTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHID13n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHID13n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHID13n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHID13n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHID13n5_vmbendcut.tab"
  // TE Memory 2
  ap_uint<1> tmpBendInnerTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHID14n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHID14n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHID14n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHID14n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHID14n5_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendInnerTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHID15n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHID15n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHID15n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHID15n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHID15n5_vmbendcut.tab"
// TE Memory 4
  ap_uint<1> tmpBendInnerTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHID16n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHID16n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHID16n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHID16n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHID16n5_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n5)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::D>()>* getBendCutOverlapTable<TF::L1, phiRegions::D>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L1, phiRegions::D>();
  // TE Overlap Memory 1
  ap_uint<1> tmpBendOverlapTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW7n1_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW7n2_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW7n3_vmbendcut.tab"
  // TE Overlap Memory 2
  ap_uint<1> tmpBendOverlapTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW8n1_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW8n2_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIW8n3_vmbendcut.tab"

  // Combine all the temporary Overlap tables into one big table
  static ap_uint<bendCutTableSize> bendCutOverlapTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n3)};

  return bendCutOverlapTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::D>()>* getBendCutOuterTable<TF::L1, phiRegions::D>(){
  return nullptr;
}


////////////////
// VMR_L1PHIE //
////////////////
template<> constexpr int getNumInputs<TF::L1, phiRegions::E>(){ // Number of input memories, EXCLUDING DISK2S
  return 7;
}
template<> constexpr int getNumInputsDisk2S<TF::L1, phiRegions::E>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L1, phiRegions::E>(){ // Allstub memory
  return 4;
}
template<> constexpr int getNumTEICopies<TF::L1, phiRegions::E>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getNumOLCopies<TF::L1, phiRegions::E>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumTEOCopies<TF::L1, phiRegions::E>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getBendCutTableSize<TF::L1, phiRegions::E>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::L1, phiRegions::E>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L1PHIE_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::E>()>* getBendCutInnerTable<TF::L1, phiRegions::E>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L1, phiRegions::E>();
  // TE Memory 1
  ap_uint<1> tmpBendInnerTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE17n5_vmbendcut.tab"
  // TE Memory 2
  ap_uint<1> tmpBendInnerTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE18n5_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendInnerTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE19n5_vmbendcut.tab"
// TE Memory 4
  ap_uint<1> tmpBendInnerTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n3_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n4_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n5[] =
#include "../emData/VMR/tables/VMSTE_L1PHIE20n5_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n5),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n4), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n5)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::E>()>* getBendCutOverlapTable<TF::L1, phiRegions::E>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L1, phiRegions::E>();
  // TE Overlap Memory 1
  ap_uint<1> tmpBendOverlapTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n1_vmbendcut.tab"

  ap_uint<1> tmpBendOverlapTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n2_vmbendcut.tab"

  ap_uint<1> tmpBendOverlapTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ9n3_vmbendcut.tab"

  // TE Overlap Memory 2
  ap_uint<1> tmpBendOverlapTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n1_vmbendcut.tab"

  ap_uint<1> tmpBendOverlapTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n2_vmbendcut.tab"

  ap_uint<1> tmpBendOverlapTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L1PHIQ10n3_vmbendcut.tab"

  // Combine all the temporary Overlap tables into one big table
  static ap_uint<bendCutTableSize> bendCutOverlapTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n3)};

  return bendCutOverlapTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L1, phiRegions::E>()>* getBendCutOuterTable<TF::L1, phiRegions::E>(){
  return nullptr;
}


////////////////
// VMR_L2PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L2, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L2, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L2, phiRegions::A>(){ // Allstub memory
  return 7;
}
template<> constexpr int getNumTEICopies<TF::L2, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumOLCopies<TF::L2, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 4;
}
template<> constexpr int getNumTEOCopies<TF::L2, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getBendCutTableSize<TF::L2, phiRegions::A>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::L2, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L2PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::A>()>* getBendCutInnerTable<TF::L2, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendInnerTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII1n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII1n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n3[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendInnerTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII2n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII2n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII2n3_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendInnerTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII3n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII3n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII3n3_vmbendcut.tab"
// TE Memory 4
  ap_uint<1> tmpBendInnerTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII4n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII4n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHII4n3_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::A>()>* getBendCutOverlapTable<TF::L2, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::A>();
  // TE Overlap Memory 1
  ap_uint<1> tmpBendOverlapTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX1n5_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX1n6_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX1n7_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n4[bendCutTableSize] = {0};
  // TE Overlap Memory 2
  ap_uint<1> tmpBendOverlapTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX2n5_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX2n6_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX2n7_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIX2n8_vmbendcut.tab"

  // Combine all the temporary Overlap tables into one big table
  static ap_uint<bendCutTableSize> bendCutOverlapTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n4),
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n4)};

  return bendCutOverlapTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::A>()>* getBendCutOuterTable<TF::L2, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA1n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n4[bendCutTableSize] = {0};
  ap_uint<1> tmpBendOuterTable1_n5[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA2n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA2n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n5[bendCutTableSize] = {0};
  // TE Memory 3
  ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA3n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA3n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA3n5_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA4n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA4n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA4n5_vmbendcut.tab"
  // TE Memory 5
  ap_uint<1> tmpBendOuterTable5_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA5n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA5n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA5n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA5n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA5n5_vmbendcut.tab"
  // TE Memory 6
  ap_uint<1> tmpBendOuterTable6_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA6n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA6n2_vmbendcut.tab"
ap_uint<1> tmpBendOuterTable6_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA6n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA6n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA6n5_vmbendcut.tab"
  // TE Memory 7
  ap_uint<1> tmpBendOuterTable7_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA7n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA7n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA7n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA7n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA7n5_vmbendcut.tab"
  // TE Memory 8
  ap_uint<1> tmpBendOuterTable8_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA8n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA8n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA8n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA8n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIA8n5_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n5)};

  return bendCutOuterTable;
}


////////////////
// VMR_L2PHIB //
////////////////
template<> constexpr int getNumInputs<TF::L2, phiRegions::B>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L2, phiRegions::B>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L2, phiRegions::B>(){ // Allstub memory
  return 10;
}
template<> constexpr int getNumTEICopies<TF::L2, phiRegions::B>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumOLCopies<TF::L2, phiRegions::B>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 4;
}
template<> constexpr int getNumTEOCopies<TF::L2, phiRegions::B>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getBendCutTableSize<TF::L2, phiRegions::B>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::L2, phiRegions::B>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L2PHIB_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::B>()>* getBendCutInnerTable<TF::L2, phiRegions::B>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::B>();
  // TE Memory 1
  ap_uint<1> tmpBendInnerTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ5n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ5n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ5n3_vmbendcut.tab"
  // TE Memory 2
  ap_uint<1> tmpBendInnerTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ6n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ6n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ6n3_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendInnerTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ7n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ7n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ7n3_vmbendcut.tab"
// TE Memory 4
  ap_uint<1> tmpBendInnerTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ8n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ8n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIJ8n3_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::B>()>* getBendCutOverlapTable<TF::L2, phiRegions::B>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::B>();
  // TE Overlap Memory 1
  ap_uint<1> tmpBendOverlapTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY3n5_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY3n6_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY3n7_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable1_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY3n8_vmbendcut.tab"
  // TE Overlap Memory 2
  ap_uint<1> tmpBendOverlapTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY4n5_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY4n6_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY4n7_vmbendcut.tab"
  ap_uint<1> tmpBendOverlapTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIY4n8_vmbendcut.tab"

  // Combine all the temporary Overlap tables into one big table
  static ap_uint<bendCutTableSize> bendCutOverlapTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOverlapTable1_n4),
    arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOverlapTable2_n4)};

  return bendCutOverlapTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L2, phiRegions::B>()>* getBendCutOuterTable<TF::L2, phiRegions::B>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L2, phiRegions::B>();
  // TE Memory 1
  ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB9n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB9n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB9n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB9n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB9n5_vmbendcut.tab"
  // TE Memory 2
  ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB10n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB10n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB10n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB10n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB10n5_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB11n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB11n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB11n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB11n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB11n5_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB12n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB12n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB12n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB12n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB12n5_vmbendcut.tab"
  // TE Memory 5
  ap_uint<1> tmpBendOuterTable5_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB13n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB13n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB13n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB13n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable5_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB13n5_vmbendcut.tab"
  // TE Memory 6
  ap_uint<1> tmpBendOuterTable6_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB14n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB14n2_vmbendcut.tab"
ap_uint<1> tmpBendOuterTable6_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB14n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB14n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable6_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB14n5_vmbendcut.tab"
  // TE Memory 7
  ap_uint<1> tmpBendOuterTable7_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB15n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB15n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB15n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB15n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable7_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB15n5_vmbendcut.tab"
  // TE Memory 8
  ap_uint<1> tmpBendOuterTable8_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB16n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB16n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB16n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB16n4_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable8_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L2PHIB16n5_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable5_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable6_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable7_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable8_n5)};

  return bendCutOuterTable;
}


////////////////
// VMR_L3PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L3, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L3, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L3, phiRegions::A>(){ // Allstub memory
  return 3;
}
template<> constexpr int getNumTEICopies<TF::L3, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 6;
}
template<> constexpr int getNumOLCopies<TF::L3, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L3, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getBendCutTableSize<TF::L3, phiRegions::A>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::L3, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L3PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L3, phiRegions::A>()>* getBendCutInnerTable<TF::L3, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L3, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA1n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n4[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA1n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n5[bendCutTableSize] = {0};
  ap_uint<1> tmpBendTable1_n6[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n4[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n5[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n6[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA2n6_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n4[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n5[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n6[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA3n6_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n5[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n6[] =
#include "../emData/VMR/tables/VMSTE_L3PHIA4n6_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendTable1_n1), arrayToInt<bendCutTableSize>(tmpBendTable1_n2), arrayToInt<bendCutTableSize>(tmpBendTable1_n3), arrayToInt<bendCutTableSize>(tmpBendTable1_n4), arrayToInt<bendCutTableSize>(tmpBendTable1_n5), arrayToInt<bendCutTableSize>(tmpBendTable1_n6),
    arrayToInt<bendCutTableSize>(tmpBendTable2_n1), arrayToInt<bendCutTableSize>(tmpBendTable2_n2), arrayToInt<bendCutTableSize>(tmpBendTable2_n3), arrayToInt<bendCutTableSize>(tmpBendTable2_n4), arrayToInt<bendCutTableSize>(tmpBendTable2_n5), arrayToInt<bendCutTableSize>(tmpBendTable2_n6),
    arrayToInt<bendCutTableSize>(tmpBendTable3_n1), arrayToInt<bendCutTableSize>(tmpBendTable3_n2), arrayToInt<bendCutTableSize>(tmpBendTable3_n3), arrayToInt<bendCutTableSize>(tmpBendTable3_n4), arrayToInt<bendCutTableSize>(tmpBendTable3_n5), arrayToInt<bendCutTableSize>(tmpBendTable3_n6),
    arrayToInt<bendCutTableSize>(tmpBendTable4_n1), arrayToInt<bendCutTableSize>(tmpBendTable4_n2), arrayToInt<bendCutTableSize>(tmpBendTable4_n3), arrayToInt<bendCutTableSize>(tmpBendTable4_n4), arrayToInt<bendCutTableSize>(tmpBendTable4_n5), arrayToInt<bendCutTableSize>(tmpBendTable4_n6)};


  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L3, phiRegions::A>()>* getBendCutOverlapTable<TF::L3, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L3, phiRegions::A>()>* getBendCutOuterTable<TF::L3, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L3, phiRegions::A>();
  // TE Outer Memory 1
  ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII1n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII1n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] = {0};
  // TE Overlap Memory 2
  ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII2n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII2n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII2n3_vmbendcut.tab"
  // TE Overlap Memory 3
  ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII3n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII3n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII3n3_vmbendcut.tab"
  // TE Overlap Memory 4
  ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII4n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII4n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L3PHII4n3_vmbendcut.tab"

  // Combine all the temporary Outer tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3)};

  return bendCutOuterTable;
}


////////////////
// VMR_L4PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L4, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 2;
}
template<> constexpr int getNumInputsDisk2S<TF::L4, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L4, phiRegions::A>(){ // Allstub memory
  return 3;
}
template<> constexpr int getNumTEICopies<TF::L4, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumOLCopies<TF::L4, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L4, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getBendCutTableSize<TF::L4, phiRegions::A>(){
  return 16;
}

template<> inline const int* getFineBinTable<TF::L4, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L4PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L4, phiRegions::A>()>* getBendCutInnerTable<TF::L4, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L4, phiRegions::A>()>* getBendCutOverlapTable<TF::L4, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L4, phiRegions::A>()>* getBendCutOuterTable<TF::L4, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L4, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n3[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n3[bendCutTableSize] = {0};
  // TE Memory 3
  ap_uint<1> tmpBendTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA3n3_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA4n3_vmbendcut.tab"
  // TE Memory 5
  ap_uint<1> tmpBendTable5_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA5n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable5_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA5n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable5_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA5n3_vmbendcut.tab"
  // TE Memory 6
  ap_uint<1> tmpBendTable6_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA6n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable6_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA6n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable6_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA6n3_vmbendcut.tab"
  // TE Memory 7
  ap_uint<1> tmpBendTable7_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA7n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable7_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA7n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable7_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA7n3_vmbendcut.tab"
  // TE Memory 8
  ap_uint<1> tmpBendTable8_n1[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA8n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable8_n2[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA8n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable8_n3[] =
#include "../emData/VMR/tables/VMSTE_L4PHIA8n3_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendTable1_n1), arrayToInt<bendCutTableSize>(tmpBendTable1_n2), arrayToInt<bendCutTableSize>(tmpBendTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable2_n1), arrayToInt<bendCutTableSize>(tmpBendTable2_n2), arrayToInt<bendCutTableSize>(tmpBendTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable3_n1), arrayToInt<bendCutTableSize>(tmpBendTable3_n2), arrayToInt<bendCutTableSize>(tmpBendTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable4_n1), arrayToInt<bendCutTableSize>(tmpBendTable4_n2), arrayToInt<bendCutTableSize>(tmpBendTable4_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable5_n1), arrayToInt<bendCutTableSize>(tmpBendTable5_n2), arrayToInt<bendCutTableSize>(tmpBendTable5_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable6_n1), arrayToInt<bendCutTableSize>(tmpBendTable6_n2), arrayToInt<bendCutTableSize>(tmpBendTable6_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable7_n1), arrayToInt<bendCutTableSize>(tmpBendTable7_n2), arrayToInt<bendCutTableSize>(tmpBendTable7_n3),
    arrayToInt<bendCutTableSize>(tmpBendTable8_n1), arrayToInt<bendCutTableSize>(tmpBendTable8_n2), arrayToInt<bendCutTableSize>(tmpBendTable8_n3)};

  return bendCutOuterTable;
}


////////////////
// VMR_L5PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L5, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L5, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L5, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumTEICopies<TF::L5, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 8;
}
template<> constexpr int getNumOLCopies<TF::L5, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L5, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getBendCutTableSize<TF::L5, phiRegions::A>(){
  return 16;
}

template<> inline const int* getFineBinTable<TF::L5, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L5PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L5, phiRegions::A>()>* getBendCutInnerTable<TF::L5, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L5, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n3[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA1n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n4[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA1n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L5PHIA1n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n6[bendCutTableSize] = {0};
  ap_uint<1> tmpBendTable1_n7[bendCutTableSize] = {0};
  ap_uint<1> tmpBendTable1_n8[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n3[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n4[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n5[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n6[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n6_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n7[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA2n7_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n8[bendCutTableSize] = {0};
  // TE Memory 3
  ap_uint<1> tmpBendTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n4[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n5[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n6[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n6_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n7[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n7_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n8[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA3n8_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n4_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n5[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n5_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n6[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n6_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n7[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n7_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n8[] =
#include "../emData/VMR/tables/VMSTE_L5PHIA4n8_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendTable1_n1), arrayToInt<bendCutTableSize>(tmpBendTable1_n2), arrayToInt<bendCutTableSize>(tmpBendTable1_n3), arrayToInt<bendCutTableSize>(tmpBendTable1_n4), arrayToInt<bendCutTableSize>(tmpBendTable1_n5), arrayToInt<bendCutTableSize>(tmpBendTable1_n6), arrayToInt<bendCutTableSize>(tmpBendTable1_n7), arrayToInt<bendCutTableSize>(tmpBendTable1_n8),
    arrayToInt<bendCutTableSize>(tmpBendTable2_n1), arrayToInt<bendCutTableSize>(tmpBendTable2_n2), arrayToInt<bendCutTableSize>(tmpBendTable2_n3), arrayToInt<bendCutTableSize>(tmpBendTable2_n4), arrayToInt<bendCutTableSize>(tmpBendTable2_n5), arrayToInt<bendCutTableSize>(tmpBendTable2_n6), arrayToInt<bendCutTableSize>(tmpBendTable2_n7), arrayToInt<bendCutTableSize>(tmpBendTable2_n8),
    arrayToInt<bendCutTableSize>(tmpBendTable3_n1), arrayToInt<bendCutTableSize>(tmpBendTable3_n2), arrayToInt<bendCutTableSize>(tmpBendTable3_n3), arrayToInt<bendCutTableSize>(tmpBendTable3_n4), arrayToInt<bendCutTableSize>(tmpBendTable3_n5), arrayToInt<bendCutTableSize>(tmpBendTable3_n6), arrayToInt<bendCutTableSize>(tmpBendTable3_n7), arrayToInt<bendCutTableSize>(tmpBendTable3_n8),
    arrayToInt<bendCutTableSize>(tmpBendTable4_n1), arrayToInt<bendCutTableSize>(tmpBendTable4_n2), arrayToInt<bendCutTableSize>(tmpBendTable4_n3), arrayToInt<bendCutTableSize>(tmpBendTable4_n4), arrayToInt<bendCutTableSize>(tmpBendTable4_n5), arrayToInt<bendCutTableSize>(tmpBendTable4_n6), arrayToInt<bendCutTableSize>(tmpBendTable4_n7), arrayToInt<bendCutTableSize>(tmpBendTable4_n8)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L5, phiRegions::A>()>* getBendCutOverlapTable<TF::L5, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L5, phiRegions::A>()>* getBendCutOuterTable<TF::L5, phiRegions::A>(){
  return nullptr;
}


////////////////
// VMR_L6PHIA //
////////////////
template<> constexpr int getNumInputs<TF::L6, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 4;
}
template<> constexpr int getNumInputsDisk2S<TF::L6, phiRegions::A>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<TF::L6, phiRegions::A>(){ // Allstub memory
  return 3;
}
template<> constexpr int getNumTEICopies<TF::L6, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumOLCopies<TF::L6, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::L6, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 4;
}
template<> constexpr int getBendCutTableSize<TF::L6, phiRegions::A>(){
  return 16;
}

template<> inline const int* getFineBinTable<TF::L6, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L6PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L6, phiRegions::A>()>* getBendCutInnerTable<TF::L6, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L6, phiRegions::A>()>* getBendCutOverlapTable<TF::L6, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::L6, phiRegions::A>()>* getBendCutOuterTable<TF::L6, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::L6, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendTable1_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable1_n3[bendCutTableSize] = {0};
  ap_uint<1> tmpBendTable1_n4[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendTable2_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_L6PHIA2n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable2_n4[bendCutTableSize] = {0};
  // TE Memory 3
  ap_uint<1> tmpBendTable3_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA3n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable3_n4[bendCutTableSize] = {0};
  // TE Memory 4
  ap_uint<1> tmpBendTable4_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA4n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable4_n4[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA4n4_vmbendcut.tab"
  // TE Memory 5
  ap_uint<1> tmpBendTable5_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA5n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable5_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA5n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable5_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA5n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable5_n4[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA5n4_vmbendcut.tab"
  // TE Memory 6 
  ap_uint<1> tmpBendTable6_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA6n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable6_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA6n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable6_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA6n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable6_n4[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA6n4_vmbendcut.tab"
// TE Memory 7
  ap_uint<1> tmpBendTable7_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA7n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable7_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA7n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable7_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA7n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable7_n4[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA7n4_vmbendcut.tab"
  // TE Memory 8
  ap_uint<1> tmpBendTable8_n1[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA8n1_vmbendcut.tab"
  ap_uint<1> tmpBendTable8_n2[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA8n2_vmbendcut.tab"
  ap_uint<1> tmpBendTable8_n3[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA8n3_vmbendcut.tab"
  ap_uint<1> tmpBendTable8_n4[] =
#include "../emData/VMR/tables/VMSTE_L6PHIA8n4_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendTable1_n1), arrayToInt<bendCutTableSize>(tmpBendTable1_n2), arrayToInt<bendCutTableSize>(tmpBendTable1_n3), arrayToInt<bendCutTableSize>(tmpBendTable1_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable2_n1), arrayToInt<bendCutTableSize>(tmpBendTable2_n2), arrayToInt<bendCutTableSize>(tmpBendTable2_n3), arrayToInt<bendCutTableSize>(tmpBendTable2_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable3_n1), arrayToInt<bendCutTableSize>(tmpBendTable3_n2), arrayToInt<bendCutTableSize>(tmpBendTable3_n3), arrayToInt<bendCutTableSize>(tmpBendTable3_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable4_n1), arrayToInt<bendCutTableSize>(tmpBendTable4_n2), arrayToInt<bendCutTableSize>(tmpBendTable4_n3), arrayToInt<bendCutTableSize>(tmpBendTable4_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable5_n1), arrayToInt<bendCutTableSize>(tmpBendTable5_n2), arrayToInt<bendCutTableSize>(tmpBendTable5_n3), arrayToInt<bendCutTableSize>(tmpBendTable5_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable6_n1), arrayToInt<bendCutTableSize>(tmpBendTable6_n2), arrayToInt<bendCutTableSize>(tmpBendTable6_n3), arrayToInt<bendCutTableSize>(tmpBendTable6_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable7_n1), arrayToInt<bendCutTableSize>(tmpBendTable7_n2), arrayToInt<bendCutTableSize>(tmpBendTable7_n3), arrayToInt<bendCutTableSize>(tmpBendTable7_n4),
    arrayToInt<bendCutTableSize>(tmpBendTable8_n1), arrayToInt<bendCutTableSize>(tmpBendTable8_n2), arrayToInt<bendCutTableSize>(tmpBendTable8_n3), arrayToInt<bendCutTableSize>(tmpBendTable8_n4)};

  return bendCutOuterTable;
}


////////////////
// VMR_D1PHIA //
////////////////
template<> constexpr int getNumInputs<TF::D1, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 6;
}
template<> constexpr int getNumInputsDisk2S<TF::D1, phiRegions::A>(){ // Number of DISK2S input memories
  return 2;
}
template<> constexpr int getNumASCopies<TF::D1, phiRegions::A>(){ // Allstub memory
  return 5;
}
template<> constexpr int getNumTEICopies<TF::D1, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumOLCopies<TF::D1, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::D1, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getBendCutTableSize<TF::D1, phiRegions::A>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::D1, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_D1PHIA_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<TF::D1, phiRegions::A>()>* getBendCutInnerTable<TF::D1, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::D1, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendInnerTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable1_n3[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendInnerTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA2n3_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendInnerTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA3n3_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendInnerTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendInnerTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIA4n3_vmbendcut.tab"


  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutInnerTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n1), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n2), arrayToInt<bendCutTableSize>(tmpBendInnerTable4_n3)};

  return bendCutInnerTable;
}

template<> inline const ap_uint<getBendCutTableSize<TF::D1, phiRegions::A>()>* getBendCutOverlapTable<TF::D1, phiRegions::A>(){
  return nullptr;
}

template<> inline const ap_uint<getBendCutTableSize<TF::D1, phiRegions::A>()>* getBendCutOuterTable<TF::D1, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::D1, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX1n5_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n4[bendCutTableSize] = {0};
  ap_uint<1> tmpBendOuterTable1_n5[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n5_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX2n6_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n5_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX3n6_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n3_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n4[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n5_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n5[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D1PHIX4n6_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n5),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n4), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n5)};

  return bendCutOuterTable;
}


////////////////
// VMR_D2PHIA //
////////////////
template<> constexpr int getNumInputs<TF::D2, phiRegions::A>(){ // Number of input memories, EXCLUDING DISK2S
  return 8;
}
template<> constexpr int getNumInputsDisk2S<TF::D2, phiRegions::A>(){ // Number of DISK2S input memories
  return 2;
}
template<> constexpr int getNumASCopies<TF::D2, phiRegions::A>(){ // Allstub memory
  return 2;
}
template<> constexpr int getNumTEICopies<TF::D2, phiRegions::A>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumOLCopies<TF::D2, phiRegions::A>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getNumTEOCopies<TF::D2, phiRegions::A>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getBendCutTableSize<TF::D2, phiRegions::A>(){
  return 8;
}

template<> inline const int* getFineBinTable<TF::D2, phiRegions::A>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_D2PHIA_finebin.tab"
  return lut;
}
template<> inline const ap_uint<getBendCutTableSize<TF::D2, phiRegions::A>()>* getBendCutInnerTable<TF::D2, phiRegions::A>(){
  return nullptr;
}
template<> inline const ap_uint<getBendCutTableSize<TF::D2, phiRegions::A>()>* getBendCutOverlapTable<TF::D2, phiRegions::A>(){
  return nullptr;
}
template<> inline const ap_uint<getBendCutTableSize<TF::D2, phiRegions::A>()>* getBendCutOuterTable<TF::D2, phiRegions::A>(){
  const int bendCutTableSize = getBendCutTableSize<TF::D2, phiRegions::A>();
  // TE Memory 1
  ap_uint<1> tmpBendOuterTable1_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA1n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA1n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable1_n3[bendCutTableSize] = {0};
  // TE Memory 2
  ap_uint<1> tmpBendOuterTable2_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA2n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA2n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable2_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA2n3_vmbendcut.tab"
  // TE Memory 3
  ap_uint<1> tmpBendOuterTable3_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA3n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA3n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable3_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA3n3_vmbendcut.tab"
  // TE Memory 4
  ap_uint<1> tmpBendOuterTable4_n1[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA4n1_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n2[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA4n2_vmbendcut.tab"
  ap_uint<1> tmpBendOuterTable4_n3[bendCutTableSize] =
#include "../emData/VMR/tables/VMSTE_D2PHIA4n3_vmbendcut.tab"

  // Combine all the temporary tables into one big table
  static ap_uint<bendCutTableSize> bendCutOuterTable[] = {
    arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable1_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable2_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable3_n3),
    arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n1), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n2), arrayToInt<bendCutTableSize>(tmpBendOuterTable4_n3)};

  return bendCutOuterTable;
}
// Add more layers and phi regions

#endif // TrackletAlgorithm_VMRouter_parameters_h
