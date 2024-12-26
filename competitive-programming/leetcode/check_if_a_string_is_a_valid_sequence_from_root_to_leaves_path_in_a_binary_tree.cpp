// https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree

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
    bool dfs(TreeNode *root, const vector<int> &arr, int idx)
    {
        if (!root)
            return false;

        // end of arr or no match => exit
        if (idx == arr.size() or root->val != arr[idx])
            return false;

        // leaf => return true iff we're at the last element of arr and it
        // equals leaf's value
        if (!root->left and !root->right)
            return (idx == arr.size() - 1) and (root->val == arr[idx]);

        bool l = dfs(root->left, arr, idx + 1);
        bool r = dfs(root->right, arr, idx + 1);

        return l or r;
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return dfs(root, arr, 0);
    }
};