# https://leetcode.com/problems/factorial-trailing-zeroes


class Solution:
    def trailingZeroes(self, n: int) -> int:
        t = 0
        f2 = f5 = 0

        for i in range(1, n + 1):
            j = i
            while j % 2 == 0:
                f2 += 1
                j /= 2

            j = i
            while j % 5 == 0:
                f5 += 1
                j /= 5

            d = min(f2, f5)
            t += d
            f2 -= d
            f5 -= d

            # while f2 > 0 and f5 > 0:
            #     f2 -= 1
            #     f5 -= 1
            #     t += 1

        return t
