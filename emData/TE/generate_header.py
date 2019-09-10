#
# Generates .h header file to read in TE cut tables
#    scans current directory for folders with name pattern TE_*PHI*_*PHI* and 
#    generates C++ header file to be included in TE module
#
# argv[1] is the function name:         readPtTable, readBendInnerTable, readBendOuterTable
# argv[2] is the suffix for cut tables: ptcut,       stubptinnercut,     stubptoutercut 
#

from os import listdir
import sys

fcnName = sys.argv[1]
suffix = sys.argv[2]

print "template<int seed, int innerphi, int outerphi, unsigned int depth>"
print "void " + fcnName + "(ap_uint<1> table[depth]){"

first=True;
for d in listdir("."):
  substr = d.split("_")
  if substr[0] == "TE":
    innerstr = substr[1].split("PHI")
    innerseed = innerstr[0]
    innerphi = innerstr[1]
    outerstr = substr[2].split("PHI")
    outerseed = outerstr[0]
    outerphi = outerstr[1]
    print ""
    if first:
      print "  if(seed==TE::" + innerseed + outerseed + " && innerphi==TE::" + innerphi + " && outerphi==TE::" + outerphi + ") {"
      first = False;
    else:
      print "  } else if(seed==TE::" + innerseed + outerseed + " && innerphi==TE::" + innerphi + " && outerphi==TE::" + outerphi + ") {"
    print "    ap_uint<1> tmp[] ="
    print "#include \"../emData/TE/" + d + "/" + d + "_" + suffix + ".tab\""
    print "    for (unsigned int i=0; i<depth; i++) { table[i]=tmp[i]; }"
print "  }"
print ""
print "}"
