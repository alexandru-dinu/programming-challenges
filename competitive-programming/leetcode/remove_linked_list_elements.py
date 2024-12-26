# https://leetcode.com/problems/remove-linked-list-elements

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def iterative(head: Optional[ListNode], val: int) -> Optional[ListNode]:
    last = ListNode(val=None, next=head)
    rv = last

    while True:
        while head and head.val == val:
            head = head.next

        last.next = head

        if head:
            last = head
            head = head.next
        else:
            break

    return rv.next


def recursive(head: Optional[ListNode], val: int) -> Optional[ListNode]:
    if not head:
        return None

    head.next = recursive(head.next, val)

    if head.val == val:
        return head.next
    else:
        return head


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # return iterative(head, val)
        return recursive(head, val)
