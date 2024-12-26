// https://leetcode.com/problems/unique-paths

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        //         DP approach: O(n*m)
        //         return DP(m, n);

        //         math approach: O(1) space
        return comb(m, n);
    }

    int DP(int m, int n)
    {
        int ways[m][n];

        for (int i = 0; i < m; i++)
            ways[i][0] = 1;

        for (int i = 0; i < n; i++)
            ways[0][i] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ways[i][j] = ways[i][j - 1] + ways[i - 1][j];
            }
        }

        return ways[m - 1][n - 1];
    }

    int comb(int m, int n)
    {
        m -= 1;
        n -= 1;

        if (m < n)
            std::swap(m, n);

        double res = 1.0;
        for (int i = 1; i <= n; i++) {
            res *= (m + i) / (1.0 * i);
        }

        return static_cast<int>(round(res));
    }
};