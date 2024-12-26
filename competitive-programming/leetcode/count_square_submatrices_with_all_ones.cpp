// https://leetcode.com/problems/count-square-submatrices-with-all-ones

class Solution
{
  public:
    int countSquares(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0)
                    continue;

                int r = 1 + min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] });
                dp[i + 1][j + 1] = r;
                ans += r;
            }
        }

        return ans;
    }
};