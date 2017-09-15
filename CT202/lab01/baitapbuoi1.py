import numpy as np

A = np.array([2,5,3,6,7,8])

B = np.array(range(1,200+1))

C = np.linspace(0, 1000, 1001)
C = C[C % 2 == 0]

A5 = A + 5

B3 = B * 3

A_sort = np.sort(A)

Dict = {'Name' : 'Duong Lu Dien', 'Age' : 21, 'Course' : 'Nguyen Ly May Hoc'}
Dict['Course'] = 'Tri Tue Nhan Tao'

def hello():
	name = input('Enter your name: ')
	print 'Hello %s' %name

# hello()

def squareEquationSolver(a, b, c):
	from math import sqrt

	delta = b * b - 4 * a * c

	if delta < 0:
		print 'No solution for this equation'
	elif delta == 0:
		x = -b / (2*a)
		print 'Solution: x = %f' %x
	else:
		x1 = (-b + sqrt(delta)) / (2*a)
		x2 = (-b - sqrt(delta)) / (2*a)
		print 'Solution: x1 = %f and x2 = %f' %(x1,x2)

# a = input('Enter a: ')
# b = input('Enter b: ')
# c = input('Enter c: ')
# squareEquationSolver(a, b, c)

def findMaximum():
	a = input('Enter a number: ')
	b = input('Enter another one: ')
	c = input('Enter another one: ')

	max = a
	if b > max:
		max = b
	if c > max:
		max = c

	print 'So lon nhat trong 3 so nhap vao la %d' %max

# findMaximum()

X = np.matrix([ [1,2,3], [4,5,6], [7,8,9] ])
Y = np.matrix([ [11,22,33,44], [55,66,77,88], [99,111,222,333] ])

Z = X * Y

import matplotlib.pyplot as plt
x = np.linspace(-10, 10, 100)
y = np.sin(x)
plt.plot(x,y)
plt.show()

x2 = np.linspace(-5, 5, 100)
y2 = x2**3 - 2*x2*x2 + x2 + 5
plt.plot(x2, y2)
plt.show()
