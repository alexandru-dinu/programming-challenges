// https://leetcode.com/problems/reverse-integer

class Solution
{
  public:
    int reverse(int x)
    {
        int sign = (x < 0) ? -1 : 1;
    std:
        int64_t bx = x;
        auto s = std::to_string(std::abs(bx));
        std::reverse(s.begin(), s.end());
        auto r = std::stoll(s);

        return (r < INT_MIN || r > INT_MAX) ? 0 : sign * (int)r;
    }
};