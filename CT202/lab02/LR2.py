import numpy as np
import matplotlib.pyplot as plt
from  sklearn.linear_model import LinearRegression

X = np.matrix([[1, 1, 1], [1, 2, 4]]).T
y = np.matrix([2,3,6]).T

lm = LinearRegression()
lm.fit(X,y)
theta0 = lm.intercept_
theta1 = lm.coef_

theta = np.array([theta0, theta1])
print theta
# plt.plot(X, y, "ro", color="blue")
# x0 = np.matrix([[1, 0], [1, 7]])
# y0 = x0.dot(theta)
# print x0
# print y0
# plt.plot(x0[:,1], y0, color="green")
# plt.show()