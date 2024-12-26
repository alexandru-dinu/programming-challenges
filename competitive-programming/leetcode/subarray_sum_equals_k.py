# https://leetcode.com/problems/subarray-sum-equals-k

from collections import defaultdict
from itertools import accumulate


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        pre = [*accumulate(nums, lambda x, y: x + y)]
        # pre[i] = sum [0 .. i]

        m = defaultdict(lambda: 0)
        # m[x] = # of continuous subarrays that sum to x
        m[0] = 1
        acc = 0
        ans = 0

        for p in pre:
            ans += m[p - k]
            m[p] += 1

        return ans
