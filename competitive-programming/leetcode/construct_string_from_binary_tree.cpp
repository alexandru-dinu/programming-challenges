// https://leetcode.com/problems/construct-string-from-binary-tree

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
    string tree2str(TreeNode *t)
    {
        if (!t)
            return "";

        if (is_leaf(t))
            return to_string(t->val);

        string s = to_string(t->val);

        string left = tree2str(t->left);
        string right = tree2str(t->right);

        s += "(" + left + ")";

        if (right.size() != 0)
            s += "(" + right + ")";

        return s;
    }

    bool is_leaf(TreeNode *r)
    {
        return (!r->left && !r->right);
    }
};