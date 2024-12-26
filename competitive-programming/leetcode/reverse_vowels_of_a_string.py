# https://leetcode.com/problems/reverse-vowels-of-a-string


class Solution:
    def reverseVowels(self, s: str) -> str:
        def is_vowel(c):
            return c.lower() in {"a", "e", "i", "o", "u"}

        l = 0
        r = len(s) - 1
        s = list(s)

        while l < r:
            while l < r and not is_vowel(s[l]):
                l += 1
            while l < r and not is_vowel(s[r]):
                r -= 1

            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1

        return "".join(s)
