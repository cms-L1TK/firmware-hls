# -*- coding: utf-8 -*-
"""
Created on Wed Apr 25 14:23:07 2018

@author: sansk
"""
import numpy as np
f = open('input2.txt', 'w')
rowrange = np.random.randint(1, 64)

#create a matrix of 64 columns and an varianble amount of rows
dataAMAT = [["0" for col in range(64)] for row in range(rowrange)]

#put a randomly generated int into an array
#filled with an random number of nonzero values.
#The rest of the values will remain as zeros.
for i in range(rowrange):
    colzero = np.random.randint(64)
    for j in range(colzero):
        dataAMAT[i][j] = str(np.random.randint(1, 100))
    print(dataAMAT[i])
    x = ', '.join(dataAMAT[i])
    print(x)
    f.write("%s\n" %x)
    #f.write("s\n", %dataAMAT[i])
    #np.save("input2.txt", dataAMAT[i])
    
f.close()