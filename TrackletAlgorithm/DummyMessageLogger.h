#ifndef MessageLogger_MessageLogger_h
#ifndef L1Trigger_TrackFindingTracklet_interface_Logger_h
#define L1Trigger_TrackFindingTracklet_interface_Logger_h
#include<iostream>
namespace edm {
  class LogVerbatim{
  public:
    LogVerbatim(std::string type) { if(0) {std::cout<<type<<std::endl;} }
    ~LogVerbatim() { std::cout << std::endl;}
    template <class T> LogVerbatim& operator<<(T const& t) {std::cout << t;return *this;}
    LogVerbatim& operator<<(std::ostream& (*f)(std::ostream&)) {std::cout << f;return *this;}
    LogVerbatim& operator<<(std::ios_base& (*f)(std::ios_base&)) {std::cout << f;return *this;}
  };
  class LogPrint{
  public:
    LogPrint(std::string type) { if(0) {std::cout<<type<<std::endl;} }
    ~LogPrint() { std::cout << std::endl;}
    template <class T> LogPrint& operator<<(T const& t) {std::cout << t;return *this;}
    LogPrint& operator<<(std::ostream& (*f)(std::ostream&)) {std::cout << f;return *this;}
    LogPrint& operator<<(std::ios_base& (*f)(std::ios_base&)) {std::cout << f;return *this;}
  };
  class LogWarning{
  public:
    LogWarning(std::string type) { if(0) {std::cout<<type<<std::endl;} }
    ~LogWarning() { std::cout << std::endl;}
    template <class T> LogWarning& operator<<(T const& t) {std::cout << t;return *this;}
    LogWarning& operator<<(std::ostream& (*f)(std::ostream&)) {std::cout << f;return *this;}
    LogWarning& operator<<(std::ios_base& (*f)(std::ios_base&)) {std::cout << f;return *this;}
  };
  class LogProblem{
  public:
    LogProblem(std::string type) { if(0) {std::cout<<type<<std::endl;} }
    ~LogProblem() { std::cout << std::endl;}
    template <class T> LogProblem& operator<<(T const& t) {std::cout << t;return *this;}
    LogProblem& operator<<(std::ostream& (*f)(std::ostream&)) {std::cout << f;return *this;}
    LogProblem& operator<<(std::ios_base& (*f)(std::ios_base&)) {std::cout << f;return *this;}
  };
};
#endif
#endif
