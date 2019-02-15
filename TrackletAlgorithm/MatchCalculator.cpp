#include "MatchCalculator.hh"
#include "hls_math.h"
#include <iostream>
#include <fstream>

//-----------------------------------------------------------------------------------------
// --------------------------------- FIXME ------------------------------------------------
// Merger needs to be re-thought
// More output FM memories? and have null pointers for ones not needed in each instance 
//-----------------------------------------------------------------------------------------

void MatchCalculator(const BXType bx,
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
                     FullMatchMemory* const outfmdata2
){

  //#pragma HLS PIPELINE II=72
  //#pragma HLS latency max=90

  // Clear memory for each BX
  outfmdata1->clear();
  outfmdata2->clear();     

  // Pick up number of candidate matches for each CM memory
  ap_uint<kNBits_MemAddr> ncm1 = incmdata1->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm2 = incmdata2->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm3 = incmdata3->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm4 = incmdata4->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm5 = incmdata5->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm6 = incmdata6->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm7 = incmdata7->getEntries(bx);
  ap_uint<kNBits_MemAddr> ncm8 = incmdata8->getEntries(bx);

  // Count up total number of CMs and protect in the case of overflow)
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
  AllProjection::AProjTCSEED projseed[kMaxProc];
  FullMatch bestmatch[kMaxProc];
  #pragma HLS ARRAY_PARTITION variable=goodmatch complete dim=1
  #pragma HLS ARRAY_PARTITION variable=projseed  complete dim=1
  #pragma HLS ARRAY_PARTITION variable=bestmatch complete dim=1

  // Bool to signal last processing
  bool last = false;

  // Processing starts
  MC_LOOP: for (ap_uint<kNBits_MemAddr> istep = 0; istep < kMaxProc; istep++)
  {

  #pragma HLS PIPELINE II=1

	 if (istep==(kMaxProc-1)) last = true;
	 else                     last = false;

     if (istep < ncm){
       // Read in each candidate match
       const CandidateMatch &cm1 = incmdata1->read_mem(bx,addr1); 
       const CandidateMatch &cm2 = incmdata2->read_mem(bx,addr2); 
       const CandidateMatch &cm3 = incmdata3->read_mem(bx,addr3); 
       const CandidateMatch &cm4 = incmdata4->read_mem(bx,addr4); 
       const CandidateMatch &cm5 = incmdata5->read_mem(bx,addr5); 
       const CandidateMatch &cm6 = incmdata6->read_mem(bx,addr6); 
       const CandidateMatch &cm7 = incmdata7->read_mem(bx,addr7); 
       const CandidateMatch &cm8 = incmdata8->read_mem(bx,addr8); 

       // Pick up the projection indices
       CandidateMatch::CMProjIndex id1 = (addr1 < ncm1) ? cm1.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id2 = (addr2 < ncm2) ? cm2.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id3 = (addr3 < ncm3) ? cm3.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id4 = (addr4 < ncm4) ? cm4.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id5 = (addr5 < ncm5) ? cm5.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id6 = (addr6 < ncm6) ? cm6.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id7 = (addr7 < ncm7) ? cm7.getProjIndex() : dummy; 
       CandidateMatch::CMProjIndex id8 = (addr8 < ncm8) ? cm8.getProjIndex() : dummy; 

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
       CandidateMatch::CMProjIndex projid = datastream.getProjIndex();
       CandidateMatch::CMStubIndex stubid = datastream.getStubIndex();
       // Use the stub and projection indices to pick up the stub and projection
       const AllProjection &proj = inprojdata->read_mem(bx,projid);
       const AllStub       &stub = instubdata->read_mem(bx,stubid); 

       // Check if processing a new tracklet or not 
       // Later we only want to store the single best match per tracklet
       id[istep] = projid;
       if (istep==0) newtracklet = true;
       else if (id[istep] != id[istep-1]) newtracklet = true;
       else newtracklet = false; 

       // Stub parameters
       AllStub::ASR    stub_r    = stub.getR();
       AllStub::ASZ    stub_z    = stub.getZ();
       AllStub::ASPHI  stub_phi  = stub.getPhi();
       AllStub::ASBEND stub_bend = stub.getBend();       

       // Projection parameters
       AllProjection::AProjTCID   proj_tcid = proj.getTrackletIndex();
       AllProjection::AProjTCSEED proj_seed = proj.getSeed();
       AllProjection::AProjPHI    proj_phi  = proj.getPhi();
       AllProjection::AProjZ      proj_z    = proj.getZ();
       AllProjection::AProjPHIDER proj_phid = proj.getPhiDer();
       AllProjection::AProjZDER   proj_zd   = proj.getZDer(); 

       if (debug){
         std::cout << "i " << istep << std::endl;
      	 if (newtracklet) std::cout << "----- New tracklet -----" << std::endl;
         std::cout << "CM params (ProjID,StubID): " << projid << " " << stubid << std::endl;
    	 std::cout << "AS params (r,z,phi,bend): " << stub_r << " " << stub_z << " " << stub_phi << " " << stub_bend << " " << std::endl;
    	 std::cout << "AP params (TCID,seed,phi,z,phid,zd): " << proj_tcid << " " << proj_seed << " " << proj_phi << " " << proj_z << " " << proj_phid << " " << proj_zd << std::endl;
       }

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

       if (debug){
    	 std::cout << "Deltas (Phi, Z): " << delta_phi << " " << delta_z << std::endl;
         std::cout << "AbsDelta(Phi,Z): " << abs_delta_phi << " " << abs_delta_z << std::endl;
       }

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
         FullMatch::FMTCID      fm_tcid  = proj_tcid;
         FullMatch::FMSTUBPHIID fm_asphi = kPhiSector;
         FullMatch::FMSTUBID    fm_asid  = stubid;
         FullMatch::FMPHIRES    fm_phi   = delta_phi;
         FullMatch::FMZRES      fm_z     = delta_z;
         FullMatch fm(fm_tcid,fm_asphi,fm_asid,fm_phi,fm_z);

         // Store bestmatch
         bestmatch[istep] = fm.raw();
         goodmatch[istep] = true;
         projseed[istep]  = proj_seed;
       }
       else if (newtracklet){ // if is a new tracklet, do not make a match because it didn't pass the cuts
    	 goodmatch[istep] = false;
    	 bestmatch[istep] = FullMatch();
    	 projseed[istep]  = 0;
       }
	   else { // if current match did not pass, but it is not a new tracklet, keep the previous best match for that tracklet
		 goodmatch[istep] = goodmatch[istep-1];
		 bestmatch[istep] = bestmatch[istep-1].raw();
		 projseed[istep]  = projseed[istep-1];
       }

       if (debug){
         std::cout << "Best match: " << goodmatch[istep] << " " << projseed[istep] << " " << bestmatch[istep].raw() << std::endl;
         std::cout << "FM params (TCID,ASID,phi,z): " << bestmatch[istep].getTrackletIndex() << " " << bestmatch[istep].getStubIndex()
           << " " << bestmatch[istep].getPhiRes() << " " << bestmatch[istep].getZRes() << std::endl;
       }

       // Write out only the best match, based on the seeding
       if (newtracklet){ // if there is a new tracklet write out the best match for the previous tracklet
         if (goodmatch[istep-1]==true && projseed[istep-1]==0) outfmdata1->write_mem(bx,bestmatch[istep-1]);
         if (goodmatch[istep-1]==true && projseed[istep-1]==2) outfmdata2->write_mem(bx,bestmatch[istep-1]);
	   }
     }
     // Write out the match from the last CM
     else if (istep==ncm){
       if (goodmatch[istep-1]==true && projseed[istep-1]==0) outfmdata1->write_mem(bx,bestmatch[istep-1]);
       if (goodmatch[istep-1]==true && projseed[istep-1]==2) outfmdata2->write_mem(bx,bestmatch[istep-1]);
     }
     else break; // end processing of CMs
  }// end MC_LOOP

  // Write out the match from the last possible output
  if (last){
    if (goodmatch[kMaxProc-1]==true && projseed[kMaxProc-1]==0) outfmdata1->write_mem(bx,bestmatch[kMaxProc-1]);
    if (goodmatch[kMaxProc-1]==true && projseed[kMaxProc-1]==2) outfmdata2->write_mem(bx,bestmatch[kMaxProc-1]);
  }

}

