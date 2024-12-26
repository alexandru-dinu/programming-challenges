// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode aux(-1);
        ListNode *last = &aux;

        while (l1 and l2) {
            if (l1->val <= l2->val) {
                last->next = l1;
                last = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }

        if (l1)
            last->next = l1;
        if (l2)
            last->next = l2;

        return aux.next;
    }
};