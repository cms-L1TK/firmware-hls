#ifndef MATCHCALCULATOR_H
#define MATCHCALCULATOR_H

#include "Constants.hh"
#include "CandidateMatchMemory.hh"
#include "AllStubMemory.hh"
#include "AllProjectionMemory.hh"
#include "FullMatchMemory.hh"

void MatchCalculator(const BXType  bx,
                     const CandidateMatchMemory* const incmdata1,
                     const CandidateMatchMemory* const incmdata2,
                     const CandidateMatchMemory* const incmdata3,
                     const CandidateMatchMemory* const incmdata4,
                     const CandidateMatchMemory* const incmdata5,
                     const CandidateMatchMemory* const incmdata6,
                     const CandidateMatchMemory* const incmdata7,
                     const CandidateMatchMemory* const incmdata8,
                     const AllProjectionMemory* const inprojdata, 
                     const AllStubMemory* const instubdata,
                     FullMatchMemory* const outfmdata1,
                     FullMatchMemory* const outfmdata2);

#endif
