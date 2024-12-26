// https://leetcode.com/problems/palindrome-number

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        int _x = x;
        int rev = 0;

        while (_x > 0) {
            rev = 10 * rev + _x % 10;
            _x /= 10;
        }

        return rev == abs(x);
    }
};