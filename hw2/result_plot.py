#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 25 16:07:56 2022
@author: raksa
"""
import matplotlib.pyplot as plt
import numpy as np
file = open('result2.txt', 'r')
Lines = file.readlines()
Lines.pop(0)
n = []
BF = []
DC = []
for line in Lines:
    List = line.split(',')
    n.append(int(List[0]))
    BF.append(float(List[1]))
    DC.append(float(List[2]))

f1, (ax1, ax2) = plt.subplots(2, 1)
ax1.stem(n, BF)
ax1.plot(n, BF, "r--")
ax1.set_title("Brute Force O(n^2)")
ax1.set_ylabel("Time (seconds)")

ax2.stem(n, DC)
ax2.plot(n, DC, "r--")
ax2.set_title("Divide-and-Conquer O(nlog(n))")
ax2.set_ylabel("Time (seconds)")
ax2.set_xlabel("Size of input array")
file.close()

nlogn = [(N*np.log(N)) for N in n]
n_sqr = [(N*N) for N in n]

f2, (ax1, ax2) = plt.subplots(2, 1)

ax1.stem(n, n_sqr)
ax1.plot(n, n_sqr, "r--")
ax1.set_title("O(n^2)")
ax1.set_ylabel("n^2")

ax2.stem(n, nlogn)
ax2.plot(n, nlogn, "r--")
ax2.set_title("O(nlog(n))")
ax2.set_ylabel("nlog(n)")
ax2.set_xlabel("Size of input array")
