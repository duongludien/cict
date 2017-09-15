list1 = [1,2,3,4]
list2 = [1,2,3,4]

# compare list1 and list2
# result is
#	-1 if list1 equals list2
#	 0 if list1 different from list2
if cmp(list1, list2) == 0:
	print 'list1 equals list2'
else:
	print 'list1 different from list2'

print 'The length of list1 is %d' %len(list1)

print 'The maximum value of list1 is %d' %max(list1)

print 'The minimum value of list2 is %d' %min(list2)

# append an object to list1
print '\n------------------------------------------------\n'
print 'Appending \'dldien\' and 4 to list1...'
list1.append('dldien')
list1.append(4)
print list1

print '\n------------------------------------------------\n'
print 'The minimum index of object 4 is %d' %list1.index(4)

# count the number of appearances of object 4 in list1
print '\n------------------------------------------------\n'
print 'The number of appearances of object 4 in list1 is %d' %list1.count(4)

# add all elements of list2 to list1
print '\n------------------------------------------------\n'
print 'list1 is '
print list1
print 'list2 is '
print list2
print 'Adding all elements of list2 to list1...'
list1.extend(list2)
print 'list1 after appending is '
print list1

# insert to list2 at position index value 'linux'
print '\n------------------------------------------------\n'
print 'Inserting \'linux\' to list2 at position 1...'
list2.insert(1, 'linux')
print 'list2 is '
print list2