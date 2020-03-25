#!/usr/bin/env bash

wget -O TC.tar.gz --verbose "https://cernbox.cern.ch/index.php/s/lV1Ixfs0F5YdtPL/download" &&
tar -xzvf TC.tar.gz
rm -fv TC.tar.gz