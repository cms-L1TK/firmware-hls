#!/usr/bin/env python
'''@package docstring
Script to merge EMP output, which is split into 9 event chunks due to buffer limitations
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
  parser.add_argument('-f','--frame_offset',default='5')
  parser.add_argument('-i','--input_prefix',default='mem/tx_summary_')
  parser.add_argument('-o','--output_filename',default='mem/out_apollo.txt')
  args = parser.parse_args()

  frame_offset = int(args.frame_offset)

  with open(args.output_filename,'w') as output_file:
    #first 11 files are 9 events each, last one is 1 event
    frame = 0
    for isplit in range(12):
      with open(args.input_prefix+str(isplit)+'.txt','r') as input_file:
        content = input_file.read().split('\n')
        nevent = 9
        if isplit == 11:
          nevent = 1
        if isplit == 0:
          #write header
          for iline in range(4):
            output_file.write(content[iline]+'\n')
        for iline in range(4+frame_offset,4+frame_offset+(nevent*108)):
          frame_data = content[iline]
          frame_data = frame_data[:6]+left_pad_zeros(4,str(frame))+frame_data[10:]
          output_file.write(frame_data+'\n')
          frame += 1
