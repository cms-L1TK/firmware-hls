// Utilities used only in test bench for C simulation
#ifndef __SYNTHESIS__

#ifndef TestBenches_FileReadUtility_h
#define TestBenches_FileReadUtility_h

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <vector>
#include <bitset>
#include <map>
#include <regex>
#include <glob.h>

#include "../TrackletAlgorithm/Constants.h"

inline bool openDataFile(std::ifstream& file_in, const std::string& file_name, bool print_error = true)
{
  file_in.open(file_name);

  bool success = file_in.good();
  if (not success && print_error) {
    std::cerr << "Open of file " << file_name << " failed with error: ";
    std::cerr << std::strerror(errno);
    std::cerr << std::endl;
    std::cerr << "running from directory " << getcwd(nullptr,0) << std::endl;
  }

  return success;
}

inline std::vector<std::string> split(const std::string& s, char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream sstream(s);
  
  while (getline(sstream, token, delimiter)) {
    if (token.empty()) continue;
    tokens.push_back(token);
  }
  
  return tokens;
}


// S.S. Storey 
// added because the IR 
// needs to fill a stream and not a memory 
// so writeMemFromFile does not work 
template<class DataType, int Base=2>
void writeArrayFromFile(DataType* hData, std::ifstream& pInputStream, int pEvent
, char pDelimeter = '|' , char pSplitToken = ' '){
  
  // check file is still good 
  assert(pInputStream.good());
  
  int cEventCounter=-1;
  int cCounter=0;
  do
  {
    std::string cInputLine="";
    getline( pInputStream, cInputLine );
    if( cInputLine.find("Event") != std::string::npos ) 
    {
      //std::cout << cInputLine << "\n";
      cEventCounter++;
    }
    else
    {
      if(cEventCounter != pEvent)
        continue;
      
      // split line 
      //std::cout << cInputLine << "\n";
      std::stringstream cLineContent(cInputLine);
      for(std::string cToken; getline( cLineContent, cToken , pSplitToken ); )
      {
        // look for binary representation of word  
        if( cToken.find('|') != std::string::npos )  
        {
          //remove delimeter
          cToken.erase( std::remove(cToken.begin(), cToken.end(), pDelimeter), cToken.end() );
          hData[cCounter] = DataType(std::stol( cToken , nullptr,Base ) );
          cCounter++; 
        }
      }
    }
  }while( pInputStream.good() && cEventCounter <= pEvent);
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
    } else {
      if (split(line,' ').size()==4) {
       memory.write_mem(ievt, line, base);
      } else {
	const std::string datastr = split(line, ' ').back();
	memory.write_mem(ievt, datastr, base);
      }
    }	
  }
  
}

template<class MemType, int InputBase=16, int OutputBase=16, int LSB=-1, int MSB=-1>
unsigned int compareMemWithFile(const MemType& memory, std::ifstream& fout,
                                int ievt, const std::string& label,
                                const bool truncated = false, int maxProc = kMaxProc)
{
  unsigned int err_count = 0;

  ////////////////////////////////////////
  // Read from file
  MemType memory_ref;
  writeMemFromFile<MemType>(memory_ref, fout, ievt, InputBase);

  constexpr int width = (LSB >= 0 && MSB >= LSB) ? (MSB + 1) : MemType::getWidth();
  constexpr int lsb = (LSB >= 0 && MSB >= LSB) ? LSB : 0;
  constexpr int msb = (LSB >= 0 && MSB >= LSB) ? MSB : MemType::getWidth() - 1;

  for (unsigned int i = 0; i < memory_ref.getDepth(); ++i) {
    auto data_ref = memory_ref.read_mem(ievt,i).raw().range(msb,lsb);
    auto data_com = memory.read_mem(ievt,i).raw().range(msb,lsb);
    if (i==0) {
      // If both reference and computed memories are completely empty, skip it
      if (data_com == 0 && data_ref == 0) break;
      std::cout << label << ":" << std::endl;
      std::cout << "index" << "\t" << "reference" << "\t" << "computed" << std::endl;
    }
    // If have reached the end of valid entries in both computed and reference, don't bother printing further
    if (data_com == 0 && data_ref == 0) continue;

    std::cout << i << "\t";
    if (OutputBase == 2) std::cout << std::bitset<width>(data_ref) << "\t";
    else                 std::cout << std::hex << data_ref << "\t";
    
    if (OutputBase == 2) std::cout << std::bitset<width>(data_com);
    else                 std::cout << std::hex << data_com; // << std::endl;

    // If there is extra entries in reference
    if (data_com == 0) {
      std::cout << "\t" << "<=== missing";
      if (!truncated) err_count++;
    // If there is extra entries in computed
    } else if (data_ref == 0) {
      std::cout << "\t" << "<=== EXTRA";
      err_count++;
    // If reference and computed entry are inconsistent
    } else if (data_com != data_ref) {
      std::cout << "\t" << "<=== INCONSISTENT";
      err_count++;
    }

    std::cout << std::endl;
  }
  
  return err_count;
  
}

template<class MemType, int InputBase=16, int OutputBase=16>
unsigned int compareBinnedMemWithFile(const MemType& memory, 
                                      std::ifstream& fout,
                                      int ievt, const std::string& label,
                                      const bool truncated = false, int maxProc = kMaxProc)
{
  unsigned int err_count = 0;

  ////////////////////////////////////////
  // Read from file
  MemType memory_ref;
  writeMemFromFile<MemType>(memory_ref, fout, ievt, InputBase);

  ////////////////////////////////////////
  // compare expected data with those computed and stored in the output memory
  std::cout << label << ":" << std::endl;
  std::cout << "index" << "\t" << "reference" << "\t" << "computed" << std::endl;
  for (unsigned int j = 0; j < memory_ref.getNBins(); ++j ) {
    std::cout << "Bin " << std::dec << j << std::endl;
    for (unsigned int i = 0; i < memory_ref.getNEntryPerBin() ; ++i) {
      auto data_ref = memory_ref.read_mem(ievt,j,i).raw();
      auto data_com = memory.read_mem(ievt,j,i).raw();

      // If have reached the end of valid entries in both computed and reference, don't bother printing further
      if (data_com == 0 && data_ref == 0) continue;

      std::cout << i << "\t";

      if (OutputBase == 2) std::cout << std::bitset<MemType::getWidth()>(data_ref) << "\t";
      else                 std::cout << std::hex << data_ref << "\t";
    
      if (OutputBase ==2) std::cout << std::bitset<MemType::getWidth()>(data_com);
      else                std::cout << std::hex << data_com; // << std::endl;

      // If there is extra entries in reference
      if (data_com == 0) {
        std::cout << "\t" << "<=== missing";
        if (!truncated) err_count++;
      // If there is extra entries in computed
      } else if (data_ref == 0) {
        std::cout << "\t" << "<=== EXTRA";
        err_count++;
      // If reference and computed entry are inconsistent
      } else if (data_com != data_ref) {
        std::cout << "\t" << "<=== INCONSISTENT";
        err_count++;
      }

      std::cout << std::endl;
    } // loop over entries in bin
  } // loop over bins

  return err_count;
  
}

// For TE Outer CM.
template<class MemType, int InputBase=16, int OutputBase=16>
unsigned int compareBinnedMemCMWithFile(const MemType& memory,
                                      std::ifstream& fout,
                                      int ievt, const std::string& label,
                                      const bool truncated = false, int maxProc = kMaxProc)
{
  unsigned int err_count = 0;

  ////////////////////////////////////////
  // Read from file
  MemType memory_ref;
  writeMemFromFile<MemType>(memory_ref, fout, ievt, InputBase);

  ////////////////////////////////////////
  // compare expected data with those computed and stored in the output memory
  for (unsigned int k = 0; k < memory_ref.getNCopy(); k++ ) {
    std::cout << label << "n" << std::to_string(k+1) << ":" << std::endl;
    std::cout << "index" << "\t" << "reference" << "\t" << "computed" << std::endl;
    for (unsigned int j = 0; j < memory_ref.getNBins(); ++j ) {
      std::cout << "Bin " << std::dec << j << std::endl;
      for (unsigned int i = 0; i < memory_ref.getNEntryPerBin() ; ++i) {
        auto data_ref = memory_ref.read_mem(k,ievt,j,i).raw();
        auto data_com = memory.read_mem(k,ievt,j,i).raw();

        // If have reached the end of valid entries in both computed and reference, don't bother printing further
        if (data_com == 0 && data_ref == 0) continue;

        std::cout << i << "\t";

        if (OutputBase == 2) std::cout << std::bitset<MemType::getWidth()>(data_ref) << "\t";
        else                 std::cout << std::hex << data_ref << "\t";

        if (OutputBase ==2) std::cout << std::bitset<MemType::getWidth()>(data_com);
        else                std::cout << std::hex << data_com; // << std::endl;

        // If there is extra entries in reference
        if (data_com == 0) {
          std::cout << "\t" << "<=== missing";
          if (!truncated) err_count++;
        // If there is extra entries in computed
        } else if (data_ref == 0) {
          std::cout << "\t" << "<=== EXTRA";
          err_count++;
        // If reference and computed entry are inconsistent
        } else if (data_com != data_ref) {
          std::cout << "\t" << "<=== INCONSISTENT";
          err_count++;
        }

        std::cout << std::endl;
      } // loop over entries in bin
    } // loop over bins
  } // loop over copies

  return err_count;

}

// Class designed to help organize test-bench input and output files. The
// member methods each take in a string that can contain glob-style wildcards,
// e.g.:
// "AllStubs*_L1*"
// See the glob(7) man page for full details of the supported syntax.
class TBHelper {
  public:
    // constructor takes in the base directory of the input and output files
    TBHelper(const std::string &baseDir) : baseDir_(baseDir) {}

    // destructor closes all open files and clears member maps
    ~TBHelper() {
      for (auto &query : files_) {
        for (auto &file : query.second)
          file.close();
      }
      files_.clear();
      fileNames_.clear();
    }

    // returns number of files matching given string
    unsigned nFiles(const std::string &query) {
      processQuery(query);
      return fileNames_.at(query).size();
    }

    // returns vector of input streams, one for each file matching given string
    std::vector<std::ifstream> &files(const std::string &query) {
      processQuery(query);
      return files_.at(query);
    }

    // returns vector of file names, one for each file matching given string
    std::vector<std::string> &fileNames(const std::string &query) {
      processQuery(query);
      return fileNames_.at(query);
    }

  private:
    std::string baseDir_;
    std::map<std::string, std::vector<std::ifstream> > files_;
    std::map<std::string, std::vector<std::string> > fileNames_;

    // private method for processing the given string using glob
    void processQuery(const std::string &query) {
      if (!files_.count(query)) {
        auto &files = files_[query];
        auto &fileNames = fileNames_[query];
        glob_t globbuf;
        globbuf.gl_offs = 0;
        glob((baseDir_ + "/" + query).c_str(), 0, nullptr, &globbuf);
        for (unsigned i = 0; i < globbuf.gl_pathc; i++)
          fileNames.emplace_back(globbuf.gl_pathv[i]);

        // define functions needed to get file order to match the wiring

        // function for padding single-digit numbers in the file name with a
        // leading zero
        const auto padNumbers = [](const std::string &fileName) {
          const std::regex singleDigit("([^0-9])([0-9])([^0-9.])");
          return std::regex_replace(fileName, singleDigit, "$010$02$03");
        };

        // function for removing padding added by padNumbers
        const auto removePadding = [](const std::string &fileName) {
          const std::regex paddedNumber("([^0-9])0([0-9])([^0-9.])");
          return std::regex_replace(fileName, paddedNumber, "$01$02$03");
        };

        // function to put files in ascending seed order (L1L2 L2L3 L3L4 L5L6 D1D2 D3D4 L1D1 L2D1)
        const auto padBySeed = [](const std::string &fileName) {
          const std::regex seedType1("L[0-9]L[0-9]");
          const std::regex seedType2("D[0-9]D[0-9]");
          const std::regex seedType3("L[0-9]D[0-9]");
          auto newFileName = std::regex_replace(fileName,seedType1,"PREFIXA_$&");
          newFileName = std::regex_replace(newFileName,seedType2,"PREFIXB_$&");
          newFileName = std::regex_replace(newFileName,seedType3,"PREFIXC_$&");
          return newFileName;
        };

        // function for removing padding added by padBySeed
        const auto removeSeedPad = [](const std::string &fileName) {
          const std::regex prefix("PREFIX[ABC]_");
          return std::regex_replace(fileName,prefix,"");
        };

        // The next three steps are needed to get the file name ordering right.
        // For example, the following file names will be returned in this order
        // by glob:
        //   "StubPairs_SP_L3PHIC10_L4PHIC17_04.dat"
        //   "StubPairs_SP_L3PHIC9_L4PHIC20_04.dat"
        // However, they should be in the opposite order according to the
        // wiring. So we first pad any single-digit numbers with a leading
        // zero:
        //   "StubPairs_SP_L3PHIC10_L4PHIC17_04.dat"
        //   "StubPairs_SP_L3PHIC09_L4PHIC20_04.dat"
        // Then we re-sort them:
        //   "StubPairs_SP_L3PHIC09_L4PHIC20_04.dat"
        //   "StubPairs_SP_L3PHIC10_L4PHIC17_04.dat"
        // And finally, we remove the padding added in the first step:
        //   "StubPairs_SP_L3PHIC9_L4PHIC20_04.dat"
        //   "StubPairs_SP_L3PHIC10_L4PHIC17_04.dat"
        std::transform(fileNames.begin(), fileNames.end(), fileNames.begin(), padBySeed);
        std::transform(fileNames.begin(), fileNames.end(), fileNames.begin(), padNumbers);
        std::sort(fileNames.begin(), fileNames.end());
        std::transform(fileNames.begin(), fileNames.end(), fileNames.begin(), removePadding);
        std::transform(fileNames.begin(), fileNames.end(), fileNames.begin(), removeSeedPad);

        for (const auto &fileName : fileNames)
          files.emplace_back(fileName);
        globfree(&globbuf);
      }
    }
};

#endif // TestBenches_FileReadUtility_h

#endif // __SYNTHESIS__
