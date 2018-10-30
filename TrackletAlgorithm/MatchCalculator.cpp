// First attempt at the MatchCalculator module
// 
// Assumptions:
//   Only working for LAYER 3 (this affects the bit size of various parameters)
//
// FIXME :
//   * Allow for other layers / disk calculations
//   * counters for CMs in and FMs out should be shortened (right now 32b ints)
//   * Setup the constants at compile instead of during running

#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"
#include "HLSFullMatch.hh"
#include "MatchCalculator.hh"
#include "ap_int.h"
#include "hls_stream.h"
#include "Tools.hh"

void MatchCalculator(
	const int layer,                           // make parameter ?
    HLSCandidateMatch CM_PHI1_PHI1[MAX_nCM],   // input
	HLSCandidateMatch CM_PHI1_PHI2[MAX_nCM],   // input
	HLSCandidateMatch CM_PHI1_PHI3[MAX_nCM],   // input
	HLSCandidateMatch CM_PHI1_PHI4[MAX_nCM],   // input
    const ap_uint<7> n_CM_PHI1_PHI1,           // input
	const ap_uint<7> n_CM_PHI1_PHI2,           // input
	const ap_uint<7> n_CM_PHI1_PHI3,           // input
	const ap_uint<7> n_CM_PHI1_PHI4,           // input
	HLSAllStubs   AS_PHI1[MAX_nSTUB],          // input
	HLSProjection Proj_PHI1[MAX_nPROJ],        // input
	HLSFullMatch  FM_seed0[MAX_nFM],           // output
	HLSFullMatch  FM_seed1[MAX_nFM],           // output
	HLSFullMatch  FM_seed2[MAX_nFM],           // output
	HLSFullMatch  FM_seed3[MAX_nFM],           // output
	HLSFullMatch  FM_seed4[MAX_nFM],           // output
	HLSFullMatch  FM_seed5[MAX_nFM],           // output
	HLSFullMatch  FM_seed6[MAX_nFM],           // output
	ap_uint<7> & n_FM_seed0,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed1,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed2,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed3,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed4,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed5,                   // output (7b allows for up to 64 FMs)
	ap_uint<7> & n_FM_seed6                    // output (7b allows for up to 64 FMs)
){

#pragma HLS PIPELINE II=36
#pragma HLS latency max=60

	// Bool to keep track if working on a new tracklet (for best match logic)
    bool newtracklet = true;

	// Current FM counter -- used to write out n_FM made
	ap_uint<7> curr_FM = 0;
	ap_uint<7> curr_FM0 = 0;
	ap_uint<7> curr_FM1 = 0;
	ap_uint<7> curr_FM2 = 0;
	ap_uint<7> curr_FM3 = 0;
	ap_uint<7> curr_FM4 = 0;
	ap_uint<7> curr_FM5 = 0;
	ap_uint<7> curr_FM6 = 0;

	// Total number of CMs coming in
	ap_uint<7> n_CM   = n_CM_PHI1_PHI1 + n_CM_PHI1_PHI2 + n_CM_PHI1_PHI3 + n_CM_PHI1_PHI4;
	//#pragma HLS RESOURCE variable=n_CM core=AddSub

	// Setup the phi and z correction shifts
	int fact = 0;
	int phi0_shift = 0;
	int phi_corr_shift = 0;
	int z_corr_shift = 0;
	setup_shifts<2>(fact,phi0_shift,phi_corr_shift,z_corr_shift);

	ap_uint<13> best_delta_z;
	ap_uint<17> best_delta_phi;

	ap_uint<12> data1 = 0;
	ap_uint<12> data2 = 0;
	ap_uint<12> data3 = 0;
	ap_uint<12> data4 = 0;

	ap_uint<7> addr1 = 0;
	ap_uint<7> addr2 = 0;
	ap_uint<7> addr3 = 0;
	ap_uint<7> addr4 = 0;

	ap_uint<12> dataout = -1;
	ap_uint<12> dumby   = 0;
	ap_uint<6>  dumbyid = -1;

	ap_uint<6> id[MAX_nCM];

	hls::stream< ap_uint<12> > out;
	ap_uint<3> state = 0;
	#pragma HLS STREAM depth=1 variable=out
	//#pragma HLS RESOURCE variable=out latency=2

	//----- Merge and sort the incoming CMs
	LOOP: for (int i = 0; i < MAX_nCM; ++i)
	{
	#pragma HLS PIPELINE II=1

		if (i < n_CM){

			// pick up the data
			data1 = CM_PHI1_PHI1[addr1].raw(); //(addr1 < n_CM_PHI1_PHI1) ? CM_PHI1_PHI1[addr1].raw() : dumby;
			data2 = CM_PHI1_PHI2[addr2].raw(); //(addr2 < n_CM_PHI1_PHI2) ? CM_PHI1_PHI2[addr2].raw() : dumby;
			data3 = CM_PHI1_PHI2[addr2].raw(); //(addr3 < n_CM_PHI1_PHI3) ? CM_PHI1_PHI3[addr3].raw() : dumby;
			data4 = CM_PHI1_PHI2[addr2].raw(); //(addr4 < n_CM_PHI1_PHI4) ? CM_PHI1_PHI4[addr4].raw() : dumby;

			// pick up the indices
			ap_uint<6> id1 = data1.range(11,6);
			ap_uint<6> id2 = data2.range(11,6);
			ap_uint<6> id3 = data3.range(11,6);
			ap_uint<6> id4 = data4.range(11,6);

			// indices for comparison
			ap_uint<6> index1 = (addr1 < n_CM_PHI1_PHI1) ? id1 : dumbyid;
			ap_uint<6> index2 = (addr2 < n_CM_PHI1_PHI2) ? id2 : dumbyid;
			ap_uint<6> index3 = (addr3 < n_CM_PHI1_PHI3) ? id3 : dumbyid;
			ap_uint<6> index4 = (addr4 < n_CM_PHI1_PHI4) ? id4 : dumbyid;

			// do comparison to decide which data to send out
			// increment the address of which data
			if (index1 <= index2 and index1 <= index3 and index1 <= index4){
				dataout = data1;
				addr1++;
			}
			else if (index2 <= index1 and index2 <= index3 and index2 <= index4){
				dataout = data2;
				addr2++;
			}
			else if (index2 <= index1 and index2 <= index3 and index2 <= index4){
				dataout = data3;
				addr3++;
			}
			else if (index4 <= index1 and index4 <= index2 and index4 <= index3){
				dataout = data4;
				addr4++;
			}
			else{
				dataout = 0;
			}

			//----- Check if processing a new tracklet or not (needed for determining best match)
			id[i] = dataout.range(11,6);
			if (i==0){ newtracklet = true; }
			else if (id[i]!=id[i-1]){ newtracklet = true; }
			else {  newtracklet = false; }

			//----- Merged data stream
			out.write(dataout);

			//----- Calculate matches (using the tmp_CM array from above)
			//
			// loop over candidate matches
			// up to the max number MAX_nCM the module can handle
			// pick up corresponding stub and projection
			// calculate z and phi corrections
			// check that residuals pass the cuts
			// and save the final match
			//

			ap_uint<12> outraw;
			out.read_nb(outraw);
			HLSCandidateMatch streamed = HLSCandidateMatch(outraw);

			//----- Extract the CM parameters (indices of stub & projection)
			CM_proj_index p_index     = streamed.GetPIndex();
			CM_stub_index s_index     = streamed.GetSIndex();
       
			//----- Use the indices to pick up the stub and projection
			HLSAllStubs     stub      = AS_PHI1[s_index];
			HLSProjection   proj      = Proj_PHI1[p_index];

			//----- Stub parameters
			const AS_r      stub_r    = stub.GetR();
			const AS_z      stub_z    = stub.GetZ();
			const AS_phi    stub_phi  = stub.GetPhi();
			const AS_bend   stub_bend = stub.GetBend();

			//----- Projection parameters
			// FIXME: Projection format here is OLD!!! Seed
			const PROJ_TCID  proj_tcid = proj.GetTCID();
			const ap_uint<3> proj_seed = proj_tcid.range(5,4); // old definition of tcid should be (6,4)
			const ap_uint<4> proj_vm   = proj_tcid.range(3,0);
			const PROJ_TCNUM proj_num  = proj.GetIndex();
			const PROJ_PHI  proj_phi   = proj.GetPhi();
			const PROJ_Z    proj_z     = proj.GetZ();
			const PROJ_PHID proj_phid  = proj.GetPhiDeriv();
			const PROJ_ZD   proj_zd    = proj.GetZDeriv();

			// write out parameters for debugging
			std::cout << "Stub: " << stub.raw() << " " << stub_r   << " " << stub_z << " " << stub_phi  << " " << stub_bend << std::endl;
		    std::cout << "Proj: " << proj.raw() << " " << proj_seed << " " << proj_phi << " " << proj_z << " " << proj_phid << " " << proj_zd   << std::endl;
		    std::cout << "PROJ (ID,SEED,VM,NUM): " << proj_tcid << " " << proj_seed << " " << proj_vm << " " << proj_num << std::endl;

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
			// For all matches (not just best) :
			//if (abs_delta_phi <= matchcut_phi[layer][seed] && abs_delta_z <= matchcut_z[layer][seed]) pass_match = true;

			// If the seed and layer combination is not valid then cut is 0
			//ap_uint<13> best_delta_z   = matchcut_z[layer][proj_seed];
			//ap_uint<17> best_delta_phi = matchcut_phi[layer][proj_seed];
			if (newtracklet){
				best_delta_z   = matchcut_z[layer][proj_seed];
				best_delta_phi = matchcut_phi[layer][proj_seed];
			}

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

				// FIXME: Not all of these seeding combinations are valid for each layer make extra ones synthesize away.
				// For L3 only L1L2 and L5L6 seeding are valid combinations -- make others null pointers so go away?
				if (proj_seed==0){ FM_seed0[curr_FM0].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM0++;} // seed L1L2
				if (proj_seed==1){ FM_seed1[curr_FM1].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM1++;} // seed L3L4
				if (proj_seed==2){ FM_seed2[curr_FM2].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM2++;} // seed L5L6
				if (proj_seed==3){ FM_seed3[curr_FM3].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM3++;} // seed D1D2
				if (proj_seed==4){ FM_seed4[curr_FM4].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM4++;} // seed D3D4
				if (proj_seed==5){ FM_seed5[curr_FM5].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM5++;} // seed L1D1
				if (proj_seed==6){ FM_seed6[curr_FM6].AddFM(fm_p_index,fm_s_index,fm_phi,fm_z); curr_FM6++;} // seed L2D1
				curr_FM++;
				std::cout << "Full Match out : " << FM_seed0[curr_FM0-1].raw() << std::endl;
				std::cout << "Parameters     : " << FM_seed0[curr_FM0-1].GetPIndex() << " " << FM_seed0[curr_FM0-1].GetSIndex() << " " << FM_seed0[curr_FM0-1].GetPhi() << " " << FM_seed0[curr_FM0-1].GetZ() << std::endl;
			}

		}// end if (i < n_CM)
		else break; // don't process more CMs than you have
	}// end CM_LOOP

	//---- Write out the number of FMs made (needed for next module)
	n_FM_seed0 = curr_FM0;
	n_FM_seed1 = curr_FM1;
	n_FM_seed2 = curr_FM2;
	n_FM_seed3 = curr_FM3;
	n_FM_seed4 = curr_FM4;
	n_FM_seed5 = curr_FM5;
	n_FM_seed6 = curr_FM6;

};
