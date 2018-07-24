// First attempt at the MatchCalculator module
// 
// Assumptions:
//
//
//
#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"
#include "HLSFullMatch.hh"
#include "MatchCalculator.hh"
#include "ap_int.h"

void MatchCalculator(
	const int seed,
	const int layer,
    HLSCandidateMatch CM_PHI1_PHI1[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI2[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI3[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI4[MAX_nCM],
    const int n_CM_PHI1_PHI1,
	const int n_CM_PHI1_PHI2,
	const int n_CM_PHI1_PHI3,
	const int n_CM_PHI1_PHI4,
	HLSAllStubs AS_PHI1[MAX_nSTUB],
	HLSProjection Proj_PHI1[MAX_nPROJ],
	HLSFullMatch FM_PHI1[MAX_nFM],
	int n_FM_PHI1
){

	// current FM counter
	int curr_FM = 0;

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
			std::cout << "Stub: " << stub.raw() << " " << stub_r   << " " << stub_z << " " << stub_phi  << " " << stub_bend << std::endl;
			std::cout << "Proj: " << proj.raw() << " " << proj_phi << " " << proj_z << " " << proj_phid << " " << proj_zd   << std::endl;

			// do full match calculations

			// get full phi and z corrections
			ap_int<16> full_phi_corr = stub_r * proj_phid;
			ap_int<16> full_z_corr   = stub_r * proj_zd;

			// r and z correction shifts
			int fact           = (layer < 3)? fact_L123           : fact_L456;
			int phi0_shift     = (layer < 3)? phi0_shift_L123     : phi0_shift_L456;
			int phi_corr_shift = (layer < 3)? phi_corr_shift_L123 : phi_corr_shift_L456;
			int z_corr_shift   = (layer < 3)? z_corr_shift_L123   : z_corr_shift_L456;

			std::cout << "Shifts : " << fact << " " << phi0_shift << " " << phi_corr_shift << " " << z_corr_shift << std::endl;


			// shift full corrections by appropriate number of bits
			ap_int<16> phi_corr = full_phi_corr >> phi_corr_shift;
			ap_int<16> z_corr   = full_z_corr >> z_corr_shift;

			// corrected values for comparisons
			ap_int<16> stub_phi_corr = stub_phi + phi_corr; // original stub phi plus the phi correction based on r
			ap_int<16> proj_z_corr   = proj_z + z_corr;     // original projection z plus the z correction

			// get differences between projection and stub values
			ap_int<16> delta_z   = stub_z - proj_z_corr;
			ap_int<16> delta_phi = (stub_phi << phi0_shift) - (proj_phi << (shift_phi0bit -1 + phi0_shift));

			std::cout << "match cuts " << matchcut_phi[layer][seed] << " " << matchcut_z[layer][seed] << std::endl;

			// apply cuts
			bool pass_match = false;
			if (delta_phi <= matchcut_phi[layer][seed] && delta_z*fact <= matchcut_z[layer][seed]) pass_match = true;

			// initialize the output full match values
			FM_STUB_INDEX fm_s_index = 0;
			FM_PROJ_INDEX fm_p_index = 0;
			FM_PHI        fm_phi     = 0;
			FM_Z          fm_z       = 0;

			// store full matches that pass cuts
			if (pass_match){
				fm_p_index = p_index;
				fm_s_index = s_index;
				fm_phi     = delta_phi;
				fm_z       = delta_z;
                std::cout << "FM residuals (phi,z): " << fm_phi << " " << fm_z << std::endl;

				FM_PHI1[curr_FM].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z);
				curr_FM++;
				std::cout << "Full Match out : " << FM_PHI1[curr_FM-1].raw() << std::endl;
			}

		}// end if (i < n_CM_PHI1_PHI1)
		else break; // don't process more CMs than you have
	}// end loop over CMs

	// write out number of FMs made
	n_FM_PHI1 = curr_FM;

};
