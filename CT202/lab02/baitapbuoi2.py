import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from  sklearn.linear_model import LinearRegression

def LR1(X, Y, alpha, theta0, theta1, it):
	m = len(X) # so luong phan tu
	theta00 =  theta0
	theta11 = theta1
	for i in range(0, it):
		print 'Lan lap: %d' %i
		for j in range(0, m):
			# theta0
			h = theta0 + theta11*X[j]
			theta0 = theta0 + alpha*(Y[j]-h)*1
			print "Phan tu ", j, "gia tri theta0 = ", theta0
			# theta1
			h = theta00 + theta1*X[j]
			theta1 = theta1 + alpha*(Y[j]-h)*X[j]
			print("Phan tu ", j, "gia tri theta1 = ", theta1)
		theta00 = theta0
		theta11 = theta1
	return [theta0, theta1]


# Importing data
dataset = pd.read_csv('data.csv')
X = np.matrix(dataset.iloc[:-1,0].values).T
y = np.matrix(dataset.iloc[:-1,1].values).T


# Using LR1
print '========== LR1 result =========='
theta = LR1(np.array(X), np.array(y), 0.03, 0, 0.5, 2)
print theta


# Using sklearn
print '========== sklearn result =========='
lm = LinearRegression()
lm.fit(X,y)
theta0 = lm.intercept_
theta1 = lm.coef_
theta = np.array([theta0, theta1])
print 'Predicted value for 183: ', lm.predict(183)
print 'theta = ', theta.T

# Ploting for the result from sklearn
x0 = np.linspace(140,180,2)
y0 = theta[0] + theta[1] * x0
plt.plot(X, y, "ro", color="blue")
plt.plot(x0, y0, color="green")
#plt.show()