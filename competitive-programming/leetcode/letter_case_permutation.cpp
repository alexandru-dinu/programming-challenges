// https://leetcode.com/problems/letter-case-permutation

class Solution
{
  public:
    char switchCase(char c)
    {
        if (65 <= c and c <= 90)
            return c + 32;
        else if (97 <= c and c <= 122)
            return c - 32;
        else
            return c;
    }

    void solve(string s, int l, int r, vector<string> &acc)
    {
        acc.push_back(s);

        for (int i = l; i < r; i++) {
            if (isalpha(s[i])) {
                s[i] = switchCase(s[i]);
                solve(s, i + 1, r, acc);
                s[i] = switchCase(s[i]);
            }
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;

        solve(s, 0, s.length(), ans);

        return ans;
    }
};