#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 11 08:10:07 2017

@author: dldien
"""

# Load data from sklearn library
from sklearn import datasets
iris = datasets.load_iris()
X = iris.data
y = iris.target

# Split model into training set and test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.3, random_state = 0)

# Train model with training set
from sklearn.naive_bayes import GaussianNB
model = GaussianNB()
model.fit(X_train, y_train)

# Test model with test set
realValue = y_test
predictedValue = model.predict(X_test)

# Training result
from sklearn.metrics import confusion_matrix
confusionMatrix = confusion_matrix(realValue, predictedValue)
print(confusionMatrix)
