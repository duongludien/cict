import numpy as np
import matplotlib.pyplot as plt

X = np.matrix([[1, 1, 1], [1, 2, 4]]).T
y = np.matrix([2,3,6]).T

alpha = 0.06
it = 10
theta = np.matrix([0,1]).T

for i in range(0,it):
	h = X.dot(theta)
	derivative = np.matrix([0, 0]).T
	for j in range(0,2):
		derivative[j] = sum(np.multiply(h-y, X[:, j]))
	theta = theta - alpha * derivative
print theta

X_data = np.matrix([1, 2, 4]).T
plt.plot(X_data, y, "ro", color="blue")
x0 = np.matrix([[1, 0], [1, 7]])
y0 = x0.dot(theta)
print x0
print y0
plt.plot(x0[:,1], y0, color="green")
plt.show()