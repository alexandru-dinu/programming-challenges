# https://leetcode.com/problems/find-the-difference

from collections import Counter


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        cs, ct = Counter(s), Counter(t)
        try:
            return (set(ct) - set(cs)).pop()
        except KeyError:
            for k in cs.keys():
                if ct[k] > cs[k]:
                    return k
