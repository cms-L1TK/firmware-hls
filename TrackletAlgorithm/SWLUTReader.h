#include <fstream>
#include <string>
template<int lutwidth, int lutsize> void readSWLUT(ap_uint<lutwidth> lut[lutsize], std::string lutpath){

  std::ifstream LUTif(lutpath);
  ap_uint<lutwidth> lutval;
  bool first = true;
  unsigned int lutIndex=0;
  std::cout << "lutpath: " << lutpath<< "open: " << !LUTif.is_open();
  while (LUTif >> lutval){
    if (first && lutval == 0){
      first = false;
      continue;
    }
    std::cout << "reglut push back value: " << std::dec << lutval << " at index: " << lutIndex << "\n";
    lut[lutIndex]=lutval;
    ++lutIndex;
  }
}
