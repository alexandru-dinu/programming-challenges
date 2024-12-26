# https://leetcode.com/problems/contains-duplicate


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        xs = sorted(nums)

        for i in range(1, len(nums)):
            if xs[i] == xs[i - 1]:
                return True

        return False
