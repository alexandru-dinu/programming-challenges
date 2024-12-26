# https://leetcode.com/problems/ugly-number


class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0:
            return False
        if n == 1:
            return True

        while n != 1:
            found = False

            for a in [2, 3, 5]:
                if n % a == 0:
                    n = n // a
                    found = True
                    break

            if not found:
                return False

        return True
