# https://leetcode.com/problems/letter-combinations-of-a-phone-number

from itertools import product


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        ds = [None, None, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        return ["".join(y) for y in product(*(ds[int(d)] for d in digits))]
