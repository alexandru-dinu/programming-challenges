# https://leetcode.com/problems/min-cost-climbing-stairs


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        M = [0] * (len(cost) + 2)

        for i in range(len(cost) - 1, -1, -1):
            M[i] = cost[i] + min(M[i + 1], M[i + 2])

        return min(M[0], M[1])
