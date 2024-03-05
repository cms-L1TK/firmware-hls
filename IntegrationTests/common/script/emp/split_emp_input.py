#!/usr/bin/env python
'''@package docstring
Script to split EMP input into nine event chunks due to buffer limitations
'''

import argparse

def left_pad_zeros(length, string):
  '''Adds zeros to the left of the string until its length is 4

  length   int, target length of string
  string   string to pad
  '''
  if len(string)<length:
    string = ''.join(['0' for i in range(length-len(string))])+string
  return string

if __name__=='__main__':
  
  parser = argparse.ArgumentParser()
  parser.add_argument('-i','--input_filename',default='mem/in.txt')
  parser.add_argument('-o','--output_prefix',default='mem/in_')
  args = parser.parse_args()

  with open(args.input_filename,'r') as input_file:
    content = input_file.read().split('\n')
    for iout in range(12):
      #first 11 files are 9 events each, last one is 1 event
      nevent = 9
      if iout==11:
        nevent = 1
      start_offset = 972*iout+4
      with open(args.output_prefix+str(iout)+'.txt','w') as output_file:
        #write header
        for iline in range(4):
          output_file.write(content[iline]+'\n')
        #write content
        for iframe in range(108*nevent):
          frame_data = content[start_offset+iframe]
          true_frame_number = 972*iout+iframe
          if true_frame_number<10000:
            frame_data = frame_data[:6]+left_pad_zeros(4,str(iframe))+frame_data[10:]
          else:
            frame_data = frame_data[:6]+left_pad_zeros(4,str(iframe))+frame_data[11:]
          output_file.write(frame_data+'\n')
