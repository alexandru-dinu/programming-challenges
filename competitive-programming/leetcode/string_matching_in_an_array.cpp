// https://leetcode.com/problems/string-matching-in-an-array

class Solution
{
  public:
    bool is_substr(const string &x, const string &y)
    {
        return y.find(x) != string::npos;
    }

    vector<string> stringMatching(vector<string> &words)
    {
        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (is_substr(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};