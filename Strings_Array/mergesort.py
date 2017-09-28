#!usr/bin/python

def mergesort(alist):
	print ("Splitting", alist)
	if len(alist) > 1:
		middle = len(alist)/2
		left = alist[:middle]
		right = alist[middle:]
		mergesort(left)
		mergesort(right)
		i = 0
		j = 0
		k = 0
		while i < len(left) and j < len(right):
			if left[i] > right[j]:
				alist[k] = right[j]
				k = k + 1
				j = j + 1
			else:
				alist[k] = left[i]
				k = k + 1
				i = i + 1

		while i < len(left):
			alist[k] = left[i]
			k = k + 1
			i = i + 1

		while j < len(right):
			alist[k] = right[j]
			k = k + 1
			j = j + 1

	print ("Merging " , alist)

alist = [1, 9, 4, 2, 0, 6, 7, 18, 16, 10, 3, 20, 11, 12, 15, 5, 19, 8, 17, 14, 13]
mergesort(alist)
print (alist)