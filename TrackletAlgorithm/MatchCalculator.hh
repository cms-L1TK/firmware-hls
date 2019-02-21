#ifndef MATCHCALCULATOR_HH
#define MATCHCALCULATOR_HH

// MatchCalculator

#include "Constants.hh"
#include "CandidateMatchMemory.hh"
#include "AllStubMemory.hh"
#include "AllProjectionMemory.hh"
#include "FullMatchMemory.hh"


//////////////////////////////////////////////////////////////

// Absolute value template

template< int width >
ap_uint<width> iabs( ap_int<width> value )
{
	ap_uint<width> absval;
	if (value < 0) absval = -value;
	else           absval = value;
	return absval;
};

//////////////////////////////////////////////////////////////

// Template to get look up tables

// Table for phi or z cuts
template<bool phi, int L, int width, int depth>
void readTable_Cuts(ap_uint<width> table[depth]){
  if (phi){ // phi cuts
    if (L==1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L1PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L2PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L4PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L5PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L6PHIC_phicut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
  } // end phi cuts
  else { // z cuts
    if (L==1){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L1PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==2){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L2PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==3){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L3PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==4){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L4PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==5){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L5PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else if (L==6){
      ap_uint<width> tmp[depth] =
#include "../emData/MC/MC_L3PHIC/MC_L6PHIC_zcut.tab"
      for (int i = 0; i < depth; i++) table[i] = tmp[i];
    }
    else {
      static_assert(true, "Only LAYERS 1 to 6 are valid");
    }
 
  }

} // end readTable_Cuts


//////////////////////////////////////////////////////////////

// MatchCalculator

template<regionType ASTYPE, regionType APTYPE, regionType FMTYPE,
         int LAYER=0, int DISK=0, int PHISEC=0>
void MatchCalculator(BXType bx,
                     const CandidateMatchMemory* const match1,
                     const CandidateMatchMemory* const match2,
                     const CandidateMatchMemory* const match3,
                     const CandidateMatchMemory* const match4,
                     const CandidateMatchMemory* const match5,
                     const CandidateMatchMemory* const match6,
                     const CandidateMatchMemory* const match7,
                     const CandidateMatchMemory* const match8,
                     const AllStubMemory<ASTYPE>* const allstub,
                     const AllProjectionMemory<APTYPE>* const allproj,
                     BXType& bx_o,
                     FullMatchMemory<FMTYPE>* const fullmatch1,
                     FullMatchMemory<FMTYPE>* const fullmatch2
){

  // Reset output memories
  fullmatch1->clear(bx);
  fullmatch2->clear(bx);

  // Initialization
 
  // Setup constants depending on which layer/disk working on
  // probably should move these to constants file
  ap_uint<4> kNbitszprojL123 = 12; // nbitszprojL123 in emulation (defined in constants) 
  ap_uint<4> kNbitszprojL456 = 8;  // nbitszprojL456 in emulation (defined in constants)
  ap_uint<5> kNbitsdrinv = 19;     // idrinvbits     in emulation (defined in constants)
  ap_uint<4> kShift_Rinv = 13;     // rinvbitshift   in emulation (defined in constants)
  ap_uint<3> kShift_Phider = 7;    // phiderbitshift in emulation (defined in constants)
  ap_uint<3> kNbitsrL123 = 7;      // nbitsrL123     in emulation (defined in constants)
  ap_uint<3> kNbitsrL456 = 7;      // nbitsrL456     in emulation (defined in constants) 
  ap_int<4>  kShift_PS_zderL = -7; // PS_zderL_shift in emulation (defined in constants)
  ap_int<4>  kShift_2S_zderL = -7; // SS_zderL_shift in emulation (defined in constants)

  auto kFact               = (1 <= LAYER <= 3)? 1 : (1<<(kNbitszprojL123-kNbitszprojL456));                             // fact_ in emulation defined in MC
  auto kPhi0_shift         = (1 <= LAYER <= 3)? 3 : 0;                                                                  // phi0shift_ in emulation defined in MC
  auto kShift_phi0bit      = 1;                                                                                         // phi0bitshift in emulation defined in constants
  ap_uint<10> kPhi_corr_shift_L123 = 7 + kNbitsdrinv + kShift_phi0bit - kShift_Rinv - kShift_Phider;                    // icorrshift for L123
  ap_uint<10> kPhi_corr_shift_L456 = kPhi_corr_shift_L123 - 10 - kNbitsrL456;                                           // icorrshift for L456
  auto kPhi_corr_shift      = (1 <= LAYER <= 3)? kPhi_corr_shift_L123 : kPhi_corr_shift_L456;                           // icorrshift_ in emulation
  ap_uint<10> kZ_corr_shiftL123 = (-1-kShift_PS_zderL);                                                                 // icorzshift for L123 (6 in L3)
  ap_uint<10> kZ_corr_shiftL456 = (-1-kShift_2S_zderL + kNbitszprojL123 - kNbitszprojL456 + kNbitsrL456 - kNbitsrL123); // icorzshift for L456
  auto kZ_corr_shift       = (1 <= LAYER <= 3)? kZ_corr_shiftL123 : kZ_corr_shiftL456;                                  // icorzshift_ in emulation

  // Setup look up tables for match cuts
  ap_uint<17> LUT_matchcut_phi[7];
  readTable_Cuts<true,LAYER,17,7>(LUT_matchcut_phi);
  ap_uint<13> LUT_matchcut_z[7];
  readTable_Cuts<false,LAYER,13,7>(LUT_matchcut_z);

  // Pick up number of candidate matches for each CM memory
  ap_uint<kNBits_MemAddr> ncm1 = match1->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm2 = match2->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm3 = match3->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm4 = match4->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm5 = match5->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm6 = match6->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm7 = match7->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm8 = match8->getEntries(bx);

  // Count up total number of CMs *and protect incase of overflow)
  ap_uint<7> ncm;
  if (ncm1+ncm2+ncm3+ncm4+ncm5+ncm6+ncm7+ncm8 > kMaxProc) ncm = kMaxProc;
  else ncm = ncm1+ncm2+ncm3+ncm4+ncm5+ncm6+ncm7+ncm8;

   // Initialize read addresses for candidate matches
  ap_uint<kNBits_MemAddr> addr1 = 0;  
  ap_uint<kNBits_MemAddr> addr2 = 0;  
  ap_uint<kNBits_MemAddr> addr3 = 0;  
  ap_uint<kNBits_MemAddr> addr4 = 0;  
  ap_uint<kNBits_MemAddr> addr5 = 0;  
  ap_uint<kNBits_MemAddr> addr6 = 0;  
  ap_uint<kNBits_MemAddr> addr7 = 0;  
  ap_uint<kNBits_MemAddr> addr8 = 0; 

   // Setup candidate match data stream that goes into match calculations
  CandidateMatch datastream = CandidateMatch();

  // Setup dummy index to be used in the comparison
  CandidateMatch::CMProjIndex dummy = -1; 

  // Bool and ID needed for determining if processing a new tracklet
  bool newtracklet = true;
  CandidateMatch::CMProjIndex id[kMaxProc];

  // Initialize MC delta phi cut variables
  ap_uint<17> best_delta_phi;

  // Full match shift register to store best match
  bool goodmatch[kMaxProc];
  typename AllProjection<APTYPE>::AProjTCSEED projseed[kMaxProc];
  FullMatch<FMTYPE> bestmatch[kMaxProc];

  // Bool to signal last processing
  bool last = false;

  // Processing starts
  MC_LOOP: for (ap_uint<kNBits_MemAddr> istep = 0; istep < kMaxProc; istep++)
  {
    
    if (istep==(kMaxProc-1) || istep==(ncm-1)) last = true;
    else last = false;

    if (istep < ncm){
      // Read in each candidate match
      const CandidateMatch &cm1 = match1->read_mem(bx,addr1); 
      const CandidateMatch &cm2 = match2->read_mem(bx,addr2); 
      const CandidateMatch &cm3 = match3->read_mem(bx,addr3); 
      const CandidateMatch &cm4 = match4->read_mem(bx,addr4); 
      const CandidateMatch &cm5 = match5->read_mem(bx,addr5); 
      const CandidateMatch &cm6 = match6->read_mem(bx,addr6); 
      const CandidateMatch &cm7 = match7->read_mem(bx,addr7); 
      const CandidateMatch &cm8 = match8->read_mem(bx,addr8); 

      // Pick up the projection indices
      auto id1 = (addr1 < ncm1) ? cm1.getProjIndex() : dummy; 
      auto id2 = (addr2 < ncm2) ? cm2.getProjIndex() : dummy; 
      auto id3 = (addr3 < ncm3) ? cm3.getProjIndex() : dummy; 
      auto id4 = (addr4 < ncm4) ? cm4.getProjIndex() : dummy; 
      auto id5 = (addr5 < ncm5) ? cm5.getProjIndex() : dummy; 
      auto id6 = (addr6 < ncm6) ? cm6.getProjIndex() : dummy; 
      auto id7 = (addr7 < ncm7) ? cm7.getProjIndex() : dummy; 
      auto id8 = (addr8 < ncm8) ? cm8.getProjIndex() : dummy; 

      // Sorted merge of incomming candidate matches
      // Do comparison of projection (ie. tracklet) indices to decide which data to send first
      // Then increment the address of which ever data has just been read
      if (id1 <= id2 and id1 <= id3 and id1 <= id4 and id1 <= id5 and id1 <= id6 and id1 <= id7 and id1 <= id8){
        datastream = cm1;
        addr1++; 
      }
      else if (id2 <= id1 and id2 <= id3 and id2 <= id4 and id2 <= id5 and id2 <= id6 and id2 <= id7 and id2 <= id8){
        datastream = cm2;
        addr2++; 
      }
      else if (id3 <= id1 and id3 <= id2 and id3 <= id4 and id3 <= id5 and id3 <= id6 and id3 <= id7 and id3 <= id8){
        datastream = cm3;
        addr3++; 
      }
      else if (id4 <= id1 and id4 <= id2 and id4 <= id3 and id4 <= id5 and id4 <= id6 and id4 <= id7 and id4 <= id8){
        datastream = cm4;
        addr4++; 
      }
      else if (id5 <= id1 and id5 <= id2 and id5 <= id3 and id5 <= id4 and id5 <= id6 and id5 <= id7 and id5 <= id8){
        datastream = cm5;
        addr5++; 
      }
      else if (id6 <= id1 and id6 <= id2 and id6 <= id3 and id6 <= id4 and id6 <= id5 and id6 <= id7 and id6 <= id8){
        datastream = cm6;
        addr6++; 
      }
      else if (id7 <= id1 and id7 <= id2 and id7 <= id3 and id7 <= id4 and id7 <= id5 and id7 <= id6 and id7 <= id8){
        datastream = cm7;
        addr7++; 
      }
      else if (id8 <= id1 and id8 <= id2 and id8 <= id3 and id8 <= id4 and id8 <= id5 and id8 <= id6 and id8 <= id7){
        datastream = cm8;
        addr8++; 
      }
      else {
        datastream = CandidateMatch();
      }

       // Extract the stub and projection indices from the candidate match
       auto projid = datastream.getProjIndex();
       auto stubid = datastream.getStubIndex();
       // Use the stub and projection indices to pick up the stub and projection
       AllProjection<APTYPE> proj = allproj->read_mem(bx,projid);
       AllStub<ASTYPE>       stub = allstub->read_mem(bx,stubid); 

       // Check if processing a new tracklet or not 
       // Later we only want to store the single best match per tracklet
       id[istep] = projid;
       if (istep==0) newtracklet = true;
       else if (id[istep] != id[istep-1]) newtracklet = true;
       else newtracklet = false; 

       // Stub parameters
       typename AllStub<ASTYPE>::ASR    stub_r    = stub.getR();
       typename AllStub<ASTYPE>::ASZ    stub_z    = stub.getZ();
       typename AllStub<ASTYPE>::ASPHI  stub_phi  = stub.getPhi();
       typename AllStub<ASTYPE>::ASBEND stub_bend = stub.getBend();       

       // Projection parameters
       typename AllProjection<APTYPE>::AProjTCID          proj_tcid = proj.getTCID();
       typename AllProjection<APTYPE>::AProjTrackletIndex proj_tkid = proj.getTrackletIndex();
       typename AllProjection<APTYPE>::AProjTCSEED        proj_seed = proj.getSeed();
       typename AllProjection<APTYPE>::AProjPHI           proj_phi  = proj.getPhi();
       typename AllProjection<APTYPE>::AProjRZ            proj_z    = proj.getRZ();
       typename AllProjection<APTYPE>::AProjPHIDER        proj_phid = proj.getPhiDer();
       typename AllProjection<APTYPE>::AProjRZDER         proj_zd   = proj.getRZDer(); 

       // Calculate residuals
       // Get phi and z correction
       ap_int<22> full_phi_corr = stub_r * proj_phid; // full corr has enough bits for full multiplication
       ap_int<18> full_z_corr   = stub_r * proj_zd;   // full corr has enough bits for full multiplication
       ap_int<11> phi_corr      = full_phi_corr >> kPhi_corr_shift;                        // only keep needed bits
       ap_int<12> z_corr        = (full_z_corr + (1<<(kZ_corr_shift-1))) >> kZ_corr_shift; // only keep needed bits
        
       // Apply the corrections
       ap_int<15> proj_phi_corr = proj_phi + phi_corr;  // original proj phi plus phi correction
       ap_int<13> proj_z_corr   = proj_z + z_corr;      // original proj z plus z correction

       // Get phi and z difference between the projection and stub
       ap_int<9> delta_z         = stub_z - proj_z_corr;
       ap_int<13> delta_z_fact   = delta_z * kFact;
       ap_int<18> stub_phi_long  = stub_phi;         // make longer to allow for shifting
       ap_int<18> proj_phi_long  = proj_phi_corr;    // make longer to allow for shifting
       ap_int<18> shiftstubphi   = stub_phi_long << kPhi0_shift;                        // shift
       ap_int<18> shiftprojphi   = proj_phi_long << (kShift_phi0bit - 1 + kPhi0_shift); // shift
       ap_int<17> delta_phi      = shiftstubphi - shiftprojphi;
       ap_uint<13> abs_delta_z   = iabs<13>( delta_z_fact ); // absolute value of delta z
       ap_uint<17> abs_delta_phi = iabs<17>( delta_phi );    // absolute value of delta phi

       // Best match logic block
       goodmatch[istep] = false;
       // For first tracklet, pick up the phi cut value
       if (newtracklet) best_delta_phi = LUT_matchcut_phi[proj_seed];

       // Check that matches fall within the selection window of the projection 
       if ((abs_delta_z <= LUT_matchcut_z[proj_seed]) && (abs_delta_phi <= best_delta_phi)){
    	 // Update values of best phi parameters, so that the next match
         // will be compared to this value instead of the original selection cut
         best_delta_phi = abs_delta_phi;

         // Full match parameters
         typename FullMatch<FMTYPE>::FMTCID          fm_tcid  = proj_tcid;
         typename FullMatch<FMTYPE>::FMTrackletIndex fm_tkid  = proj_tkid;
         typename FullMatch<FMTYPE>::FMSTUBPHIID     fm_asphi = PHISEC;
         typename FullMatch<FMTYPE>::FMSTUBID        fm_asid  = stubid;
         typename FullMatch<FMTYPE>::FMPHIRES        fm_phi   = delta_phi;
         typename FullMatch<FMTYPE>::FMZRES          fm_z     = delta_z;
         FullMatch<FMTYPE> fm(fm_tcid,fm_tkid,fm_asphi,fm_asid,fm_phi,fm_z);

         // Store bestmatch
         bestmatch[istep] = fm.raw();
         goodmatch[istep] = true;
         projseed[istep]  = proj_seed;
       }
       else if (newtracklet){ // if is a new tracklet, do not make a match because it didn't pass the cuts
    	 goodmatch[istep] = false;
    	 bestmatch[istep] = FullMatch<FMTYPE>();
    	 projseed[istep]  = 0;
       }
	   else { // if current match did not pass, but it is not a new tracklet, keep the previous best match for that tracklet
		 goodmatch[istep] = goodmatch[istep-1];
		 bestmatch[istep] = bestmatch[istep-1].raw();
		 projseed[istep]  = projseed[istep-1];
       }

       // Write out only the best match, based on the seeding
       if (newtracklet){ // if there is a new tracklet write out the best match for the previous tracklet
         if (goodmatch[istep-1]==true && projseed[istep-1]==0) fullmatch1->write_mem(bx,bestmatch[istep-1]);
         if (goodmatch[istep-1]==true && projseed[istep-1]==2) fullmatch2->write_mem(bx,bestmatch[istep-1]);
	   }
       if (last){ // if this is the last iteration of loop, write out the current best also
    	 if (goodmatch[istep]==true && projseed[istep]==0) fullmatch1->write_mem(bx,bestmatch[istep]);
    	 if (goodmatch[istep]==true && projseed[istep]==2) fullmatch2->write_mem(bx,bestmatch[istep]);
       }

     }
     else break; // end processing of CMs
  }// end MC_LOOP 

}// end MatchCalculator

#endif
 
