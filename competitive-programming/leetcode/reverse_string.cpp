// https://leetcode.com/problems/reverse-string

class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, n = s.size(); i < n / 2; swap(s[i], s[n - i - 1]), ++i)
            ;
    }
};