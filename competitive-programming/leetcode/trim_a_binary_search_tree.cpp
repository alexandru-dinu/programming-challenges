// https://leetcode.com/problems/trim-a-binary-search-tree

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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return NULL;

        TreeNode *troot = NULL;

        if (root->val < L)
            return trimBST(root->right, L, R);
        if (root->val > R)
            return trimBST(root->left, L, R);

        if (root->val >= L && root->val <= R) {
            troot = new TreeNode(root->val);
            troot->left = trimBST(root->left, L, R);
            troot->right = trimBST(root->right, L, R);
        }

        return troot;
    }
};