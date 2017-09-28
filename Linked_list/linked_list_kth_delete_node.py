class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class Linkedlist:
	def __init__(self):
		self.head = None
		self.count = 0


	def add(self, data):
		if self.head is None:
			new_node = Node(data)
			self.head = new_node
		else:
			new_node = Node(data)
			new_node.next = self.head
			self.head = new_node
		self.count = self.count + 1

	def display(self):
		current = self.head
		val = "List = "
		while current != None:
			val = val + str(current.data) + "\t"
			current = current.next
		print val

	def delete_position_from_last(self, position):
		count = 0
		if self.head is None or position > self.count:
			return
		elif position == self.count:
			self.count = self.count - 1
			data = self.head.data
			self.head = self.head.next
			return data
		else:
			ptr1 = self.head
			ptr2 = self.head
			while count != position:
				ptr2 = ptr2.next
				count = count + 1
			while ptr2 != None:
				prev = ptr1
				ptr1 = ptr1.next
				ptr2 = ptr2.next
		self.count = self.count - 1
		prev.next = ptr1.next
		data = ptr1.data
		return data

	def print_position_from_last(self, position):
		count = 0
		if self.head is None or position > self.count:
			return
		elif position == self.count:
			 return self.head.data	
		else:
			ptr1 = self.head
			ptr2 = self.head

			while count != position:
				ptr2 = ptr2.next
				count = count + 1
			while ptr2 != None:
				ptr1 = ptr1.next
				ptr2 = ptr2.next

		data = ptr1.data
		return data

if __name__ == "__main__":
	llist = Linkedlist()
	llist.add(7)
	llist.add(6)
	llist.add(5)
	llist.add(4)
	llist.add(3)
	llist.add(2)
	llist.add(1)
	llist.display()
	data = llist.print_position_from_last(8)
	print "kth node from last is " + str(data)
	
	data = llist.delete_position_from_last(8)
	print "kth node from last deleted is " + str(data)
	llist.display()


