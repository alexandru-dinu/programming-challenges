// https://leetcode.com/problems/univalued-binary-tree

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
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;

        return aux(root, root->val);
    }

    bool aux(TreeNode *n, int x)
    {
        if (!n)
            return true;

        if (n->val != x)
            return false;

        return aux(n->left, x) && aux(n->right, x);
    }
};