// https://leetcode.com/problems/reverse-linked-list

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
    ListNode *iterative(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = NULL;

        while (cur != NULL) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode *recursive(ListNode *head)
    {
        // reverse(x:xs) = reverse(xs) ++ (x:[])
        if (!head || !head->next)
            return head;

        ListNode *rest = recursive(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    ListNode *reverseList(ListNode *head)
    {

        return recursive(head);

        // return iterative(head);
    }
};