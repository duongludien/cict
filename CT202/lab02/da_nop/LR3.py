#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 21 20:07:25 2017

@author: dldien
"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

dataset = pd.read_csv('data.csv')
X = np.matrix(dataset.iloc[:, 0].values).T
Y = np.matrix(dataset.iloc[:, 1].values).T

lr = LinearRegression()
lr.fit(X, Y)

plt.scatter([X], [Y], color="blue")
plt.plot(X, lr.predict(X), color="red")
plt.xlabel('height')
plt.ylabel('weight')
plt.show()