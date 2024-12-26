// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return mEquals(root->left, root->right);
    }

    bool mEquals(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;

        if (!l || !r)
            return false;

        return (l->val == r->val) && mEquals(l->left, r->right) &&
               mEquals(l->right, r->left);
    }
};