# https://leetcode.com/problems/third-maximum-number


def imax(xs, ignore):
    m = float("-inf")
    idx = -1
    for i, x in enumerate(xs):
        if x >= m and x not in ignore:
            m = x
            idx = i
    return (idx, m)


class Solution:
    def thirdMax(self, xs: List[int]) -> int:
        if len(xs) < 3:
            return max(xs)

        ms = set()
        for i in range(3):
            j, m = imax(xs[: len(xs) - i], ignore=ms)
            xs[len(xs) - 1 - i], xs[j] = xs[j], xs[len(xs) - 1 - i]
            ms.add(m)

        return xs[-3]
