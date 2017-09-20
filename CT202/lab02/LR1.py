import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def LR1(X, Y, alpha, it):
	m = len(X) # so luong phan tu
	theta00 =  theta0 = 0
	theta11 = theta1 = 1
	for i in range(0, it):
		print 'Lan lap: %d' %i
		for j in range(0, m):
			# theta0
			h = theta0 + theta11*X[j]
			theta0 = theta0 + alpha*(Y[j]-h)*1
			print("Phan tu ", j, "gia tri theta0 = ", theta0)
			# theta1
			h = theta00 + theta1*X[j]
			theta1 = theta1 + alpha*(Y[j]-h)*X[j]
			print("Phan tu ", j, "gia tri theta1 = ", theta1)
		theta00 = theta0
		theta11 = theta1
	return [theta0, theta1]

X = np.array([1, 2, 4]).T
y = np.array([2,3,6]).T
theta = LR1(X, y, 0.06, 2)
x0 = np.linspace(1,6,2)
y0 = theta[0] + theta[1] * x0
plt.plot(X, y, "ro", color="blue")
plt.plot(x0, y0, color="green")
plt.show()