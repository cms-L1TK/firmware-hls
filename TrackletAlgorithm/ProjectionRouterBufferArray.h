#ifndef PRBUFFERARRAY_HH
#define PRBUFFERARRAY_HH

#include "ProjectionRouterBuffer.h"
#include "MatchEngineUnit_parameters.h"

template<int kNBitsBuffer,int AllProjectionType> class ProjectionRouterBufferArray {
public:
  inline ProjectionRouterBuffer<BARREL,AllProjectionType> read() {
#pragma HLS inline
    //#pragma HLS ARRAY_PARTITION variable=projbuffer_ complete
    return projbuffer_[readptr_++];
  }

  inline ProjectionRouterBuffer<BARREL,AllProjectionType> peek() {
#pragma HLS inline
    //#pragma HLS ARRAY_PARTITION variable=projbuffer_ complete
    return projbuffer_[readptr_];
  }

  inline void advance() {
#pragma HLS inline
    //#pragma HLS ARRAY_PARTITION variable=projbuffer_ complete
    readptr_++;
  }



  inline void saveProjection(ProjectionRouterBuffer<BARREL,AllProjectionType> &proj) {
#pragma HLS inline
    //#pragma HLS array_partition variable=projbuffer_ complete
    projbuffer_[writeptr_] = proj;
  }

  inline void incProjection() {
#pragma HLS inline
    writeptr_++;
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

private:
  ap_uint<kNBitsBuffer> readptr_ = 0;
  ap_uint<kNBitsBuffer> writeptr_ = 0;
  ProjectionRouterBuffer<BARREL,AllProjectionType> projbuffer_[1<<kNBitsBuffer];
  ap_uint<(1 << (2 * kNBitsBuffer))> nearFullLUT = nearFullUnit<kNBitsBuffer>();
  ap_uint<(1 << (2 * kNBitsBuffer))> emptyLUT = emptyUnit<kNBitsBuffer>();

};

#endif
