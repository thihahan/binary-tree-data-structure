# create Node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# search the number of nodes
def nodes(root):
    if root is None:
        return 0
    return 1+nodes(root.left) + nodes(root.right)

# check full binary tree
def isCbt(root, index, number_of_nodes):
    if root is None:
        return True
    if index >= number_of_nodes:
        return False
    return isCbt(root.left, 2*index +1, number_of_nodes) and isCbt(root.right, 2*index+2, number_of_nodes)


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    # root.right.right = Node(7)
    if isCbt(root, 0, nodes(root)):
        print("This is complete binary tree")
    else:
        print("This is not complete binary tree")