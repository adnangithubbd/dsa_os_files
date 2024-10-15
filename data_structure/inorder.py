class TreeNode:
    def __init__(self,value) -> None:
        self.value=value
        self.right=None
        self.left=None
    
def pre_order(root):
        if root is None:
            return
        print(root.value,end=' ')
        pre_order(root.left)
        pre_order(root.right)

    
def in_order(root):
        if root is None:
            return
        pre_order(root.left)
        print(root.value,end=' ')
        pre_order(root.right)

def post_order(root):
        if root is None:
            return
        pre_order(root.left)
        pre_order(root.right)
        print(root.value,end=' ')



root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

def max_depth(root):
    if root is None:
        return 0
    return 1 +max(max_depth(root.left),max_depth(root.right))
# print(max_depth(root))


# ;; --------------------
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(2)
root.left.left = TreeNode(3)
root.left.right = TreeNode(4)
root.right.left = TreeNode(4)
root.right.right = TreeNode(3)

# def issymetric(root):
#     def ismirror(t1,t2):
#         if not t1 and not t2:
#             return True
#         if not t1 or not t1:
#             return False
#         return (t1.value==t2.value) and ismirror(t1.left,t2.right) and ismirror(t1.right,t2.right)
#     return ismirror(root,root)

def issymetric(root):
    def ismirror(t1,t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return (t1.value==t2.value) and ismirror(t1.left,t2.right) and ismirror(t1.right,t2.left)
    return ismirror(root,root)
print(issymetric(root))


# return tree path 
