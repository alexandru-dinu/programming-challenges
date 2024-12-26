// https://leetcode.com/problems/longest-common-subsequence

class Solution
{
  public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int n1 = text1.length();
        const int n2 = text2.length();

        int dp[n1 + 1][n2 + 1];
        fill(&dp[0][0], &dp[n1][n2], 0);

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n1][n2];
    }
};