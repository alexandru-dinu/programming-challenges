# https://leetcode.com/problems/guess-number-higher-or-lower

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:


class Solution:
    def guessNumber(self, n: int) -> int:
        lo, hi = 1, n

        while True:
            g = int(lo + (hi - lo) / 2)
            r = guess(g)

            if r == 0:
                return g

            if r == 1:
                lo = g + 1

            if r == -1:
                hi = g - 1

        assert False
