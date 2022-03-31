#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 31 19:49:59 2022

@author: raksa
"""

import matplotlib.pyplot as plt
import numpy as np
file = open('result2.txt', 'r')
Lines = file.readlines()
Lines.pop(0)
n = []
MH = []
for line in Lines:
    List = line.split(',')
    n.append(int(List[0]))
    MH.append(float(List[1]))
file.close()
    
plt.figure(1)
plt.title("Heap Sort | O(nlog(n))")
plt.stem(n, MH)
plt.plot(n, MH, 'r--')
plt.xlabel("Size of input array")
plt.ylabel("Time (seconds)")

nlogn = [(N*np.log(N)) for N in n]

plt.figure(2)

plt.stem(n, nlogn)
plt.plot(n, nlogn, "r--")
plt.title("O(nlog(n))")
plt.ylabel("nlog(n)")
plt.xlabel("Size of input array")