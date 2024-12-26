// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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
    vector<int> postorder(Node *root)
    {
        vector<int> v;

        aux(root, v);

        return v;
    }

    void aux(Node *root, vector<int> &acc)
    {
        if (!root)
            return;

        for (const auto &n : root->children) {
            aux(n, acc);
        }

        acc.push_back(root->val);
    }
};