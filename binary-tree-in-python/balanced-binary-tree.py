# create a node
class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

# check balanced binary tree
def isBalancedBianryTree(root, height):
    l = r = 0
    leftH = Height(0)
    rightH = Height(0)
    if root is None:
        height.height = 0
        return 1
    l = isBalancedBianryTree(root.left, leftH)
    r = isBalancedBianryTree(root.right, rightH)
    height.height = max(leftH.height, rightH.height)+1
    if (leftH.height - rightH.height >=2) or (leftH.height - rightH.height >=2):
        return 0
    else:
        return l and r


class Height:
    def __init__(self, height):
        self.height = height

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.left.left.left = Node(6)
    # root.left.left.left.left = Node(6)
    if isBalancedBianryTree(root, Height(0)):
        print("This is balanced binary tree")
    else:
        print("This is not balanced binary tree")