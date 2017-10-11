#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct  4 05:35:40 2017

@author: dldien
"""

import numpy as np
import random as rd
import matplotlib.pyplot as plt

w = np.random.rand(3)
eta = 0.3
n = 100
activate = lambda x: 0 if x < 0 else 1

data =  np.array([
                    [1, 0, 0, 0],
                    [1, 0, 1, 1],
                    [1, 1, 0, 1],
                    [1, 1, 1, 1]
                ])

neg = data[:, 3] == 0
pos = data[:, 3] == 1
plt.plot(data[neg, 1], data[neg, 2], 'ro')
plt.plot(data[pos, 1], data[pos, 2], 'rx')

print('initialized w is', w)

for i in range(n):
    print('lap', i)
    dt = rd.choice(data)
    print('dt is', dt)
    result = np.dot(w, dt[0:3])
    print('dt[0:3] is', dt[0:3])
    print('result is', result)
    print('activate is', activate(result))
    error = dt[3] - activate(result)
    print('error is', error)
    w += eta * error * dt[0:3]
    print('w is', w)

print('finally, w is', w)
x0 = np.array([0, 1])
y0 = -w[0] / w[2] - (w[1]/w[2]) * x0 
plt.plot(x0, y0)
plt.show()