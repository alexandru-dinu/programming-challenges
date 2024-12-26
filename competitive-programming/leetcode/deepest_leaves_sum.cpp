// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> q1, q2;
        q1.push(root);

        while (true) {
            int ans = 0;

            while (!q1.empty()) {
                TreeNode *n = q1.front();
                q1.pop();

                if (!n)
                    continue;

                if (!n->left and !n->right)
                    ans += n->val;

                if (n->left)
                    q2.push(n->left);
                if (n->right)
                    q2.push(n->right);
            }

            // no deeper level
            if (q2.empty())
                return ans;

            // go to next level
            swap(q1, q2);
        }

        assert(false);
    }
};