# https://leetcode.com/problems/compare-version-numbers


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        x1 = version1.split(".")
        x2 = version2.split(".")

        shorter = min([x1, x2], key=len)
        diff = abs(len(x1) - len(x2))

        if x1 is shorter:
            x1.extend(["0"] * diff)
        if x2 is shorter:
            x2.extend(["0"] * diff)

        for i, j in zip(map(int, x1), map(int, x2)):
            if i == j:
                continue
            return -1 if i < j else 1

        return 0
