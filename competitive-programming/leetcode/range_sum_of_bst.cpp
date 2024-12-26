// https://leetcode.com/problems/range-sum-of-bst

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
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        if (!root)
            return 0;

        int s = 0;

        if (L <= root->val && root->val <= R)
            s += root->val;

        if (L <= root->val)
            s += rangeSumBST(root->left, L, min(root->val, R));

        if (root->val <= R)
            s += rangeSumBST(root->right, max(root->val, L), R);

        return s;
    }
};