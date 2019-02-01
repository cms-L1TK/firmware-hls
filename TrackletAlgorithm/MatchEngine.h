#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "Constants.hh"
#include "VMProjectionMemory.hh"
#include "CandidateMatchMemory.hh"
#include "VMStubMEMemory.hh"


void MatchEngine(const BXType  bx,
		 const VMStubMEMemory* const instubdata, 
		 const VMProjectionMemory* const inprojdata,
		 CandidateMatchMemory* const outcanddata
		 );

#endif
