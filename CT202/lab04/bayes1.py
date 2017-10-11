#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 11 07:28:54 2017

@author: dldien
"""

import pandas as pd

# Load data from csv
df = pd.read_csv('play_tennis.csv')

OutlookYes = df.Outlook[df.Play == "Yes"]
POutlookYes = OutlookYes.value_counts() / OutlookYes.count()

OutlookNo = df.Outlook[df.Play == "No"]
POutlookNo = OutlookNo.value_counts() / OutlookNo.count()

TempYes = df.Temp[df.Play == "Yes"]
PTempYes = TempYes.value_counts() / TempYes.count()

TempNo = df.Temp[df.Play == "No"]
PTempNo = TempNo.value_counts() / TempNo.count()

HumidityYes = df.Humidity[df.Play == "Yes"]
PHumidityYes = HumidityYes.value_counts() / HumidityYes.count()

HumidityNo = df.Humidity[df.Play == "No"]
PHumidityNo = HumidityNo.value_counts() / HumidityNo.count()

WindyYes = df.Windy[df.Play == "Yes"]
PWindyYes = WindyYes.value_counts() / WindyYes.count()

WindyNo = df.Windy[df.Play == "No"]
PWindyNo = WindyNo.value_counts() / WindyNo.count()

PPlay = df.Play.value_counts() / df.Play.count()

# Predict for X = ('Rainy', 'Cool', 'High', 'False')
PYes = POutlookYes[1] * PTempYes[1] * PHumidityYes[1] * PWindyYes[0] * PPlay[0]
PNo = POutlookNo[1] * PTempNo[2] * PHumidityNo[0] * PWindyNo[1] * PPlay[1]
PY = PYes / (PYes + PNo)
PN = PNo / (PYes + PNo)