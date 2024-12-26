// https://leetcode.com/problems/add-two-numbers

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *res = new ListNode(0);
        ListNode *rHead = res;
        int carry = 0, s, x1, x2;

        while (l1 != NULL || l2 != NULL || carry > 0) {
            x1 = (l1 == NULL) ? 0 : l1->val;
            x2 = (l2 == NULL) ? 0 : l2->val;

            s = x1 + x2 + carry;
            carry = s / 10;

            res->next = new ListNode(s % 10);
            res = res->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return rHead->next;
    }
};