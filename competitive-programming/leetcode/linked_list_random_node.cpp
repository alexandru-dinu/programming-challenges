// https://leetcode.com/problems/linked-list-random-node

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
  private:
    ListNode *_h;
    int size = 0;

  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode *head)
    {
        this->_h = head;
        ListNode *tmp = head;
        while (tmp) {
            this->size++;
            tmp = tmp->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        ListNode *t = this->_h;
        int r = static_cast<int>(rand() % size);
        while (r) {
            t = t->next;
            r--;
        }
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */