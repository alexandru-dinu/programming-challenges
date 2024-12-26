# https://leetcode.com/problems/fibonacci-number

from itertools import islice


def fib_gen(a=0, b=1):
    while True:
        yield a
        a, b = b, a + b


# 0 1 1 2 3


class Solution:
    def fib(self, n: int) -> int:
        *_, out = islice(fib_gen(), n + 1)
        return out
