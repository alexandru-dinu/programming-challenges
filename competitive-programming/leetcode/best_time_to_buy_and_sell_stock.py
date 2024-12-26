# https://leetcode.com/problems/best-time-to-buy-and-sell-stock

from itertools import accumulate


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # buy = float('inf')
        # profit = float('-inf')
        # for p in prices:
        #     buy = min(buy, p)
        #     profit = max(profit, p - buy)

        return max(sell - buy for (sell, buy) in zip(prices, accumulate(prices, min)))
