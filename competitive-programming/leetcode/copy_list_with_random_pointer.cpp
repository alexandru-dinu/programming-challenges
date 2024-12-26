// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
  public:
    Node *clone(Node *head, std::map<void *, void *> &m)
    {
        Node *auxh = head;
        Node *auxNewHead = NULL;
        Node *auxNewTail = NULL;

        while (auxh != NULL) {
            if (auxNewHead == NULL) {
                push(&auxNewHead, auxh->val);
                auxNewTail = auxNewHead;

                m[(void *)auxh] = (void *)auxNewHead;
            } else {
                push(&(auxNewTail->next), auxh->val);
                m[(void *)auxh] = (void *)(auxNewTail->next);
                auxNewTail = auxNewTail->next;
            }

            auxh = auxh->next;
        }

        return auxNewHead;
    }

    void push(Node **head, int val)
    {
        Node *node = new Node(val);
        node->next = *head;
        *head = node;
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