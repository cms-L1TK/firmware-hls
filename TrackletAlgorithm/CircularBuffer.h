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

template <int BufferWidth,int AddressWidth,int NearFullCount>
class CircularBuffer {

 public:

  typedef ap_uint<BufferWidth> BUFFERWORD;
  typedef ap_uint<AddressWidth> ADDR;

  // Constructors
 CircularBuffer():
  writeptr_(0), readptr_(0), empty_(true)
    {
      //Initialize nearFullLUT
      for(unsigned int iwrt=0; iwrt<(1<<AddressWidth); iwrt++) {
#pragma HLS unroll 
	for(unsigned int iread=0; iread<(1<<AddressWidth); iread++) {
#pragma HLS unroll 
	  ADDR writeptr(iwrt);
	  ADDR readptr(iread);
	  nearFullLUT_[(writeptr,readptr)] = false;
	  for(unsigned i=1; i<NearFullCount; i++) {
#pragma HLS unroll 
	    if (writeptr+i == readptr) {
	      nearFullLUT_[(writeptr, readptr)] = true;
	    }
	  }
	}
      }
    }
	
  void reset() {
    writeptr_ = 0;
    readptr_ = 0;
    empty_ = true;
  }

  void loopInit() {
    loopInitNearFull_ = nearFullLUT_[(writeptr_, readptr_)];
  }

  void loopEnd() {
    readcache_ = buffer_[readptr_];
  }

  void store(const BUFFERWORD data) {
    if (empty_) {
      assert(writeptr_ == readptr_);
      nextword_ =  data;
      empty_ = false;
    } else {
      buffer_[writeptr_++]=data;
    }
  }

  BUFFERWORD peek() const {
    return nextword_;
  }

  BUFFERWORD read() {
    BUFFERWORD tmp = nextword_;
    assert(!empty_);
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
      readptr_++;
    }
    return tmp;
  }

  void advance() {
    assert(!empty_);
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
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
  
  BUFFERWORD buffer_[1<<AddressWidth];

  bool nearFullLUT_[1<<(2*AddressWidth)];

};

#endif
