// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode *root)
    {
        double inf = std::numeric_limits<double>::infinity();

        return inRange(root, -inf, inf);
    }

    bool inRange(TreeNode *root, double lo, double hi)
    {
        if (!root)
            return true;

        if (lo < root->val && root->val < hi)
            return inRange(root->left, lo, root->val) &&
                   inRange(root->right, root->val, hi);

        return false;
    }
};