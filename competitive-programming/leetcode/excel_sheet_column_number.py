# https://leetcode.com/problems/excel-sheet-column-number


class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        n = len(columnTitle)

        return sum(
            i * t
            for (i, t) in zip(
                map(lambda c: ord(c) - ord("A") + 1, columnTitle),
                (26 ** i for i in range(n - 1, -1, -1)),
            )
        )
