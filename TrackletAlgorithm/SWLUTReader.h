#include <fstream>
#include <string>
// The following function provides a more compiler efficient method for reading look up table arrays (currently used in TP), this is only used in C simulations and not synthesis
template<class lutType, int lutsize> void readSWLUT(lutType lut[lutsize], std::string lutpath){

  std::ifstream LUTif(lutpath);
  lutType lutval;
  bool first = true;
  unsigned int lutIndex=0;
  while (LUTif >> lutval){
    if (first && lutval == 0){
      first = false;
      continue;
    }
    lut[lutIndex]=lutval;
    ++lutIndex;
  }
}
