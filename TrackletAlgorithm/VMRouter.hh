// VMRouter
// Log
// -------

// First tracklet 2.0 version -- December 2018 -- wittich

#pragma once
#include "ap_int.h"

#include "InputStubMemory.hh"
#include "AllStubMemory.hh"
#include "VMStubMEMemory.hh"
#include "VMStubTEInnerMemory.hh"
#include "VMStubTEOuterMemory.hh"

void VMRouter(
		const int layer_, const int disk_, const bool isPSmodule,
		const BXType bx,
		const InputStubMemory* const a0,
		const InputStubMemory* const a1,
		const InputStubMemory* const a2,
		const InputStubMemory* const a3,
		const InputStubMemory* const a4,
		AllStubMemory* allstub,
		ap_uint<32> memask,
              VMStubMEMemory *m0,
              VMStubMEMemory *m1,
              VMStubMEMemory *m2,
              VMStubMEMemory *m3,
              VMStubMEMemory *m4,
              VMStubMEMemory *m5,
              VMStubMEMemory *m6,
              VMStubMEMemory *m7,
              VMStubMEMemory *m8,
              VMStubMEMemory *m9,
              VMStubMEMemory *m10,
              VMStubMEMemory *m11,
              VMStubMEMemory *m12,
              VMStubMEMemory *m13,
              VMStubMEMemory *m14,
              VMStubMEMemory *m15,
              VMStubMEMemory *m16,
              VMStubMEMemory *m17,
              VMStubMEMemory *m18,
              VMStubMEMemory *m19,
              VMStubMEMemory *m20,
              VMStubMEMemory *m21,
              VMStubMEMemory *m22,
              VMStubMEMemory *m23,
              VMStubMEMemory *m24,
              VMStubMEMemory *m25,
              VMStubMEMemory *m26,
              VMStubMEMemory *m27,
              VMStubMEMemory *m28,
              VMStubMEMemory *m29,
              VMStubMEMemory *m30,
              VMStubMEMemory *m31);
