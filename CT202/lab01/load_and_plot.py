import numpy as np

# load data from file
data = np.genfromtxt('web_traffic.tsv', delimiter='\t')

# x is the first column and y is the second one
x = data[:, 0]
y = data[:, 1]

# exclude all rows which has nan value
x = x[~np.isnan(y)]
y = y[~np.isnan(y)]

import matplotlib.pyplot as plt

plt.scatter(x, y)
plt.show()