# https://leetcode.com/problems/island-perimeter


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        def nei(i, j):
            t = 0

            for (di, dj) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                if 0 <= i + di < len(grid) and 0 <= j + dj < len(grid[0]):
                    t += grid[i + di][j + dj]

            return t

        n = len(grid)
        m = len(grid[0])

        return sum(4 - nei(i, j) for i in range(n) for j in range(m) if grid[i][j] == 1)
