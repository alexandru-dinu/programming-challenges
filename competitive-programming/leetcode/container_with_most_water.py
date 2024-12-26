# https://leetcode.com/problems/container-with-most-water

"""
Area(i, j) = (j - i) * min(ai, aj)

obvious O(n^2) solution gives TLE
"""


class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        rv = 0

        while i < j:
            w = j - i
            h = min(height[i], height[j])
            rv = max(rv, w * h)

            # try to find a taller left left
            if height[i] < height[j]:
                i += 1

            # try to find a taller right line
            else:
                j -= 1

            # if no such taller lines can be found,
            # then the max answer is already found
            # e.g. 8 7 6 5 4 3 2 1 9

        return rv
