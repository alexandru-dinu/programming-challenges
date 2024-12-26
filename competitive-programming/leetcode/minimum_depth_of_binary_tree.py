# https://leetcode.com/problems/minimum-depth-of-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if root.left is None and root.right is None:
            return 1

        left = float("inf")
        if root.left is not None:
            left = 1 + self.minDepth(root.left)

        right = float("inf")
        if root.right is not None:
            right = 1 + self.minDepth(root.right)

        return min(left, right)
