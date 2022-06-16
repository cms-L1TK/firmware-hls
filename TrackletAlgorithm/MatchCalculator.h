#ifndef TrackletAlgorithm_MatchCalculator_h
#define TrackletAlgorithm_MatchCalculator_h

// MatchCalculator

#include "Constants.h"
#include "CandidateMatchMemory.h"
#include "AllStubMemory.h"
#include "AllProjectionMemory.h"
#include "FullMatchMemory.h"
#include <bitset>

namespace MC {
  const auto cmzero = CandidateMatch::CandidateMatchData(0);
  const auto cmhigh = CandidateMatch::CandidateMatchData(-1);
  enum lutType {PHICUT, ZCUT, PSPHICUT, SSPHICUT, PSRCUT, SSRCUT, ALPHAINNERCUT, ALPHAOUTERCUT, RDSSINNERCUT, RDSSOUTERCUT};
}

//////////////////////////////////////////////////////////////

template<int layer, int part>
void merger(
     // inputs
     CandidateMatch inA,
     bool validA,
     CandidateMatch inB,
     bool validB,
     CandidateMatch out,
     bool vout,
     bool inread,
     CandidateMatch A,
     bool vA,
     bool sA,
     CandidateMatch B,
     bool vB,
     bool sB,
     // outputs
     CandidateMatch * Anext,
     bool * vAnext,
     bool * sAnext,
     CandidateMatch * Bnext,
     bool * vBnext,
     bool * sBnext,
     CandidateMatch * outnext,
     bool * voutnext,
     bool * readA,
     bool * readB
){

#pragma HLS inline
#pragma HLS pipeline II=1 rewind
#pragma HLS interface ap_ctrl_none port=return
#pragma HLS interface ap_ctrl_none port=inA,validA,inB,validB,out,vout,inread,A,vA,sA,B,vB,sB
#pragma HLS interface ap_ctrl_none port=Anext,Bnext,vAnext,vBnext,sAnext,sBnext,voutnext

    // Set read enables for A and B
    *readA = (((inread || !vout) && sA) || !vA) && validA;
    *readB = (((inread || !vout) && sB) || !vB) && validB;

    // Setup state machine
    static enum {HOLD, PROC_A, PROC_B, START, DONE} state;
    if (sA && (inread || !vout))                          state = PROC_A;
    else if (sB && (inread || !vout))                     state = PROC_B;
    else if ((!sA && !sB) && (validA || validB) && !vout) state = START;
    else if (!sB && !sA && vout && inread)                state = DONE;
    else                                                  state = HOLD;

    //------------- Explanation of the states -------------
    // START:  Either inA or inB is valid & there is no valid output & neither sA or sB is set
    //         No output yet, but set the next sA and sB and pipeline the inputs
    // PROC_A: sA is set & either there is an inread from the next layer or not valid output
    //         Output is the pipelined A, and set the next sA and sB
    // PROC_B: sB is set & either there is an inread from the next layer or not valid output
    //         Output is the pipelined B, and set the next sA and sB
    // DONE:   There is an valid output & there is no inread from the next layer and neither sA or sB is set
    //         No output, and set all reads to false
    // HOLD:   In all other cases, pipeline everthing
    //-----------------------------------------------------

    // Case statements
    switch(state)
    {
    case PROC_A: // just readA and compare inA with pipelined B
        *outnext  = A;      // output is A
        *voutnext = vA;     // output valid is vA
    	*Anext    = inA;    // pipeline inA
    	*vAnext   = validA; // pipeline inA valid
        *Bnext    = B;      // pipeline B
        *vBnext   = vB;     // pipeline vB
        *sAnext   = ((inA.getProjIndex() <= B.getProjIndex()) || !vB) && validA;  // sA=true if inA is valid and (inA <= B or B not valid)
    	*sBnext   = (!(inA.getProjIndex() <= B.getProjIndex()) || !validA) && vB; // sB=true if B is valid and (inA > B or inA not valid)
        break;
    case PROC_B: // just readB and compare inB with pipelined A
        *outnext  = B;      // output is B
    	*voutnext = vB;     // output valid is vB
    	*Bnext    = inB;    // pipeline inB
    	*vBnext   = validB; // pipeline inB valid
        *Anext    = A;      // pipeline A
        *vAnext   = vA;     // pipeline vA
        *sAnext   = ((A.getProjIndex() <= inB.getProjIndex()) || !validB) && vA;  // sA=true if A is valid and (A <= inB or inB not valid)
        *sBnext   = (!(A.getProjIndex() <= inB.getProjIndex()) || !vA) && validB; // sB=true if inB is valid and (A > inB or A not valid)
        break;
    case START: // both in at same time
        *outnext  = CandidateMatch(MC::cmhigh);
    	*voutnext = false;
    	*Anext    = inA;    // pipeline inA
    	*vAnext   = validA; // pipeline inA valid
    	*Bnext    = inB;    // pipeline inB
    	*vBnext   = validB; // pipeline inB valid
        *sAnext   = ((inA.getProjIndex() <= inB.getProjIndex()) || !validB) && validA;  // sA=true if inA is valid and (inA <= inB or inB not valid)
        *sBnext   = (!(inA.getProjIndex() <= inB.getProjIndex()) || !validA) && validB; // sB=true if inB is valid and (inA > inB or inA not valid)
        break;
    case DONE: // set everything to false 
        *outnext  = CandidateMatch(MC::cmhigh);
        *voutnext = false;
        *Anext    = CandidateMatch(MC::cmhigh);
        *vAnext   = false;
        *Bnext    = CandidateMatch(MC::cmhigh);
        *vBnext   = false;
        *sAnext   = false;
        *sBnext   = false;
        break;
    case HOLD: // pipeline all
        *outnext  = out;
        *voutnext = vout;
        *Anext    = A;
        *Bnext    = B;
        *vAnext   = vA;
        *vBnext   = vB;
        *sAnext   = sA;
        *sBnext   = sB;
        break;
    }

}

//////////////////////////////////////////////////////////////

// Absolute value template

template< int width >
ap_uint<width> iabs( ap_int<width> value )
{
  ap_uint<width> absval;
  if (value < 0) absval = -value;
  else           absval = value;
  return absval;
};

//////////////////////////////////////////////////////////////

// Template to get look up tables

// Table for phi or z cuts
template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (type==MC::PHICUT){ // phi cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L1PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L1PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L2PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L2PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L3PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L3PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L4PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L4PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L5PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L5PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L6PHIC_phicut.tab")
#  include "../emData/MC/tables/MC_L6PHIC_phicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else if(type==MC::PSPHICUT) { // PSphi cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_PSphicut.tab")
#  include "../emData/MC/tables/MC_D1PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_PSphicut.tab")
#  include "../emData/MC/tables/MC_D2PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_PSphicut.tab")
#  include "../emData/MC/tables/MC_D3PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_PSphicut.tab")
#  include "../emData/MC/tables/MC_D4PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_PSphicut.tab")
#  include "../emData/MC/tables/MC_D5PHIC_PSphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end PSphi
  else if(type==MC::SSPHICUT) { // 2Sphi cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_2Sphicut.tab")
#  include "../emData/MC/tables/MC_D1PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_2Sphicut.tab")
#  include "../emData/MC/tables/MC_D2PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_2Sphicut.tab")
#  include "../emData/MC/tables/MC_D3PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_2Sphicut.tab")
#  include "../emData/MC/tables/MC_D4PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_2Sphicut.tab")
#  include "../emData/MC/tables/MC_D5PHIC_2Sphicut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end SSphi
  else if (type==MC::ZCUT) { // z cuts
    if (L==TF::L1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L1PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L1PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L2PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L2PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L3PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L3PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L4PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L4PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L5PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L5PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::L6){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_L6PHIC_zcut.tab")
#  include "../emData/MC/tables/MC_L6PHIC_zcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
  } // end z cuts
  else if(type==MC::PSRCUT) { // PSr cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_PSrcut.tab")
#  include "../emData/MC/tables/MC_D1PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_PSrcut.tab")
#  include "../emData/MC/tables/MC_D2PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_PSrcut.tab")
#  include "../emData/MC/tables/MC_D3PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_PSrcut.tab")
#  include "../emData/MC/tables/MC_D4PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_PSrcut.tab")
#  include "../emData/MC/tables/MC_D5PHIC_PSrcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end PSr
  else if(type==MC::SSRCUT) { // 2Sr cuts
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_2Srcut.tab")
#  include "../emData/MC/tables/MC_D1PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_2Srcut.tab")
#  include "../emData/MC/tables/MC_D2PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_2Srcut.tab")
#  include "../emData/MC/tables/MC_D3PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_2Srcut.tab")
#  include "../emData/MC/tables/MC_D4PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_2Srcut.tab")
#  include "../emData/MC/tables/MC_D5PHIC_2Srcut.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  } // end 2Sr
  else if(type==MC::ALPHAINNERCUT) { // alphainner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_alphainner.tab")
#  include "../emData/MC/tables/MC_D1PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_alphainner.tab")
#  include "../emData/MC/tables/MC_D2PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha inner");
    }
  }
  else if(type==MC::ALPHAOUTERCUT) { // alphaouter cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_alphaouter.tab")
#  include "../emData/MC/tables/MC_D1PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_alphaouter.tab")
#  include "../emData/MC/tables/MC_D2PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha outer");
    }
  }

} // end readTable_Cuts

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_disk(ap_uint<width> table[depth]){
  if(type==MC::ALPHAINNERCUT) { // alphainner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_alphainner.tab")
#  include "../emData/MC/tables/MC_D1PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_alphainner.tab")
#  include "../emData/MC/tables/MC_D2PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_alphainner.tab")
#  include "../emData/MC/tables/MC_D3PHIC_alphainner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for alpha inner");
    }
  }
  else if(type==MC::ALPHAOUTERCUT) { // alphaouter cuts (//for disks only)
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_alphaouter.tab")
#  include "../emData/MC/tables/MC_D3PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_alphaouter.tab")
#  include "../emData/MC/tables/MC_D4PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_alphaouter.tab")
#  include "../emData/MC/tables/MC_D5PHIC_alphaouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 3 to 5 are valid for alpha outer");
    }
  }
} // end readTable_disk()

template<MC::lutType type, TF::layerDisk L, int width, int depth>
void readTable_rDSS(ap_uint<width> table[depth]){
  if(type==MC::RDSSINNERCUT) { // rDSSinner cuts (//for disks only)
    if (L==TF::D1){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D1PHIC_rDSSinner.tab")
#  include "../emData/MC/tables/MC_D1PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D2){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D2PHIC_rDSSinner.tab")
#  include "../emData/MC/tables/MC_D2PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_rDSSinner.tab")
#  include "../emData/MC/tables/MC_D3PHIC_rDSSinner.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 1 and 2 are valid for rDSS inner");
    }
  }
  else if(type==MC::RDSSOUTERCUT) { // rDSSouter cuts (//for disks only)
    if (L==TF::D3){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D3PHIC_rDSSouter.tab")
#  include "../emData/MC/tables/MC_D3PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D4){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D4PHIC_rDSSouter.tab")
#  include "../emData/MC/tables/MC_D4PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==TF::D5){
      ap_uint<width> tmp[depth] =
#if __has_include("../emData/MC/tables/MC_D5PHIC_rDSSouter.tab")
#  include "../emData/MC/tables/MC_D5PHIC_rDSSouter.tab"
#else
      {};
#endif
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only DISKS 3 to 5 are valid for rDSS outer");
    }
  }
} // end readTable_rDSS()


//////////////////////////////////////////////////////////////

// MatchCalculator
template<TF::layerDisk Layer, TF::phiRegion PHI, TF::seed Seed> constexpr bool FMMask();
template<TF::layerDisk Layer, TF::phiRegion PHI> constexpr uint32_t FMMask();
#include "MatchCalculator_parameters.h"

template<regionType ASTYPE, regionType APTYPE, regionType FMTYPE, int MaxMatchCopies, int MaxFullMatchCopies, TF::layerDisk LAYER=TF::L1, MC::imc PHISEC=MC::A>
void MatchCalculator(BXType bx,
                     const CandidateMatchMemory match[MaxMatchCopies],
                     const AllStubMemory<ASTYPE>* allstub,
                     const AllProjectionMemory<APTYPE>* allproj,
                     BXType& bx_o,
                     FullMatchMemory<FMTYPE> fullmatch[MaxFullMatchCopies]
){
#pragma HLS inline
#pragma HLS array_partition variable=match complete dim=1
#pragma HLS array_partition variable=fullmatch complete dim=1
  constexpr int totalMatchCopies(8);

  // Initialization

  // Setup constants depending on which layer/disk working on
  // probably should move these to constants file
  const ap_uint<4> kNbitszprojL123 = 12; // nbitszprojL123 in emulation (defined in constants)
  const ap_uint<4> kNbitszprojL456 = 8;  // nbitszprojL456 in emulation (defined in constants)
  const ap_uint<5> kNbitsdrinv = 19;     // idrinvbits     in emulation (defined in constants)
  const ap_uint<4> kShift_Rinv = 13;     // rinvbitshift   in emulation (defined in constants)
  const ap_uint<3> kShift_Phider = 7;    // phiderbitshift in emulation (defined in constants)
  const ap_uint<3> kNbitsrL123 = 7;      // nbitsrL123     in emulation (defined in constants)
  const ap_uint<3> kNbitsrL456 = 7;      // nbitsrL456     in emulation (defined in constants)
  const ap_int<4>  kShift_PS_zderL = -7; // PS_zderL_shift in emulation (defined in constants)
  const ap_int<4>  kShift_2S_zderL = -7; // SS_zderL_shift in emulation (defined in constants)

  const auto kFact               = (LAYER < TF::L4)? 1 : (1<<(kNbitszprojL123-kNbitszprojL456)); // fact_ in emulation defined in MC
  const auto kPhi0_shift         = (LAYER < TF::L4)? 3 : 0;                                      // phi0shift_ in emulation defined in MC
  const auto kShift_phi0bit      = 1;                                                             // phi0bitshift in emulation defined in constants
  const ap_uint<10> kPhi_corr_shift_L123 = 7 + kNbitsdrinv + kShift_phi0bit - kShift_Rinv - kShift_Phider;                    // icorrshift for L123
  const ap_uint<10> kPhi_corr_shift_L456 = kPhi_corr_shift_L123 - 10 + kNbitsrL456;                                           // icorrshift for L456
  const auto kPhi_corr_shift     = (LAYER < TF::L4)? kPhi_corr_shift_L123 : kPhi_corr_shift_L456;                            // icorrshift_ in emulation
  const ap_uint<10> kZ_corr_shiftL123 = (-1-kShift_PS_zderL);                                                                 // icorzshift for L123 (6 in L3)
  const ap_uint<10> kZ_corr_shiftL456 = (-1-kShift_2S_zderL + kNbitszprojL123 - kNbitszprojL456 + kNbitsrL456 - kNbitsrL123); // icorzshift for L456
  const auto kZ_corr_shift       = (LAYER < TF::L4)? kZ_corr_shiftL123 : kZ_corr_shiftL456;                                  // icorzshift_ in emulation

  const auto LUT_matchcut_phi_width = 17;
  const auto LUT_matchcut_phi_depth = 12;
  const auto LUT_matchcut_z_width = 14;
  const auto LUT_matchcut_z_depth = 12;
  const auto LUT_matchcut_rphi_width = 20;
  const auto LUT_matchcut_rphi_depth = 12;
  const auto LUT_matchcut_alpha_width = (LAYER < TF::D3) ? 9 : 10;
  const auto LUT_matchcut_alpha_depth = 10;
  const auto LUT_matchcut_r_width = 12;
  const auto LUT_matchcut_r_depth = 12;
  const auto LUT_matchcut_rDSS_width = 12;
  const auto LUT_matchcut_rDSS_depth = 10;

  // Setup look up tables for match cuts
  ap_uint<LUT_matchcut_phi_width> LUT_matchcut_phi[LUT_matchcut_phi_depth];
  readTable_Cuts<MC::PHICUT,LAYER,LUT_matchcut_phi_width,LUT_matchcut_phi_depth>(LUT_matchcut_phi);
  ap_uint<LUT_matchcut_z_width> LUT_matchcut_z[LUT_matchcut_z_depth];
  readTable_Cuts<MC::ZCUT,LAYER,LUT_matchcut_z_width,LUT_matchcut_z_depth>(LUT_matchcut_z);

  ap_uint<LUT_matchcut_rphi_width> LUT_matchcut_PSrphi[LUT_matchcut_rphi_depth];
  readTable_Cuts<MC::PSPHICUT,LAYER,LUT_matchcut_rphi_width,LUT_matchcut_rphi_depth>(LUT_matchcut_PSrphi);

  ap_uint<LUT_matchcut_rphi_width> LUT_matchcut_2Srphi[LUT_matchcut_rphi_depth];
  readTable_Cuts<MC::SSPHICUT,LAYER,LUT_matchcut_rphi_width,LUT_matchcut_rphi_depth>(LUT_matchcut_2Srphi);

  ap_uint<LUT_matchcut_r_width> LUT_matchcut_PSr[LUT_matchcut_r_depth];
  readTable_Cuts<MC::PSRCUT,LAYER,LUT_matchcut_r_width,LUT_matchcut_r_depth>(LUT_matchcut_PSr);

  ap_uint<LUT_matchcut_r_width> LUT_matchcut_2Sr[LUT_matchcut_r_depth];
  readTable_Cuts<MC::SSRCUT,LAYER,LUT_matchcut_r_width,LUT_matchcut_r_depth>(LUT_matchcut_2Sr);

  ap_uint<LUT_matchcut_alpha_width> LUT_matchcut_alpha[LUT_matchcut_alpha_depth];
  constexpr enum MC::lutType ALPHA = (LAYER < TF::D3) ? MC::ALPHAINNERCUT : MC::ALPHAOUTERCUT;
  readTable_disk<ALPHA,LAYER,LUT_matchcut_alpha_width,LUT_matchcut_alpha_depth>(LUT_matchcut_alpha);

  ap_uint<LUT_matchcut_rDSS_width> LUT_matchcut_rDSS[LUT_matchcut_rDSS_depth];
  constexpr enum MC::lutType RDSS = (LAYER < TF::D3) ? MC::RDSSINNERCUT : MC::RDSSOUTERCUT;
  readTable_rDSS<RDSS,LAYER,LUT_matchcut_rDSS_width,LUT_matchcut_rDSS_depth>(LUT_matchcut_rDSS);

  // Initialize MC delta phi cut variables
  ap_uint<LUT_matchcut_z_width> best_delta_z;
  ap_uint<LUT_matchcut_phi_width> best_delta_phi;
  ap_uint<LUT_matchcut_rphi_width> best_delta_rphi;
  ap_uint<LUT_matchcut_r_width> best_delta_r;

  // Bool and ID needed for determining if processing a new tracklet
  CandidateMatch::CMProjIndex id;
  CandidateMatch::CMProjIndex id_next;

  ap_uint<kNBits_MemAddr> ncm[totalMatchCopies];
#pragma HLS array_partition variable=ncm complete dim=0
  ncm_loop: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
    ncm[i] = ap_uint<kNBits_MemAddr>(0);
  }
  ap_uint<kNBits_MemAddr+1> total  = 0;

  // Initialize read addresses for candidate matches
  ap_uint<kNBits_MemAddr> addr[totalMatchCopies];
#pragma HLS array_partition variable=addr complete dim=0
  addr_loop: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
    addr[i] = 0;
  }

  // Read signals for the input candidate matches
  bool read[8];
  read_loop: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
    read[i] = false;
  }

  // Variables for the merger
  // layer 1 variables
  bool read_L1_1 = false;
  bool read_L1_2 = false;
  bool read_L1_3 = false;
  bool read_L1_4 = false;
  CandidateMatch cm_L1_1(MC::cmhigh);
  CandidateMatch cm_L1_2(MC::cmhigh);
  CandidateMatch cm_L1_3(MC::cmhigh);
  CandidateMatch cm_L1_4(MC::cmhigh);
  CandidateMatch tmpA_L1_1(MC::cmhigh);
  CandidateMatch tmpA_L1_2(MC::cmhigh);
  CandidateMatch tmpA_L1_3(MC::cmhigh);
  CandidateMatch tmpA_L1_4(MC::cmhigh);
  CandidateMatch tmpB_L1_1(MC::cmhigh);
  CandidateMatch tmpB_L1_2(MC::cmhigh);
  CandidateMatch tmpB_L1_3(MC::cmhigh);
  CandidateMatch tmpB_L1_4(MC::cmhigh);
  bool valid_L1_1 = false; 
  bool valid_L1_2 = false; 
  bool valid_L1_3 = false; 
  bool valid_L1_4 = false; 
  bool vA_L1_1 = false; 
  bool vA_L1_2 = false; 
  bool vA_L1_3 = false; 
  bool vA_L1_4 = false; 
  bool vB_L1_1 = false; 
  bool vB_L1_2 = false; 
  bool vB_L1_3 = false; 
  bool vB_L1_4 = false; 
  bool sA_L1_1 = false; 
  bool sA_L1_2 = false; 
  bool sA_L1_3 = false; 
  bool sA_L1_4 = false; 
  bool sB_L1_1 = false; 
  bool sB_L1_2 = false; 
  bool sB_L1_3 = false; 
  bool sB_L1_4 = false; 

  // layer 2 variables
  bool read_L2_1 = false;
  bool read_L2_2 = false;
  CandidateMatch cm_L2_1(MC::cmhigh);
  CandidateMatch cm_L2_2(MC::cmhigh);
  CandidateMatch tmpA_L2_1(MC::cmhigh);
  CandidateMatch tmpA_L2_2(MC::cmhigh);
  CandidateMatch tmpB_L2_1(MC::cmhigh);
  CandidateMatch tmpB_L2_2(MC::cmhigh);
  bool valid_L2_1 = false; 
  bool valid_L2_2 = false; 
  bool vA_L2_1 = false; 
  bool vA_L2_2 = false; 
  bool vB_L2_1 = false; 
  bool vB_L2_2 = false; 
  bool sA_L2_1 = false; 
  bool sA_L2_2 = false; 
  bool sB_L2_1 = false; 
  bool sB_L2_2 = false; 

  // layer 3 variables
  CandidateMatch tmpA_L3(MC::cmhigh);
  CandidateMatch tmpB_L3(MC::cmhigh);
  bool valid_L3 = false;
  bool vA_L3 = false;
  bool vB_L3 = false;
  bool sA_L3 = false;
  bool sB_L3 = false;

  // Setup candidate match data stream that goes into match calculations
  CandidateMatch datastream(MC::cmhigh);

  // Full match shift register to store best match
  typename AllProjection<APTYPE>::AProjTCSEED projseed;
  FullMatch<FMTYPE> bestmatch;
  bool goodmatch = false;

  ap_uint<1> inc_fm = 1;


  //-----------------------------------------------------------------------------------------------------------
  //-------------------------------- DATA PROCESSING STARTS ---------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------
  // declare counters for each of the 8 output VMProj // !!!
  ap_uint<kNBits_MemAddr> nmcout1 = 0;
  ap_uint<kNBits_MemAddr> nmcout2 = 0;
  ap_uint<kNBits_MemAddr> nmcout3 = 0;
  ap_uint<kNBits_MemAddr> nmcout4 = 0;
  ap_uint<kNBits_MemAddr> nmcout5 = 0;
  ap_uint<kNBits_MemAddr> nmcout6 = 0;
  ap_uint<kNBits_MemAddr> nmcout7 = 0;
  ap_uint<kNBits_MemAddr> nmcout8 = 0;
  MC_LOOP: for (ap_uint<kNBits_MemAddr> istep = 0; istep < kMaxProc - kMaxProcOffset(module::MC); istep++)
  {

#pragma HLS PIPELINE II=1

    // Pick up number of candidate matches for each CM memory
    ncm_load: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
      ncm[i] = (i < MaxMatchCopies) ? match[i].getEntries(bx) : ap_uint<kNBits_MemAddr>(0);
      // Count up total number of CMs *and protect incase of overflow)
      total += ncm[i];
    }

    // pipeline variables
    bool read_L1_1_next = false;
    bool read_L1_2_next = false;
    bool read_L1_3_next = false;
    bool read_L1_4_next = false;
    CandidateMatch cm_L1_1_next(MC::cmhigh);
    CandidateMatch cm_L1_2_next(MC::cmhigh);
    CandidateMatch cm_L1_3_next(MC::cmhigh);
    CandidateMatch cm_L1_4_next(MC::cmhigh);
    CandidateMatch tmpA_L1_1_next(MC::cmhigh);
    CandidateMatch tmpA_L1_2_next(MC::cmhigh);
    CandidateMatch tmpA_L1_3_next(MC::cmhigh);
    CandidateMatch tmpA_L1_4_next(MC::cmhigh);
    CandidateMatch tmpB_L1_1_next(MC::cmhigh);
    CandidateMatch tmpB_L1_2_next(MC::cmhigh);
    CandidateMatch tmpB_L1_3_next(MC::cmhigh);
    CandidateMatch tmpB_L1_4_next(MC::cmhigh);
    bool valid_L1_1_next = false;
    bool valid_L1_2_next = false;
    bool valid_L1_3_next = false;
    bool valid_L1_4_next = false;
    bool vA_L1_1_next = false;
    bool vA_L1_2_next = false;
    bool vA_L1_3_next = false;
    bool vA_L1_4_next = false;
    bool vB_L1_1_next = false;
    bool vB_L1_2_next = false;
    bool vB_L1_3_next = false;
    bool vB_L1_4_next = false;
    bool sA_L1_1_next = false;
    bool sA_L1_2_next = false;
    bool sA_L1_3_next = false;
    bool sA_L1_4_next = false;
    bool sB_L1_1_next = false;
    bool sB_L1_2_next = false;
    bool sB_L1_3_next = false;
    bool sB_L1_4_next = false;

    bool read_L2_1_next = false;
    bool read_L2_2_next = false;
    CandidateMatch cm_L2_1_next(MC::cmhigh);
    CandidateMatch cm_L2_2_next(MC::cmhigh);
    CandidateMatch tmpA_L2_1_next(MC::cmhigh);
    CandidateMatch tmpA_L2_2_next(MC::cmhigh);
    CandidateMatch tmpB_L2_1_next(MC::cmhigh);
    CandidateMatch tmpB_L2_2_next(MC::cmhigh);
    bool valid_L2_1_next = false; 
    bool valid_L2_2_next = false; 
    bool vA_L2_1_next = false; 
    bool vA_L2_2_next = false; 
    bool vB_L2_1_next = false; 
    bool vB_L2_2_next = false; 
    bool sA_L2_1_next = false; 
    bool sA_L2_2_next = false; 
    bool sB_L2_1_next = false; 
    bool sB_L2_2_next = false; 

    CandidateMatch cm_L3_next(MC::cmhigh);
    CandidateMatch tmpA_L3_next(MC::cmhigh);
    CandidateMatch tmpB_L3_next(MC::cmhigh); 
    bool valid_L3_next = false;
    bool vA_L3_next = false;
    bool vB_L3_next = false;
    bool sA_L3_next = false;
    bool sB_L3_next = false;
    bool read1_next = false;
    bool read2_next = false;
    bool read3_next = false;
    bool read4_next = false;
    bool read5_next = false;
    bool read6_next = false;
    bool read7_next = false;
    bool read8_next = false;
    bool read_next[8];
    read_next_loop: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
      read_next[i] = false;
    }


    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------- MERGE INPUT CANDIDATE MATCHES --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // Increment the read addresses for the candidate matches

    addr_inc: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
      if(read[i]) addr[i]++;
    }


    // Read in each candidate match
    CandidateMatch cm[8];
#pragma HLS array_partition variable=cm complete dim=0
    cm_load: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
      cm[i] = (i < MaxMatchCopies) ? match[i].read_mem(bx,addr[i]) : CandidateMatch(-1);
    }

    // Valid signal for the candidate match
    bool valid1 = (addr[0] < ncm[0]) && (ncm[0] > 0);
    bool valid2 = (addr[1] < ncm[1]) && (ncm[1] > 0);
    bool valid3 = (addr[2] < ncm[2]) && (ncm[2] > 0);
    bool valid4 = (addr[3] < ncm[3]) && (ncm[3] > 0);
    bool valid5 = (addr[4] < ncm[4]) && (ncm[4] > 0);
    bool valid6 = (addr[5] < ncm[5]) && (ncm[5] > 0);
    bool valid7 = (addr[6] < ncm[6]) && (ncm[6] > 0);
    bool valid8 = (addr[7] < ncm[7]) && (ncm[7] > 0);

    // merger Layer 1 Part 1
    merger<1,1>(
      cm[0], valid1, cm[1], valid2,                      // inputs: inA, validA, inB, validB
      cm_L1_1, valid_L1_1, read_L1_1,                // inputs: out, vout, inread from L2_1
      tmpA_L1_1, vA_L1_1, sA_L1_1,                   // tmp variables internal to L1_1 merger
      tmpB_L1_1, vB_L1_1, sB_L1_1,                   // tmp variables internal to L1_1 merger
      &tmpA_L1_1_next, &vA_L1_1_next, &sA_L1_1_next, // tmp variables internal to L1_1 merger
      &tmpB_L1_1_next, &vB_L1_1_next, &sB_L1_1_next, // tmp variables internal to L1_1 merger
      &cm_L1_1_next, &valid_L1_1_next,               // outputs: out, vout
      &read_next[0], &read_next[1]                       // outputs: read1, read2
    );

    // merger Layer 1 Part 2
    merger<1,2>(
      cm[2], valid3, cm[3], valid4,                      // inputs: inA, validA, inB, validB
      cm_L1_2, valid_L1_2, read_L1_2,                // inputs: out, vout, inread from L2_1
      tmpA_L1_2, vA_L1_2, sA_L1_2,                   // tmp variables internal to L1_2 merger
      tmpB_L1_2, vB_L1_2, sB_L1_2,                   // tmp variables internal to L1_2 merger
      &tmpA_L1_2_next, &vA_L1_2_next, &sA_L1_2_next, // tmp variables internal to L1_2 merger
      &tmpB_L1_2_next, &vB_L1_2_next, &sB_L1_2_next, // tmp variables internal to L1_2 merger
      &cm_L1_2_next, &valid_L1_2_next,               // outputs: out, vout
      &read_next[2], &read_next[3]                       // outputs: read3, read4
    );

    // merger Layer 1 Part 3
    merger<1,3>(
      cm[4], valid5, cm[5], valid6,                      // inputs: inA, validA, inB, validB
      cm_L1_3, valid_L1_3, read_L1_3,                // inputs: out, vout, inread from L2_1
      tmpA_L1_3, vA_L1_3, sA_L1_3,                   // tmp variables internal to L1_3 merger
      tmpB_L1_3, vB_L1_3, sB_L1_3,                   // tmp variables internal to L1_3 merger
      &tmpA_L1_3_next, &vA_L1_3_next, &sA_L1_3_next, // tmp variables internal to L1_3 merger
      &tmpB_L1_3_next, &vB_L1_3_next, &sB_L1_3_next, // tmp variables internal to L1_3 merger
      &cm_L1_3_next, &valid_L1_3_next,               // outputs: out, vout
      &read_next[4], &read_next[5]                       // outputs: read5, read6
    );

    // merger Layer 1 Part 4
    merger<1,4>(
      cm[6], valid7, cm[7], valid8,                      // inputs: inA, validA, inB, validB
      cm_L1_4, valid_L1_4, read_L1_4,                // inputs: out, vout, inread from L2_1
      tmpA_L1_4, vA_L1_4, sA_L1_4,                   // tmp variables internal to L1_4 merger
      tmpB_L1_4, vB_L1_4, sB_L1_4,                   // tmp variables internal to L1_4 merger
      &tmpA_L1_4_next, &vA_L1_4_next, &sA_L1_4_next, // tmp variables internal to L1_4 merger
      &tmpB_L1_4_next, &vB_L1_4_next, &sB_L1_4_next, // tmp variables internal to L1_4 merger
      &cm_L1_4_next, &valid_L1_4_next,               // outputs: out, vout
      &read_next[6], &read_next[7]                       // outputs: read7, read8
    );

    // merger Layer 2 Part 1
    merger<2,1>(
      cm_L1_1_next, valid_L1_1_next,                 // inputs: inA, validA
      cm_L1_2_next, valid_L1_2_next,                 // inputs: inB, validB
      cm_L2_1, valid_L2_1, read_L2_1,                // inputs: out, vout, inread from L3_1
      tmpA_L2_1, vA_L2_1, sA_L2_1,                   // tmp variables internal to L2_1 merger
      tmpB_L2_1, vB_L2_1, sB_L2_1,                   // tmp variables internal to L2_1 merger
      &tmpA_L2_1_next, &vA_L2_1_next, &sA_L2_1_next, // tmp variables internal to L2_1 merger
      &tmpB_L2_1_next, &vB_L2_1_next, &sB_L2_1_next, // tmp variables internal to L2_1 merger
      &cm_L2_1_next, &valid_L2_1_next,               // outputs: out, vout
      &read_L1_1_next, &read_L1_2_next               // outputs: read_L1_1, read_L1_2
    );

    // merger Layer 2 Part 2
    merger<2,2>(
      cm_L1_3_next, valid_L1_3_next,                 // inputs: inA, validA
      cm_L1_4_next, valid_L1_4_next,                 // inputs: inB, validB
      cm_L2_2, valid_L2_2, read_L2_2,                // inputs: out, vout, inread from L3_1
      tmpA_L2_2, vA_L2_2, sA_L2_2,                   // tmp variables internal to L2_2 merger
      tmpB_L2_2, vB_L2_2, sB_L2_2,                   // tmp variables internal to L2_2 merger
      &tmpA_L2_2_next, &vA_L2_2_next, &sA_L2_2_next, // tmp variables internal to L2_2 merger
      &tmpB_L2_2_next, &vB_L2_2_next, &sB_L2_2_next, // tmp variables internal to L2_2 merger
      &cm_L2_2_next, &valid_L2_2_next,               // outputs: out, vout
      &read_L1_3_next, &read_L1_4_next               // outputs: read_L1_3, read_L1_4
    );

    // merger Layer 3 Part 1
    merger<3,1>(
      cm_L2_1_next, valid_L2_1_next,           // inputs: inA, validA
      cm_L2_2_next, valid_L2_2_next,           // inputs: inB, validB
      datastream, valid_L3, true,              // inputs: out, vout, true inread because last layer
      tmpA_L3, vA_L3, sA_L3,                   // tmp variables internal to L3_1 merger
      tmpB_L3, vB_L3, sB_L3,                   // tmp variables internal to L3_1 merger
      &tmpA_L3_next, &vA_L3_next, &sA_L3_next, // tmp variables internal to L3_1 merger
      &tmpB_L3_next, &vB_L3_next, &sB_L3_next, // tmp variables internal to L3_1 merger
      &cm_L3_next, &valid_L3_next,             // outputs: out, vout
      &read_L2_1_next, &read_L2_2_next         // outputs: read_L2_1, read_L2_2
    );

    // pipeline the variables
    // set up the inputs for the next iteration of the loop

    read_next: for(int i = 0; i < totalMatchCopies; ++i) { // priority encoder ALWAYS expects 8
#pragma HLS unroll
        read[i] = read_next[i];
    }

    read_L1_1  = read_L1_1_next;
    read_L1_2  = read_L1_2_next;
    read_L1_3  = read_L1_3_next;
    read_L1_4  = read_L1_4_next;
    read_L2_1  = read_L2_1_next;
    read_L2_2  = read_L2_2_next;

    cm_L1_1    = cm_L1_1_next;
    cm_L1_2    = cm_L1_2_next;
    cm_L1_3    = cm_L1_3_next;
    cm_L1_4    = cm_L1_4_next;
    cm_L2_1    = cm_L2_1_next;
    cm_L2_2    = cm_L2_2_next;
    datastream = cm_L3_next;

    valid_L1_1 = valid_L1_1_next;
    valid_L1_2 = valid_L1_2_next;
    valid_L1_3 = valid_L1_3_next;
    valid_L1_4 = valid_L1_4_next;
    valid_L2_1 = valid_L2_1_next;
    valid_L2_2 = valid_L2_2_next;
    valid_L3   = valid_L3_next;

    tmpA_L1_1 = tmpA_L1_1_next;
    tmpA_L1_2 = tmpA_L1_2_next;
    tmpA_L1_3 = tmpA_L1_3_next;
    tmpA_L1_4 = tmpA_L1_4_next;
    tmpB_L1_1 = tmpB_L1_1_next;
    tmpB_L1_2 = tmpB_L1_2_next;
    tmpB_L1_3 = tmpB_L1_3_next;
    tmpB_L1_4 = tmpB_L1_4_next;

    tmpA_L2_1 = tmpA_L2_1_next;
    tmpA_L2_2 = tmpA_L2_2_next;
    tmpB_L2_1 = tmpB_L2_1_next;
    tmpB_L2_2 = tmpB_L2_2_next;
    tmpA_L3   = tmpA_L3_next;
    tmpB_L3   = tmpB_L3_next;

    vA_L1_1   = vA_L1_1_next;
    vA_L1_2   = vA_L1_2_next;
    vA_L1_3   = vA_L1_3_next;
    vA_L1_4   = vA_L1_4_next;
    vB_L1_1   = vB_L1_1_next;
    vB_L1_2   = vB_L1_2_next;
    vB_L1_3   = vB_L1_3_next;
    vB_L1_4   = vB_L1_4_next;
    vA_L2_1   = vA_L2_1_next;
    vA_L2_2   = vA_L2_2_next;
    vB_L2_1   = vB_L2_1_next;
    vB_L2_2   = vB_L2_2_next;
    vA_L3     = vA_L3_next;
    vB_L3     = vB_L3_next;

    sA_L1_1   = sA_L1_1_next;
    sA_L1_2   = sA_L1_2_next;
    sA_L1_3   = sA_L1_3_next;
    sA_L1_4   = sA_L1_4_next;
    sB_L1_1   = sB_L1_1_next;
    sB_L1_2   = sB_L1_2_next;
    sB_L1_3   = sB_L1_3_next;
    sB_L1_4   = sB_L1_4_next;
    sA_L2_1   = sA_L2_1_next;
    sA_L2_2   = sA_L2_2_next;
    sB_L2_1   = sB_L2_1_next;
    sB_L2_2   = sB_L2_2_next;
    sA_L3     = sA_L3_next;
    sB_L3     = sB_L3_next;

    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- MATCH CALCULATION STEPS --------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    // Extract the stub and projection indices from the candidate match
    auto projid = datastream.getProjIndex();
    auto stubid = datastream.getStubIndex();
    constexpr bool isDisk = LAYER >= TF::D1;
    // Use the stub and projection indices to pick up the stub and projection
    AllProjection<APTYPE> proj = allproj->read_mem(bx,projid);
    AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid);
    AllStub<DISKPS>       stub_ps = AllStub<DISKPS>(allstub->read_mem(bx,stubid).raw());
    AllStub<DISK2S>       stub_2s = AllStub<DISK2S>(allstub->read_mem(bx,stubid).raw());

    // Check if processing a new tracklet or not
    // Later we only want to store the single best match per tracklet
    id      = id_next; // pipelined id
    id_next = projid;
    bool newtracklet = (istep==0 || (id_next != id))? true : false;

    //increment full match memories
    if (newtracklet) {
      inc_fm = 1;
    }

    // Stub parameters
    typename AllStub<ASTYPE>::ASR    stub_r    = stub.getR();
    typename AllStub<ASTYPE>::ASZ    stub_z    = stub.getZ();
    typename AllStub<ASTYPE>::ASPHI  stub_phi  = stub.getPhi();
    typename AllStub<ASTYPE>::ASBEND stub_bend = stub.getBend();       
    typename AllStub<DISKPS>::ASR    stub_ps_r    = stub_ps.getR();
    typename AllStub<DISKPS>::ASZ    stub_ps_z    = stub_ps.getZ();
    typename AllStub<DISKPS>::ASPHI  stub_ps_phi  = stub_ps.getPhi();
    typename AllStub<DISKPS>::ASBEND stub_ps_bend = stub_ps.getBend();       
    typename AllStub<DISK2S>::ASR    stub_2s_r    = stub_2s.getR();
    typename AllStub<DISK2S>::ASZ    stub_2s_z    = stub_2s.getZ();
    typename AllStub<DISK2S>::ASPHI  stub_2s_phi  = stub_2s.getPhi();
    typename AllStub<DISK2S>::ASBEND stub_2s_bend = stub_2s.getBend();       
    typename AllStub<DISK2S>::ASALPHA stub_2s_alpha = stub_2s.getAlpha();       
    auto isPSStub = stub.isPSStub();

    // Projection parameters
    typename AllProjection<APTYPE>::AProjTCID          proj_tcid = proj.getTCID();
    typename AllProjection<APTYPE>::AProjTrackletIndex proj_tkid = proj.getTrackletIndex();
    typename AllProjection<APTYPE>::AProjTCSEED        proj_seed = proj.getSeed();
    typename AllProjection<APTYPE>::AProjPHI           proj_phi  = proj.getPhi();
    typename AllProjection<APTYPE>::AProjRZ            proj_z    = proj.getRZ();
    typename AllProjection<APTYPE>::AProjPHIDER        proj_phid = proj.getPhiDer();
    typename AllProjection<APTYPE>::AProjRZDER         proj_zd   = proj.getRZDer(); 
    bool isProjDisk = proj_seed >= TF::D1;


    // Calculate residuals
    // Get phi and z correction
    ap_int<22> full_phi_corr = stub_r * proj_phid; // full corr has enough bits for full multiplication
    ap_int<18> full_z_corr   = stub_r * proj_zd;   // full corr has enough bits for full multiplication
    ap_int<11> phi_corr      = full_phi_corr >> kPhi_corr_shift;                        // only keep needed bits
    ap_uint<3> shifttmp = 6;
    if(isDisk && isPSStub)
      phi_corr = (stub_ps_z * proj_phid) >> shifttmp;
    else if(isDisk && !isPSStub)
      phi_corr = (stub_2s_z * proj_phid) >> shifttmp;
    ap_int<12> z_corr        = (full_z_corr + (1<<(kZ_corr_shift-1))) >> kZ_corr_shift; // only keep needed bits
     
    // Apply the corrections
    const int kProj_phi_len = AllProjection<APTYPE>::kAProjPhiSize + 1;
    ap_int<kProj_phi_len> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction
    ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction

    // Get phi and z difference between the projection and stub
    ap_int<12> delta_z        = stub_z - proj_z_corr;
    ap_int<14> delta_z_fact   = delta_z * kFact;
    const ap_int<18> &stub_phi_long  = stub_phi;         // make longer to allow for shifting
    const ap_int<18> &proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
    ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
    ap_int<18> shiftprojphi   = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
    if(isDisk && isPSStub)
      shiftstubphi = stub_ps_phi << kPhi0_shift;
    else if(isDisk && !isPSStub) {
      shiftstubphi = stub_2s_phi << kPhi0_shift;
    }
    constexpr int dphibit = 20;
    ap_int<dphibit> delta_phi      = shiftstubphi - shiftprojphi;
    ap_uint<3> shiftprojz     = 7;
    ap_int<14> proj_r_corr    = (stub_z * proj_zd) >> shiftprojz;
    if(isDisk && isPSStub)
      proj_r_corr = (stub_ps_z * proj_zd) >> shiftprojz;
    else if(isDisk)
      proj_r_corr = (stub_2s_z * proj_zd) >> shiftprojz;
    const ap_int<15> &proj_r_long  = proj_z + proj_r_corr;
    ap_uint<1> shiftr         = 1;
    ap_int<12> delta_r        = (stub_r >> shiftr) - proj_r_long; // proj_z = RZ
    typename FullMatch<FMTYPE>::FMSTUBR tmp_stubr = isProjDisk ? LUT_matchcut_rDSS[stub_2s_r] : LUT_matchcut_rDSS[stub_r]; //FIXME

    if(isDisk && isPSStub) {
      delta_r   = (stub_ps_r >> shiftr) - proj_r_long; // proj_z = RZ
    }
    else if(isDisk && !isPSStub) {
      auto alpha_fact = LUT_matchcut_alpha[stub_2s_r];
      stub_2s_r = LUT_matchcut_rDSS[stub_2s_r];
      delta_r   = ((tmp_stubr >> shiftr) - proj_r_long); // proj_z = RZ
      ap_uint<4> alpha_shift = 12;
      ap_uint<12> alpha_corr = (delta_r * stub_2s_alpha * alpha_fact) >> alpha_shift;
      delta_phi += alpha_corr;
    }
    constexpr int adphibit = isDisk ? 12 : 17;
    ap_uint<adphibit> abs_delta_phi = iabs<adphibit>( delta_phi );    // absolute value of delta phi
    ap_int<12> abs_delta_r    = iabs<11>( delta_r );

    // Full match parameters
    const typename FullMatch<FMTYPE>::FMTCID          &fm_tcid  = proj_tcid;
    const typename FullMatch<FMTYPE>::FMTrackletIndex &fm_tkid  = proj_tkid;
    const typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
    const typename FullMatch<FMTYPE>::FMSTUBID        &fm_asid = stubid;
    typename FullMatch<FMTYPE>::FMSTUBR               fm_stubr = stub_r;
    if(isDisk && isPSStub) fm_stubr = stub_ps_r;
    const typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
    const typename FullMatch<FMTYPE>::FMZRES          fm_z     = (!isDisk) ? delta_z : delta_r;

    // Full match
    FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,fm_asphi,fm_asid,fm_stubr,fm_phi,fm_z);


    //-----------------------------------------------------------------------------------------------------------
    //-------------------------------------- BEST MATCH LOGIC BLOCK ---------------------------------------------
    //-----------------------------------------------------------------------------------------------------------

    typename AllProjection<APTYPE>::AProjTCSEED projseed_next;
    FullMatch<FMTYPE> bestmatch_next;
    bool goodmatch_next = false;

    // For first tracklet, pick up the phi cut value
    best_delta_z = (newtracklet)? LUT_matchcut_z[proj_seed] : best_delta_z;
    best_delta_phi = (newtracklet)? LUT_matchcut_phi[proj_seed] : best_delta_phi;
    if(newtracklet) {
      if(isPSStub) {
        best_delta_rphi = LUT_matchcut_PSrphi[proj_seed];
        best_delta_r = LUT_matchcut_PSr[proj_seed];
      }
      else  {
        best_delta_rphi = LUT_matchcut_2Srphi[proj_seed];
        best_delta_r = LUT_matchcut_2Sr[proj_seed];
      }
    }
  
    // Check that matches fall within the selection window of the projection 
    bool barrel_match = (delta_z_fact < best_delta_z) && (delta_z_fact >= -best_delta_z) && (abs_delta_phi <= best_delta_phi);
    bool disk_match = isPSStub ? ((abs_delta_phi * stub_ps_r) < best_delta_rphi) && (abs_delta_r < best_delta_r) : ((abs_delta_phi * tmp_stubr) < best_delta_rphi) && (abs_delta_r < best_delta_r);
    if ((!isDisk && barrel_match) || (isDisk && disk_match)){
      // Update values of best phi parameters, so that the next match
      // will be compared to this value instead of the original selection cut
      if(isDisk) {
        best_delta_rphi = isPSStub ? ap_uint<20>(abs_delta_phi * stub_ps_r) : ap_uint<20>(abs_delta_phi * tmp_stubr);
        best_delta_r    = abs_delta_r;
      }
      else {
        best_delta_z = iabs<14>(delta_z_fact);
        best_delta_phi = abs_delta_phi;
      }

      // Store bestmatch
      bestmatch_next = fm;
      goodmatch_next = true;
      projseed_next  = proj_seed;
    }

    if(goodmatch_next&&valid_L3) {

      switch (projseed_next) {
        case 0:
        if(FMMask<LAYER, PHISEC, TF::L1L2>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L1L2>()].write_mem(bx,bestmatch_next,nmcout1+inc_fm-1); // L1L2 seed
          nmcout1+=inc_fm;
        }
        break;
        case 1:
        if(FMMask<LAYER, PHISEC, TF::L2L3>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L2L3>()].write_mem(bx,bestmatch_next,nmcout2+inc_fm-1); // L2L3 seed
          nmcout2+=inc_fm;
        }
        break;
        case 2:
        if(FMMask<LAYER, PHISEC, TF::L3L4>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L3L4>()].write_mem(bx,bestmatch_next,nmcout3+inc_fm-1); // L3L4 seed
          nmcout3+=inc_fm;
        }
        break;
        case 3:
        if(FMMask<LAYER, PHISEC, TF::L5L6>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L5L6>()].write_mem(bx,bestmatch_next,nmcout4+inc_fm-1); // L5L6 seed
          nmcout4+=inc_fm;
        }
        break;
        case 4:
        if(FMMask<LAYER, PHISEC, TF::D1D2>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::D1D2>()].write_mem(bx,bestmatch_next,nmcout5+inc_fm-1); // D1D2 seed
          nmcout5+=inc_fm;
        }
        break;
        case 5:
        if(FMMask<LAYER, PHISEC, TF::D3D4>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::D3D4>()].write_mem(bx,bestmatch_next,nmcout6+inc_fm-1); // D3D4 seed
          nmcout6+=inc_fm;
        }
        break;
        case 6:
        if(FMMask<LAYER, PHISEC, TF::L1D1>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L1D1>()].write_mem(bx,bestmatch_next,nmcout7+inc_fm-1); // L1D1 seed
          nmcout7+=inc_fm;
        }
        break;
        case 7:
        if(FMMask<LAYER, PHISEC, TF::L2D1>()) {
          fullmatch[FMCount<LAYER, PHISEC, TF::L2D1>()].write_mem(bx,bestmatch_next,nmcout8+inc_fm-1); // L2D1 seed
          nmcout8+=inc_fm;
        }
        break;
      }
      inc_fm=0;
    }

    // pipeline the bestmatch registers
    bestmatch      = bestmatch_next;
    goodmatch      = goodmatch_next;
    projseed       = projseed_next;

  }// end MC_LOOP

  bx_o = bx;

}// end MatchCalculator

#endif
