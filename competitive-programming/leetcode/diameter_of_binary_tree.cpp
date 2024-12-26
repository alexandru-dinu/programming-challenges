// https://leetcode.com/problems/diameter-of-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int depth(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;

        int l = depth(root->left, diameter);
        int r = depth(root->right, diameter);

        diameter = max(diameter, l + r + 1);

        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 1;

        depth(root, d);

        return d - 1;
    }
};