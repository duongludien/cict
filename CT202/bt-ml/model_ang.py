#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov  3 21:13:52 2017
"""

# load data
import pandas as pd

dataset = pd.read_csv('data.csv')
m = dataset.shape[0]                # number of training examples
n = dataset.shape[1] - 1            # number of features
X = dataset.iloc[:, 0:n]
y = dataset.iloc[:, n].values

# take care of missing data (NaN)
from sklearn.preprocessing import Imputer
imputer = Imputer(missing_values = 'NaN', strategy = 'mean')
imputer = imputer.fit(X)
X = imputer.transform(X)

# split dataset into training set (60%), test set (20%) and cross validation set (20%)
from sklearn.model_selection import train_test_split
X_train, X_test_cv, y_train, y_test_cv = train_test_split(X, y, shuffle=True, test_size=0.4)
X_test, X_cv, y_test, y_cv = train_test_split(X_test_cv, y_test_cv, test_size=0.5)
print('X_train.shape =', X_train.shape)
print('y_train.shape =', y_train.shape)
print('X_test.shape =', X_test.shape)
print('y_test.shape =', y_test.shape)
print('X_cv.shape =', X_cv.shape)
print('y_cv.shape =', y_cv.shape)

# create 9 neural networks
from sklearn.linear_model import Perceptron
nn1 = Perceptron(max_iter=100, eta0=0.01)
nn2 = Perceptron(max_iter=1000, eta0=0.01)
nn3 = Perceptron(max_iter=10000, eta0=0.01)
nn4 = Perceptron(max_iter=100, eta0=0.03)
nn5 = Perceptron(max_iter=1000, eta0=0.03)
nn6 = Perceptron(max_iter=10000, eta0=0.03)
nn7 = Perceptron(max_iter=100, eta0=0.1)
nn8 = Perceptron(max_iter=1000, eta0=0.1)
nn9 = Perceptron(max_iter=10000, eta0=0.1)
models = [nn1, nn2, nn3, nn4, nn5, nn6, nn7, nn8, nn9]

# model selection: select the model with largest accuracy
max_accuracy = 0
selected_nn = nn1
from sklearn.metrics import confusion_matrix, accuracy_score 
for nn in models:
    nn.fit(X_train, y_train)
    actualValue = y_test
    predictedValue = nn.predict(X_test)
    matrix = confusion_matrix(actualValue, predictedValue)
    accuracy = accuracy_score(actualValue, predictedValue)
    print(matrix)
    print('accuracy =', accuracy)
    if accuracy > max_accuracy:
        max_accuracy = accuracy
        selected_nn = nn

# evaluate selected model with test set
print("=================================================")
print('selected model:', selected_nn)
actualValue = y_cv
predictedValue = selected_nn.predict(X_cv)
matrix = confusion_matrix(actualValue, predictedValue)
accuracy = accuracy_score(actualValue, predictedValue)
print(matrix)
print('accuracy =', accuracy)