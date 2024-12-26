# https://leetcode.com/problems/sum-of-left-leaves

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def isLeaf(root):
    return root.left is None and root.right is None


class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if isLeaf(root):
            return 0

        left = self.sumOfLeftLeaves(root.left)
        right = self.sumOfLeftLeaves(root.right)

        if root.left is not None and isLeaf(root.left):
            return root.left.val + right
        else:
            return left + right
