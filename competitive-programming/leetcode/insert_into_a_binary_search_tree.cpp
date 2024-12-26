// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else if (val > root->val)
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};