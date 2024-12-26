# https://leetcode.com/problems/keyboard-row

import re


class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """

        match_r1 = lambda w: bool(re.match("^[qwertyuiop]*$", w.lower()))
        match_r2 = lambda w: bool(re.match("^[asdfghjkl]*$", w.lower()))
        match_r3 = lambda w: bool(re.match("^[zxcvbnm]*$", w.lower()))

        res = [w for w in words if match_r1(w) or match_r2(w) or match_r3(w)]

        return res
