#ifndef MATCHCALCULATOR_H
#define MATCHCALCULATOR_H

#include "Constants.hh"
#include "CandidateMatchMemory.hh"
#include "AllStubMemory.hh"
#include "AllProjectionMemory.hh"
#include "FullMatchMemory.hh"

const int kFact           = 1;
const int kPhi0_shift     = 3; 
const int kShift_phi0bit  = 1;
const int kPhi_corr_shift = 5;
const int kZ_corr_shift   = 6;
const int kPhiSector      = 2; // PHI Sector C = 2

void MatchCalculator(const BXType  bx,
                     const CandidateMatchMemory* const incmdata1,
                     const CandidateMatchMemory* const incmdata2,
                     const CandidateMatchMemory* const incmdata3,
                     const CandidateMatchMemory* const incmdata4,
                     const CandidateMatchMemory* const incmdata5,
                     const CandidateMatchMemory* const incmdata6,
                     const CandidateMatchMemory* const incmdata7,
                     const CandidateMatchMemory* const incmdata8,
                     const AllProjectionMemory* const inprojdata, 
                     const AllStubMemory* const instubdata,
                     FullMatchMemory* const outfmdata1,
                     FullMatchMemory* const outfmdata2);


template< int width >
ap_uint<width> iabs( ap_int<width> value )
{
	ap_uint<width> absval;
	if (value < 0) absval = -value;
	else           absval = value;
	return absval;
};


static const ap_int<17> LUT_matchcut_phi[7] = {
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_phicut.tab" 
};

static const ap_int<13> LUT_matchcut_z[7] = {
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_zcut.tab"
};


#endif

/*
void readTable(bool table[256]){

  bool tmp[256]=
  #include "../emData/MC/MC_L3PHIC/MC_L3PHIC_phicut.tab"

  for (int i=0;i<256;i++){
    table[i]=tmp[i];
  }

}
*/
