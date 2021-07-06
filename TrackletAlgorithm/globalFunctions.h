#ifndef TrackletAlgorithm_globalFunctions_h
#define TrackletAlgorithm_globalFunctions_h

#ifdef CMSSW_GIT_HASH

 static std::string decodeToBits(unsigned int field, unsigned int size) {
   unsigned int valtmp = field;
   std::string str = "";
   for(unsigned int i=0; i< size; i++) {
     str = ((valtmp & 1) ? "1" : "0") + str;
     valtmp >>= 1;
   }
   return str;
 }
#endif
#endif
