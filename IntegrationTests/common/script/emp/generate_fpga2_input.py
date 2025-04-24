#!/usr/bin/env python3

from argparse import ArgumentParser
from emp_data_format_tools import *

def get_memprints_words(memprints_dir: str, first_event: int = 0, 
    last_event: int = 100) -> list[dict[str,list[Bitmap]]]:
  """Get data from MemPrints in given event range

  Args:
    memprints_dir: MemPrints directory
    first_event: first event to include in data, inclusive
    last_event: last event to include in data, noninclusive

  Returns:
    list (indexed by event) of dictionary (indexed by memory) of lists of 
    words as Bitmaps
  """
  event_data = []
  for event in range(first_event,last_event):
    event_data.append(get_output_fpga1_memprints(memprints_dir,event))
  return event_data

def get_f1output_words(f1_empdata: EmpData, first_event: int = 0,
    last_event: int = 100) -> list[dict[str, list[Bitmap]]]:
  """Get data from FPGA1 output in given event range

  Args:
    f1_empdata: EMP output from FPGA1 (simulated or hardware)
    first_event: first event to include in data, inclusive
    last_event: last event to include in data, noninclusive

  Returns:
    list (indexed by event) of dictionary (indexed by memory) of lists of 
    words as Bitmaps
  """
  tf_words_simu = []
  offset = get_first_valid_nonempty_word(f1_empdata, 1)
  for event in range(first_event,last_event):
    event_words = get_words_fpga1_empdata(f1_empdata,offset+108*event)
    #remove valid bits
    for memory in event_words:
      if memory != 'BX':
        event_words[memory] = remove_empty_bitmaps_in_list(event_words[memory])
        event_words[memory] = strip_leading_bits(event_words[memory],1)
    tf_words_simu.append(event_words)
  return tf_words_simu

if __name__=='__main__':

  parser = ArgumentParser(
      description='Generates FPGA2 EMP input')
  parser.add_argument('-i', '--input', dest='input_name', 
                      help='MemPrints directory or FPGA1 EMP output', 
                      type=str, default='emData/MemPrintsReduced/')
  parser.add_argument('-o','--output', dest='out_file', 
                      help='output file name', type=str, 
                      default='Link_EMP.txt')
  args = parser.parse_args()

  output_name = args.out_file
  if output_name[-4:] != '.txt':
    output_name += '.txt'

  memprint_ref = True
  if args.input_name[-4:] == '.txt':
    memprint_ref = False

  #generate FPGA2 input from MemPrints
  if memprint_ref:
    tf_words_emu = get_memprints_words(args.input_name)
    fpga2_empdata = create_empdata_fpga2_input(tf_words_emu)
    fpga2_empdata.write_to_file(output_name)
    #to accomodate buffer size of 1024, split EMP data into 12 files: 11 with 9
    #events and 1 with 1 event
    for i in range(11):
      output_split_name = output_name[:-4]+'_{}.txt'.format(i)
      tf_words_emu = get_memprints_words(args.input_name,i*9,(i+1)*9)
      fpga2_empdata = create_empdata_fpga2_input(tf_words_emu)
      fpga2_empdata.write_to_file(output_split_name)
    output_split_name = output_name[:-4]+'_11.txt'.format(i)
    tf_words_emu = get_memprints_words(args.input_name,99,100)
    fpga2_empdata = create_empdata_fpga2_input(tf_words_emu)
    fpga2_empdata.write_to_file(output_split_name)

  #generate FPGA2 input from FPGA1 output (simulation or on-board)
  else:
    data_f1_simu = load_emp_data(args.input_name)
    tf_words_simu = get_f1output_words(data_f1_simu,0,99)
    fpga2_empdata = create_empdata_fpga2_input(tf_words_simu)
    fpga2_empdata.write_to_file(output_name)
    #to accomodate buffer size of 1024, split EMP data into 12 files: 11 with 9
    #events and 1 with 1 event
    for i in range(11):
      output_split_name = output_name[:-4]+'_{}.txt'.format(i)
      tf_words_emu = get_f1output_words(data_f1_simu,i*9,(i+1)*9)
      fpga2_empdata = create_empdata_fpga2_input(tf_words_emu)
      fpga2_empdata.write_to_file(output_split_name)
