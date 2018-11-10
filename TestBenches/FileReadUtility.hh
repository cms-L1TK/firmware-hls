// Utilities used only in test bench for C simulation
#ifndef __SYNTHESIS__

#ifndef FILEREADUTILITY
#define FILEREADUTILITY

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool openDataFile(std::ifstream& file_in, const std::string& file_name)
{
  file_in.open(file_name);

  bool success = file_in.good();
  if (not success) {
    std::cerr << "Open of file " << file_name << " failed with error!";
    std::cerr << std::endl;
  }

  return success;
}

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

    if (line.find("Event") != std::string::npos) {
	return;
    }
    else {
      memarray.write_mem_line(ievt,line);
    }
    
  }
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream sstream(s);
  
  while (getline(sstream, token, delimiter)) {
    tokens.push_back(token);
  }
  
  return tokens;
}

template<class MemType>
void writeMemFromFile(MemType& memory, std::ifstream& fin, int ievt, int base=16)
{
  std::string line;

  if (ievt==0) {
    getline(fin, line);
  }
  
  memory.clear();
  
  while (getline(fin, line)) {
    
    if (!fin.good()) {
      return;
    }
    
    if (line.find("Event") != std::string::npos) {
      return;
    }
    else {
      if (split(line,' ').size()==4) {
	memory.write_mem(ievt, line.c_str(), base);	
      } else {
	const std::string datastr = split(line, ' ').back();
	memory.write_mem(ievt, datastr.c_str(), base);
      }
    }	
  }
  
}

// TODO: FIXME or write a new one for binned memories
template<class MemType, int base=16>
unsigned int compareMemWithFile(const MemType& memory, std::ifstream& fout,
                                int ievt, const std::string& label)
{
  unsigned int err_count = 0;

  ////////////////////////////////////////
  // Read from file
  MemType memory_ref;
  writeMemFromFile<MemType>(memory_ref, fout, ievt, base);

  // Check if at least one of the memories in comparison is non empty
  // before spamming the screen
  if (memory_ref.getEntries(ievt) or memory.getEntries(ievt)) {
    std::cout << label << ":" << std::endl;
  }

  ////////////////////////////////////////
  // compare expected data with those computed and stored in the output memory
  if (memory.getEntries(ievt)!=0 or memory_ref.getEntries(ievt)!=0)
    std::cout << "reference" << "\t" << "computed" << std::endl;
  
  for (int i = 0; i < memory_ref.getEntries(ievt); ++i) {
    
    auto data_ref = memory_ref.read_mem(ievt,i).raw();
    std::cout << std::hex << data_ref << "\t";
    
    if (i >= memory.getEntries(ievt) ) {
      // missing entries in the computed memory
      err_count++;
      std::cout << "missing" << std::endl;
      continue;
    }

    auto data_com = memory.read_mem(ievt,i).raw();
    std::cout << std::hex << data_com << std::endl;

    if (data_com != data_ref) err_count++;
  }
  
  // in case computed memory has extra contents...
  if (memory.getEntries(ievt) >  memory_ref.getEntries(ievt)) {
    
    for (int i = memory_ref.getEntries(ievt); i < memory.getEntries(ievt); ++i) {
      auto data_extra = memory.read_mem(ievt, i).raw();   
      std::cout << "missing" << "\t" << std::hex << data_extra << std::endl;
      err_count++;
    }
  }

  return err_count;
  
}

#endif  // FILEREADUTILITY

#endif  // __SYNTHESIS__
