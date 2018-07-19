// First attempt at the MatchCalculator module
// 
// Assumptions:
//
//
//
#include "HLSCandidateMatch.hh"
#include "MatchCalculator.hh"
#include "ap_int.h"

void MatchCalculator(
    HLSCandidateMatch * CM_PHI1_PHI1[MAX_nCM],
    const int n_CM_PHI1_PHI1
    //HLSCandidateMatch * CM_PHI1_PHI2,
    //HLSCandidateMatch * CM_PHI1_PHI3,
    //HLSCandidateMatch * CM_PHI1_PHI4
){

   //const CM_proj_index p_index = CM_PHI1_PHI1->GetPIndex();
   //const CM_stub_index s_index = CM_PHI1_PHI1->GetSIndex();


   // loop over candidate matches
   // up to the max number MAX_nCM the module can handle
   CM_LOOP: for (int i = 0; i < MAX_nCM; ++i)
   {
     if (i < n_CM_PHI1_PHI1) // up to the number that are coming in
     {

       std::cout << " i : " << i << std::endl;
  	   std::cout << "Data: " << hex << CM_PHI1_PHI1[i]->raw() << std::endl;

       // extract the CM parameters
       const CM_proj_index p_index = CM_PHI1_PHI1[i]->GetPIndex();
       const CM_stub_index s_index = CM_PHI1_PHI1[i]->GetSIndex();
       
       std::cout << "Proj index = " << p_index << std::endl;
       std::cout << "Stub index = " << s_index << std::endl;


     }// end if (i < n_CM_PHI1_PHI1)
     else break; // don't process more CMs than you have
   }// end loop over CMs


};
