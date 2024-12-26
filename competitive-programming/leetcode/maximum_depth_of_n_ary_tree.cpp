// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
  public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        int max = 0;

        for (const auto &n : root->children) {
            int d = maxDepth(n);
            max = (d > max) ? d : max;
        }

        return max + 1;
    }
};