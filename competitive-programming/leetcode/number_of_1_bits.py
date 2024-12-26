# https://leetcode.com/problems/number-of-1-bits


class Solution:
    def hammingWeight(self, n: int) -> int:
        t = 0
        while n > 0:
            t += n & 1
            n >>= 1
        return t
