// https://leetcode.com/problems/maximal-square

class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() or matrix[0].empty())
            return 0;

        const int n = matrix.size();
        const int m = matrix[0].size();

        if (n == 1 and m == 1)
            return matrix[0][0] == '1';

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue;

                dp[i + 1][j + 1] =
                  1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i][j]));
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }

        return ans * ans;
    }
};