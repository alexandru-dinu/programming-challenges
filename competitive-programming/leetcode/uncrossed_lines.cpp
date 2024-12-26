// https://leetcode.com/problems/uncrossed-lines

class Solution
{
  public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        const int na = A.size();
        const int nb = B.size();

        vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 0));

        for (int i = 0; i < na; ++i) {
            for (int j = 0; j < nb; ++j) {
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[na][nb];
    }
};