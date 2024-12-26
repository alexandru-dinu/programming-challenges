# https://leetcode.com/problems/maximum-product-subarray

"""
max sum:  reset when current x added to the sum < x
max prod: find the longest subarray without 0 and with even number of negative numbers
"""


def split_at(xs, val):
    while len(xs) > 0:
        try:
            i = xs.index(val)
            if xs[:i] != []:
                yield xs[:i]
            xs = xs[i + 1 :]
        except ValueError:
            yield xs
            break


def solve_non_zero(xs):
    """
    solve MPS knowing that `xs` does not contain any 0

    KEY OBSERVATION:
        any sub-array *must* include xs[0] or xs[-1]:
        suppose you choose M, you can extend it by:
        - M - => entire array
        - M + => (M, +)
        + M - => (+, M)
        + M + => entire array

        therefore, use prefix and post
    """
    if len(xs) == 0:
        return 0
    if len(xs) == 1:
        return xs[0]

    scanr = [xs[0]]
    scanl = [xs[-1]]

    for i in range(1, len(xs)):
        scanr.append(scanr[-1] * xs[i])
        scanl.append(scanl[-1] * xs[-i - 1])

    return max(*scanl, *scanr)


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = list(map(solve_non_zero, split_at(nums, val=0)))

        if not res:
            return 0

        return max(0, *res) if 0 in nums else max(res)
