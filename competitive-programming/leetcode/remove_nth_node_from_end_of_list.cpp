// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *h, *fast, *slow, **ret;

        h = new ListNode(0);
        h->next = head;
        fast = h;
        slow = h;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return h->next;
    }
};