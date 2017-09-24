#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 21 21:32:51 2017

@author: dldien
"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# importing data
dataset = pd.read_csv('data.csv')

# divide them into X and Y
X = dataset.iloc[:, 0].values
Y = dataset.iloc[:, 1].values

# reshape X and Y
X = X.reshape(len(X),1)
Y = Y.reshape(len(Y),1)

# scatter training set
plt.scatter(X, Y, color="blue")

# add ones column into X
X = np.c_[np.ones(X.shape[0]), X]

# convert X and Y to matrix
X = np.matrix(X)
Y = np.matrix(Y)

# learning rate
alpha = 0.000001
# number of iterations
it = 100
# default value of theta
theta = np.matrix([[0.0001], [0.1]])

# learning
for i in range(0, it):
	print "Lap", i
	h = X.dot(theta)
	print "h = ", h
	derivative = np.matrix([[0], [0]])
	for j in range(0, 2):
		derivative[j] = sum(np.multiply(h-Y, X[:, j]))
	print "derivative = ", derivative
	theta = theta - alpha * derivative
	print "theta = [%d, %d]" %(theta[0], theta[1])

print theta
print theta[0][0]

h = X.dot(theta);
plt.plot(X[:, 1], h, color="red")
plt.xlabel('height')
plt.ylabel('weight')
plt.show()
