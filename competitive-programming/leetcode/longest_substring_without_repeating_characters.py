# https://leetcode.com/problems/longest-substring-without-repeating-characters


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lss = set()
        rv = 0
        i = j = 0

        while i < len(s):
            if s[i] not in lss:
                lss.add(s[i])
                rv = max(rv, len(lss))
                i += 1
            else:
                # erase past items
                lss.remove(s[j])
                j += 1

        return rv
