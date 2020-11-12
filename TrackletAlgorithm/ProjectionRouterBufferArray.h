#ifndef PRBUFFERARRAY_HH
#define PRBUFFERARRAY_HH

#include "ProjectionRouterBuffer.h"

template<int kNBitsBuffer> class ProjectionRouterBufferArray {
public:
  inline ProjectionRouterBuffer<BARREL> read() {
    ap_uint<kNBitsBuffer> tmpptr = ptr_;
    ptr_++;
    //if(empty()) reset(); //read all projections, reset array to 0
    std::cout << std::hex << "reading projbuffer proj=" << projbuffer[tmpptr].raw() << "\ttmpptr=" << tmpptr << "\tmoving ptr_=" << ptr_ << "\twidth_=" << width_ << std::endl;
    return projbuffer[tmpptr];

  }

  inline void add(ProjectionRouterBuffer<BARREL> proj) {
    projbuffer[width_] = proj;
    std::cout << std::hex << "adding proj=" << projbuffer[width_].raw() << "\twidth= " << width_ << std::endl;
    width_++;
  }

  inline bool empty() { 
    std::cout << "Empty? " << (ptr_ == width_) << std::endl;
    return ptr_ == width_;
  }

  inline void reset() {
    ptr_ = 0;
    width_ = 0;
    //std::cout << "Resetting proj buffer array!" << std::endl;
    empty();
  }

  ProjectionRouterBufferArray() {
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=0
    reset();
  }

private:
  ap_uint<kNBitsBuffer> ptr_ = 0;
  ap_uint<kNBitsBuffer> width_ = 0;
  ProjectionRouterBuffer<BARREL> projbuffer[1<<kNBitsBuffer];

};

#endif
