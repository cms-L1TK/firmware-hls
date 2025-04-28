#!/usr/bin/env python

#================================================================
# Compare .txt files (corresponding to memory content) written
# by FW with those expected from C++ emulation.
# 
# Run from IntegrationTests/someChain/script/ with:
#  ../../common/script/CompareMemPrintsFW.py -p -s
#
# Assumes txt files written by FW are in dataOut/
# & C++ emulation expectations in ./MemPrints/
#================================================================

import argparse
import os
import pandas as pd
import re
import sys
import glob
from enum import Enum

# Python 2-3 compatibility - commented out by Ryd as it did not seem to work?
#try:
#        import future, builtins, past, six
#except ImportError as error:
#        raise ImportError("Unable to import the python2/3 compatibility modules (future, builtins, past, six)")

# Based on: https://stackoverflow.com/questions/14906764/how-to-redirect-stdout-to-both-file-and-console-with-scripting/14906787
class Logger(object):
    def __init__(self, output_filename):
        self.original_stdout = sys.stdout
        self.terminal = sys.stdout
        self.log = open(output_filename, "w")

    def __del__(self):
        self.log.close()
        sys.stdout = self.original_stdout

    def write(self, message):
        self.terminal.write(message)
        self.log.write(message)

    def flush(self):
        #this flush method is needed for python 3 compatibility.
        #this handles the flush command by doing nothing.
        #you might want to specify some extra behavior here.
        pass

class ReferenceType(Enum):
    IL     = 'InputStubs'
    VMSTE  = 'VMStubs'
    VMSME  = 'VMStubs'
    AS     = 'AllStubs'
    SP     = 'StubPairs'
    TPAR   = 'TrackletParameters'
    MPAR   = 'TrackletParameters'
    MPROJ  = 'TrackletProjections'
    TPROJ  = 'TrackletProjections'
    VMPROJ = 'VMProjections'
    AP     = 'AllProjections'
    CM     = 'CandidateMatches'
    FM     = 'FullMatches'
    TF     = 'TrackFit'
    CT     = 'CleanTrack'


    def __str__(self):
        return '{0}'.format(self.name)

    def FullName(self):
        return '{0}'.format(self.value)

def parse_reference_file(filename, is_binned):
    # Parse .txt file from C++ emulation in emData/
    # Returns only data if unbinned.
    # Returns bin & data if binned.
    events = []
    with open(filename,'r') as f:
        values = []
        for iline, line in enumerate(f):
            if line.startswith('BX = ') and iline == 0:
                continue
            elif line.startswith('BX = '):
                events.append(values)
                values = []
            else:
                data = line.split()[-1].upper().replace('X','x')
                if is_binned:
                    bin = line.split()[0]
                    values.append([bin, data])
                else:
                    values.append(data)
        events.append(values)
    return events

def print_results(total_number_of_events, number_of_good_events, number_of_missing_events, number_of_event_length_mismatches, number_of_value_mismatches):
    print("\nResults\n"+(7*'='))
    print("Good events: "+str(number_of_good_events))
    print("Bad events: "+str(total_number_of_events-number_of_good_events))
    print("\tMissing events: "+str(number_of_missing_events))
    print("\tLength mismatches: "+str(number_of_event_length_mismatches))
    print("\tValue mismatches: "+str(number_of_value_mismatches)+"\n\n")

def compare(comparison_filename="", fail_on_error=False, file_location='./', predefined="", reference_filenames=[], save=False, verbose=False):
    # Sanity checks
    if len(reference_filenames) == 0:
        raise Exception("No reference files were specified (-r). At least one reference file is needed to run the comparison.")

    # Set the output filename
    if save:
        original_stdout = sys.stdout
        filename_pieces = os.path.splitext(comparison_filename)
        sys.stdout = Logger(filename_pieces[0]+"_cmp"+filename_pieces[1])

    # Global error tracking
    failed = 0

    for reference_filename in reference_filenames:
        # Define some counters
        number_of_missing_events=0 # The number of events missing from the testbench output
        number_of_event_length_mismatches=0 # The number of events where the length of the testbench output doesn't match the length of the reference output
        number_of_value_mismatches=0 # The number of times the values between the testbench output and the reference output don't match
        number_of_good_events=0

        # Find the type of MemPrint being used
        try:
            reference_type_string = re.search("(_[A-Z][A-Z]_)",reference_filename).group(0)[1:-1]
        except AttributeError:
            reference_type_string = reference_filename.split('_')[1]
        except IndexError:
            raise IndexError("Unable to determine the reference file type from the file name")
        finally:
            reference_type = ReferenceType[reference_type_string]

        print("Comparing TB results "+str(comparison_filename)+" to ref. file "+str(reference_filename)+" ... ")

        # Read column names from comparison file
        column_names = list(pd.read_csv(file_location+"/"+comparison_filename,sep='\s+',nrows=1))
        if verbose: print(column_names)

        # Check if binned memory
        if ('VMS' in comparison_filename):
            is_binned = True
        else:
            is_binned = False

        column_selections = ['TIME', 'BX', 'ADDR', 'DATA']

        # Open the comparison (= VHDL test-bench output) data
        data = pd.read_csv(file_location+"/"+comparison_filename,sep='\s+',header=0,names=column_names,usecols=[i for i in column_names if any(select in i for select in column_selections)])
        if verbose: print(data) # Can also just do data.head()

        #Need to figure out how to handle the memory "overwrite" - this is a bit of a hack...
        if (not is_binned) and ("TF_" not in comparison_filename):
            rows = []
            for index, row in data.iterrows():
                if row['ADDR'] == "0x01":
                    rows.append(index-1) # -1 to remove previos entry
            data=data.drop(rows)

        #This is a hack to work around over flows in VMStub memories
        if is_binned:
            rows = []
            count = {}
            for index, row in data.iterrows():
                entry = str(row['BX'])+row['ADDR']
                if entry not in count:
                    count[entry]=1
                else:
                    count[entry]+=1
                if count[entry]>15:
                    rows.append(index)
            data=data.drop(rows)

        #This is a hack to work around over flows in MPROJ memories
        if "MPROJ_" in comparison_filename:
            rows = []
            count = {}
            for index, row in data.iterrows():
                entry = str(row['BX'])+row['ADDR']
                if entry not in count:
                    count[entry]=1
                else:
                    count[entry]+=1
                if count[entry]>63:
                    rows.append(index)
            data=data.drop(rows)

        # Sort data by ascending address
        if is_binned:
            data.sort_values(by=['BX','ADDR','DATA'], inplace = True)
        else:
            data.sort_values(by=['BX','DATA'], inplace = True)
            
        data.reset_index(drop = True, inplace = True)

        selected_columns = data[column_selections]

        # Parse the reference data
        reference_data = parse_reference_file(file_location+"/"+reference_filename, is_binned)

        for ievent,event in enumerate(reference_data):

            print("Doing event "+str(ievent)+"/"+str(len(reference_data))+" ... ")
            good = True

            # Select the correct event from the comparison data
            selected_rows = selected_columns.loc[selected_columns['BX'] == ievent]
            if len(selected_rows) == 0 and len(event) != 0:
                good = False
                number_of_missing_events += 1
                message = "Event "+str(ievent)+" does not exist in the comparison data!"
                if fail_on_error: raise Exception(message)
                else:             print("\t"+message)

            # Select only the comparison data where the valid bit is set
            #selected_rows = selected_rows.loc[selected_rows[selected_rows.columns[1]] == '0b1']

            # Check the length of the two sets
            # Raise an exception if the are fewer entries for a given event in the comparison data than in the reference data
            if len(selected_rows) != len(event):
                good = False
                number_of_event_length_mismatches += 1
                message = "The number of entries in the comparison data doesn't match the number of entries in the reference data for event "+str(ievent)+"!"\
                          "\n\treference="+str(len(event))+" comparison="+str(len(selected_rows))
                if fail_on_error: raise Exception(message)
                else:             print("\t"+message.replace("\n","\n\t"))

            # If there are no entries in the comparison data, then don't try to compare any of the values
            if len(selected_rows) == 0:
                number_of_good_events += good
                continue

            offset = selected_rows['DATA'].index[0]

            event.sort()

            for ival,val in enumerate(event):
                # In case there are fewer entries in the comparison data than in the reference data
                if offset+ival not in selected_rows['DATA']: continue

                if is_binned:
                    bin, data = val
                    bin = bin.replace("0x","")
                else:
                    data = val

                # Raise exception if the values for a given entry don't match
                if selected_rows['DATA'][offset+ival] != data:
                    good = False
                    number_of_value_mismatches += 1
                    message = "The values for event "+str(ievent)+" address "+str(selected_rows['ADDR'][offset+ival])+" do not match!"\
                              "\n\treference="+str(data)+" comparison="+str(selected_rows['DATA'][offset+ival])
                    if fail_on_error: raise Exception(message)
                    else:             print("\t\t"+message.replace("\n","\n\t\t"))

                # Raise exception if the bin number of a given entry don't match
                elif is_binned:
                    ref_add = selected_rows['ADDR'][offset+ival][3:]
                    data_add = bin.upper()
                    if ref_add != data_add:
                        good = False
                        number_of_value_mismatches += 1
                        message = "The bin for event "+str(ievent)+" stub "+str(selected_rows['DATA'][offset+ival])+" do not match!"\
                                  "\n\treference="+bin+" comparison="+str(selected_rows['ADDR'][offset+ival])
                        if fail_on_error: raise Exception(message)
                        else:             print("\t\t"+message.replace("\n","\n\t\t"))

            number_of_good_events += good

        print_results(len(reference_data),number_of_good_events,number_of_missing_events,number_of_event_length_mismatches,number_of_value_mismatches)
        failed += len(reference_data)-number_of_good_events

    if save:
        sys.stdout = original_stdout

    if predefined:
        return failed
    else:
        sys.exit(failed)

def comparePredefined(args):
    ret_sum = 0

    comparison_dir = "./dataOut/"
    reference_dir = args.memprints_location

    # Make sure the default directories exists
    if (not os.path.isdir(comparison_dir) or not os.path.isdir(reference_dir)):
        raise FileNotFoundError("Please make sure that the directories " + comparison_dir + " and " + reference_dir + " exist from where this script is run with the predefined (-p) flag")

    # Check that the comparison files exist, exit if not
    if not os.listdir(comparison_dir):
        raise FileNotFoundError(comparison_dir + " is empty. No files to compare.")

    # Find the lists of filenames
    comparison_filename_list = [f for f in glob.glob(comparison_dir+"*.txt") if "debug" not in f and "cmp" not in f and "TW" not in f and "BW" not in f and "DW" not in f] # Remove debug and comparison files from file list, also also TW/BW output from TB (since TF output used instead).
    comparison_filename_list.sort()
    reference_filename_list = [f.split('/')[-1].split('.')[0].replace("TEO", "TE").replace("TEI", "TE") for f in comparison_filename_list] # Remove file extension from comparison_filename_list and replace TEO/TEI with TE
    try:
        reference_filename_list = [glob.glob(reference_dir+"*/*"+f+"*.dat")[0] for f in reference_filename_list] # Find the corresponding reference filenames
    except IndexError :
        raise IndexError("Could not find matching reference file for comparison file.")

    # Loop over all the filenames and compare the data
    for comp, ref in zip(comparison_filename_list, reference_filename_list):
        ret_sum += compare(comparison_filename=comp, fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                           reference_filenames=[ref], save=args.save, verbose=args.verbose)

    if args.save:
      print("Summary of memories with errors")
      print("=================================")
      sys.stdout.flush()
      os.system('grep "Bad events: [1-9]" dataOut/*cmp.txt')

    print("\n Accumulated number of errors =",ret_sum)

    sys.exit(ret_sum)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="""
Compare reference files to the output of the testbench.

Dependencies:
=============
The main dependency is the module 'pandas', though to make sure this program is compatible both with python 2 and python 3 we also require the 'future', 'builtins', 'past', and 'six' modules.

Examples:
=========
python3 CompareMemPrintsFW.py --help
python3 CompareMemPrintsFW.py -l testData/ -r CandidateMatches_CM_L3PHIC17_04.dat -c CM_L3PHIC17.txt
python3 CompareMemPrintsFW.py -l testData/ -r FullMatches_FM_L1L2_L3PHIC_04.dat -c FM_L1L2_L3PHIC.txt
python3 CompareMemPrintsFW.py -l testData/ -r FullMatches_FM_L5L6_L3PHIC_04.dat -c FM_L5L6_L3PHIC.txt
python3 CompareMemPrintsFW.py -l testData/ -r VMProjections_VMPROJ_L3PHIC17_04.dat -c VMPROJ_L3PHIC17.txt
""",
                                    epilog="",
                                    formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("-c","--comparison_filename",default="output.txt",help="The filename of the testbench output file (default = %(default)s)")
    parser.add_argument("-f","--fail_on_error",default=False,action="store_true",help="Raise an exception on the first error as opposed to simply printing a message (default = %(default)s)")
    parser.add_argument("-l","--file_location",default="./",help="Location of the input files (default = %(default)s)")
    parser.add_argument("-p","--predefined",default=False,action="store_true",help="Run predefined comparisons using the output files in ./dataOut. Make sure that the reference files are located in ./MemPrints/ (default = %(default)s)")
    parser.add_argument("-r","--reference_filenames",default=[],nargs="+",help="A list of filenames for the reference files (default = %(default)s)")
    parser.add_argument("-m","--memprints_location",default="./MemPrints/",help="Location of MemPrints directory for predefined comparisons (default = %(default)s)")
    parser.add_argument("-s","--save",default=False,action="store_true",help="Save the output to a file (default = %(default)s)")
    parser.add_argument("-v","--verbose",default=False,action="store_true",help="Print extra information to the console (default = %(default)s)")

    args = parser.parse_args()

    if args.predefined:
        comparePredefined(args)
    else:
        compare(**vars(args))
