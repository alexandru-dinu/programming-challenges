# https://leetcode.com/problems/can-place-flowers


class Solution:
    def canPlaceFlowers(self, xs: List[int], n: int) -> bool:
        xs = [0, *xs, 0]
        c = 0
        for i in range(1, len(xs) - 1):
            if sum(xs[i - 1 : i + 2]) == 0:
                xs[i] = 1
                c += 1

        return c >= n
