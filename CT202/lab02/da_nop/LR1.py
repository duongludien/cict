import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def LR1(X, Y, alpha, it, theta0, theta1):
    m = len(X)  # so luong phan tu
    theta00 =  theta0 = 0
    theta11 = theta1 = 1
    for i in range(0, it):
        print 'Lan lap: %d' %i
        for j in range(0, m):
            # theta0
            h = theta0 + theta11 * X[j]
            theta0 = theta0 + alpha * (Y[j]- h)
            print("Phan tu ", j, "gia tri theta0 = ", theta0)
            
            # theta1
            h = theta00 + theta1 * X[j]
            theta1 = theta1 + alpha * (Y[j] - h) * X[j]
            print("Phan tu ", j, "gia tri theta1 = ", theta1)
        
        theta00 = theta0
        theta11 = theta1
        
    plt.plot(X, Y, "ro", color="blue")
    x0 = np.linspace(1, 6, 2)
    y0 = theta0 + theta1 * x0;
    plt.plot(x0, y0.T, color="green")
    plt.show()
    
    return [theta0, theta1]

dataset = pd.read_csv('data.csv')
X = dataset.iloc[:, 0].values
y = dataset.iloc[:, 1].values
alpha = 0.2
it = 4
theta0 = 0
theta1 = 0.5
LR1(X, y, alpha, it, theta0, theta1)