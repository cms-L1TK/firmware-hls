# Coding Style for HLS 

The primary guideline is to follow the CMS guidelines, as outlined in [this CMSSW style guide](http://cms-sw.github.io/cms_coding_rules.html).

In this document let's try to collect our best practices.

## General good coding practice

1. Avoid hard-wired constants buried in code.
   * Commonly varied constants should be declared in Constants.h type-file or via CMSSW cfg params.
2. Avoid lots of almost identical lines of code. Or almost duplicate code. Keep code short.
3. Add plenty of comments, especially when the code obscure, but even if it seems clear to you. 
   * The class definition file should contain a short description of the class at the start of the file
4. Put class implementation in separate file (.cc) to declaration (.h).
   * Or put at end of .h file if templated classes prevent use of .cc.
5. Git PRs reviewed by another person before merge to master.
   * this is technically enforced in this repository

## HLS specific practice

* General constants start with k. e.g. `kNumEvents` and are declared `constexpr`
* Constants specifying number of bits are defined in the relevant memory header file, start with 'k' and end with 'Size', i.e., `kChi2Size`
   * alternate proposal: start with B & capitalized. e.g `BCHI2` ?
* Size constants are declared via enum
* Class data members end with underscore. e.g. `raw_`.
* Use setters and getters to hide implementation;
   * Follow CMSSW standards such that the setter for quantity Q has 'set' prepended and the getter is just the quantity, i.e., `setQ()` and `Q()` 
* Use of class templates can avoid code duplication.

### RAMs
We use the following model for the inter-module RAMs in the project. 
* In a header file we define both the data that the RAM contains as well as the particular template instantiation that defines the RAM. For instance, following the `StubPairMemory.h` example. In the header file we define a class `StubPair` that is the data stored in a `StubPairMemory`, which in turn is just the instantiation of the template `MemoryBase` with a `StubPair` data member. 

For the data types:
* data is stored in aggregate types (packed)
* getters and setters provide access to the physically meaningful quantities from these bitpacked types.

The data types follow a strict convention and were all written by the same person (Derek). The header file first defines via enums the bit sizes of each piece of information, for example from the `TrackletParameters` data type:
````c++
  enum BitWidths {
    // Bit sizes for TrackletParameterMemory fields
    kTParRinvSize = 14, //rinv
    kTParPhi0Size = 18, //phi0
    kTParZ0Size = 10, //z0
    kTParTSize = 14, //t
    // Bit size for full TrackletParameterMemory
    kTrackletParameterSize = kTParRinvSize + kTParPhi0Size + kTParZ0Size + kTParTSize + 2*kNBits_MemAddr
  };
  ````
From these definitions the LSB and MSB of the packed bitword is calculated by the compiler and then used in the getter and setter routines, so if bit sizes change only this enum needs to be updated. 
