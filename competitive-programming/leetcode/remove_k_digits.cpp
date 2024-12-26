// https://leetcode.com/problems/remove-k-digits

class Solution
{
    string lstrip(string s, char c)
    {
        while (s[0] == c)
            s = s.substr(1);

        if (s.length() == 0)
            s = "0";

        return s;
    }

  public:
    string removeKdigits(string num, int k)
    {
        const int n = num.length();

        if (n == k)
            return "0";

        vector<int> s;

        for (char d : num) {
            while (k > 0 and !s.empty() and s.back() > d) {
                s.pop_back();
                k--;
            }

            s.push_back(d);
        }

        string ans(s.begin(), s.begin() + s.size() - k);

        return lstrip(ans, '0');
    }
};