// https://leetcode.com/problems/permutation-in-string

class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        const int n1 = s1.length();
        const int n2 = s2.length();

        vector<int> goal(26, 0), cnt(26, 0);

        for (char c : s1)
            ++goal[c - 'a'];

        for (int i = 0; i < n2; ++i) {
            ++cnt[s2[i] - 'a'];

            if (i >= n1)
                --cnt[s2[i - n1] - 'a'];

            if (goal == cnt)
                return true;
        }

        return false;
    }
};