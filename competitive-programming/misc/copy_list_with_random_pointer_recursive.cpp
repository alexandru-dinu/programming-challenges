#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int val;
    Node *next, *random;
    Node(int x)
      : val(x)
      , next(NULL)
      , random(NULL)
    {}
};

class Solution
{
  public:
    Node *clone(Node *head, std::map<void *, void *> &m)
    {
        if (head == NULL)
            return NULL;

        Node *node = new Node(head->val);
        m[(void *)head] = (void *)node;
        node->next = clone(head->next, m);

        return node;
    }

    Node *copyRandomList(Node *head)
    {
        std::map<void *, void *> m;

        Node *copy = clone(head, m);

        Node *auxc = copy;
        Node *auxh = head;

        while (auxh != NULL) {
            auxc->random = (Node *)m[(Node *)auxh->random];

            auxc = auxc->next;
            auxh = auxh->next;
        }

        return copy;
    }
};

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    n1->next = n2;
    n1->random = n3;

    n2->next = n3;
    n2->random = n1;

    n3->next = NULL;
    n3->random = n2;

    Solution s;

    Node *c1 = s.copyRandomList(n1);
    Node *c2 = c1->next;
    Node *c3 = c2->next;

    cout << (void *)c2->random << endl;
    cout << (void *)c1 << endl;

    return 0;
}
