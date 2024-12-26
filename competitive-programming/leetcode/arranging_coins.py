# https://leetcode.com/problems/arranging-coins

from math import sqrt


class Solution:
    def arrangeCoins(self, n: int) -> int:
        """
        max k
        k(k+1) / 2 <= n
        k(k+1) <= 2n
        k**2 + k -2n <= 0
        """

        return int(-0.5 + 0.5 * sqrt(1 + 8 * n))
