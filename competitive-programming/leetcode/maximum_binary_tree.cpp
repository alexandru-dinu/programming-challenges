// https://leetcode.com/problems/maximum-binary-tree

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;

        auto max_val_it = std::max_element(std::begin(nums), std::end(nums));
        int max_index = std::distance(std::begin(nums), max_val_it);

        TreeNode *root = new TreeNode(nums[max_index]);

        std::vector<int> left(std::begin(nums), max_val_it);
        std::vector<int> right(max_val_it + 1, std::end(nums));

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};