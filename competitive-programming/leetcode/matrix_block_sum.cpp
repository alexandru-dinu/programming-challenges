// https://leetcode.com/problems/matrix-block-sum

class Solution
{
  public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> answer(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Safe get
        auto S = [&dp, n, m](int i, int j) {
            if (i < 0 or j < 0)
                return 0;
            i = min(i, m - 1);
            j = min(j, n - 1);
            return dp[i][j];
        };

        // dp[i][j] is the sum of all cells in the rectangle from (0,0) to (i,j)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] =
                  mat[i][j] + S(i - 1, j) + S(i, j - 1) - S(i - 1, j - 1);

        /*
        .   .   .     .      .
        .   .   .     .      .
               |-----------------|
        .   .  |.     .      .   |
        .   .  |.    i,j     .   |
        .   .  |.     .   i+K,j+K|
               |-----------------|
         */

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                answer[i][j] = S(i + K, j + K) - S(i + K, j - K - 1) -
                               S(i - K - 1, j + K) + S(i - K - 1, j - K - 1);

        return answer;
    }
};