# https://leetcode.com/problems/longest-palindrome

from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = Counter(list(s))
        ans = 0
        put_odd = False

        for c, n in reversed(cnt.most_common()):
            # if n % 2 == 0:
            #     ans += n
            # else:
            #     ans += n - put_odd
            #     put_odd = True

            ans += n - (put_odd and n % 2 == 1)
            put_odd |= n % 2 == 1

        return ans
