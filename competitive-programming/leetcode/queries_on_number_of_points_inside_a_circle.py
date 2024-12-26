# https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle


class Solution:
    def countPoints(
        self, points: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        out = [0] * len(queries)

        eucl = lambda p1, p2: (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

        for i, (xc, yc, r) in enumerate(queries):
            out[i] = sum(1 for (x, y) in points if eucl((x, y), (xc, yc)) <= r ** 2)

        return out
