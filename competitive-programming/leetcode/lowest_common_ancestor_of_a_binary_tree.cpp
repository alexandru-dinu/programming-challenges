// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

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
        TreeNode *lca_node = NULL;

        find(root, p, q, &lca_node);

        return lca_node;
    }

    bool find(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **lca_node)
    {
        if (!root)
            return NULL;

        bool left = find(root->left, p, q, lca_node);
        bool right = find(root->right, p, q, lca_node);

        bool at_least = (left == true || right == true);

        bool case_1 = (left == true && right == true);
        bool case_2 = (at_least && (root == p || root == q));

        if (case_1 || case_2) {
            if (*lca_node == NULL)
                *lca_node = root;
        }

        if (root == p || root == q)
            return root;

        return at_least;
    }
};