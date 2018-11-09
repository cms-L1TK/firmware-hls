#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "Constants.hh"
#include "VMProjectionMemory.hh"
#include "CandidateMatchMemory.hh"
#include "VMStubMemory.hh"


void MatchEngine(const BXType  bx,
		 const VMStubMemory* const instubdata, 
		 const VMProjectionMemory* const inprojdata,
		 CandidateMatchMemory* const outcanddata
		 );

#endif
