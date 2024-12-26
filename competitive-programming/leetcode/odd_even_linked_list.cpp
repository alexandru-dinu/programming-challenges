// https://leetcode.com/problems/odd-even-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *o = head, *e = head->next;
        ListNode *fo = o, *fe = e, *lo;

        while (true) {
            lo = o;
            o->next = e->next;
            o = o->next;

            if (o) {
                e->next = o->next;
                e = e->next;
                if (!e) {
                    o->next = fe;
                    break;
                }
            } else {
                lo->next = fe;
                break;
            }
        }

        return fo;
    }
};