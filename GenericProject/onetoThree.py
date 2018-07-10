# -*- coding: utf-8 -*-
"""
Created on Wed Apr 25 14:24:26 2018

@author: sansk
"""
import numpy

n_out1 = 0
n_out2 = 0
n_out3 = 0

par1 = 2
par2 = 3
par3 = 4

#create the output arrays

out_1 = numpy.zeros(64, int)
out_2 = numpy.zeros(64, int)
out_3 = numpy.zeros(64, int)

#read the input arrays from the text file
arr = numpy.genfromtxt("input1.txt", dtype = int, delimiter = ", ",)

(r, c) = arr.shape
print(r)
print(c)

#create ouput matrix
out_T = numpy.zeros((3*r, c), int)
counter = 0

#iterate through the input matrix and 
#create the output matrix
for row in arr:
    for i in range(64):
        out_1[i] = par1 * row[i]
        out_2[i] = par2 * row[i]
        out_3[i] = par3 * row[i]
    print(out_1)
    out_T[counter] = out_1
    out_T[counter+1] = out_2
    out_T[counter+2] = out_3
    print(out_T)
    counter = counter + 3
    
    # *** Was attempt 1, but kept overwriting the previous line ***
    #out_1.tofile('output2.txt', sep = ' ')
    #out_2.tofile('output2.txt', sep = ' ')
    #out_3.tofile('output2.txt', sep = ' ')
    
    #this is the current attempt, but it is just a mess of numbers, need to 
    #figure out format
    out_T.tofile('output2.txt', sep = '\n')
    