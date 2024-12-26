# https://leetcode.com/problems/missing-number


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        x = 0

        for i in range(len(nums)):
            x ^= i ^ nums[i]

        return x ^ len(nums)
