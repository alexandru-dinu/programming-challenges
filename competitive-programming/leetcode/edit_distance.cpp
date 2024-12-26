// https://leetcode.com/problems/edit-distance

class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        const int n = word1.length();
        const int m = word2.length();

        if (min(n, m) == 0)
            return max(n, m);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; ++i)
            dp[i + 1][0] = i + 1;

        for (int j = 0; j < m; ++j)
            dp[0][j + 1] = j + 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                    continue;
                }

                dp[i + 1][j + 1] =
                  1 + min({ dp[i][j + 1], dp[i + 1][j], dp[i][j] });
            }
        }

        return dp[n][m];
    }
};