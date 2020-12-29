#!/usr/bin/env python

import argparse
import os
import pandas as pd
import re
import sys
from enum import Enum

# Python 2-3 compatibility
try:
        import future, builtins, past, six
except ImportError as error:
        raise ImportError("Unable to import the python2/3 compatibility modules (future, builtins, past, six)")

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
    AP     = 'AllProjections'
    CM     = 'CandidateMatches'
    FM     = 'FullMatches'
    VMPROJ = 'VMProjections'


    def __str__(self):
        return '{0}'.format(self.name)

    def FullName(self):
        return '{0}'.format(self.value)

def parse_reference_file(filename):
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
                values.append(line.split()[2].upper().replace('X','x'))
        events.append(values)
    return events

def get_column_index(layers, df):
    match = False
    column_index = -1
    for icol, column_header in enumerate(df.columns):
        match = len(re.findall(layers,column_header))>0
        if match:
            column_index = icol
            break
    return icol

def print_results(total_number_of_events, number_of_good_events, number_of_missing_events, number_of_event_length_mismatches, number_of_value_mismatches):
    print("\nResults\n"+(7*'='))
    print("Good events: "+str(number_of_good_events))
    print("Bad events: "+str(total_number_of_events-number_of_good_events))
    print("\tMissing events: "+str(number_of_missing_events))
    print("\tLength mismatches: "+str(number_of_event_length_mismatches))
    print("\tValue mismatches: "+str(number_of_value_mismatches)+"\n\n")

def compare(comparison_filename="", fail_on_error=False, file_location='./', predefined=False, reference_filenames=[], save=False, verbose=False):
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
        print("Comparing " + reference_type.FullName() + " values ... ")

        # Find the layer names for the reference file
        if reference_type == ReferenceType.FM:
            layers = re.search("(L[0-9]L[0-9])",reference_filename).group(0)
            print("Comparing the values for layers "+str(layers)+" to the reference file "+str(reference_filename)+" ... ")
        elif reference_type in [ReferenceType.AP,ReferenceType.CM,ReferenceType.VMPROJ] :
            layers = re.search("(L[0-9])",reference_filename).group(0)
        else:
            raise TypeError("Unknown type of the reference file (implemented options: FullMatches, CandidateMatches)")

        # Parse the reference data
        reference_data = parse_reference_file(file_location+"/"+reference_filename)

        # Read column names from file and add a column because the time and units are separated by a space (first two columns)
        column_names = list(pd.read_csv(file_location+"/"+comparison_filename,delim_whitespace=True,nrows=1))
        column_names.insert(1,"unit")
        if verbose: print(column_names)

        # Open the comparison data
        if reference_type == ReferenceType.FM:
            column_selections = ['BX#','enb','readaddr',reference_type.name+"_"]
        elif reference_type in [ReferenceType.AP,ReferenceType.CM,ReferenceType.VMPROJ]:
            column_selections = ['BX#','wea','mem_addr',reference_type.name+"_"]
        else:
            raise TypeError("Unknown type of the reference file (implemented options: FullMatches, CandidateMatches)")
        data = pd.read_csv(file_location+"/"+comparison_filename,delim_whitespace=True,header=0,names=column_names,usecols=[i for i in column_names if any(select in i for select in column_selections)])
        if verbose: print(data) # Can also just do data.head()

        # Get the column index for the correct columns of data
        value_index = get_column_index(layers,data)
        address_index = value_index-1
        valid_index = value_index-2
        selected_columns = data[['BX#',data.columns[valid_index],data.columns[address_index],data.columns[value_index]]]

        group_index = 0
        group_sub_index = -1

        for ievent,event in enumerate(reference_data):
            print("Doing event "+str(ievent+1)+"/"+str(len(reference_data))+" ... ")
            good = True

            # Select the correct event from the comparison data
            selected_rows = selected_columns.loc[selected_columns['BX#'] == ievent]
            if len(selected_rows) == 0 and len(event) != 0:
                good = False
                number_of_missing_events += 1
                message = "Event "+str(ievent+1)+" does not exist in the comparison data!"
                if fail_on_error: raise Exception(message)
                else:             print("\t"+message)

            # Select only the comparison data where the valid bit is set
            selected_rows = selected_rows.loc[selected_rows[selected_rows.columns[1]] == '0b1']

            # Check the legnth of the two sets
            # Raise an exception if the are fewer entries for a given event in the comparison data than in the reference data
            if len(selected_rows) != len(event):
                good = False
                number_of_event_length_mismatches += 1
                message = "The number of entries in the comparison data doesn't match the number of entries in the reference data for event "+str(ievent+1)+"!"\
                          "\n\treference="+str(len(event))+" comparison="+str(len(selected_rows))
                if fail_on_error: raise Exception(message)
                else:             print("\t"+message.replace("\n","\n\t"))

            # If there are no entries in the comparison data, then don't try to compare any of the values
            if len(selected_rows) == 0:
                number_of_good_events += good
                continue

            offset = selected_rows[selected_rows.columns[3]].index[0]
            for ival,val in enumerate(event):
                # In case there are fewer entries in the comparison data than in the reference data
                if offset+ival not in selected_rows[selected_rows.columns[3]]: continue

                # Raise exception if the values for a given entry don't match
                if selected_rows[selected_rows.columns[3]][offset+ival] != val:
                    good = False
                    number_of_value_mismatches += 1
                    message = "The values for event "+str(ievent)+" address "+str(selected_rows[selected_rows.columns[2]][offset+ival])+" do not match!"\
                              "\n\treference="+str(val)+" comparison="+str(selected_rows[selected_rows.columns[3]][offset+ival])
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
    if os.path.exists('./TextIO/AP_L3PHIC.txt'):
        ret_sum += compare(comparison_filename="TextIO/AP_L3PHIC.txt", fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                           reference_filenames=["../../emData/MemPrints/TrackletProjections/AllProj_AP_L3PHIC_04.dat"], save=args.save, verbose=args.verbose)

    for i in range(17,25):
        if os.path.exists(('./TextIO/VMPROJ_L3PHIC%i.txt' % (i))):
            ret_sum += compare(comparison_filename=("TextIO/VMPROJ_L3PHIC%i.txt" % (i)), fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                               reference_filenames=[("../../emData/MemPrints/VMProjections/VMProjections_VMPROJ_L3PHIC%i_04.dat" % (i))], save=args.save, verbose=args.verbose)

    for i in range(17,25):
        if os.path.exists(('./TextIO/CM_L3PHIC%i.txt' % (i))):
            ret_sum += compare(comparison_filename=("TextIO/CM_L3PHIC%i.txt" % (i)), fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                               reference_filenames=[("../../emData/MemPrints/Matches/CandidateMatches_CM_L3PHIC%i_04.dat" % (i))], save=args.save, verbose=args.verbose)

    ret_sum += compare(comparison_filename="TextIO/FM_L1L2XX_L3PHIC.txt", fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                       reference_filenames=["../../emData/MemPrints/Matches/FullMatches_FM_L1L2_L3PHIC_04.dat"], save=args.save, verbose=args.verbose)
    ret_sum += compare(comparison_filename="TextIO/FM_L5L6XX_L3PHIC.txt", fail_on_error=False, file_location=args.file_location, predefined=args.predefined,
                       reference_filenames=["../../emData/MemPrints/Matches/FullMatches_FM_L5L6_L3PHIC_04.dat"], save=args.save, verbose=args.verbose)

    print("Accumulated number of errors =",ret_sum)

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
python3 CompareMemPrintsFW.py -l testData/ -r FullMatches_FM_L1L2_L3PHIC_04.dat -c FM_L1L2XX_L3PHIC.txt
python3 CompareMemPrintsFW.py -l testData/ -r FullMatches_FM_L5L6_L3PHIC_04.dat -c FM_L5L6XX_L3PHIC.txt
python3 CompareMemPrintsFW.py -l testData/ -r VMProjections_VMPROJ_L3PHIC17_04.dat -c VMPROJ_L3PHIC17.txt
""",
                                    epilog="",
                                    formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("-c","--comparison_filename",default="output.txt",help="The filename of the testbench output file (default = %(default)s)")
    parser.add_argument("-f","--fail_on_error",default=False,action="store_true",help="Raise an exception on the first error as opposed to simply printing a message (default = %(default)s)")
    parser.add_argument("-l","--file_location",default="./",help="Location of the input files (default = %(default)s)")
    parser.add_argument("-p","--predefined",default=False,action="store_true",help="Run predefined comparisons (default = %(default)s)")
    parser.add_argument("-r","--reference_filenames",default=[],nargs="+",help="A list of filenames for the reference files (default = %(default)s)")
    parser.add_argument("-s","--save",default=False,action="store_true",help="Save the output to a file (default = %(default)s)")
    parser.add_argument("-v","--verbose",default=False,action="store_true",help="Print extra information to the console (default = %(default)s)")

    args = parser.parse_args()

    if args.predefined:
        comparePredefined(args)
    else:
        compare(**vars(args))
