// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        const int n = preorder.size();

        if (n == 0)
            return NULL;

        int r = preorder[0];
        TreeNode *root = new TreeNode(r);

        if (n == 1)
            return root;

        auto it = partition(
          begin(preorder) + 1, end(preorder), [r](int x) { return x < r; });
        vector<int> left, right;
        move(begin(preorder) + 1, it, back_inserter(left));
        move(it, end(preorder), back_inserter(right));

        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);

        return root;
    }
};