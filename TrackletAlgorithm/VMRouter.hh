// VMRouter
// Log
// -------

// First tracklet 2.0 version -- December 2018 -- wittich

#pragma once
#include "ap_int.h"

#include "Constants.hh"
#include "InputStubMemory.hh"
#include "AllStubMemory.hh"
#include "VMStubMEMemory.hh"
#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"

void VMRouter(
		const int layer_, const int disk_, const bool isPSmodule,
		const BXType bx,
		const InputStubMemory<BARRELPS>* const a0,
		const InputStubMemory<BARRELPS>* const a1,
		const InputStubMemory<BARRELPS>* const a2,
		const InputStubMemory<BARRELPS>* const a3,
		const InputStubMemory<BARRELPS>* const a4,
		AllStubMemory<BARRELPS>* allstub,
		ap_uint<32> memask,
              VMStubMEMemory<BARRELPS> *m0,
              VMStubMEMemory<BARRELPS> *m1,
              VMStubMEMemory<BARRELPS> *m2,
              VMStubMEMemory<BARRELPS> *m3,
              VMStubMEMemory<BARRELPS> *m4,
              VMStubMEMemory<BARRELPS> *m5,
              VMStubMEMemory<BARRELPS> *m6,
              VMStubMEMemory<BARRELPS> *m7,
              VMStubMEMemory<BARRELPS> *m8,
              VMStubMEMemory<BARRELPS> *m9,
              VMStubMEMemory<BARRELPS> *m10,
              VMStubMEMemory<BARRELPS> *m11,
              VMStubMEMemory<BARRELPS> *m12,
              VMStubMEMemory<BARRELPS> *m13,
              VMStubMEMemory<BARRELPS> *m14,
              VMStubMEMemory<BARRELPS> *m15,
              VMStubMEMemory<BARRELPS> *m16,
              VMStubMEMemory<BARRELPS> *m17,
              VMStubMEMemory<BARRELPS> *m18,
              VMStubMEMemory<BARRELPS> *m19,
              VMStubMEMemory<BARRELPS> *m20,
              VMStubMEMemory<BARRELPS> *m21,
              VMStubMEMemory<BARRELPS> *m22,
              VMStubMEMemory<BARRELPS> *m23,
              VMStubMEMemory<BARRELPS> *m24,
              VMStubMEMemory<BARRELPS> *m25,
              VMStubMEMemory<BARRELPS> *m26,
              VMStubMEMemory<BARRELPS> *m27,
              VMStubMEMemory<BARRELPS> *m28,
              VMStubMEMemory<BARRELPS> *m29,
              VMStubMEMemory<BARRELPS> *m30,
              VMStubMEMemory<BARRELPS> *m31);
