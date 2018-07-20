// First attempt at the MatchCalculator module
// 
// Assumptions:
//
//
//
#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"
#include "MatchCalculator.hh"
#include "ap_int.h"

void MatchCalculator(
    HLSCandidateMatch CM_PHI1_PHI1[MAX_nCM],
    const int n_CM_PHI1_PHI1,
	HLSAllStubs AS_PHI1[MAX_nSTUB],
	HLSProjection Proj_PHI1[MAX_nPROJ]

    //HLSCandidateMatch * CM_PHI1_PHI2,
    //HLSCandidateMatch * CM_PHI1_PHI3,
    //HLSCandidateMatch * CM_PHI1_PHI4
){

   // loop over candidate matches
   // up to the max number MAX_nCM the module can handle
   CM_LOOP: for (int i = 0; i < MAX_nCM; ++i)
   {
     if (i < n_CM_PHI1_PHI1) // up to the number that are coming in
     {

       // extract the CM parameters (indices of stub & projection)
       const CM_proj_index p_index = CM_PHI1_PHI1[i].GetPIndex();
       const CM_stub_index s_index = CM_PHI1_PHI1[i].GetSIndex();
       
       // pick up the right stub from the index
       HLSAllStubs     stub      = AS_PHI1[s_index];
       const AS_r      stub_r    = stub.GetR();
       const AS_z      stub_z    = stub.GetZ();
       const AS_phi    stub_phi  = stub.GetPhi();
       const AS_bend   stub_bend = stub.GetBend();

       // pick up the right projection from the index
       HLSProjection   proj      = Proj_PHI1[p_index];
       const PROJ_PHI  proj_phi  = proj.GetPhi();
       const PROJ_Z    proj_z    = proj.GetZ();
       const PROJ_PHID proj_phid = proj.GetPhiDeriv();
       const PROJ_ZD   proj_zd   = proj.GetZDeriv();

       // write out parameters for debugging
       std::cout << "Stub: " << stub.raw() << " " << stub_r << " " << stub_z << " " << stub_phi << " " << stub_bend << std::endl;
       std::cout << "Proj: " << proj.raw() << " " << proj_phi << " " << proj_z << " " << proj_phid << " " << proj_zd << std::endl;

       // do full match calculations

       ap_int<16> r_corr = stub_r * proj_phid;
       ap_int<16> z_corr = stub_r * proj_zd;


     }// end if (i < n_CM_PHI1_PHI1)
     else break; // don't process more CMs than you have
   }// end loop over CMs


};
