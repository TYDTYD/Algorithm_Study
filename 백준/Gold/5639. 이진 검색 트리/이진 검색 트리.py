import sys
sys.setrecursionlimit(100000)
input=sys.stdin.readline

# 노드 구현
class Node(object):
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data

# 이진트리 구현
class BinarySearchTree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root=self._insert_value(self.root,data)
        return self.root is not None

    def _insert_value(self, node, data):
        if node is None:
            node = Node(data)
        else:
            if data <= node.data:
                node.left = self._insert_value(node.left, data)
            else:
                node.right = self._insert_value(node.right, data)
        return node
        
# 후위 순회
    def PostOrder(self, root):
        if root is None:
            pass
        else:
            self.PostOrder(root.left)
            self.PostOrder(root.right)
            print(root.data)

array=[]

while(True):
    try:
        array.append(int(input()))
    except:
        break

bst = BinarySearchTree()
for x in array:
    bst.insert(x)

bst.PostOrder(bst.root)