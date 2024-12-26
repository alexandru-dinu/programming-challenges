# https://leetcode.com/problems/remove-element

"""
  3 2 2 3 _
j   ^
i ^        
"""


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i
