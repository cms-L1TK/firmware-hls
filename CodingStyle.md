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

* General constants start with k. e.g. kNumEvents and are declared `constexpr`
* Constants specifying number of bits are defined in the relevant memory header file, start with 'k' and end with 'Size', i.e., `kChi2Size`
   * alternate proposal: start with B & capitalized. e.g `BCHI2` ?
* Size constants are declared via enum
* Class data members end with underscore. e.g. `raw_`.
* Use setters and getters to hide implementation;
   * Follow CMSSW standards such that the setter for quantity Q has 'set' prepended and the getter is just the quantity, i.e., `setQ()` and `Q()` 
* Use of class templates can avoid code duplication.
* Inter-processing module RAMS inherit from common class (MemoryBase) and follow a specific model (details to be added here)
