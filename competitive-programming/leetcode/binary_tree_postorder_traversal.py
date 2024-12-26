# https://leetcode.com/problems/binary-tree-postorder-traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        acc = []
        acc.extend(self.postorderTraversal(root.left))
        acc.extend(self.postorderTraversal(root.right))
        acc.append(root.val)

        return acc
