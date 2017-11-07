#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 31 13:08:16 2017

@author: dldien
"""

import numpy as np

# activation function
activate = lambda x: 0 if x < 0 else 1
activate_vectorized = np.vectorize(activate)

# perceptron algorithm to train model
def perceptron(alpha, X_train, y_train):
    w = np.random.randn(n) + 0.5            # auto generate weights
    
    from sklearn.utils import shuffle    # use to shuffle training set
    
    errors = []
    
    X_train_shuffled, y_train_shuffled = shuffle(X_train, y_train)
    
    h = np.dot(X_train_shuffled, w)
    
    a = activate_vectorized(h)
        
    error = a - y_train
    errors.append(error)
    
    w =  w + alpha * error * X_train
    
    
    print(w)
        
# predict function
def predict(X, w):
    import numpy as np
    u = np.multiply(X, w)
    m = u.shape[0]
    output = np.zeros((m, 1))
    for i in range(0, m):
        output[i] = activate(np.sum(u[i]))
    return output

"""
    =========== Main program ===========
"""     

# load data
import pandas as pd

dataset = pd.read_csv('data_10.csv')
m = dataset.shape[0]            # number of training examples
n = dataset.shape[1] - 1        # number of features
X = dataset.iloc[:, 0:n]
y = dataset.iloc[:, n].values

# take care of missing data
from sklearn.preprocessing import Imputer
imputer = Imputer(missing_values = 'NaN', strategy = 'mean')
imputer = imputer.fit(X)
X = imputer.transform(X)

# split dataset into training set and test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 1/3)

# train
alpha = 0.01
perceptron(alpha, X_train, y_train)

#print('======== call predict ========')
#predictedValue = predict(X_test, w)
#actualValue = y_test
#from sklearn.metrics import confusion_matrix, accuracy_score
#matrix = confusion_matrix(actualValue, predictedValue)
#print(matrix)
#print(accuracy_score(actualValue, predictedValue))