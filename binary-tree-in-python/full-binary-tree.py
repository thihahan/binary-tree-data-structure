# create Node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# check full binary tree
def isFbt(root):
    if root is None:
        return True
    if (root.left is None) and (root.right is None):
        return True
    if root.left and root.right:
        return isFbt(root.left) and isFbt(root.right)
    return False


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    if isFbt(root):
        print("This is full binary tree")
    else:
        print("This is not full binary tree")