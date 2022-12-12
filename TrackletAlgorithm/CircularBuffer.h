#ifndef TrackletAlgorithm_CircularBuffer_h
#define TrackletAlgorithm_CircularBuffer_h

// This circular buffer implements a memory in DRAM with caching of the
// next data to read in the buffer
// BufferWidth is the bit width of the words stored in the buffer
// AddressWidth is the widht of the address word
// If you write a new value you can read it on the next clock - but not on the
// same even if you write first and then read

//
// Usage:
// Call reset() at the start of each event
// Call loopInit() to cache state at the start of each processing loop
// You must read before writing in the processing loop
//
//
//
//

template <int BufferWidth, int AddressWidth, int NearFullCount>
class CircularBuffer {

 public:

  typedef ap_uint<BufferWidth> BUFFERWORD;
  //typedef ap_uint<BufferWidthProjSeq> BUFFERWORDPROJSEQ;
  typedef ap_uint<AddressWidth> ADDR;

  // Constructors
 CircularBuffer():
  writeptr_(0), readptr_(0), empty_(true)
    {
    }
	
  static const ap_uint<(1<<(2*AddressWidth))> nearFullInit() {

     ap_uint<(1<<(2*AddressWidth))> nearFulltmp;

    //Initialize nearFullLUT
    for(unsigned int iwrt=0; iwrt<(1<<AddressWidth); iwrt++) {
#pragma HLS unroll 
      for(unsigned int iread=0; iread<(1<<AddressWidth); iread++) {
#pragma HLS unroll 
	ADDR writeptr(iwrt);
	ADDR readptr(iread);
	nearFulltmp[(writeptr,readptr)] = false;
	for(unsigned i=1; i<NearFullCount; i++) {
#pragma HLS unroll 
	  if (writeptr+i == readptr) {
	    nearFulltmp[(writeptr, readptr)] = true;
	  }
	}
      }
    }
    return nearFulltmp;
  }

  void reset() {
    writeptr_ = 0;
    readptr_ = 0;
    empty_ = true;
  }

  void loopInit() {
    static const ap_uint<(1<<(2*AddressWidth))> nearFullLUT = nearFullInit();
    loopInitNearFull_ = nearFullLUT[(writeptr_, readptr_)];
  }

  void loopEnd() {
    //#pragma HLS dependence variable=buffer_ intra false
    //if (readptr_ != writeptr_) {
      readcache_ = buffer_[readptr_];
      //readcacheprojseq_ = bufferprojseq_[readptr_];
      //}
  }

  void inc() {
    if (empty_) {
      empty_ = false;
    } else {
      writeptr_++;
    }
  }

  void save(const BUFFERWORD word) {
    if (empty_) {
      nextword_ =  word;
      //nextwordprojseq_ =  projseq;
    } 
    buffer_[writeptr_] = word;
    //bufferprojseq_[writeptr_]=projseq;
  }

  void store(const BUFFERWORD word) {
    //#pragma HLS dependence variable=buffer_ intra false
    if (empty_) {
      //assert(writeptr_ == readptr_);
      nextword_ =  word;
      //nextwordprojseq_ =  projseq;
      empty_ = false;
    } else {
      buffer_[writeptr_]=word;
      //bufferprojseq_[writeptr_++]=projseq;
    }
  }

  BUFFERWORD peek() const {
    return nextword_;
  }

  //BUFFERWORDPROJSEQ peekprojseq() const {
  //  return nextwordprojseq_;
  // }

  BUFFERWORD read() {
    BUFFERWORD tmp = nextword_;
    //assert(!empty_);
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
      //nextwordprojseq_ = readcacheprojseq_;
      readptr_++;
    }
    return tmp;
  }

  void advance() {
    //assert(!empty_);
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
      //nextwordprojseq_ = readcacheprojseq_;
      readptr_++;
    }
  }

  bool full() const {
    ADDR writeptrnext = writeptr_+1;
    return writeptrnext == readptr_;
  }

  bool nearFull() const {
    return loopInitNearFull_;
  }

  bool empty() const {
    return empty_;
  }

  ADDR readptr() const {
    return readptr_;
  }

  ADDR writeptr() const {
    return writeptr_;
  }

  private:

  ADDR writeptr_, readptr_;

  bool empty_;
  bool loopInitNearFull_;

  BUFFERWORD nextword_;
  BUFFERWORD readcache_;
  
  //BUFFERWORDPROJSEQ nextwordprojseq_;
  //BUFFERWORDPROJSEQ readcacheprojseq_;
  
  BUFFERWORD buffer_[1<<AddressWidth];
  //BUFFERWORDPROJSEQ bufferprojseq_[1<<AddressWidth];

  ap_uint<(1<<(2*AddressWidth))> nearFullLUT_;

};

#endif
