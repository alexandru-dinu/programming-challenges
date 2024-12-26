// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
  public:
    int solve(TreeNode *root, int &s)
    {
        if (!root)
            return 0;

        // if negative, ignore
        int l = max(0, solve(root->left, s));
        int r = max(0, solve(root->right, s));

        s = max(s, l + r + root->val);

        // max(l, r) chooses the path that
        // maximizes the sum through root
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        int s = INT_MIN;

        solve(root, s);

        return s;
    }
};