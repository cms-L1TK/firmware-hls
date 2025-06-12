#!/usr/bin/env python3
#Note: no emulation reference yet, just sim to board comparison

from argparse import ArgumentParser
from emp_data_format_tools import *

if __name__=='__main__':

  parser = ArgumentParser(
      description='Checks FPGA2 output')
  parser.add_argument('-e', '--events',
                      help='events to compare', type=str, 
                      default='0-99')
  parser.add_argument('-r', '--reference', 
                      help='Simulation output', 
                      type=str, default='out_sim.txt')
  parser.add_argument('-c','--comparison', 
                      help='On-board output to be compared',
                      type=str, default='out_board.txt')
  parser.add_argument('-so', '--simuoffset',
                      help='offset in simulation', type=int, 
                      default=36)
  parser.add_argument('-bo', '--boardoffset',
                      help='offset in hardware', type=int, 
                      default=5)
  parser.add_argument('-n', '--nevents',
                      help='events to compare', type=int, 
                      default=6)
  args = parser.parse_args()

  sim_data = load_emp_data(args.reference)
  board_data = load_emp_data(args.comparison)
  for i in range(args.nevents):
    sim_words = get_words_fpga2_empdata(sim_data,args.simuoffset+108*i)
    board_words = get_words_fpga2_empdata(board_data,args.boardoffset+108*i)
    compare_bitmap_list(sim_words[0], board_words[0])
    compare_bitmap_list(sim_words[1], board_words[1])


