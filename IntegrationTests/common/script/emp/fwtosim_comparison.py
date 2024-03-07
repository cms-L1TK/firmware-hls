import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-e', action='store', dest='emp_file',
                    default='out.txt', help='Input file name from EMP firmware simulation')
parser.add_argument('-s', action='store', dest='sim_file',
                    default='TF_L1L2.txt', help='Input file name from standalone simulation')
args = parser.parse_args()

elines = []

with open(args.emp_file) as emp_file:
    elines = emp_file.readlines()

with open(args.sim_file) as sim_file:
    slines = sim_file.readlines()

# Data manipulation for EMP output file
checks = ['0v', '1v', 'Uv']
words_per_event = 108
hex_chars_per_track = 80

elines = [eline for eline in elines if 'Frame' in eline] #Remove EMP header
nchar = len(elines[0]) - 1 #Number of characters per line
elines = [eline[0:nchar] for eline in elines] #Remove final '\n' from line
elines = [eline.split() for eline in elines]
#elines = [eline[3] for eline in elines if eline[2][3]=='1'] # only keep link 0 and keep when valid bit set
elines = [eline[3] if eline[2][3]=='1' else '' for eline in elines] # only keep link 0 and keep when valid bit set
elines = [elines[x:x+words_per_event] for x in range(0, len(elines), words_per_event)] #Create sublists with events
elines = [''.join(sub_list) for sub_list in elines] #Merge single events
elines = [eline for eline in elines if eline!=''] #remove empty events for now
elines = [[eline[x:x+hex_chars_per_track] for x in range(0,len(eline),hex_chars_per_track)] for eline in elines] #split tracks within events
elines = [track for event in elines for track in event] #flatten
elines = [eline.upper() for eline in elines] #Change to capital letters
elines = [eline.replace('8048D15A','2')[:-4] for eline in elines] #remove header and tailer

slines = [sline for sline in slines if '0x' in sline] #Remove sim header
slines = [sline.split() for sline in slines]
slines = [sline[4:] for sline in slines]
slines = [sline for sublist in slines for sline in sublist] #Recreate list
slines = [sline.replace('0x','') for sline in slines]
slines = [sline[:69] for sline in slines]

events = min(len(elines), len(slines))
mismatches = 0

for x in range(events):
    if (elines[x] != slines[x]):
        mismatches = mismatches + 1

if (mismatches == 0):
    print("Test passed!! {} events processed".format(events))
else:
    print("Test not passed!!")
    print("{} of {} tracks incorrect.".format(mismatches, events))
