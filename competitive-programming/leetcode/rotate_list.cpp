// https://leetcode.com/problems/rotate-list

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
    void rotateOnce(ListNode **head)
    {
        ListNode *prev = NULL, *last = *head;

        while (last->next) {
            prev = last;
            last = last->next;
        }

        prev->next = NULL;
        last->next = *head;
        *head = last;
    }

    std::size_t size(ListNode *h)
    {
        std::size_t s;

        for (s = 0; h; s++, h = h->next)
            ;

        return s;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next)
            return head;

        k %= size(head);

        for (int i = 0; i < k; rotateOnce(&head), i++)
            ;

        return head;
    }
};