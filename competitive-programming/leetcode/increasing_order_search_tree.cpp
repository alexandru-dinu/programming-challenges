// https://leetcode.com/problems/increasing-order-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
  private:
    TreeNode *tmp;

  public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *x = new TreeNode(-1);
        tmp = x;
        inorder(root);
        return x->right;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        root->left = NULL;
        tmp->right = root;
        tmp = root;

        inorder(root->right);
    }
};