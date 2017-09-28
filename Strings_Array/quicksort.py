#!usr/bin/python

def quicksort(alist, first, last):
	if first < last:

		pivotpoint = partition(alist, first, last)

		quicksort(alist, first, pivotpoint - 1)
		quicksort(alist, pivotpoint + 1, last)

def partition(alist, first, last):
	pivot = alist[first]
	left = first + 1
	right = last
	done = 0

	while not done:
		while left <= right and alist[left] <= pivot:
			left = left + 1

		while right >= left and alist[right] >= pivot:
			right = right - 1

		if right < left:
			done = 1 #done = True
		else:
			temp = alist[left]
			alist[left] = alist[right]
			alist[right] = temp

	if alist[right] < alist[first]:
		temp1 = alist[first]
		alist[first] = alist[right]
		alist[right] = temp1
	
	
	return right

alist = [1, 9, 4, 2, 0, 6, 7, 18, 16, 10, 3, 20, 11, 12, 15, 5, 19, 8, 17, 14, 13]
quicksort(alist, 0, len(alist) - 1)
print (alist)