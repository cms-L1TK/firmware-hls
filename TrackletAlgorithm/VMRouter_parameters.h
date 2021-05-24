#ifndef TrackletAlgorithm_VMRouter_parameters_h
#define TrackletAlgorithm_VMRouter_parameters_h

// Hardcoded number of memories and masks from the wiring.
// NOTE: this file is incomplete. Please add the missing numbers

// Enums used to get the correct parameters
enum class phiRegions : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F', G = 'G', H = 'H'};

// The functions that returns the LUTs and parameters
template<bool isLayer, int layer> const int* getPhiCorrTable();
template<bool isLayer, int layer> const int* getRzBitsInnerTable();
template<bool isLayer, int layer> const int* getRzBitsOverlapTable();
template<bool isLayer, int layer> const int* getRzBitsOuterTable();
template<bool isLayer, int layer, phiRegions phi> const int* getFineBinTable();
template<bool isLayer, int layer, phiRegions phi, int size> const ap_uint<size>* getBendCutInnerTable();
template<bool isLayer, int layer, phiRegions phi, int size> const ap_uint<size>* getBendCutOverlapTable();
template<bool isLayer, int layer, phiRegions phi, int size> const ap_uint<size>* getBendCutOuterTable();

template<bool isLayer, int layer, phiRegions phi> constexpr int getNumInputs();
template<bool isLayer, int layer, phiRegions phi> constexpr int getNumInputsDisk2S();
template<bool isLayer, int layer, phiRegions phi> constexpr int getNumASCopies();
template<bool isLayer, int layer, phiRegions phi> constexpr int getNumTEICopies();
template<bool isLayer, int layer, phiRegions phi> constexpr int getNumOLCopies();
template<bool isLayer, int layer, phiRegions phi> constexpr int getNumTEOCopies();

template<bool isLayer, int layer, phiRegions phi> constexpr int getBendCutTableSize();

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
template<> inline const int* getPhiCorrTable<true, TF::L1>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL1.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<true, TF::L2>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL2.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<true, TF::L3>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL3.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<true, TF::L4>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL4.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<true, TF::L5>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL5.tab"
  return lut;
}
template<> inline const int* getPhiCorrTable<true, TF::L6>(){
  static int lut[] = 
#include "../emData/VMR/tables/VMPhiCorrL6.tab"
  return lut;
}

// VMTableInner
template<> inline const int* getRzBitsInnerTable<true, TF::L1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL1L2.tab"
  return lut;
}

// VMTableInner - Overlap
template<> inline const int* getRzBitsOverlapTable<true, TF::L1>(){
  static int lut[] =
#include "../emData/VMR/tables/VMTableInnerL1D1.tab"
  return lut;
}

//VMTableOuter
template<> inline const int* getRzBitsOuterTable<true, TF::L1>(){
  return nullptr;
}

// VMR_L1PHID
template<> constexpr int getNumInputs<true, TF::L1, phiRegions::D>(){ // Number of input memories, EXCLUDING DISK2S
  return 7;
}
template<> constexpr int getNumInputsDisk2S<true, TF::L1, phiRegions::D>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<true, TF::L1, phiRegions::D>(){ // Allstub memory
  return 5;
}
template<> constexpr int getNumTEICopies<true, TF::L1, phiRegions::D>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getNumOLCopies<true, TF::L1, phiRegions::D>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumTEOCopies<true, TF::L1, phiRegions::D>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getBendCutTableSize<true, TF::L1, phiRegions::D>(){
  return 8;
}

template<> inline const int* getFineBinTable<true, TF::L1, phiRegions::D>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L1PHID_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::D>()>* getBendCutInnerTable<true, TF::L1, phiRegions::D>(){
  const int bendCutTableSize = getBendCutTableSize<true, TF::L1, phiRegions::D>();
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

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::D>()>* getBendCutOverlapTable<true, TF::L1, phiRegions::D>(){
  const int bendCutTableSize = getBendCutTableSize<true, TF::L1, phiRegions::D>();
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

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::D>()>* getBendCutOuterTable<true, TF::L1, phiRegions::D>(){
  return nullptr;
}


// VMR_L1PHIE
template<> constexpr int getNumInputs<true, TF::L1, phiRegions::E>(){ // Number of input memories, EXCLUDING DISK2S
  return 7;
}
template<> constexpr int getNumInputsDisk2S<true, TF::L1, phiRegions::E>(){ // Number of DISK2S input memories
  return 0;
}
template<> constexpr int getNumASCopies<true, TF::L1, phiRegions::E>(){ // Allstub memory
  return 4;
}
template<> constexpr int getNumTEICopies<true, TF::L1, phiRegions::E>(){ // TE Inner memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 5;
}
template<> constexpr int getNumOLCopies<true, TF::L1, phiRegions::E>(){ // TE Inner Overlap memory. NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 3;
}
template<> constexpr int getNumTEOCopies<true, TF::L1, phiRegions::E>(){ // TE Outer memories, NOTE: can't use 0 if we don't have any memories of a certain type. Use 1.
  return 1;
}
template<> constexpr int getBendCutTableSize<true, TF::L1, phiRegions::E>(){
  return 8;
}

template<> inline const int* getFineBinTable<true, TF::L1, phiRegions::E>(){
  static int lut[] =
#include "../emData/VMR/tables/VMR_L1PHIE_finebin.tab"
  return lut;
}

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::E>()>* getBendCutInnerTable<true, TF::L1, phiRegions::E>(){
  const int bendCutTableSize = getBendCutTableSize<true, TF::L1, phiRegions::E>();
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

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::E>()>* getBendCutOverlapTable<true, TF::L1, phiRegions::E>(){
  const int bendCutTableSize = getBendCutTableSize<true, TF::L1, phiRegions::E>();
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

template<> inline const ap_uint<getBendCutTableSize<true, TF::L1, phiRegions::E>()>* getBendCutOuterTable<true, TF::L1, phiRegions::E>(){
  return nullptr;
}
// Add more layers and phi regions

#endif // TrackletAlgorithm_VMRouter_parameters_h