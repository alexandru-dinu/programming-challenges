// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    void deleteNode(ListNode *node)
    {
        //         ListNode *h = node;
        //         ListNode *p = NULL;

        //         while (h->next) {
        //             h->val = h->next->val;
        //             p = h;
        //             h = h->next;
        //         }

        //         p->next = NULL;

        // or smarter:
        node->val = node->next->val;
        node->next = node->next->next;
    }
};