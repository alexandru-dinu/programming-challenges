// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *auxA = headA, *auxB = headB;

        while (auxA != auxB) {
            auxA = (auxA == NULL) ? headB : auxA->next;
            auxB = (auxB == NULL) ? headA : auxB->next;
        }

        return auxA;
    }
};