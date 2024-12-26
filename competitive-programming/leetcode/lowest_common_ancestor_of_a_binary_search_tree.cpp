// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::vector<TreeNode *> p_path = cons_path(root, p);
        std::vector<TreeNode *> q_path = cons_path(root, q);

        int lim = std::min(p_path.size(), q_path.size());

        for (int i = 0; i < lim; i++)
            if (p_path[i]->val != q_path[i]->val)
                return p_path[i - 1];

        if (p_path.size() < q_path.size())
            return p_path[lim - 1];
        else
            return q_path[lim - 1];
    }

    std::vector<TreeNode *> cons_path(TreeNode *root, TreeNode *node)
    {
        std::vector<TreeNode *> path;

        while (root->val != node->val) {
            path.push_back(root);
            if (node->val > root->val)
                root = root->right;
            else
                root = root->left;
        }

        path.push_back(root);

        return path;
    }
};