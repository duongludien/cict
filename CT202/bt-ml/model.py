#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 31 13:08:16 2017

@author: dldien
"""

# activation function
activate = lambda x: 0 if x < 0 else 1

# perceptron algorithm to train model
def perceptron(alpha, X_train, y_train):
    
    print('X_train.shape =', X_train.shape)
    print('y_train.shape =', y_train.shape)
    
    import numpy as np
    
    m_train = X_train.shape[0]              # number of training examples
    n = X_train.shape[1]                    # number of features
    w = np.random.randn(n) + 0.5            # auto generate weights
    
    # compute epsilon: 5%
    epsilon = m_train * 0.1
    
    from sklearn.utils import shuffle       # use to shuffle training set
    
    it = 1        # use to count iterations  
    while True:
        print('================= Lap', it, '=================')
        
        # reinitialize error
        error = 0
        
        # shuffle training set
        X_train_shuffled, y_train_shuffled = shuffle(X_train, y_train)
        
        # train
        for i in range(0, m_train):
            u = np.sum(np.multiply(X_train_shuffled[i], w))
            print('u =', u)
            output = activate(u)
            print('output =', output)
            print('y_train_shuffled =', y_train_shuffled[i])
            if(output != y_train_shuffled[i]):
                # recompute error
                error = error + np.abs(y_train_shuffled[i] - output)
                
                # update weights
                for j in range(0, n):
                    w[j] = w[j] + alpha * (y_train_shuffled[i] - output) * X_train_shuffled[i, j]
                print('Cap nhat trong so w =', w)
        
        # loop until error <= epsilon
        if error <= epsilon:
            print('Finally, w is', w)
            return w
        
        # count iterations
        it = it + 1
        
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

dataset = pd.read_csv('data.csv')
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
w = perceptron(alpha, X_train, y_train)

print('======== call predict ========')
predictedValue = predict(X_test, w)
actualValue = y_test
from sklearn.metrics import confusion_matrix, accuracy_score
matrix = confusion_matrix(actualValue, predictedValue)
print(matrix)
print(accuracy_score(actualValue, predictedValue))