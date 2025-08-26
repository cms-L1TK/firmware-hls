"""Utilities for manipulating TF and EMP data

Provides Bitmap and EmpData classes as well as various methods for 
transforming between EMP/CSP style data and TF words that are used for 
generating input and checking output in hardware. See other scripts
that include this for usage

MO 2024-12-05
"""

from __future__ import annotations
import argparse
import math

CHAR_TO_BOOL = {'0' : False, '1' : True}

BOOL_TO_CHAR = {False : '0', True : '1'}

EMP_INFO_STRING = ('Metadata: (strobe,) start of orbit, start of packet, '
                   'end of packet, valid')

DL_NAMES = ['PS10G_1_A','PS10G_1_B','PS10G_2_A','PS10G_2_B','PS10G_3_A',
            'PS10G_3_B','PS10G_4_A','PS10G_4_B','PS_1_A','PS_1_B','PS_2_A',
            'PS_2_B','negPS10G_1_A','negPS10G_1_B','negPS10G_2_A',
            'negPS10G_2_B','negPS10G_3_A','negPS10G_3_B','negPS10G_4_A',
            'negPS10G_4_B','negPS_1_A','negPS_1_B','negPS_2_A','negPS_2_B',
            '2S_1_A','2S_1_B','2S_2_A','2S_2_B','2S_3_A','2S_3_B',
            '2S_4_A','2S_4_B','2S_5_A','2S_5_B','2S_6_A','2S_6_B',
            'neg2S_1_A','neg2S_1_B','neg2S_2_A','neg2S_2_B','neg2S_3_A',
            'neg2S_3_B','neg2S_4_A','neg2S_4_B','neg2S_5_A','neg2S_5_B',
            'neg2S_6_A','neg2S_6_B']

#Note the order of DL_CHANNELS corresponds to the order of DL_NAMES. If the 
#convention for DL channel mapping changes in FW, this list and DL_NAMES 
#should be appropriately reordered
DL_CHANNELS = [68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 84, 85, 86, 87,
               88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 
               103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
               116, 117, 118, 119]

AS_NAMES = ['D5PHID', 'D5PHIC', 'D5PHIB', 'D5PHIA', 'D4PHID', 'D4PHIC', 
            'D4PHIB', 'D4PHIA', 'D3PHID', 'D3PHIC', 'D3PHIB', 'D3PHIA', 
            'D2PHID', 'D2PHIC', 'D2PHIB', 'D2PHIA', 'D1PHID', 'D1PHIC', 
            'D1PHIB', 'D1PHIA', 'L6PHID', 'L6PHIC', 'L6PHIB', 'L6PHIA', 
            'L5PHID', 'L5PHIC', 'L5PHIB', 'L5PHIA', 'L4PHID', 'L4PHIC', 
            'L4PHIB', 'L4PHIA', 'L3PHID', 'L3PHIC', 'L3PHIB', 'L3PHIA', 
            'L2PHID', 'L2PHIC', 'L2PHIB', 'L2PHIA', 'L1PHIH', 'L1PHIG', 
            'L1PHIF', 'L1PHIE', 'L1PHID', 'L1PHIC', 'L1PHIB', 'L1PHIA']

MPAR_NAMES = ['L2D1ABCD', 'L1D1EFGH', 'L1D1ABCD', 'D3D4ABCD', 'D1D2ABCD', 
              'L5L6ABCD', 'L3L4CD', 'L3L4AB', 'L2L3ABCD', 'L1L2JKL', 'L1L2HI', 
              'L1L2G', 'L1L2F', 'L1L2DE', 'L1L2ABC']

def fix_phi_range(phi: float) -> float:
  """Forces an angle into the range (-pi,pi)

  Args:
    phi: unnormalized angle

  Returns
    phi normalized into the range (-pi,pi)
  """
  while phi>3.1416:
    phi -= 2.0*3.1416
  while phi<-3.1416:
    phi += 2.0*3.1416
  return phi

def trim_zeros(bitstring: str) -> str:
  """Remove leading zeros in bitstring

  Args:
    bitstring: binary string with no prefix

  Returns:
    bitstring with the leading zeros removed
  """
  first_one_pos = bitstring.find('1')
  if first_one_pos == -1:
    return '0'
  return bitstring[first_one_pos:]

def zero_pad(bitstring: str, length: int) -> str:
  """Pads a bitstring to at least length by adding leading zeros

  Args:
    bitstring: binary string to pad with no prefix
    length: minimum length of resulting bitmap

  Returns:
    bistring padded to at least length
  """
  len_difference = length-len(bitstring)
  new_bitstring = bitstring
  if len_difference > 0:
    new_bitstring = ''.join(['0' for i in range(len_difference)]) + bitstring
  return new_bitstring

def r_to_pt(r: float) -> float:
  """Converts track radius of curvature (in cm) to transverse momentum (in GeV)

  Args:
    r: Track radius of curvature in cm

  Returns:
    pT, track transverse momentum in GeV
  """
  return 0.299792458*3.8112*0.01*r

class Bitmap:
  """Class to work with bit data

  Attributes:
    value: binary string with MSB first
  """

  def __init__(self, value: str):
    """Initializes bitmap

    Args:
      value: binary or hex string. Binary strings must be prefixed with 'bin'

    Raises:
      ValueError in the case of uninterpretable input strings
    """
    if (value[:3]=='bin'):
      value = value[3:]
      n_valid_chars = value.count('0')+value.count('1')+value.count('U')
      if n_valid_chars != len(value):
        raise ValueError('Binary string contains characters other than '
                         '0, 1, and U')
      self.value = value.replace('U','0')
    else:
      if value[:2] in ['0x']:
        value = value[2:]
      if len(value)==0:
        self.value = ''
      else:
        bin_length = len(value)*4
        bin_string = bin(int(value,16))
        self.value = zero_pad(bin_string[2:],bin_length)

  def __and__(self, other: Bitmap) -> Bitmap:
    """bitwise AND operation

    Args:
      other: bitmap to AND with

    Returns:
      AND of self and other. If lengths are unequal, the shorter bitmap will
      be left-padded with zeros
    """
    other_value = other.value
    self_value = self.value
    max_length = max(len(self_value, other_value))
    other_value = zero_pad(other_value, max_length)
    self_value = zero_pad(self_value, max_length)
    result = ''
    for self_bit, other_bit in zip(self_value, other_value):
      result += BOOL_TO_CHAR[CHAR_TO_BOOL[self_bit] & CHAR_TO_BOOL[other_bit]]
    return Bitmap('bin'+result)

  def __or__(self, other: Bitmap) -> Bitmap:
    """bitwise OR operation

    Args:
      other: bitmap to OR with

    Returns:
      OR of self and other. If lengths are unequal, the shorter bitmap will
      be left-padded with zeros
    """
    other_value = other.value
    self_value = self.value
    max_length = max(len(self_value, other_value))
    other_value = zero_pad(other_value, max_length)
    self_value = zero_pad(self_value, max_length)
    result = ''
    for self_bit, other_bit in zip(self_value, other_value):
      result += BOOL_TO_CHAR[CHAR_TO_BOOL[self_bit] | CHAR_TO_BOOL[other_bit]]
    return Bitmap('bin'+result)

  def __invert__(self) -> Bitmap:
    """bitwise NOT operation

    Returns:
      bitwise not of self
    """
    result = ''.join(BOOL_TO_CHAR[not CHAR_TO_BOOL[bit]] for bit in self.value)
    return Bitmap('bin'+result)

  def __rshift__(self, other: int) -> Bitmap:
    """bitwise right shift operation

    Args:
      other: how much to shift by

    Returns:
      self right shifted by other
    """
    return Bitmap('bin'+self.value[:len(self-value)-other])

  def __lshift__(self, other: int) -> Bitmap:
    """bitwise left shift operation

    Args:
      other: how much to shift by

    Returns:
      self left shifted by other
    """
    return Bitmap('bin'+self.value + ''.join(['0' for i in range(other)]))

  def to_hexstring(self) -> str:
    """Convert to string of hex characters

    Returns:
      hex string representation of self (with no leading 0x)
    """
    if self.value == '':
      return '0'
    mod4 = len(self.value)%4
    pad_value = self.value
    if mod4 != 0:
      pad_value = zero_pad(self.value, len(self.value)+(4-mod4))
    hex_string = ''
    for digit in range(len(pad_value)//4):
      hex_string += hex(int(pad_value[(digit)*4:(digit+1)*4],2))[2:]
    return hex_string

  def to_binstring(self) -> str:
    """Convert to string of binary characters

    Returns:
      binary string representation of self (with no leading 0b/bin)
    """
    if self.value == '':
      return '0'
    return self.value

  def to_int(self) -> int:
    """Convert to unsigned integer

    Returns:
      integer represented by this bitmap
    """
    if self.value == '':
      return 0
    return int(self.value,2)

  def to_signedint(self) -> int:
    """Convert to signed integer

    Args:
      length: number of bits, -1 uses default length

    Returns:
      integer represented by this bitmap
    """
    if self.value == '':
      return 0
    value = self.value
    if value[0]=='0':
      return int(self.value,2)
    else:
      return -1*((~self).to_int()+1)

  def append(self, other: Bitmap) -> Bitmap:
    """Append another bitmap
    
    Args:
      other: bitmap to append

    Returns:
      a bitmap that is self with other appended
    """
    return Bitmap('bin' + self.value + other.value)

  def undigitize(self, is_signed: bool, granularity: float) -> float:
    """Convert to float based on digitization scheme

    Args:
      is_signed: whether bitmap is signed or unsigned
      granularity: binning size of digitization

    Returns:
      float represented by this bitmap under given conditions
    """
    int_value = 0
    if is_signed:
      int_value = self.to_signedint()
    else:
      int_value = self.to_int()
    return (float(int_value)+0.5)*granularity

  def undigitze_binning(self, bin_boundaries: list[float]) -> float:
    """Convert to float based on digitization binning scheme

    Args:
      bin_boundaries: bin boundaries. Length must match bitmap range

    Returns:
      mean of bin into which digitized value falls

    Raises:
      ValueError: bin_boundary length not appropriate
    """
    if 2**len(self.value)!=len(bin_boundaries):
      raise ValueError('Number of bins does not match bitmap size.')
    index = self.to_int()
    return (bin_boundaries[index]+bin_boundaries[index+1])/2.0

  def substring(self, end: int, start: int) -> Bitmap:
    """Returns sub-bitmap 

    Args:
      end: ending index counting from LSB
      start: starting index counting from LSB

    Returns:
      sub-bitmap from start to end inclusively and counting from the LSB.
      For example Bitmap('bin10111010').substring(3,0) is equal to 
      Bitmap('bin1010'). This is similar to ex. VHDL bitmap(3 downto 0)

    Raises:
      ValueError if either start or end is out of range
    """
    if start<0 or end<0:
      raise ValueError('Substring index out of bounds')
    if start>=len(self.value) or end>=len(self.value):
      raise ValueError('Substring index out of bounds')
    start = len(self.value)-start
    end = len(self.value)-end-1
    return Bitmap('bin'+self.value[end:start])

class EmpData:
  """Class to work with EMP formatted data

  Attributes:
    id: EMP ID
    channels: list of channel indices
    data: EMP metadata (4-5 bit bitmaps) organized as a list of lists, one
          per channel
    data: EMP data packets (64 bit bitmaps) organized as a list of lists, one
          per channel
  """

  def __init__(self, channels: list[int]):
    """Initializes empty EMP data

    Args:
      channels: channels to be represented in EMP data columns
    """
    self.id = 'x0'
    self.channels = channels
    self.metadata = [[] for i in range(len(channels))]
    self.data = [[] for i in range(len(channels))]

  def slice_rows(self, start_frame: int, end_frame: int) -> EmpData:
    """Returns a subset of the EMP data

    Args:
      start_frame: frame to start subset, inclusive
      end_frame: frame to end subset, not inclusive

    Returns:
      a copy of this EMP data with only the data between start_frame and 
      end_frame
    """
    sub_data = EmpData(self.channels)
    sub_data.id = self.id
    for iframe in range(start_frame, end_frame):
      for ichannel in range(len(self.channels)):
        sub_data.metadata[ichannel].append(self.metadata[ichannel][iframe])
        sub_data.data[ichannel].append(self.data[ichannel][iframe])
    return sub_data

  def append(self, other: EmpData):
    """Appends other EMP data to the end of current EMP data

    Args:
      other: another EMP data set with the same number of columns

    Raises:
      ValueError if number of columns incompatible
    """
    if not len(self.channels)==len(other.channels):
      raise ValueError('Incompatible number of channels in append.')
    for iframe in range(len(other.data[0])):
      for ichannel in range(len(self.channels)):
        self.metadata[ichannel].append(other.metadata[ichannel][iframe])
        self.data[ichannel].append(other.data[ichannel][iframe])

  def write_to_file(self, filename: str):
    """Output EMP data to a file

    Args:
      filename: name of file to write to
    """
    with open(filename, 'w') as output_file:
      output_file.write('ID: {}\n'.format(self.id))
      output_file.write('{}\n\n'.format(EMP_INFO_STRING)) 
      output_file.write('      Link              ')
      for channel in self.channels:
        output_file.write('{}                    '.format(
            str(channel).zfill(3)))
      output_file.write('\n')
      for frame in range(len(self.data[0])):
        output_file.write('Frame {}    '.format(str(frame).zfill(4)))
        for channel in range(len(self.channels)):
          output_file.write('{} {}  '.format(
              self.metadata[channel][frame].to_binstring(),
              self.data[channel][frame].to_hexstring()))
        output_file.write('\n')
    print('Saved output to {}'.format(filename))

  def frame_data(self, frame: int) -> list[Bitmap]:
    """Returns list of bitmaps for a given frame

    Args:
      frame: frame to retreive

    Returns:
      data for given frame, indexed by channel
    """
    data = []
    for channel in range(len(self.channels)):
      data.append(self.data[channel][frame])
    return data

  def frame_metadata(self, frame: int) -> list[Bitmap]:
    """Returns list of bitmaps for a given frame

    Args:
      frame: frame to retreive

    Returns:
      metadata for given frame, indexed by channel
    """
    data = []
    for channel in range(len(self.channels)):
      data.append(self.metadata[channel][frame])
    return data

class TBWord:
  """Class to interpret tracks output by TB

  Attributes:
    bitmap: raw bitmap representation of word
  """

  def __init__(self, bitmap: Bitmap):
    """Constructor

    Args:
      bitmap: bitmap of track word data
    """
    self.bitmap = bitmap

  def valid(self) -> bool:
    """Returns valid bit

    Returns:
      true if word is valid, false otherwise
    """
    return (self.bitmap.substring(103,103).to_int()==1)

  def invr(self) -> float:
    """Returns 1/track curvature radius in /cm

    Returns:
      1/R where R is track curvature radius in cm
    """
    return self.bitmap.substring(79,66).undigitize(True,1.04549e-6)

  def phi0(self) -> float:
    """Returns track azimuthal angle at origin

    Returns:
      phi0, azimuthal angle at origin (rel to sector?)
    """
    return self.bitmap.substring(65,48).undigitize(True,1.56824e-5)

  def z0(self) -> float:
    """Returns track longitudinal displacement in cm

    Returns:
      z0, longitudinal displacement in cm
    """
    return self.bitmap.substring(47,38).undigitize(True,0.0585938)

  def tanl(self) -> float:
    """Returns tan(lambda)=cot(theta)

    Returns:
      cotangent of polar angle
    """
    return self.bitmap.substring(37,24).undigitize(True,0.00195312)

  def pt(self) -> float:
    """Returns track pT in GeV

    Returns:
      pT, transerve momentum in GeV
    """
    return r_to_pt(1.0/self.invr())

  def eta(self) -> float:
    """Returns pseudorapidity

    Returns:
      eta, pseudorapidity
    """
    return math.asinh(self.tanl())

  def print(self):
    """Prints track properties
    """
    print(('TW {}: valid: {}, 1/R: {} cm-1, pT: {} GeV, phi: {}, z0: {}, '
           +'cottheta: {}, eta: {}').format(self.bitmap.to_hexstring(),
           self.valid(),self.invr(),self.pt(),self.phi0(),self.z0(),self.tanl(),
           self.eta()))

class TQWord:
  """Class to interpret tracks output by KF/TQ

  Attributes:
    bitmap: raw bitmap representation of word
  """

  def __init__(self, bitmap: Bitmap):
    """Constructor

    Args:
      bitmap: bitmap of track word data
    """
    self.bitmap = bitmap

  def valid(self) -> bool:
    """Returns valid bit

    Returns:
      true if word is valid, false otherwise
    """
    return (self.bitmap.substring(95,95).to_int()==1)

  def invr(self) -> float:
    """Returns 1/(2x?)track curvature radius in /cm

    Returns:
      1/R (1/2R?) where R is track curvature radius in cm
    """
    return self.bitmap.substring(94,80).undigitize(True,2.60212e-07 )

  def phi0(self) -> float:
    """Returns track azimuthal angle at origin

    Returns:
      phi0, azimuthal angle at origin rel to sector center
    """
    return self.bitmap.substring(79,68).undigitize(True,0.000340885)

  def z0(self) -> float:
    """Returns track longitudinal displacement in cm

    Returns:
      z0, longitudinal displacement in cm
    """
    return self.bitmap.substring(47,36).undigitize(True,0.00999469)

  def tanl(self) -> float:
    """Returns tan(lambda)=cot(theta)

    Returns:
      cotangent of polar angle
    """
    return self.bitmap.substring(63,48).undigitize(True,0.000244141)

  def pt(self) -> float:
    """Returns track pT in GeV

    Returns:
      pT, transerve momentum in GeV
    """
    return r_to_pt(1.0/self.invr())

  def eta(self) -> float:
    """Returns pseudorapidity

    Returns:
      eta, pseudorapidity
    """
    return math.asinh(self.tanl())

  def print(self):
    """Prints track properties
    """
    print(('TW {}: valid: {}, 1/R: {} cm-1, pT: {} GeV, phi: {}, z0: {}, '
           +'cottheta: {}, eta: {}').format(self.bitmap.to_hexstring(),
           self.valid(),self.invr(),self.pt(),self.phi0(),self.z0(),self.tanl(),
           self.eta()))

def load_emp_data(filename: str) -> EmpData:
  """Reads data from EMP file and stores result as EmpData object

  Args:
    filename: name of EMP file

  Returns:
    EmpData object with data
  """
  #In the EMP format, the first 3 lines are uninteresting, the 4th has channel
  #indices, and all subsequent lines have data
  with open(filename,'r') as input_file:
    for i in range(3):
      input_file.readline()
    channel_line = input_file.readline()[:-1]
    channel_indices = [int(index) for index in channel_line.split()[1:]]
    n_channels = len(channel_indices)
    emp_data = EmpData(channel_indices)
    line_content = input_file.readline()
    while 'Frame' in line_content:
      #in a given line, the format is:
      #Frame <frame no> <meta1> <data1> <meta2> <data2>...
      line_content_split = line_content.split()
      for column in range(n_channels):
        emp_data.metadata[column].append(Bitmap('bin'+line_content_split[column*2+2]))
        emp_data.data[column].append(Bitmap(line_content_split[column*2+3]))
      line_content = input_file.readline()
  return emp_data

def get_first_valid_nonempty_word(emp_data: EmpData, channel_idx: int) -> int:
  """Finds row of first nonempty valid data word for given column 

  Arg: 
    emp_data: emp data to search through
    channel_idx: target channel (column) index (NOT channel name)

  Returns:
    frame (row) index of first nonempty valid data word. If no nonempty valid
    words in channel, returns 0
  """
  for iframe in range(len(emp_data.data[0])):
    channel_data = emp_data.frame_data(iframe)[channel_idx]
    channel_metadata = emp_data.frame_metadata(iframe)[channel_idx]
    if ((channel_data.to_int() != 0) 
        and (channel_metadata.substring(3,3).to_int() == 1)):
      return iframe
  return -1

def fpga1_link_to_words(link_data: list[Bitmap]) -> dict[str,Bitmap]:
  """Converts FPGA1 output from EMP style links into TF words

  Args:
    link_data: data as it appears on CSP links at FPGA1 output, assumed 
      the data is ordered by channels 4-15,20-54

  Returns:
    data formatted as a dictionary of TF word bitmaps
  """

  #first concatenate everything
  as_bitmap = Bitmap('')
  mpar_bitmap = Bitmap('')
  #links 4-15,20-35 have AllStub data
  for channel in range(28):
    as_bitmap = as_bitmap.append(link_data[27-channel])
  #links 36-53 have MergedTrackletParameter data
  for channel in range(18):
    mpar_bitmap = mpar_bitmap.append(link_data[17-channel+28])
  #link 54 has BX
  bx_bitmap = link_data[46]
  
  #then split into TF words
  tf_words = {}
  for ias in range(len(AS_NAMES)):
    as_name = 'AS'+AS_NAMES[len(AS_NAMES)-1-ias]
    tf_words[as_name] = as_bitmap.substring(37*(ias+1)-1,37*ias)
  for impar in range(len(MPAR_NAMES)):
    mpar_name = 'MPAR'+MPAR_NAMES[len(MPAR_NAMES)-1-impar]
    tf_words[mpar_name] = mpar_bitmap.substring(76*(impar+1)-1,76*impar)
  tf_words['BX'] = bx_bitmap
  
  return tf_words

def fpga2_words_to_link(words: dict[str,Bitmap]) -> list[Bitmap]:
  """Converts FPGA2 input from TF words into EMP style link words

  Args:
    words: EMP data words, organized as a dictionary mapping strings to 
    bitmaps

  Returns:
    data as it appears on CSP links at FPGA input, assumed the data is ordered
    by channels 10-43,48-59
  """

  #first concatenate everything
  #add extra 64 bits of zeros so we can treat links uniformly below
  as_bitmap = Bitmap('0x0000000000000000')
  mpar_bitmap = Bitmap('0x0000000000000000')
  #AS names are ordered so D5PHID first and L1PHIA last
  for ias in range(len(AS_NAMES)):
    as_name = 'AS'+AS_NAMES[ias]
    as_bitmap = as_bitmap.append(words[as_name])
  #MPAR names are ordered so  L2D1ABCD is first and L1L2ABC is last
  for impar in range(len(MPAR_NAMES)):
    mpar_name = 'MPAR'+MPAR_NAMES[impar]
    mpar_bitmap = mpar_bitmap.append(words[mpar_name])
  
  #then split into links
  link_data = []
  for ilink in range(10,28):
    i = 27-ilink
    link_data.append(mpar_bitmap.substring(63+i*64, i*64))
  for ilink in range(28,44):
    i = 55-ilink
    link_data.append(as_bitmap.substring(63+i*64, i*64))
  for ilink in range(48,60):
    i = 59-ilink
    link_data.append(as_bitmap.substring(63+i*64, i*64))
  
  return link_data

def create_empdata_fpga2_input(data: list[dict[str,list[Bitmap]]]) -> EmpData:
  """Generates EMP input to FPGA2 using given data

  Args:
    data: list (indexed by event) of dictionary (indexed by memory name) of
          lists of bitmaps for the words. Note that the words should NOT 
          include the valid bit

  Returns:
    EmpData with FPGA2-style input
  """
  link_data = EmpData([i for i in range(9,44)]+[i for i in range(48,60)])
  bitmap_one = Bitmap('bin1')
  ievent = 0
  for event in range(len(data)):
    event_data = data[event]
    for iframe in range(6):
      abs_frame = iframe+ievent*108
      for ichannel in range(47):
        link_data.metadata[ichannel].append(default_metadata(abs_frame))
        link_data.data[ichannel].append(make_zero_bitmap(64))
    for iframe in range(102):
      abs_frame = iframe+6+ievent*108
      frame_words = {}
      for ias in range(len(AS_NAMES)):
        as_name = 'AS'+AS_NAMES[ias]
        if iframe<len(event_data[as_name]):
          frame_words[as_name] = bitmap_one.append(event_data[as_name][iframe])
        else:
          frame_words[as_name] = make_zero_bitmap(37)
      for impar in range(len(MPAR_NAMES)):
        mpar_name = 'MPAR'+MPAR_NAMES[impar]
        if iframe<len(event_data[mpar_name]):
          frame_words[mpar_name] = bitmap_one.append(
              event_data[mpar_name][iframe])
        else:
          frame_words[mpar_name] = make_zero_bitmap(76)
      frame_link_data = fpga2_words_to_link(frame_words)
      #first channel is BX
      link_data.metadata[0].append(default_metadata(abs_frame))
      if iframe == 0 and event==1:
        link_data.data[0].append(Bitmap('00000000D057A271'))
      else:
        link_data.data[0].append(Bitmap(zero_pad(hex(ievent%8)[2:],16)))
      for ichannel in range(46):
        link_data.metadata[ichannel+1].append(default_metadata(abs_frame))
        link_data.data[ichannel+1].append(frame_link_data[ichannel])
    ievent += 1
  return link_data

def get_words_fpga1_empdata(emp_data: EmpData, 
    offset: int) -> dict[str,list[Bitmap]]:
  """Gets TF words for a given event from EMP data

  Args:
    emp_data: EMP data to process in FPGA1 output format
    offset: event offset in frames from the beginning of the data

  Returns:
    dictionary of lists of TF word bitmaps, indexed by memory name 
  """
  tf_words = {}
  all_names = []
  for as_name in AS_NAMES:
    all_names.append('AS'+as_name)
  for mpar_name in MPAR_NAMES:
    all_names.append('MPAR'+mpar_name)
  all_names.append('BX')

  for name in all_names:
    tf_words[name] = []
  
  for frame in range(108):
    events_words = fpga1_link_to_words(emp_data.frame_data(frame+offset))
    for name in all_names:
      tf_words[name].append(events_words[name])

  return tf_words

def get_words_fpga2_empdata(emp_data: EmpData, 
    offset: int) -> (list[Bitmap],list[Bitmap]):
  """Gets TF words for a given event from EMP data

  Args:
    emp_data: EMP data to process in FPGA2 output format
    offset: event offset in frames from the beginning of the data

  Returns:
    tuple (indexed by channel = eta sign) of lists of TF track bitmaps
  """
  eta_lists = ([],[])

  for frame in range(34):
    f1 = emp_data.frame_data(frame*3+offset)
    f2 = emp_data.frame_data(frame*3+offset+1)
    f3 = emp_data.frame_data(frame*3+offset+2)
    for ieta in range(2):
      eta_lists[ieta].append(f1[ieta].append(f2[ieta].substring(63,32)))
      eta_lists[ieta].append(f2[ieta].substring(31,0).append(f3[ieta]))

  return eta_lists

def get_memprints_words(filename: str, event: int) -> list[Bitmap]:
  """Get list of words for given event from MemPrints file

  Args:
    filename: name of file
    event: event whose data to retrieve

  Returns:
    list of bitmaps
  """
  words = []

  with open(filename) as input_file:
    lines = input_file.readlines()
    current_event = False
    for line in lines:
      if not current_event:
        if ('Event : {}\n'.format(event) in line):
          current_event = True
      elif current_event:
        if not ('Event : ' in line):
          line_terms = line.split(' ')
          bit_string = ''
          if len(line_terms)==3:
            bit_string = (line_terms[1]).replace('|','')
          else:
            #special case to handle MPAR, need to add page index bits
            bit_string = bin(int(line_terms[0][3],16))[2:]
            if len(bit_string)<2:
              bit_string = '0'+bit_string
            bit_string += (line_terms[2]).replace('|','')
          words.append(Bitmap('bin'+bit_string))
        else:
          current_event = False

  return words

def get_output_fpga1_memprints(memprints_dir: str, 
    event: int) -> dict[str,list[Bitmap]]:
  """Gets FPGA1 output words for given event from MemPrints

  Args:
    memprints_dir: MemPrints directory location
    event: which event to get data for

  Returns
    dictionary of lists of TF word bitmaps, indexed by memory name
  """
  data = {}
  for as_name in AS_NAMES:
    data['AS'+as_name] = get_memprints_words(
        '{}/Stubs/AllStubs_AS_{}n1_04.dat'.format(memprints_dir,as_name),event)
  for mpar_name in MPAR_NAMES:
    data['MPAR'+mpar_name] = get_memprints_words(
        '{}/TrackletParameters/TrackletParameters_MPAR_{}_04.dat'.format(
        memprints_dir,mpar_name),event)
  return data

def get_input_fpga1_memprints(memprints_dir: str, 
    event: int) -> dict[str,list[Bitmap]]:
  """Gets FPGA1 input words for given event from MemPrints

  Args:
    memprints_dir: MemPrints directory location
    event: which event to get data for

  Returns
    dictionary of lists of TF word bitmaps, indexed by memory name
  """
  data = {}
  for dl_name in DL_NAMES:
    data['DL'+dl_name] = get_memprints_words(
        '{}/InputStubs/Link_DL_{}_04.dat'.format(memprints_dir,dl_name),event)
  return data

def make_zero_bitmap(length: int) -> Bitmap:
  """Creates a bitmap of all zeros

  Args:
    length: length of bitmap

  Returns:
    An all-zero bitmap of length length
  """
  return Bitmap('bin'+''.join(['0' for i in range(length)]))
  
def default_metadata(frame: int) -> Bitmap:
  """Returns default metadata for given frame

  Args:
    frame: frame

  Returns
    0b1101 if frame = 6
    0b0000 if frame < 6 mod 108
    0b0101 if frame = 6 mod 108
    0b0001 if 6 < frame < 107 mod 108
    0b0011 if frame = 107 mod 108
  """
  if frame==6:
    return Bitmap('bin1101')
  elif (frame%108)<6:
    return Bitmap('bin0000')
  elif (frame%108)==6:
    return Bitmap('bin0101')
  elif (frame%108)<107:
    return Bitmap('bin0001')
  else:
    return Bitmap('bin0011')

def create_empdata_fpga1_input(memprints_dir: str, event_start: int,
    event_end: int) -> EmpData:
  """Generates an EmpData object with FPGA1 input words

  Args:
    memprints_dir: MemPrints directory location
    event_start: first event, inclusive
    event_end: last event, not inclusive

  Returns:
    EmpData object constructed from DL MemPrints
  """
  data = EmpData(DL_CHANNELS)
  ievent = 0
  for event in range(event_start, event_end):
    dl_data = get_input_fpga1_memprints(memprints_dir, event)
    #truncate or pad each list to 102 entries, then pad to 108
    for idl in range(len(DL_NAMES)):
      dl_name = 'DL'+DL_NAMES[idl]
      if len(dl_data[dl_name])>102:
        dl_data[dl_name] = dl_data[dl_name][:108]
      while len(dl_data[dl_name])<102:
        dl_data[dl_name].append(make_zero_bitmap(39))
      for i in range(6):
        dl_data[dl_name].insert(0,make_zero_bitmap(39))
    #add words to EmpData object
    for iframe in range(108):
      for idl in range(len(DL_NAMES)):
        dl_name = 'DL'+DL_NAMES[idl]
        data.metadata[idl].append(default_metadata(iframe+ievent*108))
        data.data[idl].append(Bitmap('bin'+zero_pad(
            dl_data[dl_name][iframe].value,64)))
    ievent += 1
  return data

def range_string_to_list(range_string: str) -> list[int]:
  """Converts EMP-style range string to list of integers

  Args:
    range_string: string specifying integers using single integers (ex. 42), 
    dashed ranges (ex. 10-20), and combinations there of (ex. 10-20,42)
  """
  range_list = []
  range_substrings = []
  if ',' in range_string:
    range_substrings = range_string.split(',')
  else:
    range_substrings = [range_string]
  for range_substring in range_substrings:
    if '-' in range_substring:
      range_start = int(range_substring.split('-')[0])
      range_end = int(range_substring.split('-')[1])
      for i in range(range_start, range_end+1):
        range_list.append(i)
    else:
      range_list.append(int(range_substring))
  return range_list

def remove_empty_bitmaps_in_list(bitmap_list: list[Bitmap]) -> list[Bitmap]:
  """Returns a version of bitmap_list with empty words removed

  Args:
    bitmap_list: original list

  Returns:
    a copy of bitmap_list with empty words removed
  """
  ret_list = []
  for bitmap in bitmap_list:
    if bitmap.to_int()!=0:
      ret_list.append(Bitmap('bin'+bitmap.value))
  return ret_list

def strip_leading_bits(bitmap_list: list[Bitmap],
    n_remove: int) -> list[Bitmap]:
  """Removes n_remove leading bits from each bitmap in given list

  Args:
    bitmap_list: starting list of bitmaps
    n_remove: number of bits to remove

  Returns:
    A copy of bitmap_list where each bitmap has n_remove leading bits removed
  """
  ret_list = []
  for bitmap in bitmap_list:
    ret_list.append(Bitmap('bin'+bitmap.value[n_remove:]))
  return ret_list

def compare_bitmap_list(list_a: list[Bitmap], list_b: list[Bitmap]):
  """Compares two lists of bitmaps and prints differences

  Args:
    list_a: first list to compare
    list_b: second list to compare
  """
  list_a_copy = remove_empty_bitmaps_in_list(list_a)
  list_b_copy = remove_empty_bitmaps_in_list(list_b)
  list_common = []
  ia = 0
  while ia < len(list_a_copy):
    source_value = list_a_copy[ia].value
    found_match = False
    for ib in range(len(list_b_copy)):
      target_value = list_b_copy[ib].value
      if source_value==target_value:
        list_common.append(Bitmap('bin'+source_value))
        list_a_copy.pop(ia)
        list_b_copy.pop(ib)
        found_match = True
        break
    if not found_match:
      ia += 1
  if (len(list_a_copy)==0 and len(list_b_copy)==0):
    print('Lists were identical')
  else:
    print('Lists not identical')
    print('Items in list A only:')
    for bitmap in list_a_copy:
      print(bitmap.to_hexstring())
    print('Items in list B only:')
    for bitmap in list_b_copy:
      print(bitmap.to_hexstring())
    print('Items in common:')
    for bitmap in list_common:
      print(bitmap.to_hexstring())

