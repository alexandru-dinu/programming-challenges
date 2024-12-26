// https://leetcode.com/problems/group-anagrams

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        map<string, vector<string>> m;

        for (string s : strs) {
            string s_ = s;
            sort(s_.begin(), s_.end());
            m[s_].push_back(s);
        }

        for (auto p : m) {
            ans.push_back(p.second);
        }

        return ans;
    }
};