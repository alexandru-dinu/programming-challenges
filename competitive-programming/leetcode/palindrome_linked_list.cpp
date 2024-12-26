// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode *head)
    {
        vector<int> xs;

        ListNode *h = head;
        while (head) {
            xs.push_back(head->val);
            head = head->next;
        }

        int n = xs.size();
        for (int i = 0; i < n / 2; i++) {
            if (xs[i] != xs[n - i - 1])
                return false;
        }

        return true;
    }
};