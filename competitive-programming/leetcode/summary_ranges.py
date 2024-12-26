# https://leetcode.com/problems/summary-ranges


class Solution:
    def summaryRanges(self, xs: List[int]) -> List[str]:
        if not xs:
            return []

        switch = [
            *[i for i in range(len(xs) - 1) if (xs[i + 1] - xs[i] > 1)],
            len(xs) - 1,
        ]

        rv = []
        last = 0

        for s in switch:
            a, b = xs[last], xs[s]
            rv.append(f"{a}" if a == b else f"{a}->{b}")
            last = s + 1

        return rv
