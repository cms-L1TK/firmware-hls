#!/usr/bin/env python
#Script that generates merged TPAR and AS inputs to second FPGA project
#as they would appear coming from first FPGA link
#Run with python from IntegrationTests/DualFPGA/firmware/

import argparse
import os

#constants

#TPARs stored of list of list of names, where inner list indicates merging
TPAR_NAMES = [['L1L2A','L1L2B','L1L2C'],['L1L2D','L1L2E'],['L1L2F'],['L1L2G'],
              ['L1L2H','L1L2I'],['L1L2J','L1L2K','L1L2L'],
              ['L2L3A','L2L3B','L2L3C','L2L3D'],['L3L4A','L3L4B'],
              ['L3L4C','L3L4D'],['L5L6A','L5L6B','L5L6C','L5L6D'],
              ['D1D2A','D1D2B','D1D2C','D1D2D'],
              ['D3D4A','D3D4B','D3D4C','D3D4D'],
              ['L1D1A','L1D1B','L1D1C','L1D1D'],
              ['L1D1E','L1D1F','L1D1G','L1D1H'],
              ['L2D1A','L2D1B','L2D1C','L2D1D']]

AS_NAMES = ['L1PHIA','L1PHIB','L1PHIC','L1PHID','L1PHIE','L1PHIF','L1PHIG',
            'L1PHIH','L2PHIA','L2PHIB','L2PHIC','L2PHID','L3PHIA','L3PHIB',
            'L3PHIC','L3PHID','L4PHIA','L4PHIB','L4PHIC','L4PHID','L5PHIA',
            'L5PHIB','L5PHIC','L5PHID','L6PHIA','L6PHIB','L6PHIC','L6PHID',
            'D1PHIA','D1PHIB','D1PHIC','D1PHID','D2PHIA','D2PHIB','D2PHIC',
            'D2PHID','D3PHIA','D3PHIB','D3PHIC','D3PHID','D4PHIA','D4PHIB',
            'D4PHIC','D4PHID','D5PHIA','D5PHIB','D5PHIC','D5PHID']

MERGE_WORDS = ['00','01','10','11']

AS_LINK_INDICES = [59,58,57,56,55,54,53,52,51,50,49,48,43,42,41,40,39,38,37,
                   36,35,34,33,32,31,30,29,28]

AS_LINK_LAST_SIZE_DIFF = 16

TPAR_LINK_INDICES = [27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10]

TPAR_LINK_LAST_SIZE_DIFF = 12

LINKS_USED = [9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
              30,31,32,33,34,35,36,37,38,39,40,41,42,43,48,49,50,51,52,53,54,
              55,56,57,58,59]

#helper functions

def parseArguments():
  '''Parse arguments and return arguments object'''
  # Create argument parser
  parser = argparse.ArgumentParser(
      description="Convert a emData/ memory data files into EMP format file")
 
  # Optional arguments
  parser.add_argument("-d", "--directory", dest="inputDir", 
      help="directory containing input data", type=str, 
      default="emData/MemPrintsReduced/")
  parser.add_argument("-o","--outFile", dest="outFile", 
      help="output file name", type=str, default="Link_EMP.txt")

  # Parse arguments
  args = parser.parse_args()

  return args

def get_words_for_event(filename, event_number, word_length):
  '''Get the data words for a given event. Returns a list of bytes'''
  words = []

  with open(filename) as input_file:
    lines = input_file.readlines()
    current_event = False
    past_event = False
    for line in lines:
      if not current_event:
        #N.B. past_event is used to avoid matching later events ex. Event : 11 to Event : 1
        if (('Event : '+str(event_number)) in line) and not past_event:
          current_event = True
      elif current_event:
        if not ('Event : ' in line):
          bit_string = (line.split(' ')[1]).replace('|','')
          words.append(bit_string)
        else:
          current_event = False
          past_event = True

  return words

def get_word_or_empty(words, type_index, word_index, length):
  '''Get words[type_index][word_index] or 0 string of length length'''
  if len(words[type_index]) > word_index:
    return words[type_index][word_index]
  return ''.join(['0' for i in range(length)])

def write_emp_input(args):
  '''Write input for second FPGA'''
  output_file = open(args.outFile, 'w')

  output_file.write("ID: x0\n")
  output_file.write("Metadata: (strobe,) start of orbit, start of packet, end of packet, valid\n") 
  output_file.write("\n")
  output_file.write("      Link              ")
  for chan in LINKS_USED:
    output_file.write("%s                    " %(str(chan).zfill(3)))
  output_file.write("\n")

  word_index =  0

  for ievent in range(100):

    #extract list AS/TPAR words for each event, where first index is AS type and second is word in event
    as_words = []
    tpar_words = []
    for as_name in AS_NAMES:
      event_words = get_words_for_event(
          args.inputDir+'/Stubs/AllStubs_AS_'+as_name+'n1_04.dat',ievent,36)
      for iword in range(len(event_words)):
        event_words[iword] = '1'+event_words[iword]
      as_words.append(event_words)
    for tpar_name_group in TPAR_NAMES:
      tpar_words_group = []
      merge_index = 0
      for tpar_name in tpar_name_group:
        event_words = get_words_for_event(
            args.inputDir+'/TrackletParameters/TrackletParameters_TPAR_'+tpar_name+'_04.dat',
            ievent,73)
        for iword in range(len(event_words)):
          event_words[iword] = '1'+MERGE_WORDS[merge_index]+event_words[iword]
        tpar_words_group += event_words
        merge_index += 1
      tpar_words.append(tpar_words_group)

    for iword in range(108):

      #merge AS/TPAR data into two giant strings for this clock cycle
      as_string = ''
      tpar_string = ''
      for ias in range(len(AS_NAMES)):
        if (iword >= 6):
          as_string = get_word_or_empty(as_words, ias, iword-6, 37) + as_string
        else:
          as_string = ''.join(['0' for i in range(37)]) + as_string
      for itpar in range(len(TPAR_NAMES)):
        if (iword >= 6):
          tpar_string = get_word_or_empty(tpar_words, itpar, iword-6, 76) + tpar_string
        else:
          tpar_string = ''.join(['0' for i in range(76)]) + tpar_string

      link_data = {}
      
      #Slice words into links
      for ilink in range(len(AS_LINK_INDICES)):
        if ilink != (len(AS_LINK_INDICES)-1):
          start_idx = len(as_string)-(ilink+1)*64
          end_idx = len(as_string)-ilink*64
          link_data[AS_LINK_INDICES[ilink]] = as_string[start_idx:end_idx]
        else:
          end_idx = len(as_string)-ilink*64
          padding = ''.join(['0' for i in range(64-end_idx)])
          link_data[AS_LINK_INDICES[ilink]] = padding+as_string[:end_idx]
      for ilink in range(len(TPAR_LINK_INDICES)):
        if ilink != (len(TPAR_LINK_INDICES)-1):
          start_idx = len(tpar_string)-(ilink+1)*64
          end_idx = len(tpar_string)-ilink*64
          link_data[TPAR_LINK_INDICES[ilink]] = tpar_string[start_idx:end_idx]
        else:
          end_idx = len(tpar_string)-ilink*64
          padding = ''.join(['0' for i in range(64-end_idx)])
          link_data[TPAR_LINK_INDICES[ilink]] = padding+tpar_string[:end_idx]
      if (iword >= 6):
        link_data[9]=''.join(['0' for i in range(61)])+bin(ievent % 4)[2:]
      else:
        link_data[9]=''.join(['0' for i in range(64)])

      #Convert link data to hex and write
      #
      output_file.write('Frame %s    ' %(str(word_index).zfill(4)))
      for link in LINKS_USED:
        if (word_index % 108) < 6:
          output_file.write('%s ' %'0000')
        elif (word_index % 108) == 6:
          if (word_index == 6):
            output_file.write('%s ' %'1101')
          else:
            output_file.write('%s ' %'0101')
        elif (word_index % 108) == 107:
          output_file.write('%s ' %'0011')
        else:
          output_file.write('%s ' %'0001')
        output_file.write('%s  '%(hex(int(link_data[link],2))[2:]).zfill(16))
      output_file.write('\n')
      word_index += 1

  output_file.close()

  print("Output written to file ",args.outFile)

def check_emp_output(args):
  '''Check output from first FPGA project'''
  #TODO write this, for now, manually check output is permutation of the first FPGA output

if __name__ == '__main__':

  args = parseArguments()
  write_emp_input(args)

    
