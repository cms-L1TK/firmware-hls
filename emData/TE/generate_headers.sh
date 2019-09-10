#!/bin/bash

#
# Generate all header files for processing TE cut tables
#
python generate_header.py readPtTable ptcut > TrackletEngine_ptcut.h
python generate_header.py readBendInnerTable stubptinnercut > TrackletEngine_stubptinnercut.h
python generate_header.py readBendOuterTable stubptoutercut > TrackletEngine_stubptoutercut.h
