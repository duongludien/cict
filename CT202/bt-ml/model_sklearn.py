#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 31 18:42:28 2017

@author: dldien
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

k = 5
avg_accuracy = 0
for i in range(k):
    # split data
    from sklearn.model_selection import train_test_split
    X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, test_size=1/3)
    
    # train
    from sklearn.linear_model import Perceptron
    nn = Perceptron(max_iter=10, eta0=0.1)
    nn.fit(X_train, y_train)
    actualValue = y_test
    predictedValue = nn.predict(X_test)
    from sklearn.metrics import confusion_matrix, accuracy_score
    matrix = confusion_matrix(actualValue, predictedValue)
    accuracy = accuracy_score(actualValue, predictedValue)
    avg_accuracy += accuracy
    print(matrix)
    print('accuracy =', accuracy)

print('average accuracy is', avg_accuracy / k)