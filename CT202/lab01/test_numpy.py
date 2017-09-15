import numpy as np

# create arrays with numpy
arr1 = np.array([1,2,3,4])
arr2 = np.array([ [1,2,3], [5,6,7] ])

# print n dimensions
print arr1.ndim
print arr2.ndim

# print arr shape
print arr1.shape
print arr2.shape

# print all elements that greater than 2 in arr1
print arr1[arr1 > 2]

# change arr2's shape
arr2.reshape(3,2)

