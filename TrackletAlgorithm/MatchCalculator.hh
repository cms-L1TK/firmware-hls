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
const double zlength		   	= 120.0;
const double kphi1            	= 2*3.14/((0.75*27)*(1<<bits_stub_phi_L456));
const double kz               	= 2*zlength/(1<<bits_z_L123);
const double rmean[6]         	= {25.1493,37.468,52.5977,68.7737,86.0591,110.844};
const double kphiproj123        = 0.0000626264;
const double rmaxdisk           = 120.0;
const int    nrbitsdisk         = 12;
const double kr                 = rmaxdisk/(1<<nrbitsdisk);
const double krprojshiftdisk    = 0.0585938;

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

// phi cuts for each seeding and disk (also split PS/2S)
// PS
const int cut_p_L1L2_D1_PS = 0.20/(kphiproj123*kr);
const int cut_p_D3D4_D1_PS = 0.10/(kphiproj123*kr);
const int cut_p_L1L2_D2_PS = 0.20/(kphiproj123*kr);
const int cut_p_D3D4_D2_PS = 0.10/(kphiproj123*kr);
const int cut_p_L1D1_D2_PS = 0.10/(kphiproj123*kr);
const int cut_p_L2D1_D2_PS = 0.10/(kphiproj123*kr);
const int cut_p_L1L2_D3_PS = 0.25/(kphiproj123*kr);
const int cut_p_D1D2_D3_PS = 0.15/(kphiproj123*kr);
const int cut_p_L1D1_D3_PS = 0.20/(kphiproj123*kr);
const int cut_p_L2D1_D3_PS = 0.15/(kphiproj123*kr);
const int cut_p_L1L2_D4_PS = 0.50/(kphiproj123*kr);
const int cut_p_D1D2_D4_PS = 0.20/(kphiproj123*kr);
const int cut_p_L1D1_D4_PS = 0.30/(kphiproj123*kr);
const int cut_p_L2D1_D4_PS = 0.50/(kphiproj123*kr);
const int cut_p_D1D2_D5_PS = 0.25/(kphiproj123*kr);
const int cut_p_D3D4_D5_PS = 0.10/(kphiproj123*kr);
const int cut_p_L1D1_D5_PS = 0.50/(kphiproj123*kr);

// 2S
const int cut_p_L1L2_D1_2S = 0.50/(kphiproj123*kr);
const int cut_p_L3L4_D1_2S = 0.80/(kphiproj123*kr);
const int cut_p_L1L2_D2_2S = 0.50/(kphiproj123*kr);
const int cut_p_L3L4_D2_2S = 0.80/(kphiproj123*kr);
const int cut_p_L1D1_D2_2S = 0.50/(kphiproj123*kr);
const int cut_p_L2D1_D2_2S = 0.15/(kphiproj123*kr);
const int cut_p_L1L2_D3_2S = 0.50/(kphiproj123*kr);
const int cut_p_D1D2_D3_2S = 0.15/(kphiproj123*kr);
const int cut_p_L1D1_D3_2S = 0.20/(kphiproj123*kr);
const int cut_p_L2D1_D3_2S = 0.25/(kphiproj123*kr);
const int cut_p_L1L2_D4_2S = 0.50/(kphiproj123*kr);
const int cut_p_D1D2_D4_2S = 0.20/(kphiproj123*kr);
const int cut_p_L1D1_D4_2S = 0.25/(kphiproj123*kr);
const int cut_p_L2D1_D4_2S = 0.50/(kphiproj123*kr);
const int cut_p_D1D2_D5_2S = 0.40/(kphiproj123*kr);
const int cut_p_D3D4_D5_2S = 0.20/(kphiproj123*kr);
const int cut_p_L1D1_D5_2S = 0.40/(kphiproj123*kr);

// r cuts for each seeding and disk (also split PS/2S)
// PS
const int cut_r_L1L2_D1_PS = 0.5/krprojshiftdisk;
const int cut_r_D3D4_D1_PS = 0.5/krprojshiftdisk;
const int cut_r_L1L2_D2_PS = 0.5/krprojshiftdisk;
const int cut_r_D3D4_D2_PS = 0.5/krprojshiftdisk;
const int cut_r_L1D1_D2_PS = 0.5/krprojshiftdisk;
const int cut_r_L2D1_D2_PS = 0.5/krprojshiftdisk;
const int cut_r_L1L2_D3_PS = 0.5/krprojshiftdisk;
const int cut_r_D1D2_D3_PS = 0.5/krprojshiftdisk;
const int cut_r_L1D1_D3_PS = 0.6/krprojshiftdisk;
const int cut_r_L2D1_D3_PS = 0.8/krprojshiftdisk;
const int cut_r_L1L2_D4_PS = 0.5/krprojshiftdisk;
const int cut_r_D1D2_D4_PS = 0.8/krprojshiftdisk;
const int cut_r_L1D1_D4_PS = 1.0/krprojshiftdisk;
const int cut_r_L2D1_D4_PS = 1.0/krprojshiftdisk;
const int cut_r_D1D2_D5_PS = 1.0/krprojshiftdisk;
const int cut_r_D3D4_D5_PS = 0.5/krprojshiftdisk;
const int cut_r_L1D1_D5_PS = 2.0/krprojshiftdisk;

// 2S
const int cut_r_L1L2_D1_2S = 3.8/krprojshiftdisk;
const int cut_r_L3L4_D1_2S = 3.8/krprojshiftdisk;
const int cut_r_L1L2_D2_2S = 3.8/krprojshiftdisk;
const int cut_r_L3L4_D2_2S = 3.8/krprojshiftdisk;
const int cut_r_L1D1_D2_2S = 3.8/krprojshiftdisk;
const int cut_r_L2D1_D2_2S = 3.4/krprojshiftdisk;
const int cut_r_L1L2_D3_2S = 3.6/krprojshiftdisk;
const int cut_r_D1D2_D3_2S = 3.6/krprojshiftdisk;
const int cut_r_L1D1_D3_2S = 3.6/krprojshiftdisk;
const int cut_r_L2D1_D3_2S = 3.8/krprojshiftdisk;
const int cut_r_L1L2_D4_2S = 3.6/krprojshiftdisk;
const int cut_r_D1D2_D4_2S = 3.6/krprojshiftdisk;
const int cut_r_L1D1_D4_2S = 3.5/krprojshiftdisk;
const int cut_r_L2D1_D4_2S = 3.8/krprojshiftdisk;
const int cut_r_D1D2_D5_2S = 3.6/krprojshiftdisk;
const int cut_r_D3D4_D5_2S = 3.4/krprojshiftdisk;
const int cut_r_L1D1_D5_2S = 3.7/krprojshiftdisk;


// setup constants based on which seeding and which layer
// MC cuts are constants by [layer] and [seeding]
// [layer]: 0 = L1, 1 = L2, 2 = L3, 3 = L4, 4 = L5, 5 = L6
// [seeding]:  0 = L1L2, 1 = L3L4, 2 = L5L6, 3 = D1D2, 4 = D3D4, 5 = L1D1, 6 = L2D1

static int matchcut_phi[6][7] = {
		{0,             cut_p_L3L4_L1, cut_p_L5L6_L1, cut_p_D1D2_L1, cut_p_D3D4_L1, 0, cut_p_L2D1_L1},
		{0,             cut_p_L3L4_L2, cut_p_L5L6_L2, cut_p_D1D2_L2, 0,             0, 0},
		{cut_p_L1L2_L3, 0,             cut_p_L5L6_L3, 0,             0,             0, 0},
		{cut_p_L1L2_L4, 0,             cut_p_L5L6_L4, 0,             0,             0, 0},
		{cut_p_L1L2_L5, cut_p_L3L4_L5, 0,             0,             0,             0, 0},
		{cut_p_L1L2_L6, cut_p_L3L4_L6, 0,             0,             0,             0, 0}
};
static int matchcut_z[6][7] = {
		{0,             cut_z_L3L4_L1, cut_z_L5L6_L1, cut_z_D1D2_L1, cut_z_D3D4_L1, 0, cut_z_L2D1_L1},
		{0,             cut_z_L3L4_L2, cut_z_L5L6_L2, cut_z_D1D2_L2, 0,             0, 0},
		{cut_z_L1L2_L3, 0,             cut_z_L5L6_L3, 0,             0,             0, 0},
		{cut_z_L1L2_L4, 0,             cut_z_L5L6_L4, 0,             0,             0, 0},
		{cut_z_L1L2_L5, cut_z_L3L4_L5, 0,             0,             0,             0, 0},
		{cut_z_L1L2_L6, cut_z_L3L4_L6, 0,             0,             0,             0, 0}
};

// setup constants based on which seeding and which layer
// MC cuts are constants by [disk] and [seeding]
// [disk]: 0 = D1, 1 = D2, 2 = D3, 3 = D4, 4 = D5
// [seeding]:  0 = L1L2, 1 = L3L4, 2 = L5L6, 3 = D1D2, 4 = D3D4, 5 = L1D1, 6 = L2D1

static int matchcut_phi_d_PS[5][7] = {
		{cut_p_L1L2_D1_PS, 0, 0, 0,                cut_p_D3D4_D1_PS, 0,                0},
		{cut_p_L1L2_D2_PS, 0, 0, 0,                cut_p_D3D4_D2_PS, cut_p_L1D1_D2_PS, cut_p_L2D1_D2_PS},
		{cut_p_L1L2_D3_PS, 0, 0, cut_p_D1D2_D3_PS, 0,                cut_p_L1D1_D3_PS, cut_p_L2D1_D3_PS},
		{cut_p_L1L2_D4_PS, 0, 0, cut_p_D1D2_D4_PS, 0,                cut_p_L1D1_D4_PS, cut_p_L2D1_D4_PS},
		{0,                0, 0, cut_p_D1D2_D5_PS, cut_p_D3D4_D5_PS, cut_p_L1D1_D5_PS, 0}
};
static int matchcut_phi_d_2S[5][7] = {
		{cut_p_L1L2_D1_2S, cut_p_L3L4_D1_2S, 0, 0,                0,                0,                0},
		{cut_p_L1L2_D2_2S, cut_p_L3L4_D2_2S, 0, 0,                0,                cut_p_L1D1_D2_2S, cut_p_L2D1_D2_2S},
		{cut_p_L1L2_D3_2S, 0,                0, cut_p_D1D2_D3_2S, 0,                cut_p_L1D1_D3_2S, cut_p_L2D1_D3_2S},
		{cut_p_L1L2_D4_2S, 0,                0, cut_p_D1D2_D4_2S, 0,                cut_p_L1D1_D4_2S, cut_p_L2D1_D4_2S},
		{0,                0,                0, cut_p_D1D2_D5_2S, cut_p_D3D4_D5_2S, cut_p_L1D1_D5_2S, 0}
};
static int matchcut_r_d_PS[5][7] = {
		{cut_r_L1L2_D1_PS, 0, 0, 0,                cut_r_D3D4_D1_PS, 0,                0},
		{cut_r_L1L2_D2_PS, 0, 0, 0,                cut_r_D3D4_D2_PS, cut_r_L1D1_D2_PS, cut_r_L2D1_D2_PS},
		{cut_r_L1L2_D3_PS, 0, 0, cut_r_D1D2_D3_PS, 0,                cut_r_L1D1_D3_PS, cut_r_L2D1_D3_PS},
		{cut_r_L1L2_D4_PS, 0, 0, cut_r_D1D2_D4_PS, 0,                cut_r_L1D1_D4_PS, cut_r_L2D1_D4_PS},
		{0,                0, 0, cut_r_D1D2_D5_PS, cut_r_D3D4_D5_PS, cut_r_L1D1_D5_PS, 0}
};
static int matchcut_r_d_2S[5][7] = {
		{cut_r_L1L2_D1_2S, cut_r_L3L4_D1_2S, 0, 0,                0,                0,                0},
		{cut_r_L1L2_D2_2S, cut_r_L3L4_D2_2S, 0, 0,                0,                cut_r_L1D1_D2_2S, cut_r_L2D1_D2_2S},
		{cut_r_L1L2_D3_2S, 0,                0, cut_r_D1D2_D3_2S, 0,                cut_r_L1D1_D3_2S, cut_r_L2D1_D3_2S},
		{cut_r_L1L2_D4_2S, 0,                0, cut_r_D1D2_D4_2S, 0,                cut_r_L1D1_D4_2S, cut_r_L2D1_D4_2S},
		{0,                0,                0, cut_r_D1D2_D5_2S, cut_r_D3D4_D5_2S, cut_r_L1D1_D5_2S, 0}
};

void MatchCalculator(
	const int layer,
    HLSCandidateMatch CM_PHI1_PHI1[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI2[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI3[MAX_nCM],
	HLSCandidateMatch CM_PHI1_PHI4[MAX_nCM],
    const ap_uint<7>  n_CM_PHI1_PHI1,
	const ap_uint<7>  n_CM_PHI1_PHI2,
	const ap_uint<7>  n_CM_PHI1_PHI3,
	const ap_uint<7>  n_CM_PHI1_PHI4,
	HLSAllStubs       AS_PHI1[MAX_nSTUB],
	HLSProjection     Proj_PHI1[MAX_nPROJ],
	HLSFullMatch      FM_seed0[MAX_nFM],
	HLSFullMatch      FM_seed1[MAX_nFM],
	HLSFullMatch      FM_seed2[MAX_nFM],
	HLSFullMatch      FM_seed3[MAX_nFM],
	HLSFullMatch      FM_seed4[MAX_nFM],
	HLSFullMatch      FM_seed5[MAX_nFM],
	HLSFullMatch      FM_seed6[MAX_nFM],
	ap_uint<7>        & n_FM_seed0,
	ap_uint<7>        & n_FM_seed1,
	ap_uint<7>        & n_FM_seed2,
	ap_uint<7>        & n_FM_seed3,
	ap_uint<7>        & n_FM_seed4,
	ap_uint<7>        & n_FM_seed5,
	ap_uint<7>        & n_FM_seed6
    );

template< int width >
ap_uint<width> iabs( ap_int<width> value )
{
	ap_uint<width> absval;
	if (value < 0) absval = -value;
	else           absval = value;
	return absval;
}


template< int layer >
void setup_shifts(int & fact, int & phi0_shift, int & phi_corr_shift, int & z_corr_shift)
{
	// Setup the r and z correction shifts
	fact           = (layer < 3)? fact_L123           : fact_L456;
	phi0_shift     = (layer < 3)? phi0_shift_L123     : phi0_shift_L456;
    phi_corr_shift = (layer < 3)? phi_corr_shift_L123 : phi_corr_shift_L456;
	z_corr_shift   = (layer < 3)? z_corr_shift_L123   : z_corr_shift_L456;
}

template< int seed, int layer >
void setup_cuts(ap_int<17> & phicut, ap_int<13> & zcut)
{
	phicut = matchcut_phi[layer][seed];
	zcut   = matchcut_z[layer][seed];
}
