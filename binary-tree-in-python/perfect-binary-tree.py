# create Node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# search depth
def depth(root):
    temp = root
    i = 0
    while temp is not None:
        temp = temp.left
        i += 1
    return i

# check full binary tree
def isPbt(root, depth, level):
    if root is None:
        return True
    if (root.left is None) and (root.right is None):
        return depth == level+1
    if root.left and root.right:
        return isPbt(root.left, depth, level+1) and isPbt(root.right, depth, level+1)
    return False


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    if isPbt(root, depth(root), 0):
        print("This is perfect binary tree")
    else:
        print("This is not perfect binary tree")