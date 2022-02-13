# -*- coding: utf-8 -*-
"""
Evolving of dest value of att48 tsp by simulated annealing.
Created on 2017/11/03

@author: wgsheng
"""
import sys

import numpy as np
import pylab as pl

try:
	resultFile = open('len.log', 'r')
except IOError:
	print "##### Error: Can't access the result log file: %s!" % 'len.log'
	sys.exit(-1)

N=0
x = []
y = []
for line in resultFile:
	N += 1
	x.append(N)
	y.append(int(line))

# plot
fig = pl.figure(figsize=(5,3))

ax = fig.add_axes((0.11,0.15,0.85,0.78))
rect = ax.plot(x, y)
#ax.set_xticks(ind+1.5*width)
#ax.set_xticklabels(circuits, rotation=45)
#ax.set_xticklabels(x)
ax.set_xlabel('Era')
#ax.set_ylim(ymin=1E-7)
#ax.set_ylim(ymax=1E4)
#ax.set_yscale('log')
ax.set_ylabel('Length')
#ax = plt.gca()  # 获取当前图像的坐标轴信息
ax.yaxis.get_major_formatter().set_powerlimits((0,1)) # 将坐标轴的base number设置为一位。

#pl.grid()
#pl.show()
pl.savefig('SA_TSP_Graph.pdf')
#pl.savefig('./speedup.eps')
pl.close()
