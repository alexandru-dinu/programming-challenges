# https://leetcode.com/problems/longest-common-prefix

from itertools import takewhile


def lmap(f, xs):
    return list(map(f, xs))


def allEqual(xs: List[str]) -> bool:
    return xs.count(xs[0]) == len(xs)


def sol1(xs: List[str]) -> str:
    # base case (first pattern: [] or there is a string of len == 0)
    if len(xs) == 0 or any(len(x) == 0 for x in xs):
        return ""

    y, *ys = lmap(lambda x: x[0], xs)

    if ys.count(y) == len(ys):
        return y + sol1(lmap(lambda x: x[1:], xs))
    return ""


# https://www.youtube.com/watch?v=3o4RR9TKdFc
def sol2(xs: List[str]) -> str:
    return "".join(x[0] for x in takewhile(allEqual, zip(*xs)))


def sol3(xs: List[str]) -> str:
    return os.path.commonprefix(xs)


class Solution:
    def longestCommonPrefix(self, xs: List[str]) -> str:
        s = [sol1(xs), sol2(xs), sol3(xs)]
        assert allEqual(s)

        return s[0]
