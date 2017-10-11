#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 11 08:29:00 2017

@author: dldien
"""

# Import data from csv
import pandas as pd
data_wine = pd.read_csv('data_wine.csv')
X = data_wine.iloc[:, :-1]
y = data_wine.iloc[:, 11]

#########   Input variables (based on physicochemical tests): #########
#   1 - fixed acidity
#   2 - volatile acidity
#   3 - citric acid
#   4 - residual sugar
#   5 - chlorides
#   6 - free sulfur dioxide
#   7 - total sulfur dioxide
#   8 - density
#   9 - pH
#   10 - sulphates
#   11 - alcohol
#########   Output variable (based on sensory data): #########
#   12 - quality (score between 0 and 10)

# Split dataset into training set and test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.25)
print('The number of training examples is', X_train.shape[0])

# Train model
from sklearn.naive_bayes import GaussianNB
model = GaussianNB()
model.fit(X_train, y_train)

# Test model with test set
realValue = y_test
predictedValue = model.predict(X_test)

# Evaluating model
from sklearn.metrics import confusion_matrix, accuracy_score
confusionMatrix = confusion_matrix(realValue, predictedValue)
print(confusionMatrix)
print("accuracy =", accuracy_score(realValue, predictedValue))