# https://leetcode.com/problems/house-robber-ii

"""
M[i] = max(nums[i] + M[i-2], M[i-1])

2 7 9 3 5 1
"""


def v1(nums: List[int]) -> int:
    M = [0] * (len(nums) + 2)

    for i in range(2, len(nums) + 2):
        M[i] = max(nums[i - 2] + M[i - 2], M[i - 1])

    return M[-1]


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        # skip first or last house
        return max(v1(nums[:-1]), v1(nums[1:]))
