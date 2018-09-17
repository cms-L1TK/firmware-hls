// 
// HLSCandidateMatch class
// 
// Contains candidate match definition
//
// 
#pragma once
#include "ap_int.h"

const int MAX_nCM     = 36; // max number of CMs an individual module can handle (truncate)


const int nBITS_CM    = 12; // total number of bits for CM
const int nBITS_INDEX = 6;  // number of bits used for indexing

// Raw candidate match data
typedef ap_uint<nBITS_CM> CandidateMatch;

// Define bit widths for CM parameters
typedef ap_uint<nBITS_INDEX>   CM_proj_index; // projection (tracklet) index
typedef ap_uint<nBITS_INDEX>   CM_stub_index; // stub index


class HLSCandidateMatch
{
private:
   CandidateMatch data_;
   CM_proj_index  p_index;
   CM_stub_index  s_index; 

public:
   // constructors
   HLSCandidateMatch(CandidateMatch newdata):
	   data_(newdata)
   {
   }
   HLSCandidateMatch():
	   data_(0)
   {
   }  
   HLSCandidateMatch(const CM_proj_index new_p_index,
                     const CM_stub_index new_s_index)
   {
      AddCM(new_p_index,new_s_index);
   }

   // other functions

   // return the raw CM
   CandidateMatch raw() const 
   {
     return data_;
   }

   // construct a CM
   void AddCM(const CandidateMatch newCM) 
   {
     data_ = newCM;
   } 
   void AddCM(const CM_proj_index new_p_index,
              const CM_stub_index new_s_index)
   {
     p_index = new_p_index;  // set p_index
     s_index = new_s_index;  // set s_index
     // setup full CM by concatenating p_index and s_index
     // data_ is the or of p_index (shifted by size of s_index) and s_index
     // need "to_long" otherwise data will truncate at its current size
     //data_   = ((new_p_index.to_long() << (nBITS_INDEX-1)) | new_s_index) & ((1<<(2*nBITS_INDEX))-1);
     data_   = ((new_p_index.to_long() << nBITS_INDEX) | new_s_index) & 0xFFFFFFFFFUL;
   }
   
   // return values
   CM_proj_index GetPIndex() const
   {
     // get projection index by shifting data to remove stub index
     // then doing and of NBITS{1} to ensure only picking up the NBITS of interest
     //CM_proj_index p = (data_ >> (nBITS_INDEX-1));
     //CM_proj_index p = ((data_ >> (nBITS_INDEX-1)) & ((1<<nBITS_INDEX)-1));
     CM_proj_index p = ((data_ >> nBITS_INDEX) & 0x3FUL);
     return p; 
   }
   CM_stub_index GetSIndex() const
   { 
     // get stub index by doing and of NBITS{1} to ensure only picking up the NBITS of interest
     //CM_stub_index s = (data_ & ((1<<nBITS_INDEX)-1));
     CM_stub_index s = (data_ & 0x3FUL);
     return s;
   }

}; // end class
