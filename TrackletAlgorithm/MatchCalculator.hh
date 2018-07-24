// First attempt at the MatchCalculator module
//
// Assumptions:
//
//
#include "ap_int.h"
#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"
#include "HLSFullMatch.hh"

using namespace std;

// MC constants
const int shift_rinvd      		= 19;
const int shift_phi0bit    		= 1;
const int shift_rinvbit    		= 13;
const int shift_phidbit    		= 7;
const int shift_PS_zd      		= -7;
const int shift_2S_zd      		= -7;
const int bits_stub_phi_L456	= 17;
const int bits_proj_z_L123 		= 12;
const int bits_proj_z_L456 		= 8;
const int bits_r_L123      		= 7;
const int bits_r_L456      		= 7;
const int bits_z_L123 	   		= 12;

// r and z correction shifts
const int fact_L123             = 1;
const int phi0_shift_L123       = 3;
const int phi_corr_shift_L123   = 5 + shift_rinvd + shift_phi0bit - shift_rinvbit - shift_phidbit;
const int z_corr_shift_L123     = -1-shift_PS_zd;
const int fact_L456             = (1 << (bits_proj_z_L123-bits_proj_z_L456));
const int phi0_shift_L456       = 0;
const int phi_corr_shift_L456   = phi_corr_shift_L123 - (10-bits_r_L456);
const int z_corr_shift_L456     = -1-shift_2S_zd + (bits_proj_z_L123 - bits_proj_z_L456 + bits_r_L456 - bits_r_L123);

// doubles needed to make the MC cuts
const double zlength		   	= 120;
const double kphi1            	= 2*3.14/((0.75*27)*(1<<bits_stub_phi_L456));
const double kz               	= 2*zlength/(1<<bits_z_L123);
const double rmean[6]         	= {25.1493,37.468,52.5977,68.7737,86.0591,110.844};

// phi cuts for each seeding and layer
const int cut_p_L3L4_L1 = 0.07/(kphi1*rmean[0]);
const int cut_p_L5L6_L1	= 0.08/(kphi1*rmean[0]);
const int cut_p_D1D2_L1 = 0.07/(kphi1*rmean[0]);
const int cut_p_D3D4_L1 = 0.05/(kphi1*rmean[0]);
const int cut_p_L2D1_L1 = 0.05/(kphi1*rmean[0]);
const int cut_p_L3L4_L2 = 0.06/(kphi1*rmean[1]);
const int cut_p_L5L6_L2 = 0.08/(kphi1*rmean[1]);
const int cut_p_D1D2_L2 = 0.05/(kphi1*rmean[1]);
const int cut_p_L1L2_L3 = 0.10/(kphi1*rmean[2]);
const int cut_p_L5L6_L3 = 0.08/(kphi1*rmean[2]);
const int cut_p_L1L2_L4 = 0.19/(kphi1*rmean[3]);
const int cut_p_L5L6_L4 = 0.05/(kphi1*rmean[3]);
const int cut_p_L1L2_L5 = 0.40/(kphi1*rmean[4]);
const int cut_p_L3L4_L5 = 0.08/(kphi1*rmean[4]);
const int cut_p_L1L2_L6 = 0.50/(kphi1*rmean[5]);
const int cut_p_L3L4_L6 = 0.19/(kphi1*rmean[5]);

// z cuts for each seeding and layer
const int cut_z_L3L4_L1 =  5.5/kz;
const int cut_z_L5L6_L1 = 15.0/kz;
const int cut_z_D1D2_L1 =  1.5/kz;
const int cut_z_D3D4_L1 =  2.0/kz;
const int cut_z_L2D1_L1 =  1.5/kz;
const int cut_z_L3L4_L2 =  3.5/kz;
const int cut_z_L5L6_L2 = 15.0/kz;
const int cut_z_D1D2_L2 = 1.25/kz;
const int cut_z_L1L2_L3 =  0.7/kz;
const int cut_z_L5L6_L3 =  9.0/kz;
const int cut_z_L1L2_L4 =  3.0/kz;
const int cut_z_L5L6_L4 =  7.0/kz;
const int cut_z_L1L2_L5 =  3.0/kz;
const int cut_z_L3L4_L5 =  8.0/kz;
const int cut_z_L1L2_L6 =  4.0/kz;
const int cut_z_L3L4_L6 =  9.5/kz;


// setup constants based on which seeding and which layer
// MC cuts are constants by [layer] and [seeding]
// [layer]: 0 = L1, 1 = L2, 2 = L3, 3 = L4, 4 = L5, 5 = L6
// [seeding]:  0 = L1L2, 1 = L3L4, 2 = L5L6, 3 = D1D2, 4 = D3D4, 5 = L1D1, 6 = L2D1

const int matchcut_phi[6][7] = {
		{-1,            cut_p_L3L4_L1, cut_p_L5L6_L1, cut_p_D1D2_L1, cut_p_D3D4_L1, -1, cut_p_L2D1_L1},
		{-1,            cut_p_L3L4_L2, cut_p_L5L6_L2, cut_p_D1D2_L2, -1,            -1, -1},
		{cut_p_L1L2_L3, -1,            cut_p_L5L6_L3, -1,            -1,            -1, -1},
		{cut_p_L1L2_L4, -1,            cut_p_L5L6_L4, -1,            -1,            -1, -1},
		{cut_p_L1L2_L5, cut_p_L3L4_L5, -1,            -1,            -1,            -1, -1},
		{cut_p_L1L2_L6, cut_p_L3L4_L6, -1,            -1,            -1,            -1, -1}
};
const int matchcut_z[6][7] = {
		{-1,            cut_z_L3L4_L1, cut_z_L5L6_L1, cut_z_D1D2_L1, cut_z_D3D4_L1, -1, cut_z_L2D1_L1},
		{-1,            cut_z_L3L4_L2, cut_z_L5L6_L2, cut_z_D1D2_L2, -1,            -1, -1},
		{cut_z_L1L2_L3, -1,            cut_z_L5L6_L3, -1,            -1,            -1, -1},
		{cut_z_L1L2_L4, -1,            cut_z_L5L6_L4, -1,            -1,            -1, -1},
		{cut_z_L1L2_L5, cut_z_L3L4_L5, -1,            -1,            -1,            -1, -1},
		{cut_z_L1L2_L6, cut_z_L3L4_L6, -1,            -1,            -1,            -1, -1}
};


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
    );
