# https://leetcode.com/problems/house-robber

"""
2 7 9 3 1 5
^   ^     ^ = 16

2 7 9 3 1 5 9
^   ^   ^   ^ = 21


M[i] = max money until house i

max(
    either rob current house and use the money from i-2 to not skip adjacent,
    either skip this house
)

M[i] = max(nums[i] + M[i-2], M[i-1])
"""


class Solution:
    def rob(self, nums: List[int]) -> int:
        M = [0] * (len(nums) + 2)

        for i in range(2, len(nums) + 2):
            M[i] = max(nums[i - 2] + M[i - 2], M[i - 1])

        return M[-1]
