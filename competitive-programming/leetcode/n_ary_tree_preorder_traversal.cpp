// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
  public:
    void recursive(Node *root, vector<int> &acc)
    {
        if (!root)
            return;

        acc.push_back(root->val);

        for (Node *n : root->children)
            recursive(n, acc);
    }

    void iterative(Node *root, vector<int> &acc)
    {
        if (!root)
            return;

        stack<Node *> st;
        st.push(root);

        while (!st.empty()) {
            Node *n = st.top();
            st.pop();

            acc.push_back(n->val);

            int c = n->children.size();
            for (int i = c - 1; i >= 0; i--)
                st.push(n->children[i]);
        }
    }

    vector<int> preorder(Node *root)
    {
        vector<int> ans;

        // recursive(root, ans);

        iterative(root, ans);

        return ans;
    }
};