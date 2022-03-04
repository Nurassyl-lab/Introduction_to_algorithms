#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 25 16:07:56 2022

@author: raksa
"""
import matplotlib.pyplot as plt
import numpy as np
file = open('result.txt', 'r')
Lines = file.readlines()
Lines.pop(0)
n = []
ins = []
mer = []
for line in Lines:
    List = line.split(',')
 
    if List[0] == "Insertion sort":
            ins.append([float(List[2]), float(List[3]), float(List[4])])
    elif List[0] == "Merge sort":
            mer.append([float(List[2]), float(List[3]), float(List[4])])    
    if (List[1] not in n):
        n.append(List[1])

f1, (ax1, ax2, ax3) = plt.subplots(3, 1)
ax1.stem(n, [i[0] for i in ins])
ax1.plot(n, [i[0] for i in ins], "r--")
ax1.set_title("Insertion Sort | Best case | O(n)")
ax1.set_ylabel("Time (seconds)")

ax2.stem(n, [i[1] for i in ins])
ax2.plot(n, [i[1] for i in ins], "r--")
ax2.set_title("Insertion Sort | Average case | O(n^2)")
ax2.set_ylabel("Time (seconds)")

ax3.stem(n, [i[2] for i in ins])
ax3.plot(n, [i[2] for i in ins], "r--")
ax3.set_title("Insertion Sort | Worst case | O(n^2)")
ax3.set_xlabel("Size of input array")
ax3.set_ylabel("Time (seconds)")


f2, (ax1, ax2, ax3) = plt.subplots(3, 1)
ax1.stem(n, [i[0] for i in mer])
ax1.plot(n, [i[0] for i in mer], "r--")
ax1.set_title("Merge Sort | Best case | O(nlog(n))")
ax1.set_ylabel("Time (seconds)")

ax2.stem(n, [i[1] for i in mer])
ax2.plot(n, [i[1] for i in mer], "r--")
ax2.set_title("Merge Sort | Average case | O(nlog(n))")
ax2.set_ylabel("Time (seconds)")

ax3.stem(n, [i[2] for i in mer])
ax3.plot(n, [i[2] for i in mer], "r--")
ax3.set_title("Merge Sort | Worst case | O(nlog(n))")
ax3.set_xlabel("Size of input array")
ax3.set_ylabel("Time (seconds)")

f3, (ax1, ax2, ax3) = plt.subplots(3, 1)
n = []
nlogn = []
nsq = []

for i in range(100000):
    n.append(i)
    nlogn.append((i*np.log(i)))
    nsq.append(i*i)
    
ax1.plot(n, n)
ax1.set_ylabel("n")
ax1.set_title("Complexities")
ax2.plot(n, nlogn, "r--")
ax2.set_ylabel("nlog(n)")
ax3.plot(n, nsq, "k--")
ax3.set_ylabel("n^2")
ax3.set_xlabel("Input size")