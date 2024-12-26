# https://leetcode.com/problems/find-median-from-data-stream

import bisect


class MedianFinder:
    def __init__(self):
        self.arr = []

    def addNum(self, num: int) -> None:
        """
        [-5, -4, -2, -1, -4]
        i = 0
        """
        bisect.insort(self.arr, num)

    def findMedian(self) -> float:
        n = len(self.arr)
        if n % 2 == 1:
            return self.arr[n // 2]
        else:
            return 0.5 * (self.arr[n // 2 - 1] + self.arr[n // 2])


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
