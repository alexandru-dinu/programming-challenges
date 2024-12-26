// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == key) {
            // find rightmost node of left subtree
            TreeNode *left_st = root->left;
            if (left_st == nullptr)
                return root->right;

            TreeNode *rightmost = left_st;

            while (rightmost->right != nullptr)
                rightmost = rightmost->right;

            rightmost->right = root->right;

            return root->left;
        }

        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
            root->left = deleteNode(root->left, key);

        return root;
    }
};