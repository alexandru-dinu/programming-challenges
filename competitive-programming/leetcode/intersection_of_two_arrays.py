# https://leetcode.com/problems/intersection-of-two-arrays


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        xs = sorted(nums1)
        ys = sorted(nums2)
        out = []

        n = len(xs)
        m = len(ys)
        i = j = 0

        while i < n and j < m:
            while i < n and xs[i] < ys[j]:
                i += 1
            if i >= n:
                break

            while j < m and ys[j] < xs[i]:
                j += 1
            if j >= m:
                break

            if xs[i] == ys[j]:
                q = xs[i]
                out.append(q)

                while i < n and xs[i] == q:
                    i += 1

                while j < m and ys[j] == q:
                    j += 1

        return out
