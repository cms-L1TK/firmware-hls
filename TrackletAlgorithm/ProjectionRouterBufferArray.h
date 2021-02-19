#ifndef PRBUFFERARRAY_HH
#define PRBUFFERARRAY_HH

#include "ProjectionRouterBuffer.h"
#include "MatchProcessor_parameters.h"

template<int kNBitsBuffer,int AllProjectionType> class ProjectionRouterBufferArray {
public:
  inline ProjectionRouterBuffer<BARREL,AllProjectionType> read() {
#pragma HLS inline
#pragma HLS ARRAY_PARTITION variable=projbuffer_ complete
    return projbuffer_[readptr_++];
  }

  inline void addProjection(ProjectionRouterBuffer<BARREL,AllProjectionType> &proj) {
#pragma HLS inline
#pragma HLS array_partition variable=projbuffer_ complete
    projbuffer_[writeptr_++] = proj;
  }

  inline bool empty() { 
    //return readptr_ == writeptr_;
    return emptyLUT[(readptr_, writeptr_)];
  }

  bool nearFull() {
    /*
    ap_uint<kNBitsBuffer> writeptrnext(writeptr_+1);
    ap_uint<kNBitsBuffer> writeptrnextnext(writeptr_+2);
    return writeptrnext==readptr_ || writeptrnextnext==readptr_;
    */
    //nearFullPRBuffUnit<kNBitsBuffer>()[readptr_, writeptr_];
    return nearFullLUT[(readptr_, writeptr_)];
  }

  ap_uint<kNBitsBuffer> getReadPtr() {
    return readptr_;
  }

  ap_uint<kNBitsBuffer> getWritePtr() {
    return writeptr_;
  }


  inline void reset() {
#pragma HLS inline
    readptr_ = 0;
    writeptr_ = 0;
  }

  ProjectionRouterBufferArray() {
    reset();
  }

  #ifndef __SYNTHESIS__
  void print() {
    if(empty()) {
      std::cout << "unread contents in projbuffer empty!" << std::endl;
    }
    else {
      std::cout << "Unread contents in projbuffer" << std::endl;
      for(int i = ptr_; i < width_; ++i){
        std::cout << std::hex << i << ": " << projbuffer[i].raw() << (i==ptr_ ? " <=== ptr" : "") << std::endl;
      }
    }
  }
  #endif

private:
  ap_uint<kNBitsBuffer> readptr_ = 0;
  ap_uint<kNBitsBuffer> writeptr_ = 0;
  ProjectionRouterBuffer<BARREL,AllProjectionType> projbuffer_[1<<kNBitsBuffer];
  ap_uint<(1 << (2 * kNBitsBuffer))> nearFullLUT = nearFullUnit<kNBitsBuffer>();
  ap_uint<(1 << (2 * kNBitsBuffer))> emptyLUT = emptyUnit<kNBitsBuffer>();

};

#endif
