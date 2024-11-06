# script to convert output from FPGA1 into input for FPGA2
# MO 06.11.2024

from argparse import ArgumentParser

#reference constants
EMP_HEADER='''ID: ALGO_TESTBENCH
Metadata: (strobe,) start of orbit, start of packet, end of packet, valid

'''
LINK_MAP = {}
IN_CHANNELS = []
OUT_CHANNELS = []
for range_low, range_high in [(4,15),(20,54)]:
  for ilink in range(range_low,range_high+1):
    LINK_MAP[63-ilink] = ilink
    IN_CHANNELS.append(ilink)
    OUT_CHANNELS.append(63-ilink)
OUT_CHANNELS.reverse()

def get_data_from_f1(input_filename):
  '''Reads EMP data from input file and stores result as dictionary of lists
  where key is link number and lists list tuples of (meta signals, data)
  '''
  input_file_content = []
  with open(input_filename,'r') as input_file:
    input_file_content = input_file.read().split('\n')
  #store dictionary mapping text column number to link number
  column_numbers = {}
  columns = input_file_content[3].split()
  for icol in range(1,len(columns)):
    link_no = int(columns[icol])
    if link_no in IN_CHANNELS:
      column_numbers[icol*2+1] = link_no
  #loop over frames and generate data
  data = {}
  for ilink in IN_CHANNELS:
    data[ilink] = []
  for iframe in range(4,len(input_file_content)):
    frame_text = input_file_content[iframe].split()
    for icol in range(len(frame_text)):
      if icol in column_numbers:
        data[column_numbers[icol]].append((frame_text[icol-1],frame_text[icol]))
  return data

def write_data_to_f2(data, output_filename):
  '''Writes EMP data to output file
  '''
  n_frames = len(data[4])
  with open(output_filename,'w') as output_file:
    output_file.write(EMP_HEADER)
    output_file.write('      Link              ')
    for channel in OUT_CHANNELS:
      output_file.write('{:03}                    '.format(channel))
    output_file.write('\n')
    for iframe in range(n_frames):
      output_file.write('Frame {:04}    '.format(iframe))
      for channel in OUT_CHANNELS:
        meta_data, data_word = data[LINK_MAP[channel]][iframe]
        output_file.write('{} {}  '.format(meta_data, data_word))
      output_file.write('\n')

#TODO check for bx link

if __name__=='__main__':
  parser = ArgumentParser(prog='conv_emp_interfpga', 
     description='Converts EMP output to input following Apollo wiring')
  parser.add_argument('-i','--input_file')
  parser.add_argument('-o','--output_file')
  args = parser.parse_args()

  print('Processing input')
  input_data = get_data_from_f1(args.input_file)
  print('Writing output')
  write_data_to_f2(input_data, args.output_file)

  


  
