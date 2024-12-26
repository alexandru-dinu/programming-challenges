# https://leetcode.com/problems/repeated-substring-pattern


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)

        # for i in range(1, n//2 + 1):
        for i in range(n // 2, 0, -1):  # ~1/3x faster
            if s == s[:i] * (n // i):
                return True

        return False
