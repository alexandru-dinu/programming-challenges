# https://leetcode.com/problems/n-th-tribonacci-number

from itertools import islice


def _tri(a, b, c):
    while True:
        yield a
        a, b, c = b, c, a + b + c


class Solution:
    def tribonacci(self, n: int) -> int:
        *_, rv = islice(_tri(a=0, b=1, c=1), n + 1)
        return rv
