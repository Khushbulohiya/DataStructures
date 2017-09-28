#!usr/bin/python

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class Linkedlist:
	def __init__(self):
		self.head = None

	def push(self, data):
		if self.head == None:
			new_node = Node(data)
			self.head = new_node
		else:
			new_node = Node(data)
			new_node.next = self.head
			self.head = new_node

	def append(self, data):
		if self.head is None:
			new_node = Node(data)
			self.head = new_node
		else:
			node = self.head
			while node.next is not None:
				node = node.next
			new_node = Node(data)
			node.next = new_node

	def rightafter(self, prev_node, data):
		if self.head is None:
			print "Previous node is not present in the linked list" 
			return
		else:
			node = self.head
			while node != prev_node:
				node = node.next
			new_node = Node(data)
			new_node.next = prev_node.next
			prev_node.next = new_node

	#cannot delet this way if node to be deleted is the last node
	def delete(self, node):
		if node is None and node.next is None:
			return
		else:
			new_node = node.next
			node.data = new_node.data
			node.next = new_node.next

	def display(self):
		node = self.head
		print "***************************"
		while node is not None:
			print node.data
			node = node.next


if __name__ == "__main__":
	llist = Linkedlist()

	llist.push(1)

	llist.push(2)

	llist.push(3)

	llist.push(4)

	llist.push(0)

	llist.append(10)

	llist.rightafter(llist.head.next.next, 11)

	llist.display()

	llist.delete(llist.head.next.next)

	llist.display()