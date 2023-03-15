import argparse
import os

# Run with python3 in work/proj/
# Converts InputRouter input data from emData to EMP format

def parseArguments():
    # Create argument parser
    parser = argparse.ArgumentParser(description="Convert an emData/ memory data file into a EMP format file. Link-file mapping is done editing the header of the script.")
 
    # Optional arguments
    parser.add_argument("-d", "--directory", dest="inputDir", help="directory containing input data", type=str, default="emData/MemPrintsReduced/InputStubs/")
    parser.add_argument("-o","--outFile", dest="outFile", help="output file name", type=str, default="Link_EMP.txt")

    # Parse arguments
    args = parser.parse_args()

    return args

# Files in order in which they are referred to in memUtil_pkg.vhd.
# with key being channel number.
mapping = {}
mapping[0]  = "Link_DL_PS10G_1_A_04.dat"
mapping[1]  = "Link_DL_PS10G_2_A_04.dat"
mapping[2]  = "Link_DL_PS10G_2_B_04.dat"
mapping[3]  = "Link_DL_PS10G_3_A_04.dat"
mapping[4]  = "Link_DL_PS10G_3_B_04.dat"
mapping[5]  = "Link_DL_PS_1_A_04.dat"
mapping[6]  = "Link_DL_PS_2_A_04.dat"
mapping[7]  = "Link_DL_PS_2_B_04.dat"
mapping[8]  = "Link_DL_2S_1_A_04.dat"
mapping[9]  = "Link_DL_2S_1_B_04.dat"
mapping[10] = "Link_DL_2S_2_A_04.dat"
mapping[11] = "Link_DL_2S_2_B_04.dat"
mapping[12] = "Link_DL_2S_3_A_04.dat"
mapping[13] = "Link_DL_2S_4_A_04.dat"
mapping[14] = "Link_DL_2S_4_B_04.dat"

#channels = ["q00c0","q00c1","q00c2","q00c3","q01c0","q01c1","q01c2","q01c3","q02c0","q02c1","q02c2","q02c3","q03c0","q03c1","q03c2","q03c3"]

empWordLen=16 # Hex chars in an EMP data word
clksInTM=108 # Length of TM period in clock cycles
clksInGap=6  # Gap when no valid data sent.

if __name__ == '__main__':

  args = parseArguments()

  outFile = open(args.outFile, 'w')

  allData = {}
  for chan, fileName in mapping.items():
    file = open(args.inputDir + "/" + fileName, 'r')
    lines = file.readlines()
    for line in lines:
      words = line.split()
      if len(words) == 6:
        eventNumber = int(words[5])
        allData[(eventNumber,chan)] = []
      if len(words) == 3:
        addr = words[0]
        data = words[2]
        empData = data[2:].zfill(empWordLen)
        allData[(eventNumber,chan)].append(empData)

  outFile.write("ID: x0\n")
  outFile.write("Metadata: (strobe,) start of orbit, start of packet, end of packet, valid\n") 
  outFile.write("\n")
  outFile.write("      Link              ")
  for chan in mapping:
    outFile.write("%s                    " %(str(chan).zfill(3)))
  outFile.write("\n")

  gapData  = "0000000000000000"
  nullData = "0000000000000000"
  md_null = "0000"
  md_valid = "0001"
  md_soe = "0101"
  md_soo = "1101"
  md_eoe = "0011"
  iClk = 0

  for event in range(1+eventNumber):
    for iFrame in range(0,clksInTM):
      iFrameCorr = iFrame - clksInGap
      iClk += 1
      outFile.write("Frame %s    " %(str(iClk-1).zfill(4)))
      for chan in mapping:
        theKey = (event,chan)
        empDataList = allData[theKey]
        if (iFrame < clksInGap):
          outFile.write("%s " %md_null)
          outFile.write("%s  " %gapData)
        elif (iFrameCorr < len(empDataList)):
          if (event == 0) :
              if (iFrameCorr == 0) :
                  outFile.write("%s " %md_soo)
              elif (iFrame == clksInTM - 1) :
                  outFile.write("%s " %md_eoe)
              else :
                  outFile.write("%s " %md_valid)
          else :
              if (iFrameCorr == 0) :
                  outFile.write("%s " %md_soe)
              elif (iFrame == clksInTM - 1) :
                  outFile.write("%s " %md_eoe)
              else :
                  outFile.write("%s " %md_valid)
          outFile.write("%s  " %empDataList[iFrameCorr])
        else:
            if (iFrame == clksInTM - 1) :
                outFile.write("%s " %md_eoe)
            else :
                outFile.write("%s " %md_valid)
            outFile.write("%s  " %nullData)
      outFile.write("\n")
  print("Output written to file ",args.outFile)
    
