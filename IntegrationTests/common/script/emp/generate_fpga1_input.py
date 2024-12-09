#!/usr/bin/env python3

from argparse import ArgumentParser
from emp_data_format_tools import *

if __name__=='__main__':

  parser = ArgumentParser(
      description='Converts emData/memory data file into a EMP format file.')
  parser.add_argument('-i', '--input', dest='input_dir', 
                      help='MemPrints directory', type=str, 
                      default='emData/MemPrintsReduced/')
  parser.add_argument('-o','--outFile', dest='out_file', 
                      help='output file name', type=str, 
                      default='Link_EMP.txt')
  args = parser.parse_args()

  output_name = args.out_file
  if output_name[-4:] != '.txt':
    output_name += '.txt'
  fpga1_input = create_empdata_fpga1_input(args.input_dir,0,100)
  fpga1_input.write_to_file(output_name)
  #to accomodate buffer size of 1024, split EMP data into 12 files: 11 with 9
  #events and 1 with 1 event
  for i in range(11):
    output_split_name = output_name[:-4]+'_{}.txt'.format(i)
    fpga1_input_split = create_empdata_fpga1_input(args.input_dir,i*9,(i+1)*9)
    fpga1_input_split.write_to_file(output_split_name)
  output_split_name = output_name[:-4]+'_11.txt'
  fpga1_input_split = create_empdata_fpga1_input(args.input_dir,99,100)
  fpga1_input_split.write_to_file(output_split_name)
