#!/usr/bin/env python3

from argparse import ArgumentParser
from emp_data_format_tools import *

BOARD_OFFSET = 36 #hard-coded for now, change once we automate testing?
SIMU_OFFSET = 5

if __name__=='__main__':

  parser = ArgumentParser(
      description='Checks FPGA1 output')
  parser.add_argument('-e', '--events',
                      help='Events to compare', type=str, 
                      default='0-99')
  parser.add_argument('-r', '--reference', 
                      help='MemPrints directory or simulation output', 
                      type=str, default='emData/MemPrintsReduced/')
  parser.add_argument('-c','--comparison', 
                      help='Simulation or on-board output to be compared',
                      type=str, default='out.txt')
  args = parser.parse_args()

  memprint_ref = True
  if args.reference[-4:] == '.txt':
    memprint_ref = False

  comp_empdata = load_emp_data(args.comparison)
  ref_empdata = EmpData([0])
  if not memprint_ref:
    ref_empdata = load_emp_data(args.reference)

  event_list = range_string_to_list(args.events)
  for ievent in event_list:
    print('Event {}'.format(ievent))
    tf_words_board = get_words_fpga2_empdata(comp_empdata,
                                             BOARD_OFFSET+108*ievent)
    tf_words_ref = {}
    #if memprint_ref:
    #  tf_words_ref = get_output_fpga2_memprints(args.reference,ievent)
    else:
      tf_words_ref = get_words_fpga2_empdata(ref_empdata,
                                             SIMU_OFFSET+108*ievent)
    for memory in tf_words_board:
      print(memory)
      compare_bitmap_list(tf_words_ref[memory],
                          strip_leading_bits(tf_words_board[memory],1))
