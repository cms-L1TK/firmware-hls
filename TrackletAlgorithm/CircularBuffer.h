#ifndef TrackletAlgorithm_CircularBuffer_h
#define TrackletAlgorithm_CircularBuffer_h

// This circular buffer implements a memory in DRAM with caching of the
// next data to read in the buffer
// BufferWidth is the bit width of the words stored in the buffer
// AddressWidth is the widht of the address word
// If you write a new value you can read it on the next clock - but not on the
// same clock
// NearFullCount is how many slots in the buffer has to be available in order to not consider the
// buffer near full

//
// Usage:
// Call reset() at the start of each event
// Call loopInit() to cache state at the start of each processing loop
// You must read before writing in the processing loop
// Call loopEnd() to update cache 
//

template <int BufferWidth, int AddressWidth, int NearFullCount>
class CircularBuffer {

 public:

  //
  // Typedef for buffer word and address
  //
  typedef ap_uint<BufferWidth> BUFFERWORD;
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


  //
  // Call this method at the start of each clock to set the near full status
  //
  void loopInit() {
    static const ap_uint<(1<<(2*AddressWidth))> nearFullLUT = nearFullInit();
    loopInitNearFull_ = nearFullLUT[(writeptr_, readptr_)];
  }

  //
  // Call this method at the end of the loop to cache the next buffer value
  //
  void loopEnd() {
    readcache_ = buffer_[readptr_];
  }

  //
  // This method stores new element in buffer
  //
  void store(const BUFFERWORD word) {
    if (empty_) {
      nextword_ =  word;
      empty_ = false;
    } else {
      buffer_[writeptr_++]=word;
    }
  }

  //
  // The save and inc methods are equivalent to calling store - but
  // if you know what you want to save before you know *if* you want to
  // save the element in the buffe you can call save first and then
  // call inc to increment the counter, or set empty to false, once
  // you know that the word should be stored on the buffer. This allows
  // a small optimization
  //
  void save(const BUFFERWORD word) {
    if (empty_) {
      nextword_ =  word;
    } 
    buffer_[writeptr_] = word;
  }

  void inc() {
    if (empty_) {
      empty_ = false;
    } else {
      writeptr_++;
    }
  }


  //
  // Extracts the next element in the circular buffer without advancing the read pointer
  //
  BUFFERWORD peek() const {
    return nextword_;
  }

  //
  // Extracts the next element in the circular buffger and advancing the read pointer
  //
  BUFFERWORD read() {
    BUFFERWORD tmp = nextword_;
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
      readptr_++;
    }
    return tmp;
  }

  //
  // Advance the read pointer
  //
  void advance() {
    if (readptr_ == writeptr_) {
      empty_ = true;
    } else {
      nextword_ = readcache_;
      readptr_++;
    }
  }

  //
  // Check if memory is full
  //
  bool full() const {
    ADDR writeptrnext = writeptr_+1;
    return writeptrnext == readptr_;
  }

  //
  // Return the nearFull status
  //
  bool nearFull() const {
    return loopInitNearFull_;
  }

  // 
  // Check if buffere is empty
  //
  bool empty() const {
    return empty_;
  }

  //
  // Return value of readptr
  //
  ADDR readptr() const {
    return readptr_;
  }

  //
  // Return value of writeptr
  //
  ADDR writeptr() const {
    return writeptr_;
  }

 private:
  //
  // Read and write ptr
  //
  ADDR writeptr_, readptr_;

  //
  // empty status flag
  //
  bool empty_;

  //
  // near full status
  //
  bool loopInitNearFull_;

  //
  // Buffer array and next word and read cache
  //
  BUFFERWORD nextword_, readcache_;
  BUFFERWORD buffer_[1<<AddressWidth];

};

#endif


