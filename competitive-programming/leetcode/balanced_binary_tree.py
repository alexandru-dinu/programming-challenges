# https://leetcode.com/problems/balanced-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def aux(root):
            if root is None:
                return 0

            left = aux(root.left)
            right = aux(root.right)

            # propagated
            if left is None or right is None:
                return None

            # found a point of imbalance, propagate upwards
            if abs(left - right) > 1:
                return None

            return 1 + max(left, right)

        if root is None:
            return True

        return aux(root)
