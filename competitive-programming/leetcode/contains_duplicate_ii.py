# https://leetcode.com/problems/contains-duplicate-ii

from collections import defaultdict


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        pos = defaultdict(lambda: [])

        for i, x in enumerate(nums):
            pos[x].append(i)

        for ixs in pos.values():
            if len(ixs) == 1:
                continue

            s = sorted(ixs)
            for i in range(1, len(s)):
                if s[i] - s[i - 1] <= k:
                    return True

        return False
