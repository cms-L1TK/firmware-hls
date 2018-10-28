#ifndef FILEREADUTILITY
#define FILEREADUTILITY

#include <iostream>
#include <fstream>
#include <string>


template<class DataType>
void readEventFromFile(DataType& memarray, std::ifstream& fin, int ievt){

  std::string line;

  if (ievt==0) {
    getline(fin, line);
  }

  memarray.clear(ievt);

  while (getline(fin, line)) {
    
    if (!fin.good()) {
      return;
    }

    if (line.find("Event") != string::npos) {
	return;
    }
    else {
      memarray.write_mem_line(ievt,line);
    }
    
  }
}





#endif
