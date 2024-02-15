#!/usr/bin/env python
'''@package docstring
Script to cross-check EMP-style outputs
'''

import argparse
import math

CHI2RXBINS = [0.0, 0.25, 0.5, 1.0, 2.0, 3.0, 5.0, 7.0, 10.0, 20.0, 40.0, 100.0, 200.0, 500.0, 1000.0, 3000.0]
CHI2BENDBINS = [0.0, 0.5, 1.25, 2.0, 3.0, 5.0, 10.0, 50.0]

class Bitmap:
  '''class to work with bit data'''
  bit_decode = {True : '1', False : '0'}

  @staticmethod
  def trim_zeros(value):
    '''Returns value with leading zeros removed
    '''
    if not True in value:
      return [False]
    lead_index = value.index(True)
    return value[lead_index:]

  def __init__(self, initializer):
    '''initialize bitmap from a hex string or list of bools

    initializer   string of hex characters or list of bools
    '''
    self.value = []
    if isinstance(initializer,str):
      hex_string = initializer
      #MSB first
      if (hex_string[:2]=='0x'):
        hex_string = hex_string[2:]
      for char in hex_string:
        bin_string = bin(int(char,16))
        bin_string = bin_string[2:]
        if len(bin_string)<4:
          bin_string = ''.join(['0' for ibit in range((-1*len(bin_string))%4)]) + bin_string
        for bin_char in bin_string:
          if bin_char=='0':
            self.value.append(False)
          else:
            self.value.append(True)
      self.value = Bitmap.trim_zeros(self.value)
    elif isinstance(initializer,list):
      self.value = Bitmap.trim_zeros(initializer)
    else:
      raise ValueError('Invalid initializer type')

  def __and__(self, other):
    '''bitwise AND operation

    other   Bitmap to compare
    '''
    other_value = other.value
    self_value = self.value
    #pad one or other if needed
    if len(other_value)<len(self_value):
      other_value = [False for ibit in range(len(self_value)-len(other_value))] + other_value
    elif len(self_value)<len(other_value):
      self_value = [False for ibit in range(len(other_value)-len(self_value))] + self_value
    return_value = []
    for ibit in range(len(self_value)):
      return_value.append(self_value[ibit] & other_value[ibit])
    return Bitmap(Bitmap.trim_zeros(return_value))

  def __or__(self, other):
    '''bitwise OR operation

    other   Bitmap to compare
    '''
    other_value = other.value
    self_value = self.value
    #pad one or other if needed
    if len(other_value)<len(self_value):
      other_value = [False for ibit in range(len(self_value)-len(other_value))] + other_value
    elif len(self_value)<len(other_value):
      self_value = [False for ibit in range(len(other_value)-len(self_value))] + self_value
    return_value = []
    for ibit in range(len(self_value)):
      return_value.append(self_value[ibit] | other_value[ibit])
    return Bitmap(Bitmap.trim_zeros(return_value))

  def __invert__(self):
    '''bitwise NOT operation'''
    return_value = [not bit for bit in self.value]
    return Bitmap(Bitmap.trim_zeros(return_value))

  def __rshift__(self, other):
    '''bitwise right shift operation

    other   int, number of bits to shift
    '''
    return Bitmap(self.value[:-1*other])

  def __lshift__(self, other):
    '''bitwise left shift operation

    other   int, number of bits to shift
    '''
    return Bitmap(self.value + [False for ibit in range(other)])

  def to_hexstring(self):
    '''Returns string of hex characters representing Bitmap content'''
    hex_string = ''
    bin_string = ''
    pad_length = (-1*len(self.value))%4
    self_value_reverse = self.value[::-1] + [False for ibit in range(pad_length)]
    for bit in self_value_reverse:
      bin_string = Bitmap.bit_decode[bit]+bin_string
      if len(bin_string)==4:
        hex_string = hex(int(bin_string,2))[2:] + hex_string
        bin_string = ''
    return hex_string

  def to_int(self):
    '''Returns unsigned integer representing Bitmap content'''
    return int(self.to_hexstring(),16)

  def to_signedint(self, length):
    '''Returns signed (two's complement) integer representing Bitmap content
    
    length   number of bits
    '''
    #pad to length
    while (len(self.value) < length):
      self.value = [False] + self.value
    if (self.value[0] == False):
      return self.to_int()
    else:
      return -1*((~ self).to_int()+1)

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
    invr = ((self.bits >> 80) & Bitmap('0xEFFF'))
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
  and channel

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
    raise ValueError('Unexpected EMP data length.')

if __name__=='__main__':
  
  parser = argparse.ArgumentParser()
  parser.add_argument('-s','--strict_compare',action='store_true')
  parser.add_argument('-e','--emu_filename',default='pre.txt')
  parser.add_argument('-c','--cmp_filename',default='/mnt/scratch1/mco62/emp_project_reduced/proj/vsim/vsim/vsim.sim/sim_1/behav/xsim/out.txt')
  args = parser.parse_args()

  n_event = 100
  n_track = 0
  n_fail_event = 0
  n_fail_track = 0

  for ievent in range(100):
    #ievent = 91
    initial_frame = ievent*108+6
    final_frame = (ievent+1)*108-1

    emu_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 7, initial_frame, final_frame)))
    #emu_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.emu_filename, 1, initial_frame, final_frame)))
    sim_tracks = empdata_to_kftracks(trim_empdata(get_empdata(args.cmp_filename, 1, initial_frame, final_frame)))

    n_event_fail_track = 0
    fail_reason = ''

    if len(emu_tracks)!=len(sim_tracks):
      fail_reason += ('Different number of tracks ('+str(len(emu_tracks))+','+str(len(sim_tracks))+'). ')
      n_event_fail_track += len(emu_tracks)
    else:
      for itrack in range(len(emu_tracks)):
        comp = (emu_tracks[itrack]==sim_tracks[itrack])
        if not args.strict_compare:
          comp = loose_compare(emu_tracks[itrack], sim_tracks[itrack], True)
        if not comp:
          fail_reason += ('Track '+str(itrack)+' differs. ')
          n_event_fail_track += 1

    n_track += len(emu_tracks)
    n_fail_track += n_event_fail_track
    if (n_event_fail_track>0):
      n_fail_event += 1
      print('Event '+str(ievent)+' does not match. '+fail_reason)
    
  print('Failing events: '+str(n_fail_event)+'/'+str(n_event))
  print('Failing tracks: '+str(n_fail_track)+'/'+str(n_track))
    
