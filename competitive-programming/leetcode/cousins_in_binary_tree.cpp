// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode *root, int x, int y)
    {
        /*
         * level-order traversal
         * search each level for possible cousins
         * don't search further if not needed
         */

        if (!root)
            return false;

        bool found_one = false, siblings = false;
        queue<TreeNode *> q_level, q_aux;
        q_level.push(root);

        while (true) {

            // check current level
            while (!q_level.empty()) {
                TreeNode *n = q_level.front();
                q_level.pop();

                if (n == NULL) {
                    siblings = false;
                    continue;
                }

                if (n->val == x or n->val == y) {
                    if (!found_one)
                        found_one = siblings = true;
                    else
                        return !siblings;
                }

                q_aux.push(n->left);
                q_aux.push(n->right);
                q_aux.push(NULL);
            }

            // one node was found, but there's no point searching forward
            // as cousins should be on the same level
            if (found_one)
                return false;

            // nothing was found on this level, move to the next one
            swap(q_level, q_aux);
        }

        // won't reach this
        assert(false);
    }
};