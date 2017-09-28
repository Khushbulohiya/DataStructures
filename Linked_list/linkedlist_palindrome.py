


class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class Linkedlist:
	st  = []
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

	def palindrome(self):
		slow = self.head
		fast = self.head
		while fast is not None and fast.next is not None:
			Linkedlist.st.append(slow.data)
			slow = slow.next
			fast = fast.next.next

		while slow is not None:
			data = Linkedlist.st.pop()
			if data == slow.data:
				slow = slow.next
			else:
				print "Not palindrome"
				return
		print "Palindrome"

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
	
	llist.push(3)

	llist.push(2)

	llist.push(1)
	
	llist.display()

	llist.palindrome()