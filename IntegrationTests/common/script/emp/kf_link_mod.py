from glob import iglob
import glob
import os
import fileinput
import sys

file_to_mod = '../../../../KalmanFilter/kfin/firmware/hdl/kfin_layerEncoding.vhd'
if 'DualFPGA' in os.getcwd():
  file_to_mod = '../../../KalmanFilter/kfin/firmware/hdl/kfin_layerEncoding.vhd'
search_line_string = '  file f: text open read_mode is "/heplnw039/tschuh/work/src/l1tk-for-emp/kfin/firmware/luts/layerEncoding.mem";'
replace_line_path = os.path.abspath('../../../KalmanFilter/kfin/firmware/luts/layerEncoding.mem')
#replace_line_path = os.path.abspath('../../../../KalmanFilter/kfin/firmware/luts/layerEncoding.mem')
replace_line_string = '  file f: text open read_mode is "' + replace_line_path + '";'


for line in fileinput.input(file_to_mod, inplace=1):
    if search_line_string in line:
        line = line.replace(search_line_string, replace_line_string)
    sys.stdout.write(line)



