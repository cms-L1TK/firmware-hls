#ifndef TrackletAlgorithm_MatchCalculatorTop_h
#define TrackletAlgorithm_MatchCalculatorTop_h

#include "MatchCalculator.h"


constexpr int L1PHIAmaxMatchCopies(4);
constexpr int L1PHIAmaxFullMatchCopies(8);

void MatchCalculator_L1PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIAmaxFullMatchCopies]
);

constexpr int L1PHIBmaxMatchCopies(4);
constexpr int L1PHIBmaxFullMatchCopies(8);

void MatchCalculator_L1PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIBmaxFullMatchCopies]
);

constexpr int L1PHICmaxMatchCopies(4);
constexpr int L1PHICmaxFullMatchCopies(8);

void MatchCalculator_L1PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L1PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHICmaxFullMatchCopies]
);

constexpr int L1PHIDmaxMatchCopies(4);
constexpr int L1PHIDmaxFullMatchCopies(8);

void MatchCalculator_L1PHID(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIDmaxFullMatchCopies]
);

constexpr int L1PHIEmaxMatchCopies(4);
constexpr int L1PHIEmaxFullMatchCopies(8);

void MatchCalculator_L1PHIE(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIEmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIEmaxFullMatchCopies]
);

constexpr int L1PHIFmaxMatchCopies(4);
constexpr int L1PHIFmaxFullMatchCopies(8);

void MatchCalculator_L1PHIF(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIFmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIFmaxFullMatchCopies]
);

constexpr int L1PHIGmaxMatchCopies(4);
constexpr int L1PHIGmaxFullMatchCopies(8);

void MatchCalculator_L1PHIG(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIGmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIGmaxFullMatchCopies]
);

constexpr int L1PHIHmaxMatchCopies(4);
constexpr int L1PHIHmaxFullMatchCopies(8);

void MatchCalculator_L1PHIH(
    const BXType bx,
    const CandidateMatchMemory match[L1PHIHmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L1PHIHmaxFullMatchCopies]
);

constexpr int L2PHIAmaxMatchCopies(8);
constexpr int L2PHIAmaxFullMatchCopies(8);

void MatchCalculator_L2PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIAmaxFullMatchCopies]
);

constexpr int L2PHIBmaxMatchCopies(8);
constexpr int L2PHIBmaxFullMatchCopies(8);

void MatchCalculator_L2PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIBmaxFullMatchCopies]
);

constexpr int L2PHICmaxMatchCopies(8);
constexpr int L2PHICmaxFullMatchCopies(8);

void MatchCalculator_L2PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L2PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHICmaxFullMatchCopies]
);

constexpr int L2PHIDmaxMatchCopies(8);
constexpr int L2PHIDmaxFullMatchCopies(8);

void MatchCalculator_L2PHID(
    const BXType bx,
    const CandidateMatchMemory match[L2PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L2PHIDmaxFullMatchCopies]
);

constexpr int L3PHIAmaxMatchCopies(8);
constexpr int L3PHIAmaxFullMatchCopies(8);

void MatchCalculator_L3PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIAmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIAmaxFullMatchCopies]
);

constexpr int L3PHIBmaxMatchCopies(8);
constexpr int L3PHIBmaxFullMatchCopies(8);

void MatchCalculator_L3PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIBmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIBmaxFullMatchCopies]
);

constexpr int L3PHICmaxMatchCopies(8);
constexpr int L3PHICmaxFullMatchCopies(8);

void MatchCalculator_L3PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L3PHICmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHICmaxFullMatchCopies]
);

constexpr int L3PHIDmaxMatchCopies(8);
constexpr int L3PHIDmaxFullMatchCopies(8);

void MatchCalculator_L3PHID(
    const BXType bx,
    const CandidateMatchMemory match[L3PHIDmaxMatchCopies],
    const AllStubMemory<BARRELPS>* allstub,
    const AllProjectionMemory<BARRELPS>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L3PHIDmaxFullMatchCopies]
);

constexpr int L4PHIAmaxMatchCopies(8);
constexpr int L4PHIAmaxFullMatchCopies(8);

void MatchCalculator_L4PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L4PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIAmaxFullMatchCopies]
);

constexpr int L4PHIBmaxMatchCopies(8);
constexpr int L4PHIBmaxFullMatchCopies(8);

void MatchCalculator_L4PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L4PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIBmaxFullMatchCopies]
);

constexpr int L4PHICmaxMatchCopies(8);
constexpr int L4PHICmaxFullMatchCopies(8);

void MatchCalculator_L4PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L4PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHICmaxFullMatchCopies]
);

constexpr int L4PHIDmaxMatchCopies(8);
constexpr int L4PHIDmaxFullMatchCopies(8);

void MatchCalculator_L4PHID(
    const BXType bx,
    const CandidateMatchMemory match[L4PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L4PHIDmaxFullMatchCopies]
);

constexpr int L5PHIAmaxMatchCopies(8);
constexpr int L5PHIAmaxFullMatchCopies(8);

void MatchCalculator_L5PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L5PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIAmaxFullMatchCopies]
);

constexpr int L5PHIBmaxMatchCopies(8);
constexpr int L5PHIBmaxFullMatchCopies(8);

void MatchCalculator_L5PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L5PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIBmaxFullMatchCopies]
);

constexpr int L5PHICmaxMatchCopies(8);
constexpr int L5PHICmaxFullMatchCopies(8);

void MatchCalculator_L5PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L5PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHICmaxFullMatchCopies]
);

constexpr int L5PHIDmaxMatchCopies(8);
constexpr int L5PHIDmaxFullMatchCopies(8);

void MatchCalculator_L5PHID(
    const BXType bx,
    const CandidateMatchMemory match[L5PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L5PHIDmaxFullMatchCopies]
);

constexpr int L6PHIAmaxMatchCopies(8);
constexpr int L6PHIAmaxFullMatchCopies(8);

void MatchCalculator_L6PHIA(
    const BXType bx,
    const CandidateMatchMemory match[L6PHIAmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIAmaxFullMatchCopies]
);

constexpr int L6PHIBmaxMatchCopies(8);
constexpr int L6PHIBmaxFullMatchCopies(8);

void MatchCalculator_L6PHIB(
    const BXType bx,
    const CandidateMatchMemory match[L6PHIBmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIBmaxFullMatchCopies]
);

constexpr int L6PHICmaxMatchCopies(8);
constexpr int L6PHICmaxFullMatchCopies(8);

void MatchCalculator_L6PHIC(
    const BXType bx,
    const CandidateMatchMemory match[L6PHICmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHICmaxFullMatchCopies]
);

constexpr int L6PHIDmaxMatchCopies(8);
constexpr int L6PHIDmaxFullMatchCopies(8);

void MatchCalculator_L6PHID(
    const BXType bx,
    const CandidateMatchMemory match[L6PHIDmaxMatchCopies],
    const AllStubMemory<BARREL2S>* allstub,
    const AllProjectionMemory<BARREL2S>* allproj,
    BXType& bx_o,
    FullMatchMemory<BARREL> fullmatch[L6PHIDmaxFullMatchCopies]
);

#endif
