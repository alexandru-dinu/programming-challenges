# https://leetcode.com/problems/maximum-difference-between-increasing-elements

from itertools import accumulate


def arr_sub(xs, ys):
    return map(lambda z: z[0] - z[1], zip(xs, ys))


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        return max(
            [-1, *filter(lambda x: x != 0, arr_sub(nums, accumulate(nums, func=min)))]
        )
