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
	HLSAllStubs   AS_PHI1[MAX_nSTUB],
	HLSProjection Proj_PHI1[MAX_nPROJ],
	HLSFullMatch  FM_PHI1[MAX_nFM],
	int n_FM_PHI1
){

	// tmp_CM setup by the priority encoder
	HLSCandidateMatch tmp_CM[MAX_nCM];

	// Bool to keep track if working on a new tracklet (for best match logic)
    bool newtracklet = true;

	// Current FM counter -- used to write out n_FM made
	int curr_FM = 0;

	// Total number of CMs
	int start1 = 0;
	int start2 = n_CM_PHI1_PHI1;
	int start3 = n_CM_PHI1_PHI1 + n_CM_PHI1_PHI2;
	int start4 = n_CM_PHI1_PHI1 + n_CM_PHI1_PHI2 + n_CM_PHI1_PHI3;
	int n_CM   = n_CM_PHI1_PHI1 + n_CM_PHI1_PHI2 + n_CM_PHI1_PHI3 + n_CM_PHI1_PHI4;

	//int fact = 0;
	//int phi0_shift = 0;
	//int phi_corr_shift = 0;
	//int z_corr_shift = 0;
	//SetupShifts<layer>(fact,phi0_shift,phi_corr_shift,z_corr_shift);

	// Setup the r and z correction shifts
	int fact           = (layer < 3)? fact_L123           : fact_L456;
	int phi0_shift     = (layer < 3)? phi0_shift_L123     : phi0_shift_L456;
	int phi_corr_shift = (layer < 3)? phi_corr_shift_L123 : phi_corr_shift_L456;
	int z_corr_shift   = (layer < 3)? z_corr_shift_L123   : z_corr_shift_L456;


	//----- Priority encoder for deciding which CM to use
    //
	// loop over candidate matches
	// up to the max number MAX_nCM the module can handle
	// and setup tmp_CM which has the array of all CMs to read
	//

	PRIO_LOOP: for (int i = 0; i < MAX_nCM; ++i)
	{
		if (i < n_CM) // up to the number that are coming in
		{

			int which_CM  = 0;
			if (start1 <= i < start2)      which_CM = 1;
			else if (start2 <= i < start3) which_CM = 2;
			else if (start3 <= i < start4) which_CM = 3;
			else if (start4 <= i < n_CM)   which_CM = 4;

			// pick up which CM to use
			switch(which_CM)
			{
				case (0):
					tmp_CM[i] = HLSCandidateMatch();
					break;
				case (1):
					tmp_CM[i] = CM_PHI1_PHI1[i-start1];
					break;
				case (2):
					tmp_CM[i] = CM_PHI1_PHI2[i-start2];
					break;
				case (3):
					tmp_CM[i] = CM_PHI1_PHI3[i-start3];
					break;
				case (4):
					tmp_CM[i] = CM_PHI1_PHI4[i-start4];
					break;
			}// end case

		}// end if (i < n_CM)
		else break;
	}// end PRIO_LOOP

	//----- Calculate matches (using the tmp_CM array from above)
	//
	// loop over candidate matches
	// up to the max number MAX_nCM the module can handle
	// pick up corresponding stub and projection
	// calculate z and phi corrections
	// check that residuals pass the cuts
	// and save the final match
	//

	CM_LOOP: for (int i = 0; i < MAX_nCM; ++i)
	{
		if (i < n_CM)  // up to the number that are coming in
		{

			//----- Extract the CM parameters (indices of stub & projection)
			const CM_proj_index p_index = tmp_CM[i].GetPIndex(); // use the priority encoder output
			const CM_stub_index s_index = tmp_CM[i].GetSIndex(); // use the priority encoder output

			//----- Check if processing a new tracklet or not (needed for determining best match)
			if (i == 0) newtracklet = true;
			else{
				if (p_index == tmp_CM[i-1].GetPIndex()) newtracklet = false;
				else newtracklet = true;
			}
       
			//----- Use the indices to pick up the stub and projection
			HLSAllStubs     stub      = AS_PHI1[s_index];
			HLSProjection   proj      = Proj_PHI1[p_index];

			//----- Stub parameters
			const AS_r      stub_r    = stub.GetR();
			const AS_z      stub_z    = stub.GetZ();
			const AS_phi    stub_phi  = stub.GetPhi();
			const AS_bend   stub_bend = stub.GetBend();

			//----- Projection parameters
			const PROJ_PHI  proj_phi  = proj.GetPhi();
			const PROJ_Z    proj_z    = proj.GetZ();
			const PROJ_PHID proj_phid = proj.GetPhiDeriv();
			const PROJ_ZD   proj_zd   = proj.GetZDeriv();

			// write out parameters for debugging
			std::cout << "Stub: " << stub.raw() << " " << stub_r   << " " << stub_z << " " << stub_phi  << " " << stub_bend << std::endl;
			std::cout << "Proj: " << proj.raw() << " " << proj_phi << " " << proj_z << " " << proj_phid << " " << proj_zd   << std::endl;

			//----- Do the full match calculations

			// get full phi and z corrections
			// corrections are signed (both stub_r and proj_phid / proj_zd are signed)
			// For L3:  stub_r (7b), proj_phid  (11 b), proj_zd (10b) -> 18b for multiplication
			ap_int<18> full_phi_corr = stub_r * proj_phid;
			ap_int<18> full_z_corr   = stub_r * proj_zd;

			// shift full corrections by appropriate number of bits (still signed)
			// For L3: phi_corr_shift = 5, z_corr_shift = 6 -> phi_corr (18-5 = 13b), z_corr (18-6 = 12b)
			ap_int<13> phi_corr      = full_phi_corr >> phi_corr_shift;
			ap_int<12> z_corr        = full_z_corr >> z_corr_shift;

			// corrected values for comparisons (signed because corrections are signed)
			// For L3: proj_phi (14b), phi_corr (13b) -> stub_phi_corr (15b)
			// For L3: proj_z (12b), z_corr (12b)     -> proj_z_corr (13b)
			ap_int<15> proj_phi_corr = proj_phi + phi_corr; // original stub phi plus the phi correction
			ap_int<13> proj_z_corr   = proj_z + z_corr;     // original projection z plus the z correction

			// get differences between projection and stub values (signed)
			// For L3: delta_z (12b - 13b)
			// For L3: delta_phi (14b << 3) - (14b << (1-1+3)) = 17b - 17b;
			// For L3: dz_fact (13b * 1)
			// absolute value of deltas have same number of bits, but unsigned
			ap_int<13> delta_z        = stub_z - proj_z_corr;
			ap_int<13> delta_z_fact   = delta_z*fact;
			ap_int<17> delta_phi      = (stub_phi << phi0_shift) - (proj_phi_corr << (shift_phi0bit -1 + phi0_shift));
			ap_uint<13> abs_delta_z   = iabs< 13 >( delta_z_fact );
			ap_uint<17> abs_delta_phi = iabs< 17 >( delta_phi );

			//----- Apply cuts

			bool pass_match = false;
			//if (abs_delta_phi <= matchcut_phi[layer][seed] && abs_delta_z <= matchcut_z[layer][seed]) pass_match = true;
			ap_uint<13> best_delta_z   = matchcut_z[layer][seed];
			ap_uint<17> best_delta_phi = matchcut_phi[layer][seed];

			if ((abs_delta_z <= best_delta_z) && (abs_delta_phi <= abs_delta_phi)){
				pass_match     = true;
				best_delta_z   = abs_delta_z;
				best_delta_phi = abs_delta_phi;
			}
			else pass_match = false;

			//----- Write out the FullMatch

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
	}// end CM_LOOP

	//---- Write out the number of FMs made (needed for next module)
	n_FM_PHI1 = curr_FM;

};
