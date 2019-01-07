// VMRouter
// Log
// -------
// First tracklet 2.0 version -- December 2018 -- wittich
#include "VMRouter.hh"
#include <cassert>

// I include this to get the constants. we should figure out if this is
// the right way to go.
//#include "MatchCalculator.hh"

constexpr double rmaxdisk           = 120.0;
constexpr int    nrbitsdisk         = 12;
constexpr double kr                 = rmaxdisk/(1<<nrbitsdisk);

// from FPGAConstants.hh -- needs a final home
constexpr unsigned int nallstubslayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmtelayers[6]={4,8,4,8,4,8};

constexpr unsigned int nallprojlayers[6]={8,4,4,4,4,4};
constexpr unsigned int nvmmelayers[6]={4,8,8,8,8,8};

constexpr unsigned int nallstubsdisks[5]={4,4,4,4,4};
constexpr unsigned int nvmmedisks[5]={4,4,4,4,4};



// from FPGAConstants
constexpr double rmindiskvm=22.5;
constexpr double rmaxdiskvm=67.0;

// ... 
// need separate lookup values for inner two vs outer three disks for 2S modules
// these assume D11 geometry!
constexpr double rDSSinner[10] = {66.7728, 71.7967, 77.5409, 82.5584, 84.8736, 89.8953, 95.7791, 100.798, 102.495, 107.52};  // <=== these 10 are for inner 2 disks
constexpr double rDSSouter[10] = {65.1694, 70.1936, 75.6641, 80.6908, 83.9581, 88.9827, 94.6539, 99.6772, 102.494, 107.519}; // <=== these 10 are for outer 3 disks

constexpr int kMaxFineBinTable = 256;



// TODO: fix the hacky underscores; probably pass in a pointer
// since we need to have different tables for different templated
// functions
// need to ensure this is recognized as a ROM
void init_finebintable(const int layer_, const int disk_,
		       int finebintable_[kMaxFineBinTable], int nbitsfinebintable_)
{
  // initialize
  for(auto i=0;i<kMaxFineBinTable;i++) {
    finebintable_[i] = -1;
  }

  if (layer_!=0) {
    nbitsfinebintable_=8;
    unsigned int nbins=1<<nbitsfinebintable_;

      
    for(unsigned int i=0;i<nbins;i++) {
      int ibin=(i>>(nbitsfinebintable_-3));
	
      int zfine=(i>>(nbitsfinebintable_-6))-(ibin<<3);
	
      //awkward bit manipulations since the index is from a signed number...
      int index=i+(1<<(nbitsfinebintable_-1));
	
      if (index>=(1<<nbitsfinebintable_)){
	index-=(1<<nbitsfinebintable_);
      }
	
      finebintable_[index]=zfine;
	
    }
  }

  if (disk_!=0) {

    nbitsfinebintable_=8;
    unsigned int nbins=1<<nbitsfinebintable_;
      
    for(unsigned int i=0;i<nbins;i++) {

      double rstub=0.0;
	
      if (i<10) {
	if (disk_<=2) {
	  rstub=rDSSinner[i];
	} else {
	  rstub=rDSSouter[i];
	}
      } else {
	rstub=kr*(i<<(nrbitsdisk-nbitsfinebintable_));
      }

      if (rstub<rmindiskvm) {
	finebintable_[i] = -1;
      } else {	
	int bin=8.0*(rstub-rmindiskvm)/(rmaxdisk-rmindiskvm);
	assert(bin>=0);
	//assert(bin<MEBinsDisks);
	int rfine=64*((rstub-rmindiskvm)-bin*(rmaxdisk-rmindiskvm)/8.0)/(rmaxdisk-rmindiskvm);
	finebintable_[i] = rfine;
      }
    }
  }
  
}


// local files
// returns top 5 bits of phi
inline ap_uint<5> iphivmRaw(const AllStub::ASPHI phi)
{
  // TODO: get rid of hard-coded values
  ap_uint<5> iphivm=phi.range(phi.length(), (phi.length()-5));
  assert(iphivm>=0 && iphivm<32); // get rid of this
  return iphivm;
}

// VMbits is the number of bits for the fine bins.
// E.g. 32 bins would use VMbits=5
// finebits is the number of bits within the VM
inline int iphivmFineBins(const AllStub::ASPHI phi, const int VMbits,
  const int finebits)
  {

    return (phi>>(phi.length()-VMbits-finebits))&((1<<finebits)-1);

  }


// Returns a number from 0 to 31. for both the plus and the minus:
// we add a small amount to the raw value; if it's not the same
// as the central value we copy the data to the adjacent memory as well.
inline
ap_uint<5> iphivmRawPlus(const AllStub::ASPHI phi)
{
  // TODO: get rid of hard-coded values
  auto iphivm=((phi+(1<<(phi.length()-7)))>>(phi.length()-5));
  if (iphivm<0) iphivm=0;
  else if (iphivm>31) iphivm=0;
  return ap_uint<5>(iphivm);

}

// see above
inline
ap_uint<5> iphivmRawMinus(const AllStub::ASPHI phi)
{
  // TODO: get rid of hard-coded values
  auto iphivm=((phi-(1<<(phi.length()-7)))>>(phi.length()-5));
  if (iphivm<0) iphivm=0;
  else if (iphivm>31) iphivm=0;
  return ap_uint<5>(iphivm);

}

constexpr int MAXVMROUTER = 64; // TODO need right symbol here

template <int layer_, int disk_, bool isPSmodule>
void VMRouter(const BXType bx,
	      const InputStubMemory* const a0,
	      const InputStubMemory* const a1,
	      const InputStubMemory* const a2,
	      const InputStubMemory* const a3,
	      const InputStubMemory* const a4,
	      AllStubMemory* allstub,
	      VMStubMEMemory *m0,
	      VMStubMEMemory *m1,
	      VMStubMEMemory *m2,
	      VMStubMEMemory *m3,
	      VMStubMEMemory *m4,
	      VMStubMEMemory *m5,
	      VMStubMEMemory *m6,
	      VMStubMEMemory *m7)
{

  // size of array here is the max possible value
  static int finebintable_[kMaxFineBinTable]; // lookup table - 2^nbinsfinbinetable entries actually filled
  static int nbitsfinebintable_ = 8; // this appears to always be 8
  static bool table_initialized = false;
  if ( ! table_initialized ) {
    init_finebintable(layer_,disk_,finebintable_,nbitsfinebintable_);
    table_initialized = true;
  }

  size_t count=0;
  int write_addr = 0;

  const auto n_A0 = a0->getEntries(bx);
  // need to figure out how to get the accurate total count of loop
  // iterations here for nested loops. Count in innermost loop?
  for(auto i = 0; i < kMaxProc; ++i ) {
    if ((count>MAXVMROUTER) || (i>n_A0 ))
      continue;
    ap_uint<kNBits_MemAddr> read_addr = i; // ??
    auto stub=a0->read_mem(bx, read_addr);

    // add stub to all stub memory (memories?)
    // HACK fix me
    AllStub allstubd(stub.raw());
    // END HACK
    allstub->write_mem(bx, allstubd);
    ++write_addr;


    count++;
    // executeME() START ------------------------------
    // hourglass only
    VMStubME stubme; stubme.setBend(stub.getBend());
    auto layer = layer_; // hack
    auto disk  = disk_; // hack --these are mutually exclusive so ...
    int nvm=-1;
    if (layer!=-1) {
      nvm=nallstubslayers[layer]*nvmmelayers[layer];
    }
    if (disk!=0){
      nvm=nallstubsdisks[disk-1]*nvmmedisks[disk-1];
    }
    auto iphiRaw = iphivmRaw(stub.getPhi());
    auto iphiRawPlus = iphivmRawPlus(stub.getPhi());
    auto iphiRawMinus = iphivmRawMinus(stub.getPhi());
    // TODO: comment this
    iphiRaw=iphiRaw/(32/nvm);
    iphiRawPlus=iphiRawPlus/(32/nvm);
    iphiRawMinus=iphiRawMinus/(32/nvm);
    if (iphiRawPlus<0) iphiRawPlus=0; // these are unsigned...
    else if (iphiRawPlus>=nvm) iphiRawPlus=nvm-1;
    if (iphiRawMinus<0) iphiRawMinus=0;
    else if (iphiRawMinus>=nvm) iphiRawMinus=nvm-1;

    if ( disk ) {
      VMStubME::VMSMEID index=stub.getR();
      // how to check this?
      if (isPSmodule) {
        index=stub.getR()>>(stub.getR().length()-nbitsfinebintable_);
      }

      auto rfine=finebintable_[index.to_int()];

      //assert(rfine>=0);
      stubme.setIndex(index);
      //stubme.setFineR(rfine); not yet
    }
    else { // layer
      VMStubME::VMSMEID index=(stub.getZ()>>(stub.getZ().length()-nbitsfinebintable_))&((1<<nbitsfinebintable_)-1);

      VMStubME::VMSMEFINEZ zfine=finebintable_[index.to_int()];

      stubme.setFineZ(zfine);
      stubme.setIndex(index);
    }
    // put in a bunch of enables to decide which memories to write
    // to.

    // now actually update the stubs in the new memories
    // based on the Verilog version by MEZ
    if ( iphiRaw == 0 || iphiRawMinus == 0 || iphiRawPlus == 0 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 1 || iphiRawMinus == 1 || iphiRawPlus == 1 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 2 || iphiRawMinus == 2 || iphiRawPlus == 2 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 3 || iphiRawMinus == 3 || iphiRawPlus == 3 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 4 || iphiRawMinus == 4 || iphiRawPlus == 4 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 5 || iphiRawMinus == 5 || iphiRawPlus == 5 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 6 || iphiRawMinus == 6 || iphiRawPlus == 6 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 7 || iphiRawMinus == 7 || iphiRawPlus == 7 ) {
    	m0->write_mem(bx,0, stubme);
    }
    if ( iphiRaw == 8 || iphiRawMinus == 8 || iphiRawPlus == 8 ) {
    	m0->write_mem(bx,0, stubme);
    }
    // executeME() END   ------------------------------

#ifdef NOTDEF
    if (disk_!=5) {
      executeTE(false); // TEOuter -- no overlap
    }
    if (layer_==1||layer_==2||disk_==1) {
      executeTE(true); // TEInner -- overlap
    }
#endif //
  } // outside loop



} // VMRouter



#if 0
void executeTE(bool overlap)
{


  unsigned int count=0;


  if (layer_!=0){  //First handle layer stubs

    for(unsigned int j=0;j<stubinputs_.size();j++){ // loop over layer stub inputs
      for(unsigned int i=0;i<stubinputs_[j]->nStubs();i++){ // loop over stubs in input
        count++;
        if (count>MAXVMROUTER) continue;
        //std::pair<FPGAStub*,L1TStub*> stub=stubinputs_[j]->getStub(i);
        auto stub(stubinputs_[j]->read_mem(bx,i));

        int iphiRaw=iphivmRaw(stub.getPhi());

        bool insert=false;


        int binlookup=-1;
        if (overlap) {
          static_assert(layer_==1||layer_==2);
          binlookup=lookupInnerOverlapLayer(stub);
        } else {
          switch (layer_) {
            case 2 :
            case 4 :
            case 6 :
            binlookup=lookupOuterLayer(stub);
            break;
            case 1 :
            case 3 :
            case 5 :
            binlookup=lookupInnerLayer(stub);
            break;
            default :
            assert(0); // FIXME
          }
        }
        if (binlookup==-1) continue;
        if (overlap) {
          stub.setVMBitsOverlap(binlookup);
        } else {
          stub.setVMBits(binlookup);
        }

        unsigned int layer=stub.layer().value();
        if (overlap) {
          iphiRaw=iphiRaw/(32/(nallstubsoverlaplayers[layer]*nvmteoverlaplayers[layer]));
          for (unsigned int l=0;l<vmstubsTEOverlapPHI_[iphiRaw].size();l++){
            vmstubsTEOverlapPHI_[iphiRaw][l]->addStub(stub);
            insert=true;
          }
        } else {
          iphiRaw=iphiRaw/(32/(nallstubslayers[layer]*nvmtelayers[layer]));
          for (unsigned int l=0;l<vmstubsTEPHI_[iphiRaw].size();l++){
            vmstubsTEPHI_[iphiRaw][l]->addStub(stub);
            insert=true;
          }
        }

      }
    }

  }

  if (disk_!=0) {
    for(unsigned int j=0;j<stubinputs_.size();j++){
      for(unsigned int i=0;i<stubinputs_[j]->nStubs();i++){
        std::pair<FPGAStub*,L1TStub*> stub=stubinputs_[j]->getStub(i);

        if (!stub.second->isPSmodule()) {
          continue;
        }

        int iphiRaw=iphivmRaw(stub.getPhi());

        bool insert=false;


        if (overlap) {

          int binlookup=lookupOuterOverlapD1(stub);
          //assert(binlookup>=0);
          stub.setVMBitsOverlap(binlookup);

          iphiRaw=iphiRaw/(32/(nallstubsoverlapdisks[0]*nvmteoverlapdisks[0]));

          for (unsigned int l=0;l<vmstubsTEOverlapPHI_[iphiRaw].size();l++){
            vmstubsTEOverlapPHI_[iphiRaw][l]->addStub(stub);
            insert=true;
          }

        } else {

          int binlookup=-1;

          if (!overlap) {
            switch (disk_) {
              case 2 :
              case 4 :
              binlookup=lookupOuterDisk(stub);
              break;
              case 1 :
              case 3 :
              binlookup=lookupInnerDisk(stub);
              break;
              default :
              assert(0);
            }
          } else {
            static_assert(disk_==1, "incorrect disk");
            binlookup=lookupOuterOverlapD1(stub);
          }

          if (binlookup==-1) continue;
          stub.setVMBits(binlookup);


          unsigned int disk=std::abs(stub.disk().value());
          iphiRaw=iphiRaw/(32/(nallstubsdisks[disk-1]*nvmtedisks[disk-1]));

          for (unsigned int l=0;l<vmstubsTEPHI_[iphiRaw].size();l++){
            if (debug1) {
              cout << getName()<<" added stub to : "<<vmstubsTEPHI_[iphiRaw][l]->getName()<<endl;
            }
            vmstubsTEPHI_[iphiRaw][l]->addStub(stub);
            insert=true;
          }

        }

        if (!insert) {
          cout << getName() << " did not insert stub"<<endl;
        }
        assert(insert);

      }
    }
  }

}


void executeME()
{

  unsigned int count=0;

  if (stubinputs_.size()!=0){
    for(unsigned int j=0;j<stubinputs_.size();j++){
      for(unsigned int i=0;i<stubinputs_[j]->nStubs();i++){
        count++;
        if (count>MAXVMROUTER) continue;
        //std::pair<FPGAStub*,L1TStub*> stub=stubinputs_[j]->getStub(i);
        auto stub = stubinputs_[j]->read_mem(bx,i);

        auto phi(stub.getPhi());

        int iphiRaw=stub.iphivmRaw();
        auto iphiRawPlus=stub.iphivmRawPlus();
        int iphiRawMinus=stub.iphivmRawMinus();

        int iphistub=iphiRaw;

        if (hourglass) {

          int layer=stub.layer().value();
          int disk=std::abs(stub.disk().value());


          int nvm=-1;
          if (layer!=-1) {
            nvm=nallstubslayers[layer]*nvmmelayers[layer];
          }
          if (disk!=0){
            nvm=nallstubsdisks[disk-1]*nvmmedisks[disk-1];
          }
          //assert(nvm>0&&nvm<=32);
          iphiRaw=iphiRaw/(32/nvm);
          iphiRawPlus=iphiRawPlus/(32/nvm);
          iphiRawMinus=iphiRawMinus/(32/nvm);
          if (iphiRawPlus<0) iphiRawPlus=0;
          if (iphiRawPlus>=nvm) iphiRawPlus=nvm-1;
          if (iphiRawMinus<0) iphiRawMinus=0;
          if (iphiRawMinus>=nvm) iphiRawMinus=nvm-1;

        } else {

          //assert(iphiRaw>=4 and iphiRaw<=27);


          iphiRaw-=4;
          iphiRaw=iphiRaw>>1;
          // assert(iphiRaw>=0);
          // assert(iphiRaw<=11);

          iphiRawPlus-=4;
          iphiRawPlus=iphiRawPlus>>1;
          if (iphiRawPlus<0) iphiRawPlus=0;
          if (iphiRawPlus>11) iphiRawPlus=11;

          iphiRawMinus-=4;
          iphiRawMinus=iphiRawMinus>>1;
          if (iphiRawMinus<0) iphiRawMinus=0;
          if (iphiRawMinus>11) iphiRawMinus=11;

        }

        // disk code
        if (disk_!=0) {

          auto r = stub.getR();
          auto index=r;
          if (stub.isPSmodule()) { // TODO fix this
            index=r>>(r.length()-nbitsfinebintable_);
          }

          int rfine=finebintable_[index];

          //assert(rfine>=0);

          stub.setfiner(rfine);

        }

        if (layer_!=0) {

          int index=(stub.z().value()>>(stub.z().nbits()-nbitsfinebintable_))&((1<<nbitsfinebintable_)-1);

          int zfine=finebintable_[index];

          stub.setfinez(zfine);

        }

        bool insert=false;


        for (unsigned int l=0;l<vmstubsMEPHI_[iphiRaw].size();l++){
          if (debug1) {
            cout << "FPGAVMRouterME "<<getName()<<" add stub ( r = "<<stub.second->r()<<" phi = "<<stub.second->phi()<<" ) in : "<<vmstubsMEPHI_[iphiRaw][l]->getName()<<" iphistub = " << iphistub << " iphivmRaw Minus Plus "<<stub.iphivmRaw()<<" "<<stub.iphivmRawMinus()<<" "<<stub.iphivmRawPlus()<<" bins "
            <<iphiRawMinus<<" "<<iphiRawPlus<<endl;
          }
          vmstubsMEPHI_[iphiRaw][l]->addStub(stub);
          insert=true;
        }

        if (iphiRaw!=iphiRawPlus) {
          for (unsigned int l=0;l<vmstubsMEPHI_[iphiRawPlus].size();l++){
            vmstubsMEPHI_[iphiRawPlus][l]->addStub(stub);
          }
        }
        if (iphiRaw!=iphiRawMinus) {
          for (unsigned int l=0;l<vmstubsMEPHI_[iphiRawMinus].size();l++){
            vmstubsMEPHI_[iphiRawMinus][l]->addStub(stub);
          }
        }

      }
    }

  }


}
#endif
