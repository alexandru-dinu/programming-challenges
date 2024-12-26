# https://leetcode.com/problems/remove-duplicates-from-sorted-list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        h = head
        q = head.next

        while True:
            # find the end of the run of consecutive items
            while q is not None and q.val == h.val:
                q = q.next

            # remove run of consecutive items
            h.next = q

            try:
                h = h.next
                q = q.next
            except AttributeError:
                # found None
                break

        return head
