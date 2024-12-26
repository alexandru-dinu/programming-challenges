# https://leetcode.com/problems/merge-k-sorted-lists

from heapq import heappush, heappop


class Item:
    def __init__(self, fst, snd):
        self.fst = fst
        self.snd = snd

    def __lt__(self, other):
        return self.fst <= other.fst


# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None

        pq = []
        ptr = ListNode(val=None)
        res = ptr

        for l in filter(lambda x: x is not None, lists):
            heappush(pq, Item(l.val, l))

        while len(pq) > 0:
            node = heappop(pq).snd

            # add node to the final result
            ptr.next = node
            ptr = ptr.next

            # advance current list
            node = node.next

            # push next node to heap
            if node is not None:
                heappush(pq, Item(node.val, node))

        return res.next
