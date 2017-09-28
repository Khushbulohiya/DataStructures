def levelorder(node):
	if node is None:
		return
    queue = []
    queue.append(node)
	while(len(queue) > 0):
		node = queue.pop()
		print node.data

		if node.left is not None:
			queue.append(node.left)
		if node.right is not None:
			queue.append(node.right)
