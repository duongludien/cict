#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Sep 24 11:34:34 2017

@author: dldien
"""

import numpy as np

X = np.matrix([[1, 1, 1, 1, 1], [0, 0.5, 1.2, 2.5, 3]]).T
y = np.matrix([1, 2.5, 3.5, 4, 5.5]).T
theta = np.matrix([0, 0.5]).T

alpha = 0.03
it = 10

for i in range(0, it):
    h = X * theta;
    derivative = np.matrix([0, 0]).T
    derivative[0] = np.sum(h - y)
    derivative[1] = np.sum(np.multiply((h - y), (X[:, 1])))
    theta = theta - alpha * derivative;

print theta

theta = np.array(theta)

import matplotlib.pyplot as plt
plt.plot(X[:, 1], y, "ro")
x0 = [0, 4]
y0 = theta[0] + theta[1] * x0
plt.plot(x0, y0, color="blue")
plt.show()