#include <fstream>
#include <string>
// The following function provides a more compiler efficient method for reading
//look up table arrays (currently used in TP), this is only used in C simulations and not synthesis
template<class lutType, int lutsize> void readSWLUT(lutType lut[lutsize], std::string lutpath, bool skipfirst = true, bool hex = false){
  std::string emdatapath =
#ifndef __CSIM__ //at run time the working directory differs between CSIM and future SW
  "../../../../../firmware-hls/emData/";
#else
  "../../../../../emData/";
#endif
  std::string fullpath = emdatapath + lutpath;
  std::ifstream LUTif(fullpath);
  if (hex) {
    LUTif >> std::hex;
  }
  lutType lutval;
  unsigned int lutIndex=0;
  while (LUTif >> lutval){
    if (skipfirst && lutval == 0){
      skipfirst = false;
      continue;
    }
    lut[lutIndex]=lutval;
    ++lutIndex;
  }
}
