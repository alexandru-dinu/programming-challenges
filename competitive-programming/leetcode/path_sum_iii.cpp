// https://leetcode.com/problems/path-sum-iii

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
    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return 0;

        int q = aux(root, 0, sum);
        int l = pathSum(root->left, sum);
        int r = pathSum(root->right, sum);

        return q + l + r;
    }

    int aux(TreeNode *root, int pre, int sum)
    {
        if (!root)
            return 0;

        pre += root->val;

        return (pre == sum) + aux(root->left, pre, sum) +
               aux(root->right, pre, sum);
    }
};