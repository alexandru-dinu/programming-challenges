# https://leetcode.com/problems/construct-the-rectangle

from math import sqrt


class Solution:
    def constructRectangle(self, n: int) -> List[int]:
        d = int(sqrt(n))
        while True:
            if n % d == 0:
                return [n // d, d]
            else:
                d -= 1
