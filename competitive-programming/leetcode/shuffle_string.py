# https://leetcode.com/problems/shuffle-string


class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        r, _ = zip(*sorted(zip(s, indices), key=lambda x: x[1]))
        return "".join(r)
