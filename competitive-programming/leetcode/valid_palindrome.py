# https://leetcode.com/problems/valid-palindrome

import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        r = re.sub(r"[^a-z0-9]", "", s.lower())
        return r == r[::-1]
