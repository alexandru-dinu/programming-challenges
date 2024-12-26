// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        const int ns = s.length();
        const int np = p.length();

        vector<int> goal(26, 0), cnt(26, 0), ans;

        for (char c : p)
            ++goal[c - 'a'];

        for (int i = 0; i < ns; ++i) {
            ++cnt[s[i] - 'a'];

            // sliding window of size np
            if (i >= np)
                --cnt[s[i - np] - 'a'];

            if (goal == cnt)
                ans.push_back(i - np + 1);
        }

        return ans;
    }
};