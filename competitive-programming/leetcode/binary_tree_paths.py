# https://leetcode.com/problems/binary-tree-paths

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def is_leaf(root):
    return root.left is None and root.right is None


def helper(root, path, acc):
    if is_leaf(root):
        acc.append([*path, root.val])
        return

    if root.left:
        helper(root.left, [*path, root.val], acc)

    if root.right:
        helper(root.right, [*path, root.val], acc)


class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        acc = []
        helper(root, [], acc)

        return ["->".join(map(str, p)) for p in acc]
