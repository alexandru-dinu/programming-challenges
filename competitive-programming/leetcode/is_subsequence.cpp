// https://leetcode.com/problems/is-subsequence

class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;

        for (char c : t) {
            if (c == s[i])
                i++;

            if (i == s.size())
                return true;
        }

        return (s.size() == 0 and t.size() == 0) or false;
    }
};