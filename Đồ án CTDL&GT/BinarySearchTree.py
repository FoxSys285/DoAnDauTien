class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if node is None:
            return TreeNode(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        return node

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        if node is None:
            return node
        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            temp = self._min_value_node(node.right)
            node.key = temp.key
            node.right = self._delete(node.right, temp.key)
        return node

    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def in_order_traversal(self):
        result = []
        self._in_order(self.root, result)
        return result

    def _in_order(self, node, result):
        if node:
            self._in_order(node.left, result)
            result.append(node.key)
            self._in_order(node.right, result)

    def pre_order_traversal(self):
        result = []
        self._pre_order(self.root, result)
        return result

    def _pre_order(self, node, result):
        if node:
            result.append(node.key)
            self._pre_order(node.left, result)
            self._pre_order(node.right, result)

    def post_order_traversal(self):
        result = []
        self._post_order(self.root, result)
        return result

    def _post_order(self, node, result):
        if node:
            self._post_order(node.left, result)
            self._post_order(node.right, result)
            result.append(node.key)


bst = BinarySearchTree()
for key in [50, 30, 70, 20, 40, 60, 80]:
    bst.insert(key)

print("In-order:", bst.in_order_traversal())
print("Pre-order:", bst.pre_order_traversal())
print("Post-order:", bst.post_order_traversal())

b = int(input("Nhập phần tử cần xóa: "))
node = bst.delete(b)
print("Cây sau khi xóa",b,bst.in_order_traversal())


a = int(input("Nhập phần tử cần tìm: "))
node = bst.search(a)
if node is None:
    print("Không tìm thấy phần tử")
else:
    print("Đã tìm thấy" , node.key)