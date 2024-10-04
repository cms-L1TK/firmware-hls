#!/usr/bin/env python
'''@package docstring
Script to cross-check EMP-style outputs from FPGA1 (AllStubs and MergedTrackletParameters)
'''

import argparse
import math

class Bitmap:
  '''class to work with bit data'''
  #Note internally, bitmap is stored as binary string with MSB first 

  char_to_bool = {'0' : False, '1' : True}
  bool_to_char = {False : '0', True : '1'}

  @staticmethod
  def trim_zeros(value):
    '''Returns value with MSB zeros removed

    value  binary string
    '''
    last_one = value.find('1')
    if last_one == -1:
      return '0'
    return value[last_one:]

  @staticmethod
  def zero_pad(value,length):
    '''Returns value padded until it is at least length

    value   binary string
    length  int minimum length
    '''
    if len(value)<length:
      value = ''.join(['0' for i in range(length-len(value))]) + value
    return value

  def __init__(self, initializer):
    '''initialize bitmap from a hex string or list of bools

    initializer   hex or binary string in reading order (MSB first)
    '''

    if initializer[:2] in ['0x','0b']:
      initializer = initializer[2:]

    #For binary string, just reverse order 
    if (initializer.count('0')+initializer.count('1')==len(initializer)):
      self.value = initializer

    #For hex string, convert to binary and reverse order
    else:
      bin_string = bin(int(initializer,16))
      self.value = bin_string[2:]

  def __and__(self, other):
    '''bitwise AND operation

    other   Bitmap to compare
    '''
    other_value = other.value
    self_value = self.value
    max_length = max(len(self_value, other_value))
    other_value = zero_pad(other_value, max_length)
    self_value = zero_pad(self_value, max_length)
    result = ''
    for self_bit, other_bit in zip(self_value, other_value):
      result += bool_to_char[char_to_bool[self_bit] & char_to_bool[other_bit]]
    return Bitmap(result)

  def __or__(self, other):
    '''bitwise OR operation

    other   Bitmap to compare
    '''
    other_value = other.value
    self_value = self.value
    max_length = max(len(self_value, other_value))
    other_value = zero_pad(other_value, max_length)
    self_value = zero_pad(self_value, max_length)
    result = ''
    for self_bit, other_bit in zip(self_value, other_value):
      result += bool_to_char[char_to_bool[self_bit] | char_to_bool[other_bit]]
    return Bitmap(result[::-1])

  def __invert__(self):
    '''bitwise NOT operation'''
    result = ''.join(bool_to_char[not char_to_bool[bit]] for bit in self.value)
    return Bitmap(result)

  def __rshift__(self, other):
    '''bitwise right shift operation

    other   int, number of bits to shift
    '''
    return Bitmap(self.value[:len(self-value)-other])

  def __lshift__(self, other):
    '''bitwise left shift operation

    other   int, number of bits to shift
    '''
    return Bitmap(self.value + ''.join(['0' for i in range(other)]))

  def to_hexstring(self):
    '''Returns string of hex characters representing Bitmap content'''
    if self.value == '':
      return '0'
    return hex(int(self.value,2))[2:]

  def to_binstring(self):
    '''Returns string of binary characters representing Bitmap content'''
    if self.value == '':
      return '0'
    return self.value

  def to_int(self):
    '''Returns unsigned integer representing Bitmap content'''
    if self.value == '':
      return 0
    return int(self.value,2)

  def to_signedint(self, length=-1):
    '''Returns signed (two's complement) integer representing Bitmap content
    
    length   number of bits, -1 uses default length
    '''
    if self.value == '':
      return 0
    value = self.value
    if length>0:
      value = zero_pad(value, length)
    if value[0]=='0':
      return int(self.value,2)
    else:
      return -1*((~self).to_int()+1)

  def undigitize(self, is_signed, nbits, granularity):
    '''Returns float representing bitmap content

    is_signed     whether bitmap represents signed or unsigned value
    nbits         number of bits
    granularity   digitization granularity
    '''
    int_value = 0
    if is_signed:
      int_value = self.to_signedint(nbits)
    else:
      int_value = self.to_int()
    return (int_value+0.5)*granularity

  def substring(self, end, start):
    '''Returns sub-bitmap from start inclusively to end noninclusively

    start  int starting index of bitmap
    end    int ending index of bitmap
    '''
    start = len(self.value)-start
    end = len(self.value)-end
    return Bitmap(self.value[end:start])

def fix_phi_range(phi):
  '''Forces an angle into the range (-pi,pi)'''
  while phi>3.1416:
    phi -= 2.0*3.1416
  while phi<-3.1416:
    phi += 2.0*3.1416
  return phi

def get_bin_mean(index, bin_boundaries):
  '''undigitize value based on bin_boundaries, returning the mean fr the
  bin the digitized value falls into. If it is in the uppermost bin 
  (extending to infinity), the lower bin boundary is given.

  index           int, digitized value
  bin_boundaries  list of floats, digitization bin boundaries
                  the last bin extends from the last entry in the
                  list to infinity
  '''
  if index<0:
    raise ValueError('Input to get_bin_mean must be unsigned.')
  if index>=(len(bin_boundaries)-1):
    return bin_boundaries[len(bin_boundaries)-1]
  return (bin_boundaries[index]+bin_boundaries[index+1])/2.0

class KfTrack:
  '''Class to store data corresponding to a track written by Kalman Filter'''

  def __init__(self, hex_string):
    '''Initialize KF track from hex string

    hex_string   string of hex characters representing track
    '''
    self.bits = Bitmap(hex_string)
    valid = ((self.bits >> 95) & Bitmap('0x1'))
    invr = ((self.bits >> 80) & Bitmap('0x7FFF'))
    phi0 = ((self.bits >> 68) & Bitmap('0xFFF'))
    chi2rphi = ((self.bits >> 64) & Bitmap('0xF'))
    tanl = ((self.bits >> 48) & Bitmap('0xFFFF'))
    z0 = ((self.bits >> 36) & Bitmap('0xFFF'))
    chi2rz = ((self.bits >> 32) & Bitmap('0xF'))
    d0 = ((self.bits >> 19) & Bitmap('0x1FFF'))
    bendchi2 = ((self.bits >> 16) & Bitmap('0x7'))
    hitpattern = ((self.bits >> 9) & Bitmap('0x7F'))
    tqmva = ((self.bits >> 6) & Bitmap('0x7'))
    extramva = ((self.bits >> 0) & Bitmap('0x3F'))
    self.valid = bool(valid.to_int())
    self.invr = invr.undigitize(True,15,2.60212e-7)*2.0 #/cm
    self.phi0 = fix_phi_range(phi0.undigitize(True,12,0.000340885))
    self.chi2rphi = get_bin_mean(chi2rphi.to_int(),CHI2RXBINS)
    self.tanl = tanl.undigitize(True,16,1.0/2.0**12)
    self.z0 = z0.undigitize(True,12,0.00999469) #cm
    self.chi2rz = get_bin_mean(chi2rz.to_int(),CHI2RXBINS)
    self.d0 = d0.undigitize(True,13,3.757580e-3) #cm
    self.bendchi2 = get_bin_mean(bendchi2.to_int(),CHI2BENDBINS)
    self.hitpattern = hitpattern.to_int()
    self.tqmva = tqmva.to_int()
    self.extramva = extramva.to_int()
    self.pt = 0.299792458*3.8112*0.01/self.invr #GeV
    self.eta = math.asinh(self.tanl)

  def __eq__(self, other):
    '''Equality operation that checks exact match between fields

    other   KfTrack to compare
    '''
    return (self.valid==other.valid and self.invr==other.invr and 
            self.phi0==other.phi0 and self.chi2rphi==other.chi2rphi and
            self.tanl==other.tanl and self.z0==other.z0 and
            self.chi2rz==other.chi2rz and self.d0==other.d0 and
            self.bendchi2==other.bendchi2 and self.hitpattern==other.hitpattern and
            self.tqmva==other.tqmva and self.extramva==other.extramva)

def loose_compare(track1, track2, verbose=False):
  '''Compares track1 and track2 allowing small differences. Returns true if
  the two tracks are very similar (see thresholds below).

  track1   KfTrack, first track to compare
  track2   KfTrack, second track to comapre
  verbose  bool used for debugging/extra information
  '''
  INVR_THRESHOLD = 0.001
  PHI0_THRESHOLD = 0.001
  CHI2RPHI_THRESHOLD = 1.0
  TANL_THRESHOLD = 0.01
  Z0_THRESHOLD = 0.2
  CHI2RZ_THRESHOLD = 1.0 
  D0_THRESHOLD = 0.1
  BENDCHI2_THRESHOLD = 0.5
  TQMVA_THRESHOLD = 1.5
  similar = True
  if (track1.valid != track2.valid):
    if (verbose):
      print('valid bit differs ('+str(track1.valid)+','+str(track2.valid)+')')
    similar = False
  if (abs(track1.invr-track2.invr)>INVR_THRESHOLD):
    if (verbose):
      print('1/R differs ('+str(track1.invr)+','+str(track2.invr)+')')
    similar = False
  if (abs(track1.phi0-track2.phi0)>PHI0_THRESHOLD):
    if (verbose):
      print('phi differs ('+str(track1.phi0)+','+str(track2.phi0)+')')
    similar = False
  if (abs(track1.chi2rphi-track2.chi2rphi)>CHI2RPHI_THRESHOLD):
    if (verbose):
      print('chi^2(r-phi) differs ('+str(track1.chi2rphi)+','+str(track2.chi2rphi)+')')
    similar = False
  if (abs(track1.tanl-track2.tanl)>TANL_THRESHOLD):
    if (verbose):
      print('tanL differs ('+str(track1.tanl)+','+str(track2.tanl)+')')
    similar = False
  if (abs(track1.z0-track2.z0)>Z0_THRESHOLD):
    if (verbose):
      print('z0 differs ('+str(track1.z0)+','+str(track2.z0)+')')
    similar = False
  if (abs(track1.chi2rz-track2.chi2rz)>CHI2RZ_THRESHOLD):
    if (verbose):
      print('chi^2(r-z) differs ('+str(track1.chi2rz)+','+str(track2.chi2rz)+')')
    similar = False
  if (abs(track1.d0-track2.d0)>D0_THRESHOLD):
    if (verbose):
      print('d0 differs ('+str(track1.d0)+','+str(track2.d0)+')')
    similar = False
  if (abs(track1.bendchi2-track2.bendchi2)>BENDCHI2_THRESHOLD):
    if (verbose):
      print('bendchi2 differs ('+str(track1.bendchi2)+','+str(track2.bendchi2)+')')
    similar = False
  if (track1.hitpattern != track2.hitpattern):
    if (verbose):
      print('hit pattern differs ('+hex(track1.hitpattern)+','+hex(track2.hitpattern)+')')
    similar = False
  if (abs(track1.tqmva-track2.tqmva)>TQMVA_THRESHOLD):
    if (verbose):
      print('Quality MVA differs ('+str(track1.tqmva)+','+str(track2.tqmva)+')')
    similar = False
  if (track1.extramva != track2.extramva):
    if (verbose):
      print('Extra MVA bits differ ('+str(track1.extramva)+','+str(track2.extramva)+')')
    similar = False
  return similar

def get_empdata(filename, channel, first_frame, last_frame):
  '''Gets hex string from EMP data in file with filename for a specific frame 
  and channel. Returns list of hex strings

  filename     string, name of file to open
  channel      int, channel number in file (i.e. column, not column number)
  first_frame  int, first frame to read (inclusive)
  last_frame   int, last frame to read (not inclusive).
  '''
  interested_frames = []
  with open(filename,'r') as input_file:
    content = input_file.read().split('\n')
    for iframe in range(first_frame,last_frame):
      interested_frames.append(content[iframe+4])
  data = []
  for frame in interested_frames:
    data.append(frame.split()[channel*2+3])
  return data

def trim_empdata(data):
  '''Removes trailing all-zero strings from EMP data
  
  data  list of strings of hex characters ex. from get_empdata
  '''
  while data[-1] == '0000000000000000':
    data.pop()
    if len(data)==0:
      return data
  return data

def empdata_to_kftracks(data):
  '''Convert EMP data (64-bit words) to (96-bit) track finder tracks. Returns
  list of KfTrack objects

  data  list of 64-bit (16 char) hex strings representing data from EMP
  '''
  if (len(data)%3 == 0):
    kf_tracks = []
    for iframe in range(0,len(data),3):
      kf_tracks.append(KfTrack(data[iframe]+data[iframe+1][:8]))
      kf_tracks.append(KfTrack(data[iframe+1][8:]+data[iframe+2]))
    return kf_tracks
  if (len(data)%3 == 2):
    kf_tracks = []
    for iframe in range(0,len(data)-2,3):
      kf_tracks.append(KfTrack(data[iframe]+data[iframe+1][:8]))
      kf_tracks.append(KfTrack(data[iframe+1][8:]+data[iframe+2]))
    kf_tracks.append(KfTrack(data[-2]+data[-1][:8]))
    return kf_tracks
  else:
    print(data)
    raise ValueError('Unexpected EMP data length.')

def interpret_fpga1output(filename, event):
  '''Reads EMP data output of FPGA1 for a given event and formats the output
  as a list of lists of AS data and merged TPAR data 

  filename  name of file to read
  event     event in file
  '''
  #setup output
  offset = 3
  result = []
  for AS_index in range(48):
    result.append([])
  for MPAR_index in range(15):
    result.append([])
  result.append([]) #for BX

  #read EMP input
  data_channels = dict()
  for channel in range(4,55):
    #currently setup for simulation column numbering, may need to change for real apollo
    if channel < 16:
      channel_in_file = channel-4 
    elif channel < 20:
      continue
    else:
      channel_in_file = channel-8
    data_channels[channel] = get_empdata(filename, channel_in_file, 
        108*event+offset, 108*(event+1)-6+offset)
  for clock_cycle in range(102):
    #parse EMP into pieces
    AS_string = '' #48
    MPAR_string = '' #15
    BX_string = ''
    for channel in range(35,3,-1):
      if channel<20 and channel>15:
        continue
      if channel==35:
        #skip first 16 bits
        AS_string += data_channels[channel][clock_cycle][4:]
      else:
        AS_string += data_channels[channel][clock_cycle]
    for channel in range(53,35,-1):
      if channel==53:
        #skip first 12 bits
        MPAR_string += data_channels[channel][clock_cycle][3:]
      else:
        MPAR_string += data_channels[channel][clock_cycle]
    BX_string = data_channels[54][clock_cycle][15]
    AS_bitmap = Bitmap(AS_string)
    MPAR_bitmap = Bitmap(MPAR_string)
    #reassemble pieces
    for AS_index in range(48):
      reverse_index = 47-AS_index
      result[AS_index].append(
          AS_bitmap.substring((reverse_index+1)*37,reverse_index*37).to_hexstring())
    for MPAR_index in range(15):
      reverse_index = 14-MPAR_index
      result[MPAR_index+48].append(
          MPAR_bitmap.substring((reverse_index+1)*76,reverse_index*76).to_hexstring())
    result[48+15].append(BX_string)

  return result

if __name__=='__main__':
  
  parser = argparse.ArgumentParser()
  parser.add_argument('-e','--emu_filename',default='mem/pre.txt')
  #parser.add_argument('-c','--cmp_filename',default='mem/out.txt')
  args = parser.parse_args()

  results = interpret_fpga1output('mem/tf1_sim_out.txt',0)
  for i in range(len(results)):
    print('Bit strings')
    print(results[i])

  #n_event = 100
  #n_track = 0
  #n_fail_event = 0
  #n_fail_track = 0

  ##Do comparison
  #if (print_event < 0):
  #  for ievent in range(100):
  #    initial_frame = ievent*108+6
  #    final_frame = (ievent+1)*108-1

  #    emu_tracks = []
  #    sim_tracks = []
  #    if not args.reducedconfig:
  #      emu_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 7, initial_frame, final_frame)))
  #      emu_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 6, initial_frame, final_frame)))
  #      sim_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 0, initial_frame, final_frame)))
  #      sim_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 1, initial_frame, final_frame)))
  #    else:
  #      emu_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 7, initial_frame, final_frame)))
  #      sim_tracks += empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 1, initial_frame, final_frame)))

  #    n_event_fail_track = 0
  #    fail_reason = ''

  #    if len(emu_tracks)!=len(sim_tracks):
  #      fail_reason += ('Different number of tracks ('+str(len(emu_tracks))+','+str(len(sim_tracks))+'). ')
  #      n_event_fail_track += len(emu_tracks)
  #    else:
  #      for itrack in range(len(emu_tracks)):
  #        comp = (emu_tracks[itrack]==sim_tracks[itrack])
  #        if not args.strictcompare:
  #          comp = loose_compare(emu_tracks[itrack], sim_tracks[itrack], True)
  #        if not comp:
  #          fail_reason += ('Track '+str(itrack)+' differs. ')
  #          n_event_fail_track += 1

  #    n_track += len(emu_tracks)
  #    n_fail_track += n_event_fail_track
  #    if (n_event_fail_track>0):
  #      n_fail_event += 1
  #      print('Event '+str(ievent)+' does not match. '+fail_reason)
  #    
  #  print('Failing events: '+str(n_fail_event)+'/'+str(n_event))
  #  print('Failing tracks: '+str(n_fail_track)+'/'+str(n_track))
  # 
  ##Do printout
  #else:
  #  for ievent in range(print_event,print_event+1):
  #    initial_frame = ievent*108+6
  #    final_frame = (ievent+1)*108-1
  #    if not args.reducedconfig:
  #      emu_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 7, initial_frame, final_frame)))
  #      sim_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 0, initial_frame, final_frame)))
  #      print('Emu tracks (+eta):')
  #      for track in emu_tracks:
  #        print_track_info(track)
  #      print('Sim tracks (+eta):')
  #      for track in sim_tracks:
  #        print_track_info(track)
  #      emu_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 6, initial_frame, final_frame)))
  #      sim_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 1, initial_frame, final_frame)))
  #      print('Emu tracks (-eta):')
  #      for track in emu_tracks:
  #        print_track_info(track)
  #      print('Sim tracks (-eta):')
  #      for track in sim_tracks:
  #        print_track_info(track)
  #    else:
  #      emu_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 7, initial_frame, final_frame)))
  #      sim_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 1, initial_frame, final_frame)))
  #      print('Emu tracks:')
  #      for track in emu_tracks:
  #        print_track_info(track)
  #      print('Sim tracks:')
  #      for track in sim_tracks:
  #        print_track_info(track)

    
