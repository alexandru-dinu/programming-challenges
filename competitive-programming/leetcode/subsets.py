# https://leetcode.com/problems/subsets


class Solution:
    def subsets(self, xs: List[int]) -> List[List[int]]:
        """
        Get subsets according to binary repr [0 .. 2**n).
        """
        n = len(xs)

        return [[xs[j] for j in range(n) if (i >> j) & 1] for i in range(2 ** n)]
