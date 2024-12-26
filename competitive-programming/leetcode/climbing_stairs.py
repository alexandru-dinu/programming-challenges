# https://leetcode.com/problems/climbing-stairs


def fib(a, b):
    while True:
        yield a
        a, b = b, a + b


class Solution:
    def climbStairs(self, n: int) -> int:
        from itertools import islice

        *_, rv = islice(fib(1, 1), n + 1)
        return rv
