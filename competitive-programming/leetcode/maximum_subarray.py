# https://leetcode.com/problems/maximum-subarray


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        meh = msf = float("-inf")

        for x in nums:
            reset = x  # start fresh from this x (sum was negative)
            accumulate = meh + x  # accumulate
            meh = max(reset, accumulate)
            msf = max(msf, meh)

        return msf
