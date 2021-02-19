#ifndef PRBUFFERARRAY_HH
#define PRBUFFERARRAY_HH

#include "ProjectionRouterBuffer.h"

template<int kNBitsBuffer> class ProjectionRouterBufferArray {
public:
  inline ProjectionRouterBuffer<BARREL> read() {
#pragma HLS inline
    ap_uint<kNBitsBuffer> tmpptr = ptr_;
    ptr_++;
    empty_ = ptr_ >= width_ ? true : false;
    if(empty()) reset(); //read all projections, reset array to 0
    //std::cout << std::hex << "reading projbuffer proj=" << projbuffer[tmpptr].getProjection() << "\ttmpptr=" << tmpptr << "\tmoving ptr_=" << ptr_ << "\twidth_=" << width_ << std::endl;
    //print();
    return projbuffer[tmpptr];

  }

  inline void addProjection(ProjectionRouterBuffer<BARREL> &proj) {
#pragma HLS inline
    projbuffer[width_] = proj;
    //std::cout << std::hex << "adding proj=" << proj.getProjection() << "\tprojid=" << proj.getIndex() << "\twidth= " << width_ << std::endl;
    width_++;
    empty_ = false;
    //print();
  }

  inline bool empty() { 
#pragma HLS inline
    //std::cout << "Empty projbuffer? " << (ptr_ == width_) << std::endl;
    //return ptr_ == width_;
    return empty_;
  }

  inline void reset() {
#pragma HLS inline
    ptr_ = 0;
    width_ = 0;
    //std::cout << "Resetting proj buffer array!" << std::endl;
    //empty();
    empty_ = true;
  }

  ProjectionRouterBufferArray() {
#pragma HLS ARRAY_PARTITION variable=projbuffer complete dim=0
//#pragma HLS resource variable=projbuffer core=RAM_2P_LUTRAM
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
  ap_uint<kNBitsBuffer> ptr_ = 0;
  ap_uint<kNBitsBuffer> width_ = 0;
  bool empty_ = false;
  ProjectionRouterBuffer<BARREL> projbuffer[1<<kNBitsBuffer];

};

#endif
