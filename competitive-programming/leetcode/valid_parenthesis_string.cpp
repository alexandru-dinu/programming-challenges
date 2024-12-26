// https://leetcode.com/problems/valid-parenthesis-string

class Solution
{
  public:
    bool checkValidString(string s)
    {
        const int n = s.length();
        unordered_map<char, vector<int>> m;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c != ')') {
                m[c].push_back(i);
            } else {
                if (m['('].size() == 0) {
                    if (m['*'].size() == 0)
                        return false;

                    m['*'].pop_back();
                } else {
                    m['('].pop_back();
                }
            }
        }

        // nothing else to match
        if (m['('].size() == 0)
            return true;

        // for each unmatched '(', find the immediate '*'
        for (int i : m['(']) {
            auto lo = lower_bound(begin(m['*']), end(m['*']), i);
            if (lo == end(m['*']))
                return false;
            else
                m['*'].erase(lo);
        }

        return true;
    }
};