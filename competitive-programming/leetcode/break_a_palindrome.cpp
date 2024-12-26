// https://leetcode.com/problems/break-a-palindrome

class Solution
{
  public:
    string breakPalindrome(string s)
    {
        const int n = s.length();

        if (n == 1)
            return "";

        for (int i = 0; i < n / 2; i++) {
            if (s[i] == 'a')
                continue;

            s[i] = 'a';
            return s;
        }

        s[n - 1] = 'b';
        return s;
    }
};