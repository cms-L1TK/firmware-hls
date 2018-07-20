// First attempt at the MatchCalculator module
//
// Assumptions:
//
//
#ifndef __MC__
#define __MC__
#include "ap_int.h"
#include "HLSCandidateMatch.hh"
#include "HLSAllStubs.hh"
#include "HLSProjection.hh"

using namespace std;

//template< int S, int N >
void MatchCalculator(
    HLSCandidateMatch CM_PHI1_PHI1[MAX_nCM],
    const int n_CM_PHI1_PHI1,
	HLSAllStubs AS_PHI1[MAX_nSTUB],
	HLSProjection Proj_PHI1[MAX_nPROJ]
    //HLSCandidateMatch * CM_PHI1_PHI2,
    //HLSCandidateMatch * CM_PHI1_PHI3,
    //HLSCandidateMatch * CM_PHI1_PHI4	
    );
#endif
