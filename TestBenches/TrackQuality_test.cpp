//Track Quality test bench 

#include "TrackQualityTop.h"
#include "TrackQualityMemory.h"
#include "parameters.h"
#include "FileReadUtility.h"
#include "BDT.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int nevents = 5;  // number of events to run
using namespace std;

int main()
{
  //load input data from text file
  ifstream fin_tracks;
  bool valid_intrack = openDataFile(fin_tracks,"TQ/hls_hex.dat");
  if (not valid_intrack) return -1;
  //load predictions from text file
  ifstream fin_predictions;
  bool valid_inpred = openDataFile(fin_predictions,"TQ/conifer_predictions.dat");
  if (not valid_inpred) return -1;

  std::string trk_line;
  std::string pred_line;
  int err_count = 0;
  int event_count = 0;

  while (event_count < nevents) {
    
    std::getline(fin_tracks,trk_line);
    
    if (trk_line.find("Event") != std::string::npos){
      event_count ++;
      continue;
    }
    else{
      std::getline(fin_predictions,pred_line); //predicitions don't have event headers so only iterate when input data is tracks

      char pDelimeter = '|';
      std::vector<std::string> splitline = split(trk_line, pDelimeter);
      
      ap_uint<96> x = 0;
      std::stringstream ss;
      ss << std::hex << splitline[0];  //convert 96-bit hex track word to 96-bit uint
      ss >> x;

      TTTrack inputTrack(x); //Convert to TTTrack representation

      score_arr_t score{};
      score_t tree_scores[BDT::fn_classes(n_classes) * n_trees]{};  //Setup score arrays
      std::fill_n(score, 2, 0.);
      
      //Top level track quality funtion
      TrackQualityTop(inputTrack,score,tree_scores);

      if (abs((float)score[0] - std::stof(pred_line)) > 0.0001 ) {
        std::cout << "\t" << "<=== INCONSISTENT";
        std::cout << (float)score[0] << "|" << std::stof(pred_line) << std::endl;
        err_count++;
      }
   
    }
  }  // end event loop
    fin_tracks.close();
      // This is necessary because HLS seems to only return an 8-bit error count, so if err%256==0, the test bench can falsely pass
    if (err_count > 255) err_count = 255;
    return err_count;
}
  
 
