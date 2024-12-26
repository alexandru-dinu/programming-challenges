# https://leetcode.com/problems/random-pick-with-weight

import random
import bisect


class Solution:
    def __init__(self, ws: List[int]):
        s = sum(ws)
        v = 0
        self.cumsum = [v := v + w / s for w in ws]

    def pickIndex(self) -> int:
        return bisect.bisect_left(self.cumsum, random.uniform(0, 1))


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
